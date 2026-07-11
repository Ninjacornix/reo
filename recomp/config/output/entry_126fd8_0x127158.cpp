#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_126fd8
// Address: 0x126fd8 - 0x127158
void entry_126fd8_0x127158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x126fd8u;

    // 0x126fd8: 0x3c020021
    ctx->pc = 0x126fd8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x126fdc: 0x3e00008
    ctx->pc = 0x126FDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126FE0u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294952872), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x127058u: goto label_127058;
            case 0x1270A0u: goto label_1270a0;
            case 0x12712Cu: goto label_12712c;
            case 0x127150u: goto label_127150;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126FE4u;
    // 0x126fe4: 0x0
    ctx->pc = 0x126fe4u;
    // NOP
    // 0x126fe8: 0x84400
    ctx->pc = 0x126fe8u;
    SET_GPR_U32(ctx, 8, SLL32(GPR_U32(ctx, 8), 16));
    // 0x126fec: 0x94c00
    ctx->pc = 0x126fecu;
    SET_GPR_U32(ctx, 9, SLL32(GPR_U32(ctx, 9), 16));
    // 0x126ff0: 0x84303
    ctx->pc = 0x126ff0u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 12));
    // 0x126ff4: 0x94b03
    ctx->pc = 0x126ff4u;
    SET_GPR_S32(ctx, 9, SRA32(GPR_S32(ctx, 9), 12));
    // 0x126ff8: 0x44890800
    ctx->pc = 0x126ff8u;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 9);
    // 0x126ffc: 0x46800860
    ctx->pc = 0x126ffcu;
    ctx->f[1] = FPU_CVT_S_W(*(int32_t*)&ctx->f[1]);
    // 0x127000: 0x482d
    ctx->pc = 0x127000u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127004: 0x44881000
    ctx->pc = 0x127004u;
    *(uint32_t*)&ctx->f[2] = GPR_U32(ctx, 8);
    // 0x127008: 0x468010a0
    ctx->pc = 0x127008u;
    ctx->f[2] = FPU_CVT_S_W(*(int32_t*)&ctx->f[2]);
    // 0x12700c: 0x80402d
    ctx->pc = 0x12700cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127010: 0x84e20000
    ctx->pc = 0x127010u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x127014: 0x84e30002
    ctx->pc = 0x127014u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x127018: 0x3c013780
    ctx->pc = 0x127018u;
    SET_GPR_U32(ctx, 1, ((uint32_t)14208 << 16));
    // 0x12701c: 0x44810000
    ctx->pc = 0x12701cu;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 1);
    // 0x127020: 0x21400
    ctx->pc = 0x127020u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 16));
    // 0x127024: 0x31c00
    ctx->pc = 0x127024u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 16));
    // 0x127028: 0x46000a02
    ctx->pc = 0x127028u;
    ctx->f[8] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x12702c: 0x44832800
    ctx->pc = 0x12702cu;
    *(uint32_t*)&ctx->f[5] = GPR_U32(ctx, 3);
    // 0x127030: 0x46802960
    ctx->pc = 0x127030u;
    ctx->f[5] = FPU_CVT_S_W(*(int32_t*)&ctx->f[5]);
    // 0x127034: 0x44820800
    ctx->pc = 0x127034u;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 2);
    // 0x127038: 0x46800860
    ctx->pc = 0x127038u;
    ctx->f[1] = FPU_CVT_S_W(*(int32_t*)&ctx->f[1]);
    // 0x12703c: 0x18a0003b
    ctx->pc = 0x12703Cu;
    {
        const bool branch_taken_0x12703c = (GPR_S32(ctx, 5) <= 0);
        ctx->pc = 0x127040u;
        ctx->f[7] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
        if (branch_taken_0x12703c) {
            ctx->pc = 0x12712Cu;
            goto label_12712c;
        }
    }
    ctx->pc = 0x127044u;
    // 0x127044: 0x240eff00
    ctx->pc = 0x127044u;
    SET_GPR_S32(ctx, 14, ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127048: 0x3c0d0024
    ctx->pc = 0x127048u;
    SET_GPR_U32(ctx, 13, ((uint32_t)36 << 16));
    // 0x12704c: 0x3c0c0024
    ctx->pc = 0x12704cu;
    SET_GPR_U32(ctx, 12, ((uint32_t)36 << 16));
    // 0x127050: 0x95030000
    ctx->pc = 0x127050u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x127054: 0x0
    ctx->pc = 0x127054u;
    // NOP
label_127058:
    // 0x127058: 0x91040001
    ctx->pc = 0x127058u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x12705c: 0x31a00
    ctx->pc = 0x12705cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 8));
    // 0x127060: 0x6e1824
    ctx->pc = 0x127060u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x127064: 0x832025
    ctx->pc = 0x127064u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x127068: 0x42400
    ctx->pc = 0x127068u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 16));
    // 0x12706c: 0x42403
    ctx->pc = 0x12706cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127070: 0x30838000
    ctx->pc = 0x127070u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 32768));
    // 0x127074: 0x14600036
    ctx->pc = 0x127074u;
    {
        const bool branch_taken_0x127074 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x127078u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x127074) {
            ctx->pc = 0x127150u;
            goto label_127150;
        }
    }
    ctx->pc = 0x12707Cu;
    // 0x12707c: 0x30821fff
    ctx->pc = 0x12707cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 8191));
    // 0x127080: 0x2404001e
    ctx->pc = 0x127080u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 30));
    // 0x127084: 0x24420001
    ctx->pc = 0x127084u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x127088: 0x25080002
    ctx->pc = 0x127088u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 2));
    // 0x12708c: 0x44823000
    ctx->pc = 0x12708cu;
    *(uint32_t*)&ctx->f[6] = GPR_U32(ctx, 2);
    // 0x127090: 0x468031a0
    ctx->pc = 0x127090u;
    ctx->f[6] = FPU_CVT_S_W(*(int32_t*)&ctx->f[6]);
    // 0x127094: 0x25aba528
    ctx->pc = 0x127094u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 13), 4294944040));
    // 0x127098: 0x258aa928
    ctx->pc = 0x127098u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 12), 4294945064));
    // 0x12709c: 0x0
    ctx->pc = 0x12709cu;
    // NOP
label_1270a0:
    // 0x1270a0: 0x91020000
    ctx->pc = 0x1270a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1270a4: 0x25080001
    ctx->pc = 0x1270a4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
    // 0x1270a8: 0x46054002
    ctx->pc = 0x1270a8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[8], ctx->f[5]);
    // 0x1270ac: 0x46000946
    ctx->pc = 0x1270acu;
    ctx->f[5] = FPU_MOV_S(ctx->f[1]);
    // 0x1270b0: 0x21080
    ctx->pc = 0x1270b0u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
    // 0x1270b4: 0x46013882
    ctx->pc = 0x1270b4u;
    ctx->f[2] = FPU_MUL_S(ctx->f[7], ctx->f[1]);
    // 0x1270b8: 0x4b1821
    ctx->pc = 0x1270b8u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x1270bc: 0x4a1021
    ctx->pc = 0x1270bcu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1270c0: 0xc4630000
    ctx->pc = 0x1270c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1270c4: 0x46054102
    ctx->pc = 0x1270c4u;
    ctx->f[4] = FPU_MUL_S(ctx->f[8], ctx->f[5]);
    // 0x1270c8: 0x2484fffe
    ctx->pc = 0x1270c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294967294));
    // 0x1270cc: 0x46001080
    ctx->pc = 0x1270ccu;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
    // 0x1270d0: 0x46061842
    ctx->pc = 0x1270d0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[3], ctx->f[6]);
    // 0x1270d4: 0xc4430000
    ctx->pc = 0x1270d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1270d8: 0x460618c2
    ctx->pc = 0x1270d8u;
    ctx->f[3] = FPU_MUL_S(ctx->f[3], ctx->f[6]);
    // 0x1270dc: 0x46011040
    ctx->pc = 0x1270dcu;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1270e0: 0x46013802
    ctx->pc = 0x1270e0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[7], ctx->f[1]);
    // 0x1270e4: 0x46000946
    ctx->pc = 0x1270e4u;
    ctx->f[5] = FPU_MOV_S(ctx->f[1]);
    // 0x1270e8: 0x460008a4
    ctx->pc = 0x1270e8u;
    *(int32_t*)&ctx->f[2] = FPU_CVT_W_S(ctx->f[1]);
    // 0x1270ec: 0x44021000
    ctx->pc = 0x1270ecu;
    SET_GPR_U32(ctx, 2, *(uint32_t*)&ctx->f[2]);
    // 0x1270f0: 0x46040000
    ctx->pc = 0x1270f0u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[4]);
    // 0x1270f4: 0x21403
    ctx->pc = 0x1270f4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1270f8: 0xa4c20000
    ctx->pc = 0x1270f8u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1270fc: 0x24c60002
    ctx->pc = 0x1270fcu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 2));
    // 0x127100: 0x46030040
    ctx->pc = 0x127100u;
    ctx->f[1] = FPU_ADD_S(ctx->f[0], ctx->f[3]);
    // 0x127104: 0x46000824
    ctx->pc = 0x127104u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[1]);
    // 0x127108: 0x44020000
    ctx->pc = 0x127108u;
    SET_GPR_U32(ctx, 2, *(uint32_t*)&ctx->f[0]);
    // 0x12710c: 0x21403
    ctx->pc = 0x12710cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x127110: 0xa4c20000
    ctx->pc = 0x127110u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127114: 0x481ffe2
    ctx->pc = 0x127114u;
    {
        const bool branch_taken_0x127114 = (GPR_S32(ctx, 4) >= 0);
        ctx->pc = 0x127118u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 2));
        if (branch_taken_0x127114) {
            ctx->pc = 0x1270A0u;
            goto label_1270a0;
        }
    }
    ctx->pc = 0x12711Cu;
    // 0x12711c: 0x25290001
    ctx->pc = 0x12711cu;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 9), 1));
    // 0x127120: 0x125102a
    ctx->pc = 0x127120u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 9), GPR_S32(ctx, 5)));
    // 0x127124: 0x5440ffcc
    ctx->pc = 0x127124u;
    {
        const bool branch_taken_0x127124 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x127124) {
            ctx->pc = 0x127128u;
            SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
            ctx->pc = 0x127058u;
            goto label_127058;
        }
    }
    ctx->pc = 0x12712Cu;
label_12712c:
    // 0x12712c: 0x46000824
    ctx->pc = 0x12712cu;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[1]);
    // 0x127130: 0x44040000
    ctx->pc = 0x127130u;
    SET_GPR_U32(ctx, 4, *(uint32_t*)&ctx->f[0]);
    // 0x127134: 0xa0102d
    ctx->pc = 0x127134u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127138: 0x46002824
    ctx->pc = 0x127138u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[5]);
    // 0x12713c: 0x44030000
    ctx->pc = 0x12713cu;
    SET_GPR_U32(ctx, 3, *(uint32_t*)&ctx->f[0]);
    // 0x127140: 0x42403
    ctx->pc = 0x127140u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127144: 0x31c03
    ctx->pc = 0x127144u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127148: 0xa4e40000
    ctx->pc = 0x127148u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x12714c: 0xa4e30002
    ctx->pc = 0x12714cu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 2), (uint16_t)GPR_U32(ctx, 3));
label_127150:
    // 0x127150: 0x3e00008
    ctx->pc = 0x127150u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x127058u: goto label_127058;
            case 0x1270A0u: goto label_1270a0;
            case 0x12712Cu: goto label_12712c;
            case 0x127150u: goto label_127150;
            default: break;
        }
        return;
    }
    ctx->pc = 0x127158u;
}
