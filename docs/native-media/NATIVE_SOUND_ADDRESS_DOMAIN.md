# Strict sound memory address policy

Status: pure address preflight helper implemented, 2026-11-06. No runtime RAM
factory, backend installation, game run or read authority is implemented by this
helper. It never dereferences an address, acquires a lock or owns a mapping.

`recomp/overrides/native_sound_ram/address_domain.{h,cpp}` implements the narrow
policy proposed in [the runtime capture design](NATIVE_SOUND_RAM_RUNTIME_CAPTURE.md).
The future owner must separately retain the actual Runtime, selected backend,
CD configuration and cooperating writer authority. Passing these checks alone
does not make a copy safe.

Nonempty EE ranges must fit wholly in one exact32MiB window starting at0,
`0x20000000`, `0x80000000` or `0xa0000000`. Unsupported segments are refused
before any normalization. IOP is a separate explicit space with offsets into
its own2MiB allocation. Neither extent arithmetic nor virtual addresses wrap.
Empty ranges may be at their own window's endpoint; that grants no payload
access. Unknown space tags refuse.

Every nonempty EE range intersecting the bridge's VU alias apertures refuses,
for both source and destination validation. Those physical intervals are
`[0x01000000,0x01001000)`, `[0x01004000,0x01005000)` and
`[0x01008000,0x01010000)`. This conservative capture policy does not change VIF
settings or establish that the upstream async VIF worker writes these aliases.
The [writer catalogue](NATIVE_SOUND_RAM_WRITER_CATALOGUE.md) distinguishes them.

Host-buffer checks use checked integer intervals and refuse overlap with either
entire guest backing, including excluded apertures. Backings must themselves
have nonnull, nonwrapping, disjoint intervals. Validating a host address does
not prove it is allocated, writable, immutable or alive; the synchronous caller
must provide that separate lifetime contract. Batch-level all-range preflight,
destination overlap checks and actual guarded copies remain owner obligations.

Both compilers pass130 checks covering canonical aliases, all aperture edges,
unsupported mirrors/SPR/MMIO/VU addresses, size overflow, IOP bounds, invalid
geometry and host aliases. Synthetic numeric backing intervals are never
dereferenced. Three private negative controls remove aperture refusal, admit an
extra mirror or remove host-alias refusal; each is detected by a failing test.
No original-game equivalence claim is made for these newly restrictive rules.

| Compiler | Private receipt SHA256 |
| --- | --- |
| GCC15.2 | `8451e2b1dce6e24b46a6c5078b244a548eaf78dc36e1ab220f116f4ff4c8395f` |
| pinned LLVM21.1.8 | `43c17a5d21a9a976a1f4b95d51a4c2857b4e657f11ae22dd3605e45dccc281cc` |

Receipts are under
`build-native-sjuni/native-sound-ram-address/{gcc-v1,llvm-v1}/receipt.json`.
They retain compiler, exact commands, input hashes, private negative sources,
test output and post-run source stability checks. Reproduce in a fresh private
output directory with `recomp/overrides/native_sound_ram/verify_address_domain.py`.
