# Native single-resource player composition

Status: isolated composition implemented; both exact compilers pass its
ownership checks, inherited original decoder comparisons and the full finite
owned-asset corpus. **Stage3 remains open.** No game ran and no audio device
opened. This implementation is not selected in V11 or the player's build.

The [contract](ADXT_PLAYER_COMPOSITION_CONTRACT.md) and
[player](../../game/native/adxt_player/player.hpp) connect the actual async
Source2, corrected Window2, phased PCM owner, qualified startup/drain control,
unchanged native PCM mixer and source-pinned output lifetime owner. Window2's
new R2 port remains part of its concrete owner; no independent mutable PCM/source
alias escapes. The R2 header/layout is exclusive to this executable. Mixing it
with frozen/R1 class definitions or implementations is invalid.

The private output mutex covers the complete stereo copy and every callback.
Only after the output owns both copied channels does the player return the
decoder read lease. Callback storage contains no decoder/player alias. Transfer
stop fences synchronous copies, while the audio Owner separately fences actual
provider callbacks. Retirement joins the provider before cutting either PCM
queue, then stops/drains/joins the actual source worker. Failed provider steps
preserve both queues and decoder admission for retry. Pre-clear output counts,
statistics and voice skipped/late observations remain available after shutdown.

Both GCC15.2 and bundled UCRT LLVM21.1.8 pass:

- All48 independent ready-flag clients /720 observations and the123 previously
  admitted original Window2 clients /8,034 observations, retaining the existing
  narrowly specified source live-grant/cache relation. The old10 excluded
  Window2 clients are not silently promoted.
- All996 inherited Window2 checks, with zero guarded allocation attempts. The
  inherited test file is byte-for-byte identical; its local quoted include
  selects the R2 header.
- A48-case finite-player matrix: mono/stereo,24/44.1/48kHz and1/31/32/33/36/64/65/
  40,017 samples, using the real async source worker and a callback model.
- Concrete failed detach/stop/unload retries with nonempty queues retained,
  a blocked actual source read whose join remains pending, a synchronous attach
  callback, and a concurrent callback/control run with paired stereo counts.
- Both selected parent Release CMake/CTest targets. The parent registers39
  suites; that count does not describe migration completeness.

The first development build refused an invalid512-frame native PCM configuration:
the unchanged core requires a configured maximum of at least12,000. Its failed
logs/source are preserved. The corrected wrapper retains the qualified default
maximum and separately admits callbacks of at most512 frames. The first frozen
composition is`1df45fc4ede0a10a6ae01335860d01ea8711fee8811f575827c8932583e7385f`.
These results were frozen after initial development tests; the original corpora
had already been seen. They are regression/composition evidence, not newly
independent original inputs.

## Owned finite assets

The first16-reference/12-payload probe passed, including complete payload-prefix
digest equality with the separately qualified native decoder. Its harness
waited one Windows millisecond on every in-flight source observation, even
while buffered work progressed. Before the full run, only that offline consumer
fixture changed: it yields when progress actually needs the worker. The initial
manifest and every source remain preserved under`composition-freeze-v1`.
The second manifest`b25c517f2158e2f02a949e51a5771cb8d4ab4f2bfd4d2c1a42b4ae49f9e5d53c`
records that exact one-file delta. No native production code changed.

Each compiler then completes all8,910 identified references, retaining real AFS
sector views from18 immediate archives, and fully plays6,706 distinct
non-looping payloads through the independent graph and deterministic model
consumer. Payload PCM totals2,396,811,288 bytes, including both channels where
present. Every first-payload sample count and rolling digest equals the prior
qualified native decoder result. The digest is noncryptographic; source/result
files and receipts also have SHA-256 identities. This is native-to-native
copied-payload validation, not original full-player PCM parity.

The89 loop-bearing references still bind their real sources but are excluded
from full player playback in this finite cohort. Their80 distinct payloads have
the [earlier corrected-decoder cycle proof](ADX_ACTUAL_LOOP_STREAM_VALIDATION.md);
that does not qualify looping player/output scheduling here.

Both full player result sets agree on every recorded field, including padding
copies/consumption and joins. Each records732,806,272 copied samples per channel
summed across selected files, including padding, and1,355,812,352 consumed bytes
per channel summed across files. These aggregates deliberately have different
channel accounting from the payload-byte total above. All selected cases have
zero model underrun frames and zero skipped samples. The consumer advances only
with buffered input; this is not a real-time workload or accepted speedup.
No output float stream or audible presentation was compared with the game.

The owned ISO's full SHA-256 was checked before each run, and size/mtime stayed
unchanged afterward. No extracted payload files or decoded audio files were
saved. Full original/native source freezes and raw JSONL observations remain.

| Local artifact | Receipt SHA-256 |
| --- | --- |
| adxt-player/qualified-gcc-v1 | `d8742ad185f24eb6cc250ac8cfefd57446a0bf14bb76d0d65c4cfe1ef8403e04` |
| adxt-player/qualified-llvm-v1 | `e5517f1061f84043148ffeee2772a630ff82e16463cb192227eb9327443032d0` |
| adxt-player-assets/probe-gcc-v1 | `fa8ece086483390689b1fd824cb0abe1747e8ea89d7b705b493afd31edcadafb` |
| adxt-player-assets/full-gcc-v1 | `17cd6581ca74a404b1a38524c689fc5ea747f04b50d9c620e8e2a3e6ac2f1dd3` |
| adxt-player-assets/full-llvm-v1 | `6e16573100bfad58c1d3631c299f79760d841a8695d7508ad85fa9e00efa929a` |
| adxt-player-assets/comparison-v1 | `e2ee757a6c00b4d9b4649fb27523fa4225aa0625c19b5c798fccf602942887ca` |

Paths above are beneath`build-native-sjuni`. The checked-in qualification manifest
also pins both parent receipts and the comparator source.

## Production boundary still required

The current production `NativeStreamProvider` accepts only its stable
process-wide callback slot, and its factory reserves one provider for the
process. This isolated player creates a private slot and owns one resource's
output. Passing that production provider directly will refuse attachment;
creating one device stream per ADXT resource is not an admitted migration.
Actual integration must use one session output owner and per-stream producer/
voice lifetime, alongside bank mixing and the existing complete audio owner.
The model's source-hash return does not certify a real device implementation.

The remaining stage3 work also includes logical final-sector PAK sources,
LSC/seamless resource transitions, full pause/estimated-clock composition,
original worker scheduling, movie-clock consumers and wider actual game/media
validation. Current asset evidence uses a read-only owned ISO; it does not meet
the final requirement that imported PAK content supplies every resource.
Stages4–6 and compatibility-runtime removal have not been completed.
