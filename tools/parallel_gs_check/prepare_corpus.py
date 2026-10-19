"""Extract real ordered VU GIF bytes; reconstructed GS state is explicit.

This is input preparation, not a GPU/GS correctness test. Root owns execution.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct


def split_artifact(path):
    raw = path.read_bytes()
    if len(raw) < 24:
        raise ValueError(f"Truncated artifact: {path}")
    magic, version, state_bytes, data_bytes, memory_count, gs_count = struct.unpack_from("<6I", raw)
    if magic != 0x504F4E56 or version != 1 or state_bytes != 632 or data_bytes != 16384:
        raise ValueError(f"Unknown VU oracle artifact: {path}")
    cursor = 24 + state_bytes + data_bytes
    groups = []
    for count in (memory_count, gs_count):
        packets = []
        for _ in range(count):
            if cursor + 4 > len(raw):
                raise ValueError(f"Truncated packet length: {path}")
            length = struct.unpack_from("<I", raw, cursor)[0]
            cursor += 4
            if not length or length % 16 or cursor + length > len(raw):
                raise ValueError(f"Invalid packet length: {path}")
            packets.append(raw[cursor:cursor + length])
            cursor += length
        groups.append(packets)
    if cursor != len(raw):
        raise ValueError(f"Artifact trailing bytes: {path}")
    # The first group is the memory/arbiter sink; do not duplicate it through GS sink.
    return groups[0] if groups[0] else groups[1]


def validate_packet(packet):
    cursor = 0
    last_eop = False
    while cursor < len(packet):
        if cursor + 16 > len(packet):
            raise ValueError("Truncated GIF tag")
        low = struct.unpack_from("<Q", packet, cursor)[0]
        loops, flag, nreg = low & 0x7FFF, (low >> 58) & 3, (low >> 60) & 15
        nreg = nreg or 16
        last_eop = bool((low >> 15) & 1)
        cursor += 16
        if flag == 0:
            payload = loops * nreg * 16
        elif flag == 1:
            payload = ((loops * nreg + 1) // 2) * 16
        else:
            payload = loops * 16
        if cursor + payload > len(packet):
            raise ValueError("Truncated GIF payload")
        cursor += payload
    if not last_eop:
        raise ValueError("Captured packet lacks completed final EOP")


def main():
    parser = argparse.ArgumentParser()
    sources = parser.add_mutually_exclusive_group(required=True)
    sources.add_argument("--artifacts", type=Path, help="Complete VU replay output directory")
    sources.add_argument("--exports", type=Path, help="Directory containing vu_gif_packets.jsonl")
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    if args.out.exists() and any(args.out.iterdir()):
        raise ValueError("Output directory must be empty")
    args.out.mkdir(parents=True, exist_ok=True)
    rows = []
    if args.artifacts:
        inputs = sorted(args.artifacts.glob("weighted-*.bin")) + sorted(args.artifacts.glob("static-*.bin"))
        if not inputs:
            raise ValueError("No actual weighted/static replay artifacts")
        for path in inputs:
            source_hash = hashlib.sha256(path.read_bytes()).hexdigest()
            for ordinal, packet in enumerate(split_artifact(path)):
                rows.append((str(path.resolve()), source_hash, ordinal, packet))
    else:
        for entry in map(json.loads, (args.exports / "vu_gif_packets.jsonl").read_text().splitlines()):
            path = args.exports / entry["file"]
            packet = path.read_bytes()
            if len(packet) != entry["bytes"] or not entry.get("complete_eop"):
                raise ValueError("Incomplete exported actual packet")
            rows.append((str(path.resolve()), hashlib.sha256(packet).hexdigest(), entry["packet"], packet))
    metadata = []
    manifest = ["REO_ACTUAL_PACKETS_RECONSTRUCTED_STATE_V1"]
    for index, (source, source_hash, ordinal, packet) in enumerate(rows):
        validate_packet(packet)
        path = (args.out / f"packet-{index:04d}.bin").resolve()
        path.write_bytes(packet)
        # std::quoted accepts escaped backslashes; use forward slashes for Windows paths.
        manifest.append(f'0 "{path.as_posix()}"')
        metadata.append({"path": 0, "packet": str(path), "bytes": len(packet),
                         "sha256": hashlib.sha256(packet).hexdigest(), "source": source,
                         "source_sha256": source_hash, "source_packet": ordinal})
    (args.out / "corpus.txt").write_text("\n".join(manifest) + "\n", encoding="utf-8")
    (args.out / "provenance.json").write_text(json.dumps({
        "classification": "actual_packet_exercise_with_reconstructed_initial_GS_state",
        "faithful_room_replay": False, "chronological_native_frame_sequence": False,
        "texture_VRAM_restored": False, "packets": metadata,
    }, indent=2) + "\n", encoding="utf-8")
    print(f"ACTUAL_PACKETS {len(rows)} bytes={sum(len(row[3]) for row in rows)} faithful_room_replay=false")


if __name__ == "__main__":
    main()
