#!/usr/bin/env python3
"""Bounded read-only media observations from one already-owned private playtest.

Samples are asynchronous observations, not atomic snapshots or tick/call counts.
No process writes, suspension, input, decoder or clock replacement is performed.
"""
import argparse
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

RAM_BYTES = 0x2000000
FIELDS = dict(pending=0x44, actual=0x48, requested=0x4c, pause=0x50,
              depth=0x54, rate=0x920, buffering=0x964, episodes=0x968,
              property_e=0x9d8, selector=0x9dc, property_47=0xabc,
              cached_n=0xf08, cached_d=0xf0c, active_counter=0xf24,
              increment=0xf28, elapsed_counter=0xf48, elapsed_origin=0xf4c,
              external_callback=0xf50, previous_external=0xf54,
              external_accumulator=0xf58, external_denominator=0xf5c)


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def address(pointer, size):
    # Accept only ordinary EE addresses and its documented cached aliases.
    if pointer >> 29 not in (0, 4, 5):
        raise ValueError('Unsupported EE pointer segment')
    result = pointer & 0x1fffffff
    if not result or result & 3 or result + size > RAM_BYTES:
        raise ValueError('Unaligned or out-of-range media object')
    return result


def sample(reader):
    reader.check()
    globals_ = reader.read(0x22f138, 0x74)
    pointers = struct.unpack_from('<8I', globals_, 0x54)
    value = dict(global_tick=struct.unpack_from('<I', globals_, 0)[0],
                 frequency=struct.unpack_from('<I', globals_, 8)[0], contexts=[])
    # These values describe the original helper's actual configured provider;
    # they do not replace it with a host clock or infer a sample from MMIO.
    value['helper_selector'] = struct.unpack('<I', reader.read(0x276158, 4))[0]
    value['helper_frequency'] = struct.unpack('<Q', reader.read(0x22f980, 8))[0]
    for slot, pointer in enumerate(pointers):
        if not pointer:
            continue
        item = dict(slot=slot, pointer=pointer)
        value['contexts'].append(item)
        try:
            main = address(pointer, 0x1b78)
            data = reader.read(main, 0x1b78)
            item['fields'] = {key: struct.unpack_from('<I', data, offset)[0]
                              for key, offset in FIELDS.items()}
            item['callbacks'] = list(struct.unpack_from('<6I', data, 0xcc0))
            child = struct.unpack_from('<I', data, 0x1b74)[0]
            item['audio_child'] = child
            if child:
                audio = reader.read(address(child, 0x3c), 0x3c)
                item['audio'] = dict(handle=struct.unpack_from('<I', audio)[0],
                                    cached=list(struct.unpack_from('<2I', audio, 0x24)),
                                    pause=struct.unpack_from('<I', audio, 0x2c)[0])
        except (OSError, ValueError) as error:
            # Destruction can race this asynchronous observer. Preserve the
            # failed observation rather than attributing it to the game.
            item['unavailable'] = str(error)
    reader.check()
    return value


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True, type=Path)
    parser.add_argument('--seconds', type=float, default=600)
    parser.add_argument('--hz', type=float, default=2)
    parser.add_argument('--name', default='media-observations')
    args = parser.parse_args()
    folder = args.session.resolve()
    if (not folder.is_relative_to(ROOT / 'build-native-sjuni') or
            not 0 < args.seconds <= 900 or not 0.2 <= args.hz <= 4 or
            not args.name.isascii() or not args.name.replace('-', '').isalnum()):
        parser.error('Use an owned private session, bounded duration/rate and ASCII name')
    _, manifest = owned.session_record(folder)
    run = json.loads((folder / 'run.json').read_bytes())
    if (manifest.get('game', 'file1') != 'file1' or len(run['players']) != 1 or
            len(manifest['players']) != 1 or run.get('finishedUtc')):
        raise ValueError('One running owned File #1 process is required')
    player = run['players'][0]
    identity = {key: player[key] for key in ('pid', 'image', 'creationFileTime')}
    image = Path(identity['image']).resolve()
    if (not image.is_relative_to(folder) or
            image != Path(manifest['players'][0]['image']).resolve() or
            owned.process_identity(identity['pid']) != identity or
            sha(image) != manifest['sourceSha256']):
        raise ValueError('Owned process/image identity mismatch')
    output = folder / (args.name + '.jsonl')
    receipt = folder / (args.name + '-receipt.json')
    if output.exists() or receipt.exists():
        raise ValueError('Observation outputs must be fresh')
    result = dict(status='sampling', identity=identity, source_sha256=manifest['sourceSha256'],
                  script_sha256=sha(__file__), started_utc=owned.utc(), hz=args.hz,
                  duration_limit=args.seconds, read_only=True, atomic_snapshot=False,
                  interpretation='Samples do not establish call counts, tick frequency or root cause',
                  samples=0)
    owned.save(receipt, result)
    reader = None
    start = time.monotonic()
    try:
        reader = GuestRam(player, manifest['elf'])
        with output.open('x', encoding='utf-8') as stream:
            while time.monotonic() - start < args.seconds:
                row = dict(seconds=time.monotonic() - start, utc=owned.utc())
                try:
                    row.update(sample(reader))
                except (OSError, ValueError) as error:
                    row['unavailable'] = str(error)
                    result['status'] = 'partial'
                    result['reason'] = str(error)
                stream.write(json.dumps(row, separators=(',', ':')) + '\n')
                stream.flush()
                result['samples'] += 1
                if 'unavailable' in row:
                    break
                time.sleep(min(1 / args.hz, max(0, args.seconds - (time.monotonic() - start))))
        if result['status'] == 'sampling':
            result['status'] = 'completed-duration'
    except BaseException as error:
        result.update(status='failed', reason=str(error))
        raise
    finally:
        if reader:
            reader.close()
        result.update(finished_utc=owned.utc(), elapsed_seconds=time.monotonic() - start)
        if output.exists():
            result.update(output_sha256=sha(output), output_bytes=output.stat().st_size)
        owned.save(receipt, result)
    print(json.dumps(result))


if __name__ == '__main__':
    main()
