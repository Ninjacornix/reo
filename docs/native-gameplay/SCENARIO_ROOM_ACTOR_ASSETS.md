# Room actor asset requests

The Session now owns the shared 128-room table of four asset requests per room.
Opcodes `0x85`, `0x86`, and `0x87` append a pair, remove matching IDs globally,
and remove matching IDs from one room. Append requires both halfwords of the
free entry to be FFFF. A full row leaves the table unchanged. Native bounds
checks reject a room outside the original 128-row table.

The same owner supplies the auxiliary descriptor allowance query from original
684770. Scenario script binding resets this table after successful admission.
Failed admission preserves the previous table and script channels. The actual
auxiliary descriptor and model loading callers still need to adopt the owner.

LLVM and GCC each pass 25,653,119 scenario checks, including 2,048 ordinary and
offline dispatch comparisons and 16,384 original descriptor allowance queries.
The test compares every table entry and checks reset, partial sentinels, full
rows, duplicates, and bounds refusal. The direct archive regression still reads
all 171 owned members and binds 51 room profiles on each compiler. These are
isolated comparisons. Live scene construction and game acceptance remain open.
