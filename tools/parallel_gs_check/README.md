# Isolated paraLLEl-GS checker

Root owns checkout, builds, GPU execution, and native integration. This tool never modifies the production renderer.

Source: <https://github.com/Arntzen-Software/parallel-gs>, pin `cc6184af7e0c03da603045ca371ffa5dae9b0655`, with exact recursive Granite revisions under `build-ninja/parallel-gs-source`. The already configured wrapper is `build-ninja/m2-gpu-gs-adapter/out`. Reuse it and its compiled dependencies:

```powershell
cmake --build build-ninja/m2-gpu-gs-adapter/out --config Release --target parallel_gs_check
build-ninja/m2-gpu-gs-adapter/out/Release/parallel_gs_check.exe build-ninja/m2-gpu-gs-adapter/controls-validation5
```

The executable requires the root-tested local `vulkan-1.dll` beside it. Root obtained this signed loader from AMD's driver store; no global driver installation occurred. Standalone library mode uses `/MD` and committed precompiled SPIR-V.

## Controls and current evidence

The checker initializes actual Vulkan/GSInterface, submits an untextured triangle and a 2x2 host-to-local CT32 transfer through GS registers. Six independent assertions check triangle interior/exterior and all four transferred pixels. Validation5 adds opposite triangle winding, direct sprite and upstream-layout packed triangle controls, for nine assertions. Address oracles use independent known CT32 words rather than the backend's swizzle helpers.

Root confirmed GSInterface initialization on RX 570, Vulkan API 1.3.260. Validation1 and validation2 failed the triangle interior. Validation2 actual pixel was zero, full 4 MiB VRAM was zero, and backend stats showed one primitive/one pass. Validation-layer evidence contained no reported VUID. This has not established correct rasterization, nor a failure cause.

Validation3 preserves the failure while exporting GPU triangle scanout before throwing. Compare `triangle-control-vram.bin` against `triangle-after-scanout-vram.bin`, and inspect `triangle-scanout/scanout.bin` plus format/size metadata. This separates GPU raster output from CPU readback/coherency. Validation2 sources are preserved under `build-ninja/m2-gpu-gs-adapter/source-validation2`.

Validation4 aggregates failures and independently executes transfer after triangle failure. With `REO_PARALLEL_GS_DESCRIPTOR_BUFFER=0`, actual enabled descriptor-buffer support is false, triangle and its scanout remain zero, but all four transferred words are exact. This excludes descriptor-buffer selection as the cause and establishes working transfer/readback for this control. Validation5 also fails reverse triangle, direct sprite and packed triangle, each counted as one primitive/one pass. Public decoded GS state is correct: flat RGBA32,64,96,128, Q1, FBW8, no framebuffer mask, Z-enabled ALWAYS with writes masked, and zero XYOFFSET. These results do not yet distinguish faulty vertex/setup-buffer visibility from shader raster behavior. Sources and artifacts for earlier validations remain separate.

Pinned upstream already exposes `-DPARALLEL_GS_DEBUG=ON`, logging decoded VERT, Primitive and render-pass metadata without modifying upstream source. The next boundary probe can use that option in the existing isolated build.

When controls pass, outputs include complete `control-vram.bin`, complete final `final-vram.bin`, GPU `scanout.bin`, `scanout.json` and `result.json`. Readback deliberately uses device-idle/fence boundaries for diagnostic correctness, not native presentation performance.

## Actual captured packet exercise

```powershell
python tools/parallel_gs_check/prepare_corpus.py --artifacts build-ninja/m2-vu-block-proposal/variant2/baseline-validation2 --out build-ninja/m2-gpu-gs-adapter/actual-corpus-320
build-ninja/m2-gpu-gs-adapter/out/Release/parallel_gs_check.exe build-ninja/m2-gpu-gs-adapter/actual-validation1 --corpus build-ninja/m2-gpu-gs-adapter/actual-corpus-320/corpus.txt
```

Expected baseline input is 307 actual packets/548560 bytes from 320 captured weighted/static VU executions. Preparation validates full artifact format, tag lengths and final EOP, records SHA256 source/packet identities, and selects the arbiter sink without duplicating direct-GS packets. Independent fixture artifacts are excluded. `--exports DIR` alternatively accepts `vu_gif_packets.jsonl` plus raw exports.

This is explicitly `actual_packet_exercise_with_reconstructed_initial_GS_state`. Original texture memory, contexts and chronological frame sequence are absent. The checker records `faithful_room_replay=false`; successful captured-byte acceptance and primitive counts cannot establish whole-room pixels, native FPS or lighting correctness.

Root prepared the expected 307 packets/548560 bytes and replayed them without parser failure in validation4-off. Final primitive/pass counts were zero with reconstructed state; final VRAM remained zero. Missing original XYOFFSET/scissor/texture state can clip these packets, so this result does not establish a backend failure independently of the synthetic raster controls.

## Full GS dump input

```powershell
build-ninja/m2-gpu-gs-adapter/out/Release/parallel_gs_check.exe build-ninja/m2-gpu-gs-adapter/dump-validation1 --gs PATH_TO_UNCOMPRESSED_DUMP.gs
```

The bounded local reader accepts new-header frozen state v8/v9 and restores contexts/global registers, VRAM, GIF path cursors, Q and privileged state following the pinned upstream parser. It validates exact sizes/ranges/records, executes FIFO markers, and materializes original VSync boundaries. It exports the final scanout/VRAM. It rejects compressed/legacy formats and cannot restore hidden in-flight details missing from the dump. Reference comparison and initial transfer/palette-state audit remain required; no faithful-room claim is automatic.

Root subsequently captured a full original-room dump. The clean isolated binning barrier variant, with debug/observer code disabled and descriptor-buffer selection off, passes all nine controls and replays 4258 packets/7,771,296 bytes across four VSync markers. Backend counts are 21315 primitives/two render passes; the final 512×448 image visually matches Kevin, the bar, mirror, lamp and ashtray in the PCSX2 reference. Artifacts are under `build-ninja/m2-gpu-gs-adapter/actual-room-clean-barrier-validation1`. This proves actual room drawing on the RX 570; it does not measure native game FPS. `tools/ps2_debug/capture_gs_dump.py` itself captures capped RAM/MMIO and is not a full PCSX2 `.gs` producer.

The isolated source correction broadens only the dependency after GPU binning, before shading consumes GPU-written indirect dispatch arguments. Static CPU-written indirect arguments and direct dispatch already produced pixels; the stronger producer dependency makes complete GPU-generated indirect dispatches render correctly. This evidence does not establish a driver defect or the narrowest sufficient barrier. The clean renderer copy is `build-ninja/m2-gpu-raster-diagnostic-proposal/gs_renderer_barrier.cpp` (SHA256 `615F8D841589BC6E79783CF7106EA6B6B73444A801AF7676F313245F64ED9C61`).

## Bounded replay timings

```powershell
cmake --build build-ninja/m2-gpu-gs-adapter/out --config Release --target parallel_gs_check
$env:REO_PARALLEL_GS_DESCRIPTOR_BUFFER = '0'
build-ninja/m2-gpu-gs-adapter/out/Release/parallel_gs_check.exe build-ninja/m2-gpu-gs-adapter/actual-room-repeat-validation1 --gs PATH_TO_UNCOMPRESSED_DUMP.gs --gs-repeat 8
```

`--gs-repeat` is valid only with `--gs`, defaults to one, and accepts 1–32. One initialized Vulkan device/GSInterface remains alive. The file is read once; each iteration separately parses and validates the cached bytes into aligned packets and a frozen snapshot, resets/restores GS contexts, VRAM, GIF paths, Q and privileged registers, and preserves every original VSync/FIFO record in order. Earlier main5 sources are preserved under `build-ninja/m2-gpu-gs-adapter/source-validation5`.

`result.json` records file-read time and per-iteration `parse_us`, `restore_us`, `enqueue_us`, `completion_tail_us`, `vram_readback_us`, and `scanout_readback_us`. Enqueue includes synchronous API work, original scanouts/FIFO waits, and possible driver shader compilation; completion is the remaining device-idle wait after final scanout submission. These are host wall times, not GPU timestamp-query execution times, and GPU work can overlap enqueue. `restore_enqueue_completion_us` measures the whole restored replay until device completion, excluding parsing and diagnostic readbacks. Four VSync markers are not automatically four equally expensive rendered frames.

The first dump replay follows the nine controls, so it is not a pristine cold-device benchmark. Compare iteration zero against later iterations to observe additional room pipeline warmup. Readback includes GPU copy/fence/map and owned CPU byte copies; hashing, exact comparisons and file output are outside these timings. Only the final iteration is normally exported. Every iteration records packet/VSync/FIFO/primitive/pass counts, dimensions/format, and full VRAM/scanout hashes. Full 4 MiB VRAM and complete scanout bytes/dimensions/format must equal iteration zero; a mismatch increments `repeat_parity_failures`, exports first/failing outputs and returns failure. The source-only repeat change still requires root's compilation and validation.

Cold driver pipeline compilation can stall despite precompiled SPIR-V. Measure cold/warm host submission, GPU completion and download separately once pixels pass. Only then integrate whole-backend startup selection behind the GS FIFO, preserving IRQ/readback/publication order, and replace diagnostic GL readback with GPU presentation.
