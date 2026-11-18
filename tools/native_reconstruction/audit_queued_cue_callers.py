#!/usr/bin/env python3
"""Resolve owned File1 static scene/gallery cue tables against native admission.

Read-only owned assets and prior native preparation evidence. No game execution,
save edits, soundtrack pairing guesses or general indirect-call reachability claim.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
OVERLAYS = {
    'o1': '719ce452cb267d5475a9fa8f06e78e977932311e081c6ec90bb34a6a74a780da',
    'o2': '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226',
}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if args.output.exists():
        raise ValueError('Preserve earlier evidence; use a fresh output folder')
    evidence = {}

    def pin(path, expected=None):
        digest = sha(path)
        if expected is not None and digest != expected:
            raise ValueError('Changed evidence: ' + str(path))
        evidence[path.relative_to(ROOT).as_posix()] = digest
        return path.read_bytes()

    images = {name: pin(ROOT / 'build-function-index/owned-overlays' / (name + '.bin'), digest)
              for name, digest in OVERLAYS.items()}
    sys.path.insert(0, str(ROOT / 'tools/function_index'))
    from index import Elf
    elf_path = ROOT / 'game_data/SLUS_207.65'
    elf = Elf(elf_path)
    pin(elf_path, elf.sha256)
    for entry in (0x1ab050, 0x1ab2f0):
        source = pin(ROOT / f'recomp/config/output/sub_{entry:08X}_0x{entry:x}.cpp').decode('utf8')
        for pc, word in re.findall(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s', source, re.I):
            assert struct.unpack('<I', elf.read(int(pc, 16), 4))[0] == int(word, 16)
    sound_names = []
    for index in range(422):
        pointer = struct.unpack('<I', elf.read(0x2337c0 + index * 4, 4))[0]
        encoded = elf.read(pointer, 256)
        assert encoded is not None and b'\0' in encoded
        sound_names.append(bytes(value ^ 255 for value in encoded.split(b'\0', 1)[0]).decode('ascii'))

    def read(image, at, count):
        data = images[image]
        if not 0x570000 <= at <= 0x570000 + len(data) - count:
            raise ValueError('Table access outside pinned overlay')
        return data[at - 0x570000:at - 0x570000 + count]

    def text(image, at):
        data = read(image, at, min(128, 0x570000 + len(images[image]) - at))
        if b'\0' not in data:
            raise ValueError('Unterminated bounded string')
        return data.split(b'\0', 1)[0].decode('ascii')

    sources = []
    for image, entry in (('o1', 0x570080), ('o1', 0x570100), ('o1', 0x570180),
                         ('o2', 0x6d7470), ('o2', 0x6d7520)):
        path = ROOT / f'recomp/config/output_ovl/{image}/{image}_{entry:08X}_0x{entry:x}.cpp'
        source = pin(path).decode('utf8')
        words = {int(pc, 16): int(word, 16) for pc, word in
                 re.findall(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s', source, re.I)}
        assert words and all(struct.unpack('<I', read(image, pc, 4))[0] == word
                             for pc, word in words.items())
        sources.append(dict(image=image, entry=hex(entry), verified_words=len(words)))

    qualification = ROOT / 'tools/native_reconstruction/owned_cue_admission_qualification_v1.json'
    qualified = json.loads(pin(qualification))
    base = ROOT / 'build-native-sjuni/queued-audio-checks/owned-assets-llvm-v1'
    data = {}
    for name in ('planned-members.json', 'results.jsonl'):
        path = base / name
        data[name] = pin(path, qualified['evidence_sha256'][path.relative_to(ROOT).as_posix()])
    members = json.loads(data['planned-members.json'])
    results = [json.loads(line) for line in data['results.jsonl'].splitlines()]
    assert len(members) == len(results) == 8910
    by_name = {}
    for index, member in enumerate(members):
        assert results[index]['index'] == index
        if len(member['names']) == 2 and member['names'][0] == 'adxsnd.afs' and member['names'][-1]:
            key = member['names'][-1].casefold()
            assert key not in by_name
            by_name[key] = (member, results[index])

    def resolve(name, root_name=False):
        # These callers use DEMO/name or the root E3 name. No ROM/RDT/EDIT
        # prefix stripping is involved. Preserve the resident table's indices;
        # inventory basename matching alone cannot establish the game's lookup.
        request = name if root_name else 'demo/' + name
        normalized = request.upper().translate(str.maketrans({'/': '_', '\\': '_', '.': '_', '-': '_'}))
        found = by_name.get(name.casefold())
        if normalized not in sound_names:
            assert found is None
            return dict(name=name, status='absent_from_adxsnd_named_inventory',
                        normalized_request=normalized, game_name_lookup_index=-1,
                        original_behavior='name resolution failure skips enqueue')
        lookup_index = sound_names.index(normalized)
        assert found is not None
        member, result = found
        assert member['member'] == f'NETBIO01.DAT/0/{lookup_index}'
        return dict(name=name, member=member['member'], status=result['status'],
                    normalized_request=normalized, game_name_lookup_index=lookup_index,
                    channels=member['adx']['channels'], frequency=member['adx']['frequency'],
                    samples=member['adx']['total_samples'],
                    inline_loop=bool(member['adx'].get('loop', {}).get('enabled')))

    assert [text('o2', at) for at in (0x7426b8, 0x7426c8, 0x7426d8)] == [
        '%02d_%02d_%d', '%s%s.adx', 'demo\\']
    scene = []
    layout = [(1, 0x731e40, 105), (2, 0x732190, 40), (28, 0x7322e0, 42),
              (35, 0x732440, 43), (41, 0x7325a0, 93)]
    for index, (scenario, pointer, count) in enumerate(layout):
        assert struct.unpack('<II', read('o2', 0x732890 + index * 8, 8)) == (scenario, pointer)
        for row in range(count):
            key, value = struct.unpack('<II', read('o2', pointer + row * 8, 8))
            cue = resolve(text('o2', value) + '.adx')
            scene.append(dict(scenario=scenario, key=text('o2', key), cue=cue))
        assert struct.unpack('<I', read('o2', pointer + count * 8, 4))[0] == 0
    assert struct.unpack('<iI', read('o2', 0x732890 + 5 * 8, 8)) == (-1, 0)
    assert text('o1', 0x5909a0) == 'demo\\s%02d%02d%02d'
    assert text('o1', 0x5909b8) == '.adx'
    gallery = []
    for movie in range(1, 70):
        record = read('o1', 0x589c20 + movie * 20, 20)
        scenario = struct.unpack_from('<I', record, 4)[0]
        width, height = struct.unpack_from('<hh', record, 8)
        if not width or not height:
            gallery.append(dict(movie=movie, admitted_geometry=False, cues=[]))
            continue
        pointer = struct.unpack_from('<I', record, 16)[0]
        cues = []
        for index in range(32):
            x, y, z = struct.unpack('<bbb', read('o1', pointer + index * 3, 3))
            if x == -1:
                break
            cues.append(resolve(f's{scenario:02d}{x:02d}{y:02d}' + chr(97 + z) + '.adx'))
        else:
            raise ValueError('Unterminated gallery cue list')
        gallery.append(dict(movie=movie, admitted_geometry=True, scenario=scenario, cues=cues))
    assert text('o1', 0x590958) == 'E3-Bio_Mix.adx'
    assert text('o1', 0x590970) == 'demo/s414000a.adx'
    special = [resolve('E3-Bio_Mix.adx', root_name=True), resolve('s414000a.adx')]
    cues = [r['cue'] for r in scene] + [c for r in gallery for c in r['cues']] + special
    present = [c for c in cues if c['status'] != 'absent_from_adxsnd_named_inventory']
    absent = sorted({c['name'] for c in cues if c['status'] == 'absent_from_adxsnd_named_inventory'})
    assert all(c['status'] == 'ready' and not c['inline_loop'] for c in present)
    for row in gallery:
        formats = {(c['channels'], c['frequency']) for c in row['cues'] if c['status'] == 'ready'}
        assert len(formats) <= 1, 'Mixed gallery playlist formats require separate handling'
    summary = dict(scene_table_rows=len(scene), scene_unique_names=len({r['cue']['name'] for r in scene}),
                   gallery_records=len(gallery), gallery_max_listed_cues=max(len(r['cues']) for r in gallery),
                   gallery_max_resolved_cues=max(sum(c['status'] == 'ready' for c in r['cues']) for r in gallery),
                   unique_resolved_members=len({c['member'] for c in present}),
                   scene_output_formats=sorted({(r['cue']['channels'], r['cue']['frequency'])
                                                for r in scene if r['cue']['status'] == 'ready'}),
                   refused_named_cues=0, inline_loop_named_cues=0, absent_names=absent)
    args.output.mkdir(parents=True)
    rows = args.output / 'callers.json'
    rows.write_text(json.dumps(dict(scene=scene, gallery=gallery, special=special), indent=2) + '\n', encoding='utf8')
    receipt = dict(schema=1, status='owned static cue tables checked against qualified native preparation',
                   source_sha256=sha(Path(__file__)), evidence_sha256=evidence, source_words=sources,
                   summary=summary, output_sha256=sha(rows), game_launched=False, asset_writes=False,
                   limitations=['Static table names and header admission, not PCM or actual game execution.',
                                'Scene list length and order are runtime descriptor data; no universal capacity proof.',
                                'Only these direct caller families; no arbitrary indirect-call absence claim.',
                                'The one absent gallery name is reported, not synthesized or enqueued.',
                                'Other queued uses of the 89 looped catalogue assets are not ruled out.'])
    (args.output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf8')
    print(json.dumps(summary))


if __name__ == '__main__':
    main()
