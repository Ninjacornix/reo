"""Check actual incremental-link artifacts, including the movie/GS class layout.

Works on ordinary MSVC COFF and /bigobj files; no debugger is required.
"""
import argparse
import hashlib
import json
import mmap
from pathlib import Path
import struct


def functions(path):
    data = path.read_bytes()
    big = data[:4] == b"\x00\x00\xff\xff"
    if big:
        _, table, count = struct.unpack_from("<III", data, 44)
        stride, sections, fmt = 20, 56, "<IiHBB"
    else:
        machine, _, _, table, count, optional, _ = struct.unpack_from("<HHIIIHH", data)
        if machine != 0x8664:
            raise ValueError(f"Not x64 COFF: {path}")
        stride, sections, fmt = 18, 20 + optional, "<IhHBB"
    strings = data[table + count * stride:]
    index = 0
    while index < count:
        at = table + index * stride
        value, section, kind, _, auxiliary = struct.unpack_from(fmt, data, at + 8)
        if kind & 0x20 and section > 0:
            name = data[at:at + 8]
            if name[:4] == bytes(4):
                name = strings[struct.unpack_from("<I", name, 4)[0]:].split(b"\0", 1)[0]
            else:
                name = name.split(b"\0", 1)[0]
            size, raw = struct.unpack_from("<II", data, sections + (section - 1) * 40 + 16)
            yield name.decode("ascii", "replace"), data[raw + value:raw + size]
        index += 1 + auxiliary


def register_offset(path, symbol):
    offsets = set()
    for name, code in functions(path):
        if symbol not in name:
            continue
        # Both accessors return &registers with LEA RAX,[RCX+disp32].
        for at in range(min(len(code), 128) - 6):
            if code[at:at + 3] == b"\x48\x8d\x81":
                offsets.add(struct.unpack_from("<I", code, at + 3)[0])
    if len(offsets) != 1:
        raise ValueError(f"Expected one register offset in {path}: {offsets}")
    return offsets.pop()


def digest(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--gs-object", required=True, type=Path)
    parser.add_argument("--movie-object", required=True, type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    manifest = json.loads(args.manifest.read_text(encoding="utf-8-sig"))
    errors = []
    records = [manifest["exe"], *manifest["archives"].values(), *manifest.get("direct_objects", [])]
    for record in records:
        path = root / record["path"]
        if not path.is_file() or digest(path) != record["sha256"]:
            errors.append(f"Artifact differs from manifest: {path}")
    for name, record in manifest.get("source_hashes", {}).items():
        path = root / name
        if not path.is_file() or digest(path) != record["sha256"]:
            errors.append(f"Source differs from manifest: {name}")
    gs_offset = register_offset(args.gs_object, "get_register_state@GSInterface")
    movie_offset = register_offset(args.movie_object, "resident_command_register_state@GSInterface")
    if gs_offset != movie_offset:
        errors.append(f"GS/movie class layout differs: {gs_offset:#x} versus {movie_offset:#x}")
    exe = root / manifest["exe"]["path"]
    with exe.open("rb") as stream, mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as image:
        diagnostic_present = image.find(b"[MOVIE-UPLOAD-DIAG]") >= 0
    if not diagnostic_present:
        errors.append("Movie upload diagnostic absent from executable")
    result = {"status": "FAIL" if errors else "PASS", "exe": str(exe),
              "gsRegisterOffset": hex(gs_offset), "movieRegisterOffset": hex(movie_offset),
              "movieUploadDiagnosticPresent": diagnostic_present, "errors": errors}
    rendered = json.dumps(result, indent=2)
    if args.output:
        args.output.write_text(rendered + "\n", encoding="utf-8")
    print(rendered)
    return bool(errors)


if __name__ == "__main__":
    raise SystemExit(main())
