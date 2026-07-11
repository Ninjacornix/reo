#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001CC830
// Address: 0x1cc830 - 0x1cc8a0
void sub_001CC830_0x1cc830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1cc830u;

    // 0x1cc830: 0x27bdffe0
    ctx->pc = 0x1cc830u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cc834: 0x3c024000
    ctx->pc = 0x1cc834u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16384 << 16));
    // 0x1cc838: 0xffbf0010
    ctx->pc = 0x1cc838u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cc83c: 0x3c011000
    ctx->pc = 0x1cc83cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x1cc840: 0x7fb00000
    ctx->pc = 0x1cc840u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cc844: 0x202d
    ctx->pc = 0x1cc844u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc848: 0xac222000
    ctx->pc = 0x1cc848u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8192), GPR_U32(ctx, 2)); // MMIO: 0x10002000
    // 0x1cc84c: 0xc044fb4
    ctx->pc = 0x1CC84Cu;
    SET_GPR_U32(ctx, 31, 0x1CC854u);
    ctx->pc = 0x1CC850u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x113ED0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC854u; }
    }
    if (ctx->pc != 0x1CC854u) { return; }
    ctx->pc = 0x1CC854u;
    // 0x1cc854: 0x3c011000
    ctx->pc = 0x1cc854u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x1cc858: 0x202d
    ctx->pc = 0x1cc858u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc85c: 0x8c222000
    ctx->pc = 0x1cc85cu;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8192))); // MMIO: 0x10002000
    // 0x1cc860: 0x282d
    ctx->pc = 0x1cc860u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc864: 0x21602
    ctx->pc = 0x1cc864u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 24));
    // 0x1cc868: 0xc044fb4
    ctx->pc = 0x1CC868u;
    SET_GPR_U32(ctx, 31, 0x1CC870u);
    ctx->pc = 0x1CC86Cu;
    SET_GPR_U32(ctx, 16, AND32(GPR_U32(ctx, 2), 255));
    ctx->pc = 0x113ED0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC870u; }
    }
    if (ctx->pc != 0x1CC870u) { return; }
    ctx->pc = 0x1CC870u;
    // 0x1cc870: 0x3c024000
    ctx->pc = 0x1cc870u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16384 << 16));
    // 0x1cc874: 0x3c011000
    ctx->pc = 0x1cc874u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x1cc878: 0x34420008
    ctx->pc = 0x1cc878u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8));
    // 0x1cc87c: 0x202d
    ctx->pc = 0x1cc87cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc880: 0x282d
    ctx->pc = 0x1cc880u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc884: 0xc044fb4
    ctx->pc = 0x1CC884u;
    SET_GPR_U32(ctx, 31, 0x1CC88Cu);
    ctx->pc = 0x1CC888u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8192), GPR_U32(ctx, 2));
    ctx->pc = 0x113ED0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC88Cu; }
    }
    if (ctx->pc != 0x1CC88Cu) { return; }
    ctx->pc = 0x1CC88Cu;
    // 0x1cc88c: 0x200102d
    ctx->pc = 0x1cc88cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc890: 0xdfbf0010
    ctx->pc = 0x1cc890u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cc894: 0x7bb00000
    ctx->pc = 0x1cc894u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc898: 0x3e00008
    ctx->pc = 0x1CC898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC89Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1CC8A0u;
}
