"""Read-only File #1 offline human-input selection audit against owned words."""
import argparse
import hashlib
import json
import struct
from pathlib import Path

from audit_retail_effect_descriptors import compare_source, elf_reader

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', required=True, type=Path)
    args = parser.parse_args()
    output = args.output.resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if output.exists() or output == allowed or not output.is_relative_to(allowed):
        raise ValueError('A fresh private evidence folder is required')
    elf = ROOT / 'game_data/SLUS_207.65'
    overlay = ROOT / 'build-function-index/owned-overlays/o2.bin'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    main_read = elf_reader(elf.read_bytes())
    data = overlay.read_bytes()
    base = struct.unpack_from('<I', data, 8)[0]
    overlay_read = lambda at, count: data[at-base:at-base+count]
    profiles = [
        ('complete session-mode getter leaf', 'main', 'sub_001B0300_0x1b0300', 0x1B0300, 0x1B030C),
        ('complete mode-zero predicate', 'main', 'sub_001B02D0_0x1b02d0', 0x1B02D0, 0x1B0300),
        ('complete actor input router', 'main', 'sub_001B0B80_0x1b0b80', 0x1B0B80, 0x1B0DA8),
        ('complete controller-map setter leaf', 'main', 'sub_001B0AA0_0x1b0aa0', 0x1B0AA0, 0x1B0AB8),
        ('complete launch-roster initializer', 'o2', 'o2_005EB0D0_0x5eb0d0', 0x5EB0D0, 0x5EB20C),
        ('complete roster resource/index bootstrap', 'o2', 'o2_005EB520_0x5eb520', 0x5EB520, 0x5EB6CC),
        ('complete eight-slot actor update loop', 'o2', 'o2_00669F30_0x669f30', 0x669F30, 0x66A2DC),
    ]
    rows = []
    for role, image, name, start, end in profiles:
        folder = 'recomp/config/output' if image == 'main' else 'recomp/config/output_ovl/o2'
        rows.append(compare_source(role, f'{folder}/{name}.cpp', start, end,
                                   main_read if image == 'main' else overlay_read))
    selected = {
        'mode': {0x1B0300: 0x3C010032, 0x1B0308: 0x902243F2},
        'router': {0x1B0B90: 0x0000882D, 0x1B0BA0: 0x14430007,
                   0x1B0BAC: 0x9023ADED, 0x1B0BC8: 0x14400007,
                   0x1B0BE4: 0x80710000, 0x1B0BE8: 0x92030FF0,
                   0x1B0BEC: 0x14600069},
        'roster': {0x5EB154: 0xA0400FF0, 0x5EB15C: 0x92030004,
                   0x5EB174: 0x24040001, 0x5EB19C: 0xA0440FF0,
                   0x5EB1A4: 0x92050005},
        'index': {0x5EB594: 0x24635C30, 0x5EB598: 0xA0640003,
                  0x5EB59C: 0x24840001, 0x5EB5A0: 0x246310E0},
        'temporary': {0x66A010: 0x92020003, 0x66A018: 0xA022ADED,
                      0x66A2C4: 0xA020ADED},
    }
    for image, words in selected.items():
        read = overlay_read if image in ('roster', 'index', 'temporary') else main_read
        for address, expected in words.items():
            assert struct.unpack('<I', read(address, 4))[0] == expected, hex(address)
    result = dict(
        schema=1, status='offline human-input selector and transient actor index verified statically',
        game_run=False, process_access=False, window_actions=False, source_edits=False,
        inputs_sha256={str(p.relative_to(ROOT)): sha(p) for p in (elf, overlay)},
        bodies=rows, selected_owned_words={kind: {hex(a): hex(w) for a, w in words.items()}
                                          for kind, words in selected.items()},
        selector=dict(session_mode_address='0x3243f2', session_mode_width='unsigned byte',
                      admitted_mode=0, actor_base='0x4a5c30', actor_stride='0x10e0',
                      conservative_scan_count=4, original_loop_count=8,
                      input_admission='actor+0xff0 == 0 in session mode 0; port 0',
                      original_input_class_guard=False, physical_slot_identity='actor byte+3',
                      human_count='unsigned byte 0x316684', ai_count='unsigned byte 0x316685',
                      transient_index='0x4baded', transient_index_is_permanent_human=False,
                      fixed_slot_zero_proven_unconditionally=False),
        limitations=[
            'No new runtime values or character identity were observed.',
            'Use unique active FF0-zero actor plus stable identity and explicit mode-zero admission; ambiguity must fail.',
            'Four-player scan and optional class-zero filter are conservative diagnostic admission, not extra original router predicates.',
            'Slot zero follows only if the actual launch human count is one and its initialized actor remains eligible.',
            'Network mode one and modes two/three use different routing; this selector does not admit them.',
        ])
    output.mkdir(parents=True)
    (output / 'audit.json').write_text(json.dumps(result, indent=2) + '\n', encoding='utf8')
    print(json.dumps(dict(status=result['status'], bodies=len(rows),
                         matched=sum(r['matched_comments'] for r in rows),
                         omitted_zero=sum(r['omitted_zero_words'] for r in rows),
                         mismatches=0)))


if __name__ == '__main__':
    main()
