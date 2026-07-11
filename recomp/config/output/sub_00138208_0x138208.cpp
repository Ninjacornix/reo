#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00138208
// Address: 0x138208 - 0x1382f0
void sub_00138208_0x138208(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x138208u;

    // 0x138208: 0x3c030022
    ctx->pc = 0x138208u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13820c: 0x3c020022
    ctx->pc = 0x13820cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x138210: 0x2463bbf4
    ctx->pc = 0x138210u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949876));
    // 0x138214: 0x2442bbf0
    ctx->pc = 0x138214u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294949872));
    // 0x138218: 0x8c650000
    ctx->pc = 0x138218u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13821c: 0xac450000
    ctx->pc = 0x13821cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
    // 0x138220: 0x3e00008
    ctx->pc = 0x138220u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138224u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x1382D0u: goto label_1382d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138228u;
    // 0x138228: 0x3c030022
    ctx->pc = 0x138228u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13822c: 0x2463bbf4
    ctx->pc = 0x13822cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949876));
    // 0x138230: 0x3e00008
    ctx->pc = 0x138230u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138234u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x1382D0u: goto label_1382d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138238u;
    // 0x138238: 0x27bdfff0
    ctx->pc = 0x138238u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13823c: 0x3c020022
    ctx->pc = 0x13823cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x138240: 0x24030001
    ctx->pc = 0x138240u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x138244: 0xffbf0000
    ctx->pc = 0x138244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x138248: 0x14830007
    ctx->pc = 0x138248u;
    {
        const bool branch_taken_0x138248 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 3));
        ctx->pc = 0x13824Cu;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294949880), GPR_U32(ctx, 4));
        if (branch_taken_0x138248) {
            ctx->pc = 0x138268u;
            goto label_138268;
        }
    }
    ctx->pc = 0x138250u;
    // 0x138250: 0x3c040024
    ctx->pc = 0x138250u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x138254: 0xdfbf0000
    ctx->pc = 0x138254u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138258: 0x2484c6c8
    ctx->pc = 0x138258u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294952648));
    // 0x13825c: 0x8045a12
    ctx->pc = 0x13825Cu;
    ctx->pc = 0x138260u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x116848u;
    sub_00116848_0x116848(rdram, ctx, runtime); return;
    ctx->pc = 0x138264u;
    // 0x138264: 0x0
    ctx->pc = 0x138264u;
    // NOP
label_138268:
    // 0x138268: 0xdfbf0000
    ctx->pc = 0x138268u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13826c: 0x3e00008
    ctx->pc = 0x13826Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138270u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x1382D0u: goto label_1382d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138274u;
    // 0x138274: 0x0
    ctx->pc = 0x138274u;
    // NOP
    // 0x138278: 0x3c030022
    ctx->pc = 0x138278u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13827c: 0x3e00008
    ctx->pc = 0x13827Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138280u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294949880)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x1382D0u: goto label_1382d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138284u;
    // 0x138284: 0x0
    ctx->pc = 0x138284u;
    // NOP
    // 0x138288: 0x3c030022
    ctx->pc = 0x138288u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13828c: 0x41600
    ctx->pc = 0x13828cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 24));
    // 0x138290: 0x2463bbcc
    ctx->pc = 0x138290u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949836));
    // 0x138294: 0x21603
    ctx->pc = 0x138294u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x138298: 0x27bdfff0
    ctx->pc = 0x138298u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13829c: 0x3c060022
    ctx->pc = 0x13829cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)34 << 16));
    // 0x1382a0: 0xffbf0000
    ctx->pc = 0x1382a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1382a4: 0x24050001
    ctx->pc = 0x1382a4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1382a8: 0xac620000
    ctx->pc = 0x1382a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1382ac: 0x8c620000
    ctx->pc = 0x1382acu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1382b0: 0x14850007
    ctx->pc = 0x1382B0u;
    {
        const bool branch_taken_0x1382b0 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 5));
        ctx->pc = 0x1382B4u;
        WRITE32(ADD32(GPR_U32(ctx, 6), 4294949884), GPR_U32(ctx, 2));
        if (branch_taken_0x1382b0) {
            ctx->pc = 0x1382D0u;
            goto label_1382d0;
        }
    }
    ctx->pc = 0x1382B8u;
    // 0x1382b8: 0x3c040024
    ctx->pc = 0x1382b8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1382bc: 0xdfbf0000
    ctx->pc = 0x1382bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1382c0: 0x2484c6e8
    ctx->pc = 0x1382c0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294952680));
    // 0x1382c4: 0x8045a12
    ctx->pc = 0x1382C4u;
    ctx->pc = 0x1382C8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x116848u;
    sub_00116848_0x116848(rdram, ctx, runtime); return;
    ctx->pc = 0x1382CCu;
    // 0x1382cc: 0x0
    ctx->pc = 0x1382ccu;
    // NOP
label_1382d0:
    // 0x1382d0: 0xdfbf0000
    ctx->pc = 0x1382d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1382d4: 0x3e00008
    ctx->pc = 0x1382D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1382D8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x1382D0u: goto label_1382d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1382DCu;
    // 0x1382dc: 0x0
    ctx->pc = 0x1382dcu;
    // NOP
    // 0x1382e0: 0x3c030022
    ctx->pc = 0x1382e0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x1382e4: 0x3e00008
    ctx->pc = 0x1382E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1382E8u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294949884)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x1382D0u: goto label_1382d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1382ECu;
    // 0x1382ec: 0x0
    ctx->pc = 0x1382ecu;
    // NOP
}
