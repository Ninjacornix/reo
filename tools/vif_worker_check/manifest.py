"""Record fresh sources; does not build, launch, copy, or mutate runtime files."""
import hashlib
import json
import pathlib
import sys

root = pathlib.Path(__file__).resolve().parents[2]
files = [
    "tools/vif_worker_check/main.cpp",
    "build-ninja/m2-vif-worker-prototype/ordered_worker.h",
    "third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_memory.cpp",
    "third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_vif1_interpreter.cpp",
    "third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_vu1.cpp",
    "third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_runtime.cpp",
    "third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_gif_arbiter.cpp",
    "third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_gs_gpu.cpp",
    "third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime.h",
    "third_party/PS2Recomp/ps2xRuntime/include/runtime/ps2_memory.h",
    "third_party/PS2Recomp/ps2xRuntime/include/runtime/ps2_vu1.h",
]
records = []
for name in files:
    data = (root / name).read_bytes()
    records.append({"path": name, "bytes": len(data), "sha256": hashlib.sha256(data).hexdigest()})
out = pathlib.Path(sys.argv[1])
if out.exists():
    raise SystemExit("Refusing to overwrite existing manifest")
out.write_text(json.dumps({"native_integration": False, "sources": records}, indent=2) + "\n", encoding="utf-8")
