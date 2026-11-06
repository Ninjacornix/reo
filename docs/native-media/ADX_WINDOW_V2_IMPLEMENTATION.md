# Shared-source Window2 qualification

Status: independent composed owner qualified for the bounded file-backed profile,
2026-11-06. Game/player integration remains open in stage 3. This establishes
neither a movie stutter fix nor a fully native media subsystem.

[`StreamWindowOwner`](../../game/native/adx_window/v2/stream_window.hpp) owns one
actual Source2, its private one-use control link, finite header/key state,
allocation-free codec workspace, and phased PCMv2 store. Mutable source control
does not escape. The [composition contract](ADX_SHARED_WINDOW_CONTRACT.md)
predates this implementation; this report records the gates now tested and the
remaining boundaries. Frozen Source2, header, workspace, and PCMv2 were unchanged.

## Implemented behavior

Header admission uses real bounded source grants and preserves selective parser
effects on defer/reject. Parsed loop geometry reaches the canonical source link
before diagnostics or credit observations. Ready configuration preserves the
original rate-dependent requests, output-depth metadata, signed pitch/pan rules,
and notification order. The scheduled `service` entry retries a deferred header;
source polling and ready configuration are explicit separate actions.

First/repeat loops, actual padding disposal, target-driven source rewind, and
seamless two-grant searches share the same source ring and sample limit. Ordinary
decode uses actual encoded input, predictor histories/key, native scalar output,
and real PCM storage. Raw stores and corrected wrap precede encoded credit;
PCM callbacks/publication follow it, then outer counters and acknowledgment.
The cumulative decoder count and acknowledged per-window cursor are distinct.

Source I/O errors preserve safe queued decoder bytes and the original two-retry
policy. Source stop retains accepted publication and independent buffered decode.
Owned protocol/geometry/credit failures retain evidence and remaining ownership.
The new geometry-fault policy disarms both action selectors with last valid
geometry before stopping/draining. It is a safety policy, not original parity.
Retirement requires the actual provider fence and drained PCM/read leases;
losing a token or staging output before a failure cannot invent a successful join.

## Measured qualification

Both GCC 15.2 and the actual bundled UCRT LLVM 21.1.8 pass:

- **996 whole-owner assertions** with zero allocation attempts on guarded
  post-construction owner/header/codec paths. Separate tests deny every actual
  constructor allocation in turn. The unchanged async backend's bounded worker
  allocations remain outside this allocation-free claim.
- **123 admitted original clients**, comparing **8,034 snapshots/events** per
  compiler, final PCM bytes, intermediate backing hashes, predictor/key state,
  source/PCM credits, loop/ready metadata, and callback/target order. Three
  40,017-sample mono/stereo/downmix streams reach their intended total.
- Nine independent evolving-counter horizon refusals before effects; source and
  PCM ID exhaustion; failure after actual encoded credit; and failure after the
  first channel's actual publication. Private variants leave production sources
  unchanged. Nine numeric bypass negatives and two absent/ignored-fault negatives
  all fail their corresponding assertions as intended.
- A whole-owner ordering negative moves encoded credit before raw PCM stores.
  **All stable operation results still match** in three original clients, while
  intermediate comparisons reject all three. Final equality alone is insufficient.
- Public stale/default/foreign/moved requests, moved/finished/lost PCM leases,
  owner destruction, callback reentry, six unsupported FP modes before effects,
  actual wrong-result identity, and an independently blocked real provider.
- Standalone and parent Release builds with the selected Window2 CTest. Parent
  registration adds one suite; the game build does not select this owner.

The separate read-only original capture executes all **133 clients / 6,801,810
instructions** per compiler. Every original transcript remains byte-identical
to the [prior original corpus](ADX_WINDOW_V2_ORACLE.md). Four original runs remain
partial. Original capture supplies no expected value to the native fixture: its
inputs are constructor bytes/configuration and authored operations only.

## Representation boundary and exclusions

This is typed-owner equivalence within the admitted profile, not raw guest-memory
ABI equivalence. At producer Get-free leave, original code still has its previous
cached descriptor: the live descriptor is on its stack, copied into the file
record only after the Ring guard returns. Source2 exposes its actual live owned
grant immediately. The comparator permits only these two cached cells at this
specific boundary after independently checking the measured free-credit delta,
native acquired offset/length, and unchanged original pre-Get cache. It records
both representations. Every other field, byte, flag, and stable descriptor is
still compared. Six policy tests reject invented grants or broader masking.

Ten excluded clients are **not successes**: two non-file constructors, four
asymmetric PCM constructors, three other partial original branches (negative end
extent, unsupported math, insufficient channels), and one malformed short end
record. The latter has a separately tested owned-fault/drain policy; it does not
claim to reproduce original descriptor loss. The fourth partial original run is
already among the non-file exclusions.

External PCM consumption compares stable synchronized channel-batch results.
It does not qualify the original per-channel RNA/DTR device-credit protocol.
The native core carries no guest object addresses, simulated registers, guest
runtime types, or device fence. A fixture-only standalone SHA helper is pinned
for hashing evidence; it is not a native core dependency.

The initial profile retains whole-sector file-backed Source2 geometry, one/two
synchronized PCM channels, tag0 18-byte/32-sample blocks, finite version3/4
headers, 24/44.1/48 kHz with filter500, admitted FP state, and no optional
resampler child. Inventory of 8,910 ADX entries does not qualify every full file
for this source profile. Partial final sectors, LSC, RNA/DTR, estimated clocks,
full player ownership, and guest-caller migration remain open.

## Reproducibility and corrections

The public `game/native/adx_window/v2/manifest.json` pins final independent inputs.
It is a post-comparison freeze and records earlier observations honestly.
`qualification.json` pins scripts, receipts, final parent builds, and this report.
Private local cohorts are under `build-native-sjuni/window2/`; none were deleted
or overwritten. `verify.py`, `verify_faults.py`, and `compare_original.py` take
`--cxx`, `--implementation` (a directory containing `manifest.json`), and a fresh
scoped `--output`. Original capture and negative-order tools have separate inputs.

Earlier comparisons exposed incorrect fixture projections of target and saved
history layout, the live-grant/cache distinction above, a missing deferred-header
dispatch in the integration, and an incorrect prototype retry default of zero.
The default was corrected to two from actual original global `21A8B4`; expected
original outputs were unchanged. Failed cohorts preserve prior comparison tools
and implementation snapshots. Expanded test v4 also exposed allocation-denial
state leaking from a test helper into its next fixture; only the helper changed.
The first private ID variant changed a saved config instead of the constructor
argument; its failed receipts and exact injected source remain preserved.

No game was launched or audio device opened for this qualification. Real player
validation and performance measurement must follow integration.
