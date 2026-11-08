# Owned media control observations

`tools/native_reconstruction/capture_media_control.py` records bounded, read-only
observations for one already running private File #1 candidate. It checks the
session manifest, exact executable hash, PID, creation identity and owned ELF
hash before opening the existing read-only `GuestRam` helper. No thread is
suspended and no guest memory, input, audio device or settings are written.

This supports the game-facing native integration work. It is separate from
the launcher's incident recorder and does not claim native owner admission.
No capture has been completed merely by adding this tool.

| Original range | Recorded meaning |
| --- | --- |
| `20F3C4` | ADXT raw tick, with no assumed frame/time unit |
| `20F3C8`, sixteen `C4` records | ADXT active/state/source-mode/channel bytes, pause byte `72`, and literal control record |
| `223880`, sixteen RNA records at stride `60` | Bounded C4+C child, literal RNA bytes, active/channel fields and route at `20` |
| `22F138` | Sofdec global raw tick, not presentation FPS |
| `22F18C`, eight pointers | Registered movie owners |
| Movie `44..57` | Pending, actual, requested, explicit pause and nesting words |
| Movie `9A0/B30`, 100 words each | Current and saved property arrays |
| Movie `1AA0`, nine records at stride `44` | Literal cached component words 0 and 4 |
| Movie `CC0..F57` | Literal clock/video metadata bytes, without guessed field labels |
| Movie `2AB0`, optional shared `DA4/DA8` | Bound shared object and its source flags |

Every followed pointer must fit the explicit aligned 32 MiB guest profile.
RNA reads additionally require the exact active File #1 RNA pool and supported
C4 channel count; arbitrary pointers and aliases are not followed. Active/channel
agreement is reported separately from before/after byte stability. These fields
are not a source capability or proof of membership in the raw PCM mixer map.
Invalid pointers are recorded as unavailable without following them. Registry
and movie controls, C4 records and RNA children are reread; differing values are retained
with a false stability marker. Separate reads never become an atomic snapshot,
even if those final markers match. These are observations, not ordered original
service calls, synchronization proof, bottlenecks or A/V equivalence evidence.

Duration is bounded at 600 seconds and interval at 0.1..5 seconds. JSONL and a
hashed receipt stay inside the private session directory, using fresh names.
Nine isolated tests cover empty pools, literal fields, invalid main/shared/RNA
pointers, exact child fields and changing C4/RNA/movie records. Live validation
is a separate gate. V20 retains five observations before its game refusal; its
original failed capture receipt is not rewritten as a completed recording.
