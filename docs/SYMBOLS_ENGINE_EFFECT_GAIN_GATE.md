# Engine effect gain gate and sound-request initialization

Static resident executable SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Both complete original intervals and queue failure exits reviewed; no audio, RPC or game execution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1ACEB0](../recomp/config/output/sub_001ACEB0_0x1aceb0.cpp) | `apply_effect_gain_with_zero_volume_gate_and_slot_or_global_sdr_command` | Confirmed complete static queue/gate/control flow | Args selector,gain. Gain0queues1A7BB0(1);negativechild=>-1,elsesets2B3838=1. Nonzerogainifflagsetqueues1A7BB0(0),failure-1,elseclearsflag. Then selector-1queues1A7690(low16gain),otherwise1A7730(low8selector,low16gain),propagateschild. Gateflagmutatesbeforefinalgaincommand,soqueuefailuredoesnotrollbackflag. Effectgainrolecorroboratedsavedvolume1B82E0/1B86F0callers;exactIOPcommandsemanticsremainpartial. |
| [0x1AC6D0](../recomp/config/output/sub_001AC6D0_0x1ac6d0.cpp) | `initialize_sdr_audio_control_and_named_sound_bank_request_state` | Confirmed complete static queue/gate/control flow | Calls1A71E0,then1A7FB0(function10,arg0),clears2B3838,1AD5C0,returns1withoutadmittinginitialization/asyncsubmissionresults. DoesnotwaitforRPCcompletionorloadabanklocally. |

[Saved effect gain settings](SYMBOLS_AUDIO_SETTINGS_BANK_FLOW.md) corroboratethegainrole. [SDRcommands](SYMBOLS_ANIMATION_SOUND.md) owncommand29/4C/41packingandasyncRPC10submission; [named bankrequests](SYMBOLS_NAMED_SOUND_BANK_REQUEST_SERVICE.md) own1AD5C0scratchbinding. Zero-volumecontrolandgainpackingareseparatequeueoperations; thisisnot a measured latencyor audio synchronization fix.

Audit: 2 rows, 53 verified owned instruction words; 3 omitted interval words are zero/NOP; 0 omitted nonzero words.
