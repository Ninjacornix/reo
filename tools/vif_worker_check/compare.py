"""Exact serial/worker parity; hashes are reporting only, not the comparator."""
import hashlib
import json
import pathlib
import sys

directory = pathlib.Path(sys.argv[1])
serial = (directory / "serial.bin").read_bytes()
worker = (directory / "worker.bin").read_bytes()
result = {
    "same": serial == worker,
    "serial_bytes": len(serial),
    "worker_bytes": len(worker),
    "serial_sha256": hashlib.sha256(serial).hexdigest(),
    "worker_sha256": hashlib.sha256(worker).hexdigest(),
    "native_integration": False,
    "comparison": "full VIF/VU state and memories, ordered GIF callbacks, display captures, final VRAM",
}
if serial != worker:
    result["first_different_offset"] = next((i for i, (a, b) in enumerate(zip(serial, worker)) if a != b), min(len(serial), len(worker)))
print(json.dumps(result, indent=2))
(directory.parent / "parity.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
raise SystemExit(0 if result["same"] else 1)
