#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00100648
// Address: 0x100648 - 0x1006e8
void sub_00100648_0x100648(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x100648u;

    // 0x100648: 0x3c020020
    ctx->pc = 0x100648u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x10064c: 0x27bdffe0
    ctx->pc = 0x10064cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x100650: 0x8c437914
    ctx->pc = 0x100650u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 30996)));
    // 0x100654: 0xffbf0010
    ctx->pc = 0x100654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x100658: 0x10600009
    ctx->pc = 0x100658u;
    {
        const bool branch_taken_0x100658 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x10065Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        if (branch_taken_0x100658) {
            ctx->pc = 0x100680u;
            goto label_100680;
        }
    }
    ctx->pc = 0x100660u;
    // 0x100660: 0x3c030020
    ctx->pc = 0x100660u;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
    // 0x100664: 0x2402ffff
    ctx->pc = 0x100664u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x100668: 0xac627958
    ctx->pc = 0x100668u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 31064), GPR_U32(ctx, 2));
    // 0x10066c: 0x3c100020
    ctx->pc = 0x10066cu;
    SET_GPR_U32(ctx, 16, ((uint32_t)32 << 16));
    // 0x100670: 0xc045190
    ctx->pc = 0x100670u;
    SET_GPR_U32(ctx, 31, 0x100678u);
    ctx->pc = 0x100674u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 31008)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100678u; }
    }
    if (ctx->pc != 0x100678u) { return; }
    ctx->pc = 0x100678u;
    // 0x100678: 0x10000003
    ctx->pc = 0x100678u;
    {
        const bool branch_taken_0x100678 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x10067Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x100678) {
            ctx->pc = 0x100688u;
            goto label_100688;
        }
    }
    ctx->pc = 0x100680u;
label_100680:
    // 0x100680: 0x3c100020
    ctx->pc = 0x100680u;
    SET_GPR_U32(ctx, 16, ((uint32_t)32 << 16));
    // 0x100684: 0x3c020020
    ctx->pc = 0x100684u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
label_100688:
    // 0x100688: 0xc04518c
    ctx->pc = 0x100688u;
    SET_GPR_U32(ctx, 31, 0x100690u);
    ctx->pc = 0x10068Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 31016)));
    ctx->pc = 0x114630u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100690u; }
    }
    if (ctx->pc != 0x100690u) { return; }
    ctx->pc = 0x100690u;
    // 0x100690: 0x3c030020
    ctx->pc = 0x100690u;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
    // 0x100694: 0xc04518c
    ctx->pc = 0x100694u;
    SET_GPR_U32(ctx, 31, 0x10069Cu);
    ctx->pc = 0x100698u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 31020)));
    ctx->pc = 0x114630u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10069Cu; }
    }
    if (ctx->pc != 0x10069Cu) { return; }
    ctx->pc = 0x10069Cu;
    // 0x10069c: 0x3c030020
    ctx->pc = 0x10069cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
    // 0x1006a0: 0xc04518c
    ctx->pc = 0x1006A0u;
    SET_GPR_U32(ctx, 31, 0x1006A8u);
    ctx->pc = 0x1006A4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 31024)));
    ctx->pc = 0x114630u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006A8u; }
    }
    if (ctx->pc != 0x1006A8u) { return; }
    ctx->pc = 0x1006A8u;
    // 0x1006a8: 0xc04518c
    ctx->pc = 0x1006A8u;
    SET_GPR_U32(ctx, 31, 0x1006B0u);
    ctx->pc = 0x1006ACu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 31008)));
    ctx->pc = 0x114630u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006B0u; }
    }
    if (ctx->pc != 0x1006B0u) { return; }
    ctx->pc = 0x1006B0u;
    // 0x1006b0: 0xc047598
    ctx->pc = 0x1006B0u;
    SET_GPR_U32(ctx, 31, 0x1006B8u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006B8u; }
    }
    if (ctx->pc != 0x1006B8u) { return; }
    ctx->pc = 0x1006B8u;
    // 0x1006b8: 0x3c048000
    ctx->pc = 0x1006b8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x1006bc: 0x40802d
    ctx->pc = 0x1006bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1006c0: 0xc045b20
    ctx->pc = 0x1006C0u;
    SET_GPR_U32(ctx, 31, 0x1006C8u);
    ctx->pc = 0x1006C4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 18));
    ctx->pc = 0x116C80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116C80_0x116c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006C8u; }
    }
    if (ctx->pc != 0x1006C8u) { return; }
    ctx->pc = 0x1006C8u;
    // 0x1006c8: 0x12000004
    ctx->pc = 0x1006C8u;
    {
        const bool branch_taken_0x1006c8 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x1006CCu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x1006c8) {
            ctx->pc = 0x1006DCu;
            goto label_1006dc;
        }
    }
    ctx->pc = 0x1006D0u;
    // 0x1006d0: 0xdfb00000
    ctx->pc = 0x1006d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1006d4: 0x80475ae
    ctx->pc = 0x1006D4u;
    ctx->pc = 0x1006D8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x1006DCu;
label_1006dc:
    // 0x1006dc: 0xdfb00000
    ctx->pc = 0x1006dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1006e0: 0x3e00008
    ctx->pc = 0x1006E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1006E4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100680u: goto label_100680;
            case 0x100688u: goto label_100688;
            case 0x1006DCu: goto label_1006dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1006E8u;
}
