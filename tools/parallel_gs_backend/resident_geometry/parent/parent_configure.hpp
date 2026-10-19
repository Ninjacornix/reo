#pragma once
#include "../resident_array_owner.hpp"
#include "../upstream/setter_assets.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <filesystem>
#include <fstream>
namespace reo_parent_install {
inline std::vector<uint32_t> pinnedParentModule(const std::filesystem::path& p,
                                                const char* expected) {
    std::ifstream f(p, std::ios::binary);
    if (!f)
        throw std::runtime_error("Pinned parent module unavailable");
    std::vector<uint8_t> bytes{std::istreambuf_iterator<char>(f), {}};
    if (bytes.size() < 20 || bytes.size() % 4 || reo_gpu_catalog::sha256(bytes) != expected)
        throw std::runtime_error("Parent module hash/shape differs");
    std::vector<uint32_t> words(bytes.size() / 4);
    std::memcpy(words.data(), bytes.data(), bytes.size());
    if (words[0] != 0x07230203u)
        throw std::runtime_error("Parent module is not SPIR-V");
    return words;
}
// Optional root composition call BEFORE makeArrayResidentOwnerConfig. Leaves
// parent.enabled and every Gates/Proofs false; no guessed session/source keys.
inline void attachPinnedParentSource(reo_resident_live::ArrayShaderBundle& owner,
                                     const std::filesystem::path& assets, uint64_t actualSession,
                                     std::shared_ptr<const ColdSource> cold) {
    if (!actualSession || !cold || !cold->ram || !cold->spr || !cold->actualContext ||
        !cold->lifetime)
        throw std::invalid_argument("Missing actual parent cold identity");
    if (owner.parent.enabled || owner.parent.cold)
        throw std::logic_error("Parent factory source already configured");
    Configuration candidate{};
    candidate.session = actualSession;
    candidate.cold = std::move(cold);
    candidate.producer.prepare =
        pinnedParentModule(assets / "parent_prepare.spv",
                           "f93c456703ba80fa360feaa8457810ae2a760639e366927e0ad0128fb290bbb9");
    candidate.producer.leaf =
        pinnedParentModule(assets / "palette_leaf.spv",
                           "265789b868f79589c4b448f31f734f190450bec4a4730e10d4a6167d41e52986");
    candidate.producer.finish =
        pinnedParentModule(assets / "parent_finish.spv",
                           "c07a1d7756b2cd3129c89ecf614210cfc5c9b1202c844256abea982a72548145");
    candidate.producer.commit =
        pinnedParentModule(assets / "parent_commit.spv",
                           "e1c6b58ec6a542eafbaebf9a7ebb602d3433e73ba3c372eabb04cb1d7acc3b0c");
    candidate.transport.mailbox =
        pinnedParentModule(assets / "parent_return_mailbox.spv",
                           "09b181c774cafcc695f2df5e448fbde8f9e6bc1c192e258d0820454f9dcfca60");
    candidate.transport.relay =
        pinnedParentModule(assets / "parent_completion_relay.spv",
                           "856371c7f53e2925922a44bc219cb354498115c8f44c28a8ddf26b2c64f4f8b6");
    const auto unpack =
        pinnedParentModule(assets / "vif_unpack.spv",
                           "a8a74f3017d22f15bf0a8e346bcecefe8037271642c02ce4571db0ec6d96c396");
    if (owner.unpack != unpack)
        throw std::invalid_argument("Actual VIF owner does not use the proved UNPACK module");
    owner.parent = std::move(candidate);
}
// Immutable upstream modules are attached after actual parent cold identity.
// This does not change source admission or enable numerical ownership.
inline void attachPinnedSetterSource(reo_resident_live::ArrayShaderBundle& owner,
                                     const std::filesystem::path& upstreamAssets) {
    if (!owner.parent.session || !owner.parent.cold || !owner.parent.cold->lifetime)
        throw std::invalid_argument(
            "Setter module attachment needs the actual configured parent cold identity");
    reo_gpu_upstream::attachSetterAssets(owner.parent.producer, upstreamAssets);
}
} // namespace reo_parent_install
