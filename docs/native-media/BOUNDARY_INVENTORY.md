# Native media boundary inventory

Status: static source review and bounded original-word fixtures, 2026-11-05.
This inventory's source audit did not launch the game or capture audio. Later
private runtime tests are recorded separately in the resource candidate record;
no performance improvement or whole-media migration is established.

The reusable host PCM output is already substantially native. Compressed ADX input,
decode scheduling, SJ chunk publication, playback position, looping and stop remain
owned by the original EE-side chain. The standalone `media/adx` implementation has
concrete correctness gaps; `media/sofdec` is a placeholder. Connecting either class
to the resource core would not establish a complete media replacement.

The smallest next *control* unit is the synchronous predictor phase/window helpers
covered by the new fixture below. The first useful complete *codec* unit is the
mono keyed block kernel `main:001276D8`, beneath that owner. Its
[positive original-word oracle](ADX_DECODE_ORACLE.md) and
[independent native implementation](../../game/native/adx_block/README.md) now
match 104 cases / 4,032 PCM samples with both compilers. The
[native scalar control core](../../game/native/adx_control/README.md) also matches
the 96 phase/window calls. Control remains unwired; mono has a default-off
temporary adapter awaiting live decode proof. Keep the original SJ/ADXT/RNA
owner, sample clock and stop policy while validating their temporary adapters.

## Source and build boundary

| Layer | Existing source and actual boundary | State / next gate |
| --- | --- | --- |
| Byte source | [ByteView](../../game/native/resources/byte_view.hpp), [ResourceSession](../../game/native/resources/resource_session.hpp), and [resource inventory](../native-resources/RESOURCE_BOUNDARY_INVENTORY.md) provide bounded positioned byte reads and native view leases. | Implemented/tested independently. A resource read does not constitute an SJ borrow, decoder completion, loop point, or playback position. Retain a view lease for native compressed data; do not turn a guest SJ pointer into a durable native view. |
| Standalone ADX | [adx_decoder.h](../../media/adx/adx_decoder.h), [adx_decoder.cpp](../../media/adx/adx_decoder.cpp) own a whole-file vector and return caller-buffer PCM. | Host C++ without guest types, but no incremental/refill contract and incorrect decoder/control behavior listed below. Not admitted as a parity implementation. |
| Standalone SFD | [sofdec_decoder.cpp](../../media/sofdec/sofdec_decoder.cpp:41) accepts a minimal pack/CRID prefix and assigns default dimensions/rate; video emits black, audio emits zero samples, demux always fails and seek does nothing. | Scaffolding, not a functioning native SFD demux/decoder/player. |
| PCM transport/output | Runtime `CriAudio::queue`, `configure`, `render`, `tick`, `drain`, `discard`, `reset` and `shutdown`; see version distinction below. | Implemented native PCM ownership and host output clock, but process-global runtime/raylib/backend integration rather than an independent media-session API. No compressed ADX decoding here. |
| Bus/endpoint controls | [mixer.h](../../runtime/audio/mixer.h), [host_bridge.h](../../runtime/audio/host_bridge.h), [reo_output_device.h](../../runtime/audio/reo_output_device.h), [reo_audio.h](../../recomp/overrides/reo_audio.h). | Native mixer percentages, bounded stream-route table, host settings bridge and WASAPI endpoint selection. Original stream-start/frame functions are delegated, not replaced. |
| Original compressed owner | ADXB borrows encoded and PCM spans; ADXT services predictor work and owns stream/loop/clock decisions. | Mapped source; only the bounded phase/window portion below has new executable offline fixtures. No full native player parity claim. |
| Native movie IMAGE support | [native_movie_image.h](../../third_party/PS2Recomp/ps2xRuntime/src/lib/native_movie_image.h:12) owns prepared image epochs/bytes and GS-consumer fence obligations; lookup still takes runtime/source-event identity. | GPU image ownership is a separate boundary. It supplies no SFD packet demux, compressed-source lifetime or media clock replacement. No experimental path was enabled. |
| Existing production movie parsing/decoding | [mpeg2_stream.h](../../tools/parallel_gs_backend/movie_runtime/mpeg2_stream.h) supplies incremental program/elementary stream parsing, bounded pending buffers, picture controls and PES timestamps; [MovieSession](../../tools/parallel_gs_backend/movie_runtime/movie_session.h) orders native decoder output and tracks real image-consumer fences. | Reusable implemented code, distinct from the unused `media/sofdec` placeholder. Windows DXVA/D3D11/Vulkan coupling and graphics-owner lifetime remain explicit; source review is not new decoder/output parity evidence. |
| Existing original/native movie bridge | [native_movie_game.cpp](../../tools/parallel_gs_backend/movie_runtime/native_movie_game.cpp), [original_transport_route.cpp](../../tools/parallel_gs_backend/movie_runtime/original_transport_route.cpp) and [native_movie_transport.h](../../tools/parallel_gs_backend/movie_runtime/native_movie_transport.h) bind original entry/return PCs and guest source spans to generations, timestamps, original frame-return events and same-device GPU work. | Reuse the native parser/decoder/fence work. Migrate original compressed-source, playback-due, audio-clock, seek/loop and final-client-return authority before retiring these guest/runtime adapters. A successful movie picture does not establish a standalone native player. |

The source search for `AdxDecoder`/`SofdecDecoder` in repository C++ headers and
implementations, excluding the dependency checkout, found only their declarations
and method definitions. [media/CMakeLists.txt](../../media/CMakeLists.txt) builds
them into `reo_media`, linked by the generic root target. The production
[recomp target](../../recomp/CMakeLists.txt:577) and the audited worker candidate
`build-native-sjuni/candidate-inputs-v2c/compile-plan.json` include
`media/tim2/tim2_loader.cpp`, not these two codec translation units. This is a
source/plan finding, not proof of the contents of an unidentified live executable.
That plan SHA-256 is
`5cb860e2a7dee958a971414296ee4446dae6e31d5b596a01e82d8b4003ebffbc`;
its linked build and process identities are recorded in
[candidate validation](../native-resources/CANDIDATE_VALIDATION.md).

## Existing host PCM contract and source coherence

Two inspected runtime sources differ materially. The active
`third_party/PS2Recomp` audio code is not identical to the freshly reconstructed
`build-native-sjuni/dependency-workers-v1` public c46d1c7d + 0001..0120 patch series.
Do not combine their stop/release behavior or infer matching compiled libraries.
The [dependency patch workflow](../../third_party/patches/README.md) applies.

The common native output contract, from complete `CriAudio` source and relevant
RPC producer/return paths, is:

* `queue(key, bytes, length, endByte)` accepts nonzero keys/pointers and positive,
  even byte lengths no larger than `0x4000`, with a bounded per-channel backlog.
  Successful calls copy planar signed PCM16 into native deques; the input pointer
  is not retained by that queue. Queued/consumed counters and `endByte` are bytes,
  not ADX bytes or samples.
* `configure` binds left/right keys, channel count, frequency, volume and playing
  state. Host render requests are stereo float frames at 48 kHz; source frequency
  controls phase advancement. A consumed PCM16 channel sample advances its byte
  counter by two. Source frequency is clamped to 8..96 kHz, with a 48 kHz default.
* Underruns produce silence and accrue late samples; later arriving samples can
  be skipped to recover timing. Thus consumed byte position is not solely a count
  of samples audibly presented. Before actual external output takes over, the
  headless wall-clock fallback advances in bounded tick intervals.
* `configure(playing=false)` retains queued data. `drain` continues playing queued
  PCM then stops; `discard` clears a channel and advances consumed to queued.
  These are observably different policies.

The EE RPC path explicitly receives **decoded planar PCM16**. `collectSjxReplies`
returns chunks when `consumed + 0x6000 >= endByte`, then tracks retirement; the
lead models an IOP PCM buffer. Copying into the host queue therefore does **not**
authorize immediate SJ credit return, nor does a reply imply those bytes have
already reached the speakers. See the source-qualified `RPC.cpp` paths below.

The reconstructed public source has voice `release`, master/per-stream gain hooks,
and the [0113 destroy-release](../../third_party/patches/ps2recomp/0113-cri-release-destroyed-rna-voices.patch)
and [0118 short-tail policy](../../third_party/patches/ps2recomp/0118-audio-keep-short-speech-tails.patch).
Its long/unreturned stop path can discard/release, while short tails drain. The
active checkout instead labels its policy diagnostic build 90, always drains,
lacks `release`, and does not release a host voice at RNA destruction. This is a
source-coherence gate before choosing any future native media stop contract.

| Source identity | SHA-256 of inspected file |
| --- | --- |
| Public reconstructed `.../Helpers/CriAudio.cpp` | `39dce6882e561ad69a0112a330ecc4023a98c21365ac2fe8709f838fce4c9a06` |
| Public reconstructed `.../Syscalls/RPC.cpp` | `050d63e738481ac592429a21ba317fcb28f86f8d47afe48b2ee4ed8c3dc81a9f` |
| Active [CriAudio.cpp](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.cpp) | `c282e974b68af687a9e9b8c6c1e3b79195fe4e3167f3f26ef64026f71628d8fe` |
| Active [RPC.cpp](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp:681) | `3c9f279e0431182fc6f932638c5e62e99ed91e1d33239d2a8a7af291f0a143d9` |

In the reconstructed source, `CriAudio::queue` starts at line 198, configure at
234 and drain/discard/release at 264/274/277. RPC reply collection starts at 696,
the EE-decoded PCM comment at 809, and the queue producer is near 1030. These
references identify the inspected private reconstruction, not portable line
numbers in the different active source.

## Why the standalone ADX class cannot be substituted

These are source findings, not observed gameplay failures:

1. [Header parsing](../../media/adx/adx_decoder.cpp:38) checks six available bytes
   then reads through offset 18. It does not validate the advertised CRI signature,
   supported encoding, positive rate, block geometry or one/two-channel bound.
   Zero channels/block size can prevent progress; more than two channels exceeds
   its two channel-state objects. A failed reopen also leaves prior `m_open` true.
2. [Sample decode](../../media/adx/adx_decoder.cpp:97) sign-extends **after** its
   caller multiplies the raw nibble by scale. For example raw nibble 7, scale 2
   becomes 14 and is incorrectly adjusted to -2. The original kernel sign-extends
   the four-bit value first. Its masked `+1` scale, keyed header, early marker and
   word arithmetic also differ from this class's raw big-endian scale.
3. [Stereo decode](../../media/adx/adx_decoder.cpp:135) advances the frame index
   only on the final channel. Consequently channel zero repeatedly overwrites
   the same left output location while consuming its block. Stopping mid-block
   advances the whole compressed block and loses unproduced samples.
4. [Seek](../../media/adx/adx_decoder.cpp:92) ignores its sample argument and resets.
   Header sample limit and declared loop fields are not implemented. Whole-file
   `ifstream` loading checks neither complete read nor a bounded resource-session
   contract. Its double coefficient calculation is not proven equivalent to the
   original COP1 single-precision/trig/conversion sequence at `126510`.

Inspection identity: `adx_decoder.cpp` SHA-256
`f8c4007c7cd94e72104126fa1e6ba154fc7d9f5fc4799afebf4c1cddbc452ac9`;
`sofdec_decoder.cpp` SHA-256
`e687b4107e24d57dc1d4841f99d1df7bff62460be36045d17a0915db5b750337`.

## Original owner: units, borrowed spans and lifecycle

The existing notebooks remain the authoritative function mappings. The following
are the boundary consequences, not new names or replacement aliases.

| Source / PCs | Constraint on native integration |
| --- | --- |
| [ADXB header/input/output](../SYMBOLS_ADXB_HEADER_INPUT_AND_OUTPUT_SERVICE.md), `12CCE0`, `12CEB8`, `12CFD8`, `12D338`, `12D500` | Compressed SJ borrows and per-channel PCM reservations have distinct lifetimes. PCM sample budgets derive from byte spans divided by two. `12D338` returns consumed encoded prefixes, ungets suffixes, splits produced/free PCM spans and invokes the optional PCM callback before output `Put`. Some formats return a source span before pointer use. This is not a universal immutable contiguous-stream contract. |
| [Decode window/accounting](../SYMBOLS_ADXB_DECODE_WINDOW_AND_WRAP_ACCOUNTING.md), `125370`, `125518` | Encoded blocks, per-channel samples, output halfwords and byte counts are different units. Signed division, odd stereo counts and wrap-copy extension matter. Native `read_exact` EOF/error semantics cannot replace their accounting. |
| [Predictor context/dispatch](../SYMBOLS_ADX_PREDICTOR_CONTEXT_AND_WORK_DISPATCH.md), `134DE0`, `135078`, `135170` | Sixteen fixed `0x3C` contexts; `135078` is synchronous CPU dispatch, publishes result then phase 3. No worker/IOP/VU submission in this dispatcher. New kernel must return to this owner; do not infer asynchronous cancellation from phase reset. |
| [Construction/start/stop](../SYMBOLS_ADXT_CONSTRUCTION_START_STOP_AND_DIAGNOSTICS.md), `1315E0`, `131D98` | Caller work area is borrowed/aligned; per-channel PCM area `0x40C0` bytes includes capacity and extension, encoded ring has its own sector rounding/extension. Stop disables play/transfer and predictor work; destroys current input `+14` only in mode 2, and does not itself stop file `+8`/LSC `+94`. |
| [Loop/drain](../SYMBOLS_ADXT_HEADER_LOOP_AND_DRAIN_TRANSITIONS.md) | Loop transition snapshots/restores predictor history and key, not merely a source byte seek. Stall counters count service calls; do not turn their thresholds into milliseconds. |
| [Position/estimated clock](../SYMBOLS_ADXT_SAMPLE_POSITION_AND_ESTIMATED_CLOCK.md), `132028`, `132160`, and complete pause `132E50..132F7C` | Position subtracts RNA occupancy and PCM queued samples from decode progress. Estimated time rebases against that position with a tolerance. Pause changes play gating, tick baseline and stored estimate, not only host output playing. Tick source `20F3C4` is not proven a game-frame counter. |
| [SFD stream adapters](../SYMBOLS_MWSFD_FILE_STREAM_AND_ADXT_ADAPTERS.md), `164700..164728` | Stop invokes `130748` pump/wait-stop then `130560` wait-close; no new timeout or cancellation completion may be invented. |
| [SFD source/SJ](../SYMBOLS_SOFDEC_BORROWED_SOURCE_AND_SJ_PEEK_MOVE.md), `166E68`, `167168`, `1672E0` | Source types distinguish borrowed storage from owned SJ; copying a 24-byte descriptor is not copying payload. Two-span peek returns both borrows; returned raw pointer lifetime is not established for asynchronous use. Requested consumption and actual movement can differ. |
| [SFD two-span/cache](../SYMBOLS_SOFDEC_VIDEO_TWO_SPAN_PREFIX_AND_CACHE_BOUNDARIES.md), [per-player service](../SYMBOLS_MWSFD_PER_PLAYER_SERVICE_GATES_AND_FLAGS.md) | Prefix parsing crosses two spans with a three-byte bridge; cached end pointers and service busy flags are not a native lease or proven OS mutex. Original decoder/progress calls remain necessary. |

## New bounded original-word evidence

[adx_phase_oracle.py](../../tools/native_reconstruction/adx_phase_oracle.py) uses the
unchanged integer instruction engine from `sjuni_oracle.py`, owned ELF instruction
fetch and isolated synthetic memory. It imports no native ADX algorithm and ships
no copied instruction arrays. The only substituted external call is an exact
eight-byte `memset` of predictor history. Unknown operations, fetches, instructions,
unexpected hook arguments and step exhaustion fail closed. Pointer values are
synthetic borrowed IDs, not retained media data.

Owned File #1 US ELF SHA-256:
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The loader rejects other content. Fixtures record per-body hashes, generator and
engine hashes, call arguments, defined returns, full relevant synthetic memory,
visited PCs and hook observations. The nine complete body intervals are:

| Entry | Exclusive end | Measured scalar contract |
| --- | --- | --- |
| `134F98` | `134FA0` | Return phase word. |
| `134FA0` / `134FD0` | `134FD0` / `135000` | Idle-only mono/stereo pointer/count configuration; return one accepted, zero nonidle. |
| `135000` | `13501C` | Idle clears completed and sets phase 1; **returns one even when nonidle**, due to the original branch delay slot. Return alone is not acceptance. |
| `135020` | `135044` | Clear phase and eight history bytes; preserve completed, pointers/count, coefficients/key and payload. This is not a wait/join acknowledgement. |
| `135048` | `135060` | Only phase 3 returns to idle; preserve completed. |
| `135060` | `135068` | Return completed word. |
| `1252D0` / `125318` | `125318` / `125370` | Mono count unchanged; stereo count doubled with word wrap. Output address is base plus twice offset; stereo right address adds twice channel spacing. Wrappers ignore configure return and tail-request. |

The 16 cases / 96 calls / 688 bounded runner steps cover initial phases 0..3,
mono/stereo configuration, request, acknowledgement, cancel, retained completion,
zero/positive/negative/maximum-signed window counts and word-wrapped output offsets.
The fixtures do **not** decode compressed data, produce PCM, run `135078`, or prove
positive codec arithmetic, concurrent operation, stream refill, stop/join, EOS or
real device timing. Raw return registers of void helpers are observations only.

Reproduce:

```text
python tools/native_reconstruction/adx_phase_oracle.py
python -m unittest discover -s tools/native_reconstruction -p test_adx_phase_oracle.py -v
```

Six tests pass. Generated ignored `build-native-sjuni/adx-phase-fixtures.json` is
1,090,720 bytes. Source-comment/owned-word reconciliation for the nine complete
bodies found 88 matching comment words plus two omitted zero words, no conflicts
or omitted nonzero words. Including the additionally read complete `1276D8`,
`135078`, `12D338`, `131D98`, `132E50`, `164700` bodies gives 499 matching comment
words and nine omitted zero words, again zero conflicts/nonzero omissions.

## Concrete next implementation and parity gates

Implementation update: the independent [control](../../game/native/adx_control/README.md)
and [mono](../../game/native/adx_block/README.md) cores now pass their bounded
original-code comparisons. The [stereo/downmix core](../../game/native/adx_stereo/README.md)
also matches 522 independently generated cases with GCC and LLVM; its
[oracle record](ADX_STEREO_ORACLE.md) describes the added isolated DIV model.
The guarded mono and stereo adapters now have executed-body evidence from the
completed private V6 opening-movie runs. The [candidate record](CANDIDATE_VALIDATION.md)
also includes V7's complete native PCM backend: actual callbacks and clean joined
shutdown, with unresolved starved frames and long movie presentation gaps.
These bounded runs do not establish full media lifecycle equivalence or justify
enabling experimental replacements in the player build.
The [exact-source PCM study](PCM_OWNER_EXTRACTION.md) establishes the next owner
boundary and separates early whole-SJ credit from buffer retirement. The list
below retains the original implementation dependency order; completed isolated kernels do not close the
remaining publication, device and player lifecycle gates.

Current next ownership cuts are described in the [ADX stream inventory](ADX_STREAM_NATIVE_BOUNDARY.md),
[bank session](BANK_SESSION_IMPLEMENTATION.md) and
[movie clock inventory](MOVIE_CLOCK_NATIVE_BOUNDARY.md). ADXT's actual compressed
and PCM rings are SJRB, so the completed SJUNI pilot cannot stand in for those
borrows, wrap-copy and publication rules. Original queue comparisons, bank DSP
comparison, aggregate bank/RPC admission and movie-control transitions remain
distinct validation work.

1. Implement a small ordinary typed predictor-control state from the nine scalar
   helpers and compare it against these independent fixtures. Keep guest layout
   conversion in a temporary bridge, preserve exact selective writes and fallback
   before publication. Do not treat `request == 1` as acceptance or cancel as join.
2. Add independently checked EE three-operand `MULT`/`MULT1` semantics to an offline
   oracle before admitting positive `1276D8` PCM fixtures. The existing engine does
   not implement the required forms; no extension or positive decode result is
   claimed here. Test every nibble, extreme coefficients/history, scale/key wrap,
   early marker after prior blocks, and nonpositive requested counts.
3. Introduce a synchronous mono kernel with bounded encoded/PCM spans, signed
   halfword coefficients/history and mutable 15-bit key state. One admitted block
   is 18 encoded bytes and 32 PCM16 samples. Preserve wrapping products/additions,
   saturation, returned block count, and the early-marker asymmetry: prior key/PCM
   effects remain, but local history is not committed. Preflight span capacity,
   aliasing and supported arguments before effects; retain original owner and
   callback order. Supply precomputed original coefficients initially, avoiding
   unproven host-double/trig equivalence.
4. Only after mono parity, extend independently to keyed stereo and other selected
   kernels. Unkeyed `126FE8`/`127158` use COP1 float history/conversion and no integer
   saturation branches; they are not interchangeable with the integer kernel.
5. Broaden to ADXB/SJ publication, loop, pause/clock or SFD controls only with new
   independent request/borrow/return and terminal-state fixtures. Correlate native
   resource leases with actual source generations before async commit, establish
   finite stop/reopen lifetime, and settle the source-qualified PCM stop policy.
   Native resource bytes alone do not supply these protocols.

This boundary permits a real native CPU decode replacement without first replacing
stream ownership or movie timing. It does not establish that decode is a measured
slowdown bottleneck, that gameplay/cutscene speed will improve, or that media has
already migrated.


## 2026-11-07: connected movie buffering

The prepared native timing Context now executes complete pause/resume buffering
predicates against its authoritative cached clock and retained native queue
adapters. Both compilers match 401 original workflows (804 operations; 1,205
initial/final snapshots). Seven deliberate faults are rejected; 29 ownership and
refusal checks and all 66 standalone suites pass. The first 202 original cases
preceded native buffering; 199 explicit audio-clock cases were then added without
changing those earlier inputs/results. See the
[buffering qualification](../../game/native/movie_timing_context/buffering_qualification.json)
and [integration contract](MOVIE_TIMING_CONTEXT_CONTRACT.md).

This closes complete buffering predicates in the serialized prepared profile.
It does not close component command execution, skip/frame publication, source/
frame lifecycle, movie construction/rebuild, scheduler binding or real game
integration. Stage 3 remains open; stages 4-6 have not started. No game or real
audio device was opened for this qualification.


## 2026-11-07: joined native movie audio controls

Pause/resume and frame-step commands now bind the prepared channel-7/decoder-3
audio graph to the actual native ADXT Session and the same movie filter owner.
Both compilers match 206 pre-native original cases/810 operations/1,016 initial
and final snapshots. Eight deliberate faults are detected. Six actual native
source/decoder/PCM configurations (mono/stereo at 24, 44.1 and 48 kHz) each pass
eight buffering/user/frame/resume cycles, plus injected failures, foreign/stale
keys and provider shutdown retry. All 67 standalone suites pass per compiler.
See the [control contract](MOVIE_AUDIO_CONTROL_CONTRACT.md) and
[qualification](../../game/native/movie_timing_context/audio_commands_qualification.json).

The original comparison declares SDK control ports; prior independent SDK
qualifications remain separate. Native owner tests use a device model. There
was no real audio-device/game launch or new performance measurement. The three
requested native audio-control items are complete within this boundary; video
publication/ownership, movie lifecycle, scheduler and game integration remain
in stage 3 for the next agreed scope.

## 2026-11-07: timed video ownership and actual GPU fences

The prepared native movie Context now owns video selection/publication through
opaque frame keys. Its existing cached clock decides hold/present and bounded
late skip. Both compilers match 218 original cases/662 operations/880 snapshots,
including public get/release, previous-picture publication and cached-clock
frame stepping. The first 199 cases preceded the native video candidate;
eight deliberate faults are rejected. All 68 standalone suites pass per
compiler, including native audio Session hold/step/resume with a device model.

The same-owner D3D11/Vulkan adapter retains exact decoder export tickets, keeps
untimed frames unpublished, and uses actual producer/consumer fences to retire
storage. An offscreen RX 570 test decoded a verified File #1 compressed I frame,
copied real GPU pixels, blocked reuse behind a host-controlled renderer fence,
then verified retirement/reuse and close with a pending timestamp. Production
polling never substitutes elapsed time for completion. See the
[results](MOVIE_VIDEO_FRAMES_RESULTS.md), [contract](MOVIE_VIDEO_FRAMES_CONTRACT.md)
and [qualification](../../game/native/movie_timing_context/video_qualification.json).

The original semantic comparison excludes the legacy pixel payload/pointer ABI
and pure guard observations in primitive pool cases; joined public cases compare
guard/callback snapshots. The GPU fixture is separate evidence for real image
and fence ownership. It is not a whole-stream I/P/B comparison or a game/monitor
presentation test. No audio device was opened, audible A/V sync was not tested,
and production selection remains unchanged. Movie construction/stop/rebuild,
full codec skip/recovery, scheduler/game binding and transition tests remain
in stage 3; stages 4-6 remain open.

## 2026-11-07: native lifecycle policy and physical movie graphs

`game/native/movie_lifecycle` implements construction/start/reset/stop/rebuild/
destroy policy and separate source/audio/video graph ownership. Both compilers
match 176 original cases/179 operations/355 snapshots; eight deliberately wrong
policies are rejected. The indexed and nine-component dispatch bodies execute
from the owned ELF with explicit installed-method and child-initializer ports.
Physical tests use actual bounded source workers, native ADXT Session streams,
timing Contexts and VideoFrames; all 69 standalone suites pass per compiler.

The actual RX 570 lifecycle fixture constructs two same-device native GPU
graphs. It proves that an unsignaled real reader fence prevents reconstruction
and that the replacement reads/decodes the same first-frame pixels. Failed
scopes are retained: initial harness setup omitted the native library receipt;
the next GPU attempts exposed the prepared graph's timestamp admission gap.
No failure was relabeled as a game reproduction. See the
[results](MOVIE_LIFECYCLE_RESULTS.md), [contract](MOVIE_LIFECYCLE_CONTRACT.md)
and [qualification](../../game/native/movie_lifecycle/qualification.json).

Native graph construction remains prepared: audio takes an independently
demuxed ADX view; the existing video PES parser does not implement Sofdec audio
demux. Some later pictures in the owned clip lack individual PES timestamps,
which the strict graph refuses. The GPU result covers first-frame decode and
stop/rebuild ownership, not whole-stream playback or audible synchronization.
Logical-to-physical command/scheduler binding, timestamp reconstruction, native
Sofdec audio routing and real game transitions remain before media migration.
No production path or original game speed changed, and stage 3 remains open.
