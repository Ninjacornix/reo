"""Capture a running coop_playtest session's game windows (PrintWindow, works under other
windows) every N seconds, with the original front-menu state, to map the co-op menu flow.

usage: coop_flow_capture.py SESSION SECONDS [EVERY]
"""
import json, struct, sys, time
from pathlib import Path
root = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(root / 'tools/coop_playtest'))
from window_capture import capture
from lobby_driver import GuestRam

session = Path(sys.argv[1]).resolve()
seconds, every = float(sys.argv[2]), float(sys.argv[3]) if len(sys.argv) > 3 else 2.0
record = json.loads((session / 'session.json').read_text())
front_at = 0x5D4898 if record.get('game', 'file1') == 'file1' else 0x5B7D00
out = session / 'flow-window'; out.mkdir(exist_ok=True)
began = time.monotonic(); ram = None; log = []
while time.monotonic() - began < seconds:
    run = json.loads((session / 'run.json').read_text()) if (session / 'run.json').exists() else None
    if run and run.get('players'):
        identity = run['players'][0]
        t = time.monotonic() - began
        state = None
        try:
            if ram is None: ram = GuestRam(identity, record['elf'])
            front = struct.unpack('<I', ram.read(front_at, 4))[0]
            if 0x100000 <= front < 0x1fff000:
                state = '%06x' % (struct.unpack('<I', ram.read(front, 4))[0] & 0xffffff)
        except Exception:
            ram = None
        name = 'w%03d.png' % int(t)
        try: capture(identity, out / name)
        except Exception as problem: name = 'capture failed: %s' % problem
        log.append({'t': round(t, 1), 'state': state, 'shot': name})
    time.sleep(every)
(out / 'flow.json').write_text(json.dumps(log, indent=1))
print('captures', len(log))
