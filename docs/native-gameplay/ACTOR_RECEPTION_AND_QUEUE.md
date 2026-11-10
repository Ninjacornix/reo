# Native actor reception and bounded delivery queue

Status: qualified on LLVM and GCC; uninstalled. Stage4 remains incomplete.
InstalledV39 is unchanged and no game was launched.

ActorReception applies typed status, alignment, interaction, carried/storage,
resource-pair and room-object messages to the canonical native World. It follows
complete67ED50's admitted branches4/6/9/10/12/14/15: phase and local-echo admission,
notice clearing before selected-status filtering, then payload application and
the shared pose-history/root-motion cleanup. Pause does not become an additional
receive filter. Missing capabilities return unavailable with the reached prefix
retained.

Room-object updates write the existing signed X/Z fields, including initialized
inactive records. They do not rebuild geometry or occupancy ahead of their own
stages. Current alignment and inventory values are shared with the existing
native actor consumers.

The shared equipment tail checks the actual selected descriptor/model binding,
rebuilds through the existing Equipment/ResourceFactory owners when needed, and
derives the selected action kind. The full owner tag is compared before its
halfword assignment, preserving large model-variant behavior. It reuses the same
actual model lifetime, immutable assets and weapon/audio owners as equipment
selection. Unknown required population fails after the measured model/pose
prefix, retaining the earlier action value.

ActorMessageQueue owns a fixed capacity of typed values allocated at construction.
UpdateOwner publication can feed this queue directly. Budgeted FIFO draining
applies those values through ActorReception; enqueue copies payloads rather than
retaining the caller's storage. A full/closed queue refuses admission. A failed
application consumes that one value and reports unavailable because its mutation
prefix may already be committed. Remaining values stay queued. Unsupported
families and absent mapped-room routing remain unavailable.

Both compilers pass the same516,096 original-receiver cases,257 equipment/asset
cases, eight refusal groups and147 queue composition checks. Source comparisons
include every admitted branch, all eight primary channels, filtering, raw pose
bits, inventory, signed coordinates, retained/rebuilt equipment, signed action
bytes, large owner tags and natural64-model exhaustion. Queue checks cover actual
UpdateOwner-to-receiver delivery, payload lifetime, budget/full/wrap/close and
partial-failure continuation.

The focused cohorts pass20,350,184 checks. Full resource/event/behavior/recovery
regressions pass951,424,625 checks with114,671 balanced original allocations and
releases per compiler. Both use identical frozen sources. Component counters are
captured by the focused output; the full aggregate keeps its previous fields.
Parent builds include the new library and all eight integration checks pass on
each compiler. Evidence: `native_actor_reception_qualification_v1.json`.

External transport/authentication/encoding, senders3/8/11, other receive/action/AI
branches, semantic saves and game installation/acceptance remain open. This is a
native delivery component, not an installed gameplay or slowdown fix.
