#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00187D38
// Address: 0x187d38 - 0x187e50
void sub_00187D38_0x187d38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x187d38u;

    // 0x187d38: 0x27bdffa0
    ctx->pc = 0x187d38u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x187d3c: 0xffb20020
    ctx->pc = 0x187d3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x187d40: 0x80902d
    ctx->pc = 0x187d40u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187d44: 0xffb60040
    ctx->pc = 0x187d44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x187d48: 0x12b0c0
    ctx->pc = 0x187d48u;
    SET_GPR_U32(ctx, 22, SLL32(GPR_U32(ctx, 18), 3));
    // 0x187d4c: 0xffb70048
    ctx->pc = 0x187d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x187d50: 0x3c170029
    ctx->pc = 0x187d50u;
    SET_GPR_U32(ctx, 23, ((uint32_t)41 << 16));
    // 0x187d54: 0x26e2b8c8
    ctx->pc = 0x187d54u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 23), 4294949064));
    // 0x187d58: 0x2d21823
    ctx->pc = 0x187d58u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
    // 0x187d5c: 0xffb10018
    ctx->pc = 0x187d5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x187d60: 0x31880
    ctx->pc = 0x187d60u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
    // 0x187d64: 0xffb00010
    ctx->pc = 0x187d64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x187d68: 0x24420004
    ctx->pc = 0x187d68u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4));
    // 0x187d6c: 0xffb30028
    ctx->pc = 0x187d6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x187d70: 0x628821
    ctx->pc = 0x187d70u;
    SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x187d74: 0xffb40030
    ctx->pc = 0x187d74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x187d78: 0xffb50038
    ctx->pc = 0x187d78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x187d7c: 0xffbf0050
    ctx->pc = 0x187d7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x187d80: 0xc0623b6
    ctx->pc = 0x187D80u;
    SET_GPR_U32(ctx, 31, 0x187D88u);
    ctx->pc = 0x187D84u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    ctx->pc = 0x188ED8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187D88u; }
    }
    if (ctx->pc != 0x187D88u) { return; }
    ctx->pc = 0x187D88u;
    // 0x187d88: 0x24030003
    ctx->pc = 0x187d88u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
    // 0x187d8c: 0x14430004
    ctx->pc = 0x187D8Cu;
    {
        const bool branch_taken_0x187d8c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x187D90u;
        SET_GPR_U32(ctx, 21, ((uint32_t)41 << 16));
        if (branch_taken_0x187d8c) {
            ctx->pc = 0x187DA0u;
            goto label_187da0;
        }
    }
    ctx->pc = 0x187D94u;
    // 0x187d94: 0x10000022
    ctx->pc = 0x187D94u;
    {
        const bool branch_taken_0x187d94 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x187D98u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x187d94) {
            ctx->pc = 0x187E20u;
            goto label_187e20;
        }
    }
    ctx->pc = 0x187D9Cu;
    // 0x187d9c: 0x0
    ctx->pc = 0x187d9cu;
    // NOP
label_187da0:
    // 0x187da0: 0x282d
    ctx->pc = 0x187da0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187da4: 0x26a4b900
    ctx->pc = 0x187da4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 21), 4294949120));
    // 0x187da8: 0xc041f1a
    ctx->pc = 0x187DA8u;
    SET_GPR_U32(ctx, 31, 0x187DB0u);
    ctx->pc = 0x187DACu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 8320));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187DB0u; }
    }
    if (ctx->pc != 0x187DB0u) { return; }
    ctx->pc = 0x187DB0u;
    // 0x187db0: 0x3c040029
    ctx->pc = 0x187db0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)41 << 16));
    // 0x187db4: 0x24022080
    ctx->pc = 0x187db4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8320));
    // 0x187db8: 0x2484d980
    ctx->pc = 0x187db8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294957440));
    // 0x187dbc: 0x282d
    ctx->pc = 0x187dbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187dc0: 0x24060100
    ctx->pc = 0x187dc0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
    // 0x187dc4: 0xc041f1a
    ctx->pc = 0x187DC4u;
    SET_GPR_U32(ctx, 31, 0x187DCCu);
    ctx->pc = 0x187DC8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187DCCu; }
    }
    if (ctx->pc != 0x187DCCu) { return; }
    ctx->pc = 0x187DCCu;
    // 0x187dcc: 0x3c100023
    ctx->pc = 0x187dccu;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
    // 0x187dd0: 0x24020004
    ctx->pc = 0x187dd0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x187dd4: 0xae02fd24
    ctx->pc = 0x187dd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294966564), GPR_U32(ctx, 2));
    // 0x187dd8: 0x3c140018
    ctx->pc = 0x187dd8u;
    SET_GPR_U32(ctx, 20, ((uint32_t)24 << 16));
    // 0x187ddc: 0x24130001
    ctx->pc = 0x187ddcu;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 0), 1));
    // 0x187de0: 0x8e240000
    ctx->pc = 0x187de0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x187de4: 0x0
    ctx->pc = 0x187de4u;
    // NOP
label_187de8:
    // 0x187de8: 0x3a0302d
    ctx->pc = 0x187de8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187dec: 0x8e05fd24
    ctx->pc = 0x187decu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 4294966564)));
    // 0x187df0: 0x26a7b900
    ctx->pc = 0x187df0u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 21), 4294949120));
    // 0x187df4: 0xc062560
    ctx->pc = 0x187DF4u;
    SET_GPR_U32(ctx, 31, 0x187DFCu);
    ctx->pc = 0x187DF8u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 20), 30728));
    ctx->pc = 0x189580u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00189580_0x189580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187DFCu; }
    }
    if (ctx->pc != 0x187DFCu) { return; }
    ctx->pc = 0x187DFCu;
    // 0x187dfc: 0x5453fffa
    ctx->pc = 0x187DFCu;
    {
        const bool branch_taken_0x187dfc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 19));
        if (branch_taken_0x187dfc) {
            ctx->pc = 0x187E00u;
            SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
            ctx->pc = 0x187DE8u;
            goto label_187de8;
        }
    }
    ctx->pc = 0x187E04u;
    // 0x187e04: 0x2d21023
    ctx->pc = 0x187e04u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
    // 0x187e08: 0x26e3b8c8
    ctx->pc = 0x187e08u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 23), 4294949064));
    // 0x187e0c: 0x21080
    ctx->pc = 0x187e0cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
    // 0x187e10: 0x621821
    ctx->pc = 0x187e10u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x187e14: 0xc061db2
    ctx->pc = 0x187E14u;
    SET_GPR_U32(ctx, 31, 0x187E1Cu);
    ctx->pc = 0x187E18u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 4)));
    ctx->pc = 0x1876C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001876C8_0x1876c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187E1Cu; }
    }
    if (ctx->pc != 0x187E1Cu) { return; }
    ctx->pc = 0x187E1Cu;
    // 0x187e1c: 0x8c420008
    ctx->pc = 0x187e1cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 8)));
label_187e20:
    // 0x187e20: 0xdfb00010
    ctx->pc = 0x187e20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x187e24: 0xdfb10018
    ctx->pc = 0x187e24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x187e28: 0xdfb20020
    ctx->pc = 0x187e28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x187e2c: 0xdfb30028
    ctx->pc = 0x187e2cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x187e30: 0xdfb40030
    ctx->pc = 0x187e30u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x187e34: 0xdfb50038
    ctx->pc = 0x187e34u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x187e38: 0xdfb60040
    ctx->pc = 0x187e38u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x187e3c: 0xdfb70048
    ctx->pc = 0x187e3cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x187e40: 0xdfbf0050
    ctx->pc = 0x187e40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x187e44: 0x3e00008
    ctx->pc = 0x187E44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187E48u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187DA0u: goto label_187da0;
            case 0x187DE8u: goto label_187de8;
            case 0x187E20u: goto label_187e20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187E4Cu;
    // 0x187e4c: 0x0
    ctx->pc = 0x187e4cu;
    // NOP
}
