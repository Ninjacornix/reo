# Scheduled VBlank capture boundary fixture

Run `tools\vblank_capture_check\run.bat` after rebuilding the Release runtime,
or pass its CMake build directory as the first argument. No game is launched.
The coordinator rebuilt the runtime and ran the fixture. Validation3 passes
all eight cases with zero failures, including fresh INTC/DMAC IDs after stop.
See `build-ninja/m2-vblank-capture-validation3.log`. Native room validation
remains pending; this result does not establish the captured flicker's cause.

The production boundary retains guest execution ownership from scheduled
VBLANK_START handler dispatch through the cheap GS capture-marker insertion.
Existing per-handler scopes remain nested. `IRQ-TIMING kind=VBLANK handler=0`
measures admission and the entire boundary; nested `kind=INTC` measures each
handler and its recursive scope, rather than independent VBlank admission.
Other interrupt causes retain their previous timing semantics.

The private fixture entry requires `REO_VBLANK_CAPTURE_TEST=1` and is never
called by the production clock. Its legacy branch deliberately admits a
waiting producer between handler return and capture. Its corrected branch
calls the same boundary used by the production clock. Both execute real
registered guest handlers, scheduler ownership and immutable GS publication.
The producer draws one black point on the selected framebuffer. The legacy
capture must contain black; the corrected capture must retain white while
later VRAM contains black. Dimensions, display/source FBP, the remaining
surface pixels and handler order are independently checked.

Cases cover a single handler, no handlers, the disabled cause mask, a disabled
handler, two ordered handlers, cancellation while the producer is queued,
and a fresh runtime after stop. The fixture stops and joins the automatic
clock started by handler registration before driving its precise boundary.
Its host thread uses the actual guest scheduler; it does not fabricate a
picture or replace runtime synchronization with a fixture mutex.

The initial repeated-runtime check exposed a separate lifecycle defect:
`Helpers/Runtime.h` declares handler maps and ordering/ID counters as static,
so `Lifecycle.cpp` cleared different copies from the maps used by
`Interrupt.cpp`. Its cleanup now calls a private reset in the owning
translation unit after worker joins. The fixture keeps handlers registered
until real runtime destruction; it uses no manual registry cleanup.

Passing this fixture proves the ordering repair. It does not establish that
the room's captured tick9985 lamp/mirror loss had this cause, nor does it
measure gameplay performance.
