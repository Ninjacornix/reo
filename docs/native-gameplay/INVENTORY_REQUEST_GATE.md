# Canonical inventory request gate

The nonzero branch of opcode63/68F140 now invokes actual604300 through the same
application-owned `InventoryUi` used by108 and recovery. It tests the complete
payload word, then stores1 in the optional canonical request-blocking byte8D.
`request_blocked()` exposes that exact value to dialogue/UI callers. An absent
producer remains unknown. Actual6DEC80 does not write8D, so repeated cold UI
initialization preserves this independent role.

The zero branch604310 clears8D and three asset-cache bytes before invoking
resource-reset6DDD70. That complete path is still unowned. `request_mode_ready`
and whole-Program admission refuse it before executing an earlier script
prefix. No successful reset callback or guessed empty cache is installed.
Missing and foreign UI owners likewise refuse before a prefix mutation.

The complete original63 handler and604300 body execute through both original
dispatchers in `inventory-request-vm-{llvm,gcc}-v1`. Both cohorts pass586,070,532
checks, including524,296 request programs, six refusals and64 complete6DEC80
reinitializations preserving8D. Tests cover every nonzero low16 word, values
whose low byte/halfword is zero, high-bit full words and four World modes, with
the entire affected64-byte global projection checked. Current28-parent suites
also pass both compilers with the same UI ABI.

The owned r028 ordinary EVB advances from63 at block2+300 to153 at block2+2536.
All171 banks retain34 ordinary/27 offline admissions; no complete scenario EVB
is admitted. The static opcode mask leaves65 ordinary records across nine
opcodes. The frontier tool separately retains the one authored zero63 command
as a known unimplemented payload branch:66 known unimplemented ordinary
records in total. Linear authored records do not establish dynamic reachability.

The exact seal is `native_inventory_request_gate_qualification_v1.json`.
Installed gameV39 and full Stage4 acceptance remain unchanged.
