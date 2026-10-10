"""Ground truth for D34: launch PCSX2 on the owned ISO and log changes of the Sofdec / CRI
server fields around the title-movie start. Usage: python -I pcsx2_sfd_probe.py <iso> <seconds> <out>"""
import os, subprocess, sys, time

sys.path.insert(0, r"C:\Users\Ninjacornix\reo\tools\ps2_debug")
from pine_client import PineClient  # noqa: E402

iso, secs, out = sys.argv[1], float(sys.argv[2]), sys.argv[3]
exe = r"C:\Users\Ninjacornix\ps2\pcsx2-qt.exe"
proc = subprocess.Popen([exe, "-fastboot", "--", iso])
log = open(out, "w")


def w(s):
    log.write(s + "\n")
    log.flush()


c = None
t0 = time.time()
while time.time() - t0 < 60:
    try:
        c = PineClient()
        if c.connect(timeout=2.0, retries=1):
            break
    except Exception:
        pass
    time.sleep(1)
if not c:
    w("no pine")
    sys.exit(1)
try:
    w("game_id=%s" % c.game_id())
except Exception as e:
    w("game_id err %s" % e)

FIELDS = {
    "dectab0": 0x22F18C, "gate": 0x22DE7C, "hs484": 0x210484, "mode10": 0x22DE68,
    "thr454": 0x210454, "prio460": 0x210460, "lock480": 0x210480, "w4ec": 0x2104EC, "w4f0": 0x2104F0,
    "helper4d8": 0x2104D8, "srvcnt6": 0x22A5F8 + 6 * 4, "inpass6": 0x22A618 + 6 * 4,
    "plyst": 0x22DEC0 + 0x13C,
}
last = {}
start = time.time()
n = 0
while time.time() - start < secs:
    try:
        cur = {k: c.read32(a) for k, a in FIELDS.items()}
        h = cur["dectab0"]
        if h:
            cur["dec44"] = c.read32(h + 0x44)
            cur["dec48"] = c.read32(h + 0x48)
    except Exception as e:
        w("read err %s" % e)
        time.sleep(0.5)
        continue
    n += 1
    # srvcnt6 changes every pass: only report it with other changes, plus once per second
    ch = {k: v for k, v in cur.items() if last.get(k) != v and k != "srvcnt6"}
    if ch or n % 2000 == 0:
        w("t=%.3f n=%d %s | srvcnt6=%d" % (time.time() - start, n,
          " ".join("%s=0x%x" % (k, v) for k, v in sorted(ch.items())), cur["srvcnt6"]))
    last = cur
w("done samples=%d" % n)
proc.terminate()
