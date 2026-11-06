# Native ADXT buffering and drain control

Status: isolated playback-control cut implemented and compared with original
instructions. Stage3 and the complete compressed-stream player remain open.
No game ran and no audio device opened for these checks.

The [contract](ADXT_PLAYBACK_CONTROL_CONTRACT.md) and
[implementation](../../game/native/adxt_playback/playback.hpp) cover the complete
buffering, playing and draining bodies `1343B8..1347F8`. The native controller
uses typed decoder observations, a PCM port and an output port. Its concrete
StorePcm bridge publishes real zero samples through the existing phased PCM
owner; it does not fake queue completion or issue a guest-addressed write.

The original harness froze330 independent inputs before the native controller
existed. All330 complete, executing101,033 original instructions in total. It
runs actual SJRB Get/Put/Unget/split operations, decoder getters, RNA queued/free
sample getters and the play/transfer/through setters. Generic bounded memset,
ring mirror memcpy and CRI guards are external library hooks. DTR stop itself
is an explicitly completed external call; this is not a DMA or device proof.
The first cohort stopped after96 results because its generic memcpy hook only
admitted the first backing. That failed freeze and raw results are preserved;
the second adds bounded nonoverlapping mirror copies for each owned queue.
It changes neither inputs nor original instructions/results.

Both GCC15.2 and bundled UCRT LLVM21.1.8 then pass:

- **318 admitted original clients**, comparing every selected control field,
  all queue positions, all four traffic totals and every physical PCM backing
  byte, with no byte mask or hidden count adjustment.
- **12 explicit uneven-channel exclusions**, with all original results retained.
  The composed PCM store cannot create those asymmetric states.
- **51 ownership checks**: inhibited/paused startup, held PCM leases, wrapped
  silence, tail progress, pending transfer stop, post-effect faults and reentry.
- Three negative controls: wrong stereo padding differs on34 clients, an
  inclusive drain-completion test differs on8, and a62-byte tail threshold
  differs on2.
- The selected Release CMake/CTest target on each compiler. The parent now
  registers37 suites; this count is not a migration percentage.

The first native comparison exposed a mistaken interpretation of the original
inhibit branch: `134438` jumps directly to the started-byte store at`134478`.
Thus an inhibited admission sets started without enabling play or changing the
phase. Both first native runs disagreed on48 clients solely at that byte. Their
receipts and complete initial source freeze remain preserved. The correction
changes the controller and adds an explicit ownership assertion; the second
native freeze is`d37d943c4daf2f65dc6166747f0f597ffcda28fbfa1e28c9fe1f9810d92822d8`.

Artifacts remain under`build-native-sjuni/adxt-playback/`:

| Cohort | Receipt SHA-256 |
| --- | --- |
| original-v2 | `898d1f80e1f1548a871a57e9c7b1967daa5789aeb2ab225db978ada5c5584468` |
| native-gcc-v2 | See checked-in qualification manifest |
| native-llvm-v2 | See checked-in qualification manifest |
| parent-gcc-v1 / parent-llvm-v1 | See checked-in qualification manifest |

The intermediate capped-Get versus full-reserve/suffix-restore observations are
deliberately different; final traffic totals and bytes match exactly. The
pending-stop extension never republishes padding while waiting and never sets
ended until the output port accepts the actual completed stop, play-off and
through operations. The fixture's output port is a declared completion model,
not a production fence or audible validation.

Window2 still keeps its PCM owner private. The next composition must connect
this control to decoder silence and actual output copy/consumption credits
without leaking a mutable owner alias or mixing incompatible class definitions.
LSC replacement, full pause/estimated-clock integration and controlled actual
game/device validation remain required. This code is not selected in V11 or
the player's current build, and supplies no measured stutter fix.
