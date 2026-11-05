# Network DNAS: ASN.1 ANY union codecs and tag dispatch

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request or live-memory read occurred.

All seven bodies were independently read through complete switches, branches, delay slots, cleanup and mutation. This closes the optional-value child of the [algorithm-identifier pair](SYMBOLS_NETDNAS_ASN1_CERTIFICATE_COMPONENTS.md). [Primitive codecs](SYMBOLS_NETDNAS_PRIMITIVE_CODECS.md), [OID/name codecs](SYMBOLS_NETDNAS_GROUPED_NAME_CODEC.md) and [tagged time](SYMBOLS_NETDNAS_TAGGED_TIME.md) retain their own bounds/encoding limits. ANY is a structure/dispatch role, not universal standards conformance. No execution, timing or slowdown cause is claimed.

All29 owned jump-table words77C780..77C7F0 were read independently. Tags and targets are hexadecimal; unsupported rows target6F136C.

| Tags | Owned target | Child operation |
| --- | --- | --- |
| 2 | 6F1198 | INTEGER6EE8A8 |
| 3 | 6F11B4 | BIT STRING6ED7A8 |
| 4 | 6F11D0 | OCTET STRING6F0A90 |
| 5 | 6F1188 | NULL payload |
| 6 | 6F11EC | OID6EF0B8 |
| 7..F,12,15,18..1A,1D | 6F136C | unsupported |
| 10,11 | 6F12EC | preserve complete encoded span |
| 13 | 6F1208 |6EF3B8 |
| 14 | 6F1224 |6EDAD8 allowedmask4 |
| 16 | 6F1244 |6EDAD8 allowedmask10 |
| 17 | 6F12C4 |UTC6EF580 |
| 1B | 6F1264 |6EDAD8 allowedmask80 |
| 1C | 6F1284 |6EDAD8 allowedmask100 |
| 1E | 6F12A4 |6EDAD8 allowedmask800 |

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6F0E78](../recomp/config/output_ovl/o4/o4_006F0E78_0x6f0e78.cpp) | `encode_netdnas_asn1_any_type_union_with_raw_sequence_passthrough` | Confirmed lifecycle/data/control flow; domain limits retained | NULL union returns0. Tag5 NULL writes5/length0 andreturns2. Types2/102 INTEGER,3 BIT STRING,4 OCTET STRING,6 OID use paired encoders;13/14/16/1B/1C/1E strings through6EDCD0(class0),17 UTC through6EF560. Types10/11 child holds already encoded span:length0,data8,rawcopies to optionalcursor andadvances. Other types return0. OID encoder returns contentlength in output mode; no normalization or uniform result-contract assumption. |
| [o4 0x6F10C8](../recomp/config/output_ovl/o4/o4_006F10C8_0x6f10c8.cpp) | `decode_netdnas_asn1_any_union_through_owned_tag_dispatch_table` | Confirmed lifecycle/data/control flow; domain limits retained | Reuses union or6F13F0;6EF948 parses header using caller length. Error80 bit aborts;clears old child6F14F8 before tag dispatch. Owned29word table77C780 maps tags2..1E (table below);unsupported(D,85,6A). Child decoders use original header start and available span;NULL tag5 storeschildNULL and commits cursor at contentstart without explicit zero-content-length check. Sequence/set10/11 allocate bytevalue and copy complete original header+declaredcontent span;local initial length comparison excludes later added header bytes,so full bounds remain helper/caller-dependent. Success writes type/input/object;failure frees only newly allocated union,reused data can already be destroyed. Parsed class and non-error header flags not locally validated. |
| [o4 0x6F13F0](../recomp/config/output_ovl/o4/o4_006F13F0_0x6f13f0.cpp) | `allocate_netdnas_asn1_any_type_union` | Confirmed lifecycle/data/control flow; domain limits retained | Allocates8bytes;type0=-1,child4NULL. Failure diagnostic(D,77,21),returnsNULL. No tag payload allocated here. |
| [o4 0x6F1448](../recomp/config/output_ovl/o4/o4_006F1448_0x6f1448.cpp) | `destroy_netdnas_asn1_any_type_union` | Confirmed lifecycle/data/control flow; domain limits retained | NULL no-op;6F14F8 releases/reset child according to tag,then710A40outer. Does not recursively inspect arbitrary schema beyond dispatch. |
| [o4 0x6F1488](../recomp/config/output_ovl/o4/o4_006F1488_0x6f1488.cpp) | `get_netdnas_asn1_union_tag_only_when_child_nonnull` | Confirmed lifecycle/data/control flow; domain limits retained | Reads union4;nonnull returns tag0,else0. No NULL union check; NULL-tag5 can therefore report0 through this getter. |
| [o4 0x6F14A8](../recomp/config/output_ovl/o4/o4_006F14A8_0x6f14a8.cpp) | `replace_netdnas_asn1_union_tag_and_take_child_pointer` | Confirmed lifecycle/data/control flow; domain limits retained | If current child4nonNULL invokes6F14F8;thenstoresoriginala2child4,originala1tag0. No retain/copy/type validation or self-alias protection; ownership transferred according to future tag dispatch. |
| [o4 0x6F14F8](../recomp/config/output_ovl/o4/o4_006F14F8_0x6f14f8.cpp) | `release_netdnas_asn1_union_child_by_literal_tag_ranges` | Confirmed lifecycle/data/control flow; domain limits retained | NULL union orchildNULL returns without resetting tag. Tag6 releases OID6EF2D0;tags2..4,10..1C,1E,102 release genericbytevalue6F0028;other nonNULLchild types are cleared without destructor. After release/drop zeroschild4 andtag0. NULL tag5 pointer is not freed; unsupported tag lifetime remains caller-owned. |
