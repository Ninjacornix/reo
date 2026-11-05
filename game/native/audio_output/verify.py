"""Build/run only the isolated fake-provider owner tests; never open audio/game."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess


def run(command, env=None):
    result = subprocess.run([str(x) for x in command], env=env, capture_output=True,
                            text=True, timeout=120)
    if result.returncode:
        raise RuntimeError(f"{command}\n{result.returncode}\n{result.stdout}\n{result.stderr}")
    return result.stdout.strip()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--compiler", type=Path, action="append", required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    source = Path(__file__).resolve().parent
    receipt = {"sources": {}, "results": []}
    for name in ("audio_output_owner.h", "audio_output_owner.cpp", "test_audio_output_owner.cpp"):
        receipt["sources"][name] = hashlib.sha256((source / name).read_bytes()).hexdigest()
    for index, compiler in enumerate(args.compiler):
        executable = args.output / f"owner-{index}.exe"
        command = [compiler, "-std=c++20", "-O2", "-Wall", "-Wextra", "-Werror", "-pthread",
                   source / "audio_output_owner.cpp", source / "test_audio_output_owner.cpp",
                   "-o", executable]
        env = dict(os.environ)
        env["PATH"] = str(compiler.parent) + os.pathsep + env.get("PATH", "")
        run(command, env)
        receipt["results"].append({"compiler": str(compiler),
            "version": run([compiler, "--version"], env).splitlines()[0],
            "command": [str(x) for x in command], "result": run([executable], env)})
    (args.output / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
    print(json.dumps(receipt, indent=2))
