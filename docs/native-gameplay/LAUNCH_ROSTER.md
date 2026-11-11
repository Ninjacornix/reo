# Native launch roster initialization

The native Session, World actors and action-choice owner now consume the first
32 bytes of the launch record through `Owner::initialize_launch_roster`.
The implementation follows complete5EB0D0 and its actual mode getter1B0300
and shared RNG1AEC80. Four player entries and two AI entries carry character,
appearance and 16-bit model variants. Population is a derived count of the
same roster. The choice row preserves the existing choice counters.

Initialization changes preexisting canonical actors. It preserves their activity,
slot numbers, transforms, inventory and other fields. It sets the single-roster
setup byte only in mode0, preserves it in other modes, advances the shared
secondary RNG through mode3 and stores the resulting low two bits in the same
RNG owner's observed byte. Those effects match the original routine.

Both LLVM and GCC pass29,062,896 identical checks in the complete scenario
comparison, including4,096 direct launch initializations and six bounded
refusals. Cases cover every mode byte, all supported player/AI counts, all four
choice rows and high-bit appearance/model values. Short input, excessive counts,
invalid choice row, a missing actor and a closed World preserve native state.
Seven parent integration tests pass under each compiler. The actual Update
entry point is exercised with a missing sixth actor, then with all six actors.
Evidence is sealed in `native_launch_roster_qualification_v1.json`.

The importer retains ordinary file encodings and owns decoded native values.
Actor/model creation5EB520/5EC100, the game launch caller, scene startup and
coherent native gameplay acceptance remain open. Installed gameplay remains
V39. Stage4 remains incomplete. These comparisons launched no game and measured
no live performance change.
