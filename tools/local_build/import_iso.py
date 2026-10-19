"""Mount-free ISO9660 import shared by portable launchers."""

import hashlib
import json
from pathlib import Path
import struct
import tempfile

from generate_game import ELF_SHA256

SECTOR = 2048


def digest(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def import_iso(source, cache, report=lambda text: None, cancelled=lambda: False):
    source, cache = Path(source).resolve(), Path(cache).resolve()
    before = source.stat()
    identity = {"source": str(source), "bytes": before.st_size, "mtimeNs": before.st_mtime_ns}
    key = hashlib.sha256(json.dumps(identity, sort_keys=True).encode()).hexdigest()
    cache.mkdir(parents=True, exist_ok=True)
    destination = cache / key
    receipt = destination / "import.json"
    if receipt.exists():
        record = json.loads(receipt.read_text(encoding="utf-8"))
        if record.get("identity") == identity and record.get("elfSha256") == ELF_SHA256:
            valid = bool(record.get("files"))
            for entry in record.get("files", []):
                path = (destination / "data" / entry["path"]).resolve()
                if not path.is_relative_to(destination / "data") or not path.is_file() or digest(path) != entry["sha256"]:
                    valid = False
                    break
            if valid:
                report("Reusing verified disc import")
                return destination / "data"
        raise ValueError("Cached disc import failed verification; preserve it and choose a fresh cache")
    if destination.exists():
        raise FileExistsError("Incomplete import is preserved: " + str(destination))
    staging = Path(tempfile.mkdtemp(prefix=key + ".importing-", dir=cache))
    data = staging / "data"
    data.mkdir()
    entries, visited, names = [], set(), set()
    total_directory_bytes = 0
    with source.open("rb") as stream:
        def read(offset, size):
            if offset < 0 or size < 0 or offset + size > before.st_size:
                raise ValueError("ISO extent escapes the source image")
            stream.seek(offset)
            result = stream.read(size)
            if len(result) != size:
                raise ValueError("Truncated ISO image")
            return result

        pvd = None
        for index in range(16, 80):
            descriptor = read(index * SECTOR, SECTOR)
            if descriptor[1:7] != b"CD001\x01":
                raise ValueError("Not a supported ISO9660 image")
            if descriptor[0] == 1:
                pvd = descriptor
                break
            if descriptor[0] == 255:
                break
        if pvd is None or struct.unpack_from("<H", pvd, 128)[0] != SECTOR:
            raise ValueError("ISO9660 primary descriptor with 2048-byte sectors is required")

        def walk(lba, size, parent, depth=0):
            nonlocal total_directory_bytes
            if depth > 32 or lba in visited or size > 16 * 1024 * 1024:
                raise ValueError("Invalid or cyclic ISO directory")
            visited.add(lba)
            total_directory_bytes += size
            if total_directory_bytes > 64 * 1024 * 1024:
                raise ValueError("ISO directory index is too large")
            directory = read(lba * SECTOR, size)
            pos = 0
            while pos < len(directory):
                length = directory[pos]
                if length == 0:
                    pos = (pos // SECTOR + 1) * SECTOR
                    continue
                record = directory[pos:pos + length]
                if length < 34 or len(record) != length or 33 + record[32] > length:
                    raise ValueError("Malformed ISO directory record")
                pos += length
                raw = record[33:33 + record[32]]
                if raw in (b"\x00", b"\x01"):
                    continue
                if record[25] & 0x80:
                    raise ValueError("Multi-extent ISO files are unsupported")
                name = raw.decode("ascii", errors="strict").split(";", 1)[0].rstrip(".")
                if not name or name in (".", "..") or any(c in name for c in "/\\:\x00"):
                    raise ValueError("Unsafe ISO file name")
                relative = parent / name
                normalized = relative.as_posix().upper()
                if normalized in names or len(names) >= 100000:
                    raise ValueError("Duplicate ISO name or too many files")
                names.add(normalized)
                extent, count = struct.unpack_from("<I", record, 2)[0], struct.unpack_from("<I", record, 10)[0]
                if record[25] & 2:
                    walk(extent, count, relative, depth + 1)
                else:
                    if extent * SECTOR + count > before.st_size:
                        raise ValueError("ISO file extent exceeds source image")
                    entries.append((relative, extent, count))

        walk(struct.unpack_from("<I", pvd, 158)[0], struct.unpack_from("<I", pvd, 166)[0], Path())
        elf_entry = next((entry for entry in entries if entry[0].as_posix() == "SLUS_207.65"), None)
        if elf_entry is None or elf_entry[2] > 32 * 1024 * 1024:
            raise ValueError("Supported File #1 executable was not found")
        if hashlib.sha256(read(elf_entry[1] * SECTOR, elf_entry[2])).hexdigest() != ELF_SHA256:
            raise ValueError("Unsupported game revision; use NTSC-U v2.00 / SLUS-20765")
        files = []
        for relative, lba, size in entries:
            if cancelled():
                raise InterruptedError("Disc import cancelled; partial files are preserved")
            report("Importing " + relative.as_posix())
            target = data / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            hasher = hashlib.sha256()
            stream.seek(lba * SECTOR)
            remaining = size
            with target.open("xb") as output:
                while remaining:
                    if cancelled():
                        raise InterruptedError("Disc import cancelled; partial files are preserved")
                    block = stream.read(min(remaining, 4 * 1024 * 1024))
                    if not block:
                        raise ValueError("Truncated source image during import")
                    output.write(block)
                    hasher.update(block)
                    remaining -= len(block)
            files.append({"path": relative.as_posix(), "sha256": hasher.hexdigest()})
    after = source.stat()
    if (before.st_size, before.st_mtime_ns) != (after.st_size, after.st_mtime_ns):
        raise ValueError("The ISO changed during import")
    (staging / "import.json").write_text(json.dumps({"format": 1, "identity": identity,
        "elfSha256": ELF_SHA256, "files": files}, indent=2), encoding="utf-8")
    staging.rename(destination)
    return destination / "data"
