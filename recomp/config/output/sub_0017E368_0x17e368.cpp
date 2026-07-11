#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017E368
// Address: 0x17e368 - 0x17e3a8
void sub_0017E368_0x17e368(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17e368u;

    // 0x17e368: 0x44801000
    ctx->pc = 0x17e368u;
    *(uint32_t*)&ctx->f[2] = GPR_U32(ctx, 0);
    // 0x17e36c: 0x24020001
    ctx->pc = 0x17e36cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e370: 0xc480003c
    ctx->pc = 0x17e370u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x17e374: 0x46020032
    ctx->pc = 0x17e374u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[2])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17e378: 0x45000004
    ctx->pc = 0x17E378u;
    {
        const bool branch_taken_0x17e378 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x17E37Cu;
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        if (branch_taken_0x17e378) {
            ctx->pc = 0x17E38Cu;
            goto label_17e38c;
        }
    }
    ctx->pc = 0x17E380u;
    // 0x17e380: 0x46020832
    ctx->pc = 0x17e380u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[1], ctx->f[2])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17e384: 0x45030001
    ctx->pc = 0x17E384u;
    {
        const bool branch_taken_0x17e384 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x17e384) {
            ctx->pc = 0x17E388u;
            SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x17E38Cu;
            goto label_17e38c;
        }
    }
    ctx->pc = 0x17E38Cu;
label_17e38c:
    // 0x17e38c: 0x3e00008
    ctx->pc = 0x17E38Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E38Cu: goto label_17e38c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E394u;
    // 0x17e394: 0x0
    ctx->pc = 0x17e394u;
    // NOP
    // 0x17e398: 0x3c020023
    ctx->pc = 0x17e398u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x17e39c: 0x3e00008
    ctx->pc = 0x17E39Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E3A0u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294965068), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E38Cu: goto label_17e38c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E3A4u;
    // 0x17e3a4: 0x0
    ctx->pc = 0x17e3a4u;
    // NOP
}
