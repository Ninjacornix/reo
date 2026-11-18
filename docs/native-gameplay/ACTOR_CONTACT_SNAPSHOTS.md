# Canonical native contact snapshots

Status: qualified on LLVM and GCC; uninstalled. Stage4 remains incomplete.
InstalledV39 is unchanged and no game was launched.

Selector5 now captures the actual native actor action/position/health/status and
contact response state. It shares HitActor and the existing collision Component:
source identity, direction, related-source pair, response code, region and
auxiliary fields have one owner. It does not introduce a second hit snapshot on
the actor. A native EntityId replaces the original embedded guest pointer.

Position conversion admits finite signed32 results, truncates toward zero and
retains the low signed16 bits, matching the source's initialized payload. Raw
status is retained; selector5 does not run the selector1/2 classification write.
Gauge classification uses the selected primary, independently of the sender.
Category1 initializes the model-variant byte. Unknown stack padding is omitted
from the typed contract; its observed52-byte framing is not a new wire layout.

Capture precedes room lookup. Shared suppression5 commits before delivery and
blocks recursive selector5 sends. Lookup callbacks can change the actor and mode
without changing the captured payload. Missing gauge/conversion capability fails
before suppression; missing mapping or message consumer retains that committed
prefix. The actual UpdateOwner facade uses the same publication owner.

Both compiler cohorts execute complete67E230 with its actual selected-gauge and
dispatch helpers. Original source pointers are translated only through an
explicit null/sender/peer identity map in the comparison. The finite conversion
profile does not establish physical PS2 exceptional arithmetic or FP flags.
589,840 new cases produce258,305 messages,131,074 room lookups and13,597 recursive
suppression checks. Thirteen refusal groups cover capability/lifetime errors.
The combined85,601,086 checks also rerun the earlier contact-alignment/math,
snapshot, gauge and event matrices. All eight parent integration checks pass on
both compilers. Evidence: `native_actor_contact_snapshot_qualification_v1.json`.

Messages3/8/9/11, actual queue/receiver/transport, remaining action/hit callers,
semantic native saves and game installation/acceptance remain open.
