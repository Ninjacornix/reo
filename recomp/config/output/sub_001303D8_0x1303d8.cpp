#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001303D8
// Address: 0x1303d8 - 0x130420
void sub_001303D8_0x1303d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1303d8u;

    // 0x1303d8: 0x80182d
    ctx->pc = 0x1303d8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1303dc: 0x202d
    ctx->pc = 0x1303dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1303e0: 0x27bdfff0
    ctx->pc = 0x1303e0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1303e4: 0x28a20100
    ctx->pc = 0x1303e4u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), 256));
    // 0x1303e8: 0xffbf0000
    ctx->pc = 0x1303e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1303ec: 0x60382d
    ctx->pc = 0x1303ecu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1303f0: 0x10400005
    ctx->pc = 0x1303F0u;
    {
        const bool branch_taken_0x1303f0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1303F4u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1303f0) {
            ctx->pc = 0x130408u;
            goto label_130408;
        }
    }
    ctx->pc = 0x1303F8u;
    // 0x1303f8: 0xc04c086
    ctx->pc = 0x1303F8u;
    SET_GPR_U32(ctx, 31, 0x130400u);
    ctx->pc = 0x1303FCu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x130218u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00130218_0x130218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130400u; }
    }
    if (ctx->pc != 0x130400u) { return; }
    ctx->pc = 0x130400u;
    // 0x130400: 0x10000004
    ctx->pc = 0x130400u;
    {
        const bool branch_taken_0x130400 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x130404u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x130400) {
            ctx->pc = 0x130414u;
            goto label_130414;
        }
    }
    ctx->pc = 0x130408u;
label_130408:
    // 0x130408: 0xc04c0be
    ctx->pc = 0x130408u;
    SET_GPR_U32(ctx, 31, 0x130410u);
    ctx->pc = 0x13040Cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1302F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001302F8_0x1302f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130410u; }
    }
    if (ctx->pc != 0x130410u) { return; }
    ctx->pc = 0x130410u;
    // 0x130410: 0xdfbf0000
    ctx->pc = 0x130410u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_130414:
    // 0x130414: 0x3e00008
    ctx->pc = 0x130414u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130418u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130408u: goto label_130408;
            case 0x130414u: goto label_130414;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13041Cu;
    // 0x13041c: 0x0
    ctx->pc = 0x13041cu;
    // NOP
}
