"""Add the modern camera hooks to a develop-based build kit's own source copies.

usage: kit_apply_camera.py KIT SPV_DIR
  KIT      refreshed kit directory (already containing the adapter, pad tap and
           native headers as added sources); edited in place, reseal afterwards
           with kit_add_native_archives.py
  SPV_DIR  folder with present_native.frag.spv, present_smaa_blend.frag.spv and camera_depth.spv
           compiled from tools/parallel_gs_backend (crosshair, presentation warp)

Edits are anchored on text that exists in both develop and native/hybrid; each
anchor must occur exactly once, so a changed source fails loudly instead of
being patched in the wrong place.
"""
import shutil, sys
from pathlib import Path

kit, spv = Path(sys.argv[1]), Path(sys.argv[2])
root = Path(__file__).resolve().parents[2]
src = kit / 'source'


def edit(rel, pairs):
    path = src / rel
    text = path.read_text(encoding='utf-8')
    newline = '\r\n' if '\r\n' in text else '\n'
    for old, new in pairs:
        old, new = old.replace('\n', newline), new.replace('\n', newline)
        if new in text:
            continue  # already applied
        if text.count(old) != 1:
            raise SystemExit(f'{rel}: anchor found {text.count(old)} times: {old[:70]!r}')
        text = text.replace(old, new)
    path.write_text(text, encoding='utf-8', newline='')


block = (root / 'tools/hybrid/camera_install_block.inc').read_text(encoding='utf-8')
# A kit patched with an older install block: drop it so the current block is inserted
# once (the block starts with the camera guard and ends right before the boot message).
_boot = src / 'recomp/reo_bootstrap.cpp'
_text = _boot.read_text(encoding='utf-8')
_nl = '\r\n' if '\r\n' in _text else '\n'
_start = _text.find('#if defined(REO_BUILD_NATIVE_ROOM_CAMERA) && REO_BUILD_NATIVE_ROOM_CAMERA' + _nl + '    // REO_NATIVE_ROOM_CAMERA=1')
_end = _text.find('    printf("[BOOT] Starting execution at entry point')
_current = _text.find(block.replace('\n', _nl))
if _start >= 0 and _end > _start:
    # Keep only the current block: remove older copies before it, or every copy if
    # the current one is absent (it is inserted again below).
    _cut = _current if _current >= _start else _end
    if _cut > _start:
        _boot.write_text(_text[:_start] + _text[_cut:], encoding='utf-8', newline='')
edit('recomp/reo_bootstrap.cpp', [
    ('#include "overrides/reo_display_probe.h"\n',
     '#include "overrides/reo_display_probe.h"\n'
     '#if defined(REO_BUILD_NATIVE_ROOM_CAMERA) && REO_BUILD_NATIVE_ROOM_CAMERA\n'
     '#include "overrides/native_camera/room_camera_adapter.hpp"\n#endif\n'
     '#if defined(REO_BUILD_NATIVE_ROOM_CAMERA) && REO_BUILD_NATIVE_ROOM_CAMERA && !defined(REO_GAME_FILE2)\n'
     'namespace reo::native::input_adapter { bool install_before_run(PS2Runtime&, bool native) noexcept; }\n#endif\n'),
    ('    printf("[BOOT] Starting execution at entry point 0x%08X...\\n", g.entry_point);',
     block + '\n    printf("[BOOT] Starting execution at entry point 0x%08X...\\n", g.entry_point);'),
])
edit('recomp/overrides/reo_hw_bridge.cpp', [
    ('#include "reo_trace_logger.h"\n', '#include "reo_trace_logger.h"\n#include "reo_pad_tap.h"\n'),
    ('            g_pad2.lastPressed = pressed;',
     '            // Mouse look (native camera mod): right button aims (R1), left button is cross.\n'
     '            if (const auto mouseButtons = reo_pad_tap::mouse_buttons_source.load(std::memory_order_relaxed)) {\n'
     '                const unsigned held = mouseButtons();\n'
     '                if (held & 2u) pressed |= reo_pad_tap::R1;\n'
     '                if (held & 1u) pressed |= reo_pad_tap::CROSS;\n'
     '            }\n'
     '            g_pad2.lastPressed = pressed;'),
    ('                reo_source_instrumentation::bankCell(rd, rec + 0x1E) = hostPad.right_x;\n'
     '                reo_source_instrumentation::bankCell(rd, rec + 0x1F) = hostPad.right_y;\n'
     '                reo_source_instrumentation::bankCell(rd, rec + 0x20) = hostPad.left_x;\n'
     '                reo_source_instrumentation::bankCell(rd, rec + 0x21) = hostPad.left_y;',
     '                // Native camera mods read the host sample; while one owns the right\n'
     '                // stick, the game sees it centred (see reo_pad_tap.h).\n'
     '                reo_pad_tap::publish(hostPad.right_x, hostPad.right_y, hostPad.left_x, hostPad.left_y, pressed);\n'
     '                const bool cameraOwnsRight = reo_pad_tap::consume_right_stick.load(std::memory_order_relaxed);\n'
     '                reo_source_instrumentation::bankCell(rd, rec + 0x1E) = cameraOwnsRight ? uint8_t(0x80) : hostPad.right_x;\n'
     '                reo_source_instrumentation::bankCell(rd, rec + 0x1F) = cameraOwnsRight ? uint8_t(0x80) : hostPad.right_y;\n'
     '                const int aimLeftY = reo_pad_tap::active_aim_left();\n'
     '                reo_source_instrumentation::bankCell(rd, rec + 0x20) = aimLeftY >= 0 ? uint8_t(0x80) : hostPad.left_x;\n'
     '                reo_source_instrumentation::bankCell(rd, rec + 0x21) = aimLeftY >= 0 ? uint8_t(aimLeftY) : hostPad.left_y;'),
])
edit('runtime/gs/performance.h', [
    ('#include <atomic>\n', '#include <atomic>\n#include <chrono>\n'),
    ('inline std::atomic<uint64_t> updates{0};\n',
     'inline std::atomic<uint64_t> updates{0};\n'
     '// Modern camera crosshair, drawn by the present shader (bit 30 of the fps push word).\n'
     'inline std::atomic<int64_t> crosshair_ms{0};\n'
     'inline int64_t steady_ms() {\n'
     '    return std::chrono::duration_cast<std::chrono::milliseconds>(\n'
     '        std::chrono::steady_clock::now().time_since_epoch()).count();\n'
     '}\n'
     'inline void request_crosshair(bool wanted) { crosshair_ms.store(wanted ? steady_ms() : 0); }\n'
     'inline bool crosshair_visible() {\n'
     '    const auto at = crosshair_ms.load(std::memory_order_relaxed);\n'
     '    return at != 0 && steady_ms() - at < 100;\n'
     '}\n'),
])
edit('tools/parallel_gs_backend/resident_dxgi_presenter1c.h', [
    ('        cmd.push_constants(&parameters, 0, sizeof(parameters));',
     '        if (reo::performance::crosshair_visible())\n'
     '            parameters.fps |= 0x40000000u;\n'
     '        cmd.push_constants(&parameters, 0, sizeof(parameters));'),
])
# Presentation warp, depth snapshot and start-at-main-menu (FRAME_DECOUPLING.md,
# MODERN_CAMERA.md). These files are identical between develop and native/hybrid apart
# from the camera work (checked when this was written), so the validated versions are
# copied whole; files that differ get anchored edits taken from this checkout.
for rel in ('runtime/gs/performance.h', 'runtime/audio/host_bridge.h',
            'tools/parallel_gs_backend/resident_dxgi_presenter1c.h',
            'tools/parallel_gs_backend/smaa/resident_smaa.hpp',
            'tools/parallel_gs_backend/resident_gs/gs_renderer.hpp',
            'tools/parallel_gs_backend/resident_gs/gs_interface.hpp'):
    shutil.copyfile(root / rel, src / rel)
backend = (root / 'tools/parallel_gs_backend/parallel_backend.cpp').read_text(encoding='utf-8').replace('\r\n', '\n')
fbp_store = ('                    reo::performance::warp::scanout_fbp.store(\n'
             '                        uint32_t(capture.registers[circuit] & 0x1FF), std::memory_order_relaxed);\n')
depth_block = backend[backend.index(fbp_store) + len(fbp_store):backend.index('#endif\n', backend.index(fbp_store)) + len('#endif\n')]
edit('tools/parallel_gs_backend/parallel_backend.cpp', [
    ('#include "runtime/gs/frame_pacing.h"\n', '#include "runtime/gs/frame_pacing.h"\n#include "runtime/gs/performance.h"\n'),
    ('                complete = presenter_->present(scanout.image, false, target.linear);',
     '                {\n'
     '                    // Display buffer of this scanout: the presenter tells a new game\n'
     '                    // frame from a repeated one (presentation warp).\n'
     '                    const size_t circuit = (capture.registers[0] & 1u) ? 7 : 9;\n' + fbp_store + depth_block +
     '                }\n'
     '                complete = presenter_->present(scanout.image, false, target.linear);'),
])
bridge = (root / 'recomp/overrides/reo_hw_bridge.cpp').read_text(encoding='utf-8').replace('\r\n', '\n')
skip_function = bridge[bridge.index('// Start at the main menu (REO_SKIP_INTRO=1'):bridge.index('// Test-only route through original guest handlers.')]
# A kit patched by an earlier version: replace its menu-skip functions and calls with the
# current ones (start at the main menu, Network Game straight to the server list).
_bridge_path = src / 'recomp/overrides/reo_hw_bridge.cpp'
_bt = _bridge_path.read_text(encoding='utf-8')
if 'uint16_t pad2SkipIntro' in _bt and skip_function not in _bt:
    _a = _bt.index('// Start at the main menu (REO_SKIP_INTRO=1')
    _b = _bt.index('// Test-only route through original guest handlers.')
    _bt = _bt[:_a] + skip_function + _bt[_b:]
    _bt = _bt.replace('            pressed |= pad2NetworkVeil(routeRam, now);\n', '')
    _bt = _bt.replace('            pressed |= pad2SkipIntro(routeRam, now);\n',
                      '            pressed |= pad2SkipIntro(routeRam, now);\n            pressed |= pad2NetworkVeil(routeRam, now);\n')
    _bridge_path.write_text(_bt, encoding='utf-8', newline='')
edit('recomp/overrides/reo_hw_bridge.cpp', [
    ('#include "reo_pad_tap.h"\n', '#include "reo_pad_tap.h"\n#include "runtime/gs/performance.h"\n'),
    ('// Test-only route through original guest handlers.', skip_function + '// Test-only route through original guest handlers.'),
    ('            pressed |= pad2TestRoute(routeRam, now);\n',
     '            pressed |= pad2TestRoute(routeRam, now);\n            pressed |= pad2SkipIntro(routeRam, now);\n'
     '            pressed |= pad2NetworkVeil(routeRam, now);\n'),
])
for name in ('present_native.frag.spv', 'present_smaa_blend.frag.spv', 'camera_depth.spv'):
    shutil.copyfile(spv / name, kit / 'shaders' / name)
print('camera hooks applied to', kit)
