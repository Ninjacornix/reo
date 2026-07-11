#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00101788
// Address: 0x101788 - 0x101968
void sub_00101788_0x101788(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x101788u;

    // 0x101788: 0x27bdff80
    ctx->pc = 0x101788u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x10178c: 0x3c030020
    ctx->pc = 0x10178cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
    // 0x101790: 0xffb50060
    ctx->pc = 0x101790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x101794: 0x3c150020
    ctx->pc = 0x101794u;
    SET_GPR_U32(ctx, 21, ((uint32_t)32 << 16));
    // 0x101798: 0xffb40050
    ctx->pc = 0x101798u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x10179c: 0x8ea27938
    ctx->pc = 0x10179cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 21), 31032)));
    // 0x1017a0: 0xc0a02d
    ctx->pc = 0x1017a0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1017a4: 0xffb30040
    ctx->pc = 0x1017a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1017a8: 0xffb20030
    ctx->pc = 0x1017a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1017ac: 0x80982d
    ctx->pc = 0x1017acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1017b0: 0xffb10020
    ctx->pc = 0x1017b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1017b4: 0x24727a00
    ctx->pc = 0x1017b4u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 3), 31232));
    // 0x1017b8: 0xffb00010
    ctx->pc = 0x1017b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1017bc: 0xa0882d
    ctx->pc = 0x1017bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1017c0: 0xffbf0070
    ctx->pc = 0x1017c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1017c4: 0x30420001
    ctx->pc = 0x1017c4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x1017c8: 0x14400006
    ctx->pc = 0x1017C8u;
    {
        const bool branch_taken_0x1017c8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1017CCu;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1017c8) {
            ctx->pc = 0x1017E4u;
            goto label_1017e4;
        }
    }
    ctx->pc = 0x1017D0u;
    // 0x1017d0: 0xc040338
    ctx->pc = 0x1017D0u;
    SET_GPR_U32(ctx, 31, 0x1017D8u);
    ctx->pc = 0x100CE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100CE0_0x100ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1017D8u; }
    }
    if (ctx->pc != 0x1017D8u) { return; }
    ctx->pc = 0x1017D8u;
    // 0x1017d8: 0x24030006
    ctx->pc = 0x1017d8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 6));
    // 0x1017dc: 0x10430059
    ctx->pc = 0x1017DCu;
    {
        const bool branch_taken_0x1017dc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x1017E0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1017dc) {
            ctx->pc = 0x101944u;
            goto label_101944;
        }
    }
    ctx->pc = 0x1017E4u;
label_1017e4:
    // 0x1017e4: 0xc0402dc
    ctx->pc = 0x1017E4u;
    SET_GPR_U32(ctx, 31, 0x1017ECu);
    ctx->pc = 0x1017E8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x100B70u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100B70_0x100b70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1017ECu; }
    }
    if (ctx->pc != 0x1017ECu) { return; }
    ctx->pc = 0x1017ECu;
    // 0x1017ec: 0x1040004d
    ctx->pc = 0x1017ECu;
    {
        const bool branch_taken_0x1017ec = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1017F0u;
        SET_GPR_U32(ctx, 8, ((uint32_t)33 << 16));
        if (branch_taken_0x1017ec) {
            ctx->pc = 0x101924u;
            goto label_101924;
        }
    }
    ctx->pc = 0x1017F4u;
    // 0x1017f4: 0xae530000
    ctx->pc = 0x1017f4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 19));
    // 0x1017f8: 0xae510004
    ctx->pc = 0x1017f8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 17));
    // 0x1017fc: 0x3c130021
    ctx->pc = 0x1017fcu;
    SET_GPR_U32(ctx, 19, ((uint32_t)33 << 16));
    // 0x101800: 0xae540008
    ctx->pc = 0x101800u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 20));
    // 0x101804: 0x26648a00
    ctx->pc = 0x101804u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 19), 4294937088));
    // 0x101808: 0x25058ac0
    ctx->pc = 0x101808u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 8), 4294937280));
    // 0x10180c: 0x24060001
    ctx->pc = 0x10180cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x101810: 0x92020000
    ctx->pc = 0x101810u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x101814: 0xa242000c
    ctx->pc = 0x101814u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 2));
    // 0x101818: 0x92030001
    ctx->pc = 0x101818u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x10181c: 0xa243000d
    ctx->pc = 0x10181cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x101820: 0x92020002
    ctx->pc = 0x101820u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x101824: 0xae440010
    ctx->pc = 0x101824u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 4));
    // 0x101828: 0xa242000e
    ctx->pc = 0x101828u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 14), (uint8_t)GPR_U32(ctx, 2));
    // 0x10182c: 0xae450014
    ctx->pc = 0x10182cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 5));
    // 0x101830: 0x92070002
    ctx->pc = 0x101830u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x101834: 0x10e60008
    ctx->pc = 0x101834u;
    {
        const bool branch_taken_0x101834 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 6));
        ctx->pc = 0x101838u;
        SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 7), 2));
        if (branch_taken_0x101834) {
            ctx->pc = 0x101858u;
            goto label_101858;
        }
    }
    ctx->pc = 0x10183Cu;
    // 0x10183c: 0x1440000a
    ctx->pc = 0x10183Cu;
    {
        const bool branch_taken_0x10183c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x101840u;
        SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 17), 11));
        if (branch_taken_0x10183c) {
            ctx->pc = 0x101868u;
            goto label_101868;
        }
    }
    ctx->pc = 0x101844u;
    // 0x101844: 0x24020002
    ctx->pc = 0x101844u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x101848: 0x10e20006
    ctx->pc = 0x101848u;
    {
        const bool branch_taken_0x101848 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 2));
        ctx->pc = 0x10184Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2340));
        if (branch_taken_0x101848) {
            ctx->pc = 0x101864u;
            goto label_101864;
        }
    }
    ctx->pc = 0x101850u;
    // 0x101850: 0x10000005
    ctx->pc = 0x101850u;
    {
        const bool branch_taken_0x101850 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x101850) {
            ctx->pc = 0x101868u;
            goto label_101868;
        }
    }
    ctx->pc = 0x101858u;
label_101858:
    // 0x101858: 0x24020918
    ctx->pc = 0x101858u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2328));
    // 0x10185c: 0x10000002
    ctx->pc = 0x10185Cu;
    {
        const bool branch_taken_0x10185c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x101860u;
        { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)(uint32_t)result); }
        if (branch_taken_0x10185c) {
            ctx->pc = 0x101868u;
            goto label_101868;
        }
    }
    ctx->pc = 0x101864u;
label_101864:
    // 0x101864: 0x2222818
    ctx->pc = 0x101864u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)(uint32_t)result); }
label_101868:
    // 0x101868: 0x8ea27938
    ctx->pc = 0x101868u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 21), 31032)));
    // 0x10186c: 0x25108ac0
    ctx->pc = 0x10186cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 8), 4294937280));
    // 0x101870: 0x30420002
    ctx->pc = 0x101870u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 2));
    // 0x101874: 0x14400003
    ctx->pc = 0x101874u;
    {
        const bool branch_taken_0x101874 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x101878u;
        WRITE32(ADD32(GPR_U32(ctx, 8), 4294937280), GPR_U32(ctx, 0));
        if (branch_taken_0x101874) {
            ctx->pc = 0x101884u;
            goto label_101884;
        }
    }
    ctx->pc = 0x10187Cu;
    // 0x10187c: 0xc045bf4
    ctx->pc = 0x10187Cu;
    SET_GPR_U32(ctx, 31, 0x101884u);
    ctx->pc = 0x101880u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x116FD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101884u; }
    }
    if (ctx->pc != 0x101884u) { return; }
    ctx->pc = 0x101884u;
label_101884:
    // 0x101884: 0x26738a00
    ctx->pc = 0x101884u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 4294937088));
    // 0x101888: 0x24050090
    ctx->pc = 0x101888u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 144));
    // 0x10188c: 0x260202d
    ctx->pc = 0x10188cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101890: 0xc045bf4
    ctx->pc = 0x101890u;
    SET_GPR_U32(ctx, 31, 0x101898u);
    ctx->pc = 0x101894u;
    SET_GPR_U32(ctx, 20, ((uint32_t)32 << 16));
    ctx->pc = 0x116FD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101898u; }
    }
    if (ctx->pc != 0x101898u) { return; }
    ctx->pc = 0x101898u;
    // 0x101898: 0x240202d
    ctx->pc = 0x101898u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10189c: 0xc045bf4
    ctx->pc = 0x10189Cu;
    SET_GPR_U32(ctx, 31, 0x1018A4u);
    ctx->pc = 0x1018A0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 24));
    ctx->pc = 0x116FD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1018A4u; }
    }
    if (ctx->pc != 0x1018A4u) { return; }
    ctx->pc = 0x1018A4u;
    // 0x1018a4: 0x200202d
    ctx->pc = 0x1018a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1018a8: 0xc045bf4
    ctx->pc = 0x1018A8u;
    SET_GPR_U32(ctx, 31, 0x1018B0u);
    ctx->pc = 0x1018ACu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x116FD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1018B0u; }
    }
    if (ctx->pc != 0x1018B0u) { return; }
    ctx->pc = 0x1018B0u;
    // 0x1018b0: 0x8e827910
    ctx->pc = 0x1018b0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x1018b4: 0x18400003
    ctx->pc = 0x1018B4u;
    {
        const bool branch_taken_0x1018b4 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1018B8u;
        SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
        if (branch_taken_0x1018b4) {
            ctx->pc = 0x1018C4u;
            goto label_1018c4;
        }
    }
    ctx->pc = 0x1018BCu;
    // 0x1018bc: 0xc045a12
    ctx->pc = 0x1018BCu;
    SET_GPR_U32(ctx, 31, 0x1018C4u);
    ctx->pc = 0x1018C0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 30288));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1018C4u; }
    }
    if (ctx->pc != 0x1018C4u) { return; }
    ctx->pc = 0x1018C4u;
label_1018c4:
    // 0x1018c4: 0x24020001
    ctx->pc = 0x1018c4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1018c8: 0x3c100020
    ctx->pc = 0x1018c8u;
    SET_GPR_U32(ctx, 16, ((uint32_t)32 << 16));
    // 0x1018cc: 0xae027958
    ctx->pc = 0x1018ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 2));
    // 0x1018d0: 0x3c110020
    ctx->pc = 0x1018d0u;
    SET_GPR_U32(ctx, 17, ((uint32_t)32 << 16));
    // 0x1018d4: 0x3c040021
    ctx->pc = 0x1018d4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x1018d8: 0x3c0b0010
    ctx->pc = 0x1018d8u;
    SET_GPR_U32(ctx, 11, ((uint32_t)16 << 16));
    // 0x1018dc: 0xae227934
    ctx->pc = 0x1018dcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 2));
    // 0x1018e0: 0x24848ad0
    ctx->pc = 0x1018e0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294937296));
    // 0x1018e4: 0xafb30000
    ctx->pc = 0x1018e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 19));
    // 0x1018e8: 0x240382d
    ctx->pc = 0x1018e8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1018ec: 0x256b04d8
    ctx->pc = 0x1018ecu;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 11), 1240));
    // 0x1018f0: 0x24050001
    ctx->pc = 0x1018f0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1018f4: 0x24060001
    ctx->pc = 0x1018f4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1018f8: 0x24080018
    ctx->pc = 0x1018f8u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 24));
    // 0x1018fc: 0x482d
    ctx->pc = 0x1018fcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101900: 0xc045e7a
    ctx->pc = 0x101900u;
    SET_GPR_U32(ctx, 31, 0x101908u);
    ctx->pc = 0x101904u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1179E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101908u; }
    }
    if (ctx->pc != 0x101908u) { return; }
    ctx->pc = 0x101908u;
    // 0x101908: 0x4430008
    ctx->pc = 0x101908u;
    {
        const bool branch_taken_0x101908 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x101908) {
            ctx->pc = 0x10190Cu;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 30992)));
            ctx->pc = 0x10192Cu;
            goto label_10192c;
        }
    }
    ctx->pc = 0x101910u;
    // 0x101910: 0xae007958
    ctx->pc = 0x101910u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x101914: 0x3c020020
    ctx->pc = 0x101914u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x101918: 0xae207934
    ctx->pc = 0x101918u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 0));
    // 0x10191c: 0xc045190
    ctx->pc = 0x10191Cu;
    SET_GPR_U32(ctx, 31, 0x101924u);
    ctx->pc = 0x101920u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 31016)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101924u; }
    }
    if (ctx->pc != 0x101924u) { return; }
    ctx->pc = 0x101924u;
label_101924:
    // 0x101924: 0x10000007
    ctx->pc = 0x101924u;
    {
        const bool branch_taken_0x101924 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x101928u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x101924) {
            ctx->pc = 0x101944u;
            goto label_101944;
        }
    }
    ctx->pc = 0x10192Cu;
label_10192c:
    // 0x10192c: 0x18400005
    ctx->pc = 0x10192Cu;
    {
        const bool branch_taken_0x10192c = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x101930u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x10192c) {
            ctx->pc = 0x101944u;
            goto label_101944;
        }
    }
    ctx->pc = 0x101934u;
    // 0x101934: 0x3c040023
    ctx->pc = 0x101934u;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x101938: 0xc045a12
    ctx->pc = 0x101938u;
    SET_GPR_U32(ctx, 31, 0x101940u);
    ctx->pc = 0x10193Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 30312));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101940u; }
    }
    if (ctx->pc != 0x101940u) { return; }
    ctx->pc = 0x101940u;
    // 0x101940: 0x24020001
    ctx->pc = 0x101940u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_101944:
    // 0x101944: 0xdfbf0070
    ctx->pc = 0x101944u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x101948: 0xdfb50060
    ctx->pc = 0x101948u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x10194c: 0xdfb40050
    ctx->pc = 0x10194cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x101950: 0xdfb30040
    ctx->pc = 0x101950u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x101954: 0xdfb20030
    ctx->pc = 0x101954u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101958: 0xdfb10020
    ctx->pc = 0x101958u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10195c: 0xdfb00010
    ctx->pc = 0x10195cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101960: 0x3e00008
    ctx->pc = 0x101960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101964u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1017E4u: goto label_1017e4;
            case 0x101858u: goto label_101858;
            case 0x101864u: goto label_101864;
            case 0x101868u: goto label_101868;
            case 0x101884u: goto label_101884;
            case 0x1018C4u: goto label_1018c4;
            case 0x101924u: goto label_101924;
            case 0x10192Cu: goto label_10192c;
            case 0x101944u: goto label_101944;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101968u;
}
