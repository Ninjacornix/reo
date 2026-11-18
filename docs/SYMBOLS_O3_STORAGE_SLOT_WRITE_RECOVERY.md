# File #1 o3 two-slot profile write and status-specific recovery

Static full-body review of owned `netwk.bin`, runtime ID4/base570000, SHA-256 `5d23ef8bf97c107421f4bcf8589cf8941f3305ae5f6715573ed68837b9511dfb`. Entire5FE4F0..5FF8D4 interval reviewed in three chunks plus an explicitly recovered truncated middle5FF4D0..5FF5F0. Branch delay slots and unsigned state load reviewed. No game, builds, card/file operations, endpoints, live attachment or runtime changes. Hexadecimal states/offsets unless marked decimal. Resident I/O semantics and exact user-facing error policy remain partial.

Companions: [profile root menu](SYMBOLS_O3_ROOT_PROFILE_MENU_CONTAINER.md), [storage adapters](SYMBOLS_O3_PROFILE_BANK_SERVICE_ADAPTERS.md), [binary choice contract](SYMBOLS_O3_BINARY_CHOICES_MARKER_TEXT.md). Profile commits are described as static paths; none were executed.

| Identity / source | Proposed role | Confidence | Evidence and contract |
| --- | --- | --- | --- |
| [o3 0x5FE4F0](../recomp/config/output_ovl/o3/o3_005FE4F0_0x5fe4f0.cpp) | `choose_profile_storage_slot_write_and_route_status_specific_recovery` | Confirmed/static control/data mechanics; full storage policy partial | Nestedphase6DF152 is UNSIGNED, so82..AC statesareadmissible(unlike5FFB20signedphase).0storageinitthen1C0370(0),clear*(32440C)+31F000[16800].1constant5FDDF0->2/timer15420/selected15A0/cursorB.2afterdelayup/downselect0/1;acceptclearuppertriplet,phase3/timer20;607C30(workspace33F000)->1CA,channel1C9=selection,607B90(buffer31F000)copies/preparesprofileandstartsresidentwrite. Cancel->64/timer20.3afterdelaypoll607B50:0->4/timer60,constant5FC2A0/empty5FC2B0then1C09D0(channel,buffer)again;-255->6E,-254->78,-253->82,-252->8C,-256->96,otherswait.4afterdelayservices1C03A0/status1C1260:0->5/timer60,-256->A0,-254->78,-255->6E,otherswait.5counter0oracceptlast9ticks->6;6returns1. Error/recoverygroupsbelowreturn0untiltheirterminalstates. No independent harddeadlinewhileproviderpending. |

Each normal error-group prelude predecrements154 until<=0, increments state, sets binary choice6DF179=0, reloads15420decimal and enables cursor0/two choices. Error-choice bodies wait until154 is exactly0 before5F6BE0; nonzero values are decremented. Choice+1/-1 below are the helper results, not an inferred button or yes/no label.

| Phase / source block | Prompt code | Choice +1 | Choice -1 / additional behavior |
| --- | --- | --- | --- |
| 64/65,5FEADC/5FEB30 | 72 + type1field4 | 66 after20; terminal66=-1 | 67 after20,selection15A0;67resets2/timer20/cursorB toretry slot choice. |
| 6E/6F,5FEC94/5FECE8 | 73 + type1field4 | 70 after20; terminal70=-1 | 67 retry. |
| 78/79,5FEDF0/5FEE44 | 6E + type1field4 | 7A after20 and607C20(1C0DC0(0));7Apoll607B50==0->67 after60,==-256->7B after20/binary0/cursor0 | 64 restart-group.7Bprompt74:choice+1->7Cterminal-1;choice-1->67 retry. |
| 82/83,5FF118/5FF174 | 75 + type1field4 | If607BF0!=0 then choice+1 resets4/timer20,1C03F0,empty5FC2C0,1C09D0(channel,buffer) | If607BF0==0,enterAA/timer20 andclearUI. Otherwisechoice-1->64. The provider test precedes timer/choice polling. |
| 8C/8D,5FF2E8/5FF33C | 76 + type1field4 | 8E after20,empty5FC2C0 and1C09D0(channel,buffer);8Ereturns-1 without polling that new write here | 67 retry. |
| 96/97,5FF46C/5FF4C0 | 7A + type1field4 | 98 after20,empty5FC2C0 and1C09D0(channel,buffer);98returns-1 | 67 retry. |
| A0/A1,5FF5F0/5FF644 | 77 + type1field4 | A2 after20,empty5FC2C0 and1C09D0(channel,buffer);A2returns-1 | 67 retry. |
| AA/AB,5FF774/5FF7C4 | 8E + type1field4 | AA afterdelaystartsAB/20,cursor0and1C03F0;ABchoice+1->AC;ACreturns-1 | ABchoice-1->67 retry;its154<=0 gatecanpoll onthecallthatdecrementreaches0,unlikesomeearliergroups. |

Every choice exit clears upper UI bit requests80000/100000/200000, with some negative exits choosing5F7590 for200000 instead of5F7500 and therefore avoiding the special transition side effect. Terminal states66/70/7C/8E/98/A2/AC preserve distinct original paths even where they all return-1. Not all nonzero provider statuses are handled; unrecognized and pending values remain in the polling phase. Timer counts are invocation based. No label is a proven original symbol or a reproduced slowdown diagnosis.

Audit: 1126 verified instruction words, zero conflicting words, 147 omitted zero words (NOP padding), and zero omitted nonzero words in the original catalogue interval.
