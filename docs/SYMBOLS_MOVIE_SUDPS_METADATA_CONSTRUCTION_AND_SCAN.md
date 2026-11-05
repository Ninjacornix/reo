# Resident movie metadata: SUDPS record construction and scan

Static File #1 US research, 2026-11-05. Owned ELF `game_data/SLUS_207.65`, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Full original instruction bodies and delay slots read, including loop entry tests and owned constants. No game/build/replay, attachment, live memory, MMIO access or numeric test.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x17E438](../recomp/config/output/sub_0017E438_0x17e438.cpp) | `movie_build_SUDPS_header_constant_size_and_three_enum_flags_candidate` | Confirmed complete 36-word body | strncpy8owned<SUDPS_>;sprintfowned<%06X>withconstant5thenstrcattoheader. Atoutput10hexwrites01twochars;17E4C8(body,originala2flags);appendsnewline. Originala1unused. Nooutputcapacityargumentorcheck. |
| [0x17E4C8](../recomp/config/output/sub_0017E4C8_0x17e4c8.cpp) | `movie_write_three_SUDPS_one_character_enum_codes_candidate` | Confirmed complete 56-word body | Atbody2/3/4writesonecharselectedbyflags0/4/8throughthree2pointerstackarrays:0/1=>A/D,N/C,P/I. Indicesnotvalidated;only8bytesinitializedineach16bytstackslot. Doesnotappendterminatoritself. |
| [0x17E6A0](../recomp/config/output/sub_0017E6A0_0x17e6a0.cpp) | `movie_scan_declared_bytes_for_last_SUDPS_marker_candidate` | Confirmed complete 49-word body | Zerosoutpointera2/outsizea3;NULLorlength<=0skip. Foreachoriginaldeclaredbytecount,firstmemcmp1with<thenmemcmp8with<SUDPS_>. Everymatchreplacesoutpointerand17E768size;continues,returnsLASTmatch. Doesnotcheckremaining8/21byteswithinlengthnorvalidateheaderhex/bodyflags. |
| [0x17E768](../recomp/config/output/sub_0017E768_0x17e768.cpp) | `movie_return_SUDPS_fixed_record_size21_or_zero_for_null_candidate` | Confirmed complete 3-word body | Nonnulloriginala0=>21decimal;NULL=>0. Noheaderparseorstrlen. Builderbody5+header16=21beforeappendednewline;scannerusesliteralhelperresult. |

4 bodies / 144 original instruction words. Ownedmetadataatoms/pointertables241500..24157F/128bytes SHA256 **1c3f8822d2f529b8bf740db616b90d7051f17f065ae03932a0da0b897b97239c**. Existing17E5A8/5E8/628flagreadersremainseparate. Fixed21bytecountdoesnotproveinputcontainscompletevalidrecord. All owned comments match; omitted aligned words zero.
