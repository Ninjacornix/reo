"""Match captured native frames to an owned movie and its host PCM timeline.

Requires PyAV, numpy and Pillow (use an isolated analysis venv). Inputs and
optional JSON report stay in ignored build output. Positive lead means audio
is ahead. Device latency is an estimate; report it explicitly, not as measured
speaker latency. REO_SHOT_AT timestamps and REO_CRI_SYNC_LOG are required.
"""
import argparse
import json
import re
from pathlib import Path

import av
import numpy as np
from PIL import Image


def feature(image):
    # Exclude repeated corner logo and bottom caption; suppress color-conversion
    # differences while retaining motion for individual-frame matching.
    a = np.asarray(image.convert("L").resize((128, 112), Image.Resampling.BOX), dtype=np.float32)
    a = a[16:100, 4:124].reshape(-1)
    a -= a.mean()
    return a / max(float(np.linalg.norm(a)), 1e-9)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("movie", type=Path)
    parser.add_argument("run", type=Path)
    parser.add_argument("--host-latency-ms", type=float, default=0)
    parser.add_argument("--min-correlation", type=float, default=0.99,
                        help="Reject frames belonging to other movies or uncertain matches")
    parser.add_argument("--report", type=Path)
    args = parser.parse_args()
    frames, times = [], []
    with av.open(str(args.movie)) as container:
        for frame in container.decode(video=0):
            if frame.time is None:
                raise ValueError("Reference movie has no presentation timestamps")
            frames.append(feature(frame.to_image()))
            times.append(float(frame.time))
    references = np.stack(frames)
    start = stop = None
    positions, shots, segments = [], [], []
    log = (args.run / "stderr.log").read_text(encoding="utf-8", errors="replace")
    for line in log.splitlines():
        match = re.search(r"\[CRI-SYNC\] play voice=\w+ enabled=(\d) ns=(\d+)", line)
        if match:
            enabled, ns = map(int, match.groups())
            if enabled:
                start, stop, positions = ns, None, []
            elif start is not None:
                segments.append((start, ns, positions))
                start, positions = None, []
        match = re.search(r"\[CRI-SYNC\] position voice=\w+ ns=(\d+) pcmSeconds=([\d.]+)", line)
        if match and start is not None:
            debt = re.search(r"skipped=(\d+) late=(\d+)", line)
            positions.append((int(match[1]), float(match[2]),
                              any(int(x) for x in debt.groups()) if debt else False))
        match = re.search(r"\[SHOT\] (shot_\d+\.bmp) \d+x\d+ ns=(\d+)", line)
        if match:
            shots.append((match[1], int(match[2])))
    if start is not None:
        segments.append((start, 2**63 - 1, positions))
    report = {"movie": str(args.movie), "run": str(args.run),
              "host_latency_estimate_ms": args.host_latency_ms, "shots": [], "rejected": []}
    for name, ns in shots:
        segment = next((s for s in segments if s[0] <= ns < s[1]), None)
        if segment is None or not segment[2]:
            continue
        with Image.open(args.run / name) as image:
            scores = references @ feature(image)
        best = int(np.argmax(scores))
        if scores[best] < args.min_correlation:
            report["rejected"].append({"shot": name, "reason": "frame correlation below threshold",
                                       "correlation": float(scores[best])})
            continue
        # Compare against a different motion interval, not indistinguishable
        # adjacent frames. Static scenes can still be ambiguous: retain score.
        mask = np.abs(np.arange(len(times)) - best) >= 10
        competing = float(scores[mask].max()) if mask.any() else 0
        pos = segment[2]
        anchor = min(pos, key=lambda p: abs(p[0] - ns))
        if any(p[2] for p in pos):
            raise ValueError("Playback interval contains skipped/late PCM; fixed-rate extrapolation is unsafe")
        pcm = anchor[1] + (ns - anchor[0]) / 1e9
        audio = pcm - args.host_latency_ms / 1000
        row = {"shot": name, "ns": ns, "reference_frame": best,
               "video_seconds": times[best], "audio_rendered_seconds": pcm,
               "audio_estimated_audible_seconds": audio,
               "audio_lead_ms": (audio - times[best]) * 1000,
               "correlation": float(scores[best]), "competing_correlation": competing,
               "anchor_distance_ms": abs(ns - anchor[0]) / 1e6}
        report["shots"].append(row)
        print(json.dumps(row))
    if not report["shots"]:
        raise ValueError("No timestamped screenshots within a traced playing interval")
    if args.report:
        args.report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
