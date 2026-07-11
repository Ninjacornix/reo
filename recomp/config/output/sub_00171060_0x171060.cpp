#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00171060
// Address: 0x171060 - 0x171160
void sub_00171060_0x171060(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x171060u;

    // 0x171060: 0x27bdfff0
    ctx->pc = 0x171060u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x171064: 0xffb00000
    ctx->pc = 0x171064u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171068: 0x80802d
    ctx->pc = 0x171068u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17106c: 0xffbf0008
    ctx->pc = 0x17106cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x171070: 0xc045198
    ctx->pc = 0x171070u;
    SET_GPR_U32(ctx, 31, 0x171078u);
    ctx->pc = 0x171074u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 64)));
    ctx->pc = 0x114660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171078u; }
    }
    if (ctx->pc != 0x171078u) { return; }
    ctx->pc = 0x171078u;
    // 0x171078: 0xae000044
    ctx->pc = 0x171078u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 0));
    // 0x17107c: 0xc05c296
    ctx->pc = 0x17107Cu;
    SET_GPR_U32(ctx, 31, 0x171084u);
    ctx->pc = 0x171080u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x170A58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170A58_0x170a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171084u; }
    }
    if (ctx->pc != 0x171084u) { return; }
    ctx->pc = 0x171084u;
    // 0x171084: 0x3c021000
    ctx->pc = 0x171084u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x171088: 0x3442b410
    ctx->pc = 0x171088u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46096));
    // 0x17108c: 0x3c041000
    ctx->pc = 0x17108cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x171090: 0x8c430000
    ctx->pc = 0x171090u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x171094: 0x3484b430
    ctx->pc = 0x171094u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46128));
    // 0x171098: 0x3c051000
    ctx->pc = 0x171098u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x17109c: 0x3c061000
    ctx->pc = 0x17109cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x1710a0: 0xae03001c
    ctx->pc = 0x1710a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 3));
    // 0x1710a4: 0x34a5b420
    ctx->pc = 0x1710a4u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 46112));
    // 0x1710a8: 0x34c6b400
    ctx->pc = 0x1710a8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 46080));
    // 0x1710ac: 0x3c071000
    ctx->pc = 0x1710acu;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x1710b0: 0x8c830000
    ctx->pc = 0x1710b0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1710b4: 0x34e72010
    ctx->pc = 0x1710b4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 8208));
    // 0x1710b8: 0xae030020
    ctx->pc = 0x1710b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1710bc: 0x8ca20000
    ctx->pc = 0x1710bcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1710c0: 0xae020024
    ctx->pc = 0x1710c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x1710c4: 0x8cc30000
    ctx->pc = 0x1710c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1710c8: 0xae030028
    ctx->pc = 0x1710c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 3));
    // 0x1710cc: 0x0
    ctx->pc = 0x1710ccu;
    // NOP
label_1710d0:
    // 0x1710d0: 0x8ce20000
    ctx->pc = 0x1710d0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1710d4: 0x304200f0
    ctx->pc = 0x1710d4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 240));
    // 0x1710d8: 0x0
    ctx->pc = 0x1710d8u;
    // NOP
    // 0x1710dc: 0x0
    ctx->pc = 0x1710dcu;
    // NOP
    // 0x1710e0: 0x0
    ctx->pc = 0x1710e0u;
    // NOP
    // 0x1710e4: 0x1440fffa
    ctx->pc = 0x1710E4u;
    {
        const bool branch_taken_0x1710e4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1710e4) {
            ctx->pc = 0x1710D0u;
            goto label_1710d0;
        }
    }
    ctx->pc = 0x1710ECu;
    // 0x1710ec: 0xc05c27c
    ctx->pc = 0x1710ECu;
    SET_GPR_U32(ctx, 31, 0x1710F4u);
    ctx->pc = 0x1710F0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1709F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001709F0_0x1709f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1710F4u; }
    }
    if (ctx->pc != 0x1710F4u) { return; }
    ctx->pc = 0x1710F4u;
    // 0x1710f4: 0x3c021000
    ctx->pc = 0x1710f4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1710f8: 0x3442b010
    ctx->pc = 0x1710f8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 45072));
    // 0x1710fc: 0x3c031000
    ctx->pc = 0x1710fcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x171100: 0x8c440000
    ctx->pc = 0x171100u;
    SET_GPR_U32(ctx, 4, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x171104: 0x3463b020
    ctx->pc = 0x171104u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 45088));
    // 0x171108: 0x3c061000
    ctx->pc = 0x171108u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x17110c: 0x3c071000
    ctx->pc = 0x17110cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x171110: 0xae04002c
    ctx->pc = 0x171110u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
    // 0x171114: 0x34c6b000
    ctx->pc = 0x171114u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 45056));
    // 0x171118: 0x34e72020
    ctx->pc = 0x171118u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 8224));
    // 0x17111c: 0x3c051000
    ctx->pc = 0x17111cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x171120: 0x8c680000
    ctx->pc = 0x171120u;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x171124: 0x34a52010
    ctx->pc = 0x171124u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 8208));
    // 0x171128: 0x8e040040
    ctx->pc = 0x171128u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x17112c: 0xae080030
    ctx->pc = 0x17112cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 8));
    // 0x171130: 0x8cc20000
    ctx->pc = 0x171130u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x171134: 0xae020034
    ctx->pc = 0x171134u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x171138: 0x8ce30000
    ctx->pc = 0x171138u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x17113c: 0xae030038
    ctx->pc = 0x17113cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x171140: 0x8ca20000
    ctx->pc = 0x171140u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x171144: 0xc045190
    ctx->pc = 0x171144u;
    SET_GPR_U32(ctx, 31, 0x17114Cu);
    ctx->pc = 0x171148u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 2));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17114Cu; }
    }
    if (ctx->pc != 0x17114Cu) { return; }
    ctx->pc = 0x17114Cu;
    // 0x17114c: 0x24020001
    ctx->pc = 0x17114cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x171150: 0xdfb00000
    ctx->pc = 0x171150u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171154: 0xdfbf0008
    ctx->pc = 0x171154u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171158: 0x3e00008
    ctx->pc = 0x171158u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17115Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1710D0u: goto label_1710d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171160u;
}
