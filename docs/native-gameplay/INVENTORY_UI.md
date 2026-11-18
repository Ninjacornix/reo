# Canonical cold inventory UI and opcode108

`NativeSession` exclusively owns `InventoryUi`, bound to its existing World.
Construction adopts the actual6DEC80 cold initializer. The same owner implements
the existing `RecoveryUi::close` interface, so recovery and scenario commands use
one state and one selected actor. Generic UI state remains unavailable until that
initializer runs; there is no second Session, actor pool or emulated memory bank.

The typed cold projection represents the initialized phase, three panel flags,
two enable bytes and primary/secondary record selections. Original6DEC80 clears
the complete16004-byte domain; the native owner does not claim implementations
for all of that domain's later active payload roles. Initialization preserves
the canonical inventory-owner byte, which the source initializer does not write.

Opcode108 executes complete6925C0 through5F4FD0 and the cold6E1430 branch: selected
actor auxiliary statusBA4 gains400, frame marker4BAE89 gains3, inventory owner
4BADEE becomes0, then the shared recovery close clears actor statusBA0 bit8000.
Direct recovery close preserves inventory owner. Both original dispatchers use
this same native command. Program admission requires the canonical bound owner,
known cold phase and the selected physical primary actor before executing a
prefix. Inactive existing actors remain valid, as in the source.

Active phases1/2 and other nonzero phases require actual equipment, audio and UI
teardown owners. They explicitly refuse. This checkpoint does not claim the
active inventory frame loop, request processing or resource-reset6DDD70.

The paired `inventory-ui-{llvm,gcc}-v1` comparisons pass4,262,927 checks each:
256 complete original initializers,16,384 commands and16,384 recovery closes,
including whole affected actor-record projections. The paired complete
interpreter `inventory-ui-vm-{llvm,gcc}-v2` cohorts pass578,910,460 checks each,
including65,536 UI programs and four provider refusals. Failedv1 linkage receipts
are retained; the fixture added explicit throwing traps for unexecuted active
helpers, without changing native production behavior.

Current28-parent suites and real227-room-key lighting asset suites pass with
both compilers. All171 banks retain34 ordinary/27 offline admissions. The owned
r028 ordinary EVB advances from108 at block2+288 to63 at block2+300; no complete
scenario EVB is admitted. The static role0 audit now finds68 unsupported
ordinary instructions across11 opcodes in4,837 authored records. These counts
describe linear authored content, not proved dynamic reachability.

The machine-readable seal is
`tools/native_reconstruction/native_inventory_ui_qualification_v1.json`.
No game, device or installed acceptance run is part of these proofs. Installed
gameV39, terminal frame services and full Stage4 acceptance remain open.
