#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0015E6A0
// Address: 0x15e6a0 - 0x15e818
void sub_0015E6A0_0x15e6a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x15e6a0u;

    // 0x15e6a0: 0x27bdffe0
    ctx->pc = 0x15e6a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15e6a4: 0xffb00000
    ctx->pc = 0x15e6a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15e6a8: 0x80802d
    ctx->pc = 0x15e6a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e6ac: 0xffb10008
    ctx->pc = 0x15e6acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15e6b0: 0x16000009
    ctx->pc = 0x15E6B0u;
    {
        const bool branch_taken_0x15e6b0 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x15E6B4u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        if (branch_taken_0x15e6b0) {
            ctx->pc = 0x15E6D8u;
            goto label_15e6d8;
        }
    }
    ctx->pc = 0x15E6B8u;
    // 0x15e6b8: 0x3c040024
    ctx->pc = 0x15e6b8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x15e6bc: 0xdfb00000
    ctx->pc = 0x15e6bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e6c0: 0xdfb10008
    ctx->pc = 0x15e6c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e6c4: 0x2484ee68
    ctx->pc = 0x15e6c4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294962792));
    // 0x15e6c8: 0xdfbf0010
    ctx->pc = 0x15e6c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e6cc: 0x8058dd4
    ctx->pc = 0x15E6CCu;
    ctx->pc = 0x15E6D0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x163750u;
    sub_00163750_0x163750(rdram, ctx, runtime); return;
    ctx->pc = 0x15E6D4u;
    // 0x15e6d4: 0x0
    ctx->pc = 0x15e6d4u;
    // NOP
label_15e6d8:
    // 0x15e6d8: 0x3c030027
    ctx->pc = 0x15e6d8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)39 << 16));
    // 0x15e6dc: 0x3c020024
    ctx->pc = 0x15e6dcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
    // 0x15e6e0: 0x24638538
    ctx->pc = 0x15e6e0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294935864));
    // 0x15e6e4: 0x2442edc8
    ctx->pc = 0x15e6e4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294962632));
    // 0x15e6e8: 0xac620000
    ctx->pc = 0x15e6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x15e6ec: 0xc058d20
    ctx->pc = 0x15E6ECu;
    SET_GPR_U32(ctx, 31, 0x15E6F4u);
    ctx->pc = 0x15E6F0u;
    SET_GPR_U32(ctx, 17, ((uint32_t)35 << 16));
    ctx->pc = 0x163480u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00163480_0x163480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E6F4u; }
    }
    if (ctx->pc != 0x15E6F4u) { return; }
    ctx->pc = 0x15E6F4u;
    // 0x15e6f4: 0x8e020008
    ctx->pc = 0x15e6f4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x15e6f8: 0x2442fffe
    ctx->pc = 0x15e6f8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967294));
    // 0x15e6fc: 0x28430000
    ctx->pc = 0x15e6fcu;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 2), 0));
    // 0x15e700: 0x3100b
    ctx->pc = 0x15e700u;
    if (GPR_U32(ctx, 3) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 0));
    // 0x15e704: 0xae020008
    ctx->pc = 0x15e704u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x15e708: 0x8e23de50
    ctx->pc = 0x15e708u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 4294958672)));
    // 0x15e70c: 0x54600039
    ctx->pc = 0x15E70Cu;
    {
        const bool branch_taken_0x15e70c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x15e70c) {
            ctx->pc = 0x15E710u;
            SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 17), 4294958672));
            ctx->pc = 0x15E7F4u;
            goto label_15e7f4;
        }
    }
    ctx->pc = 0x15E714u;
    // 0x15e714: 0xc04a87a
    ctx->pc = 0x15E714u;
    SET_GPR_U32(ctx, 31, 0x15E71Cu);
    ctx->pc = 0x12A1E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A1E8_0x12a1e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E71Cu; }
    }
    if (ctx->pc != 0x15E71Cu) { return; }
    ctx->pc = 0x15E71Cu;
    // 0x15e71c: 0xc04fdfe
    ctx->pc = 0x15E71Cu;
    SET_GPR_U32(ctx, 31, 0x15E724u);
    ctx->pc = 0x13F7F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F7F8_0x13f7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E724u; }
    }
    if (ctx->pc != 0x15E724u) { return; }
    ctx->pc = 0x15E724u;
    // 0x15e724: 0xc04fcb0
    ctx->pc = 0x15E724u;
    SET_GPR_U32(ctx, 31, 0x15E72Cu);
    ctx->pc = 0x13F2C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F2C0_0x13f2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E72Cu; }
    }
    if (ctx->pc != 0x15E72Cu) { return; }
    ctx->pc = 0x15E72Cu;
    // 0x15e72c: 0xc050008
    ctx->pc = 0x15E72Cu;
    SET_GPR_U32(ctx, 31, 0x15E734u);
    ctx->pc = 0x140020u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00140020_0x140020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E734u; }
    }
    if (ctx->pc != 0x15E734u) { return; }
    ctx->pc = 0x15E734u;
    // 0x15e734: 0xc059102
    ctx->pc = 0x15E734u;
    SET_GPR_U32(ctx, 31, 0x15E73Cu);
    ctx->pc = 0x164408u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00164408_0x164408(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E73Cu; }
    }
    if (ctx->pc != 0x15E73Cu) { return; }
    ctx->pc = 0x15E73Cu;
    // 0x15e73c: 0x10400006
    ctx->pc = 0x15E73Cu;
    {
        const bool branch_taken_0x15e73c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x15E740u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4294967195));
        if (branch_taken_0x15e73c) {
            ctx->pc = 0x15E758u;
            goto label_15e758;
        }
    }
    ctx->pc = 0x15E744u;
    // 0x15e744: 0xc057abc
    ctx->pc = 0x15E744u;
    SET_GPR_U32(ctx, 31, 0x15E74Cu);
    ctx->pc = 0x15EAF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E74Cu; }
    }
    if (ctx->pc != 0x15E74Cu) { return; }
    ctx->pc = 0x15E74Cu;
    // 0x15e74c: 0x3c040024
    ctx->pc = 0x15e74cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x15e750: 0xc058dd4
    ctx->pc = 0x15E750u;
    SET_GPR_U32(ctx, 31, 0x15E758u);
    ctx->pc = 0x15E754u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294962832));
    ctx->pc = 0x163750u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E758u; }
    }
    if (ctx->pc != 0x15E758u) { return; }
    ctx->pc = 0x15E758u;
label_15e758:
    // 0x15e758: 0xc057a18
    ctx->pc = 0x15E758u;
    SET_GPR_U32(ctx, 31, 0x15E760u);
    ctx->pc = 0x15E75Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x15E860u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E860_0x15e860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E760u; }
    }
    if (ctx->pc != 0x15E760u) { return; }
    ctx->pc = 0x15E760u;
    // 0x15e760: 0x3c020023
    ctx->pc = 0x15e760u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x15e764: 0xc6000000
    ctx->pc = 0x15e764u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x15e768: 0x2442ef5c
    ctx->pc = 0x15e768u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294963036));
    // 0x15e76c: 0x3c01447a
    ctx->pc = 0x15e76cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)17530 << 16));
    // 0x15e770: 0x44816000
    ctx->pc = 0x15e770u;
    *(uint32_t*)&ctx->f[12] = GPR_U32(ctx, 1);
    // 0x15e774: 0x0
    ctx->pc = 0x15e774u;
    // NOP
    // 0x15e778: 0xc04462e
    ctx->pc = 0x15E778u;
    SET_GPR_U32(ctx, 31, 0x15E780u);
    ctx->pc = 0x15E77Cu;
    ctx->f[12] = FPU_MUL_S(ctx->f[0], ctx->f[12]);
    ctx->pc = 0x1118B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E780u; }
    }
    if (ctx->pc != 0x15E780u) { return; }
    ctx->pc = 0x15E780u;
    // 0x15e780: 0x3405ff80
    ctx->pc = 0x15e780u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 0), 65408));
    // 0x15e784: 0x52bbc
    ctx->pc = 0x15e784u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x15e788: 0xc04473c
    ctx->pc = 0x15E788u;
    SET_GPR_U32(ctx, 31, 0x15E790u);
    ctx->pc = 0x15E78Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x111CF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E790u; }
    }
    if (ctx->pc != 0x15E790u) { return; }
    ctx->pc = 0x15E790u;
    // 0x15e790: 0xc0448e8
    ctx->pc = 0x15E790u;
    SET_GPR_U32(ctx, 31, 0x15E798u);
    ctx->pc = 0x15E794u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1123A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E798u; }
    }
    if (ctx->pc != 0x15E798u) { return; }
    ctx->pc = 0x15E798u;
    // 0x15e798: 0xc057ad0
    ctx->pc = 0x15E798u;
    SET_GPR_U32(ctx, 31, 0x15E7A0u);
    ctx->pc = 0x15E79Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x15EB40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EB40_0x15eb40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7A0u; }
    }
    if (ctx->pc != 0x15E7A0u) { return; }
    ctx->pc = 0x15E7A0u;
    // 0x15e7a0: 0x3c040024
    ctx->pc = 0x15e7a0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x15e7a4: 0x10400003
    ctx->pc = 0x15E7A4u;
    {
        const bool branch_taken_0x15e7a4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x15E7A8u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294962872));
        if (branch_taken_0x15e7a4) {
            ctx->pc = 0x15E7B4u;
            goto label_15e7b4;
        }
    }
    ctx->pc = 0x15E7ACu;
    // 0x15e7ac: 0xc058dd4
    ctx->pc = 0x15E7ACu;
    SET_GPR_U32(ctx, 31, 0x15E7B4u);
    ctx->pc = 0x163750u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7B4u; }
    }
    if (ctx->pc != 0x15E7B4u) { return; }
    ctx->pc = 0x15E7B4u;
label_15e7b4:
    // 0x15e7b4: 0x3c020023
    ctx->pc = 0x15e7b4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x15e7b8: 0x24030001
    ctx->pc = 0x15e7b8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x15e7bc: 0x200202d
    ctx->pc = 0x15e7bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e7c0: 0xc057a66
    ctx->pc = 0x15E7C0u;
    SET_GPR_U32(ctx, 31, 0x15E7C8u);
    ctx->pc = 0x15E998u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E998_0x15e998(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7C8u; }
    }
    if (ctx->pc != 0x15E7C8u) { return; }
    ctx->pc = 0x15E7C8u;
    // 0x15e7c8: 0xc04f566
    ctx->pc = 0x15E7C8u;
    SET_GPR_U32(ctx, 31, 0x15E7D0u);
    ctx->pc = 0x13D598u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D598_0x13d598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7D0u; }
    }
    if (ctx->pc != 0x15E7D0u) { return; }
    ctx->pc = 0x15E7D0u;
    // 0x15e7d0: 0x3c040016
    ctx->pc = 0x15e7d0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)22 << 16));
    // 0x15e7d4: 0x282d
    ctx->pc = 0x15e7d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e7d8: 0xc04f534
    ctx->pc = 0x15E7D8u;
    SET_GPR_U32(ctx, 31, 0x15E7E0u);
    ctx->pc = 0x15E7DCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294960776));
    ctx->pc = 0x13D4D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4D0_0x13d4d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7E0u; }
    }
    if (ctx->pc != 0x15E7E0u) { return; }
    ctx->pc = 0x15E7E0u;
    // 0x15e7e0: 0xc0582c0
    ctx->pc = 0x15E7E0u;
    SET_GPR_U32(ctx, 31, 0x15E7E8u);
    ctx->pc = 0x160B00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B00_0x160b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7E8u; }
    }
    if (ctx->pc != 0x15E7E8u) { return; }
    ctx->pc = 0x15E7E8u;
    // 0x15e7e8: 0xc057a06
    ctx->pc = 0x15E7E8u;
    SET_GPR_U32(ctx, 31, 0x15E7F0u);
    ctx->pc = 0x15E7ECu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x15E818u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E818_0x15e818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7F0u; }
    }
    if (ctx->pc != 0x15E7F0u) { return; }
    ctx->pc = 0x15E7F0u;
    // 0x15e7f0: 0x2623de50
    ctx->pc = 0x15e7f0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 17), 4294958672));
label_15e7f4:
    // 0x15e7f4: 0xdfb10008
    ctx->pc = 0x15e7f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e7f8: 0x8c620000
    ctx->pc = 0x15e7f8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x15e7fc: 0xdfb00000
    ctx->pc = 0x15e7fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e800: 0xdfbf0010
    ctx->pc = 0x15e800u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e804: 0x24420001
    ctx->pc = 0x15e804u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x15e808: 0xac620000
    ctx->pc = 0x15e808u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x15e80c: 0x3e00008
    ctx->pc = 0x15E80Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E810u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E6D8u: goto label_15e6d8;
            case 0x15E758u: goto label_15e758;
            case 0x15E7B4u: goto label_15e7b4;
            case 0x15E7F4u: goto label_15e7f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E814u;
    // 0x15e814: 0x0
    ctx->pc = 0x15e814u;
    // NOP
}
