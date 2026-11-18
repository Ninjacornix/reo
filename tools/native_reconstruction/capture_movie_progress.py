#!/usr/bin/env python3
"""Observe public movie frame progress in an owned test, without suspending it."""
import argparse
from contextlib import closing
import hashlib
import json
from pathlib import Path
import struct
import sys
import time

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/coop_playtest'))
import coop_playtest as owned
from lobby_driver import GuestRam


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', type=Path, required=True)
    parser.add_argument('--seconds', type=int, default=600)
    parser.add_argument('--hz', type=int, default=100)
    parser.add_argument('--name', default='movie-progress')
    args = parser.parse_args()
    folder, manifest = owned.session_record(args.session)
    if not folder.is_relative_to(ROOT / 'build-native-sjuni/playtests') or len(manifest['players']) != 1 or manifest['game'] != 'file1':
        raise ValueError('One private owned File1 game required')
    if not 1 <= args.seconds <= 900 or not 1 <= args.hz <= 240 or not args.name or any(c not in 'abcdefghijklmnopqrstuvwxyz0123456789-' for c in args.name):
        raise ValueError('Bounded duration/rate and simple report name required')
    run = json.loads((folder / 'run.json').read_text())
    if run.get('finishedUtc') or len(run['players']) != 1:
        raise ValueError('One running owned game required')
    identity = {k: run['players'][0][k] for k in ('pid', 'image', 'creationFileTime')}
    image = Path(manifest['players'][0]['image'])
    if image.resolve() != Path(identity['image']).resolve() or sha(image) != manifest['sourceSha256'] or owned.process_identity(identity['pid']) != identity:
        raise ValueError('Owned image/process identity mismatch')
    output, receipt = (folder / (args.name + suffix) for suffix in ('.csv', '-receipt.json'))
    if output.exists() or receipt.exists():
        raise ValueError('Fresh evidence names required')
    result = dict(schema=1, status='failed', identity=identity, executable_sha256=manifest['sourceSha256'],
                  source_sha256=sha(Path(__file__)), records=0, hz=args.hz, guest_writes=False,
                  threads_suspended=False, errors=[],
                  limitations=['Asynchronous CPU handoff observations, not display scanout or decoder invocations.',
                               'A long progress gap alone does not establish a bottleneck or root cause.',
                               'Read durations and observer scheduling gaps must be considered.'])
    started = time.perf_counter_ns()
    try:
        with closing(GuestRam(identity, manifest['elf'])) as reader, output.open('x', newline='') as stream:
            stream.write('qpc_ns,read_ns,handle,status,frame,width,height,game_flag_4badf8\n')
            last_flush = started
            while time.perf_counter_ns() - started < args.seconds * 1_000_000_000:
                begin = time.perf_counter_ns()
                public = reader.read(0x340a40, 0x98)
                frame = struct.unpack('<I', reader.read(0x56bad8, 4))[0]
                game_flag = reader.read(0x4badf8, 1)[0]
                end = time.perf_counter_ns()
                stream.write(f'{begin},{end-begin},{struct.unpack_from("<I", public)[0]},{public[0x80]},{frame},{struct.unpack_from("<H", public, 0x8c)[0]},{struct.unpack_from("<H", public, 0x8e)[0]},{game_flag}\n')
                result['records'] += 1
                if end - last_flush >= 1_000_000_000:
                    reader.check()
                    stream.flush()
                    last_flush = end
                time.sleep(max(0, 1 / args.hz - (time.perf_counter_ns() - begin) / 1e9))
        result['status'] = 'completed'
    except Exception as error:
        result['errors'].append(str(error))
        raise
    finally:
        result['elapsed_seconds'] = (time.perf_counter_ns() - started) / 1e9
        if output.exists():
            result['output_sha256'] = sha(output)
        receipt.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
