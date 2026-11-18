# Native scenario room counter policy

The File #1 handler at `691D20` (opcode F2) writes one signed halfword in the
Session's existing `RoomContacts::counters` bank. The destination must fit the
128-room, 24-counter extent established by the original `5D7CF0` initializer.
That initializer fills every cell with column four of the selected policy row
and preserves the adjacent pending-contact array.

Selectors below decimal 100, including negative values, use the low four bits
to select one of sixteen halfwords in the built-in policy row. Other selectors
subtract 100 before masking, then store the low halfword of the selected EVB
word. The original loader at `68C260` relocates EVB top-level word `+0x34`,
so the authored words come from scenario EVB object 13. Each of the five
hash-verified File #1 EVBs provides exactly 256 bytes there, covering four
rows of sixteen words. The native VM checks for the required policy at entry
before it mutates any script state. The offline dispatcher retains its
existing actor-category restriction.

Both compiler comparisons use the full original initializer and handler.
The controlled corpus uses the five owned EVBs plus a high-halfword truncation
fixture, with 24 original resets, 73,728 original handler calls and 192
ordinary/offline dispatches per compiler. The original-dispatch comparison
also checks the restored continuation and the complete counter bank.

The game still needs a native caller for Session setup and complete stock
program installation. [Interpreter qualification](../../tools/native_reconstruction/gameplay_scenario_qualification_v18.json)
