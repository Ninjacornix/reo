#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017CEA0
// Address: 0x17cea0 - 0x17d078
void sub_0017CEA0_0x17cea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17cea0u;

    // 0x17cea0: 0x27bdfff0
    ctx->pc = 0x17cea0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17cea4: 0x282d
    ctx->pc = 0x17cea4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cea8: 0xffb00000
    ctx->pc = 0x17cea8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ceac: 0x3c100023
    ctx->pc = 0x17ceacu;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
    // 0x17ceb0: 0x2610f2a0
    ctx->pc = 0x17ceb0u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294963872));
    // 0x17ceb4: 0x240604a8
    ctx->pc = 0x17ceb4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1192));
    // 0x17ceb8: 0xffbf0008
    ctx->pc = 0x17ceb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17cebc: 0xc041f1a
    ctx->pc = 0x17CEBCu;
    SET_GPR_U32(ctx, 31, 0x17CEC4u);
    ctx->pc = 0x17CEC0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CEC4u; }
    }
    if (ctx->pc != 0x17CEC4u) { return; }
    ctx->pc = 0x17CEC4u;
    // 0x17cec4: 0x24030008
    ctx->pc = 0x17cec4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
    // 0x17cec8: 0x0
    ctx->pc = 0x17cec8u;
    // NOP
    // 0x17cecc: 0xc05f482
    ctx->pc = 0x17CECCu;
    SET_GPR_U32(ctx, 31, 0x17CED4u);
    ctx->pc = 0x17CED0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x17D208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D208_0x17d208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CED4u; }
    }
    if (ctx->pc != 0x17CED4u) { return; }
    ctx->pc = 0x17CED4u;
    // 0x17ced4: 0xc052472
    ctx->pc = 0x17CED4u;
    SET_GPR_U32(ctx, 31, 0x17CEDCu);
    ctx->pc = 0x1491C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001491C8_0x1491c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CEDCu; }
    }
    if (ctx->pc != 0x17CEDCu) { return; }
    ctx->pc = 0x17CEDCu;
    // 0x17cedc: 0xdfb00000
    ctx->pc = 0x17cedcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cee0: 0xdfbf0008
    ctx->pc = 0x17cee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cee4: 0x8052498
    ctx->pc = 0x17CEE4u;
    ctx->pc = 0x17CEE8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x149260u;
    entry_149260_0x149268(rdram, ctx, runtime); return;
    ctx->pc = 0x17CEECu;
    // 0x17ceec: 0x0
    ctx->pc = 0x17ceecu;
    // NOP
    // 0x17cef0: 0x27bdfff0
    ctx->pc = 0x17cef0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17cef4: 0x3c020023
    ctx->pc = 0x17cef4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x17cef8: 0xffb00000
    ctx->pc = 0x17cef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17cefc: 0x2450f298
    ctx->pc = 0x17cefcu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294963864));
    // 0x17cf00: 0x8e030000
    ctx->pc = 0x17cf00u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17cf04: 0x1860000c
    ctx->pc = 0x17CF04u;
    {
        const bool branch_taken_0x17cf04 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x17CF08u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        if (branch_taken_0x17cf04) {
            ctx->pc = 0x17CF38u;
            goto label_17cf38;
        }
    }
    ctx->pc = 0x17CF0Cu;
    // 0x17cf0c: 0xc05f5d0
    ctx->pc = 0x17CF0Cu;
    SET_GPR_U32(ctx, 31, 0x17CF14u);
    ctx->pc = 0x17D740u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D740_0x17d740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF14u; }
    }
    if (ctx->pc != 0x17CF14u) { return; }
    ctx->pc = 0x17CF14u;
    // 0x17cf14: 0xc05e99e
    ctx->pc = 0x17CF14u;
    SET_GPR_U32(ctx, 31, 0x17CF1Cu);
    ctx->pc = 0x17A678u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A678_0x17a678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF1Cu; }
    }
    if (ctx->pc != 0x17CF1Cu) { return; }
    ctx->pc = 0x17CF1Cu;
    // 0x17cf1c: 0xc05f594
    ctx->pc = 0x17CF1Cu;
    SET_GPR_U32(ctx, 31, 0x17CF24u);
    ctx->pc = 0x17D650u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D650_0x17d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF24u; }
    }
    if (ctx->pc != 0x17CF24u) { return; }
    ctx->pc = 0x17CF24u;
    // 0x17cf24: 0xc052480
    ctx->pc = 0x17CF24u;
    SET_GPR_U32(ctx, 31, 0x17CF2Cu);
    ctx->pc = 0x149200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00149200_0x149200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF2Cu; }
    }
    if (ctx->pc != 0x17CF2Cu) { return; }
    ctx->pc = 0x17CF2Cu;
    // 0x17cf2c: 0x8e020000
    ctx->pc = 0x17cf2cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17cf30: 0x2442ffff
    ctx->pc = 0x17cf30u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x17cf34: 0xae020000
    ctx->pc = 0x17cf34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_17cf38:
    // 0x17cf38: 0xdfb00000
    ctx->pc = 0x17cf38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cf3c: 0xdfbf0008
    ctx->pc = 0x17cf3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cf40: 0x3e00008
    ctx->pc = 0x17CF40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CF44u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CF38u: goto label_17cf38;
            case 0x17CFD8u: goto label_17cfd8;
            case 0x17D024u: goto label_17d024;
            case 0x17D040u: goto label_17d040;
            case 0x17D054u: goto label_17d054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CF48u;
    // 0x17cf48: 0x3c020023
    ctx->pc = 0x17cf48u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x17cf4c: 0x2442f2a8
    ctx->pc = 0x17cf4cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294963880));
    // 0x17cf50: 0xac450004
    ctx->pc = 0x17cf50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x17cf54: 0x3e00008
    ctx->pc = 0x17CF54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CF58u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CF38u: goto label_17cf38;
            case 0x17CFD8u: goto label_17cfd8;
            case 0x17D024u: goto label_17d024;
            case 0x17D040u: goto label_17d040;
            case 0x17D054u: goto label_17d054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CF5Cu;
    // 0x17cf5c: 0x0
    ctx->pc = 0x17cf5cu;
    // NOP
    // 0x17cf60: 0x27bdffd0
    ctx->pc = 0x17cf60u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17cf64: 0xffb00000
    ctx->pc = 0x17cf64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17cf68: 0xc0802d
    ctx->pc = 0x17cf68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf6c: 0xffb10008
    ctx->pc = 0x17cf6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17cf70: 0xe0882d
    ctx->pc = 0x17cf70u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf74: 0xffb20010
    ctx->pc = 0x17cf74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17cf78: 0xffb30018
    ctx->pc = 0x17cf78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17cf7c: 0xa0982d
    ctx->pc = 0x17cf7cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf80: 0xffb40020
    ctx->pc = 0x17cf80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x17cf84: 0xffbf0028
    ctx->pc = 0x17cf84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x17cf88: 0xc05f41e
    ctx->pc = 0x17CF88u;
    SET_GPR_U32(ctx, 31, 0x17CF90u);
    ctx->pc = 0x17CF8Cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x17D078u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D078_0x17d078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF90u; }
    }
    if (ctx->pc != 0x17CF90u) { return; }
    ctx->pc = 0x17CF90u;
    // 0x17cf90: 0x40902d
    ctx->pc = 0x17cf90u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf94: 0x260202d
    ctx->pc = 0x17cf94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf98: 0x200282d
    ctx->pc = 0x17cf98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf9c: 0x1240002d
    ctx->pc = 0x17CF9Cu;
    {
        const bool branch_taken_0x17cf9c = (GPR_U32(ctx, 18) == GPR_U32(ctx, 0));
        ctx->pc = 0x17CFA0u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17cf9c) {
            ctx->pc = 0x17D054u;
            goto label_17d054;
        }
    }
    ctx->pc = 0x17CFA4u;
    // 0x17cfa4: 0xc05f45a
    ctx->pc = 0x17CFA4u;
    SET_GPR_U32(ctx, 31, 0x17CFACu);
    ctx->pc = 0x17D168u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D168_0x17d168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFACu; }
    }
    if (ctx->pc != 0x17CFACu) { return; }
    ctx->pc = 0x17CFACu;
    // 0x17cfac: 0x24030001
    ctx->pc = 0x17cfacu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x17cfb0: 0x202d
    ctx->pc = 0x17cfb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cfb4: 0x280282d
    ctx->pc = 0x17cfb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cfb8: 0x10430007
    ctx->pc = 0x17CFB8u;
    {
        const bool branch_taken_0x17cfb8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x17CFBCu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17cfb8) {
            ctx->pc = 0x17CFD8u;
            goto label_17cfd8;
        }
    }
    ctx->pc = 0x17CFC0u;
    // 0x17cfc0: 0x3c060024
    ctx->pc = 0x17cfc0u;
    SET_GPR_U32(ctx, 6, ((uint32_t)36 << 16));
    // 0x17cfc4: 0x282d
    ctx->pc = 0x17cfc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cfc8: 0xc05f472
    ctx->pc = 0x17CFC8u;
    SET_GPR_U32(ctx, 31, 0x17CFD0u);
    ctx->pc = 0x17CFCCu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 5064));
    ctx->pc = 0x17D1C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFD0u; }
    }
    if (ctx->pc != 0x17CFD0u) { return; }
    ctx->pc = 0x17CFD0u;
    // 0x17cfd0: 0x10000020
    ctx->pc = 0x17CFD0u;
    {
        const bool branch_taken_0x17cfd0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x17CFD4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17cfd0) {
            ctx->pc = 0x17D054u;
            goto label_17d054;
        }
    }
    ctx->pc = 0x17CFD8u;
label_17cfd8:
    // 0x17cfd8: 0xc05f432
    ctx->pc = 0x17CFD8u;
    SET_GPR_U32(ctx, 31, 0x17CFE0u);
    ctx->pc = 0x17CFDCu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x17D0C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D0C8_0x17d0c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFE0u; }
    }
    if (ctx->pc != 0x17CFE0u) { return; }
    ctx->pc = 0x17CFE0u;
    // 0x17cfe0: 0xc05f5d2
    ctx->pc = 0x17CFE0u;
    SET_GPR_U32(ctx, 31, 0x17CFE8u);
    ctx->pc = 0x17D748u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D748_0x17d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFE8u; }
    }
    if (ctx->pc != 0x17CFE8u) { return; }
    ctx->pc = 0x17CFE8u;
    // 0x17cfe8: 0x3c060024
    ctx->pc = 0x17cfe8u;
    SET_GPR_U32(ctx, 6, ((uint32_t)36 << 16));
    // 0x17cfec: 0x282d
    ctx->pc = 0x17cfecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cff0: 0x24c613f8
    ctx->pc = 0x17cff0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 5112));
    // 0x17cff4: 0x1040000b
    ctx->pc = 0x17CFF4u;
    {
        const bool branch_taken_0x17cff4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x17CFF8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17cff4) {
            ctx->pc = 0x17D024u;
            goto label_17d024;
        }
    }
    ctx->pc = 0x17CFFCu;
    // 0x17cffc: 0xc05e9a0
    ctx->pc = 0x17CFFCu;
    SET_GPR_U32(ctx, 31, 0x17D004u);
    ctx->pc = 0x17D000u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 2));
    ctx->pc = 0x17A680u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A680_0x17a680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D004u; }
    }
    if (ctx->pc != 0x17D004u) { return; }
    ctx->pc = 0x17D004u;
    // 0x17d004: 0x3c060024
    ctx->pc = 0x17d004u;
    SET_GPR_U32(ctx, 6, ((uint32_t)36 << 16));
    // 0x17d008: 0x40382d
    ctx->pc = 0x17d008u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d00c: 0x3c020023
    ctx->pc = 0x17d00cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x17d010: 0x2448f2a0
    ctx->pc = 0x17d010u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 2), 4294963872));
    // 0x17d014: 0x24c61418
    ctx->pc = 0x17d014u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 5144));
    // 0x17d018: 0x282d
    ctx->pc = 0x17d018u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d01c: 0x14e00008
    ctx->pc = 0x17D01Cu;
    {
        const bool branch_taken_0x17d01c = (GPR_U32(ctx, 7) != GPR_U32(ctx, 0));
        ctx->pc = 0x17D020u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17d01c) {
            ctx->pc = 0x17D040u;
            goto label_17d040;
        }
    }
    ctx->pc = 0x17D024u;
label_17d024:
    // 0x17d024: 0xc05f472
    ctx->pc = 0x17D024u;
    SET_GPR_U32(ctx, 31, 0x17D02Cu);
    ctx->pc = 0x17D1C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D02Cu; }
    }
    if (ctx->pc != 0x17D02Cu) { return; }
    ctx->pc = 0x17D02Cu;
    // 0x17d02c: 0xc05f45e
    ctx->pc = 0x17D02Cu;
    SET_GPR_U32(ctx, 31, 0x17D034u);
    ctx->pc = 0x17D030u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x17D178u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D178_0x17d178(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D034u; }
    }
    if (ctx->pc != 0x17D034u) { return; }
    ctx->pc = 0x17D034u;
    // 0x17d034: 0x10000007
    ctx->pc = 0x17D034u;
    {
        const bool branch_taken_0x17d034 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x17D038u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17d034) {
            ctx->pc = 0x17D054u;
            goto label_17d054;
        }
    }
    ctx->pc = 0x17D03Cu;
    // 0x17d03c: 0x0
    ctx->pc = 0x17d03cu;
    // NOP
label_17d040:
    // 0x17d040: 0x8d030000
    ctx->pc = 0x17d040u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x17d044: 0x240102d
    ctx->pc = 0x17d044u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d048: 0xae470030
    ctx->pc = 0x17d048u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 7));
    // 0x17d04c: 0x24630001
    ctx->pc = 0x17d04cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1));
    // 0x17d050: 0xad030000
    ctx->pc = 0x17d050u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 3));
label_17d054:
    // 0x17d054: 0xdfb00000
    ctx->pc = 0x17d054u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d058: 0xdfb10008
    ctx->pc = 0x17d058u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d05c: 0xdfb20010
    ctx->pc = 0x17d05cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17d060: 0xdfb30018
    ctx->pc = 0x17d060u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17d064: 0xdfb40020
    ctx->pc = 0x17d064u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17d068: 0xdfbf0028
    ctx->pc = 0x17d068u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17d06c: 0x3e00008
    ctx->pc = 0x17D06Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D070u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CF38u: goto label_17cf38;
            case 0x17CFD8u: goto label_17cfd8;
            case 0x17D024u: goto label_17d024;
            case 0x17D040u: goto label_17d040;
            case 0x17D054u: goto label_17d054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D074u;
    // 0x17d074: 0x0
    ctx->pc = 0x17d074u;
    // NOP
}
