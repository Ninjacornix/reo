# Read-only installed import probe

This probe constructs the ordinary CDVD PAK facade and production MountedReader
against an explicit installed File #1 extracted-data directory. It opens no game
session, PS2 runtime library or original instructions. Imported assets and the
manifest are read only; output is restricted to `build-native-sjuni`.

The native factory streams all original file hashes through its retained handles.
`matches_plain_pak_layout` must accept the actual facade's initialized mode,
ordered keys/LBAs/lengths and equivalent current filesystem objects. No overlay
environment is inherited, and the native factory receives no overlay plan.

For every route, bounded full-sector samples at the start, middle and end compare
native output against existing CDVD output, using buffers of at most 8 KiB. Files
smaller than one sector have no covered full-sector sample. Partial EOF sectors
must remain native `not_covered` with untouched output, while the old facade must
produce the retained prefix plus zero padding. Every file also checks a pure
read-ahead sector: native exclusion/unchanged output versus legacy zeros.

An actual non-PAK reference is constructed with the same long extracted-directory
root and an intentionally absent private ISO pathname. The root is not a drive
root, so CDVD's raw-volume fallback is not entered. Admission must reject this
non-PAK instance. The missing sentinel is never created; no ISO is opened.

The Python receipt binds source/compiler/executable hashes, exact raw manifest
hash before/after, mount route identity, typed statuses and counts. Neither
payload bytes nor extracted samples are saved or printed. Construction time
includes file hashing/admission/cache effects and is not a game performance
measurement or an improvement claim.

Example authorized installed-import command:

```text
python tools/native_reconstruction/probe_mounted_import.py --cxx C:/msys64/mingw64/bin/g++.exe --data-root C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data --expected-files 85
```

The original manifest is unsigned, pre-existing writable mappings are not revoked,
and namespace admission is not a hostile-change filesystem transaction. This
probe does not validate original ISO LBAs, overlay assets, original RPC callbacks,
guest destination publication, asynchronous completion or gameplay behavior.

## Measured run — 2026-11-05

The explicit installed import above passed with GCC 15.2.0, C++20 and warnings
treated as errors. All 23 bound source/header/helper files stayed byte-identical
through compilation and execution. The receipt is
`build-native-sjuni/real-import-probe/receipt.json`.

| Observation | Result |
| --- | --- |
| Import version / file routes | V1 / 85 |
| Imported bytes verified by factory hashes | 4,267,473,063 |
| Actual plain-PAK facade admission | Accepted |
| Actual non-PAK facade with no image | Rejected |
| Files with at least one complete sector | 75 |
| Files below one sector | 10; excluded from exact sector sampling |
| Exact native/legacy comparisons | 222 ranges / 1,193,984 bytes |
| Partial EOF exclusions plus prefix/padding checks | 77 / 71,847 prefix bytes |
| Pure read-ahead exclusions plus legacy zero checks | 85 |
| Native source failures | 0 |
| Validation checks | 1,024 |
| Factory construction interval | 15,434,693 microseconds, including full hash/admission work |

The single construction interval is recorded for reproducibility, not as a
benchmark or a claim about gameplay performance. No payload sample was saved.
The raw manifest digest was identical before, during and after the probe.

```text
raw manifest SHA-256:
ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b
computed mount route identity:
445c11c55d9d26a600d666c3d13ddf12e5575184f23f1e4722e033b687367650
probe executable SHA-256:
fe2e803e26d4c1c6e931307d14ca9b90b6e04413e0c646445d0a7d26926b24c2
compiler executable SHA-256:
51911fb398529fa19769da935279c1a8a56f1c3508b2df295624aaa3dae34aa5
receipt SHA-256:
9bbbf83b79e9ae07d99c768ab9b193dc824224ab8cdd841fb79f29599b8d18b9
```

The mount digest includes local filesystem object identities; it is not a
portable retail-image checksum. The probe did not change user assets, open an
original ISO, launch the game, register guest functions or execute game code.
