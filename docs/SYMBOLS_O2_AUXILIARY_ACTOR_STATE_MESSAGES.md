# Auxiliary actor persistent-state message producers and inbound dispatch

Static File #1 US o2/runtime ID3/base570000, owned SHA-256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`, 2026-11-05. Three complete original catalogue intervals read, including every case and delay slot. No message send/receive, game, builds, input, live memory or target execution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x684D50](../recomp/config/output_ovl/o2/o2_00684D50_0x684d50.cpp) | `route_auxiliary_descriptor_position_and_heading_type_seven_message` | High complete local mechanics; original message names candidate | Buildstype7,size18,header2/3=0;packet8/C/10=descriptorXYZ8/C/10,half14=descriptorheading14.1AFDD0(9,packet,0,4). Payload4..7 and16..17 not initialized; in particular a required receiver ID atpacket4 is not written here. No local descriptor mutation. |
| [o2 0x684DB0](../recomp/config/output_ovl/o2/o2_00684DB0_0x684db0.cpp) | `route_auxiliary_descriptor_room_and_parameter_type_eight_message` | High complete local mechanics; original message names candidate | Storesdescriptorroom1=a1,param21=a2;type8,size1C,header2/3=0,halfpacket4=templateID4,bytes6/7=room/param,XYZC/10/14 fromdescriptor8/C/10. Calls1AFDD0(9,...),thenfirstmatchingof64descriptors ID calls6260E0(index). Packet8..B/18..1B unspecified; no size validation. |
| [o2 0x684E80](../recomp/config/output_ovl/o2/o2_00684E80_0x684e80.cpp) | `apply_auxiliary_actor_descriptor_messages_by_nine_case_numeric_kind` | High complete local mechanics; original message names candidate | Packetbyte0 kind,byte2 sender,half4 templateID. Scansall64 descriptors and retainslastIDmatch; optionalactiveactorlist firstmatch when4BADF8==0. Missingdescriptor ordescriptorstate30 in{4,7} returns. Owned740860 nine-case table updatespersistent room/state/health/position andoptional liveactor fields; kinds0/1/3/5/6/7 ignorelocalsender,2/4/8accept. No packet-length/admission proof; details below. |

[Auxiliary actor pool/descriptor schema](SYMBOLS_O2_AUXILIARY_ACTOR_POOL_AND_DESCRIPTORS.md), [entity ownership registry](SYMBOLS_O2_ROOM_ENTITY_OWNERSHIP_REGISTRY.md) and [guest message router](SYMBOLS_DISPATCH.md) provide independently reviewed ownership and delivery limits. Descriptor array390210 has64 records of78 bytes; live auxiliary actors use417090 slots1170 bytes. A descriptor match and a live actor match are separate operations.

For684E80 letP=packet+4,D=persistent descriptor,T=optional live auxiliary actor. No matchingD returns, but the last duplicate descriptor ID wins. Live lookup requires4BADF8==0 and activebyte0 nonzero, returnsfirst BB4==ID; unlike two tick loops this search advances past inactive nodes. D.word30 in4/7 suppresses **all** cases before sender filtering. No request-length check precedes payload loads.

| Packet kind | Owned branch | Descriptor and live actor updates |
| --- | --- | --- |
|0|684F78|Foreignsender: D.state30=P4,word28=P8,health16=halfPC,room1=P2,ID4=halfP0,byte20=P3. T ifpresent setsvisibility by equality of oldT.room andnewD.room,updatesroom/health/B9B/1150,setsFCF fromD.state andclearsFD0..3;leavingFCF5clearsBA0 mask1000000. D.1E=0.|
|1,5|685048|Foreignsender: D.state=P4,XYZ=P8..10,heading14=halfP18,ID/bytes24/25/word28=P0/P2/P3/P14. T getspositiondirect onroomchange; sameroom andBA0mask80000clear usesdirectposition forkind5, otherwise5BE150(T,D.XYZ,F). Updatesheading,bytes1020/101F;when1150changedsetsFCF/clearsFD0..3. D.1E=0.|
|2,8|6851B8|D.XYZ=P8..10,ID=P0,room=P2,param21=P3,1E=2. T ifpresent FCF5,1154=param,roomupdate,visible0,FD0..3=0,FB7=10,BA0clears80000. No localsender rejection.|
|3|685240|Foreignsender: D.state=P4,bytes24/25=P2/P3,ID=P0. T visibilitybyold/newroom,room/1020/101Fupdate;leavingFCF5mayclearBA01000000 andresetFCF/FD0..3.|
|4|6852F4|D.state=P4,XYZ=P8..10,ID=P0,room=P2,1E=1. T FCF5,roomupdate,visible0,1150=D.word28,FD0..3=0,FB7=10.|
|6|6853B4|Foreignsender: extendedstate/XYZ/heading/health/room/B9B/word28 record. T directpositiononroomchange,otherwise5BE150 unlessBA080000;updatesheading/D8C,health,low8P1C->113C,FCF/FD0..3 when1150changes,finallyFD2=1 andD.1E=0.|
|7|685368|Foreignsender: XYZ=P4/P8/PC,ID=P0;T uses5BE150(T,D.XYZ,F),D.1E=0.|
|other|epilogue|No mutation aftercommonlookup/admission.|

In thekind1/5 sameroom route, headingD8C and92 writes follow positional interpolation only on its corresponding branch; direct roomchange writes92. Runtime interpolation output and packet arrival timing were not sampled. Helper5BE150's original contract remains as separately mapped source; it is not automatically native network smoothing.

Owned jump table740860..740884 has9 targets[684F78,685048,6851B8,685240,6852F4,685048,6853B4,685368,6851B8], SHA-256`0fd5e8bb5ae92987e61fc931f4f021860e40f7cb00547aa4286f40dd071334da`. Kinds1/5 and2/8 share branch bodies but kind5 has explicit position handling. Numericcodes alone do not establish message enum names.

684D50 does not write the ID expected atpacket4 by kind7 receiver;684DB0 writes packetheader sender0, not local4BADED. Unwritten bytes may be supplied by an external caller/router contract, but this body does not establish that. These are reviewable producer/consumer discrepancies, not a claim of observed malformed packets or slowdown.

Audit: 471 owned instruction words matched, 29 omitted aligned zero/NOP words, zero omitted nonzero words.
