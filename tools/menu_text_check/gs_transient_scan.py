"""Inspect existing native present bursts; never launch or alter the game.

Usage: python gs_transient_scan.py <present_dump.jsonl> [--roi .28 .15 .63 .29]
The default ROI is the large mirror in the first Kevin camera. Candidate labels
are image heuristics, not proof of a renderer, palette, or presentation defect.
Requires Pillow, also used by the existing screenshot comparison tools.
"""
import argparse
import json
from pathlib import Path
from PIL import Image


def stats(image):
    image = image.convert("RGB")
    image.thumbnail((128, 112))
    pixels = list(image.getdata())
    count = max(1, len(pixels))
    luminance = [(54 * r + 183 * g + 19 * b) / 256 for r, g, b in pixels]
    mean = sum(luminance) / count
    return {
        "luma": round(mean, 3),
        "luma_sd": round((sum((v - mean) ** 2 for v in luminance) / count) ** .5, 3),
        "near_black_fraction": round(sum(max(p) <= 8 for p in pixels) / count, 5),
        "green_fraction": round(sum(g >= 60 and g > 1.5 * r and g > 1.5 * b for r, g, b in pixels) / count, 5),
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("sidecar", type=Path)
    parser.add_argument("--roi", nargs=4, type=float, default=(.28, .15, .63, .29), metavar=("X0", "Y0", "X1", "Y1"))
    args = parser.parse_args()
    x0, y0, x1, y1 = args.roi
    if not (0 <= x0 < x1 <= 1 and 0 <= y0 < y1 <= 1):
        parser.error("ROI must be an ordered normalized rectangle inside the frame")
    previous = None
    for line in args.sidecar.read_text(encoding="utf-8").splitlines():
        record = json.loads(line)
        image_path = args.sidecar.parent / record["image"]
        with Image.open(image_path) as image:
            width, height = image.size
            whole = stats(image)
            roi = stats(image.crop((round(x0 * width), round(y0 * height), round(x1 * width), round(y1 * height))))
        flags = []
        if whole["green_fraction"] >= .8:
            flags.append("global_green_candidate")
        if previous and roi["luma"] < previous["roi"]["luma"] * .45 and previous["roi"]["luma"] >= 8:
            flags.append("mirror_darkening_candidate")
        if previous and record.get("frame_tick") == previous.get("frame_tick"):
            flags.append("same_copied_frame_tick")
        result = {**record, "whole": whole, "roi": roi, "flags": flags}
        print(json.dumps(result, separators=(",", ":")))
        previous = result


if __name__ == "__main__":
    main()
