#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001BB230
// Address: 0x1bb230 - 0x1bb2b0
void sub_001BB230_0x1bb230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1bb230u;

    // 0x1bb230: 0x27bdfff0
    ctx->pc = 0x1bb230u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb234: 0xffbf0000
    ctx->pc = 0x1bb234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb238: 0xc06b700
    ctx->pc = 0x1BB238u;
    SET_GPR_U32(ctx, 31, 0x1BB240u);
    ctx->pc = 0x1ADC00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADC00_0x1adc00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB240u; }
    }
    if (ctx->pc != 0x1BB240u) { return; }
    ctx->pc = 0x1BB240u;
    // 0x1bb240: 0xc06e0b8
    ctx->pc = 0x1BB240u;
    SET_GPR_U32(ctx, 31, 0x1BB248u);
    ctx->pc = 0x1B82E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82E0_0x1b82e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB248u; }
    }
    if (ctx->pc != 0x1BB248u) { return; }
    ctx->pc = 0x1BB248u;
    // 0x1bb248: 0xc06bb58
    ctx->pc = 0x1BB248u;
    SET_GPR_U32(ctx, 31, 0x1BB250u);
    ctx->pc = 0x1AED60u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AED60_0x1aed60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB250u; }
    }
    if (ctx->pc != 0x1BB250u) { return; }
    ctx->pc = 0x1BB250u;
    // 0x1bb250: 0xc06eb08
    ctx->pc = 0x1BB250u;
    SET_GPR_U32(ctx, 31, 0x1BB258u);
    ctx->pc = 0x1BAC20u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAC20_0x1bac20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB258u; }
    }
    if (ctx->pc != 0x1BB258u) { return; }
    ctx->pc = 0x1BB258u;
    // 0x1bb258: 0xc06bddc
    ctx->pc = 0x1BB258u;
    SET_GPR_U32(ctx, 31, 0x1BB260u);
    ctx->pc = 0x1AF770u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF770_0x1af770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB260u; }
    }
    if (ctx->pc != 0x1BB260u) { return; }
    ctx->pc = 0x1BB260u;
    // 0x1bb260: 0xc073254
    ctx->pc = 0x1BB260u;
    SET_GPR_U32(ctx, 31, 0x1BB268u);
    ctx->pc = 0x1CC950u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC950_0x1cc950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB268u; }
    }
    if (ctx->pc != 0x1BB268u) { return; }
    ctx->pc = 0x1BB268u;
    // 0x1bb268: 0xc06be70
    ctx->pc = 0x1BB268u;
    SET_GPR_U32(ctx, 31, 0x1BB270u);
    ctx->pc = 0x1AF9C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF9C0_0x1af9c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB270u; }
    }
    if (ctx->pc != 0x1BB270u) { return; }
    ctx->pc = 0x1BB270u;
    // 0x1bb270: 0x24020001
    ctx->pc = 0x1bb270u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb274: 0x3c010023
    ctx->pc = 0x1bb274u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bb278: 0xc06ec44
    ctx->pc = 0x1BB278u;
    SET_GPR_U32(ctx, 31, 0x1BB280u);
    ctx->pc = 0x1BB110u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB110_0x1bb110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB280u; }
    }
    if (ctx->pc != 0x1BB280u) { return; }
    ctx->pc = 0x1BB280u;
    // 0x1bb280: 0xc06bb14
    ctx->pc = 0x1BB280u;
    SET_GPR_U32(ctx, 31, 0x1BB288u);
    ctx->pc = 0x1AEC50u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC50_0x1aec50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB288u; }
    }
    if (ctx->pc != 0x1BB288u) { return; }
    ctx->pc = 0x1BB288u;
    // 0x1bb288: 0xc06df24
    ctx->pc = 0x1BB288u;
    SET_GPR_U32(ctx, 31, 0x1BB290u);
    ctx->pc = 0x1B7C90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7C90_0x1b7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB290u; }
    }
    if (ctx->pc != 0x1BB290u) { return; }
    ctx->pc = 0x1BB290u;
    // 0x1bb290: 0x3c010032
    ctx->pc = 0x1bb290u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb294: 0xac204190
    ctx->pc = 0x1bb294u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16784), GPR_U32(ctx, 0));
    // 0x1bb298: 0xdfbf0000
    ctx->pc = 0x1bb298u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb29c: 0x3e00008
    ctx->pc = 0x1BB29Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB2A0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BB2A4u;
    // 0x1bb2a4: 0x0
    ctx->pc = 0x1bb2a4u;
    // NOP
    // 0x1bb2a8: 0x0
    ctx->pc = 0x1bb2a8u;
    // NOP
    // 0x1bb2ac: 0x0
    ctx->pc = 0x1bb2acu;
    // NOP
}
