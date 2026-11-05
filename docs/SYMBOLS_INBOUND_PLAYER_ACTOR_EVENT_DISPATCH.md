# Inbound player-channel actor events

Static File #1 US, 2026-11-05. One complete original o2 body reviewed across 67ED50..67FF77, including all sixteen cases, shared cleanup, interaction bit dispatch and delay slots. No execution, build, attachment, live memory, input or network traffic. Addresses, fields, opcodes and masks below are hexadecimal. Original event names, channel admission and transport authentication remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x67ED50](../recomp/config/output_ovl/o2/o2_0067ED50_0x67ed50.cpp) | `dispatch_inbound_player_channel_state_and_interaction_events_candidate` | High mechanics; candidate role | a0 channel,a1 packet,a2 include-own-channel flag. Requires1B0310 nonzero; zeroa2 rejects channel-1==localplayer. Base actorA=4A5C30+10E0*(channel-1), resets A.D92 before checking localplayerBA0 bit4. Opcodes0..F select owned740750 table; most cases share pose-history/root-offset/item-binding cleanup. Cases1/5 may redirect state actor through666640 while cleanup still uses baseA. No channel bounds or packet length verification. |

Let `P` be the original packet, `U=P+4` its payload, `A` the channel-selected base player actor, and `T` the possibly redirected state actor (initially A). The function does not validate channel1..4, sender, payload size or pointer lifetime locally. Main1B0310 must be nonzero. With a2==0 it suppresses own channel before selecting A; with a2!=0 it admits own channel. It then clears A.D92 even if local player BA0 bit4 subsequently causes an early return. Thus rejection is not uniformly side-effect-free.

The complete owned dispatch740750..74078F has sixteen pointers, SHA256`67c4ab66df54a82dfb2a305030647b250241f6e5a07a0ca4a764ea371cd79f49`:

```text
0 67EE38   1 67EE40   2 67F158   3 67F2FC
4 67F328   5 67F34C   6 67F548   7 67F56C
8 67FC24   9 67FCD0   A 67FD24   B 67FD4C
C 67FDA8   D 67FDC0   E 67FDD4   F 67FDE8
```

| Opcode | Concrete payload effects before shared cleanup |
| --- | --- |
| 0 | Returns immediately through67EE38; skips shared cleanup. A.D92 was already cleared. |
| 1 | Full state, matching the outbound67EB60 type1 family. If U14 flags bit10000000 is set, clears that bit IN THE INPUT PACKET and resolves T=666640(U22); null resolution skips payload work and enters baseA cleanup. Otherwise T=A. For T class0 and A.room1E2!=U20, calls1B0010(A3), stores A.room=U20, calls1AFF90(A3), and586E70(A) if new room is current. Stores T.BA0=U14; nonzero U26 ORs T.BA4 bit20000000 (zero does not clear it). Position/state paths are detailed below. |
| 2 | T=A. BA0=wordUC; BAC=668D00(A,U12). Nonzero signedhealth with BA0bit100 can set activebyte1 for same room, clear54F/548bit1, set8/9/A/B=1/0/1/0, snapshot667370, choose2050 and activate bank58C7B0. Position path uses rawfloatU0/4/8, yaw signedhalfU10; same-room BA0bit08000000 instead calls663980/6647B0 with D90=F, clearsflag and storesD8C. Other path stores XYZ/D74..7C, yaw/D8C, rebuilds forward, then6686C0(A,0). |
| 3 | Copies exactly seven words U0..18 to A.AB8..AD0, clears A.D32. The loop starts count7, copies once before decrement/test and therefore copies seven, not eight. |
| 4 | U0..3 bytes ->A.C78..C7B. |
| 5 | Packed full state. U10 bit10000000 causes input-word bit clear and T=666640(UF); null ->base cleanup. Copies U0..3 toT8..B, UE roombyte->half1E2; signedhalfU4/6/8 ->floatXYZ AND D74/78/7C; UA yaw->92/D8C; D90=0 and forward rebuild. UC health, U10 BA0; U14..1C ->148/149/14A/14B/140/13E/14C/141/143; copies new state9 to13D; BAC=668D00(T,U1D). RawfloatU20/24/28 ->12C/130/134, wordU2C ->11C; memsetB1C..B33 zero. Off-room T calls667370. |
| 6 | RawfloatU0/4/8 ->A.C34/C38/C3C; signedhalfUC ->A.C4C (overlaps the C44/C48/C4C vector family's Z word in other contexts; no cross-state field meaning assumed). |
| 7 | UnsignedhalfU0 ->A.D92, U2..5 ->DA2..DA5, U6 ->C7F. Zero D92 skips bit work. Nonzero invokes the ordered bit handlers below and clears D92 at end. |
| 8 | Four signedhalvesU0/2/4/6 ->A.C64/C66/C68/C6A. PackedU2 bit8000 chooses target666640(low15), otherwise fixedplayerpool+10E0*low15. Null target returns immediately, skipping shared cleanup. Valid target receives the same four halves, then its C66 is overwritten with baseA byte3. No player-index bound on low15 path. |
| 9 | U0 ->A.CB0; signedbytesU1/U2 ->runtime3C4598/3C4599+3C*CB0. |
| A | U0/U1 ->A.CAA/CAB; copies exactly four bytes U2..5 toC84..87 via18DBB0. |
| B | Calls6DFEE0, stores signedbyteUA toA.DA9. If UA==0 and actor is off-room skips remaining payload. Otherwise wordU0->DB4,halfU4->DC2,halfU6 lowbyte->DC7,wordUC lowbyte->DC1,signedbyteU8->DC0,signedbyteU9->wordDB8. |
| C | Copies exactly four bytes U0..3 toA.C84..87. |
| D | Calls6811E0(originalchannel,P), then returns without shared cleanup. Callee ownership-release semantics belong to its separate notebook. |
| E | wordU0->A.BA0,signedhalfU4->health544. |
| F | Copies exactly four bytes U0..3 toA.C89..8C. |
| >=10 | No payload operation, but still shared baseA cleanup after initial D92 clear and localflag admission. |

Full-state case1 first updates flags, optional room and health/status for T, while the common tail remains tied to A. Same-room T.BA0bit08000000 is cleared, D90=F,663980(T) supplies the third argument to6647B0(T,U+4,result), and received signed yawU10 is stored toD8C. Otherwise681D70(T,U) bit1 can suppress position application. Without that bit it clearsD90, copies rawfloatU4/8/C to bothT.D74/78/7C and T.XYZ, stores signedyawU10 to92/D8C, sets forwardA8/AC/B0=(0,0,1), then rotates it by unsignedyaw*owned2pi/65536. Ownedfloat740808=6.2831854820251465, rawdb0fc940, SHA256`12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`.

After either position path, case1 copies healthU12->544; bytesU18/19/1A/1B ->C7C/C7F/C80/CB0; halvesU1C/1E->BC8/CD4; byteU21->CDC;668D00(T,U23)->BAC;U24/25->CAA/CAB. It calls5F1F70 to refresh/clear CA8 according to currentC7C and existingCA8. NonzeroT.B9E then bypasses remaining state application. Otherwise681D70(T,U) bit2 suppresses copying U0..3 to8..B. A nonzero1AFE70 with state8/9/A==1/24/0 calls5B1610(C7F,FF). Off-roomT snapshots667370; all admitted remainder calls6686C0(T,1). Both case1 and2 preserve position-versus-state suppression as separate bits, not one all-or-nothing packet admission.

Case7 executes masks in this exact order, reloading D92 after handlers. Bits can coexist; this is not a single opcode switch. Numeric helper contracts retain the [interaction command/replay distinctions](SYMBOLS_CUTSCENE_RESOURCES.md) and mapped resource helper evidence, without guessing original inventory/action names.

| D92 mask | Handler and additional effects |
| --- | --- |
| 40 | If C7C!=C7F, marks runtime item records3C5648+3C*old/newID bit1,5B1A90(old),C7C=new, writes owner3C5658+3C*newID=(class0?actor3+1:BB4+5),5B18D0(new),CA8=5F1F70(A). If equal, marks current recordbit1,5B1A90(C7C),thenC7C=0,CA8=0. |
| 1 | 5F5670(A,1,DA3,DA2). NonzeroDA3 additionally addresses4A57C8/9/A+10E0*DA3, writes bytes2/0/C7A. These are literal addresses and index origin, not a newly inferred player-field layout. |
| 2 | 5F54A0(A,1,DA2,DA3). |
| 4 | 5F5870(A,1,DA4,DA2,DA3); nonzeroDA4 writes4A57C8/9+10E0*DA4 bytes2/1. |
| 10 | Marks C7F item recordbit1; result=signedbyte5B2080(C7F,playerpool+10E0*DA2). Result2 ->5F2120(A,C7F),5F2330(A),clearsC7F BEFORE comparing it to C7C, conditionally clearsC7C, refreshesCA8. Result3 only refreshesCA8. Other results leave those cleanup fields. |
| 20 | Same record mark; result=signedbyte5B1F30(C7F,playerpool+10E0*DA2). Result2 ->5F2120/5F2330, compares C7F toC7C BEFORE clearingC7F, conditionally clearsC7C, refreshesCA8,thenC7F=0. Result3 only refreshesCA8. Order differs from mask10. |
| 80 | Signedhalf5B3DD0(DA2,DA3) results16/17 skip local current-item clearing; otherresults call5B1A90 andclearC7C/CA8 if currentID equalsDA2orDA3. Then signedbyte5B28F0(DA2,DA3):result2 calls5F2120(A,DA2),result3 calls5F2120(A,DA3); all results call5F2330(A). |
| 100 | NonzeroDA4 writes4A57C8/9/A+10E0*DA4 bytes2/0/C7A;then5F5170(A,1,DA4,DA2,DA3). |
| 200 | 5F5D20(A,1). |
| 400 | 5F62D0(A,1). |
| 800 | 5F5C50(A,1,DA2). |
| 1000 | 5F4FE0(A,1,DA2,DA3,DA4). |
| 2000 | 5F6800(A,1). |
| 4000 | 5F6970(A,1,signedbyteDA3,unsignedbyteDA2). |
| 8000 | 5F6A80(A,1,DA2). |

Mask8 has no local handler. Original scalar1 passed to the5F command family is preserved; no new live input is injected by this static investigation. On completion case7 writesD92=0 before shared cleanup. The mask10-versus20 comparison/clear order difference is a literal observation; caller admission, expected resource IDs and runtime consequences are untested.

The shared tail at67FDF8 always operates on baseA, even when case1/5 used redirectedT. It copies currentXYZ38..40 to previousXYZ44..4C, copies four anglehalves90..96 toA0..A6, and zeros three root-offsetwords4E4/4E8/4EC. IfC7C==0 it returns. Otherwise item work at3C5648+3C*C7C is checked for nonzero word+4 and ownerhalf+10 matching(class0?A3+1:BB4+5). A matching binding calls5F1F70(A)->CA8. Missing/mismatched binding writes owner, marks itemword0bit1, calls5B18D0(C7C),thenrefreshesCA8. Thus even unrecognized opcodes>=10 can refresh pose history and item binding; no packet length/type error status is produced here.

[Outbound actor records](SYMBOLS_CHANNEL5_CONTROL_AND_ACTOR_EVENT_SENDERS.md) document raw type1/7 construction, and [stat classification](SYMBOLS_DISPATCH.md), [animation](SYMBOLS_ANIMATION.md), and [resource operation routing](SYMBOLS_RESOURCE_EFFECTS_AUX_LISTS.md) retain their independent contracts. No original protocol names, player reproduction, desynchronization, slowdown cost, confirmed rootcause or code fix is claimed. Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Runtime arrays and packet contents were not read. Full owned-body audit: 1,076 original words verified; 86 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.
