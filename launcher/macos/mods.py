"""RC1 mod manifests, validated data patches and shared original-asset catalogues."""

import json
from pathlib import Path
import shutil
import subprocess

from core import CHEATS, ELF_SHA256, ROOT, atomic_json, pnach_program


def installed(home):
    folder = Path(home) / "mods/file1"
    folder.mkdir(parents=True, exist_ok=True)
    result = []
    for path in sorted(folder.glob("*.json")):
        try:
            manifest = read(path)
            result.append((path, manifest, ""))
        except (OSError, ValueError, KeyError, TypeError) as error:
            result.append((path, None, str(error)))
    return result


def read(path):
    path = Path(path)
    if path.stat().st_size > 1024 * 1024:
        raise ValueError("Mod manifest exceeds 1 MiB")
    value = json.loads(path.read_text(encoding="utf-8-sig"))
    if value.get("format") != 1 or value.get("elfSha256") != ELF_SHA256:
        raise ValueError("This mod does not target the supported File #1 revision")
    if not isinstance(value.get("id"), str) or not value["id"] or not isinstance(value.get("name"), str):
        raise ValueError("Mod identity and name are required")
    if any(effect not in CHEATS for effect in value.get("effects", [])):
        raise ValueError("Unsupported mod effect")
    for kind in ("weaponShuffle", "itemRandomizer", "enemyRandomizer"):
        if kind in value:
            seed = value[kind].get("seed", 0)
            if type(seed) is not int or not 0 <= seed <= 0xffffffff:
                raise ValueError("Mod seed must be an unsigned 32-bit number")
    if value.get("itemRandomizer", {}).get("mode", "shuffle") not in ("shuffle", "global"):
        raise ValueError("Unsupported item randomizer mode")
    if value.get("enemyRandomizer", {}).get("mode", "zombieProfiles") not in ("zombieProfiles", "enemyTypes"):
        raise ValueError("Unsupported enemy randomizer mode")
    return value


def install(source, home):
    value = read(source)
    folder = Path(home) / "mods/file1"
    folder.mkdir(parents=True, exist_ok=True)
    # IDs are data, not host paths.
    import hashlib
    target = folder / (hashlib.sha256(value["id"].encode()).hexdigest() + ".json")
    if target.exists():
        raise FileExistsError("A mod with this identity is already installed")
    atomic_json(target, value)
    return value["id"]


def mod_environment(settings, home, disc, session):
    selected = []
    for path, manifest, error in installed(home):
        if manifest and manifest["id"] in settings["EnabledMods"]:
            selected.append(manifest)
    if settings["CoopMode"] != "offline":
        if "_OnlineMods" not in settings:
            raise ValueError("The host's shared randomizer configuration is required before online play")
        selected = settings["_OnlineMods"]
    elif set(settings["EnabledMods"]) != {value["id"] for value in selected}:
        raise ValueError("An enabled mod is missing or invalid")
    if not selected:
        return {}
    environment, owners, builtins, patch_lines = {}, set(), [], []
    for manifest in selected:
        for kind, key in (("weaponShuffle", "REO_MOD_WEAPON_SHUFFLE_SEED"),
                          ("itemRandomizer", "REO_MOD_ITEM_RANDOMIZER_SEED"),
                          ("enemyRandomizer", "REO_MOD_ENEMY_SPAWN_SEED")):
            if kind not in manifest:
                continue
            if kind in owners:
                raise ValueError("Select one mod for each randomizer type")
            owners.add(kind)
            options = manifest[kind]
            if kind == "enemyRandomizer" and options.get("mode", "zombieProfiles") == "zombieProfiles":
                key = "REO_MOD_ZOMBIE_RANDOMIZER_SEED"
            environment[key] = str(options.get("seed", 0))
            if kind == "itemRandomizer":
                exclusions = options.get("excludeItemTypes", [])
                if any(type(value) is not int or not 0 <= value <= 65535 for value in exclusions):
                    raise ValueError("Invalid excluded item type")
                if exclusions:
                    environment["REO_MOD_ITEM_EXCLUDE_TYPES"] = ",".join(map(str, exclusions))
                if options.get("mode") == "global":
                    resource = Path(settings.get("_Resources", ROOT))
                    helper = resource / "tools/AssetHelper"
                    if not helper.is_file():
                        helper = ROOT / "build-macos/asset-helper/AssetHelper"
                    if not helper.is_file():
                        raise RuntimeError("The shared Mac asset-catalogue helper is missing")
                    subprocess.run([str(helper), "catalogue", str(disc), str(session)], check=True,
                                   stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
                    environment["REO_MOD_GLOBAL_ITEM_CATALOGUE"] = str(session / "global-items.bin")
            if kind == "enemyRandomizer" and options.get("mode") == "enemyTypes":
                pool = options.get("pool", [])
                if not 1 <= len(pool) <= 128:
                    raise ValueError("Enemy pool must contain 1–128 profiles")
                packed = []
                for profile in pool:
                    values = [profile.get(field, 1 if field == "weight" else 0)
                              for field in ("type", "model", "health", "behavior", "posture", "weight")]
                    if any(type(value) is not int or not 0 <= value <= 65535 for value in values):
                        raise ValueError("Invalid enemy profile")
                    packed.append(":".join(map(str, values)))
                environment["REO_MOD_ENEMY_POOL"] = ";".join(packed)
                behaviors = options.get("sourceBehaviors", [0])
                if any(type(value) is not int or not 0 <= value <= 255 for value in behaviors):
                    raise ValueError("Invalid enemy source behavior")
                environment["REO_MOD_ENEMY_SOURCE_BEHAVIORS"] = ",".join(map(str, behaviors))
        builtins += ["builtin " + name for name in manifest.get("effects", [])]
        for patch in manifest.get("patches", []):
            timing = {"boot": 0, "frame": 1}.get(patch.get("when", "frame"))
            size = patch.get("size")
            if timing is None or size not in (1, 2, 4, 8):
                raise ValueError("Unsupported mod patch timing or size")
            patch_lines.append(f"patch={timing},EE,{patch['address']},{ {1:'byte',2:'short',4:'word',8:'double'}[size]},{patch['value']}")
    if builtins or patch_lines:
        temporary = session / "mod-patches.pnach"
        temporary.write_text("\n".join(patch_lines))
        writes = pnach_program([temporary])
        target = session / "cheats.txt"
        original = target.read_text().splitlines()[1:] if target.exists() else []
        target.write_text("REO-CHEATS-2\n" + "\n".join(original + builtins + writes) + "\n")
        environment["REO_CHEATS_FILE"] = str(target)
    atomic_json(session / "mods.json", selected)
    return environment
