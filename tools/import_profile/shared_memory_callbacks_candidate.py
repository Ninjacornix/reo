"""Use named memory callbacks in a private header, retaining guard operations.

A macro expansion otherwise creates a distinct callback type for every guest
instruction. This experiment shares callback types by width and fast/normal
access, with the same reference captures and evaluation order.
"""
import difflib
import hashlib
import json
from pathlib import Path
import sys


def transform(before):
    anchor = "constexpr bool DirectFieldRewriteComplete = false;"
    if before.count(anchor) != 1:
        raise ValueError("Unexpected guard header")
    helpers = ""
    for bits, kind in [(8, "uint8_t"), (16, "uint16_t"), (32, "uint32_t"),
                       (64, "uint64_t"), (128, "__m128i")]:
        helpers += f"""
template<bool Fast> struct OriginalMemoryRead{bits} {{
    PS2Runtime*& runtime;
    uint8_t*& rdram;
    R5900Context*& ctx;
    const uint32_t& at;
    {kind} operator()() const {{
        if constexpr (Fast) return Ps2FastRead{bits}(rdram, at);
        else return PS2Runtime::isSpecialAddress(at)
            ? runtime->Load{bits}(rdram, ctx, at) : Ps2FastRead{bits}(rdram, at);
    }}
}};
template<bool Fast> struct OriginalMemoryWrite{bits} {{
    PS2Runtime*& runtime;
    uint8_t*& rdram;
    R5900Context*& ctx;
    const uint32_t& at;
    void operator()({kind} value) const {{
        if constexpr (Fast) Ps2FastWrite{bits}(rdram, at, value);
        else if (PS2Runtime::isSpecialAddress(at)) runtime->Store{bits}(rdram, ctx, at, value);
        else {{
            uint64_t lo = 0, hi = 0;
            std::memcpy(&lo, &value, std::min<size_t>(sizeof({kind}), 8));
            if constexpr (sizeof({kind}) > 8)
                std::memcpy(&hi, reinterpret_cast<const uint8_t*>(&value) + 8, 8);
            ps2TraceGuestWrite(rdram, at, sizeof({kind}), lo, hi, "WRITE{bits}", ctx);
            Ps2FastWrite{bits}(rdram, at, value);
        }}
    }}
}};
"""
    after = before.replace(anchor, helpers + anchor)
    start = after.index("#define REO_GUARDED_FAST_READ(")
    end = after.index("#define FAST_READ8(", start)
    macros = ""
    for fast in (True, False):
        name = "FAST_" if fast else ""
        flag = str(fast).lower()
        macros += f"""#define REO_GUARDED_{name}READ(T, N, A) \\
    ([&]() -> T {{ \\
        const uint32_t reo_at = (uint32_t)(A); \\
        return reo_source_adapter::guardedRead<T>(*runtime, rdram, *ctx, reo_at, {flag}, \\
            reo_source_adapter::OriginalMemoryRead##N<{flag}>{{runtime, rdram, ctx, reo_at}}); \\
    }}())
#define REO_GUARDED_{name}WRITE(T, N, A, V) \\
    do {{ \\
        const uint32_t reo_at = (uint32_t)(A); \\
        const T reo_value = (T)(V); \\
        reo_source_adapter::guardedWrite(*runtime, rdram, *ctx, reo_at, reo_value, {flag}, \\
            reo_source_adapter::OriginalMemoryWrite##N<{flag}>{{runtime, rdram, ctx, reo_at}}); \\
    }} while (0)
"""
    after = after[:start] + macros + after[end:]
    # The owner/permit/readback/exception machinery is untouched.
    assert after[:after.index(helpers)] == before[:before.index(anchor)]
    return after


def main():
    repo = Path(__file__).resolve().parents[2]
    original = repo / ("build-ninja/import-optimized-20261020/worker-benchmark/work/project/"
                       "tools/parallel_gs_backend/resident_geometry/guarded_source_overlay.hpp")
    output = Path(sys.argv[1]).resolve()
    if not output.is_relative_to(repo / "build-ninja") or output.exists():
        raise ValueError("Use a fresh directory under build-ninja")
    before = original.read_text()
    after = transform(before)
    if "--site-tags" in sys.argv[2:]:
        replacements = [
            ("template <class T, class OriginalRead>", "template <class T, unsigned Site = 0, class OriginalRead>"),
            ("template <class T, class OriginalWrite>", "template <unsigned Site = 0, class T, class OriginalWrite>"),
            ("::guardedRead<T>(", "::guardedRead<T, __COUNTER__>("),
            ("::guardedWrite(", "::guardedWrite<__COUNTER__>("),
        ]
        for old, new in replacements:
            if old not in after:
                raise ValueError("Missing per-site replacement: " + old)
            after = after.replace(old, new)
    if "--inline-guards" in sys.argv[2:]:
        for old in ("T guardedRead(", "void guardedWrite("):
            if after.count(old) != 1:
                raise ValueError("Unexpected guarded wrapper declaration")
            after = after.replace(old, "__attribute__((always_inline)) " + old)
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
        "acceptedForRelease": False, "guardBodiesUnchanged": True,
        "inlineGuards": "--inline-guards" in sys.argv[2:],
        "siteTags": "--site-tags" in sys.argv[2:],
        "originalHeader": str(original),
        "originalSha256": hashlib.sha256(original.read_bytes()).hexdigest(),
        "candidateSha256": hashlib.sha256(header.read_bytes()).hexdigest(),
    }, indent=2))


if __name__ == "__main__":
    main()
