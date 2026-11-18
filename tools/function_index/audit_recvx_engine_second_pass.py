"""Static copied-word audit for the bounded CVX engine comparison; never executes guest code."""
import hashlib
import json
import pathlib
import re
import sqlite3
import sys

sys.path.insert(0, "tools/function_index")
from index import Elf

root = pathlib.Path(".")
identity = json.loads((root / "tools/function_index/overlay_identities.json").read_text())
elf_path = root / "game_data/SLUS_207.65"
assert hashlib.sha256(elf_path.read_bytes()).hexdigest() == identity["elf_sha256"]
elf = Elf(str(elf_path))
overlays = {}
for im in identity["images"]:
    if im["image"] not in ("o0", "o2"):
        continue
    raw = (root / f'build-function-index/owned-overlays/{im["image"]}.bin').read_bytes()
    assert hashlib.sha256(raw).hexdigest() == im["imageSha256"]
    overlays[im["image"]] = (im["base"], raw, im["imageSha256"])

db = sqlite3.connect("file:build-function-index/index.sqlite?mode=ro", uri=True)
db.row_factory = sqlite3.Row
entries = {
    "main": [0x18F340, 0x18F470, 0x18FE20, 0x1900E0, 0x1919D0, 0x17EC98, 0x18F1E0, 0x1930F0],
    "o0": [0x3700C0, 0x370100],
    "o2": [0x68C660, 0x68CE90],
}
rows = []
for image, starts in entries.items():
    for start in starts:
        f = db.execute("SELECT * FROM functions WHERE image=? AND start=?", (image, start)).fetchone()
        assert f is not None
        source = pathlib.Path(f["source"])
        words = {}
        for match in re.finditer(r"// 0x([\da-f]+): 0x([\da-f]+)\s+", source.read_text(), re.I):
            pc, word = int(match[1], 16), int(match[2], 16)
            if start <= pc < f["end"]:
                assert pc not in words or words[pc] == word
                words[pc] = word
        omitted_zero = 0
        for pc in range(start, f["end"], 4):
            if image == "main":
                raw = elf.read(pc, 4)
            else:
                base, data, _ = overlays[image]
                raw = data[pc - base:pc - base + 4]
            assert raw is not None and len(raw) == 4
            word = int.from_bytes(raw, "little")
            if pc in words:
                assert words[pc] == word, (image, hex(pc))
            else:
                assert word == 0, (image, hex(pc), hex(word))
                omitted_zero += 1
        rows.append({"image": image, "start": f"0x{start:08X}", "end": f"0x{f['end']:08X}",
                     "source": str(source).replace("\\", "/"), "source_sha256": hashlib.sha256(source.read_bytes()).hexdigest(),
                     "verified_comments": len(words), "omitted_zero_words": omitted_zero})

result = {"kind": "static-word-audit-only", "elf_sha256": identity["elf_sha256"],
          "overlay_sha256": {key: val[2] for key, val in overlays.items()},
          "entries": rows, "verified_comments": sum(r["verified_comments"] for r in rows),
          "omitted_zero_words": sum(r["omitted_zero_words"] for r in rows),
          "conflicts": 0, "omitted_nonzero_words": 0}
path = root / "build-function-index/recvx-engine-second-pass-audit.json"
path.write_text(json.dumps(result, indent=2) + "\n")
print(json.dumps({k: result[k] for k in ("kind", "verified_comments", "omitted_zero_words", "conflicts", "omitted_nonzero_words")}))
