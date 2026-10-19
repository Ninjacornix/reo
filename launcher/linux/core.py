"""Portable Linux launch/build lifecycle. No system installation or shell commands."""

from contextlib import contextmanager
import hashlib
import json
import math
import os
from pathlib import Path, PurePosixPath
import signal
import subprocess
import sys
import threading

TOOLS = Path(__file__).resolve().parents[2] / "tools/local_build"
if TOOLS.exists():
    sys.path.insert(0, str(TOOLS))
from generate_game import ELF_SHA256
from import_iso import import_iso

RESOLUTIONS = ("1024x768", "1280x960", "1600x1200", "1280x720", "1920x1080", "2560x1440", "3840x2160")


def resolution(settings):
    value = settings.get("Resolution")
    if value in RESOLUTIONS:
        return value
    index = max(0, min(len(RESOLUTIONS) - 1, settings.get("WindowSize", 0)))
    return RESOLUTIONS[index]


def sha(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def inside(root, relative):
    part = PurePosixPath(relative)
    if not relative or part.is_absolute() or any(p in {"..", "."} for p in relative.split("/")) or "\\" in relative or ":" in relative:
        raise ValueError("Invalid relative build-kit path")
    path = Path(root) / relative
    if not path.resolve().is_relative_to(Path(root).resolve()):
        raise ValueError("Build-kit path escapes its root")
    return path


def native_elf(path):
    with Path(path).open("rb") as stream:
        header = stream.read(20)
    return len(header) == 20 and header[:7] == b"\x7fELF\x02\x01\x01" and int.from_bytes(header[18:20], "little") == 62


def verify_kit(root, report=lambda text: None):
    root = Path(root).resolve()
    manifest = root / "build-kit.json"
    identity = sha(manifest)
    kit = json.loads(manifest.read_text(encoding="utf-8"))
    if kit.get("format") != 1 or kit.get("architecture") != "linux-x64" or kit.get("elfSha256") != ELF_SHA256:
        raise ValueError("This launcher requires a supported native linux-x64 build kit")
    if kit.get("toolchain") != "portable-clang" or not kit.get("runtimeAbi"):
        raise ValueError("The Linux kit must contain its portable native compiler")
    files = kit.get("files", [])
    names = [entry["path"] for entry in files]
    if not files or len(names) != len(set(names)):
        raise ValueError("Empty or duplicate build-kit inventory")
    for index, entry in enumerate(files):
        path = inside(root, entry["path"])
        toolchain_object = entry["path"].startswith("toolchain/") and path.suffix == ".o"
        if (path.suffix.lower() in {".exe", ".dll", ".lib", ".iso", ".elf", ".obj", ".o"} and not toolchain_object) or path.name == "reo_recomp":
            raise ValueError("Windows or private game input is forbidden in the Linux kit")
        if sha(path) != entry["sha256"]:
            raise ValueError("Build-kit integrity failure: " + entry["path"])
        if index % 100 == 0:
            report(f"Checking build files {index + 1}/{len(files)}")
    for name in ("tools/python/bin/python3", "tools/ps2_recomp", "tools/local_build/build_game.py", "compile-plan-linux.json"):
        if name not in names:
            raise ValueError("Missing verified Linux tool: " + name)
    for name in ("tools/python/bin/python3", "tools/ps2_recomp"):
        if not native_elf(root / name):
            raise ValueError("Non-native Linux tool: " + name)
    plan = json.loads((root / "compile-plan-linux.json").read_text(encoding="utf-8"))
    if plan.get("architecture") != "linux-x64" or plan.get("runtimeAbi") != kit["runtimeAbi"]:
        raise ValueError("Linux toolchain/runtime ABI mismatch")
    for key in ("compiler", "archiver"):
        name = plan[key].removeprefix("{kit}/")
        if name not in names or not native_elf(inside(root, name)):
            raise ValueError("Unverified portable Linux compiler tool")
    if sha(manifest) != identity:
        raise ValueError("Build-kit manifest changed during verification")
    return kit, identity


@contextmanager
def cache_lock(path):
    import fcntl
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a+b") as stream:
        try:
            fcntl.flock(stream, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError as error:
            raise RuntimeError("Another launcher is already preparing this game") from error
        try:
            yield
        finally:
            fcntl.flock(stream, fcntl.LOCK_UN)


def output_hashes(root, outputs):
    if not outputs or len(outputs) != len(set(outputs)) or "reo_recomp" not in outputs:
        raise ValueError("A verified Linux executable/output inventory is required")
    result = {name: sha(inside(root, name)) for name in outputs}
    if not native_elf(Path(root) / "reo_recomp"):
        raise ValueError("Local build did not produce a native Linux game")
    return result


class Session:
    def __init__(self):
        self.cancelled = threading.Event()
        self.process = None

    def cancel(self):
        self.cancelled.set()
        process = self.process
        if process is not None and process.poll() is None:
            # Only this session's separately created process group is signalled.
            try:
                os.killpg(process.pid, signal.SIGTERM)
            except ProcessLookupError:
                pass

    def run(self, command, cwd, environment, report, log):
        if self.cancelled.is_set():
            raise InterruptedError("Cancelled")
        with Path(log).open("a", encoding="utf-8") as output:
            process = subprocess.Popen(command, cwd=cwd, env=environment, stdout=subprocess.PIPE,
                                       stderr=subprocess.STDOUT, text=True, encoding="utf-8",
                                       errors="replace", start_new_session=True)
            self.process = process
            try:
                if self.cancelled.is_set():
                    self.cancel()
                for line in process.stdout:
                    output.write(line)
                    output.flush()
                    report(line.rstrip())
                code = process.wait()
            finally:
                self.process = None
            if self.cancelled.is_set():
                raise InterruptedError("Cancelled; partial build is preserved")
            if code:
                raise RuntimeError(f"Process exited with status {code}; see {log}")

    def prepare(self, kit_root, iso, home, report=lambda text: None):
        if sys.platform != "linux":
            raise RuntimeError("The Linux game must be built and run on Linux")
        kit_root, home = Path(kit_root).resolve(), Path(home).resolve()
        kit, identity = verify_kit(kit_root, report)
        cache = home / "local-games" / identity
        with cache_lock(home / "prepare.lock"):
            disc = import_iso(iso, home / "imports", report, self.cancelled.is_set)
            if sha(disc / "SLUS_207.65") != ELF_SHA256:
                raise ValueError("Local executable verification failed")
            output, work = cache / "output", cache / "work"
            receipt = cache / "ready.json"
            if receipt.exists():
                record = json.loads(receipt.read_text())
                if record.get("kitSha256") == identity and record.get("outputs") == output_hashes(output, kit["outputs"]):
                    return output / "reo_recomp", disc
                raise ValueError("Cached native build failed integrity verification")
            work.mkdir(parents=True, exist_ok=True)
            environment = dict(os.environ)
            environment["PYTHONDONTWRITEBYTECODE"] = "1"
            self.run([str(kit_root / "tools/python/bin/python3"), "-B", "-u",
                      str(kit_root / "tools/local_build/build_game.py"), "--kit", str(kit_root),
                      "--disc", str(disc), "--work", str(work), "--output", str(output), "--jobs", "4"],
                     work, environment, report, cache / "build.log")
            if identity != sha(kit_root / "build-kit.json"):
                raise ValueError("The build kit changed while compiling")
            outputs = output_hashes(output, kit["outputs"])
            temporary = receipt.with_suffix(".pending")
            temporary.write_text(json.dumps({"format": 1, "kitSha256": identity, "outputs": outputs}), encoding="utf-8")
            temporary.replace(receipt)
            return output / "reo_recomp", disc


def game_environment(iso, settings):
    aspect = "16:9" if settings.get("AspectRatio") == "16:9" else "4:3"
    fit = settings.get("ScreenFit", "fit")
    if fit not in {"fit", "center", "stretch", "fill"}:
        fit = "fit"
    anisotropy = settings.get("Anisotropy", 1)
    if anisotropy not in {2, 4, 8, 16}:
        anisotropy = 1
    aa = settings.get("AntiAliasingMode", "fxaa")
    aa = "off" if not settings.get("AntiAliasing", True) or aa == "off" else "smaa" if aa == "smaa" else "fxaa"
    brightness = max(50, min(150, settings.get("Brightness", 100)))
    gamma = settings.get("Gamma", 1.0)
    gamma = max(0.5, min(2.0, gamma)) if math.isfinite(gamma) else 1.0
    environment = {key: value for key, value in os.environ.items() if not key.startswith("REO_")}
    environment.update({"REO_ISO": str(Path(iso).resolve()), "REO_NATURAL": "1", "REO_TURBO": "1",
        "REO_GS_BACKEND": "parallel", "REO_GS_THREAD": "1", "REO_GS_GPU_PRESENT": "1",
        "REO_GS_DISPATCH_PACE": "2", "REO_GS_SPRITE_DEPTH_PARALLEL": "1",
        "REO_VIF1_ASYNC": "1" if settings.get("AsyncVif", True) else "0", "REO_VIF1_GPU_RESIDENT": "0",
        "REO_DISPLAY_ASPECT": aspect, "REO_DISPLAY_FIT": fit,
        "REO_DISPLAY_FILTER": "linear" if settings.get("LinearFilter", True) else "nearest",
        "REO_TEXTURE_FILTER": "linear" if settings.get("TextureLinear", False) else "original",
        "REO_TEXTURE_ANISOTROPY": str(anisotropy), "REO_POST_AA": aa,
        "REO_BRIGHTNESS": f'{brightness / 100:.2f}', "REO_GAMMA": f'{gamma:.2f}'})
    if settings.get("SkipIntros", False):
        environment["REO_SKIP_INTROS"] = "1"
    width, height = resolution(settings).split("x")
    environment.update({"REO_WINDOW_WIDTH": str(int(width)), "REO_WINDOW_HEIGHT": str(int(height))})
    return environment
