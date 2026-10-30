"""Create a replacement-only .pak from edited copies of extracted native assets.

Keep the extracted directory as reference. Copy files to an edited directory with
the same relative paths, edit them with format-specific tools, then run this tool.
Only files whose hashes differ from assets.json enter the pack. Nothing is decoded.
"""
import argparse
import csv
import hashlib
import json
import re
import zipfile
from pathlib import Path

ELF = {
    'file1': '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46',
    'file2': '5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d',
}


def string_changes(edited, game):
    originals, edits = {}, []
    roots = (edited, edited / 'executable-strings')
    for root in roots:
        for name in ('strings.json', 'ui-strings.json'):
            file = root / name
            if not file.is_file():
                continue
            data = json.loads(file.read_text(encoding='utf-8-sig'))
            if data.get('format') != 1 or data.get('game') != game or data.get('elfSha256') != ELF[game]:
                raise ValueError('Executable string reference belongs to another game/revision')
            for entry in data['entries']:
                identity = entry['id']
                original = {k: entry[k] for k in ('address', 'maxBytes', 'originalText', 'originalBytesHex', 'originalSha256')}
                original['paddingMaxBytes'] = entry.get('paddingMaxBytes', entry['maxBytes'])
                if identity in originals and originals[identity] != original:
                    raise ValueError('Conflicting original executable string identities')
                originals[identity] = original
                if entry.get('translation') is not None or entry.get('translationBytesHex') is not None:
                    edits.append((identity, entry.get('translation'), entry.get('translationBytesHex'), entry.get('usePadding', False)))
    for root in roots:
        for name in ('ui-strings.csv', 'candidates.csv'):
            file = root / name
            if not file.is_file():
                continue
            with file.open(encoding='utf-8-sig', newline='') as stream:
                for row in csv.DictReader(stream):
                    if not row.get('translation'):
                        continue
                    source = originals.get(row['id'])
                    if source is None or row['originalText'] != source['originalText'] or row['address'] != source['address'] or int(row['maxBytes']) != source['maxBytes']:
                        raise ValueError('Keep the original JSON reference alongside edited CSV files')
                    padding = row.get('usePadding', 'false').strip().lower() or 'false'
                    if padding not in ('true', 'false'):
                        raise ValueError('usePadding must be true or false')
                    edits.append((row['id'], row['translation'], None, padding == 'true'))
    result = {}
    for identity, text, encoded, padding in edits:
        source = originals[identity]
        raw = bytes.fromhex(source['originalBytesHex'])
        if len(raw) != source['maxBytes'] or hashlib.sha256(raw).hexdigest() != source['originalSha256']:
            raise ValueError('Original executable string byte identity differs')
        if (text is None) == (encoded is None):
            raise ValueError('Use translation or translationBytesHex, not both')
        try:
            replacement = text.encode('cp932') if text is not None else bytes.fromhex(encoded)
            decoded = replacement.decode('cp932')
        except (UnicodeError, ValueError) as error:
            raise ValueError('Invalid CP932 translation; custom fonts need verified encoded byte mappings') from error
        if not isinstance(padding, bool):
            raise ValueError('usePadding must be true or false')
        budget = source['paddingMaxBytes'] if padding else len(raw)
        if not isinstance(budget, int) or not len(raw) <= budget <= 65535:
            raise ValueError('Invalid verified padding budget')
        if len(replacement) > budget or b'\0' in replacement:
            raise ValueError('Executable translation exceeds byte budget or contains NUL')
        for pattern in (r'<[^>\r\n]+>', r'%(?:\d+\$)?[-+ #0]*(?:\d+|\*)?(?:\.(?:\d+|\*))?(?:hh|ll|[hlLjzt])?[diuoxXfFeEgGaAcspn%]'):
            if re.findall(pattern, source['originalText']) != re.findall(pattern, decoded):
                raise ValueError('Preserve executable string formatting tags and printf arguments')
        if raw == replacement:
            continue
        address = source['address']
        entry = dict(address=address, maxBytes=budget, baseSha256=source['originalSha256'])
        if padding:
            entry['usePadding'] = True
        entry['text' if text is not None else 'bytesHex'] = text if text is not None else replacement.hex()
        if address in result and result[address] != entry:
            raise ValueError('Conflicting translations for the same executable address')
        result[address] = entry
    return list(result.values())


def create(index_path, edited, output, game, identity, name, version):
    edited, output = Path(edited).resolve(), Path(output).resolve()
    if not re.fullmatch(r'[a-z0-9][a-z0-9.-]{0,79}', identity):
        raise ValueError('Invalid package ID')
    if not name.strip() or len(name) > 120 or not version.strip() or len(version) > 40:
        raise ValueError('Supply a name (up to 120 characters) and version (up to 40)')
    index = json.loads(Path(index_path).read_text(encoding='utf-8'))
    if index.get('format') != 1 or not index.get('verified'):
        raise ValueError('Use assets.json from the verified extraction tool')
    changes, files, seen, total = [], [], set(), 0
    for entry in index['entries']:
        address = entry['path']
        if not re.fullmatch(r'NETBIO0[012]\.DAT(?:/[0-9]+){1,4}', address):
            raise ValueError('Invalid archive address in extraction manifest')
        relative = Path(entry['file'])
        if relative.is_absolute() or '..' in relative.parts or ':' in str(relative):
            raise ValueError('Unsafe extraction path')
        source = (edited / relative).resolve()
        if edited not in source.parents:
            raise ValueError('Edited asset escapes its directory')
        if not source.exists():
            continue
        if not source.is_file() or source.stat().st_size > 256 * 1024 * 1024:
            raise ValueError('Replacement must be a regular file up to 256 MiB')
        with source.open('rb') as stream:
            digest = hashlib.file_digest(stream, 'sha256').hexdigest()
        if digest == entry['sha256']:
            continue
        if relative.name.lower().endswith('_h.bin'):
            raise ValueError('Room name-table replacements are unsupported')
        if address in seen:
            raise ValueError('Duplicate archive address')
        seen.add(address)
        total += source.stat().st_size
        if total > 2 * 1024 * 1024 * 1024 or len(changes) >= 4096:
            raise ValueError('Pack exceeds 2 GiB or 4096 replacement limit')
        if not re.fullmatch(r'[0-9a-fA-F]{64}', entry['sha256']):
            raise ValueError('Invalid original SHA-256')
        member = f'files/{len(changes):05d}{source.suffix or ".bin"}'
        changes.append(dict(path=address, file=member, baseSha256=entry['sha256']))
        files.append((source, member))
    strings = string_changes(edited, game)
    if not changes and not strings:
        raise ValueError('No changed assets or translated executable strings found')
    if len(changes) + len(strings) > 4096:
        raise ValueError('Pack exceeds 4096 combined replacements')
    manifest = dict(format=1, id=identity, name=name, version=version,
                    game=game, elfSha256=ELF[game], replace=changes)
    if strings:
        manifest['strings'] = strings
    with zipfile.ZipFile(output, 'x', compression=zipfile.ZIP_DEFLATED, compresslevel=6) as archive:
        archive.writestr('pak.json', json.dumps(manifest, indent=2, ensure_ascii=False) + '\n')
        for source, member in files:
            archive.write(source, member)
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('index', type=Path)
    parser.add_argument('edited', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--game', required=True, choices=ELF)
    parser.add_argument('--id', required=True)
    parser.add_argument('--name', required=True)
    parser.add_argument('--version', default='1.0.0')
    args = parser.parse_args()
    manifest = create(args.index, args.edited, args.output, args.game, args.id, args.name, args.version)
    print(f'{args.output}: {len(manifest["replace"])} changed assets, {len(manifest.get("strings", []))} strings, {args.output.stat().st_size} bytes')


if __name__ == '__main__':
    main()
