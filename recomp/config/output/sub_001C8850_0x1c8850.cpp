#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001C8850
// Address: 0x1c8850 - 0x1c8930
void sub_001C8850_0x1c8850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1c8850u;

    // 0x1c8850: 0x27bdffe0
    ctx->pc = 0x1c8850u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8854: 0x3c010034
    ctx->pc = 0x1c8854u;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1c8858: 0xffbf0010
    ctx->pc = 0x1c8858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c885c: 0x7fb00000
    ctx->pc = 0x1c885cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c8860: 0x9022b200
    ctx->pc = 0x1c8860u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294947328)));
    // 0x1c8864: 0x1440000c
    ctx->pc = 0x1C8864u;
    {
        const bool branch_taken_0x1c8864 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1C8868u;
        SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
        if (branch_taken_0x1c8864) {
            ctx->pc = 0x1C8898u;
            goto label_1c8898;
        }
    }
    ctx->pc = 0x1C886Cu;
    // 0x1c886c: 0x3c011000
    ctx->pc = 0x1c886cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x1c8870: 0x24030083
    ctx->pc = 0x1c8870u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 131));
    // 0x1c8874: 0xac200810
    ctx->pc = 0x1c8874u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2064), GPR_U32(ctx, 0)); // MMIO: 0x10000810
    // 0x1c8878: 0x24020001
    ctx->pc = 0x1c8878u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c887c: 0x3c011000
    ctx->pc = 0x1c887cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x1c8880: 0xac200800
    ctx->pc = 0x1c8880u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2048), GPR_U32(ctx, 0)); // MMIO: 0x10000800
    // 0x1c8884: 0x3c011000
    ctx->pc = 0x1c8884u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x1c8888: 0xac230810
    ctx->pc = 0x1c8888u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2064), GPR_U32(ctx, 3)); // MMIO: 0x10000810
    // 0x1c888c: 0x3c010034
    ctx->pc = 0x1c888cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1c8890: 0xa022b200
    ctx->pc = 0x1c8890u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294947328), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c8894: 0x3c011000
    ctx->pc = 0x1c8894u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
label_1c8898:
    // 0x1c8898: 0x8c230800
    ctx->pc = 0x1c8898u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2048))); // MMIO: 0x10000800
    // 0x1c889c: 0x3c010034
    ctx->pc = 0x1c889cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1c88a0: 0x8c22b208
    ctx->pc = 0x1c88a0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294947336)));
    // 0x1c88a4: 0x3c010034
    ctx->pc = 0x1c88a4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1c88a8: 0x621023
    ctx->pc = 0x1c88a8u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c88ac: 0x18400019
    ctx->pc = 0x1C88ACu;
    {
        const bool branch_taken_0x1c88ac = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1C88B0u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294947336), GPR_U32(ctx, 3));
        if (branch_taken_0x1c88ac) {
            ctx->pc = 0x1C8914u;
            goto label_1c8914;
        }
    }
    ctx->pc = 0x1C88B4u;
    // 0x1c88b4: 0x44820000
    ctx->pc = 0x1c88b4u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 2);
    // 0x1c88b8: 0xc04462e
    ctx->pc = 0x1C88B8u;
    SET_GPR_U32(ctx, 31, 0x1C88C0u);
    ctx->pc = 0x1C88BCu;
    ctx->f[12] = FPU_CVT_S_W(*(int32_t*)&ctx->f[0]);
    ctx->pc = 0x1118B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88C0u; }
    }
    if (ctx->pc != 0x1C88C0u) { return; }
    ctx->pc = 0x1C88C0u;
    // 0x1c88c0: 0x3c034030
    ctx->pc = 0x1c88c0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16432 << 16));
    // 0x1c88c4: 0x40202d
    ctx->pc = 0x1c88c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c88c8: 0xc04480e
    ctx->pc = 0x1C88C8u;
    SET_GPR_U32(ctx, 31, 0x1C88D0u);
    ctx->pc = 0x1C88CCu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    ctx->pc = 0x112038u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88D0u; }
    }
    if (ctx->pc != 0x1C88D0u) { return; }
    ctx->pc = 0x1C88D0u;
    // 0x1c88d0: 0x40802d
    ctx->pc = 0x1c88d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c88d4: 0xc0448ba
    ctx->pc = 0x1C88D4u;
    SET_GPR_U32(ctx, 31, 0x1C88DCu);
    ctx->pc = 0x1C88D8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1000));
    ctx->pc = 0x1122E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88DCu; }
    }
    if (ctx->pc != 0x1C88DCu) { return; }
    ctx->pc = 0x1C88DCu;
    // 0x1c88dc: 0x200202d
    ctx->pc = 0x1c88dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c88e0: 0xc04480e
    ctx->pc = 0x1C88E0u;
    SET_GPR_U32(ctx, 31, 0x1C88E8u);
    ctx->pc = 0x1C88E4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112038u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88E8u; }
    }
    if (ctx->pc != 0x1C88E8u) { return; }
    ctx->pc = 0x1C88E8u;
    // 0x1c88e8: 0x3c010025
    ctx->pc = 0x1c88e8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)37 << 16));
    // 0x1c88ec: 0xdc242dd0
    ctx->pc = 0x1c88ecu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 1), 11728)));
    // 0x1c88f0: 0xc04476c
    ctx->pc = 0x1C88F0u;
    SET_GPR_U32(ctx, 31, 0x1C88F8u);
    ctx->pc = 0x1C88F4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x111DB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88F8u; }
    }
    if (ctx->pc != 0x1C88F8u) { return; }
    ctx->pc = 0x1C88F8u;
    // 0x1c88f8: 0xc04491c
    ctx->pc = 0x1C88F8u;
    SET_GPR_U32(ctx, 31, 0x1C8900u);
    ctx->pc = 0x1C88FCu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112470u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112470_0x112470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8900u; }
    }
    if (ctx->pc != 0x1C8900u) { return; }
    ctx->pc = 0x1C8900u;
    // 0x1c8900: 0x3c010034
    ctx->pc = 0x1c8900u;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1c8904: 0xc421b210
    ctx->pc = 0x1c8904u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294947344)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c8908: 0x46000800
    ctx->pc = 0x1c8908u;
    ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1c890c: 0x3c010034
    ctx->pc = 0x1c890cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1c8910: 0xe420b210
    ctx->pc = 0x1c8910u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 4294947344), bits); }
label_1c8914:
    // 0x1c8914: 0x3c010034
    ctx->pc = 0x1c8914u;
    SET_GPR_U32(ctx, 1, ((uint32_t)52 << 16));
    // 0x1c8918: 0xdfbf0010
    ctx->pc = 0x1c8918u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c891c: 0x7bb00000
    ctx->pc = 0x1c891cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8920: 0xc420b210
    ctx->pc = 0x1c8920u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294947344)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c8924: 0x3e00008
    ctx->pc = 0x1C8924u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8928u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8898u: goto label_1c8898;
            case 0x1C8914u: goto label_1c8914;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C892Cu;
    // 0x1c892c: 0x0
    ctx->pc = 0x1c892cu;
    // NOP
}
