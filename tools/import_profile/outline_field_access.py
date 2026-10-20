"""Prepare an isolated noinline experiment; preserve complete access-check bodies."""
import difflib
import hashlib
import json
from pathlib import Path
import sys


def main():
    repo = Path(__file__).resolve().parents[2]
    original = repo / (
        "build-ninja/import-optimized-20261020/worker-benchmark/work/project/"
        "third_party/PS2Recomp/ps2xRuntime/src/lib/source_instruction_access.hpp"
    )
    output = Path(sys.argv[1]).resolve()
    if not output.is_relative_to(repo / "build-ninja") or output.exists():
        raise ValueError("Use a fresh directory under build-ninja")
    before = original.read_text()
    after = before
    changes = [
        ("template<class T> T readField(", "template<class T> REO_FIELD_NOINLINE T readField("),
        ("template<class T> void writeField(", "template<class T> REO_FIELD_NOINLINE void writeField("),
    ]
    for old, new in changes:
        if after.count(old) != 1:
            raise ValueError("Unexpected access helper declaration: " + old)
        after = after.replace(old, new)
    prefix = (
        "#if defined(_MSC_VER)\n#define REO_FIELD_NOINLINE __declspec(noinline)\n"
        "#else\n#define REO_FIELD_NOINLINE __attribute__((noinline))\n#endif\n"
    )
    suffix = "\n#undef REO_FIELD_NOINLINE\n"
    after = prefix + after + suffix
    reconstructed = after[len(prefix):-len(suffix)]
    for old, new in changes:
        reconstructed = reconstructed.replace(new, old)
    assert reconstructed == before
    output.mkdir(parents=True)
    header = output / original.name
    header.write_text(after)
    (output / "overlay.json").write_text(json.dumps({
        "version": 0, "case-sensitive": False, "use-external-names": False,
        "roots": [{"type": "file", "name": original.as_posix(),
                   "external-contents": header.as_posix()}],
    }, indent=2))
    (output / "candidate.patch").write_text("".join(difflib.unified_diff(
        before.splitlines(True), after.splitlines(True),
        fromfile=str(original), tofile=str(header))))
    (output / "candidate.json").write_text(json.dumps({
        "acceptedForRelease": False, "functionBodiesUnchanged": True,
        "originalHeader": str(original),
        "originalSha256": hashlib.sha256(original.read_bytes()).hexdigest(),
        "candidateSha256": hashlib.sha256(header.read_bytes()).hexdigest(),
        "annotations": ["readField", "writeField"],
    }, indent=2))


if __name__ == "__main__":
    main()
