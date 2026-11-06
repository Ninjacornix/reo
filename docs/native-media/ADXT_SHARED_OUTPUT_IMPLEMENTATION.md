# Shared output for native compressed streams

Status: independent shared output owner implemented and isolated checks pass.
Stage3 remains open. No game ran and no audio device opened. The previous
single-resource player has not yet been migrated to this output interface.

The [contract](ADXT_SHARED_OUTPUT_CONTRACT.md) and
[session](../../game/native/adxt_output_session/session.hpp) provide one output
renderer/provider and up to16 exclusive stream producers. Per-stream retirement
fences copy/render, releases only that voice and its queues, and preserves other
streams' playback and provider ownership. Slot reuse creates a new generation
and DSP phase. Old producer evidence remains available; stale producers cannot
modify the replacement. Lost producers retain an observable bounded orphan
record until session shutdown.

The actual callback slot is supplied explicitly, allowing the existing runtime's
stable process-wide slot. This addresses the private-slot incompatibility of
the earlier isolated player. The session does not manufacture a provider or
reserve a second device stream. A renderer retains only session-owned PCM;
no callback can touch a decoder or compressed-source object.

The initial GCC/LLVM source freeze passed2,069 ownership/float checks per
compiler. The order coordinator was then narrowed to const producer identities,
so a future player can supply mix identity without exposing mutable producer
operations. The first manifest/source and both receipts remain preserved.
The current freeze is
`fccda4e5d6cb9f9b17ea2ab6111efb7a2c976da06badcbf6f1dde7d3d6254390`.
Qualification repeats both exact compilers against this final interface.

The checks cover:

- Paired stereo copies/consumption while rendering concurrently.
- A live peer continuing with its exact queue/play state when another stream
  retires, with zero provider detach/stop/unload calls at that point.
- Generation/phase reset and retained pre-clear evidence across reuse.
- Full-batch capacity/counter refusals before either channel changes.
- A failed whole-provider fence preserving queues for actual retry.
- Explicit render-counter failure diagnostics and closed admission.
- Exact mixed float words against the unchanged qualified PCM core. A gain-based
  cancellation case changes when the explicit summation order changes, checking
  that the order assertion has discriminating inputs.
- Required explicit order before a third voice starts, plus duplicate-order
  rejection and orphan detection.

The additional fixture compiles the **actual** `NativeStreamProvider` and uses
its **actual** static callback slot. It links hash-qualified original raylib
source functions with declared model device/converter primitives, following
the earlier provider harness. Two producers load/play one stream, render their
sum, retire one producer while the other continues through the actual adapter
trampoline, then unload once at whole-session join. The provider's permanent
single-instance reservation remains intact. This is source-model integration;
it proves neither actual-device behavior nor a matching rebuilt game package.

Controlled stale-generation and missing-order mutations must compile and fail
the relevant ownership checks. The parent standalone Release target also passes
with GCC15.2 and bundled UCRT LLVM21.1.8. The parent registers40 suites; this is
not a migration percentage. Local receipts under
`build-native-sjuni/adxt-output-session/` are pinned in the checked-in
qualification manifest.

The shared session must next receive the actual compressed player producers,
then retain the existing bank/mixer behavior in one complete runtime selection.
Logical PAK source tails, full clocks/pause, LSC/seamless ownership, movie
consumers and actual game/media validation still gate stage3 completion.
Gameplay, scene/platform reconstruction and final compatibility removal follow
in stages4–6. Nothing in these checks enables an experimental path or changes
the player's game speed.
