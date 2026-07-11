#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001028F0
// Address: 0x1028f0 - 0x102b20
void sub_001028F0_0x1028f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1028f0u;

label_1028f0:
    // 0x1028f0: 0x3c021000
    ctx->pc = 0x1028f0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1028f4: 0x34423800
    ctx->pc = 0x1028f4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 14336));
    // 0x1028f8: 0x8c440000
    ctx->pc = 0x1028f8u;
    SET_GPR_U32(ctx, 4, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1028fc: 0x30830003
    ctx->pc = 0x1028fcu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 3));
    // 0x102900: 0x14600003
    ctx->pc = 0x102900u;
    {
        const bool branch_taken_0x102900 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x102904u;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 1792));
        if (branch_taken_0x102900) {
            ctx->pc = 0x102910u;
            goto label_102910;
        }
    }
    ctx->pc = 0x102908u;
    // 0x102908: 0x3e00008
    ctx->pc = 0x102908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10290Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1028F0u: goto label_1028f0;
            case 0x102910u: goto label_102910;
            case 0x102920u: goto label_102920;
            case 0x102930u: goto label_102930;
            case 0x102970u: goto label_102970;
            case 0x102984u: goto label_102984;
            case 0x102AA0u: goto label_102aa0;
            case 0x102AE8u: goto label_102ae8;
            case 0x102B00u: goto label_102b00;
            case 0x102B14u: goto label_102b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102910u;
label_102910:
    // 0x102910: 0x10400003
    ctx->pc = 0x102910u;
    {
        const bool branch_taken_0x102910 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x102914u;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 12));
        if (branch_taken_0x102910) {
            ctx->pc = 0x102920u;
            goto label_102920;
        }
    }
    ctx->pc = 0x102918u;
    // 0x102918: 0x3e00008
    ctx->pc = 0x102918u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10291Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1028F0u: goto label_1028f0;
            case 0x102910u: goto label_102910;
            case 0x102920u: goto label_102920;
            case 0x102930u: goto label_102930;
            case 0x102970u: goto label_102970;
            case 0x102984u: goto label_102984;
            case 0x102AA0u: goto label_102aa0;
            case 0x102AE8u: goto label_102ae8;
            case 0x102B00u: goto label_102b00;
            case 0x102B14u: goto label_102b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102920u;
label_102920:
    // 0x102920: 0x10400003
    ctx->pc = 0x102920u;
    {
        const bool branch_taken_0x102920 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x102924u;
        SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), 12288));
        if (branch_taken_0x102920) {
            ctx->pc = 0x102930u;
            goto label_102930;
        }
    }
    ctx->pc = 0x102928u;
    // 0x102928: 0x3e00008
    ctx->pc = 0x102928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10292Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1028F0u: goto label_1028f0;
            case 0x102910u: goto label_102910;
            case 0x102920u: goto label_102920;
            case 0x102930u: goto label_102930;
            case 0x102970u: goto label_102970;
            case 0x102984u: goto label_102984;
            case 0x102AA0u: goto label_102aa0;
            case 0x102AE8u: goto label_102ae8;
            case 0x102B00u: goto label_102b00;
            case 0x102B14u: goto label_102b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102930u;
label_102930:
    // 0x102930: 0x24030004
    ctx->pc = 0x102930u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4));
    // 0x102934: 0x24020003
    ctx->pc = 0x102934u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x102938: 0x3e00008
    ctx->pc = 0x102938u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10293Cu;
        if (GPR_U32(ctx, 4) == 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 3));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1028F0u: goto label_1028f0;
            case 0x102910u: goto label_102910;
            case 0x102920u: goto label_102920;
            case 0x102930u: goto label_102930;
            case 0x102970u: goto label_102970;
            case 0x102984u: goto label_102984;
            case 0x102AA0u: goto label_102aa0;
            case 0x102AE8u: goto label_102ae8;
            case 0x102B00u: goto label_102b00;
            case 0x102B14u: goto label_102b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102940u;
    // 0x102940: 0x27bdffa0
    ctx->pc = 0x102940u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x102944: 0x3c021000
    ctx->pc = 0x102944u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x102948: 0xffb30030
    ctx->pc = 0x102948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x10294c: 0x34423840
    ctx->pc = 0x10294cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 14400));
    // 0x102950: 0xffbf0050
    ctx->pc = 0x102950u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x102954: 0x80982d
    ctx->pc = 0x102954u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102958: 0xffb20020
    ctx->pc = 0x102958u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x10295c: 0xffb10010
    ctx->pc = 0x10295cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x102960: 0xffb00000
    ctx->pc = 0x102960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102964: 0xffb40040
    ctx->pc = 0x102964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x102968: 0xc040a3c
    ctx->pc = 0x102968u;
    SET_GPR_U32(ctx, 31, 0x102970u);
    ctx->pc = 0x10296Cu;
    SET_GPR_U32(ctx, 20, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x1028F0u;
    goto label_1028f0;
    ctx->pc = 0x102970u;
label_102970:
    // 0x102970: 0x2c420002
    ctx->pc = 0x102970u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 2));
    // 0x102974: 0x14400003
    ctx->pc = 0x102974u;
    {
        const bool branch_taken_0x102974 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x102978u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x102974) {
            ctx->pc = 0x102984u;
            goto label_102984;
        }
    }
    ctx->pc = 0x10297Cu;
    // 0x10297c: 0x10000048
    ctx->pc = 0x10297Cu;
    {
        const bool branch_taken_0x10297c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x102980u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x10297c) {
            ctx->pc = 0x102AA0u;
            goto label_102aa0;
        }
    }
    ctx->pc = 0x102984u;
label_102984:
    // 0x102984: 0x3c031000
    ctx->pc = 0x102984u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x102988: 0x34423900
    ctx->pc = 0x102988u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 14592));
    // 0x10298c: 0x34633910
    ctx->pc = 0x10298cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 14608));
    // 0x102990: 0x8c450000
    ctx->pc = 0x102990u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x102994: 0x3c041000
    ctx->pc = 0x102994u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x102998: 0x34843920
    ctx->pc = 0x102998u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 14624));
    // 0x10299c: 0x3c061000
    ctx->pc = 0x10299cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x1029a0: 0xae650000
    ctx->pc = 0x1029a0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 5));
    // 0x1029a4: 0x34c63930
    ctx->pc = 0x1029a4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 14640));
    // 0x1029a8: 0x3c051000
    ctx->pc = 0x1029a8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x1029ac: 0x3c0f1000
    ctx->pc = 0x1029acu;
    SET_GPR_U32(ctx, 15, ((uint32_t)4096 << 16));
    // 0x1029b0: 0x8c620000
    ctx->pc = 0x1029b0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1029b4: 0x34a53940
    ctx->pc = 0x1029b4u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 14656));
    // 0x1029b8: 0x35ef3950
    ctx->pc = 0x1029b8u;
    SET_GPR_U32(ctx, 15, OR32(GPR_U32(ctx, 15), 14672));
    // 0x1029bc: 0x3c101000
    ctx->pc = 0x1029bcu;
    SET_GPR_U32(ctx, 16, ((uint32_t)4096 << 16));
    // 0x1029c0: 0xae620004
    ctx->pc = 0x1029c0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x1029c4: 0x36103960
    ctx->pc = 0x1029c4u;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 16), 14688));
    // 0x1029c8: 0x3c0e1000
    ctx->pc = 0x1029c8u;
    SET_GPR_U32(ctx, 14, ((uint32_t)4096 << 16));
    // 0x1029cc: 0x3c111000
    ctx->pc = 0x1029ccu;
    SET_GPR_U32(ctx, 17, ((uint32_t)4096 << 16));
    // 0x1029d0: 0x8c820000
    ctx->pc = 0x1029d0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1029d4: 0x35ce3970
    ctx->pc = 0x1029d4u;
    SET_GPR_U32(ctx, 14, OR32(GPR_U32(ctx, 14), 14704));
    // 0x1029d8: 0x36313870
    ctx->pc = 0x1029d8u;
    SET_GPR_U32(ctx, 17, OR32(GPR_U32(ctx, 17), 14448));
    // 0x1029dc: 0x3c0c1000
    ctx->pc = 0x1029dcu;
    SET_GPR_U32(ctx, 12, ((uint32_t)4096 << 16));
    // 0x1029e0: 0xae620008
    ctx->pc = 0x1029e0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 2));
    // 0x1029e4: 0x358c3880
    ctx->pc = 0x1029e4u;
    SET_GPR_U32(ctx, 12, OR32(GPR_U32(ctx, 12), 14464));
    // 0x1029e8: 0x3c0b1000
    ctx->pc = 0x1029e8u;
    SET_GPR_U32(ctx, 11, ((uint32_t)4096 << 16));
    // 0x1029ec: 0x3c0d1000
    ctx->pc = 0x1029ecu;
    SET_GPR_U32(ctx, 13, ((uint32_t)4096 << 16));
    // 0x1029f0: 0x8cc20000
    ctx->pc = 0x1029f0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1029f4: 0x356b3800
    ctx->pc = 0x1029f4u;
    SET_GPR_U32(ctx, 11, OR32(GPR_U32(ctx, 11), 14336));
    // 0x1029f8: 0x35ad38d0
    ctx->pc = 0x1029f8u;
    SET_GPR_U32(ctx, 13, OR32(GPR_U32(ctx, 13), 14544));
    // 0x1029fc: 0x3c061000
    ctx->pc = 0x1029fcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x102a00: 0xae62000c
    ctx->pc = 0x102a00u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 2));
    // 0x102a04: 0x34c63890
    ctx->pc = 0x102a04u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 14480));
    // 0x102a08: 0x3c071000
    ctx->pc = 0x102a08u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x102a0c: 0x3c091000
    ctx->pc = 0x102a0cu;
    SET_GPR_U32(ctx, 9, ((uint32_t)4096 << 16));
    // 0x102a10: 0x8ca20000
    ctx->pc = 0x102a10u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x102a14: 0x34e73830
    ctx->pc = 0x102a14u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 14384));
    // 0x102a18: 0x35293860
    ctx->pc = 0x102a18u;
    SET_GPR_U32(ctx, 9, OR32(GPR_U32(ctx, 9), 14432));
    // 0x102a1c: 0x3c081000
    ctx->pc = 0x102a1cu;
    SET_GPR_U32(ctx, 8, ((uint32_t)4096 << 16));
    // 0x102a20: 0xae620010
    ctx->pc = 0x102a20u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x102a24: 0x35083820
    ctx->pc = 0x102a24u;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 8), 14368));
    // 0x102a28: 0x149202
    ctx->pc = 0x102a28u;
    SET_GPR_U32(ctx, 18, SRL32(GPR_U32(ctx, 20), 8));
    // 0x102a2c: 0x3c0a1000
    ctx->pc = 0x102a2cu;
    SET_GPR_U32(ctx, 10, ((uint32_t)4096 << 16));
    // 0x102a30: 0x8de40000
    ctx->pc = 0x102a30u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x102a34: 0x354a3850
    ctx->pc = 0x102a34u;
    SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 10), 14416));
    // 0x102a38: 0x24020001
    ctx->pc = 0x102a38u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x102a3c: 0xae640014
    ctx->pc = 0x102a3cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 4));
    // 0x102a40: 0x8e030000
    ctx->pc = 0x102a40u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x102a44: 0xae630018
    ctx->pc = 0x102a44u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 24), GPR_U32(ctx, 3));
    // 0x102a48: 0x8dc40000
    ctx->pc = 0x102a48u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x102a4c: 0xae64001c
    ctx->pc = 0x102a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 4));
    // 0x102a50: 0x8e230000
    ctx->pc = 0x102a50u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x102a54: 0xae630020
    ctx->pc = 0x102a54u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 32), GPR_U32(ctx, 3));
    // 0x102a58: 0x8d840000
    ctx->pc = 0x102a58u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x102a5c: 0xae640024
    ctx->pc = 0x102a5cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 36), GPR_U32(ctx, 4));
    // 0x102a60: 0x8d630000
    ctx->pc = 0x102a60u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x102a64: 0xae630028
    ctx->pc = 0x102a64u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 40), GPR_U32(ctx, 3));
    // 0x102a68: 0x8da40000
    ctx->pc = 0x102a68u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x102a6c: 0x8cc30000
    ctx->pc = 0x102a6cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102a70: 0x8ce50000
    ctx->pc = 0x102a70u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x102a74: 0x8d260000
    ctx->pc = 0x102a74u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x102a78: 0x8d070000
    ctx->pc = 0x102a78u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x102a7c: 0xa663002e
    ctx->pc = 0x102a7cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 46), (uint16_t)GPR_U32(ctx, 3));
    // 0x102a80: 0xa664002c
    ctx->pc = 0x102a80u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 44), (uint16_t)GPR_U32(ctx, 4));
    // 0x102a84: 0xa6650030
    ctx->pc = 0x102a84u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 48), (uint16_t)GPR_U32(ctx, 5));
    // 0x102a88: 0xa6660032
    ctx->pc = 0x102a88u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 50), (uint16_t)GPR_U32(ctx, 6));
    // 0x102a8c: 0xa2670034
    ctx->pc = 0x102a8cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 52), (uint8_t)GPR_U32(ctx, 7));
    // 0x102a90: 0xa2740035
    ctx->pc = 0x102a90u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 53), (uint8_t)GPR_U32(ctx, 20));
    // 0x102a94: 0xa2720036
    ctx->pc = 0x102a94u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 54), (uint8_t)GPR_U32(ctx, 18));
    // 0x102a98: 0x8d430000
    ctx->pc = 0x102a98u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x102a9c: 0xa2630037
    ctx->pc = 0x102a9cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 55), (uint8_t)GPR_U32(ctx, 3));
label_102aa0:
    // 0x102aa0: 0xdfbf0050
    ctx->pc = 0x102aa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x102aa4: 0xdfb40040
    ctx->pc = 0x102aa4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x102aa8: 0xdfb30030
    ctx->pc = 0x102aa8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x102aac: 0xdfb20020
    ctx->pc = 0x102aacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x102ab0: 0xdfb10010
    ctx->pc = 0x102ab0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102ab4: 0xdfb00000
    ctx->pc = 0x102ab4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102ab8: 0x3e00008
    ctx->pc = 0x102AB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102ABCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1028F0u: goto label_1028f0;
            case 0x102910u: goto label_102910;
            case 0x102920u: goto label_102920;
            case 0x102930u: goto label_102930;
            case 0x102970u: goto label_102970;
            case 0x102984u: goto label_102984;
            case 0x102AA0u: goto label_102aa0;
            case 0x102AE8u: goto label_102ae8;
            case 0x102B00u: goto label_102b00;
            case 0x102B14u: goto label_102b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102AC0u;
    // 0x102ac0: 0x382d
    ctx->pc = 0x102ac0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102ac4: 0x10a00013
    ctx->pc = 0x102AC4u;
    {
        const bool branch_taken_0x102ac4 = (GPR_U32(ctx, 5) == GPR_U32(ctx, 0));
        ctx->pc = 0x102AC8u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 5), 4294967295));
        if (branch_taken_0x102ac4) {
            ctx->pc = 0x102B14u;
            goto label_102b14;
        }
    }
    ctx->pc = 0x102ACCu;
    // 0x102acc: 0x3c061000
    ctx->pc = 0x102accu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x102ad0: 0x3c051000
    ctx->pc = 0x102ad0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x102ad4: 0x34c63800
    ctx->pc = 0x102ad4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 14336));
    // 0x102ad8: 0x3c091000
    ctx->pc = 0x102ad8u;
    SET_GPR_U32(ctx, 9, ((uint32_t)4096 << 16));
    // 0x102adc: 0x34a54000
    ctx->pc = 0x102adcu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 16384));
    // 0x102ae0: 0x2408ffff
    ctx->pc = 0x102ae0u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x102ae4: 0x0
    ctx->pc = 0x102ae4u;
    // NOP
label_102ae8:
    // 0x102ae8: 0x8cc20000
    ctx->pc = 0x102ae8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102aec: 0x491024
    ctx->pc = 0x102aecu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x102af0: 0x50400003
    ctx->pc = 0x102AF0u;
    {
        const bool branch_taken_0x102af0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x102af0) {
            ctx->pc = 0x102AF4u;
            SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 4), 0)));
            ctx->pc = 0x102B00u;
            goto label_102b00;
        }
    }
    ctx->pc = 0x102AF8u;
    // 0x102af8: 0x3e00008
    ctx->pc = 0x102AF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102AFCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1028F0u: goto label_1028f0;
            case 0x102910u: goto label_102910;
            case 0x102920u: goto label_102920;
            case 0x102930u: goto label_102930;
            case 0x102970u: goto label_102970;
            case 0x102984u: goto label_102984;
            case 0x102AA0u: goto label_102aa0;
            case 0x102AE8u: goto label_102ae8;
            case 0x102B00u: goto label_102b00;
            case 0x102B14u: goto label_102b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102B00u;
label_102b00:
    // 0x102b00: 0x24e70001
    ctx->pc = 0x102b00u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 1));
    // 0x102b04: 0x24840010
    ctx->pc = 0x102b04u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 16));
    // 0x102b08: 0x2463ffff
    ctx->pc = 0x102b08u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x102b0c: 0x1468fff6
    ctx->pc = 0x102B0Cu;
    {
        const bool branch_taken_0x102b0c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 8));
        ctx->pc = 0x102B10u;
        WRITE128(ADD32(GPR_U32(ctx, 5), 0), GPR_VEC(ctx, 2));
        if (branch_taken_0x102b0c) {
            ctx->pc = 0x102AE8u;
            goto label_102ae8;
        }
    }
    ctx->pc = 0x102B14u;
label_102b14:
    // 0x102b14: 0x3e00008
    ctx->pc = 0x102B14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102B18u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1028F0u: goto label_1028f0;
            case 0x102910u: goto label_102910;
            case 0x102920u: goto label_102920;
            case 0x102930u: goto label_102930;
            case 0x102970u: goto label_102970;
            case 0x102984u: goto label_102984;
            case 0x102AA0u: goto label_102aa0;
            case 0x102AE8u: goto label_102ae8;
            case 0x102B00u: goto label_102b00;
            case 0x102B14u: goto label_102b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102B1Cu;
    // 0x102b1c: 0x0
    ctx->pc = 0x102b1cu;
    // NOP
}
