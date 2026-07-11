#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011CF08
// Address: 0x11cf08 - 0x11cff0
void sub_0011CF08_0x11cf08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11cf08u;

    // 0x11cf08: 0x27bdffc0
    ctx->pc = 0x11cf08u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11cf0c: 0x3c020021
    ctx->pc = 0x11cf0cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x11cf10: 0xffb20020
    ctx->pc = 0x11cf10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11cf14: 0xffb10010
    ctx->pc = 0x11cf14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11cf18: 0x24120003
    ctx->pc = 0x11cf18u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 3));
    // 0x11cf1c: 0xffb00000
    ctx->pc = 0x11cf1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11cf20: 0xffbf0030
    ctx->pc = 0x11cf20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11cf24: 0x2450a188
    ctx->pc = 0x11cf24u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294943112));
    // 0x11cf28: 0x8c44a188
    ctx->pc = 0x11cf28u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294943112)));
    // 0x11cf2c: 0x26110018
    ctx->pc = 0x11cf2cu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 24));
    // 0x11cf30: 0xc0473be
    ctx->pc = 0x11CF30u;
    SET_GPR_U32(ctx, 31, 0x11CF38u);
    ctx->pc = 0x11CF34u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    ctx->pc = 0x11CEF8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CEF8_0x11cef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CF38u; }
    }
    if (ctx->pc != 0x11CF38u) { return; }
    ctx->pc = 0x11CF38u;
    // 0x11cf38: 0x3c050021
    ctx->pc = 0x11cf38u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x11cf3c: 0x3c048007
    ctx->pc = 0x11cf3cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)32775 << 16));
    // 0x11cf40: 0x24060330
    ctx->pc = 0x11cf40u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 816));
    // 0x11cf44: 0x24a59e08
    ctx->pc = 0x11cf44u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294942216));
    // 0x11cf48: 0xc0473a8
    ctx->pc = 0x11CF48u;
    SET_GPR_U32(ctx, 31, 0x11CF50u);
    ctx->pc = 0x11CF4Cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 20480));
    ctx->pc = 0x11CEA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CEA0_0x11cea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CF50u; }
    }
    if (ctx->pc != 0x11CF50u) { return; }
    ctx->pc = 0x11CF50u;
    // 0x11cf50: 0xc045228
    ctx->pc = 0x11CF50u;
    SET_GPR_U32(ctx, 31, 0x11CF58u);
    ctx->pc = 0x11CF54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CF58u; }
    }
    if (ctx->pc != 0x11CF58u) { return; }
    ctx->pc = 0x11CF58u;
    // 0x11cf58: 0xc045228
    ctx->pc = 0x11CF58u;
    SET_GPR_U32(ctx, 31, 0x11CF60u);
    ctx->pc = 0x11CF5Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CF60u; }
    }
    if (ctx->pc != 0x11CF60u) { return; }
    ctx->pc = 0x11CF60u;
    // 0x11cf60: 0x8e040008
    ctx->pc = 0x11cf60u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11cf64: 0xc0473be
    ctx->pc = 0x11CF64u;
    SET_GPR_U32(ctx, 31, 0x11CF6Cu);
    ctx->pc = 0x11CF68u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    ctx->pc = 0x11CEF8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CEF8_0x11cef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CF6Cu; }
    }
    if (ctx->pc != 0x11CF6Cu) { return; }
    ctx->pc = 0x11CF6Cu;
    // 0x11cf6c: 0x8e040010
    ctx->pc = 0x11cf6cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x11cf70: 0xc0473be
    ctx->pc = 0x11CF70u;
    SET_GPR_U32(ctx, 31, 0x11CF78u);
    ctx->pc = 0x11CF74u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 20)));
    ctx->pc = 0x11CEF8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CEF8_0x11cef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CF78u; }
    }
    if (ctx->pc != 0x11CF78u) { return; }
    ctx->pc = 0x11CF78u;
    // 0x11cf78: 0x8e240000
    ctx->pc = 0x11cf78u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11cf7c: 0x0
    ctx->pc = 0x11cf7cu;
    // NOP
label_11cf80:
    // 0x11cf80: 0xc0473ba
    ctx->pc = 0x11CF80u;
    SET_GPR_U32(ctx, 31, 0x11CF88u);
    ctx->pc = 0x11CF84u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
    ctx->pc = 0x11CEE8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CEE8_0x11cee8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CF88u; }
    }
    if (ctx->pc != 0x11CF88u) { return; }
    ctx->pc = 0x11CF88u;
    // 0x11cf88: 0x8e240000
    ctx->pc = 0x11cf88u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11cf8c: 0x40282d
    ctx->pc = 0x11cf8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cf90: 0xc0473be
    ctx->pc = 0x11CF90u;
    SET_GPR_U32(ctx, 31, 0x11CF98u);
    ctx->pc = 0x11CF94u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 8));
    ctx->pc = 0x11CEF8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CEF8_0x11cef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CF98u; }
    }
    if (ctx->pc != 0x11CF98u) { return; }
    ctx->pc = 0x11CF98u;
    // 0x11cf98: 0x2e420008
    ctx->pc = 0x11cf98u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 18), 8));
    // 0x11cf9c: 0x5440fff8
    ctx->pc = 0x11CF9Cu;
    {
        const bool branch_taken_0x11cf9c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x11cf9c) {
            ctx->pc = 0x11CFA0u;
            SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
            ctx->pc = 0x11CF80u;
            goto label_11cf80;
        }
    }
    ctx->pc = 0x11CFA4u;
    // 0x11cfa4: 0xc0473ba
    ctx->pc = 0x11CFA4u;
    SET_GPR_U32(ctx, 31, 0x11CFACu);
    ctx->pc = 0x11CFA8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x11CEE8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CEE8_0x11cee8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CFACu; }
    }
    if (ctx->pc != 0x11CFACu) { return; }
    ctx->pc = 0x11CFACu;
    // 0x11cfac: 0x3c030021
    ctx->pc = 0x11cfacu;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x11cfb0: 0xdfbf0030
    ctx->pc = 0x11cfb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11cfb4: 0xdfb20020
    ctx->pc = 0x11cfb4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11cfb8: 0xdfb10010
    ctx->pc = 0x11cfb8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11cfbc: 0xdfb00000
    ctx->pc = 0x11cfbcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11cfc0: 0xac62a180
    ctx->pc = 0x11cfc0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294943104), GPR_U32(ctx, 2));
    // 0x11cfc4: 0x3e00008
    ctx->pc = 0x11CFC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CFC8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CF80u: goto label_11cf80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CFCCu;
    // 0x11cfcc: 0x0
    ctx->pc = 0x11cfccu;
    // NOP
    // 0x11cfd0: 0x24030055
    ctx->pc = 0x11cfd0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 85));
    // 0x11cfd4: 0xc
    ctx->pc = 0x11cfd4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11cfd8: 0x3e00008
    ctx->pc = 0x11CFD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CF80u: goto label_11cf80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CFE0u;
    // 0x11cfe0: 0x2403ffab
    ctx->pc = 0x11cfe0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967211));
    // 0x11cfe4: 0xc
    ctx->pc = 0x11cfe4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11cfe8: 0x3e00008
    ctx->pc = 0x11CFE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CF80u: goto label_11cf80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CFF0u;
}
