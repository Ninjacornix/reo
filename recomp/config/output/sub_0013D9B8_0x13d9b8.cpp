#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013D9B8
// Address: 0x13d9b8 - 0x13db48
void sub_0013D9B8_0x13d9b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13d9b8u;

    // 0x13d9b8: 0x27bdffe0
    ctx->pc = 0x13d9b8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13d9bc: 0x24060001
    ctx->pc = 0x13d9bcu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d9c0: 0xffb00000
    ctx->pc = 0x13d9c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13d9c4: 0x80802d
    ctx->pc = 0x13d9c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d9c8: 0xffb10008
    ctx->pc = 0x13d9c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13d9cc: 0xffb20010
    ctx->pc = 0x13d9ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13d9d0: 0xffbf0018
    ctx->pc = 0x13d9d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13d9d4: 0x82020004
    ctx->pc = 0x13d9d4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x13d9d8: 0x10460025
    ctx->pc = 0x13D9D8u;
    {
        const bool branch_taken_0x13d9d8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 6));
        ctx->pc = 0x13D9DCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x13d9d8) {
            ctx->pc = 0x13DA70u;
            goto label_13da70;
        }
    }
    ctx->pc = 0x13D9E0u;
    // 0x13d9e0: 0x82120001
    ctx->pc = 0x13d9e0u;
    SET_GPR_S32(ctx, 18, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x13d9e4: 0x56420023
    ctx->pc = 0x13D9E4u;
    {
        const bool branch_taken_0x13d9e4 = (GPR_U32(ctx, 18) != GPR_U32(ctx, 2));
        if (branch_taken_0x13d9e4) {
            ctx->pc = 0x13D9E8u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x13DA74u;
            goto label_13da74;
        }
    }
    ctx->pc = 0x13D9ECu;
    // 0x13d9ec: 0x8e020024
    ctx->pc = 0x13d9ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13d9f0: 0x58400020
    ctx->pc = 0x13D9F0u;
    {
        const bool branch_taken_0x13d9f0 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x13d9f0) {
            ctx->pc = 0x13D9F4u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x13DA74u;
            goto label_13da74;
        }
    }
    ctx->pc = 0x13D9F8u;
    // 0x13d9f8: 0x8e050020
    ctx->pc = 0x13d9f8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13d9fc: 0x26110010
    ctx->pc = 0x13d9fcu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 16));
    // 0x13da00: 0x51140
    ctx->pc = 0x13da00u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 5));
    // 0x13da04: 0x511021
    ctx->pc = 0x13da04u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x13da08: 0x8c430040
    ctx->pc = 0x13da08u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x13da0c: 0x14660005
    ctx->pc = 0x13DA0Cu;
    {
        const bool branch_taken_0x13da0c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 6));
        ctx->pc = 0x13DA10u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 5));
        if (branch_taken_0x13da0c) {
            ctx->pc = 0x13DA24u;
            goto label_13da24;
        }
    }
    ctx->pc = 0x13DA14u;
    // 0x13da14: 0xc04f600
    ctx->pc = 0x13DA14u;
    SET_GPR_U32(ctx, 31, 0x13DA1Cu);
    ctx->pc = 0x13D800u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D800_0x13d800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DA1Cu; }
    }
    if (ctx->pc != 0x13DA1Cu) { return; }
    ctx->pc = 0x13DA1Cu;
    // 0x13da1c: 0x8e050020
    ctx->pc = 0x13da1cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13da20: 0x51140
    ctx->pc = 0x13da20u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 5));
label_13da24:
    // 0x13da24: 0x511021
    ctx->pc = 0x13da24u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x13da28: 0x8c430040
    ctx->pc = 0x13da28u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x13da2c: 0x14720005
    ctx->pc = 0x13DA2Cu;
    {
        const bool branch_taken_0x13da2c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 18));
        ctx->pc = 0x13DA30u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 5));
        if (branch_taken_0x13da2c) {
            ctx->pc = 0x13DA44u;
            goto label_13da44;
        }
    }
    ctx->pc = 0x13DA34u;
    // 0x13da34: 0xc04f62c
    ctx->pc = 0x13DA34u;
    SET_GPR_U32(ctx, 31, 0x13DA3Cu);
    ctx->pc = 0x13DA38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x13D8B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D8B0_0x13d8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DA3Cu; }
    }
    if (ctx->pc != 0x13DA3Cu) { return; }
    ctx->pc = 0x13DA3Cu;
    // 0x13da3c: 0x8e050020
    ctx->pc = 0x13da3cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13da40: 0x51140
    ctx->pc = 0x13da40u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 5));
label_13da44:
    // 0x13da44: 0x511021
    ctx->pc = 0x13da44u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x13da48: 0x8c430040
    ctx->pc = 0x13da48u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x13da4c: 0x54600009
    ctx->pc = 0x13DA4Cu;
    {
        const bool branch_taken_0x13da4c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x13da4c) {
            ctx->pc = 0x13DA50u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x13DA74u;
            goto label_13da74;
        }
    }
    ctx->pc = 0x13DA54u;
    // 0x13da54: 0x200202d
    ctx->pc = 0x13da54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13da58: 0xdfb00000
    ctx->pc = 0x13da58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13da5c: 0xdfb10008
    ctx->pc = 0x13da5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13da60: 0xdfb20010
    ctx->pc = 0x13da60u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13da64: 0xdfbf0018
    ctx->pc = 0x13da64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13da68: 0x804f5b6
    ctx->pc = 0x13DA68u;
    ctx->pc = 0x13DA6Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x13D6D8u;
    entry_13d6d8_0x13d800(rdram, ctx, runtime); return;
    ctx->pc = 0x13DA70u;
label_13da70:
    // 0x13da70: 0xdfb00000
    ctx->pc = 0x13da70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13da74:
    // 0x13da74: 0xdfb10008
    ctx->pc = 0x13da74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13da78: 0xdfb20010
    ctx->pc = 0x13da78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13da7c: 0xdfbf0018
    ctx->pc = 0x13da7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13da80: 0x3e00008
    ctx->pc = 0x13DA80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13DA84u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DA24u: goto label_13da24;
            case 0x13DA44u: goto label_13da44;
            case 0x13DA70u: goto label_13da70;
            case 0x13DA74u: goto label_13da74;
            case 0x13DAB8u: goto label_13dab8;
            case 0x13DAD8u: goto label_13dad8;
            case 0x13DB08u: goto label_13db08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13DA88u;
    // 0x13da88: 0x27bdfff0
    ctx->pc = 0x13da88u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13da8c: 0x80502d
    ctx->pc = 0x13da8cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13da90: 0xffbf0000
    ctx->pc = 0x13da90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13da94: 0x5410008
    ctx->pc = 0x13DA94u;
    {
        const bool branch_taken_0x13da94 = (GPR_S32(ctx, 10) >= 0);
        ctx->pc = 0x13DA98u;
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13da94) {
            ctx->pc = 0x13DAB8u;
            goto label_13dab8;
        }
    }
    ctx->pc = 0x13DA9Cu;
    // 0x13da9c: 0x3c040024
    ctx->pc = 0x13da9cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x13daa0: 0xdfbf0000
    ctx->pc = 0x13daa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13daa4: 0x140282d
    ctx->pc = 0x13daa4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13daa8: 0x2484d4e0
    ctx->pc = 0x13daa8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294956256));
    // 0x13daac: 0x8045a12
    ctx->pc = 0x13DAACu;
    ctx->pc = 0x13DAB0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x116848u;
    sub_00116848_0x116848(rdram, ctx, runtime); return;
    ctx->pc = 0x13DAB4u;
    // 0x13dab4: 0x0
    ctx->pc = 0x13dab4u;
    // NOP
label_13dab8:
    // 0x13dab8: 0x5610007
    ctx->pc = 0x13DAB8u;
    {
        const bool branch_taken_0x13dab8 = (GPR_S32(ctx, 11) >= 0);
        ctx->pc = 0x13DABCu;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 10), 1));
        if (branch_taken_0x13dab8) {
            ctx->pc = 0x13DAD8u;
            goto label_13dad8;
        }
    }
    ctx->pc = 0x13DAC0u;
    // 0x13dac0: 0x3c040024
    ctx->pc = 0x13dac0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x13dac4: 0xdfbf0000
    ctx->pc = 0x13dac4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13dac8: 0x2484d510
    ctx->pc = 0x13dac8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294956304));
    // 0x13dacc: 0x8045a12
    ctx->pc = 0x13DACCu;
    ctx->pc = 0x13DAD0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x116848u;
    sub_00116848_0x116848(rdram, ctx, runtime); return;
    ctx->pc = 0x13DAD4u;
    // 0x13dad4: 0x0
    ctx->pc = 0x13dad4u;
    // NOP
label_13dad8:
    // 0x13dad8: 0x4b4821
    ctx->pc = 0x13dad8u;
    SET_GPR_U32(ctx, 9, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x13dadc: 0x91980
    ctx->pc = 0x13dadcu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 9), 6));
    // 0x13dae0: 0x29220021
    ctx->pc = 0x13dae0u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 9), 33));
    // 0x13dae4: 0x14400008
    ctx->pc = 0x13DAE4u;
    {
        const bool branch_taken_0x13dae4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13DAE8u;
        SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
        if (branch_taken_0x13dae4) {
            ctx->pc = 0x13DB08u;
            goto label_13db08;
        }
    }
    ctx->pc = 0x13DAECu;
    // 0x13daec: 0x3c040024
    ctx->pc = 0x13daecu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x13daf0: 0xdfbf0000
    ctx->pc = 0x13daf0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13daf4: 0x24050020
    ctx->pc = 0x13daf4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 32));
    // 0x13daf8: 0x2484d540
    ctx->pc = 0x13daf8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294956352));
    // 0x13dafc: 0x8045a12
    ctx->pc = 0x13DAFCu;
    ctx->pc = 0x13DB00u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x116848u;
    sub_00116848_0x116848(rdram, ctx, runtime); return;
    ctx->pc = 0x13DB04u;
    // 0x13db04: 0x0
    ctx->pc = 0x13db04u;
    // NOP
label_13db08:
    // 0x13db08: 0xdfbf0000
    ctx->pc = 0x13db08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13db0c: 0x33a00
    ctx->pc = 0x13db0cu;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 3), 8));
    // 0x13db10: 0x3c080022
    ctx->pc = 0x13db10u;
    SET_GPR_U32(ctx, 8, ((uint32_t)34 << 16));
    // 0x13db14: 0x3c040022
    ctx->pc = 0x13db14u;
    SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
    // 0x13db18: 0x3c030022
    ctx->pc = 0x13db18u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13db1c: 0x3c050022
    ctx->pc = 0x13db1cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)34 << 16));
    // 0x13db20: 0x3c060022
    ctx->pc = 0x13db20u;
    SET_GPR_U32(ctx, 6, ((uint32_t)34 << 16));
    // 0x13db24: 0x24020001
    ctx->pc = 0x13db24u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x13db28: 0xac6a1460
    ctx->pc = 0x13db28u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 5216), GPR_U32(ctx, 10));
    // 0x13db2c: 0xac8b1464
    ctx->pc = 0x13db2cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 5220), GPR_U32(ctx, 11));
    // 0x13db30: 0xaca7143c
    ctx->pc = 0x13db30u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 5180), GPR_U32(ctx, 7));
    // 0x13db34: 0xacc21440
    ctx->pc = 0x13db34u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 5184), GPR_U32(ctx, 2));
    // 0x13db38: 0xad091438
    ctx->pc = 0x13db38u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 5176), GPR_U32(ctx, 9));
    // 0x13db3c: 0x3e00008
    ctx->pc = 0x13DB3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13DB40u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DA24u: goto label_13da24;
            case 0x13DA44u: goto label_13da44;
            case 0x13DA70u: goto label_13da70;
            case 0x13DA74u: goto label_13da74;
            case 0x13DAB8u: goto label_13dab8;
            case 0x13DAD8u: goto label_13dad8;
            case 0x13DB08u: goto label_13db08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13DB44u;
    // 0x13db44: 0x0
    ctx->pc = 0x13db44u;
    // NOP
}
