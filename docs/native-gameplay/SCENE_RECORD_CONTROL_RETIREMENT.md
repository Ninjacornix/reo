# Scene-record condition clearing and control retirement

Opcode165 now composes the canonical eligibility bank, EnemyDescriptors and
shared AI ControlRequests. Its complete6943D0 semantics clear the selected bit
first, then inspect all256 descriptor rows. Each row with owner_mode nonzero
and condition equal to the full payload word retires the first matching kind2
control registration for that physical row. The scan deliberately does not use
the imported descriptor count or an active-byte filter. Duplicate control
registrations retain the original first-match behavior.

The native helper `clear_scene_record_eligibility` uses the existing qualified
ControlRequests::unregister_control (complete681330). It preserves registration
payload, phase and owner tag while clearing only the source-owned active/kind/
target/counter fields. Neither operation sends a flag notification or retires
live Actor generations. Invalid bit IDs and closed Worlds refuse before mutation;
Program import validates the admitted256-bit extent and four-byte payload.
Whole-program execution requires the canonical FlagState and World before any
earlier instruction changes counters.

Both compilers pass the complete current interpreter comparison:
492,589,059 checks each, including2,048 complete6943D0/681330 comparisons and1,344
actual ordinary/offline165 dispatcher comparisons. Test descriptors have a
published count of zero but populated physical tail rows, proving that the
complete256-row traversal is retained. Cases cover multiple matching rows,
duplicate registrations, absent registrations, owner modes, unchanged descriptor
fields, notification absence and invalid/missing provider boundaries.

The same frozen comparison also includes the new opcode73 VM integration:
9,072 ordinary/offline dispatches,1,800 actual declared audio-port calls,
290,304 mixed native bank frames and4,944 nonzero samples. It compares real
native BankSession request state, shared RNG, remembered cues and PCM. The
VM's1B8930 boundary is an explicit test port feeding a separate real native bank;
the [script audio proof](SCRIPT_SCENARIO_AUDIO.md) independently executes the
complete original1B8930 and lower audio behavior. These two boundaries must not
be conflated.

The [qualification record](../../tools/native_reconstruction/native_scene_record_control_retirement_qualification_v1.json)
identifies exact frozen source and receipts. Source coverage is358 ordinary and
330 offline table entries, including original no-ops. This does not establish
complete authored-program coverage. Full current room/scenario ownership,
scene-record eligibility readers, semantic save/resume and installed gameplay
acceptance remain open; Stage4 remains incomplete.
