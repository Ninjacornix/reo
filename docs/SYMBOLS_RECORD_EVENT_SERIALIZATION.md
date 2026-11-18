# Record update and explicit event serialization adapters

Static File #1 US research, 2026-11-04. All named original bodies reviewed,
including local updates when session sending is disabled and ownership-gated
returns. No game, build, replay, attachment or live-memory inspection. Addresses,
offsets, type bytes and lengths are hexadecimal; explicit counts decimal.

Connected [response/record helpers](SYMBOLS_ACTOR_RESPONSE_RECORD_EVENTS.md)
use scratch packet74F210. Main1B0310 is a boolean predicate on session byte3243FB
in1/2. A send through1AFDD0 does not establish delivery, reliability, recipient
identity or a real observed network action. Event names remain numeric.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5A7150](../recomp/config/output_ovl/o2/o2_005A7150_0x5a7150.cpp) | `write_record_xyz_and_optionally_send_type35_event_candidate` | Probable role; full body reviewed | a0 recordR,a1 floatXYZ. Main1B0310==1: R2B==1 returns with no local changes; otherwise scratch74F210 bytes0/1/3={35,C,R0},640050(XYZ,scratch4,0,outByte),1AFDD0(8,scratch,0,4). Main predicatefalse skips send but still convertsXYZ viaoriginalcvt.w.s toR10/14/18 and clearsR39. No entity refresh here. |
| [o2 0x5A7230](../recomp/config/output_ovl/o2/o2_005A7230_0x5a7230.cpp) | `write_record40_and_optionally_send_type39_event_candidate` | Probable role; full body reviewed | a0 recordR,a1 value. Main1B0310==1 withR2B==1 skips bothsend andlocalwrite; otherwise scratch74F210 type39,length6,ownerR0,byte4=value then1AFDD0(8,scratch,0,4). Outsidethisownership rejection writes lowbytea1 toR40 even when mainpredicatefalse. |
| [o2 0x5A72C0](../recomp/config/output_ovl/o2/o2_005A72C0_0x5a72c0.cpp) | `write_record39_and_optionally_send_type34_event_candidate` | Probable role; full body reviewed | Independently reviewed counterpart to5A7230: same main/session-owner gate, type34,length6,ownerR0,byte5=value,channel8 send. Localwrite R39=lowa1; mainfalse stillwrites. Does not clear any other recordfield. |
| [o2 0x5A7350](../recomp/config/output_ovl/o2/o2_005A7350_0x5a7350.cpp) | `send_type3a_record_state_auxiliary_position_event_candidate` | Probable role; full body reviewed | a0 R,a1 state,a2 auxiliarybyte,a3 auxiliaryhalf. Requiresmain1B0310nonzero andR2B!=1; all localwrites also gated. ReconstructsXYZ via5FE150(signedstate,signedR22),negative signedbyte result fallsbackintegerRXYZ. Scratchtype3A,length10,ownerR0,state4,aux5,half6;640050(XYZ,scratch8,0,out).1AFDD0 channel8. WritesroundedXYZ,R22/24,R3E,R39=0;R1!=FF refreshes entity42EB00+D90*R1 via5A8DB0. Distinctfrom type33 helper5A6FC0. |
| [o2 0x5A74F0](../recomp/config/output_ovl/o2/o2_005A74F0_0x5a74f0.cpp) | `send_type49_record_event_with_ff_payload_candidate` | Probable role; full body reviewed | Requiresmain1B0310 andR2B!=1; scratch74F210 type49,length6,ownerR0,byte4=FF,1AFDD0(8,scratch,0,4). No localrecordwrite or positionencoding. |
| [o2 0x5A7580](../recomp/config/output_ovl/o2/o2_005A7580_0x5a7580.cpp) | `write_record2a_and_optionally_send_type32_event_candidate` | Probable role; full body reviewed | Main1B0310==1 andR2B==1 skips bothsend/localwrite. Otherwise ifmaintrue scratchtype32,length6,ownerR0,byte5=lowa1,channel8 send. LocallyR2A=lowa1 even whenmainfalse. Independently reviewed different destinationfrom5A72C0. |
| [o2 0x5A7610](../recomp/config/output_ovl/o2/o2_005A7610_0x5a7610.cpp) | `write_record_xyz_and2a_with_optional_type4c_event_candidate` | Probable role; full body reviewed | a0 R,a1 XYZ,a2 bytevalue. Maintrue+R2B1 rejectsboth. Maintrueotherwise scratchtype4C,lengthC,ownerR0,encodedXYZat4 via640050,byteB=value;channel8send. Admittedlocalpath roundsXYZtoR10/14/18 andR2A=value; unlike5A7150 does notclearR39. |
| [o2 0x5A7700](../recomp/config/output_ovl/o2/o2_005A7700_0x5a7700.cpp) | `write_record_pose_fields_and_conditionally_dirty_type4d_event_candidate` | Probable role; full body reviewed | a0 R,a1 XYZ,a2 halfvalue,a3 bytevalue,t0 extra. Maintrue+R2B1 rejectsboth; maintrueotherwise type4D,length10,ownerR0,encodedXYZ4,halfC=a2,byteE=a3,byteB=t0,sendchannel8. Localpath writesroundedXYZ,R1C=halfa2,R45=bytea3,R40=bytet0. OnlyR2==1 ANDR46==1 clearsR39. Mainfalse stillupdateslocalrecord. |
| [o2 0x5A7840](../recomp/config/output_ovl/o2/o2_005A7840_0x5a7840.cpp) | `write_record_pose_fields_with_optional_type4e_event_candidate` | Probable role; full body reviewed | Independently reviewed same argument/storelayoutas5A7700, but packettype4E and NO conditionalR39clear. Mainfalse localupdates remain; maintrue+R2B1 rejectsboth. Distinct entry retained despite sharedstructure. |
| [o2 0x5A7960](../recomp/config/output_ovl/o2/o2_005A7960_0x5a7960.cpp) | `write_record_xyz2a40_with_optional_type4f_event_candidate` | Probable role; full body reviewed | a0 R,a1 XYZ,a2 byte2A,a3 byte40. Maintrue+R2B1 rejectsboth. Maintrueotherwise scratchtype4F,lengthE,ownerR0,encodedXYZ4,byteB=a2,byteC=a3,channel8send. Localpath roundedXYZ,R2A/R40 assignments. Mainfalse stilllocalupdates; no R39clear. |
| [o2 0x5A7A70](../recomp/config/output_ovl/o2/o2_005A7A70_0x5a7a70.cpp) | `send_explicit_xyz_type33_record_event_and_refresh_entity_candidate` | Probable role; full body reviewed | a0 R,a1 state,a2 XYZ,a3 auxiliary. Requiresmain1B0310nonzero andR2B!=1;mainfalse returnswithoutlocalupdates. Scratchtype33,lengthE,ownerR0,state4,aux5,640050(XYZ,scratch6,0,out),channel8send. WritesroundedXYZ,R22/R24 andR39=0;R1!=FF updatesassociatedentitythrough5A8DB0. Unlike5A6FC0 explicitXYZ means no5FE150 reconstruction. |
| [o2 0x5A7BC0](../recomp/config/output_ovl/o2/o2_005A7BC0_0x5a7bc0.cpp) | `lookup_halfword_from_one_of_two_matching_type_banks_candidate` | Probable role; full body reviewed | a0 signedlowbyte requestedtype,a1 signedlow16 index. Scans exactlytwo unsignedtypehalfwords4BA820/22;firstmatchselects bank4BA620+100*bank+2*index andreturnsunsignedhalf. No matchFFFF. Bankselectorusesloopindex,notrequestedtype; no indexboundornegativecheck. |
| [o2 0x5A7C40](../recomp/config/output_ovl/o2/o2_005A7C40_0x5a7c40.cpp) | `initialize_two_twenty_byte_slots_from_one_of_four_byte_pairs_candidate` | Probable role; full body reviewed | a0 eight-byte table,a1 destination. RNG low2 chooses pair offset0/2/4/6. Twoslots stride14: slot+10active=1,+11=selectedbyte,+12=lowbytequotient(2/global74F200); selectedFFclearsactive. Doesnotclearotherfields. Divisorzeroisnotlocallyguarded; caller/globalinitializationnotestablished,notareproducedfailure. Original MIPS division retained, no host division rewrite. |

XYZ record updates retain original `cvt.w.s` rounding, rather than silently
substituting truncation. Helpers have materially different dirty-state and main
predicate behavior; similar packet layouts do not justify aliasing their names
or replacing them with one presumed original function. No performance fix is
implemented or recommended from this static evidence alone.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
