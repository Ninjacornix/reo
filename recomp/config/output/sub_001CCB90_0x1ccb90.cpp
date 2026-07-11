#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001CCB90
// Address: 0x1ccb90 - 0x1cccf0
void sub_001CCB90_0x1ccb90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1ccb90u;

    // 0x1ccb90: 0x27bdff80
    ctx->pc = 0x1ccb90u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1ccb94: 0xffbf0020
    ctx->pc = 0x1ccb94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ccb98: 0x7fb10010
    ctx->pc = 0x1ccb98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ccb9c: 0x80882d
    ctx->pc = 0x1ccb9cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ccba0: 0xc0732a0
    ctx->pc = 0x1CCBA0u;
    SET_GPR_U32(ctx, 31, 0x1CCBA8u);
    ctx->pc = 0x1CCBA4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x1CCA80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCA80_0x1cca80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCBA8u; }
    }
    if (ctx->pc != 0x1CCBA8u) { return; }
    ctx->pc = 0x1CCBA8u;
    // 0x1ccba8: 0x40802d
    ctx->pc = 0x1ccba8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ccbac: 0x16000003
    ctx->pc = 0x1CCBACu;
    {
        const bool branch_taken_0x1ccbac = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x1CCBB0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1ccbac) {
            ctx->pc = 0x1CCBBCu;
            goto label_1ccbbc;
        }
    }
    ctx->pc = 0x1CCBB4u;
    // 0x1ccbb4: 0x1000001a
    ctx->pc = 0x1CCBB4u;
    {
        const bool branch_taken_0x1ccbb4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1CCBB8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1ccbb4) {
            ctx->pc = 0x1CCC20u;
            goto label_1ccc20;
        }
    }
    ctx->pc = 0x1CCBBCu;
label_1ccbbc:
    // 0x1ccbbc: 0xc063790
    ctx->pc = 0x1CCBBCu;
    SET_GPR_U32(ctx, 31, 0x1CCBC4u);
    ctx->pc = 0x1CCBC0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x18DE40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DE40_0x18de40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCBC4u; }
    }
    if (ctx->pc != 0x1CCBC4u) { return; }
    ctx->pc = 0x1CCBC4u;
    // 0x1ccbc4: 0xae020000
    ctx->pc = 0x1ccbc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1ccbc8: 0x8e020000
    ctx->pc = 0x1ccbc8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ccbcc: 0x10400011
    ctx->pc = 0x1CCBCCu;
    {
        const bool branch_taken_0x1ccbcc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1CCBD0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1ccbcc) {
            ctx->pc = 0x1CCC14u;
            goto label_1ccc14;
        }
    }
    ctx->pc = 0x1CCBD4u;
    // 0x1ccbd4: 0x3045ffff
    ctx->pc = 0x1ccbd4u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 2), 65535));
    // 0x1ccbd8: 0xc067644
    ctx->pc = 0x1CCBD8u;
    SET_GPR_U32(ctx, 31, 0x1CCBE0u);
    ctx->pc = 0x1CCBDCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x19D910u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D910_0x19d910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCBE0u; }
    }
    if (ctx->pc != 0x1CCBE0u) { return; }
    ctx->pc = 0x1CCBE0u;
    // 0x1ccbe0: 0x24030001
    ctx->pc = 0x1ccbe0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ccbe4: 0x14430009
    ctx->pc = 0x1CCBE4u;
    {
        const bool branch_taken_0x1ccbe4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x1ccbe4) {
            ctx->pc = 0x1CCC0Cu;
            goto label_1ccc0c;
        }
    }
    ctx->pc = 0x1CCBECu;
    // 0x1ccbec: 0xae110004
    ctx->pc = 0x1ccbecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x1ccbf0: 0x8fa20034
    ctx->pc = 0x1ccbf0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1ccbf4: 0xa6020008
    ctx->pc = 0x1ccbf4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ccbf8: 0x8fa20038
    ctx->pc = 0x1ccbf8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1ccbfc: 0xa602000a
    ctx->pc = 0x1ccbfcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ccc00: 0x8fa20044
    ctx->pc = 0x1ccc00u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1ccc04: 0xa602000c
    ctx->pc = 0x1ccc04u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ccc08: 0xa603000e
    ctx->pc = 0x1ccc08u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 3));
label_1ccc0c:
    // 0x1ccc0c: 0x10000004
    ctx->pc = 0x1CCC0Cu;
    {
        const bool branch_taken_0x1ccc0c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1CCC10u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1ccc0c) {
            ctx->pc = 0x1CCC20u;
            goto label_1ccc20;
        }
    }
    ctx->pc = 0x1CCC14u;
label_1ccc14:
    // 0x1ccc14: 0xc0732b4
    ctx->pc = 0x1CCC14u;
    SET_GPR_U32(ctx, 31, 0x1CCC1Cu);
    ctx->pc = 0x1CCAD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCAD0_0x1ccad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCC1Cu; }
    }
    if (ctx->pc != 0x1CCC1Cu) { return; }
    ctx->pc = 0x1CCC1Cu;
    // 0x1ccc1c: 0x102d
    ctx->pc = 0x1ccc1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ccc20:
    // 0x1ccc20: 0xdfbf0020
    ctx->pc = 0x1ccc20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ccc24: 0x7bb10010
    ctx->pc = 0x1ccc24u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ccc28: 0x7bb00000
    ctx->pc = 0x1ccc28u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ccc2c: 0x3e00008
    ctx->pc = 0x1CCC2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CCC30u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CCBBCu: goto label_1ccbbc;
            case 0x1CCC0Cu: goto label_1ccc0c;
            case 0x1CCC14u: goto label_1ccc14;
            case 0x1CCC20u: goto label_1ccc20;
            case 0x1CCC6Cu: goto label_1ccc6c;
            case 0x1CCCBCu: goto label_1cccbc;
            case 0x1CCCC4u: goto label_1cccc4;
            case 0x1CCCD0u: goto label_1cccd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CCC34u;
    // 0x1ccc34: 0x0
    ctx->pc = 0x1ccc34u;
    // NOP
    // 0x1ccc38: 0x0
    ctx->pc = 0x1ccc38u;
    // NOP
    // 0x1ccc3c: 0x0
    ctx->pc = 0x1ccc3cu;
    // NOP
    // 0x1ccc40: 0x27bdff80
    ctx->pc = 0x1ccc40u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1ccc44: 0xffbf0020
    ctx->pc = 0x1ccc44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ccc48: 0x7fb10010
    ctx->pc = 0x1ccc48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ccc4c: 0x80882d
    ctx->pc = 0x1ccc4cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ccc50: 0xc0732a0
    ctx->pc = 0x1CCC50u;
    SET_GPR_U32(ctx, 31, 0x1CCC58u);
    ctx->pc = 0x1CCC54u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x1CCA80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCA80_0x1cca80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCC58u; }
    }
    if (ctx->pc != 0x1CCC58u) { return; }
    ctx->pc = 0x1CCC58u;
    // 0x1ccc58: 0x40802d
    ctx->pc = 0x1ccc58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ccc5c: 0x16000003
    ctx->pc = 0x1CCC5Cu;
    {
        const bool branch_taken_0x1ccc5c = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x1CCC60u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1ccc5c) {
            ctx->pc = 0x1CCC6Cu;
            goto label_1ccc6c;
        }
    }
    ctx->pc = 0x1CCC64u;
    // 0x1ccc64: 0x1000001a
    ctx->pc = 0x1CCC64u;
    {
        const bool branch_taken_0x1ccc64 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1CCC68u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1ccc64) {
            ctx->pc = 0x1CCCD0u;
            goto label_1cccd0;
        }
    }
    ctx->pc = 0x1CCC6Cu;
label_1ccc6c:
    // 0x1ccc6c: 0xc06388c
    ctx->pc = 0x1CCC6Cu;
    SET_GPR_U32(ctx, 31, 0x1CCC74u);
    ctx->pc = 0x1CCC70u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x18E230u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E230_0x18e230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCC74u; }
    }
    if (ctx->pc != 0x1CCC74u) { return; }
    ctx->pc = 0x1CCC74u;
    // 0x1ccc74: 0xae020000
    ctx->pc = 0x1ccc74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1ccc78: 0x8e020000
    ctx->pc = 0x1ccc78u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ccc7c: 0x10400011
    ctx->pc = 0x1CCC7Cu;
    {
        const bool branch_taken_0x1ccc7c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1CCC80u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1ccc7c) {
            ctx->pc = 0x1CCCC4u;
            goto label_1cccc4;
        }
    }
    ctx->pc = 0x1CCC84u;
    // 0x1ccc84: 0x3045ffff
    ctx->pc = 0x1ccc84u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 2), 65535));
    // 0x1ccc88: 0xc067644
    ctx->pc = 0x1CCC88u;
    SET_GPR_U32(ctx, 31, 0x1CCC90u);
    ctx->pc = 0x1CCC8Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x19D910u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D910_0x19d910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCC90u; }
    }
    if (ctx->pc != 0x1CCC90u) { return; }
    ctx->pc = 0x1CCC90u;
    // 0x1ccc90: 0x24030001
    ctx->pc = 0x1ccc90u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ccc94: 0x14430009
    ctx->pc = 0x1CCC94u;
    {
        const bool branch_taken_0x1ccc94 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x1ccc94) {
            ctx->pc = 0x1CCCBCu;
            goto label_1cccbc;
        }
    }
    ctx->pc = 0x1CCC9Cu;
    // 0x1ccc9c: 0xae110004
    ctx->pc = 0x1ccc9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x1ccca0: 0x8fa20034
    ctx->pc = 0x1ccca0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1ccca4: 0xa6020008
    ctx->pc = 0x1ccca4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ccca8: 0x8fa20038
    ctx->pc = 0x1ccca8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1cccac: 0xa602000a
    ctx->pc = 0x1cccacu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cccb0: 0x8fa20044
    ctx->pc = 0x1cccb0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1cccb4: 0xa602000c
    ctx->pc = 0x1cccb4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cccb8: 0xa603000e
    ctx->pc = 0x1cccb8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 3));
label_1cccbc:
    // 0x1cccbc: 0x10000004
    ctx->pc = 0x1CCCBCu;
    {
        const bool branch_taken_0x1cccbc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1CCCC0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1cccbc) {
            ctx->pc = 0x1CCCD0u;
            goto label_1cccd0;
        }
    }
    ctx->pc = 0x1CCCC4u;
label_1cccc4:
    // 0x1cccc4: 0xc0732b4
    ctx->pc = 0x1CCCC4u;
    SET_GPR_U32(ctx, 31, 0x1CCCCCu);
    ctx->pc = 0x1CCAD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCAD0_0x1ccad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCCCCu; }
    }
    if (ctx->pc != 0x1CCCCCu) { return; }
    ctx->pc = 0x1CCCCCu;
    // 0x1ccccc: 0x102d
    ctx->pc = 0x1cccccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cccd0:
    // 0x1cccd0: 0xdfbf0020
    ctx->pc = 0x1cccd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cccd4: 0x7bb10010
    ctx->pc = 0x1cccd4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cccd8: 0x7bb00000
    ctx->pc = 0x1cccd8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cccdc: 0x3e00008
    ctx->pc = 0x1CCCDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CCCE0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CCBBCu: goto label_1ccbbc;
            case 0x1CCC0Cu: goto label_1ccc0c;
            case 0x1CCC14u: goto label_1ccc14;
            case 0x1CCC20u: goto label_1ccc20;
            case 0x1CCC6Cu: goto label_1ccc6c;
            case 0x1CCCBCu: goto label_1cccbc;
            case 0x1CCCC4u: goto label_1cccc4;
            case 0x1CCCD0u: goto label_1cccd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CCCE4u;
    // 0x1ccce4: 0x0
    ctx->pc = 0x1ccce4u;
    // NOP
    // 0x1ccce8: 0x0
    ctx->pc = 0x1ccce8u;
    // NOP
    // 0x1cccec: 0x0
    ctx->pc = 0x1cccecu;
    // NOP
}
