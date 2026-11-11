# Native actor placement commands

Opcodes `65`, `68`, `69` and `6A` write the canonical World Session or the
existing Actor. Opcode `68` scans four records by character, including inactive
records, and sets the selected-actor request if the matching record's slot
matches the selection. Opcode `6A` resets only the first byte of each placement
request. The byte written by opcode `65` retains the original address identity
until its consumer is established.

Opcode `69` resolves literal actor indices or selector 4, which uses the
selected actor. F0 reads the counted 32-byte position records and restores the
signed X/Y/Z and yaw. F1 enters the same original `6268D0` restore with the
actor's existing saved pose. Both publish current and previous transforms
and clear the root delta and surface blend. Other command bytes write the
three-byte placement request. Native admission checks all actor and placement
extents. The immediate restore also invalidates the derived collision pose.

The complete ordinary and offline dispatchers matched 512 controlled cases
per compiler and passed the full VM regression suite. Both compilers also
passed five native parent tests. The first comparison caught F1's direct
branch to the restore helper, which the initial native translation had omitted.
The final source snapshots are under
`build-native-sjuni/gameplay-scenario-actor-placement-*-v4`, with receipt
SHA-256 `644995f1f757932807ae7f02beb4a84dc5a7f1c056239634c511c699abd4fa84`
for LLVM and `aa05f67537b37ac4902e303f5eaab6fea8e3d8878a3d632c05aabfed1c36fa67`
for GCC.

The runtime still needs the original placement packet and room-transition
consumers. Native command execution here used controlled packets and Actors.
