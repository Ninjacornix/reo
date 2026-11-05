"""Confirm private File1 character/difficulty menus, then observe without skips.

Uses an owned read-only GuestRam handle and expiring ordinary controller inputs.
It never sends Start, writes guest memory or changes a process execution state.
"""
import argparse
import json
from pathlib import Path
import struct
import time

import coop_playtest as harness
from lobby_driver import GuestRam


def confirmable(phase, selection_state, timer):
    # Phase 0E is the original cinematic; 02 is interactive gameplay. Stale
    # selection pointers must never admit input in either phase.
    return phase not in (2, 14) and (
        selection_state == 0x109 and timer == 0 or
        selection_state in (0x30A, 0x50B))


def drive(folder, *, timeout=300, observe_only=False):
    folder, record = harness.session_record(folder)
    if record['game'] != 'file1' or len(record['players']) != 1 or not 10 <= timeout <= 600:
        raise ValueError('Requires a one-player File1 session and timeout 10..600')
    run = json.loads((folder / 'run.json').read_text(encoding='utf-8'))
    if len(run.get('players', [])) != 1 or run['players'][0].get('environment', {}).get('REO_TEST_ROUTE') != 'character':
        raise ValueError('Requires --route character; gameplay route skips cinematics')
    player, identity = record['players'][0], run['players'][0]
    expected = {key: identity[key] for key in ('pid','image','creationFileTime')}
    if Path(player['image']).resolve() != Path(identity['image']).resolve() or harness.process_identity(identity['pid']) != expected:
        raise ValueError('Private process identity mismatch')
    receipt = folder / ('cinematic-followup.json' if observe_only else 'cinematic-observation.json')
    with receipt.open('x', encoding='utf-8') as stream:
        json.dump({'status':'initializing'}, stream)
    result = dict(events=[], inputs=[], skip_inputs=0, cinematic_observed=False,
                  gameplay_observed=False, startedUtc=harness.utc(),
                  observe_only=observe_only,
                  process_identity=expected, source_executable_sha256=record['sourceSha256'],
                  limitation='Phase 14 alone does not distinguish video from an in-engine cutscene. State/input observations supply no image, waveform or timing equivalence verdict.')
    started = time.monotonic()
    last, sealed, since_gameplay = None, observe_only, None
    presses, next_press, route_reached = {}, 0, False
    reader = None
    try:
        reader = GuestRam(identity, record['elf'])
        word = lambda address: struct.unpack('<I', reader.read(address, 4))[0]
        while time.monotonic()-started < timeout:
            reader.check()
            now = time.monotonic()
            phase_data = reader.read(0x4BADD0, 0x40)
            phase, modal, paused = phase_data[0], phase_data[0x1E], phase_data[0x28]
            selection = word(0x32442C)
            state = timer = None
            if 0x100000 <= selection <= 0x2000000-0x24:
                block = reader.read(selection, 0x24)
                state, timer = struct.unpack_from('<I', block, 4)[0], struct.unpack_from('<I', block, 0x20)[0]
            snapshot = (phase, modal, paused, selection, state, timer)
            if snapshot != last:
                result['events'].append(dict(seconds=round(now-started,3), phase=phase,
                    modal=modal, paused=paused, selection=selection, state=state, timer=timer))
                last = snapshot
            if phase == 14:
                result['cinematic_observed'] = True
                sealed = True
            if phase == 2:
                sealed = True
                if not modal and not paused:
                    since_gameplay = since_gameplay or now
                    if now-since_gameplay >= 2:
                        result['gameplay_observed'] = True
                        break
                else:
                    since_gameplay = None
            else:
                since_gameplay = None
            # The native route must relinquish input first. Each menu receives
            # at most four bounded retries; later phases permanently seal input.
            # The verified --route character implementation relinquishes input
            # on this exact idle state. Latch the observed state; rereading an
            # ever-growing movie log here can delay the controller publisher.
            if not sealed and not route_reached and state == 0x109 and timer == 0:
                route_reached = True
                result['character_idle_observed_seconds'] = round(now-started,3)
            if not sealed and route_reached and now >= next_press and confirmable(phase, state, timer):
                key = (selection, state)
                count = presses.get(key, 0)
                if count >= 4:
                    raise ValueError('Menu confirmation retry bound reached')
                reader.check()
                harness.save(player['inputFile'], dict(buttons=['cross'], expiresUnix=time.time()+0.6))
                presses[key] = count+1
                result['inputs'].append(dict(seconds=round(now-started,3), button='cross',
                    selection=selection, state=state, retry=count+1))
                next_press = now+1.25
            harness.save(receipt, result)
            time.sleep(0.1)
    except (OSError, ValueError) as error:
        result['error'] = dict(type=type(error).__name__, message=str(error))
    finally:
        if reader is not None:
            reader.close()
        result['finishedUtc'] = harness.utc()
        result['elapsedSeconds'] = round(time.monotonic()-started,3)
        result['status'] = 'observed-gameplay' if result['gameplay_observed'] else 'incomplete'
        harness.save(receipt, result)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True)
    parser.add_argument('--timeout', type=float, default=300)
    parser.add_argument('--observe-only', action='store_true', help='Separate follow-up receipt; send no input')
    args = parser.parse_args()
    result = drive(args.session, timeout=args.timeout, observe_only=args.observe_only)
    print(json.dumps(result, indent=2))
    if not result['gameplay_observed']:
        raise SystemExit(2)


if __name__ == '__main__':
    main()
