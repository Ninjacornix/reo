"""Qualify binding against reconstructed124 headers and fake runtime/audio dispatch."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
BASELINE_SHA = "944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb"
HELPERS = "ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/"
ELF_SHA = "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46"
WINDOWS = ((0x1392f8, 0x40, "48af9491776a966a35a3dd46ed6122d2aa237c85f2a1967c38f204a488517be8"),
           (0x135078, 0xf8, "a6ac3b23bfac0c9862d0facae8e02be99f08a69e6e20cb2dda05a10ffd3813bd"))


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def block(source, start):
    begin = source.index(start)
    opening = source.index("{", begin)
    depth = 0
    for end in range(opening, len(source)):
        depth += (source[end] == "{") - (source[end] == "}")
        if depth == 0:
            return source[begin:end + 1]
    raise ValueError("Unterminated reviewed source block")


def run(command, env):
    result = subprocess.run([str(x) for x in command], env=env, capture_output=True,
                            text=True, timeout=180)
    if result.returncode:
        raise RuntimeError(f"{command}\nexit={result.returncode}\n{result.stdout}\n{result.stderr}")
    return result


def verify(checkout, baseline, compilers, output):
    assert sha(baseline) == BASELINE_SHA, "Unreviewed124 reconstruction receipt"
    qualification = json.loads(baseline.read_text())
    assert qualification["status"] == "passed" and qualification["applied_count"] == 124
    names = [HELPERS + name for name in ("CriAudio.cpp", "CriAudio.h", "CriAudioBackend.h",
                                         "CriAudioDispatch.h", "ReoSoundBanks.h")]
    names += ["ps2xRuntime/include/ps2_runtime.h", "ps2xRuntime/include/runtime/ps2_memory.h"]
    names += ["ps2xRuntime/src/lib/ps2_runtime.cpp", "ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp"]
    for name in names:
        assert sha(checkout / name) == qualification["source_sha256"][name], name
    elf = ROOT / "game_data/SLUS_207.65"
    assert sha(elf) == ELF_SHA
    data = elf.read_bytes()
    header = struct.unpack_from("<HHIIIIIHHHHHH", data, 16)
    sections = [struct.unpack_from("<10I", data, header[5] + n * header[10])
                for n in range(header[11])]
    fixture = bytearray()
    for address, size, expected in WINDOWS:
        for section in sections:
            if section[1] == 1 and section[2] & 2 and section[3] <= address and address + size <= section[3] + section[5]:
                start = section[4] + address - section[3]
                chunk = data[start:start + size]
                assert hashlib.sha256(chunk).hexdigest() == expected
                fixture.extend(chunk)
                break
        else:
            raise ValueError("Identity window is not allocated/file-backed")
    identity = output / "owned_identity.bin"
    identity.write_bytes(fixture)
    snapshot = output / "snapshot"
    helpers = snapshot / "Kernel/Syscalls/Helpers"
    helpers.mkdir(parents=True, exist_ok=True)
    runtime_header = (checkout / "ps2xRuntime/include/ps2_runtime.h").read_text()
    runtime_source = (checkout / "ps2xRuntime/src/lib/ps2_runtime.cpp").read_text()
    rpc = (checkout / "ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp").read_text()
    exact = {
        "exact_layout.inc": block(runtime_header, "struct PS2DtxCompatLayout") + ";\n",
        "exact_lease.inc": block(runtime_header, "    class PreRunSetupLease final") + ";\n",
        "exact_runtime_methods.inc": "\n\n".join(block(runtime_source, signature) for signature in (
            "PS2Runtime::PreRunSetupLease::PreRunSetupLease(PreRunSetupLease&& other) noexcept",
            "PS2Runtime::PreRunSetupLease::~PreRunSetupLease()",
            "PS2Runtime::PreRunSetupLease PS2Runtime::acquirePreRunSetup() noexcept",
            "void PS2Runtime::releasePreRunSetup() noexcept", "bool PS2Runtime::externalWorkerResetAllowed()",
            "void PS2Runtime::beginExternalWorkerRun()")) + "\n",
        "exact_rpc_methods.inc": "\n\n".join(block(rpc, signature) for signature in (
            "        void resetDtxRpcStateUnlocked(PS2Runtime *runtime = nullptr)",
            "    PS2DtxCompatLayout dtxCompatLayoutSnapshot()",
            "    void setDtxCompatLayout(const PS2DtxCompatLayout &layout, PS2Runtime *runtime)",
            "    void clearDtxCompatLayout(PS2Runtime *runtime)")) + "\n",
    }
    for name, contents in exact.items():
        (snapshot / name).write_text(contents, encoding="utf-8", newline="\n")
    for name in ("CriAudio.cpp", "CriAudio.h", "CriAudioBackend.h", "CriAudioDispatch.h", "ReoSoundBanks.h"):
        shutil.copyfile(checkout / HELPERS / name, helpers / name)
    shutil.copyfile(HERE / "ps2_runtime.h", snapshot / "ps2_runtime.h")
    shutil.copyfile(checkout / "ps2xRuntime/src/lib/cri_pcm_retire.h", snapshot / "cri_pcm_retire.h")
    (snapshot / "ps2_host_backend.h").write_text('#pragma once\n#include "raylib.h"\n')
    (snapshot / "vblank_music_diag.h").write_text(
        "#pragma once\nnamespace ps2_vblank_music_diag { enum class Kind {AudioReport,PcmPush,Voice,SjxPoll,PcmRetire,SjxPublished}; template<class... T> void note(Kind,T...){} }\n")
    authored = [ROOT / name for name in (
        "game/native/pcm/pcm.cpp", "game/native/pcm_bridge/session_bridge.cpp",
        "game/native/audio_output/audio_output_owner.cpp", "runtime/audio/native_stream_provider.cpp",
        "recomp/overrides/native_pcm/runtime_adapter.cpp")]
    raylib = ROOT / "third_party/PS2Recomp/out/build/_deps/raylib-src/src"
    assert sha(raylib / "raylib.h") == "5181a1e739762e32cb851ee4dfecd8b51e4861290c38c312c188284677c58bcb"
    assert sha(raylib / "raudio.c") == "2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc"
    authored_inputs = [*authored, *[path.with_suffix(".h") for path in authored[2:]],
        ROOT / "game/native/pcm/pcm.hpp", ROOT / "game/native/pcm_bridge/session_bridge.hpp",
        ROOT / "recomp/overrides/native_geometry/reo_vu_native_sha256.h",
        HERE / "ps2_runtime.h", HERE / "fake_audio.h", HERE / "fake_audio.cpp", HERE / "harness.cpp", Path(__file__)]
    result = {"dependencyReceiptSha256": sha(baseline), "appliedCount": 124,
        "extractedInputs": {name: sha(snapshot / name) for name in exact},
        "dependencyInputs": {name: sha(checkout / name) for name in names},
        "elfSha256": ELF_SHA, "identityWindows": WINDOWS,
        "authoredInputs": {str(path.relative_to(ROOT)): sha(path) for path in authored_inputs},
        "raylibHeaderSha256": sha(raylib / "raylib.h"), "compilers": []}
    for index, compiler in enumerate(compilers):
        folder = output / str(index)
        folder.mkdir(exist_ok=True)
        env = dict(os.environ)
        env["PATH"] = str(compiler.parent) + os.pathsep + env.get("PATH", "")
        for name in list(env):
            if name.startswith(("REO_CRI_", "REO_AUDIO_PATH", "REO_RNA_STOP")):
                env.pop(name)
        common = [compiler, "-std=c++20", "-O2", "-Wall", "-Wextra", "-Werror",
                  "-msse4.1", "-fno-fast-math", "-ffp-contract=off", "-pthread", "-I", ROOT, "-I", raylib]
        object_command = [*common, "-I", checkout / "ps2xRuntime/include", "-I", checkout / "ps2xRuntime/src/lib",
                          "-c", authored[-1], "-o", folder / "runtime_adapter-real.o"]
        run(object_command, env)
        executable = folder / "backend.exe"
        test_command = [*common, "-I", snapshot, *authored, helpers / "CriAudio.cpp",
                        HERE / "fake_audio.cpp", HERE / "harness.cpp", "-o", executable]
        run(test_command, env)
        cases = {}
        env["REO_NATIVE_PCM"] = "1"
        for mode in ("lifecycle", "boot_setup", "headless", "producer", "callback", "capacity", "startup",
                     "alias", "outside", "huge", "gain", "install", "identity", "ram64", "boot_reset"):
            executed = run([executable, mode, identity], env)
            cases[mode] = {"stdout": executed.stdout.strip(), "stderr": executed.stderr.strip()}
            reports = [line for line in executed.stderr.splitlines() if line.startswith("[NATIVE-PCM-REPORT]")]
            if mode not in ("identity", "ram64", "boot_reset"):
                assert len(reports) == 1, "Expected one successful joined report"
            if mode in ("lifecycle", "boot_setup"):
                completed = reports[0].split("method_completed=")[1].split()[0]
                assert all(int(value) > 0 for value in completed.split(",")), "All eleven methods must complete"
        for value in ("", "0", "true", "01", "1 "):
            env["REO_NATIVE_PCM"] = value
            executed = run([executable, "disabled", identity], env)
            cases[f"disabled:{value!r}"] = {"stdout": executed.stdout.strip(), "stderr": executed.stderr.strip()}
        result["compilers"].append({"compiler": str(compiler),
            "version": run([compiler, "--version"], env).stdout.splitlines()[0],
            "realHeaderObjectCommand": [str(x) for x in object_command],
            "realHeaderObjectSha256": sha(folder / "runtime_adapter-real.o"),
            "testCommand": [str(x) for x in test_command], "cases": cases})
    (output / "receipt.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({"receipt": str(output / "receipt.json"),
                      "compilers": [{"version": c["version"], "cases": len(c["cases"])}
                                    for c in result["compilers"]]}, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--checkout", type=Path, required=True)
    parser.add_argument("--baseline-receipt", type=Path, required=True)
    parser.add_argument("--compiler", type=Path, action="append", required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    verify(args.checkout, args.baseline_receipt, args.compiler, args.output)
