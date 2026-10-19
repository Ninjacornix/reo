"""Fresh source provenance; coordinator must separately verify library/source identity."""
import hashlib
import json
import pathlib
import sys
root = pathlib.Path(__file__).resolve().parents[2]
files = [
    "tools/vif_async_check/main.cpp",
    "tools/vif_async_check/run.bat",
    "build-ninja/m2-vif-async-integration/vif_cursor.h",
    "tools/vif_worker_check/main.cpp",
    "build-ninja/m2-vif-worker-prototype/ordered_worker.h",
]
runtime = root / "third_party/PS2Recomp/ps2xRuntime"
files += [str(p.relative_to(root)).replace("\\", "/") for p in (
    runtime / "src/lib/ps2_memory.cpp",
    runtime / "src/lib/ps2_vif1_interpreter.cpp",
    runtime / "src/lib/ps2_vu1.cpp",
    runtime / "src/lib/ps2_runtime.cpp",
    runtime / "src/lib/ps2_gif_arbiter.cpp",
    runtime / "src/lib/ps2_gs_gpu.cpp",
    runtime / "include/ps2_runtime.h",
    runtime / "include/runtime/ps2_memory.h",
    runtime / "include/runtime/ps2_vu1.h",
)]
records = []
for name in files:
    data = (root / name).read_bytes()
    records.append(dict(path=name, bytes=len(data), sha256=hashlib.sha256(data).hexdigest()))
out = pathlib.Path(sys.argv[1])
if out.exists():
    raise SystemExit("Refusing to overwrite existing manifest")
out.write_text(json.dumps(dict(native_integration=False, sources=records), indent=2) + "\n", encoding="utf-8")
