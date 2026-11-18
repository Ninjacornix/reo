"""Copy owned fog members into a bounded, provenance-bound offline corpus."""
import argparse
import hashlib
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda body: hashlib.sha256(body).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    output = args.output.resolve()
    assert output.is_relative_to(ROOT / 'build-native-sjuni') and not output.exists()
    inventory = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    assert sha(inventory.read_bytes()) == '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    iso = ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso'
    assert iso.stat().st_size == 4698767360
    output.mkdir(parents=True)
    selected = []
    chunks = []
    with iso.open('rb') as source:
        for member in json.loads(inventory.read_bytes()):
            if not member['names']:
                continue
            name = member['names'][-1]
            if not (name.lower().endswith('.fog')):
                continue
            source.seek(member['iso_offset'])
            body = source.read(member['bytes'])
            assert sha(body) == member['sha256']
            selected.append(member)
            chunks.append(body)
    assert len(chunks) == 229
    package = struct.pack('<I', len(chunks)) + b''.join(struct.pack('<I', len(body)) + body for body in chunks)
    (output / 'owned_fog.bin').write_bytes(package)
    receipt = dict(schema=1, game_run=False, original_assets_changed=False,
                   selection='all229 physical FOG entries in the owned File1 inventory; no reachability claim',
                   inventory_sha256=sha(inventory.read_bytes()), assets=selected,
                   source_tool_sha256=sha(Path(__file__).read_bytes()),
                   package_sha256=sha(package), bytes=len(package))
    (output / 'source_import_fog_assets.py').write_bytes(Path(__file__).read_bytes())
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(dict(assets=len(selected), bytes=len(package), output=str(output))))


if __name__ == '__main__':
    main()
