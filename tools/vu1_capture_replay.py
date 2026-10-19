"""Replay one bounded live VU capture using the production-interpreter fixture.

This creates independent CPU reference bytes for GPU development. It neither
admits a program nor treats a captured optimized native return as reference gold.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("capture", type=Path, help="Live capture prefix, without .state.bin")
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    parser.add_argument("--image-sha256", required=True)
    args = parser.parse_args()
    prefix, out, reference = args.capture.resolve(), args.out.resolve(), args.reference.resolve()
    if out.exists():
        raise SystemExit("Refusing to replace an existing reference run")
    files = {name: Path(str(prefix) + "." + name + ".bin") for name in ("code", "state", "data", "meta")}
    raw = {name: path.read_bytes() for name, path in files.items()}
    if tuple(len(raw[name]) for name in ("code", "state", "data", "meta")) != (16384, 632, 16384, 32):
        raise SystemExit("Expected the bounded live collector's 16KiB/632B/16KiB/32B schema")
    magic, version, state_bytes, data_bytes, pc, top, itop, resume = struct.unpack("<8I", raw["meta"])
    if (magic, version, state_bytes, data_bytes) != (0x43415556, 1, 632, 16384):
        raise SystemExit("Unknown live capture schema")
    if pc >= 16384 or pc & 7 or top >= 1024 or itop >= 1024 or resume not in (0, 1):
        raise SystemExit("Invalid captured launch boundary")
    if digest(files["code"]) != args.image_sha256.lower():
        raise SystemExit("Capture does not match the explicitly selected exact image")
    state = bytearray(raw["state"])
    carried_pc = struct.unpack_from("<I", state, 604)[0]
    if resume and carried_pc != pc:
        raise SystemExit("Resume must use the captured architectural continuation PC")
    # The fixture starts at state.pc. MSCAL replaces that PC; MSCNT retains it.
    # Preserve every other architectural byte, including the incoming E flag.
    if not resume:
        struct.pack_into("<I", state, 604, pc)
    out.mkdir(parents=True)
    normalized = out / "input"
    for name in ("code", "data"):
        Path(str(normalized) + "." + name + ".bin").write_bytes(raw[name])
    Path(str(normalized) + ".state.bin").write_bytes(state)
    Path(str(normalized) + ".meta.bin").write_bytes(
        struct.pack("<10I", 0, 0, 0, 0, 65536, top, top, itop, 0, 0))
    command = [str(reference), str(normalized), "--dump-gif", str(out / "original"),
               "--dump-gif-count", "512", "--dump-gif-bytes", str(64 * 1024 * 1024)]
    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=120)
    (out / "reference.log").write_bytes(result.stdout)
    log = result.stdout.decode("utf-8", errors="replace")
    if result.returncode or not re.search(r"CHECKS \d+ passed 0 failed", log):
        raise SystemExit("Production-interpreter reference failed; preserve reference.log")
    match = re.search(r"REPLAY pc=[0-9a-f]+ end=[0-9a-f]+ packets=(\d+)", log)
    records = [json.loads(line) for line in (out / "original/vu_gif_packets.jsonl").read_text().splitlines()]
    if not match or len(records) != int(match.group(1)):
        raise SystemExit("Ordered packet capture was incomplete")
    final_state = (out / "original/vu_final_state.bin").read_bytes()
    final_data = (out / "original/vu_final_data.bin").read_bytes()
    if len(final_state) != 632 or len(final_data) != 16384 or not final_state[620]:
        raise SystemExit("Reference did not reach an E-bit termination within the pair budget")
    report = {
        "status": "CPU_REFERENCE_COMPLETE_NOT_GPU_PROOF", "image_sha256": digest(files["code"]),
        "entryPC": pc, "capturedCarryPC": carried_pc, "resume": bool(resume), "TOP": top, "ITOP": itop,
        "reference_exe": str(reference), "reference_sha256": digest(reference),
        "source_inputs": {str(path): digest(path) for path in files.values()},
        "normalization": "MSCAL sets only PC; MSCNT retains captured PC; no other state/data reseeding",
        "TOPS": "Not captured; fixture metadata uses TOP, unused by numerical execution",
        "postPC": struct.unpack_from("<I", final_state, 604)[0],
        "packets": [{"file": row["file"], "bytes": row["bytes"],
                     "sha256": digest(out / "original" / row["file"])} for row in records],
        "final_state_sha256": digest(out / "original/vu_final_state.bin"),
        "final_data_sha256": digest(out / "original/vu_final_data.bin"),
    }
    (out / "reference.json").write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps({"status": report["status"], "packets": len(records), "postPC": report["postPC"]}))


if __name__ == "__main__":
    main()
