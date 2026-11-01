#!/usr/bin/env python3
"""Compare paired RC1/common launcher captures from tools/launcher/parity.ps1.

Writes <folder>/diff/<Page>.png (RC1 | common | amplified difference), index.html and
report.json with per-page and per-region difference measurements. Requires Pillow.
"""
import json
import sys
from pathlib import Path

from PIL import Image, ImageChops, ImageDraw, ImageOps

PAGES = ['Play', 'Graphics', 'Audio', 'Controller', 'Saves', 'Coop', 'Mods', 'Cheats',
         'Setup', 'Launcher', 'Logs', 'Developer']
# Regions of the client area (fractions of width/height) reported separately.
REGIONS = {'sidebar': (0, 0, 210, None), 'page': (210, 0, None, -110), 'footer': (210, -110, None, None)}


def client(image):
    """WPF RenderTargetBitmap(Window) leaves the frame area transparent; keep the client."""
    image = image.convert('RGBA')
    box = image.getchannel('A').point(lambda a: 255 if a > 0 else 0).getbbox()
    return image.crop(box).convert('RGB') if box else image.convert('RGB')


def region(size, spec):
    width, height = size
    left, top, right, bottom = spec
    fix = lambda value, total, default: default if value is None else (total + value if value < 0 else value)
    return (fix(left, width, 0), fix(top, height, 0), fix(right, width, width), fix(bottom, height, height))


def measure(a, b):
    difference = ImageChops.difference(a, b).convert('L')
    histogram = difference.histogram()
    total = sum(histogram) or 1
    mean = sum(i * n for i, n in enumerate(histogram)) / total
    changed = sum(histogram[24:]) / total
    return difference, round(mean, 2), round(100 * changed, 2)


def main(folder):
    folder = Path(folder)
    out = folder / 'diff'
    out.mkdir(exist_ok=True)
    report, rows = {}, []
    for page in PAGES:
        rc1_path, common_path = folder / 'rc1' / f'{page}.png', folder / 'common' / f'{page}.png'
        if not rc1_path.exists() or not common_path.exists():
            report[page] = {'missing': [str(p) for p in (rc1_path, common_path) if not p.exists()]}
            continue
        rc1, common = client(Image.open(rc1_path)), client(Image.open(common_path))
        entry = {'rc1Size': rc1.size, 'commonSize': common.size}
        size = (min(rc1.width, common.width), min(rc1.height, common.height))
        a, b = rc1.crop((0, 0) + size), common.crop((0, 0) + size)
        difference, mean, changed = measure(a, b)
        entry.update(mean=mean, changedPercent=changed, regions={})
        for name, spec in REGIONS.items():
            box = region(size, spec)
            _, rmean, rchanged = measure(a.crop(box), b.crop(box))
            entry['regions'][name] = {'mean': rmean, 'changedPercent': rchanged}
        heat = ImageOps.autocontrast(difference, cutoff=0).convert('RGB')
        sheet = Image.new('RGB', (size[0] * 3, size[1] + 24), (20, 18, 16))
        for i, (label, image) in enumerate((('RC1', a), ('common', b), ('difference', heat))):
            sheet.paste(image, (i * size[0], 24))
            ImageDraw.Draw(sheet).text((i * size[0] + 8, 6), f'{page} - {label}', fill=(243, 236, 223))
        sheet.save(out / f'{page}.png')
        report[page] = entry
        rows.append(f'<h2>{page}: mean {mean}, changed {changed}%</h2><img src="{page}.png" width="100%">')
    (out / 'index.html').write_text('<body style="background:#141210;color:#f3ecdf;font-family:sans-serif">' + ''.join(rows))
    (out / 'report.json').write_text(json.dumps(report, indent=2))
    print(json.dumps(report, indent=2))
    if __import__('os').environ.get('GITHUB_ACTIONS') == 'true':
        # One annotation: a step shows at most ten.
        summary = ' | '.join(f"{page} {e.get('changedPercent', 'missing')}%/{e.get('mean', '-')}"
                             for page, e in report.items())
        print('::notice title=Parity (changed %/mean)::' + summary)


if __name__ == '__main__':
    main(sys.argv[1] if len(sys.argv) > 1 else 'build-launcher/parity')
