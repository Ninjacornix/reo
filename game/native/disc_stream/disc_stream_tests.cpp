#include "disc_stream.hpp"

#include <bit>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

namespace ds = reo::native::disc_stream;
#define CHECK(condition) do { if (!(condition)) throw std::runtime_error(#condition); } while (false)

struct TestHooks final : ds::Hooks {
    struct Seen { std::string kind; ds::FileState state; };
    ds::FileState& file;
    std::vector<Seen> seen;
    ds::RequestId created{0x100000001ULL};
    bool prepare{true};
    ds::RequestStatus current{ds::RequestStatus::complete};
    ds::BufferId observed_buffer;
    std::uint32_t observed_bytes{}, observed_start{};
    ds::Diagnostic diagnostic_kind{};
    explicit TestHooks(ds::FileState& state) : file(state) {}
    void note(const char* kind) { seen.push_back({kind, file}); }
    void diagnostic(ds::Diagnostic kind) override { diagnostic_kind = kind; note("diagnostic"); }
    void enter() override { note("enter"); }
    void leave() override { note("leave"); }
    ds::RequestId create_request() override { note("create"); return created; }
    void cache_range(ds::BufferId buffer, std::uint32_t bytes) override {
        observed_buffer = buffer; observed_bytes = bytes; note("cache");
    }
    bool prepare_disc(ds::RequestId id, std::uint32_t start, std::int32_t count,
                      ds::BufferId buffer, const std::array<std::uint8_t, 4>& mode) override {
        CHECK(id == created && buffer == observed_buffer);
        CHECK(count == file.accepted && mode == file.read_mode);
        observed_start = start; note("prepare"); return prepare;
    }
    void cd_sync() override { note("sync"); }
    void server_gate() override { note("gate"); }
    void server_service() override { note("service"); }
    void wait(ds::RequestId id) override { CHECK(id == file.request); note("wait"); }
    void destroy(ds::RequestId id) override { CHECK(id == file.request); note("destroy"); }
    ds::RequestStatus request_status(ds::RequestId id) override {
        CHECK(id == file.request); note("request_status"); return current;
    }
};

int main() {
    try {
        ds::FileState file;
        file.sectors = 20; file.cursor = 18; file.completed = 123;
        file.base_sector = 0xFFFFFFF0U; file.read_mode = {4, 5, 6, 0xA5};
        TestHooks hooks(file);
        const ds::BufferId buffer{0x200000001ULL};
        const ds::Settings settings{{1, 2, 3}, 0};
        CHECK(ds::request(&file, 8, buffer, settings, hooks) == 2);
        CHECK(file.request == hooks.created && file.buffer == buffer);
        CHECK(hooks.observed_buffer == buffer && hooks.observed_bytes == 4096);
        CHECK(hooks.observed_start == 2); // sector addition wraps independently of IDs.
        CHECK((file.read_mode == std::array<std::uint8_t,4>{1,2,3,0xA5}));
        CHECK(file.cursor == 18 && file.completed == 123 && file.status == ds::FileStatus::pending);
        std::cout << "opaque64 IDs / async acceptance / mode retention / sector wrap: PASS\n";

        hooks.seen.clear();
        ds::update(file, hooks);
        CHECK(file.cursor == 20 && file.completed == 2 && !file.request);
        CHECK(hooks.seen.size() == 4 && hooks.seen[2].kind == "destroy");
        CHECK(hooks.seen[2].state.request == hooks.created && !hooks.seen[3].state.request);
        CHECK(ds::transferred(&file, hooks) == 4096);
        std::cout << "terminal publication and destroy-before-clear: PASS\n";

        file.cursor = 18; hooks.seen.clear();
        CHECK(ds::request(&file, 8, buffer, ds::Settings{{1,2,3},1}, hooks) == 2);
        CHECK(file.cursor == 20 && file.completed == 8 && !file.request);
        CHECK(hooks.seen.size() == 8 && hooks.seen[6].kind == "wait");
        CHECK(hooks.seen.back().state.cursor == 18);
        std::cout << "sync preserves requested completed count: PASS\n";

        file.status = ds::FileStatus::error; file.completed = 99;
        hooks.seen.clear();
        CHECK(ds::request(&file, 0, buffer, settings, hooks) == 0);
        CHECK(file.completed == 99 && file.status == ds::FileStatus::ready && hooks.seen.empty());
        file.status = ds::FileStatus::pending;
        const auto before = file;
        CHECK(ds::request(&file, 0, buffer, settings, hooks) == 0 && file == before);
        CHECK(ds::request(&file, -1, {}, settings, hooks) == 0);
        CHECK(hooks.diagnostic_kind == ds::Diagnostic::negative_request);
        CHECK(ds::request(&file, 0, {}, settings, hooks) == 0);
        CHECK(hooks.diagnostic_kind == ds::Diagnostic::null_buffer);
        CHECK(ds::request(nullptr, -1, {}, settings, hooks) == 0);
        CHECK(hooks.diagnostic_kind == ds::Diagnostic::null_file);
        std::cout << "zero / busy / null / validation order: PASS\n";

        file.status = ds::FileStatus::idle; file.cursor = 3;
        hooks.prepare = false; hooks.seen.clear();
        CHECK(ds::request(&file, 4, buffer, settings, hooks) == 0);
        CHECK(file.request == hooks.created && file.cursor == 3 && file.accepted == 4);
        CHECK(hooks.seen.back().kind == "destroy");
        std::cout << "prepare failure preserves residual ID: PASS\n";

        file.cursor = std::numeric_limits<std::int32_t>::max();
        CHECK(ds::seek(&file, 1, 1, hooks) == 0 && file.completed == 0);
        file.cursor = 9;
        CHECK(ds::seek(&file, 123, 7, hooks) == 9);
        file.sectors = -1;
        CHECK(ds::seek(&file, 0, 7, hooks) == 0);
        file.status = ds::FileStatus::ready; file.completed = 0x100001;
        CHECK(static_cast<std::uint32_t>(ds::transferred(&file, hooks)) == 0x80000800U);
        std::cout << "signed clamps / invalid origin / word arithmetic: PASS\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n'; return 1;
    }
}
