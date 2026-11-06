# Native bank packet adapter

Status: isolated implementation with synthetic source and lifecycle validation;
not selected by a runtime. No game, device, dependency, bootstrap, root CMake or
preparer change is made here.

`recomp/overrides/native_banks/packet_adapter.{h,cpp}` implements the raw packet
boundary outside the allocator-accounted v2 BankSession. It owns bounded packet
staging and producer admission; the v2 Session continues to own bank parsing,
decoded assets, request scheduling, synthesis, clocks and clip retirement.

## Source and proposed aggregate facade

The source is qualified124 `ReoSoundBanks.cpp` SHA256
`e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818`
and header `28963da544d533ae8f04765558ff0665c4dc87c38cfba767a4828705c07616c8`.
Packet handling is433–496, positive mix499–553, reset/queries558–599 in the
reconstructed source. The unchanged full-source oracle and original input are
described in [BANK_SESSION_ORACLE.md](BANK_SESSION_ORACLE.md). The core is
described in [BANK_SESSION_IMPLEMENTATION.md](BANK_SESSION_IMPLEMENTATION.md).

The independently authored0124 facade plan supplies one complete shared PCM/
bank owner, an outer `SoundCall` admitted before sound-RPC adoption or guest
reads, and a `render_admitted` callback retaining the same outer admission.
The adapter does not implement or independently select that registry. Each
producer bank-table callback creates an inner adapter Call inside the existing
outer SoundCall, and releases it before the outer call returns. Runtime
integration must never reacquire a closed outer gate halfway through an
already-admitted composite render.

The proposed bank table accepts the existing raw pointer signatures. A concrete
runtime owner must convert those arguments into a qualified `CaptureSource`
while retaining the outer SoundCall. This implementation deliberately does not
pretend that an arbitrary pointer or supplied hash constitutes that proof.

## Identity, lifetime and owned capture

`MemoryIdentity` records schema, session nonce, executable/build SHA256 values,
runtime and RAM incarnations, and full RAM extent. Construction rejects missing
identity fields and an extent outside the25-bit physical RAM domain. Equality
is a binding check against the supplied profile, not executable verification.
The eventual runtime factory must establish exact actual executable/build and
Runtime/RAM identity and retain their lifetime. PID or process-name attachment
is absent.

`CaptureSource` is a synchronous caller-retained capability. Its outer owner
must retain actual RAM storage and packet/direct-bank borrows through the entire
method. Its read methods copy into supplied owned writable spans; they must
provide bounded, synchronized, coherent reads without allocation or device-lock
inversion. Adapter identity checks before/after capture detect a changed
incarnation, but do not stop guest writers or legalize a data race. No source
pointer or borrowed span is stored in BankSession. A fixture provider is not
evidence that actual game-memory reads satisfy those requirements.

`begin_call` reserves a bounded packet slot and obtains a v2 Submission before
any source capture. The inner Submission spans packet copy, ordered parsing,
descriptor reads, bank capture, decode and install. Packet bytes are copied once
to the exclusive pool slot before parsing. Bank payloads use v2 `capture` before
HD/BD/TQ filling; temporary preparation, retained assets and old clips remain
charged to that Session's separate asset budget.

Default producer domain is16 simultaneous Calls and65,536 bytes per packet.
Actual124 RPC permits packets up to the remaining32MiB RAM range, so the64KiB
limit is an explicit conservative native admission policy, not a source format
limit. Oversized packets refuse before prefix effects. Any future installation
must qualify this domain; no runtime installer is provided here.

The packet pool and control State/slot/shared-control-block allocations use a
separate explicit requested-byte budget, default2MiB. All packet buffers and slot
metadata allocate before publication; call admission/parser commands use fixed
storage. Control budget is independent of v2 assets and, like v2, excludes heap
bookkeeping and separately owned caller/runtime storage. The pool remains
charged after join until its owner/control block is destroyed.

## Source command and ordering rules

The parser applies an accepted prefix immediately. Unknown or truncated commands
report once and return `parser_accepted=false`; earlier effects remain. It stops
at0xFF and ignores the trailing buffer. No native rejection retries a prefix or
individual operation through legacy code.

- Opcodes0–15 preserve optional volume/pan/pitch lengths, source sentinel
  defaults, high-bit request masks, cancellation and ignored trailer behavior.
- Load0x4D/0x4E uses the big-endian port and three packed six-byte descriptors;
  addresses retain the source25-bit mask and lengths the source16-byte units.
  Invalid extents fail without inventing an unsupported report.
- A loaded0x4E skips every unused descriptor/RAM extent validation, RAM read,
  asset-count admission and asset allocation. The fixed command length is still
  validated first. Decode/install uses force semantics after an initially
  admitted load, matching source behavior if another load wins while decode is
  unlocked; reset generation checks intentionally prevent stale resurrection.
- All/port volume, mute and inverted mono controls, stop/unload combinations,
  accepted no-ops and report counts preserve the source parser. Invalid-port
  0x4C is an accepted no-op without a report; invalid0x47–0x4A reports globally.
- Direct invalid-port bank submit fails before payload capture. Query results
  keep synchronous pending0, port count behavior and index/group masking.

The original sound mutex serializes the entire command prefix, including
queries and bank mixing, except while preparing an asset. A separate adapter
transaction mutex preserves that boundary over already-owned packet bytes.
It is released for payload capture/decode and reacquired for install. Reset and
queries share it; the already-admitted bank render must use adapter `mix_add`,
not bypass it to bare Session. Null/zero mix keeps the source fast no-op path.
CaptureSource callbacks execute outside this transaction. Asset deallocators
may run on control operations; the reviewed AllocationSource contract still
requires a concurrent, aligned, symmetric, nonreentrant memory provider.

## Stop, reset and integration limits

Producer `request_stop` is a nonblocking signal that closes new adapter Calls
and cancels pending capture before its next commit admission. An already
admitted short commit may finish after the signal returns; `join` waits all
complete Calls and is the terminal producer fence. Caller-owned Calls must be
released before joining, and CaptureSource callbacks must not synchronously
join their own operation. Pool and v2 submission release/destruction occur
outside the admission mutex.

Adapter stop does not stop the inner bank render owner. The aggregate worker
must first stop outer producer/provider admission and drain admitted whole
SoundCalls, including producers paused BEFORE their bank-table callback. It
must keep adapter `begin_call` and the inner bank owner open throughout that
drain, just as it keeps the bank half of an admitted render open. Then it can
signal/join this adapter and stop/join/clear inner bank/PCM state, with the actual
provider fenced before owners are released. Signalling adapter stop at the
initial outer stop would incorrectly reject those already-admitted RPCs.
This adapter alone proves no provider shutdown or whole-RPC retirement.

Bank reset uses v2 epoch invalidation: staged captures/preparations cannot install
after the reset. A reset returns current bank/query state to its source defaults;
it does not reset PCM routes, host category gains, the device or sound-status
IOP arena. Packet command0x43 unloads ports while retaining source bank storage;
it is not a whole Session reset.

`PacketResult` separates native status from the source parser bool. Runtime
integration must retain the original accepted RPC acknowledgement when that
bool is ignored by the source caller; diagnostics errors do not reinterpret the
RPC contract. No generic SIF transport, status-address/table arena, guest reply
write or end-callback migration is claimed. Those remain in the complete0124
facade/integration scope.

Unsupported packet/load report counts are retained, but the bounded native
diagnostic event kind uses `global_control` where the old observer did not expose
packet-opcode/load-id kind. No event-kind parity claim is made.

## Initial isolated validation (cohort1)

Identified post-expectations adapter cohort:
`1d80a3bc44694d7962a05f29d43d321fadeec772e1815ff3f6c45859651e51b7`.
All source and generated metadata use LF bytes. The identity binds the unchanged
budget-v2 LF cohort `77b6c1bc...`; the historical blind v1 identity is preserved.
Both verification drivers reject changed adapter or v2 prerequisite identities.

GCC15.2 and Clang21.1.8 each compile the actual production adapter/core objects
with warnings as errors and pass103 assertions. Cases cover packet/control pool
capacity before reads, partial constructor refund, source identity/refusal,
loaded0x4E unused-RAM skip without asset allocation, descriptor extents/physical
mask, malformed accepted prefix, reset during real packet/raw capture and
prepare allocation, stop plus complete producer join, retained Call lifetime,
whole-prefix render serialization and mutation of caller packet bytes after
the owned copy has completed. These are bounded deterministic fixture tests;
there is no timing-based game or real-RAM lease claim.

Both full-source comparisons route submits, queries, reset AND bank mix through
the production adapter and match all18cases/252actions,13,004 float words and
12,768 gain records, plus complete observed metadata/clip/request/voice/clock
state. The reused observer performs no expected-derived DSP or normalization.
Its CaptureSource is explicitly synthetic. All four source postchecks are empty.

The status bridge also compiles against the actual fresh125 reconstructed
`CriAudioBackend.h`, SHA256
`a47a63a67d8044b82b50e28ccef96612f4d75a30bbbb39386280fbf05047d47d`.
The verifier checks the full reapply receipt, every recorded source and all125
patch input hashes; receipt SHA256 is
`b11bc490b316dc5c5092612646bc7cf34f3c42d2e779c7d42fac40c90a560d09`.
No dirty active dependency or old runtime library is used. This object proves
the typed status/header contract, not actual runtime binding or selected-owner
registration.

Receipts under `build-native-sjuni/native-bank-packet-adapter`:

- `gcc-unit-v1`: `cfca89e3c87bec36b7d902a8b84b5a89df7b683fbd1d12295dfadd1a46fc2896`.
- `llvm-unit-v1`: `1a65c3327c9569eeb26cfc824df8dead2a4de77aa4ae584f049c06169955a064`.
- `gcc-original-v1`: `64b1dd86d4865f54881f569008fe02bc91486ab1019f0eaefae12930bcca5bec`.
- `llvm-original-v1`: `c516b868545d96f00f89fa931d4ede55f8452358ae1e90590005a05abe1f72c0`.

Actual Runtime/RAM coherent capture qualification, complete selected aggregate
owner/provider registration and rebuilt game validation are still required
before selecting this adapter. Neither these comparisons nor the public status
header object establish the sound-status arena or generic SIF migration.

## Source-order correction and final125 validation (cohort2)

Source review found that original124 reacquires its sound mutex after a failed
bank load, before returning the source false result. Cohort1 only reacquired
on success. Its measured prefix/state/DSP results above remain valid, but it did
not preserve that failure-return ordering against another active transaction.

The second cohort adds a narrow packet-load RAII guard: pre-relock capture or
preparation failures destroy staging while unlocked, then reacquire the packet
transaction before returning. Once relocked, stop/stale/install refusal can
destroy a PreparedBank under transaction, like ordinary control-side frees;
the explicit nonreentrant AllocationSource contract applies. Direct
`submitBank` remains unchanged. A gated failed-load fixture
holds a render transaction after a known volume prefix; failure cleanup must
complete, then submit must wait for that render before returning. The verifier
also compiles a private missing-relock variant and requires the same complete
adapter test to reject it. The negative control does not change authored source
or original expectations.

Cohort1 source bytes, identity and four receipts are preserved under
`build-native-sjuni/native-bank-packet-adapter/preserved-cohort-1`; its original
four output directories remain unchanged. The separately identified cohort2 is
`2d7efe5f594096d8e1083214341451bde5aa4396d1b7b37750c0a594e9f66616`.
It explicitly records the prior identity and correction, without changing the
historical blind core or its expected-observation history.

Both GCC and LLVM now pass109 assertions, including the failure-return test.
After explicit prepare, render and complete-staging-free gates, the test checks
100ms of noncompletion while render remains held, then releases it and verifies
the failure result/preserved volume prefix/suppressed suffix. Both deliberately
missing-relock private variants fail this same test at assertion104, establishing
that the test detects the missing ordering. This is a bounded synchronization
test; it is not a game performance measurement.

Both original comparisons again match18cases/252actions/13,004 float words/
12,768 gain records and complete observed state with zero differences. Both
status objects compile against FINAL fresh125 headers from
`dependency-bank-reapply-v3`, after the separate SifInit/DTX/status-copy control
closure. Header SHA256 is
`631db6363db9a8945711f5c305ed8bfb0628ca50b3625cc2492e2afb3987f126`;
full-reapply receipt SHA256 is
`3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a`.
Every recorded source and all125 patch inputs match that proof. All four
cohort2 postchecks are empty; its output directories are separate:

- `gcc-unit-v2`: `3bce1cdf65495f0e8cd6ae8d30e914dbb2019a263a686f2adaba50775a0a7cd5`.
- `llvm-unit-v2`: `fd652005b2ec2dfb667753e1d16b3ca7da7e841229c979835fe3023e9ae77558`.
- `gcc-original-v2`: `ef424d0edc970ade9bb9e7724e1946cdc3db0347e01c17f0bcbd3da86f92114b`.
- `llvm-original-v2`: `a50f60a26b7b6f52f155e79d73a5e1970724aad26dcc27d40435121c05a9e69a`.

```powershell
python recomp/overrides/native_banks/verify.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/native-bank-packet-adapter/gcc-unit-v2 `
  --runtime-lib build-native-sjuni/dependency-bank-reapply-v3/ps2xRuntime/src/lib
python recomp/overrides/native_banks/compare_original.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/native-bank-packet-adapter/gcc-original-v2
```
