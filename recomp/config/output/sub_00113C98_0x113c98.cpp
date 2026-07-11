#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00113C98
// Address: 0x113c98 - 0x113d80
void sub_00113C98_0x113c98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x113c98u;

    // 0x113c98: 0x27bdffe0
    ctx->pc = 0x113c98u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x113c9c: 0xffb00000
    ctx->pc = 0x113c9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x113ca0: 0x80802d
    ctx->pc = 0x113ca0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113ca4: 0xffbf0010
    ctx->pc = 0x113ca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x113ca8: 0xc044f08
    ctx->pc = 0x113CA8u;
    SET_GPR_U32(ctx, 31, 0x113CB0u);
    ctx->pc = 0x113CACu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x113C20u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113C20_0x113c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113CB0u; }
    }
    if (ctx->pc != 0x113CB0u) { return; }
    ctx->pc = 0x113CB0u;
    // 0x113cb0: 0x3c021000
    ctx->pc = 0x113cb0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113cb4: 0x3c061000
    ctx->pc = 0x113cb4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x113cb8: 0x3442b410
    ctx->pc = 0x113cb8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46096));
    // 0x113cbc: 0x34c6b430
    ctx->pc = 0x113cbcu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 46128));
    // 0x113cc0: 0x8c430000
    ctx->pc = 0x113cc0u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113cc4: 0x3c041000
    ctx->pc = 0x113cc4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x113cc8: 0x3484b420
    ctx->pc = 0x113cc8u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46112));
    // 0x113ccc: 0x3c051000
    ctx->pc = 0x113cccu;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x113cd0: 0xae030000
    ctx->pc = 0x113cd0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x113cd4: 0x34a5b400
    ctx->pc = 0x113cd4u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 46080));
    // 0x113cd8: 0x3c071000
    ctx->pc = 0x113cd8u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x113cdc: 0x8cc30000
    ctx->pc = 0x113cdcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x113ce0: 0x34e72010
    ctx->pc = 0x113ce0u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 8208));
    // 0x113ce4: 0xae030004
    ctx->pc = 0x113ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x113ce8: 0x8c820000
    ctx->pc = 0x113ce8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x113cec: 0xae020008
    ctx->pc = 0x113cecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x113cf0: 0x8ca30000
    ctx->pc = 0x113cf0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x113cf4: 0xae03000c
    ctx->pc = 0x113cf4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
label_113cf8:
    // 0x113cf8: 0x8ce20000
    ctx->pc = 0x113cf8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x113cfc: 0x304200f0
    ctx->pc = 0x113cfcu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 240));
    // 0x113d00: 0x0
    ctx->pc = 0x113d00u;
    // NOP
    // 0x113d04: 0x0
    ctx->pc = 0x113d04u;
    // NOP
    // 0x113d08: 0x0
    ctx->pc = 0x113d08u;
    // NOP
    // 0x113d0c: 0x1440fffa
    ctx->pc = 0x113D0Cu;
    {
        const bool branch_taken_0x113d0c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x113d0c) {
            ctx->pc = 0x113CF8u;
            goto label_113cf8;
        }
    }
    ctx->pc = 0x113D14u;
    // 0x113d14: 0xc044eea
    ctx->pc = 0x113D14u;
    SET_GPR_U32(ctx, 31, 0x113D1Cu);
    ctx->pc = 0x113D18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x113BA8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113BA8_0x113ba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113D1Cu; }
    }
    if (ctx->pc != 0x113D1Cu) { return; }
    ctx->pc = 0x113D1Cu;
    // 0x113d1c: 0x3c021000
    ctx->pc = 0x113d1cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113d20: 0x3c071000
    ctx->pc = 0x113d20u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x113d24: 0x3442b010
    ctx->pc = 0x113d24u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 45072));
    // 0x113d28: 0x34e7b020
    ctx->pc = 0x113d28u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 45088));
    // 0x113d2c: 0x8c430000
    ctx->pc = 0x113d2cu;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113d30: 0x3c051000
    ctx->pc = 0x113d30u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x113d34: 0x34a5b000
    ctx->pc = 0x113d34u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 45056));
    // 0x113d38: 0x3c061000
    ctx->pc = 0x113d38u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x113d3c: 0xae030010
    ctx->pc = 0x113d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x113d40: 0x34c62020
    ctx->pc = 0x113d40u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 8224));
    // 0x113d44: 0x3c041000
    ctx->pc = 0x113d44u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x113d48: 0xdfbf0010
    ctx->pc = 0x113d48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x113d4c: 0x8ce30000
    ctx->pc = 0x113d4cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x113d50: 0x34842010
    ctx->pc = 0x113d50u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 8208));
    // 0x113d54: 0xae030014
    ctx->pc = 0x113d54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x113d58: 0x8ca20000
    ctx->pc = 0x113d58u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x113d5c: 0xae020018
    ctx->pc = 0x113d5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 2));
    // 0x113d60: 0x8cc30000
    ctx->pc = 0x113d60u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x113d64: 0xae03001c
    ctx->pc = 0x113d64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 3));
    // 0x113d68: 0x8c820000
    ctx->pc = 0x113d68u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x113d6c: 0xae020020
    ctx->pc = 0x113d6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x113d70: 0xdfb00000
    ctx->pc = 0x113d70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113d74: 0x3e00008
    ctx->pc = 0x113D74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113D78u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113CF8u: goto label_113cf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113D7Cu;
    // 0x113d7c: 0x0
    ctx->pc = 0x113d7cu;
    // NOP
}
