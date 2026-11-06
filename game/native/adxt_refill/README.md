# Owned encoded-source refill

One typed owner for a real SJRB encoded ring shared by asynchronous refill and a
future decoder consumer. No guest addresses, register context, runtime headers,
duplicate encoded ring or mutable backing/Ring escape. This library is not wired
into a game build and is not a complete ADXT player.

The source-derived algorithm was authored **after** the independent original
refill corpus was generated and inspected. `frozen_identity.json` seals the
core/dependencies after both compiler unit checks and **before** the new paired
comparator was written. No blind reconstruction claim. The core passed the
paired comparison without a post-freeze algorithm change.

`EncodedSource` retains one full free grant while I/O is pending. One move-only
`DataLease` can concurrently hold already-published data. Read access is bounded
copying; no provider writes ring memory. `finish_data` returns the consumed
prefix to free and ungets the unread suffix. Token destructors do not return
credit. Lost tokens keep the owner busy. Foreign/moved/stale/duplicate returns
refuse, and owner/incarnation/request/consumer identities never wrap.

All owner methods, snapshots, lease reads and destruction require external
serialization. Provider workers only access private output and retained views.
Ring/target hooks are synchronous, read-only and nonreentrant. An actual
AsyncReadOwner/SerialWorker supplies the production backend; no extra worker or
global audio service is introduced. Constructor allocation/thread failure throws;
normal service is noexcept and reports bounded provider failure without fallback.

The native safety policy deliberately differs from original raw I/O:

- Complete exact provider results are staged privately and copied during later
  publication. Original synchronous ReqRd may already have changed unpublished
  free bytes; those intermediate bytes are not a parity target or production API.
- Normal stop/close drains accepted publication. It does not call
  AsyncReadOwner.cancel or join a worker. Close preserves buffered encoded bytes
  and existing consumer credit. Terminal shutdown/finalization is separate.
- Reset/replacement refuses pending I/O, active consumer credit or buffered data.
  Original reset could lose a reservation and permit unsafe reuse/late writes.
  Those original observations are preserved, not normalized in expected output.
- Invalid/wrong-ID provider completion retains an unretired producer grant and
  enters terminal error. It does not manufacture a fence or reuse storage.
- Emergency destruction joins the retained private backend and closes tokens;
  this is teardown policy, not ordinary stop or a claim of audible output drain.

The initial profile admits 2048/4096/8192-byte capacities plus36, one exact
whole-sector in-view source range, one queued/active/ready read and one data
lease. The caller must provide an immutable retained content view; production
mount/identity admission remains outside this portable core. An optional bounded
constructor bootstrap establishes preloaded bytes/position through actual ring
operations before hooks; it exposes no later mutable feed or restore API.

Maximum requested bytes are bounded by capacity, sectors by512, and the real
provider output+staging budget is twice its configured maximum read. Allocation
or provider exceptions become errors; no partial successful payload is published.
Config/range/geometry exceptions are rejected before callbacks/provider I/O.

Standalone CMake builds this library and its unchanged native dependencies:

```text
cmake -S game/native/adxt_refill -B build-native-sjuni/adxt-refill-checks
cmake --build build-native-sjuni/adxt-refill-checks
ctest --test-dir build-native-sjuni/adxt-refill-checks --output-on-failure
```

GCC and LLVM pass 2151 assertions, including a real blocked provider, stop/close
drain and explicit join, actual read/allocation failure and budget refusal,
simultaneous producer/consumer credits, wrap, foreign/duplicate/moved/abandoned
tokens, reentrant callback refusal, ID exhaustion and quiescent replacement.
Most assertion count comes from a full wrapped-payload comparison; it does not
represent thousands of independent scenarios. Standalone CMake/Ninja+CTest1/1
also passes.

Paired original comparison:

```text
python game/native/adxt_refill/compare_original.py --compiler g++ --output build-native-sjuni/adxt-refill-parity-new/gcc
python game/native/adxt_refill/compare_original.py --compiler clang++ --output build-native-sjuni/adxt-refill-parity-new/llvm
```

Use new output directories; earlier evidence is never overwritten. All29 frozen
original inputs are classified:25 admitted observable comparisons, one
before-construction partial-sector refusal, three pending-reset refusals. Both
compilers match97 state/callback/data observations and79,872 data bytes. A normal
data-lease read+unget0 observes published bytes without changing ring state.
Expected views come from190 additional actual original Get/Unget calls on clones
of the frozen original snapshots, not a host ring implementation. The derived
projection is saved before native compilation/output. No expected result enters
`fixture_runner.cpp`.

Receipts and retained input/output:
`build-native-sjuni/adxt-refill-native-parity-v2/{gcc,llvm}/receipt.json`.
V1 comparisons remain preserved; V2 tightens the comparator's allowed refusal
statuses and records comparator/transport identity, without changing the core.

See [design](../../../docs/native-media/ADXT_REFILL_NATIVE_CONTRACT.md),
[qualification](../../../docs/native-media/ADXT_REFILL_IMPLEMENTATION.md) and
[original oracle](../../../docs/native-media/ADXT_REFILL_ORACLE.md). Future Window
v2 must take this owner's actual data lease and return consumed bytes. The frozen
window's request256/total4096 bounds and mutating loop callbacks are unresolved;
source-derived requests1152/2240, long streams, header/LSC/clock/RNA ownership
still need separate qualification before game integration.
