"""Privately annotate the trivial lazy register wrapper for early inlining."""
import difflib
import hashlib
import json
from pathlib import Path
import sys


def main():
    repo = Path(__file__).resolve().parents[2]
    original = repo / ("build-ninja/import-optimized-20261020/worker-benchmark/work/project/"
                       "third_party/PS2Recomp/ps2xRuntime/src/lib/source_instruction_access.hpp")
    output = Path(sys.argv[1]).resolve()
    if not output.is_relative_to(repo / "build-ninja") or output.exists():
        raise ValueError("Use a fresh directory under build-ninja")
    before = original.read_text()
    old = "template<class T,class ContextFactory>constexpr T sourceGprReadLazy("
    new = "template<class T,class ContextFactory>__attribute__((always_inline)) constexpr T sourceGprReadLazy("
    if before.count(old) != 1:
        raise ValueError("Unexpected lazy wrapper declaration")
    after = before.replace(old, new)
    assert after.replace(new, old) == before
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
    }, indent=2))


if __name__ == "__main__":
    main()
