"""Sample the File #1 network step bytes and card dialog fields of a running
coop_playtest session (player 1) ten times a second; prints each change.

usage: network_step_sampler.py SESSION SECONDS [STEP_BLOCK_HEX]  (File #1 6DF150, File #2 6E9490)
Fields (network step block 0x6DF150, see recomp/overrides/reo_hw_bridge.cpp menu.card*):
step +0, substep +1, card state +2, +3, timers (16-bit) +4, +6, +0xA; printed when a state byte changes.
"""
import json, struct, sys, time
from pathlib import Path
root = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(root / 'tools/coop_playtest'))
from lobby_driver import GuestRam

session = Path(sys.argv[1]).resolve()
seconds = float(sys.argv[2])
block = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0x6DF150
record = json.loads((session / 'session.json').read_text())
began = time.monotonic(); ram = None; last = None
while time.monotonic() - began < seconds:
    run = json.loads((session / 'run.json').read_text()) if (session / 'run.json').exists() else None
    if run and run.get('players'):
        try:
            if ram is None: ram = GuestRam(run['players'][0], record['elf'])
            b = ram.read(block, 0x188)
            row = (b[0], b[1], b[2], b[3], struct.unpack_from('<h', b, 4)[0], struct.unpack_from('<h', b, 6)[0],
                   struct.unpack_from('<h', b, 0xA)[0])
            key = row[:4]
            if key != last:
                print('%.2f step=%d sub=%d state=%d sub2=%d timer4=%d timer6=%d timerA=%d' % ((time.monotonic() - began,) + row), flush=True)
                last = key
        except Exception:
            ram = None
    time.sleep(0.1)
