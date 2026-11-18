# Mechanically classified guest leaves

These exact whole-body classifications are separate from reviewed semantic names.
They establish only the stated register/memory behavior. Original API purpose,
return type and caller expectations remain unknown. Field accesses retain guest
memory exceptions/alias/MMIO behavior; no pure-getter, null-safety or host-memory
replacement contract is inferred. A no-op preserves v0; it
does **not** return zero. No gameplay, build, replay or live process was used.

Current snapshot: **173** previously unnamed entries.

Only aligned catalogue intervals of 8..32 bytes are admitted. Every original
word is read from the identity-checked main ELF or overlay. Accepted bodies are
JR ra with one admitted delay instruction, or one admitted a0-relative memory
instruction followed by JR ra/NOP. Direct J tails are also admitted only
outside protected o4/o5, to one reviewed same-image catalogue entry, with
NOP or ADDIU a1,a0,signed16 delay. Local loops, JAL, other delay effects
and callee behavior are excluded. All trailing words must be zero. Padding
is included in the recorded fingerprint.
Unaligned/byte-sized catalogue artifacts are excluded. No reviewed name is replaced.

Regenerate after refreshing the index:

```powershell
python tools/function_index/classify_leaves.py
```

| Image / original entry | Complete observed behavior | Source |
| --- | --- | --- |
| main 0x00114D08 | Returns sign-extended constant -1 in v0; no memory access. | [generated body](../recomp/config/output/sub_00114D08_0x114d08.cpp) |
| main 0x00114D10 | Returns sign-extended constant -1 in v0; no memory access. | [generated body](../recomp/config/output/sub_00114D10_0x114d10.cpp) |
| main 0x00114D18 | Returns sign-extended constant -1 in v0; no memory access. | [generated body](../recomp/config/output/sub_00114D18_0x114d18.cpp) |
| main 0x00114DD0 | Returns sign-extended constant 1 in v0; no memory access. | [generated body](../recomp/config/output/sub_00114DD0_0x114dd0.cpp) |
| main 0x00114DF0 | Returns sign-extended constant 1 in v0; no memory access. | [generated body](../recomp/config/output/sub_00114DF0_0x114df0.cpp) |
| main 0x0011DF28 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0011DF28_0x11df28.cpp) |
| main 0x001244C0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001244C0_0x1244c0.cpp) |
| main 0x0012A8E8 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0012A8E8_0x12a8e8.cpp) |
| main 0x0012C660 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0012C660_0x12c660.cpp) |
| main 0x0012C828 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0012C828_0x12c828.cpp) |
| main 0x0012C890 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_0012C890_0x12c890.cpp) |
| main 0x0012C8C8 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0012C8C8_0x12c8c8.cpp) |
| main 0x0012C8D0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0012C8D0_0x12c8d0.cpp) |
| main 0x0012C8D8 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0012C8D8_0x12c8d8.cpp) |
| main 0x0012C8E0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0012C8E0_0x12c8e0.cpp) |
| main 0x0012C8E8 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0012C8E8_0x12c8e8.cpp) |
| main 0x0012C8F0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_0012C8F0_0x12c8f0.cpp) |
| main 0x0012DA68 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_0012DA68_0x12da68.cpp) |
| main 0x0012DD48 | Returns sign-extended constant 256 in v0; no memory access. | [generated body](../recomp/config/output/sub_0012DD48_0x12dd48.cpp) |
| main 0x001300F8 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001300F8_0x1300f8.cpp) |
| main 0x00130100 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00130100_0x130100.cpp) |
| main 0x00130E38 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00130E38_0x130e38.cpp) |
| main 0x00132FE0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00132FE0_0x132fe0.cpp) |
| main 0x00132FE8 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00132FE8_0x132fe8.cpp) |
| main 0x00133010 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00133010_0x133010.cpp) |
| main 0x00133018 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_00133018_0x133018.cpp) |
| main 0x00133020 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00133020_0x133020.cpp) |
| main 0x00133028 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00133028_0x133028.cpp) |
| main 0x00133030 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00133030_0x133030.cpp) |
| main 0x00133038 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00133038_0x133038.cpp) |
| main 0x001347F8 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001347F8_0x1347f8.cpp) |
| main 0x00134F90 | Stores low 32 bits of a1 to guest memory at a0+8; preserves v0. | [generated body](../recomp/config/output/sub_00134F90_0x134f90.cpp) |
| main 0x00136C38 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_00136C38_0x136c38.cpp) |
| main 0x0013D588 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0013D588_0x13d588.cpp) |
| main 0x0013D590 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0013D590_0x13d590.cpp) |
| main 0x0013F150 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_0013F150_0x13f150.cpp) |
| main 0x00147CE8 | Returns sign-extended constant 1 in v0; no memory access. | [generated body](../recomp/config/output/sub_00147CE8_0x147ce8.cpp) |
| main 0x00149200 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00149200_0x149200.cpp) |
| main 0x00149260 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00149260_0x149260.cpp) |
| main 0x00149278 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00149278_0x149278.cpp) |
| main 0x00149290 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00149290_0x149290.cpp) |
| main 0x00149298 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_00149298_0x149298.cpp) |
| main 0x001492A8 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001492A8_0x1492a8.cpp) |
| main 0x001492D0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001492D0_0x1492d0.cpp) |
| main 0x00188838 | Returns sign-extended constant 1 in v0; no memory access. | [generated body](../recomp/config/output/sub_00188838_0x188838.cpp) |
| main 0x001A9180 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001A9180_0x1a9180.cpp) |
| main 0x001A91C0 | Returns sign-extended constant 1 in v0; no memory access. | [generated body](../recomp/config/output/sub_001A91C0_0x1a91c0.cpp) |
| main 0x001AA3D0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001AA3D0_0x1aa3d0.cpp) |
| main 0x001AC640 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001AC640_0x1ac640.cpp) |
| main 0x001AC6C0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001AC6C0_0x1ac6c0.cpp) |
| main 0x001B2CD0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B2CD0_0x1b2cd0.cpp) |
| main 0x001B3860 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B3860_0x1b3860.cpp) |
| main 0x001B3870 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B3870_0x1b3870.cpp) |
| main 0x001B3880 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B3880_0x1b3880.cpp) |
| main 0x001B3C30 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B3C30_0x1b3c30.cpp) |
| main 0x001B77C0 | Returns sign-extended constant 1 in v0; no memory access. | [generated body](../recomp/config/output/sub_001B77C0_0x1b77c0.cpp) |
| main 0x001B77D0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B77D0_0x1b77d0.cpp) |
| main 0x001B77E0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B77E0_0x1b77e0.cpp) |
| main 0x001B77F0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B77F0_0x1b77f0.cpp) |
| main 0x001B7800 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B7800_0x1b7800.cpp) |
| main 0x001B7810 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B7810_0x1b7810.cpp) |
| main 0x001B7820 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B7820_0x1b7820.cpp) |
| main 0x001B8290 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B8290_0x1b8290.cpp) |
| main 0x001B82B0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B82B0_0x1b82b0.cpp) |
| main 0x001B82C0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B82C0_0x1b82c0.cpp) |
| main 0x001B82D0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001B82D0_0x1b82d0.cpp) |
| main 0x001BB1C0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001BB1C0_0x1bb1c0.cpp) |
| main 0x001BB470 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001BB470_0x1bb470.cpp) |
| main 0x001BD2E0 | Jumps to guest 0x00114650 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output/sub_001BD2E0_0x1bd2e0.cpp) |
| main 0x001C0410 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001C0410_0x1c0410.cpp) |
| main 0x001C80D0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001C80D0_0x1c80d0.cpp) |
| main 0x001C80E0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001C80E0_0x1c80e0.cpp) |
| main 0x001C80F0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001C80F0_0x1c80f0.cpp) |
| main 0x001C8100 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001C8100_0x1c8100.cpp) |
| main 0x001C8D50 | Jumps to guest 0x001C8130 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output/sub_001C8D50_0x1c8d50.cpp) |
| main 0x001C8F40 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001C8F40_0x1c8f40.cpp) |
| main 0x001CC230 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001CC230_0x1cc230.cpp) |
| main 0x001D1C40 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001D1C40_0x1d1c40.cpp) |
| main 0x001D1F30 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001D1F30_0x1d1f30.cpp) |
| main 0x001D1F40 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001D1F40_0x1d1f40.cpp) |
| main 0x001D97E0 | Returns sign-extended constant -1 in v0; no memory access. | [generated body](../recomp/config/output/sub_001D97E0_0x1d97e0.cpp) |
| main 0x001DA310 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001DA310_0x1da310.cpp) |
| main 0x001DA320 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001DA320_0x1da320.cpp) |
| main 0x001F45B0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001F45B0_0x1f45b0.cpp) |
| main 0x001F45C0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output/sub_001F45C0_0x1f45c0.cpp) |
| main 0x001F5030 | Returns sign-extended constant 1 in v0; no memory access. | [generated body](../recomp/config/output/sub_001F5030_0x1f5030.cpp) |
| main 0x001F5040 | Returns sign-extended constant -1 in v0; no memory access. | [generated body](../recomp/config/output/sub_001F5040_0x1f5040.cpp) |
| main 0x001F6FA0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001F6FA0_0x1f6fa0.cpp) |
| main 0x001F6FB0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output/sub_001F6FB0_0x1f6fb0.cpp) |
| main 0x001F71E0 | Jumps to guest 0x001BB2B0 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output/sub_001F71E0_0x1f71e0.cpp) |
| o2 0x0057EAA0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_0057EAA0_0x57eaa0.cpp) |
| o2 0x0057EAB0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_0057EAB0_0x57eab0.cpp) |
| o2 0x0057EAC0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_0057EAC0_0x57eac0.cpp) |
| o2 0x00587620 | Stores low 8 bits of zero to guest memory at a0+1; preserves v0. | [generated body](../recomp/config/output_ovl/o2/o2_00587620_0x587620.cpp) |
| o2 0x00588BE0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00588BE0_0x588be0.cpp) |
| o2 0x00588D00 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00588D00_0x588d00.cpp) |
| o2 0x00588D10 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00588D10_0x588d10.cpp) |
| o2 0x00588EA0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00588EA0_0x588ea0.cpp) |
| o2 0x00588EB0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00588EB0_0x588eb0.cpp) |
| o2 0x00588EC0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00588EC0_0x588ec0.cpp) |
| o2 0x00588ED0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00588ED0_0x588ed0.cpp) |
| o2 0x00588FC0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00588FC0_0x588fc0.cpp) |
| o2 0x00589110 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00589110_0x589110.cpp) |
| o2 0x00589120 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00589120_0x589120.cpp) |
| o2 0x005892C0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_005892C0_0x5892c0.cpp) |
| o2 0x005892D0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_005892D0_0x5892d0.cpp) |
| o2 0x0058F210 | Stores low 8 bits of zero to guest memory at a0+1; preserves v0. | [generated body](../recomp/config/output_ovl/o2/o2_0058F210_0x58f210.cpp) |
| o2 0x005951A0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_005951A0_0x5951a0.cpp) |
| o2 0x005D1970 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_005D1970_0x5d1970.cpp) |
| o2 0x005D5BD0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_005D5BD0_0x5d5bd0.cpp) |
| o2 0x005D8620 | Jumps to guest 0x005D8630 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_005D85E0_0x5d85e0.cpp) |
| o2 0x005F1B30 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_005F1B30_0x5f1b30.cpp) |
| o2 0x005F30C0 | Returns sign-extended constant 1 in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_005F30C0_0x5f30c0.cpp) |
| o2 0x005F46B0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_005F46B0_0x5f46b0.cpp) |
| o2 0x005FE660 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_005FE660_0x5fe660.cpp) |
| o2 0x00606BC0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_00606BC0_0x606bc0.cpp) |
| o2 0x00606BD0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_00606BD0_0x606bd0.cpp) |
| o2 0x00613D10 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_00613D10_0x613d10.cpp) |
| o2 0x00615BD0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_00615BD0_0x615bd0.cpp) |
| o2 0x00626AD0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00626AD0_0x626ad0.cpp) |
| o2 0x00626AE0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00626AE0_0x626ae0.cpp) |
| o2 0x00626B70 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00626B70_0x626b70.cpp) |
| o2 0x00626B80 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00626B80_0x626b80.cpp) |
| o2 0x00626B90 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00626B90_0x626b90.cpp) |
| o2 0x00626BA0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00626BA0_0x626ba0.cpp) |
| o2 0x00626BB0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00626BB0_0x626bb0.cpp) |
| o2 0x006272A0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_006272A0_0x6272a0.cpp) |
| o2 0x006272B0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_006272B0_0x6272b0.cpp) |
| o2 0x006272C0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_006272C0_0x6272c0.cpp) |
| o2 0x00627310 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00627310_0x627310.cpp) |
| o2 0x00627590 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00627590_0x627590.cpp) |
| o2 0x006275F0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_006275F0_0x6275f0.cpp) |
| o2 0x00627650 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00627650_0x627650.cpp) |
| o2 0x00627660 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00627660_0x627660.cpp) |
| o2 0x00627670 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00627670_0x627670.cpp) |
| o2 0x00627760 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00627760_0x627760.cpp) |
| o2 0x00628D20 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00628D20_0x628d20.cpp) |
| o2 0x00628D30 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00628D30_0x628d30.cpp) |
| o2 0x00629320 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_00629320_0x629320.cpp) |
| o2 0x00633780 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_00633780_0x633780.cpp) |
| o2 0x00635630 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_00635630_0x635630.cpp) |
| o2 0x0063F590 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_0063F590_0x63f590.cpp) |
| o2 0x006408D0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_006408D0_0x6408d0.cpp) |
| o2 0x006408E0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_006408E0_0x6408e0.cpp) |
| o2 0x006409C0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_006409C0_0x6409c0.cpp) |
| o2 0x006409D0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_006409D0_0x6409d0.cpp) |
| o2 0x00684000 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_00684000_0x684000.cpp) |
| o2 0x0068BFB0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_0068BFB0_0x68bfb0.cpp) |
| o2 0x006A1790 | Jumps to guest 0x006A9490 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006A1790_0x6a1790.cpp) |
| o2 0x006B4B90 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_006B4B90_0x6b4b90.cpp) |
| o2 0x006B60D0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_006B60D0_0x6b60d0.cpp) |
| o2 0x006C1BC0 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o2/o2_006C1BC0_0x6c1bc0.cpp) |
| o2 0x006C2240 | Jumps to guest 0x00625930 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C2240_0x6c2240.cpp) |
| o2 0x006C2250 | Jumps to guest 0x00625C50 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C2250_0x6c2250.cpp) |
| o2 0x006C2260 | Jumps to guest 0x00625670 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C2260_0x6c2260.cpp) |
| o2 0x006C2270 | Jumps to guest 0x006257A0 without linking ra. Sets a1 to sign-extended 32-bit (a0+4260) in the delay slot. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C2270_0x6c2270.cpp) |
| o2 0x006C2280 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_006C2280_0x6c2280.cpp) |
| o2 0x006C2D40 | Jumps to guest 0x00625930 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C2D40_0x6c2d40.cpp) |
| o2 0x006C2D50 | Jumps to guest 0x00625C50 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C2D50_0x6c2d50.cpp) |
| o2 0x006C2D60 | Jumps to guest 0x00625670 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C2D60_0x6c2d60.cpp) |
| o2 0x006C2D70 | Jumps to guest 0x006257A0 without linking ra. Sets a1 to sign-extended 32-bit (a0+4260) in the delay slot. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C2D70_0x6c2d70.cpp) |
| o2 0x006C2D80 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_006C2D80_0x6c2d80.cpp) |
| o2 0x006C4760 | Jumps to guest 0x00625930 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C4760_0x6c4760.cpp) |
| o2 0x006C4770 | Jumps to guest 0x00625C50 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C4770_0x6c4770.cpp) |
| o2 0x006C4780 | Jumps to guest 0x00625670 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C4780_0x6c4780.cpp) |
| o2 0x006C4790 | Jumps to guest 0x006257A0 without linking ra. Sets a1 to sign-extended 32-bit (a0+4260) in the delay slot. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C4790_0x6c4790.cpp) |
| o2 0x006C47A0 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_006C47A0_0x6c47a0.cpp) |
| o2 0x006C53F0 | Jumps to guest 0x00625930 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C53F0_0x6c53f0.cpp) |
| o2 0x006C5400 | Jumps to guest 0x00625C50 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C5400_0x6c5400.cpp) |
| o2 0x006C5410 | Jumps to guest 0x00625670 without linking ra. Preserves argument registers before transfer. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C5410_0x6c5410.cpp) |
| o2 0x006C5420 | Jumps to guest 0x006257A0 without linking ra. Sets a1 to sign-extended 32-bit (a0+4260) in the delay slot. Callee effects and return value are not inferred. | [generated body](../recomp/config/output_ovl/o2/o2_006C5420_0x6c5420.cpp) |
| o2 0x006C5430 | Returns without modifying guest registers or memory. | [generated body](../recomp/config/output_ovl/o2/o2_006C5430_0x6c5430.cpp) |
| o6 0x006FFF88 | Returns integer zero in v0; no memory access. | [generated body](../recomp/config/output_ovl/o6/o6_006FFF88_0x6fff88.cpp) |
