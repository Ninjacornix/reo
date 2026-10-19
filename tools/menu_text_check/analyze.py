"""Measure missing bright text in a bounded burst of native present dumps.

Requires numpy and Pillow. Coordinates use the dumped framebuffer, not the window.
This flags visual anomalies; guest state and a reference distinguish intentional
selection animation from a rendering defect. No game assets are stored here.
"""

import argparse
import json
import re
from pathlib import Path

import numpy as np
from PIL import Image


def parse_roi(value):
    fields = value.split(":", 1)
    if len(fields) != 2:
        raise argparse.ArgumentTypeError("ROI must be name:x,y,width,height")
    try:
        coords = tuple(int(part) for part in fields[1].split(","))
    except ValueError as exc:
        raise argparse.ArgumentTypeError("ROI coordinates must be integers") from exc
    if len(coords) != 4 or min(coords[:2]) < 0 or min(coords[2:]) < 1:
        raise argparse.ArgumentTypeError("ROI needs nonnegative origin and positive size")
    return fields[0], coords


def score_region(images, roi, threshold, reference=None):
    x, y, width, height = roi
    crops = np.stack([image[y:y + height, x:x + width, :3] for image in images])
    # A stable white glyph has bright, nearly neutral RGB. Movie motion outside
    # the glyph changes brightness without meeting this predicate consistently.
    neutral = crops.max(axis=-1).astype(np.int16) - crops.min(axis=-1).astype(np.int16) < 35
    bright = (crops.min(axis=-1) >= threshold) & neutral
    # At 40% this also detects alternating good/bad fields. A known good menu
    # reference supplies a fixed glyph mask when most captured frames are bad.
    if reference is None:
        mask = bright.mean(axis=0) >= 0.40
    else:
        crop = reference[y:y + height, x:x + width, :3]
        mask = (crop.min(axis=-1) >= threshold) & (
            crop.max(axis=-1).astype(np.int16) - crop.min(axis=-1).astype(np.int16) < 35)
    pixels = int(mask.sum())
    coverage = bright[:, mask].mean(axis=1) if pixels else np.zeros(len(images))
    baseline = float(np.percentile(coverage, 90)) if pixels else 0.0
    return {
        "roi": list(roi),
        "mask_pixels": pixels,
        "mask_source": "reference" if reference is not None else "empirical bright frequency >= 40%",
        "baseline_coverage_p90": baseline,
        "coverage_min": float(coverage.min()),
        "coverage_median": float(np.median(coverage)),
        "coverage_max": float(coverage.max()),
        "anomalies": [index for index, value in enumerate(coverage)
                      if pixels >= 12 and value < baseline * 0.50],
        "coverage": [round(float(value), 6) for value in coverage],
        "status": "measured" if pixels >= 12 else "insufficient stable bright pixels",
    }


def self_test():
    rng = np.random.default_rng(4)
    images = [rng.integers(0, 100, (20, 40, 3), dtype=np.uint8) for _ in range(20)]
    for image in images:
        image[5:9, 12:25] = 255
    images[7][5:9, 12:25] = 0
    result = score_region(images, (10, 4, 20, 8), 210)
    assert result["mask_pixels"] == 52 and result["anomalies"] == [7], result
    for index in range(0, len(images), 2):
        images[index][5:9, 12:25] = 0
    images[7][5:9, 12:25] = 255
    result = score_region(images, (10, 4, 20, 8), 210)
    assert result["anomalies"] == list(range(0, 20, 2)), result
    print("PASS: moving background rejected; isolated and alternating missing glyph frames detected")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory", nargs="?", type=Path)
    parser.add_argument("--roi", action="append", type=parse_roi,
                        help="name:x,y,width,height (repeatable)")
    parser.add_argument("--threshold", type=int, default=210)
    parser.add_argument("--reference", type=Path, help="known good framebuffer with the same menu and dimensions")
    parser.add_argument("--report", type=Path)
    parser.add_argument("--self-test", action="store_true")
    args = parser.parse_args()
    if args.self_test:
        self_test()
        return
    if args.directory is None or not args.roi:
        parser.error("directory and at least one --roi are required")
    if not 0 <= args.threshold <= 255:
        parser.error("--threshold must be between 0 and 255")
    files = sorted(args.directory.glob("present_*.bmp"),
                   key=lambda path: int(re.fullmatch(r"present_(\d+)\.bmp", path.name)[1]))
    if not files:
        parser.error("no present_<number>.bmp files found")
    images = [np.asarray(Image.open(path).convert("RGB")) for path in files]
    if len({image.shape for image in images}) != 1:
        parser.error("frame sizes differ; analyze separate stable menu segments")
    frame_height, frame_width = images[0].shape[:2]
    reference = np.asarray(Image.open(args.reference).convert("RGB")) if args.reference else None
    if reference is not None and reference.shape != images[0].shape:
        parser.error("reference dimensions differ from captured frames")
    for name, (x, y, width, height) in args.roi:
        if x + width > frame_width or y + height > frame_height:
            parser.error(f"{name} ROI exceeds {frame_width}x{frame_height} framebuffer")
    metadata = {}
    metadata_path = args.directory / "present_dump.jsonl"
    if metadata_path.exists():
        for line in metadata_path.read_text(encoding="utf-8").splitlines():
            entry = json.loads(line)
            metadata[entry["image"]] = entry
    report = {
        "directory": str(args.directory.resolve()),
        "frame_count": len(files),
        "dimensions": [frame_width, frame_height],
        "threshold": args.threshold,
        "frames": [{"image": file.name, **metadata.get(file.name, {})} for file in files],
        "reference": str(args.reference) if args.reference else None,
        "regions": {name: score_region(images, roi, args.threshold, reference) for name, roi in args.roi},
        "limitation": "Anomaly candidates require guest color/state and reference review; capture can perturb timing.",
    }
    encoded = json.dumps(report, indent=2)
    if args.report:
        args.report.write_text(encoded + "\n", encoding="utf-8")
    for name, result in report["regions"].items():
        print(f"{name}: {result['status']}, mask={result['mask_pixels']} pixels, "
              f"coverage={result['coverage_min']:.3f}..{result['coverage_max']:.3f}, "
              f"anomaly candidates={result['anomalies']}")
    if not args.report:
        print(encoded)


if __name__ == "__main__":
    main()
