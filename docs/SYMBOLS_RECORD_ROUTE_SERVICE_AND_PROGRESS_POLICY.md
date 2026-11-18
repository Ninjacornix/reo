# Record route service and progress policy

Static File #1 US owned o2 image,2026-11-05. Three complete original bodies,full progress tables and connected [route sequence](SYMBOLS_RECORD_ROUTE_CONTROLS.md) / [point sampling](SYMBOLS_ROUTE_GRAPH_POINT_QUERIES.md) contracts. [Identity](FUNCTION_INDEX.md). No route, event or game executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5D0EE0](../recomp/config/output_ovl/o2/o2_005D0EE0_0x5d0ee0.cpp) | `service_record_route_substates_waits_point_progress_and_pose_transitions` | Confirmed complete ordered dispatcher and all side effects | Requires6D45A0 route sequence and nonnegative signed-lowbyte6D4650(record22,sequence); builds previous/current/next triplet6D5400. Work18 states0/1/2/8/10/14hex/15hex/16hex follow table below,others return0. Only successful state1/2 transition establishes return1; other side-effect routes0. No timer converted to elapsed seconds, no local resource bounds or child-failure rollback. |
| [o2 0x5D1420](../recomp/config/output_ovl/o2/o2_005D1420_0x5d1420.cpp) | `admit_route_node_progress_from_numeric_node_and_scenario_flag_mask` | Confirmed complete flag predicate | Signed-lowbyte node2 always1;node1 requires4B9C04 bit4000,node5 bit8000,node11 bit10000,node13 bit400000;all others0. Returns normalized0/1; no mutation. |
| [o2 0x5D14F0](../recomp/config/output_ovl/o2/o2_005D14F0_0x5d14f0.cpp) | `lookup_route_point_progress_byte_and_latch_node_five_flags` | Confirmed full table lookup and exceptional flag branch | Signed-lowbyte node selects70AC20 pointer,NULL->0. Workunsignedhalf10<countbyte yields following progressbyte,else0. Special node5/cursor3 and4B9C00 bit8set with bits10/10000/20000clear sets flags4/16/17 through5703E0; still returns table byte. No local node-table bound. |

| Work18 state | Complete original behavior |
| --- | --- |
|0|record2E0->8;flags45 bit1->14/15hex by6D4750,elsebit2->16hex,elseglobal4BADF8nonzero->10decimal. Otherwise endpoint16 mustnonnegative and5D1420(current)true. Decrementhalf12;onexpiry reset30*record3C. Endpoint0 incrementscursor10,samples next jittered point5FDF10,publishes5A7150,computes5D14F0 and raises record39 via5A72C0 only iflarger. Nonzero endpoint advances to1 and setswait150decimal.|
|1|5D1720(record,work,next):signedlowbyte-1 advanceswork18;1 setsreturn1. Successful currentnode11 with neither4B9C00 bits1000/2000 set latchesflags12/13.|
|2|5D1820(record,work,next)success setsreturn1 andsame currentnode11flag latch.|
|8|Once record2Enonzero,5D12F0(record,work,1) route/XYZ relocation.|
|10decimal|Clearswork18 onceglobal4BADF8 becomeszero.|
|14hex|6D4770 true clearswork18 then6D47C0 selected placement route initializer.|
|15hex|Requires3B5050[record0]==FF,then6D4910(record,work,recordhalf1E,0,triplet,cursor),clearswork18.|
|16hex|6D4910(record,work,recordhalf1C,record45&FD,triplet,cursor),clearswork18.|

Progress pointers70AC20[64] SHA-256 `4b4f0436463092898c715d7aa4fc627416cb0d28bf130d521038377501354fdb`. NonNULLnodes1->70ABE0 `{7,0,0,1,1,1,2,3}`,2->70ABE8 `{4,0,0,0,0}`,5->70ABF0 `{9,0,1,2,3,4,5,6,6,7}`,11->70AC00 `{8,0,1,2,2,3,3,3,4}`,13->70AC10 `{5,0,0,1,1,1}`;allother reviewed16slotsNULL. Each row's firstbyte is count, not progress. Row hashes respectively`a0df933bde4b36d42ac1afdefa37d331968a5c7f3b188005572391df4b100b57`,`88420266dfd64d604627234a8a6c75cf6477c6fd5505df0d17c59959ae9ce234`,`769fc833ab37aac047673cdd26078c44a1bc451913b8f5a6b436d7a62e138163`,`9922d960d4986508ddaafe34b1639bd77d9148967253d203595d64ee79dd401b`,`3f264e1e87819a1b545113927e81a18d9da1a624abb667cf9e12365bb3bb7dce`. Three bodies /329 verified words. Timers are calls admitted by these branches, not a measurement of game-speed progression.
