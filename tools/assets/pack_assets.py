"""Create a replacement-only .pak from edited copies of extracted native assets.

Keep the extracted directory as reference. Copy files to an edited directory with
the same relative paths, edit them with format-specific tools, then run this tool.
Only files whose hashes differ from assets.json enter the pack. Nothing is decoded.
"""
import argparse
import hashlib
import json
import re
import zipfile
from pathlib import Path

ELF = {
    'file1': '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46',
    'file2': '5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d',
}


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
    if not changes:
        raise ValueError('No changed assets found; copy edited files using their extracted relative paths')
    manifest = dict(format=1, id=identity, name=name, version=version,
                    game=game, elfSha256=ELF[game], replace=changes)
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
    print(f'{args.output}: {len(manifest["replace"])} changed assets, {args.output.stat().st_size} bytes')


if __name__ == '__main__':
    main()
