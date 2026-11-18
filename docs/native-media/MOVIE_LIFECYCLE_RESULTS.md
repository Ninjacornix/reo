# Native movie lifecycle: results and remaining gates

Status: original lifecycle orchestration and prepared physical graph ownership
are implemented and qualified. The game still uses its existing movie path.
Stage 3 remains open.

The module separates original numeric decisions (`Policy`) from physical
retirement (`Session`). `PreparedGraph` joins a bounded native source reader,
optional native ADXT audio stream, shared timing Context and video backend.
`NativeVideoGraph` joins the existing MPEG parser and same-device GPU decoder.
Old keys stop admitting work immediately; replacement waits for actual source,
audio and GPU retirement. Failed construction retains its partial graph for
cleanup retry. Movie retirement preserves the shared audio device.

| Evidence | Result |
| --- | --- |
| Original lifecycle oracle | 176 cases, 179 operations, 453,272 interpreted instructions per compiler; inputs frozen before native lifecycle existed. GCC/LLVM original outputs agree. |
| Native policy comparison | Zero differences across 355 initial/final snapshots, including callback sequence and callback-entry state. Eight deliberately incorrect policies are rejected. |
| Native physical owners | Actual positioned source workers, ADXT Session streams, timing Contexts and VideoFrames, with modeled audio device/render fences. Covers blocked reads, exact feed/end, pending rendering, partial construction, stale/foreign keys, reentry, callback-time owner release, shutdown and rebuild. Poll-loop counts vary. |
| Standalone regression | All 69 suites pass under GCC 15.2 and LLVM 21.1.8. |
| Actual offscreen GPU lifecycle | RX 570, two constructed native graphs. Real source reads, program/elementary parsing, D3D11 decode, shared-clock frame ownership and Vulkan pixel copy. An unsignaled real renderer fence prevents graph replacement. Rebuild then decodes identical first-frame pixels. |

The final hardware receipt is
`build-native-sjuni/movie-lifecycle/gpu-v6/receipt.json`, SHA-256
`eaf1f39cfdf702ec3b7d0228e53dd8e24e9450b0fabdb2ebec6907cda5a5954e`.
The independently identified input is File #1's
`adxsnd.afs/PS2continue.sfd`, extracted from the imported `NETBIO01.DAT` at byte
710572032, length 299008; payload SHA-256
`f003fe27fc6c402e9e2142a3786828a492bcb26c4b933b8f1a2a944a6d1e94bb`.
Rebuilt first-frame readback SHA-256:
`4eb588549f774d0691a29edd11c5a2865636f6a591245c4ed5dd21f9f8edeaa6`.
This establishes stable fixture output, not new PS2 pixel-parity evidence.

Original child initializers/cleanup and installed component methods remain
declared ports. The real nine-component broadcast and indexed dispatch execute.
Normalized registry identities and numeric properties do not assert guest
workspace/pointer ABI parity. An unwritten required snapshot is undefined;
native code refuses to invent the original caller's uninitialized stack value.
See the [contract](MOVIE_LIFECYCLE_CONTRACT.md) and
[qualification](../../game/native/movie_lifecycle/qualification.json).

Raw original/qualification/GPU receipts and failed/superseded scopes remain in
ignored `build-native-sjuni/movie-lifecycle/`. Original-v1 had retained the
earlier timing oracle's indexed-dispatch port; v2 executes that dispatcher.
Qualified-v1 failed strict compiler warnings before execution. GPU-v1 lacked the
native-library receipt; GPU-v2/v3 exposed timestamp admission before first-frame
publication. These are preserved as harness/admission findings, not game crash
reproductions. Later hardware receipts pin the final sources and rebuilt native
libraries. Sealed dependency/compiler/allocator identity checks remain mandatory;
no runtime dependency or private source-header layout was patched.

The new native manifest incorporates the prior timing-context source cohort.
Its only changed prior input is `game/native/CMakeLists.txt`, adding this module.
All prior implementation bytes remain unchanged and their 68 suites are included
in the new 69-suite regression. Historical ancestor manifests are preserved.

The complete movie migration still needs:

1. Source-qualified picture timestamps. Later pictures in this owned clip can
   lack individual PES timestamps. The strict prepared graph rejects those;
   the successful GPU case stops/rebuilds after the timestamped first frame.
   It does not demonstrate whole-movie playback. PTS zero is safely first within
   the admitted nonnegative domain; other reference frames use a reorder watermark.
2. Native Sofdec audio routing. The current program parser selects video PES
   and ignores audio/private streams. Prepared audio ownership takes an
   independently demuxed ADX ByteView and actual service-tick provider.
3. The logical-policy/physical-owner scheduler and game command adapter, including
   property/provider reconciliation, actual IPU controls and authoritative state
   observations. The prepared graph starts at actual/requested state 1.
4. Whole-stream I/P/B, skip/recovery, real transitions, monitor presentation and
   audible A/V synchronization validation before production selection.

No game window or audio device was opened. No gameplay speed or rendering mode
changed, and no stutter fix or performance gain is claimed from this work.
