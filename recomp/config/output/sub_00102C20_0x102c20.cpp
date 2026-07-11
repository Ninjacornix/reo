#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00102C20
// Address: 0x102c20 - 0x102f08
void sub_00102C20_0x102c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x102c20u;

label_102c20:
    // 0x102c20: 0x3c021000
    ctx->pc = 0x102c20u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x102c24: 0x34423c00
    ctx->pc = 0x102c24u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 15360));
    // 0x102c28: 0x8c440000
    ctx->pc = 0x102c28u;
    SET_GPR_U32(ctx, 4, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x102c2c: 0x30830003
    ctx->pc = 0x102c2cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 3));
    // 0x102c30: 0x14600003
    ctx->pc = 0x102C30u;
    {
        const bool branch_taken_0x102c30 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x102C34u;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 1792));
        if (branch_taken_0x102c30) {
            ctx->pc = 0x102C40u;
            goto label_102c40;
        }
    }
    ctx->pc = 0x102C38u;
    // 0x102c38: 0x3e00008
    ctx->pc = 0x102C38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102C3Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102C20u: goto label_102c20;
            case 0x102C40u: goto label_102c40;
            case 0x102C50u: goto label_102c50;
            case 0x102C60u: goto label_102c60;
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102C40u;
label_102c40:
    // 0x102c40: 0x10400003
    ctx->pc = 0x102C40u;
    {
        const bool branch_taken_0x102c40 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x102C44u;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 12));
        if (branch_taken_0x102c40) {
            ctx->pc = 0x102C50u;
            goto label_102c50;
        }
    }
    ctx->pc = 0x102C48u;
    // 0x102c48: 0x3e00008
    ctx->pc = 0x102C48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102C4Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102C20u: goto label_102c20;
            case 0x102C40u: goto label_102c40;
            case 0x102C50u: goto label_102c50;
            case 0x102C60u: goto label_102c60;
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102C50u;
label_102c50:
    // 0x102c50: 0x10400003
    ctx->pc = 0x102C50u;
    {
        const bool branch_taken_0x102c50 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x102C54u;
        SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), 12288));
        if (branch_taken_0x102c50) {
            ctx->pc = 0x102C60u;
            goto label_102c60;
        }
    }
    ctx->pc = 0x102C58u;
    // 0x102c58: 0x3e00008
    ctx->pc = 0x102C58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102C5Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102C20u: goto label_102c20;
            case 0x102C40u: goto label_102c40;
            case 0x102C50u: goto label_102c50;
            case 0x102C60u: goto label_102c60;
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102C60u;
label_102c60:
    // 0x102c60: 0x24030004
    ctx->pc = 0x102c60u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4));
    // 0x102c64: 0x24020003
    ctx->pc = 0x102c64u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x102c68: 0x3e00008
    ctx->pc = 0x102C68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102C6Cu;
        if (GPR_U32(ctx, 4) == 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 3));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102C20u: goto label_102c20;
            case 0x102C40u: goto label_102c40;
            case 0x102C50u: goto label_102c50;
            case 0x102C60u: goto label_102c60;
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102C70u;
    // 0x102c70: 0x27bdff70
    ctx->pc = 0x102c70u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x102c74: 0x3c021000
    ctx->pc = 0x102c74u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x102c78: 0xffb60060
    ctx->pc = 0x102c78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x102c7c: 0x34423c40
    ctx->pc = 0x102c7cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 15424));
    // 0x102c80: 0xffbf0080
    ctx->pc = 0x102c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x102c84: 0x80b02d
    ctx->pc = 0x102c84u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102c88: 0xffb50050
    ctx->pc = 0x102c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x102c8c: 0xffb40040
    ctx->pc = 0x102c8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x102c90: 0xffb30030
    ctx->pc = 0x102c90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x102c94: 0xffb20020
    ctx->pc = 0x102c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x102c98: 0xffb10010
    ctx->pc = 0x102c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x102c9c: 0xffb00000
    ctx->pc = 0x102c9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102ca0: 0xffb70070
    ctx->pc = 0x102ca0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x102ca4: 0xc040b08
    ctx->pc = 0x102CA4u;
    SET_GPR_U32(ctx, 31, 0x102CACu);
    ctx->pc = 0x102CA8u;
    SET_GPR_U32(ctx, 23, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x102C20u;
    goto label_102c20;
    ctx->pc = 0x102CACu;
label_102cac:
    // 0x102cac: 0x2c420002
    ctx->pc = 0x102cacu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 2));
    // 0x102cb0: 0x14400003
    ctx->pc = 0x102CB0u;
    {
        const bool branch_taken_0x102cb0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x102CB4u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x102cb0) {
            ctx->pc = 0x102CC0u;
            goto label_102cc0;
        }
    }
    ctx->pc = 0x102CB8u;
    // 0x102cb8: 0x10000058
    ctx->pc = 0x102CB8u;
    {
        const bool branch_taken_0x102cb8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x102CBCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x102cb8) {
            ctx->pc = 0x102E1Cu;
            goto label_102e1c;
        }
    }
    ctx->pc = 0x102CC0u;
label_102cc0:
    // 0x102cc0: 0x3c031000
    ctx->pc = 0x102cc0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x102cc4: 0x34423d00
    ctx->pc = 0x102cc4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 15616));
    // 0x102cc8: 0x34633d10
    ctx->pc = 0x102cc8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 15632));
    // 0x102ccc: 0x8c450000
    ctx->pc = 0x102cccu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x102cd0: 0x3c041000
    ctx->pc = 0x102cd0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x102cd4: 0x34843d20
    ctx->pc = 0x102cd4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 15648));
    // 0x102cd8: 0x3c061000
    ctx->pc = 0x102cd8u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x102cdc: 0xaec50000
    ctx->pc = 0x102cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 5));
    // 0x102ce0: 0x34c63d30
    ctx->pc = 0x102ce0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 15664));
    // 0x102ce4: 0x3c051000
    ctx->pc = 0x102ce4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x102ce8: 0x3c071000
    ctx->pc = 0x102ce8u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x102cec: 0x8c620000
    ctx->pc = 0x102cecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x102cf0: 0x34a53d40
    ctx->pc = 0x102cf0u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 15680));
    // 0x102cf4: 0x34e73d50
    ctx->pc = 0x102cf4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 15696));
    // 0x102cf8: 0x3c0c1000
    ctx->pc = 0x102cf8u;
    SET_GPR_U32(ctx, 12, ((uint32_t)4096 << 16));
    // 0x102cfc: 0xaec20004
    ctx->pc = 0x102cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 4), GPR_U32(ctx, 2));
    // 0x102d00: 0x358c3d60
    ctx->pc = 0x102d00u;
    SET_GPR_U32(ctx, 12, OR32(GPR_U32(ctx, 12), 15712));
    // 0x102d04: 0x3c131000
    ctx->pc = 0x102d04u;
    SET_GPR_U32(ctx, 19, ((uint32_t)4096 << 16));
    // 0x102d08: 0x3c141000
    ctx->pc = 0x102d08u;
    SET_GPR_U32(ctx, 20, ((uint32_t)4096 << 16));
    // 0x102d0c: 0x8c820000
    ctx->pc = 0x102d0cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x102d10: 0x36733d70
    ctx->pc = 0x102d10u;
    SET_GPR_U32(ctx, 19, OR32(GPR_U32(ctx, 19), 15728));
    // 0x102d14: 0x36943c70
    ctx->pc = 0x102d14u;
    SET_GPR_U32(ctx, 20, OR32(GPR_U32(ctx, 20), 15472));
    // 0x102d18: 0x3c111000
    ctx->pc = 0x102d18u;
    SET_GPR_U32(ctx, 17, ((uint32_t)4096 << 16));
    // 0x102d1c: 0xaec20008
    ctx->pc = 0x102d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 8), GPR_U32(ctx, 2));
    // 0x102d20: 0x36313c80
    ctx->pc = 0x102d20u;
    SET_GPR_U32(ctx, 17, OR32(GPR_U32(ctx, 17), 15488));
    // 0x102d24: 0x3c101000
    ctx->pc = 0x102d24u;
    SET_GPR_U32(ctx, 16, ((uint32_t)4096 << 16));
    // 0x102d28: 0x3c121000
    ctx->pc = 0x102d28u;
    SET_GPR_U32(ctx, 18, ((uint32_t)4096 << 16));
    // 0x102d2c: 0x8cc20000
    ctx->pc = 0x102d2cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102d30: 0x36103c00
    ctx->pc = 0x102d30u;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 16), 15360));
    // 0x102d34: 0x36523cd0
    ctx->pc = 0x102d34u;
    SET_GPR_U32(ctx, 18, OR32(GPR_U32(ctx, 18), 15568));
    // 0x102d38: 0x3c061000
    ctx->pc = 0x102d38u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x102d3c: 0xaec2000c
    ctx->pc = 0x102d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 12), GPR_U32(ctx, 2));
    // 0x102d40: 0x34c63c90
    ctx->pc = 0x102d40u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 15504));
    // 0x102d44: 0x3c081000
    ctx->pc = 0x102d44u;
    SET_GPR_U32(ctx, 8, ((uint32_t)4096 << 16));
    // 0x102d48: 0x3c0e1000
    ctx->pc = 0x102d48u;
    SET_GPR_U32(ctx, 14, ((uint32_t)4096 << 16));
    // 0x102d4c: 0x8ca20000
    ctx->pc = 0x102d4cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x102d50: 0x35083ca0
    ctx->pc = 0x102d50u;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 8), 15520));
    // 0x102d54: 0x35ce3cb0
    ctx->pc = 0x102d54u;
    SET_GPR_U32(ctx, 14, OR32(GPR_U32(ctx, 14), 15536));
    // 0x102d58: 0x3c0b1000
    ctx->pc = 0x102d58u;
    SET_GPR_U32(ctx, 11, ((uint32_t)4096 << 16));
    // 0x102d5c: 0xaec20010
    ctx->pc = 0x102d5cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 16), GPR_U32(ctx, 2));
    // 0x102d60: 0x356b3ce0
    ctx->pc = 0x102d60u;
    SET_GPR_U32(ctx, 11, OR32(GPR_U32(ctx, 11), 15584));
    // 0x102d64: 0x3c091000
    ctx->pc = 0x102d64u;
    SET_GPR_U32(ctx, 9, ((uint32_t)4096 << 16));
    // 0x102d68: 0x3c0f1000
    ctx->pc = 0x102d68u;
    SET_GPR_U32(ctx, 15, ((uint32_t)4096 << 16));
    // 0x102d6c: 0x8ce20000
    ctx->pc = 0x102d6cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x102d70: 0x35293cc0
    ctx->pc = 0x102d70u;
    SET_GPR_U32(ctx, 9, OR32(GPR_U32(ctx, 9), 15552));
    // 0x102d74: 0x35ef3c30
    ctx->pc = 0x102d74u;
    SET_GPR_U32(ctx, 15, OR32(GPR_U32(ctx, 15), 15408));
    // 0x102d78: 0x3c0d1000
    ctx->pc = 0x102d78u;
    SET_GPR_U32(ctx, 13, ((uint32_t)4096 << 16));
    // 0x102d7c: 0xaec20014
    ctx->pc = 0x102d7cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 20), GPR_U32(ctx, 2));
    // 0x102d80: 0x35ad3c60
    ctx->pc = 0x102d80u;
    SET_GPR_U32(ctx, 13, OR32(GPR_U32(ctx, 13), 15456));
    // 0x102d84: 0x3c0a1000
    ctx->pc = 0x102d84u;
    SET_GPR_U32(ctx, 10, ((uint32_t)4096 << 16));
    // 0x102d88: 0x17aa02
    ctx->pc = 0x102d88u;
    SET_GPR_U32(ctx, 21, SRL32(GPR_U32(ctx, 23), 8));
    // 0x102d8c: 0x8d830000
    ctx->pc = 0x102d8cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x102d90: 0x354a3c20
    ctx->pc = 0x102d90u;
    SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 10), 15392));
    // 0x102d94: 0x3c0c1000
    ctx->pc = 0x102d94u;
    SET_GPR_U32(ctx, 12, ((uint32_t)4096 << 16));
    // 0x102d98: 0x24020001
    ctx->pc = 0x102d98u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x102d9c: 0xaec30018
    ctx->pc = 0x102d9cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 24), GPR_U32(ctx, 3));
    // 0x102da0: 0x358c3c50
    ctx->pc = 0x102da0u;
    SET_GPR_U32(ctx, 12, OR32(GPR_U32(ctx, 12), 15440));
    // 0x102da4: 0x8e630000
    ctx->pc = 0x102da4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x102da8: 0xaec3001c
    ctx->pc = 0x102da8u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 28), GPR_U32(ctx, 3));
    // 0x102dac: 0x8e840000
    ctx->pc = 0x102dacu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x102db0: 0xaec40020
    ctx->pc = 0x102db0u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 32), GPR_U32(ctx, 4));
    // 0x102db4: 0x8e230000
    ctx->pc = 0x102db4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x102db8: 0xaec30024
    ctx->pc = 0x102db8u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 36), GPR_U32(ctx, 3));
    // 0x102dbc: 0x8e040000
    ctx->pc = 0x102dbcu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x102dc0: 0xaec40028
    ctx->pc = 0x102dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 40), GPR_U32(ctx, 4));
    // 0x102dc4: 0x8e430000
    ctx->pc = 0x102dc4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x102dc8: 0x8cc40000
    ctx->pc = 0x102dc8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102dcc: 0x8d050000
    ctx->pc = 0x102dccu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x102dd0: 0x8dc60000
    ctx->pc = 0x102dd0u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x102dd4: 0x8d670000
    ctx->pc = 0x102dd4u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x102dd8: 0x8d280000
    ctx->pc = 0x102dd8u;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x102ddc: 0xa6c3002c
    ctx->pc = 0x102ddcu;
    WRITE16(ADD32(GPR_U32(ctx, 22), 44), (uint16_t)GPR_U32(ctx, 3));
    // 0x102de0: 0xa6c4002e
    ctx->pc = 0x102de0u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 46), (uint16_t)GPR_U32(ctx, 4));
    // 0x102de4: 0xa6c50030
    ctx->pc = 0x102de4u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 48), (uint16_t)GPR_U32(ctx, 5));
    // 0x102de8: 0xa6c60032
    ctx->pc = 0x102de8u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 50), (uint16_t)GPR_U32(ctx, 6));
    // 0x102dec: 0xa6c70034
    ctx->pc = 0x102decu;
    WRITE16(ADD32(GPR_U32(ctx, 22), 52), (uint16_t)GPR_U32(ctx, 7));
    // 0x102df0: 0xa6c80036
    ctx->pc = 0x102df0u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 54), (uint16_t)GPR_U32(ctx, 8));
    // 0x102df4: 0x8de40000
    ctx->pc = 0x102df4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x102df8: 0x8da50000
    ctx->pc = 0x102df8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x102dfc: 0x8d430000
    ctx->pc = 0x102dfcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x102e00: 0xa2d5003e
    ctx->pc = 0x102e00u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 62), (uint8_t)GPR_U32(ctx, 21));
    // 0x102e04: 0xa2c3003c
    ctx->pc = 0x102e04u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 60), (uint8_t)GPR_U32(ctx, 3));
    // 0x102e08: 0xa2d7003d
    ctx->pc = 0x102e08u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 61), (uint8_t)GPR_U32(ctx, 23));
    // 0x102e0c: 0xa6c40038
    ctx->pc = 0x102e0cu;
    WRITE16(ADD32(GPR_U32(ctx, 22), 56), (uint16_t)GPR_U32(ctx, 4));
    // 0x102e10: 0x8d830000
    ctx->pc = 0x102e10u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x102e14: 0xa6c5003a
    ctx->pc = 0x102e14u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 58), (uint16_t)GPR_U32(ctx, 5));
    // 0x102e18: 0xa2c3003f
    ctx->pc = 0x102e18u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 63), (uint8_t)GPR_U32(ctx, 3));
label_102e1c:
    // 0x102e1c: 0xdfbf0080
    ctx->pc = 0x102e1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x102e20: 0xdfb70070
    ctx->pc = 0x102e20u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x102e24: 0xdfb60060
    ctx->pc = 0x102e24u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x102e28: 0xdfb50050
    ctx->pc = 0x102e28u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x102e2c: 0xdfb40040
    ctx->pc = 0x102e2cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x102e30: 0xdfb30030
    ctx->pc = 0x102e30u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x102e34: 0xdfb20020
    ctx->pc = 0x102e34u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x102e38: 0xdfb10010
    ctx->pc = 0x102e38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102e3c: 0xdfb00000
    ctx->pc = 0x102e3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102e40: 0x3e00008
    ctx->pc = 0x102E40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102E44u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 144));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102C20u: goto label_102c20;
            case 0x102C40u: goto label_102c40;
            case 0x102C50u: goto label_102c50;
            case 0x102C60u: goto label_102c60;
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102E48u;
    // 0x102e48: 0x382d
    ctx->pc = 0x102e48u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102e4c: 0x10a00013
    ctx->pc = 0x102E4Cu;
    {
        const bool branch_taken_0x102e4c = (GPR_U32(ctx, 5) == GPR_U32(ctx, 0));
        ctx->pc = 0x102E50u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 5), 4294967295));
        if (branch_taken_0x102e4c) {
            ctx->pc = 0x102E9Cu;
            goto label_102e9c;
        }
    }
    ctx->pc = 0x102E54u;
    // 0x102e54: 0x3c061000
    ctx->pc = 0x102e54u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x102e58: 0x3c051000
    ctx->pc = 0x102e58u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x102e5c: 0x34c63c00
    ctx->pc = 0x102e5cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 15360));
    // 0x102e60: 0x3c091000
    ctx->pc = 0x102e60u;
    SET_GPR_U32(ctx, 9, ((uint32_t)4096 << 16));
    // 0x102e64: 0x34a55000
    ctx->pc = 0x102e64u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 20480));
    // 0x102e68: 0x2408ffff
    ctx->pc = 0x102e68u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x102e6c: 0x0
    ctx->pc = 0x102e6cu;
    // NOP
label_102e70:
    // 0x102e70: 0x8cc20000
    ctx->pc = 0x102e70u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102e74: 0x491024
    ctx->pc = 0x102e74u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x102e78: 0x50400003
    ctx->pc = 0x102E78u;
    {
        const bool branch_taken_0x102e78 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x102e78) {
            ctx->pc = 0x102E7Cu;
            SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 4), 0)));
            ctx->pc = 0x102E88u;
            goto label_102e88;
        }
    }
    ctx->pc = 0x102E80u;
    // 0x102e80: 0x3e00008
    ctx->pc = 0x102E80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102E84u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102C20u: goto label_102c20;
            case 0x102C40u: goto label_102c40;
            case 0x102C50u: goto label_102c50;
            case 0x102C60u: goto label_102c60;
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102E88u;
label_102e88:
    // 0x102e88: 0x24e70001
    ctx->pc = 0x102e88u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 1));
    // 0x102e8c: 0x24840010
    ctx->pc = 0x102e8cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 16));
    // 0x102e90: 0x2463ffff
    ctx->pc = 0x102e90u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x102e94: 0x1468fff6
    ctx->pc = 0x102E94u;
    {
        const bool branch_taken_0x102e94 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 8));
        ctx->pc = 0x102E98u;
        WRITE128(ADD32(GPR_U32(ctx, 5), 0), GPR_VEC(ctx, 2));
        if (branch_taken_0x102e94) {
            ctx->pc = 0x102E70u;
            goto label_102e70;
        }
    }
    ctx->pc = 0x102E9Cu;
label_102e9c:
    // 0x102e9c: 0x3e00008
    ctx->pc = 0x102E9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102EA0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102C20u: goto label_102c20;
            case 0x102C40u: goto label_102c40;
            case 0x102C50u: goto label_102c50;
            case 0x102C60u: goto label_102c60;
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102EA4u;
    // 0x102ea4: 0x0
    ctx->pc = 0x102ea4u;
    // NOP
    // 0x102ea8: 0x382d
    ctx->pc = 0x102ea8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102eac: 0x10a00012
    ctx->pc = 0x102EACu;
    {
        const bool branch_taken_0x102eac = (GPR_U32(ctx, 5) == GPR_U32(ctx, 0));
        ctx->pc = 0x102EB0u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 5), 4294967295));
        if (branch_taken_0x102eac) {
            ctx->pc = 0x102EF8u;
            goto label_102ef8;
        }
    }
    ctx->pc = 0x102EB4u;
    // 0x102eb4: 0x3c061000
    ctx->pc = 0x102eb4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x102eb8: 0x3c051000
    ctx->pc = 0x102eb8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x102ebc: 0x34c63c00
    ctx->pc = 0x102ebcu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 15360));
    // 0x102ec0: 0x3c091f00
    ctx->pc = 0x102ec0u;
    SET_GPR_U32(ctx, 9, ((uint32_t)7936 << 16));
    // 0x102ec4: 0x34a55000
    ctx->pc = 0x102ec4u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 20480));
    // 0x102ec8: 0x2408ffff
    ctx->pc = 0x102ec8u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x102ecc: 0x0
    ctx->pc = 0x102eccu;
    // NOP
label_102ed0:
    // 0x102ed0: 0x8cc20000
    ctx->pc = 0x102ed0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102ed4: 0x491024
    ctx->pc = 0x102ed4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x102ed8: 0x10400009
    ctx->pc = 0x102ED8u;
    {
        const bool branch_taken_0x102ed8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x102EDCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x102ed8) {
            ctx->pc = 0x102F00u;
            goto label_102f00;
        }
    }
    ctx->pc = 0x102EE0u;
    // 0x102ee0: 0x78a20000
    ctx->pc = 0x102ee0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x102ee4: 0x24e70001
    ctx->pc = 0x102ee4u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 1));
    // 0x102ee8: 0x2463ffff
    ctx->pc = 0x102ee8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x102eec: 0x7c820000
    ctx->pc = 0x102eecu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 2));
    // 0x102ef0: 0x1468fff7
    ctx->pc = 0x102EF0u;
    {
        const bool branch_taken_0x102ef0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 8));
        ctx->pc = 0x102EF4u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 16));
        if (branch_taken_0x102ef0) {
            ctx->pc = 0x102ED0u;
            goto label_102ed0;
        }
    }
    ctx->pc = 0x102EF8u;
label_102ef8:
    // 0x102ef8: 0x3e00008
    ctx->pc = 0x102EF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102EFCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102C20u: goto label_102c20;
            case 0x102C40u: goto label_102c40;
            case 0x102C50u: goto label_102c50;
            case 0x102C60u: goto label_102c60;
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102F00u;
label_102f00:
    // 0x102f00: 0x3e00008
    ctx->pc = 0x102F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102C20u: goto label_102c20;
            case 0x102C40u: goto label_102c40;
            case 0x102C50u: goto label_102c50;
            case 0x102C60u: goto label_102c60;
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102F08u;
}
