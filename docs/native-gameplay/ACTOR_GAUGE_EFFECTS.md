# Native actor gauge adjustment and threshold events

Status: qualified on both compilers; uninstalled. Stage4 remains incomplete.
InstalledV39 is unchanged; no game or physical audio device was launched.

The UpdateOwner now supplies complete660060 gauge adjustment and667E90
threshold notification through canonical Actor state, the actual cooperative
event pool, simulation counter and room. No second clock, actor registry or
successful callback stand-in is introduced. GaugeBAC remains optional until
an actual producer or import supplies it.

Addition preserves class/selected-actor admission, low16 amount, signed-low8
mode, BB6/BB8/BBA modifiers and auxiliary/status masks. The BBA modifier view
reuses `linked_model_variant`, preserving its existing model consumer rather
than creating a duplicate field. Threshold notification precedes the addition;
the quantity is reread afterward. Unsigned addition can wrap. Subtraction keeps
the wrapped result only when its signed interpretation is positive. This is
not an unconditional unsigned saturating subtraction.

Threshold conversion668050 uses the selected character's cap with an explicit
before/after value; it needs no stored selected gauge. At most the first upward
50/70/90 crossing emits event21/22/23hex. The later comparison667F90 reads the
selected actor's stored gauge independently. The mutated actor is clamped to
its own character cap. A newly local cap sets auxiliary10000000 before event24hex.
These are actual cooperative records, not audio events or per-second rates.

Original660060 also invokes pure668110(actor,100) near the cap and discards its
return. The oracle executes its complete body with the actual owned cap and
exact-integral conversion. Native state does not emulate that discarded pure
result. The oracle rejects every other float-to-word conversion, including
unadmitted message selectors. This does not qualify general PS2 rounding or
exceptional floating-point behavior.

Both compilers pass70,103,000 combined assertions with identical observations:
720,920 adjustment cases,65,536 direct crossing cases,216,410 retained-record
observations across independently reset cases, nine capability/lifetime groups
and24 capacity profiles. Capacity tests start with126/127/128 real records and
exercise pruning/full behavior between threshold and cap events. Normal
priority rejection or full capacity preserves the original ignored-queue-result
behavior; a closed or unavailable native consumer is explicitly reported.
Missing selected state or an unsupported profile preserves any preceding
addition, cap or auxiliary-flag mutation. Existing message/activity cases remain
included. Both production builds and all eight integration tests per compiler
pass. Exact identities: `native_actor_gauge_effects_qualification_v1.json`.

Pending-hit and other real gauge callers, periodic667420 progression, gauge
initialization/import and the remaining gameplay owners still require migration.
Final transport, semantic native World save/load, coherent installation and
representative game acceptance remain open. This is not a measured slowdown fix.

Follow-up: [pending-hit gauge application](ACTOR_HIT_GAUGE.md) binds this actual
mutation owner into native World/behavior and removes the old D28 cleanup
provider. The earlier gauge qualification remains immutable; periodic progression,
other hit effects/import and installation remain open.
