"""Observe unchanged qualified124 PCM and real bank playback together.

Synthetic wire inputs only; no native candidate is read or linked. Device and
runtime registration surroundings are explicit refusing mocks. Full original
CriAudio.cpp and ReoSoundBanks.cpp supply every playback observation.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess

import bank_session_oracle as bank

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).with_suffix("")
BASE_RECEIPT = "944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb"
LIB = "ps2xRuntime/src/lib/"
HELPERS = LIB + "Kernel/Syscalls/Helpers/"
FILES = [HELPERS + name for name in (
    "CriAudio.cpp", "CriAudio.h", "CriAudioBackend.h", "CriAudioDispatch.h",
    "ReoSoundBanks.cpp", "ReoSoundBanks.h")]
KINDS = dict(pcm_reset=0, bank=1, packet=2, render=3, gains=4, queue=5,
             configure=6, discard=7, drain=8, release=9, consumed=10, queued=11,
             bank_reset=12, clock=13, ensure=14, shutdown=15, query=16)


def canonical(value):
    return (json.dumps(value, sort_keys=True, separators=(",", ":")) + "\n").encode()


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def float_bits(value):
    return struct.unpack("<I", struct.pack("<f", value))[0]


def action(op, *words, data=b""):
    return dict(op=op, words=list(words), bytes_hex=data.hex())


def transcript():
    assets = [bank.synthetic_bank("loop"), bank.synthetic_bank("changed", seed=7),
              bank.synthetic_bank("one_shot", loop=False),
              bank.synthetic_bank("layers", layers=4)]
    def load(port=2, asset=0): return action("bank", port, asset)
    def packet(*values): return action("packet", data=bytes(values))
    def request(port=2, index=1, group=3): return packet(0, port, index, group, 0)
    def queue(key=1, samples=(32767, -32768, 16384, -8192)):
        return action("queue", key, data=struct.pack("<" + "h"*len(samples), *samples))
    def configure(voice=10, left=1, right=0, channels=1, rate=48000, volume=256, play=1):
        return action("configure", voice, left, right, channels, rate, volume, play)
    def render(frames, null=0): return action("render", frames, null)
    def gains(master=1, stream=1, mode=0):
        return action("gains", float_bits(master), float_bits(stream), mode)
    def clock(ns): return action("clock", ns & 0xffffffff, (ns >> 32) & 0xffffffff)
    def case(name, actions, external=True):
        return dict(name=name, actions=[action("pcm_reset"), action("bank_reset"),
            gains(), *([render(0)] if external else []), *actions])
    long_pcm = tuple(((i*1021) % 65536)-32768 for i in range(1200))
    common = [load(), request(), queue(samples=long_pcm), configure()]
    cases = [
        case("real_mono_bank", [*common, render(1), render(198), render(1), render(201)]),
        case("real_stereo_bank", [load(), request(), queue(1, long_pcm),
            queue(2, tuple(-x if x != -32768 else 32767 for x in long_pcm)),
            configure(right=2, channels=2), render(1), render(200), render(400)]),
        case("bank_gain_order", [*common, gains(.5, 2, 1), render(1), render(199),
            gains(2, .25, 0), render(200)]),
        case("master_clip_before_or_after_bank", [load(asset=3),
            *[request(group=g) for g in range(8)], queue(samples=(32767,)*600),
            configure(volume=512), gains(.5, 4), render(200), gains(4, 4), render(200)]),
        case("bank_mute_keeps_pcm", [*common, packet(0x41, 1), render(100),
            packet(0x41, 0), render(101)]),
        case("bank_mono_port_volume", [*common, packet(0x42, 1, 0x4C, 2, 1, 128),
            render(200), packet(0x42, 0), render(200)]),
        case("pcm_pause_keeps_bank", [*common, render(1), configure(play=0),
            render(199), configure(), render(201)]),
        case("drain_reconfigure", [*common, render(3), action("drain", 10),
            configure(play=0), render(199), action("queued", 1), action("consumed", 1)]),
        case("pcm_reset_retains_bank", [*common, render(12), action("pcm_reset"),
            render(0), render(188), action("query", 2, 1, 3)]),
        case("bank_reset_retains_pcm", [*common, render(12), action("bank_reset"),
            render(188), action("consumed", 1), action("queued", 1)]),
        case("release_discard", [*common, configure(voice=11), render(1),
            action("release", 10), render(3), action("discard", 1), render(200)]),
        case("bank_cancel_replace", [*common, render(20), packet(8, 2, 1, 3),
            render(64), load(asset=1), request(group=5), render(200)]),
        case("half_rate", [load(), request(), queue(), configure(rate=24000), render(8)]),
        case("44100_phase", [load(), request(), queue(samples=long_pcm),
            configure(rate=44100), render(137), render(200), action("consumed", 1)]),
        case("missing_right_and_catchup", [load(), request(), queue(),
            configure(right=2, channels=2), render(3), queue(2, (1000, 2000, 3000, 4000)),
            render(3), queue(1, (1,2,3,4,5,6)), render(2)]),
        case("shared_channel_voices", [load(), request(), queue(samples=long_pcm),
            configure(voice=10, volume=128), configure(voice=11, volume=512), render(200)]),
        case("all_bank_ports_pcm", [*[load(port=p) for p in range(14)],
            *[request(port=p, index=p%8, group=p) for p in range(14)],
            queue(samples=long_pcm), configure(), gains(.25, .5, 1), render(1), render(200)]),
        case("null_render_progress", [*common, render(200, 1), render(1),
            action("consumed", 1)]),
        case("headless_does_not_tick_bank", [*common, clock(10000000),
            action("consumed", 1), action("query", 2, 1, 3), clock(250000000),
            action("consumed", 1), render(1)], external=False),
        case("ensure_without_device", [*common, action("ensure"), clock(10000000),
            action("ensure"), action("consumed", 1), render(1)], external=False),
        case("shutdown_both", [*common, render(7), action("shutdown")]),
    ]
    return dict(schema=1, purpose="original124 real PCM plus real bank composition",
                assets=assets, cases=cases, kinds=KINDS)


def encode(value, case):
    out = bytearray(b"AAGO1\0\0\0")
    def word(v): out.extend(struct.pack("<I", v))
    def blob(v): word(len(v)); out.extend(v)
    word(len(value["assets"]))
    for asset in value["assets"]:
        for key in ("hd_hex", "bd_hex", "tq_hex"): blob(bytes.fromhex(asset[key]))
    blob(case["name"].encode()); word(len(case["actions"]))
    for item in case["actions"]:
        word(KINDS[item["op"]]); word(len(item["words"]))
        for v in item["words"]: word(v)
        blob(bytes.fromhex(item["bytes_hex"]))
    return bytes(out)


def frozen_write(path, data):
    if path.exists() and path.read_bytes() != data:
        raise ValueError("Frozen cohort differs; use a new output: " + str(path))
    path.write_bytes(data)


def run(command, env):
    result = subprocess.run([str(x) for x in command], capture_output=True,
                            text=True, env=env, timeout=180)
    if result.returncode:
        raise RuntimeError(f"{command}\n{result.returncode}\n{result.stdout}\n{result.stderr}")
    return result


def generate(args):
    checkout, output = args.checkout.resolve(), args.output.resolve()
    receipt_path = args.baseline_receipt.resolve()
    if sha(receipt_path) != BASE_RECEIPT: raise ValueError("Unqualified124 receipt")
    receipt = json.loads(receipt_path.read_bytes())
    if receipt["status"] != "passed" or receipt["applied_count"] != 124:
        raise ValueError("Wrong dependency cohort")
    source_hashes = {name: receipt["source_sha256"][name] for name in FILES}
    for name, digest in source_hashes.items():
        if sha(checkout/name) != digest: raise ValueError("Dependency changed: " + name)
    if source_hashes[bank.SOURCE] != bank.SOURCE_SHA: raise ValueError("Bank identity changed")
    output.mkdir(parents=True, exist_ok=True)
    value = transcript()
    inputs = {"input.json":canonical(value)}
    inputs.update({f"case-{i:02}.bin":encode(value, c) for i,c in enumerate(value["cases"])})
    for name in ("harness.cpp", "ps2_runtime.h", "ps2_host_backend.h", "vblank_music_diag.h"):
        inputs[name] = (HERE/name).read_bytes()
    for name,data in inputs.items(): frozen_write(output/name, data)
    manifest = dict(schema=1, kind="authored inputs, no expected playback",
        source_sha256=source_hashes, input_sha256={n:sha(output/n) for n in inputs},
        cases=len(value["cases"]), actions=sum(len(c["actions"]) for c in value["cases"]))
    frozen_write(output/"input-manifest.json", canonical(manifest))
    if args.freeze_only: return manifest
    snapshot = output/"source"; helpers = snapshot/"Kernel/Syscalls/Helpers"
    helpers.mkdir(parents=True,exist_ok=True)
    for name in FILES: shutil.copyfile(checkout/name, helpers/Path(name).name)
    shutil.copyfile(output/"vblank_music_diag.h", snapshot/"vblank_music_diag.h")
    results = dict(schema=1, status="passed", source_sha256=source_hashes,
        receipt_sha256=BASE_RECEIPT, input_manifest_sha256=sha(output/"input-manifest.json"),
        generator_sha256=sha(Path(__file__)), candidate_read=False, device_opened=False,
        game_run=False, compilers=[])
    for i, compiler in enumerate(args.compiler):
        compiler = compiler.resolve(); folder = output/str(i); folder.mkdir(exist_ok=True)
        env = dict(os.environ); env["PATH"] = str(compiler.parent)+os.pathsep+env.get("PATH", "")
        for name in ("REO_AUDIO_PATH_LOG", "REO_CRI_SYNC_LOG"): env.pop(name,None)
        exe = folder/"source-aggregate.exe"
        command = [compiler, "-std=c++20", "-O2", "-pthread", "-Wall", "-Wextra", "-Werror",
            "-Wno-misleading-indentation", "-fno-fast-math", "-ffp-contract=off",
            "-Wl,--no-insert-timestamp",
            "-I"+str(output), output/"harness.cpp", "-o", exe]
        run(command, env)
        observations = []
        for j,case in enumerate(value["cases"]):
            result = run([exe, output/f"case-{j:02}.bin"], env)
            observed = json.loads(result.stdout)
            if observed["name"] != case["name"] or len(observed["actions"]) != len(case["actions"]):
                raise ValueError("Incomplete original observation")
            observations.append(observed)
        expected = folder/"expected.json"; frozen_write(expected,canonical(observations))
        results["compilers"].append(dict(compiler=str(compiler), compiler_sha256=sha(compiler),
            compiler_version=run([compiler,"--version"],env).stdout.splitlines()[0],
            command=[str(x) for x in command], binary_sha256=sha(exe),
            expected_sha256=sha(expected), expected=str(expected)))
    if len(args.compiler)==2:
        results["cross_compiler_exact_equal"] = ((output/"0/expected.json").read_bytes()==
                                                 (output/"1/expected.json").read_bytes())
    for name,digest in source_hashes.items():
        if sha(helpers/Path(name).name)!=digest or sha(checkout/name)!=digest:
            raise ValueError("Original source changed during execution")
    frozen_write(output/"receipt.json", canonical(results))
    return dict(receipt=str(output/"receipt.json"), cases=manifest["cases"],
                actions=manifest["actions"], cross_compiler_exact_equal=results.get("cross_compiler_exact_equal"))


if __name__ == "__main__":
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--checkout",type=Path,required=True)
    p.add_argument("--baseline-receipt",type=Path,required=True)
    p.add_argument("--output",type=Path,required=True)
    p.add_argument("--compiler",type=Path,action="append",default=[])
    p.add_argument("--freeze-only",action="store_true")
    args=p.parse_args()
    if not args.output.resolve().is_relative_to(ROOT/"build-native-sjuni"):
        p.error("Use a private ignored output subdirectory")
    if not args.freeze_only and not args.compiler: p.error("Existing compiler required")
    print(json.dumps(generate(args),indent=2))
