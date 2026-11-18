"""Compare complete 5D7D60/5BE980 against the current canonical application."""
import argparse
import hashlib
import json
import os
import re
import subprocess
import time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS

ROOT = Path(__file__).resolve().parents[2]
FIXTURE = "tools/native_reconstruction/scene_reset_tests.cpp"
REFERENCE = "tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp"
EXPECTED_COMPILER = "f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3"


def sha(path):
    with Path(path).open("rb") as source:
        return hashlib.file_digest(source, "sha256").hexdigest()


def native_sources():
    return {p.relative_to(ROOT).as_posix(): sha(p)
            for p in sorted((ROOT / "game/native").rglob("*"))
            if p.is_file() and p.suffix in (".cpp", ".hpp", ".h", ".inc", ".txt")}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--compiler", choices=["llvm"], required=True)
    parser.add_argument("--native-build", type=Path, required=True)
    parser.add_argument("--build-receipt", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    out, build = args.output.resolve(), args.native_build.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / "build-native-sjuni")
    compiler = COMPILERS[args.compiler]
    cohort = json.loads(args.build_receipt.read_text())
    before = native_sources()
    assert cohort["status"] == "passed"
    assert sha(compiler) == cohort["compiler_sha256"] == EXPECTED_COMPILER
    assert before == cohort["sources_sha256"], "Native source/header identity mismatch"
    ninja = (build / "build.ninja").read_text().splitlines()
    at = next(i for i, line in enumerate(ninja)
              if line.startswith("build gameplay_application/session_resources_tests.exe:"))
    words = next(line.split("=", 1)[1].split() for line in ninja[at+1:at+8]
                 if line.lstrip().startswith("LINK_LIBRARIES ="))
    archives = {name: sha(build / name) for name in words if name.endswith(".a")}
    assert all(cohort["archives_sha256"].get(n) == h for n, h in archives.items())
    libraries = [str(build / name) if name.endswith(".a") else name for name in words]
    resource_command = next(x["command"] for x in cohort["commands"]
                            if x["label"] == "session-resources")
    archive = Path(resource_command[1])
    archive_hash = sha(archive)
    assert cohort["input_sha256"][str(archive.resolve())] == archive_hash
    owned = [FIXTURE, REFERENCE, Path(__file__).relative_to(ROOT).as_posix()]
    frozen = {name: (ROOT / name).read_bytes() for name in owned}
    overlay = ROOT / "build-function-index/owned-overlays/o2.bin"
    assert sha(overlay) == "45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226"
    bank, entries, proof = overlay.read_bytes(), {}, []
    for address in (0x5d7d60, 0x5be980):
        path = next((ROOT / "recomp/config/output_ovl/o2").glob(f"o2_{address:08X}_*"))
        name, body = path.relative_to(ROOT).as_posix(), path.read_bytes()
        end = int(re.search(r"// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)", body.decode())[1], 16)
        proof.append(compare_source("complete model scene and room camera reset", name, address, end,
                                    lambda at, n: bank[at-0x570000:at-0x570000+n]))
        entries[address], frozen[name] = name, body
    out.mkdir(parents=True)
    for name, body in frozen.items():
        target = out / "source" / name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(body)
    (out / "reference.hpp").write_bytes(frozen[REFERENCE])
    body = "\n".join(frozen[name].decode() for name in entries.values())
    actual = {Path(name).stem for name in entries.values()}
    called = set(re.findall(r"\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram", body))
    declarations = "".join("void " + name + "(std::uint8_t*,R5900Context*,PS2Runtime*);\n" for name in sorted(actual))
    declarations += "".join("inline void " + name + "(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n"
                            for name in sorted(called - actual))
    (out / "functions.h").write_text("#pragma once\n" + declarations)
    (out / "original.cpp").write_text(body)
    (out / "original_dispatch.hpp").write_text("".join("case " + hex(address) + ":" + Path(name).stem + "(memory,context,runtime);return;\n"
                                                       for address, name in entries.items()))
    for name in ("ps2_runtime.h", "ps2_runtime_macros.h"):
        (out / name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out / "o2_functions.h").write_text('#pragma once\n#include "functions.h"\n')
    for name in ("ps2_recompiled_stubs.h", "ps2_syscalls.h", "ps2_stubs.h"):
        (out / name).write_text("#pragma once\n")
    env = dict(os.environ, PATH=str(compiler.parent) + os.pathsep + os.environ.get("PATH", ""))
    executable = out / "checks.exe"
    flags = ["-std=c++20", "-O2", "-msse4.1", "-Wall", "-Wextra", "-Wpedantic", "-Werror",
             "-Wno-unused-label", "-Wno-unused-parameter", "-Wno-unused-variable", "-fno-fast-math", "-ffp-contract=off",
             "-I" + str(out), "-I" + str(ROOT)]
    command = [str(compiler), *flags, str(out / "source" / FIXTURE), str(out / "original.cpp"),
               "-Wl,--start-group", *libraries, "-Wl,--end-group", "-o", str(executable)]
    receipt = dict(schema=2, status="failed", compiler_sha256=sha(compiler),
                   sources_sha256=before, archives_sha256=archives, archive_sha256=archive_hash,
                   oracle_sources_sha256={n: hashlib.sha256(b).hexdigest() for n, b in frozen.items()},
                   build_receipt_sha256=sha(args.build_receipt), original_owned_bodies=proof,
                   commands=[], game_run=False, stage4_complete=False,
                   limits=["Complete represented scene reset and shared script/camera fields; no ordinary room camera selection or scene-entry completion.",
                           "Original 107C68 uses an explicit bounded memory primitive; no original runtime or addressed gameplay memory enters production."])
    def run(label, invocation):
        start = time.monotonic()
        result = subprocess.run(invocation, env=env, capture_output=True, timeout=240)
        (out / (label + ".stdout.txt")).write_bytes(result.stdout)
        (out / (label + ".stderr.txt")).write_bytes(result.stderr)
        receipt["commands"].append(dict(label=label, command=invocation, returncode=result.returncode, seconds=time.monotonic()-start))
        assert result.returncode == 0, label + " failed; see " + str(out / (label + ".stderr.txt"))
        return result.stdout
    try:
        run("compile", command)
        receipt["observed"] = json.loads(run("test", [str(executable), str(archive)]))
        after = native_sources()
        receipt["source_drift"] = [n for n in sorted(set(before) | set(after)) if before.get(n) != after.get(n)]
        receipt["archive_drift"] = [n for n, h in archives.items() if sha(build / n) != h]
        receipt["oracle_source_drift"] = [n for n, b in frozen.items() if (ROOT / n).read_bytes() != b]
        assert not receipt["source_drift"] and not receipt["archive_drift"] and not receipt["oracle_source_drift"]
        assert sha(archive) == archive_hash
        receipt.update(status="passed", executable_sha256=sha(executable))
    finally:
        (out / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
    print(json.dumps({k: receipt[k] for k in ("status", "observed", "source_drift", "archive_drift")}))


if __name__ == "__main__":
    main()
