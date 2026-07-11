#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011E7A0
// Address: 0x11e7a0 - 0x11e870
void sub_0011E7A0_0x11e7a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11e7a0u;

    // 0x11e7a0: 0x3c031000
    ctx->pc = 0x11e7a0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x11e7a4: 0x3c040021
    ctx->pc = 0x11e7a4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x11e7a8: 0x34631000
    ctx->pc = 0x11e7a8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 4096));
    // 0x11e7ac: 0x9c620000
    ctx->pc = 0x11e7acu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11e7b0: 0x8c680010
    ctx->pc = 0x11e7b0u;
    SET_GPR_U32(ctx, 8, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 16))); // MMIO: 0x10000010
    // 0x11e7b4: 0xdc8ab3e8
    ctx->pc = 0x11e7b4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 4), 4294947816)));
    // 0x11e7b8: 0x31090800
    ctx->pc = 0x11e7b8u;
    SET_GPR_U32(ctx, 9, AND32(GPR_U32(ctx, 8), 2048));
    // 0x11e7bc: 0x11200003
    ctx->pc = 0x11E7BCu;
    {
        const bool branch_taken_0x11e7bc = (GPR_U32(ctx, 9) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E7C0u;
        SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x11e7bc) {
            ctx->pc = 0x11E7CCu;
            goto label_11e7cc;
        }
    }
    ctx->pc = 0x11E7C4u;
    // 0x11e7c4: 0x9c620000
    ctx->pc = 0x11e7c4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11e7c8: 0x654a0001
    ctx->pc = 0x11e7c8u;
    SET_GPR_S64(ctx, 10, (int64_t)GPR_S64(ctx, 10) + (int64_t)1);
label_11e7cc:
    // 0x11e7cc: 0x31080003
    ctx->pc = 0x11e7ccu;
    SET_GPR_U32(ctx, 8, AND32(GPR_U32(ctx, 8), 3));
    // 0x11e7d0: 0xa5438
    ctx->pc = 0x11e7d0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) << 16);
    // 0x11e7d4: 0x8480a
    ctx->pc = 0x11e7d4u;
    if (GPR_U32(ctx, 8) == 0) SET_GPR_U32(ctx, 9, GPR_U32(ctx, 0));
    // 0x11e7d8: 0x4a1025
    ctx->pc = 0x11e7d8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x11e7dc: 0x1094814
    ctx->pc = 0x11e7dcu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << (GPR_U32(ctx, 8) & 0x3F));
    // 0x11e7e0: 0x1221014
    ctx->pc = 0x11e7e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (GPR_U32(ctx, 9) & 0x3F));
    // 0x11e7e4: 0x3e00008
    ctx->pc = 0x11E7E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E7CCu: goto label_11e7cc;
            case 0x11E830u: goto label_11e830;
            case 0x11E85Cu: goto label_11e85c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E7ECu;
    // 0x11e7ec: 0x0
    ctx->pc = 0x11e7ecu;
    // NOP
    // 0x11e7f0: 0x27bdffe0
    ctx->pc = 0x11e7f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11e7f4: 0xffb00000
    ctx->pc = 0x11e7f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11e7f8: 0xffbf0010
    ctx->pc = 0x11e7f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11e7fc: 0xc047598
    ctx->pc = 0x11E7FCu;
    SET_GPR_U32(ctx, 31, 0x11E804u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E804u; }
    }
    if (ctx->pc != 0x11E804u) { return; }
    ctx->pc = 0x11E804u;
    // 0x11e804: 0x3c031000
    ctx->pc = 0x11e804u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x11e808: 0x3c040021
    ctx->pc = 0x11e808u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x11e80c: 0x34631000
    ctx->pc = 0x11e80cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 4096));
    // 0x11e810: 0x9c700000
    ctx->pc = 0x11e810u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11e814: 0x8c680010
    ctx->pc = 0x11e814u;
    SET_GPR_U32(ctx, 8, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 16))); // MMIO: 0x10000010
    // 0x11e818: 0xdc8ab3e8
    ctx->pc = 0x11e818u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 4), 4294947816)));
    // 0x11e81c: 0x31090800
    ctx->pc = 0x11e81cu;
    SET_GPR_U32(ctx, 9, AND32(GPR_U32(ctx, 8), 2048));
    // 0x11e820: 0x11200003
    ctx->pc = 0x11E820u;
    {
        const bool branch_taken_0x11e820 = (GPR_U32(ctx, 9) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E824u;
        SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x11e820) {
            ctx->pc = 0x11E830u;
            goto label_11e830;
        }
    }
    ctx->pc = 0x11E828u;
    // 0x11e828: 0x9c700000
    ctx->pc = 0x11e828u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11e82c: 0x654a0001
    ctx->pc = 0x11e82cu;
    SET_GPR_S64(ctx, 10, (int64_t)GPR_S64(ctx, 10) + (int64_t)1);
label_11e830:
    // 0x11e830: 0x31080003
    ctx->pc = 0x11e830u;
    SET_GPR_U32(ctx, 8, AND32(GPR_U32(ctx, 8), 3));
    // 0x11e834: 0xa5438
    ctx->pc = 0x11e834u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) << 16);
    // 0x11e838: 0x8480a
    ctx->pc = 0x11e838u;
    if (GPR_U32(ctx, 8) == 0) SET_GPR_U32(ctx, 9, GPR_U32(ctx, 0));
    // 0x11e83c: 0x20a8025
    ctx->pc = 0x11e83cu;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 16), GPR_U32(ctx, 10)));
    // 0x11e840: 0x1094814
    ctx->pc = 0x11e840u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << (GPR_U32(ctx, 8) & 0x3F));
    // 0x11e844: 0x1308014
    ctx->pc = 0x11e844u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (GPR_U32(ctx, 9) & 0x3F));
    // 0x11e848: 0x10400004
    ctx->pc = 0x11E848u;
    {
        const bool branch_taken_0x11e848 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E84Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x11e848) {
            ctx->pc = 0x11E85Cu;
            goto label_11e85c;
        }
    }
    ctx->pc = 0x11E850u;
    // 0x11e850: 0xc0475ae
    ctx->pc = 0x11E850u;
    SET_GPR_U32(ctx, 31, 0x11E858u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E858u; }
    }
    if (ctx->pc != 0x11E858u) { return; }
    ctx->pc = 0x11E858u;
    // 0x11e858: 0x200102d
    ctx->pc = 0x11e858u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_11e85c:
    // 0x11e85c: 0xdfbf0010
    ctx->pc = 0x11e85cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e860: 0xdfb00000
    ctx->pc = 0x11e860u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e864: 0x3e00008
    ctx->pc = 0x11E864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E868u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E7CCu: goto label_11e7cc;
            case 0x11E830u: goto label_11e830;
            case 0x11E85Cu: goto label_11e85c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E86Cu;
    // 0x11e86c: 0x0
    ctx->pc = 0x11e86cu;
    // NOP
}
