# Native event-completion statistics and explicit item events

The update Owner now owns one `Statistics` alongside its actual cooperative
event pool. This component reconstructs completion bits, points, the unique
available-event count and both64-entry seen arrays. It does not introduce an
opaque mirror of the original232-byte statistics block or claim its remaining
gameplay counters have migrated.

`RuleBook` holds immutable typed rules with no original pointers or sentinels.
All171 actual rules in ten paired lists and the48-byte File #1 scenario-map
prefix are pinned against owned o0 bytes. The five groups preserve original
numeric conditions, arguments, IDs and weights. Native metadata admission
requires at most64 records per seen array and event IDs below64. Other profiles
and scenario IDs beyond the measured mapping explicitly remain unavailable.

Initialization clears reconstructed state and resets the actual event pool.
The total counts distinct event IDs across both lists. Complete admitted37BBC0
and37C470 explicit-event behavior is supplied: low16 content matches every
unseen kind1 record in the explicit list, completion bits are ORed, points add
with32-bit wrapping, the seen byte is set and a real generic event is requested.
Duplicate matching records independently add points and events even if they
share a completion bit. Any nonzero seen byte suppresses the record. The current
scenario is reread on every call; changing it alone does not reset seen state.

Points and seen writes precede event append. A full pool of priority9 events
therefore retains the completion prefix and reports dropped requests. Generation
exhaustion reports an unavailable event capability after that prefix, rather
than claiming an event was stored. The update-facing method uses its actual
clock and Session scenario; absent initialization/scenario explicitly refuses.
It does not add a local-actor filter: source callers own that admission.

Both compilers pass27,872,000 combined assertions each, including329,049
explicit-completion calls,311 initializations and eight additional refusal
groups. Coverage includes every measured mapping byte, all five owned groups,
the full unsigned content domain, changed scenarios, all seen-byte values,
duplicate IDs, bit31/32/63, point overflow, actual event saturation and serial
exhaustion. Complete original initialization/explicit/marker bodies execute;
only their reconstructed state is compared for initialization. The ignored pure
mode getter is an audited three-word port. The initial metadata parser expected
LF and rejected CRLF source; its preflight failure and frozen bytes are retained.
The parser now accepts either line ending while checking the same exact data.

The actual CMake update test initializes scenario0, consumes an explicit event,
checks its completion score and generic event and verifies duplicate suppression.
Both parent builds, eight integration tests and current worker/phase comparisons
pass. Exact identities are sealed in `native_completion_statistics_qualification_v1.json`.

The subsequent [automatic completion implementation](AUTOMATIC_COMPLETION.md)
supplies condition evaluation and the actual worker binding. Other original
statistics counters/writers, ownership-tag publication and durable save/export
remain open. [Direct consumption](RESOURCE_CONSUMPTION.md) now uses explicit
events; message wrappers and health/status effects remain open.
No game or audio device was launched. Installed V39 is unchanged; coherent native
gameplay installation/acceptance and the rest of Stage4 remain incomplete.
