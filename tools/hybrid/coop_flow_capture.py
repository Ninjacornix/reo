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
        probe = None
        try:
            if ram is not None:
                second = record.get('game') == 'file2'
                addrs = ([0x58D000, 0x6E32EA, 0x6A9848, 0x6A9849, 0x6E37D0, 0x6E37D1] if second else
                         [0x570000, 0x6DF150, 0x6DF151, 0x6D91CA, 0x6995A0, 0x6D9688, 0x6D9689])
                probe = [struct.unpack('<I', ram.read(addrs[0], 4))[0]] + [ram.read(a, 1)[0] for a in addrs[1:]]
        except Exception:
            probe = None
        log.append({'t': round(t, 1), 'state': state, 'shot': name, 'serverProbe': probe})
    time.sleep(every)
(out / 'flow.json').write_text(json.dumps(log, indent=1))
print('captures', len(log))
