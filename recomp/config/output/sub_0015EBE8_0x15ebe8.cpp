#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0015EBE8
// Address: 0x15ebe8 - 0x15ee48
void sub_0015EBE8_0x15ebe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x15ebe8u;

    // 0x15ebe8: 0x27bdfff0
    ctx->pc = 0x15ebe8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ebec: 0xffbf0000
    ctx->pc = 0x15ebecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ebf0: 0xc05a6ce
    ctx->pc = 0x15EBF0u;
    SET_GPR_U32(ctx, 31, 0x15EBF8u);
    ctx->pc = 0x169B38u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169B38_0x169b38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBF8u; }
    }
    if (ctx->pc != 0x15EBF8u) { return; }
    ctx->pc = 0x15EBF8u;
    // 0x15ebf8: 0xdfbf0000
    ctx->pc = 0x15ebf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ebfc: 0x102d
    ctx->pc = 0x15ebfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec00: 0x3e00008
    ctx->pc = 0x15EC00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EC04u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EC58u: goto label_15ec58;
            case 0x15EC6Cu: goto label_15ec6c;
            case 0x15EC9Cu: goto label_15ec9c;
            case 0x15ECF0u: goto label_15ecf0;
            case 0x15ED2Cu: goto label_15ed2c;
            case 0x15ED40u: goto label_15ed40;
            case 0x15ED74u: goto label_15ed74;
            case 0x15ED90u: goto label_15ed90;
            case 0x15EDB8u: goto label_15edb8;
            case 0x15EDBCu: goto label_15edbc;
            case 0x15EDC0u: goto label_15edc0;
            case 0x15EDCCu: goto label_15edcc;
            case 0x15EDD0u: goto label_15edd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EC08u;
    // 0x15ec08: 0x27bdffd0
    ctx->pc = 0x15ec08u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15ec0c: 0xffb00000
    ctx->pc = 0x15ec0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ec10: 0x80802d
    ctx->pc = 0x15ec10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec14: 0xffb10008
    ctx->pc = 0x15ec14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15ec18: 0xa0882d
    ctx->pc = 0x15ec18u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec1c: 0xffb30018
    ctx->pc = 0x15ec1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15ec20: 0x982d
    ctx->pc = 0x15ec20u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec24: 0xffb20010
    ctx->pc = 0x15ec24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15ec28: 0xffb40020
    ctx->pc = 0x15ec28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x15ec2c: 0x1200000a
    ctx->pc = 0x15EC2Cu;
    {
        const bool branch_taken_0x15ec2c = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x15EC30u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        if (branch_taken_0x15ec2c) {
            ctx->pc = 0x15EC58u;
            goto label_15ec58;
        }
    }
    ctx->pc = 0x15EC34u;
    // 0x15ec34: 0xc057ec8
    ctx->pc = 0x15EC34u;
    SET_GPR_U32(ctx, 31, 0x15EC3Cu);
    ctx->pc = 0x15FB20u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EC3Cu; }
    }
    if (ctx->pc != 0x15EC3Cu) { return; }
    ctx->pc = 0x15EC3Cu;
    // 0x15ec3c: 0x3c030023
    ctx->pc = 0x15ec3cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x15ec40: 0x40902d
    ctx->pc = 0x15ec40u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec44: 0x3c020023
    ctx->pc = 0x15ec44u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x15ec48: 0xac50ef40
    ctx->pc = 0x15ec48u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963008), GPR_U32(ctx, 16));
    // 0x15ec4c: 0x10000007
    ctx->pc = 0x15EC4Cu;
    {
        const bool branch_taken_0x15ec4c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x15EC50u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294963012), GPR_U32(ctx, 18));
        if (branch_taken_0x15ec4c) {
            ctx->pc = 0x15EC6Cu;
            goto label_15ec6c;
        }
    }
    ctx->pc = 0x15EC54u;
    // 0x15ec54: 0x0
    ctx->pc = 0x15ec54u;
    // NOP
label_15ec58:
    // 0x15ec58: 0x3c020023
    ctx->pc = 0x15ec58u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x15ec5c: 0x3c030023
    ctx->pc = 0x15ec5cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x15ec60: 0xac40ef40
    ctx->pc = 0x15ec60u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963008), GPR_U32(ctx, 0));
    // 0x15ec64: 0x902d
    ctx->pc = 0x15ec64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec68: 0xac60ef44
    ctx->pc = 0x15ec68u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963012), GPR_U32(ctx, 0));
label_15ec6c:
    // 0x15ec6c: 0x1220000b
    ctx->pc = 0x15EC6Cu;
    {
        const bool branch_taken_0x15ec6c = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        ctx->pc = 0x15EC70u;
        SET_GPR_U32(ctx, 2, ((uint32_t)39 << 16));
        if (branch_taken_0x15ec6c) {
            ctx->pc = 0x15EC9Cu;
            goto label_15ec9c;
        }
    }
    ctx->pc = 0x15EC74u;
    // 0x15ec74: 0x24458580
    ctx->pc = 0x15ec74u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 2), 4294935936));
    // 0x15ec78: 0x8ca40000
    ctx->pc = 0x15ec78u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15ec7c: 0x41080
    ctx->pc = 0x15ec7cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 2));
    // 0x15ec80: 0x2883000f
    ctx->pc = 0x15ec80u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 4), 15));
    // 0x15ec84: 0x3c010027
    ctx->pc = 0x15ec84u;
    SET_GPR_U32(ctx, 1, ((uint32_t)39 << 16));
    // 0x15ec88: 0x220821
    ctx->pc = 0x15ec88u;
    SET_GPR_U32(ctx, 1, ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x15ec8c: 0xac318540
    ctx->pc = 0x15ec8cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294935872), GPR_U32(ctx, 17));
    // 0x15ec90: 0x10600002
    ctx->pc = 0x15EC90u;
    {
        const bool branch_taken_0x15ec90 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x15EC94u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x15ec90) {
            ctx->pc = 0x15EC9Cu;
            goto label_15ec9c;
        }
    }
    ctx->pc = 0x15EC98u;
    // 0x15ec98: 0xaca20000
    ctx->pc = 0x15ec98u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_15ec9c:
    // 0x15ec9c: 0x3c02ff00
    ctx->pc = 0x15ec9cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x15eca0: 0x34420f1c
    ctx->pc = 0x15eca0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 3868));
    // 0x15eca4: 0x1222003a
    ctx->pc = 0x15ECA4u;
    {
        const bool branch_taken_0x15eca4 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 2));
        ctx->pc = 0x15ECA8u;
        SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
        if (branch_taken_0x15eca4) {
            ctx->pc = 0x15ED90u;
            goto label_15ed90;
        }
    }
    ctx->pc = 0x15ECACu;
    // 0x15ecac: 0x14400010
    ctx->pc = 0x15ECACu;
    {
        const bool branch_taken_0x15ecac = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x15ecac) {
            ctx->pc = 0x15ECF0u;
            goto label_15ecf0;
        }
    }
    ctx->pc = 0x15ECB4u;
    // 0x15ecb4: 0x3c02ff00
    ctx->pc = 0x15ecb4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x15ecb8: 0x34420f18
    ctx->pc = 0x15ecb8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 3864));
    // 0x15ecbc: 0x51102b
    ctx->pc = 0x15ecbcu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x15ecc0: 0x1440003d
    ctx->pc = 0x15ECC0u;
    {
        const bool branch_taken_0x15ecc0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x15ECC4u;
        SET_GPR_U32(ctx, 20, ((uint32_t)39 << 16));
        if (branch_taken_0x15ecc0) {
            ctx->pc = 0x15EDB8u;
            goto label_15edb8;
        }
    }
    ctx->pc = 0x15ECC8u;
    // 0x15ecc8: 0x3c02ff00
    ctx->pc = 0x15ecc8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x15eccc: 0x34420f17
    ctx->pc = 0x15ecccu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 3863));
    // 0x15ecd0: 0x222102b
    ctx->pc = 0x15ecd0u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x15ecd4: 0x54400039
    ctx->pc = 0x15ECD4u;
    {
        const bool branch_taken_0x15ecd4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x15ecd4) {
            ctx->pc = 0x15ECD8u;
            SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
            ctx->pc = 0x15EDBCu;
            goto label_15edbc;
        }
    }
    ctx->pc = 0x15ECDCu;
    // 0x15ecdc: 0x3c140027
    ctx->pc = 0x15ecdcu;
    SET_GPR_U32(ctx, 20, ((uint32_t)39 << 16));
    // 0x15ece0: 0x3c050024
    ctx->pc = 0x15ece0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x15ece4: 0x10000011
    ctx->pc = 0x15ECE4u;
    {
        const bool branch_taken_0x15ece4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x15ECE8u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294963016));
        if (branch_taken_0x15ece4) {
            ctx->pc = 0x15ED2Cu;
            goto label_15ed2c;
        }
    }
    ctx->pc = 0x15ECECu;
    // 0x15ecec: 0x0
    ctx->pc = 0x15ececu;
    // NOP
label_15ecf0:
    // 0x15ecf0: 0x3c02ff00
    ctx->pc = 0x15ecf0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x15ecf4: 0x34420f40
    ctx->pc = 0x15ecf4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 3904));
    // 0x15ecf8: 0x12220011
    ctx->pc = 0x15ECF8u;
    {
        const bool branch_taken_0x15ecf8 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 2));
        ctx->pc = 0x15ECFCu;
        SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
        if (branch_taken_0x15ecf8) {
            ctx->pc = 0x15ED40u;
            goto label_15ed40;
        }
    }
    ctx->pc = 0x15ED00u;
    // 0x15ed00: 0x1440002d
    ctx->pc = 0x15ED00u;
    {
        const bool branch_taken_0x15ed00 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x15ED04u;
        SET_GPR_U32(ctx, 20, ((uint32_t)39 << 16));
        if (branch_taken_0x15ed00) {
            ctx->pc = 0x15EDB8u;
            goto label_15edb8;
        }
    }
    ctx->pc = 0x15ED08u;
    // 0x15ed08: 0x2e22ffff
    ctx->pc = 0x15ed08u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 17), 65535));
    // 0x15ed0c: 0x1040002b
    ctx->pc = 0x15ED0Cu;
    {
        const bool branch_taken_0x15ed0c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x15ED10u;
        SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
        if (branch_taken_0x15ed0c) {
            ctx->pc = 0x15EDBCu;
            goto label_15edbc;
        }
    }
    ctx->pc = 0x15ED14u;
    // 0x15ed14: 0x2e22fffd
    ctx->pc = 0x15ed14u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 17), 65533));
    // 0x15ed18: 0x14400029
    ctx->pc = 0x15ED18u;
    {
        const bool branch_taken_0x15ed18 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x15ED1Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294963168));
        if (branch_taken_0x15ed18) {
            ctx->pc = 0x15EDC0u;
            goto label_15edc0;
        }
    }
    ctx->pc = 0x15ED20u;
    // 0x15ed20: 0x3c140027
    ctx->pc = 0x15ed20u;
    SET_GPR_U32(ctx, 20, ((uint32_t)39 << 16));
    // 0x15ed24: 0x3c050024
    ctx->pc = 0x15ed24u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x15ed28: 0x24a5ef18
    ctx->pc = 0x15ed28u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294962968));
label_15ed2c:
    // 0x15ed2c: 0x220302d
    ctx->pc = 0x15ed2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ed30: 0xc042a0c
    ctx->pc = 0x15ED30u;
    SET_GPR_U32(ctx, 31, 0x15ED38u);
    ctx->pc = 0x15ED34u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 4294935944));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED38u; }
    }
    if (ctx->pc != 0x15ED38u) { return; }
    ctx->pc = 0x15ED38u;
    // 0x15ed38: 0x10000025
    ctx->pc = 0x15ED38u;
    {
        const bool branch_taken_0x15ed38 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x15ED3Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 4294935944));
        if (branch_taken_0x15ed38) {
            ctx->pc = 0x15EDD0u;
            goto label_15edd0;
        }
    }
    ctx->pc = 0x15ED40u;
label_15ed40:
    // 0x15ed40: 0x3c140027
    ctx->pc = 0x15ed40u;
    SET_GPR_U32(ctx, 20, ((uint32_t)39 << 16));
    // 0x15ed44: 0x3c050024
    ctx->pc = 0x15ed44u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x15ed48: 0x26908588
    ctx->pc = 0x15ed48u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 20), 4294935944));
    // 0x15ed4c: 0x3c06ff00
    ctx->pc = 0x15ed4cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)65280 << 16));
    // 0x15ed50: 0x24a5ef30
    ctx->pc = 0x15ed50u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294962992));
    // 0x15ed54: 0x200202d
    ctx->pc = 0x15ed54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ed58: 0xc042a0c
    ctx->pc = 0x15ED58u;
    SET_GPR_U32(ctx, 31, 0x15ED60u);
    ctx->pc = 0x15ED5Cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 3904));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED60u; }
    }
    if (ctx->pc != 0x15ED60u) { return; }
    ctx->pc = 0x15ED60u;
    // 0x15ed60: 0x12400004
    ctx->pc = 0x15ED60u;
    {
        const bool branch_taken_0x15ed60 = (GPR_U32(ctx, 18) == GPR_U32(ctx, 0));
        if (branch_taken_0x15ed60) {
            ctx->pc = 0x15ED74u;
            goto label_15ed74;
        }
    }
    ctx->pc = 0x15ED68u;
    // 0x15ed68: 0xc05c602
    ctx->pc = 0x15ED68u;
    SET_GPR_U32(ctx, 31, 0x15ED70u);
    ctx->pc = 0x15ED6Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x171808u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00171808_0x171808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED70u; }
    }
    if (ctx->pc != 0x15ED70u) { return; }
    ctx->pc = 0x15ED70u;
    // 0x15ed70: 0x40982d
    ctx->pc = 0x15ed70u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_15ed74:
    // 0x15ed74: 0x12600015
    ctx->pc = 0x15ED74u;
    {
        const bool branch_taken_0x15ed74 = (GPR_U32(ctx, 19) == GPR_U32(ctx, 0));
        ctx->pc = 0x15ED78u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x15ed74) {
            ctx->pc = 0x15EDCCu;
            goto label_15edcc;
        }
    }
    ctx->pc = 0x15ED7Cu;
    // 0x15ed7c: 0x260282d
    ctx->pc = 0x15ed7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ed80: 0xc042ca4
    ctx->pc = 0x15ED80u;
    SET_GPR_U32(ctx, 31, 0x15ED88u);
    ctx->pc = 0x15ED84u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 105));
    ctx->pc = 0x10B290u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B290_0x10b290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED88u; }
    }
    if (ctx->pc != 0x15ED88u) { return; }
    ctx->pc = 0x15ED88u;
    // 0x15ed88: 0x10000011
    ctx->pc = 0x15ED88u;
    {
        const bool branch_taken_0x15ed88 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x15ED8Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 4294935944));
        if (branch_taken_0x15ed88) {
            ctx->pc = 0x15EDD0u;
            goto label_15edd0;
        }
    }
    ctx->pc = 0x15ED90u;
label_15ed90:
    // 0x15ed90: 0x3c140027
    ctx->pc = 0x15ed90u;
    SET_GPR_U32(ctx, 20, ((uint32_t)39 << 16));
    // 0x15ed94: 0x3c050024
    ctx->pc = 0x15ed94u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x15ed98: 0x3c06ff00
    ctx->pc = 0x15ed98u;
    SET_GPR_U32(ctx, 6, ((uint32_t)65280 << 16));
    // 0x15ed9c: 0x24a5ef80
    ctx->pc = 0x15ed9cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294963072));
    // 0x15eda0: 0x26848588
    ctx->pc = 0x15eda0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 4294935944));
    // 0x15eda4: 0xc042a0c
    ctx->pc = 0x15EDA4u;
    SET_GPR_U32(ctx, 31, 0x15EDACu);
    ctx->pc = 0x15EDA8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 3868));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EDACu; }
    }
    if (ctx->pc != 0x15EDACu) { return; }
    ctx->pc = 0x15EDACu;
    // 0x15edac: 0x10000008
    ctx->pc = 0x15EDACu;
    {
        const bool branch_taken_0x15edac = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x15EDB0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 4294935944));
        if (branch_taken_0x15edac) {
            ctx->pc = 0x15EDD0u;
            goto label_15edd0;
        }
    }
    ctx->pc = 0x15EDB4u;
    // 0x15edb4: 0x0
    ctx->pc = 0x15edb4u;
    // NOP
label_15edb8:
    // 0x15edb8: 0x3c050024
    ctx->pc = 0x15edb8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
label_15edbc:
    // 0x15edbc: 0x24a5efe0
    ctx->pc = 0x15edbcu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294963168));
label_15edc0:
    // 0x15edc0: 0x220302d
    ctx->pc = 0x15edc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15edc4: 0xc042a0c
    ctx->pc = 0x15EDC4u;
    SET_GPR_U32(ctx, 31, 0x15EDCCu);
    ctx->pc = 0x15EDC8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 4294935944));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EDCCu; }
    }
    if (ctx->pc != 0x15EDCCu) { return; }
    ctx->pc = 0x15EDCCu;
label_15edcc:
    // 0x15edcc: 0x26848588
    ctx->pc = 0x15edccu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 4294935944));
label_15edd0:
    // 0x15edd0: 0xdfb40020
    ctx->pc = 0x15edd0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15edd4: 0xdfb00000
    ctx->pc = 0x15edd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15edd8: 0xdfb10008
    ctx->pc = 0x15edd8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15eddc: 0xdfb20010
    ctx->pc = 0x15eddcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15ede0: 0xdfb30018
    ctx->pc = 0x15ede0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15ede4: 0xdfbf0028
    ctx->pc = 0x15ede4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15ede8: 0x8058dd4
    ctx->pc = 0x15EDE8u;
    ctx->pc = 0x15EDECu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x163750u;
    sub_00163750_0x163750(rdram, ctx, runtime); return;
    ctx->pc = 0x15EDF0u;
    // 0x15edf0: 0x3c030023
    ctx->pc = 0x15edf0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x15edf4: 0x3e00008
    ctx->pc = 0x15EDF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EDF8u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294963008)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EC58u: goto label_15ec58;
            case 0x15EC6Cu: goto label_15ec6c;
            case 0x15EC9Cu: goto label_15ec9c;
            case 0x15ECF0u: goto label_15ecf0;
            case 0x15ED2Cu: goto label_15ed2c;
            case 0x15ED40u: goto label_15ed40;
            case 0x15ED74u: goto label_15ed74;
            case 0x15ED90u: goto label_15ed90;
            case 0x15EDB8u: goto label_15edb8;
            case 0x15EDBCu: goto label_15edbc;
            case 0x15EDC0u: goto label_15edc0;
            case 0x15EDCCu: goto label_15edcc;
            case 0x15EDD0u: goto label_15edd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EDFCu;
    // 0x15edfc: 0x0
    ctx->pc = 0x15edfcu;
    // NOP
    // 0x15ee00: 0x27bdfff0
    ctx->pc = 0x15ee00u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ee04: 0xffb00000
    ctx->pc = 0x15ee04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ee08: 0xffbf0008
    ctx->pc = 0x15ee08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15ee0c: 0xc05799e
    ctx->pc = 0x15EE0Cu;
    SET_GPR_U32(ctx, 31, 0x15EE14u);
    ctx->pc = 0x15EE10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x15E678u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE14u; }
    }
    if (ctx->pc != 0x15EE14u) { return; }
    ctx->pc = 0x15EE14u;
    // 0x15ee14: 0xac500034
    ctx->pc = 0x15ee14u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 52), GPR_U32(ctx, 16));
    // 0x15ee18: 0xdfbf0008
    ctx->pc = 0x15ee18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15ee1c: 0xdfb00000
    ctx->pc = 0x15ee1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ee20: 0x3e00008
    ctx->pc = 0x15EE20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EE24u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EC58u: goto label_15ec58;
            case 0x15EC6Cu: goto label_15ec6c;
            case 0x15EC9Cu: goto label_15ec9c;
            case 0x15ECF0u: goto label_15ecf0;
            case 0x15ED2Cu: goto label_15ed2c;
            case 0x15ED40u: goto label_15ed40;
            case 0x15ED74u: goto label_15ed74;
            case 0x15ED90u: goto label_15ed90;
            case 0x15EDB8u: goto label_15edb8;
            case 0x15EDBCu: goto label_15edbc;
            case 0x15EDC0u: goto label_15edc0;
            case 0x15EDCCu: goto label_15edcc;
            case 0x15EDD0u: goto label_15edd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EE28u;
    // 0x15ee28: 0x27bdfff0
    ctx->pc = 0x15ee28u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ee2c: 0xffbf0000
    ctx->pc = 0x15ee2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ee30: 0xc05799e
    ctx->pc = 0x15EE30u;
    SET_GPR_U32(ctx, 31, 0x15EE38u);
    ctx->pc = 0x15E678u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE38u; }
    }
    if (ctx->pc != 0x15EE38u) { return; }
    ctx->pc = 0x15EE38u;
    // 0x15ee38: 0x8c420034
    ctx->pc = 0x15ee38u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x15ee3c: 0xdfbf0000
    ctx->pc = 0x15ee3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ee40: 0x3e00008
    ctx->pc = 0x15EE40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EE44u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EC58u: goto label_15ec58;
            case 0x15EC6Cu: goto label_15ec6c;
            case 0x15EC9Cu: goto label_15ec9c;
            case 0x15ECF0u: goto label_15ecf0;
            case 0x15ED2Cu: goto label_15ed2c;
            case 0x15ED40u: goto label_15ed40;
            case 0x15ED74u: goto label_15ed74;
            case 0x15ED90u: goto label_15ed90;
            case 0x15EDB8u: goto label_15edb8;
            case 0x15EDBCu: goto label_15edbc;
            case 0x15EDC0u: goto label_15edc0;
            case 0x15EDCCu: goto label_15edcc;
            case 0x15EDD0u: goto label_15edd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EE48u;
}
