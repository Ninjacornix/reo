#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001D5130
// Address: 0x1d5130 - 0x1d53f0
void sub_001D5130_0x1d5130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1d5130u;

    // 0x1d5130: 0x27bdff00
    ctx->pc = 0x1d5130u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967040));
    // 0x1d5134: 0xffb200e0
    ctx->pc = 0x1d5134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 224), GPR_U64(ctx, 18));
    // 0x1d5138: 0x80902d
    ctx->pc = 0x1d5138u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d513c: 0xffb100d0
    ctx->pc = 0x1d513cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 17));
    // 0x1d5140: 0xffb000c0
    ctx->pc = 0x1d5140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 16));
    // 0x1d5144: 0xffbf00f0
    ctx->pc = 0x1d5144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 240), GPR_U64(ctx, 31));
    // 0x1d5148: 0xc045c20
    ctx->pc = 0x1D5148u;
    SET_GPR_U32(ctx, 31, 0x1D5150u);
    ctx->pc = 0x1D514Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5150u; }
    }
    if (ctx->pc != 0x1D5150u) { return; }
    ctx->pc = 0x1D5150u;
    // 0x1d5150: 0x1000000c
    ctx->pc = 0x1D5150u;
    {
        const bool branch_taken_0x1d5150 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D5154u;
        SET_GPR_U32(ctx, 17, ((uint32_t)52 << 16));
        if (branch_taken_0x1d5150) {
            ctx->pc = 0x1D5184u;
            goto label_1d5184;
        }
    }
    ctx->pc = 0x1D5158u;
label_1d5158:
    // 0x1d5158: 0x3c02ffff
    ctx->pc = 0x1d5158u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65535 << 16));
    // 0x1d515c: 0x3c060001
    ctx->pc = 0x1d515cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)1 << 16));
    // 0x1d5160: 0x3442ffff
    ctx->pc = 0x1d5160u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x1d5164: 0x0
    ctx->pc = 0x1d5164u;
    // NOP
label_1d5168:
    // 0x1d5168: 0x24c6ffff
    ctx->pc = 0x1d5168u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1d516c: 0x0
    ctx->pc = 0x1d516cu;
    // NOP
    // 0x1d5170: 0x0
    ctx->pc = 0x1d5170u;
    // NOP
    // 0x1d5174: 0x0
    ctx->pc = 0x1d5174u;
    // NOP
    // 0x1d5178: 0x0
    ctx->pc = 0x1d5178u;
    // NOP
    // 0x1d517c: 0x14c2fffa
    ctx->pc = 0x1D517Cu;
    {
        const bool branch_taken_0x1d517c = (GPR_U32(ctx, 6) != GPR_U32(ctx, 2));
        if (branch_taken_0x1d517c) {
            ctx->pc = 0x1D5168u;
            goto label_1d5168;
        }
    }
    ctx->pc = 0x1D5184u;
label_1d5184:
    // 0x1d5184: 0x263028e0
    ctx->pc = 0x1d5184u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 17), 10464));
    // 0x1d5188: 0x3c058000
    ctx->pc = 0x1d5188u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x1d518c: 0x200202d
    ctx->pc = 0x1d518cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5190: 0x34a50211
    ctx->pc = 0x1d5190u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 529));
    // 0x1d5194: 0xc045e06
    ctx->pc = 0x1D5194u;
    SET_GPR_U32(ctx, 31, 0x1D519Cu);
    ctx->pc = 0x1D5198u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117818u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D519Cu; }
    }
    if (ctx->pc != 0x1D519Cu) { return; }
    ctx->pc = 0x1D519Cu;
    // 0x1d519c: 0x4400055
    ctx->pc = 0x1D519Cu;
    {
        const bool branch_taken_0x1d519c = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x1D51A0u;
        SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
        if (branch_taken_0x1d519c) {
            ctx->pc = 0x1D52F4u;
            goto label_1d52f4;
        }
    }
    ctx->pc = 0x1D51A4u;
    // 0x1d51a4: 0x8e020024
    ctx->pc = 0x1d51a4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1d51a8: 0x1040ffeb
    ctx->pc = 0x1D51A8u;
    {
        const bool branch_taken_0x1d51a8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D51ACu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1d51a8) {
            ctx->pc = 0x1D5158u;
            goto label_1d5158;
        }
    }
    ctx->pc = 0x1D51B0u;
    // 0x1d51b0: 0x27a40090
    ctx->pc = 0x1d51b0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 144));
    // 0x1d51b4: 0xafa20094
    ctx->pc = 0x1d51b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 148), GPR_U32(ctx, 2));
    // 0x1d51b8: 0x3c110023
    ctx->pc = 0x1d51b8u;
    SET_GPR_U32(ctx, 17, ((uint32_t)35 << 16));
    // 0x1d51bc: 0xafa20098
    ctx->pc = 0x1d51bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 152), GPR_U32(ctx, 2));
    // 0x1d51c0: 0xc045188
    ctx->pc = 0x1D51C0u;
    SET_GPR_U32(ctx, 31, 0x1D51C8u);
    ctx->pc = 0x1D51C4u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x114620u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51C8u; }
    }
    if (ctx->pc != 0x1D51C8u) { return; }
    ctx->pc = 0x1D51C8u;
    // 0x1d51c8: 0x14500006
    ctx->pc = 0x1D51C8u;
    {
        const bool branch_taken_0x1d51c8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 16));
        ctx->pc = 0x1D51CCu;
        WRITE32(ADD32(GPR_U32(ctx, 17), 27032), GPR_U32(ctx, 2));
        if (branch_taken_0x1d51c8) {
            ctx->pc = 0x1D51E4u;
            goto label_1d51e4;
        }
    }
    ctx->pc = 0x1D51D0u;
    // 0x1d51d0: 0x3c040025
    ctx->pc = 0x1d51d0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1d51d4: 0xc045a12
    ctx->pc = 0x1D51D4u;
    SET_GPR_U32(ctx, 31, 0x1D51DCu);
    ctx->pc = 0x1D51D8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 28136));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51DCu; }
    }
    if (ctx->pc != 0x1D51DCu) { return; }
    ctx->pc = 0x1D51DCu;
    // 0x1d51dc: 0x1000004c
    ctx->pc = 0x1D51DCu;
    {
        const bool branch_taken_0x1d51dc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D51E0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1d51dc) {
            ctx->pc = 0x1D5310u;
            goto label_1d5310;
        }
    }
    ctx->pc = 0x1D51E4u;
label_1d51e4:
    // 0x1d51e4: 0xc0754fc
    ctx->pc = 0x1D51E4u;
    SET_GPR_U32(ctx, 31, 0x1D51ECu);
    ctx->pc = 0x1D51E8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1D53F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001D53F0_0x1d53f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51ECu; }
    }
    if (ctx->pc != 0x1D51ECu) { return; }
    ctx->pc = 0x1D51ECu;
    // 0x1d51ec: 0x14400011
    ctx->pc = 0x1D51ECu;
    {
        const bool branch_taken_0x1d51ec = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D51F0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d51ec) {
            ctx->pc = 0x1D5234u;
            goto label_1d5234;
        }
    }
    ctx->pc = 0x1D51F4u;
    // 0x1d51f4: 0xc075646
    ctx->pc = 0x1D51F4u;
    SET_GPR_U32(ctx, 31, 0x1D51FCu);
    ctx->pc = 0x1D51F8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 176));
    ctx->pc = 0x1D5918u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5918_0x1d5918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51FCu; }
    }
    if (ctx->pc != 0x1D51FCu) { return; }
    ctx->pc = 0x1D51FCu;
    // 0x1d51fc: 0x8fa300b0
    ctx->pc = 0x1d51fcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1d5200: 0x1460000c
    ctx->pc = 0x1D5200u;
    {
        const bool branch_taken_0x1d5200 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D5204u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x1d5200) {
            ctx->pc = 0x1D5234u;
            goto label_1d5234;
        }
    }
    ctx->pc = 0x1D5208u;
    // 0x1d5208: 0x1880000a
    ctx->pc = 0x1D5208u;
    {
        const bool branch_taken_0x1d5208 = (GPR_S32(ctx, 4) <= 0);
        ctx->pc = 0x1D520Cu;
        SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 4), 128));
        if (branch_taken_0x1d5208) {
            ctx->pc = 0x1D5234u;
            goto label_1d5234;
        }
    }
    ctx->pc = 0x1D5210u;
    // 0x1d5210: 0x10400008
    ctx->pc = 0x1D5210u;
    {
        const bool branch_taken_0x1d5210 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D5214u;
        SET_GPR_U32(ctx, 7, ((uint32_t)52 << 16));
        if (branch_taken_0x1d5210) {
            ctx->pc = 0x1D5234u;
            goto label_1d5234;
        }
    }
    ctx->pc = 0x1D5218u;
    // 0x1d5218: 0x3c020034
    ctx->pc = 0x1d5218u;
    SET_GPR_U32(ctx, 2, ((uint32_t)52 << 16));
    // 0x1d521c: 0x24422a10
    ctx->pc = 0x1d521cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 10768));
    // 0x1d5220: 0x24e32840
    ctx->pc = 0x1d5220u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 7), 10304));
    // 0x1d5224: 0xace42840
    ctx->pc = 0x1d5224u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 10304), GPR_U32(ctx, 4));
    // 0x1d5228: 0xae440000
    ctx->pc = 0x1d5228u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x1d522c: 0x14400006
    ctx->pc = 0x1D522Cu;
    {
        const bool branch_taken_0x1d522c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D5230u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
        if (branch_taken_0x1d522c) {
            ctx->pc = 0x1D5248u;
            goto label_1d5248;
        }
    }
    ctx->pc = 0x1D5234u;
label_1d5234:
    // 0x1d5234: 0xc04518c
    ctx->pc = 0x1D5234u;
    SET_GPR_U32(ctx, 31, 0x1D523Cu);
    ctx->pc = 0x1D5238u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 27032)));
    ctx->pc = 0x114630u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D523Cu; }
    }
    if (ctx->pc != 0x1D523Cu) { return; }
    ctx->pc = 0x1D523Cu;
    // 0x1d523c: 0xae306998
    ctx->pc = 0x1d523cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 27032), GPR_U32(ctx, 16));
    // 0x1d5240: 0x10000033
    ctx->pc = 0x1D5240u;
    {
        const bool branch_taken_0x1d5240 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D5244u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1d5240) {
            ctx->pc = 0x1D5310u;
            goto label_1d5310;
        }
    }
    ctx->pc = 0x1D5248u;
label_1d5248:
    // 0x1d5248: 0x1080001b
    ctx->pc = 0x1D5248u;
    {
        const bool branch_taken_0x1d5248 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D524Cu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d5248) {
            ctx->pc = 0x1D52B8u;
            goto label_1d52b8;
        }
    }
    ctx->pc = 0x1D5250u;
    // 0x1d5250: 0x3c08001d
    ctx->pc = 0x1d5250u;
    SET_GPR_U32(ctx, 8, ((uint32_t)29 << 16));
    // 0x1d5254: 0x24030038
    ctx->pc = 0x1d5254u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 56));
label_1d5258:
    // 0x1d5258: 0x24e22840
    ctx->pc = 0x1d5258u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 7), 10304));
    // 0x1d525c: 0xc31818
    ctx->pc = 0x1d525cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
    // 0x1d5260: 0x8c450004
    ctx->pc = 0x1d5260u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1d5264: 0x24040001
    ctx->pc = 0x1d5264u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5268: 0x24c60001
    ctx->pc = 0x1d5268u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
    // 0x1d526c: 0x651821
    ctx->pc = 0x1d526cu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1d5270: 0xac640008
    ctx->pc = 0x1d5270u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 4));
    // 0x1d5274: 0xac600034
    ctx->pc = 0x1d5274u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 52), GPR_U32(ctx, 0));
    // 0x1d5278: 0xac640000
    ctx->pc = 0x1d5278u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1d527c: 0xac640004
    ctx->pc = 0x1d527cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
    // 0x1d5280: 0xac60000c
    ctx->pc = 0x1d5280u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x1d5284: 0xac600010
    ctx->pc = 0x1d5284u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
    // 0x1d5288: 0xac600014
    ctx->pc = 0x1d5288u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 0));
    // 0x1d528c: 0xac600018
    ctx->pc = 0x1d528cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 24), GPR_U32(ctx, 0));
    // 0x1d5290: 0xac60001c
    ctx->pc = 0x1d5290u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 28), GPR_U32(ctx, 0));
    // 0x1d5294: 0xac60002c
    ctx->pc = 0x1d5294u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 44), GPR_U32(ctx, 0));
    // 0x1d5298: 0xac600030
    ctx->pc = 0x1d5298u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 48), GPR_U32(ctx, 0));
    // 0x1d529c: 0xa4600020
    ctx->pc = 0x1d529cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 32), (uint16_t)GPR_U32(ctx, 0));
    // 0x1d52a0: 0x8fa20000
    ctx->pc = 0x1d52a0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d52a4: 0xc2102b
    ctx->pc = 0x1d52a4u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1d52a8: 0x1440ffeb
    ctx->pc = 0x1D52A8u;
    {
        const bool branch_taken_0x1d52a8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D52ACu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 56));
        if (branch_taken_0x1d52a8) {
            ctx->pc = 0x1D5258u;
            goto label_1d5258;
        }
    }
    ctx->pc = 0x1D52B0u;
    // 0x1d52b0: 0x10000003
    ctx->pc = 0x1D52B0u;
    {
        const bool branch_taken_0x1d52b0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D52B4u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 7), 10304));
        if (branch_taken_0x1d52b0) {
            ctx->pc = 0x1D52C0u;
            goto label_1d52c0;
        }
    }
    ctx->pc = 0x1D52B8u;
label_1d52b8:
    // 0x1d52b8: 0x3c08001d
    ctx->pc = 0x1d52b8u;
    SET_GPR_U32(ctx, 8, ((uint32_t)29 << 16));
    // 0x1d52bc: 0x24f02840
    ctx->pc = 0x1d52bcu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 7), 10304));
label_1d52c0:
    // 0x1d52c0: 0x25056090
    ctx->pc = 0x1d52c0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 8), 24720));
    // 0x1d52c4: 0xae000010
    ctx->pc = 0x1d52c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x1d52c8: 0x24040003
    ctx->pc = 0x1d52c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d52cc: 0xc0450c0
    ctx->pc = 0x1D52CCu;
    SET_GPR_U32(ctx, 31, 0x1D52D4u);
    ctx->pc = 0x1D52D0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x114300u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114300_0x114300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D52D4u; }
    }
    if (ctx->pc != 0x1D52D4u) { return; }
    ctx->pc = 0x1D52D4u;
    // 0x1d52d4: 0x441000b
    ctx->pc = 0x1D52D4u;
    {
        const bool branch_taken_0x1d52d4 = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x1D52D8u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 156), GPR_U32(ctx, 2));
        if (branch_taken_0x1d52d4) {
            ctx->pc = 0x1D5304u;
            goto label_1d5304;
        }
    }
    ctx->pc = 0x1D52DCu;
    // 0x1d52dc: 0xc04518c
    ctx->pc = 0x1D52DCu;
    SET_GPR_U32(ctx, 31, 0x1D52E4u);
    ctx->pc = 0x1D52E0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 27032)));
    ctx->pc = 0x114630u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D52E4u; }
    }
    if (ctx->pc != 0x1D52E4u) { return; }
    ctx->pc = 0x1D52E4u;
    // 0x1d52e4: 0x2403ffff
    ctx->pc = 0x1d52e4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d52e8: 0x2402ffff
    ctx->pc = 0x1d52e8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d52ec: 0x10000008
    ctx->pc = 0x1D52ECu;
    {
        const bool branch_taken_0x1d52ec = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D52F0u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 27032), GPR_U32(ctx, 3));
        if (branch_taken_0x1d52ec) {
            ctx->pc = 0x1D5310u;
            goto label_1d5310;
        }
    }
    ctx->pc = 0x1D52F4u;
label_1d52f4:
    // 0x1d52f4: 0xc045a12
    ctx->pc = 0x1D52F4u;
    SET_GPR_U32(ctx, 31, 0x1D52FCu);
    ctx->pc = 0x1D52F8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 28112));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D52FCu; }
    }
    if (ctx->pc != 0x1D52FCu) { return; }
    ctx->pc = 0x1D52FCu;
    // 0x1d52fc: 0x10000004
    ctx->pc = 0x1D52FCu;
    {
        const bool branch_taken_0x1d52fc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D5300u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1d52fc) {
            ctx->pc = 0x1D5310u;
            goto label_1d5310;
        }
    }
    ctx->pc = 0x1D5304u;
label_1d5304:
    // 0x1d5304: 0xc04545a
    ctx->pc = 0x1D5304u;
    SET_GPR_U32(ctx, 31, 0x1D530Cu);
    ctx->pc = 0x1D5308u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x115168u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00115168_0x115168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D530Cu; }
    }
    if (ctx->pc != 0x1D530Cu) { return; }
    ctx->pc = 0x1D530Cu;
    // 0x1d530c: 0x102d
    ctx->pc = 0x1d530cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d5310:
    // 0x1d5310: 0xdfbf00f0
    ctx->pc = 0x1d5310u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x1d5314: 0xdfb200e0
    ctx->pc = 0x1d5314u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x1d5318: 0xdfb100d0
    ctx->pc = 0x1d5318u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x1d531c: 0xdfb000c0
    ctx->pc = 0x1d531cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1d5320: 0x3e00008
    ctx->pc = 0x1D5320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5324u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 256));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5158u: goto label_1d5158;
            case 0x1D5168u: goto label_1d5168;
            case 0x1D5184u: goto label_1d5184;
            case 0x1D51E4u: goto label_1d51e4;
            case 0x1D5234u: goto label_1d5234;
            case 0x1D5248u: goto label_1d5248;
            case 0x1D5258u: goto label_1d5258;
            case 0x1D52B8u: goto label_1d52b8;
            case 0x1D52C0u: goto label_1d52c0;
            case 0x1D52F4u: goto label_1d52f4;
            case 0x1D5304u: goto label_1d5304;
            case 0x1D5310u: goto label_1d5310;
            case 0x1D536Cu: goto label_1d536c;
            case 0x1D537Cu: goto label_1d537c;
            case 0x1D5398u: goto label_1d5398;
            case 0x1D53D0u: goto label_1d53d0;
            case 0x1D53D4u: goto label_1d53d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5328u;
    // 0x1d5328: 0x27bdffc0
    ctx->pc = 0x1d5328u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d532c: 0xffb20020
    ctx->pc = 0x1d532cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1d5330: 0xffb10010
    ctx->pc = 0x1d5330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1d5334: 0xffb00000
    ctx->pc = 0x1d5334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1d5338: 0xffbf0030
    ctx->pc = 0x1d5338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d533c: 0xc047598
    ctx->pc = 0x1D533Cu;
    SET_GPR_U32(ctx, 31, 0x1D5344u);
    ctx->pc = 0x1D5340u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5344u; }
    }
    if (ctx->pc != 0x1D5344u) { return; }
    ctx->pc = 0x1D5344u;
    // 0x1d5344: 0x40882d
    ctx->pc = 0x1d5344u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5348: 0x24040003
    ctx->pc = 0x1d5348u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d534c: 0x3c020034
    ctx->pc = 0x1d534cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)52 << 16));
    // 0x1d5350: 0xc0450c8
    ctx->pc = 0x1D5350u;
    SET_GPR_U32(ctx, 31, 0x1D5358u);
    ctx->pc = 0x1D5354u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 10460)));
    ctx->pc = 0x114320u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114320_0x114320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5358u; }
    }
    if (ctx->pc != 0x1D5358u) { return; }
    ctx->pc = 0x1D5358u;
    // 0x1d5358: 0x40802d
    ctx->pc = 0x1d5358u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d535c: 0x16000003
    ctx->pc = 0x1D535Cu;
    {
        const bool branch_taken_0x1d535c = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        if (branch_taken_0x1d535c) {
            ctx->pc = 0x1D536Cu;
            goto label_1d536c;
        }
    }
    ctx->pc = 0x1D5364u;
    // 0x1d5364: 0xc045440
    ctx->pc = 0x1D5364u;
    SET_GPR_U32(ctx, 31, 0x1D536Cu);
    ctx->pc = 0x1D5368u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x115100u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00115100_0x115100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D536Cu; }
    }
    if (ctx->pc != 0x1D536Cu) { return; }
    ctx->pc = 0x1D536Cu;
label_1d536c:
    // 0x1d536c: 0x12200003
    ctx->pc = 0x1D536Cu;
    {
        const bool branch_taken_0x1d536c = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d536c) {
            ctx->pc = 0x1D537Cu;
            goto label_1d537c;
        }
    }
    ctx->pc = 0x1D5374u;
    // 0x1d5374: 0xc0475ae
    ctx->pc = 0x1D5374u;
    SET_GPR_U32(ctx, 31, 0x1D537Cu);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D537Cu; }
    }
    if (ctx->pc != 0x1D537Cu) { return; }
    ctx->pc = 0x1D537Cu;
label_1d537c:
    // 0x1d537c: 0x6010006
    ctx->pc = 0x1D537Cu;
    {
        const bool branch_taken_0x1d537c = (GPR_S32(ctx, 16) >= 0);
        ctx->pc = 0x1D5380u;
        SET_GPR_U32(ctx, 17, ((uint32_t)35 << 16));
        if (branch_taken_0x1d537c) {
            ctx->pc = 0x1D5398u;
            goto label_1d5398;
        }
    }
    ctx->pc = 0x1D5384u;
    // 0x1d5384: 0x3c040025
    ctx->pc = 0x1d5384u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1d5388: 0x24120001
    ctx->pc = 0x1d5388u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d538c: 0xc045a12
    ctx->pc = 0x1D538Cu;
    SET_GPR_U32(ctx, 31, 0x1D5394u);
    ctx->pc = 0x1D5390u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 28168));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5394u; }
    }
    if (ctx->pc != 0x1D5394u) { return; }
    ctx->pc = 0x1D5394u;
    // 0x1d5394: 0x3c110023
    ctx->pc = 0x1d5394u;
    SET_GPR_U32(ctx, 17, ((uint32_t)35 << 16));
label_1d5398:
    // 0x1d5398: 0x2410ffff
    ctx->pc = 0x1d5398u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d539c: 0x8e246998
    ctx->pc = 0x1d539cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 27032)));
    // 0x1d53a0: 0x1090000c
    ctx->pc = 0x1D53A0u;
    {
        const bool branch_taken_0x1d53a0 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 16));
        ctx->pc = 0x1D53A4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1d53a0) {
            ctx->pc = 0x1D53D4u;
            goto label_1d53d4;
        }
    }
    ctx->pc = 0x1D53A8u;
    // 0x1d53a8: 0xc04518c
    ctx->pc = 0x1D53A8u;
    SET_GPR_U32(ctx, 31, 0x1D53B0u);
    ctx->pc = 0x114630u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53B0u; }
    }
    if (ctx->pc != 0x1D53B0u) { return; }
    ctx->pc = 0x1D53B0u;
    // 0x1d53b0: 0x4430007
    ctx->pc = 0x1D53B0u;
    {
        const bool branch_taken_0x1d53b0 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x1d53b0) {
            ctx->pc = 0x1D53B4u;
            WRITE32(ADD32(GPR_U32(ctx, 17), 27032), GPR_U32(ctx, 16));
            ctx->pc = 0x1D53D0u;
            goto label_1d53d0;
        }
    }
    ctx->pc = 0x1D53B8u;
    // 0x1d53b8: 0x3c040025
    ctx->pc = 0x1d53b8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1d53bc: 0x26520001
    ctx->pc = 0x1d53bcu;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
    // 0x1d53c0: 0xc045a12
    ctx->pc = 0x1D53C0u;
    SET_GPR_U32(ctx, 31, 0x1D53C8u);
    ctx->pc = 0x1D53C4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 28216));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53C8u; }
    }
    if (ctx->pc != 0x1D53C8u) { return; }
    ctx->pc = 0x1D53C8u;
    // 0x1d53c8: 0x10000002
    ctx->pc = 0x1D53C8u;
    {
        const bool branch_taken_0x1d53c8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D53CCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1d53c8) {
            ctx->pc = 0x1D53D4u;
            goto label_1d53d4;
        }
    }
    ctx->pc = 0x1D53D0u;
label_1d53d0:
    // 0x1d53d0: 0x2402ffff
    ctx->pc = 0x1d53d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1d53d4:
    // 0x1d53d4: 0xdfbf0030
    ctx->pc = 0x1d53d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d53d8: 0x12100a
    ctx->pc = 0x1d53d8u;
    if (GPR_U32(ctx, 18) == 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 0));
    // 0x1d53dc: 0xdfb10010
    ctx->pc = 0x1d53dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d53e0: 0xdfb20020
    ctx->pc = 0x1d53e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d53e4: 0xdfb00000
    ctx->pc = 0x1d53e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d53e8: 0x3e00008
    ctx->pc = 0x1D53E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D53ECu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5158u: goto label_1d5158;
            case 0x1D5168u: goto label_1d5168;
            case 0x1D5184u: goto label_1d5184;
            case 0x1D51E4u: goto label_1d51e4;
            case 0x1D5234u: goto label_1d5234;
            case 0x1D5248u: goto label_1d5248;
            case 0x1D5258u: goto label_1d5258;
            case 0x1D52B8u: goto label_1d52b8;
            case 0x1D52C0u: goto label_1d52c0;
            case 0x1D52F4u: goto label_1d52f4;
            case 0x1D5304u: goto label_1d5304;
            case 0x1D5310u: goto label_1d5310;
            case 0x1D536Cu: goto label_1d536c;
            case 0x1D537Cu: goto label_1d537c;
            case 0x1D5398u: goto label_1d5398;
            case 0x1D53D0u: goto label_1d53d0;
            case 0x1D53D4u: goto label_1d53d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D53F0u;
}
