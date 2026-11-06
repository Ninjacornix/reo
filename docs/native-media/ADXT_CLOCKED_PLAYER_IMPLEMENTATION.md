# Live native player clock composition

Status: bounded clock/player composition implemented and compared with original
instructions under both exact compilers. **Stage3 remains open.** No game ran,
no audio device opened and no runtime default changed.

The [contract](ADXT_CLOCKED_PLAYER_CONTRACT.md) and
[player](../../game/native/adxt_clocked_player/player.hpp) connect the unchanged
prepared clock core to actual decoder/PCM/shared-output observations. Supplied
tick values retain the original clock's units; service calls and audio frames
are never counted as game ticks. The initial tag0 profile uses16-bit depth and
no seamless/A4 offset. Original decoded counters, PCM bytes, output occupied
samples, frequency, total and modulo32 time base form the raw observation.

Actual output pause/resume happens before the canonical raw-baseline snapshot.
A private scratch execution of the pure core first checks admission without
canonical/output effects. The original signed argument comparison and low-byte
storage remain intact: argument1 pauses, argument2 resumes audio while storing
byte2, and an unchanged signed argument performs no new output operation.
Startup, rebases and pause/resume synchronize canonical clock origins with the
playback controller. Retired pre-clear queue evidence is explicitly invalid as
a live clock observation.

Both GCC15.2 and bundled UCRT LLVM21.1.8 pass the live ownership scenarios:

- Pause freezes actual consumption for that stream while a peer continues.
- Resume changes actual output play and uses the supplied tick origin.
- Pre-header pause survives ready/buffering startup with its previous origin.
- Argument2 retains its byte while resuming actual PCM output.
- Unsupported FP rounding and zero-divisor queries do not mute output.
- Shared-clock reentry refuses before effects.
- The unowned discard/global-worker branch refuses; the already-busy branch
  rebases against live queues without claiming a global worker implementation.
- Both new parent Release tests pass, including the inherited48-case finite
  matrix, peer/source lifetime and held-credit/constructor-failure scenarios.
  Assertion counts vary with actual worker scheduling; scenarios define coverage.

## Original-word differential evidence

The measurement fixture runs actual native workers and model output at24/44.1/
48kHz. It captures live post-command queues, pre/post stream/shared clock state
and literal query results. Each compiler freezes those measurement-derived
inputs and executable identities **before** original replay. They are not newly
independent authored original inputs or game-session recordings.

For each compiler, all**138 operations** match the already audited original
clock bodies under the separately qualified exact FP worker:69 plain and69
scheduled operations,20,310 original instructions and1,386 emitted-FP steps.
Typed stream/shared fields, estimate ratios, centiseconds and actual play agree.
The original machine is initialized with the measured RNA play byte; no hook
supplies a clock result or sample position. Its existing explicit critical/
diagnostic hooks and PS2-FPU/current-runtime limitations remain unchanged.

The scheduled fixture inserts a declared external model callback after actual
resume and before queue capture. No later callback runs before recording the
post-command queues. It supplies actual callback progress, not an invented
sample-position return. Plain and scheduled results intentionally have different
external progress and are compared independently with original execution.

A stale pre-resume snapshot mutation fails**15 operations** with each compiler.
Those rows retain actual consumed-before/after counts and original mismatches.
The production source has no scheduling hook. These checks qualify the prepared
clock calculation at the observed point; they do not reconstruct the original
whole-worker schedule, guest ABI or raw FPR/stack side effects.

The first GCC cohort passes. The first LLVM cohort compiled and captured inputs
but its original FP worker failed the handshake because the verification helper
did not propagate the bundled LLVM DLL search path to that subprocess. The
failed receipt and complete freeze remain preserved at
`build-native-sjuni/adxt-clocked-player/frozen-v1`, manifest
`64b86266f077848db36306252e61eca29a289465ab3ff3b273ad76abec465092`.
Only the helper's worker environment changed; no native code or expected result
changed. The current manifest is
`216c3a7656ae8744b2438cfd35b300a8b13add7d968a02c9f4f49084a81a732b`.

| Local artifact beneath build-native-sjuni/adxt-clocked-player | Receipt SHA-256 |
| --- | --- |
| qualified-gcc-v1 | `b59251a9b4eb4ac1e9d6706819bac494921410118f3d020f718efd3d46fd1d59` |
| qualified-llvm-v2 | `d7979c203c8116900a7803cde1190a608cfe71d091de9c47413f3a55d5a5df60` |

The checked-in qualification also pins both parent test receipts. The standalone
project registers43 suites; this is not a migration percentage.

## Remaining clock and media work

The unowned service branch is concrete: original`132C08` guards/reentry-checks
the global service word, services all ADXB decoders via`12D678`, visits16 active
ADXT slots in array order via`134C58`, then services RNA via`12C798`. Its word
passes through1/2/3 before clearing. The current per-player source/decoder/pump/
control order is an explicitly bounded native composition, not proof of that
complete global schedule. Do not force the busy word to bypass this obligation.

Native group scheduling, bank/packet aggregation, LSC/seamless ownership,
logical PAK tails, movie-clock consumers and actual game/media validation remain
required. The earlier finite asset evidence belongs to the unchanged shared
player data plane; these new tests exercise clock integration and inherited
composition, without relabeling that older corpus as a clocked-player game run.
Stages4–6 and final compatibility-runtime removal remain required.
