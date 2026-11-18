# File #1 o3 optional profile data confirmation and provider workflow

Static full-body review of owned `netwk.bin`, runtime ID 4/base 570000, SHA-256 `5d23ef8bf97c107421f4bcf8589cf8941f3305ae5f6715573ed68837b9511dfb`. Original catalogue interval 603AE0..605610 read in four consecutive chunks. Owned tables 62C960[56], 62C940[6], 62C920[6] read directly. No target execution, files/card writes or endpoints. Hexadecimal phases/addresses/masks; timer counts decimal. Source role is proposed, not an original name or rewritten implementation.

Companions: [request caller and optional confirmation admission](SYMBOLS_O3_IDENTIFIER_REQUEST_RESULTS.md), [root menu/container and fade helpers](SYMBOLS_O3_ROOT_PROFILE_MENU_CONTAINER.md), [resident card/profile chain](SYMBOLS_CARD_PROFILE_REQUESTS_AND_MANIFESTS.md), [shared provider workflow and hold counter](SYMBOLS_O3_TOPLEVEL_ROUTES_RECOVERY.md), [storage modal results](SYMBOLS_O3_STORAGE_MODAL_RESULTS.md).

| Identity / source | Proposed role | Confidence | Evidence and contract |
| --- | --- | --- | --- |
| [o3 0x603AE0](../recomp/config/output_ovl/o3/o3_00603AE0_0x603ae0.cpp) | `coordinate_optional_profile_data_confirmation_storage_and_provider_result` | Confirmed static control/data mechanics; external provider and displayed content policy partial | Unsigned phase 6DF2A9 is checked <38 before owned table62C960 dispatch; subphase2AA and external substate2AB are separate from nested menu152/153. Return defaults0, phase8 returns1, phases2C/36 return-1. Copies8000 bytes between35F080 and367080 on preparation/provider success; descriptor36F080 stores identifier10 bytes, version4 bytes and result word+14. Calls709B40/7099D0 with substate, signed status156, buffer, descriptor/result1D4 and size8000; negative calls7099C0, saves error1D0 and routes22. Calls7507D0 with2AB/156/154;negative calls7507B0 and same error route, positive updates descriptor data and proceeds. Those external addresses have no established overlay binding in this note. Complete phase mechanics below, with provider-pending0 preserving the current phase indefinitely. |

Shared locals: timer/status halfwords 6DF154/156, selection15A, mode165, notice subtype1CE, success-mode byte1CF, error1D0, provider value1D4; saved channel/index6DF100. Counters are calls, not measured wall time. Some waits require decrement to exactly0, so they are not interchangeable with <=0 gates; no malformed-state/runtime reachability claim follows from that distinction.

| Phase / destination | Static behavior and transitions |
| --- | --- |
| 00 /603B28 | Subphase0 clears mode165/notice1CE/error1D0, calls5F6D70(0),5F6D80,5F6D90(0),5F6CC0, copies35F080->367080[8000]; subphase1 polls6017E0, subphase2 polls601840, then advances01, resets2AA,5F75B0/5F75E0 and timer10. Other subphases wait. |
| 01 /603C1C | Predecrement154<=0 ->02; clears2AA/2AB and nested152/153/timer154. |
| 02 /603C74 | Polls600200 container: +1 ->0A/timer10, success-mode1CF=1, mode161=1, saves6DF140 to6DF100, fade5F6CD0(0,20,1); -1 ->28/timer10;0 or other values wait. |
| 03 /603D08 | Six-subphase fade sequence:0 wait5F6C90==0 then161=1/5F74E0;1 wait6016F0(2),timer30;2 decrement154 until exactly0;3 wait6017A0(2);4 wait6017E0;5 wait601840,reset2AA,advance04/timer10,5F75B0/5F75E0,fade5F6CD0(0,20,0). |
| 04 /603E6C | Prompt55/type2field9; afterdelay10 ->05, clears2AB/status156/error1D0, copies35F080->367080[8000], value1D4=36F094, mode165=1. |
| 05 /603F00 | Prompt55+field9 if1CF=0, otherwise5F.709B40(&2AB,&156,367080,value1D4,8000):0wait;positive clears selected resident objects via1F71F0(0/4) and conditionally8/9/A using1A9750(7/8/9,1), advances06/timer90,mode165=3, clears2AA/2AB/status156;negative ->22,timer0/status32/mode165=2 and error7099C0(). |
| 06 /604068 | Same prompt selection; decrement154 until<=0 or accept5F6B70 once remaining<60 ->07 andfade5F6CD0(0,20,1). |
| 07 /604130 | Wait5F6C90==0,advance08 and5F74E0. |
| 08 /60415C | Returns1. |
| 09 /604164 | Three-subphase transition:0wait6016F0(1),timer30;1decrement154 until exactly0;2wait6017A0(1),phase0B/reset2AA,5F75E0,cursor5F7710(B,2). |
| 0A /604228 | Six-subphase fade sequence like03 but6016F0(1) does not reload154; next subphase decrements existing154 until exactly0. Completion ->0B/timer15,selection15A0,5F75B0/5F75E0,cursor(B,2),fade5F6CD0(0,20,0). |
| 0B /604394 | Prompt56 plus fields4/A/B; delay ->0C,selection0,timer3600. |
| 0C /604400 | Same prompt; predecrement154<=0 ->32/timer10 and clearsUI. Otherwise up/down selects15A0/1 with5F6A70 feedback. Accept:selection0 ->0D/timer10, selection1 ->32/timer10. Cancel ->32/timer10. |
| 0D /604594 | Prompt56+fieldsA/B,delay ->0E/timer10. |
| 0E /6045F0 | Prompt57,delay ->0F/reset2AB; storageinit5F6DA0 then1C0370(0). |
| 0F /604648 | Prompt57, constant5FDDF0 ->10; saves6DF100 lowbyte to channel1C9, starts1C0710(signed channel,workspace31F000,0). |
| 10 /6046AC | Prompt57;1C03A0/1C1260:0 or-251 ->11/timer10/5F74F0; -255 ->1E/timer10/notice1CE5; -252/-253/-256/-254 ->20/timer10/notice1CE6; other statuses wait. |
| 11 /60478C | Delay ->12/timer10/5F75E0. |
| 12 /6047D0 | Delay ->13; clears2AB/status156/selection15A/error1D0/timer154;mode1651;5F7810/5F77F0. |
| 13 /604844 | Hold helper6032B0(&15A) can set156=30; poll7507D0(&2AB,&156,&154).0wait;negative ->22/status32/mode1652 and error7507B0();positive ->14,clears2AA/2AB/156, copies367080->35F080[8000],value1D4=6DDFFC. |
| 14 /60492C | Subphase0 increments1 and falls through polling6016F0(2); completion sets15630/nextsubphase.2decrements156 until exactly0;3polls6017A0(2),reset2AA,advance15. |
| 15 /604A08 | Poll7099D0(&2AB,&156,35F080,value1D4,8000).0wait;positive ->16,154=result,156114,mode1653, clears2AA/2AB and writes result36F094;negative ->22/error7099C0() path. |
| 16 /604ACC | Predecrement156<=0,or accept whenremaining<=60 ->17/timer15410; clears masks4000/8000/2000000/2000/400. |
| 17 /604BA4 | Delay ->18, clears nested152/153,5F75E0; copies6DE000[10] and6DE010[4] into36F080/36F08A. |
| 18 /604C14 | Poll5FF8E0 storage-modal:1 ->05,copy35F080->367080[8000],1D4=36F094,clears2AB/156/error,mode1651; -1 ->19/timer10;others wait. |
| 19 /604CA8 | Delay ->09/timer10,clear2AA/selection15A. |
| 1A..1D /6055F8 | Explicit no-op/default-return0 table entries. |
| 1E /604CF4 | Delay ->1F/timer150/notice subtype5. |
| 1F /604D40 | Prompt(subtype1CE signed +55)&FF; decrementtimer<=0 or accept whenremaining<=90 ->28/timer10. |
| 20 /604DCC | Delay ->1F/timer150/subtype6. |
| 21 /604E14 | Delay ->1F/timer150/subtype7; admitted entry, no local ordinary status transition selects21. |
| 22 /604E5C | Delay ->23/timer45/mode1653,clearsUI2000. |
| 23 /604EB4 | Delay ->24/timer10, clears4000/8000/2000000/400. |
| 24 /604F14 | Delay ->25/timer5,5F75E0/5F7890. |
| 25 /604F60 | Delay ->26,timer154315,threshold156210. |
| 26 /604FAC | Decrement154<=0 or accept when154<=156 ->32/timer10, clears4000000. |
| 27 /6055F8 | Explicit no-op/default-return0. |
| 28 /60504C | Delay ->29/timer10/selection0/cursor(B,1). |
| 29 /6050A0 | Prompt59+field4;delay ->2A/timer3600. |
| 2A /6050F4 | Prompt59+field4;timerexpiry ->2B/timer10 andfade(0,20,1). Otherwise selects0/1;accept selection0 ->2B/fade; selection1 orcancel ->2D/timer10. UI clears uppertriplet. |
| 2B /6052A8 | Wait5F6C90==0 ->2C;5F74E0/1F7160. |
| 2C /6052DC | Returns-1. |
| 2D /6052E4 | Delay ->02/timer15,clear nested152. |
| 2E..31 /6055F8 | Explicit no-op/default-return0. |
| 32 /605328 | Delay ->33/timer15/selection0/cursor(B,2). |
| 33 /60537C | Prompt58+field4;delay ->34/timer3600. |
| 34 /6053D0 | Prompt58+field4;expiry ->35/timer10,clearUI. Otherwise selects0/1;accept selection0 clearsUI400 and ->35,selection1/cancel ->37/timer10. |
| 35 /605564 | Delay ->36;5F74E0/1F7160. |
| 36 /6055A8 | Returns-1. |
| 37 /6055B0 | Delay ->09/timer10,clears2AA/selection15A. |

The outer phase is bounds checked; subphase tables03/0A separately check<6. 00/09/14 use explicit admitted-value branches. Timer3600 is only the local choice timeout, not a bound on external709*/750* provider waits. Copy lengths and parameter contracts do not prove safe admission/complete resource lifetime without the providers. The caller608DE0 may reissue its resident request on this controller's return1; that is separate from external binding or any observed network activity.

Raw owned dispatch tables (hex phase -> absolute block) are retained below to distinguish empty admitted phases from omitted analysis:

```
62C960: 00:603B28, 01:603C1C, 02:603C74, 03:603D08, 04:603E6C, 05:603F00, 06:604068, 07:604130, 08:60415C, 09:604164, 0A:604228, 0B:604394, 0C:604400, 0D:604594, 0E:6045F0, 0F:604648, 10:6046AC, 11:60478C, 12:6047D0, 13:604844, 14:60492C, 15:604A08, 16:604ACC, 17:604BA4, 18:604C14, 19:604CA8, 1A:6055F8, 1B:6055F8, 1C:6055F8, 1D:6055F8, 1E:604CF4, 1F:604D40, 20:604DCC, 21:604E14, 22:604E5C, 23:604EB4, 24:604F14, 25:604F60, 26:604FAC, 27:6055F8, 28:60504C, 29:6050A0, 2A:6050F4, 2B:6052A8, 2C:6052DC, 2D:6052E4, 2E:6055F8, 2F:6055F8, 30:6055F8, 31:6055F8, 32:605328, 33:60537C, 34:6053D0, 35:605564, 36:6055A8, 37:6055B0
62C940: 00:603D34, 01:603D6C, 02:603D9C, 03:603DCC, 04:603DF0, 05:603E14
62C920: 00:604254, 01:60428C, 02:6042B0, 03:6042E0, 04:604304, 05:604328
```

Audit: 1619 verified instruction words, zero conflicts, 121 omitted zero words (NOP padding), zero omitted nonzero words.
