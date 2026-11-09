#include "game/native/gameplay_scenario/saved_controls.hpp"
#include "game/native/gameplay_scenario/scene_matrix_programs.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace vm = reo::native::gameplay_scenario;
namespace math = reo::native::transform_math;
std::size_t checks{}, calls{}, refused{}, terminal_calls{}, first_evaluations{},
    binding_calls{}, ownership_checks{};
std::string context;
void check(bool value,
           const std::source_location at = std::source_location::current()) {
    ++checks;
    if (!value)
        throw std::runtime_error(
            "Scene matrix comparison " + std::to_string(checks) + " " +
            context + " " + at.file_name() + ":" + std::to_string(at.line()));
}
#include "control_vm_fixture.inc"
PS2Runtime::Function PS2Runtime::lookupFunction(std::uint32_t at) const {
    if (at == 0x6b5050)
        ++first_evaluations;
    if (at == 0x5d8280)
        ++binding_calls;
    switch (at) {
#include "original_lookup.inc"
    default:
        throw std::runtime_error("Unexpected original matrix call " +
                                 std::to_string(at));
    }
}
void original_transform_port(std::uint8_t *, R5900Context *, PS2Runtime *) {
    throw std::runtime_error("Unexpected original matrix fallback");
}
void project(std::uint8_t *m, std::uint32_t at,
             const vm::SceneMatrixChannel &c) {
    m[at + 1] = c.contact.gate;
    m[at + 2] = c.interaction;
    m[at + 3] = c.progress;
    m[at + 4] = c.playback;
    m[at + 6] = c.model_slot;
    m[at + 7] = c.program;
    m[at + 8] = c.cursor;
    m[at + 9] = c.curve;
    m[at + 10] = c.transform;
    m[at + 11] = c.contact.active;
    fixture_write(m, at + 12, c.time);
    fixture_write(m, at + 14, c.segment);
    fixture_write(m, at + 16, c.sound_cursor);
    std::memcpy(m + at + 32, c.matrix.data(), 64);
}
vm::SceneModelState models(unsigned seed) {
    vm::SceneModelState s;
    for (unsigned i = 0; i < 128; ++i) {
        s.visibility[i] = std::uint8_t(seed + i);
        s.styles[i] = 0x12345678u ^ (i * 777u + seed);
        auto &m = s.poses[i];
        for (unsigned c = 0; c < 4; ++c)
            for (unsigned r = 0; r < 3; ++r)
                m[c][r] =
                    float(int((seed + i * 13 + c * 17 + r * 19) % 129) - 64) /
                    16.0f;
        for (unsigned c = 0; c < 4; ++c)
            m[c][3] = std::bit_cast<float>(0x7fc00123u + i + c);
    }
    return s;
}
vm::SceneMatrixPrograms::State initial(unsigned seed) {
    vm::SceneMatrixPrograms::State s;
    for (unsigned i = 0; i < 16; ++i) {
        auto &c = s[i];
        c.contact = {std::uint8_t(seed + i), std::uint8_t(seed * 3 + i)};
        c.interaction = std::uint8_t(seed * 5 + i);
        c.progress = std::uint8_t(seed * 7 + i);
        c.playback = std::uint8_t(seed * 11 + i);
        c.model_slot = std::uint8_t((seed + i) % 128);
        c.program = std::uint8_t((seed + i) % 36);
        c.cursor = std::uint8_t(seed + i * 3);
        c.curve = std::uint8_t((seed + i) % 236);
        c.transform = std::uint8_t(seed + i * 7);
        c.time = std::int16_t(int(seed % 29) - 8);
        c.segment = std::int16_t(seed);
        c.sound_cursor = std::int16_t(seed * 3);
        for (unsigned col = 0; col < 4; ++col)
            for (unsigned r = 0; r < 4; ++r)
                c.matrix[col][r] = float(int(seed + i + col + r) - 64);
    }
    return s;
}
int main() try {
    std::vector<std::uint8_t> ram(0x2000000);
    owned_matrix_constants(ram.data());
    const std::array<std::uint32_t, 5> entry{0x6b5760, 0x6b5920, 0x6b5ab0,
                                             0x6b5c60, 0x6b5e10};
    for (unsigned selection = 0; selection < 5; ++selection)
        for (unsigned tag : {0u, 2u})
            for (unsigned kind = 0; kind < 256; ++kind)
                for (unsigned mode : {0u, 1u, 2u, 3u, 4u, 127u, 128u, 255u})
                    for (unsigned index : {0u, 1u, 7u, 15u}) {
                        const auto seed = selection * 139 + tag * 71 +
                                          kind * 19 + mode + index;
                        context = "selection=" + std::to_string(selection) +
                                  " tag=" + std::to_string(tag) +
                                  " kind=" + std::to_string(kind) +
                                  " mode=" + std::to_string(mode) +
                                  " index=" + std::to_string(index);
                        const auto state = models(seed);
                        vm::RoomModelRemap remap{};
                        vm::SceneModels model(state, remap);
                        reo::native::gameplay_actors::EntityStore entities(
                            {64});
                        vm::SceneModelBindings bindings(model, entities);
                        vm::FlagState flags;
                        auto fs = flags.snapshot();
                        const std::uint16_t room = std::uint16_t(seed % 128);
                        fs.strided[room][2] = 0xffff;
                        fs.strided[room][3] = std::uint16_t(seed * 12345);
                        flags.restore(fs);
                        const auto channels = initial(seed);
                        ControlFixture controls;
                        const auto slot =
                            std::uint8_t((seed * 17 + index) % 128);
                        const auto descriptor = std::uint32_t(seed % 4);
                        if (tag == 0) {
                            vm::ControlTypeZero z;
                            z.matrix_program = vm::ControlMatrixProgramResource{
                                slot, descriptor, std::uint8_t(kind)};
                            z.refresh_parameter = std::uint8_t(mode);
                            z.destination = vm::ControlRouteDestination{
                                0x87654321, 0xfedcba98};
                            controls.ids.push_back(*controls.owner.append(
                                {index, std::uint8_t(seed), z}));
                        } else {
                            vm::ControlTypeTwo t;
                            t.model_reference = vm::ControlModelReference{
                                0xabcd0000u | slot, descriptor};
                            t.matrix_resource_class = std::uint8_t(kind);
                            t.refresh_parameter = std::uint8_t(mode);
                            controls.ids.push_back(*controls.owner.append(
                                {index, std::uint8_t(seed), t}));
                        }
                        vm::SceneMatrixPrograms native(controls.owner, model,
                                                       bindings, flags, room,
                                                       channels);
                        controls.export_original(ram);
                        std::memcpy(ram.data() + 0x49fa10, state.poses.data(),
                                    sizeof(state.poses));
                        std::memset(ram.data() + 0x4a1b60, 0, 16 + 512);
                        fixture_write(ram.data(), 0x3243dc, room);
                        std::memcpy(ram.data() + 0x4b9e20, fs.strided.data(),
                                    sizeof(fs.strided));
                        std::array<std::uint8_t, 16 * 96> expected;
                        expected.fill(0xa5);
                        for (unsigned i = 0; i < 16; ++i)
                            project(expected.data(), i * 96, channels[i]);
                        std::memcpy(ram.data() + 0x4a3620, expected.data(),
                                    expected.size());
                        const auto result = native.select(
                            0x12340000u | index,
                            static_cast<vm::SceneMatrixSelection>(selection));
                        if (result.status ==
                            vm::SceneMatrixStatus::unadmitted_profile) {
                            for (unsigned i = 0; i < 16; ++i)
                                project(expected.data(), i * 96,
                                        *native.inspect(i));
                            check(std::memcmp(ram.data() + 0x4a3620,
                                              expected.data(),
                                              expected.size()) == 0);
                            check(bindings.mask() ==
                                  std::array<std::uint32_t, 4>{});
                            ++refused;
                            continue;
                        }
                        check(result.status ==
                                  vm::SceneMatrixStatus::completed &&
                              result.matched);
                        check(result.changed == (selection != 4 || kind <= 3));
                        R5900Context c;
                        PS2Runtime runtime;
                        SET_GPR_U32(&c, 4,
                                    selection == 1 ? 0xabcdef01u
                                                   : 0x12340000u | index);
                        SET_GPR_U32(&c, 5, 0x12340000u | index);
                        SET_GPR_U32(&c, 29, 0x1f00000);
                        SET_GPR_U32(&c, 31, 0xdeadbeef);
                        runtime.lookupFunction(entry[selection])(ram.data(), &c,
                                                                 &runtime);
                        check(c.pc == 0xdeadbeef);
                        ++calls;
                        terminal_calls += selection == 4;
                        for (unsigned i = 0; i < 16; ++i)
                            project(expected.data(), i * 96,
                                    *native.inspect(i));
                        if (std::memcmp(ram.data() + 0x4a3620, expected.data(),
                                        expected.size()) != 0) {
                            for (unsigned i = 0; i < expected.size(); ++i)
                                if (ram[0x4a3620 + i] != expected[i])
                                    throw std::runtime_error(
                                        context +
                                        " first different channel byte=" +
                                        std::to_string(i) + " expected=" +
                                        std::to_string(expected[i]) +
                                        " original=" +
                                        std::to_string(ram[0x4a3620 + i]));
                        }
                        check(std::memcmp(ram.data() + 0x49fa10,
                                          state.poses.data(),
                                          sizeof(state.poses)) == 0);
                        const auto mask = bindings.mask();
                        check(std::memcmp(ram.data() + 0x4a1b60, mask.data(),
                                          16) == 0);
                        for (unsigned i = 0; i < 128; ++i) {
                            const auto pointer = fixture_read<std::uint32_t>(
                                ram.data(), 0x4a1b70 + 4 * i);
                            check(pointer == ((result.changed && i == slot)
                                                  ? 0x4a3620 + index * 96 + 32
                                                  : 0));
                        }
                        if (result.changed) {
                            const auto live = bindings.live_pose(slot);
                            check(live && std::memcmp(live->data(),
                                                      ram.data() + 0x4a3620 +
                                                          index * 96 + 32,
                                                      64) == 0);
                        }
                    }
    {
        context = "canonical matrix/contact/lifetime admission";
        vm::SceneModelState state = models(7);
        vm::RoomModelRemap map{};
        vm::SceneModels model(state, map);
        reo::native::gameplay_actors::EntityStore entities({64});
        vm::SceneModelBindings bindings(model, entities);
        vm::FlagState flags;
        std::uint16_t room = 0;
        vm::SceneControls controls;
        auto native = std::make_unique<vm::SceneMatrixPrograms>(
            controls, model, bindings, flags, room);
        for (unsigned i = 0; i < 16; ++i) {
            const auto c = native->inspect(i);
            check(c && c->contact.gate == 0 && c->contact.active == 0 &&
                  c->progress == 0 && c->playback == 0);
            for (const auto &col : c->matrix)
                for (float value : col)
                    check(std::bit_cast<std::uint32_t>(value) == 0);
        }
        check(!native->channel(16) && !native->inspect(16));
        check(native->select(16, vm::SceneMatrixSelection::expiry).status ==
              vm::SceneMatrixStatus::invalid_channel);
        auto contact = native->channel(3);
        check(contact.has_value());
        contact->active = 255;
        contact->gate = 128;
        check(native->inspect(3)->contact.active == 255 &&
              native->inspect(3)->contact.gate == 128);
        check(native->select(0, vm::SceneMatrixSelection::expiry).status ==
              vm::SceneMatrixStatus::completed);
        check(!native->select(0, vm::SceneMatrixSelection::expiry).matched);
        room = 256;
        check(native->select(0, vm::SceneMatrixSelection::terminal).status ==
              vm::SceneMatrixStatus::unavailable_flags);
        room = 0;
        vm::ControlTypeZero z;
        const auto id = *controls.append({0, 0, z});
        check(native->select(0, vm::SceneMatrixSelection::expiry).status ==
              vm::SceneMatrixStatus::unavailable_control);
        check(bindings.mask() == std::array<std::uint32_t, 4>{});
        controls.erase(id);
        z.matrix_program = vm::ControlMatrixProgramResource{7, 0, 1};
        controls.append({0, 255, z});
        check(native->select(0, vm::SceneMatrixSelection::expiry).status ==
              vm::SceneMatrixStatus::completed);
        const auto first = bindings.live_pose(7);
        check(first && std::memcmp(first->data(),state.poses[7].data(),64)==0);
        auto changed = state.poses[7];
        changed[3][1] = changed[3][1] + 17;
        check(model.pose(7, changed) == vm::ModelStatus::completed);
        check(native->evaluate_first(0) == vm::SceneMatrixStatus::completed);
        const auto fresh = bindings.live_pose(7);
        check(fresh && std::memcmp(fresh->data(),
                                   native->inspect(0)->matrix.data(), 64) == 0);
        check(std::memcmp(fresh->data(), first->data(), 64) != 0);
        native->close();
        check(!native->channel(0) && !native->inspect(0));
        check(native->select(0, vm::SceneMatrixSelection::expiry).status ==
              vm::SceneMatrixStatus::closed);
        native.reset();
        const auto retained = bindings.live_pose(7);
        check(retained &&
              std::memcmp(retained->data(), fresh->data(), 64) == 0);
        vm::SceneMatrixPrograms closed_bindings(controls, model, bindings,
                                                flags, room);
        bindings.close();
        check(closed_bindings.select(0, vm::SceneMatrixSelection::expiry)
                  .status == vm::SceneMatrixStatus::binding_refused);
        check(closed_bindings.inspect(0)->playback == 0);
        ownership_checks = checks;
    }
    std::cout << "{\"status\":\"passed\",\"checks\":" << checks
              << ",\"original_selection_calls\":" << calls
              << ",\"terminal_calls\":" << terminal_calls
              << ",\"profile_refusals\":" << refused
              << ",\"actual_first_evaluations\":" << first_evaluations
              << ",\"actual_bindings\":" << binding_calls
              << ",\"game_launched\":false}\n";
} catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
}
