"""Compare complete benchmark outputs, including PE code and normalized metadata."""
import hashlib
import json
import mmap
from pathlib import Path
import struct
import sys


def compile_inputs(root):
    units = {}
    for line in (root / 'commands.jsonl').read_text().splitlines():
        event = json.loads(line)
        if event['stage'] != 'compile' or event['event'] != 'begin':
            continue
        command = event['command'][:]
        source = Path(command[-1])
        command[-1] = source.name
        output_index = command.index('-o') + 1
        command[output_index] = Path(command[output_index]).name
        preamble = None
        if '-include-pch' in command:
            pch_index = command.index('-include-pch') + 1
            preamble = Path(command[pch_index]).with_suffix('.hpp').read_bytes().hex()
            command[pch_index] = '{private-pch}'
        if source.stem in units:
            raise ValueError('A unit compiled more than once')
        units[source.stem] = {'command': command, 'preamble': preamble,
                              'unitySourceSha256': hashlib.sha256(source.read_bytes()).hexdigest()}
    return units


def link_inputs(root):
    prefix = root.as_posix() + '/'
    return [json.loads(line).replace('\\', '/').replace(prefix, '{trial}/')
            for line in (root / 'local-game-link.rsp').read_text().splitlines()]


def inspect_pe(path):
    with path.open('rb') as stream, mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as data:
        if data[:2] != b'MZ':
            raise ValueError('Expected a Windows executable')
        header = struct.unpack_from('<I', data, 0x3c)[0]
        if data[header:header+4] != b'PE\0\0':
            raise ValueError('Invalid PE signature')
        machine, count, timestamp, _, _, optional_size, characteristics = struct.unpack_from(
            '<HHIIIHH', data, header+4)
        optional = header+24
        if struct.unpack_from('<H', data, optional)[0] != 0x20b:
            raise ValueError('Expected PE32+')
        ranges = [(header+8, 4), (optional+64, 4)]
        normalized_fields = ['COFF TimeDateStamp', 'optional-header CheckSum']
        sections = []
        for index in range(count):
            offset = optional+optional_size+index*40
            name = data[offset:offset+8].rstrip(b'\0').decode('ascii')
            virtual_size, virtual_address, size, raw = struct.unpack_from('<IIII', data, offset+8)
            if raw+size > len(data):
                raise ValueError('Section exceeds image')
            sections.append({'name': name, 'virtualSize': virtual_size, 'virtualAddress': virtual_address,
                             'rawSize': size, 'rawOffset': raw,
                             'sha256': hashlib.sha256(data[raw:raw+size]).hexdigest()})
        # Only the documented TimeDateStamp of a CodeView debug-directory entry,
        # matching this image's link time, is normalized. GUID/data stay checked.
        # https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#debug-directory-image-only
        if optional_size >= 168 and struct.unpack_from('<I', data, optional+108)[0] > 6:
            debug_rva, debug_size = struct.unpack_from('<II', data, optional+160)
            if debug_size:
                if debug_size % 28:
                    raise ValueError('Invalid debug directory size')
                containing = [s for s in sections if s['virtualAddress'] <= debug_rva and
                              debug_rva+debug_size <= s['virtualAddress']+s['rawSize']]
                if len(containing) != 1:
                    raise ValueError('Debug directory is not contained in one raw section')
                s = containing[0]
                raw = s['rawOffset'] + debug_rva-s['virtualAddress']
                for entry in range(debug_size // 28):
                    offset = raw+entry*28
                    debug_characteristics, stamp, _, _, kind, _, _, _ = struct.unpack_from(
                        '<IIHHIIII', data, offset)
                    if debug_characteristics == 0 and kind == 2 and stamp == timestamp:
                        ranges.append((offset+4, 4))
                        normalized_fields.append(f'CodeView debug entry {entry} TimeDateStamp')

        def normalized_digest(begin, end):
            result = hashlib.sha256()
            start = begin
            for offset, size in sorted(ranges):
                if begin <= offset and offset+size <= end:
                    result.update(data[start:offset])
                    result.update(bytes(size))
                    start = offset+size
            result.update(data[start:end])
            return result.hexdigest()

        for section in sections:
            section['normalizedSha256'] = normalized_digest(
                section['rawOffset'], section['rawOffset']+section['rawSize'])
        return {'bytes': len(data), 'machine': machine, 'characteristics': characteristics,
                'coffTimestamp': timestamp, 'normalizedSha256': normalized_digest(0, len(data)),
                'normalizedFields': normalized_fields, 'sections': sections}


def main():
    root = Path(sys.argv[1]).resolve()
    variants = {name: inspect_pe(root / name / 'output/reo_recomp.exe') for name in ['old', 'new']}
    old, new = variants['old'], variants['new']
    result = {'images': variants, 'normalizedImagesIdentical': old['normalizedSha256'] == new['normalizedSha256'],
              'sectionsIdentical': old['sections'] == new['sections'],
              'sectionsIdenticalApartFromTimestamps':
                  [{k: v for k, v in s.items() if k != 'sha256'} for s in old['sections']] ==
                  [{k: v for k, v in s.items() if k != 'sha256'} for s in new['sections']],
              'compileCommandsAndUnityInputsIdentical': compile_inputs(root / 'old') == compile_inputs(root / 'new'),
              'linkCommandsAndOrderIdentical': link_inputs(root / 'old') == link_inputs(root / 'new')}
    (root / 'executable-parity.json').write_text(json.dumps(result, indent=2))
    print(json.dumps({key: value for key, value in result.items() if key != 'images'}, indent=2))
    if not all(value for key, value in result.items() if key not in {'images', 'sectionsIdentical'}):
        raise SystemExit('Build inputs or executable differ beyond the stated normalization; inspect the receipt')


if __name__ == '__main__':
    main()
