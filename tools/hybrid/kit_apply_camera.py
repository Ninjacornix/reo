"""Add the modern camera hooks to a develop-based build kit's own source copies.

usage: kit_apply_camera.py KIT SPV_DIR
  KIT      refreshed kit directory (already containing the adapter, pad tap and
           native headers as added sources); edited in place, reseal afterwards
           with kit_add_native_archives.py
  SPV_DIR  folder with present_native.frag.spv and present_smaa_blend.frag.spv
           compiled from tools/parallel_gs_backend (crosshair)

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
edit('recomp/reo_bootstrap.cpp', [
    ('#include "overrides/reo_display_probe.h"\n',
     '#include "overrides/reo_display_probe.h"\n'
     '#if defined(REO_BUILD_NATIVE_ROOM_CAMERA) && REO_BUILD_NATIVE_ROOM_CAMERA\n'
     '#include "overrides/native_camera/room_camera_adapter.hpp"\n#endif\n'),
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
for name in ('present_native.frag.spv', 'present_smaa_blend.frag.spv'):
    shutil.copyfile(spv / name, kit / 'shaders' / name)
print('camera hooks applied to', kit)
