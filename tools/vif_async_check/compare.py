"""Exact state bytes comparison; hashes describe the already exact result."""
import hashlib
import json
import pathlib
import sys
directory = pathlib.Path(sys.argv[1])
serial = (directory / "serial.bin").read_bytes()
cursor = (directory / "cursor.bin").read_bytes()
result = dict(same=serial == cursor, serial_bytes=len(serial), cursor_bytes=len(cursor),
              serial_sha256=hashlib.sha256(serial).hexdigest(),
              cursor_sha256=hashlib.sha256(cursor).hexdigest(), native_integration=False,
              comparison="full real VIF/VU/code/data, ordered GIF callbacks, captures and final VRAM")
if serial != cursor:
    result["first_different_offset"] = next((i for i, (a, b) in enumerate(zip(serial, cursor)) if a != b),
                                         min(len(serial), len(cursor)))
print(json.dumps(result, indent=2))
out = directory.parent / "parity.json"
if out.exists():
    raise SystemExit("Refusing to overwrite parity record")
out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
raise SystemExit(0 if result["same"] else 1)
