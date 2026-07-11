#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001010A8
// Address: 0x1010a8 - 0x101388
void sub_001010A8_0x1010a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1010a8u;

    // 0x1010a8: 0x27bdff50
    ctx->pc = 0x1010a8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1010ac: 0xffb30040
    ctx->pc = 0x1010acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1010b0: 0x80982d
    ctx->pc = 0x1010b0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1010b4: 0xffbf00a0
    ctx->pc = 0x1010b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x1010b8: 0xffbe0090
    ctx->pc = 0x1010b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x1010bc: 0x24040001
    ctx->pc = 0x1010bcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1010c0: 0xffb70080
    ctx->pc = 0x1010c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 23));
    // 0x1010c4: 0xffb60070
    ctx->pc = 0x1010c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x1010c8: 0xffb50060
    ctx->pc = 0x1010c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x1010cc: 0xffb40050
    ctx->pc = 0x1010ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x1010d0: 0xffb20030
    ctx->pc = 0x1010d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1010d4: 0xffb10020
    ctx->pc = 0x1010d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1010d8: 0xc040386
    ctx->pc = 0x1010D8u;
    SET_GPR_U32(ctx, 31, 0x1010E0u);
    ctx->pc = 0x1010DCu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    ctx->pc = 0x100E18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E18_0x100e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1010E0u; }
    }
    if (ctx->pc != 0x1010E0u) { return; }
    ctx->pc = 0x1010E0u;
    // 0x1010e0: 0x1440009d
    ctx->pc = 0x1010E0u;
    {
        const bool branch_taken_0x1010e0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1010E4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1010e0) {
            ctx->pc = 0x101358u;
            goto label_101358;
        }
    }
    ctx->pc = 0x1010E8u;
    // 0x1010e8: 0x202d
    ctx->pc = 0x1010e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1010ec: 0xc045c20
    ctx->pc = 0x1010ECu;
    SET_GPR_U32(ctx, 31, 0x1010F4u);
    ctx->pc = 0x1010F0u;
    SET_GPR_U32(ctx, 21, ((uint32_t)32 << 16));
    ctx->pc = 0x117080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1010F4u; }
    }
    if (ctx->pc != 0x1010F4u) { return; }
    ctx->pc = 0x1010F4u;
    // 0x1010f4: 0xc045144
    ctx->pc = 0x1010F4u;
    SET_GPR_U32(ctx, 31, 0x1010FCu);
    ctx->pc = 0x1010F8u;
    SET_GPR_U32(ctx, 20, ((uint32_t)32 << 16));
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1010FCu; }
    }
    if (ctx->pc != 0x1010FCu) { return; }
    ctx->pc = 0x1010FCu;
    // 0x1010fc: 0x3c100026
    ctx->pc = 0x1010fcu;
    SET_GPR_U32(ctx, 16, ((uint32_t)38 << 16));
    // 0x101100: 0x8ea57954
    ctx->pc = 0x101100u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 21), 31060)));
    // 0x101104: 0x24030001
    ctx->pc = 0x101104u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x101108: 0x3c040020
    ctx->pc = 0x101108u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32 << 16));
    // 0x10110c: 0x3c060026
    ctx->pc = 0x10110cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)38 << 16));
    // 0x101110: 0xac837924
    ctx->pc = 0x101110u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 31012), GPR_U32(ctx, 3));
    // 0x101114: 0x24a50001
    ctx->pc = 0x101114u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
    // 0x101118: 0x2404ffff
    ctx->pc = 0x101118u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10111c: 0x3c070020
    ctx->pc = 0x10111cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)32 << 16));
    // 0x101120: 0x3c080020
    ctx->pc = 0x101120u;
    SET_GPR_U32(ctx, 8, ((uint32_t)32 << 16));
    // 0x101124: 0x3c090020
    ctx->pc = 0x101124u;
    SET_GPR_U32(ctx, 9, ((uint32_t)32 << 16));
    // 0x101128: 0x3c0b0020
    ctx->pc = 0x101128u;
    SET_GPR_U32(ctx, 11, ((uint32_t)32 << 16));
    // 0x10112c: 0x3c030020
    ctx->pc = 0x10112cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
    // 0x101130: 0x3c0a0020
    ctx->pc = 0x101130u;
    SET_GPR_U32(ctx, 10, ((uint32_t)32 << 16));
    // 0x101134: 0xacc29f98
    ctx->pc = 0x101134u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4294942616), GPR_U32(ctx, 2));
    // 0x101138: 0x3c020026
    ctx->pc = 0x101138u;
    SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
    // 0x10113c: 0xac647940
    ctx->pc = 0x10113cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 31040), GPR_U32(ctx, 4));
    // 0x101140: 0xace47944
    ctx->pc = 0x101140u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 31044), GPR_U32(ctx, 4));
    // 0x101144: 0x2451a1a8
    ctx->pc = 0x101144u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 2), 4294943144));
    // 0x101148: 0xad04793c
    ctx->pc = 0x101148u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 31036), GPR_U32(ctx, 4));
    // 0x10114c: 0x2612a200
    ctx->pc = 0x10114cu;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 16), 4294943232));
    // 0x101150: 0xad24794c
    ctx->pc = 0x101150u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 31052), GPR_U32(ctx, 4));
    // 0x101154: 0x3c1e0021
    ctx->pc = 0x101154u;
    SET_GPR_U32(ctx, 30, ((uint32_t)33 << 16));
    // 0x101158: 0xad647948
    ctx->pc = 0x101158u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 31048), GPR_U32(ctx, 4));
    // 0x10115c: 0x3c170020
    ctx->pc = 0x10115cu;
    SET_GPR_U32(ctx, 23, ((uint32_t)32 << 16));
    // 0x101160: 0xad407938
    ctx->pc = 0x101160u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 31032), GPR_U32(ctx, 0));
    // 0x101164: 0x3c160023
    ctx->pc = 0x101164u;
    SET_GPR_U32(ctx, 22, ((uint32_t)35 << 16));
    // 0x101168: 0xaea57954
    ctx->pc = 0x101168u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 31060), GPR_U32(ctx, 5));
    // 0x10116c: 0xae847950
    ctx->pc = 0x10116cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 31056), GPR_U32(ctx, 4));
label_101170:
    // 0x101170: 0x3c058000
    ctx->pc = 0x101170u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x101174: 0x220202d
    ctx->pc = 0x101174u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101178: 0x34a50592
    ctx->pc = 0x101178u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 1426));
    // 0x10117c: 0xc045e06
    ctx->pc = 0x10117Cu;
    SET_GPR_U32(ctx, 31, 0x101184u);
    ctx->pc = 0x101180u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117818u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101184u; }
    }
    if (ctx->pc != 0x101184u) { return; }
    ctx->pc = 0x101184u;
    // 0x101184: 0x40282d
    ctx->pc = 0x101184u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101188: 0x4a30012
    ctx->pc = 0x101188u;
    {
        const bool branch_taken_0x101188 = (GPR_S32(ctx, 5) >= 0);
        if (branch_taken_0x101188) {
            ctx->pc = 0x10118Cu;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 36)));
            ctx->pc = 0x1011D4u;
            goto label_1011d4;
        }
    }
    ctx->pc = 0x101190u;
    // 0x101190: 0x8ee27910
    ctx->pc = 0x101190u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 23), 30992)));
    // 0x101194: 0x18400003
    ctx->pc = 0x101194u;
    {
        const bool branch_taken_0x101194 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x101198u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 31060)));
        if (branch_taken_0x101194) {
            ctx->pc = 0x1011A4u;
            goto label_1011a4;
        }
    }
    ctx->pc = 0x10119Cu;
    // 0x10119c: 0xc045a12
    ctx->pc = 0x10119Cu;
    SET_GPR_U32(ctx, 31, 0x1011A4u);
    ctx->pc = 0x1011A0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 22), 30136));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1011A4u; }
    }
    if (ctx->pc != 0x1011A4u) { return; }
    ctx->pc = 0x1011A4u;
label_1011a4:
    // 0x1011a4: 0x3c020010
    ctx->pc = 0x1011a4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
    // 0x1011a8: 0x2403ffff
    ctx->pc = 0x1011a8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1011ac: 0x0
    ctx->pc = 0x1011acu;
    // NOP
label_1011b0:
    // 0x1011b0: 0x2442ffff
    ctx->pc = 0x1011b0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1011b4: 0x0
    ctx->pc = 0x1011b4u;
    // NOP
    // 0x1011b8: 0x0
    ctx->pc = 0x1011b8u;
    // NOP
    // 0x1011bc: 0x0
    ctx->pc = 0x1011bcu;
    // NOP
    // 0x1011c0: 0x0
    ctx->pc = 0x1011c0u;
    // NOP
    // 0x1011c4: 0x1443fffa
    ctx->pc = 0x1011C4u;
    {
        const bool branch_taken_0x1011c4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x1011c4) {
            ctx->pc = 0x1011B0u;
            goto label_1011b0;
        }
    }
    ctx->pc = 0x1011CCu;
    // 0x1011cc: 0x1000ffe8
    ctx->pc = 0x1011CCu;
    {
        const bool branch_taken_0x1011cc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1011cc) {
            ctx->pc = 0x101170u;
            goto label_101170;
        }
    }
    ctx->pc = 0x1011D4u;
label_1011d4:
    // 0x1011d4: 0x10400015
    ctx->pc = 0x1011D4u;
    {
        const bool branch_taken_0x1011d4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1011D8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1011d4) {
            ctx->pc = 0x10122Cu;
            goto label_10122c;
        }
    }
    ctx->pc = 0x1011DCu;
    // 0x1011dc: 0xae13a200
    ctx->pc = 0x1011dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294943232), GPR_U32(ctx, 19));
    // 0x1011e0: 0xae807950
    ctx->pc = 0x1011e0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 31056), GPR_U32(ctx, 0));
    // 0x1011e4: 0xc045bf4
    ctx->pc = 0x1011E4u;
    SET_GPR_U32(ctx, 31, 0x1011ECu);
    ctx->pc = 0x1011E8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x116FD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1011ECu; }
    }
    if (ctx->pc != 0x1011ECu) { return; }
    ctx->pc = 0x1011ECu;
    // 0x1011ec: 0x27d08b00
    ctx->pc = 0x1011ecu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 30), 4294937344));
    // 0x1011f0: 0x220202d
    ctx->pc = 0x1011f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1011f4: 0x240382d
    ctx->pc = 0x1011f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1011f8: 0xafa00000
    ctx->pc = 0x1011f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1011fc: 0x282d
    ctx->pc = 0x1011fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101200: 0x302d
    ctx->pc = 0x101200u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101204: 0x24080004
    ctx->pc = 0x101204u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 4));
    // 0x101208: 0x200482d
    ctx->pc = 0x101208u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10120c: 0x240a0010
    ctx->pc = 0x10120cu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 16));
    // 0x101210: 0xc045e7a
    ctx->pc = 0x101210u;
    SET_GPR_U32(ctx, 31, 0x101218u);
    ctx->pc = 0x101214u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1179E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101218u; }
    }
    if (ctx->pc != 0x101218u) { return; }
    ctx->pc = 0x101218u;
    // 0x101218: 0x4410010
    ctx->pc = 0x101218u;
    {
        const bool branch_taken_0x101218 = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x10121Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x101218) {
            ctx->pc = 0x10125Cu;
            goto label_10125c;
        }
    }
    ctx->pc = 0x101220u;
    // 0x101220: 0xac407924
    ctx->pc = 0x101220u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31012), GPR_U32(ctx, 0));
    // 0x101224: 0x1000004c
    ctx->pc = 0x101224u;
    {
        const bool branch_taken_0x101224 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x101228u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x101224) {
            ctx->pc = 0x101358u;
            goto label_101358;
        }
    }
    ctx->pc = 0x10122Cu;
label_10122c:
    // 0x10122c: 0x3c020010
    ctx->pc = 0x10122cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
    // 0x101230: 0x2403ffff
    ctx->pc = 0x101230u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x101234: 0x0
    ctx->pc = 0x101234u;
    // NOP
label_101238:
    // 0x101238: 0x2442ffff
    ctx->pc = 0x101238u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10123c: 0x0
    ctx->pc = 0x10123cu;
    // NOP
    // 0x101240: 0x0
    ctx->pc = 0x101240u;
    // NOP
    // 0x101244: 0x0
    ctx->pc = 0x101244u;
    // NOP
    // 0x101248: 0x0
    ctx->pc = 0x101248u;
    // NOP
    // 0x10124c: 0x1443fffa
    ctx->pc = 0x10124Cu;
    {
        const bool branch_taken_0x10124c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x10124c) {
            ctx->pc = 0x101238u;
            goto label_101238;
        }
    }
    ctx->pc = 0x101254u;
    // 0x101254: 0x1000ffc6
    ctx->pc = 0x101254u;
    {
        const bool branch_taken_0x101254 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x101254) {
            ctx->pc = 0x101170u;
            goto label_101170;
        }
    }
    ctx->pc = 0x10125Cu;
label_10125c:
    // 0x10125c: 0x3c052000
    ctx->pc = 0x10125cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)8192 << 16));
    // 0x101260: 0x2602000c
    ctx->pc = 0x101260u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 12));
    // 0x101264: 0x451025
    ctx->pc = 0x101264u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x101268: 0x26030004
    ctx->pc = 0x101268u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 16), 4));
    // 0x10126c: 0x26040008
    ctx->pc = 0x10126cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 8));
    // 0x101270: 0x8c460000
    ctx->pc = 0x101270u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x101274: 0x852025
    ctx->pc = 0x101274u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x101278: 0x651825
    ctx->pc = 0x101278u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x10127c: 0x8c650000
    ctx->pc = 0x10127cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x101280: 0x24100001
    ctx->pc = 0x101280u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 1));
    // 0x101284: 0x240200ff
    ctx->pc = 0x101284u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 255));
    // 0x101288: 0x10c20016
    ctx->pc = 0x101288u;
    {
        const bool branch_taken_0x101288 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 2));
        ctx->pc = 0x10128Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 0)));
        if (branch_taken_0x101288) {
            ctx->pc = 0x1012E4u;
            goto label_1012e4;
        }
    }
    ctx->pc = 0x101290u;
    // 0x101290: 0x240200fe
    ctx->pc = 0x101290u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 254));
    // 0x101294: 0x14c20004
    ctx->pc = 0x101294u;
    {
        const bool branch_taken_0x101294 = (GPR_U32(ctx, 6) != GPR_U32(ctx, 2));
        ctx->pc = 0x101298u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x101294) {
            ctx->pc = 0x1012A8u;
            goto label_1012a8;
        }
    }
    ctx->pc = 0x10129Cu;
    // 0x10129c: 0x3c020020
    ctx->pc = 0x10129cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x1012a0: 0x10000010
    ctx->pc = 0x1012A0u;
    {
        const bool branch_taken_0x1012a0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1012A4u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 30992), GPR_U32(ctx, 16));
        if (branch_taken_0x1012a0) {
            ctx->pc = 0x1012E4u;
            goto label_1012e4;
        }
    }
    ctx->pc = 0x1012A8u;
label_1012a8:
    // 0x1012a8: 0x24a200ff
    ctx->pc = 0x1012a8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 5), 255));
    // 0x1012ac: 0xc5182a
    ctx->pc = 0x1012acu;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 6), GPR_S32(ctx, 5)));
    // 0x1012b0: 0xa3100b
    ctx->pc = 0x1012b0u;
    if (GPR_U32(ctx, 3) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 5));
    // 0x1012b4: 0x21203
    ctx->pc = 0x1012b4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1012b8: 0x28420002
    ctx->pc = 0x1012b8u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 2));
    // 0x1012bc: 0x54400009
    ctx->pc = 0x1012BCu;
    {
        const bool branch_taken_0x1012bc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1012bc) {
            ctx->pc = 0x1012C0u;
            SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
            ctx->pc = 0x1012E4u;
            goto label_1012e4;
        }
    }
    ctx->pc = 0x1012C4u;
    // 0x1012c4: 0xc4182a
    ctx->pc = 0x1012c4u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 6), GPR_S32(ctx, 4)));
    // 0x1012c8: 0x248200ff
    ctx->pc = 0x1012c8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 255));
    // 0x1012cc: 0x83100b
    ctx->pc = 0x1012ccu;
    if (GPR_U32(ctx, 3) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 4));
    // 0x1012d0: 0x21203
    ctx->pc = 0x1012d0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1012d4: 0x28420002
    ctx->pc = 0x1012d4u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 2));
    // 0x1012d8: 0x10400003
    ctx->pc = 0x1012D8u;
    {
        const bool branch_taken_0x1012d8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1012DCu;
        SET_GPR_U32(ctx, 4, ((uint32_t)32 << 16));
        if (branch_taken_0x1012d8) {
            ctx->pc = 0x1012E8u;
            goto label_1012e8;
        }
    }
    ctx->pc = 0x1012E0u;
    // 0x1012e0: 0x24100002
    ctx->pc = 0x1012e0u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
label_1012e4:
    // 0x1012e4: 0x3c040020
    ctx->pc = 0x1012e4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32 << 16));
label_1012e8:
    // 0x1012e8: 0xac807924
    ctx->pc = 0x1012e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 31012), GPR_U32(ctx, 0));
    // 0x1012ec: 0x6600015
    ctx->pc = 0x1012ECu;
    {
        const bool branch_taken_0x1012ec = (GPR_S32(ctx, 19) < 0);
        ctx->pc = 0x1012F0u;
        SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 19), 2));
        if (branch_taken_0x1012ec) {
            ctx->pc = 0x101344u;
            goto label_101344;
        }
    }
    ctx->pc = 0x1012F4u;
    // 0x1012f4: 0x14400013
    ctx->pc = 0x1012F4u;
    {
        const bool branch_taken_0x1012f4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1012F8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 5));
        if (branch_taken_0x1012f4) {
            ctx->pc = 0x101344u;
            goto label_101344;
        }
    }
    ctx->pc = 0x1012FCu;
    // 0x1012fc: 0x16620011
    ctx->pc = 0x1012FCu;
    {
        const bool branch_taken_0x1012fc = (GPR_U32(ctx, 19) != GPR_U32(ctx, 2));
        ctx->pc = 0x101300u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x1012fc) {
            ctx->pc = 0x101344u;
            goto label_101344;
        }
    }
    ctx->pc = 0x101304u;
    // 0x101304: 0x8c437910
    ctx->pc = 0x101304u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x101308: 0x18600003
    ctx->pc = 0x101308u;
    {
        const bool branch_taken_0x101308 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x10130Cu;
        SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
        if (branch_taken_0x101308) {
            ctx->pc = 0x101318u;
            goto label_101318;
        }
    }
    ctx->pc = 0x101310u;
    // 0x101310: 0xc045a12
    ctx->pc = 0x101310u;
    SET_GPR_U32(ctx, 31, 0x101318u);
    ctx->pc = 0x101314u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 30168));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101318u; }
    }
    if (ctx->pc != 0x101318u) { return; }
    ctx->pc = 0x101318u;
label_101318:
    // 0x101318: 0xc040192
    ctx->pc = 0x101318u;
    SET_GPR_U32(ctx, 31, 0x101320u);
    ctx->pc = 0x100648u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100648_0x100648(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101320u; }
    }
    if (ctx->pc != 0x101320u) { return; }
    ctx->pc = 0x101320u;
    // 0x101320: 0x2404ffff
    ctx->pc = 0x101320u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x101324: 0x3c020020
    ctx->pc = 0x101324u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x101328: 0xac447928
    ctx->pc = 0x101328u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31016), GPR_U32(ctx, 4));
    // 0x10132c: 0x3c030020
    ctx->pc = 0x10132cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
    // 0x101330: 0xac64792c
    ctx->pc = 0x101330u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 31020), GPR_U32(ctx, 4));
    // 0x101334: 0x3c020020
    ctx->pc = 0x101334u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x101338: 0xac447920
    ctx->pc = 0x101338u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31008), GPR_U32(ctx, 4));
    // 0x10133c: 0x10000006
    ctx->pc = 0x10133Cu;
    {
        const bool branch_taken_0x10133c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x101340u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x10133c) {
            ctx->pc = 0x101358u;
            goto label_101358;
        }
    }
    ctx->pc = 0x101344u;
label_101344:
    // 0x101344: 0xc040164
    ctx->pc = 0x101344u;
    SET_GPR_U32(ctx, 31, 0x10134Cu);
    ctx->pc = 0x100590u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10134Cu; }
    }
    if (ctx->pc != 0x10134Cu) { return; }
    ctx->pc = 0x10134Cu;
    // 0x10134c: 0xc0401f0
    ctx->pc = 0x10134Cu;
    SET_GPR_U32(ctx, 31, 0x101354u);
    ctx->pc = 0x1007C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001007C0_0x1007c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101354u; }
    }
    if (ctx->pc != 0x101354u) { return; }
    ctx->pc = 0x101354u;
    // 0x101354: 0x200102d
    ctx->pc = 0x101354u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101358:
    // 0x101358: 0xdfbf00a0
    ctx->pc = 0x101358u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x10135c: 0xdfbe0090
    ctx->pc = 0x10135cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x101360: 0xdfb70080
    ctx->pc = 0x101360u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x101364: 0xdfb60070
    ctx->pc = 0x101364u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x101368: 0xdfb50060
    ctx->pc = 0x101368u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x10136c: 0xdfb40050
    ctx->pc = 0x10136cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x101370: 0xdfb30040
    ctx->pc = 0x101370u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x101374: 0xdfb20030
    ctx->pc = 0x101374u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101378: 0xdfb10020
    ctx->pc = 0x101378u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10137c: 0xdfb00010
    ctx->pc = 0x10137cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101380: 0x3e00008
    ctx->pc = 0x101380u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101384u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 176));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101170u: goto label_101170;
            case 0x1011A4u: goto label_1011a4;
            case 0x1011B0u: goto label_1011b0;
            case 0x1011D4u: goto label_1011d4;
            case 0x10122Cu: goto label_10122c;
            case 0x101238u: goto label_101238;
            case 0x10125Cu: goto label_10125c;
            case 0x1012A8u: goto label_1012a8;
            case 0x1012E4u: goto label_1012e4;
            case 0x1012E8u: goto label_1012e8;
            case 0x101318u: goto label_101318;
            case 0x101344u: goto label_101344;
            case 0x101358u: goto label_101358;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101388u;
}
