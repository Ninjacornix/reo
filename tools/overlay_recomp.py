#!/usr/bin/env python3
"""Recompile SLUS-20765 code overlays into recomp/config/output_ovl/.

Inputs per overlay <n> in <work_dir> (see tools/overlay_extract.py):
  <n>.elf       image wrapped as an EE ELF at its load base
  ovl<n>.csv    Ghidra function map of that ELF (tools/ghidra_export_functions.py,
                tools/ghidra_fill_gaps.py --elf <n>.elf --program /ovl/ovl<n>.elf)

For each overlay this
  - drops map rows inside the 0x80-byte MWo3 header or at unaligned starts,
  - renames sub_XXXXXXXX to o<n>_XXXXXXXX (overlays sharing a load base would collide),
  - runs ps2_recomp into output_ovl/o<n>/ (quoted includes resolve locally, so each
    directory's ps2_recompiled_functions.h stays private to it),
  - rewrites register_functions.cpp into reoRegisterOverlay_o<n>(), which registers with
    PS2Runtime::registerOverlayFunction(base, 'MWo3', 4, id, ...),
and writes output_ovl/register_overlays.cpp with reoRegisterOverlays().

Usage: overlay_recomp.py <work_dir> <recomp_exe> [--maps <dir>] <n> [<n> ...]
  --maps: read ovl<n>.csv from <dir> (default <work_dir>); the committed maps live in
  recomp/config/overlay_maps/, so regeneration does not need Ghidra.
"""
import csv
import os
import re
import struct
import subprocess
import sys
import time

MAGIC = 0x336F574D  # "MWo3"
HEADER = 0x80
OUT_ROOT = os.path.join('recomp', 'config', 'output_ovl')


def image_info(elf_path):
    elf = open(elf_path, 'rb').read()
    phoff = struct.unpack_from('<I', elf, 28)[0]
    off, va = struct.unpack_from('<II', elf, phoff + 4)
    ident, base = struct.unpack_from('<II', elf, off + 4)
    assert struct.unpack_from('<I', elf, off)[0] == MAGIC and base == va, elf_path
    return base, ident


def main():
    work, exe, rest = sys.argv[1], sys.argv[2], sys.argv[3:]
    maps = work
    if rest[:1] == ['--maps']:
        maps, rest = rest[1], rest[2:]
    nums = rest
    os.makedirs(OUT_ROOT, exist_ok=True)
    for n in nums:
        tag = 'o' + n
        elf = os.path.abspath(os.path.join(work, n + '.elf'))
        base, ident = image_info(elf)
        rows = []
        for r in csv.DictReader(open(os.path.join(maps, 'ovl%s.csv' % n))):
            start = int(r['start'], 16)
            if start % 4 or start < base + HEADER:
                continue
            r['name'] = re.sub(r'^(sub|FUN)_', tag + '_', r['name'])
            rows.append(r)
        # ps2_recomp registers the ELF entry function; point it at the first real function.
        rows.sort(key=lambda r: int(r['start'], 16))
        img = bytearray(open(elf, 'rb').read())
        struct.pack_into('<I', img, 24, int(rows[0]['start'], 16))
        elf = os.path.abspath(os.path.join(work, tag + '.elf'))
        open(elf, 'wb').write(img)
        map_path = os.path.abspath(os.path.join(work, tag + '.csv'))
        with open(map_path, 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=['name', 'start', 'end', 'size'])
            w.writeheader()
            w.writerows(rows)
        out_dir = os.path.abspath(os.path.join(OUT_ROOT, tag))
        os.makedirs(out_dir, exist_ok=True)
        for old in os.listdir(out_dir):
            for attempt in range(20):  # indexers/AV briefly lock freshly written files
                try:
                    os.remove(os.path.join(out_dir, old))
                    break
                except PermissionError:
                    time.sleep(0.25)
        toml = os.path.join(work, tag + '.toml')
        with open(toml, 'w') as f:
            f.write('[general]\ninput = "%s"\nghidra_output = "%s"\noutput = "%s/"\n'
                    'single_file_output = false\npatch_syscalls = false\npatch_cop0 = true\n'
                    'patch_cache = true\n' % (elf.replace('\\', '/'), map_path.replace('\\', '/'),
                                              out_dir.replace('\\', '/')))
        subprocess.run([exe, toml], check=True, stdout=subprocess.DEVNULL)
        # The main output's ps2_recompiled_functions.h (same name, same include guard) is in
        # the precompiled header; give this overlay's header a unique name and guard.
        hdr = tag + '_functions.h'
        src = open(os.path.join(out_dir, 'ps2_recompiled_functions.h')).read()
        src = src.replace('PS2_RECOMPILED_FUNCTIONS_H', tag.upper() + '_RECOMPILED_FUNCTIONS_H')
        open(os.path.join(out_dir, hdr), 'w').write(src)
        os.remove(os.path.join(out_dir, 'ps2_recompiled_functions.h'))
        for fn_ in os.listdir(out_dir):
            if fn_.endswith('.cpp'):
                p_ = os.path.join(out_dir, fn_)
                c_ = open(p_).read()
                c_ = c_.replace('#include "ps2_recompiled_functions.h"', '#include "%s"' % hdr)
                open(p_, 'w').write(c_)
        reg = open(os.path.join(out_dir, 'register_functions.cpp')).read()
        calls = re.findall(r'runtime\.registerFunction\((0x[0-9a-fA-F]+), (\w+)\);', reg)
        os.remove(os.path.join(out_dir, 'register_functions.cpp'))
        with open(os.path.join(out_dir, 'register_' + tag + '.cpp'), 'w') as f:
            f.write('// Generated by tools/overlay_recomp.py: BIN/%s.DAT, id %d, base 0x%X.\n'
                    '#include "ps2_runtime.h"\n#include "%s"\n\n'
                    'void reoRegisterOverlay_%s(PS2Runtime& runtime) {\n' % (n, ident, base, hdr, tag))
            for addr, fn in calls:
                if int(addr, 16) >= base + HEADER:
                    f.write('    runtime.registerOverlayFunction(0x%Xu, 0x%Xu, 4u, %du, %su, %s);\n'
                            % (base, MAGIC, ident, addr, fn))
            f.write('}\n')
        print('%s: base 0x%X id %d, %d functions -> %s' % (tag, base, ident, len(calls), out_dir))

    tags = sorted(d for d in os.listdir(OUT_ROOT) if os.path.isdir(os.path.join(OUT_ROOT, d)))
    with open(os.path.join(OUT_ROOT, 'register_overlays.cpp'), 'w') as f:
        f.write('// Generated by tools/overlay_recomp.py.\n#include "ps2_runtime.h"\n'
                '#include <cstdio>\n#include <cstdlib>\n#include <string>\n\n')
        for t in tags:
            f.write('void reoRegisterOverlay_%s(PS2Runtime& runtime);\n' % t)
        f.write('\n// REO_OVL_SKIP=o0,o2 leaves those overlays unregistered (diagnostic).\n'
                'static bool reoOvlSkipped(const char* tag) {\n'
                '    const char* e = std::getenv("REO_OVL_SKIP");\n'
                '    if (!e) return false;\n'
                '    const std::string list = std::string(",") + e + ",";\n'
                '    const bool skip = list.find(std::string(",") + tag + ",") != std::string::npos;\n'
                '    if (skip) std::fprintf(stderr, "[OVL] %s not registered (REO_OVL_SKIP)\\n", tag);\n'
                '    return skip;\n}\n')
        f.write('\nvoid reoRegisterOverlays(PS2Runtime& runtime) {\n')
        for t in tags:
            f.write('    if (!reoOvlSkipped("%s")) reoRegisterOverlay_%s(runtime);\n' % (t, t))
        f.write('}\n')


if __name__ == '__main__':
    main()
