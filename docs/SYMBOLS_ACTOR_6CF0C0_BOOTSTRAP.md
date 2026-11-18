# Actor 6CF0C0 update, initialization and dispatch

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed.
Addresses and offsets are hex unless marked decimal. Actor identity and original
action names remain candidates. No target execution or engine/runtime changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CF030](../recomp/config/output_ovl/o2/o2_006CF030_0x6cf030.cpp) | `dispatch_record_relocation_queries_when_auxiliary_gate_zero_candidate` | High mechanics; probable role | a0 compact recordR,a1 workW,a2 lowbyte gate,a3 lowbyte mode. Default v0=0. Gate0/mode0 calls6CEA50(R,W) timer initialization;gate0/mode1 calls6CEB20(R,W) relocation selection;other inputs no query. Returns callee result on selected paths. These are record/work queries adjacent to the actor update, not actor-pair geometry. |
| [o2 0x6CF0C0](../recomp/config/output_ovl/o2/o2_006CF0C0_0x6cf0c0.cpp) | `update_actor_6cf0c0_alignment_contacts_state_and_root_motion_candidate` | High mechanics; probable role | D2C=170;when BE8==0 and primary nonzero restores D28 from49F78C and modeBA3==2 snaps Y=D28. SnapshotsXYZ/angles,replaces54A=10,clearsBA5/C82/32/C36. Nonnull actor24 refreshes BD4 via5A9F80 and BD8 via3AF0 heading-yaw.640210,positive timer12 decrement;13F invokes1DA0 contact,return1 additionally1C60,any nonzero5A6B20(actor,2). C94mask201 follows544<=0. Saves BA3 toC29 then731540[primary](actor). C82zero applies2180 root motion;nonzero zeros C0 triple. Mode1 ORs54Abit4;chooses owned731760/764 material1AC by modezero/nonzero.3440 pitch,6347D0,5A7D00(7315D0,CD8);nonzeroBA3 setsBA51. State1/secondary1or4/nonzero phase runs2440 for mode0/2 or26C0 for1. Mode2 clamps Y<=D28. Secondary!=7:mode1 clamps Y to[D2C+100,D28-100],then2340 commits deltas/matrix;secondary7 skips that final commit. Always5A6B20(actor,signedC36),then1B0310. Ordering permits earlier handlers to commit movement separately; callback count is not global game time. |
| [o2 0x6CF470](../recomp/config/output_ovl/o2/o2_006CF470_0x6cf470.cpp) | `initialize_actor_6cf0c0_alignment_material_and_status_candidate` | High mechanics; probable role | Builds matrix50 fromangles;byte1/5531,F0=1,C800,520=-1,shape1A8=7316E8->7316B0 and1D8=731730->7316F0,shared owned color731760->731740 into C70/1AC/1BC. ORsC94masksC4/201,19020FFFF,1940,551/5523,CE8/CFC0. Selector3243DA0 sets D28/49F78C=decimal500;29 with3243DC25 sets both-1900. Nonzero BA3 queries30F0(normalD00,pointD0C):return0 clearsBA3 even if query found zero heading delta;nonzero buildsD18 and mode1 position=hit+normal. Initial BA30 setsD00=(0,1,0). Clears fourBE8 bytes,eightC..13,C390;floor query616F20 ->D2C. Health<=0,owner3B5050[B98]!=FF or indexed status74F295+60*B98==1 enters4/savedB9E/A5/B0,clearsBA3/544/byte74F270+60*B98,normalizes secondary to2or5. Otherwise1/0/0/0 and1C60. C36=7,39E0 base-motion selection. |
| [o2 0x6CF760](../recomp/config/output_ovl/o2/o2_006CF760_0x6cf760.cpp) | `dispatch_actor_6cf0c0_primary_one_alignment_route_candidate` | High routing; probable role | Calls635E20(actor,C8C,3,f12BCC,f13BD0). Secondary3..6 additionally635640(actor,FA),return unused. Then unchecked731560[byte9](actor). Owned nine pointers below; this wrapper does not itself advance animation or record global updates. |

Owned731540 primary pointers:6CF470,6CF760,6D0500,6D0A60,6D10F0.
Owned731560 secondary pointers:6CF7E0,6CF8C0,6CFA40,6CFB70,6CFC10,6CFD40,
6CFE50,6D0070,6D0380. All destinations now have full-body reviews in this
family's scoped notebooks; internal merged dispatch targets are counted once.

Owned material floats731740=(0,0,0,decimal120),731750=(0,120,0,120).
The status tables and global49F78C are referenced by instructions only; their
live values were not read. Initialization interprets30F0's zero result as
failure although that query also returns0 for straight-ahead success. This is
an observed caller contract, not a proven gameplay defect.

Related [primary-one states](SYMBOLS_ACTOR_6CF0C0_PRIMARY_ONE.md),
[alignment transitions](SYMBOLS_ACTOR_6D_ALIGNMENT_TRANSITIONS.md),
[response motions](SYMBOLS_ACTOR_6D_RESPONSE_MOTIONS.md),
[selection](SYMBOLS_ACTOR_6D_STATE_SELECTION.md), and
[surface probes](SYMBOLS_ACTOR_6D_SURFACE_PROBES.md).
