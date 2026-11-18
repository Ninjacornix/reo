# Native control value and ownership reception

2026-11-10. Complete bounded681820/6818D0 now update the same Session control
registrations used by native request producers. Stage4 remains incomplete;
installed gameplay remains V39.

The direct application helper masks the encoded index to six bits. Mode0 copies
four payload bytes, including to inactive registrations. Mode1 copies one owner
tag only when the external activity-mode result equals zero. Other modes ignore
the payload. The native API represents an unavailable activity-mode fact
explicitly and requires it only when a nonempty owner update would consume it.

The packet helper follows the original framing: mode0 has one index plus four
payload bytes independently of the length byte. Nonzero modes process
floor((length-4)/2) entries; an odd final byte is ignored. The native admission
checks physical extents and length underflow before effects. These checks do not
claim an equivalent original out-of-bounds result or establish outer network
framing acceptance for unusual length bytes.

Both compilers pass75024841 identical checks, retaining every preceding AI/control
producer comparison.4096 complete direct applications cover all256 encoded
indices, modes0/1/2/255 and activity values-1/0/1/2.64516 complete packet calls
cover all256 packet-mode and length-byte values within physical buffers.1020
unsafe underflow profiles refuse. Extra native checks cover short buffers,
missing required mode facts, empty batches and unused mode/payload inputs.

The oracle declares1AFE70 as a controlled external read-only activity-mode result
(4020602 observations). It does not claim the complete main/overlay mode provider
or its producer is native. Both receive bodies execute completely with word
audits; no successful packet-handler double replaces them.

Both parent builds and twelve integration tests pass. Actual Owner checks verify
canonical payload changes, conditional owner updates, refusal on unknown mode,
subsequent outgoing-request admission and World closure. Evidence is sealed by
`native_gameplay_ai_receive_qualification_v1.json` (SHA256
`7b3e6e3b8e756fd2319fb989547af743e0d6c46a58a7ee7c8cc5b4cdb42c2696`).

The later [Session activity query](SESSION_ACTIVITY_MODE.md) supersedes the
external result substitute above: the full original query chain now executes,
and actual Owner reception derives its mode from the canonical Session. Its
initialization/network producers remain open; historical evidence is retained.

Complete activity-mode production, outgoing service/transport, frame reset,
initialization/observations/goal/action dispatch, input/network/save ownership
and coherent native game installation/acceptance remain open. No game was
launched or performance change measured for this work.
