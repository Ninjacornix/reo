"""Build one handwritten TU with its configured command and retained header receipts.

Run from a VS developer environment. This deliberately bypasses the cached
Ninja dependency result without changing old objects or regenerating game code.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--build-dir", required=True, type=Path)
    parser.add_argument("--source", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    source, output = args.source.resolve(), args.output.resolve()
    if output.exists():
        raise SystemExit(f"Refusing to replace retained object: {output}")
    commands = json.loads((args.build_dir / "compile_commands.json").read_text())
    entry = next(item for item in commands if Path(item["file"]).resolve() == source)
    output.parent.mkdir(parents=True, exist_ok=True)
    command = re.sub(r'/Fo(?:"[^"]+"|\S+)', lambda _: '/Fo"' + str(output) + '"', entry["command"])
    command = re.sub(r'/Fd(?:"[^"]+"|\S+)', lambda _: '/Fd"' + str(output.with_suffix('.pdb')) + '"', command)
    dependencies = output.with_suffix(".dependencies.json")
    command += ' /sourceDependencies "' + str(dependencies) + '"'
    print(f"Compiling {source.name} -> {output}", flush=True)
    subprocess.run(command, cwd=entry["directory"], check=True)
    data = json.loads(dependencies.read_text(encoding="utf-8-sig"))["Data"]
    inputs = [source, *(Path(name) for name in data["Includes"])]
    def sha(path):
        with path.open("rb") as stream:
            return hashlib.file_digest(stream, "sha256").hexdigest()
    receipt = {"source": str(source), "output": str(output), "sha256": sha(output),
               "command": command, "directory": entry["directory"],
               "inputs": {str(path): sha(path) for path in inputs}}
    output.with_suffix(".receipt.json").write_text(json.dumps(receipt, indent=2) + "\n", encoding="utf-8")
    print(f"Compiled with {len(inputs)} input hashes; sha256={receipt['sha256']}", flush=True)


if __name__ == "__main__":
    main()
