"""Compile real stream adapter and exercise exact-source/fake-device API tests."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[3]
SOURCE_SHA256 = "2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc"
HEADER_SHA256 = "5181a1e739762e32cb851ee4dfecd8b51e4861290c38c312c188284677c58bcb"
FUNCTIONS = (
    "void TrackAudioBuffer(AudioBuffer *buffer)",
    "void UntrackAudioBuffer(AudioBuffer *buffer)",
    "void UnloadAudioBuffer(AudioBuffer *buffer)",
    "AudioStream LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels)",
    "bool IsAudioStreamValid(AudioStream stream)",
    "void SetAudioStreamBufferSizeDefault(int size)",
    "void SetAudioStreamCallback(AudioStream stream, AudioCallback callback)",
    "void PlayAudioStream(AudioStream stream)",
    "void StopAudioStream(AudioStream stream)",
    "void UnloadAudioStream(AudioStream stream)",
    "static ma_uint32 ReadAudioBufferFramesInMixingFormat(AudioBuffer *audioBuffer, float *framesOut, ma_uint32 frameCount)",
)


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def function(source, signature):
    start = source.index(signature + "\n{")
    opening = source.index("{", start)
    depth = 0
    for index in range(opening, len(source)):
        depth += (source[index] == "{") - (source[index] == "}")
        if depth == 0:
            return source[start:index + 1]
    raise ValueError("Unterminated reviewed function")


def run(command, env):
    result = subprocess.run([str(x) for x in command], capture_output=True, text=True,
                            env=env, timeout=120)
    if result.returncode:
        raise RuntimeError(f"{command}\nexit={result.returncode}\n{result.stdout}\n{result.stderr}")
    return result.stdout.strip()


def verify(compilers, output):
    raylib = ROOT / "third_party/PS2Recomp/out/build/_deps/raylib-src/src"
    assert sha(raylib / "raudio.c") == SOURCE_SHA256, "Unreviewed raudio.c"
    assert sha(raylib / "raylib.h") == HEADER_SHA256, "Unreviewed raylib.h"
    source = (raylib / "raudio.c").read_text(encoding="utf-8")
    sending = function(source, "static void OnSendAudioDataToDevice(ma_device *pDevice, void *pFramesOut, const void *pFramesInput, ma_uint32 frameCount)")
    assert sending.index("ma_mutex_lock(&AUDIO.System.lock)") < sending.index("ReadAudioBufferFramesInMixingFormat(") < sending.index("ma_mutex_unlock(&AUDIO.System.lock)")
    internal = function(source, "static ma_uint32 ReadAudioBufferFramesInInternalFormat(AudioBuffer *audioBuffer, void *framesOut, ma_uint32 frameCount)")
    assert "audioBuffer->callback(framesOut, frameCount);" in internal
    extracted = {signature: function(source, signature) for signature in FUNCTIONS}
    (output / "qualified_raudio.inc").write_text(
        "// Generated from hash-qualified raylib; original upstream license applies.\n" +
        "\n\n".join(extracted.values()) + "\n", encoding="utf-8")
    adapter = ROOT / "runtime/audio/native_stream_provider.cpp"
    owner = ROOT / "game/native/audio_output/audio_output_owner.cpp"
    test = Path(__file__).with_name("test_provider.cpp")
    receipt = {"raylibRevision": "c1ab645ca298a2801097931d1079b10ff7eb9df8",
               "raudioSha256": SOURCE_SHA256, "raylibHeaderSha256": HEADER_SHA256,
               "extractedFunctions": {signature: hashlib.sha256(body.encode()).hexdigest()
                                      for signature, body in extracted.items()},
               "sources": {str(path.relative_to(ROOT)): sha(path) for path in (
                   adapter, adapter.with_suffix(".h"), owner, owner.with_suffix(".h"), test)},
               "compilers": []}
    for index, compiler in enumerate(compilers):
        folder = output / str(index)
        folder.mkdir(exist_ok=True)
        env = dict(os.environ)
        env["PATH"] = str(compiler.parent) + os.pathsep + env.get("PATH", "")
        common = [compiler, "-std=c++20", "-O2", "-Wall", "-Wextra", "-Werror", "-pthread",
                  "-I", ROOT, "-I", raylib]
        obj = folder / "native_stream_provider.o"
        object_command = [*common, "-c", adapter, "-o", obj]
        run(object_command, env)
        executable = folder / "test_provider.exe"
        link_command = [*common, "-Wno-missing-field-initializers", "-I", output,
                        obj, owner, test, "-o", executable]
        run(link_command, env)
        results = {mode: run([executable, mode], env)
                   for mode in ("lifecycle", "headless", "bounds", "selfjoin", "reservation")}
        receipt["compilers"].append({"compiler": str(compiler),
            "version": run([compiler, "--version"], env).splitlines()[0],
            "objectCommand": [str(x) for x in object_command], "objectSha256": sha(obj),
            "testCommand": [str(x) for x in link_command], "results": results})
    (output / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
    print(json.dumps(receipt, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--compiler", type=Path, action="append", required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    verify(args.compiler, args.output)
