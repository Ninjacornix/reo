#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00130038
// Address: 0x130038 - 0x1300c8
void sub_00130038_0x130038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x130038u;

    // 0x130038: 0x27bdffe0
    ctx->pc = 0x130038u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13003c: 0x3c020022
    ctx->pc = 0x13003cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x130040: 0xffbf0018
    ctx->pc = 0x130040u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x130044: 0xffb00000
    ctx->pc = 0x130044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130048: 0x24508760
    ctx->pc = 0x130048u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294936416));
    // 0x13004c: 0xffb10008
    ctx->pc = 0x13004cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x130050: 0x24110007
    ctx->pc = 0x130050u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 7));
    // 0x130054: 0xffb20010
    ctx->pc = 0x130054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x130058: 0x24120001
    ctx->pc = 0x130058u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 1));
    // 0x13005c: 0x0
    ctx->pc = 0x13005cu;
    // NOP
label_130060:
    // 0x130060: 0x82020000
    ctx->pc = 0x130060u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x130064: 0x54520004
    ctx->pc = 0x130064u;
    {
        const bool branch_taken_0x130064 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 18));
        if (branch_taken_0x130064) {
            ctx->pc = 0x130068u;
            SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 4294967295));
            ctx->pc = 0x130078u;
            goto label_130078;
        }
    }
    ctx->pc = 0x13006Cu;
    // 0x13006c: 0xc04bffe
    ctx->pc = 0x13006Cu;
    SET_GPR_U32(ctx, 31, 0x130074u);
    ctx->pc = 0x130070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x12FFF8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012FFF8_0x12fff8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130074u; }
    }
    if (ctx->pc != 0x130074u) { return; }
    ctx->pc = 0x130074u;
    // 0x130074: 0x2631ffff
    ctx->pc = 0x130074u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 4294967295));
label_130078:
    // 0x130078: 0x621fff9
    ctx->pc = 0x130078u;
    {
        const bool branch_taken_0x130078 = (GPR_S32(ctx, 17) >= 0);
        ctx->pc = 0x13007Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 752));
        if (branch_taken_0x130078) {
            ctx->pc = 0x130060u;
            goto label_130060;
        }
    }
    ctx->pc = 0x130080u;
    // 0x130080: 0xdfb00000
    ctx->pc = 0x130080u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130084: 0xdfb10008
    ctx->pc = 0x130084u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130088: 0xdfb20010
    ctx->pc = 0x130088u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13008c: 0xdfbf0018
    ctx->pc = 0x13008cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x130090: 0x3e00008
    ctx->pc = 0x130090u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130094u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130060u: goto label_130060;
            case 0x130078u: goto label_130078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130098u;
    // 0x130098: 0x3c020022
    ctx->pc = 0x130098u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13009c: 0x3e00008
    ctx->pc = 0x13009Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1300A0u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294944932), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130060u: goto label_130060;
            case 0x130078u: goto label_130078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1300A4u;
    // 0x1300a4: 0x0
    ctx->pc = 0x1300a4u;
    // NOP
    // 0x1300a8: 0x24020028
    ctx->pc = 0x1300a8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 40));
    // 0x1300ac: 0x3c030022
    ctx->pc = 0x1300acu;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x1300b0: 0x441023
    ctx->pc = 0x1300b0u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1300b4: 0x3c050022
    ctx->pc = 0x1300b4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)34 << 16));
    // 0x1300b8: 0xac62a8a8
    ctx->pc = 0x1300b8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294944936), GPR_U32(ctx, 2));
    // 0x1300bc: 0x3e00008
    ctx->pc = 0x1300BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1300C0u;
        WRITE32(ADD32(GPR_U32(ctx, 5), 4294944940), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130060u: goto label_130060;
            case 0x130078u: goto label_130078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1300C4u;
    // 0x1300c4: 0x0
    ctx->pc = 0x1300c4u;
    // NOP
}
