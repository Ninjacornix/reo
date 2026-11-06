# Native PCM/bank aggregate owner

Status: inert composite implementation and isolated tests, 2026-11-06. No actual
RuntimeCaptureFactory, bootstrap/preparer/CMake wiring, game/device run or complete
runtime/game link is supplied here. A qualified capture provider and output
endpoint must be injected; their type names and hashes do not prove qualification.
This closes the composite owner contract, not all of Stage3 or native audio.

## Frozen implementation and inputs

Implementation: [aggregate.h](../../recomp/overrides/native_audio/aggregate.h) and
[aggregate.cpp](../../recomp/overrides/native_audio/aggregate.cpp).
Pre-joint-expected [identity](../../recomp/overrides/native_audio/identity.json):
`bc33ed692ea0be697dcd0b8d3950e534c8dca3226dc62b119b8dfd3d1523a8db`.

| File | SHA-256 before new joint expectations were read |
| --- | --- |
| `aggregate.h` | `681bfd778a88aef6498f7ea4497afbacdbcc20270dfaef3c8d10d3f6fbdd23be` |
| `aggregate.cpp` | `40965f93dc35d5e665a98b096044dbe553c83cd217e0990d8cea63dbdf39dd77` |
| `tests.cpp` | `cbe8a15dbf9950112ed57908b976f2ad864f7dfe000fcc0651a47851cc03c28d` |
| `verify.py` | `1947475e5e58fb8b854852f7e88da8a87332b19266d96302deba3afbc196e010` |

The existing PCM core/bridge, audio output owner, allocator-accounted bank v2 and
packet adapter cohort2 are reused unchanged. No V1 Backend or actual
NativeStreamProvider is constructed. Actual125 V2 headers are qualified by
reapply receipt `3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a`.
The new joint original expected observations were not read before this freeze;
existing component original observations were already known. This is new glue
over source-derived components, not a new blind DSP reconstruction.

`create` always declares production2040 channels,2041 voices and391,680,000 PCM
sample bytes, plus4MiB raw-map metadata. `create_for_tests(TestDomain)` is the
explicit small-capacity test path; it permits arbitrary raw IDs for synthetic
transcripts and marks reports as testing. Both retain the component's existing
96,000 samples/channel and minimum12,000-frame headless/render allowance;
production/manual render cap is16,384, while the output callback contract caps
actual device frames at512. Bank render admission must cover the PCM render cap.
There is no environment or runtime installation helper in this component.

## One admitted composite render

The owned DeviceRenderer takes a temporary strong Aggregate lease from its weak
reference and calls **the actual facade `ps2_cri_audio::render`**. It never bypasses
Binding admission by calling the backend body directly. V2 `render_admitted`
receives that same SoundCall, serializes complete renders through an owner mutex
and lends a stack SoundCall pointer to the unchanged bridge Host for that render.
RAII clears the pointer before unlocking or releasing admission.

The bridge retains its original PCM/order/gain/phase work and drops PCM data locks
before Host.mix_banks. That hook invokes the existing SoundCall's `mix`; the bank
table routes it through PacketAdapter.mix_add, preserving prefix/load serialization.
No TLS owner selection or fresh bank admission occurs between the two stages.
TLS frames only detect device context/self-join. The test-only render probe can
pause exactly after PCM and before banks; it is absent from production creation.

Provider control never runs under PCM/bank/render state locks. Output-ready is
an atomic cached value, reserved before attach can publish a synchronous callback.
An ensure mutex serializes reserve/start/failure restoration. Stop retains a
previously active ready reservation until a real fence, preventing simultaneous
headless and live callback clocks. No callback performs logging or provider
lifecycle calls. All gain/clock/route/allocation hooks retain the inherited
pure/nonreentrant contracts.

The output slot, Provider, hooks and capture provider are strongly retained.
OutputOwner holds a Renderer with only a weak Aggregate reference, avoiding a
strong callback cycle. The registered Binding worker must retain its owner until
successful teardown; dropping its storage before join is not supported. The
injected stable slot must outlive every dispatch and the actual provider fence.

## Complete methods, capture and failure behavior

Registration supplies all11 PCM and8 bank callbacks in one V2 transaction.
Production PCM raw IDs remain zero or the File1 `[0x1e0000,0x1eff00)` stride32
profile. Queue/metadata/alias/gain refusals remain explicit; there is no legacy
fallback. Oversized render is checked before touching the supplied buffer. The
compatibility V1 render entry deliberately refuses: a V2 renderer must carry
the admitted SoundCall.

Each bank producer/query/reset callback obtains a bounded adapter Call inside its
outer SoundCall and destroys it before returning. QualifiedCaptureProvider lends
a synchronous CaptureSource through a stack operation. No operation or source
can escape, and success without exactly one operation, repeated operation or a
changed returned result is an explicit provider-contract fault. Identity is
supplied binding metadata, not actual Runtime/RAM verification. The factory must
retain actual storage/incarnation and a coherent read lease, validate raw borrows
and provide complete bounded copies. PCM queue borrows retain their existing
caller lifetime/coherence obligation too.

Ordinary PCM reset retains bank state; bank-only reset retains PCM/output/routes.
Native report_paths produces an actual bounded bank point snapshot through the
control hook; it refuses device-context I/O. It does not claim legacy printf or
reset-counter parity, nor a whole-prefix diagnostic snapshot. Game-state queries
and mixing retain the adapter transaction; diagnostic point snapshots use the
bank's own serialized observation.

## Stop, retry and reports

The initial stop only closes provider admission/caches closing. Binding closes
outer admission and drains **every** SoundCall before lifecycle callbacks run.
The aggregate leaves inner PCM, adapter and bank admission open throughout that
drain, including an accepted producer paused before its bank-table callback and
a render paused between PCM and banks.

After outer drain, control first fences/detaches/stops/unloads OutputOwner with no
PCM, bank, guest or RPC lock held. Any failed provider step retains every inner
core, packet pool, output slot and resource for retry; no joined report or early
reset follows. Successful fence captures PCM statistics/clock, full bank state,
asset/control budgets and supplied profile metadata **before** core clearing.
Then unchanged bridge shutdown clears PCM/routes, whose terminal bank hook stops/
joins adapter producers and closes/joins inner banks. Direct owner and outer
facade self-join are refused. Provider stop does not close the application device.

The saved report preserves those pre-clear numeric observations and emits once
after successful cleanup, outside lifecycle locks. An incomplete fenced snapshot
remains inspectable without claiming owner_joined. Method arrays label delivered
attempts, successful completions and refusals; a completed no-op does not prove
audible output. Callback counts cover DeviceRenderer entries/completions, not OS
underruns. PCM underrun_frames retains its missing-source-voice meaning. Bank
path counters have an explicit enabled flag; disabled zero counters do not mean
no bank work. Self-refusal counters are owner-local; Binding refusals that never
enter this owner are not counted. Stop/join counters count owner invocations.
Requested asset/control bytes and declared PCM storage exclude heap bookkeeping,
fixed owner/diagnostic/scheduler administration and external services; no RSS
budget is claimed.

## Isolated verification and comparison boundary

Both GCC15.2 and Clang21.1.8 passed12 fresh-process unit/lifetime modes and a
separate production-object compile against actual125 headers (14checks each).
The modes cover all19 completed methods, no C++ ordinary/aligned callback alloc/
free, exact PCM-to-bank stop continuation, pre-table producer continuation,
paused producer drain, failed-fence retention/retry, synchronous attach callback,
headless clock, callback self-join guards, weak-cycle lifetime, raw provider
contract refusal and oversized output with a tiny untouched buffer.

Receipts under `build-native-sjuni/native-audio-aggregate`:

| Receipt | SHA-256 |
| --- | --- |
| `gcc-v3/receipt.json` | `4a5335ba38cf8133d5922c4de550c32190bb0fe0f9cd5844f0e73e7627af32d1` |
| `llvm-v1/receipt.json` | `d87f58c658e7f87ddc61763274fcf7e7151f6ad18c831bd6011a9e99d1704d4e` |

The input-only joint comparator was authored after the freeze. Against the
independent unchanged124 PCM plus real-bank reference, both toolchains observed
21 cases / 287 actions, 9,316 exact PCM float words and 10,052 ordered hooks
(including 9,856 bank gains). Applicable reference observations agree: PCM/bank
state, clocks, samples and hook values/order. The raw comparator result is
**different**, with exactly14 declared terminal-policy differences, retained
without normalization in each output's `differences.json`.

All14 paths are `$[20].actions[9].state.bank.ports[i][3]`, for ports0 through13:
`shutdown_both`, terminal shutdown action9, followed by the observer's `portState`
query. Original legacy writes count0; closed V2 refuses that query and preserves
the supplied count sentinel999, as required by the declared0124 closed-query
policy. This is a refused terminal observation, not a successful query claiming
999 active requests. No other raw differences occurred. These results do not
claim raw equality across shutdown behavior.

| Raw comparison receipt | SHA-256 |
| --- | --- |
| `gcc-original-v3/receipt.json` | `776ec8b83c4f007d20322bb9eb693f039563e0ea42fe29f7d5903c5f0709f15e` |
| `llvm-original-v1/receipt.json` | `db75dd1cf35655253f2ffcdf247571ba155ace2b6de5459f058675f7c8df503b` |

The [qualification summary](../../recomp/overrides/native_audio/comparison_qualification.json)
(SHA-256 `6fdc7ca313d679f9f42124f313bf3776e3fe1bf3f64ff771e7fb4a4e9029dac3`) identifies the raw receipts,
actual observations, full14 paths via the raw difference hashes, transport and
actual-object project inputs. Both production objects include11 identified
project inputs, checked against the unit authored-input identities or the full125
source reapply receipt. System headers/toolchain libraries are outside that
project-input list; the compiler executable is separately hashed in each receipt.
The independent original receipt is
`b142dd116ef7c81b03c9795462a324ab413a29baa8d4147c098225adfd20da57`;
its input manifest is
`59a6d270ae310d78444354325b6d8edcd0d4c4891b4283425be38887a304fc91`.
No frozen implementation or expected value changed during comparison.

Actual capture qualification remains separate. The
[runtime capture review](NATIVE_BANK_RUNTIME_CAPTURE_REVIEW.md) and independently
issued CD configuration seals address only their stated parts of the writer/
reader/lifetime/parent-authority problem. A supplied hash, guest depth or seal
alone is not complete capture qualification. No device/game/full-build behavior,
performance improvement, unrestricted profile or complete Stage3 claim follows
from these mocks/header objects. Callback serialization is stronger than an
arbitrary pair of concurrent manual legacy renders; the intended profile has
the serialized actual provider callback and explicitly controlled manual tests.
