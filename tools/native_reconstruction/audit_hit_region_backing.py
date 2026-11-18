"""Offline owned-source/data audit of the scanner's advanced region pointer."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
from audit_retail_effect_descriptors import compare_source

ROOT = Path(__file__).resolve().parents[2]


def sha(body):
    return hashlib.sha256(body).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    output = args.output.resolve()
    assert output.is_relative_to(ROOT / 'build-native-sjuni') and not output.exists()
    image = ROOT / 'build-function-index/owned-overlays/o2.bin'
    raw = image.read_bytes()
    assert sha(raw) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    def read(address, size):
        offset = address - 0x570000
        assert offset >= 0 and offset + size <= len(raw)
        return raw[offset:offset + size]
    def word(address):
        return struct.unpack('<I', read(address, 4))[0]
    def region_list(address):
        for count in range(256):
            if struct.unpack('<f', read(address + 20 * count + 12, 4))[0] == -1:
                return count, sha(read(address, (count + 1) * 20))
        raise ValueError('No bounded region terminator')
    sources = sorted((ROOT / 'recomp/config/output_ovl/o2').glob('*.cpp'))
    store_pattern = re.compile(r'// (0x[\da-fA-F]+): (0x[\da-f]+)  (swc1|sw|sq|sd)\s+.*?0x([\dA-Fa-f]+)\(')
    stores = {offset: [] for offset in [0x1dc, 0xb1c, 0xb20, 0xb24]}
    index = hashlib.sha256()
    for path in sources:
        body = path.read_bytes()
        relative = path.relative_to(ROOT).as_posix()
        index.update((relative + '\0' + sha(body) + '\n').encode())
        for match in store_pattern.finditer(body.decode()):
            offset = int(match[4], 16)
            if offset in stores:
                stores[offset].append(dict(path=relative, source_sha256=sha(body),
                                           pc=match[1], instruction=match[0].removeprefix('// ')))
    initializers = ['0066A750', '006834B0', '006837C0', '006BBDA0']
    assert len(stores[0x1dc]) == 4
    audits = []
    for name in initializers + ['005DC1B0', '0057AC60', '0057B6F0']:
        path = next((ROOT / 'recomp/config/output_ovl/o2').glob('o2_' + name + '_*'))
        start, end = [int(value, 16) for value in re.search(
            r'// Address: (0x[\da-f]+) - (0x[\da-f]+)', path.read_text()).groups()]
        audit = compare_source('region backing and advanced-pointer source', path.relative_to(ROOT).as_posix(), start, end, read)
        # Keep the complete proof digest without duplicating thousands of rows.
        audit['comparison_sha256'] = sha(json.dumps(audit.pop('comparisons'), sort_keys=True).encode())
        audits.append(audit)
    defaults = []
    for character in range(8):
        table = word(0x71bdc0 + 4 * character)
        address = word(table)
        count, digest = region_list(address)
        assert count == 4
        defaults.append(dict(character=character, table=hex(table), definition=hex(address),
                             count=count, terminated_definition_sha256=digest,
                             inline_base='0xaec', advanced_offset=hex(0xaec + 12 * count)))
    secondary = []
    for subtype in range(4):
        address = word(0x716440 + 4 * subtype)
        count, digest = region_list(address)
        assert count == 4
        secondary.append(dict(subtype=subtype, definition=hex(address), count=count,
                              terminated_definition_sha256=digest, advanced_offset=hex(0xaec + 12 * count)))
    record = dict(schema=1, status='static audit passed', game_run=False, live_process_access=False,
                  stage4_complete=False, tool_sha256=sha(Path(__file__).read_bytes()),
                  overlay_sha256=sha(raw), source_count=len(sources), source_index_sha256=index.hexdigest(),
                  source_audits=audits, primary_default_definitions=defaults,
                  first_four_secondary_definitions=secondary,
                  direct_store_matches={hex(offset): matches for offset, matches in stores.items()},
                  observed_direct_store_counts={hex(offset): len(matches) for offset, matches in stores.items()},
                  limitations=[
                      'The source search covers direct immediate-offset stores in the current generated o2 tree, not all aliases or bulk initialization.',
                      'Default lists are static initial selections; other action-selected descriptor lists and runtime reachability are not established.',
                      'Source region refresh writes actual count only; a transformed sentinel or a universal zero tail is not established.',
                      'B24 direct stores may write actor relationships; their numeric address bits are not native geometric data.',
                      'No game incident, contact frequency, performance cost or repaired gameplay behavior was observed.'])
    output.mkdir(parents=True)
    (output / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf8')
    print(json.dumps(dict(status=record['status'], source_count=len(sources), counts=record['observed_direct_store_counts'],
                          receipt_sha256=sha((output / 'receipt.json').read_bytes()))))


if __name__ == '__main__':
    main()
