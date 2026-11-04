#!/usr/bin/env python3
"""Export authored changes to local generated copies without copying game bodies.

Maintainer-only: inputs are private generated reference files. The exported
recipe is verified by rebuilding each result from its local base before use.
"""

import argparse
import difflib
import hashlib
import json
from pathlib import Path
import re

from source_recipes import apply_recipe, normalized
from generate_game import GAMES


def recipe(base, result):
    base, result = normalized(base), normalized(result)
    old, new = base.splitlines(keepends=True), result.splitlines(keepends=True)
    offsets = [0]
    for line in old:
        offsets.append(offsets[-1] + len(line))
    parts = []

    def append(kind, *args):
        if kind == "copy" and args[1] == 0 or kind == "text" and not args[0]:
            return
        if parts and kind == "copy" and parts[-1][0] == kind and parts[-1][1] + parts[-1][2] == args[0]:
            parts[-1][2] += args[1]
        elif parts and kind == "text" and parts[-1][0] == kind:
            parts[-1][1] += args[0]
        else:
            parts.append([kind, *args])

    for kind, a, b, c, d in difflib.SequenceMatcher(None, old, new, autojunk=False).get_opcodes():
        if kind == "equal":
            append("copy", offsets[a], offsets[b] - offsets[a])
        elif kind == "insert":
            append("text", "".join(new[c:d]))
        elif kind == "replace":
            before, after = "".join(old[a:b]), "".join(new[c:d])
            for op, i, j, k, l in difflib.SequenceMatcher(None, before, after, autojunk=False).get_opcodes():
                if op == "equal":
                    append("copy", offsets[a] + i, j - i)
                elif op in {"insert", "replace"}:
                    append("text", after[k:l])
    plan = {"baseSha256": hashlib.sha256(base.encode()).hexdigest(),
            "resultSha256": hashlib.sha256(result.encode()).hexdigest(), "parts": parts}
    assert apply_recipe(base, plan) == result
    return plan


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--inventory", required=True, type=Path)
    parser.add_argument("--source-root", required=True, type=Path)
    parser.add_argument("--generated", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--game", choices=GAMES, default="file1")
    parser.add_argument("--preserve-generated", action="store_true",
                        help="Retain existing authored fixes/registrations in generated translation units")
    args = parser.parse_args()
    args.source_root = args.source_root.resolve()
    args.generated = args.generated.resolve()
    records = []
    for unit in json.loads(args.inventory.read_text()):
        for file, kind in zip(unit["sources"], unit["kinds"]):
            if kind != "copied-body":
                continue
            target = Path(file)
            source = target.read_text()
            match = re.search(r"// Function:\s*(\w+)\s*\n// Address:\s*(0x[\da-fA-F]+)", source)
            if not match:
                raise ValueError("Copied function lacks its source identity")
            name, address = match.groups()
            entry = int(address, 16)
            if args.game == "file2":
                # Ported movie wrappers retain historical File #1 header names;
                # their original instruction comments identify the actual File #2 entry.
                instruction = re.search(r"// 0x([0-9a-fA-F]+): 0x[0-9a-fA-F]+", source)
                if instruction is None:
                    raise ValueError("File #2 copied body has no original entry instruction")
                entry = int(instruction[1], 16)
                candidates = [p for folder in ("output", "output_ovl", "output_extra")
                              for p in (args.generated / folder).rglob(f"*_0x{entry:x}.cpp")]
                if len(candidates) != 1:
                    raise ValueError("File #2 copied body must match exactly one regenerated entry")
                relative = candidates[0].relative_to(args.generated).as_posix()
            else:
                relative = ("output/" if entry < 0x370000 else "output_ovl/" + name.split("_")[0] + "/")
                relative += name + f"_0x{entry:x}.cpp"
            base = args.generated / relative
            result = recipe(base.read_text(), source)
            result.update(source=relative, destination=target.relative_to(args.source_root).as_posix())
            if args.game == "file2":
                result["sourceAudit"] = False
            records.append(result)
    if args.preserve_generated:
        config = args.source_root / "recomp/config" / ("output_file2" if args.game == "file2" else "")
        for folder, pattern in [("output", "*.cpp"), ("output_ovl", "**/*.cpp"), ("output_extra", "*.cpp")]:
            for target in sorted((config / folder).glob(pattern)):
                relative = target.relative_to(config).as_posix()
                base = args.generated / relative
                if not base.exists():
                    raise ValueError("An existing game source was not regenerated: " + relative)
                before, after = base.read_text(), target.read_text()
                if normalized(before) == normalized(after):
                    continue
                result = recipe(before, after)
                result.update(source=relative, destination="generated-overrides/" + relative)
                if args.game == "file2":
                    result["sourceAudit"] = False
                records.append(result)
    args.output.write_text(json.dumps({"format": 1,
        "elfSha256": GAMES[args.game]["sha256"],
        "recipes": records}, indent=2) + "\n")
    print(f"Exported and round-trip verified {len(records)} source recipes without original instruction comments")


if __name__ == "__main__":
    main()
