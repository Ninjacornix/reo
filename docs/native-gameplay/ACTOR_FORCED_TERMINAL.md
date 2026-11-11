# Forced actor terminal transition

The native transition uses the canonical actor, inventory/resource operations,
cooperative event pool, action pose, and local-player message sender. It clears
the inventory UI owner before calling the UI provider and records event 26.
It then applies the forced health/action state and publishes the snapshot and
any action notice. Mode 1 restores the saved health, status, action bytes, and
motion class after publication. Inventory, events, and pose snapshots follow
their own source lifetimes.

The local-player sender from original 67EB60 has its own phase, category and
selected-slot gates. Its snapshot clears status bit 08000000 and captures the
canonical actor fields. The implementation shares payload capture with the
general sender while preserving each entry's pause and suppression rules.
The new entry supports the established selectors 0, 1, and 7.

Opcode 61 now calls this provider. Its interpreter preflight checks for the
provider before executing the program. Opcode 62 can also use it when actor
state requires forced termination. Parent tests exercise both commands with
the actual resource, event, and message owners. The UI close operation remains
an explicit provider, and actual transport and game installation remain open.

## Verification

- LLVM and GCC each pass the complete 909,920,516-check resource/actor suite.
  This includes 10,240 original forced transition calls, 5,120 direct local
  sender calls, 1,400 captured messages, and 15 native refusal cases.
- The scenario suites each pass 28,178,140 checks, including 512 original
  ordinary/offline opcode-61 adapter comparisons and the transition-input
  comparisons recorded in the linked qualification.
- The existing general publication suites each pass 73,525,738 checks, including
  589,824 snapshot and 393,216 action cases with the shared payload capture.
- All seven selected parent CTests pass per compiler, including the actual
  interpreter-to-forced-transition and Update Owner transition-input callers.

The tests use controlled final UI/message sinks. The receipts retain complete
source, compiler, original-body, content, and executable identities. Live scene
orchestration and representative native gameplay acceptance remain Stage 4 work.
