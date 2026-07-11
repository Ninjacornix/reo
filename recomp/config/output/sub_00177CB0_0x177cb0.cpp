#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00177CB0
// Address: 0x177cb0 - 0x177d90
void sub_00177CB0_0x177cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x177cb0u;

    // 0x177cb0: 0x27bdfff0
    ctx->pc = 0x177cb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x177cb4: 0x282d
    ctx->pc = 0x177cb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177cb8: 0x240601c0
    ctx->pc = 0x177cb8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 448));
    // 0x177cbc: 0xffb00000
    ctx->pc = 0x177cbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x177cc0: 0xffbf0008
    ctx->pc = 0x177cc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x177cc4: 0xc041f1a
    ctx->pc = 0x177CC4u;
    SET_GPR_U32(ctx, 31, 0x177CCCu);
    ctx->pc = 0x177CC8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177CCCu; }
    }
    if (ctx->pc != 0x177CCCu) { return; }
    ctx->pc = 0x177CCCu;
    // 0x177ccc: 0x24030001
    ctx->pc = 0x177cccu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x177cd0: 0x2402000a
    ctx->pc = 0x177cd0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 10));
    // 0x177cd4: 0xae03000c
    ctx->pc = 0x177cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x177cd8: 0xae020010
    ctx->pc = 0x177cd8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x177cdc: 0x200202d
    ctx->pc = 0x177cdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ce0: 0xae030000
    ctx->pc = 0x177ce0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x177ce4: 0xae000004
    ctx->pc = 0x177ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x177ce8: 0xc05df64
    ctx->pc = 0x177CE8u;
    SET_GPR_U32(ctx, 31, 0x177CF0u);
    ctx->pc = 0x177CECu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    ctx->pc = 0x177D90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00177D90_0x177d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177CF0u; }
    }
    if (ctx->pc != 0x177CF0u) { return; }
    ctx->pc = 0x177CF0u;
    // 0x177cf0: 0xfe000108
    ctx->pc = 0x177cf0u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 264), GPR_U64(ctx, 0));
    // 0x177cf4: 0x3c03000f
    ctx->pc = 0x177cf4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)15 << 16));
    // 0x177cf8: 0x34634240
    ctx->pc = 0x177cf8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 16960));
    // 0x177cfc: 0x24020001
    ctx->pc = 0x177cfcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x177d00: 0x2404412b
    ctx->pc = 0x177d00u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 16683));
    // 0x177d04: 0x3c050003
    ctx->pc = 0x177d04u;
    SET_GPR_U32(ctx, 5, ((uint32_t)3 << 16));
    // 0x177d08: 0x34a50d40
    ctx->pc = 0x177d08u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 3392));
    // 0x177d0c: 0x2406ffff
    ctx->pc = 0x177d0cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x177d10: 0xfe020130
    ctx->pc = 0x177d10u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 304), GPR_U64(ctx, 2));
    // 0x177d14: 0xfe040138
    ctx->pc = 0x177d14u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 312), GPR_U64(ctx, 4));
    // 0x177d18: 0xfe050148
    ctx->pc = 0x177d18u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 328), GPR_U64(ctx, 5));
    // 0x177d1c: 0xfe030170
    ctx->pc = 0x177d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 368), GPR_U64(ctx, 3));
    // 0x177d20: 0xfe060178
    ctx->pc = 0x177d20u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 6));
    // 0x177d24: 0xae0001b8
    ctx->pc = 0x177d24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 440), GPR_U32(ctx, 0));
    // 0x177d28: 0xfe020110
    ctx->pc = 0x177d28u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 272), GPR_U64(ctx, 2));
    // 0x177d2c: 0xfe000118
    ctx->pc = 0x177d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 280), GPR_U64(ctx, 0));
    // 0x177d30: 0xfe020120
    ctx->pc = 0x177d30u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 288), GPR_U64(ctx, 2));
    // 0x177d34: 0xfe000128
    ctx->pc = 0x177d34u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 296), GPR_U64(ctx, 0));
    // 0x177d38: 0xfe030140
    ctx->pc = 0x177d38u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 320), GPR_U64(ctx, 3));
    // 0x177d3c: 0xfe030150
    ctx->pc = 0x177d3cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 336), GPR_U64(ctx, 3));
    // 0x177d40: 0xfe000158
    ctx->pc = 0x177d40u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 344), GPR_U64(ctx, 0));
    // 0x177d44: 0xfe030160
    ctx->pc = 0x177d44u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 352), GPR_U64(ctx, 3));
    // 0x177d48: 0xfe000168
    ctx->pc = 0x177d48u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 360), GPR_U64(ctx, 0));
    // 0x177d4c: 0xfe000180
    ctx->pc = 0x177d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 0));
    // 0x177d50: 0xfe000188
    ctx->pc = 0x177d50u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 392), GPR_U64(ctx, 0));
    // 0x177d54: 0xae000190
    ctx->pc = 0x177d54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 400), GPR_U32(ctx, 0));
    // 0x177d58: 0xae000194
    ctx->pc = 0x177d58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 404), GPR_U32(ctx, 0));
    // 0x177d5c: 0xae000198
    ctx->pc = 0x177d5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 408), GPR_U32(ctx, 0));
    // 0x177d60: 0xae00019c
    ctx->pc = 0x177d60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 412), GPR_U32(ctx, 0));
    // 0x177d64: 0xae0001a0
    ctx->pc = 0x177d64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 0));
    // 0x177d68: 0xae0001a4
    ctx->pc = 0x177d68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 420), GPR_U32(ctx, 0));
    // 0x177d6c: 0xae0001a8
    ctx->pc = 0x177d6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 0));
    // 0x177d70: 0xae0001ac
    ctx->pc = 0x177d70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 0));
    // 0x177d74: 0xae0001b0
    ctx->pc = 0x177d74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 432), GPR_U32(ctx, 0));
    // 0x177d78: 0xae0001b4
    ctx->pc = 0x177d78u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 436), GPR_U32(ctx, 0));
    // 0x177d7c: 0xdfbf0008
    ctx->pc = 0x177d7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177d80: 0xdfb00000
    ctx->pc = 0x177d80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177d84: 0x805e110
    ctx->pc = 0x177D84u;
    ctx->pc = 0x177D88u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x178440u;
    entry_178440_0x1785a0(rdram, ctx, runtime); return;
    ctx->pc = 0x177D8Cu;
    // 0x177d8c: 0x0
    ctx->pc = 0x177d8cu;
    // NOP
}
