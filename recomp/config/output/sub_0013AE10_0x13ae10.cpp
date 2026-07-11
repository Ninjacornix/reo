#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013AE10
// Address: 0x13ae10 - 0x13af00
void sub_0013AE10_0x13ae10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13ae10u;

    // 0x13ae10: 0x27bdffe0
    ctx->pc = 0x13ae10u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13ae14: 0xffb00000
    ctx->pc = 0x13ae14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13ae18: 0x80802d
    ctx->pc = 0x13ae18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ae1c: 0xffb10008
    ctx->pc = 0x13ae1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13ae20: 0x200282d
    ctx->pc = 0x13ae20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ae24: 0x16000004
    ctx->pc = 0x13AE24u;
    {
        const bool branch_taken_0x13ae24 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x13AE28u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        if (branch_taken_0x13ae24) {
            ctx->pc = 0x13AE38u;
            goto label_13ae38;
        }
    }
    ctx->pc = 0x13AE2Cu;
    // 0x13ae2c: 0x3c020022
    ctx->pc = 0x13ae2cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13ae30: 0x10000024
    ctx->pc = 0x13AE30u;
    {
        const bool branch_taken_0x13ae30 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x13AE34u;
        WRITE8(ADD32(GPR_U32(ctx, 2), 4294957296), (uint8_t)GPR_U32(ctx, 0));
        if (branch_taken_0x13ae30) {
            ctx->pc = 0x13AEC4u;
            goto label_13aec4;
        }
    }
    ctx->pc = 0x13AE38u;
label_13ae38:
    // 0x13ae38: 0x82030000
    ctx->pc = 0x13ae38u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13ae3c: 0x2402002f
    ctx->pc = 0x13ae3cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 47));
    // 0x13ae40: 0x1062000d
    ctx->pc = 0x13AE40u;
    {
        const bool branch_taken_0x13ae40 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x13AE44u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 92));
        if (branch_taken_0x13ae40) {
            ctx->pc = 0x13AE78u;
            goto label_13ae78;
        }
    }
    ctx->pc = 0x13AE48u;
    // 0x13ae48: 0x1062000b
    ctx->pc = 0x13AE48u;
    {
        const bool branch_taken_0x13ae48 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x13AE4Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
        if (branch_taken_0x13ae48) {
            ctx->pc = 0x13AE78u;
            goto label_13ae78;
        }
    }
    ctx->pc = 0x13AE50u;
    // 0x13ae50: 0x3c040022
    ctx->pc = 0x13ae50u;
    SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
    // 0x13ae54: 0x2448cc70
    ctx->pc = 0x13ae54u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 2), 4294954096));
    // 0x13ae58: 0x2487d8f0
    ctx->pc = 0x13ae58u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 4), 4294957296));
    // 0x13ae5c: 0x81030000
    ctx->pc = 0x13ae5cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x13ae60: 0x81060001
    ctx->pc = 0x13ae60u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x13ae64: 0xa0e30000
    ctx->pc = 0x13ae64u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x13ae68: 0xa0e60001
    ctx->pc = 0x13ae68u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 1), (uint8_t)GPR_U32(ctx, 6));
    // 0x13ae6c: 0x10000005
    ctx->pc = 0x13AE6Cu;
    {
        const bool branch_taken_0x13ae6c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x13AE70u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 4), 4294957296));
        if (branch_taken_0x13ae6c) {
            ctx->pc = 0x13AE84u;
            goto label_13ae84;
        }
    }
    ctx->pc = 0x13AE74u;
    // 0x13ae74: 0x0
    ctx->pc = 0x13ae74u;
    // NOP
label_13ae78:
    // 0x13ae78: 0x3c040022
    ctx->pc = 0x13ae78u;
    SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
    // 0x13ae7c: 0xa080d8f0
    ctx->pc = 0x13ae7cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 4294957296), (uint8_t)GPR_U32(ctx, 0));
    // 0x13ae80: 0x2491d8f0
    ctx->pc = 0x13ae80u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 4), 4294957296));
label_13ae84:
    // 0x13ae84: 0xc042aee
    ctx->pc = 0x13AE84u;
    SET_GPR_U32(ctx, 31, 0x13AE8Cu);
    ctx->pc = 0x13AE88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10ABB8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AE8Cu; }
    }
    if (ctx->pc != 0x13AE8Cu) { return; }
    ctx->pc = 0x13AE8Cu;
    // 0x13ae8c: 0xc042c56
    ctx->pc = 0x13AE8Cu;
    SET_GPR_U32(ctx, 31, 0x13AE94u);
    ctx->pc = 0x13AE90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AE94u; }
    }
    if (ctx->pc != 0x13AE94u) { return; }
    ctx->pc = 0x13AE94u;
    // 0x13ae94: 0x220202d
    ctx->pc = 0x13ae94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ae98: 0x2021021
    ctx->pc = 0x13ae98u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x13ae9c: 0x2403002f
    ctx->pc = 0x13ae9cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 47));
    // 0x13aea0: 0x8042ffff
    ctx->pc = 0x13aea0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x13aea4: 0x10430003
    ctx->pc = 0x13AEA4u;
    {
        const bool branch_taken_0x13aea4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x13AEA8u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 92));
        if (branch_taken_0x13aea4) {
            ctx->pc = 0x13AEB4u;
            goto label_13aeb4;
        }
    }
    ctx->pc = 0x13AEACu;
    // 0x13aeac: 0x14450006
    ctx->pc = 0x13AEACu;
    {
        const bool branch_taken_0x13aeac = (GPR_U32(ctx, 2) != GPR_U32(ctx, 5));
        ctx->pc = 0x13AEB0u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x13aeac) {
            ctx->pc = 0x13AEC8u;
            goto label_13aec8;
        }
    }
    ctx->pc = 0x13AEB4u;
label_13aeb4:
    // 0x13aeb4: 0xc042c56
    ctx->pc = 0x13AEB4u;
    SET_GPR_U32(ctx, 31, 0x13AEBCu);
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AEBCu; }
    }
    if (ctx->pc != 0x13AEBCu) { return; }
    ctx->pc = 0x13AEBCu;
    // 0x13aebc: 0x511021
    ctx->pc = 0x13aebcu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x13aec0: 0xa040ffff
    ctx->pc = 0x13aec0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 4294967295), (uint8_t)GPR_U32(ctx, 0));
label_13aec4:
    // 0x13aec4: 0xdfb00000
    ctx->pc = 0x13aec4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13aec8:
    // 0x13aec8: 0xdfb10008
    ctx->pc = 0x13aec8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13aecc: 0xdfbf0010
    ctx->pc = 0x13aeccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13aed0: 0x3e00008
    ctx->pc = 0x13AED0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AED4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AE38u: goto label_13ae38;
            case 0x13AE78u: goto label_13ae78;
            case 0x13AE84u: goto label_13ae84;
            case 0x13AEB4u: goto label_13aeb4;
            case 0x13AEC4u: goto label_13aec4;
            case 0x13AEC8u: goto label_13aec8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13AED8u;
    // 0x13aed8: 0x3c020022
    ctx->pc = 0x13aed8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13aedc: 0x3e00008
    ctx->pc = 0x13AEDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AEE0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294957296));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AE38u: goto label_13ae38;
            case 0x13AE78u: goto label_13ae78;
            case 0x13AE84u: goto label_13ae84;
            case 0x13AEB4u: goto label_13aeb4;
            case 0x13AEC4u: goto label_13aec4;
            case 0x13AEC8u: goto label_13aec8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13AEE4u;
    // 0x13aee4: 0x0
    ctx->pc = 0x13aee4u;
    // NOP
    // 0x13aee8: 0x27bdfff0
    ctx->pc = 0x13aee8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13aeec: 0xffbf0000
    ctx->pc = 0x13aeecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13aef0: 0xdfbf0000
    ctx->pc = 0x13aef0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13aef4: 0x804e0d8
    ctx->pc = 0x13AEF4u;
    ctx->pc = 0x13AEF8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x138360u;
    entry_138360_0x1383e8(rdram, ctx, runtime); return;
    ctx->pc = 0x13AEFCu;
    // 0x13aefc: 0x0
    ctx->pc = 0x13aefcu;
    // NOP
}
