#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0019F380
// Address: 0x19f380 - 0x19f430
void sub_0019F380_0x19f380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x19f380u;

    // 0x19f380: 0x27bdfff0
    ctx->pc = 0x19f380u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19f384: 0xffbf0000
    ctx->pc = 0x19f384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19f388: 0xc067d54
    ctx->pc = 0x19F388u;
    SET_GPR_U32(ctx, 31, 0x19F390u);
    ctx->pc = 0x19F550u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F550_0x19f550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F390u; }
    }
    if (ctx->pc != 0x19F390u) { return; }
    ctx->pc = 0x19F390u;
    // 0x19f390: 0x14400003
    ctx->pc = 0x19F390u;
    {
        const bool branch_taken_0x19f390 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x19f390) {
            ctx->pc = 0x19F3A0u;
            goto label_19f3a0;
        }
    }
    ctx->pc = 0x19F398u;
    // 0x19f398: 0x10000022
    ctx->pc = 0x19F398u;
    {
        const bool branch_taken_0x19f398 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19F39Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x19f398) {
            ctx->pc = 0x19F424u;
            goto label_19f424;
        }
    }
    ctx->pc = 0x19F3A0u;
label_19f3a0:
    // 0x19f3a0: 0xc063738
    ctx->pc = 0x19F3A0u;
    SET_GPR_U32(ctx, 31, 0x19F3A8u);
    ctx->pc = 0x18DCE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCE0_0x18dce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3A8u; }
    }
    if (ctx->pc != 0x19F3A8u) { return; }
    ctx->pc = 0x19F3A8u;
    // 0x19f3a8: 0x3c01002a
    ctx->pc = 0x19f3a8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f3ac: 0xac20fa04
    ctx->pc = 0x19f3acu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965764), GPR_U32(ctx, 0));
    // 0x19f3b0: 0x3c01002a
    ctx->pc = 0x19f3b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f3b4: 0xac20fa08
    ctx->pc = 0x19f3b4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965768), GPR_U32(ctx, 0));
    // 0x19f3b8: 0x3c01002a
    ctx->pc = 0x19f3b8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f3bc: 0xc067dd4
    ctx->pc = 0x19F3BCu;
    SET_GPR_U32(ctx, 31, 0x19F3C4u);
    ctx->pc = 0x19F3C0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965772), GPR_U32(ctx, 0));
    ctx->pc = 0x19F750u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F750_0x19f750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3C4u; }
    }
    if (ctx->pc != 0x19F3C4u) { return; }
    ctx->pc = 0x19F3C4u;
    // 0x19f3c4: 0x24040004
    ctx->pc = 0x19f3c4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    // 0x19f3c8: 0x24060001
    ctx->pc = 0x19f3c8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f3cc: 0x80282d
    ctx->pc = 0x19f3ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f3d0: 0x382d
    ctx->pc = 0x19f3d0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f3d4: 0xc067e04
    ctx->pc = 0x19F3D4u;
    SET_GPR_U32(ctx, 31, 0x19F3DCu);
    ctx->pc = 0x19F3D8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x19F810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F810_0x19f810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3DCu; }
    }
    if (ctx->pc != 0x19F3DCu) { return; }
    ctx->pc = 0x19F3DCu;
    // 0x19f3dc: 0x202d
    ctx->pc = 0x19f3dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f3e0: 0xc0680d4
    ctx->pc = 0x19F3E0u;
    SET_GPR_U32(ctx, 31, 0x19F3E8u);
    ctx->pc = 0x19F3E4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1A0350u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0350_0x1a0350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3E8u; }
    }
    if (ctx->pc != 0x19F3E8u) { return; }
    ctx->pc = 0x19F3E8u;
    // 0x19f3e8: 0xc068624
    ctx->pc = 0x19F3E8u;
    SET_GPR_U32(ctx, 31, 0x19F3F0u);
    ctx->pc = 0x1A1890u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1890_0x1a1890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3F0u; }
    }
    if (ctx->pc != 0x19F3F0u) { return; }
    ctx->pc = 0x19F3F0u;
label_19f3f0:
    // 0x19f3f0: 0xc044cfc
    ctx->pc = 0x19F3F0u;
    SET_GPR_U32(ctx, 31, 0x19F3F8u);
    ctx->pc = 0x19F3F4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1133F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3F8u; }
    }
    if (ctx->pc != 0x19F3F8u) { return; }
    ctx->pc = 0x19F3F8u;
    // 0x19f3f8: 0x3c01002a
    ctx->pc = 0x19f3f8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f3fc: 0xac22f9fc
    ctx->pc = 0x19f3fcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965756), GPR_U32(ctx, 2));
    // 0x19f400: 0x0
    ctx->pc = 0x19f400u;
    // NOP
    // 0x19f404: 0x1440fffa
    ctx->pc = 0x19F404u;
    {
        const bool branch_taken_0x19f404 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x19f404) {
            ctx->pc = 0x19F3F0u;
            goto label_19f3f0;
        }
    }
    ctx->pc = 0x19F40Cu;
    // 0x19f40c: 0x24030080
    ctx->pc = 0x19f40cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 128));
    // 0x19f410: 0x3c011000
    ctx->pc = 0x19f410u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x19f414: 0xac230810
    ctx->pc = 0x19f414u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2064), GPR_U32(ctx, 3)); // MMIO: 0x10000810
    // 0x19f418: 0x24020001
    ctx->pc = 0x19f418u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f41c: 0x3c011000
    ctx->pc = 0x19f41cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x19f420: 0xac200800
    ctx->pc = 0x19f420u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2048), GPR_U32(ctx, 0)); // MMIO: 0x10000800
label_19f424:
    // 0x19f424: 0xdfbf0000
    ctx->pc = 0x19f424u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19f428: 0x3e00008
    ctx->pc = 0x19F428u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19F42Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F3A0u: goto label_19f3a0;
            case 0x19F3F0u: goto label_19f3f0;
            case 0x19F424u: goto label_19f424;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19F430u;
}
