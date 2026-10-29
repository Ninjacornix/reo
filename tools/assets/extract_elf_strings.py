"""Export private, addressable string references from an owned Outbreak ELF.

This does not patch the executable or create an installable translation mod.
The supported File #1 profile examines the UI/data tail, including the region
reported in issue #25. Stripped ELF sections do not identify individual UI text.
"""
import argparse
import csv
import hashlib
import io
import json
import re
import struct
import zipfile
from pathlib import Path


FILE1_SHA256 = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
FILE1_START, FILE1_END = 0x150060, 0x159F80
UI_END = 0x152E80


def sha(data):
    return hashlib.sha256(data).hexdigest()


def load_segments(data):
    if len(data) < 52 or data[:7] != b'\x7fELF\x01\x01\x01':
        raise ValueError('Expected a little-endian ELF32 executable')
    header = struct.unpack_from('<16sHHIIIIIHHHHHH', data)
    if header[1] != 2 or header[2] != 8 or header[8] != 52 or header[9] != 32:
        raise ValueError('Expected an executable MIPS ELF32 header')
    offset, count = header[5], header[10]
    if not 0 < count <= 256 or offset < 52 or offset + count * 32 > len(data):
        raise ValueError('Invalid ELF program table')
    segments = []
    for index in range(count):
        kind, file_offset, address, _, size, memory_size, flags, _ = struct.unpack_from('<8I', data, offset + index * 32)
        if kind != 1 or size == 0:
            continue
        if size > memory_size or file_offset > len(data) or size > len(data) - file_offset or address + memory_size > 0x100000000:
            raise ValueError('Invalid file-backed ELF segment')
        if any(file_offset < old['fileOffset'] + old['bytes'] and old['fileOffset'] < file_offset + size for old in segments):
            raise ValueError('Ambiguous overlapping ELF file ranges')
        segments.append(dict(fileOffset=file_offset, address=address, bytes=size, flags=flags))
    if not segments:
        raise ValueError('ELF has no file-backed load segments')
    return segments


def candidates(data, start, end, ui_end):
    segments = load_segments(data)
    if not 0 < start < end <= len(data) or data[start - 1] != 0:
        raise ValueError('String range must be bounded and start after a NUL')
    containing = [s for s in segments if s['fileOffset'] <= start and end <= s['fileOffset'] + s['bytes']]
    if len(containing) != 1:
        raise ValueError('String range must lie in one file-backed load segment')
    segment = containing[0]
    entries, originals = [], bytearray()
    position = start
    while position < end:
        stop = data.find(b'\0', position, end)
        if stop < 0:
            break  # Never claim a truncated final run has a usable terminator.
        raw = data[position:stop]
        try:
            text = raw.decode('cp932', errors='strict')
        except UnicodeDecodeError:
            text = ''
        # Conservative readable candidates, not a claim that all are displayed.
        # Keeping the entire NUL-delimited run preserves leading spaces/tags.
        if len(text) >= 2 and all(c.isprintable() or c in '\r\n\t' for c in text) and re.search(r'[A-Za-z]{2}|[^\x00-\x7f]{2}', text):
            address = segment['address'] + position - segment['fileOffset']
            entries.append(dict(
                id=f'elf-{address:08X}', fileOffset=position, address=f'0x{address:08X}',
                group='ui-region-candidate' if position < ui_end else 'other-candidate',
                originalText=text, translation=None, encoding='cp932', maxBytes=len(raw),
                terminatorBytes=1, originalBytesHex=raw.hex(), originalSha256=sha(raw),
                originalsOffset=len(originals), sourceTextRoundTrips=text.encode('cp932') == raw,
                controlTokens=re.findall(r'<[^>\r\n]+>', text),
                formatTokens=re.findall(r'%(?:\d+\$)?[-+ #0]*(?:\d+|\*)?(?:\.(?:\d+|\*))?(?:hh|ll|[hlLjzt])?[diuoxXfFeEgGaAcspn%]', text),
                needsManualReview=True))
            originals.extend(raw + b'\0')
        position = stop + 1
    by_address = {int(entry['address'], 16): entry for entry in entries}
    for entry in entries:
        entry['literalAddressWordFileOffsets'] = []
    for source in segments:
        aligned = (source['fileOffset'] + 3) & ~3
        limit = (source['fileOffset'] + source['bytes']) & ~3
        for index, (value,) in enumerate(struct.iter_unpack('<I', data[aligned:limit])):
            if value in by_address:
                by_address[value]['literalAddressWordFileOffsets'].append(f'0x{aligned + index * 4:08X}')
    return segment, entries, bytes(originals)


def json_bytes(value):
    return (json.dumps(value, ensure_ascii=False, indent=2) + '\n').encode('utf-8')


def csv_bytes(entries):
    stream = io.StringIO(newline='')
    writer = csv.writer(stream)
    writer.writerow(['id', 'address', 'fileOffset', 'maxBytes', 'encoding', 'literalAddressWordFileOffsets', 'originalText', 'translation'])
    for entry in entries:
        writer.writerow([entry['id'], entry['address'], f"0x{entry['fileOffset']:08X}", entry['maxBytes'], entry['encoding'], ';'.join(entry['literalAddressWordFileOffsets']), entry['originalText'], ''])
    return stream.getvalue().encode('utf-8-sig')


def export(elf, output, *, expected_sha=FILE1_SHA256, start=FILE1_START, end=FILE1_END, ui_end=UI_END):
    elf, output = Path(elf).resolve(), Path(output).resolve()
    data = elf.read_bytes()
    if sha(data) != expected_sha:
        raise ValueError('Executable SHA-256 does not match the supported File #1 revision')
    segment, entries, originals = candidates(data, start, end, ui_end)
    if not entries:
        raise ValueError('No printable string candidates in the selected range')
    if output.exists():
        raise ValueError('Choose a new output directory; existing files are never overwritten')
    if elf.parent in output.parents:
        raise ValueError('Keep string references outside the imported game-data directory')
    # Check all source ranges independently before publishing reference data.
    for entry in entries:
        offset, size = entry['fileOffset'], entry['maxBytes']
        raw = bytes.fromhex(entry['originalBytesHex'])
        if data[offset:offset + size + 1] != raw + b'\0' or originals[entry['originalsOffset']:entry['originalsOffset'] + size + 1] != raw + b'\0':
            raise ValueError('Extracted reference does not match its source bytes')
    ui = [e for e in entries if e['group'] == 'ui-region-candidate']
    readme = '''Executable string reference for Outbreak File #1 NTSC-U v2.00.

This is a private editing reference, not an installable mod or a playable game PAK.
No executable-string runtime override has been implemented by this extraction.

Start with ui-strings.csv or ui-strings.json. The broader strings.json and
candidates.csv also contain SDK messages, resource paths and possible false
positives. All entries need manual review; no call-site or rendering validation
is implied. UI-region membership is a location heuristic, not proof of use.
literalAddressWordFileOffsets lists aligned words equal to the string address;
these are static pointer candidates, not verified runtime references.

Addresses come from ELF PT_LOAD mapping, not from a hard-coded offset guess.
maxBytes counts original encoded bytes, excluding the one-byte NUL terminator.
It does not borrow adjacent padding. Preserve leading spaces, <...> controls,
printf arguments and line breaks. Enter a translation separately; keep the raw
original bytes and identity fields unchanged. CP932 represents the original
Shift-JIS-family bytes; Unicode character count is not an encoded byte budget.
Encoding a translation successfully does not prove the game font has its glyphs.

originals.bin holds only the extracted NUL-terminated candidates, indexed by
originalsOffset. No executable is bundled. Original text bytes stay private.
'''
    payloads = {
        'strings.json': json_bytes(dict(format=1, game='file1', elfSha256=sha(data), entries=entries)),
        'ui-strings.json': json_bytes(dict(format=1, game='file1', elfSha256=sha(data), entries=ui)),
        'ui-strings.csv': csv_bytes(ui), 'candidates.csv': csv_bytes(entries),
        'originals.bin': originals, 'README.txt': readme.encode('utf-8')}
    header = dict(format=1, kind='executable-string-reference', game='file1', elf='SLUS_207.65',
                  elfSha256=sha(data), runtimePatchSupported=False, candidateCount=len(entries),
                  uiRegionCandidateCount=len(ui), encoding='cp932',
                  uiRegionCandidatesWithAddressWords=sum(bool(e['literalAddressWordFileOffsets']) for e in ui),
                  range=dict(fileStart=start, fileEndExclusive=end, uiFileEndExclusive=ui_end,
                             addressStart=f"0x{segment['address'] + start - segment['fileOffset']:08X}"),
                  limitations=['Static byte extraction only; not a complete semantic UI catalogue.',
                               'No pointer/call-site, glyph coverage or in-game translation verification.'],
                  files={name: dict(bytes=len(raw), sha256=sha(raw)) for name, raw in payloads.items()})
    payloads['string-reference.json'] = json_bytes(header)
    output.mkdir(parents=True)
    pak = output / 'executable-strings-file1.pak'
    with zipfile.ZipFile(pak, 'x', compression=zipfile.ZIP_DEFLATED) as archive:
        for name, raw in payloads.items():
            archive.writestr(name, raw)
    with zipfile.ZipFile(pak) as archive:
        if archive.testzip() is not None or set(archive.namelist()) != set(payloads):
            raise ValueError('Exported ZIP failed verification')
        for name, raw in payloads.items():
            if archive.read(name) != raw:
                raise ValueError('Exported payload differs: ' + name)
    for name, raw in payloads.items():
        (output / name).write_bytes(raw)
    report = dict(passed=True, game='file1', sourceSha256=sha(data), pak=str(pak),
                  pakBytes=pak.stat().st_size, pakSha256=sha(pak.read_bytes()),
                  candidates=len(entries), uiRegionCandidates=len(ui),
                  uiRegionCandidatesWithAddressWords=header['uiRegionCandidatesWithAddressWords'], allSourceBytesVerified=True,
                  allZipPayloadsVerified=True, runtimePatchSupported=False)
    (output / 'verification.json').write_bytes(json_bytes(report))
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('elf', type=Path, help='Owned, unmodified SLUS_207.65')
    parser.add_argument('output', type=Path, help='New private output directory')
    args = parser.parse_args()
    print(json.dumps(export(args.elf, args.output), indent=2))


if __name__ == '__main__':
    main()
