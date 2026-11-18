# Map door record loading, admission and snapshot adapters

Static File #1 US research, 2026-11-04. Six full original bodies reviewed.
Owned door%03d.dat names support door-record context; individual type enums
remain unknown. Addresses/offsets hexadecimal. No game/build/replay/attachment
or live-memory inspection. Snapshots here are original guest buffers, not
new slowdown incident reports or evidence of files saved on the host.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6DD7F0](../recomp/config/output_ovl/o2/o2_006DD7F0_0x6dd7f0.cpp) | `find_id_in_twelve_byte_table_until_999_sentinel_candidate` | High mechanics; candidate role | ScansunsignedhalfIDat3898E0inCstrides;ID3E7returns-1,ID==a0returnszero-basedindex. Sentineltestprecedesequality,socannotreturn3E7entry. Noexplicitboundoractivitycheck;tablepurposeunresolved. |
| [o2 0x6DD840](../recomp/config/output_ovl/o2/o2_006DD840_0x6dd840.cpp) | `serialize_map_door_records_and_admission_snapshot_candidate` | Probable role; full body reviewed | a0output. Clears800bytes;size0=min(unsigned755C84+80,5C0). Copiesrecordbuffer755C70word0tooutput40,size0;copiesadmissionpointer+18tooutput600,size80;copies759D50to680,size200. Header4/8/Cfixedserializedaddresses31E768/31ED28/31EDA8. Highestwriteends880despite800clear;callerbuffersizeunseen,notassumed800. Noallocation,filewriteorboundsproof. |
| [o2 0x6DD900](../recomp/config/output_ovl/o2/o2_006DD900_0x6dd900.cpp) | `restore_map_door_record_snapshot_with_optional_pointer_rebase_candidate` | Probable role; full body reviewed | a0snapshot. Ifa0!=31E728rewritesheader4/8/Ctosnapshot40/600/680. Copiesheader4,sizeword0intocurrent755C70recordbase;header8,size80intoadmissionpointer+18;headerC,size200into759D50. Mutatessnapshotheaderandglobalrecordmemory;noallocationorvalidationofsize/pointers. |
| [o2 0x6DD9A0](../recomp/config/output_ovl/o2/o2_006DD9A0_0x6dd9a0.cpp) | `load_scenario_door_records_and_initialize_admission_bytes_candidate` | Probable role; full body reviewed | Null324458returns;clearsits4000bytesand755C70[1C]. Readsowned item_msg/door%03d.dat via1CC8F0(flags1)when3243D7zero,otherwisecurrentscenario door%03d.dat via1AA3E0. Storesreturnedsize14,header0/4tosize/endmetadata,groupstart=filebase+10,end=groupstart+header0,metadataC=header4,admission18=filebase+readsize;zeros80admissionbytes. No read-success/headerboundscheckbeforeparse. |
| [o2 0x6DDB80](../recomp/config/output_ovl/o2/o2_006DDB80_0x6ddb80.cpp) | `admit_map_room_and_mark_its_door_record_groups_candidate` | Probable role; full body reviewed | a0room;firstDDD30reloadsmapcontext. Ifdoorbufferexistssetsadmissionbyte[room]=1. Initializes16wordlocalIDs=-1,A380collectsplacementIDs;countsnon-FFbutresultunused. Forall16non--1IDs,walkslength-prefixedgroups,checksfinaladdress<endandfirstrecordX!=-1,setsbyte6=1ineach8bytemarkerrecord. Doesnotdirectlymanipulateworlddoorphysicsorcollision;outputisrecordflags. Collectorcapacitycontractnotlocallyproven. |
| [o2 0x6DDD30](../recomp/config/output_ovl/o2/o2_006DDD30_0x6ddd30.cpp) | `reload_map_file_and_reinitialize_current_map_work_candidate` | Probable role; full body reviewed | Ifglobal755768nullreturns. Else8D40(324450)then8E30(755768),ignoringfirstreadresult. NoUIwindowconstruction,presentationorcallerbufferallocation. |

Variable record addressing/admission helpers6DDAC0/6DDCF0 are mapped in the
[map composition notebook](SYMBOLS_MAP_TILE_AND_MARKER_COMPOSITION.md).
No malformed file, invalid snapshot or record slowdown has been reproduced.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
