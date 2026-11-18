"""Qualify pinned provider close fix without opening a device or running the game."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools/local_build"))
from prepare_audio_output import instrument

RAUDIO = "2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc"
MINIAUDIO = "7cc33503a3b8ea3ecd6e4a0c337f7a07e1058dd69623b38ddd0daccab347c406"
PATCH = ROOT / "third_party/patches/raylib/0000-stop-device-before-audio-mutex-uninit.patch"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def close_body(source):
    begin = source.index("void CloseAudioDevice(void)\n{")
    end = source.index("\n}", begin) + 2
    return source[begin:end]


def run(command, env=None):
    result = subprocess.run([str(x) for x in command], capture_output=True, text=True,
                            timeout=180, env=env)
    if result.returncode:
        raise RuntimeError(f"{command}\nexit={result.returncode}\n{result.stdout}\n{result.stderr}")
    return result.stdout.strip()


def verify(compilers, output):
    provider = ROOT / "third_party/PS2Recomp/out/build/_deps/raylib-src/src/raudio.c"
    mini = provider.parent / "external/miniaudio.h"
    assert sha(provider) == RAUDIO, "Unreviewed raylib source"
    assert sha(mini) == MINIAUDIO, "Unreviewed miniaudio source"
    source = provider.read_text(encoding="utf-8")
    transformed = instrument(source)
    old, new = close_body(source), close_body(transformed)
    # The committed transform must match the dependency patch's close-only edit.
    with tempfile.TemporaryDirectory(prefix="patch-check-", dir=output) as temporary:
        root = Path(temporary)
        (root / "src").mkdir()
        (root / "src/raudio.c").write_bytes(provider.read_bytes())
        run(["git", "-C", root, "apply", "--check", PATCH])
        run(["git", "-C", root, "apply", PATCH])
        patched = (root / "src/raudio.c").read_text(encoding="utf-8")
        assert close_body(patched) == new
        assert source.replace(old, new) == patched, "Patch changed more than close order"
    # The declaration may precede the definition; qualify against last occurrence.
    callback = source[source.rindex("static void OnSendAudioDataToDevice("):]
    assert callback.index("ma_mutex_lock(&AUDIO.System.lock)") < callback.index("for (AudioBuffer *audioBuffer")
    template = Path(__file__).with_name("mock_close.cpp.in").read_text()
    staged = output / "reo_audio_output.c"
    staged.write_text(transformed, encoding="utf-8")
    receipt = {"raylibRevision": "c1ab645ca298a2801097931d1079b10ff7eb9df8",
               "raudioSha256": RAUDIO, "miniaudioSha256": MINIAUDIO,
               "patchSha256": sha(PATCH), "transformedSha256": sha(staged),
               "patchReproduced": True, "compilers": []}
    for index, compiler in enumerate(compilers):
        folder = output / str(index)
        folder.mkdir(exist_ok=True)
        env = dict(os.environ)
        env["PATH"] = str(compiler.parent) + os.pathsep + env.get("PATH", "")
        item = {"compiler": str(compiler), "version": run([compiler, "--version"]).splitlines()[0], "mock": {}}
        for label, body, safe in (("original", old, 0), ("patched", new, 1)):
            cpp = folder / f"{label}.cpp"
            cpp.write_text(template.replace("/* EXTRACTED_CLOSE */", body))
            executable = folder / f"{label}.exe"
            command = [compiler, "-std=c++17", "-O2", "-pthread", f"-DEXPECT_SAFE={safe}", cpp, "-o", executable]
            run(command, env)
            item["mock"][label] = run([executable], env)
        command = [compiler, "-x", "c", "-std=c11", "-O2", "-DNDEBUG", "-DWIN32", "-D_WINDOWS",
                   "-DMA_DEFAULT_PERIOD_SIZE_IN_MILLISECONDS_LOW_LATENCY=5", "-DMA_DEFAULT_PERIODS=2",
                   "-I", ROOT, "-I", provider.parent, "-c", staged, "-o", folder / "provider.o"]
        run(command, env)
        item["providerObjectSha256"] = sha(folder / "provider.o")
        item["providerCommand"] = [str(x) for x in command]
        receipt["compilers"].append(item)
    (output / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
    print(json.dumps(receipt, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--compiler", action="append", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    verify(args.compiler, args.output)
