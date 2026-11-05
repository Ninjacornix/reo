# Resource dependency input audit

2026-11-05. All **120 public patch files** applied successfully, in filename
order, to a fresh isolated checkout of the recorded PS2Recomp revision
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`. Every patch first passed
`git apply --check`. The active dependency checkout and player build were not
modified. No libraries or game were built in this audit.

The local source/patch discrepancy in the [inventory](RESOURCE_BOUNDARY_INVENTORY.md)
is therefore reproducible without relying on an old library: the current public
series reconstructs the overlay-aware host/syscall source, while the active dirty
checkout still contains different files. This does not diagnose which source
produced an existing player executable.

## Reproduction and identity

Use a fresh worktree, then the [audit driver](../../tools/native_reconstruction/audit_dependency_series.py):

```powershell
git -C third_party/PS2Recomp worktree add --detach C:/Users/Ninjacornix/reo/build-native-sjuni/dependency-audit-v1 c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f
python tools/native_reconstruction/audit_dependency_series.py --checkout build-native-sjuni/dependency-audit-v1
```

The example directory already exists from this audit; choose another fresh
directory to repeat it. The driver requires a clean pinned checkout below
`build-native-sjuni`, preserves partial failures and does not reset active trees.
It records every patch SHA/check/apply result and resulting source SHA in
`build-native-sjuni/dependency-audit-v1-receipt.json`, SHA-256:
`e915642a3bd76fff9d5b1e53afda13da74a1ab42f5561b7a5d8b2b851d30fb38`.
There are two different `0109-*` files; both are included in the same lexical
order used by `setup_deps.ps1`. The file count is not inferred from the highest
number or the older count in the dependency README.

| Inspected file relative to PS2Recomp | Fresh public-series SHA-256 | Active checkout SHA-256 |
| --- | --- | --- |
| `ps2xRuntime/src/lib/Kernel/Stubs/Helpers/Support.h` | `894635bc916ef39df97786b6a1751f568ec4c3de36d6fbb12a556a8a11b961fe` | `e52884fc5fc1ee5d05b21dcddff41dc7dcd5e4a8e30af15089db3a18f876ceae` |
| `ps2xRuntime/src/lib/Kernel/Syscalls/FileIO.cpp` | `c28e2d81a4584f24b91c8e3656c33be722002aa69ab1b1304cbe396099a28d3a` | `109ec25f69f1fffe11d93a32d639937ea89ee121a0b2f6155b7f30d9ce307d98` |
| `ps2xRuntime/include/ps2_runtime.h` | `a83a0bdc7e5d0caddc772e78013ae0c7381d04b55c50b29727ee6ac1bdfdf6b4` | `d0f0d4811e09dde6af0c1bd025ac046241e044fd29c3dcf975b4b114530545ee` |

The reconstructed Support helper starts pseudo LBAs at `0x40000000` and contains
`assets::hostSize`, `hostRead` and sector routing. Reconstructed FileIO has the
asset-FD branch. These are source observations, not linked-path reachability.

## Remaining build gate

Both files use `__has_include("runtime/assets/overlay.h")`. Applying the patch
does not enable those branches when the matching root header is absent from the
build inputs/include path. The earlier SJUNI candidate's frozen SDK lacks that
asset provider header and uses its older source baseline. Its successful ISO
playback tests do not certify the current PAK/FIO path.

The next resource candidate must include the current root asset providers and
matching public patched runtime sources, rebuild the affected libraries/objects
with a consistent compiler/ABI, record the resulting executable identity, and
test the actual mounted route. No preexisting `ps2_runtime.lib` is approved by
these source hashes. The [cvFs boundary review](CVFS_REQUEST_BOUNDARY.md) also
requires destination/request ownership and completion/error evidence before a
new payload provider is enabled.
