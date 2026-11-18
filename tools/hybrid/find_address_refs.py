"""Find generated functions that load/store a guest address built with lui + offset.

usage: find_address_refs.py ADDRESS [SOURCE_GLOB ...]
Reads the original instruction comments in the generated bodies (default: File #1 main
and overlay output). Prints op, instruction address and file for each match.
"""
import glob, os, re, sys

target = int(sys.argv[1], 16)
globs = sys.argv[2:] or ['recomp/config/output/*.cpp', 'recomp/config/output_ovl/*/*.cpp']
pat = re.compile(r'//\s*0x([0-9a-f]+):\s*0x[0-9a-f]+\s+(lui|sw|lw|sb|lb|lbu|sh|lh|lhu|addiu)\s+\$(\w+),\s*'
                 r'(?:\$(\w+),\s*)?(-?0x[0-9A-Fa-f]+|-?\d+)(?:\(\$(\w+)\))?')
for pattern in globs:
    for f in glob.glob(pattern):
        hi = {}
        for line in open(f, errors='replace'):
            m = pat.search(line)
            if not m:
                continue
            addr, op, rt, rs, imm, base = m.groups()
            v = int(imm, 16) if 'x' in imm.lower() else int(imm)
            if op == 'lui':
                hi[rt] = (v & 0xffff) << 16
                continue
            reg = rs if op == 'addiu' else base
            if reg in hi and ((hi[reg] + ((v + 0x8000) & 0xffff) - 0x8000) & 0xffffffff) == target:
                print(op, addr, os.path.basename(f))
