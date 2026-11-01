"""macOS launcher state, native game sessions and persistent memory cards."""

from contextlib import contextmanager
import copy
import fcntl
import hashlib
import ipaddress
import json
import math
import os
from pathlib import Path
import re
import shutil
import signal
import struct
import subprocess
import sys
import threading
import time
import uuid
import zipfile

ROOT = Path(__file__).resolve().parents[2]
DEFAULT_HOME = Path.home() / "Library/Application Support/OutbreakRecomp"
ELF_SHA256 = "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46"
RESOLUTIONS = {"Native": (512, 448), "HD": (1280, 720), "FHD": (1920, 1080),
               "QHD": (2560, 1440), "4K": (3840, 2160)}
CHEATS = {"health": "Full health", "infection": "No infection", "ammo": "Infinite ammunition",
          "unlock": "Unlock everything", "points": "Maximum results points", "escape": "Infinite escape time"}
KEY_DEFAULTS = {"UP": 13, "DOWN": 1, "LEFT": 0, "RIGHT": 2, "CROSS": 49, "CIRCLE": 14,
                "SQUARE": 12, "TRIANGLE": 15, "L1": 18, "R1": 19, "L2": 20, "R2": 21,
                "START": 36, "SELECT": 51, "L3": 6, "R3": 7}
PAD_NAMES = ["SELECT", "L3", "R3", "START", "UP", "RIGHT", "DOWN", "LEFT", "L2", "R2",
             "L1", "R1", "TRIANGLE", "CIRCLE", "CROSS", "SQUARE"]
DEFAULTS = {"Iso": "", "Resolution": "HD", "Fullscreen": False, "AspectRatio": "4:3",
    "WidescreenCamera": False, "ScreenFit": "fit", "InternalResolution": 1,
    "AntiAliasingMode": "off", "Anisotropy": 1, "LinearFilter": True, "TextureLinear": False,
    "AsyncVif": True, "PerformanceOverlay": False, "Brightness": 100, "Gamma": 1.0,
    "MasterVolume": 100, "MusicVolume": 100, "SfxVolume": 100, "VoiceVolume": 100, "UiVolume": 100,
    "ShowSubtitles": True, "DeadZone": 15, "InputDevice": "auto", "RumbleEnabled": True,
    "Keyboard": KEY_DEFAULTS, "PadMapping": list(range(16)), "MemoryCard": "default",
    "CheatsEnabled": False, "EnabledCheats": [], "PnachFiles": [], "EnabledMods": [],
    "CoopMode": "offline", "CoopHost": "127.0.0.1", "Username": "", "AutoLobby": True,
    "RoomName": "Outbreak", "RoomPlayers": 4, "SignupPort": 10128, "GamePort": 9091,
    "FrameTiming": False, "GameClock": False, "NetworkTrace": False, "BuildJobs": 4,
    "AudioOutput": "", "Theme": "dark"}


def atomic_json(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + "." + uuid.uuid4().hex + ".pending")
    try:
        with temporary.open("x", encoding="utf-8") as stream:
            json.dump(value, stream, indent=2, ensure_ascii=False)
            stream.flush()
            os.fsync(stream.fileno())
        temporary.replace(path)
    finally:
        temporary.unlink(missing_ok=True)


def digest(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def native_arm64(path):
    with Path(path).open("rb") as stream:
        header = stream.read(12)
    return len(header) == 12 and struct.unpack_from("<II", header) == (0xfeedfacf, 0x100000c)


def clean_environment():
    # Do not accidentally inherit a test route, cheats, credentials or diagnostic
    # switches from a developer terminal into an ordinary Play session.
    return {key: value for key, value in os.environ.items()
            if not key.startswith(("REO_", "OPENSNAP_")) and key not in {"PYTHONHOME", "PYTHONPATH"}}


@contextmanager
def lease(path):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a+b") as stream:
        try:
            fcntl.flock(stream, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError as error:
            raise RuntimeError("Another game or launcher is using this memory card or build.") from error
        try:
            yield
        finally:
            fcntl.flock(stream, fcntl.LOCK_UN)


class Store:
    def __init__(self, config_home=None, resources=None, data_home=None):
        self.config_home = Path(config_home or DEFAULT_HOME / "launcher")
        self.resources = Path(resources or (Path(sys._MEIPASS) if getattr(sys, "frozen", False) else ROOT))
        self.home = Path(data_home or DEFAULT_HOME)
        try:
            self.home = Path(json.loads((self.config_home / "storage.json").read_text())["path"])
        except FileNotFoundError:
            pass
        self.home = self.home.expanduser().resolve()
        self.settings = copy.deepcopy(DEFAULTS)
        try:
            value = json.loads((self.config_home / "settings.json").read_text())
            if not isinstance(value, dict):
                raise ValueError("Settings must contain an object")
            self.settings.update(value)
        except FileNotFoundError:
            pass
        self.build_record = self.locate_build()
        if not self.settings["Iso"] and self.build_record:
            self.settings["Iso"] = self.build_record.get("iso", "")
        self.home.mkdir(parents=True, exist_ok=True)

    def locate_build(self):
        candidates = [self.config_home / "local-build.json", self.resources / "mac-launcher.json",
                      ROOT / "build-macos/macos-build.json"]
        for candidate in candidates:
            if candidate.is_file():
                value = json.loads(candidate.read_text())
                if value.get("format") != 1:
                    raise ValueError("Unsupported Mac build record")
                for key in ("executable", "data", "driver", "sourceRoot", "buildRoot", "python"):
                    if key in value and not Path(value[key]).is_absolute():
                        value[key] = str((candidate.parent / value[key]).resolve())
                return value
        return None

    def save(self):
        atomic_json(self.config_home / "settings.json", self.settings)

    def set_storage(self, path):
        path = Path(path).expanduser().resolve()
        path.mkdir(parents=True, exist_ok=True)
        atomic_json(self.config_home / "storage.json", {"format": 1, "path": str(path)})
        self.home = path

    def cards(self):
        root = self.home / "memory-cards"
        default = root / "default/data"
        default.mkdir(parents=True, exist_ok=True)
        result = [("Default memory card", "default", default)]
        if root.is_dir():
            for folder in sorted(root.iterdir()):
                if folder.name == "default" or not (folder / "data").is_dir():
                    continue
                name = folder.name
                if (folder / "name.json").is_file():
                    name = json.loads((folder / "name.json").read_text())["name"]
                result.append((name, folder.name, folder / "data"))
        return result

    def card(self, settings=None):
        selected = (settings or self.settings)["MemoryCard"]
        for _, identity, path in self.cards():
            if identity == selected:
                return path
        raise ValueError("The selected memory card no longer exists. Select another card.")

    def create_card(self, name):
        name = name.strip()
        if not name or len(name) > 80:
            raise ValueError("Use a memory-card name between 1 and 80 characters.")
        identity = uuid.uuid4().hex
        path = self.home / "memory-cards" / identity
        (path / "data").mkdir(parents=True)
        atomic_json(path / "name.json", {"name": name})
        self.settings["MemoryCard"] = identity
        self.save()
        return path / "data"

    def backup_card(self, destination):
        card, destination = self.card(), Path(destination).resolve()
        if destination.is_relative_to(card.resolve()):
            raise ValueError("Choose a backup destination outside the memory card.")
        if destination.exists():
            raise FileExistsError("Choose a new backup filename; existing files are preserved.")
        with lease(card.parent / ".reo-lock"):
            with zipfile.ZipFile(destination, "x", zipfile.ZIP_DEFLATED) as archive:
                for file in sorted(card.rglob("*")):
                    if file.is_symlink():
                        raise ValueError("Memory-card symlinks cannot be backed up.")
                    if file.is_file():
                        archive.write(file, file.relative_to(card).as_posix())

    def restore_card(self, backup, name):
        # Always restore into a new card, keeping the current card untouched.
        with zipfile.ZipFile(backup) as archive:
            entries = archive.infolist()
            if len(entries) > 20000 or sum(item.file_size for item in entries) > 64 * 1024 * 1024:
                raise ValueError("Memory-card backup exceeds supported limits.")
            for item in entries:
                part = Path(item.filename)
                if (part.is_absolute() or ".." in part.parts or "\\" in item.filename or
                        (item.external_attr >> 16) & 0o170000 == 0o120000):
                    raise ValueError("Unsafe memory-card backup entry.")
            if len({item.filename for item in entries}) != len(entries):
                raise ValueError("Duplicate backup entries")
            if not name.strip() or len(name.strip()) > 80:
                raise ValueError("Use a memory-card name between 1 and 80 characters.")
            folder = self.home / "memory-cards" / uuid.uuid4().hex
            card = folder / "data"
            card.mkdir(parents=True)
            try:
                for item in entries:
                    target = card / item.filename
                    if item.is_dir():
                        target.mkdir(parents=True, exist_ok=True)
                    else:
                        target.parent.mkdir(parents=True, exist_ok=True)
                        with target.open("xb") as output, archive.open(item) as source:
                            shutil.copyfileobj(source, output)
                atomic_json(folder / "name.json", {"name": name.strip()})
            except BaseException:
                shutil.rmtree(folder)
                raise
            self.settings["MemoryCard"] = folder.name
            self.save()
        return card


def graphics_environment(settings):
    resolution = settings.get("Resolution", "HD")
    if resolution not in RESOLUTIONS:
        raise ValueError("Unknown output resolution")
    width, height = RESOLUTIONS[resolution]
    aspect, fit = settings["AspectRatio"], settings["ScreenFit"]
    aa, internal, aniso = settings["AntiAliasingMode"], settings["InternalResolution"], settings["Anisotropy"]
    if aspect not in ("4:3", "16:9", "21:9", "32:9") or fit not in ("fit", "stretch", "center", "fill"):
        raise ValueError("Unsupported display layout")
    if aa not in ("off", "fxaa", "smaa") or internal not in (1, 2, 4) or aniso not in (1, 2, 4, 8, 16):
        raise ValueError("Unsupported rendering setting")
    brightness, gamma = int(settings["Brightness"]), float(settings["Gamma"])
    if not 50 <= brightness <= 150 or not math.isfinite(gamma) or not 0.5 <= gamma <= 2:
        raise ValueError("Brightness or gamma is out of range")
    return {"REO_WINDOW_WIDTH": str(width), "REO_WINDOW_HEIGHT": str(height),
        "REO_FULLSCREEN": str(int(bool(settings["Fullscreen"]))), "REO_DISPLAY_ASPECT": aspect,
        "REO_DISPLAY_FIT": fit, "REO_WIDESCREEN": str(int(settings["WidescreenCamera"] and aspect != "4:3")),
        "REO_POST_AA": aa, "REO_INTERNAL_RESOLUTION": str(internal), "REO_TEXTURE_ANISOTROPY": str(aniso),
        "REO_DISPLAY_FILTER": "linear" if settings["LinearFilter"] else "nearest",
        "REO_TEXTURE_FILTER": "linear" if settings["TextureLinear"] else "original",
        "REO_VIF1_ASYNC": str(int(bool(settings["AsyncVif"]))),
        "REO_PERFORMANCE_OVERLAY": str(int(bool(settings["PerformanceOverlay"]))),
        "REO_BRIGHTNESS": f"{brightness / 100:.2f}", "REO_GAMMA": f"{gamma:.2f}"}


def mixer_value(settings):
    values = [int(settings[key]) for key in ("MasterVolume", "MusicVolume", "SfxVolume", "VoiceVolume", "UiVolume")]
    if any(not 0 <= value <= 100 for value in values):
        raise ValueError("Audio volume is outside 0–100")
    return ",".join(map(str, values))


def input_environment(settings):
    keys, mapping = settings["Keyboard"], settings["PadMapping"]
    if set(keys) != set(KEY_DEFAULTS) or any(type(value) is not int or not 0 <= value < 256 for value in keys.values()):
        raise ValueError("Invalid macOS keyboard mapping")
    if len(mapping) != 16 or any(type(value) is not int or not 0 <= value < 16 for value in mapping):
        raise ValueError("Invalid controller mapping")
    deadzone = int(settings["DeadZone"])
    if not 0 <= deadzone <= 30:
        raise ValueError("Controller deadzone is outside 0–30%")
    return {"REO_MACOS_KEYS": ",".join(str(keys[name]) for name in PAD_NAMES),
            "REO_MACOS_PAD_MAPPING": ",".join(map(str, mapping)), "REO_MACOS_DEADZONE": str(deadzone),
            "REO_MACOS_INPUT_DEVICE": str(settings["InputDevice"]),
            "REO_MACOS_RUMBLE": str(int(bool(settings["RumbleEnabled"])))}


def pnach_program(paths):
    writes = []
    for path in paths:
        path = Path(path)
        if path.stat().st_size > 1024 * 1024:
            raise ValueError("Cheat file exceeds 1 MiB")
        for number, raw in enumerate(path.read_text(encoding="utf-8-sig").splitlines(), 1):
            line = raw.split("//", 1)[0].strip()
            if not line or line.startswith(("#", ";", "[")):
                continue
            key, separator, value = line.partition("=")
            if key.lower().strip() in ("gametitle", "comment", "author", "description"):
                continue
            try:
                fields = [part.strip() for part in value.split(",")]
                if not separator or key.lower().strip() != "patch" or len(fields) != 5 or fields[1].upper() != "EE":
                    raise ValueError("Only EE direct data patches are supported")
                place, address, value = int(fields[0]), int(fields[2], 16), int(fields[4], 16)
                kind = fields[3].lower()
                size = {"byte": 1, "short": 2, "word": 4, "double": 8}.get(kind, 0)
                if kind == "extended":
                    if address >> 28 > 2:
                        raise ValueError("Conditional and pointer cheats are unsupported")
                    size, address = 1 << (address >> 28), address & 0xfffffff
                else:
                    for base in (0x20000000, 0x80000000, 0xa0000000):
                        if base <= address < base + 0x2000000:
                            address -= base
                            break
                if (place not in range(4) or not size or value < 0 or value >= 1 << (size * 8) or
                    address < 0x370000 or address + size > 0x1fd0000 or
                    (address < 0x900000 and address + size > 0x570000)):
                    raise ValueError("Patch is outside supported game data")
                writes.append(f"{place} {address:08X} {size} {value:016X}")
            except ValueError as error:
                raise ValueError(f"{path.name}, line {number}: {error}") from error
    if len(writes) > 4096:
        raise ValueError("Select fewer cheats (4096-write limit)")
    return writes


def export_cheats(settings, session):
    if not settings["CheatsEnabled"]:
        return None
    if settings["CoopMode"] != "offline":
        raise ValueError("Disable cheats before hosting or joining co-op")
    selected = settings["EnabledCheats"]
    if any(name not in CHEATS for name in selected):
        raise ValueError("Unknown built-in cheat")
    lines = ["builtin " + name for name in selected] + pnach_program(settings["PnachFiles"])
    if not lines:
        return None
    target = session / "cheats.txt"
    target.write_text("REO-CHEATS-2\n" + "\n".join(lines) + "\n", encoding="ascii")
    return target


class Processes:
    def __init__(self):
        self.cancelled = threading.Event()
        self.current = None
        self.gate = threading.Lock()

    def cancel(self):
        self.cancelled.set()
        with self.gate:
            process = self.current
        if process and process.poll() is None:
            try:
                os.killpg(process.pid, signal.SIGTERM)
            except ProcessLookupError:
                return
            def timeout():
                try:
                    process.wait(timeout=10)
                except subprocess.TimeoutExpired:
                    try:
                        os.killpg(process.pid, signal.SIGKILL)
                    except ProcessLookupError:
                        pass
            threading.Thread(target=timeout, daemon=True).start()

    def run(self, command, cwd, environment, log, report=lambda text: None, on_line=None):
        if self.cancelled.is_set():
            raise InterruptedError("Cancelled")
        Path(log).parent.mkdir(parents=True, exist_ok=True)
        with Path(log).open("a", encoding="utf-8") as output:
            process = subprocess.Popen(list(map(str, command)), cwd=cwd, env=environment,
                stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, errors="replace",
                start_new_session=True, bufsize=1)
            with self.gate:
                self.current = process
            try:
                if self.cancelled.is_set():
                    self.cancel()
                for line in process.stdout:
                    output.write(line)
                    output.flush()
                    report(line.rstrip())
                    if on_line:
                        on_line(line)
                code = process.wait()
            finally:
                process.stdout.close()
                with self.gate:
                    self.current = None
            if self.cancelled.is_set():
                return code
            if code:
                raise RuntimeError(f"Process exited with status {code}. See {log}")
            return code


class Session:
    def __init__(self, store):
        self.store = store
        self.processes = Processes()
        self.folder = None
        self.live_file = None
        self.active_settings = None

    def cancel(self):
        self.processes.cancel()

    def import_disc(self, iso, report=lambda text: None):
        source_root = Path((self.store.build_record or {}).get("sourceRoot", ROOT))
        tool_path = source_root / "tools/local_build"
        if str(tool_path) not in sys.path:
            sys.path.insert(0, str(tool_path))
        from import_iso import import_iso
        record = self.store.build_record or {}
        cache = self.store.home / "imports"
        if record.get("iso") and Path(record["iso"]).resolve() == Path(iso).resolve() and record.get("data"):
            imported = Path(record["data"])
            if (imported.parent / "import.json").is_file():
                cache = imported.parent.parent
        return import_iso(iso, cache, report, self.processes.cancelled.is_set)

    def build(self, settings, report=lambda text: None):
        record = self.store.build_record or {}
        root = Path(record.get("sourceRoot", ROOT))
        script = root / "tools/macos/build.py"
        if not script.is_file():
            raise RuntimeError("This application has no native build sources. Keep the Mac source checkout available for rebuilding.")
        python = Path(record.get("python", "/opt/homebrew/bin/python3"))
        if not python.is_file():
            raise RuntimeError("The native build Python is unavailable. Select a compatible source build in Game files.")
        build = Path(record.get("buildRoot", root / "build-macos"))
        log = self.store.home / "build-logs" / (time.strftime("%Y%m%d-%H%M%S") + ".log")
        with lease(self.store.home / "build.lock"):
            code = self.processes.run([python, "-u", script, "--iso", settings["Iso"], "--build", build,
                                      "--jobs", str(settings["BuildJobs"])], root, clean_environment(), log, report)
            if self.processes.cancelled.is_set():
                raise InterruptedError("Build cancelled; completed objects are preserved for retry")
            if code == 0:
                value = json.loads((build / "macos-build.json").read_text())
                value.update(sourceRoot=str(root), buildRoot=str(build), python=str(python))
                atomic_json(self.store.config_home / "local-build.json", value)
                self.store.build_record = value

    def live_settings(self, settings):
        target = self.live_file
        if target:
            value = mixer_value(settings) + "\n" + str(int(bool(settings["ShowSubtitles"]))) + "\n"
            temporary = target.with_name(target.name + "." + uuid.uuid4().hex + ".pending")
            try:
                temporary.write_text(value, encoding="ascii")
                temporary.replace(target)
            finally:
                temporary.unlink(missing_ok=True)

    def launch(self, settings, report=lambda text: None, route=None, seconds=None):
        settings = copy.deepcopy(settings)
        settings["_Resources"] = str(self.store.resources)
        record = self.store.build_record
        if not record:
            raise RuntimeError("Build the game or select an existing Mac build first")
        executable = Path(record["executable"])
        if not executable.is_file() or not native_arm64(executable):
            raise RuntimeError("The selected game is not a native ARM64 macOS executable")
        if record.get("executableSha256") and digest(executable) != record["executableSha256"]:
            raise RuntimeError("The game executable changed. Select or rebuild it before playing.")
        if not settings["Iso"] or not Path(settings["Iso"]).is_file():
            raise ValueError("Choose your supported File #1 NTSC-U v2.00 ISO")
        disc = self.import_disc(settings["Iso"], report)
        if digest(disc / "SLUS_207.65") != ELF_SHA256:
            raise ValueError("Unsupported game executable")
        self.folder = self.store.home / "sessions" / (time.strftime("%Y%m%d-%H%M%S") + "-" + uuid.uuid4().hex[:6])
        self.folder.mkdir(parents=True)
        self.active_settings = settings
        self.live_file = self.folder / "live-settings.txt"
        self.live_settings(settings)
        environment = clean_environment()
        driver = record.get("driver")
        if not driver or not Path(driver).is_file():
            candidates = [self.store.resources / "native/libMoltenVK.dylib", Path("/opt/homebrew/lib/libMoltenVK.dylib"),
                          Path("/usr/local/lib/libMoltenVK.dylib")]
            driver = next((str(path) for path in candidates if path.is_file()), None)
        if not driver:
            raise RuntimeError("The bundled Metal graphics driver is missing")
        card = self.store.card(settings)
        environment.update({"GRANITE_VULKAN_LIBRARY": str(driver), "REO_ISO": str(Path(settings["Iso"]).resolve()),
            "REO_MC0_ROOT": str(card), "REO_MC1_ROOT": ":none:", "REO_NATURAL": "1", "REO_TURBO": "1",
            "REO_GS_BACKEND": "parallel", "REO_GS_THREAD": "1", "REO_GS_GPU_PRESENT": "1",
            "REO_GS_DISPATCH_PACE": "2", "REO_GS_SPRITE_DEPTH_PARALLEL": "1", "REO_VIF1_GPU_RESIDENT": "0",
            "REO_PARALLEL_GS_DESCRIPTOR_BUFFER": "0",
            "REO_GPU_MOVIE": "0", "REO_DEBUG_PANEL": "0", "REO_MACOS_LIVE_SETTINGS": str(self.live_file),
            "REO_AUDIO_LEVELS": mixer_value(settings), "REO_SUBTITLES": str(int(bool(settings["ShowSubtitles"])))})
        environment.update(graphics_environment(settings))
        environment.update(input_environment(settings))
        if settings.get("AudioOutput"):
            environment["REO_AUDIO_DEVICE"] = settings["AudioOutput"]
        if settings["FrameTiming"]:
            environment["REO_FRAME_PACING_FILE"] = str(self.folder / "frames.csv")
        if settings["PerformanceOverlay"]:
            environment["REO_PERFORMANCE_DIAG"] = "1"
        if settings["GameClock"]:
            environment.update(REO_GAME_CLOCK_LOG="1", REO_GAME_CLOCK_FROM_SECS="0",
                REO_GAME_CLOCK_SECONDS="600", REO_GAME_CLOCK_FILE=str(self.folder / "clock.csv"))
        if settings["NetworkTrace"] and settings["CoopMode"] != "offline":
            environment["REO_COOP_TRACE_FILE"] = str(self.folder / "network.jsonl")
        cheat_file = export_cheats(settings, self.folder)
        if cheat_file:
            environment["REO_CHEATS_FILE"] = str(cheat_file)
        from mods import mod_environment
        environment.update(mod_environment(settings, self.store.home, disc, self.folder))
        account = None
        if settings["CoopMode"] != "offline":
            from services import OnlineAccount, online_environment
            account = OnlineAccount(settings, self.folder, report, self.store.resources)
            environment["REO_COOP_ACCOUNT_STATUS"] = str(account.status)
        if route:
            environment["REO_TEST_ROUTE"] = route
        if seconds:
            environment["REO_MACOS_RUN_SECONDS"] = str(seconds)
        with lease(card.parent / ".reo-lock"):
            try:
                if account:
                    environment.update(online_environment(settings, card))
                report("Starting File #1 on Metal…")
                self.processes.run([executable, "--game", "file1", "--elf", disc / "SLUS_207.65", "--data", disc],
                    self.folder, environment, self.folder / "game.log", report,
                    account.on_line if account else None)
            finally:
                if account:
                    account.close()
                self.live_file = None
