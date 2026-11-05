# Resident IPU: DMA control, saved context and initialization commands

Static File #1 US research, 2026-11-04, resident main ELF `SLUS_207.65`, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Seven complete bodies,382 owned instruction words, all80+32 constant bytes and the exact command sequence were independently read. No game, build, replay, target execution, IPU command, attachment, network request or live-memory inspection occurred.

Addresses10002000/2010/2020 and DMA channels1000B000/B400 establish an IPU-related register/context family in the original artifact. Labels retain candidate API identities and exact busy-loop limits. [Interrupt guards](SYMBOLS_EE_INTERRUPT_GUARDS_AND_HEAP_BREAK.md) describe the called disable/restore wrappers; [GS transfer notes](SYMBOLS_GS_ENVIRONMENT_AND_TRANSFER_SDK.md) describe the separate graphics path. Neither family is a measured slowdown, current call frequency or host implementation proof.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x113BA8](../recomp/config/output/sub_00113BA8_0x113ba8.cpp) | `write_ipu_from_dma_control_under_interrupt_and_dma_enable_guard_candidate` | Confirmed complete interrupt/MMIO/restore flow | Saves input,11D660 disables interrupts and reports prior state. Reads1000F520, writes valueOR10000hex to1000F590, writes original input to1000B000, rereads1000F520 and writes cleared10000bit to1000F590. Calls11D6B8 only when prior state nonzero. Does not restore original DMA-enable bit verbatim or wait for transfer completion. |
| [0x113C20](../recomp/config/output/sub_00113C20_0x113c20.cpp) | `write_ipu_to_dma_control_under_interrupt_and_dma_enable_guard_candidate` | Confirmed complete interrupt/MMIO/restore flow | Same independently read guard sequence, targeting1000B400. No local transfer completion or error status normalization. Entry113F38 is a separate identical control writer used by initialization. |
| [0x113C98](../recomp/config/output/sub_00113C98_0x113c98.cpp) | `stop_and_capture_ipu_input_output_dma_register_context_candidate` | Confirmed complete register capture and FIFO gate; hardware stability partial | Calls113C20(1), storesB410/B430/B420/B400 at context0/4/8/C; spins while10002010&F0, then113BA8(0), storesB010/B020/B000/10002020/10002010 at10/14/18/1C/20. No iteration/time limit, sleep or cancellation branch in FIFO loop. At least24hex writable context bytes required by stores, not locally checked. |
| [0x113D80](../recomp/config/output/sub_00113D80_0x113d80.cpp) | `restore_ipu_dma_context_with_bit_pointer_fifo_compensation_candidate` | Confirmed complete arithmetic, optional restarts and busy gates; context validity partial | Derives bitPointer=context1C&7F, extraQWC=((1C>>8)&F)+((1C>>16)&3), adjusted input count=context8+extra and address=context0-16*extra. If saved output address10/count14 nonzero, restoresB010/B020 and starts via113BA8(saved18|100). Waits while signed10002010 negative, writes bitPointer to10002000 and waits again. If adjusted address/count nonzero restoresB410/B430/B420 then tails113C20(savedC|100). No bounds, timeout or whole-context equivalence proof. |
| [0x113ED0](../recomp/config/output/sub_00113ED0_0x113ed0.cpp) | `wait_or_query_ipu_control_busy_bit_candidate` | Confirmed complete mode and return flow | Mode0 spins while signed10002010 negative then returns0. Mode1 returns register bit31. Other modes return0 without register read. Wait has no timeout/yield or caller progress check; no runtime hang reproduced. |
| [0x113F38](../recomp/config/output/sub_00113F38_0x113f38.cpp) | `write_ipu_to_dma_control_for_initialization_with_interrupt_guard_candidate` | Confirmed complete independently read duplicate mechanics | Same complete original body as113C20: writes1000B400 through interrupt/DMA-enable guard. Separate entry and initialization caller retained; this does not provide a second independent hardware contract. |
| [0x113FB0](../recomp/config/output/sub_00113FB0_0x113fb0.cpp) | `initialize_ipu_fifo_tables_and_issue_fixed_command_sequence_candidate` | Confirmed complete constants/FIFO/command/wait flow; table semantics candidate | Starts113F38(1), writes10002010=40000000, waits busy clear, issues command0 and waits, sends FIFO10007010 quadwords209CB0+0/10/20/30/40 then repeats+40 three more times, issues50000000 then58000000 with waits. Sends two209D00quadwords, issues60000000,90000000, resets40000000, then command0; each stage waits busy clear. No timeout or game progress hook. Constants resemble quantization/palette setup, but exact SDK name and complete decoder-state meaning remain unproved. |

The original busy loops test signed32 register negativity, representing bit31, except the context-capture FIFO-count maskF0. Every initial loop entry and repeated register read was checked. These are unbounded guest register polls; whether native overrides yield, emulate completion or bypass them is a separate source/runtime investigation. No execution or timing evidence here establishes that a player incident traversed one.

The guard wrappers clear the10000hex enable/suspend bit after the protected write even if it had been set before entry; only CPU interrupt enable is conditionally restored from the saved result. The context restore’s pointer/count compensation is literal guest32 arithmetic and does not validate a context’s provenance or underlying buffers. Successful local returns do not prove later DMA or IPU completion.

## Complete constants and FIFO order

Owned **209CB0..209D00**,80bytes, SHA-256 **6cfa0a25279ddf079af0017fc16fc08796f6d91ae5aa21d9a91c1bc8e555b11e**:

```text
08 10 10 13 10 13 16 16 16 16 16 16 1A 18 1A 1B
1B 1B 1A 1A 1A 1A 1B 1B 1B 1D 1D 1D 22 22 22 1D
1D 1D 1B 1B 1D 1D 20 20 22 22 25 26 25 23 23 22
23 26 26 28 28 28 30 30 2E 2E 38 38 3A 45 45 53
10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
```

The first four rows are each sent once; the final row is sent four times total. The FIFO therefore receives128bytes from this80-byte owned storage, retaining repeats rather than inventing128 distinct stored bytes.

Owned **209D00..209D20**,32bytes, SHA-256 **ddbcd5dffa2acac67836bc3ea702ef0cb402beb924bfa723bebd7ee75193d15d**:

```text
00 00 21 04 42 08 E0 03 84 10 A5 14 C6 18 E7 1C
1F 00 29 25 4A 29 00 7C 8C 31 AD 35 FF 7F CE 39
```

No bytes were transformed into a VU program, emulator workload or replay. All382 instruction comments match original owned ELF bytes; aligned omissions are zero. This notebook covers the complete113FB0 body through1141E8 despite its start in the assigned lower range. No runtime/build change, execution, decoding result, numerical test or slowdown diagnosis is claimed.
