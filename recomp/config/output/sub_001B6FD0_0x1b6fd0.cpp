#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001B6FD0
// Address: 0x1b6fd0 - 0x1b7150
void sub_001B6FD0_0x1b6fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1b6fd0u;

    // 0x1b6fd0: 0x31030007
    ctx->pc = 0x1b6fd0u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 8), 7));
    // 0x1b6fd4: 0x240c0008
    ctx->pc = 0x1b6fd4u;
    SET_GPR_S32(ctx, 12, ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b6fd8: 0x24020001
    ctx->pc = 0x1b6fd8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b6fdc: 0x14620002
    ctx->pc = 0x1B6FDCu;
    {
        const bool branch_taken_0x1b6fdc = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x1B6FE0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1b6fdc) {
            ctx->pc = 0x1B6FE8u;
            goto label_1b6fe8;
        }
    }
    ctx->pc = 0x1B6FE4u;
    // 0x1b6fe4: 0x240c0006
    ctx->pc = 0x1b6fe4u;
    SET_GPR_S32(ctx, 12, ADD32(GPR_U32(ctx, 0), 6));
label_1b6fe8:
    // 0x1b6fe8: 0x14620002
    ctx->pc = 0x1B6FE8u;
    {
        const bool branch_taken_0x1b6fe8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x1b6fe8) {
            ctx->pc = 0x1B6FF4u;
            goto label_1b6ff4;
        }
    }
    ctx->pc = 0x1B6FF0u;
    // 0x1b6ff0: 0x240c0004
    ctx->pc = 0x1b6ff0u;
    SET_GPR_S32(ctx, 12, ADD32(GPR_U32(ctx, 0), 4));
label_1b6ff4:
    // 0x1b6ff4: 0x24020003
    ctx->pc = 0x1b6ff4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b6ff8: 0x14620002
    ctx->pc = 0x1B6FF8u;
    {
        const bool branch_taken_0x1b6ff8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x1B6FFCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
        if (branch_taken_0x1b6ff8) {
            ctx->pc = 0x1B7004u;
            goto label_1b7004;
        }
    }
    ctx->pc = 0x1B7000u;
    // 0x1b7000: 0x240c0002
    ctx->pc = 0x1b7000u;
    SET_GPR_S32(ctx, 12, ADD32(GPR_U32(ctx, 0), 2));
label_1b7004:
    // 0x1b7004: 0x14620002
    ctx->pc = 0x1B7004u;
    {
        const bool branch_taken_0x1b7004 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x1b7004) {
            ctx->pc = 0x1B7010u;
            goto label_1b7010;
        }
    }
    ctx->pc = 0x1B700Cu;
    // 0x1b700c: 0x240c0001
    ctx->pc = 0x1b700cu;
    SET_GPR_S32(ctx, 12, ADD32(GPR_U32(ctx, 0), 1));
label_1b7010:
    // 0x1b7010: 0x8fa20000
    ctx->pc = 0x1b7010u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b7014: 0x1621018
    ctx->pc = 0x1b7014u;
    { int64_t result = (int64_t)GPR_S32(ctx, 11) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x1b7018: 0x1821818
    ctx->pc = 0x1b7018u;
    { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
    // 0x1b701c: 0x31142
    ctx->pc = 0x1b701cu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 3), 5));
    // 0x1b7020: 0x3063001f
    ctx->pc = 0x1b7020u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 31));
    // 0x1b7024: 0x10600002
    ctx->pc = 0x1B7024u;
    {
        const bool branch_taken_0x1b7024 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x1b7024) {
            ctx->pc = 0x1B7030u;
            goto label_1b7030;
        }
    }
    ctx->pc = 0x1B702Cu;
    // 0x1b702c: 0x24420001
    ctx->pc = 0x1b702cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_1b7030:
    // 0x1b7030: 0x6303c
    ctx->pc = 0x1b7030u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1b7034: 0x7183c
    ctx->pc = 0x1b7034u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 0));
    // 0x1b7038: 0x6303e
    ctx->pc = 0x1b7038u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x1b703c: 0x3183e
    ctx->pc = 0x1b703cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1b7040: 0x6303c
    ctx->pc = 0x1b7040u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1b7044: 0x31c3c
    ctx->pc = 0x1b7044u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b7048: 0xc33825
    ctx->pc = 0x1b7048u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1b704c: 0xb603c
    ctx->pc = 0x1b704cu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 11) << (32 + 0));
    // 0x1b7050: 0x8183c
    ctx->pc = 0x1b7050u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) << (32 + 0));
    // 0x1b7054: 0x240b0051
    ctx->pc = 0x1b7054u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 0), 81));
    // 0x1b7058: 0x3183e
    ctx->pc = 0x1b7058u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1b705c: 0xc603e
    ctx->pc = 0x1b705cu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) >> (32 + 0));
    // 0x1b7060: 0x3363c
    ctx->pc = 0x1b7060u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) << (32 + 24));
    // 0x1b7064: 0x9183c
    ctx->pc = 0x1b7064u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) << (32 + 0));
    // 0x1b7068: 0xc74025
    ctx->pc = 0x1b7068u;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1b706c: 0x3183e
    ctx->pc = 0x1b706cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1b7070: 0x3c091000
    ctx->pc = 0x1b7070u;
    SET_GPR_U32(ctx, 9, ((uint32_t)4096 << 16));
    // 0x1b7074: 0x3303c
    ctx->pc = 0x1b7074u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1b7078: 0xa183c
    ctx->pc = 0x1b7078u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 10) << (32 + 0));
    // 0x1b707c: 0x3183e
    ctx->pc = 0x1b707cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1b7080: 0x240a000e
    ctx->pc = 0x1b7080u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 14));
    // 0x1b7084: 0x31c3c
    ctx->pc = 0x1b7084u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b7088: 0xc33825
    ctx->pc = 0x1b7088u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1b708c: 0x35230007
    ctx->pc = 0x1b708cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 9), 7));
    // 0x1b7090: 0xac830000
    ctx->pc = 0x1b7090u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x1b7094: 0x9483c
    ctx->pc = 0x1b7094u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << (32 + 0));
    // 0x1b7098: 0xac800004
    ctx->pc = 0x1b7098u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x1b709c: 0x3c035100
    ctx->pc = 0x1b709cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)20736 << 16));
    // 0x1b70a0: 0x34660007
    ctx->pc = 0x1b70a0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 7));
    // 0x1b70a4: 0xac800008
    ctx->pc = 0x1b70a4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1b70a8: 0xac86000c
    ctx->pc = 0x1b70a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 6));
    // 0x1b70ac: 0x431825
    ctx->pc = 0x1b70acu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b70b0: 0x24060005
    ctx->pc = 0x1b70b0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 5));
    // 0x1b70b4: 0xc93025
    ctx->pc = 0x1b70b4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
    // 0x1b70b8: 0xfc860010
    ctx->pc = 0x1b70b8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 6));
    // 0x1b70bc: 0x2409003f
    ctx->pc = 0x1b70bcu;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 63));
    // 0x1b70c0: 0xfc8a0018
    ctx->pc = 0x1b70c0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 10));
    // 0x1b70c4: 0x24060050
    ctx->pc = 0x1b70c4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 80));
    // 0x1b70c8: 0xfc800020
    ctx->pc = 0x1b70c8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 32), GPR_U64(ctx, 0));
    // 0x1b70cc: 0x240a0052
    ctx->pc = 0x1b70ccu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 82));
    // 0x1b70d0: 0xfc890028
    ctx->pc = 0x1b70d0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 40), GPR_U64(ctx, 9));
    // 0x1b70d4: 0xfc880030
    ctx->pc = 0x1b70d4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 48), GPR_U64(ctx, 8));
    // 0x1b70d8: 0x24090053
    ctx->pc = 0x1b70d8u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 83));
    // 0x1b70dc: 0xfc860038
    ctx->pc = 0x1b70dcu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 56), GPR_U64(ctx, 6));
    // 0x1b70e0: 0x2403c
    ctx->pc = 0x1b70e0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b70e4: 0xfc870040
    ctx->pc = 0x1b70e4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 64), GPR_U64(ctx, 7));
    // 0x1b70e8: 0x3c060800
    ctx->pc = 0x1b70e8u;
    SET_GPR_U32(ctx, 6, ((uint32_t)2048 << 16));
    // 0x1b70ec: 0xfc8b0048
    ctx->pc = 0x1b70ecu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 72), GPR_U64(ctx, 11));
    // 0x1b70f0: 0x6383c
    ctx->pc = 0x1b70f0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1b70f4: 0x9fab0000
    ctx->pc = 0x1b70f4u;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b70f8: 0x34068000
    ctx->pc = 0x1b70f8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 0), 32768));
    // 0x1b70fc: 0x8403f
    ctx->pc = 0x1b70fcu;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 8) >> (32 + 0));
    // 0x1b7100: 0xc73025
    ctx->pc = 0x1b7100u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1b7104: 0x1063825
    ctx->pc = 0x1b7104u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
    // 0x1b7108: 0x3c063000
    ctx->pc = 0x1b7108u;
    SET_GPR_U32(ctx, 6, ((uint32_t)12288 << 16));
    // 0x1b710c: 0x463025
    ctx->pc = 0x1b710cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1b7110: 0x24820090
    ctx->pc = 0x1b7110u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 144));
    // 0x1b7114: 0xb403c
    ctx->pc = 0x1b7114u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 11) << (32 + 0));
    // 0x1b7118: 0x1884025
    ctx->pc = 0x1b7118u;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 12), GPR_U32(ctx, 8)));
    // 0x1b711c: 0xfc880050
    ctx->pc = 0x1b711cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 80), GPR_U64(ctx, 8));
    // 0x1b7120: 0xfc8a0058
    ctx->pc = 0x1b7120u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 88), GPR_U64(ctx, 10));
    // 0x1b7124: 0xfc800060
    ctx->pc = 0x1b7124u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 96), GPR_U64(ctx, 0));
    // 0x1b7128: 0xfc890068
    ctx->pc = 0x1b7128u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 104), GPR_U64(ctx, 9));
    // 0x1b712c: 0xfc870070
    ctx->pc = 0x1b712cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 112), GPR_U64(ctx, 7));
    // 0x1b7130: 0xfc800078
    ctx->pc = 0x1b7130u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 120), GPR_U64(ctx, 0));
    // 0x1b7134: 0xac860080
    ctx->pc = 0x1b7134u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 128), GPR_U32(ctx, 6));
    // 0x1b7138: 0xac850084
    ctx->pc = 0x1b7138u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 132), GPR_U32(ctx, 5));
    // 0x1b713c: 0xac800088
    ctx->pc = 0x1b713cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 136), GPR_U32(ctx, 0));
    // 0x1b7140: 0x3e00008
    ctx->pc = 0x1B7140u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7144u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 140), GPR_U32(ctx, 3));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B6FE8u: goto label_1b6fe8;
            case 0x1B6FF4u: goto label_1b6ff4;
            case 0x1B7004u: goto label_1b7004;
            case 0x1B7010u: goto label_1b7010;
            case 0x1B7030u: goto label_1b7030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7148u;
    // 0x1b7148: 0x0
    ctx->pc = 0x1b7148u;
    // NOP
    // 0x1b714c: 0x0
    ctx->pc = 0x1b714cu;
    // NOP
}
