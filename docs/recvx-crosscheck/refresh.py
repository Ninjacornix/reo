"""Validate curated comparisons and inventory notebooks without executing game code.

The reference checkout is supplied explicitly; this script never downloads it.
Generated reports do not modify the main symbol annotations or function index.
"""
from __future__ import annotations

import argparse
from collections import Counter
import csv
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys


HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
sys.path.insert(0, str(ROOT / 'tools/function_index'))
from recvx_scope_inventory import function_records


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def git(path: Path, *args: str) -> str:
    return subprocess.check_output(
        ["git", "-C", str(path), *args], text=True, encoding="utf-8"
    ).strip()


def definitions(text: str) -> dict[str, tuple[int, int]]:
    # The original single-line regex missed multiline and debug-metadata
    # definitions. Preserve named bodies with the shared balanced inventory.
    found = {}
    for record in function_records(text):
        name = record['symbol']
        if name in found:
            raise ValueError(f'Ambiguous duplicate reference definition: {name}')
        found[name] = (record['start_line'], record['end_line'])
    return found


def write_csv(name: str, rows: list[dict], fields: list[str]) -> None:
    with (HERE / name).open("w", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def comparison_links(text: str, notebook: Path) -> str:
    """Contracts copied from a notebook retain that notebook's link context."""
    def replace(match):
        label, target = match[1], match[2]
        if re.match(r'^[a-zA-Z][a-zA-Z0-9+.-]*:', target) or target.startswith('/'):
            return match[0]
        path, separator, fragment = target.partition('#')
        resolved = (notebook.parent / path).resolve() if path else notebook.resolve()
        if not resolved.exists():
            # Explicitly authored comparison links may already use the output
            # folder as their context; accept those without guessing a target.
            resolved = (HERE / path).resolve()
        if not resolved.exists():
            raise ValueError(f'Invalid comparison link in {notebook.name}: {target}')
        relative = Path(os.path.relpath(resolved, HERE)).as_posix()
        return f'[{label}]({relative}{separator}{fragment})'
    return re.sub(r'\[([^\]\n]+)\]\(([^)]+)\)', replace, text)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", required=True, type=Path)
    parser.add_argument("--elf", required=True, type=Path)
    args = parser.parse_args()
    review = json.loads((HERE / "review.json").read_text(encoding="utf-8"))
    reference = args.reference.resolve()
    if git(reference, "rev-parse", "HEAD") != review["reference_commit"]:
        raise ValueError("Reference revision does not match review.json")
    if git(reference, "status", "--porcelain", "--untracked-files=no"):
        raise ValueError("Reference checkout has tracked modifications")
    elf = args.elf.read_bytes()
    if sha(elf) != review["outbreak_elf_sha256"]:
        raise ValueError("Outbreak ELF SHA-256 does not match review.json")
    if elf[:6] != b"\x7fELF\x01\x01":
        raise ValueError("Expected ELF32 little endian")
    phoff = struct.unpack_from("<I", elf, 28)[0]
    phsize, phcount = struct.unpack_from("<HH", elf, 42)
    segments = []
    for i in range(phcount):
        kind, offset, va, _, size, _, _, _ = struct.unpack_from(
            "<8I", elf, phoff + i * phsize)
        if kind == 1:
            segments.append((va, va + size, offset))

    def original_word(address: int) -> int:
        for start, end, offset in segments:
            if start <= address and address + 4 <= end:
                return struct.unpack_from("<I", elf, offset + address - start)[0]
        raise ValueError(f"Instruction outside file-backed ELF segments: {address:x}")

    source_index = {}
    source_bytes = {}
    symbol_locations = {}
    for path in sorted((reference / "src").rglob("*.c")):
        relative = path.relative_to(reference).as_posix()
        raw = path.read_bytes()
        # Some engine comments contain legacy Japanese bytes. Only ASCII C
        # identifiers and newline positions are used; raw bytes remain hashed.
        defs = definitions(raw.decode("utf-8-sig", errors="replace"))
        source_index[relative] = defs
        source_bytes[relative] = raw
        for symbol in defs:
            # API spellings only; lexical overlap is never an equivalence result.
            if "_" in symbol or symbol.startswith(("cvFs", "nj", "bh")):
                symbol_locations.setdefault(symbol, []).append(relative)

    rows = []
    used = set()
    inspected_files = {}
    for group in review["groups"]:
        notebook = ROOT / "docs" / group["notebook"]
        text = notebook.read_text(encoding="utf-8-sig")
        for address, symbol, status, comparison in group["rows"]:
            if address in used:
                raise ValueError(f"Duplicate curated main entry {address}")
            used.add(address)
            matches = []
            for lineno, line in enumerate(text.splitlines(), 1):
                if not line.startswith("|"):
                    continue
                cells = line.split("|")
                if re.search(r"\b0x0*" + address + r"\b", cells[1], re.I):
                    matches.append((lineno, cells))
            if len(matches) != 1:
                raise ValueError(f"Expected one notebook row for {address}: {matches}")
            lineno, cells = matches[0]
            anchors = re.findall(r"\[([^\]]+)\]\(([^)]+\.cpp)\)", cells[1])
            selected = [(i, target) for i, (label, target) in enumerate(anchors)
                        if re.search(r"\b0x0*" + address + r"\b", label, re.I)]
            if len(selected) != 1:
                raise ValueError(f"No generated-source link for {address}")
            anchor_index, source_target = selected[0]
            generated = (notebook.parent / source_target).resolve()
            relative_generated = generated.relative_to(ROOT).as_posix()
            if relative_generated not in inspected_files:
                raw = generated.read_bytes()
                words = re.findall(r"//\s*0x([0-9a-f]+):\s*0x([0-9a-f]{1,8})\b",
                                   raw.decode("utf-8-sig"), re.I)
                if not words:
                    raise ValueError(f"No original instruction comments: {generated}")
                for pc, word in words:
                    if original_word(int(pc, 16)) != int(word, 16):
                        raise ValueError(f"ELF/comment mismatch: {relative_generated}:{pc}")
                inspected_files[relative_generated] = {
                    "sha256": sha(raw), "verified_instruction_comments": len(words)}
            start, end = source_index[group["cvx_file"]][symbol]
            url = (f'{review["reference_repository"]}/blob/{review["reference_commit"]}/'
                   f'{group["cvx_file"]}#L{start}-L{end}')
            labels = re.findall(r'`([^`]+)`', cells[2])
            current_label = (labels[anchor_index] if len(labels) == len(anchors)
                             else labels[0] if labels else cells[2].strip())
            rows.append(dict(group=group["id"], image="main", address="0x" + address,
                             notebook=group["notebook"], notebook_line=lineno,
                             current_label=current_label,
                             generated_source=relative_generated,
                             cvx_symbol=symbol, cvx_source=group["cvx_file"],
                             cvx_url=url, status=status,
                             comparison=comparison_links(comparison, notebook)))

    notebooks = []
    for path in sorted((ROOT / "docs").glob("SYMBOLS*.md")):
        text = path.read_text(encoding="utf-8-sig")
        tokens = set(re.findall(r"\b[A-Za-z_]\w*\b", text))
        overlaps = sorted(tokens & symbol_locations.keys())
        count = sum(r["notebook"] == path.name for r in rows)
        title = next((x[2:] for x in text.splitlines() if x.startswith("# ")), path.stem)
        notebooks.append(dict(notebook=path.name, title=title,
                              sha256=sha(path.read_bytes()),
                              curated_entries=count,
                              screening="curated-entries" if count else "lexical-screen-only",
                              cvx_api_token_count=len(overlaps),
                              cvx_api_tokens=";".join(overlaps)))

    write_csv("crosswalk.csv", rows, list(rows[0]))
    write_csv("notebook-inventory.csv", notebooks, list(notebooks[0]))
    counts = dict(sorted(Counter(row["status"] for row in rows).items()))
    provenance = {
        "review_date": review["review_date"],
        "reference_repository": review["reference_repository"],
        "reference_commit": review["reference_commit"],
        "outbreak_image": review["outbreak_image"],
        "outbreak_elf_sha256": sha(elf),
        "local_head": git(ROOT, "rev-parse", "HEAD"),
        "scope": "Static comparison; ELF/comment integrity is not semantic or runtime equivalence",
        "counts": {"symbol_notebooks": len(notebooks), "curated_entries": len(rows),
                   "notebooks_with_curated_entries": sum(n["curated_entries"] > 0 for n in notebooks),
                   "reference_c_files_lexically_screened": len(source_index),
                   "generated_files_checked": len(inspected_files),
                   "instruction_comments_checked": sum(v["verified_instruction_comments"]
                                                       for v in inspected_files.values()),
                   "by_status": counts},
        "reference_files_used_in_crosswalk": {
            p: {"sha256": sha(source_bytes[p])} for p in sorted({r["cvx_source"] for r in rows})},
        "supporting_reference_files": {
            p: {"sha256": sha((reference / p).read_bytes())}
            for p in review["supporting_reference_files"]},
        "generated_files_checked": dict(sorted(inspected_files.items())),
    }
    (HERE / "provenance.json").write_text(json.dumps(provenance, indent=2) + "\n", encoding="utf-8")
    markdown = ["# Reviewed symbol comparisons", "",
                "Generated from [review.json](review.json). See [scope and confidence](README.md).", "",
                f"{len(rows)} main-ELF entries; " + "; ".join(f"{n} {s}" for s, n in counts.items()) + ".", "",
                "`supported-role` supports the stated API role, not complete semantic equivalence.", ""]
    for group in review["groups"]:
        markdown.extend([f'## {group["id"]}', "",
                         "| Outbreak entry / notebook | CVX reference | Result | Comparison |",
                         "| --- | --- | --- | --- |"])
        for row in rows:
            if row["group"] == group["id"]:
                comparison = re.sub(r'(?<!\\)\|', lambda _: r'\|', row["comparison"])
                markdown.append(f'| [{row["address"]}](../{row["notebook"]}) | '
                                f'[{row["cvx_symbol"]}]({row["cvx_url"]}) | '
                                f'{row["status"]} | {comparison} |')
        markdown.append("")
    (HERE / "CROSSWALK.md").write_text("\n".join(markdown), encoding="utf-8")
    print(json.dumps(provenance["counts"], indent=2))


if __name__ == "__main__":
    main()
