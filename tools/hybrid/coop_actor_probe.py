"""Read actor 0 position/yaw (File #2 +0x38/+0x92) from both harness clients; optional input step first."""
import json, os, struct, sys, time
sys.path.insert(0, os.path.join(os.getcwd(), 'tools', 'coop_playtest'))
from lobby_driver import GuestRam  # read-only process reader

session = os.path.abspath(sys.argv[1])
record = json.load(open(os.path.join(session, 'session.json')))
run = json.load(open(os.path.join(session, 'run.json')))
BASE, STRIDE = 0x4C5E10, 0x1100


def read_all():
    out = {}
    for ident in run['players']:
        r = GuestRam(ident, record['elf'])
        try:
            r.check()
            a = BASE
            xyz = struct.unpack('<fff', r.read(a + 0x38, 12))
            yaw = struct.unpack('<h', r.read(a + 0x92, 2))[0]
            elev = struct.unpack('<h', r.read(a + 0xBE0, 2))[0]
            out[ident['number']] = (tuple(round(v, 2) for v in xyz), yaw, elev)
        finally:
            r.close()
    return out


def press(seconds, **cmd):
    cmd['expiresUnix'] = time.time() + seconds
    cmd.setdefault('buttons', [])
    p = os.path.join(session, 'player1', 'input.json')
    open(p + '.tmp', 'w').write(json.dumps(cmd)); os.replace(p + '.tmp', p)


def show(label):
    s = read_all()
    same = s[1] == s[2]
    print(f'{label:28s} p1 sees {s[1]}  p2 sees {s[2]}  {"MATCH" if same else "DIFF"}', flush=True)
    return s


show('idle')
for label, cmd in (('aim + camera turn right', dict(buttons=['r1'], rx=22000)),
                   ('aim + camera turn left', dict(buttons=['r1'], rx=-22000)),
                   ('aim + strafe left', dict(buttons=['r1'], lx=-24000)),
                   ('aim, stick up (elevation)', dict(buttons=['r1'], ry=20000))):
    press(2.0, **cmd)
    time.sleep(1.0)
    show(label + ' (held)')
    time.sleep(1.4)
    show(label + ' (settled)')
