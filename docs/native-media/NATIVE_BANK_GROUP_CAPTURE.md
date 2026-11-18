# Versioned grouped bank capture adapter

Status: isolated adapter3 implementation and source regressions, 2026-11-06.
No runtime capture factory, aggregate replacement, bootstrap/preparer/CMake
wiring, game/device run or full build is supplied. The frozen parent adapter2
and aggregate1 remain unchanged. Existing original expectations were known
before this mechanical derivation; this is not an independent DSP reconstruction.

## Derivation and protocol

[derive.py](../../recomp/overrides/native_banks/v3/derive.py) verifies the parent
identity and every parent candidate hash before generating six files in the new
`reo::native::bank_packets::v3` namespace. It adjusts relative includes and makes
reviewed exact replacements for the grouped interface/call and the explicitly
synthetic historical test fixture. `--check` refuses generated-file drift.

Parent identity SHA-256:
`2d7efe5f594096d8e1083214341451bde5aa4396d1b7b37750c0a594e9f66616`.
Adapter3 [identity](../../recomp/overrides/native_banks/v3/identity.json) SHA-256:
`2850d8d7a2dfc8b8f91cdcd65434be434878e25793f75531d856a7df661aeb66`.

The [header](../../recomp/overrides/native_banks/v3/packet_adapter.h) adds:

```cpp
enum class CopySourceV1 { ram, direct_hd, bd, tq };
struct PartCopyV1 {
    CopySourceV1 source;
    std::size_t offset;
    std::span<std::uint8_t> destination;
};
virtual Status copy_parts_v1(std::span<const PartCopyV1>) const noexcept;
```

The default batch operation returns `unsupported`. Old independent `copy_ram`
and `copy_bank` methods have optional false defaults. The production adapter
never uses either method as a fallback. A source implementing only independent
copies is refused explicitly, even when those methods would return true.

For packed RAM descriptors, the adapter supplies three `ram` entries with the
existing validated/masked offsets. For direct bank submission it supplies
`direct_hd`, `bd` and `tq`, each with offset0. Destinations belong to already
admitted, byte/count-budgeted bank capture vectors; no borrowed source pointer
survives the synchronous call. No numerical bank algorithm changed.

The source contract requires **one qualified coherent read scope across all
parts**, including all required writer/parent/lifetime authority. The source
must release that scope before returning. Merely using this interface, matching
identity values or constructing a CPU gate does not prove a provider qualified.
No provider is permitted to retain a destination span or perform deferred writes.

## Copy/decode and transaction ordering

`prepare_install` preserves the parent's RAII packet-load unlock. After producer
and identity checks, `Session::capture` reserves the asset and allocates **all
three** owned vectors before invoking the source. There is exactly one batch
call, with identity checks immediately before and after it, including a failed
batch result. Any non-ok copy result is returned without decoding/installing.
Successful batch return precedes `Session::prepare` and eventual install.

This is an explicit copy-window boundary, not an invitation to keep guest,
graphics, RPC or parent-read locks while allocating/decoding/installing. The
packet transaction is still released during capture/decode and reacquired on
every return, including source failure. Pre-relock failed staging frees before
the RAII relock; post-relock stop/stale/install refusals can free prepared assets
under the transaction, retaining the parent's pure/nonreentrant allocator rule.
Packet prefix effects and suppression of the suffix after failure are unchanged.

Loaded conditional `0x4E` skips descriptor validation, asset admission and the
entire unused group capture. Packet capture itself still occurs. Submission,
stop/incarnation checks, pool/control budget, query/reset serialization and
already-admitted render continuation retain the parent contracts. A future
aggregate must keep inner adapter/bank admission open until accepted outer calls
drain; adapter stop is not the outer aggregate stop signal.

## Verification

Both GCC15.2 and pinned Clang21.1.8 passed the derived **109 historical unit
assertions**, plus **39 grouped-copy checks**, with empty authored-source and
CPU-gate postchecks. Group checks cover direct and packed calls, default
unsupported despite implemented old helpers, exactly one batch, no unused loaded
`0x4E` capture, budget refusal before source entry, source/identity failure cleanup
and failed-copy prefix relock. Existing pause/reset/stop/lifetime cases remain.

The grouped fixture uses the actual committed `ram_capture::Coordinator`/
`CpuGroup`/`GraphicsActivity` implementation. A graphics attempt begins after the
first copied part and waits while the remaining two parts are copied. All three
owned results equal the initial immutable generation. Graphics then acquires and
mutates the source while the real bank decoder's allocator is paused, proving
this fixture's group has ended before decode/install. This tests actual gate
exclusion with synthetic writer/source surroundings; it does not qualify actual
Runtime, CD, guest or graphics integration.

Private negative variants must fail the same tests: removing failed-load RAII
relock fails historical assertion104; splitting the one batch into independent
single-part batches fails grouped assertion4; adding an independent-helper
fallback fails grouped assertion2. Original sources and expected values remain
unchanged. Earlier GCC v1 retained a failed header-probe namespace check; its
unit/group checks had passed, and it is not the final positive receipt.

The derived old fixture's explicit batch override deliberately calls its
historical helper methods to retain barrier/counter behavior. Those fixture bytes
are stable for the complete borrow except its explicitly coordinated tests. That
override is **synthetic test transport**, not a production coherent-copy recipe.

Both original-source regressions pass **18 cases / 252 actions / 13,004 float
words / 12,768 ordered gain calls with zero differences**. They reuse the frozen
original inputs/observer and expected values without DSP or expected rewrites.

Final receipts below ignored `build-native-sjuni/native-bank-group-capture`:

| Receipt | SHA-256 |
| --- | --- |
| `gcc-unit-v2/receipt.json` | `e057f443b1bf6e0038f83f64cdd98ec598d786dc956cee822ab747f17af51e91` |
| `llvm-unit-v1/receipt.json` | `9f030bb66c9096d158cdb44c0ae4d9a68a5fc5a7237a8ceecfa705cf501b2867` |
| `gcc-original-v1/receipt.json` | `ccca61d0d00aaa512a5e8bac2c85d8daf45edcf71b6de8a5475ec5419c02acac` |
| `llvm-original-v1/receipt.json` | `28fe612858c024bc087b7c24317882aa0e0025de66889e2b24226aa14f68a0f2` |

Both unit verifiers also compile the actual V2 status/API binding and the whole
adapter object with that binding force-included against final125 headers. The
full reapply receipt is
`3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a`;
header SHA-256 is
`631db6363db9a8945711f5c305ed8bfb0628ca50b3625cc2492e2afb3987f126`.
The verifier checks all source and patch inputs against that receipt before
compilation. This cohort does not claim final126 qualification.

Actual CPU-gate inputs, also recorded/checked in both unit receipts:

| File | SHA-256 |
| --- | --- |
| `cpu_authority_gate.hpp` | `0abd7a66d9892bdd3e590ecf3ec4a4b8080ad7c6312348c87dac8afde21dbc77` |
| `cpu_authority_gate.cpp` | `f338c6f1092214b1d482a971f107481d15c3879f8af268a395476783e00c35f8` |

The remaining production gate is a separately reviewed runtime capture factory
that actually obtains the enclosing Runtime/RAM/parent pins, canonical grouped
read reservation, CD configuration seal and graphics exclusion for the selected
source profile. [Capture capability requirements](NATIVE_BANK_CAPTURE_CAPABILITY_DESIGN.md)
remain applicable. Metadata identity alone cannot replace these capabilities or
make concurrent C++ storage copies coherent. No game behavior, device behavior,
whole Stage3 completion or performance improvement follows from these checks.
