"""Compare the native World observation frame against complete owned bodies."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

from audit_retail_effect_descriptors import compare_source, elf_reader
from comparison_objects import compile_objects
from gameplay_update_sources import UPDATE_UNITS
from generate_ai_observation_frame_policy import generated
from verify_gameplay_collision import COMPILERS


ROOT = Path(__file__).resolve().parents[2]
IMAGES = (
    (
        "build-function-index/owned-overlays/o9.bin", "recomp/config/output_ovl/o9", 0x810000,
        "604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343",
        (
            0x812540, 0x813BD0, 0x812EF0, 0x8130D0, 0x813380, 0x81A6E0, 0x81A6F0,
            0x812460, 0x813330, 0x8133D0, 0x813DE0, 0x814B30, 0x815820,
            0x81A720, 0x81A770, 0x81A780, 0x81BB80, 0x825CC0, 0x823190, 0x817140,
        ),
    ),
    (
        "build-function-index/owned-overlays/o2.bin", "recomp/config/output_ovl/o2", 0x570000,
        "45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226", (0x5F2210,),
    ),
    (
        "game_data/SLUS_207.65", "recomp/config/output", None,
        "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46",
        (0x107AB0, 0x1AEC80),
    ),
)
FIXTURE = "tools/native_reconstruction/ai_observation_frame_tests.cpp"
REFERENCE = "tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp"
CONVERSION = "third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h"
INCLUDES = re.compile(r'#include "([^"\n]+)"')


def digest(data):
    return hashlib.sha256(data).hexdigest()


def image_reader(raw, base):
    if base is None:
        return elf_reader(raw)

    def read(address, size):
        offset = address - base
        return raw[offset:offset + size]

    return read


def original_bodies():
    entries, audits, images = {}, [], {}
    for image, directory, base, expected, addresses in IMAGES:
        raw = (ROOT / image).read_bytes()
        if digest(raw) != expected:
            raise ValueError(f"Unexpected source image: {image}")
        images[image] = raw
        read = image_reader(raw, base)
        for address in addresses:
            path = next((ROOT / directory).glob(f"*_{address:08X}_0x{address:x}.cpp"))
            end = int(re.search(r"// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)", path.read_text())[1], 16)
            name = path.relative_to(ROOT).as_posix()
            entries[address] = name
            audits.append(compare_source("Complete observation-frame body", name, address, end, read))
    return entries, audits, images


def freeze(out, inputs, original_sources):
    closure = set(inputs) | set(original_sources)
    pending = list(inputs)
    while pending:
        path = ROOT / pending.pop()
        for name in INCLUDES.findall(path.read_text(encoding="utf-8")):
            for candidate in (path.parent / name, ROOT / name):
                candidate = candidate.resolve()
                if not candidate.is_relative_to(ROOT) or not candidate.is_file():
                    continue
                relative = candidate.relative_to(ROOT).as_posix()
                if relative not in closure:
                    closure.add(relative)
                    pending.append(relative)
                break
    frozen = {}
    for name in sorted(closure):
        data = (ROOT / name).read_bytes()
        path = out / "source" / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)
        frozen[name] = data
    return frozen


def prepare_reference(out, entries, frozen):
    reference = frozen[REFERENCE].replace(
        b"struct R5900Context {", b"struct R5900Context { std::uint64_t hi{}, lo{};",
    )
    assert reference != frozen[REFERENCE]
    (out / "word_conversion.hpp").write_bytes(frozen[CONVERSION])
    (out / "reference.hpp").write_bytes(reference + b"""
#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))
#define FPU_DIV_S(a,b) ((a)/(b))
#include "word_conversion.hpp"
#define FPU_CVT_W_S(a) Ps2FpuConvertWord(a)
""")
    body = "\n".join(frozen[name].decode() for name in entries.values())
    (out / "original.cpp").write_text(body)
    functions = {address: Path(name).stem for address, name in entries.items()}
    calls = set(re.findall(r"\b((?:sub|o[0-9]+)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram", body))
    declarations = [f"void {name}(std::uint8_t*, R5900Context*, PS2Runtime*);" for name in functions.values()]
    declarations.extend(
        f"inline void {name}(std::uint8_t* m, R5900Context* c, PS2Runtime* r)"
        "{ original_transform_port(m, c, r); }"
        for name in sorted(calls.difference(functions.values()))
    )
    (out / "functions.h").write_text("#pragma once\n" + "\n".join(declarations) + "\n")
    for header in ("ps2_runtime.h", "ps2_runtime_macros.h"):
        (out / header).write_text('#pragma once\n#include "reference.hpp"\n')
    for header in ("o2_functions.h", "o9_functions.h", "ps2_recompiled_functions.h"):
        (out / header).write_text('#pragma once\n#include "functions.h"\n')
    for header in ("ps2_recompiled_stubs.h", "ps2_stubs.h", "ps2_syscalls.h"):
        (out / header).write_text("#pragma once\n")
    (out / "dispatch.inc").write_text("".join(
        f"case {address:#x}: {name}(memory, context, runtime); return;\n"
        for address, name in functions.items()
    ))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--compiler", choices=COMPILERS, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / "build-native-sjuni")
    assert (ROOT / "game/native/gameplay_update/ai_observation_frame_policy.inc").read_text() == generated()
    entries, audits, images = original_bodies()
    out.mkdir(parents=True)
    inputs = [
        FIXTURE, REFERENCE, CONVERSION, *UPDATE_UNITS,
        "tools/native_reconstruction/gameplay_update_sources.py",
        "tools/native_reconstruction/generate_ai_observation_frame_policy.py",
        "tools/native_reconstruction/comparison_objects.py",
        "tools/native_reconstruction/audit_retail_effect_descriptors.py",
        Path(__file__).relative_to(ROOT).as_posix(),
    ]
    frozen = freeze(out, inputs, entries.values())
    prepare_reference(out, entries, frozen)
    image = out / "o9.bin"
    image.write_bytes(images[IMAGES[0][0]])

    compiler = COMPILERS[args.compiler]
    env = dict(os.environ)
    env["PATH"] = str(compiler.parent) + os.pathsep + env.get("PATH", "")
    flags = [
        "-std=c++20", "-O2", "-msse4.1", "-fno-fast-math", "-ffp-contract=off",
        "-Wall", "-Wextra", "-Wpedantic", "-Werror", "-I" + str(out), "-I" + str(out / "source"),
    ]
    receipt = dict(
        schema=1, status="failed", game_launched=False, installed_in_game=False, stage4_complete=False,
        compiler_sha256=digest(compiler.read_bytes()), owned_image_sha256={n: digest(b) for n, b in images.items()},
        source_sha256={n: digest(b) for n, b in frozen.items()}, original_word_audits=audits, commands=[],
        declared_ports=[
            "815BC0 current-node selection in the admitted single-node graph",
            "819BC0 scene scan with an empty scene-record owner",
            "191F80 and 191BC0 finite heading and forward vector via native transform math",
            "579980 room wall probe through the same native trace consumer",
            "107C68 checked eight-byte zero fill",
            "370140 reference-facing heading through qualified native position math",
        ],
    )
    try:
        original = out / "original.o"
        executable = out / "checks.exe"
        commands = [
            ("original", [
                str(compiler), *flags, "-Wno-unused-label", "-Wno-unused-parameter",
                "-Wno-unused-variable", "-c", str(out / "original.cpp"), "-o", str(original),
            ]),
            ("fixture", [
                str(compiler), *flags, "-c", str(out / "source" / FIXTURE), "-o", str(out / "fixture.o"),
            ]),
        ]
        for label, command in commands:
            run(out, label, command, env, receipt)
        objects, _ = compile_objects(ROOT, out, compiler, flags, UPDATE_UNITS, frozen, env)
        run(out, "link", [
            str(compiler), str(out / "fixture.o"), str(original), *objects, "-o", str(executable),
        ], env, receipt)
        receipt["observed"] = json.loads(run(out, "test", [str(executable), str(image)], env, receipt))
        receipt["source_unchanged"] = all((ROOT / name).read_bytes() == data for name, data in frozen.items())
        assert receipt["source_unchanged"]
        receipt["status"] = "passed"
    finally:
        receipt["output_sha256"] = {p.name: digest(p.read_bytes()) for p in out.iterdir() if p.is_file()}
        (out / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
    print(json.dumps(receipt["observed"]))


def run(out, label, command, env, receipt):
    result = subprocess.run(command, capture_output=True, env=env, timeout=180)
    (out / f"{label}.stdout.txt").write_bytes(result.stdout)
    (out / f"{label}.stderr.txt").write_bytes(result.stderr)
    receipt["commands"].append(dict(label=label, exit_code=result.returncode, command=command))
    if result.returncode:
        raise RuntimeError(f"{label} failed. See {out / (label + '.stderr.txt')}")
    return result.stdout


if __name__ == "__main__":
    main()
