# Logical resource allocation, scenario tables and template loading

Static File #1 US research, 2026-11-04. Original identities are recorded in
[the central index](FUNCTION_INDEX.md). This follows
[resource instance pooling](SYMBOLS_RESOURCE_INSTANCE_POOL.md). Only generated
instruction comments and owned file-backed bytes were inspected; no game,
build, replay, attachment, live-memory inspection or implementation change was
performed. File formats and resource roles remain descriptive candidates.

## Logical record storage and allocation

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5919F0](../recomp/config/output_ovl/o2/o2_005919F0_0x5919f0.cpp) | `clear_logical_resources_and_initialize_template_tables_candidate` | Confirmed/static mechanics | Clears3C00 bytes logical records3C5630,counter743128=0,half74CCF0=0. Clears74C970 length300,74C770 length200,templates74BB50 lengthC18,Y-offset table74B940 length204;fills content-selector74B6E0 length258 withFF. Initializes129 property rows74B2D0 stride8:half0=32(hex),remaining halfwords0. Clears32 auxiliary-list bytes4BAC52. No model/auxiliary release, instance-pool reset or file load in this body. |
| [o2 0x591AE0](../recomp/config/output_ovl/o2/o2_00591AE0_0x591ae0.cpp) | `allocate_logical_resource_record_with_content_selector_candidate` | Confirmed/static mechanics | Signed active counter743128 must<FF. Scans indices1..255 for inactive byte0,zeroes60 bytes,sets activity1,byte1=a0,half4=a1,selfID2=index,content6=a2,byte3=1. Resolves signed content through5B42B0 into byte2B,increments counter,returns record pointer. Excludes index0. Counter gate not recomputed from scan;negative counter is not rejected. Quantity/owner/flags remain zero. |
| [o2 0x591BE0](../recomp/config/output_ovl/o2/o2_00591BE0_0x591be0.cpp) | `retire_active_logical_resource_and_mark_flags_candidate` | Confirmed/static mechanics | Active low8 ID only:clears activity byte0 and flags18 bit1,ORs flag20000000,decrements743128. Does not clear remaining record,release attached1C/20,remove inventory references or claim tag,or validate count. Callers needing release use other helpers first. |
| [o2 0x592900](../recomp/config/output_ovl/o2/o2_00592900_0x592900.cpp) | `find_logical_resource_by_positive_signed_definition_id_candidate` | Confirmed/static mechanics | Signed low16 a0 must>0;scans256 records and returns first whose unsigned half4 matches,else0. Does not check activity,flag1,owner or content. Can return inactive historical record and does not resolve slot ID from content type. |
| [o2 0x592A90](../recomp/config/output_ovl/o2/o2_00592A90_0x592a90.cpp) | `allocate_owned_resource_with_quantity_candidate` | Confirmed/static mechanics | a0 actor index,a1 content,a2 quantity. Calls591AE0(0,0,content),failure0. Success flags18=1,byte3=0,quantity24=low16 a2,owner28=low16(actor index)+1,returns record pointer. No actor/content-admission/free-inventory-slot check or insertion into actor banks. |

## Scenario resource placement and initialization

The owned path strings at73E140/160/180 are
`%s/item%03d%02d.tbl`, `data/rom/scene/item_set`, `item%03d%02d.tbl`.
The data-file formats73E1A0/1B0 are `%s/item%03d.dat` and `item%03d.dat`.
These file-backed strings corroborate the resource-data role; they do not prove
that a specific file was read during the player's session.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x591C50](../recomp/config/output_ovl/o2/o2_00591C50_0x591c50.cpp) | `initialize_scenario_resource_records_tables_and_actor_grants_candidate` | Probable role; full body reviewed | Saves scenario3243DA,clears5919F0. Mode1B02D0==1 chooses591F40,otherwise591D50,then5920C0(scenario);load return values ignored. Mode1 plus4BAE96 bit1 scans active content!=20 with template flags1 and6000,raising nonpositive quantity to1. Finally5924E0 grants actor resources. Does not initialize/recreate render-instance pool here;that is591920's separate stage. |
| [o2 0x591D50](../recomp/config/output_ovl/o2/o2_00591D50_0x591d50.cpp) | `load_weighted_scenario_item_set_variant_candidate` | Probable role; full body and path strings reviewed | a0 low16 scenario. Chooses variant4*global4BAE8A+(random1AEC80(2) low2),one random1AEC80(0) low16%100 reused for every row. Loads tbl into32440C using18DAB0/18D820 when3243D7==0,otherwise1AA3E0. Requires version word4 and nonzero signed row count. Each12-byte row has three4-byte(content unsigned half,quantity signed byte,weight unsigned byte) alternatives;subtracts weights from shared random sample per row until negative. ContentFFFF skips. Allocates591AE0(0,rowIndex+1,0),then writes chosen content/quantity,flags800;content3717 quantity=4B0 if3243CC==0,otherwise258. Initial allocation selector derives content0 and is not refreshed locally after content overwrite;placement pass592370 later refreshes matched records. Bad load/header returns0,otherwise1 even if rows skipped or allocations fail. |
| [o2 0x591F40](../recomp/config/output_ovl/o2/o2_00591F40_0x591f40.cpp) | `load_direct_scenario_item_set_mode_variant_candidate` | Probable role; mechanics verified | a0 low16 scenario;variant=global4BAE8A+10. Same tbl load backends/header version4/nonzero signed count as591D50,then one4-byte content/quantity entry per row,not weighted triples. ContentFFFF skipped;allocates zero-content definition rowIndex+1,overwrites content/quantity,flags800,3717 quantity override. Allocation failure exits loop but still returns1;read/header failures0. Does not refresh selector after overwrite in this body. |
| [o2 0x5920C0](../recomp/config/output_ovl/o2/o2_005920C0_0x5920c0.cpp) | `load_scenario_item_dat_and_dispatch_nonempty_sections_candidate` | Probable role; full body reviewed | a0 low16 scenario builds dat path. Uses32440C as read destination throughsame local/alternate backends. After success reads section directory from global324420;no alias between those pointers assumed. Nonzero(offset,count) pairs at0/4,8/C,10/14 dispatch base+offset to5921D0,592370,5924A0 respectively. No file-size/range/version validation at directory level and no aggregation of section return values. |
| [o2 0x5921D0](../recomp/config/output_ovl/o2/o2_005921D0_0x5921d0.cpp) | `load_resource_templates_and_build_content_selector_table_candidate` | Probable role; full body reviewed | Requires section version3 and nonzero count word4;other counts8/C for compatibility halfwords and float offsets. Writes low16 count74CCF0. Four relative offsets10/14/18/1C optionally copy count*24 templates to74BB50,count*4 Y offsets to74B940,offsetCount*4 floats to74C770,compatCount*2 halfwords to74C970;copies require respective signed counts>0. Then scans template count,normalizes unsigned content half12>=2710 to%100+1F4,range0..257,stores template index low8 in74B6E0. Later duplicate normalized types overwrite earlier;selector table not cleared here. No source extent or destination capacity checks. |
| [o2 0x592370](../recomp/config/output_ovl/o2/o2_00592370_0x592370.cpp) | `apply_resource_placement_rows_by_definition_halfword_candidate` | Probable role; full body reviewed | Requires version3 and nonzero signed count. Each36-byte row (0x24) scans256 records for first active record half4==row half2. Copies row half0 low8 togroup byte1,XYZ4..C to8..10,angles10/12 to14/16,bytes14/15 to2C/2D,half16 to2E,XYZ18..20 tosaved30..38. ORs flags1,refreshes template selector through5B42B0(record signed content),then next row. Missing match skipped;returns1 for accepted header even no match or negative count. No owner/content matching,allocation or model creation. |
| [o2 0x5924A0](../recomp/config/output_ovl/o2/o2_005924A0_0x5924a0.cpp) | `copy_counted_resource_property_rows_candidate` | Confirmed/static mechanics | Signed word0 count>0 copies8*count bytes fromsection+4 to74B2D0,returns1;otherwise0. No version,source-size or129-row destination capacity admission. |
| [o2 0x5924E0](../recomp/config/output_ovl/o2/o2_005924E0_0x5924e0.cpp) | `grant_actor_resource_from_bb4_definition_table_candidate` | Probable role; mechanics verified | Iterates fixed actor array up to signed global actor count4BAEA0,not hardcoded4. Actor unsigned BB4 must1..98 and5F29A0(actor) nonzero. Table723810[BB4-1] supplies content half0 (FFFF reject),quantity half2 (0 reject). Allocates591AE0(0,0,content),failure ends whole traversal. Sets flags1,byte3=0,quantity,owner=actorIndex+1,then5F27B0(actor,selfID). Does not inspect actor activity,resource admission593060 or report insertion success here. |

The tbl allocation and dat placement stages are separate. A temporary selector
based on content0 before later placement refresh is therefore documented as a
sequence, without assuming that it is an active-session defect. Loading failure
does not roll back already allocated records in these bodies.

All13 named entries' instruction words and source links were checked against
owned o2 bytes. The displayed formats are exact owned strings. No current file
load, slowdown measurement, root cause or controlled fix/retest is claimed.
