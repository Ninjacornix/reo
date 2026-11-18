# Owned movie audio clock

Implements the typed `165C08` envelope and `165B48` audio slot in the
[contract](../../../docs/native-media/MOVIE_AUDIO_CLOCK_ENVELOPE_CONTRACT.md).
`Clock` retains the audio/helper providers, native filter and raw word cache.
`SessionSource` retains an actual native ADXT Session, opaque stream key and
service-tick provider. Registration in selected-clock slot 2 is explicit.

Both compilers match 89 cases / 315 operations from 477,029 original instructions,
including complete state and observations at the estimator/counter boundaries.
The original status getter, admission helper, frequency getter and entire filter
execute. The estimator and hardware-counter samples are declared ports, not
claimed executions of the whole original ADXT or MMIO timer service. Source
instructions, stack/callee-save restoration and guard bytes are checked.

The first 81 cases / 307 operations were frozen before this module existed.
Eight negative-word filter cases were added after a counterfactual escaped
detection: the earlier negative-word cases bypassed filtering and narrowed away
the difference. The new original execution retains all earlier inputs/results
unchanged, and records the existing candidate's hashes. It detects replacing
sign extension with zero extension. All seven deliberate faults are detected;
52 separate checks cover reentry, lifetime, ordered provider failure and refusal
before caller publication. Failed runs and candidate snapshots are preserved.

The first candidate also exposed a contract error: `176670` writes -1/1 when
the state is ineligible. The full wrapper inherits that write; it does not leave
the caller untouched. The actual original outputs were retained unchanged.

The owner test uses a real asynchronous native source and decoder, native PCM
queues, the actual Session estimate and this cache owner, with an explicit audio
provider model. It checks foreign/stale keys, retained Session lifetime,
per-stream source retirement and whole-output join. No real device is opened.
The helper is a declared sample provider; no native host clock equivalence or
whole original movie/audio integration is established by this test.

Failures expose `Health` and preserve caller words. A status observation already
published to diagnostics, or estimator/provider state already advanced before
a later failure, is retained. Only the filter's own failed numeric transaction
is rolled back. A failed provider call has no defined original callback return
claim. The selected-clock callback leaves words untouched on native failure and
its owner must inspect/report health; this profile is not production selected.

Run `python game/native/movie_audio_clock/verify.py --cxx <compiler> --output
build-native-sjuni/movie-audio-clock/<fresh-scope>` for the frozen comparison and
negative controls. The standalone CMake project adds the real Session binding
test. `manifest.json` pins native and verification dependencies;
`qualification.json` identifies the successful and failed cohorts.

Shared CRI guard/priority ownership, a qualified live helper/service-tick binding,
movie construction/reset, pause/buffering, picture due/skip, frame/source
lifetime and a coherent game adapter remain stage 3 obligations. Gameplay,
graphics/platform migration and final runtime removal remain stages 4–6.
