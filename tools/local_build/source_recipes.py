#!/usr/bin/env python3
"""Reapply authored instrumentation using copies from locally generated code.

Recipes contain source offsets and authored insertions, never complete original
game function templates. Instruction witnesses are read from the supplied ELF.
"""

import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

INSTRUCTION_COMMENT = re.compile(r"(?im)^\s*//\s*(?:0x)?[0-9a-f]{6,8}:\s*(?:0x)?[0-9a-f]{7,8}\b[^\n]*\n?")
WITNESS = re.compile(r"(\.at\(\s*0x([0-9a-fA-F]+)u?\s*,\s*)0x[0-9a-fA-F]+u(\s*\))")


def normalized(text):
    text = text.replace("\r\n", "\n")
    text = INSTRUCTION_COMMENT.sub("", text)
    return WITNESS.sub(lambda m: m[1] + "REO_LOCAL_WORD_" + m[2].lower() + m[3], text)


def apply_recipe(base, recipe):
    base = normalized(base)
    if hashlib.sha256(base.encode()).hexdigest() != recipe["baseSha256"]:
        raise ValueError("Locally generated source differs from this instrumentation recipe")
    chunks = []
    for item in recipe["parts"]:
        if item[0] == "copy" and len(item) == 3:
            start, size = item[1:]
            if type(start) is not int or type(size) is not int or min(start, size) < 0 or start + size > len(base):
                raise ValueError("Invalid local source-copy range")
            chunks.append(base[start:start + size])
        elif item[0] == "text" and len(item) == 2 and isinstance(item[1], str):
            if INSTRUCTION_COMMENT.search(item[1]):
                raise ValueError("An insertion contains original instruction text")
            chunks.append(item[1])
        else:
            raise ValueError("Invalid source recipe operation")
    result = "".join(chunks)
    if hashlib.sha256(result.encode()).hexdigest() != recipe["resultSha256"]:
        raise ValueError("Local source recipe result failed verification")
    return result


def apply_plan(elf, generated, plan, output):
    image = Path(elf).read_bytes()
    plan = json.loads(Path(plan).read_text())
    if plan.get("format") != 1 or hashlib.sha256(image).hexdigest() != plan["elfSha256"]:
        raise ValueError("Unsupported source ELF")
    phoff = struct.unpack_from("<I", image, 28)[0]
    phsize, count = struct.unpack_from("<HH", image, 42)
    segments = [struct.unpack_from("<8I", image, phoff + i * phsize) for i in range(count)]

    def witness(match):
        pc = int(match[1], 16)
        for kind, offset, address, _, size, *_ in segments:
            if kind == 1 and address <= pc and pc + 4 <= address + size:
                word = struct.unpack_from("<I", image, offset + pc - address)[0]
                return f"0x{word:08x}u"
        raise ValueError("An instruction witness is not present in the owned ELF")

    def inside(root, name):
        root = Path(root).resolve()
        path = (root / name).resolve()
        if not path.is_relative_to(root):
            raise ValueError("Source recipe escapes its private workspace")
        return path

    for recipe in plan["recipes"]:
        base = inside(generated, recipe["source"])
        target = inside(output, recipe["destination"])
        result = apply_recipe(base.read_text(), recipe)
        result = re.sub(r"REO_LOCAL_WORD_([0-9a-f]+)", witness, result)
        target.parent.mkdir(parents=True, exist_ok=True)
        temporary = target.with_suffix(target.suffix + ".pending")
        temporary.write_text(result)
        temporary.replace(target)
    return len(plan["recipes"])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--elf", required=True, type=Path)
    parser.add_argument("--generated", required=True, type=Path)
    parser.add_argument("--plan", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    print(f"Applied {apply_plan(args.elf, args.generated, args.plan, args.output)} local source recipes")


if __name__ == "__main__":
    main()
