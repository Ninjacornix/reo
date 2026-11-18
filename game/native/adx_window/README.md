# Native keyed ADX decode-window owner

One bounded tag0 decode-window owner, with typed state and private owned SJRB
rings. It performs input acquisition, output reservation, actual keyed decode,
result/wrap accounting, input return, per-channel PCM publication and ack.
It has no PS2 context, guest memory, runtime/device or original-code execution.

The frozen mono/stereo/downmix kernels and predictor control/service are reused
unchanged. Their allocating result vectors are prepared from stable private
ring snapshots **before the first observable guard/Get**. Original numeric
state and payload effects are then committed at the original boundaries. There
is no whole-call rollback or fallback after borrowing/publication.

`Request` carries a private owner identity/generation. `stop()` closes new work
and feed admission while retaining accepted PCM for explicit drain; it is not
a cancel interrupt, ring reset or join. Publication `PcmView` keeps actual
storage alive and exposes checked read copies only. Retaining it does not make
its contents immutable after later consumption/reuse. Serialize all accesses;
callbacks observe only, and mutating reentry refuses.

The admitted profile uses 2048+36 encoded bytes, **16384+192 PCM bytes per
channel**, one/two channels, at most 256 requested samples/window and total
samples 1..4096. Unequal channel grants and scratch that would exceed an actual
reservation refuse before effects. Header parsing, coefficient computation,
refill/LSC, loop/drain policy, playback-clock authority and RNA/PCM credit
transport are not implemented by this component.

GCC and LLVM each pass all **33 frozen original cases** (32 outer transaction
cases plus the actual constructor-default-reservation helper), including 673
typed state observations and complete backing/callback comparisons. Both pass 86
native unit assertions, including real allocation failure before borrowing and
forbidding every allocation after the first guard. Standalone CMake/CTest passes.
See [ADX_WINDOW_IMPLEMENTATION.md](../../../docs/native-media/ADX_WINDOW_IMPLEMENTATION.md)
for source/receipt hashes, projections, refusals and lifecycle limits.

```powershell
cmake -S game/native/adx_window -B build-native-sjuni/adx-window-cmake -G Ninja
cmake --build build-native-sjuni/adx-window-cmake --parallel 2
ctest --test-dir build-native-sjuni/adx-window-cmake --output-on-failure
python game/native/adx_window/compare_original.py --compiler g++ --output build-native-sjuni/adx-window-parity-new/gcc
python game/native/adx_window/compare_original.py --compiler clang++ --output build-native-sjuni/adx-window-parity-new/llvm
```

Use installed tool paths when CMake/Ninja are absent from PATH. This directory
does not wire itself into the game or the root native build. Implementation was
honestly frozen after original-oracle exposure and before comparator development;
no blind authorship or full ADXT player claim is made.
