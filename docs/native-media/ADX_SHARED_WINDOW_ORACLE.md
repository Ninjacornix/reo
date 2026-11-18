# Original shared-source ADXB window corpus

Status: bounded original-instruction evidence, 2026-11-06. This qualifies a
synthetic source/control domain for the proposed
[Window v2 contract](ADX_WINDOW_V2_CONTRACT.md). It does not implement native
Source2, Window2 or a codec workspace, run the game, access an audio device, or
prove a complete ADXT player. Frozen engines, cores and older fixtures were not
modified.

## Frozen evidence and reproduction

Authority: owned `game_data/SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The original function catalogue identifies complete intervals. The new
`tools/native_reconstruction/adx_shared_window_oracle.py` combines unchanged
EE/Ring/Window instruction runners and the already qualified compiled raw-bit
FP worker from [header math](ADX_HEADER_MATH_ORACLE.md). There is no new ISA
instruction implementation, substituted codec/ring/loop result, Python floating
point algorithm, or host expected decoder.

Final evidence is under `build-native-sjuni/adx-shared-window-oracle-v14`:

| Artifact | SHA-256 |
| --- | --- |
| `inputs.json`, authored and written before replay | `d3adee3434a56a218b6a67040ee44a2df99b1cdd813bcaf15c067d8d0adb4d46` |
| `manifest.json` | `e41b48940b06b95d5b5641160225e10b0902dd5808d9eaf1dca5b1aa0b127972` |

There are **39 cases: 35 complete returned transcripts and four explicit partial
cuts**. One returned case is a direct complete repeat-helper call with a prepared
caller, clearly labeled separately from a full ready/window transaction.
The complete cohort executes **6,510,610 original instructions**, reaches **4,051
unique words**, and audits 163 body identities against generated source comments:
**5,654 matched instruction comments, 92 omitted zero words, no omitted nonzero
word**. Overlapping body intervals are deduplicated in instruction/audit counts.

Each case file contains exact typed-layout bytes, actual ring state and
callback/entry snapshots, original instruction/return observations, FP raw state,
provider actions, initial backing bytes, and exact changed-byte runs with before
and after hashes. Scalar store sequence hashes/counts and event write indices
retain ordering evidence without duplicating every PCM store. There are no
per-case 32 MiB RAM dumps. The whole final directory is about 43 MiB.
PCM planes are contiguous; per-plane evidence windows overlap adjacent real
PCM, so only the outer PCM-arena edges are guards. Do not mislabel neighboring
channel samples as guard corruption.

The manifest pins every unchanged runner, owned body/table, raw-bit worker,
original math parent fixture and current oracle source. Old staged outputs
`v1` through `v13` are retained. Earlier missing-body/table cuts, a source-start
omission in prepared probes, and corrected test interpretations are not silently
rewritten. The final setup executes actual `130698` before setting the prepared
file cursor; source stop tests therefore exercise active-source gating.

```powershell
python tools/native_reconstruction/adx_shared_window_oracle.py `
  --output build-native-sjuni/adx-shared-window-oracle-NEW
python -m unittest discover -s tools/native_reconstruction `
  -p test_adx_shared_window_oracle.py -v
```

Use a new output directory; existing evidence is never overwritten. `--case NAME`
can replay selected cases while still freezing the full authored input file;
selection is recorded in the manifest. `--fp-worker` accepts the separately
qualified GCC or LLVM worker only when its original parent receipt and binary
hash match. Tests replay ten complete selected boundaries against **both**
workers, including all six ready configurations, pending-producer/two-span
transition, real file target callback, rejection and deferred header. The full
39-case cohort uses the qualified GCC worker; this does not claim a second full
long-stream LLVM replay or measured PS2 hardware FP equivalence.
All **14 unittest checks pass**; `qualification.json` records the source/test,
input/manifest and worker identities for that observed check run.

## Complete original routes and measured results

Ready setup executes actual `133FE0`, real metadata getters, request setter,
file target configuration and decoder limit installation. RNA wrappers run to
explicit external control edges. At divisor 60 and block size 32 the actual
returned requests are:

| Rate | No loop metadata | Positive loop metadata |
| --- | ---: | ---: |
| 24,000 | 640 | 1,216 |
| 44,100 | 1,152 | 2,240 |
| 48,000 | 1,216 | 2,432 |

These are original synthetic observations, not new game measurements or gameplay
frame rates. Positive parsed loop metadata determines this branch; the runtime
loop-enable flag is a distinct control.

The source audit exposed an additional setter obligation: `12CC10` stores
outer `+38` and executes **`123020` and `122E70`**, also setting inner
`B4=request`, `B8=trunc(request/96)`, `C0=request`, `C4=trunc(request/1536)`.
The complete bodies, including the null optional child path, are executed rather
than replaced by a guessed outer-field setter:

| Interval | SHA-256 |
| --- | --- |
| `123020..123084` | `5c2f64059e914c587dd25fee1792cc453c4c1981f4c72c867a891421f7ed8891` |
| `122E70..122E90` | `c6b2b0c5ef8b22221a24008f6fd5165025627f4702cfb313808b7b7524c5b69d` |

The optional child at inner `B0` remains null in this profile. No resampler/child
ownership claim follows from those extra counters.

Long mono 44.1 kHz, stereo 48 kHz and downmix 24 kHz transcripts each reach
exactly **40,017 decoded samples**, monotonically crossing 4,096, 8,192 and 32,768
without counter resets. They interleave real file refill, actual SJRB grants,
codec execution, PCM publication and channel credit. Separate complete loop
profiles execute real **2,240/2,432-sample** requests through mono and downmix
paths. A marker after 17 completed blocks/pairs checks a retained large-request
prefix; backpressure preserves zero progress and then recovers through actual
credit return. Full integer-limit safety is not established by these totals.

The decode route includes actual `12D638`, `12CFD8`, `12CEB8`, `125370`,
`135078`, mono/stereo/downmix kernel words, `125518`, and `12D338`. No host ring
or supplied predictor result replaces any of these operations. Actual header
initialization and finite coefficient math precede ready setup.

The loop corpus executes `133870`, real key/history snapshot, `133928`, padding
Get/Put and restore. Short padding diagnoses and still increments the loop
counter. File target callbacks execute **inside actual `130800`**, after accepted
prefix publication and reservation clearing. The physical-end pair reaches
progress sector 2 on a two-sector file: enabled looping rewinds it to 0 and
leaves source state 2; disabled looping leaves it at 2 and the subsequent actual
terminal branch sets state 3. Accepted cumulative bytes stay 2,048 in both.
This is an observed control dependency, not a simulated mutation after service.

Seamless cases execute complete `133D10`, original `126F20/126670`, two actual
SJRB Get calls, ordered split/Put/Unget, decoder stop/start, and actual qualified
header/math re-entry. First-span and second-span headers succeed. A pending
three-sector read retains its producer grant while **both positive consumer
spans** exist; data plus free legitimately remains below ring capacity. Partial
acceptance and error completion use the same actual ledger/disposition route.
Provider completion bytes are explicit synthetic inputs, not evidence of a
real filesystem completion fence.

A rejected or deferred next header retains consumed-prefix and selective reset
effects, updates accumulated samples, and clears seamless enable. Missing magic
restores the callback's grants in reverse order; the enclosing `12CFD8` then
continues and can consume end-marker/padding bytes. Do not claim whole-call
rollback merely because the nested callback restores its own grants. The
seamless next-rate change is a synthetic decoder-state probe; it does not prove
RNA/device clock reconfiguration or audible playback at the new rate.

Actual `1306E0` stop during pending I/O sets stop intent without canceling the
accepted write; a later actual service still publishes its accepted prefix.
No reset/reuse, provider join or new original generation fence is inferred.

## Explicit partials and excluded unsafe inputs

| Case | Exact cut | Preserved evidence / limit |
| --- | --- | --- |
| Negative end-record length | `126688`, word `84820000`, access `003F8098+2` | Original signed record length leads the scanner outside mapped input after two grants. Bounded access refuses. It is never an admitted native extent. |
| Next header filter 8,000 at 44.1 kHz | unowned fetch `120AE8` | Original next-header processing reaches unqualified math range reduction after prefix consumption and selective resets. No host cosine or fake coefficient is supplied. |
| No-file loop ready setup | `1307B4`, word `ACC5002C`, access `0000002C+4` | Original ready loop path calls file-target setter with null file. Separately, the direct `133928` no-file/disabled helper returns as observed. These are different caller domains. |
| Insufficient channel capacity | unowned fetch `1282A0` | Diagnostic integer formatting/stop closure remains unowned. The full early rejection is not claimed complete. |

Partials preserve held-grant/state/backing evidence; none is counted as a
successful native-admissible transaction. A returned original malformed-marker
case is still a protocol negative control, not evidence of valid media.

## Native boundary now supported, and remaining gates

The evidence supports designing one shared encoded owner with one producer and
two ordered consumers, concrete source-order file/seamless transitions, actual
typed header state, real request sizes, and long counters. It does not justify
changing frozen Source1 or merely increasing Window1's cap. The old allocating
codec interface still needs a separately qualified preallocated workspace before
mutating loop effects. Source1 has neither the second consumer ledger nor an
owned file-progress transition.

Before a native profile is claimed, review the precise transcript projection:
prepared queued prefixes and file cursor are inputs, raw producer intermediate
writes are intentionally outside the approved private-result staging policy,
and synthetic metadata/sample-byte relationships do not assert every real
asset's shape. Initial native admission must separately bound counters,
physical extents, loop geometry, optional child absence, supported finite math
and FP environment, channel/PCM geometry and owner/provider lifetimes.

Remaining exclusions include SJMEM mode2 reset, LSC filename replacement,
arbitrary divisor/rate/math domains, unbounded/wrapped long counters, mutating
user callbacks, asymmetric PCM admission, source reset with outstanding work,
full ready-configuration AINF policy and nonnull optional child branches,
device/RNA/DTR consumption credit, scheduler preemption and movie/audio clocks.
There is no native integration or stutter-fix claim. Native implementation and
its honest freeze/comparator come only after review of this original evidence.
