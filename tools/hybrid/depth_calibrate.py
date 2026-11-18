"""Calibrate the presentation-warp depth mapping Z = a + b / d from REO_CAMERA_DEPTH_DUMP dumps.

usage: depth_calibrate.py DUMP_FOLDER

Each dump holds the GS Z buffer of a shown frame (uint per pixel) and the camera views
around the flip. For the lower part of the picture the floor is the dominant surface;
for every candidate (pose lag L, floor height h) the forward distance d of each pixel's
ray to the plane y = h is computed and Z is fitted linearly against 1/d with outlier
trimming. The best (L, h) per dump and the median a, b across dumps are printed; the
result is REO_CAMERA_WARP_DEPTH=a,b and REO_CAMERA_WARP_LAG=L.
"""
import json, math, statistics, sys
from pathlib import Path
import numpy as np


def basis(forward):
    f = np.array(forward, float); f /= np.linalg.norm(f)
    yaw, pitch = math.atan2(f[0], f[2]), math.asin(max(-1, min(1, f[1])))
    cp = math.cos(pitch)
    f = np.array([math.sin(yaw) * cp, math.sin(pitch), math.cos(yaw) * cp])
    r = np.array([math.cos(yaw), 0.0, -math.sin(yaw)])
    u = np.cross(f, r)
    return f, r, u


def fit(z, inv_d):
    keep = np.ones(len(z), bool)
    a = b = 0.0
    for _ in range(4):
        if keep.sum() < 200:
            return None
        A = np.stack([np.ones(keep.sum()), inv_d[keep]], 1)
        (a, b), *_ = np.linalg.lstsq(A, z[keep], rcond=None)
        res = np.abs(z - (a + b * inv_d))
        cut = 3 * np.median(res[keep]) + 1e-9
        keep = res < cut
    res = np.abs(z - (a + b * inv_d))
    return a, b, float(np.median(res[keep])), int(keep.sum()), float(keep.mean())


def calibrate(meta_path):
    meta = json.loads(meta_path.read_text())
    w, h = meta['width'], meta['height']
    z = np.fromfile(meta_path.with_suffix('.bin'), dtype='<u4').reshape(h, w).astype(np.float64)
    views = {v['serial']: v for v in meta['views']}
    ys, xs = np.mgrid[0:h, 0:w]
    rows = ys >= int(h * 0.55)
    valid = rows & (z > 0)
    nx = ((xs + 0.5) / w * 2 - 1)[valid]; ny = (1 - (ys + 0.5) / h * 2)[valid]; zz = z[valid]
    best = None
    for lag in range(0, 4):
        view = views.get(meta['flipSerial'] - lag)
        if not view:
            continue
        f, r, u = basis(view['forward'])
        ty = math.tan(math.radians(view['lens']) / 2); tx = ty * 4 / 3
        dirs = f[None] + (-nx * tx)[:, None] * r[None] + (ny * ty)[:, None] * u[None]
        down = dirs[:, 1] < -1e-3
        eye_y = view['eye'][1]
        for floor in np.arange(eye_y - 400, eye_y - 40, 5.0):
            t = (floor - eye_y) / dirs[down, 1]
            ok = (t > 1) & (t < 20000)
            if ok.sum() < 500:
                continue
            result = fit(zz[down][ok], 1.0 / t[ok])
            if not result:
                continue
            a, b, err, n, share = result
            score = err / max(share, 1e-3)
            if best is None or score < best['score']:
                best = dict(lag=lag, floor=float(floor), a=float(a), b=float(b), err=err, n=n, share=share, score=score,
                            eye_y=eye_y)
    return meta_path.stem, best


if __name__ == '__main__':
    folder = Path(sys.argv[1])
    results = []
    for meta_path in sorted(folder.glob('depth-*.json')):
        name, best = calibrate(meta_path)
        print(name, json.dumps(best))
        if best:
            results.append(best)
    if results:
        good = [r for r in results if r['share'] > 0.5]
        use = good or results
        a = statistics.median(r['a'] for r in use); b = statistics.median(r['b'] for r in use)
        lags = [r['lag'] for r in use]
        print(f'REO_CAMERA_WARP_DEPTH={a:.6g},{b:.6g}  REO_CAMERA_WARP_LAG={statistics.mode(lags)}  (lags {lags})')
