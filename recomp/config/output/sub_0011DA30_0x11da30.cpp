#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011DA30
// Address: 0x11da30 - 0x11dae0
void sub_0011DA30_0x11da30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11da30u;

    // 0x11da30: 0x27bdffc0
    ctx->pc = 0x11da30u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11da34: 0xffbf0030
    ctx->pc = 0x11da34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11da38: 0xffb20020
    ctx->pc = 0x11da38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11da3c: 0xffb10010
    ctx->pc = 0x11da3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11da40: 0xc047672
    ctx->pc = 0x11DA40u;
    SET_GPR_U32(ctx, 31, 0x11DA48u);
    ctx->pc = 0x11DA44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    ctx->pc = 0x11D9C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D9C8_0x11d9c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA48u; }
    }
    if (ctx->pc != 0x11DA48u) { return; }
    ctx->pc = 0x11DA48u;
    // 0x11da48: 0x1040001e
    ctx->pc = 0x11DA48u;
    {
        const bool branch_taken_0x11da48 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x11DA4Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
        if (branch_taken_0x11da48) {
            ctx->pc = 0x11DAC4u;
            goto label_11dac4;
        }
    }
    ctx->pc = 0x11DA50u;
    // 0x11da50: 0x24120002
    ctx->pc = 0x11da50u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 2));
    // 0x11da54: 0x2450ac20
    ctx->pc = 0x11da54u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294945824));
    // 0x11da58: 0x8c44ac20
    ctx->pc = 0x11da58u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294945824)));
    // 0x11da5c: 0x8e050004
    ctx->pc = 0x11da5cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11da60: 0xc047658
    ctx->pc = 0x11DA60u;
    SET_GPR_U32(ctx, 31, 0x11DA68u);
    ctx->pc = 0x11DA64u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 16));
    ctx->pc = 0x11D960u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D960_0x11d960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA68u; }
    }
    if (ctx->pc != 0x11DA68u) { return; }
    ctx->pc = 0x11DA68u;
    // 0x11da68: 0x3c050021
    ctx->pc = 0x11da68u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x11da6c: 0x3c048007
    ctx->pc = 0x11da6cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)32775 << 16));
    // 0x11da70: 0x240607a8
    ctx->pc = 0x11da70u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1960));
    // 0x11da74: 0x24a5a478
    ctx->pc = 0x11da74u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294943864));
    // 0x11da78: 0xc04765c
    ctx->pc = 0x11DA78u;
    SET_GPR_U32(ctx, 31, 0x11DA80u);
    ctx->pc = 0x11DA7Cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 16384));
    ctx->pc = 0x11D970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D970_0x11d970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA80u; }
    }
    if (ctx->pc != 0x11DA80u) { return; }
    ctx->pc = 0x11DA80u;
    // 0x11da80: 0xc045228
    ctx->pc = 0x11DA80u;
    SET_GPR_U32(ctx, 31, 0x11DA88u);
    ctx->pc = 0x11DA84u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA88u; }
    }
    if (ctx->pc != 0x11DA88u) { return; }
    ctx->pc = 0x11DA88u;
    // 0x11da88: 0xc045228
    ctx->pc = 0x11DA88u;
    SET_GPR_U32(ctx, 31, 0x11DA90u);
    ctx->pc = 0x11DA8Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA90u; }
    }
    if (ctx->pc != 0x11DA90u) { return; }
    ctx->pc = 0x11DA90u;
    // 0x11da90: 0x8e040008
    ctx->pc = 0x11da90u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11da94: 0xc047658
    ctx->pc = 0x11DA94u;
    SET_GPR_U32(ctx, 31, 0x11DA9Cu);
    ctx->pc = 0x11DA98u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    ctx->pc = 0x11D960u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D960_0x11d960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA9Cu; }
    }
    if (ctx->pc != 0x11DA9Cu) { return; }
    ctx->pc = 0x11DA9Cu;
    // 0x11da9c: 0x8e240000
    ctx->pc = 0x11da9cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_11daa0:
    // 0x11daa0: 0xc04766e
    ctx->pc = 0x11DAA0u;
    SET_GPR_U32(ctx, 31, 0x11DAA8u);
    ctx->pc = 0x11DAA4u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
    ctx->pc = 0x11D9B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D9B8_0x11d9b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DAA8u; }
    }
    if (ctx->pc != 0x11DAA8u) { return; }
    ctx->pc = 0x11DAA8u;
    // 0x11daa8: 0x8e240000
    ctx->pc = 0x11daa8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11daac: 0x40282d
    ctx->pc = 0x11daacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dab0: 0xc047658
    ctx->pc = 0x11DAB0u;
    SET_GPR_U32(ctx, 31, 0x11DAB8u);
    ctx->pc = 0x11DAB4u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 8));
    ctx->pc = 0x11D960u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D960_0x11d960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DAB8u; }
    }
    if (ctx->pc != 0x11DAB8u) { return; }
    ctx->pc = 0x11DAB8u;
    // 0x11dab8: 0x2e420003
    ctx->pc = 0x11dab8u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 18), 3));
    // 0x11dabc: 0x5440fff8
    ctx->pc = 0x11DABCu;
    {
        const bool branch_taken_0x11dabc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x11dabc) {
            ctx->pc = 0x11DAC0u;
            SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
            ctx->pc = 0x11DAA0u;
            goto label_11daa0;
        }
    }
    ctx->pc = 0x11DAC4u;
label_11dac4:
    // 0x11dac4: 0xdfbf0030
    ctx->pc = 0x11dac4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11dac8: 0xdfb20020
    ctx->pc = 0x11dac8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11dacc: 0xdfb10010
    ctx->pc = 0x11daccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11dad0: 0xdfb00000
    ctx->pc = 0x11dad0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dad4: 0x3e00008
    ctx->pc = 0x11DAD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DAD8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DAA0u: goto label_11daa0;
            case 0x11DAC4u: goto label_11dac4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DADCu;
    // 0x11dadc: 0x0
    ctx->pc = 0x11dadcu;
    // NOP
}
