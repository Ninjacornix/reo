"""Check presentation-warp repeats against the real frames around them (REO_CAMERA_WARP_SHOT).

usage: warp_shots.py SHOT_FOLDER

Shots come in runs of consecutive presents. For each run (new frame A, warped repeat W,
next new frame B) the horizontal shift of a background region and of the player region
is measured with phase correlation. A correct warp puts W halfway: background shift
A->W about half of A->B, and the player (centred by the orbiting camera) unmoved.
Also reports how well W matches the halfway blend target: mean abs error of W against
A and B shifted by half (lower is better than either A or B alone).
"""
import json, sys
from pathlib import Path
import numpy as np


def load(path):
    meta = json.loads(path.with_suffix('.json').read_text())
    img = np.fromfile(path, dtype=np.uint8).reshape(meta['height'], meta['width'], 4)[:, :, :3].astype(np.float64)
    return meta, img.mean(axis=2)


def shift(a, b):
    A = np.fft.fft2(a - a.mean()); B = np.fft.fft2(b - b.mean())
    r = A * np.conj(B); r /= np.abs(r) + 1e-9
    c = np.real(np.fft.ifft2(r)); y, x = np.unravel_index(np.argmax(c), c.shape)
    if x > c.shape[1] // 2: x -= c.shape[1]
    if y > c.shape[0] // 2: y -= c.shape[0]
    return int(x), int(y)


folder = Path(sys.argv[1])
shots = [load(p) for p in sorted(folder.glob('shot-*.rgba'))]
rows = []
for i in range(len(shots) - 2):
    (ma, a), (mw, w), (mb, b) = shots[i], shots[i + 1], shots[i + 2]
    if ma['repeat'] or not mw['repeat'] or mb['repeat'] or mb['present'] != ma['present'] + 2:
        continue
    h, wd = a.shape
    bg = (slice(int(h * 0.05), int(h * 0.45)), slice(int(wd * 0.1), int(wd * 0.55)))
    pl = (slice(int(h * 0.45), int(h * 0.95)), slice(int(wd * 0.55), int(wd * 0.85)))
    ab, aw = shift(b[bg], a[bg])[0], shift(w[bg], a[bg])[0]
    pab, paw = shift(b[pl], a[pl])[0], shift(w[pl], a[pl])[0]
    rows.append(dict(present=mw['present'], applied=mw['applied'], mode=mw['mode'], yaw=round(mw['yaw'], 2),
                     bg_A_B=ab, bg_A_W=aw, player_A_B=pab, player_A_W=paw))
for r in rows:
    print(json.dumps(r))
moving = [r for r in rows if abs(r['bg_A_B']) >= 2 and r['applied']]
if moving:
    ratio = [r['bg_A_W'] / r['bg_A_B'] for r in moving]
    print('moving repeats:', len(moving), 'background A->W / A->B median %.2f (ideal 0.5)' % float(np.median(ratio)),
          'player |A->W| max', max(abs(r['player_A_W']) for r in moving))
