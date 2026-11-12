"""Pin cinematic primary/linked dispatch boundaries against owned File1 words."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
from audit_retail_effect_descriptors import compare_source

ROOT = Path(__file__).resolve().parents[2]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    images = {}
    for bank, expected in [('o2', '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'),
                           ('o0', 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2')]:
        image = ROOT / 'build-function-index/owned-overlays' / (bank + '.bin')
        assert sha(image) == expected
        images[bank] = image.read_bytes()
    files = [Path(__file__).resolve()]
    proof = []
    for at in [0x66b500, 0x67be90, 0x67bc90, 0x67be60, 0x6ba880, 0x5ecae0,
               0x5ecb80, 0x5ecbe0, 0x66a2e0, 0x376cf0, 0x375550, 0x61a6a0,
               0x61a820, 0x67c250]:
        bank = 'o2' if at >= 0x570000 else 'o0'
        base = 0x570000 if bank == 'o2' else 0x370000
        source = next((ROOT / 'recomp/config/output_ovl' / bank).glob(f'{bank}_{at:08X}_*'))
        begin, end = map(lambda s: int(s, 16), re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', source.read_text()).groups())
        assert begin == at
        proof.append(compare_source('complete cinematic actor dispatch boundary', source.relative_to(ROOT).as_posix(), begin, end,
                                    lambda address, size: images[bank][address-base:address-base+size]))
        files.append(source)
    read = lambda at, size: images['o2'][at-0x570000:at-0x570000+size]
    primary = struct.unpack('<16I', read(0x712bd0, 64))
    secondary = struct.unpack('<16I', read(0x712c10, 64))
    assert primary[6] == 0x66b950 and secondary[6] == 0x67be90
    assert [struct.unpack('<3I', read(at, 12)) for at in [0x70b010, 0x70b040]] == [
        (0x40e00000, 0, 0x40c00000), (0x40d33333, 0, 0x40b00000)]
    result = dict(schema=1, status='static_owned_dispatch_audit', game_run=False, installed_in_game=False, stage4_complete=False,
                  source_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in files}, original_owned_bodies=proof,
                  owned_data={hex(at): read(at, size).hex() for at, size in [(0x712bd0, 64), (0x712c10, 64), (0x70b010, 12), (0x70b040, 12)]},
                  action_six=dict(primary_pass=hex(primary[6]), secondary_pass=hex(secondary[6]), linked_callback='0x6ba880'),
                  findings=['67BE90 is the real action-six secondary dispatch target. 6BA880 is a distinct linked callback.',
                            '67BE90 cue states1 and2 both execute67BC90 then67BE60. State1 first changes visibility/cue and clears action substates.',
                            'Primary root integration and actor basis publication belong to the enclosing66A2E0 frame, not67BE90.',
                            '5ECAE0 visits active temporary players then the auxiliary linked population, restoring secondary links before common frames.',
                            '5ECB80 publishes active temporary models through376CF0;5ECBE0 has separate active/visible reaction/secondary-pose work.',
                            '67C250 resets unrelated face/matrix resource bookkeeping; it is not the cinematic model traversal.'],
                  limitations=['Static source/data audit. Native execution, secondary-pose chain ownership, full scene scheduling and installed acceptance require separate evidence.'])
    out.mkdir()
    for source in files:
        target = out / 'source' / source.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(source.read_bytes())
    (out / 'receipt.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(dict(status=result['status'], bodies=len(proof), action_six=result['action_six'])))


if __name__ == '__main__':
    main()
