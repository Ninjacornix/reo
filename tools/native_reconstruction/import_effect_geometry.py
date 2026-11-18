"""Extract owned physical effect NBDs and same-archive efdata partners."""
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda body: hashlib.sha256(body).hexdigest()


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--output', type=Path, required=True)
    args = p.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    inventory = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    assert sha(inventory.read_bytes()) == '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    members = json.loads(inventory.read_bytes())
    selected = []
    payloads = []
    iso = ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso'
    assert iso.stat().st_size == 4698767360
    with iso.open('rb') as source:
        for member in members:
            match = re.fullmatch(r'ef(\d+)\.nbd', member['names'][-1], re.I) if member['names'] else None
            if not match:
                continue
            name = 'efdata' + match[1] + '.bin'
            partners = [m for m in members if m['names'] and m['container'] == member['container'] and m['names'][:-1] == member['names'][:-1] and m['names'][-1].lower() == name]
            assert len(partners) == 1
            for asset in [member, partners[0]]:
                source.seek(asset['iso_offset'])
                body = source.read(asset['bytes'])
                assert sha(body) == asset['sha256']
                selected.append(asset)
                payloads.append(body)
    assert len(payloads) == 12
    package = struct.pack('<I', len(payloads)) + b''.join(struct.pack('<I', len(b)) + b for b in payloads)
    out.mkdir(parents=True)
    (out / 'owned_effect_geometry.bin').write_bytes(package)
    (out / 'source_import_effect_geometry.py').write_bytes(Path(__file__).read_bytes())
    receipt = dict(schema=1, game_run=False, assets=selected, original_assets_changed=False,
                   inventory_sha256=sha(inventory.read_bytes()), source_tool_sha256=sha(Path(__file__).read_bytes()),
                   selection='all six physically named EF*.NBD members, each paired with efdata of the same number in the same archive',
                   package_sha256=sha(package), bytes=len(package))
    (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(dict(pairs=6, bytes=len(package), output=str(out))))


if __name__ == '__main__':
    main()
