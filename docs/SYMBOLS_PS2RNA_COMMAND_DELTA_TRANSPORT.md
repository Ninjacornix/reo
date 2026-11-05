# PS2RNA delta-command serialization and command acknowledgement callback

Static File #1 US research, 2026-11-04. Original **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Full original bodies, callback registration in13E2B8 and all1000 owned attenuation table words220498..221437 reviewed. No commands, audio, DMA, RPC or game executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x13E000](../recomp/config/output/sub_0013E000_0x13e000.cpp) | `serialize_PS2RNA_group_control_deltas_into_DTX_command_block_candidate` | Confirmed full field comparisons and transport producer | a1 output block:countword0,16-byte commands at10. Scans16 active groups223880,stride60; uses group remoteID20 in commandword4. Compares desired/last pairs and emits types8,2,A,3,4,5,9 in order shown below,updating last-sent fields immediately. Checks total128 after individual groups of emissions; per-channel type9 inner loop has no capacity check, and an outer check exits at127 beforehand. With intended at-most-two channels, count126 followed by two changes fits128; larger malformed counts need separate admission. Leaves unassigned commandwords untouched. Stores final count; no remote acknowledgement/error/retry or actual DMA in this callback. |
| [0x13DFA0](../recomp/config/output/sub_0013DFA0_0x13dfa0.cpp) | `PS2RNA_DTX_completion_delay_from_received_count_candidate` | Confirmed complete callback and registration | Ignores a0. NULLa1 enters permanent NOP loop; otherwise reads signed count=*a1 once. Positivecount performs literal decrement/NOP loop tozero; nonpositive returns. Does not parse command results, return spans, publish an error or reread progress. This callback can delay a service invocation but no live duration/cost is established. |

| Command type | Input condition and payload | Last-sent publication |
| --- | --- | --- |
| 8 | Signed desiredbyte53 differs from52; command8=signed53. Owned IOP receiver stores low byte into thru/drain flag1; exact1 enables repeated pool1-to-pool0 disposal in IOPRNA_ExecHndl. | 52=53. |
| 2 stop | Packed half24==0100 (desired24=0,last25=1); command8=signed24. | 25=24. |
| A | Desiredword48 differs4C; command8=48. Owned IOP receiver stores the value and selects PSM_SetMix0 for exact1, PSM_SetMix1 otherwise, with volume refresh on the latter path. Bus/output meaning remains qualified. | 4C=48. |
| 3 | Signed desired channelbyte26 differs27; command8=signed26. | 27=26. |
| 4 | Desired sampling-rateword28 differs2C; command8=28. | 2C=28. |
| 5 | Desired attenuationword30 differs34; command8=0,commandC=owned word(220498-4*attenuation). | 34=30. |
| 9 | For each signedchannelcount26, desiredpan38+4*i differs40+4*i; command8=channelindex,commandC=desiredpan. | 40+4*i=desiredpan. |
| 2 play | After channel deltas,packedhalf24==0001 (desired24=1,last25=0); command8=signed24. | 25=24. |

The attenuation lookup has1000 uint32 values, monotonically nonincreasing: first256, at indices100/200/300/400 are80/25/8/2, last entries0. The setter clamps decimal[-999,0], so its ordinary range covers the owned table. These values support an attenuation role but do not establish a decibel convention or current device mixing behavior. No semantic credit is granted merely for a table cell or command number. The [owned IOP mixer review](SYMBOLS_PS2RNA_OWNED_IOP_DOLBY_AND_MIX_ROUTES.md) resolves typeA, and [second-pass audio review](recvx-crosscheck/AUDIO_SECOND_PASS.md) resolves type8's exact drain consumer. Neither immediate last-sent publication proves remote completion.

Offsets, type numbers and masks hexadecimal; table counts/indices/values in the preceding paragraph decimal. Related: [audio setters](SYMBOLS_PS2RNA_AUDIO_CONTROLS_AND_UNSUPPORTED_API.md), [transport lifetime](SYMBOLS_PS2RNA_LIFECYCLE_AND_VOICE_CONFIGURATION.md), [DTX sequence protocol](SYMBOLS_CRI_DTX_TRANSFER_CONTEXT_AND_ACKNOWLEDGEMENT.md), [central index](FUNCTION_INDEX.md).
