"""Audit owned File1 retail room texture descriptors without executing the game.

Reads the admitted member inventory, exact ISO extents, owned executable/overlay,
and generated original instruction comments. Writes metadata only to a NEW output
directory. No decoder, native game, process inspection, or asset extraction runs.
"""
import argparse
import collections
import hashlib
import json
import re
import struct
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
PINNED = {
    "game_data/SLUS_207.65": "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46",
    "build-function-index/owned-overlays/o2.bin": "45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226",
    "build-native-sjuni/audio-asset-inventory/file1-v1/members.json": "276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2",
    "build-native-sjuni/audio-asset-inventory/file1-v1/receipt.json": "765b03bca36fa7a3c78f57f8bf73bb72f0790d504dd14054e304dff29d570d23",
}
SOURCE_PROFILES = [
    ("producer", "recomp/config/output/sub_001D0C80_0x1d0c80.cpp", 0x1D0C80, 0x1D102C),
    ("consumer", "recomp/config/output_ovl/o2/o2_00576F90_0x576f90.cpp", 0x576F90, 0x5770B8),
]
LIMITATIONS = [
    "This accounts for the named eNNNNNNN.bin members of the pinned inventory, not every possible input source.",
    "Runtime mutation, indirect writers, alternate roots, mods, and other builds are not excluded by this audit.",
    "No game execution, live process access, window action, effect decode, or subjective A/V validation occurred.",
    "No effect movie payload is identified or decoded; absent names/header candidates alone cannot establish payload absence.",
    "The existing inventory receipt records full ISO identity; this audit rehashes selected payloads, not the entire ISO.",
]


def digest(data):
    return hashlib.sha256(data).hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def elf_reader(data):
    require(data[:6] == b"\x7fELF\x01\x01", "Expected little-endian ELF32")
    phoff = struct.unpack_from("<I", data, 28)[0]
    entsize, count = struct.unpack_from("<HH", data, 42)
    segments = []
    for i in range(count):
        kind, off, va, _, size = struct.unpack_from("<5I", data, phoff + i * entsize)
        if kind == 1:
            require(off + size <= len(data), "Truncated ELF load segment")
            segments.append((va, off, size))

    def read(address, length):
        for va, off, size in segments:
            if va <= address and address + length <= va + size:
                return data[off + address - va:off + address - va + length]
        raise ValueError(f"Unbacked owned ELF address {address:#x}")

    return read


def compare_source(role, relative, start, end, read):
    raw = (ROOT / relative).read_bytes()
    words = {}
    for address, encoded in re.findall(r"// 0x([\da-fA-F]+): 0x([\da-fA-F]+)", raw.decode()):
        address, encoded = int(address, 16), int(encoded, 16)
        if start <= address < end:
            require(address not in words or words[address] == encoded, "Conflicting instruction comment")
            words[address] = encoded
    comparisons = []
    for address in range(start, end, 4):
        actual = struct.unpack("<I", read(address, 4))[0]
        commented = words.get(address)
        require(commented == actual if commented is not None else actual == 0,
                f"{relative}: unaccounted/mismatched word at {address:#x}")
        comparisons.append({"pc": f"0x{address:08x}", "owned_word": f"0x{actual:08x}",
                            "comment_word": None if commented is None else f"0x{commented:08x}",
                            "status": "omitted_zero" if commented is None else "matched"})
    return {"role": role, "path": relative, "sha256": digest(raw),
            "start": f"0x{start:x}", "end_exclusive": f"0x{end:x}",
            "matched_comments": len(words), "omitted_zero_words": len(comparisons) - len(words),
            "conflicts": 0, "comparisons": comparisons}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--iso", type=Path, default=ROOT / "iso/Resident Evil - Outbreak (v2.00).iso")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    require(not args.output.exists(), "Output directory must be new")
    inputs = {}
    for relative, expected in PINNED.items():
        raw = (ROOT / relative).read_bytes()
        require(digest(raw) == expected, f"Pinned input mismatch: {relative}")
        inputs[relative] = {"sha256": expected, "bytes": len(raw)}
    elf = (ROOT / "game_data/SLUS_207.65").read_bytes()
    overlay = (ROOT / "build-function-index/owned-overlays/o2.bin").read_bytes()
    readers = [elf_reader(elf), lambda a, n: overlay[a - 0x570000:a - 0x570000 + n]]
    sources = [compare_source(*profile, reader) for profile, reader in zip(SOURCE_PROFILES, readers)]
    receipt = json.loads((ROOT / "build-native-sjuni/audio-asset-inventory/file1-v1/receipt.json").read_text())
    inventory = json.loads((ROOT / "build-native-sjuni/audio-asset-inventory/file1-v1/members.json").read_text())
    iso_stat = args.iso.stat()
    require(iso_stat.st_size == 4698767360, "Unexpected owned ISO size")
    members, count_hist, first_hist, scenarios = [], collections.Counter(), collections.Counter(), collections.Counter()
    with args.iso.open("rb") as stream:
        for entry in inventory:
            names = [name for name in entry["names"] if re.fullmatch(r"e\d{7}\.bin", name, re.I)]
            if not names:
                continue
            require(len(names) == 1, "Ambiguous room-script member name")
            name = names[0]
            offset, length = entry["iso_offset"], entry["bytes"]
            require(0 <= offset and 4 <= length <= 16 * 1024 * 1024 and offset + length <= iso_stat.st_size,
                    f"Out-of-bounds room-script member: {name}")
            stream.seek(offset)
            raw = stream.read(length)
            require(len(raw) == length and digest(raw) == entry["sha256"], f"Member hash mismatch: {name}")
            count = struct.unpack_from("<I", raw)[0]
            require(4 + count * 8 <= length, f"Descriptor count outside member: {name}")
            descriptors = []
            for index in range(count):
                row = raw[4 + 8 * index:12 + 8 * index]
                kind = "skip_ff" if row[0] == 255 else "animated_texture" if row[0] & 128 else "arm_effect_1"
                descriptors.append({"index": index, "member_offset": 4 + 8 * index,
                                    "guest_destination": f"0x{0x392630 + 8 * index:08x}",
                                    "hex": row.hex(), "first_byte": row[0], "consumer_route": kind})
                first_hist[row[0]] += 1
            scenario = int(name[1:4])
            scenarios[f"{scenario:03d}"] += 1
            count_hist[count] += 1
            members.append({"member": entry["member"], "names": entry["names"], "name": name,
                            "container": entry["container"], "iso_offset": offset, "bytes": length,
                            "sha256": entry["sha256"], "payload_hash_verified": True,
                            "scenario": scenario, "room": int(name[4:6]), "variant": int(name[6:8]),
                            "descriptor_count": count, "descriptors": descriptors})
    require(args.iso.stat().st_size == iso_stat.st_size and args.iso.stat().st_mtime_ns == iso_stat.st_mtime_ns,
            "ISO metadata changed during audit")
    rows = [row for member in members for row in member["descriptors"]]
    effect_rows = sum(row["consumer_route"] == "arm_effect_1" for row in rows)
    summary = {"members": len(members), "payload_bytes_hashed": sum(m["bytes"] for m in members),
               "descriptor_rows": len(rows), "nonempty_members": sum(m["descriptor_count"] > 0 for m in members),
               "count_histogram": dict(sorted(count_hist.items())),
               "first_byte_histogram": {f"0x{k:02x}": v for k, v in sorted(first_hist.items())},
               "scenario_members": dict(sorted(scenarios.items())), "effect_arm_rows": effect_rows,
               "skipped_ff_rows": sum(row["first_byte"] == 255 for row in rows)}
    require((len(members), len(rows), effect_rows) == (265, 74, 0), "Pinned retail cohort changed")
    result = {"schema": 1, "status": "passed", "scope": "five pinned retail scenario room-script descriptor sets",
              "game_run": False, "live_process_access": False, "window_actions": False,
              "source_files_modified": False, "iso": {"path": str(args.iso.resolve()), "bytes": iso_stat.st_size,
              "mtime_ns": iso_stat.st_mtime_ns, "prior_inventory_receipt_iso_sha256": receipt["iso_sha256"],
              "full_iso_rehashed": False}, "tool_sha256": digest(Path(__file__).read_bytes()),
              "inputs": inputs, "summary": summary, "source_intervals": sources,
              "members": members, "limitations": LIMITATIONS}
    args.output.mkdir(parents=True, exist_ok=False)
    report = args.output / "audit.json"
    report.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "passed", "report": str(report.resolve()),
                      "report_sha256": digest(report.read_bytes()), "summary": summary}))


if __name__ == "__main__":
    main()
