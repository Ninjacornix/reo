"""Check complete batching coverage/options and guest bodies, without gameplay claims."""
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import sys

from benchmark_full_compilation import digest
from compare_compiled_outputs import link_inputs
from compare_unity_functions import bodies


def inputs(root):
    result, functions, object_sources, explicit_objects = {}, {}, {}, {}
    commands = [json.loads(line) for line in (root / "commands.jsonl").read_text().splitlines()]
    for row in commands:
        if row["event"] != "begin" or row["stage"] != "compile":
            continue
        command = row["command"][:]
        unity = Path(command.pop())
        at = command.index("-o")
        obj = Path(command[at + 1]).with_suffix(".obj")
        # Pending objects are atomically renamed by the production worker.
        obj = obj.with_name(obj.name.replace(".pending.obj", ".obj"))
        del command[at:at+2]
        if "-include-pch" in command:
            at = command.index("-include-pch")
            pch = Path(command[at+1])
            command[at+1] = "{pch:" + hashlib.sha256(pch.with_suffix(".hpp").read_bytes()).hexdigest() + "}"
        sources = [json.loads(line[len("#include "):]) for line in unity.read_text().splitlines()
                   if line.startswith("#include ")]
        if not sources:
            raise ValueError("No source includes in " + str(unity))
        object_sources[obj.name] = [Path(source).resolve().as_posix() for source in sources]
        if not re.fullmatch(r"(main|overlay|extra|legacy)\d+", unity.stem):
            explicit_objects[obj.name] = digest(obj)
        for source in sources:
            key = Path(source).resolve().as_posix()
            result.setdefault(key, []).append(command)
        current = bodies(obj)
        if current.keys() & functions.keys():
            raise ValueError("Duplicate guest definition")
        functions.update({name: {**value, "object": obj.name} for name, value in current.items()})
    for resource in (root / "objects").glob("resource*.obj"):
        explicit_objects[resource.name] = digest(resource)
    ordered_link = []
    for value in link_inputs(root):
        if value.startswith("{trial}/objects/") and Path(value).name in object_sources:
            ordered_link.extend(object_sources[Path(value).name])
        else:
            ordered_link.append(value)
    return result, functions, explicit_objects, ordered_link


def main():
    reference, candidate = map(lambda value: Path(value).resolve(), sys.argv[1:3])
    old_inputs, old, old_explicit, old_link = inputs(reference)
    new_inputs, new, new_explicit, new_link = inputs(candidate)
    missing, added = sorted(old.keys() - new.keys()), sorted(new.keys() - old.keys())
    different = [name for name in old.keys() & new.keys()
                 if (old[name]["bytes"], old[name]["sha256"]) !=
                 (new[name]["bytes"], new[name]["sha256"])]
    named_different = [name for name in old.keys() & new.keys()
                       if old[name]["namedRelocationsSha256"] != new[name]["namedRelocationsSha256"]]
    flags_equal = old_inputs.keys() == new_inputs.keys() and all(
        Counter(json.dumps(v) for v in old_inputs[key]) ==
        Counter(json.dumps(v) for v in new_inputs[key]) for key in old_inputs)
    result = {
        "sourceCoverageAndFlagsIdentical": flags_equal, "sourceFiles": len(old_inputs),
        "explicitObjectsIdentical": old_explicit == new_explicit,
        "explicitObjectsCompared": len(old_explicit),
        "flattenedLinkSourceOrderAndOptionsIdentical": old_link == new_link,
        "guestFunctions": len(old), "missingFunctions": missing, "addedFunctions": added,
        "instructionBodiesEqual": len(old) - len(missing) - len(different),
        "differentBodies": [{"name": name, "old": old[name], "new": new[name]} for name in different],
        "namedReferencesDiffer": named_different,
        "unresolvedLocalReferences": sum(value["unresolvedLocalRelocations"] for value in new.values()),
        "localReferenceContentsVerified": False, "exceptionTablesVerified": False,
        "gameExecuted": False,
    }
    (candidate / "batch-parity.json").write_text(json.dumps(result, indent=2))
    print(json.dumps({**result, "differentBodies": len(different),
                      "namedReferencesDiffer": len(named_different)}, indent=2))
    if (not flags_equal or missing or added or different or named_different
            or old_explicit != new_explicit or old_link != new_link):
        raise SystemExit("Source, options, object ordering or guest code differs; inspect batch-parity.json")


if __name__ == "__main__":
    main()
