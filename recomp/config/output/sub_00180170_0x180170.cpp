#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00180170
// Address: 0x180170 - 0x1801f0
void sub_00180170_0x180170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x180170u;

    // 0x180170: 0x27bdfff0
    ctx->pc = 0x180170u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x180174: 0xffbf0000
    ctx->pc = 0x180174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x180178: 0xc047598
    ctx->pc = 0x180178u;
    SET_GPR_U32(ctx, 31, 0x180180u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180180u; }
    }
    if (ctx->pc != 0x180180u) { return; }
    ctx->pc = 0x180180u;
    // 0x180180: 0x3c031000
    ctx->pc = 0x180180u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x180184: 0x3c041000
    ctx->pc = 0x180184u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x180188: 0x34633830
    ctx->pc = 0x180188u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 14384));
    // 0x18018c: 0x34843820
    ctx->pc = 0x18018cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 14368));
    // 0x180190: 0xac600000
    ctx->pc = 0x180190u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x180194: 0x3c051000
    ctx->pc = 0x180194u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x180198: 0xac800000
    ctx->pc = 0x180198u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x18019c: 0x34a53810
    ctx->pc = 0x18019cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 14352));
    // 0x1801a0: 0x24030001
    ctx->pc = 0x1801a0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1801a4: 0xaca30000
    ctx->pc = 0x1801a4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1801a8: 0x4848e000
    ctx->pc = 0x1801a8u;
    SET_GPR_U32(ctx, 8, ctx->vu0_itop);
    // 0x1801ac: 0x35080002
    ctx->pc = 0x1801acu;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 8), 2));
    // 0x1801b0: 0x48c8e000
    ctx->pc = 0x1801b0u;
    ctx->vu0_itop = GPR_U32(ctx, 8) & 0x3FF;
    // 0x1801b4: 0x40f
    ctx->pc = 0x1801b4u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1801b8: 0x3c050023
    ctx->pc = 0x1801b8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)35 << 16));
    // 0x1801bc: 0x3c061000
    ctx->pc = 0x1801bcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x1801c0: 0x24a5f9b0
    ctx->pc = 0x1801c0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294965680));
    // 0x1801c4: 0x34c64000
    ctx->pc = 0x1801c4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 16384));
    // 0x1801c8: 0x78a30000
    ctx->pc = 0x1801c8u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1801cc: 0x7cc30000
    ctx->pc = 0x1801ccu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 3));
    // 0x1801d0: 0x78a40010
    ctx->pc = 0x1801d0u;
    SET_GPR_VEC(ctx, 4, READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x1801d4: 0x7cc40000
    ctx->pc = 0x1801d4u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 4));
    // 0x1801d8: 0x10400003
    ctx->pc = 0x1801D8u;
    {
        const bool branch_taken_0x1801d8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1801DCu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x1801d8) {
            ctx->pc = 0x1801E8u;
            goto label_1801e8;
        }
    }
    ctx->pc = 0x1801E0u;
    // 0x1801e0: 0x80475ae
    ctx->pc = 0x1801E0u;
    ctx->pc = 0x1801E4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x1801E8u;
label_1801e8:
    // 0x1801e8: 0x3e00008
    ctx->pc = 0x1801E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1801ECu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1801E8u: goto label_1801e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1801F0u;
}
