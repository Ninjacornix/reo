"""Create Ghidra functions in code gaps between mapped functions, then re-export.

Functions reached only through pointers are often not defined by Ghidra's
auto-analysis; an indirect call to one at runtime fails with "Function at address
... not found" (docs/DIVERGENCES.md D6/D8). This scans the ELF's loadable segments
for non-zero words between consecutive mapped functions, asks Ghidra (ghidra-mcp
POST /create_function) to create a function at each gap's first instruction, re-exports
the map, and repeats until it converges. MODIFIES the Ghidra program (save it after).

    MSYS_NO_PATHCONV=1 python tools/ghidra_fill_gaps.py recomp/config/outbreak_ghidra_functions.csv
"""
import csv, json, struct, subprocess, sys, urllib.request, os
ELF = 'game_data/SLUS_207.65'
MAP = sys.argv[1]
elf = open(ELF, 'rb').read()
phoff = struct.unpack_from('<I', elf, 28)[0]; phnum = struct.unpack_from('<H', elf, 44)[0]
segs = []
for i in range(phnum):
    t, off, va, pa, fs, ms, fl, al = struct.unpack_from('<8I', elf, phoff + i * 32)
    if t == 1 and fs: segs.append((va, off, fs))
def rd(a):
    for va, off, fs in segs:
        if va <= a < va + fs: return struct.unpack_from('<I', elf, off + a - va)[0]
    return None
def export():
    env = dict(os.environ, MSYS_NO_PATHCONV='1')
    subprocess.run([sys.executable, '-I', 'tools/ghidra_export_functions.py', '--program', '/ps2/SLUS_207.65', '--out', MAP], check=True, env=env, capture_output=True)
def gaps():
    rows = sorted((int(r['start'], 16), int(r['end'], 16)) for r in csv.DictReader(open(MAP)))
    out = []
    for (s0, e0), (s1, e1) in zip(rows, rows[1:]):
        if s1 > e0:
            for a in range(e0, s1, 4):
                w = rd(a)
                if w not in (0, None):
                    out.append(a); break
    return out
def create(addr):
    body = json.dumps({'address': f'0x{addr:08X}', 'disassemble_first': 'true', 'program': '/ps2/SLUS_207.65'}).encode()
    req = urllib.request.Request('http://127.0.0.1:8089/create_function?program=/ps2/SLUS_207.65', data=body, headers={'Content-Type': 'application/json'}, method='POST')
    try:
        return json.load(urllib.request.urlopen(req, timeout=120))
    except Exception as e:
        return {'success': False, 'error': str(e)}
failed = set()
for rnd in range(8):
    export()
    g = [a for a in gaps() if a not in failed]
    print(f'round {rnd}: {len(g)} gap starts')
    if not g: break
    ok = 0
    for a in g:
        r = create(a)
        if r.get('success'): ok += 1
        else: failed.add(a)
    print(f'  created {ok}, failed {len(g) - ok}')
export()
print('final gaps (incl. failed):', len(gaps()), 'failed:', [hex(a) for a in sorted(failed)][:20])
