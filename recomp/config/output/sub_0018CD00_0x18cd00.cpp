#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018CD00
// Address: 0x18cd00 - 0x18ce30
void sub_0018CD00_0x18cd00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18cd00u;

    // 0x18cd00: 0x27bdffe0
    ctx->pc = 0x18cd00u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18cd04: 0xa0302d
    ctx->pc = 0x18cd04u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cd08: 0xffbf0010
    ctx->pc = 0x18cd08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18cd0c: 0x24050003
    ctx->pc = 0x18cd0cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 3));
    // 0x18cd10: 0x7fb00000
    ctx->pc = 0x18cd10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18cd14: 0x382d
    ctx->pc = 0x18cd14u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cd18: 0xc0631f0
    ctx->pc = 0x18CD18u;
    SET_GPR_U32(ctx, 31, 0x18CD20u);
    ctx->pc = 0x18CD1Cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C7C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7C0_0x18c7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CD20u; }
    }
    if (ctx->pc != 0x18CD20u) { return; }
    ctx->pc = 0x18CD20u;
    // 0x18cd20: 0x26040010
    ctx->pc = 0x18cd20u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 16));
    // 0x18cd24: 0xc063214
    ctx->pc = 0x18CD24u;
    SET_GPR_U32(ctx, 31, 0x18CD2Cu);
    ctx->pc = 0x18CD28u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x18C850u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C850_0x18c850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CD2Cu; }
    }
    if (ctx->pc != 0x18CD2Cu) { return; }
    ctx->pc = 0x18CD2Cu;
    // 0x18cd2c: 0x3c041000
    ctx->pc = 0x18cd2cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x18cd30: 0x34038001
    ctx->pc = 0x18cd30u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 0), 32769));
    // 0x18cd34: 0x4283c
    ctx->pc = 0x18cd34u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) << (32 + 0));
    // 0x18cd38: 0x652825
    ctx->pc = 0x18cd38u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x18cd3c: 0x2404000e
    ctx->pc = 0x18cd3cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 14));
    // 0x18cd40: 0xfe050020
    ctx->pc = 0x18cd40u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 32), GPR_U64(ctx, 5));
    // 0x18cd44: 0x2403003f
    ctx->pc = 0x18cd44u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 63));
    // 0x18cd48: 0xfe040028
    ctx->pc = 0x18cd48u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 40), GPR_U64(ctx, 4));
    // 0x18cd4c: 0xfe000030
    ctx->pc = 0x18cd4cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 0));
    // 0x18cd50: 0xfe030038
    ctx->pc = 0x18cd50u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 56), GPR_U64(ctx, 3));
    // 0x18cd54: 0xdfbf0010
    ctx->pc = 0x18cd54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18cd58: 0x7bb00000
    ctx->pc = 0x18cd58u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18cd5c: 0x3e00008
    ctx->pc = 0x18CD5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18CD60u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CE0Cu: goto label_18ce0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18CD64u;
    // 0x18cd64: 0x0
    ctx->pc = 0x18cd64u;
    // NOP
    // 0x18cd68: 0x0
    ctx->pc = 0x18cd68u;
    // NOP
    // 0x18cd6c: 0x0
    ctx->pc = 0x18cd6cu;
    // NOP
    // 0x18cd70: 0x27bdffe0
    ctx->pc = 0x18cd70u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18cd74: 0x3c010029
    ctx->pc = 0x18cd74u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x18cd78: 0xffbf0010
    ctx->pc = 0x18cd78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18cd7c: 0x7fb00000
    ctx->pc = 0x18cd7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18cd80: 0x8c224150
    ctx->pc = 0x18cd80u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 16720)));
    // 0x18cd84: 0x10400021
    ctx->pc = 0x18CD84u;
    {
        const bool branch_taken_0x18cd84 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x18CD88u;
        SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
        if (branch_taken_0x18cd84) {
            ctx->pc = 0x18CE0Cu;
            goto label_18ce0c;
        }
    }
    ctx->pc = 0x18CD8Cu;
    // 0x18cd8c: 0x3c030080
    ctx->pc = 0x18cd8cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)128 << 16));
    // 0x18cd90: 0x8c30fd78
    ctx->pc = 0x18cd90u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 1), 4294966648)));
    // 0x18cd94: 0x24020001
    ctx->pc = 0x18cd94u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x18cd98: 0x202d
    ctx->pc = 0x18cd98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cd9c: 0x3c011000
    ctx->pc = 0x18cd9cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x18cda0: 0xac233c00
    ctx->pc = 0x18cda0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 15360), GPR_U32(ctx, 3)); // MMIO: 0x10003c00
    // 0x18cda4: 0x3c011200
    ctx->pc = 0x18cda4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
    // 0x18cda8: 0xc0454b0
    ctx->pc = 0x18CDA8u;
    SET_GPR_U32(ctx, 31, 0x18CDB0u);
    ctx->pc = 0x18CDACu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4160), GPR_U64(ctx, 2));
    ctx->pc = 0x1152C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001152C0_0x1152c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CDB0u; }
    }
    if (ctx->pc != 0x18CDB0u) { return; }
    ctx->pc = 0x18CDB0u;
    // 0x18cdb0: 0x92070000
    ctx->pc = 0x18cdb0u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18cdb4: 0x2405ffbf
    ctx->pc = 0x18cdb4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x18cdb8: 0x30020001
    ctx->pc = 0x18cdb8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 0), 1));
    // 0x18cdbc: 0x64060040
    ctx->pc = 0x18cdbcu;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)64);
    // 0x18cdc0: 0x219c0
    ctx->pc = 0x18cdc0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 7));
    // 0x18cdc4: 0x3c010029
    ctx->pc = 0x18cdc4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x18cdc8: 0x2402ff7f
    ctx->pc = 0x18cdc8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x18cdcc: 0xe52824
    ctx->pc = 0x18cdccu;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x18cdd0: 0xa62825
    ctx->pc = 0x18cdd0u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x18cdd4: 0xa2050000
    ctx->pc = 0x18cdd4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x18cdd8: 0x92050000
    ctx->pc = 0x18cdd8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18cddc: 0xa21024
    ctx->pc = 0x18cddcu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x18cde0: 0x431025
    ctx->pc = 0x18cde0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18cde4: 0xa2020000
    ctx->pc = 0x18cde4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x18cde8: 0x8c264150
    ctx->pc = 0x18cde8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 1), 16720)));
    // 0x18cdec: 0x3c010029
    ctx->pc = 0x18cdecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x18cdf0: 0x8c254148
    ctx->pc = 0x18cdf0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 16712)));
    // 0x18cdf4: 0xc040d4c
    ctx->pc = 0x18CDF4u;
    SET_GPR_U32(ctx, 31, 0x18CDFCu);
    ctx->pc = 0x18CDF8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x103530u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00103530_0x103530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CDFCu; }
    }
    if (ctx->pc != 0x18CDFCu) { return; }
    ctx->pc = 0x18CDFCu;
    // 0x18cdfc: 0x3c010029
    ctx->pc = 0x18cdfcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x18ce00: 0xac204148
    ctx->pc = 0x18ce00u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16712), GPR_U32(ctx, 0));
    // 0x18ce04: 0x3c010029
    ctx->pc = 0x18ce04u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x18ce08: 0xac204150
    ctx->pc = 0x18ce08u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16720), GPR_U32(ctx, 0));
label_18ce0c:
    // 0x18ce0c: 0xf
    ctx->pc = 0x18ce0cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x18ce10: 0x42000038
    ctx->pc = 0x18ce10u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x18ce14: 0xdfbf0010
    ctx->pc = 0x18ce14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18ce18: 0x102d
    ctx->pc = 0x18ce18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ce1c: 0x7bb00000
    ctx->pc = 0x18ce1cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18ce20: 0x3e00008
    ctx->pc = 0x18CE20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18CE24u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CE0Cu: goto label_18ce0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18CE28u;
    // 0x18ce28: 0x0
    ctx->pc = 0x18ce28u;
    // NOP
    // 0x18ce2c: 0x0
    ctx->pc = 0x18ce2cu;
    // NOP
}
