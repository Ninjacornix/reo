# Scenario actor inventory grants

Opcodes 38, 39, and 173 (hexadecimal) now grant resources through the native
Actor inventories and the shared scene resource pool. The pool uses the same
template defaults and handle allocation as other native resource consumers.

- 38 allocates the signed resource ID and quantity, then attempts insertion
  into the selected active actor. The allocation persists when insertion fails.
- 39 searches matching active characters in actor order. An allocation failure
  ends the scan. A full inventory keeps the allocation and lets the scan continue.
- 173 accepts IDs 300 through 302. The first active character 7 needs item 413
  in storage and fewer than three copies of the requested item. The handler
  allocates each unit, inserts it into the matching storage group, then compacts
  the inventory. Original execution corrected the previous static mapping of
  the accepted range.

The interpreter validates the world, resource providers and population profile
before dispatch. The original first two handlers use a signed population byte.
173 uses the full signed population word. The native insertion checks the
storage group bounds before writing, including when the group is already full.

The LLVM and GCC v3 scenario receipts each pass 21,323,566 checks, including
2,048 grant dispatches through the ordinary and offline actor tables and 512
actor placement dispatches. The separate LLVM and GCC inventory suites each
pass 15,404,715 checks, including 30,576 compactions. The opcode ledger records
the receipts and coverage for these profiles. These comparisons use owned
original code with controlled actor, template, and pool state. Stock startup
must still supply those providers in the live game.

Run `tools/native_reconstruction/gameplay_scenario/verify.py` on each compiler,
then use `tools/native_reconstruction/gameplay_scenario/qualify_v19.py` to
verify the receipts and publish the coverage ledger.
