#!/usr/bin/env python3
"""Emit transitional caller-range to native-key metadata; no source payloads."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def main():
    imported = Path(__file__).with_name('file1_movies.inc')
    proof = json.loads(imported.with_suffix('.json').read_text())
    if hashlib.sha256(imported.read_bytes()).hexdigest() != proof['catalogue_sha256']:
        raise ValueError('Qualified import metadata identity drift')
    rows = [json.loads('[' + line[1:-2] + ']') for line in imported.read_text().splitlines() if line.startswith('{')]
    if len(rows) != 201:
        raise ValueError('Complete File1 metadata required')
    output = ['constexpr Cue file1_cues[]{']
    for container, label, offset, size, key, frames, archive, member in rows:
        if offset % 2048 or size % 2048:
            raise ValueError('Game cue must use an exact imported sector range')
        output.append('    {' + ','.join([json.dumps(container.lower()), str(offset // 2048), str(size // 2048), json.dumps(key), str(frames)]) + '},')
    output.append('};')
    target = ROOT / 'recomp/overrides/native_host_movie/runtime_adapter.cpp'
    text = target.read_text()
    begin, end = '// BEGIN GENERATED NATIVE MOVIE CUES', '// END GENERATED NATIVE MOVIE CUES'
    if text.count(begin) != 1 or text.count(end) != 1:
        raise ValueError('Unique generated cue boundary required')
    prefix, rest = text.split(begin)
    _, suffix = rest.split(end)
    target.write_text(prefix + begin + '\n' + '\n'.join(output) + '\n' + end + suffix, newline='\n')
    print('Generated 201 imported range/native resource-key mappings; no payloads.')


if __name__ == '__main__':
    main()
