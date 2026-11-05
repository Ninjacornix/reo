# Native ADX predictor control

This independent C++20 library implements the nine scalar phase/configuration/
window helpers reviewed in
[BOUNDARY_INVENTORY.md](../../../docs/native-media/BOUNDARY_INVENTORY.md). It is
not a codec, player, scheduler or worker. It performs no I/O, allocates no work,
contains no PS2 addresses/layout, and has no global service or game integration.

`PredictorState` uses typed phase/mode, 32-bit requested/completed word counts,
opaque `SpanToken`/byte-coordinate positions, four signed history halfwords,
two coefficients and a key triple. Tokens identify borrowed storage; they own
no lease and permit no dereference. The owner must validate storage and retain it
before actual decoding. State access is ordinary synchronous C++; callers provide
exclusive ownership/synchronization. No concurrency or cancel/join guarantee is
invented from a phase value.

| Function | Contract |
| --- | --- |
| `phase`, `completed` | Observe current phase or raw completed word. Completed units are lower-kernel units, not automatically samples or bytes. |
| `configure_mono`, `configure_stereo` | Idle-only selective input/count/output/mode changes; return true accepted or false with unchanged state. Mono clears the second output position. |
| `request_if_idle` | Idle clears completed and sets requested. Busy preserves all state. Returns the original word **1 on both paths**; this result is not admission. |
| `cancel` | Clears phase and four history halfwords; preserves completion, configuration, coefficients and key. No waiting/join. |
| `acknowledge_ready` | Only ready returns to idle; completed work remains. |
| `request_mono_window`, `request_stereo_window` | Compute output positions, ignore configuration refusal, then request. Stereo doubles requested units. |

Offsets are explicit modulo-2^32 byte coordinates. Both offset-to-byte shifts and
stereo count doubling use unsigned word wrap; no signed overflow or actual pointer
arithmetic is used. Native span identity is preserved even when the word coordinate
wraps. These values are not capacity checks and cannot be used directly as host
offsets without a separate admission boundary. Mono preserves zero/negative raw
count words; stereo doubles them modulo 2^32. The core does not clamp arguments.
No guest register sign-extension/void-return ABI is supplied by this library.

## Original-word comparison

```text
python tools/native_reconstruction/compare_adx_control.py --cxx C:/msys64/mingw64/bin/g++.exe
```

The helper calls the existing `adx_phase_oracle.generate()` unchanged. That
generator fetches the owned pinned ELF's complete nine bodies and executes only
their admitted integer instructions over synthetic memory; it imports no native
algorithm. Its only substituted external operation is bounded history memset.
The expected full fixture remains JSON in ignored output, with a bounded binary
transport for the C++ test executable. No copied instruction arrays are shipped.

The isolated test adapter maps synthetic numeric buffer references to unrelated
64-bit opaque token IDs, then compares 16 cases / 96 calls, all 96 full relevant
context/decoder/payload images (22,944 words) and 72 defined word returns. The 24
void raw-return observations are deliberately ignored. Unrelated original owner
words and decoder/payload data are carried by the test adapter's preserved shadow;
they are not guest-layout fields inside the native core. Original memset hook
observations remain in the oracle JSON; no native external-call ABI parity is
claimed for replacing that bounded memory clear with typed history assignment.

Standalone CMake builds the library and unit tests. If Python and the owned ELF
are available, CTest also runs the independent original-word comparison using the
built executable. `--executable <adx_control_tests.exe>` skips helper compilation;
`--output` can select separate GCC/LLVM `adx-control-checks` directories under
ignored repository build roots. Prebuilt receipts require separate build evidence.

There is no compressed block decoding, PCM generation, coefficient calculation,
resource/SJ borrow publication, looping, sample clock, device output or gameplay
validation here. No runtime path is enabled and no performance improvement is
claimed from these control helpers.

## Synchronous predictor service

`predictor_service.hpp/.cpp` extends the typed state with the complete scalar
dispatch/publication contract of original `135078` and helper `135068`. Requested
work enters processing; requested/processing invokes an admitted synchronous
`Decoder`, then stores its completed word and enters ready. Mode one selects mono;
every other raw mode takes the existing stereo selector route. Only a positive
signed odd stereo result sets the caller's separate flag word to one. Other
results preserve it. The selected decoder owns actual downmix choice and storage.

The request snapshots scalar arguments, while history/key remain in live state.
Scripted synchronous cancel/release mutations remain visible, but original
completed/ready publication still follows the callback. This deliberately does
not turn cancel into a join or add an invented incarnation check. Missing decoder
returns new native admission metadata before processing publication; an admitted
decoder cannot refuse or throw. A real adapter must settle storage/codec admission
before entering this contract.

The independently frozen implementation matches all 74 original cases and 54
scripted calls with GCC and LLVM: 182 semantic state images, 2,730 context words
and 23,296 preserved/test payload bytes; 301 unit assertions also pass per
compiler. Original void return-register observations and guest stack/register
ABI are excluded. See [the original oracle](../../../docs/native-media/ADX_SERVICE_ORACLE.md)
and `tools/native_reconstruction/compare_adx_service.py`. No actual codec, source
lease, scheduler, device or whole-player replacement is established by this test.
