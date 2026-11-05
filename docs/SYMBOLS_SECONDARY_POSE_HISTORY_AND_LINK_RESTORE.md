# Secondary-pose history reset and original node-link selector

Static File #1 US,2026-11-04. Two complete o2 bodies; high-confidence mechanics, secondary-motion semantics candidate. No execution/build/attachment/live memory/input/timing. Addresses/field offsets/IDs hexadecimal; explicit dimensions decimal. [Existing solver and node-link patcher](SYMBOLS_SECONDARY_POSE.md), [action-entry caller66B8E0](SYMBOLS_SCRIPT_VM.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x61A620](../recomp/config/output_ovl/o2/o2_0061A620_0x61a620.cpp) | `clear_actor_secondary_pose_four_by_two_history_vectors` | Confirmed static mechanics | a0 actor; exactly four outer iterations/2 inner iterations, stores zero XYZ at actor+E58+72*chain+36*segment. Clears eight 3-float history vectors, not contiguous288B. No model traversal, descriptor lookup, allocation, or runtime enable switch. |
| [o2 0x61A6A0](../recomp/config/output_ovl/o2/o2_0061A6A0_0x61a6a0.cpp) | `select_and_restore_actor_secondary_pose_original_node_links_candidate` | High mechanics; candidate role | Requires nonzero signed active bytes0/1,54A bit40 clear; category2 dispatches byte-selector tables below and rejects FF. Calls61B1A0(model+820,70F650[selected]) to patch parent/child/sibling links. Does not run61AAA0 solver or rebuild matrices. Local actor/table/node bounds are not checked. |

Reset writes E58/E5C/E60 plus E7C/E80/E84 in chain0, repeated with stride48(hex) for four chains; highest storeF5C (throughF5F). It leaves each vector's remaining24(decimal) bytes untouched. The mapped61AAA0 solver reads these same E58+72*chain+36*segment history vectors; action-entry66B8E0 calls this reset before its substate controller. That shared address contract supports history naming without claiming which original garment/body system the vectors represent.

61A6A0 byte-selection contract (all offsets/table indices hex):

| Category byte2 | Admission | Selector byte address |
| --- | --- | --- |
|0,BB4 nonzero|none beyond common active gate|70F2AF+unsignedBB4 (equivalent70F2B0+[BB4-1])|
|0,BB4 zero,54D=1|none further|70F2A0+B98|
|0,BB4 zero,54D other|BBC must zero|70F298+B98|
|1,54D=1|none further|70F390+unsignedBB4|
|1,54D other|none further|70F2B0+unsignedBB4|
|other|return|none|

ByteFF returns. Otherwise selector byte indexes pointer70F650+4*byte, then mapped61B1A0 processes three-byte records until leading nodeFF, with targetFF meaning null. Its kind0 writes node+C8 parent;kind1 node+D0 child;kind2 node+CC sibling. The four initial owned pointer entries below point to unlink/reconnect sequences; the later61A820 uses distinct pointer bank70F680 for its secondary-pose solved chain. That paired ordering supports original-link restoration as a role candidate, not proof of actual current node topology.

Owned selector windows are serialized below in full sparse form: any unlisted byte is FF. The224B physical windows extend to the next known table; their trailing zeros may be padding, and are not proof those BB4 indices are legal assets. No caller asset enumeration or runtime bounds admission was measured. Adjacent pointer bank70F650 has four verified entries; at70F660 bytes begin node records, not additional guest pointers.

| Owned window | Non-FF bytes (offset:value) | SHA256 |
| --- | --- | --- |
|70F298..70F29F|7:0|`237c43c775527e314eac5d1e874a8b74cffe9789f112e343d8a8643730435851`|
|70F2A0..70F2A7|7:1|`5de7788a5858063a1fc5e019b467310f33b42fa10a14590b8f70082573835b2f`|
|70F2B0..70F38F|CF:0, D2:0, D3:0, D4:0, D5:0, D6:0, D7:0, D8:0, D9:0, DA:0, DB:0, DC:0, DD:0, DE:0, DF:0|`e9fc5fa7f70aca16a70bbebacdd298c015cea98073721b60898f2a5890a3e9b0`|
|70F390..70F46F|36:3, 58:3, C7:2, CF:1, D2:0, D3:0, D4:0, D5:0, D6:0, D7:0, D8:0, D9:0, DA:0, DB:0, DC:0, DD:0, DE:0, DF:0|`6b74a07c8b293f87bac10b3ddddaf30f82cdecbdc77eced9509124b1a076c07d`|

Four pointer bytes70F650..70F65F, SHA256 `632dd47c5848d1fdd0ddaed525b6654fe5793b6b43823789a740887e55f7ca09`: 70F628, 70F630, 70F638, 70F640. Complete selected sequences include the one-byte leading-node sentinel:

| Selector | Owned records | SHA256 |
| --- | --- | --- |
|0, 70F628..70F62E|(15,1,16), (24,2,FF); leading-node FF|`c137a4d9191a3c7cdd71b4cf7389a48ed55c27f62efc21560b1cb2aff5d2bf16`|
|1, 70F630..70F633|(3E,2,FF); leading-node FF|`d73e776389f4165f9a521d101a9799cdc600e47ff943e5504d853193aa798df2`|
|2, 70F638..70F63B|(40,2,FF); leading-node FF|`926d2e6fa4b4cb40b78e3b56407cdb0ab1570eca2acfc508a560fb0e85ee9423`|
|3, 70F640..70F643|(3E,2,FF); leading-node FF|`d73e776389f4165f9a521d101a9799cdc600e47ff943e5504d853193aa798df2`|

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Reads into runtime actor/model records remain static contracts. There is no capture of topology, traversal frequency, slowdown admission, or measured optimization benefit.

Owned-word audit: two complete bodies,104 original instruction words verified,19 omitted zero/NOP words,zero conflicts and zero omitted nonzero words. Four selector physical windows/four pointer entries/all selected record terminators hashed above. Live note/actual annotation/link checks clean; no shared index mutation.
