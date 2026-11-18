"""Validate presentation rotation warp against real frames (tools/hybrid/room_driver.py --warp-probe).

Each capture records the camera eye/aim/lens. For each pair (A, B) with the same eye, warp image A
to B's orientation under candidate conventions and compare with the real image B (mean absolute
error over pixels whose source lies inside A). The convention with the lowest error is the one the
present shader must use.
"""
import json, math, re, sys
from pathlib import Path
import numpy as np
from PIL import Image

folder = Path(sys.argv[1])
poses = {}
log_path = folder.parent / (folder.name + '.driver.log')
for line in (log_path.read_text().splitlines() if log_path.exists() else []):
    m = re.search(r'WARP-CAPTURE (\w+) .* pose=(\[[^\]]*\])', line)
    if m: poses[m.group(1)] = json.loads(m.group(2))


def basis(eye, aim):
    f = np.array(aim) - np.array(eye); f /= np.linalg.norm(f)
    up = np.array([0.0, 1.0, 0.0])
    r = np.cross(up, f); r /= np.linalg.norm(r)       # game "right" (up x forward)
    u = np.cross(f, r)
    return f, r, u


def warp(img, pa, pb, sx, sy, fov_axis):
    h, w = img.shape[:2]
    fa, ra, ua = basis(pa[0:3], pa[3:6]); fb, rb, ub = basis(pb[0:3], pb[3:6])
    t = math.tan(math.radians(pa[6]) * 0.5)
    aspect = 4.0 / 3.0
    tx, ty = (t * aspect, t) if fov_axis == 'v' else (t, t / aspect)
    ys, xs = np.mgrid[0:h, 0:w].astype(np.float64)
    nx = (xs + 0.5) / w * 2 - 1; ny = 1 - (ys + 0.5) / h * 2
    # ray in B camera: screen x maps to sx*right, screen up maps to sy*up
    d = (fb[None, None] + (sx * nx * tx)[..., None] * rb + (sy * ny * ty)[..., None] * ub)
    za = d @ fa; xa = d @ ra; ya = d @ ua
    ok = za > 1e-6
    px = (sx * xa / np.where(ok, za, 1) / tx + 1) * 0.5 * w - 0.5
    py = (1 - sy * ya / np.where(ok, za, 1) / ty) * 0.5 * h - 0.5
    inside = ok & (px >= 0) & (px <= w - 1) & (py >= 0) & (py <= h - 1)
    xi = np.clip(np.round(px).astype(int), 0, w - 1); yi = np.clip(np.round(py).astype(int), 0, h - 1)
    return img[yi, xi], inside


def load(name):
    a = np.asarray(Image.open(folder / f'warp-{name}.png').convert('RGB')).astype(np.float64)
    # Exclude the black pillar/border columns and the crosshair centre.
    return a


pairs = [] if len(sys.argv) > 2 else [('w0', 'w1'), ('w2', 'w3'), ('w4', 'w5'), ('w5', 'w6'), ('w1', 'w0')]
results = {}
for a, b in pairs:
    A, B = load(a), load(b)
    h, w = A.shape[:2]
    # Picture region: ignore fully black left/right columns.
    cols = np.where(A.mean(axis=(0, 2)) > 2)[0]
    x0, x1 = (cols[0], cols[-1] + 1) if len(cols) else (0, w)
    Ac, Bc = A[:, x0:x1], B[:, x0:x1]
    base = np.abs(Ac - Bc).mean()
    row = {'size': [int(x1 - x0), h], 'unwarped': round(base, 2)}
    for sx in (1, -1):
        for sy in (1, -1):
            for fov in ('v', 'h'):
                W, inside = warp(Ac, poses[a], poses[b], sx, sy, fov)
                err = np.abs(W - Bc).mean(axis=2)[inside].mean() if inside.any() else 1e9
                row[f'sx{sx:+d} sy{sy:+d} fov-{fov}'] = round(float(err), 2)
    results[f'{a}->{b}'] = row
    print(f'{a}->{b}', json.dumps(row))
if pairs: json.dump(results, open(folder / 'warp-validation.json', 'w'), indent=2)


def gpu_check(reference, warped, yaw_deg, pitch_deg, lens=40.0):
    """REO_CAMERA_WARP_TEST=<yaw>,<pitch>: compare the shader's output with this warp of an
    unwarped capture at the same pose (picture 597.33x448 at x=21.33 in the 640x448 client)."""
    PW, PH, OX = 597.33, 448.0, 21.33
    A = np.asarray(Image.open(reference).convert('RGB')).astype(np.float64)
    B = np.asarray(Image.open(warped).convert('RGB')).astype(np.float64)
    h, w = A.shape[:2]
    def fwd(y, p):
        y, p = math.radians(y), math.radians(p)
        f = np.array([math.sin(y) * math.cos(p), math.sin(p), math.cos(y) * math.cos(p)])
        r = np.array([math.cos(y), 0.0, -math.sin(y)]); u = np.cross(f, r)
        return f, r, u
    fd, rd, ud = fwd(0, 0); ft, rt, ut = fwd(yaw_deg, pitch_deg)
    ty = math.tan(math.radians(lens) / 2); tx = ty * 4 / 3
    ys, xs = np.mgrid[0:h, 0:w].astype(np.float64)
    nx = (xs + .5 - OX) / PW * 2 - 1; ny = 1 - (ys + .5) / PH * 2
    d = ft[None, None] + (-nx * tx)[..., None] * rt + (ny * ty)[..., None] * ut
    z = d @ fd; sx = -(d @ rd) / z / tx; sy = (d @ ud) / z / ty
    px = np.clip((sx * .5 + .5), 0, 1) * PW + OX - .5; py = np.clip((.5 - sy * .5), 0, 1) * PH - .5
    W = A[np.clip(np.round(py).astype(int), 0, h - 1), np.clip(np.round(px).astype(int), 0, w - 1)]
    m = np.zeros((h, w), bool); m[:, 23:] = True
    m &= (py <= h - 1) & (px <= w - 1)  # source inside the captured (cropped) client
    m[200:250, 290:350] = False  # crosshair
    return {'python_vs_gpu': round(float(np.abs(W - B).mean(axis=2)[m].mean()), 2),
            'unwarped_vs_gpu': round(float(np.abs(A - B).mean(axis=2)[m].mean()), 2)}


if __name__ == '__main__' and len(sys.argv) > 2 and sys.argv[2] == '--gpu':
    print(json.dumps(gpu_check(sys.argv[3], sys.argv[4], float(sys.argv[5]), float(sys.argv[6]))))
