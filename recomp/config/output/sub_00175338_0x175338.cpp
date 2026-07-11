#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00175338
// Address: 0x175338 - 0x1753f0
void sub_00175338_0x175338(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x175338u;

    // 0x175338: 0x27bdffe0
    ctx->pc = 0x175338u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17533c: 0xffb00000
    ctx->pc = 0x17533cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175340: 0x80802d
    ctx->pc = 0x175340u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175344: 0xffb10008
    ctx->pc = 0x175344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175348: 0xa0882d
    ctx->pc = 0x175348u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17534c: 0xffb20010
    ctx->pc = 0x17534cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x175350: 0xc0902d
    ctx->pc = 0x175350u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175354: 0x1600000a
    ctx->pc = 0x175354u;
    {
        const bool branch_taken_0x175354 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x175358u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        if (branch_taken_0x175354) {
            ctx->pc = 0x175380u;
            goto label_175380;
        }
    }
    ctx->pc = 0x17535Cu;
    // 0x17535c: 0x220202d
    ctx->pc = 0x17535cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175360: 0xc05d4fc
    ctx->pc = 0x175360u;
    SET_GPR_U32(ctx, 31, 0x175368u);
    ctx->pc = 0x175364u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1753F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001753F0_0x1753f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175368u; }
    }
    if (ctx->pc != 0x175368u) { return; }
    ctx->pc = 0x175368u;
    // 0x175368: 0x111080
    ctx->pc = 0x175368u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 17), 2));
    // 0x17536c: 0x3c010023
    ctx->pc = 0x17536cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x175370: 0x220821
    ctx->pc = 0x175370u;
    SET_GPR_U32(ctx, 1, ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x175374: 0xac32ef88
    ctx->pc = 0x175374u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294963080), GPR_U32(ctx, 18));
    // 0x175378: 0x10000016
    ctx->pc = 0x175378u;
    {
        const bool branch_taken_0x175378 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x17537Cu;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x175378) {
            ctx->pc = 0x1753D4u;
            goto label_1753d4;
        }
    }
    ctx->pc = 0x175380u;
label_175380:
    // 0x175380: 0xc05a78c
    ctx->pc = 0x175380u;
    SET_GPR_U32(ctx, 31, 0x175388u);
    ctx->pc = 0x169E30u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175388u; }
    }
    if (ctx->pc != 0x175388u) { return; }
    ctx->pc = 0x175388u;
    // 0x175388: 0x3c05ff00
    ctx->pc = 0x175388u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x17538c: 0x10400008
    ctx->pc = 0x17538Cu;
    {
        const bool branch_taken_0x17538c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x175390u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17538c) {
            ctx->pc = 0x1753B0u;
            goto label_1753b0;
        }
    }
    ctx->pc = 0x175394u;
    // 0x175394: 0xdfb00000
    ctx->pc = 0x175394u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175398: 0x34a50112
    ctx->pc = 0x175398u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 274));
    // 0x17539c: 0xdfb10008
    ctx->pc = 0x17539cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1753a0: 0xdfb20010
    ctx->pc = 0x1753a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1753a4: 0xdfbf0018
    ctx->pc = 0x1753a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1753a8: 0x805a704
    ctx->pc = 0x1753A8u;
    ctx->pc = 0x1753ACu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x1753B0u;
label_1753b0:
    // 0x1753b0: 0x200202d
    ctx->pc = 0x1753b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753b4: 0x220282d
    ctx->pc = 0x1753b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753b8: 0xc05d518
    ctx->pc = 0x1753B8u;
    SET_GPR_U32(ctx, 31, 0x1753C0u);
    ctx->pc = 0x1753BCu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x175460u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1753C0u; }
    }
    if (ctx->pc != 0x1753C0u) { return; }
    ctx->pc = 0x1753C0u;
    // 0x1753c0: 0x200202d
    ctx->pc = 0x1753c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753c4: 0x220282d
    ctx->pc = 0x1753c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753c8: 0xc05d52c
    ctx->pc = 0x1753C8u;
    SET_GPR_U32(ctx, 31, 0x1753D0u);
    ctx->pc = 0x1753CCu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1754B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001754B0_0x1754b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1753D0u; }
    }
    if (ctx->pc != 0x1753D0u) { return; }
    ctx->pc = 0x1753D0u;
    // 0x1753d0: 0xdfb00000
    ctx->pc = 0x1753d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1753d4:
    // 0x1753d4: 0x102d
    ctx->pc = 0x1753d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1753d8: 0xdfb10008
    ctx->pc = 0x1753d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1753dc: 0xdfb20010
    ctx->pc = 0x1753dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1753e0: 0xdfbf0018
    ctx->pc = 0x1753e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1753e4: 0x3e00008
    ctx->pc = 0x1753E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1753E8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175380u: goto label_175380;
            case 0x1753B0u: goto label_1753b0;
            case 0x1753D4u: goto label_1753d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1753ECu;
    // 0x1753ec: 0x0
    ctx->pc = 0x1753ecu;
    // NOP
}
