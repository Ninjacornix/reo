"""Isolate RAM-boundary slow paths, retaining the ordinary inline memory access."""
import difflib
import json
from pathlib import Path
import sys


def prepare(original):
    text = original
    records = []
    for operation in ("Read", "Write"):
        for bits, value_type in ((16, "uint16_t"), (32, "uint32_t"),
                                 (64, "uint64_t"), (128, "__m128i")):
            name = f"Ps2Fast{operation}{bits}"
            result_type = value_type if operation == "Read" else "void"
            signature = f"static inline {result_type} {name}("
            start = text.index(signature)
            conditional = text.index("if (!Ps2FastRangeIsContiguous", start)
            begin = text.index("{", conditional)
            depth, end = 1, begin + 1
            while depth:
                depth += (text[end] == "{") - (text[end] == "}")
                end += 1
            body = text[begin + 1:end - 1]
            const = "const " if operation == "Read" else ""
            parameter = "" if operation == "Read" else f", {value_type} value"
            argument = "" if operation == "Read" else ", value"
            helper = (f"static REO_MEMORY_NOINLINE {result_type} {name}Wrapped("
                      f"{const}uint8_t *rdram, uint32_t offset{parameter})\n"
                      "{" + body + "}\n\n")
            replacement = "{\n        return " + name + f"Wrapped(rdram, offset{argument});\n    }}"
            old = text[start:end]
            new = helper + text[start:begin] + replacement
            records.append((old, new))
            text = text[:start] + new + text[end:]
    macro = ("#if defined(_MSC_VER)\n#define REO_MEMORY_NOINLINE __declspec(noinline)\n"
             "#else\n#define REO_MEMORY_NOINLINE __attribute__((noinline))\n#endif\n")
    suffix = "\n#undef REO_MEMORY_NOINLINE\n"
    reconstructed = text
    for old, new in reversed(records):
        assert reconstructed.count(new) == 1
        reconstructed = reconstructed.replace(new, old)
    assert reconstructed == original
    return macro + text + suffix


def main():
    repo = Path(__file__).resolve().parents[2]
    path = repo / ("build-ninja/import-optimized-20261020/worker-benchmark/work/project/"
                   "third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h")
    out = Path(sys.argv[1]).resolve()
    if not out.is_relative_to(repo / "build-ninja") or out.exists():
        raise ValueError("Use a fresh directory under build-ninja")
    before = path.read_text()
    after = prepare(before)
    out.mkdir(parents=True)
    header = out / path.name
    header.write_text(after)
    (out / "candidate.patch").write_text("".join(difflib.unified_diff(
        before.splitlines(True), after.splitlines(True),
        fromfile=str(path), tofile=str(header))))
    (out / "overlay.json").write_text(json.dumps({
        "version": 0, "case-sensitive": False, "use-external-names": False,
        "roots": [{"type": "file", "name": path.as_posix(),
                   "external-contents": header.as_posix()}],
    }, indent=2))
    (out / "candidate.json").write_text(json.dumps({
        "acceptedForRelease": False, "originalHeader": str(path),
        "slowPathBodiesUnchanged": True, "ordinaryPathUnchanged": True,
    }, indent=2))


if __name__ == "__main__":
    main()
