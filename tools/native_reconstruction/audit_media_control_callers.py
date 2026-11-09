"""Read-only File #1 movie-control caller audit against owned original words."""
import argparse
import hashlib
import json
import re
import struct
import subprocess
from pathlib import Path

from audit_retail_effect_descriptors import compare_source, elf_reader

ROOT = Path(__file__).resolve().parents[2]
PROFILES = [
    ('game status/error service', 'o0', 'o0_0037A5A0_0x37a5a0', 0x37A5A0, 0x37A9A8),
    ('game destroy', 'o0', 'o0_0037A4E0_0x37a4e0', 0x37A4E0, 0x37A594),
    ('game busy query', 'o0', 'o0_0037AA10_0x37aa10', 0x37AA10, 0x37AA3C),
    ('gallery playback', 'o1', 'o1_0057B730_0x57b730', 0x57B730, 0x57B958),
    ('gallery completion/audio cleanup', 'o1', 'o1_005703F0_0x5703f0', 0x5703F0, 0x5704D0),
    ('public pause', 'main', 'sub_0015F3F0_0x15f3f0', 0x15F3F0, 0x15F5B0),
    ('engine pause and I/O suspension', 'o0', 'o0_0037AA40_0x37aa40', 0x37AA40, 0x37AAA0),
    ('HDD maintenance caller', 'main', 'sub_001BD160_0x1bd160', 0x1BD160, 0x1BD2E0),
]


def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if args.output.exists():
        raise ValueError('Fresh output directory required')
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    main_read = elf_reader(elf.read_bytes())
    readers = {'main': main_read}
    inputs = {str(elf.relative_to(ROOT)): sha(elf)}
    for image, expected in [('o0', 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),
                            ('o1', '719ce452cb267d5475a9fa8f06e78e977932311e081c6ec90bb34a6a74a780da')]:
        p = ROOT / f'build-function-index/owned-overlays/{image}.bin'
        data = p.read_bytes()
        # Original overlay files include their MWo3 header in the loaded image.
        base = struct.unpack_from('<I', data, 8)[0]
        assert sha(p) == expected
        readers[image] = lambda a, n, b=base, d=data: d[a-b:a-b+n]
        inputs[str(p.relative_to(ROOT))] = sha(p)
    rows = []
    for role, image, name, start, end in PROFILES:
        folder = 'recomp/config/output' if image == 'main' else f'recomp/config/output_ovl/{image}'
        rows.append(compare_source(role, f'{folder}/{name}.cpp', start, end, readers[image]))
    vtable = struct.unpack('<17I', main_read(0x22DCE8, 68))
    assert vtable[0x28//4] == 0x15F3F0 and vtable[0x20//4] == 0x160060
    service = {int(r['pc'], 16): int(r['owned_word'], 16) for r in rows[0]['comparisons']}
    assert service[0x37A65C] == 0x24030004 and service[0x37A674] == 0x10830046
    assert service[0x37A790] == 0x0C0DE938 and service[0x37A780] == 0x0C0DE938
    gallery = {int(r['pc'],16):int(r['owned_word'],16) for r in rows[3]['comparisons']}
    assert gallery[0x57B8AC] == 0x30630030
    suspension = {int(r['pc'],16):int(r['owned_word'],16) for r in rows[6]['comparisons']}
    assert suspension[0x37AA60] == 0x8C420028 and suspension[0x37AA68] == 0x24050001
    # Direct call search only. Indirect calls and embedded pointers are not
    # excluded by this lexical generated-source search.
    direct = []
    candidates = subprocess.run(['rg','-l','func_(15F3F0|37AA40)',
        'recomp/config/output','recomp/config/output_ovl','--glob','*.cpp'],
        cwd=ROOT,capture_output=True,text=True,check=True).stdout.splitlines()
    for relative in candidates:
        path = ROOT / relative
        raw = path.read_text(encoding='utf8')
        matches = [(int(a,16),int(w,16)) for a,w in re.findall(r'// 0x([\da-fA-F]+): 0x([\da-fA-F]+)',raw)]
        calls = sorted({(a,(w & 0x3ffffff)*4) for a,w in matches if w >> 26 in (2,3) and (w & 0x3ffffff)*4 in (0x15F3F0,0x37AA40)})
        if calls:
            assert 'output_ovl' not in path.parts, 'New overlay direct caller needs its own owned-word reader'
            for address, target in calls:
                original = struct.unpack('<I',main_read(address,4))[0]
                assert original >> 26 in (2,3) and (original & 0x3ffffff)*4 == target
            direct.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),calls=[dict(pc=hex(a),target=hex(t)) for a,t in calls]))
    result = dict(schema=1, status='static source and owned-word control audit passed', game_run=False,
        process_access=False, existing_files_edited=False, inputs_sha256=inputs,
        sources=rows, public_vtable_address='0x22dce8', pause_slot='0x28',
        pause_target='0x15f3f0', direct_pause_source_references=direct,
        direct_search_boundary=['recomp/config/output/**/*.cpp','recomp/config/output_ovl/**/*.cpp'],
        limitations=['Direct lexical references do not exclude indirect/dynamic calls.',
                     'No injected game error, pause operation, or recovery was executed.',
                     'Status4 and EOF3 have distinct original branches to the same destroy callee; this is not proof they have the same cause.'])
    args.output.mkdir(parents=True)
    (args.output/'audit.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status=result['status'],matched=sum(r['matched_comments'] for r in rows),omitted_zero=sum(r['omitted_zero_words'] for r in rows),direct_reference_files=len(direct))))


if __name__ == '__main__':
    main()
