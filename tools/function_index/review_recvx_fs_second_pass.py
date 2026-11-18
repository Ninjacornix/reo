#!/usr/bin/env python3
"""Hash-bound, offline CVX/Outbreak filesystem comparison evidence.

Only reads source and original words. Does not execute guest instructions,
build either project, or write the shared index or the first-pass reports.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct
import subprocess

from index import Elf, ELF_SHA

ROOT = Path(__file__).resolve().parents[2]
REVISION = '657b0c0c9489943116c71f151804ad7304fca975'
REL = 'cri/mwlib/ee/lib/libadxe/'
CASES = {
    'cri_cvfs.c': ['cvFsClose', 'cvFsExecServer', 'cvFsGetFileSize',
        'cvFsGetFileSizeEx', 'cvFsSetSctLen', 'cvFsGetNumTr',
        'cvFsGetNumFiles', 'getNumFilesAll', 'getNumFiles',
        'cvFsLoadDirInfo', 'cvFsOptFn1', 'cvFsOptFn2'],
    'dvci.c': ['dvCiGetFileSize', 'dvCiSeek', 'dvCiTell', 'dvCiGetNumTr'],
    'htci.c': ['htCiGetFileSize', 'htCiSeek', 'htCiTell', 'htCiGetNumTr'],
    'adx_fs.c': ['adxf_SetAfsFileInfo', 'ADXF_OpenAfs', 'ADXF_GetFsizeSct',
        'ADXF_GetFsizeByte', 'ADXF_GetFnameRangeEx'],
}
ENTRIES = [0x129168, 0x129240, 0x129C08, 0x129CA8, 0x129E18,
    0x135560, 0x135888, 0x135C80, 0x135EF0, 0x135FB8, 0x136078,
    0x136148, 0x136350, 0x1363A8, 0x136578, 0x136688, 0x136AA8,
    0x136B10, 0x136F98, 0x136FE8, 0x137138, 0x1371F0, 0x139FE8,
    0x13A088, 0x13A160, 0x13A168, 0x13A180, 0x13B308, 0x13B330,
    0x13BBE8, 0x13BC38, 0x13BCA0, 0x13BCC0, 0x13BCF0]
CROSSWALK = [
    dict(notebook='SYMBOLS_CRI.md', cvx_file='src/' + REL + 'cri_cvfs.c', rows=[
        ['135C80', 'cvFsClose', 'supported-role', 'Both release the wrapper only after a callable Close returns; missing Close diagnoses and retains it.'],
        ['136350', 'cvFsSetSctLen', 'related-different', 'Outbreak leaves a1 and other argument registers unchanged when replacing a0 with the backend object. CVX source passes only the object despite its public two-argument prototype. Do not drop the Outbreak length argument.'],
        ['1363A8', 'cvFsGetNumTr', 'supported-role', 'Same +0x38 dispatch. Both owned Outbreak providers return bytes from completed sectors only in state1; CVX concrete providers instead expose their seek/Tell cursor times2048 without a state guard.'],
        ['136578', 'getNumFiles', 'name-candidate', 'Private CVX helper matches full strlen/input-length-prefix/32-device scan/first-callable/default0 legacy route and no explicit callback arguments. Outbreak adds capability selector64 and optional selector4; no NULL aggregation, provider implementation or extension-result unit is proved.'],
        ['136688', 'cvFsLoadDirInfo', 'name-candidate', 'Full split/default/three original arguments/+0x48/duplicated IsExistFile diagnostic supports qualified alias; Outbreak additionally rewrites scratch path, but still forwards original arguments.'],
        ['135FB8', 'cvFsGetFileSize', 'related-different', 'Same resolved-path +8 size query, but Outbreak adds rewrite/default fallback; its NULL-interface diagnostic can return into a NULL +8 load, unlike CVX explicit return.'],
        ['136078', 'cvFsGetFileSizeEx', 'related-different', 'Same resolved-path +0x5C plus original second argument. Outbreak adds resolver behavior and may continue to NULL +0x5C load after its returning diagnostic.'],
    ]),
    dict(notebook='SYMBOLS.md', cvx_file='src/' + REL + 'cri_cvfs.c', rows=[
        ['135EF0', 'cvFsExecServer', 'name-candidate', 'Complete 32-slot registry scan and nonnull interface/method0 guards agree; candidate alias now recorded on the existing authoritative row.']]),
    dict(notebook='SYMBOLS_CVFS_64BIT_FILE_SIZE_QUERY_ROUTES.md', cvx_file='src/' + REL + 'cri_cvfs.c', rows=[
        ['137138', 'cvFsGetFileSize', 'related-different', 'Related filename-size purpose only: Outbreak uses two optional CA/CB halves with original name plus resolved-path argument, and lacks a NULL resolver guard; CVX calls ordinary +8 once and has no such 64-bit API here.'],
        ['1371F0', 'cvFsGetFileSizeEx', 'related-different', 'Related size-with-parameter purpose only: Outbreak performs uninitialized stack device lookup before splitting, then CC/CD half queries. CVX explicit initialization/validation cannot be substituted as proof of intended admission.']]),
    dict(notebook='SYMBOLS_CRI_BACKENDS.md', cvx_file='src/' + REL + 'dvci.c', rows=[
        ['139FE8', 'dvCiGetNumTr', 'related-different', 'Both return byte quantities, but Outbreak uses completed-count+0x14 only in state1. CVX returns req_nsct*2048 without state guard; that same field is modified by Seek and returned by Tell.']]),
    dict(notebook='SYMBOLS_CRI_BACKENDS.md', cvx_file='src/' + REL + 'htci.c', rows=[
        ['13BBE8', 'htCiGetNumTr', 'related-different', 'Outbreak returns completed-count+0x28 shifted11 only in state1; CVX returns Seek/Tell req_nsct*2048 regardless of state. Neither getter alone proves completion of arbitrary pending I/O.'],
        ['13B308', 'htCiGetFileSize', 'related-different', 'Owned interface +8 is a signed-low32 adapter around wider13B330. CVX exposes a Sint32 cached/open/seek-end/close query directly and has no CA..CD optional methods.']]),
    dict(notebook='SYMBOLS_CRI.md', cvx_file='src/' + REL + 'adx_fs.c', rows=[
        ['129168', 'adxf_SetAfsFileInfo', 'related-different', 'Shared partition/member resolution and sector-byte sizing. CVX opens a new stream; Outbreak reconfigures existing stream+4 with richer parent/path bounds and rejects status4.'],
        ['129240', 'ADXF_OpenAfs', 'supported-role', 'Both log operation2, create a record, delegate partition/member setup, close on negative setup and return NULL on failure. Child stream contracts and guards differ.'],
        ['129C08', 'ADXF_GetFsizeSct', 'related-different', 'CVX is a field getter. Outbreak conditionally refreshes oversized cached metadata, always queries stream bytes on remaining valid paths, divides signed toward zero by2048 and can return-5.'],
        ['129CA8', 'ADXF_GetFsizeByte', 'related-different', 'CVX returns fsize and preserves NULL -3. Outbreak shifts the result of129C08 by11, including errors (-3 becomes -6144), so this is sector-derived bytes rather than an exact unpadded byte field.']]),
    dict(notebook='SYMBOLS_ADXF_RESIDUAL_PARTITION_AND_PROGRESS_CONTROLS.md', cvx_file='src/' + REL + 'adx_fs.c', rows=[
        ['129E18', 'ADXF_GetFnameRangeEx', 'related-different', 'Shared validated path/parent/range output and cumulative16-bit member lengths; Outbreak additionally selects32-bit lengths by descriptor+F, adds descriptor+114 base, and does not walk CVX linked additive partitions.']]),
]


def digest(data):
    return hashlib.sha256(data).hexdigest()


def source_body(text, name):
    # Declaration line, braces balanced outside C strings/comments. These
    # selected functions contain no braces in their literals or comments.
    match = re.search(r'^.*\b' + re.escape(name) + r'\([^;\n]*\)\s*\{', text, re.M)
    assert match, name
    start = text.index('{', match.start())
    depth = 1
    end = start + 1
    while depth:
        depth += (text[end] == '{') - (text[end] == '}')
        end += 1
    return text[match.start():end], text.count('\n', 0, match.start()) + 1, text.count('\n', 0, end) + 1


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference', type=Path, default=Path(
        'C:/Users/Ninjacornix/AppData/Local/Temp/reo-recvx-crosscheck-20261104'))
    parser.add_argument('--output', type=Path, default=ROOT / 'build-function-index/review_recvx_fs_second_pass.json')
    args = parser.parse_args()
    ref = args.reference.resolve()
    git = lambda *a: subprocess.check_output(['git', '-C', str(ref), *a], text=True).strip()
    assert git('rev-parse', 'HEAD') == REVISION
    assert not git('status', '--porcelain'), 'reference must remain clean'
    references = []
    bodies = {}
    for filename, names in CASES.items():
        for prefix, selected in [('src/', names), ('include/', [])]:
            path = prefix + REL + (filename if prefix == 'src/' else filename[:-2] + '.h')
            data = (ref / path).read_bytes()
            # Pin against the repository object too, not just its worktree path.
            original = subprocess.check_output(['git', '-C', str(ref), 'show', REVISION + ':' + path])
            assert data.replace(b'\r\n', b'\n') == original.replace(b'\r\n', b'\n'), path
            text = data.decode('utf-8').replace('\r\n', '\n')
            functions = []
            for name in selected:
                body, first, last = source_body(text, name)
                bodies[name] = body
                functions.append(dict(name=name, first_line=first, last_line=last,
                    normalized_lf_body_sha256=digest(body.encode()), body=body))
            references.append(dict(path=path, sha256=digest(data),
                git_blob_sha256=digest(original), functions=functions))
    assert 'cvfsif->LoadDirInfo(name, inf, num)' in bodies['cvFsLoadDirInfo']
    assert 'cvFsIsExistFile #2:illegal device name' in bodies['cvFsLoadDirInfo']
    assert 'lp < 32' in bodies['cvFsExecServer']
    assert 'strlen((const char*)devname)' in bodies['getNumFiles']
    assert 'cvfsif->GetNumFiles()' in bodies['getNumFiles']
    assert 'cvfs->vtbl->SetSctLen(cvfs->obj)' in bodies['cvFsSetSctLen']
    assert 'cvfs->vtbl->OptFn1(cvfs->obj)' in bodies['cvFsOptFn1']
    assert 'cvfs->vtbl->OptFn2(cvfs->obj)' in bodies['cvFsOptFn2']
    assert 'return adxf->fsize;' in bodies['ADXF_GetFsizeByte']
    for prefix in ('dvci', 'htci'):
        name = 'dvCi' if prefix == 'dvci' else 'htCi'
        assert f'return {prefix}->req_nsct * 2048;' in bodies[name + 'GetNumTr']
        assert '->stat' not in bodies[name + 'GetNumTr']
        assert f'return {prefix}->req_nsct;' in bodies[name + 'Tell']
    elf = Elf(ROOT / 'game_data/SLUS_207.65')
    db = sqlite3.connect('file:' + (ROOT / 'build-function-index/index.sqlite').as_posix() + '?mode=ro', uri=True)
    db.row_factory = sqlite3.Row
    functions = []
    comments_total = omitted_total = 0
    def words(start, count):
        return struct.unpack('<' + 'I' * count, elf.read(start, count * 4))
    for entry in ENTRIES:
        row = db.execute('select * from functions where image=? and start=?', ('main', entry)).fetchone()
        assert row and row['source']
        source = (ROOT / row['source']).read_text()
        comments = {int(m[1], 16): int(m[2], 16) for m in re.finditer(
            r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s', source, re.I)
            if entry <= int(m[1], 16) < row['end']}
        raw = elf.read(entry, row['end'] - entry)
        original_words = words(entry, len(raw) // 4)
        for i, word in enumerate(original_words):
            pc = entry + i * 4
            if pc in comments:
                assert comments[pc] == word, hex(pc)
            else:
                assert word == 0, ('omitted nonzero word', hex(pc))
        omitted = len(original_words) - len(comments)
        comments_total += len(comments)
        omitted_total += omitted
        functions.append(dict(entry=hex(entry), end_exclusive=hex(row['end']),
            source=row['source'], original_sha256=digest(raw),
            comment_words=len(comments), omitted_zero_words=omitted,
            words=[dict(pc=hex(entry + i * 4), word=f'{w:08X}') for i, w in enumerate(original_words)]))
    # Exact original instructions for the evidence-sensitive boundaries.
    checks = {
        0x135CCC: 0xDFBF0008, # valid Close continuation restores then tails clear
        0x135CD4: 0x08000000 | (0x135AC0 >> 2),
        0x135CEC: 0x08000000 | (0x135200 >> 2), # missing method tail diagnostic
        0x136380: 0x0040F809, 0x136384: 0x8C840004,
        0x136AE0: 0x0040F809, 0x136AE4: 0x8C840004,
        0x136B48: 0x0040F809, 0x136B4C: 0x8C840004,
        0x136630: 0x8E100044, 0x136638: 0,
        0x13663C: 0x0200F809, 0x136640: 0,
        0x136FBC: 0x0000202D, # capability helper clears a0, not preserved name
        0x13A024: 0x000212C0, 0x13BC24: 0x000212C0,
        0x129CBC: 0x000212C0,
    }
    for pc, word in checks.items():
        assert words(pc, 1)[0] == word, hex(pc)
    tables = []
    for address, expected in [
        (0x21CBF8, '110e07237b9879134ef9aa44289116e0a63f2ff0392b117f842bebb325692d8a'),
        (0x21DA88, '40df6d55908bd06ecee4d4c144c3a30a7a3b2aed1f0afcd9202dd43ffd3f2a00')]:
        data = elf.read(address, 104)
        assert digest(data) == expected
        values = words(address, 26)
        assert values[0x44 // 4] == values[0x48 // 4] == 0
        tables.append(dict(address=hex(address), sha256=expected,
            entries={f'{4*i:02X}': hex(w) for i, w in enumerate(values)}))
    out = dict(schema=1, purpose='static filesystem comparison; no new mapping credit from this receipt',
        original_elf_sha256=ELF_SHA, reference_revision=REVISION, references=references,
        functions=functions, provider_tables=tables, crosswalk_additions=CROSSWALK,
        audit=dict(full_original_functions=len(functions), original_comment_words=comments_total,
            omitted_zero_words=omitted_total, conflicts=0, omitted_nonzero_words=0),
        unresolved=['136578 optional selector4 implementation and output units; method44 has no explicit argument setup',
            '1371F0 admission before initialization', 'external/dynamically registered provider contracts'])
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(dict(receipt=str(args.output), audit=out['audit'], references=[
        dict(path=r['path'], sha256=r['sha256']) for r in references]), indent=2))


if __name__ == '__main__':
    main()
