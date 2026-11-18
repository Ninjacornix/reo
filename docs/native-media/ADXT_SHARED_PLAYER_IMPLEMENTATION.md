# Native compressed players with shared output

Status: independent shared-player composition implemented and qualified in the
bounded offline domain. **Stage3 remains open.** No game ran and no audio device
opened. No runtime adapter or player default changed.

The [contract](ADXT_SHARED_PLAYER_CONTRACT.md) and
[player](../../game/native/adxt_shared_player/player.hpp) connect each actual
Source2/Window2-R2/PCM/control graph to an exclusive producer in the qualified
shared output session. A per-stream retirement disables/releases only that
producer, then joins its own source worker. It has no access to the provider
join/reset API. A blocked source join therefore cannot shut down peer output.
The caller separately owns actual output readiness and whole-session shutdown.

Copied PCM credit returns only after the shared output accepts both planes.
Output refusal retains the real decoder lease; cleanup first fences that
producer, then explicitly returns/cuts decoder PCM and joins its source. A
constructor failure retires the consumed producer after safely unwinding the
decoder construction, including State-allocation failure. This avoids silently
orphaning a session slot on failed player construction. Read-only producer
identity supplies explicit summation ordering without mutable output aliases.

Both GCC15.2 and bundled UCRT LLVM21.1.8 pass:

- A48-case finite matrix over mono/stereo,24/44.1/48kHz and1/31/32/33/36/64/65/
  40,017 samples, reusing one provider across all48 resources.
- Two independent live players, with actual peer consumption continuing after
  the first player's producer and source have retired.
- A blocked actual source read: its producer retires, its source join remains
  pending, and its peer continues actual native output consumption.
- A real bounded output-counter refusal retaining a nonzero decoder read-lease
  identity while publishing neither stereo plane.
- Constructor failure returning the consumed producer slot to the session.
- The selected standalone parent Release CTest. Its assertion count varies with
  real worker scheduling; the fixed matrix/scenarios above define coverage.

An additional fixture compiles two actual decoder/worker graphs together with
the **actual** NativeStreamProvider, its **actual** static slot and hash-qualified
raylib functions from the reviewed provider harness. Device/converter primitives
remain explicitly modeled. One source retires while its peer continues through
the actual adapter trampoline. The provider is loaded/played once and stopped/
unloaded only at final session join. This proves the source-model composition,
not actual-device output, original whole-player timing or a rebuilt game binary.

The early-source-credit mutation compiles and fails the held-lease assertion
under an actual output-copy refusal. Removing constructor cleanup compiles and
fails the slot-reclamation assertion. Both negatives fail with both compilers.

The first standalone verification helper omitted Source2's existing
`-Wno-misleading-indentation` compile flag. Both one-shot compiles failed on the
unchanged frozen dependency, while the per-target CMake builds/tests passed.
Those receipts and the complete initial freeze
`d293bdb478893456715bc7e25c71c6b5a31ffcc2700189c81ca984964baf186c`
remain preserved under`build-native-sjuni/adxt-shared-player/frozen-v1`.
Only the helper flag changed for the second freeze:
`3c29ed6a28ce2e86c82fac8050f9d6b861581bf901ddedc39bc38f7629edf29c`.
No native production code, input case or expected result changed.

## One persistent session across owned assets

Each compiler independently binds all8,910 identified references from18 actual
immediate AFS archives and completely services6,706 distinct non-looping
payloads through **one persistent output session**. Every copied payload sample
count/digest matches the separately qualified native decoder. Payload PCM totals
2,396,811,288 bytes across channels. Every source actually joins and its stream
producer retires; the final session summary records exactly one detach, one
stop and one unload, with zero occupied producer records.

Both result sets agree on every recorded field, including padding-copy and
consumption observations. The deterministic buffered consumer records zero
underrun frames and zero skipped samples. It does not model real-time load or
establish a speedup. The rolling digest is noncryptographic; full result files,
source freezes and receipts also have SHA-256 identities. No original full-game
audio or exported float output was compared. The89 loop-bearing references bind
but are excluded from full player playback in this finite cohort; the earlier
80-payload decoder cycle proof remains separate.

Full ISO SHA-256 is checked before each run; size/mtime remain unchanged after.
The backing is read-only and no payload/audio files are extracted. Using owned
ISO sector views does not meet the final imported-PAK-only requirement.

| Local artifact beneath build-native-sjuni | Receipt SHA-256 |
| --- | --- |
| adxt-shared-player/qualified-gcc-v2 | `e9215665f6aa5f7755f6bdb8be094fd8240440e76280f4f757bd01489ba9cd65` |
| adxt-shared-player/qualified-llvm-v2 | `50438b0852b32700616be61b5b3e9d755dd71ceaa17db261ca05d22095323f00` |
| adxt-shared-player-assets/full-gcc-v1 | `97f988a82cd2babcdd780037d7740b7625fb62ecd40a4de236816dee7ba8b4cd` |
| adxt-shared-player-assets/full-llvm-v1 | `e99ef4ee3acd532123154baee205ac9ac25be389762d510eca9eab18c77c7b43` |
| adxt-shared-player-assets/comparison-v1 | `384b8356fceccdbed6f1bad516b7d15f7770bb59d37c51d136e3f42175b7167a` |

The checked-in qualification manifest also pins both parent test receipts.
The standalone project now registers41 suites; that is not a native migration
percentage. Bank/packet aggregate integration, complete clocks/pause,
LSC/seamless ownership, logical PAK tails, movie consumers and actual game/media
validation remain stage3 work. Stages4–6 and runtime removal remain required.
