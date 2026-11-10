# Canonical actor alignment target and publication

Status: qualified on both compilers; uninstalled. Stage4 remains incomplete.
InstalledV39 is unchanged; no game or physical audio device was launched.

The actor now has one optional `AlignmentTarget` containing a position and signed
yaw. It is separate from current/saved position, body direction and collision
shape targets. Source666F50 writes C34/C38/C3C and C4C after contact-offset
admission;66D850 consumes that target during alignment. Those two bodies have
owned instruction-word provenance audits here. They are not executed by this
message comparison or claimed migrated by that historical fixture. The later
[native contact producer](ACTOR_CONTACT_ALIGNMENT.md) now executes666F50 and its
complete heading/trig chain in separate qualified comparisons. Other source phases reuse overlapping
storage; that does not establish an admitted native alignment target.

Selector6 uses this same value through UpdateOwner/StatePublication and the
common phase/authority/status/suppression gates. It captures raw XYZ and signed
yaw before room lookup, then rereads mode before final dispatch. It neither
reads the selected actor's gauge nor changes status/suppression. Framing retains
the observed type6/length20/dispatch4 contract; untouched final stack padding is
not a native wire layout. Missing target, mapping or required message consumer
returns unavailable. Existing sinks have an unsuccessful default for the new
typed message.

Both compilers pass74,567,101 combined checks with identical observations:
196,609 new cases,29,156 messages,14,610 mapped-room lookups and ten capability/
lifetime refusal groups. The matrix covers all yaw halfwords, dispersed raw
float bits, full byte slot/selection domains, admission gates, callback mutation
and wrapped integer channels. The actual Owner facade also sends with unknown
gauge state. Both parent builds and all eight integration checks per compiler
pass. Evidence: `native_actor_alignment_message_qualification_v1.json`.

Other target producers/import, alignment movement, selectors3/5/8/9/11,
queue/receiver/transport, semantic native saves and game installation/acceptance
remain open.
