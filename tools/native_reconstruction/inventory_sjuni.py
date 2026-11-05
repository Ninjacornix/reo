#!/usr/bin/env python3
"""Offline SJUNI boundary inventory; never executes or attaches to the game.

Requires the local function index, generated comments and the owned File #1 ELF.
The committed result contains metadata, hashes and references, not game bytes.
"""
import argparse
import hashlib
import json
from pathlib import Path
import sqlite3
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/function_index'))
from index import Elf, read_instructions  # noqa: E402


# Reviewed boundaries, not a transitive call graph or proof of all pointer users.
GROUPS = {
    'local_sjuni': [0x140000, 0x140020, 0x140070, 0x1400C0, 0x1401A8,
                    0x1401E0, 0x1401E8, 0x1401F8, 0x140288, 0x140300,
                    0x140438, 0x140590, 0x1406D8, 0x140768, 0x1407A8, 0x1407E0],
    'shared_lifetime': [0x12A1E8, 0x12A388, 0x15E6A0, 0x15EA00],
    'paired_ownership': [0x13DA88, 0x13DB48, 0x13DE40, 0x13DF20, 0x13DF98,
                         0x13E2B8, 0x13E6C0, 0x13E770, 0x13EAC0],
    'typed_local_queries_and_escape': [0x12C4E0, 0x12C520, 0x13ECB0, 0x13ECF0,
                                       0x13ED28, 0x13F1C8, 0x1314E0],
    'generic_dma_consumers': [0x138650, 0x138AB8, 0x138BA8, 0x138BE0],
    'generic_sjx_consumers': [0x140F18, 0x140FB8, 0x1410C8, 0x141158,
                              0x141490, 0x141588, 0x1415D0],
    'remote_transport': [0x140B98, 0x140BF0, 0x140C20, 0x140C90, 0x140CC0,
                         0x140D30, 0x140D80, 0x140DD0, 0x140E20, 0x139460],
    'guard_and_diagnostic': [0x13F258, 0x13F270, 0x13F288, 0x1416D0, 0x1416E8,
                              0x1415E0, 0x141640, 0x12A968, 0x12A9F0],
    'guard_installation_and_dependencies': [0x10B5F8, 0x114460, 0x1144B0,
        0x114510, 0x114520, 0x114590, 0x1145B0, 0x12AB88, 0x12ABA0,
        0x12B0F0, 0x12B158, 0x12B638, 0x12B800, 0x12C1D0, 0x12C388,
        0x141800, 0x1418A8, 0x141DB0, 0x141DF0, 0x141E08],
    'remote_completion_dependencies': [0x139110, 0x139198, 0x13F1E0, 0x12C560, 0x12C598],
}
RANGES = {
    'sjuni_vtable': (0x228C60, 0x228C90),
    'sjuni_reference_count': (0x228C90, 0x228C94),
    'sjuni_objects': (0x228C98, 0x229898),
    'sjuni_uuid': (0x23DA78, 0x23DA88),
    'paired_configuration': (0x221438, 0x221480),
    'paired_records': (0x221480, 0x221780),
    'paired_local_node_storage': (0x221780, 0x223780),
    'ps2rna_groups': (0x223880, 0x223E80),
    'sjx_bindings': (0x229A90, 0x229D10),
    'dtr_records': (0x21BC08, 0x21C408),
}
VTABLE = [0, 0, 0, 0x1401A8, 0x1401E0, 0x1401F8, 0x140300,
          0x140590, 0x140438, 0x140288, 0x1406D8, 0x1401E8]
CONTEXT = [
    'recomp/overrides/reo_override.cpp', 'recomp/CMakeLists.txt',
    'third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp',
    'third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/State.h',
    'third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Thread.cpp',
    'third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Sync.cpp',
    'third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/Runtime.h',
    'third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Stubs/SIF.cpp',
    'third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_runtime.cpp',
    'third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime.h',
    'third_party/PS2Recomp/ps2xRuntime/CMakeLists.txt',
]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def iop_inventory(path, elf):
    """Hash-check owned IOP evidence; retain only function metadata/digests."""
    data = path.read_bytes()
    sha = hashlib.sha256(data).hexdigest()
    if sha != '456f07cb55a5bed66643fd95ca6ef64874265b578630b905a9328346e01aefb7':
        raise ValueError('Owned CRI IOP module identity mismatch')
    header = struct.unpack_from('<HHIIIIIHHHHHH', data, 16)
    sections = [struct.unpack_from('<10I', data, header[5] + i * header[10])
                for i in range(header[11])]
    def read(address, size):
        for section in sections:
            # Allocated file-backed sections only, never symtab/strings/NOBITS.
            if section[1] == 1 and section[2] & 2 and section[3] <= address and address + size <= section[3] + section[5]:
                off = section[4] + address - section[3]
                return data[off:off + size]
        raise ValueError(f'IOP interval is not file-backed: {address:X}')
    expected = {'sjrmt_uni_create': (0x658C, 64), 'SJUNI_Create': (0x5AB4, 200),
        'SJUNI_Reset': (0x5BC8, 128), 'SJUNI_GetNumData': (0x5C48, 116),
        'sjx_create_rmt': (0x6D28, 192), 'sjx_rcvcbf_iop': (0x6B3C, 172),
        'sjx_sndcbf_iop': (0x6BE8, 288), 'sjx_rcvcbf': (0x6970, 172),
        'sjx_sndcbf': (0x6A1C, 288)}
    symbols = {}
    for section in sections:
        if section[1] != 2:
            continue
        strings_section = sections[section[6]]
        strings = data[strings_section[4]:strings_section[4] + strings_section[5]]
        for off in range(section[4], section[4] + section[5], 16):
            nameoff, value, size, info, _, _ = struct.unpack_from('<IIIBBH', data, off)
            name = strings[nameoff:].split(b'\0')[0].decode('ascii', 'replace')
            if name in expected:
                if (value, size) != expected[name] or info & 15 != 2:
                    raise ValueError(f'Unexpected IOP symbol: {name}')
                symbols[name] = dict(start=value, size=size,
                    interval_sha256=hashlib.sha256(read(value, size)).hexdigest())
    if set(symbols) != set(expected):
        raise ValueError('Missing reviewed IOP symbols')
    uuid = read(0x9940, 16)
    if uuid != elf.read(0x23DA78, 16):
        raise ValueError('Local/remote SJUNI UUID differs')
    return dict(module_sha256=sha, functions=symbols, matching_uuid=uuid.hex(),
                evidence_kind='owned static bytes and symbol bounds; no execution')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--elf', type=Path, default=ROOT / 'game_data/SLUS_207.65')
    parser.add_argument('--db', type=Path, default=ROOT / 'build-function-index/index.sqlite')
    parser.add_argument('--iop', type=Path, default=ROOT / 'build-function-index/owned-iop/cri_adx_driver.irx')
    parser.add_argument('--out', type=Path, default=ROOT / 'docs/native-sjuni/inventory.json')
    args = parser.parse_args()
    elf = Elf(args.elf)
    db = sqlite3.connect(args.db.resolve().as_uri() + '?mode=ro', uri=True)
    db.row_factory = sqlite3.Row
    meta = {r['key']: json.loads(r['value']) for r in db.execute('SELECT * FROM metadata')}
    if meta['expected_main_elf_sha256'] != elf.sha256 or not meta['main_elf_checked']:
        raise ValueError('Index does not attest this ELF identity')
    for path, expected in meta['catalogue_hashes'].items():
        if digest(ROOT / path) != expected:
            raise ValueError(f'Stale catalogue: {path}')
    actual_vtable = list(struct.unpack('<12I', elf.read(0x228C60, 48)))
    if actual_vtable != VTABLE:
        raise ValueError('SJUNI vtable differs from reviewed boundary')

    cache = {}
    def verified(row):
        """Check complete nonzero-word coverage, while allowing omitted zero padding."""
        path = ROOT / row['source']
        if row['source'] not in cache:
            sha = digest(path)
            if sha != meta['source_hashes'].get(row['source']):
                raise ValueError(f'Stale indexed source: {path}')
            cache[row['source']] = sha, read_instructions(path)
        sha, comments = cache[row['source']]
        lo, hi = row['start'], row['end']
        if lo % 4 or hi % 4:
            raise ValueError(f'Unaligned reviewed boundary: {row["id"]}')
        raw = elf.read(lo, hi - lo)
        if raw is None:
            raise ValueError(f'Non-file-backed reviewed boundary: {row["id"]}')
        matched = omitted_zero = 0
        for pc in range(lo, hi, 4):
            word = struct.unpack_from('<I', raw, pc - lo)[0]
            if pc in comments:
                if comments[pc][0] != word:
                    raise ValueError(f'Comment conflict at {pc:X}')
                matched += 1
            elif word == 0:
                omitted_zero += 1
            else:
                raise ValueError(f'Unreviewed nonzero word at {pc:X}')
        return dict(id=row['id'], start=lo, end=hi, source=row['source'],
                    source_sha256=sha, interval_sha256=hashlib.sha256(raw).hexdigest(),
                    matched_comment_words=matched, omitted_zero_words=omitted_zero,
                    label=row['proposed_name'])

    functions = {}
    for addresses in GROUPS.values():
        for addr in addresses:
            row = db.execute('SELECT * FROM functions WHERE image=? AND start=?',
                             ('main', addr)).fetchone()
            if row is None:
                raise ValueError(f'Missing reviewed entry {addr:X}')
            functions[row['id']] = verified(row)

    incoming = []
    for row in db.execute('SELECT * FROM edges WHERE target>=? AND target<? ORDER BY target,caller,site',
                          (0x140000, 0x140840)):
        caller = db.execute('SELECT * FROM functions WHERE id=?', (row['caller'],)).fetchone()
        if caller['image'] == 'main' and 0x140000 <= caller['start'] < 0x140840:
            continue
        # The current graph has only main callers; reject a newly found overlay
        # instead of checking its PCs against the resident ELF by accident.
        if caller['image'] != 'main':
            raise ValueError(f'New overlay caller needs independent verification: {caller["id"]}')
        functions[caller['id']] = verified(caller)
        incoming.append(dict(row))

    references = []
    for row in db.execute('SELECT * FROM refs ORDER BY owner,site,physical,kind'):
        regions = [name for name, (lo, hi) in RANGES.items() if lo <= row['physical'] < hi]
        if regions:
            # Graph reference candidates remain candidates; they do not establish
            # a dereference or actual stream type in a generic caller.
            references.append(dict(row) | {'regions': regions})
            owner = db.execute('SELECT * FROM functions WHERE id=?', (row['owner'],)).fetchone()
            if owner['image'] != 'main':
                raise ValueError(f'New overlay reference needs independent verification: {owner["id"]}')
            functions[owner['id']] = verified(owner)

    # Search *file-backed aligned words* for function-pointer candidates. Code
    # words with the same value remain candidates, not asserted pointer tables.
    targets = set(GROUPS['local_sjuni'])
    pointer_words = []
    for base, offset, size in elf.segments:
        for delta in range((-base) % 4, size - 3, 4):
            value = struct.unpack_from('<I', elf.data, offset + delta)[0]
            if value in targets:
                pointer_words.append(dict(address=base + delta, target=value))

    def git(*args):
        return subprocess.check_output(['git', *args], cwd=ROOT, text=True).strip()

    context = dict(
        source_sha256={p: digest(ROOT / p) for p in CONTEXT},
        recorded_submodule=git('ls-tree', 'HEAD', 'third_party/PS2Recomp'),
        local_submodule_head=git('-C', 'third_party/PS2Recomp', 'rev-parse', 'HEAD'),
        local_submodule_status=git('-C', 'third_party/PS2Recomp', 'status', '--porcelain=v1').splitlines(),
        patch_sha256={p.relative_to(ROOT).as_posix(): digest(p)
                      for p in sorted((ROOT / 'third_party/patches/ps2recomp').glob('*.patch'))},
        patch_application_state='not independently verified in this inventory',
        matching_compiled_library_identity='not established; no build or running-process inspection')

    payload = dict(
        schema=1, edition='SLUS-20765', evidence_kind='static-offline',
        elf_sha256=elf.sha256, catalogue_hashes=meta['catalogue_hashes'],
        groups=GROUPS, ranges=RANGES, vtable=actual_vtable,
        verified_main_intervals=sorted(functions.values(), key=lambda r: r['start']),
        indexed_external_direct_edges=incoming,
        indexed_global_reference_candidates=references,
        main_file_backed_pointer_word_candidates=pointer_words,
        native_runtime_source_context=context,
        owned_iop_context=iop_inventory(args.iop, elf),
        limitations=[
            'Selected intervals verified against original words; static behavior is not execution.',
            'Direct edges/refs use the existing graph; pointer escapes and indirect calls need manual review.',
            'All returned edge/ref owners are word-verified; sources outside those owners are not revalidated.',
            'Pointer-word scan covers aligned words in main ELF PT_LOAD file bytes only, not overlays/BSS.',
            'Generic SJ consumers may receive SJRB/SJMEM or another implementation.',
            'No proof of complete field-access closure, native parity, synchronization or performance.',
        ])
    db.close()
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(payload, indent=2, ensure_ascii=False) + '\n', encoding='utf-8')
    print(json.dumps(dict(intervals=len(functions),
                          matched_words=sum(f['matched_comment_words'] for f in functions.values()),
                          omitted_zero_words=sum(f['omitted_zero_words'] for f in functions.values()),
                          external_direct_edges=len(incoming),
                          global_reference_candidates=len(references),
                          pointer_word_candidates=len(pointer_words))))


if __name__ == '__main__':
    main()
