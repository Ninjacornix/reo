#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0019F810
// Address: 0x19f810 - 0x1a0350
void sub_0019F810_0x19f810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x19f810u;

    // 0x19f810: 0x27bdffb0
    ctx->pc = 0x19f810u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x19f814: 0x3c01002a
    ctx->pc = 0x19f814u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f818: 0xffbf0040
    ctx->pc = 0x19f818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19f81c: 0x24020001
    ctx->pc = 0x19f81cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f820: 0x7fb30030
    ctx->pc = 0x19f820u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19f824: 0x7fb20020
    ctx->pc = 0x19f824u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19f828: 0x80982d
    ctx->pc = 0x19f828u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f82c: 0x7fb10010
    ctx->pc = 0x19f82cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19f830: 0xa0902d
    ctx->pc = 0x19f830u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f834: 0x7fb00000
    ctx->pc = 0x19f834u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19f838: 0xac27f9b0
    ctx->pc = 0x19f838u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965680), GPR_U32(ctx, 7));
    // 0x19f83c: 0x3c01002a
    ctx->pc = 0x19f83cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f840: 0xac26f9b4
    ctx->pc = 0x19f840u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965684), GPR_U32(ctx, 6));
    // 0x19f844: 0x3c01002a
    ctx->pc = 0x19f844u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f848: 0xac33f9c8
    ctx->pc = 0x19f848u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965704), GPR_U32(ctx, 19));
    // 0x19f84c: 0x3c01002a
    ctx->pc = 0x19f84cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f850: 0xac32f9e0
    ctx->pc = 0x19f850u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965728), GPR_U32(ctx, 18));
    // 0x19f854: 0x3c01002a
    ctx->pc = 0x19f854u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f858: 0xac20fd6c
    ctx->pc = 0x19f858u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966636), GPR_U32(ctx, 0));
    // 0x19f85c: 0x3c01002a
    ctx->pc = 0x19f85cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f860: 0x11020006
    ctx->pc = 0x19F860u;
    {
        const bool branch_taken_0x19f860 = (GPR_U32(ctx, 8) == GPR_U32(ctx, 2));
        ctx->pc = 0x19F864u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966640), GPR_U32(ctx, 0));
        if (branch_taken_0x19f860) {
            ctx->pc = 0x19F87Cu;
            goto label_19f87c;
        }
    }
    ctx->pc = 0x19F868u;
    // 0x19f868: 0x24020003
    ctx->pc = 0x19f868u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x19f86c: 0x3c01002a
    ctx->pc = 0x19f86cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f870: 0x24110280
    ctx->pc = 0x19f870u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 640));
    // 0x19f874: 0x10000005
    ctx->pc = 0x19F874u;
    {
        const bool branch_taken_0x19f874 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19F878u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294965700), GPR_U32(ctx, 2));
        if (branch_taken_0x19f874) {
            ctx->pc = 0x19F88Cu;
            goto label_19f88c;
        }
    }
    ctx->pc = 0x19F87Cu;
label_19f87c:
    // 0x19f87c: 0x24020004
    ctx->pc = 0x19f87cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x19f880: 0x3c01002a
    ctx->pc = 0x19f880u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f884: 0x24110200
    ctx->pc = 0x19f884u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 512));
    // 0x19f888: 0xac22f9c4
    ctx->pc = 0x19f888u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965700), GPR_U32(ctx, 2));
label_19f88c:
    // 0x19f88c: 0x14c00031
    ctx->pc = 0x19F88Cu;
    {
        const bool branch_taken_0x19f88c = (GPR_U32(ctx, 6) != GPR_U32(ctx, 0));
        ctx->pc = 0x19F890u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x19f88c) {
            ctx->pc = 0x19F954u;
            goto label_19f954;
        }
    }
    ctx->pc = 0x19F894u;
    // 0x19f894: 0x24020002
    ctx->pc = 0x19f894u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x19f898: 0x10e20020
    ctx->pc = 0x19F898u;
    {
        const bool branch_taken_0x19f898 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 2));
        ctx->pc = 0x19F89Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x19f898) {
            ctx->pc = 0x19F91Cu;
            goto label_19f91c;
        }
    }
    ctx->pc = 0x19F8A0u;
    // 0x19f8a0: 0x24050001
    ctx->pc = 0x19f8a0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f8a4: 0x10e50010
    ctx->pc = 0x19F8A4u;
    {
        const bool branch_taken_0x19f8a4 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 5));
        ctx->pc = 0x19F8A8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x19f8a4) {
            ctx->pc = 0x19F8E8u;
            goto label_19f8e8;
        }
    }
    ctx->pc = 0x19F8ACu;
    // 0x19f8ac: 0x24050001
    ctx->pc = 0x19f8acu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f8b0: 0x202d
    ctx->pc = 0x19f8b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f8b4: 0x24060002
    ctx->pc = 0x19f8b4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
    // 0x19f8b8: 0xc04495a
    ctx->pc = 0x19F8B8u;
    SET_GPR_U32(ctx, 31, 0x19F8C0u);
    ctx->pc = 0x19F8BCu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112568u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112568_0x112568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F8C0u; }
    }
    if (ctx->pc != 0x19F8C0u) { return; }
    ctx->pc = 0x19F8C0u;
    // 0x19f8c0: 0x2403027c
    ctx->pc = 0x19f8c0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 636));
    // 0x19f8c4: 0x3c01002a
    ctx->pc = 0x19f8c4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f8c8: 0xac23fd64
    ctx->pc = 0x19f8c8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966628), GPR_U32(ctx, 3));
    // 0x19f8cc: 0x24020032
    ctx->pc = 0x19f8ccu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 50));
    // 0x19f8d0: 0x3c01002a
    ctx->pc = 0x19f8d0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f8d4: 0x241000e0
    ctx->pc = 0x19f8d4u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 224));
    // 0x19f8d8: 0x240401c0
    ctx->pc = 0x19f8d8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 448));
    // 0x19f8dc: 0x1000004a
    ctx->pc = 0x19F8DCu;
    {
        const bool branch_taken_0x19f8dc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19F8E0u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966632), GPR_U32(ctx, 2));
        if (branch_taken_0x19f8dc) {
            ctx->pc = 0x19FA08u;
            goto label_19fa08;
        }
    }
    ctx->pc = 0x19F8E4u;
    // 0x19f8e4: 0x202d
    ctx->pc = 0x19f8e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19f8e8:
    // 0x19f8e8: 0x24060003
    ctx->pc = 0x19f8e8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 3));
    // 0x19f8ec: 0xc04495a
    ctx->pc = 0x19F8ECu;
    SET_GPR_U32(ctx, 31, 0x19F8F4u);
    ctx->pc = 0x19F8F0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112568u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112568_0x112568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F8F4u; }
    }
    if (ctx->pc != 0x19F8F4u) { return; }
    ctx->pc = 0x19F8F4u;
    // 0x19f8f4: 0x24030290
    ctx->pc = 0x19f8f4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 656));
    // 0x19f8f8: 0x3c01002a
    ctx->pc = 0x19f8f8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f8fc: 0xac23fd64
    ctx->pc = 0x19f8fcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966628), GPR_U32(ctx, 3));
    // 0x19f900: 0x24020062
    ctx->pc = 0x19f900u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 98));
    // 0x19f904: 0x3c01002a
    ctx->pc = 0x19f904u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f908: 0x241000e0
    ctx->pc = 0x19f908u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 224));
    // 0x19f90c: 0x240401c0
    ctx->pc = 0x19f90cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 448));
    // 0x19f910: 0x1000003d
    ctx->pc = 0x19F910u;
    {
        const bool branch_taken_0x19f910 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19F914u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966632), GPR_U32(ctx, 2));
        if (branch_taken_0x19f910) {
            ctx->pc = 0x19FA08u;
            goto label_19fa08;
        }
    }
    ctx->pc = 0x19F918u;
    // 0x19f918: 0x24050001
    ctx->pc = 0x19f918u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_19f91c:
    // 0x19f91c: 0x202d
    ctx->pc = 0x19f91cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f920: 0x24060003
    ctx->pc = 0x19f920u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 3));
    // 0x19f924: 0xc04495a
    ctx->pc = 0x19F924u;
    SET_GPR_U32(ctx, 31, 0x19F92Cu);
    ctx->pc = 0x19F928u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112568u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112568_0x112568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F92Cu; }
    }
    if (ctx->pc != 0x19F92Cu) { return; }
    ctx->pc = 0x19F92Cu;
    // 0x19f92c: 0x24030290
    ctx->pc = 0x19f92cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 656));
    // 0x19f930: 0x3c01002a
    ctx->pc = 0x19f930u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f934: 0xac23fd64
    ctx->pc = 0x19f934u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966628), GPR_U32(ctx, 3));
    // 0x19f938: 0x24020048
    ctx->pc = 0x19f938u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 72));
    // 0x19f93c: 0x3c01002a
    ctx->pc = 0x19f93cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f940: 0x24100100
    ctx->pc = 0x19f940u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 256));
    // 0x19f944: 0x24040200
    ctx->pc = 0x19f944u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 512));
    // 0x19f948: 0x1000002f
    ctx->pc = 0x19F948u;
    {
        const bool branch_taken_0x19f948 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19F94Cu;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966632), GPR_U32(ctx, 2));
        if (branch_taken_0x19f948) {
            ctx->pc = 0x19FA08u;
            goto label_19fa08;
        }
    }
    ctx->pc = 0x19F950u;
    // 0x19f950: 0x24020002
    ctx->pc = 0x19f950u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
label_19f954:
    // 0x19f954: 0x10e20020
    ctx->pc = 0x19F954u;
    {
        const bool branch_taken_0x19f954 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 2));
        ctx->pc = 0x19F958u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x19f954) {
            ctx->pc = 0x19F9D8u;
            goto label_19f9d8;
        }
    }
    ctx->pc = 0x19F95Cu;
    // 0x19f95c: 0x24050001
    ctx->pc = 0x19f95cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f960: 0x10e50010
    ctx->pc = 0x19F960u;
    {
        const bool branch_taken_0x19f960 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 5));
        ctx->pc = 0x19F964u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x19f960) {
            ctx->pc = 0x19F9A4u;
            goto label_19f9a4;
        }
    }
    ctx->pc = 0x19F968u;
    // 0x19f968: 0x202d
    ctx->pc = 0x19f968u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f96c: 0x24050001
    ctx->pc = 0x19f96cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f970: 0x24060002
    ctx->pc = 0x19f970u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
    // 0x19f974: 0xc04495a
    ctx->pc = 0x19F974u;
    SET_GPR_U32(ctx, 31, 0x19F97Cu);
    ctx->pc = 0x19F978u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112568u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112568_0x112568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F97Cu; }
    }
    if (ctx->pc != 0x19F97Cu) { return; }
    ctx->pc = 0x19F97Cu;
    // 0x19f97c: 0x2402027c
    ctx->pc = 0x19f97cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 636));
    // 0x19f980: 0x3c01002a
    ctx->pc = 0x19f980u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f984: 0xac22fd64
    ctx->pc = 0x19f984u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966628), GPR_U32(ctx, 2));
    // 0x19f988: 0x241001c0
    ctx->pc = 0x19f988u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 448));
    // 0x19f98c: 0x24020032
    ctx->pc = 0x19f98cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 50));
    // 0x19f990: 0x3c01002a
    ctx->pc = 0x19f990u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f994: 0x200202d
    ctx->pc = 0x19f994u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f998: 0x1000001b
    ctx->pc = 0x19F998u;
    {
        const bool branch_taken_0x19f998 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19F99Cu;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966632), GPR_U32(ctx, 2));
        if (branch_taken_0x19f998) {
            ctx->pc = 0x19FA08u;
            goto label_19fa08;
        }
    }
    ctx->pc = 0x19F9A0u;
    // 0x19f9a0: 0x202d
    ctx->pc = 0x19f9a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19f9a4:
    // 0x19f9a4: 0x24060003
    ctx->pc = 0x19f9a4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 3));
    // 0x19f9a8: 0xc04495a
    ctx->pc = 0x19F9A8u;
    SET_GPR_U32(ctx, 31, 0x19F9B0u);
    ctx->pc = 0x19F9ACu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112568u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112568_0x112568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F9B0u; }
    }
    if (ctx->pc != 0x19F9B0u) { return; }
    ctx->pc = 0x19F9B0u;
    // 0x19f9b0: 0x24020290
    ctx->pc = 0x19f9b0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 656));
    // 0x19f9b4: 0x3c01002a
    ctx->pc = 0x19f9b4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f9b8: 0xac22fd64
    ctx->pc = 0x19f9b8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966628), GPR_U32(ctx, 2));
    // 0x19f9bc: 0x241001c0
    ctx->pc = 0x19f9bcu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 448));
    // 0x19f9c0: 0x24020062
    ctx->pc = 0x19f9c0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 98));
    // 0x19f9c4: 0x3c01002a
    ctx->pc = 0x19f9c4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f9c8: 0x200202d
    ctx->pc = 0x19f9c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f9cc: 0x1000000e
    ctx->pc = 0x19F9CCu;
    {
        const bool branch_taken_0x19f9cc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19F9D0u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966632), GPR_U32(ctx, 2));
        if (branch_taken_0x19f9cc) {
            ctx->pc = 0x19FA08u;
            goto label_19fa08;
        }
    }
    ctx->pc = 0x19F9D4u;
    // 0x19f9d4: 0x202d
    ctx->pc = 0x19f9d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19f9d8:
    // 0x19f9d8: 0x24050001
    ctx->pc = 0x19f9d8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f9dc: 0x24060003
    ctx->pc = 0x19f9dcu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 3));
    // 0x19f9e0: 0xc04495a
    ctx->pc = 0x19F9E0u;
    SET_GPR_U32(ctx, 31, 0x19F9E8u);
    ctx->pc = 0x19F9E4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112568u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112568_0x112568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F9E8u; }
    }
    if (ctx->pc != 0x19F9E8u) { return; }
    ctx->pc = 0x19F9E8u;
    // 0x19f9e8: 0x24020290
    ctx->pc = 0x19f9e8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 656));
    // 0x19f9ec: 0x3c01002a
    ctx->pc = 0x19f9ecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19f9f0: 0xac22fd64
    ctx->pc = 0x19f9f0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966628), GPR_U32(ctx, 2));
    // 0x19f9f4: 0x24100200
    ctx->pc = 0x19f9f4u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 512));
    // 0x19f9f8: 0x24020048
    ctx->pc = 0x19f9f8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 72));
    // 0x19f9fc: 0x3c01002a
    ctx->pc = 0x19f9fcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa00: 0x200202d
    ctx->pc = 0x19fa00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19fa04: 0xac22fd68
    ctx->pc = 0x19fa04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966632), GPR_U32(ctx, 2));
label_19fa08:
    // 0x19fa08: 0x3c01002a
    ctx->pc = 0x19fa08u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa0c: 0x24020004
    ctx->pc = 0x19fa0cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x19fa10: 0xac24f9c0
    ctx->pc = 0x19fa10u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965696), GPR_U32(ctx, 4));
    // 0x19fa14: 0x3c01002a
    ctx->pc = 0x19fa14u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa18: 0xac31fed8
    ctx->pc = 0x19fa18u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967000), GPR_U32(ctx, 17));
    // 0x19fa1c: 0x3c01002a
    ctx->pc = 0x19fa1cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa20: 0xac30fed0
    ctx->pc = 0x19fa20u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966992), GPR_U32(ctx, 16));
    // 0x19fa24: 0x3c01002a
    ctx->pc = 0x19fa24u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa28: 0xac31f9bc
    ctx->pc = 0x19fa28u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965692), GPR_U32(ctx, 17));
    // 0x19fa2c: 0x3c01002a
    ctx->pc = 0x19fa2cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa30: 0x8c23f9c8
    ctx->pc = 0x19fa30u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294965704)));
    // 0x19fa34: 0x1062001b
    ctx->pc = 0x19FA34u;
    {
        const bool branch_taken_0x19fa34 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x19fa34) {
            ctx->pc = 0x19FAA4u;
            goto label_19faa4;
        }
    }
    ctx->pc = 0x19FA3Cu;
    // 0x19fa3c: 0x24020003
    ctx->pc = 0x19fa3cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x19fa40: 0x1062000f
    ctx->pc = 0x19FA40u;
    {
        const bool branch_taken_0x19fa40 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x19FA44u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x19fa40) {
            ctx->pc = 0x19FA80u;
            goto label_19fa80;
        }
    }
    ctx->pc = 0x19FA48u;
    // 0x19fa48: 0x24020002
    ctx->pc = 0x19fa48u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x19fa4c: 0x10620003
    ctx->pc = 0x19FA4Cu;
    {
        const bool branch_taken_0x19fa4c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x19fa4c) {
            ctx->pc = 0x19FA5Cu;
            goto label_19fa5c;
        }
    }
    ctx->pc = 0x19FA54u;
    // 0x19fa54: 0x10000013
    ctx->pc = 0x19FA54u;
    {
        const bool branch_taken_0x19fa54 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x19fa54) {
            ctx->pc = 0x19FAA4u;
            goto label_19faa4;
        }
    }
    ctx->pc = 0x19FA5Cu;
label_19fa5c:
    // 0x19fa5c: 0x3c01002a
    ctx->pc = 0x19fa5cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa60: 0xac22f9cc
    ctx->pc = 0x19fa60u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965708), GPR_U32(ctx, 2));
    // 0x19fa64: 0x24020040
    ctx->pc = 0x19fa64u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 64));
    // 0x19fa68: 0x3c01002a
    ctx->pc = 0x19fa68u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa6c: 0xac22f9d0
    ctx->pc = 0x19fa6cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965712), GPR_U32(ctx, 2));
    // 0x19fa70: 0x3c01002a
    ctx->pc = 0x19fa70u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa74: 0x10000013
    ctx->pc = 0x19FA74u;
    {
        const bool branch_taken_0x19fa74 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19FA78u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294965716), GPR_U32(ctx, 2));
        if (branch_taken_0x19fa74) {
            ctx->pc = 0x19FAC4u;
            goto label_19fac4;
        }
    }
    ctx->pc = 0x19FA7Cu;
    // 0x19fa7c: 0x24020001
    ctx->pc = 0x19fa7cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_19fa80:
    // 0x19fa80: 0x3c01002a
    ctx->pc = 0x19fa80u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa84: 0xac22f9cc
    ctx->pc = 0x19fa84u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965708), GPR_U32(ctx, 2));
    // 0x19fa88: 0x24030040
    ctx->pc = 0x19fa88u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
    // 0x19fa8c: 0x3c01002a
    ctx->pc = 0x19fa8cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa90: 0x24020020
    ctx->pc = 0x19fa90u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 32));
    // 0x19fa94: 0xac23f9d0
    ctx->pc = 0x19fa94u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965712), GPR_U32(ctx, 3));
    // 0x19fa98: 0x3c01002a
    ctx->pc = 0x19fa98u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fa9c: 0x10000009
    ctx->pc = 0x19FA9Cu;
    {
        const bool branch_taken_0x19fa9c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19FAA0u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294965716), GPR_U32(ctx, 2));
        if (branch_taken_0x19fa9c) {
            ctx->pc = 0x19FAC4u;
            goto label_19fac4;
        }
    }
    ctx->pc = 0x19FAA4u;
label_19faa4:
    // 0x19faa4: 0x3c01002a
    ctx->pc = 0x19faa4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19faa8: 0x24020040
    ctx->pc = 0x19faa8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 64));
    // 0x19faac: 0xac20f9cc
    ctx->pc = 0x19faacu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965708), GPR_U32(ctx, 0));
    // 0x19fab0: 0x3c01002a
    ctx->pc = 0x19fab0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fab4: 0xac22f9d0
    ctx->pc = 0x19fab4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965712), GPR_U32(ctx, 2));
    // 0x19fab8: 0x24020020
    ctx->pc = 0x19fab8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 32));
    // 0x19fabc: 0x3c01002a
    ctx->pc = 0x19fabcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fac0: 0xac22f9d4
    ctx->pc = 0x19fac0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965716), GPR_U32(ctx, 2));
label_19fac4:
    // 0x19fac4: 0x3c01002a
    ctx->pc = 0x19fac4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fac8: 0x8c25f9d0
    ctx->pc = 0x19fac8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965712)));
    // 0x19facc: 0x3c01002a
    ctx->pc = 0x19faccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fad0: 0x2251021
    ctx->pc = 0x19fad0u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
    // 0x19fad4: 0x8c24f9d4
    ctx->pc = 0x19fad4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 4294965716)));
    // 0x19fad8: 0x2442ffff
    ctx->pc = 0x19fad8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x19fadc: 0x2041821
    ctx->pc = 0x19fadcu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x19fae0: 0x2463ffff
    ctx->pc = 0x19fae0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x19fae4: 0x64001b
    ctx->pc = 0x19fae4u;
    { uint32_t divisor = GPR_U32(ctx, 4); if (divisor != 0) { ctx->lo = GPR_U32(ctx, 3) / divisor; ctx->hi = GPR_U32(ctx, 4) % divisor; } else { ctx->lo = 0xFFFFFFFF; ctx->hi = GPR_U32(ctx,3); } }
    // 0x19fae8: 0x0
    ctx->pc = 0x19fae8u;
    // NOP
    // 0x19faec: 0x0
    ctx->pc = 0x19faecu;
    // NOP
    // 0x19faf0: 0x1812
    ctx->pc = 0x19faf0u;
    SET_GPR_U32(ctx, 3, ctx->lo);
    // 0x19faf4: 0x45001b
    ctx->pc = 0x19faf4u;
    { uint32_t divisor = GPR_U32(ctx, 5); if (divisor != 0) { ctx->lo = GPR_U32(ctx, 2) / divisor; ctx->hi = GPR_U32(ctx, 5) % divisor; } else { ctx->lo = 0xFFFFFFFF; ctx->hi = GPR_U32(ctx,2); } }
    // 0x19faf8: 0x0
    ctx->pc = 0x19faf8u;
    // NOP
    // 0x19fafc: 0x0
    ctx->pc = 0x19fafcu;
    // NOP
    // 0x19fb00: 0x1012
    ctx->pc = 0x19fb00u;
    SET_GPR_U32(ctx, 2, ctx->lo);
    // 0x19fb04: 0xa21018
    ctx->pc = 0x19fb04u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x19fb08: 0x621018
    ctx->pc = 0x19fb08u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x19fb0c: 0x821018
    ctx->pc = 0x19fb0cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x19fb10: 0x2629818
    ctx->pc = 0x19fb10u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 19, (int32_t)(uint32_t)result); }
    // 0x19fb14: 0xc067238
    ctx->pc = 0x19FB14u;
    SET_GPR_U32(ctx, 31, 0x19FB1Cu);
    ctx->pc = 0x19FB18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x19C8E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019C8E0_0x19c8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19FB1Cu; }
    }
    if (ctx->pc != 0x19FB1Cu) { return; }
    ctx->pc = 0x19FB1Cu;
    // 0x19fb1c: 0x3042ffff
    ctx->pc = 0x19fb1cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65535));
    // 0x19fb20: 0x3c01002a
    ctx->pc = 0x19fb20u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fb24: 0x260202d
    ctx->pc = 0x19fb24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19fb28: 0xc067238
    ctx->pc = 0x19FB28u;
    SET_GPR_U32(ctx, 31, 0x19FB30u);
    ctx->pc = 0x19FB2Cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965720), GPR_U32(ctx, 2));
    ctx->pc = 0x19C8E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019C8E0_0x19c8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19FB30u; }
    }
    if (ctx->pc != 0x19FB30u) { return; }
    ctx->pc = 0x19FB30u;
    // 0x19fb30: 0x3c01002a
    ctx->pc = 0x19fb30u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fb34: 0x3042ffff
    ctx->pc = 0x19fb34u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65535));
    // 0x19fb38: 0x8c24f9e0
    ctx->pc = 0x19fb38u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 4294965728)));
    // 0x19fb3c: 0x3c01002a
    ctx->pc = 0x19fb3cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fb40: 0xac22f9dc
    ctx->pc = 0x19fb40u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965724), GPR_U32(ctx, 2));
    // 0x19fb44: 0x24020004
    ctx->pc = 0x19fb44u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x19fb48: 0x1082002f
    ctx->pc = 0x19FB48u;
    {
        const bool branch_taken_0x19fb48 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        if (branch_taken_0x19fb48) {
            ctx->pc = 0x19FC08u;
            goto label_19fc08;
        }
    }
    ctx->pc = 0x19FB50u;
    // 0x19fb50: 0x24020003
    ctx->pc = 0x19fb50u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x19fb54: 0x1082001d
    ctx->pc = 0x19FB54u;
    {
        const bool branch_taken_0x19fb54 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x19FB58u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 49));
        if (branch_taken_0x19fb54) {
            ctx->pc = 0x19FBCCu;
            goto label_19fbcc;
        }
    }
    ctx->pc = 0x19FB5Cu;
    // 0x19fb5c: 0x24030002
    ctx->pc = 0x19fb5cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x19fb60: 0x10830003
    ctx->pc = 0x19FB60u;
    {
        const bool branch_taken_0x19fb60 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x19fb60) {
            ctx->pc = 0x19FB70u;
            goto label_19fb70;
        }
    }
    ctx->pc = 0x19FB68u;
    // 0x19fb68: 0x10000027
    ctx->pc = 0x19FB68u;
    {
        const bool branch_taken_0x19fb68 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x19fb68) {
            ctx->pc = 0x19FC08u;
            goto label_19fc08;
        }
    }
    ctx->pc = 0x19FB70u;
label_19fb70:
    // 0x19fb70: 0x3c01002a
    ctx->pc = 0x19fb70u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fb74: 0x8c22f9c8
    ctx->pc = 0x19fb74u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294965704)));
    // 0x19fb78: 0x14430006
    ctx->pc = 0x19FB78u;
    {
        const bool branch_taken_0x19fb78 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x19FB7Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 58));
        if (branch_taken_0x19fb78) {
            ctx->pc = 0x19FB94u;
            goto label_19fb94;
        }
    }
    ctx->pc = 0x19FB80u;
    // 0x19fb80: 0x24020032
    ctx->pc = 0x19fb80u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 50));
    // 0x19fb84: 0x3c01002a
    ctx->pc = 0x19fb84u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fb88: 0x10000004
    ctx->pc = 0x19FB88u;
    {
        const bool branch_taken_0x19fb88 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19FB8Cu;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294965732), GPR_U32(ctx, 2));
        if (branch_taken_0x19fb88) {
            ctx->pc = 0x19FB9Cu;
            goto label_19fb9c;
        }
    }
    ctx->pc = 0x19FB90u;
    // 0x19fb90: 0x2402003a
    ctx->pc = 0x19fb90u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 58));
label_19fb94:
    // 0x19fb94: 0x3c01002a
    ctx->pc = 0x19fb94u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fb98: 0xac22f9e4
    ctx->pc = 0x19fb98u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965732), GPR_U32(ctx, 2));
label_19fb9c:
    // 0x19fb9c: 0x3402ffff
    ctx->pc = 0x19fb9cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 65535));
    // 0x19fba0: 0x24030040
    ctx->pc = 0x19fba0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
    // 0x19fba4: 0x44820000
    ctx->pc = 0x19fba4u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 2);
    // 0x19fba8: 0x3c01002a
    ctx->pc = 0x19fba8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fbac: 0xac23f9e8
    ctx->pc = 0x19fbacu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965736), GPR_U32(ctx, 3));
    // 0x19fbb0: 0x46800020
    ctx->pc = 0x19fbb0u;
    ctx->f[0] = FPU_CVT_S_W(*(int32_t*)&ctx->f[0]);
    // 0x19fbb4: 0x3c01002a
    ctx->pc = 0x19fbb4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fbb8: 0xac23f9ec
    ctx->pc = 0x19fbb8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965740), GPR_U32(ctx, 3));
    // 0x19fbbc: 0x3c01002a
    ctx->pc = 0x19fbbcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fbc0: 0x10000028
    ctx->pc = 0x19FBC0u;
    {
        const bool branch_taken_0x19fbc0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19FBC4u;
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 4294965748), bits); }
        if (branch_taken_0x19fbc0) {
            ctx->pc = 0x19FC64u;
            goto label_19fc64;
        }
    }
    ctx->pc = 0x19FBC8u;
    // 0x19fbc8: 0x24030031
    ctx->pc = 0x19fbc8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 49));
label_19fbcc:
    // 0x19fbcc: 0x3c01002a
    ctx->pc = 0x19fbccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fbd0: 0xac23f9e4
    ctx->pc = 0x19fbd0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965732), GPR_U32(ctx, 3));
    // 0x19fbd4: 0x24020040
    ctx->pc = 0x19fbd4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 64));
    // 0x19fbd8: 0x3c01002a
    ctx->pc = 0x19fbd8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fbdc: 0x24030020
    ctx->pc = 0x19fbdcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
    // 0x19fbe0: 0xac22f9e8
    ctx->pc = 0x19fbe0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965736), GPR_U32(ctx, 2));
    // 0x19fbe4: 0x3c0200ff
    ctx->pc = 0x19fbe4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)255 << 16));
    // 0x19fbe8: 0x3c01002a
    ctx->pc = 0x19fbe8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fbec: 0x3442ff28
    ctx->pc = 0x19fbecu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65320));
    // 0x19fbf0: 0xac23f9ec
    ctx->pc = 0x19fbf0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965740), GPR_U32(ctx, 3));
    // 0x19fbf4: 0x44820000
    ctx->pc = 0x19fbf4u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 2);
    // 0x19fbf8: 0x3c01002a
    ctx->pc = 0x19fbf8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fbfc: 0x46800020
    ctx->pc = 0x19fbfcu;
    ctx->f[0] = FPU_CVT_S_W(*(int32_t*)&ctx->f[0]);
    // 0x19fc00: 0x10000018
    ctx->pc = 0x19FC00u;
    {
        const bool branch_taken_0x19fc00 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19FC04u;
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 4294965748), bits); }
        if (branch_taken_0x19fc00) {
            ctx->pc = 0x19FC64u;
            goto label_19fc64;
        }
    }
    ctx->pc = 0x19FC08u;
label_19fc08:
    // 0x19fc08: 0x3c01002a
    ctx->pc = 0x19fc08u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fc0c: 0x24020002
    ctx->pc = 0x19fc0cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x19fc10: 0x8c23f9c8
    ctx->pc = 0x19fc10u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294965704)));
    // 0x19fc14: 0x14620005
    ctx->pc = 0x19FC14u;
    {
        const bool branch_taken_0x19fc14 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x19FC18u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 48));
        if (branch_taken_0x19fc14) {
            ctx->pc = 0x19FC2Cu;
            goto label_19fc2c;
        }
    }
    ctx->pc = 0x19FC1Cu;
    // 0x19fc1c: 0x2402000a
    ctx->pc = 0x19fc1cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 10));
    // 0x19fc20: 0x3c01002a
    ctx->pc = 0x19fc20u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fc24: 0xac22f9cc
    ctx->pc = 0x19fc24u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965708), GPR_U32(ctx, 2));
    // 0x19fc28: 0x24030030
    ctx->pc = 0x19fc28u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 48));
label_19fc2c:
    // 0x19fc2c: 0x3c01002a
    ctx->pc = 0x19fc2cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fc30: 0xac23f9e4
    ctx->pc = 0x19fc30u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965732), GPR_U32(ctx, 3));
    // 0x19fc34: 0x24020040
    ctx->pc = 0x19fc34u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 64));
    // 0x19fc38: 0x3c01002a
    ctx->pc = 0x19fc38u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fc3c: 0x24030020
    ctx->pc = 0x19fc3cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
    // 0x19fc40: 0xac22f9e8
    ctx->pc = 0x19fc40u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965736), GPR_U32(ctx, 2));
    // 0x19fc44: 0x3c0200ff
    ctx->pc = 0x19fc44u;
    SET_GPR_U32(ctx, 2, ((uint32_t)255 << 16));
    // 0x19fc48: 0x3c01002a
    ctx->pc = 0x19fc48u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fc4c: 0x3442ff28
    ctx->pc = 0x19fc4cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65320));
    // 0x19fc50: 0xac23f9ec
    ctx->pc = 0x19fc50u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965740), GPR_U32(ctx, 3));
    // 0x19fc54: 0x44820000
    ctx->pc = 0x19fc54u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 2);
    // 0x19fc58: 0x3c01002a
    ctx->pc = 0x19fc58u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fc5c: 0x46800020
    ctx->pc = 0x19fc5cu;
    ctx->f[0] = FPU_CVT_S_W(*(int32_t*)&ctx->f[0]);
    // 0x19fc60: 0xe420f9f4
    ctx->pc = 0x19fc60u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 4294965748), bits); }
label_19fc64:
    // 0x19fc64: 0x3c01002a
    ctx->pc = 0x19fc64u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fc68: 0x8c25f9ec
    ctx->pc = 0x19fc68u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965740)));
    // 0x19fc6c: 0x3c01002a
    ctx->pc = 0x19fc6cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fc70: 0x2051021
    ctx->pc = 0x19fc70u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x19fc74: 0x8c24f9e8
    ctx->pc = 0x19fc74u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 4294965736)));
    // 0x19fc78: 0x2442ffff
    ctx->pc = 0x19fc78u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x19fc7c: 0x2241821
    ctx->pc = 0x19fc7cu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x19fc80: 0x2463ffff
    ctx->pc = 0x19fc80u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x19fc84: 0x64001b
    ctx->pc = 0x19fc84u;
    { uint32_t divisor = GPR_U32(ctx, 4); if (divisor != 0) { ctx->lo = GPR_U32(ctx, 3) / divisor; ctx->hi = GPR_U32(ctx, 4) % divisor; } else { ctx->lo = 0xFFFFFFFF; ctx->hi = GPR_U32(ctx,3); } }
    // 0x19fc88: 0x0
    ctx->pc = 0x19fc88u;
    // NOP
    // 0x19fc8c: 0x0
    ctx->pc = 0x19fc8cu;
    // NOP
    // 0x19fc90: 0x1812
    ctx->pc = 0x19fc90u;
    SET_GPR_U32(ctx, 3, ctx->lo);
    // 0x19fc94: 0x831818
    ctx->pc = 0x19fc94u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
    // 0x19fc98: 0x45001b
    ctx->pc = 0x19fc98u;
    { uint32_t divisor = GPR_U32(ctx, 5); if (divisor != 0) { ctx->lo = GPR_U32(ctx, 2) / divisor; ctx->hi = GPR_U32(ctx, 5) % divisor; } else { ctx->lo = 0xFFFFFFFF; ctx->hi = GPR_U32(ctx,2); } }
    // 0x19fc9c: 0x0
    ctx->pc = 0x19fc9cu;
    // NOP
    // 0x19fca0: 0x0
    ctx->pc = 0x19fca0u;
    // NOP
    // 0x19fca4: 0x1012
    ctx->pc = 0x19fca4u;
    SET_GPR_U32(ctx, 2, ctx->lo);
    // 0x19fca8: 0x70a21018
    ctx->pc = 0x19fca8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 2); ctx->lo1 = (uint32_t)result; ctx->hi1 = (uint32_t)(result >> 32); }
    // 0x19fcac: 0x621018
    ctx->pc = 0x19fcacu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x19fcb0: 0xc067238
    ctx->pc = 0x19FCB0u;
    SET_GPR_U32(ctx, 31, 0x19FCB8u);
    ctx->pc = 0x19FCB4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)(uint32_t)result); }
    ctx->pc = 0x19C8E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019C8E0_0x19c8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19FCB8u; }
    }
    if (ctx->pc != 0x19FCB8u) { return; }
    ctx->pc = 0x19FCB8u;
    // 0x19fcb8: 0x3c01002a
    ctx->pc = 0x19fcb8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fcbc: 0x3042ffff
    ctx->pc = 0x19fcbcu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65535));
    // 0x19fcc0: 0xac20fd5c
    ctx->pc = 0x19fcc0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966620), GPR_U32(ctx, 0));
    // 0x19fcc4: 0x24030800
    ctx->pc = 0x19fcc4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2048));
    // 0x19fcc8: 0x3c01002a
    ctx->pc = 0x19fcc8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fccc: 0xac22f9f0
    ctx->pc = 0x19fcccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965744), GPR_U32(ctx, 2));
    // 0x19fcd0: 0x3c01002a
    ctx->pc = 0x19fcd0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fcd4: 0x111043
    ctx->pc = 0x19fcd4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 17), 1));
    // 0x19fcd8: 0xac20fd60
    ctx->pc = 0x19fcd8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966624), GPR_U32(ctx, 0));
    // 0x19fcdc: 0x621023
    ctx->pc = 0x19fcdcu;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x19fce0: 0x3c01002a
    ctx->pc = 0x19fce0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fce4: 0xac31fe84
    ctx->pc = 0x19fce4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966916), GPR_U32(ctx, 17));
    // 0x19fce8: 0x3c01002a
    ctx->pc = 0x19fce8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fcec: 0xac22fd54
    ctx->pc = 0x19fcecu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966612), GPR_U32(ctx, 2));
    // 0x19fcf0: 0x3c01002a
    ctx->pc = 0x19fcf0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fcf4: 0x101043
    ctx->pc = 0x19fcf4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 16), 1));
    // 0x19fcf8: 0xac30fe88
    ctx->pc = 0x19fcf8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966920), GPR_U32(ctx, 16));
    // 0x19fcfc: 0x621023
    ctx->pc = 0x19fcfcu;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x19fd00: 0x3c01002a
    ctx->pc = 0x19fd00u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd04: 0xac22fd58
    ctx->pc = 0x19fd04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966616), GPR_U32(ctx, 2));
    // 0x19fd08: 0x3c01002a
    ctx->pc = 0x19fd08u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd0c: 0x24020004
    ctx->pc = 0x19fd0cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x19fd10: 0xac20fe90
    ctx->pc = 0x19fd10u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966928), GPR_U32(ctx, 0));
    // 0x19fd14: 0x3c01002a
    ctx->pc = 0x19fd14u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd18: 0xac20fe80
    ctx->pc = 0x19fd18u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966912), GPR_U32(ctx, 0));
    // 0x19fd1c: 0x3c01002a
    ctx->pc = 0x19fd1cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd20: 0x8c24f9c8
    ctx->pc = 0x19fd20u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 4294965704)));
    // 0x19fd24: 0x2241818
    ctx->pc = 0x19fd24u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
    // 0x19fd28: 0x3c01002a
    ctx->pc = 0x19fd28u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd2c: 0xac24fe94
    ctx->pc = 0x19fd2cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966932), GPR_U32(ctx, 4));
    // 0x19fd30: 0x3c01002a
    ctx->pc = 0x19fd30u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd34: 0x10820043
    ctx->pc = 0x19FD34u;
    {
        const bool branch_taken_0x19fd34 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x19FD38u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966924), GPR_U32(ctx, 3));
        if (branch_taken_0x19fd34) {
            ctx->pc = 0x19FE44u;
            goto label_19fe44;
        }
    }
    ctx->pc = 0x19FD3Cu;
    // 0x19fd3c: 0x24020003
    ctx->pc = 0x19fd3cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x19fd40: 0x10820024
    ctx->pc = 0x19FD40u;
    {
        const bool branch_taken_0x19fd40 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        if (branch_taken_0x19fd40) {
            ctx->pc = 0x19FDD4u;
            goto label_19fdd4;
        }
    }
    ctx->pc = 0x19FD48u;
    // 0x19fd48: 0x24020002
    ctx->pc = 0x19fd48u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x19fd4c: 0x10820003
    ctx->pc = 0x19FD4Cu;
    {
        const bool branch_taken_0x19fd4c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        if (branch_taken_0x19fd4c) {
            ctx->pc = 0x19FD5Cu;
            goto label_19fd5c;
        }
    }
    ctx->pc = 0x19FD54u;
    // 0x19fd54: 0x10000057
    ctx->pc = 0x19FD54u;
    {
        const bool branch_taken_0x19fd54 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x19fd54) {
            ctx->pc = 0x19FEB4u;
            goto label_19feb4;
        }
    }
    ctx->pc = 0x19FD5Cu;
label_19fd5c:
    // 0x19fd5c: 0x3c01002a
    ctx->pc = 0x19fd5cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd60: 0x24050005
    ctx->pc = 0x19fd60u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 5));
    // 0x19fd64: 0xac20fe9c
    ctx->pc = 0x19fd64u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966940), GPR_U32(ctx, 0));
    // 0x19fd68: 0x2402000a
    ctx->pc = 0x19fd68u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 10));
    // 0x19fd6c: 0x3c01002a
    ctx->pc = 0x19fd6cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd70: 0x2404001f
    ctx->pc = 0x19fd70u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 31));
    // 0x19fd74: 0xac25fe98
    ctx->pc = 0x19fd74u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966936), GPR_U32(ctx, 5));
    // 0x19fd78: 0x24030001
    ctx->pc = 0x19fd78u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19fd7c: 0x3c01002a
    ctx->pc = 0x19fd7cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd80: 0xac22feb4
    ctx->pc = 0x19fd80u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966964), GPR_U32(ctx, 2));
    // 0x19fd84: 0x3c01002a
    ctx->pc = 0x19fd84u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd88: 0x2402000f
    ctx->pc = 0x19fd88u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 15));
    // 0x19fd8c: 0xac24fea0
    ctx->pc = 0x19fd8cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966944), GPR_U32(ctx, 4));
    // 0x19fd90: 0x3c01002a
    ctx->pc = 0x19fd90u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd94: 0xac25fea8
    ctx->pc = 0x19fd94u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966952), GPR_U32(ctx, 5));
    // 0x19fd98: 0x3c01002a
    ctx->pc = 0x19fd98u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fd9c: 0xac22fec0
    ctx->pc = 0x19fd9cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966976), GPR_U32(ctx, 2));
    // 0x19fda0: 0x3c01002a
    ctx->pc = 0x19fda0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fda4: 0xac25feb0
    ctx->pc = 0x19fda4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966960), GPR_U32(ctx, 5));
    // 0x19fda8: 0x3c01002a
    ctx->pc = 0x19fda8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fdac: 0xac25fea4
    ctx->pc = 0x19fdacu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966948), GPR_U32(ctx, 5));
    // 0x19fdb0: 0x3c01002a
    ctx->pc = 0x19fdb0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fdb4: 0xac24feb8
    ctx->pc = 0x19fdb4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966968), GPR_U32(ctx, 4));
    // 0x19fdb8: 0x3c01002a
    ctx->pc = 0x19fdb8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fdbc: 0xac24feac
    ctx->pc = 0x19fdbcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966956), GPR_U32(ctx, 4));
    // 0x19fdc0: 0x3c01002a
    ctx->pc = 0x19fdc0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fdc4: 0xac23febc
    ctx->pc = 0x19fdc4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966972), GPR_U32(ctx, 3));
    // 0x19fdc8: 0x3c01002a
    ctx->pc = 0x19fdc8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fdcc: 0x10000039
    ctx->pc = 0x19FDCCu;
    {
        const bool branch_taken_0x19fdcc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19FDD0u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966980), GPR_U32(ctx, 3));
        if (branch_taken_0x19fdcc) {
            ctx->pc = 0x19FEB4u;
            goto label_19feb4;
        }
    }
    ctx->pc = 0x19FDD4u;
label_19fdd4:
    // 0x19fdd4: 0x3c01002a
    ctx->pc = 0x19fdd4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fdd8: 0x24030008
    ctx->pc = 0x19fdd8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
    // 0x19fddc: 0xac20febc
    ctx->pc = 0x19fddcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966972), GPR_U32(ctx, 0));
    // 0x19fde0: 0x24020010
    ctx->pc = 0x19fde0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 16));
    // 0x19fde4: 0x3c01002a
    ctx->pc = 0x19fde4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fde8: 0xac23fe98
    ctx->pc = 0x19fde8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966936), GPR_U32(ctx, 3));
    // 0x19fdec: 0x3c01002a
    ctx->pc = 0x19fdecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fdf0: 0xac22feb4
    ctx->pc = 0x19fdf0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966964), GPR_U32(ctx, 2));
    // 0x19fdf4: 0x240200ff
    ctx->pc = 0x19fdf4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 255));
    // 0x19fdf8: 0x3c01002a
    ctx->pc = 0x19fdf8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fdfc: 0xac22fea0
    ctx->pc = 0x19fdfcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966944), GPR_U32(ctx, 2));
    // 0x19fe00: 0x3c01002a
    ctx->pc = 0x19fe00u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe04: 0xac23fea4
    ctx->pc = 0x19fe04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966948), GPR_U32(ctx, 3));
    // 0x19fe08: 0x3c01002a
    ctx->pc = 0x19fe08u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe0c: 0xac23fea8
    ctx->pc = 0x19fe0cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966952), GPR_U32(ctx, 3));
    // 0x19fe10: 0x3c01002a
    ctx->pc = 0x19fe10u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe14: 0xac23feb0
    ctx->pc = 0x19fe14u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966960), GPR_U32(ctx, 3));
    // 0x19fe18: 0x3c01002a
    ctx->pc = 0x19fe18u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe1c: 0xac22feac
    ctx->pc = 0x19fe1cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966956), GPR_U32(ctx, 2));
    // 0x19fe20: 0x3c01002a
    ctx->pc = 0x19fe20u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe24: 0xac22feb8
    ctx->pc = 0x19fe24u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966968), GPR_U32(ctx, 2));
    // 0x19fe28: 0x3c01002a
    ctx->pc = 0x19fe28u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe2c: 0xac20fec0
    ctx->pc = 0x19fe2cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966976), GPR_U32(ctx, 0));
    // 0x19fe30: 0x3c01002a
    ctx->pc = 0x19fe30u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe34: 0xac20fec4
    ctx->pc = 0x19fe34u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966980), GPR_U32(ctx, 0));
    // 0x19fe38: 0x3c01002a
    ctx->pc = 0x19fe38u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe3c: 0x1000001d
    ctx->pc = 0x19FE3Cu;
    {
        const bool branch_taken_0x19fe3c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19FE40u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966940), GPR_U32(ctx, 0));
        if (branch_taken_0x19fe3c) {
            ctx->pc = 0x19FEB4u;
            goto label_19feb4;
        }
    }
    ctx->pc = 0x19FE44u;
label_19fe44:
    // 0x19fe44: 0x3c01002a
    ctx->pc = 0x19fe44u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe48: 0x24040008
    ctx->pc = 0x19fe48u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8));
    // 0x19fe4c: 0xac20fe9c
    ctx->pc = 0x19fe4cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966940), GPR_U32(ctx, 0));
    // 0x19fe50: 0x24020010
    ctx->pc = 0x19fe50u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 16));
    // 0x19fe54: 0x3c01002a
    ctx->pc = 0x19fe54u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe58: 0x240300ff
    ctx->pc = 0x19fe58u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 255));
    // 0x19fe5c: 0xac24fe98
    ctx->pc = 0x19fe5cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966936), GPR_U32(ctx, 4));
    // 0x19fe60: 0x3c01002a
    ctx->pc = 0x19fe60u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe64: 0xac22feb4
    ctx->pc = 0x19fe64u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966964), GPR_U32(ctx, 2));
    // 0x19fe68: 0x3c01002a
    ctx->pc = 0x19fe68u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe6c: 0x24020018
    ctx->pc = 0x19fe6cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 24));
    // 0x19fe70: 0xac23fea0
    ctx->pc = 0x19fe70u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966944), GPR_U32(ctx, 3));
    // 0x19fe74: 0x3c01002a
    ctx->pc = 0x19fe74u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe78: 0xac22fec0
    ctx->pc = 0x19fe78u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966976), GPR_U32(ctx, 2));
    // 0x19fe7c: 0x3c01002a
    ctx->pc = 0x19fe7cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe80: 0xac24fea4
    ctx->pc = 0x19fe80u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966948), GPR_U32(ctx, 4));
    // 0x19fe84: 0x3c01002a
    ctx->pc = 0x19fe84u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe88: 0xac24fea8
    ctx->pc = 0x19fe88u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966952), GPR_U32(ctx, 4));
    // 0x19fe8c: 0x3c01002a
    ctx->pc = 0x19fe8cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe90: 0xac23feac
    ctx->pc = 0x19fe90u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966956), GPR_U32(ctx, 3));
    // 0x19fe94: 0x3c01002a
    ctx->pc = 0x19fe94u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fe98: 0xac24feb0
    ctx->pc = 0x19fe98u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966960), GPR_U32(ctx, 4));
    // 0x19fe9c: 0x3c01002a
    ctx->pc = 0x19fe9cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fea0: 0xac24febc
    ctx->pc = 0x19fea0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966972), GPR_U32(ctx, 4));
    // 0x19fea4: 0x3c01002a
    ctx->pc = 0x19fea4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fea8: 0xac23feb8
    ctx->pc = 0x19fea8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966968), GPR_U32(ctx, 3));
    // 0x19feac: 0x3c01002a
    ctx->pc = 0x19feacu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19feb0: 0xac23fec4
    ctx->pc = 0x19feb0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966980), GPR_U32(ctx, 3));
label_19feb4:
    // 0x19feb4: 0xc065794
    ctx->pc = 0x19FEB4u;
    SET_GPR_U32(ctx, 31, 0x19FEBCu);
    ctx->pc = 0x195E50u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00195E50_0x195e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19FEBCu; }
    }
    if (ctx->pc != 0x19FEBCu) { return; }
    ctx->pc = 0x19FEBCu;
    // 0x19febc: 0x3c01002a
    ctx->pc = 0x19febcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fec0: 0x3c11002a
    ctx->pc = 0x19fec0u;
    SET_GPR_U32(ctx, 17, ((uint32_t)42 << 16));
    // 0x19fec4: 0xac20fa00
    ctx->pc = 0x19fec4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965760), GPR_U32(ctx, 0));
    // 0x19fec8: 0x2631f870
    ctx->pc = 0x19fec8u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 4294965360));
    // 0x19fecc: 0x24020001
    ctx->pc = 0x19feccu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19fed0: 0x3c01002a
    ctx->pc = 0x19fed0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fed4: 0x3c10002a
    ctx->pc = 0x19fed4u;
    SET_GPR_U32(ctx, 16, ((uint32_t)42 << 16));
    // 0x19fed8: 0xac22f9fc
    ctx->pc = 0x19fed8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965756), GPR_U32(ctx, 2));
    // 0x19fedc: 0x220202d
    ctx->pc = 0x19fedcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19fee0: 0x24050009
    ctx->pc = 0x19fee0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 9));
    // 0x19fee4: 0x302d
    ctx->pc = 0x19fee4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19fee8: 0x382d
    ctx->pc = 0x19fee8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19feec: 0xc0631f0
    ctx->pc = 0x19FEECu;
    SET_GPR_U32(ctx, 31, 0x19FEF4u);
    ctx->pc = 0x19FEF0u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294965520));
    ctx->pc = 0x18C7C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7C0_0x18c7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19FEF4u; }
    }
    if (ctx->pc != 0x19FEF4u) { return; }
    ctx->pc = 0x19FEF4u;
    // 0x19fef4: 0x200202d
    ctx->pc = 0x19fef4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19fef8: 0x24050009
    ctx->pc = 0x19fef8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 9));
    // 0x19fefc: 0x302d
    ctx->pc = 0x19fefcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ff00: 0xc0631f0
    ctx->pc = 0x19FF00u;
    SET_GPR_U32(ctx, 31, 0x19FF08u);
    ctx->pc = 0x19FF04u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C7C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7C0_0x18c7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19FF08u; }
    }
    if (ctx->pc != 0x19FF08u) { return; }
    ctx->pc = 0x19FF08u;
    // 0x19ff08: 0x3c021000
    ctx->pc = 0x19ff08u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x19ff0c: 0x3c01002a
    ctx->pc = 0x19ff0cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ff10: 0x2203c
    ctx->pc = 0x19ff10u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 0));
    // 0x19ff14: 0x34038008
    ctx->pc = 0x19ff14u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 0), 32776));
    // 0x19ff18: 0x2402000e
    ctx->pc = 0x19ff18u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14));
    // 0x19ff1c: 0x641825
    ctx->pc = 0x19ff1cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x19ff20: 0xfc22f888
    ctx->pc = 0x19ff20u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965384), GPR_U64(ctx, 2));
    // 0x19ff24: 0x3c01002a
    ctx->pc = 0x19ff24u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ff28: 0xfc23f880
    ctx->pc = 0x19ff28u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965376), GPR_U64(ctx, 3));
    // 0x19ff2c: 0xfe030010
    ctx->pc = 0x19ff2cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 16), GPR_U64(ctx, 3));
    // 0x19ff30: 0x3c01002a
    ctx->pc = 0x19ff30u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ff34: 0xfe020018
    ctx->pc = 0x19ff34u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 24), GPR_U64(ctx, 2));
    // 0x19ff38: 0x8c23fed8
    ctx->pc = 0x19ff38u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x19ff3c: 0x4610003
    ctx->pc = 0x19FF3Cu;
    {
        const bool branch_taken_0x19ff3c = (GPR_S32(ctx, 3) >= 0);
        ctx->pc = 0x19FF40u;
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 6));
        if (branch_taken_0x19ff3c) {
            ctx->pc = 0x19FF4Cu;
            goto label_19ff4c;
        }
    }
    ctx->pc = 0x19FF44u;
    // 0x19ff44: 0x2462003f
    ctx->pc = 0x19ff44u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 3), 63));
    // 0x19ff48: 0x21183
    ctx->pc = 0x19ff48u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 6));
label_19ff4c:
    // 0x19ff4c: 0x3c01002a
    ctx->pc = 0x19ff4cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ff50: 0x2103c
    ctx->pc = 0x19ff50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x19ff54: 0x9c28f9cc
    ctx->pc = 0x19ff54u;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x19ff58: 0x2103f
    ctx->pc = 0x19ff58u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x19ff5c: 0x23438
    ctx->pc = 0x19ff5cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << 16);
    // 0x19ff60: 0x24050001
    ctx->pc = 0x19ff60u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19ff64: 0x2403004c
    ctx->pc = 0x19ff64u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 76));
    // 0x19ff68: 0x2402004d
    ctx->pc = 0x19ff68u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 77));
    // 0x19ff6c: 0x5203c
    ctx->pc = 0x19ff6cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) << (32 + 0));
    // 0x19ff70: 0x240b004e
    ctx->pc = 0x19ff70u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 0), 78));
    // 0x19ff74: 0x240a004f
    ctx->pc = 0x19ff74u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 79));
    // 0x19ff78: 0x24090018
    ctx->pc = 0x19ff78u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 24));
    // 0x19ff7c: 0x3c01002a
    ctx->pc = 0x19ff7cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ff80: 0x87638
    ctx->pc = 0x19ff80u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 8) << 24);
    // 0x19ff84: 0x8c27f9dc
    ctx->pc = 0x19ff84u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 1), 4294965724)));
    // 0x19ff88: 0x24080019
    ctx->pc = 0x19ff88u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 25));
    // 0x19ff8c: 0x3c01002a
    ctx->pc = 0x19ff8cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ff90: 0x73942
    ctx->pc = 0x19ff90u;
    SET_GPR_U32(ctx, 7, SRL32(GPR_U32(ctx, 7), 5));
    // 0x19ff94: 0xfc23f898
    ctx->pc = 0x19ff94u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965400), GPR_U64(ctx, 3));
    // 0x19ff98: 0x7383c
    ctx->pc = 0x19ff98u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << (32 + 0));
    // 0x19ff9c: 0x3c01002a
    ctx->pc = 0x19ff9cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ffa0: 0x7383e
    ctx->pc = 0x19ffa0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) >> (32 + 0));
    // 0x19ffa4: 0x8c2cf9d8
    ctx->pc = 0x19ffa4u;
    SET_GPR_U32(ctx, 12, READ32(ADD32(GPR_U32(ctx, 1), 4294965720)));
    // 0x19ffa8: 0xe66825
    ctx->pc = 0x19ffa8u;
    SET_GPR_U32(ctx, 13, OR32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x19ffac: 0x1cd6825
    ctx->pc = 0x19ffacu;
    SET_GPR_U32(ctx, 13, OR32(GPR_U32(ctx, 14), GPR_U32(ctx, 13)));
    // 0x19ffb0: 0x24070002
    ctx->pc = 0x19ffb0u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 2));
    // 0x19ffb4: 0x1a46825
    ctx->pc = 0x19ffb4u;
    SET_GPR_U32(ctx, 13, OR32(GPR_U32(ctx, 13), GPR_U32(ctx, 4)));
    // 0x19ffb8: 0x3c01002a
    ctx->pc = 0x19ffb8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ffbc: 0xc6142
    ctx->pc = 0x19ffbcu;
    SET_GPR_U32(ctx, 12, SRL32(GPR_U32(ctx, 12), 5));
    // 0x19ffc0: 0xfc22f8a8
    ctx->pc = 0x19ffc0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965416), GPR_U64(ctx, 2));
    // 0x19ffc4: 0xc603c
    ctx->pc = 0x19ffc4u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) << (32 + 0));
    // 0x19ffc8: 0xc603e
    ctx->pc = 0x19ffc8u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) >> (32 + 0));
    // 0x19ffcc: 0x3c01002a
    ctx->pc = 0x19ffccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ffd0: 0x1866025
    ctx->pc = 0x19ffd0u;
    SET_GPR_U32(ctx, 12, OR32(GPR_U32(ctx, 12), GPR_U32(ctx, 6)));
    // 0x19ffd4: 0xfc2df890
    ctx->pc = 0x19ffd4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965392), GPR_U64(ctx, 13));
    // 0x19ffd8: 0x1cc6025
    ctx->pc = 0x19ffd8u;
    SET_GPR_U32(ctx, 12, OR32(GPR_U32(ctx, 14), GPR_U32(ctx, 12)));
    // 0x19ffdc: 0x3c01002a
    ctx->pc = 0x19ffdcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ffe0: 0xfc2df8a0
    ctx->pc = 0x19ffe0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965408), GPR_U64(ctx, 13));
    // 0x19ffe4: 0x1846025
    ctx->pc = 0x19ffe4u;
    SET_GPR_U32(ctx, 12, OR32(GPR_U32(ctx, 12), GPR_U32(ctx, 4)));
    // 0x19ffe8: 0xfe0c0020
    ctx->pc = 0x19ffe8u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 32), GPR_U64(ctx, 12));
    // 0x19ffec: 0x3c01002a
    ctx->pc = 0x19ffecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fff0: 0x9c2df9cc
    ctx->pc = 0x19fff0u;
    SET_GPR_U32(ctx, 13, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x19fff4: 0x3c01002a
    ctx->pc = 0x19fff4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19fff8: 0xd6e38
    ctx->pc = 0x19fff8u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) << 24);
    // 0x19fffc: 0x8c2cf9d8
    ctx->pc = 0x19fffcu;
    SET_GPR_U32(ctx, 12, READ32(ADD32(GPR_U32(ctx, 1), 4294965720)));
    // 0x1a0000: 0xc6142
    ctx->pc = 0x1a0000u;
    SET_GPR_U32(ctx, 12, SRL32(GPR_U32(ctx, 12), 5));
    // 0x1a0004: 0x3c01002a
    ctx->pc = 0x1a0004u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0008: 0xc603c
    ctx->pc = 0x1a0008u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) << (32 + 0));
    // 0x1a000c: 0xc603e
    ctx->pc = 0x1a000cu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) >> (32 + 0));
    // 0x1a0010: 0x1863025
    ctx->pc = 0x1a0010u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 12), GPR_U32(ctx, 6)));
    // 0x1a0014: 0x1a63025
    ctx->pc = 0x1a0014u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 13), GPR_U32(ctx, 6)));
    // 0x1a0018: 0xc42025
    ctx->pc = 0x1a0018u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1a001c: 0xfe040030
    ctx->pc = 0x1a001cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 4));
    // 0x1a0020: 0xfe030028
    ctx->pc = 0x1a0020u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 40), GPR_U64(ctx, 3));
    // 0x1a0024: 0xfe020038
    ctx->pc = 0x1a0024u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 56), GPR_U64(ctx, 2));
    // 0x1a0028: 0xfc2bf8b8
    ctx->pc = 0x1a0028u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965432), GPR_U64(ctx, 11));
    // 0x1a002c: 0x3c01002a
    ctx->pc = 0x1a002cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0030: 0xfc2af8c8
    ctx->pc = 0x1a0030u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965448), GPR_U64(ctx, 10));
    // 0x1a0034: 0x3c01002a
    ctx->pc = 0x1a0034u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0038: 0x8c23f9f0
    ctx->pc = 0x1a0038u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294965744)));
    // 0x1a003c: 0x3c01002a
    ctx->pc = 0x1a003cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0040: 0x31942
    ctx->pc = 0x1a0040u;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), 5));
    // 0x1a0044: 0x9c22f9e4
    ctx->pc = 0x1a0044u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294965732)));
    // 0x1a0048: 0x3183c
    ctx->pc = 0x1a0048u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a004c: 0x3183e
    ctx->pc = 0x1a004cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1a0050: 0x21638
    ctx->pc = 0x1a0050u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 24);
    // 0x1a0054: 0x3c01002a
    ctx->pc = 0x1a0054u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0058: 0x621025
    ctx->pc = 0x1a0058u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a005c: 0xfc22f8b0
    ctx->pc = 0x1a005cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965424), GPR_U64(ctx, 2));
    // 0x1a0060: 0x3c01002a
    ctx->pc = 0x1a0060u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0064: 0xfc22f8c0
    ctx->pc = 0x1a0064u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965440), GPR_U64(ctx, 2));
    // 0x1a0068: 0xfe020040
    ctx->pc = 0x1a0068u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 64), GPR_U64(ctx, 2));
    // 0x1a006c: 0x3c01002a
    ctx->pc = 0x1a006cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0070: 0x8c23f9f0
    ctx->pc = 0x1a0070u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294965744)));
    // 0x1a0074: 0x3c01002a
    ctx->pc = 0x1a0074u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0078: 0x31942
    ctx->pc = 0x1a0078u;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), 5));
    // 0x1a007c: 0x9c22f9e4
    ctx->pc = 0x1a007cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294965732)));
    // 0x1a0080: 0x3183c
    ctx->pc = 0x1a0080u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a0084: 0x3183e
    ctx->pc = 0x1a0084u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1a0088: 0x21638
    ctx->pc = 0x1a0088u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 24);
    // 0x1a008c: 0x3c01002a
    ctx->pc = 0x1a008cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0090: 0x621025
    ctx->pc = 0x1a0090u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a0094: 0xfe020050
    ctx->pc = 0x1a0094u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 80), GPR_U64(ctx, 2));
    // 0x1a0098: 0xfe0b0048
    ctx->pc = 0x1a0098u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 72), GPR_U64(ctx, 11));
    // 0x1a009c: 0xfe0a0058
    ctx->pc = 0x1a009cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 88), GPR_U64(ctx, 10));
    // 0x1a00a0: 0xfc29f8d8
    ctx->pc = 0x1a00a0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965464), GPR_U64(ctx, 9));
    // 0x1a00a4: 0x3c01002a
    ctx->pc = 0x1a00a4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a00a8: 0xfc28f8e8
    ctx->pc = 0x1a00a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965480), GPR_U64(ctx, 8));
    // 0x1a00ac: 0x3c01002a
    ctx->pc = 0x1a00acu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a00b0: 0x8c23fd54
    ctx->pc = 0x1a00b0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1a00b4: 0x3c01002a
    ctx->pc = 0x1a00b4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a00b8: 0x31900
    ctx->pc = 0x1a00b8u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a00bc: 0x8c22fd58
    ctx->pc = 0x1a00bcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1a00c0: 0x21100
    ctx->pc = 0x1a00c0u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 4));
    // 0x1a00c4: 0x3c01002a
    ctx->pc = 0x1a00c4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a00c8: 0x2103c
    ctx->pc = 0x1a00c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a00cc: 0x621025
    ctx->pc = 0x1a00ccu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a00d0: 0xfc22f8d0
    ctx->pc = 0x1a00d0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965456), GPR_U64(ctx, 2));
    // 0x1a00d4: 0x3c01002a
    ctx->pc = 0x1a00d4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a00d8: 0xfc22f8e0
    ctx->pc = 0x1a00d8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965472), GPR_U64(ctx, 2));
    // 0x1a00dc: 0xfe020060
    ctx->pc = 0x1a00dcu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 96), GPR_U64(ctx, 2));
    // 0x1a00e0: 0x3c01002a
    ctx->pc = 0x1a00e0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a00e4: 0x8c23fd54
    ctx->pc = 0x1a00e4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1a00e8: 0x3c01002a
    ctx->pc = 0x1a00e8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a00ec: 0x31900
    ctx->pc = 0x1a00ecu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a00f0: 0x8c22fd58
    ctx->pc = 0x1a00f0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1a00f4: 0x21100
    ctx->pc = 0x1a00f4u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 4));
    // 0x1a00f8: 0x3c01002a
    ctx->pc = 0x1a00f8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a00fc: 0x2103c
    ctx->pc = 0x1a00fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a0100: 0x621025
    ctx->pc = 0x1a0100u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a0104: 0xfe020070
    ctx->pc = 0x1a0104u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 112), GPR_U64(ctx, 2));
    // 0x1a0108: 0xfe090068
    ctx->pc = 0x1a0108u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 104), GPR_U64(ctx, 9));
    // 0x1a010c: 0xfe080078
    ctx->pc = 0x1a010cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 120), GPR_U64(ctx, 8));
    // 0x1a0110: 0x8c22f9c8
    ctx->pc = 0x1a0110u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294965704)));
    // 0x1a0114: 0x14470004
    ctx->pc = 0x1A0114u;
    {
        const bool branch_taken_0x1a0114 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 7));
        if (branch_taken_0x1a0114) {
            ctx->pc = 0x1A0128u;
            goto label_1a0128;
        }
    }
    ctx->pc = 0x1A011Cu;
    // 0x1a011c: 0xfe250080
    ctx->pc = 0x1a011cu;
    WRITE64(ADD32(GPR_U32(ctx, 17), 128), GPR_U64(ctx, 5));
    // 0x1a0120: 0x10000003
    ctx->pc = 0x1A0120u;
    {
        const bool branch_taken_0x1a0120 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A0124u;
        WRITE64(ADD32(GPR_U32(ctx, 16), 128), GPR_U64(ctx, 5));
        if (branch_taken_0x1a0120) {
            ctx->pc = 0x1A0130u;
            goto label_1a0130;
        }
    }
    ctx->pc = 0x1A0128u;
label_1a0128:
    // 0x1a0128: 0xfe200080
    ctx->pc = 0x1a0128u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 128), GPR_U64(ctx, 0));
    // 0x1a012c: 0xfe000080
    ctx->pc = 0x1a012cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 128), GPR_U64(ctx, 0));
label_1a0130:
    // 0x1a0130: 0x24030045
    ctx->pc = 0x1a0130u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 69));
    // 0x1a0134: 0x3c04002a
    ctx->pc = 0x1a0134u;
    SET_GPR_U32(ctx, 4, ((uint32_t)42 << 16));
    // 0x1a0138: 0xfe230088
    ctx->pc = 0x1a0138u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 136), GPR_U64(ctx, 3));
    // 0x1a013c: 0x24060001
    ctx->pc = 0x1a013cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0140: 0xfe030088
    ctx->pc = 0x1a0140u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 136), GPR_U64(ctx, 3));
    // 0x1a0144: 0x24020046
    ctx->pc = 0x1a0144u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 70));
    // 0x1a0148: 0xfe260090
    ctx->pc = 0x1a0148u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 144), GPR_U64(ctx, 6));
    // 0x1a014c: 0x2484f730
    ctx->pc = 0x1a014cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294965040));
    // 0x1a0150: 0xfe060090
    ctx->pc = 0x1a0150u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 144), GPR_U64(ctx, 6));
    // 0x1a0154: 0x24050013
    ctx->pc = 0x1a0154u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 19));
    // 0x1a0158: 0xfe220098
    ctx->pc = 0x1a0158u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 152), GPR_U64(ctx, 2));
    // 0x1a015c: 0x382d
    ctx->pc = 0x1a015cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0160: 0xc0631f0
    ctx->pc = 0x1A0160u;
    SET_GPR_U32(ctx, 31, 0x1A0168u);
    ctx->pc = 0x1A0164u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 152), GPR_U64(ctx, 2));
    ctx->pc = 0x18C7C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7C0_0x18c7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0168u; }
    }
    if (ctx->pc != 0x1A0168u) { return; }
    ctx->pc = 0x1A0168u;
    // 0x1a0168: 0x3c01002a
    ctx->pc = 0x1a0168u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a016c: 0x3c021300
    ctx->pc = 0x1a016cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4864 << 16));
    // 0x1a0170: 0xfc20f750
    ctx->pc = 0x1a0170u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965072), GPR_U64(ctx, 0));
    // 0x1a0174: 0x24050047
    ctx->pc = 0x1a0174u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 71));
    // 0x1a0178: 0x3c01002a
    ctx->pc = 0x1a0178u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a017c: 0x24040005
    ctx->pc = 0x1a017cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a0180: 0xac22f738
    ctx->pc = 0x1a0180u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965048), GPR_U32(ctx, 2));
    // 0x1a0184: 0x3c01002a
    ctx->pc = 0x1a0184u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0188: 0x3c025100
    ctx->pc = 0x1a0188u;
    SET_GPR_U32(ctx, 2, ((uint32_t)20736 << 16));
    // 0x1a018c: 0xfc20f760
    ctx->pc = 0x1a018cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965088), GPR_U64(ctx, 0));
    // 0x1a0190: 0x34420013
    ctx->pc = 0x1a0190u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 19));
    // 0x1a0194: 0x3c01002a
    ctx->pc = 0x1a0194u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0198: 0xac22f73c
    ctx->pc = 0x1a0198u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965052), GPR_U32(ctx, 2));
    // 0x1a019c: 0x3c01002a
    ctx->pc = 0x1a019cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a01a0: 0x3c021000
    ctx->pc = 0x1a01a0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1a01a4: 0xfc20f788
    ctx->pc = 0x1a01a4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965128), GPR_U64(ctx, 0));
    // 0x1a01a8: 0x2183c
    ctx->pc = 0x1a01a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a01ac: 0x3c01002a
    ctx->pc = 0x1a01acu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a01b0: 0x34028012
    ctx->pc = 0x1a01b0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32786));
    // 0x1a01b4: 0xfc20f790
    ctx->pc = 0x1a01b4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965136), GPR_U64(ctx, 0));
    // 0x1a01b8: 0x431025
    ctx->pc = 0x1a01b8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a01bc: 0x3c01002a
    ctx->pc = 0x1a01bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a01c0: 0x24030040
    ctx->pc = 0x1a01c0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
    // 0x1a01c4: 0xfc20f7a0
    ctx->pc = 0x1a01c4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965152), GPR_U64(ctx, 0));
    // 0x1a01c8: 0x3c01002a
    ctx->pc = 0x1a01c8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a01cc: 0xfc22f740
    ctx->pc = 0x1a01ccu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965056), GPR_U64(ctx, 2));
    // 0x1a01d0: 0x2402000e
    ctx->pc = 0x1a01d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14));
    // 0x1a01d4: 0x3c01002a
    ctx->pc = 0x1a01d4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a01d8: 0xfc22f748
    ctx->pc = 0x1a01d8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965064), GPR_U64(ctx, 2));
    // 0x1a01dc: 0x2402004a
    ctx->pc = 0x1a01dcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 74));
    // 0x1a01e0: 0x3c01002a
    ctx->pc = 0x1a01e0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a01e4: 0xfc22f758
    ctx->pc = 0x1a01e4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965080), GPR_U64(ctx, 2));
    // 0x1a01e8: 0x3c01002a
    ctx->pc = 0x1a01e8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a01ec: 0xfc22f828
    ctx->pc = 0x1a01ecu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965288), GPR_U64(ctx, 2));
    // 0x1a01f0: 0x3c01002a
    ctx->pc = 0x1a01f0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a01f4: 0x3c020003
    ctx->pc = 0x1a01f4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)3 << 16));
    // 0x1a01f8: 0xfc23f768
    ctx->pc = 0x1a01f8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965096), GPR_U64(ctx, 3));
    // 0x1a01fc: 0x34420003
    ctx->pc = 0x1a01fcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 3));
    // 0x1a0200: 0x3c01002a
    ctx->pc = 0x1a0200u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0204: 0xfc22f770
    ctx->pc = 0x1a0204u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965104), GPR_U64(ctx, 2));
    // 0x1a0208: 0x3c01002a
    ctx->pc = 0x1a0208u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a020c: 0x24020006
    ctx->pc = 0x1a020cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 6));
    // 0x1a0210: 0xfc23f7c8
    ctx->pc = 0x1a0210u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965192), GPR_U64(ctx, 3));
    // 0x1a0214: 0x3c01002a
    ctx->pc = 0x1a0214u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0218: 0x24030001
    ctx->pc = 0x1a0218u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a021c: 0xfc22f780
    ctx->pc = 0x1a021cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965120), GPR_U64(ctx, 2));
    // 0x1a0220: 0x3c01002a
    ctx->pc = 0x1a0220u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0224: 0x24020041
    ctx->pc = 0x1a0224u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 65));
    // 0x1a0228: 0xfc25f778
    ctx->pc = 0x1a0228u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965112), GPR_U64(ctx, 5));
    // 0x1a022c: 0x3c01002a
    ctx->pc = 0x1a022cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0230: 0xfc25f7e8
    ctx->pc = 0x1a0230u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965224), GPR_U64(ctx, 5));
    // 0x1a0234: 0x3c01002a
    ctx->pc = 0x1a0234u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0238: 0xfc22f7d8
    ctx->pc = 0x1a0238u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965208), GPR_U64(ctx, 2));
    // 0x1a023c: 0x24020048
    ctx->pc = 0x1a023cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 72));
    // 0x1a0240: 0x3c01002a
    ctx->pc = 0x1a0240u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0244: 0xfc22f7f8
    ctx->pc = 0x1a0244u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965240), GPR_U64(ctx, 2));
    // 0x1a0248: 0x2402004e
    ctx->pc = 0x1a0248u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 78));
    // 0x1a024c: 0x3c01002a
    ctx->pc = 0x1a024cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0250: 0xfc22f808
    ctx->pc = 0x1a0250u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965256), GPR_U64(ctx, 2));
    // 0x1a0254: 0x2402004f
    ctx->pc = 0x1a0254u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 79));
    // 0x1a0258: 0x3c01002a
    ctx->pc = 0x1a0258u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a025c: 0xfc22f818
    ctx->pc = 0x1a025cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965272), GPR_U64(ctx, 2));
    // 0x1a0260: 0x2402004b
    ctx->pc = 0x1a0260u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 75));
    // 0x1a0264: 0x3c01002a
    ctx->pc = 0x1a0264u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0268: 0xfc22f838
    ctx->pc = 0x1a0268u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965304), GPR_U64(ctx, 2));
    // 0x1a026c: 0x24020049
    ctx->pc = 0x1a026cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 73));
    // 0x1a0270: 0x3c01002a
    ctx->pc = 0x1a0270u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0274: 0xfc22f848
    ctx->pc = 0x1a0274u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965320), GPR_U64(ctx, 2));
    // 0x1a0278: 0x2402001a
    ctx->pc = 0x1a0278u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 26));
    // 0x1a027c: 0x3c01002a
    ctx->pc = 0x1a027cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0280: 0xfc22f858
    ctx->pc = 0x1a0280u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965336), GPR_U64(ctx, 2));
    // 0x1a0284: 0x3c01002a
    ctx->pc = 0x1a0284u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0288: 0x3c026071
    ctx->pc = 0x1a0288u;
    SET_GPR_U32(ctx, 2, ((uint32_t)24689 << 16));
    // 0x1a028c: 0xfc23f798
    ctx->pc = 0x1a028cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965144), GPR_U64(ctx, 3));
    // 0x1a0290: 0x34422435
    ctx->pc = 0x1a0290u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 9269));
    // 0x1a0294: 0x3c01002a
    ctx->pc = 0x1a0294u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0298: 0xfc23f850
    ctx->pc = 0x1a0298u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965328), GPR_U64(ctx, 3));
    // 0x1a029c: 0x3c01002a
    ctx->pc = 0x1a029cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a02a0: 0x2183c
    ctx->pc = 0x1a02a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a02a4: 0xfc24f7a8
    ctx->pc = 0x1a02a4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965160), GPR_U64(ctx, 4));
    // 0x1a02a8: 0x3c027160
    ctx->pc = 0x1a02a8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)29024 << 16));
    // 0x1a02ac: 0x3c01002a
    ctx->pc = 0x1a02acu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a02b0: 0x34423524
    ctx->pc = 0x1a02b0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 13604));
    // 0x1a02b4: 0xfc24f7b8
    ctx->pc = 0x1a02b4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965176), GPR_U64(ctx, 4));
    // 0x1a02b8: 0x431025
    ctx->pc = 0x1a02b8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a02bc: 0x3c01002a
    ctx->pc = 0x1a02bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a02c0: 0x3c04001a
    ctx->pc = 0x1a02c0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)26 << 16));
    // 0x1a02c4: 0xfc20f7b0
    ctx->pc = 0x1a02c4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965168), GPR_U64(ctx, 0));
    // 0x1a02c8: 0x2484f600
    ctx->pc = 0x1a02c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294964736));
    // 0x1a02cc: 0x3c01002a
    ctx->pc = 0x1a02ccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a02d0: 0xfc22f860
    ctx->pc = 0x1a02d0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965344), GPR_U64(ctx, 2));
    // 0x1a02d4: 0x24020044
    ctx->pc = 0x1a02d4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 68));
    // 0x1a02d8: 0x3c01002a
    ctx->pc = 0x1a02d8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a02dc: 0xfc22f868
    ctx->pc = 0x1a02dcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965352), GPR_U64(ctx, 2));
    // 0x1a02e0: 0x3c01002a
    ctx->pc = 0x1a02e0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a02e4: 0xfc20f7c0
    ctx->pc = 0x1a02e4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965184), GPR_U64(ctx, 0));
    // 0x1a02e8: 0x3c01002a
    ctx->pc = 0x1a02e8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a02ec: 0xfc20f7d0
    ctx->pc = 0x1a02ecu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965200), GPR_U64(ctx, 0));
    // 0x1a02f0: 0x3c01002a
    ctx->pc = 0x1a02f0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a02f4: 0xfc20f7e0
    ctx->pc = 0x1a02f4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965216), GPR_U64(ctx, 0));
    // 0x1a02f8: 0x3c01002a
    ctx->pc = 0x1a02f8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a02fc: 0xfc20f7f0
    ctx->pc = 0x1a02fcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965232), GPR_U64(ctx, 0));
    // 0x1a0300: 0x3c01002a
    ctx->pc = 0x1a0300u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0304: 0xfc20f800
    ctx->pc = 0x1a0304u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965248), GPR_U64(ctx, 0));
    // 0x1a0308: 0x3c01002a
    ctx->pc = 0x1a0308u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a030c: 0xfc20f810
    ctx->pc = 0x1a030cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965264), GPR_U64(ctx, 0));
    // 0x1a0310: 0x3c01002a
    ctx->pc = 0x1a0310u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0314: 0xfc20f820
    ctx->pc = 0x1a0314u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965280), GPR_U64(ctx, 0));
    // 0x1a0318: 0x3c01002a
    ctx->pc = 0x1a0318u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a031c: 0xfc20f830
    ctx->pc = 0x1a031cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965296), GPR_U64(ctx, 0));
    // 0x1a0320: 0x3c01002a
    ctx->pc = 0x1a0320u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a0324: 0xc044ec2
    ctx->pc = 0x1A0324u;
    SET_GPR_U32(ctx, 31, 0x1A032Cu);
    ctx->pc = 0x1A0328u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965312), GPR_U64(ctx, 0));
    ctx->pc = 0x113B08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113B08_0x113b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A032Cu; }
    }
    if (ctx->pc != 0x1A032Cu) { return; }
    ctx->pc = 0x1A032Cu;
    // 0x1a032c: 0xdfbf0040
    ctx->pc = 0x1a032cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a0330: 0x7bb30030
    ctx->pc = 0x1a0330u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a0334: 0x7bb20020
    ctx->pc = 0x1a0334u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a0338: 0x7bb10010
    ctx->pc = 0x1a0338u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a033c: 0x7bb00000
    ctx->pc = 0x1a033cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a0340: 0x3e00008
    ctx->pc = 0x1A0340u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A0344u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F87Cu: goto label_19f87c;
            case 0x19F88Cu: goto label_19f88c;
            case 0x19F8E8u: goto label_19f8e8;
            case 0x19F91Cu: goto label_19f91c;
            case 0x19F954u: goto label_19f954;
            case 0x19F9A4u: goto label_19f9a4;
            case 0x19F9D8u: goto label_19f9d8;
            case 0x19FA08u: goto label_19fa08;
            case 0x19FA5Cu: goto label_19fa5c;
            case 0x19FA80u: goto label_19fa80;
            case 0x19FAA4u: goto label_19faa4;
            case 0x19FAC4u: goto label_19fac4;
            case 0x19FB70u: goto label_19fb70;
            case 0x19FB94u: goto label_19fb94;
            case 0x19FB9Cu: goto label_19fb9c;
            case 0x19FBCCu: goto label_19fbcc;
            case 0x19FC08u: goto label_19fc08;
            case 0x19FC2Cu: goto label_19fc2c;
            case 0x19FC64u: goto label_19fc64;
            case 0x19FD5Cu: goto label_19fd5c;
            case 0x19FDD4u: goto label_19fdd4;
            case 0x19FE44u: goto label_19fe44;
            case 0x19FEB4u: goto label_19feb4;
            case 0x19FF4Cu: goto label_19ff4c;
            case 0x1A0128u: goto label_1a0128;
            case 0x1A0130u: goto label_1a0130;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A0348u;
    // 0x1a0348: 0x0
    ctx->pc = 0x1a0348u;
    // NOP
    // 0x1a034c: 0x0
    ctx->pc = 0x1a034cu;
    // NOP
}
