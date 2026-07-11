#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00197780
// Address: 0x197780 - 0x197900
void sub_00197780_0x197780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x197780u;

    // 0x197780: 0x27bdffd0
    ctx->pc = 0x197780u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x197784: 0x30828000
    ctx->pc = 0x197784u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 32768));
    // 0x197788: 0xffbf0020
    ctx->pc = 0x197788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19778c: 0x38428000
    ctx->pc = 0x19778cu;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 2), 32768));
    // 0x197790: 0x7fb10010
    ctx->pc = 0x197790u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x197794: 0x2182b
    ctx->pc = 0x197794u;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x197798: 0x7fb00000
    ctx->pc = 0x197798u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19779c: 0xa0882d
    ctx->pc = 0x19779cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1977a0: 0x3c01002a
    ctx->pc = 0x1977a0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1977a4: 0x24020002
    ctx->pc = 0x1977a4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x1977a8: 0x8c25f9f0
    ctx->pc = 0x1977a8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965744)));
    // 0x1977ac: 0x3183c
    ctx->pc = 0x1977acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1977b0: 0x3c01002a
    ctx->pc = 0x1977b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1977b4: 0x52942
    ctx->pc = 0x1977b4u;
    SET_GPR_U32(ctx, 5, SRL32(GPR_U32(ctx, 5), 5));
    // 0x1977b8: 0x8c24f9e4
    ctx->pc = 0x1977b8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 4294965732)));
    // 0x1977bc: 0x5283c
    ctx->pc = 0x1977bcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1977c0: 0x5283f
    ctx->pc = 0x1977c0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1977c4: 0x42638
    ctx->pc = 0x1977c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 24);
    // 0x1977c8: 0xa42025
    ctx->pc = 0x1977c8u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1977cc: 0x12220006
    ctx->pc = 0x1977CCu;
    {
        const bool branch_taken_0x1977cc = (GPR_U32(ctx, 17) == GPR_U32(ctx, 2));
        ctx->pc = 0x1977D0u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x1977cc) {
            ctx->pc = 0x1977E8u;
            goto label_1977e8;
        }
    }
    ctx->pc = 0x1977D4u;
    // 0x1977d4: 0x24040030
    ctx->pc = 0x1977d4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 48));
    // 0x1977d8: 0xc063774
    ctx->pc = 0x1977D8u;
    SET_GPR_U32(ctx, 31, 0x1977E0u);
    ctx->pc = 0x1977DCu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1977E0u; }
    }
    if (ctx->pc != 0x1977E0u) { return; }
    ctx->pc = 0x1977E0u;
    // 0x1977e0: 0x10000005
    ctx->pc = 0x1977E0u;
    {
        const bool branch_taken_0x1977e0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1977E4u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1977e0) {
            ctx->pc = 0x1977F8u;
            goto label_1977f8;
        }
    }
    ctx->pc = 0x1977E8u;
label_1977e8:
    // 0x1977e8: 0x24040040
    ctx->pc = 0x1977e8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 64));
    // 0x1977ec: 0xc063774
    ctx->pc = 0x1977ECu;
    SET_GPR_U32(ctx, 31, 0x1977F4u);
    ctx->pc = 0x1977F0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1977F4u; }
    }
    if (ctx->pc != 0x1977F4u) { return; }
    ctx->pc = 0x1977F4u;
    // 0x1977f4: 0x24070003
    ctx->pc = 0x1977f4u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 3));
label_1977f8:
    // 0x1977f8: 0x3c047000
    ctx->pc = 0x1977f8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)28672 << 16));
    // 0x1977fc: 0x3c038000
    ctx->pc = 0x1977fcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)32768 << 16));
    // 0x197800: 0xe42021
    ctx->pc = 0x197800u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x197804: 0x3c051300
    ctx->pc = 0x197804u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x197808: 0x832025
    ctx->pc = 0x197808u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x19780c: 0x4303c
    ctx->pc = 0x19780cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197810: 0x3c035000
    ctx->pc = 0x197810u;
    SET_GPR_U32(ctx, 3, ((uint32_t)20480 << 16));
    // 0x197814: 0x6303e
    ctx->pc = 0x197814u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x197818: 0xe32025
    ctx->pc = 0x197818u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x19781c: 0xfc460000
    ctx->pc = 0x19781cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
    // 0x197820: 0x24e3ffff
    ctx->pc = 0x197820u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x197824: 0xac450008
    ctx->pc = 0x197824u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 5));
    // 0x197828: 0x3283c
    ctx->pc = 0x197828u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x19782c: 0xac44000c
    ctx->pc = 0x19782cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 4));
    // 0x197830: 0x3c031000
    ctx->pc = 0x197830u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x197834: 0x5283e
    ctx->pc = 0x197834u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x197838: 0x3203c
    ctx->pc = 0x197838u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x19783c: 0x34038000
    ctx->pc = 0x19783cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 0), 32768));
    // 0x197840: 0x641825
    ctx->pc = 0x197840u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x197844: 0xa32825
    ctx->pc = 0x197844u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x197848: 0x2404000e
    ctx->pc = 0x197848u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 14));
    // 0x19784c: 0xfc450010
    ctx->pc = 0x19784cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 5));
    // 0x197850: 0x24030002
    ctx->pc = 0x197850u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x197854: 0x12230012
    ctx->pc = 0x197854u;
    {
        const bool branch_taken_0x197854 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 3));
        ctx->pc = 0x197858u;
        WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 4));
        if (branch_taken_0x197854) {
            ctx->pc = 0x1978A0u;
            goto label_1978a0;
        }
    }
    ctx->pc = 0x19785Cu;
    // 0x19785c: 0x24030001
    ctx->pc = 0x19785cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x197860: 0x1223000a
    ctx->pc = 0x197860u;
    {
        const bool branch_taken_0x197860 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 3));
        ctx->pc = 0x197864u;
        SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
        if (branch_taken_0x197860) {
            ctx->pc = 0x19788Cu;
            goto label_19788c;
        }
    }
    ctx->pc = 0x197868u;
    // 0x197868: 0x12200003
    ctx->pc = 0x197868u;
    {
        const bool branch_taken_0x197868 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        ctx->pc = 0x19786Cu;
        SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
        if (branch_taken_0x197868) {
            ctx->pc = 0x197878u;
            goto label_197878;
        }
    }
    ctx->pc = 0x197870u;
    // 0x197870: 0x10000016
    ctx->pc = 0x197870u;
    {
        const bool branch_taken_0x197870 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197874u;
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
        if (branch_taken_0x197870) {
            ctx->pc = 0x1978CCu;
            goto label_1978cc;
        }
    }
    ctx->pc = 0x197878u;
label_197878:
    // 0x197878: 0x2403004e
    ctx->pc = 0x197878u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 78));
    // 0x19787c: 0xfc30fde0
    ctx->pc = 0x19787cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966752), GPR_U64(ctx, 16));
    // 0x197880: 0xfc500020
    ctx->pc = 0x197880u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197884: 0x10000010
    ctx->pc = 0x197884u;
    {
        const bool branch_taken_0x197884 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197888u;
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        if (branch_taken_0x197884) {
            ctx->pc = 0x1978C8u;
            goto label_1978c8;
        }
    }
    ctx->pc = 0x19788Cu;
label_19788c:
    // 0x19788c: 0x2403004f
    ctx->pc = 0x19788cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 79));
    // 0x197890: 0xfc30fde8
    ctx->pc = 0x197890u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966760), GPR_U64(ctx, 16));
    // 0x197894: 0xfc500020
    ctx->pc = 0x197894u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197898: 0x1000000b
    ctx->pc = 0x197898u;
    {
        const bool branch_taken_0x197898 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19789Cu;
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        if (branch_taken_0x197898) {
            ctx->pc = 0x1978C8u;
            goto label_1978c8;
        }
    }
    ctx->pc = 0x1978A0u;
label_1978a0:
    // 0x1978a0: 0x3c01002a
    ctx->pc = 0x1978a0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1978a4: 0x2404004e
    ctx->pc = 0x1978a4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 78));
    // 0x1978a8: 0xfc30fde0
    ctx->pc = 0x1978a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966752), GPR_U64(ctx, 16));
    // 0x1978ac: 0x2403004f
    ctx->pc = 0x1978acu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 79));
    // 0x1978b0: 0x3c01002a
    ctx->pc = 0x1978b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1978b4: 0xfc30fde8
    ctx->pc = 0x1978b4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966760), GPR_U64(ctx, 16));
    // 0x1978b8: 0xfc500020
    ctx->pc = 0x1978b8u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x1978bc: 0xfc440028
    ctx->pc = 0x1978bcu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 4));
    // 0x1978c0: 0xfc500030
    ctx->pc = 0x1978c0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 48), GPR_U64(ctx, 16));
    // 0x1978c4: 0xfc430038
    ctx->pc = 0x1978c4u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 56), GPR_U64(ctx, 3));
label_1978c8:
    // 0x1978c8: 0x2293c
    ctx->pc = 0x1978c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
label_1978cc:
    // 0x1978cc: 0x3c07002a
    ctx->pc = 0x1978ccu;
    SET_GPR_U32(ctx, 7, ((uint32_t)42 << 16));
    // 0x1978d0: 0x5293e
    ctx->pc = 0x1978d0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x1978d4: 0x40302d
    ctx->pc = 0x1978d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1978d8: 0x202d
    ctx->pc = 0x1978d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1978dc: 0xc0633ec
    ctx->pc = 0x1978DCu;
    SET_GPR_U32(ctx, 31, 0x1978E4u);
    ctx->pc = 0x1978E0u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
    ctx->pc = 0x18CFB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1978E4u; }
    }
    if (ctx->pc != 0x1978E4u) { return; }
    ctx->pc = 0x1978E4u;
    // 0x1978e4: 0xdfbf0020
    ctx->pc = 0x1978e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1978e8: 0x24020001
    ctx->pc = 0x1978e8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1978ec: 0x7bb10010
    ctx->pc = 0x1978ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1978f0: 0x7bb00000
    ctx->pc = 0x1978f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1978f4: 0x3e00008
    ctx->pc = 0x1978F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1978F8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1977E8u: goto label_1977e8;
            case 0x1977F8u: goto label_1977f8;
            case 0x197878u: goto label_197878;
            case 0x19788Cu: goto label_19788c;
            case 0x1978A0u: goto label_1978a0;
            case 0x1978C8u: goto label_1978c8;
            case 0x1978CCu: goto label_1978cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1978FCu;
    // 0x1978fc: 0x0
    ctx->pc = 0x1978fcu;
    // NOP
}
