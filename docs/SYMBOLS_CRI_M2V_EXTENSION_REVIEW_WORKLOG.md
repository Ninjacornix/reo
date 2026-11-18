# CRI M2V extension review: unfinished static worklog

Status: completed. All3050 original instruction words and owned tables were subsequently reviewed;the sole catalogue row and final findings live in [complete extension notebook](SYMBOLS_CRI_M2V_EXTENSION_HEADER_DISPATCH.md). This historical worklog has **zero additional catalogue credit**. No target/build/replay/attachment/live-memory work occurred.

Owned resident ELF `game_data/SLUS_207.65`, SHA-25606bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46.

Read consecutive `read_insns.py main151CC0` output batches first260,skip260/280,skip540/280,skip820/300,skip1120/300,skip1420/300,skip1720/300,skip2020/300,skip2320/300,skip2620/remainder. Last owned instruction read154C74. Body has one catalogue identity; internal case labels are not new functions.

Working observations, not final conformance findings:

- Inputs handle a0,extension pointer a1,state=handle128. Increments state4F0,bit reader aligns pointer down4 and prefetches. Stores32-bit start code34,4-bit extensionID40. Dispatch uses10-entry table23E480 indexedID-1 with unsigned bound<10. Context-dependent branch cluster151E60..151E9C assigns a temporary v0 that is overwritten at151EA0,so it does not establish a format/context rejection; follow actual dispatch targets before assigning admission policy.
- First case151EC8..152540:profile/level44(8bits),progressive48(1),chroma4C(2),Wext50(2),Hext54(2),bitrateext58(12),marker18(1),VBVext5C(8),lowdelay60(1),rateN64(2),rateD68(5). Table23E3D0 indexedchroma givesstate338,then geometry150E08/aspect150ED0. Combined bitrate2F8=(58<<18)|14;VBV2FC=(5C<<10)|1C. Base-rate table23E350 indexedstate10 gives2E8;2F0=base*(N+1)/(D+1) via software arithmetic. No bounds/marker checks observed in these paths.
- Second case152548..152964:videoformat6C(3),colordesc70(1),optionalprimaries74/transfer78/matrix7C(8each),displayW80(14),marker18(1),displayH84(14),aspect150ED0. Fields not conditionally assigned retain prior values.
- Quant-matrix extension152968..152CE0 reads load flags24/28/158/15C(1each), skips64 bytes per enabled matrix, calls151130(noop), returns via common tail. No matrix coefficient store.
- Copyright152CE8..153200 fields19Cflag1,1A0ID8,1A4original1,1A8reserved7,marker18(1),1ACnumber20,marker18,1B0number22,marker18,1B4number22. Thus64 copyright-number bits are separate scalar fields, not an invented contiguous u64.
- Scalable case153208 sets330=1,88mode2,8ClayerID4. Mode1 parses lower-layer size90W14,marker18,94H14,then98/9C/A0/A4 five-bit subsampling fields. Mode3 parsesA8one-bit picture-mux flag and optionalACone-bit flag (in progress at1537A4). Other modes go common tail. Remaining temporal fields, later extension cases, table values and common tail NOT yet reviewed.

Reuse existing completed notebooks for sequence/GOP/picture and shared consumed-position/prefetch limits; do not infer the remainder from MPEG familiarity. No shared JSON/index writes.
