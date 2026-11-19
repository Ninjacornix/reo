#include "parallel_backend.h"
#if defined(REO_BUILD_NATIVE_SOUND_RAM_CAPTURE) && REO_BUILD_NATIVE_SOUND_RAM_CAPTURE >= 2
#include "resident_geometry/parent/parent_owner_service.hpp"
#endif
#if defined(PS2_RUNTIME_HAS_GS_SOUND_RAM_PROFILE)
#include "gs_sound_ram_profile.h"
#endif
#include "runtime/gs/internal_resolution.h"
#include "runtime/gs/frame_pacing.h"
#include "runtime/gs/performance.h"
#include "shader_location.hpp"
#include "parent_first_entry.h"
#include "parent_natural_runtime.h"
#include "native_movie_owner.h"
#include "resident_vif_live_hooks.h"
#if defined(_WIN32)
#include "resident_dxgi_presenter1c.h"
#include "movie_runtime/movie_owner_service_fwd.h"
#elif defined(REO_MACOS_METAL_PRESENT)
#include "macos/resident_metal_presenter.h"
#elif defined(REO_LINUX_XLIB_PRESENT)
#include "linux/resident_xlib_presenter.h"
#endif
#include "resident_owner_images.h"
#include "stream_helpers.h"
#include "gs_interface.hpp"
#include "gs_util.hpp"
#include "resident_clear_context.hpp"
#include "frame_replay.hpp"
#include <chrono>
#include <fstream>
#include <deque>
#include <cstddef>
#include "context.hpp"
#include "device.hpp"
#include "command_buffer.hpp"
#include "fence.hpp"
#include "thread_id.hpp"
#include "pipeline_cache_store.h"
#include "hash.hpp"
#include <cstdio>
#include <memory>
#include <utility>
#if defined(_WIN32)
std::filesystem::path reo_shader_location::executableDirectory() {
    wchar_t executable[32768];
    const DWORD length = GetModuleFileNameW(nullptr, executable, 32768);
    if (!length || length == 32768)
        return {};
    return std::filesystem::path(executable).parent_path();
}
#endif
// ---- Native renderer (inlined: edits here recompile only this unit; a header change would
// invalidate every cached object of the local build) ----
// Native renderer (REO_NATIVE_RENDER=1): draws the current room and the active characters from
// the game's own model files with the camera, room and bone matrices the game thread publishes
// (runtime/gs/native_render_frame.h). The result replaces the GS scanout for presentation.
// Offline reference and format notes: tools/native_render/room_render.py,
// docs/native-gameplay/NATIVE_RENDERER.md.
//
// Scope of this first live version: room geometry (part matrices) and skinned characters,
// textured, with the measured room colour factor and a neutral character light; material type
// 0x12 is additive. Not yet: fog, character lighting, room objects, effects, HUD/menus (the
// GS picture is shown whenever no room is loaded).
#include "runtime/gs/native_render_frame.h"
#include "runtime/cdvd/cdvd.h"
#include "../../game/native/gameplay_presentation/texture.cpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>

namespace reo_native_render {

constexpr float RoomColorScale = 95.0f / 255.0f;      // measured (NATIVE_RENDER.md step 2)
constexpr float CharacterNeutralLight = RoomColorScale;

struct Vertex { float pos[3]; float color[4]; float uv[2]; };

struct Part {
    std::vector<std::array<float, 3>> pos;
    std::vector<std::array<float, 4>> col;
    std::vector<std::array<float, 2>> uv;
    std::vector<uint32_t> palette;
    std::vector<std::vector<std::pair<uint32_t, float>>> influences;
    struct Tri { uint32_t a, b, c, material; };
    std::vector<Tri> tris;
};

struct Model {
    std::vector<Part> parts;
    std::vector<std::pair<uint32_t, uint32_t>> materials;  // (type, texture slot)
    std::vector<Vulkan::ImageHandle> textures;
};

inline uint32_t rd32(const std::vector<uint8_t>& b, size_t at) {
    if (at + 4 > b.size()) throw std::runtime_error("NBD read out of range");
    uint32_t v; std::memcpy(&v, b.data() + at, 4); return v;
}
inline float rdf(const std::vector<uint8_t>& b, size_t at) { uint32_t v = rd32(b, at); float f; std::memcpy(&f, &v, 4); return f; }

struct Chunk { size_t at; uint32_t kind, count, size; };
inline std::vector<Chunk> chunks(const std::vector<uint8_t>& b, size_t at) {
    std::vector<Chunk> out;
    const size_t end = at + rd32(b, at + 8);
    size_t cur = at + 12;
    while (cur < end) {
        Chunk c{cur, rd32(b, cur), rd32(b, cur + 4), rd32(b, cur + 8)};
        if (c.size < 12 || cur + c.size > end) throw std::runtime_error("Bad AMO chunk");
        out.push_back(c);
        cur += c.size;
    }
    return out;
}

// AMO model (section 2 of the NBD: tag "AMO" at 0x10, offset at 0x14). Layout as room_render.py.
inline Model parse_model(const std::vector<uint8_t>& b) {
    if (b.size() < 0x20 || std::memcmp(b.data() + 0x10, "AMO", 3)) throw std::runtime_error("NBD has no AMO section");
    const auto top = chunks(b, rd32(b, 0x14));
    Model m;
    const Chunk* parts = nullptr; const Chunk* mats = nullptr; const Chunk* texs = nullptr;
    for (const auto& c : top) { if (c.kind == 0x2) parts = &c; else if (c.kind == 0x9) mats = &c; else if (c.kind == 0xA) texs = &c; }
    if (!parts || !mats || !texs) throw std::runtime_error("AMO model lists missing");
    std::vector<uint32_t> slots;
    for (const auto& c : chunks(b, texs->at)) slots.push_back(rd32(b, c.at + 12));
    for (const auto& c : chunks(b, mats->at)) {
        const uint32_t record = rd32(b, c.at + c.size - 4);
        m.materials.push_back({c.kind >> 16, record < slots.size() ? slots[record] : 0});
    }
    for (const auto& pc : chunks(b, parts->at)) {
        if (pc.kind != 0x4) continue;
        Part part;
        std::vector<std::vector<uint32_t>> strips;
        std::vector<uint32_t> part_materials, strip_refs;
        for (const auto& s : chunks(b, pc.at)) {
            const size_t data = s.at + 12;
            if (s.kind == 0x5) {
                for (const auto& l : chunks(b, s.at)) {
                    if (l.kind != 0x30000) continue;
                    size_t cur = l.at + 12;
                    for (uint32_t k = 0; k < l.count; ++k) {
                        const uint32_t n = rd32(b, cur);
                        if (n > 20000) throw std::runtime_error("Bad strip");
                        std::vector<uint32_t> strip(n);
                        for (uint32_t j = 0; j < n; ++j) strip[j] = rd32(b, cur + 4 + 4 * j);
                        strips.push_back(std::move(strip));
                        cur += 4 + 4 * n;
                    }
                }
            } else if (s.kind == 0x50000) {
                for (uint32_t k = 0; k < s.count; ++k) part_materials.push_back(rd32(b, data + 4 * k));
            } else if (s.kind == 0x60000) {
                for (uint32_t k = 0; k < s.count; ++k) strip_refs.push_back(rd32(b, data + 4 * k));
            } else if (s.kind == 0x70000) {
                for (uint32_t k = 0; k < s.count; ++k) part.pos.push_back({rdf(b, data + 12 * k), rdf(b, data + 12 * k + 4), rdf(b, data + 12 * k + 8)});
            } else if (s.kind == 0xA0000) {
                for (uint32_t k = 0; k < s.count; ++k) part.uv.push_back({rdf(b, data + 8 * k), rdf(b, data + 8 * k + 4)});
            } else if (s.kind == 0xB0000) {
                for (uint32_t k = 0; k < s.count; ++k)
                    part.col.push_back({rdf(b, data + 16 * k), rdf(b, data + 16 * k + 4), rdf(b, data + 16 * k + 8), rdf(b, data + 16 * k + 12)});
            } else if (s.kind == 0x100000) {
                for (uint32_t k = 0; k < s.count; ++k) part.palette.push_back(rd32(b, data + 4 * k));
            } else if (s.kind == 0xC0000) {
                size_t cur = data;
                for (uint32_t k = 0; k < s.count; ++k) {
                    const uint32_t n = rd32(b, cur);
                    if (n > 8) throw std::runtime_error("Bad skin record");
                    std::vector<std::pair<uint32_t, float>> inf;
                    for (uint32_t j = 0; j < n; ++j) inf.push_back({rd32(b, cur + 4 + 8 * j) & 255u, rdf(b, cur + 8 + 8 * j) / 100.f});
                    part.influences.push_back(std::move(inf));
                    cur += 4 + 8 * n;
                }
            }
        }
        const size_t vertices = part.pos.size();
        if (part.uv.size() != vertices) part.uv.assign(vertices, {0.f, 0.f});
        if (part.col.size() != vertices) part.col.assign(vertices, {0.f, 0.f, 0.f, 255.f});
        for (size_t s = 0; s < strips.size(); ++s) {
            uint32_t material = 0;
            if (s < strip_refs.size()) material = strip_refs[s] < part_materials.size() ? part_materials[strip_refs[s]] : strip_refs[s];
            const auto& st = strips[s];
            for (size_t k = 0; k + 2 < st.size(); ++k) {
                const uint32_t a = st[k], b2 = st[k + 1], c = st[k + 2];
                if (a == b2 || b2 == c || a == c || a >= vertices || b2 >= vertices || c >= vertices) continue;
                part.tris.push_back({a, b2, c, material});
            }
        }
        m.parts.push_back(std::move(part));
    }
    return m;
}

// The disc: NETBIO00.DAT and its nested AFS archives, read through the runtime's CDVD.
class Disc {
  public:
    Disc() {
        const char* root = std::getenv("REO_NATIVE_RENDER_CDROOT");
        cd_ = std::make_unique<reo::CDVD>(root ? std::filesystem::path(root) : std::filesystem::current_path());
        uint32_t size = 0;
        if (!cd_->search_file("cdrom0:\\NETBIO00.DAT;1", lba_, size)) throw std::runtime_error("NETBIO00.DAT not found on the disc");
        top_ = toc(0);
    }
    std::vector<uint8_t> member(const std::string& archive, const std::string& name) {
        const auto& t = nested(archive);
        for (size_t i = 0; i < t.names.size(); ++i)
            if (iequal(t.names[i], name)) return read(t.base + t.entries[i].first, t.entries[i].second);
        return {};
    }
    std::vector<uint8_t> ordinal(const std::string& archive, uint32_t index) {
        const auto& t = nested(archive);
        if (index >= t.entries.size()) return {};
        return read(t.base + t.entries[index].first, t.entries[index].second);
    }

  private:
    struct Toc { uint64_t base = 0; std::vector<std::pair<uint32_t, uint32_t>> entries; std::vector<std::string> names; };
    static bool iequal(const std::string& a, const std::string& b) {
        return a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin(), [](char x, char y) { return std::tolower((unsigned char)x) == std::tolower((unsigned char)y); });
    }
    std::vector<uint8_t> read(uint64_t offset, uint32_t bytes) {
        const uint64_t first = offset / 2048, last = (offset + bytes + 2047) / 2048;
        std::vector<uint8_t> sectors(size_t(last - first) * 2048);
        if (!cd_->read_sectors(uint32_t(lba_ + first), uint32_t(last - first), sectors.data())) throw std::runtime_error("Disc read failed");
        return std::vector<uint8_t>(sectors.begin() + (offset - first * 2048), sectors.begin() + (offset - first * 2048) + bytes);
    }
    Toc toc(uint64_t base) {
        Toc t; t.base = base;
        auto head = read(base, 8);
        if (std::memcmp(head.data(), "AFS", 3)) throw std::runtime_error("Not an AFS archive");
        uint32_t count; std::memcpy(&count, head.data() + 4, 4);
        if (count > 100000) throw std::runtime_error("AFS too large");
        auto raw = read(base + 8, count * 8 + 8);
        for (uint32_t i = 0; i < count; ++i) { uint32_t o, s; std::memcpy(&o, &raw[i * 8], 4); std::memcpy(&s, &raw[i * 8 + 4], 4); t.entries.push_back({o, s}); }
        uint32_t no, ns; std::memcpy(&no, &raw[count * 8], 4); std::memcpy(&ns, &raw[count * 8 + 4], 4);
        if (no && ns) {
            auto names = read(base + no, ns);
            for (uint32_t i = 0; i < count && (i + 1) * 48 <= names.size(); ++i)
                t.names.push_back(std::string(reinterpret_cast<const char*>(&names[i * 48]), strnlen(reinterpret_cast<const char*>(&names[i * 48]), 32)));
        }
        return t;
    }
    const Toc& nested(const std::string& archive) {
        auto it = nested_.find(archive);
        if (it != nested_.end()) return it->second;
        for (size_t i = 0; i < top_.names.size(); ++i)
            if (iequal(top_.names[i], archive)) return nested_.emplace(archive, toc(top_.entries[i].first)).first->second;
        throw std::runtime_error("Archive " + archive + " not found");
    }
    std::unique_ptr<reo::CDVD> cd_;
    uint32_t lba_ = 0;
    Toc top_;
    std::map<std::string, Toc> nested_;
};

class Renderer {
  public:
    explicit Renderer(Vulkan::Device& device) : device_(device) {
        const char* s = std::getenv("REO_NATIVE_RENDER_SCALE");
        scale_ = s ? std::clamp(std::atoi(s), 1, 4) : 2;
        const auto dir = std::filesystem::path(__FILE__).parent_path() / "native_render_shaders";
        auto load = [&](const char* name) {
            std::ifstream f(reo_shader_location::find(dir, name), std::ios::binary | std::ios::ate);
            if (!f) throw std::runtime_error(std::string("Missing native render shader ") + name);
            std::vector<uint32_t> code(size_t(f.tellg()) / 4); f.seekg(0); f.read(reinterpret_cast<char*>(code.data()), code.size() * 4);
            return code;
        };
        const auto vs = load("scene.vert.spv"), fs = load("scene.frag.spv");
        // This Granite build has no shader reflection: declare the layouts (as the presenter does).
        Vulkan::ResourceLayout v{}, f{};
        v.input_mask = 7;                      // position, color, uv
        v.push_constant_size = 80;             // mat4 view_projection + vec4 screen
        f.sets[0].sampled_image_mask = 1;      // set 0 binding 0: texture
        f.sets[0].fp_mask = 1;
        f.sets[0].meta[0].array_size = 1;
        f.output_mask = 1;
        program_ = device_.request_program(vs.data(), vs.size() * 4, fs.data(), fs.size() * 4, &v, &f);
        if (!program_) throw std::runtime_error("Native render program unavailable");
        disc_ = std::make_unique<Disc>();
        const uint8_t white[4] = {255, 255, 255, 255};
        white_ = upload(1, 1, white);
    }

    // Returns the native picture for the newest published frame, or empty (show the GS one).
    Vulkan::ImageHandle render() {
        reo::native_render::Frame frame;
        if (!reo::native_render::snapshot(frame)) return {};
        if (!ensure_room(frame.scenario, frame.room)) return {};
        for (uint32_t i = 0; i < frame.actor_count; ++i) ensure_character(frame.actors[i].character);
        return draw(frame);
    }
    uint64_t frames() const { return frames_; }

  private:
    Vulkan::ImageHandle upload(uint32_t w, uint32_t h, const void* rgba) {
        auto info = Vulkan::ImageCreateInfo::immutable_2d_image(w, h, VK_FORMAT_R8G8B8A8_UNORM);
        Vulkan::ImageInitialData initial{};
        initial.data = rgba;
        return device_.create_image(info, &initial);
    }
    Vulkan::ImageHandle decode(const std::vector<uint8_t>& compressed) {
        using namespace reo::native::gameplay_presentation;
        const auto expanded = decompress_texture(std::span<const std::byte>(reinterpret_cast<const std::byte*>(compressed.data()), compressed.size()));
        const auto t = decode_texture(expanded);
        return upload(t.width, t.height, t.rgba.data());
    }
    bool ensure_room(uint8_t scenario, uint8_t room) {
        if (room_ && scenario == room_scenario_ && room == room_index_) return true;
        if (failed_rooms_.count(scenario * 256u + room)) return false;
        try {
            char archive[32], name[32];
            std::snprintf(archive, sizeof(archive), "r%03u.afs", unsigned(scenario));
            std::snprintf(name, sizeof(name), "r%03u%02u00.nbd", unsigned(scenario), unsigned(room));
            auto nbd = disc_->member(archive, name);
            if (nbd.empty()) throw std::runtime_error(std::string("room model ") + name + " not found");
            auto model = std::make_unique<Model>(parse_model(nbd));
            if (std::memcmp(nbd.data(), "TID", 3) == 0) {
                const uint32_t tid = rd32(nbd, 4), count = rd32(nbd, tid);
                for (uint32_t i = 0; i < count && i < 256; ++i) {
                    auto bytes = disc_->ordinal(archive, rd32(nbd, tid + 4 + 4 * i));
                    model->textures.push_back(bytes.empty() ? white_ : decode(bytes));
                }
            }
            room_ = std::move(model);
            room_scenario_ = scenario; room_index_ = room;
            std::fprintf(stderr, "[NATIVE-RENDER] room %s: %zu parts, %zu textures\n", name, room_->parts.size(), room_->textures.size());
            return true;
        } catch (const std::exception& e) {
            failed_rooms_.insert(scenario * 256u + room);
            std::fprintf(stderr, "[NATIVE-RENDER] room r%03u%02u00 unavailable: %s\n", unsigned(scenario), unsigned(room), e.what());
            return false;
        }
    }
    void ensure_character(uint8_t id) {
        if (characters_.count(id) || id > 15) return;
        try {
            char name[32];
            std::snprintf(name, sizeof(name), "P%02u_00.nbd", unsigned(id));
            auto nbd = disc_->member("romdata_usa.afs", name);
            if (nbd.empty()) throw std::runtime_error("model not found");
            auto model = std::make_unique<Model>(parse_model(nbd));
            if (std::memcmp(nbd.data(), "TEX", 3) == 0) {
                uint32_t at = rd32(nbd, 4); const uint32_t count = rd32(nbd, 12);
                for (uint32_t i = 0; i < count && i < 64; ++i) {
                    const uint32_t n = rd32(nbd, at);
                    model->textures.push_back(decode(std::vector<uint8_t>(nbd.begin() + at + 4, nbd.begin() + at + 4 + n)));
                    at += 4 + n;
                }
            }
            std::fprintf(stderr, "[NATIVE-RENDER] character %s: %zu parts, %zu textures\n", name, model->parts.size(), model->textures.size());
            characters_[id] = std::move(model);
        } catch (const std::exception& e) {
            characters_[id] = nullptr;
            std::fprintf(stderr, "[NATIVE-RENDER] character %u unavailable: %s\n", unsigned(id), e.what());
        }
    }

    // Row-vector 4x4 helpers (the game's convention: v' = v . M).
    static void mul(const float* a, const float* b, float* out) {
        for (int r = 0; r < 4; ++r) for (int c = 0; c < 4; ++c) {
            float s = 0; for (int k = 0; k < 4; ++k) s += a[r * 4 + k] * b[k * 4 + c]; out[r * 4 + c] = s;
        }
    }
    static void transform(const float* v3, const float* m, float* out3) {
        for (int c = 0; c < 3; ++c) out3[c] = v3[0] * m[c] + v3[1] * m[4 + c] + v3[2] * m[8 + c] + m[12 + c];
    }

    struct Batch { const Vulkan::ImageView* texture; bool additive; std::vector<Vertex> vertices; };

    void add_model(std::map<std::pair<const void*, bool>, Batch>& batches, const Model& model,
                   const std::vector<std::vector<std::array<float, 3>>>& world, bool character) {
        for (size_t p = 0; p < model.parts.size(); ++p) {
            const auto& part = model.parts[p];
            if (world[p].empty()) continue;
            for (const auto& t : part.tris) {
                const auto& mat = t.material < model.materials.size() ? model.materials[t.material] : std::pair<uint32_t, uint32_t>{0x13, 0};
                const bool additive = mat.first == 0x12;
                const Vulkan::ImageView* view = mat.second < model.textures.size() ? &model.textures[mat.second]->get_view() : &white_->get_view();
                auto& batch = batches[{view, additive}];
                batch.texture = view; batch.additive = additive;
                for (uint32_t i : {t.a, t.b, t.c}) {
                    Vertex v{};
                    std::memcpy(v.pos, world[p][i].data(), 12);
                    if (character) { v.color[0] = v.color[1] = v.color[2] = CharacterNeutralLight; v.color[3] = 1.f; }
                    else {
                        for (int c = 0; c < 3; ++c) v.color[c] = part.col[i][c] / 128.f * RoomColorScale;
                        v.color[3] = part.col[i][3] / 128.f;
                    }
                    v.uv[0] = part.uv[i][0]; v.uv[1] = part.uv[i][1];
                    batch.vertices.push_back(v);
                }
            }
        }
    }

    Vulkan::ImageHandle draw(const reo::native_render::Frame& frame) {
        std::map<std::pair<const void*, bool>, Batch> batches;
        // Room: part vertices through the published part matrices.
        {
            std::vector<std::vector<std::array<float, 3>>> world(room_->parts.size());
            for (size_t p = 0; p < room_->parts.size() && p < reo::native_render::MaxRoomParts; ++p) {
                const float* m = frame.room_parts[p];
                bool any = false; for (int k = 0; k < 16; ++k) any |= m[k] != 0.f;
                if (!any) continue;
                world[p].resize(room_->parts[p].pos.size());
                for (size_t i = 0; i < world[p].size(); ++i) transform(room_->parts[p].pos[i].data(), m, world[p][i].data());
            }
            add_model(batches, *room_, world, false);
        }
        // Characters: skinned on the CPU (sum of weight x v . inverse_bind . world).
        for (uint32_t a = 0; a < frame.actor_count; ++a) {
            const auto& actor = frame.actors[a];
            auto it = characters_.find(actor.character);
            if (it == characters_.end() || !it->second) continue;
            const Model& model = *it->second;
            std::vector<std::array<float, 16>> skin(actor.bones);
            for (uint32_t b = 0; b < actor.bones; ++b) mul(actor.inverse_bind[b], actor.world[b], skin[b].data());
            std::vector<std::vector<std::array<float, 3>>> world(model.parts.size());
            for (size_t p = 0; p < model.parts.size(); ++p) {
                const auto& part = model.parts[p];
                if (part.influences.size() != part.pos.size()) continue;
                world[p].assign(part.pos.size(), {0.f, 0.f, 0.f});
                bool ok = true;
                for (size_t i = 0; i < part.pos.size() && ok; ++i)
                    for (const auto& [index, weight] : part.influences[i]) {
                        if (index >= part.palette.size() || part.palette[index] >= actor.bones) { ok = false; break; }
                        float out[3]; transform(part.pos[i].data(), skin[part.palette[index]].data(), out);
                        for (int c = 0; c < 3; ++c) world[p][i][c] += weight * out[c];
                    }
                if (!ok) world[p].clear();
            }
            add_model(batches, model, world, true);
        }

        const uint32_t width = 512 * scale_, height = 448 * scale_;
        if (!color_ || color_->get_width() != width) {
            auto info = Vulkan::ImageCreateInfo::render_target(width, height, VK_FORMAT_R8G8B8A8_UNORM);
            info.usage |= VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
            info.initial_layout = VK_IMAGE_LAYOUT_UNDEFINED;
            auto dinfo = Vulkan::ImageCreateInfo::render_target(width, height, VK_FORMAT_D32_SFLOAT);
            dinfo.initial_layout = VK_IMAGE_LAYOUT_UNDEFINED;
            depth_ = device_.create_image(dinfo);
            color_images_.clear();
            for (int k = 0; k < 3; ++k) color_images_.push_back(device_.create_image(info));
            color_ = color_images_[0];
        }
        color_ = color_images_[(++frames_) % color_images_.size()];

        auto cmd = device_.request_command_buffer();
        cmd->image_barrier(*color_, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
                           VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                           VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT);
        cmd->image_barrier(*depth_, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL,
                           VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT,
                           VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT | VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT);
        Vulkan::RenderPassInfo pass{};
        pass.num_color_attachments = 1;
        pass.color_attachments[0] = &color_->get_view();
        pass.depth_stencil = &depth_->get_view();
        pass.clear_attachments = 1;
        pass.store_attachments = 1;
        pass.op_flags = Vulkan::RENDER_PASS_OP_CLEAR_DEPTH_STENCIL_BIT;
        pass.clear_color[0].float32[3] = 1.f;
        pass.clear_depth_stencil.depth = 1.f;
        cmd->begin_render_pass(pass);
        cmd->set_program(program_);
        cmd->set_opaque_state();
        cmd->set_cull_mode(VK_CULL_MODE_NONE);
        cmd->set_primitive_topology(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST);
        cmd->set_vertex_attrib(0, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(Vertex, pos));
        cmd->set_vertex_attrib(1, 0, VK_FORMAT_R32G32B32A32_SFLOAT, offsetof(Vertex, color));
        cmd->set_vertex_attrib(2, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(Vertex, uv));
        struct Push { float view_projection[16]; float screen[4]; } push{};
        mul(frame.view, frame.projection, push.view_projection);  // world -> pixels x w (row vectors)
        push.screen[0] = 1.f / 256.f; push.screen[1] = 1.f / 224.f; push.screen[2] = 1.f / 65536.f;
        cmd->push_constants(&push, 0, sizeof(push));
        for (int pass_index = 0; pass_index < 2; ++pass_index) {
            const bool additive = pass_index == 1;
            cmd->set_depth_test(true, !additive);
            cmd->set_depth_compare(VK_COMPARE_OP_LESS_OR_EQUAL);
            cmd->set_blend_enable(true);
            if (additive) cmd->set_blend_factors(VK_BLEND_FACTOR_SRC_ALPHA, VK_BLEND_FACTOR_ONE);
            else cmd->set_blend_factors(VK_BLEND_FACTOR_SRC_ALPHA, VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA);
            for (auto& [key, batch] : batches) {
                if (batch.additive != additive || batch.vertices.empty()) continue;
                cmd->set_texture(0, 0, *batch.texture, Vulkan::StockSampler::LinearWrap);
                void* data = cmd->allocate_vertex_data(0, batch.vertices.size() * sizeof(Vertex), sizeof(Vertex));
                std::memcpy(data, batch.vertices.data(), batch.vertices.size() * sizeof(Vertex));
                cmd->draw(uint32_t(batch.vertices.size()));
            }
        }
        cmd->end_render_pass();
        cmd->image_barrier(*color_, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL,
                           VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT,
                           VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_ACCESS_2_SHADER_SAMPLED_READ_BIT);
        device_.submit(cmd);
        return color_;
    }

    Vulkan::Device& device_;
    int scale_ = 2;
    Vulkan::Program* program_ = nullptr;
    std::unique_ptr<Disc> disc_;
    Vulkan::ImageHandle white_, color_, depth_;
    std::vector<Vulkan::ImageHandle> color_images_;
    std::unique_ptr<Model> room_;
    uint8_t room_scenario_ = 0xFF, room_index_ = 0xFF;
    std::set<uint32_t> failed_rooms_;
    std::map<uint8_t, std::unique_ptr<Model>> characters_;
    uint64_t frames_ = 0;
};

}  // namespace reo_native_render
// ---- end native renderer ----
namespace reo_parallel_backend {
namespace {
using namespace ParallelGS;
using namespace Vulkan;
using namespace gs_backend_bridge;
constexpr size_t VramSize = 4u * 1024u * 1024u;
static_assert(sizeof(Util::Hash) == 8 && VK_UUID_SIZE == 16 &&
                  VK_MAX_PIPELINE_BINARY_KEY_SIZE_KHR == 32,
              "Pinned Granite pipeline cache codec changed");
// Route serializes all use, so a single command-pool index is sufficient.
// Preserve a host thread's preexisting Granite registration on handoff.
struct ThreadIndexScope {
    unsigned previous = Util::get_current_thread_index();
    ThreadIndexScope() {
        Util::register_thread_index(0);
    }
    ~ThreadIndexScope() {
        Util::register_thread_index(previous);
    }
};
class ParallelBackend final : public Backend, private SignalInterface {
    Config config_;
    unsigned internalResolution_ = reo::graphics::internalResolution(std::getenv("REO_INTERNAL_RESOLUTION"));
    uint32_t reportedScanoutWidth_ = 0, reportedScanoutHeight_ = 0, scanoutReports_ = 0;
    unsigned memoryLogFrames_ = 0;
    Vulkan::ImageHandle repeatImage_;  // last presented scanout (REO_DISPLAY_RATE repeats)
    bool repeatLinear_ = false;
    // REO_FRAME_REPLAY=1: interpolated frames (docs/native-gameplay/FRAME_DECOUPLING.md). The GS
    // input of each displayed frame (GIF packets, direct register writes) is recorded between
    // scanout flips, with a snapshot of the GS state at its start. Every present replays the
    // newest complete frame on a second GS instance, its vertex positions blended from the frame
    // before by the time elapsed since its flip (one frame of latency, as in RT64).
    struct ReplayItem { uint8_t path = 0, addr = 0; uint64_t value = 0; std::vector<uint64_t> words; size_t bytes = 0; };
    // REO_NATIVE_RENDER=1: the native renderer's picture replaces the GS scanout while a room
    // is loaded (native_render.hpp). Created on first use on the GS worker.
    std::unique_ptr<reo_native_render::Renderer> native_;
    bool nativeFailed_ = false;
    Vulkan::ImageHandle nativeRender() {
        if (!reo::native_render::enabled() || nativeFailed_) return {};
        try {
            if (!native_) native_ = std::make_unique<reo_native_render::Renderer>(*device_);
            return native_->render();
        } catch (const std::exception& e) {
            std::fprintf(stderr, "[NATIVE-RENDER] disabled: %s\n", e.what());
            nativeFailed_ = true; native_.reset();
            return {};
        }
    }
    static constexpr uint8_t ReplayClearPath = 0xFE;  // item: clearContext(addr, value lo, value bit 32)
    struct ReplayFrame { std::vector<ReplayItem> items; size_t bytes = 0; bool overflow = false; };
    // Diagnostics: REO_FRAME_REPLAY_DEBUG=record (record only) | snapshot (snapshot only) |
    // exact (every 30th new frame: replay it unblended and compare with the real scanout).
    static int replayDebug() {
        static const int mode = [] { const char* v = std::getenv("REO_FRAME_REPLAY_DEBUG");
            return !v ? 0 : std::strcmp(v, "record") == 0 ? 1 : std::strcmp(v, "snapshot") == 0 ? 2
                : std::strcmp(v, "exact") == 0 ? 3 : 0; }();
        return mode;
    }
    static bool replayEnabled() {
        static const bool on = [] { const char* v = std::getenv("REO_FRAME_REPLAY"); return v && v[0] == '1' && !v[1]; }();
        return on;
    }
    std::unique_ptr<GSInterface> replayGs_;
    GSOptions replayOptions_{};
    GSInterface::ReplaySnapshot replayRecordingStart_, replayCurrentStart_;
    ReplayFrame replayRecording_, replayCurrent_, replayPrevious_;
    Privileged replayRegisters_{};
    VSyncInfo replayInfo_{};
    bool replayCurrentValid_ = false, replayPreviousValid_ = false, replayFailed_ = false;
    uint32_t replayLastFbp_ = 0xFFFFFFFFu;
    std::chrono::steady_clock::time_point replayFlip_{};
    double replayIntervalMs_ = 1000.0 / 60.0;
    uint64_t replayFrames_ = 0, replayPresents_ = 0, replayPairs_ = 0, replayVertices_ = 0, replayKept_ = 0;
    std::vector<uint64_t> replayScratch_;
    uint64_t replayLoadedFrame_ = ~0ull, replayFlips_ = 0;
    double replayRenderMs_ = 0, replayRenderMax_ = 0;
    uint64_t replayVerifiedFrame_ = ~0ull, replayDirectWrites_ = 0, replaySkipped_ = 0;

    void replayRecordGif(uint8_t path, const uint8_t* data, size_t bytes) {
        if (replayDebug() == 2) return;
        auto& f = replayRecording_;
        if (f.overflow) return;
        if (f.bytes + bytes > (48u << 20)) { f.overflow = true; f.items.clear(); return; }
        ReplayItem item;
        item.path = path; item.bytes = bytes;
        item.words.resize((bytes + 7) / 8);
        std::memcpy(item.words.data(), data, bytes);
        f.bytes += bytes;
        f.items.push_back(std::move(item));
    }
    void replayRecordRegister(uint8_t addr, uint64_t value) {
        if (replayDebug() == 2 || replayRecording_.overflow) return;
        ReplayItem item; item.addr = addr; item.value = value;
        replayRecording_.items.push_back(std::move(item));
    }
    // At a scanout flip to a new picture: the recorded frame becomes current, the old current
    // becomes previous, and the GS state now is the next frame's start.
    // REO_GIF_DUMP_AT=N (with REO_FRAME_REPLAY=1, REO_FRAME_REPLAY_DUMP=<dir>): write the GS input
    // of displayed frames N..N+2 (counted in flips) to gif_<n>.bin for offline analysis
    // (tools/native_render). Per item: u8 path (0 = register write, 0xFE = clear), u8 addr,
    // u16 0, u32 bytes, u64 value, then the packet bytes.
    void replayDumpRecording() {
        static const long long at = [] { const char* v = std::getenv("REO_GIF_DUMP_AT"); return v ? std::atoll(v) : -1ll; }();
        const char* dir = std::getenv("REO_FRAME_REPLAY_DUMP");
        ++replayFlips_;
        if (at < 0 || !dir || replayFlips_ < uint64_t(at) || replayFlips_ >= uint64_t(at) + 3) return;
        char name[1024];
        std::snprintf(name, sizeof(name), "%s/gif_%llu.bin", dir, (unsigned long long)replayFlips_);
        FILE* out = std::fopen(name, "wb");
        if (!out) return;
        for (const auto& item : replayRecording_.items) {
            const uint8_t head[4] = {item.path, item.addr, 0, 0};
            const uint32_t bytes = uint32_t(item.bytes);
            std::fwrite(head, 1, 4, out); std::fwrite(&bytes, 4, 1, out); std::fwrite(&item.value, 8, 1, out);
            if (bytes) std::fwrite(item.words.data(), 1, bytes, out);
        }
        std::fclose(out);
        std::fprintf(stderr, "[GIF-DUMP] %s items=%zu overflow=%d\n", name, replayRecording_.items.size(), int(replayRecording_.overflow));
    }
    void replayRotate(const Capture& capture, const VSyncInfo& info) {
        replayDumpRecording();
        const auto now = std::chrono::steady_clock::now();
        if (replayFlip_.time_since_epoch().count()) {
            const double ms = std::chrono::duration<double, std::milli>(now - replayFlip_).count();
            replayIntervalMs_ = std::clamp(ms, 8.0, 100.0);
        }
        replayFlip_ = now;
        if (replayRecordingStart_.valid) {
            replayPrevious_ = std::move(replayCurrent_);
            replayPreviousValid_ = replayCurrentValid_;
            replayCurrent_ = std::move(replayRecording_);
            std::swap(replayCurrentStart_, replayRecordingStart_);
            // Movie uploads and resident commands write VRAM outside the recorded stream.
            replayCurrentValid_ = !replayCurrent_.overflow && gs_->direct_writes == replayDirectWrites_;
            if (!replayCurrentValid_) ++replaySkipped_;
            replayRegisters_ = capture.registers;
            replayInfo_ = info;
            ++replayFrames_;
        }
        static unsigned logged = 0;
        const auto begin = std::chrono::steady_clock::now();
        const size_t items = replayRecording_.items.size(), bytes = replayRecording_.bytes;
        replayRecording_ = {};
        replayDirectWrites_ = gs_->direct_writes;
        if (replayDebug() != 1) gs_->replay_snapshot(replayRecordingStart_);
        else replayRecordingStart_.valid = false;
        if (logged < 12) {
            ++logged;
            std::fprintf(stderr, "[FRAME-REPLAY] rotate=%llu items=%zu bytes=%zu snapshot_ms=%.2f\n", (unsigned long long)replayFrames_,
                         items, bytes, std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - begin).count());
        }
    }
    // Replays the current frame with vertices blended from the previous one (k = 0: previous
    // positions, k = 1: the current frame exactly). Empty when unavailable.
    Vulkan::ImageHandle replayRender(float k, bool exact = false) {
        if (replayDebug() == 1 || replayDebug() == 2 || replayFailed_ || !replayCurrentValid_ || !replayCurrentStart_.valid)
            return {};
        if (!replayGs_)
            return {};
        // VRAM is restored for every replay (frames may blend onto the existing framebuffer);
        // cached textures are dropped only when the recorded frame changes.
        // Nothing to blend (k = 1, a menu or cut whose stream changed shape): the real frame is
        // shown, so replays cost nothing outside matched gameplay frames.
        const bool pair = !exact && replayPreviousValid_ && k < 0.999f && replayPrevious_.items.size() == replayCurrent_.items.size();
        if (!pair && !exact) return {};
        const auto renderBegin = std::chrono::steady_clock::now();
        replayGs_->replay_restore(replayCurrentStart_, replayLoadedFrame_ != replayFrames_);
        replayLoadedFrame_ = replayFrames_;
        if (pair) ++replayPairs_;
        reo::frame_replay::BlendStats stats;
        for (size_t i = 0; i < replayCurrent_.items.size(); ++i) {
            const auto& item = replayCurrent_.items[i];
            if (!item.path) { replayGs_->write_register(static_cast<RegisterAddr>(item.addr), item.value); continue; }
            if (item.path == ReplayClearPath) {
                runContextClear(*replayGs_, item.addr, uint32_t(item.value), (item.value >> 32) & 1);
                continue;
            }
            const uint64_t* source = item.words.data();
            if (pair) {
                const auto& before = replayPrevious_.items[i];
                if (before.path == item.path && before.bytes == item.bytes) {
                    replayScratch_.resize(item.words.size());
                    if (reo::frame_replay::blend_gif(item.words.data(), before.words.data(), replayScratch_.data(),
                                                     item.words.size(), k, &stats))
                        source = replayScratch_.data();
                }
            }
            replayGs_->gif_transfer(item.path - 1, source, item.bytes);
        }
        replayVertices_ += stats.vertices; replayKept_ += stats.kept;
        auto& priv = replayGs_->get_priv_register_state();
        for (size_t i = 0; i < 15; ++i) {
            const uint32_t offset = privilegedOffsets[i];
            (offset < 0x1000 ? priv.qwords_lo[offset / 8] : priv.qwords_hi[(offset - 0x1000) / 8]) = replayRegisters_[i];
        }
        replayGs_->replay_flush();
        auto scan = replayGs_->vsync(replayInfo_);
        // Submit everything the scanout recorded: the renderer keeps command buffers open between
        // calls, and the device cannot advance its frame (the game's own GS flush) while any
        // command buffer requested in that frame is still unsubmitted.
        replayGs_->replay_flush();
        const double renderMs = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - renderBegin).count();
        replayRenderMs_ += renderMs; replayRenderMax_ = std::max(replayRenderMax_, renderMs);
        if (++replayPresents_ <= 3 || replayPresents_ % 600 == 0) {
            std::fprintf(stderr, "[FRAME-REPLAY] render=%llu k=%.2f items=%zu image=%d avg_ms=%.2f max_ms=%.2f vertices=%llu kept=%llu\n",
                         (unsigned long long)replayPresents_, k, replayCurrent_.items.size(), int(bool(scan.image)),
                         replayRenderMs_ / double(replayPresents_), replayRenderMax_, (unsigned long long)replayVertices_,
                         (unsigned long long)replayKept_);
            replayRenderMax_ = 0;
        }
        return scan.image;
    }
    float replayPhase() const {
        if (!replayFlip_.time_since_epoch().count()) return 1.f;
        const double ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - replayFlip_).count();
        return float(std::clamp(ms / replayIntervalMs_, 0.0, 1.0));
    }
    void reportMemory() {
        const char* option = std::getenv("REO_GPU_MEMORY_LOG");
        if (!option || std::strcmp(option, "1") != 0 || memoryLogFrames_++ % 120)
            return;
        Vulkan::HeapBudget heaps[VK_MAX_MEMORY_HEAPS]{};
        device_->get_memory_budget(heaps);
        const auto& properties = device_->get_memory_properties();
        for (uint32_t i = 0; i < properties.memoryHeapCount; ++i)
            std::fprintf(stderr, "[GPU-MEMORY] heap=%u local=%u size_mib=%llu budget_mib=%llu tracked_mib=%llu usage_mib=%llu\n",
                i, (properties.memoryHeaps[i].flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT) ? 1u : 0u,
                static_cast<unsigned long long>(heaps[i].max_size >> 20),
                static_cast<unsigned long long>(heaps[i].budget_size >> 20),
                static_cast<unsigned long long>(heaps[i].tracked_usage >> 20),
                static_cast<unsigned long long>(heaps[i].device_usage >> 20));
    }
    Init init_;
    std::unique_ptr<Context> context_;
    std::unique_ptr<Device> device_;
    std::unique_ptr<reo_resident_live::SemanticOwner> residentGeometry_;
    bool residentResetReady_ = false;
    std::unique_ptr<GSInterface> gs_;
    std::unique_ptr<reo_gpu_clear_context::ClearContext> contextClear_;
    std::shared_ptr<reo_movie_owner::Target> movieOwner_;
    bool movieEnabled_ = false;
#if defined(_WIN32)
    std::unique_ptr<reo_gpu_present::ResidentDxgiPresenter> presenter_;
#elif defined(REO_MACOS_METAL_PRESENT)
    std::unique_ptr<reo_gpu_present::ResidentMetalPresenter> presenter_;
#elif defined(REO_LINUX_XLIB_PRESENT)
    std::unique_ptr<reo_gpu_present::ResidentXlibPresenter> presenter_;
#endif
    reo_gpu_present::ResidentOwnerImages displayImages_;
    reo::performance::FrameTrace frameTrace_;
    uint64_t staleScanouts_ = 0;
    unsigned consecutiveStale_ = 0;
    std::array<uint64_t, 2> lastScanoutMode_{};
    bool lastScanoutProgressive_ = false;
    uint64_t normalDownloads_ = 0, outputReadbacks_ = 0;
    BufferHandle captureReadback_;
    size_t captureReadbackBytes_ = 0;
    cache_store::Identity cacheIdentity_{};
    std::filesystem::path cachePath_;
    bool cacheReady_ = false;
    GifBoundaryObserver observer_;
    ByteFifo fifo_;
    struct Event {
        uint8_t addr;
        uint64_t payload;
    };
    std::vector<Event> events_;
    // Resumable second-SIGNAL handling, following PCSX2's queued-SIGNAL and
    // CSR-acknowledgment behavior. When a SIGNAL event is completed while the
    // previous SIGNAL event flag (CSR bit 0) is still set, the GIF packet path
    // halts exactly at that event instead of failing: the pending SIGNAL and
    // every later event stay queued, freshly arriving packets are held with
    // their already-observed boundary list, and direct register writes are
    // held as raw lanes. The guest's CSR acknowledgment (W1C write on the
    // event lanes) releases the halt; held work then resumes strictly in the
    // original arrival order and each held event is delivered exactly once.
    // No state waits for the acknowledgment: while halted this backend never
    // blocks a call, it only buffers, so the CSR write can always reach it.
    struct PendingPacket {
        uint8_t path = 0;          // GIF path the packet arrived on
        std::vector<uint8_t> data; // unconsumed packet bytes (16B aligned length)
        std::vector<GifBoundaryObserver::Boundary> boundaries; // observed once at arrival
        size_t next = 0;                                       // first boundary not yet handled
        size_t consumed = 0;                                   // bytes already handed to paraLLEl
    };
    struct PendingRegister {
        uint8_t addr = 0;
        uint64_t value = 0;
    };
    struct PendingWork {
        bool isPacket = false; // false: direct register lane
        PendingPacket packet{};
        PendingRegister register_{};
    };
    std::deque<PendingWork> heldWork_; // arrival order across packets and registers
    bool gifHalted_ = false;           // paused at a queued second-SIGNAL event
    bool deliveringEvents_ = false;    // inside completeEvents() delivery loop
    bool live_ = false;
    void installMovieOwner() {
#if defined(_WIN32)
        if (movieEnabled_) {
            movieOwner_ = reo_gpu_movie::makeMovieOwnerService(
                *device_, *gs_, reo_resident_live::currentGsEpoch(),
                [this](uint32_t bytes) { observer_.consumeImage(3u, bytes); });
            reo_movie_owner::installActualOwner(movieOwner_);
        }
#endif
    }
    void retireMovieOwner() noexcept {
        if (movieOwner_) {
            reo_movie_owner::retireActualOwner(movieOwner_);
            movieOwner_->stop();
            movieOwner_.reset();
        }
    }
    void initializePipelineCache() {
        if (!config_.persistentPipelineCache)
            return;
        const auto& props = device_->get_gpu_properties();
        cacheIdentity_.format =
            device_->get_device_features().pipeline_binary_features.pipelineBinaries ? 1 : 0;
        cacheIdentity_.vendor = props.vendorID;
        cacheIdentity_.device = props.deviceID;
        cacheIdentity_.driver = props.driverVersion;
        cacheIdentity_.flags = config_.descriptorBuffer ? 1 : 0;
        std::memcpy(cacheIdentity_.uuid.data(), props.pipelineCacheUUID, 16);
        std::vector<uint8_t> payload;
        try {
            cachePath_ = config_.pipelineCacheFile.empty()
                             ? cache_store::defaultPath(cacheIdentity_)
                             : std::filesystem::u8path(config_.pipelineCacheFile);
            payload = cache_store::load(cachePath_, cacheIdentity_);
        } catch (...) {
            payload.clear();
            cachePath_.clear();
        }
        try {
            cacheReady_ = device_->init_pipeline_cache(payload.empty() ? nullptr : payload.data(),
                                                       payload.size(), false);
        } catch (...) {
            cacheReady_ = false;
        }
        if (!cacheReady_)
            try {
                cacheReady_ = device_->init_pipeline_cache(nullptr, 0, false);
            } catch (...) {
                cacheReady_ = false;
            }
        std::fprintf(stderr,
                     "[GS-PIPELINE-CACHE] submitted_bytes=%zu ready=%u format=%u disk_path=%u\n",
                     payload.size(), unsigned(cacheReady_), cacheIdentity_.format,
                     unsigned(!cachePath_.empty()));
    }
    void persistPipelineCache() noexcept {
        if (!cacheReady_ || cachePath_.empty())
            return;
        try {
            const size_t size = device_->get_pipeline_cache_size();
            bool saved = false;
            if (size && size <= cache_store::MaxPayload) {
                std::vector<uint8_t> payload(size);
                if (device_->get_pipeline_cache_data(payload.data(), payload.size()))
                    saved = cache_store::save(cachePath_, payload, cacheIdentity_);
            }
            std::fprintf(stderr, "[GS-PIPELINE-CACHE] save_bytes=%zu saved=%u\n", size,
                         unsigned(saved));
        } catch (...) {
            std::fprintf(stderr, "[GS-PIPELINE-CACHE] save_failed=1\n");
        }
    }
    void requireLive() const {
        if (!live_ || !gs_ || !device_)
            throw std::runtime_error("GPU backend is not live");
    }
    bool on_signal(uint64_t p) override {
        events_.push_back({0x60, p});
        return true;
    }
    bool on_finish(uint64_t p) override {
        events_.push_back({0x61, p});
        return true;
    }
    bool on_label(uint64_t p) override {
        events_.push_back({0x62, p});
        return true;
    }
    uint64_t& privWord(uint32_t offset) {
        auto& p = gs_->get_priv_register_state();
        return offset < 0x1000 ? p.qwords_lo[offset / 8] : p.qwords_hi[(offset - 0x1000) / 8];
    }
    Privileged copyPrivileged() {
        Privileged out{};
        for (size_t i = 0; i < out.size(); ++i)
            out[i] = privWord(privilegedOffsets[i]);
        return out;
    }
    bool refreshEventFront() {
        if (!config_.peekEventFrontState)
            return true;
        const auto front = config_.peekEventFrontState();
        if (!front)
            return false;
        privWord(0x1000) = (privWord(0x1000) & ~0x1Full) | ((*front)[15] & 0x1Full);
        privWord(0x1010) = (*front)[16];
        privWord(0x1080) = (*front)[18];
        return true;
    }
    // True while the guest-visible CSR SIGNAL event flag is still set. Uses the
    // same authority completeEvents publishes through, so the acknowledgment
    // cannot race the halt decision.
    bool csrSignalPending() {
        if (!refreshEventFront())
            return false; // owner front retired: no SIGNAL authority
        return (privWord(0x1000) & 1u) != 0u;
    }
    void completeEvents() {
        if (gifHalted_)
            return; // Frontier events stay queued; the CSR acknowledgment resumes them.
        if (deliveringEvents_)
            return; // Reentrant guard: a completion callback (which may
        // read back VRAM) must never re-enter event delivery - the caller that
        // erased nothing would redeliver the same event forever.
        if (events_.empty())
            return;
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        gs_->flush();
        // Correctness-first prefix fence. This is a host GPU wait only: no
        // guest execution or IO lock. A narrower timeline fence may replace it
        // only after its exact completion coverage has been demonstrated.
        device_->wait_idle();
        // Deliver in original event order. A SIGNAL while the previous SIGNAL
        // event flag is still set halts the packet path there: this and every
        // later event stay queued for the guest's CSR acknowledgment, which
        // resumes through releaseQueuedFrontier(). This replaces the former
        // port blocker with an owned, resumable barrier.
        size_t delivered = 0;
        bool dropRemaining = false;
        deliveringEvents_ = true; // cleared with the completion of delivery, exceptions included
        struct DeliveryGuard {
            bool& flag;
            ~DeliveryGuard() {
                flag = false;
            }
        } deliveryGuard{deliveringEvents_};
        while (delivered < events_.size()) {
            const Event event = events_[delivered];
            if (!refreshEventFront()) {
                // Owner execution front retired (epoch change/reset): the
                // remaining queue is stale by definition. Drop without
                // delivery so old events are never replayed into a new epoch.
                dropRemaining = true;
                break;
            }
            if (event.addr == 0x60 && (privWord(0x1000) & 1u)) {
                gifHalted_ = true;
                break;
            }
            auto& status = privWord(0x1000);
            auto& ids = privWord(0x1080);
            if (event.addr == 0x60) {
                const uint32_t mask = uint32_t(event.payload >> 32), id = uint32_t(event.payload);
                ids = (ids & 0xFFFFFFFF00000000ull) | ((uint32_t(ids) & ~mask) | (id & mask));
                status |= 1u;
            } else if (event.addr == 0x61)
                status |= 2u;
            else {
                const uint32_t mask = uint32_t(event.payload >> 32), id = uint32_t(event.payload);
                const uint32_t hi = (uint32_t(ids >> 32) & ~mask) | (id & mask);
                ids = (uint64_t(hi) << 32) | uint32_t(ids);
            }
            if (init_.completedEvent)
                init_.completedEvent(event.addr, event.payload);
            refreshEventFront();
            ++delivered;
        }
        if (dropRemaining)
            events_.clear();
        else if (delivered)
            events_.erase(events_.begin(), events_.begin() + std::ptrdiff_t(delivered));
    }
    // Called from the CSR acknowledgment path in privilegedWrite. The halt is
    // released only when the SIGNAL event flag now reads clear under the same
    // authority the delivery used. Nothing here waits: the caller is the guest
    // acknowledgment itself (or the reset path), already serialized on Route.
    void releaseQueuedFrontier() {
        if (!gifHalted_)
            return;
        if (!refreshEventFront()) {
            // Owner execution front retired while stalled (epoch change/stop):
            // the halt and every held item are stale for the new epoch. Drop
            // them without delivery so nothing is replayed across the epoch
            // boundary; RESET builds the fresh state from here.
            gifHalted_ = false;
            events_.clear();
            heldWork_.clear();
            return;
        }
        if (privWord(0x1000) & 1u)
            return; // pending SIGNAL still unacknowledged
        gifHalted_ = false;
        completeEvents(); // deliver the held SIGNAL and any already-queued events, exactly once
        if (gifHalted_)
            return; // a later queued SIGNAL engaged the halt again
        // Resume held work strictly in arrival order. While partially consumed,
        // a packet stays at the front of heldWork_ with its parser position
        // (consumed/next) intact, so a re-engaged halt resumes exactly there.
        while (!gifHalted_ && !heldWork_.empty()) {
            PendingWork& work = heldWork_.front();
            if (!work.isPacket) {
                PendingRegister item = work.register_;
                heldWork_.pop_front();
                if (residentGeometry_)
                    residentGeometry_->guardPublishedEffects();
                gs_->write_register(static_cast<RegisterAddr>(item.addr), item.value);
                if (item.addr == 0x53)
                    transferBoundary(item.value);
                else
                    completeEvents();
                continue;
            }
            PendingPacket& item = work.packet;
            if (item.consumed >= item.data.size()) {
                heldWork_.pop_front();
                continue;
            }
            if (residentGeometry_)
                residentGeometry_->guardPublishedEffects();
            std::vector<uint64_t> aligned(item.data.size() / 8);
            std::memcpy(aligned.data(), item.data.data(), item.data.size());
            const auto* input = reinterpret_cast<const uint8_t*>(aligned.data());
            while (item.next < item.boundaries.size()) {
                const auto& boundary = item.boundaries[item.next];
                if (boundary.end > item.consumed) {
                    gs_->gif_transfer(item.path - 1, input + item.consumed,
                                      boundary.end - item.consumed);
                    item.consumed = boundary.end;
                }
                ++item.next;
                if (boundary.addr == 0x53)
                    transferBoundary(boundary.value);
                else
                    completeEvents();
                if (gifHalted_)
                    return; // position preserved inside heldWork_.front()
            }
            if (item.consumed < item.data.size()) {
                gs_->gif_transfer(item.path - 1, input + item.consumed,
                                  item.data.size() - item.consumed);
                item.consumed = item.data.size();
            }
            completeEvents(); // trailing events of the held packet
            if (gifHalted_)
                return;            // position preserved; next release resumes the tail
            heldWork_.pop_front(); // packet fully processed
        }
    }
    // Absolute held-work report for the runtime accounting (see the route
    // header). Packet bytes parked behind the SIGNAL are counted; held
    // register lanes count as zero bytes, matching their zero queue charge.
    // Called under Route serialization, so the walk observes a stable hold.
    size_t heldGifBytes() const noexcept override {
        size_t bytes = 0;
        for (const auto& work : heldWork_)
            if (work.isPacket)
                bytes += work.packet.data.size();
        return bytes;
    }
    size_t heldGifCount() const noexcept override {
        // Parked packets/lanes PLUS the events still queued behind the halt.
        // A SIGNAL at a packet's final boundary parks no bytes (empty suffix)
        // yet must still report as outstanding work until it is delivered or
        // explicitly canceled; a zero-item report while an event awaits
        // acknowledgment would hide ownership from the runtime accounting.
        return heldWork_.size() + (gifHalted_ ? events_.size() : 0u);
    }
    void transferBoundary(uint64_t value) {
        if ((uint32_t(value) & 3u) != 1u) {
            fifo_.clear();
            return;
        }
        // The original GS TRXDIR has already completed GPU format conversion.
        // Retain its complete byte tail instead of repeating CPU unswizzle.
        fifo_.replace(gs_->resident_transfer_readback());
    }
    Frame download(const ScanoutResult& scanout, uint64_t tick, const Capture& capture) {
        if (!capture.forceHostReadback)
            ++normalDownloads_;
        Frame frame;
        frame.tick = tick;
        const size_t circuit = (capture.registers[0] & 1u) ? 7 : 9;
        frame.displayFbp = uint32_t(capture.registers[circuit] & 0x1FF);
        frame.sourceFbp = frame.displayFbp;
        if (!scanout.image)
            return frame;
        const auto& ci = scanout.image->get_create_info();
        const bool bgra =
            ci.format == VK_FORMAT_B8G8R8A8_UNORM || ci.format == VK_FORMAT_B8G8R8A8_SRGB;
        if (!bgra && ci.format != VK_FORMAT_R8G8B8A8_UNORM && ci.format != VK_FORMAT_R8G8B8A8_SRGB)
            throw std::runtime_error("Unexpected GPU scanout format");
        if (ci.width > 4096 || ci.height > 4096)
            throw std::runtime_error("Oversized GPU scanout");
        frame.width = ci.width;
        frame.height = ci.height;
        frame.rgba.resize(size_t(ci.width) * ci.height * 4);
        if (!captureReadback_ || captureReadbackBytes_ < frame.rgba.size()) {
            BufferCreateInfo info{};
            info.domain = BufferDomain::CachedHost;
            info.size = frame.rgba.size();
            info.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            auto allocated = device_->create_buffer(info);
            if (!allocated)
                throw std::runtime_error("GPU scanout readback allocation failed");
            captureReadback_ = std::move(allocated);
            captureReadbackBytes_ = frame.rgba.size();
        }
        // Previous capture returned only after its copy fence and CPU unmap;
        // serialized Route ownership makes this staging allocation reusable.
        const auto& buffer = captureReadback_;
        device_->wait_idle();
        auto cmd = device_->request_command_buffer();
        cmd->image_barrier(*scanout.image, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL,
                           VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        VkBufferImageCopy copy{};
        copy.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        copy.imageSubresource.layerCount = 1;
        copy.imageExtent = {ci.width, ci.height, 1};
        cmd->copy_image_to_buffer(*buffer, *scanout.image, 1, &copy);
        cmd->buffer_barrier(*buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                            VK_PIPELINE_STAGE_HOST_BIT, VK_ACCESS_2_HOST_READ_BIT);
        cmd->image_barrier(*scanout.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                           VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                           VK_ACCESS_2_SHADER_SAMPLED_READ_BIT);
        Fence fence;
        device_->submit(cmd, &fence);
        fence->wait();
        const auto* pixels =
            static_cast<const uint8_t*>(device_->map_host_buffer(*buffer, MEMORY_ACCESS_READ_BIT));
        if (!pixels)
            throw std::runtime_error("GPU scanout readback mapping failed");
        std::memcpy(frame.rgba.data(), pixels, frame.rgba.size());
        device_->unmap_host_buffer(*buffer, MEMORY_ACCESS_READ_BIT);
        if (bgra)
            for (size_t i = 0; i < frame.rgba.size(); i += 4)
                std::swap(frame.rgba[i], frame.rgba[i + 2]);
        return frame;
    }

  public:
    reo_parallel_backend::ResidentDiagnostics diagnostics() const {
#if defined(_WIN32) || defined(REO_LINUX_XLIB_PRESENT) || defined(REO_MACOS_METAL_PRESENT)
        const uint64_t presented = presenter_ ? presenter_->submittedFrames() : 0;
#else
        const uint64_t presented = 0;
#endif
        return {presented,
                normalDownloads_,
                outputReadbacks_,
                displayImages_.serial(),
                displayImages_.fenceWaits(),
                displayImages_.liveImages()};
    }
    Privileged snapshot() {
        ThreadIndexScope threadIndex;
        requireLive();
        return copyPrivileged();
    }
    bool soundRamProfileObservedV1() const noexcept {
        return live_ && !config_.residentGeometry.enabled &&
            !reo_parent_natural::actualFirstEntryEnrollmentRequested() &&
            !reo_parent_natural::anyActualOwnerBound();
    }
    explicit ParallelBackend(Config config) : config_(std::move(config)) {
#if defined(_WIN32)
        const auto* movie = std::getenv("REO_GPU_MOVIE");
        movieEnabled_ = movie && std::strcmp(movie, "1") == 0;
#endif
    }
    ~ParallelBackend() override {
        close();
    }
    bool init(const Init& value, std::string& error) override {
        ThreadIndexScope threadIndex;
        close();
        if (!config_.validatedDrawing) {
            error = "Clean GPU draw/replay gate is not approved";
            return false;
        }
        if (!config_.publishPrivilegedReset) {
            error = "Coherent guest privileged reset publication is not installed";
            return false;
        }
        if (!config_.peekEventFrontState && !config_.publishStatusAck) {
            error = "Ordered guest CSR acknowledgment publication is not installed";
            return false;
        }
        if (!value.vram || value.vramSize != VramSize) {
            error = "Expected 4 MiB GS VRAM";
            return false;
        }
        init_ = value;
        if (!Context::init_loader(nullptr)) {
            error = "Vulkan loader initialization failed";
            return false;
        }
        context_ = std::make_unique<Context>();
        context_->set_num_thread_indices(1);
        const unsigned flags =
            CONTEXT_CREATION_ENABLE_PUSH_DESCRIPTOR_BIT |
            CONTEXT_CREATION_ENABLE_DESCRIPTOR_HEAP_BIT |
#if defined(_WIN32)
            // Keep command checkpoints when upscaling. On the RX 570, removing these
            // markers reproducibly loses the device during the startup draw;
            // with them the same run reaches gameplay. This is a compatibility
            // workaround, and retains post-mortem evidence if a failure recurs.
            (internalResolution_ > 1 ? CONTEXT_CREATION_ENABLE_POST_MORTEM_BIT : 0) |
#endif
            (config_.descriptorBuffer ? CONTEXT_CREATION_ENABLE_DESCRIPTOR_BUFFER_BIT : 0);
        bool initialized = false;
#if defined(_WIN32)
        if (config_.residentPresentation) {
            // The DXGI bridge uses PRESENT_SRC_KHR for external image
            // ownership transitions, requiring the swapchain extension.
            // Also enable VK_KHR_win32_surface so drivers without D3D12-Vulkan
            // external interop (e.g. Intel Iris Xe, #104) can present directly
            // through a native Win32 Vulkan swapchain.
            const char* instanceExtensions[] = {"VK_KHR_surface", "VK_KHR_win32_surface"};
            const char* deviceExtensions[] = {"VK_KHR_swapchain"};
            initialized = context_->init_instance_and_device(instanceExtensions, 2,
                                                              deviceExtensions, 1, flags);
            if (!initialized)
                initialized = context_->init_instance_and_device(instanceExtensions, 1,
                                                                  deviceExtensions, 1, flags);
        } else
#endif
#if defined(REO_MACOS_METAL_PRESENT)
        if (config_.residentPresentation) {
            const char* instanceExtensions[] = {"VK_KHR_surface", "VK_EXT_metal_surface"};
            const char* deviceExtensions[] = {"VK_KHR_swapchain"};
            initialized = context_->init_instance_and_device(instanceExtensions, 2,
                                                              deviceExtensions, 1, flags);
        } else
#endif
#if defined(REO_LINUX_XLIB_PRESENT)
        if (config_.residentPresentation) {
            const char* instanceExtensions[] = {"VK_KHR_surface", "VK_KHR_xlib_surface"};
            const char* deviceExtensions[] = {"VK_KHR_swapchain"};
            initialized = context_->init_instance_and_device(instanceExtensions, 2,
                                                              deviceExtensions, 1, flags);
        } else
#endif
            initialized = context_->init_instance_and_device(nullptr, 0, nullptr, 0, flags);
        if (!initialized) {
            error = "Vulkan device initialization failed";
            close();
            return false;
        }
        device_ = std::make_unique<Device>();
        device_->set_context(*context_);
        device_->init_frame_contexts(4);
        initializePipelineCache();
#if defined(_WIN32) || defined(REO_LINUX_XLIB_PRESENT) || defined(REO_MACOS_METAL_PRESENT)
        if (config_.residentPresentation) {
            displayImages_.beginSession();
            if (!config_.presentationTarget || !config_.presentationEpochCurrent ||
                config_.presentationVertex.empty() || config_.presentationFragment.empty()) {
                error = "Resident presentation configuration is incomplete";
                close();
                return false;
            }
#if defined(_WIN32)
            presenter_ = std::make_unique<reo_gpu_present::ResidentDxgiPresenter>(
#elif defined(REO_MACOS_METAL_PRESENT)
            presenter_ = std::make_unique<reo_gpu_present::ResidentMetalPresenter>(
#else
            presenter_ = std::make_unique<reo_gpu_present::ResidentXlibPresenter>(
#endif
                *device_, config_.presentationVertex, config_.presentationFragment);
        }
#else
        if (config_.residentPresentation) {
            error = "Resident DXGI presentation requires Windows";
            close();
            return false;
        }
#endif
        // GSInterface otherwise silently clamps unsupported sampling rates.
        // Reject an unavailable 4x mode rather than report a lower resolution
        // as the requested quality. Match GSRenderer's X16 capability check.
        if (internalResolution_ == 4 && !device_->supports_subgroup_size_log2(true, 4, 6)) {
#if defined(__APPLE__)
            // Apple GPUs (MoltenVK) lack the subgroup-size control 4x needs. Falling back
            // to the CPU renderer would make movies and gameplay slow; use 2x on the GPU.
            std::fprintf(stderr, "[INTERNAL-RESOLUTION-1] 4x is unavailable on this GPU; using 2x\n");
            internalResolution_ = 2;
#else
            error = "4x internal resolution is unavailable on this GPU. Select 2x or Native.";
            close();
            return false;
#endif
        }
        gs_ = std::make_unique<GSInterface>();
        GSOptions options{};
        // Ordered samples form a 2x2 or 4x4 grid for higher-resolution scanout.
        options.super_sampling = internalResolution_ == 4 ? SuperSampling::X16
                               : internalResolution_ == 2 ? SuperSampling::X4
                                                          : SuperSampling::X1;
        options.ordered_super_sampling = true;
        // Preserve the existing texture resolve policy; geometry still uses
        // distinct samples at the selected internal resolution.
        options.super_sampled_textures = false;
        std::fprintf(stderr,"[INTERNAL-RESOLUTION-1] scale=%u samples=%u\n",
                     internalResolution_,internalResolution_ * internalResolution_);
        replayOptions_ = options;
        if (!gs_->init(device_.get(), options)) {
            error = "paraLLEl-GS initialization failed";
            close();
            return false;
        }
        // The frame-replay instance is created here, next to the main one: GSRenderer::init
        // waits for the device to go idle, which on the GS worker could wait on the main
        // instance's open command buffers.
        if (replayEnabled()) {
            replayGs_ = std::make_unique<GSInterface>();
            replayGs_->set_secondary_instance();
            if (!replayGs_->init(device_.get(), options)) {
                std::fprintf(stderr, "[FRAME-REPLAY] second GS instance unavailable; interpolation off\n");
                replayGs_.reset(); replayFailed_ = true;
            }
        }
        std::memcpy(gs_->map_vram_write(0, VramSize), value.vram, VramSize);
        gs_->end_vram_write(0, VramSize);
        for (size_t i = 0; i < value.registers.size(); ++i)
            privWord(privilegedOffsets[i]) = value.registers[i];
        gs_->set_signal_interface(this);
        installMovieOwner();
        if (config_.residentGeometry.enabled) {
            if ((!config_.residentGeometry.fullProtocolCoverage &&
                 !config_.residentGeometry.authenticColdComponentEnrollment) ||
                !config_.residentGeometry.factory) {
                error = "Resident full VIF/GS protocol is not certified";
                close();
                return false;
            }
            residentGeometry_ = config_.residentGeometry.factory(*device_, *gs_);
            if (!residentGeometry_) {
                error = "Resident geometry owner factory returned null";
                close();
                return false;
            }
            if (config_.residentGeometry.authenticColdComponentEnrollment &&
                (config_.residentGeometry.fullProtocolCoverage ||
                 !residentGeometry_->authenticFirstEntryRequested())) {
                error = "Cold component factory lacks genuine deferred enrollment or claimed full "
                        "coverage";
                close();
                return false;
            }
        }
        reo_parent_natural::setActualFirstEntryEnrollmentRequested(
            residentGeometry_ && residentGeometry_->authenticFirstEntryRequested());
        live_ = true;
        error.clear();
        return true;
    }
    void close() noexcept override {
        ThreadIndexScope threadIndex;
        repeatImage_.reset();
        if (replayEnabled())
            std::fprintf(stderr, "[FRAME-REPLAY] frames=%llu presents=%llu blended_pairs=%llu vertices=%llu kept=%llu skipped_direct=%llu failed=%d\n",
                         (unsigned long long)replayFrames_, (unsigned long long)replayPresents_, (unsigned long long)replayPairs_,
                         (unsigned long long)replayVertices_, (unsigned long long)replayKept_, (unsigned long long)replaySkipped_, int(replayFailed_));
        replayGs_.reset();
        if (native_) std::fprintf(stderr, "[NATIVE-RENDER] frames=%llu\n", (unsigned long long)native_->frames());
        native_.reset();
        replayRecordingStart_ = {}; replayCurrentStart_ = {};
        const bool saveCache = live_ && cacheReady_;
        live_ = false;
        if (staleScanouts_)
            std::fprintf(stderr, "[GS-PRESENT-PACING] retired_stale=%llu\n",
                static_cast<unsigned long long>(staleScanouts_));
        staleScanouts_ = 0;
        consecutiveStale_ = 0;
        lastScanoutProgressive_ = false;
        reo_parent_natural::setActualFirstEntryEnrollmentRequested(false);
        retireMovieOwner();
        if (gs_)
            gs_->set_signal_interface(nullptr);
        try {
            if (gs_)
                gs_->flush();
            if (device_)
                device_->wait_idle();
        } catch (...) {
        }
        gifHalted_ = false;
        heldWork_.clear();
        events_.clear();
        fifo_.clear();
        observer_.reset();
        displayImages_.shutdown();
#if defined(_WIN32) || defined(REO_LINUX_XLIB_PRESENT) || defined(REO_MACOS_METAL_PRESENT)
        if (presenter_ && config_.residentStoppedDiagnostic)
            try {
                config_.residentStoppedDiagnostic(displayImages_.liveImages(),
                                                  displayImages_.fenceWaits());
            } catch (...) {
            }
        presenter_.reset();
#endif
        try {
            if (residentGeometry_)
                residentGeometry_->drainBeforeEpochReset();
        } catch (...) {
        }
        residentGeometry_.reset();
        residentResetReady_ = false;
        contextClear_.reset();
        gs_.reset();
        try {
            if (device_)
                device_->wait_idle();
        } catch (...) {
        }
        // GS destruction drains compilation tasks before cache serialization.
        if (saveCache)
            persistPipelineCache();
        captureReadback_.reset();
        captureReadbackBytes_ = 0;
        cacheReady_ = false;
        cachePath_.clear();
        device_.reset();
        context_.reset();
        init_ = {};
    }
    void reset() override {
        ThreadIndexScope threadIndex;
        requireLive();
        consecutiveStale_ = 0;
        lastScanoutProgressive_ = false;
        if (residentGeometry_ && !residentResetReady_)
            throw std::runtime_error("GS reset lacks real resident retirement/epoch preparation");
        residentResetReady_ = false;
        // A GS RESET cancels the resumable-SIGNAL state FIRST: the halt, every
        // held packet suffix and held lane, and all queued events are
        // discarded before any operation capable of delivering them (the
        // former completeEvents() call here delivered queued events into the
        // fresh GS state). Nothing is replayed across the reset boundary.
        // Cancellation releases the retained ownership exactly once; the
        // runtime observes the emptied hold on its next held-work sample and
        // wakes its waiters from there.
        events_.clear();
        gifHalted_ = false;
        heldWork_.clear();
        displayImages_.retireEpoch();
#if defined(_WIN32) || defined(REO_LINUX_XLIB_PRESENT) || defined(REO_MACOS_METAL_PRESENT)
        if (presenter_)
            presenter_->retireSource();
#endif
        retireMovieOwner();
        gs_->reset_context_state();
        observer_.reset();
        fifo_.clear();
        installMovieOwner();
    }
    void rawGif(uint8_t path, const uint8_t* data, size_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!bytes)
            return;
        if (replayEnabled())
            replayRecordGif(path, data, bytes);
        // Observe exactly once per packet, even while halted: a retried suffix
        // resumes from the stored boundary list instead of advancing the
        // observer a second time.
        const auto boundaries = observer_.observe(path, data, bytes);
        if (gifHalted_) { // Hold the entire incoming packet with its observed boundaries.
            PendingWork work{};
            work.isPacket = true;
            work.packet.path = path;
            work.packet.data.assign(data, data + bytes);
            work.packet.boundaries.assign(boundaries.begin(), boundaries.end());
            heldWork_.push_back(std::move(work));
            return;
        }
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        std::vector<uint64_t> aligned(bytes / 8);
        std::memcpy(aligned.data(), data, bytes);
        const auto* input = reinterpret_cast<const uint8_t*>(aligned.data());
        size_t begin = 0;
        for (size_t index = 0; index < boundaries.size(); ++index) {
            const auto& boundary = boundaries[index];
            gs_->gif_transfer(path - 1, input + begin, boundary.end - begin);
            begin = boundary.end;
            if (boundary.addr == 0x53)
                transferBoundary(boundary.value);
            else
                completeEvents();
            if (gifHalted_) { // Hold the residue of this packet, resumable via the stored list.
                PendingWork work{};
                work.isPacket = true;
                work.packet.path = path;
                work.packet.data.assign(data + begin, data + bytes);
                work.packet.boundaries.reserve(boundaries.size() - index);
                for (size_t rest = index; rest < boundaries.size(); ++rest) {
                    GifBoundaryObserver::Boundary shifted{};
                    shifted.end = boundaries[rest].end - begin;
                    shifted.addr = boundaries[rest].addr;
                    shifted.value = boundaries[rest].value;
                    work.packet.boundaries.push_back(shifted);
                }
                work.packet.next = 1; // the halting boundary was fully handled just above
                work.packet.consumed = 0;
                heldWork_.push_back(std::move(work));
                return;
            }
        }
        if (begin < bytes)
            gs_->gif_transfer(path - 1, input + begin, bytes - begin);
        completeEvents();
    }
    void residentFirstEntry(
        const std::shared_ptr<const reo_parent_natural::ColdEntry>& capture) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("First graphics entry has no same-Device factory owner");
        residentGeometry_->enrollFirstGraphicsEntry(capture);
    }
    void residentParentControl(
        const std::function<void(reo_parent_natural::ControlTarget&)>& call) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_ || !call)
            throw std::runtime_error("No actual connected semantic parent owner");
        residentGeometry_->parentControl(call);
    }
    void residentEnqueue(const reo_resident_live::Batch& batch) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident geometry owner not configured");
        if (replayEnabled()) { replayRecording_.overflow = true; replayRecording_.items.clear(); }
        residentGeometry_->enqueue(batch);
    }
    std::vector<reo_resident_live::Retired> residentRetire(reo_resident_live::Barrier reason,
                                                           uint64_t epoch,
                                                           uint64_t generation) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident geometry retirement owner not configured");
        return residentGeometry_->retire(reason, epoch, generation);
    }
    void residentReadData(uint32_t offset, uint8_t* destination, uint32_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident VU bank owner not configured");
        residentGeometry_->readData(offset, destination, bytes);
    }
    void residentReadControls(uint32_t offset, uint8_t* destination, uint32_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident VIF control owner not configured");
        residentGeometry_->readControls(offset, destination, bytes);
    }
    void residentImportHandoff(reo_resident_live::Handoff& handoff) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident handoff owner not configured");
        residentGeometry_->importHandoff(handoff);
    }
    void residentExportHandoff(reo_resident_live::Handoff& handoff) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident handoff owner not configured");
        residentGeometry_->exportHandoff(handoff);
    }
    void residentPrepareGsReset(uint64_t epoch) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (residentGeometry_) {
            residentGeometry_->prepareGsReset(epoch);
            residentResetReady_ = true;
        }
    }
    void residentRetainFailedLaunch(
        std::vector<reo_resident_live::RetainedLaunchFailure>& out) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident retained-snapshot owner not configured");
        residentGeometry_->retainFailedLaunch(out);
    }
    void directRegister(uint8_t addr, uint64_t value) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (replayEnabled())
            replayRecordRegister(addr, value);
        if (gifHalted_) { // Hold the raw lane; the release replays it in arrival order.
            PendingWork work{};
            work.register_.addr = addr;
            work.register_.value = value;
            heldWork_.push_back(std::move(work));
            return;
        }
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        // Events queued by earlier packets complete first: the direct lane's
        // own event must never overtake them in guest-visible program order.
        completeEvents();
        if (gifHalted_) { // The backlog re-engaged the halt; keep the lane pending.
            PendingWork work{};
            work.register_.addr = addr;
            work.register_.value = value;
            heldWork_.push_back(std::move(work));
            return;
        }
        // paraLLEl executes this write immediately, so a SIGNAL whose event
        // flag is still set must be held BEFORE the write: replaying the held
        // lane later enqueues its event exactly once.
        if (addr == 0x60 && csrSignalPending()) {
            PendingWork work{};
            work.register_.addr = addr;
            work.register_.value = value;
            heldWork_.push_back(std::move(work));
            gifHalted_ = true;
            return;
        }
        gs_->write_register(static_cast<RegisterAddr>(addr), value);
        if (addr == 0x53)
            transferBoundary(value);
        completeEvents();
    }
    void privilegedWrite(uint32_t offset, uint8_t width, uint64_t input) override {
        ThreadIndexScope threadIndex;
        requireLive();
        const uint32_t base = offset & ~15u, lane = offset & 15u;
        if (lane >= 8)
            return; // High half of 128-bit-spaced privileged register.
        if (std::find(privilegedOffsets.begin(), privilegedOffsets.end(), base) ==
            privilegedOffsets.end())
            return;
        if (base == 0x1000) {
            const uint64_t written = mergeLane(0, lane, width, input);
            if (written & (1u << 9)) {
                reset();
                auto& priv = gs_->get_priv_register_state();
                std::memset(&priv, 0, sizeof(priv));
                privWord(0x1010) = 0x7F00;
                privWord(0x1000) = 0x551B4000;
                config_.publishPrivilegedReset(copyPrivileged());
            }
            if (written & (1u << 8))
                flush();
            const uint64_t ack = written & 0x1Fu;
            if (config_.peekEventFrontState)
                refreshEventFront();
            else {
                privWord(0x1000) &= ~ack;
                if (ack)
                    config_.publishStatusAck(ack);
            }
            // Guest CSR acknowledgment (write-one-to-clear on the event lanes)
            // releases a queued second-SIGNAL halt; nothing waited for it, but
            // reaching here while halted means the guest is unblocked now.
            releaseQueuedFrontier();
            return;
        }
        if (base == 0x1010) {
            const uint64_t merged = mergeLane(privWord(base), lane, width, input);
            privWord(base) = (merged & 0x1F00u) | 0x6000u;
            return;
        }
        privWord(base) = mergeLane(privWord(base), lane, width, input);
    }
    // REO_DISPLAY_RATE: show the last displayed image again between guest vblanks. The
    // presenter sees the same display buffer, so it treats this as a repeat and applies the
    // camera warp for the time elapsed since that frame flipped.
    bool presentRepeat() override {
#if defined(_WIN32)
        ThreadIndexScope threadIndex;
        if (!live_ || !presenter_ || !repeatImage_)
            return false;
        const auto target = config_.presentationTarget();
        if (!target.hwnd || !target.width || !target.height)
            return false;
        Vulkan::ImageHandle shown = repeatImage_;
        if (replayEnabled())
            if (auto replayed = replayRender(replayPhase())) shown = replayed;
        if (auto native = nativeRender()) shown = native;
        auto complete = presenter_->present(shown, false, repeatLinear_);
        (void)complete;  // repeatImage_ keeps the source alive until the next scanout
        return true;
#else
        return false;
#endif
    }

    Frame capture(const Capture& capture) override {
        auto timing = frameTrace_.begin(capture.tick);
        ThreadIndexScope threadIndex;
        requireLive();
        reportMemory();
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        completeEvents();
        // Display marker owns display fields. CSR/event IDs stay backend-owned;
        // only FIELD is consumed from the guest clock for scanout phase.
        for (size_t i = 0; i < 15; ++i)
            privWord(privilegedOffsets[i]) = capture.registers[i];
        VSyncInfo info{};
        info.phase = uint32_t(capture.registers[15] >> 13) & 1;
        info.dst_layout = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL;
        info.dst_stage = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
        info.dst_access = VK_ACCESS_2_SHADER_SAMPLED_READ_BIT;
        info.adapt_to_internal_horizontal_resolution = true;
        info.force_progressive = config_.forceProgressive;
        info.anti_blur = config_.antiBlur;
        info.high_resolution_scanout = reo::graphics::highResolutionScanout(
            internalResolution_, capture.registers[0], capture.registers[8], capture.registers[10]);
        gs_->flush();
        if (replayEnabled()) {
            const size_t circuit = (capture.registers[0] & 1u) ? 7 : 9;
            const uint32_t fbp = uint32_t(capture.registers[circuit] & 0x1FF);
            if (fbp != replayLastFbp_) { replayLastFbp_ = fbp; replayRotate(capture, info); }
            // Display registers (PMODE/BGCOLOR fades, DISPLAY) change without a flip: replays
            // scan out with the newest ones, as the real frame does.
            replayRegisters_ = capture.registers;
            replayInfo_ = info;
        }
        // Presentation can fall behind the guest while the queue still owns
        // newer drawings. Retire obsolete progressive markers after submitting
        // ALL preceding GS work; never discard a guest packet, event or DMA.
        // Interlaced history and EXTWRITE have side effects and cannot be skipped.
        // At most two consecutive markers may be retired, preventing starvation.
        static const bool pace = [] {
            const char* value = std::getenv("REO_SKIP_STALE_SCANOUT");
            return !value || std::strcmp(value, "0") != 0;
        }();
        if (pace && config_.currentVsyncTick && consecutiveStale_ < 2 &&
            lastScanoutProgressive_ && lastScanoutMode_[0] == capture.registers[1] &&
            lastScanoutMode_[1] == capture.registers[2] &&
            !capture.forceHostReadback && !(capture.registers[13] & 1u) &&
            !(config_.diagnosticOutputRequested &&
              config_.diagnosticOutputRequested(capture.tick)) &&
            gs_->vsync_can_skip(info)) {
            const uint64_t now = config_.currentVsyncTick();
            if (now > capture.tick && now - capture.tick > 3) {
                ++staleScanouts_;
                ++consecutiveStale_;
                // An empty frame means this marker has no new host picture.
                // The worker keeps its last publication while retiring the marker.
                return {};
            }
        }
        consecutiveStale_ = 0;
        auto scanout = gs_->vsync(info);
        lastScanoutProgressive_ = scanout.image && !scanout.interlaced;
        lastScanoutMode_ = {capture.registers[1], capture.registers[2]};
        timing.scanout();
        if(scanout.image && scanoutReports_ < 16 &&
           (scanout.image->get_width()!=reportedScanoutWidth_ || scanout.image->get_height()!=reportedScanoutHeight_)) {
            reportedScanoutWidth_=scanout.image->get_width();reportedScanoutHeight_=scanout.image->get_height();++scanoutReports_;
            std::fprintf(stderr,"[INTERNAL-RESOLUTION-1] image=%ux%u high-resolution=%u\n",
                         reportedScanoutWidth_,reportedScanoutHeight_,scanout.high_resolution_scanout ? 1u : 0u);
        }
#if defined(_WIN32) || defined(REO_LINUX_XLIB_PRESENT) || defined(REO_MACOS_METAL_PRESENT)
        if (presenter_ && scanout.image) {
            if (!config_.presentationEpochCurrent(capture.epoch))
                return {};
            const auto target = config_.presentationTarget();
            Vulkan::Fence complete;
            const bool visible = target.hwnd && target.width && target.height;
            if (visible) {
#if defined(_WIN32)
                presenter_->attach(reinterpret_cast<HWND>(target.hwnd), target.width,
                                   target.height);
#else
                presenter_->attach(target.hwnd, target.width, target.height);
#endif
                if (!config_.presentationEpochCurrent(capture.epoch))
                    return {};
                {
                    // Display buffer of this scanout: the presenter tells a new game
                    // frame from a repeated one (presentation warp).
                    const size_t circuit = (capture.registers[0] & 1u) ? 7 : 9;
                    reo::performance::warp::scanout_fbp.store(
                        uint32_t(capture.registers[circuit] & 0x1FF), std::memory_order_relaxed);
#if defined(_WIN32)
                    // Depth source for the presentation warp: the context-1 Z buffer
                    // (ZBP in 2048-word pages, the swizzle base in 64-word blocks).
                    const auto& state = gs_->get_register_state();
                    const auto zbuf = state.ctx[0].zbuf.desc;
                    const auto frame = state.ctx[0].frame.desc;
                    presenter_->setDepthSource(gs_->resident_vram_buffer(), uint32_t(zbuf.ZBP) * 32u,
                                               uint32_t(frame.FBW), uint32_t(zbuf.PSM) | 0x30u,
                                               scanout.internal_width, scanout.internal_height);
#endif
                }
                Vulkan::ImageHandle shown = scanout.image;
                if (replayEnabled() && replayDebug() == 3 && replayFrames_ != replayVerifiedFrame_ &&
                    replayFrames_ % 30 == 0 && scanout.image) {
                    replayVerifiedFrame_ = replayFrames_;
                    // Snapshot check: the snapshot just taken (end of this frame) scanned out with no
                    // replayed input must equal the real scanout, if the snapshot is complete.
                    if (replayGs_ && replayRecordingStart_.valid) {
                        replayGs_->replay_restore(replayRecordingStart_, true);
                        replayLoadedFrame_ = ~0ull;
                        auto& priv = replayGs_->get_priv_register_state();
                        for (size_t i = 0; i < 15; ++i) {
                            const uint32_t offset = privilegedOffsets[i];
                            (offset < 0x1000 ? priv.qwords_lo[offset / 8] : priv.qwords_hi[(offset - 0x1000) / 8]) = capture.registers[i];
                        }
                        replayGs_->replay_flush();
                        auto snapScan = replayGs_->vsync(info);
                        replayGs_->replay_flush();
                        if (snapScan.image) {
                            Capture probe = capture; probe.forceHostReadback = true;
                            ScanoutResult s2 = scanout; s2.image = snapScan.image;
                            const Frame a = download(scanout, 0, probe), b = download(s2, 0, probe);
                            size_t differ = 0;
                            if (a.rgba.size() == b.rgba.size())
                                for (size_t i = 0; i < a.rgba.size(); i += 4)
                                    differ += a.rgba[i] != b.rgba[i] || a.rgba[i + 1] != b.rgba[i + 1] || a.rgba[i + 2] != b.rgba[i + 2];
                            std::fprintf(stderr, "[FRAME-REPLAY-SNAP] frame=%llu differing_pixels=%zu\n", (unsigned long long)replayFrames_,
                                         a.rgba.size() == b.rgba.size() ? differ : size_t(-1));
                        }
                    }
                    if (auto exact = replayRender(1.f, true)) {
                        Capture probe = capture; probe.forceHostReadback = true;
                        ScanoutResult replayed = scanout; replayed.image = exact;
                        const Frame a = download(scanout, 0, probe), b = download(replayed, 0, probe);
                        size_t differ = 0; int worst = 0;
                        if (a.rgba.size() == b.rgba.size())
                            for (size_t i = 0; i < a.rgba.size(); i += 4) {
                                int d = 0;
                                for (int c = 0; c < 3; ++c) d = std::max(d, std::abs(int(a.rgba[i + c]) - int(b.rgba[i + c])));
                                differ += d != 0; worst = std::max(worst, d);
                            }
                        static int dumped = 0;
                        if (differ && replayCurrent_.items.size() > 1500 && a.rgba.size() == b.rgba.size() && a.width * a.height * 4 == a.rgba.size() && dumped < 4) {
                            if (const char* dir = std::getenv("REO_FRAME_REPLAY_DUMP")) {
                                ++dumped;
                                for (int which = 0; which < 2; ++which) {
                                    const Frame& f = which ? b : a;
                                    char name[1024];
                                    std::snprintf(name, sizeof(name), "%s/exact_%llu_%s.ppm", dir, (unsigned long long)replayFrames_, which ? "replay" : "real");
                                    if (FILE* out = std::fopen(name, "wb")) {
                                        std::fprintf(out, "P6 %u %u 255\n", f.width, f.height);
                                        for (size_t i = 0; i < f.rgba.size(); i += 4) std::fwrite(&f.rgba[i], 1, 3, out);
                                        std::fclose(out);
                                    }
                                }
                            }
                        }
                        std::fprintf(stderr, "[FRAME-REPLAY-EXACT] frame=%llu size=%ux%u/%ux%u items=%zu differing_pixels=%zu max_delta=%d\n",
                                     (unsigned long long)replayFrames_, a.width, a.height, b.width, b.height,
                                     replayCurrent_.items.size(), a.rgba.size() == b.rgba.size() ? differ : size_t(-1), worst);
                    }
                }
                if (replayEnabled())
                    if (auto replayed = replayRender(replayPhase())) shown = replayed;
                if (auto native = nativeRender()) shown = native;
                complete = presenter_->present(shown, false, target.linear);
                repeatImage_ = shown;
                repeatLinear_ = target.linear;
                timing.presented();
            } else {
                // Minimize/attach suspension is not a backend failure. Retain
                // the newly rendered source after a genuine queue fence.
                auto command = device_->request_command_buffer();
                command->image_barrier(
                    *scanout.image, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL,
                    VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                    VK_ACCESS_2_MEMORY_WRITE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                    VK_ACCESS_2_MEMORY_READ_BIT);
                device_->submit(command, &complete);
            }
            const auto serial =
                displayImages_.retain(scanout.image, std::move(complete), capture.epoch);
            if (visible && config_.diagnosticOutputRequested && config_.diagnosticOutput &&
                config_.diagnosticOutputRequested(capture.tick)) {
                auto bytes = presenter_->diagnosticShaderOutput();
                ++outputReadbacks_;
                config_.diagnosticOutput(capture.tick, bytes, target.width, target.height);
            }
            if (!capture.forceHostReadback) {
                const auto& image = scanout.image->get_create_info();
                Frame frame;
                frame.width = image.width;
                frame.height = image.height;
                frame.tick = capture.tick;
                const size_t circuit = (capture.registers[0] & 1u) ? 7 : 9;
                frame.displayFbp = uint32_t(capture.registers[circuit] & 0x1FF);
                frame.sourceFbp = frame.displayFbp;
                reo_gpu_present::Receipt receipt{};
                receipt.tick = frame.tick;
                receipt.epoch = capture.epoch;
                receipt.serial = serial;
                receipt.width = frame.width;
                receipt.height = frame.height;
                receipt.displayFbp = frame.displayFbp;
                receipt.sourceFbp = frame.sourceFbp;
                frame.resident = receipt;
                return frame;
            }
        }
#endif
        return download(scanout, capture.tick, capture);
    }
    void exportVram(size_t offset, uint8_t* dst, size_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (offset > VramSize || bytes > VramSize - offset || (!dst && bytes))
            throw std::out_of_range("VRAM readback range");
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        completeEvents();
        if (bytes)
            std::memcpy(dst, gs_->map_vram_read(offset, bytes), bytes);
    }
    uint32_t readTransfer(uint8_t* dst, uint32_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        return fifo_.read(dst, bytes);
    }
    bool clearContext(uint32_t context, uint32_t rgba, bool active) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        completeEvents();
        if (replayEnabled() && !replayRecording_.overflow) {
            ReplayItem item; item.path = ReplayClearPath; item.addr = uint8_t(context);
            item.value = uint64_t(rgba) | (uint64_t(active) << 32);
            replayRecording_.items.push_back(std::move(item));
        }
        return runContextClear(*gs_, context, rgba, active);
    }
    // The context clear on either GS instance (the main one, or the frame-replay one).
    bool runContextClear(GSInterface& gs, uint32_t context, uint32_t rgba, bool active) {
        const auto& r = gs.resident_command_register_state();
        const auto& c = r.ctx[active ? uint32_t(r.prim.desc.CTXT) : (context ? 1 : 0)];
        const uint32_t psm = c.frame.desc.PSM;
        if (!c.frame.desc.FBW ||
            (psm != PSMCT32 && psm != PSMCT24 && psm != PSMCT16 && psm != PSMCT16S))
            return false;
        if (!contextClear_) {
            const auto directory =
                std::filesystem::path(__FILE__).parent_path() / "resident_gs/shaders";
            const std::array<const char*, 3> names{"clear_setup.spv", "clear_bounds.spv",
                                                   "clear_write.spv"};
            std::array<std::vector<uint32_t>, 3> modules;
            for (size_t k = 0; k < names.size(); ++k) {
                std::ifstream file(reo_shader_location::find(directory, names[k]),
                                   std::ios::binary | std::ios::ate);
                if (!file)
                    throw std::runtime_error("Missing pinned GPU context clear shader");
                const auto bytes = file.tellg();
                if (bytes < 20 || bytes > 65536 || (uint64_t(bytes) & 3u))
                    throw std::runtime_error("GPU clear shader size differs");
                modules[k].resize(size_t(bytes) / 4u);
                file.seekg(0);
                file.read(reinterpret_cast<char*>(modules[k].data()), bytes);
                if (!file)
                    throw std::runtime_error("GPU clear shader read failed");
            }
            contextClear_ =
                std::make_unique<reo_gpu_clear_context::ClearContext>(*device_, modules);
        }
        auto command = device_->request_command_buffer(CommandBuffer::Type::Generic);
        try {
            if (!gs.record_resident_context_clear(*command, *contextClear_, context, rgba,
                                                    active)) {
                device_->submit_discard(command);
                return false;
            }
            device_->submit(command);
            return true;
        } catch (...) {
            if (command)
                device_->submit_discard(command);
            throw;
        }
    }

    void flush() override {
        ThreadIndexScope threadIndex;
        requireLive();
        gs_->flush();
        completeEvents();
    }
};
} // namespace
gs_backend_bridge::Factory makeFactory(Config config) {
    gs_backend_bridge::Factory factory = [config = std::move(config)] { return std::make_unique<ParallelBackend>(config); };
#if defined(PS2_RUNTIME_HAS_GS_SOUND_RAM_PROFILE)
    return gs_backend_bridge::withSoundRamProfileProbeV1(std::move(factory),&soundRamProfileObservedV1);
#else
    return factory;
#endif
}
#if defined(PS2_RUNTIME_HAS_GS_SOUND_RAM_PROFILE)
bool soundRamProfileObservedV1(gs_backend_bridge::Backend& backend) noexcept {
    auto* actual=dynamic_cast<ParallelBackend*>(&backend);
    return actual && actual->soundRamProfileObservedV1();
}
#endif
ResidentDiagnostics residentDiagnostics(gs_backend_bridge::Backend& value) {
    auto* backend = dynamic_cast<ParallelBackend*>(&value);
    if (!backend)
        throw std::invalid_argument("Not the actual parallel backend");
    return backend->diagnostics();
}
gs_backend_bridge::Privileged snapshotPrivileged(gs_backend_bridge::Backend& backend) {
    auto* concrete = dynamic_cast<ParallelBackend*>(&backend);
    if (!concrete)
        throw std::invalid_argument("Not a concrete paraLLEl-GS backend");
    return concrete->snapshot();
}
reo::native::ram_capture::v2::Coordinator* nativeSoundRamWriterCoordinatorV2() noexcept {
#if defined(REO_BUILD_NATIVE_SOUND_RAM_CAPTURE) && REO_BUILD_NATIVE_SOUND_RAM_CAPTURE >= 2
    return reo_parent_install::Service::nativeSoundRamCaptureCoordinatorV2();
#else
    return nullptr;
#endif
}
} // namespace reo_parallel_backend
