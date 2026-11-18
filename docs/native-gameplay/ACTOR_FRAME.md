# Native primary-actor frame ownership

Status, 2026-11-09: the complete eight-primary-actor update orchestration from
File #1 `669F30..66A2DB` is implemented in native C++ and compared with the actual
original body on LLVM and GCC. Actor behaviors, input, contact/pose services and
game integration remain separate migration work. Stage 4 is incomplete.

`gameplay_actors::World` owns eight native frame-state objects and session gates.
`update_primary_actors` uses ordinary references, flags, input words and positions.
It has no guest addresses, simulated CPU context, runtime dependency or original
function dispatch. The synchronous `Services` interface explicitly names the
remaining behavior/contact/input/pose/grid/publication owners. Those owners must
be implemented or connected through a reviewed temporary bridge before this
root can replace an actual game update.

## Preserved ordering

The loop visits all eight physical primary slots and tests activity at each
visit, so a callback can affect a later slot in the same invocation. Its offline
AI frame prepass occurs before iteration; session mode is freshly observed at
the corresponding per-actor and final gates. It is not a global game-clock tick
per active actor. The transient selected actor is separate from permanent human
controller identity.

Per active actor it resets the original transient fields/masks, normalizes only
the `FF` marker, selects offline AI ownership, then applies room admission.
Unpaused off-room actors are hidden and cleaned up without entering the main
update. Paused actors continue through core services and skip the normal
visibility-enable assignment. Input filtering uses its own session predicate:
original `1B0310` tests signed setting `3243FB` for values 1 or 2, while `1B02D0`
tests the independent mode byte `3243F2` for zero. These must not be conflated.

Contact preparation precedes input routing, authority preparation and behavior
dispatch. Remote motion omits local motion but retains pose and subsequent
services. Grid response preserves the unsigned-stored/signed-selected comparison,
including negative selected bytes. A missing grid always clears status `4000`;
contact bit 2 suppresses association cleanup and ID reset, not that status clear.
Pending notices are published before their marker is cleared. Final transient
cleanup and offline selected-actor reset retain the original order.

Names for incompletely understood business fields remain conservative frame
markers/values. They are not relabeled as proven gameplay concepts. `input_words`
is the retained game action-frame payload, not a PS2 CPU register bank. Full
native input-field semantics and action consumers remain a separate row in the
Stage 4 plan.

## Original-body comparison

The verifier compiles the actual complete generated `669F30` body after matching
all original instruction comments and omitted words against the owned o2 image.
Register/byte-address scaffolding exists only in that offline oracle. Callee
ports record order and mutate actor/session state; they do not claim to execute
the real AI, input, animation, contact or network services.

Both compilers pass **4,096** mixed activity/room/pause/mode/grid cases and
**182,072 ordered service calls**. Comparisons include all bytes across the eight
original actor records, selected global projections, return address and stack
restoration. Cases include same-frame next-actor deactivation, prepass activation,
mid-loop mode changes, input clearing, pending publication, remote/local motion,
signed grid IDs, failed lookup and association-retention flags.

Three counterfactuals are compiled and must fail the original comparison:
blanket pause freezing, omitted nonselected-input clearing and retaining the
missing-grid status bit. Earlier fixture compile failures and the two native
branch mistakes remain retained in their failed output folders.

The scalar-response corpus uses finite exactly representable values. Its declared
addition port does not establish exceptional PS2 floating-point behavior. Guest
preemption is disabled in the oracle; production native task continuation and
actual caller ownership remain integration requirements. No game, window,
controller, save or device is touched by these comparisons.

Evidence: `gameplay-actor-frame-llvm-v5` and `gameplay-actor-frame-gcc-v4` under
`build-native-sjuni`, bound by
`tools/native_reconstruction/native_gameplay_actor_frame_qualification_v1.json`.
