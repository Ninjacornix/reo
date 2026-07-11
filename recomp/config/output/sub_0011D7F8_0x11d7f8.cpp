#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011D7F8
// Address: 0x11d7f8 - 0x11d8f8
void sub_0011D7F8_0x11d7f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11d7f8u;

    // 0x11d7f8: 0x27bdff80
    ctx->pc = 0x11d7f8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x11d7fc: 0x3c020021
    ctx->pc = 0x11d7fcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x11d800: 0xffb50050
    ctx->pc = 0x11d800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x11d804: 0xffb40040
    ctx->pc = 0x11d804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11d808: 0x3c150012
    ctx->pc = 0x11d808u;
    SET_GPR_U32(ctx, 21, ((uint32_t)18 << 16));
    // 0x11d80c: 0xffb30030
    ctx->pc = 0x11d80cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11d810: 0x3c140012
    ctx->pc = 0x11d810u;
    SET_GPR_U32(ctx, 20, ((uint32_t)18 << 16));
    // 0x11d814: 0xffb20020
    ctx->pc = 0x11d814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11d818: 0xffb10010
    ctx->pc = 0x11d818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11d81c: 0xffb00000
    ctx->pc = 0x11d81cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11d820: 0xffbf0070
    ctx->pc = 0x11d820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x11d824: 0x2450a460
    ctx->pc = 0x11d824u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294943840));
    // 0x11d828: 0xffb60060
    ctx->pc = 0x11d828u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x11d82c: 0x8c44a460
    ctx->pc = 0x11d82cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294943840)));
    // 0x11d830: 0xc04763e
    ctx->pc = 0x11D830u;
    SET_GPR_U32(ctx, 31, 0x11D838u);
    ctx->pc = 0x11D834u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    ctx->pc = 0x11D8F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D8F8_0x11d8f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D838u; }
    }
    if (ctx->pc != 0x11D838u) { return; }
    ctx->pc = 0x11D838u;
    // 0x11d838: 0x8e05000c
    ctx->pc = 0x11d838u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x11d83c: 0xc04763e
    ctx->pc = 0x11D83Cu;
    SET_GPR_U32(ctx, 31, 0x11D844u);
    ctx->pc = 0x11D840u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    ctx->pc = 0x11D8F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D8F8_0x11d8f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D844u; }
    }
    if (ctx->pc != 0x11D844u) { return; }
    ctx->pc = 0x11D844u;
    // 0x11d844: 0x3c048000
    ctx->pc = 0x11d844u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x11d848: 0x3c058008
    ctx->pc = 0x11d848u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32776 << 16));
    // 0x11d84c: 0xc0475ec
    ctx->pc = 0x11D84Cu;
    SET_GPR_U32(ctx, 31, 0x11D854u);
    ctx->pc = 0x11D850u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 21), 4294956912));
    ctx->pc = 0x11D7B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D7B0_0x11d7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D854u; }
    }
    if (ctx->pc != 0x11D854u) { return; }
    ctx->pc = 0x11D854u;
    // 0x11d854: 0x40982d
    ctx->pc = 0x11d854u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d858: 0x3c048000
    ctx->pc = 0x11d858u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x11d85c: 0x3c058008
    ctx->pc = 0x11d85cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)32776 << 16));
    // 0x11d860: 0xc0475ec
    ctx->pc = 0x11D860u;
    SET_GPR_U32(ctx, 31, 0x11D868u);
    ctx->pc = 0x11D864u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 20), 4294956856));
    ctx->pc = 0x11D7B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D7B0_0x11d7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D868u; }
    }
    if (ctx->pc != 0x11D868u) { return; }
    ctx->pc = 0x11D868u;
    // 0x11d868: 0x2671fdf4
    ctx->pc = 0x11d868u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 19), 4294966772));
    // 0x11d86c: 0x40902d
    ctx->pc = 0x11d86cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d870: 0x2650fe98
    ctx->pc = 0x11d870u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 18), 4294966936));
    // 0x11d874: 0x12300014
    ctx->pc = 0x11D874u;
    {
        const bool branch_taken_0x11d874 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 16));
        ctx->pc = 0x11D878u;
        SET_GPR_U32(ctx, 22, ((uint32_t)33 << 16));
        if (branch_taken_0x11d874) {
            ctx->pc = 0x11D8C8u;
            goto label_11d8c8;
        }
    }
    ctx->pc = 0x11D87Cu;
    // 0x11d87c: 0x230102b
    ctx->pc = 0x11d87cu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
label_11d880:
    // 0x11d880: 0x10400007
    ctx->pc = 0x11D880u;
    {
        const bool branch_taken_0x11d880 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x11D884u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 19), 4));
        if (branch_taken_0x11d880) {
            ctx->pc = 0x11D8A0u;
            goto label_11d8a0;
        }
    }
    ctx->pc = 0x11D888u;
    // 0x11d888: 0x3c058008
    ctx->pc = 0x11d888u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32776 << 16));
    // 0x11d88c: 0xc0475ec
    ctx->pc = 0x11D88Cu;
    SET_GPR_U32(ctx, 31, 0x11D894u);
    ctx->pc = 0x11D890u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 21), 4294956912));
    ctx->pc = 0x11D7B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D7B0_0x11d7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D894u; }
    }
    if (ctx->pc != 0x11D894u) { return; }
    ctx->pc = 0x11D894u;
    // 0x11d894: 0x40982d
    ctx->pc = 0x11d894u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d898: 0x10000007
    ctx->pc = 0x11D898u;
    {
        const bool branch_taken_0x11d898 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11D89Cu;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 19), 4294966772));
        if (branch_taken_0x11d898) {
            ctx->pc = 0x11D8B8u;
            goto label_11d8b8;
        }
    }
    ctx->pc = 0x11D8A0u;
label_11d8a0:
    // 0x11d8a0: 0x26440004
    ctx->pc = 0x11d8a0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 18), 4));
    // 0x11d8a4: 0x3c058008
    ctx->pc = 0x11d8a4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32776 << 16));
    // 0x11d8a8: 0xc0475ec
    ctx->pc = 0x11D8A8u;
    SET_GPR_U32(ctx, 31, 0x11D8B0u);
    ctx->pc = 0x11D8ACu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 20), 4294956856));
    ctx->pc = 0x11D7B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D7B0_0x11d7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D8B0u; }
    }
    if (ctx->pc != 0x11D8B0u) { return; }
    ctx->pc = 0x11D8B0u;
    // 0x11d8b0: 0x40902d
    ctx->pc = 0x11d8b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d8b4: 0x2650fe98
    ctx->pc = 0x11d8b4u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 18), 4294966936));
label_11d8b8:
    // 0x11d8b8: 0x1630fff1
    ctx->pc = 0x11D8B8u;
    {
        const bool branch_taken_0x11d8b8 = (GPR_U32(ctx, 17) != GPR_U32(ctx, 16));
        ctx->pc = 0x11D8BCu;
        SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        if (branch_taken_0x11d8b8) {
            ctx->pc = 0x11D880u;
            goto label_11d880;
        }
    }
    ctx->pc = 0x11D8C0u;
    // 0x11d8c0: 0x10000002
    ctx->pc = 0x11D8C0u;
    {
        const bool branch_taken_0x11d8c0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11D8C4u;
        WRITE32(ADD32(GPR_U32(ctx, 22), 4294943832), GPR_U32(ctx, 17));
        if (branch_taken_0x11d8c0) {
            ctx->pc = 0x11D8CCu;
            goto label_11d8cc;
        }
    }
    ctx->pc = 0x11D8C8u;
label_11d8c8:
    // 0x11d8c8: 0xaed1a458
    ctx->pc = 0x11d8c8u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 4294943832), GPR_U32(ctx, 17));
label_11d8cc:
    // 0x11d8cc: 0xdfbf0070
    ctx->pc = 0x11d8ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11d8d0: 0xdfb60060
    ctx->pc = 0x11d8d0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11d8d4: 0xdfb50050
    ctx->pc = 0x11d8d4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11d8d8: 0xdfb40040
    ctx->pc = 0x11d8d8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11d8dc: 0xdfb30030
    ctx->pc = 0x11d8dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11d8e0: 0xdfb20020
    ctx->pc = 0x11d8e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11d8e4: 0xdfb10010
    ctx->pc = 0x11d8e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11d8e8: 0xdfb00000
    ctx->pc = 0x11d8e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11d8ec: 0x3e00008
    ctx->pc = 0x11D8ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D8F0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D880u: goto label_11d880;
            case 0x11D8A0u: goto label_11d8a0;
            case 0x11D8B8u: goto label_11d8b8;
            case 0x11D8C8u: goto label_11d8c8;
            case 0x11D8CCu: goto label_11d8cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D8F4u;
    // 0x11d8f4: 0x0
    ctx->pc = 0x11d8f4u;
    // NOP
}
