"""Read-only structural audit of the owned unrolled File #1 digest core.

This compares file bytes and instruction templates. It never executes guest code.
Run from the repository root; generated source and the existing index are inputs.
"""
import collections
import hashlib
import json
import pathlib
import re
import struct

from index import Elf


def main():
    elf = Elf("game_data/SLUS_207.65")
    source = pathlib.Path("recomp/config/output/sub_001EB830_0x1eb830.cpp")
    insns = {}
    for match in re.finditer(
        r"// 0x([\da-f]+): 0x([\da-f]+)\s+([^\r\n]+)",
        source.read_text(encoding="utf-8"), re.I,
    ):
        pc, word = int(match[1], 16), int(match[2], 16)
        if 0x1EB830 <= pc < 0x1F05B4:
            assert int.from_bytes(elf.read(pc, 4), "little") == word, hex(pc)
            value = (pc, word, " ".join(match[3].split()))
            assert pc not in insns or insns[pc] == value
            insns[pc] = value
    seq = [insns[pc] for pc in sorted(insns)]
    assert len(seq) == 4942
    for pc in range(0x1EB830, 0x1F05B4, 4):
        assert pc in insns or elf.read(pc, 4) == b"\0" * 4, hex(pc)
    starts = [
        i for i, item in enumerate(seq)
        if item[2] == "lw $v0, 0x1C($fp)"
        and seq[i + 1][2] == "sll $v1, $v0, 5"
    ]
    assert len(starts) == 80
    templates = collections.defaultdict(list)
    covered = set()
    for number, start in enumerate(starts):
        end = next(
            i + 1 for i in range(start, len(seq))
            if seq[i][2] == "sw $v0, 0x1C($fp)"
        )
        words = tuple(item[1] for item in seq[start:end])
        templates[words].append((number, seq[start][0], seq[end - 1][0] + 4))
        covered.update(range(start, end))
    expected = [(37, 16), (41, 4), (39, 20), (43, 20), (39, 19), (36, 1)]
    assert [(len(words), len(rows)) for words, rows in templates.items()] == expected
    # Every gap inside the complete round region is schedule construction.
    blocks, block = [], []
    for i, item in enumerate(seq):
        if i in covered or not 0x1EBB84 <= item[0] < 0x1F0518:
            continue
        if block and item[0] != block[-1][0] + 4:
            blocks.append(block)
            block = []
        block.append(item)
    if block:
        blocks.append(block)
    schedules = collections.defaultdict(list)
    for block in blocks:
        schedules[tuple(item[1] for item in block)].append(block[0][0])
    assert [(len(words), len(rows)) for words, rows in schedules.items()] == [
        (36, 1), (24, 62), (12, 1),
    ]

    def digest(words):
        return hashlib.sha256(struct.pack("<" + "I" * len(words), *words)).hexdigest()

    print(json.dumps({
        "source": str(source), "verifiedWords": len(seq),
        "coreStart": "0x1EBB84", "coreEndExclusive": "0x1F0518",
        "coreSha256": hashlib.sha256(elf.read(0x1EBB84, 0x1F0518 - 0x1EBB84)).hexdigest(),
        "roundTemplates": [
            {"words": len(words), "rounds": [r[0] for r in rows],
             "firstPc": hex(rows[0][1]), "sha256": digest(words)}
            for words, rows in templates.items()
        ],
        "scheduleTemplates": [
            {"words": len(words), "occurrences": len(rows),
             "firstPc": hex(rows[0]), "sha256": digest(words)}
            for words, rows in schedules.items()
        ],
    }, indent=2))


if __name__ == "__main__":
    main()
