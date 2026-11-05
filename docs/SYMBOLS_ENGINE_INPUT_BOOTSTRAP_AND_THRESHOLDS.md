# Engine input startup, shutdown and threshold setters

Static owned resident executable SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. All3 original bodies read in full, including loop entry and configured0/-1/other modes. No controller input, game, build or target execution. Hex values.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1A5C80](../recomp/config/output/sub_001A5C80_0x1a5c80.cpp) | `initialize_engine_input_snapshots_device_records_and_threshold_defaults` | Confirmed complete static initialization/control/write flow | 1A6660mustnonzeroelse0;clearsnapshot1A6030. Setsrawpacket2B09A0byte0=FF,half2=FFFF,copies20bytesto2B09C0. Firstdevice2B0A10clearsstatus/phase/port/slot/byte5,setsbufferpointer8=2B0800. Mode231040==-1opensport0slot0;mode0openscount2B0980recordsstride18onport0,slotindex,orfallbackport1slot0ifcount<=0;othermodeopensport0slot0firstthenconfiguredport/slotindexintorecordsindex+1. Openchildstatusesignored. Copies8-byteownedthresholddefault231150to2B0A00;copiesfirstdeviceport/slottofirstsnapshot2B0A34/35,clearsflags2B0988/990,returns1. No devicecount/capacitybound or fullrecordmapinitialization. |
| [0x1A5E80](../recomp/config/output/sub_001A5E80_0x1a5e80.cpp) | `clear_engine_input_snapshot_then_close_first_device_and_backend` | Confirmed complete static initialization/control/write flow | Calls1A6030then1A6720,returnsrawlastchildstatus. Doesnotiterateconfiguredrecordsorzeroallthresholds. |
| [0x1A5EC0](../recomp/config/output/sub_001A5EC0_0x1a5ec0.cpp) | `set_three_halfword_input_thresholds_for_selected_port` | Confirmed complete static initialization/control/write flow | Forportindexa0writeslow16a1/a2/a3to2B0A00+8*port offsets0/2/4,leaveshalf6;noindex/rangechecks orstatusassignment.1A5F00consumerestablishesthresholdrole. |

Owned threshold8-byte default231150..231158 is fourlittle-endianhalfwords `[1,1,1,0]`,SHA-256 `e7416d13eb6e700f34181669425e25e2591aa33c517b38796b391c75b6de3971`. The firstdevicebuffer is a pointerstoredatrecord8,notinlinepayload. Subsequentrecordbufferpointerinitialization isnotperformedbythisbody;caller/staticstateadmissionremainsseparate.

[Raw input service](SYMBOLS_INPUT_RAW_SERVICE.md) ownsexisting1A6660/66A0/6720/6030/5F00 rows; [libpad2 reports](SYMBOLS_LIBPAD2_REPORT_BUFFERS_AND_FIELDS.md) and [DBC clients](SYMBOLS_LIBDBC_SOCKET_AND_DATA_RPC.md) nowestablishthat1A6660initializesbackendplusall16slotheaders,notaport0statusprobe. The byte-narrowednegativecheckin1A66A0remainsitsliteralcontract. [Stick scaling](SYMBOLS_SESSION_INPUT_STATUS.md) uses thethresholds,withindependentdivision/deadzoneadmission.

Audit: 3 rows, 142 verified owned instruction words; 7 omitted interval words are zero/NOP; 0 omitted nonzero words.
