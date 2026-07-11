#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001B7CB0
// Address: 0x1b7cb0 - 0x1b7ee0
void sub_001B7CB0_0x1b7cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1b7cb0u;

label_1b7cb0:
    // 0x1b7cb0: 0x27bdffb0
    ctx->pc = 0x1b7cb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
label_1b7cb4:
    // 0x1b7cb4: 0x3c010023
    ctx->pc = 0x1b7cb4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1b7cb8:
    // 0x1b7cb8: 0xffbf0040
    ctx->pc = 0x1b7cb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
label_1b7cbc:
    // 0x1b7cbc: 0x2402ffff
    ctx->pc = 0x1b7cbcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1b7cc0:
    // 0x1b7cc0: 0x7fb30030
    ctx->pc = 0x1b7cc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
label_1b7cc4:
    // 0x1b7cc4: 0x7fb20020
    ctx->pc = 0x1b7cc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
label_1b7cc8:
    // 0x1b7cc8: 0x7fb10010
    ctx->pc = 0x1b7cc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
label_1b7ccc:
    // 0x1b7ccc: 0x7fb00000
    ctx->pc = 0x1b7cccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_1b7cd0:
    // 0x1b7cd0: 0x802447f0
    ctx->pc = 0x1b7cd0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18416)));
label_1b7cd4:
    // 0x1b7cd4: 0x10820014
label_1b7cd8:
    if (ctx->pc == 0x1B7CD8u) {
        ctx->pc = 0x1B7CDCu;
        goto label_1b7cdc;
    }
    ctx->pc = 0x1B7CD4u;
    {
        const bool branch_taken_0x1b7cd4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        if (branch_taken_0x1b7cd4) {
            ctx->pc = 0x1B7D28u;
            goto label_1b7d28;
        }
    }
    ctx->pc = 0x1B7CDCu;
label_1b7cdc:
    // 0x1b7cdc: 0xc06a568
label_1b7ce0:
    if (ctx->pc == 0x1B7CE0u) {
        ctx->pc = 0x1B7CE4u;
        goto label_1b7ce4;
    }
    ctx->pc = 0x1B7CDCu;
    SET_GPR_U32(ctx, 31, 0x1B7CE4u);
    ctx->pc = 0x1A95A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A95A0_0x1a95a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7CE4u; }
    }
    if (ctx->pc != 0x1B7CE4u) { return; }
    ctx->pc = 0x1B7CE4u;
label_1b7ce4:
    // 0x1b7ce4: 0x3c010023
    ctx->pc = 0x1b7ce4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1b7ce8:
    // 0x1b7ce8: 0x3c110031
    ctx->pc = 0x1b7ce8u;
    SET_GPR_U32(ctx, 17, ((uint32_t)49 << 16));
label_1b7cec:
    // 0x1b7cec: 0x802347f0
    ctx->pc = 0x1b7cecu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18416)));
label_1b7cf0:
    // 0x1b7cf0: 0x263163d0
    ctx->pc = 0x1b7cf0u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 25552));
label_1b7cf4:
    // 0x1b7cf4: 0x2402ffff
    ctx->pc = 0x1b7cf4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1b7cf8:
    // 0x1b7cf8: 0x282d
    ctx->pc = 0x1b7cf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b7cfc:
    // 0x1b7cfc: 0x220202d
    ctx->pc = 0x1b7cfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1b7d00:
    // 0x1b7d00: 0x3c010032
    ctx->pc = 0x1b7d00u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
label_1b7d04:
    // 0x1b7d04: 0xa02343f8
    ctx->pc = 0x1b7d04u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17400), (uint8_t)GPR_U32(ctx, 3));
label_1b7d08:
    // 0x1b7d08: 0x3c010023
    ctx->pc = 0x1b7d08u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1b7d0c:
    // 0x1b7d0c: 0xa02247f0
    ctx->pc = 0x1b7d0cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 18416), (uint8_t)GPR_U32(ctx, 2));
label_1b7d10:
    // 0x1b7d10: 0x8e300004
    ctx->pc = 0x1b7d10u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_1b7d14:
    // 0x1b7d14: 0xc041f1a
label_1b7d18:
    if (ctx->pc == 0x1B7D18u) {
        ctx->pc = 0x1B7D18u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 32));
        ctx->pc = 0x1B7D1Cu;
        goto label_1b7d1c;
    }
    ctx->pc = 0x1B7D14u;
    SET_GPR_U32(ctx, 31, 0x1B7D1Cu);
    ctx->pc = 0x1B7D18u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 32));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7D1Cu; }
    }
    if (ctx->pc != 0x1B7D1Cu) { return; }
    ctx->pc = 0x1B7D1Cu;
label_1b7d1c:
    // 0x1b7d1c: 0xae300004
    ctx->pc = 0x1b7d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 16));
label_1b7d20:
    // 0x1b7d20: 0x24020004
    ctx->pc = 0x1b7d20u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
label_1b7d24:
    // 0x1b7d24: 0xa6220000
    ctx->pc = 0x1b7d24u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_1b7d28:
    // 0x1b7d28: 0x3c010023
    ctx->pc = 0x1b7d28u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1b7d2c:
    // 0x1b7d2c: 0x2402ffff
    ctx->pc = 0x1b7d2cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1b7d30:
    // 0x1b7d30: 0x802447f8
    ctx->pc = 0x1b7d30u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18424)));
label_1b7d34:
    // 0x1b7d34: 0x1082000a
label_1b7d38:
    if (ctx->pc == 0x1B7D38u) {
        ctx->pc = 0x1B7D3Cu;
        goto label_1b7d3c;
    }
    ctx->pc = 0x1B7D34u;
    {
        const bool branch_taken_0x1b7d34 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        if (branch_taken_0x1b7d34) {
            ctx->pc = 0x1B7D60u;
            goto label_1b7d60;
        }
    }
    ctx->pc = 0x1B7D3Cu;
label_1b7d3c:
    // 0x1b7d3c: 0xc06a568
label_1b7d40:
    if (ctx->pc == 0x1B7D40u) {
        ctx->pc = 0x1B7D44u;
        goto label_1b7d44;
    }
    ctx->pc = 0x1B7D3Cu;
    SET_GPR_U32(ctx, 31, 0x1B7D44u);
    ctx->pc = 0x1A95A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A95A0_0x1a95a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7D44u; }
    }
    if (ctx->pc != 0x1B7D44u) { return; }
    ctx->pc = 0x1B7D44u;
label_1b7d44:
    // 0x1b7d44: 0x3c010023
    ctx->pc = 0x1b7d44u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1b7d48:
    // 0x1b7d48: 0x2402ffff
    ctx->pc = 0x1b7d48u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1b7d4c:
    // 0x1b7d4c: 0x802347f8
    ctx->pc = 0x1b7d4cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18424)));
label_1b7d50:
    // 0x1b7d50: 0x3c010032
    ctx->pc = 0x1b7d50u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
label_1b7d54:
    // 0x1b7d54: 0xa02343f9
    ctx->pc = 0x1b7d54u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17401), (uint8_t)GPR_U32(ctx, 3));
label_1b7d58:
    // 0x1b7d58: 0x3c010023
    ctx->pc = 0x1b7d58u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1b7d5c:
    // 0x1b7d5c: 0xa02247f8
    ctx->pc = 0x1b7d5cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 18424), (uint8_t)GPR_U32(ctx, 2));
label_1b7d60:
    // 0x1b7d60: 0x3c010032
    ctx->pc = 0x1b7d60u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
label_1b7d64:
    // 0x1b7d64: 0x942244d0
    ctx->pc = 0x1b7d64u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17616)));
label_1b7d68:
    // 0x1b7d68: 0x1440000c
label_1b7d6c:
    if (ctx->pc == 0x1B7D6Cu) {
        ctx->pc = 0x1B7D6Cu;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 4));
        ctx->pc = 0x1B7D70u;
        goto label_1b7d70;
    }
    ctx->pc = 0x1B7D68u;
    {
        const bool branch_taken_0x1b7d68 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1B7D6Cu;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 4));
        if (branch_taken_0x1b7d68) {
            ctx->pc = 0x1B7D9Cu;
            goto label_1b7d9c;
        }
    }
    ctx->pc = 0x1B7D70u;
label_1b7d70:
    // 0x1b7d70: 0x3c010032
    ctx->pc = 0x1b7d70u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
label_1b7d74:
    // 0x1b7d74: 0x902243c0
    ctx->pc = 0x1b7d74u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17344)));
label_1b7d78:
    // 0x1b7d78: 0x10400005
label_1b7d7c:
    if (ctx->pc == 0x1B7D7Cu) {
        ctx->pc = 0x1B7D7Cu;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x1B7D80u;
        goto label_1b7d80;
    }
    ctx->pc = 0x1B7D78u;
    {
        const bool branch_taken_0x1b7d78 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B7D7Cu;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x1b7d78) {
            ctx->pc = 0x1B7D90u;
            goto label_1b7d90;
        }
    }
    ctx->pc = 0x1B7D80u;
label_1b7d80:
    // 0x1b7d80: 0x3c01004c
    ctx->pc = 0x1b7d80u;
    SET_GPR_U32(ctx, 1, ((uint32_t)76 << 16));
label_1b7d84:
    // 0x1b7d84: 0x9022adec
    ctx->pc = 0x1b7d84u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946284)));
label_1b7d88:
    // 0x1b7d88: 0x14400003
label_1b7d8c:
    if (ctx->pc == 0x1B7D8Cu) {
        ctx->pc = 0x1B7D90u;
        goto label_1b7d90;
    }
    ctx->pc = 0x1B7D88u;
    {
        const bool branch_taken_0x1b7d88 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1b7d88) {
            ctx->pc = 0x1B7D98u;
            goto label_1b7d98;
        }
    }
    ctx->pc = 0x1B7D90u;
label_1b7d90:
    // 0x1b7d90: 0x10000003
label_1b7d94:
    if (ctx->pc == 0x1B7D94u) {
        ctx->pc = 0x1B7D94u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x1B7D98u;
        goto label_1b7d98;
    }
    ctx->pc = 0x1B7D90u;
    {
        const bool branch_taken_0x1b7d90 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B7D94u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1b7d90) {
            ctx->pc = 0x1B7DA0u;
            goto label_1b7da0;
        }
    }
    ctx->pc = 0x1B7D98u;
label_1b7d98:
    // 0x1b7d98: 0x24120004
    ctx->pc = 0x1b7d98u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 4));
label_1b7d9c:
    // 0x1b7d9c: 0x2411000c
    ctx->pc = 0x1b7d9cu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 12));
label_1b7da0:
    // 0x1b7da0: 0xc06e0a0
label_1b7da4:
    if (ctx->pc == 0x1B7DA4u) {
        ctx->pc = 0x1B7DA8u;
        goto label_1b7da8;
    }
    ctx->pc = 0x1B7DA0u;
    SET_GPR_U32(ctx, 31, 0x1B7DA8u);
    ctx->pc = 0x1B8280u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8280_0x1b8280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7DA8u; }
    }
    if (ctx->pc != 0x1B7DA8u) { return; }
    ctx->pc = 0x1B7DA8u;
label_1b7da8:
    // 0x1b7da8: 0x10400003
label_1b7dac:
    if (ctx->pc == 0x1B7DACu) {
        ctx->pc = 0x1B7DACu;
        SET_GPR_U32(ctx, 16, ((uint32_t)49 << 16));
        ctx->pc = 0x1B7DB0u;
        goto label_1b7db0;
    }
    ctx->pc = 0x1B7DA8u;
    {
        const bool branch_taken_0x1b7da8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B7DACu;
        SET_GPR_U32(ctx, 16, ((uint32_t)49 << 16));
        if (branch_taken_0x1b7da8) {
            ctx->pc = 0x1B7DB8u;
            goto label_1b7db8;
        }
    }
    ctx->pc = 0x1B7DB0u;
label_1b7db0:
    // 0x1b7db0: 0x902d
    ctx->pc = 0x1b7db0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b7db4:
    // 0x1b7db4: 0x2411000c
    ctx->pc = 0x1b7db4u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 12));
label_1b7db8:
    // 0x1b7db8: 0x982d
    ctx->pc = 0x1b7db8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b7dbc:
    // 0x1b7dbc: 0x26106350
    ctx->pc = 0x1b7dbcu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 25424));
label_1b7dc0:
    // 0x1b7dc0: 0x272102a
    ctx->pc = 0x1b7dc0u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 19), GPR_S32(ctx, 18)));
label_1b7dc4:
    // 0x1b7dc4: 0x14400003
label_1b7dc8:
    if (ctx->pc == 0x1B7DC8u) {
        ctx->pc = 0x1B7DC8u;
        SET_GPR_U32(ctx, 1, SLT32(GPR_S32(ctx, 17), GPR_S32(ctx, 19)));
        ctx->pc = 0x1B7DCCu;
        goto label_1b7dcc;
    }
    ctx->pc = 0x1B7DC4u;
    {
        const bool branch_taken_0x1b7dc4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1B7DC8u;
        SET_GPR_U32(ctx, 1, SLT32(GPR_S32(ctx, 17), GPR_S32(ctx, 19)));
        if (branch_taken_0x1b7dc4) {
            ctx->pc = 0x1B7DD4u;
            goto label_1b7dd4;
        }
    }
    ctx->pc = 0x1B7DCCu;
label_1b7dcc:
    // 0x1b7dcc: 0x1020002e
label_1b7dd0:
    if (ctx->pc == 0x1B7DD0u) {
        ctx->pc = 0x1B7DD4u;
        goto label_1b7dd4;
    }
    ctx->pc = 0x1B7DCCu;
    {
        const bool branch_taken_0x1b7dcc = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        if (branch_taken_0x1b7dcc) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7DD4u;
label_1b7dd4:
    // 0x1b7dd4: 0x86040000
    ctx->pc = 0x1b7dd4u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_1b7dd8:
    // 0x1b7dd8: 0x24020010
    ctx->pc = 0x1b7dd8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 16));
label_1b7ddc:
    // 0x1b7ddc: 0x1082001e
label_1b7de0:
    if (ctx->pc == 0x1B7DE0u) {
        ctx->pc = 0x1B7DE0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x1B7DE4u;
        goto label_1b7de4;
    }
    ctx->pc = 0x1B7DDCu;
    {
        const bool branch_taken_0x1b7ddc = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x1B7DE0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1b7ddc) {
            ctx->pc = 0x1B7E58u;
            goto label_1b7e58;
        }
    }
    ctx->pc = 0x1B7DE4u;
label_1b7de4:
    // 0x1b7de4: 0x10820018
label_1b7de8:
    if (ctx->pc == 0x1B7DE8u) {
        ctx->pc = 0x1B7DECu;
        goto label_1b7dec;
    }
    ctx->pc = 0x1B7DE4u;
    {
        const bool branch_taken_0x1b7de4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        if (branch_taken_0x1b7de4) {
            ctx->pc = 0x1B7E48u;
            goto label_1b7e48;
        }
    }
    ctx->pc = 0x1B7DECu;
label_1b7dec:
    // 0x1b7dec: 0x24020001
    ctx->pc = 0x1b7decu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_1b7df0:
    // 0x1b7df0: 0x10820025
label_1b7df4:
    if (ctx->pc == 0x1B7DF4u) {
        ctx->pc = 0x1B7DF4u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
        ctx->pc = 0x1B7DF8u;
        goto label_1b7df8;
    }
    ctx->pc = 0x1B7DF0u;
    {
        const bool branch_taken_0x1b7df0 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x1B7DF4u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
        if (branch_taken_0x1b7df0) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7DF8u;
label_1b7df8:
    // 0x1b7df8: 0x1083000e
label_1b7dfc:
    if (ctx->pc == 0x1B7DFCu) {
        ctx->pc = 0x1B7DFCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 12));
        ctx->pc = 0x1B7E00u;
        goto label_1b7e00;
    }
    ctx->pc = 0x1B7DF8u;
    {
        const bool branch_taken_0x1b7df8 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x1B7DFCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x1b7df8) {
            ctx->pc = 0x1B7E34u;
            goto label_1b7e34;
        }
    }
    ctx->pc = 0x1B7E00u;
label_1b7e00:
    // 0x1b7e00: 0x1082000a
label_1b7e04:
    if (ctx->pc == 0x1B7E04u) {
        ctx->pc = 0x1B7E08u;
        goto label_1b7e08;
    }
    ctx->pc = 0x1B7E00u;
    {
        const bool branch_taken_0x1b7e00 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        if (branch_taken_0x1b7e00) {
            ctx->pc = 0x1B7E2Cu;
            goto label_1b7e2c;
        }
    }
    ctx->pc = 0x1B7E08u;
label_1b7e08:
    // 0x1b7e08: 0x24020004
    ctx->pc = 0x1b7e08u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
label_1b7e0c:
    // 0x1b7e0c: 0x10820005
label_1b7e10:
    if (ctx->pc == 0x1B7E10u) {
        ctx->pc = 0x1B7E14u;
        goto label_1b7e14;
    }
    ctx->pc = 0x1B7E0Cu;
    {
        const bool branch_taken_0x1b7e0c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        if (branch_taken_0x1b7e0c) {
            ctx->pc = 0x1B7E24u;
            goto label_1b7e24;
        }
    }
    ctx->pc = 0x1B7E14u;
label_1b7e14:
    // 0x1b7e14: 0x1080001c
label_1b7e18:
    if (ctx->pc == 0x1B7E18u) {
        ctx->pc = 0x1B7E1Cu;
        goto label_1b7e1c;
    }
    ctx->pc = 0x1B7E14u;
    {
        const bool branch_taken_0x1b7e14 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        if (branch_taken_0x1b7e14) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E1Cu;
label_1b7e1c:
    // 0x1b7e1c: 0x1000001b
label_1b7e20:
    if (ctx->pc == 0x1B7E20u) {
        ctx->pc = 0x1B7E20u;
        SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 1));
        ctx->pc = 0x1B7E24u;
        goto label_1b7e24;
    }
    ctx->pc = 0x1B7E1Cu;
    {
        const bool branch_taken_0x1b7e1c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B7E20u;
        SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 1));
        if (branch_taken_0x1b7e1c) {
            ctx->pc = 0x1B7E8Cu;
            goto label_1b7e8c;
        }
    }
    ctx->pc = 0x1B7E24u;
label_1b7e24:
    // 0x1b7e24: 0x10000018
label_1b7e28:
    if (ctx->pc == 0x1B7E28u) {
        ctx->pc = 0x1B7E28u;
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->pc = 0x1B7E2Cu;
        goto label_1b7e2c;
    }
    ctx->pc = 0x1B7E24u;
    {
        const bool branch_taken_0x1b7e24 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B7E28u;
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        if (branch_taken_0x1b7e24) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E2Cu;
label_1b7e2c:
    // 0x1b7e2c: 0x10000016
label_1b7e30:
    if (ctx->pc == 0x1B7E30u) {
        ctx->pc = 0x1B7E30u;
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->pc = 0x1B7E34u;
        goto label_1b7e34;
    }
    ctx->pc = 0x1B7E2Cu;
    {
        const bool branch_taken_0x1b7e2c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B7E30u;
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        if (branch_taken_0x1b7e2c) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E34u;
label_1b7e34:
    // 0x1b7e34: 0x8e020004
    ctx->pc = 0x1b7e34u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_1b7e38:
    // 0x1b7e38: 0x40f809
label_1b7e3c:
    if (ctx->pc == 0x1B7E3Cu) {
        ctx->pc = 0x1B7E3Cu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1B7E40u;
        goto label_1b7e40;
    }
    ctx->pc = 0x1B7E38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1B7E40u);
        ctx->pc = 0x1B7E3Cu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7CB0u: goto label_1b7cb0;
            case 0x1B7CB4u: goto label_1b7cb4;
            case 0x1B7CB8u: goto label_1b7cb8;
            case 0x1B7CBCu: goto label_1b7cbc;
            case 0x1B7CC0u: goto label_1b7cc0;
            case 0x1B7CC4u: goto label_1b7cc4;
            case 0x1B7CC8u: goto label_1b7cc8;
            case 0x1B7CCCu: goto label_1b7ccc;
            case 0x1B7CD0u: goto label_1b7cd0;
            case 0x1B7CD4u: goto label_1b7cd4;
            case 0x1B7CD8u: goto label_1b7cd8;
            case 0x1B7CDCu: goto label_1b7cdc;
            case 0x1B7CE0u: goto label_1b7ce0;
            case 0x1B7CE4u: goto label_1b7ce4;
            case 0x1B7CE8u: goto label_1b7ce8;
            case 0x1B7CECu: goto label_1b7cec;
            case 0x1B7CF0u: goto label_1b7cf0;
            case 0x1B7CF4u: goto label_1b7cf4;
            case 0x1B7CF8u: goto label_1b7cf8;
            case 0x1B7CFCu: goto label_1b7cfc;
            case 0x1B7D00u: goto label_1b7d00;
            case 0x1B7D04u: goto label_1b7d04;
            case 0x1B7D08u: goto label_1b7d08;
            case 0x1B7D0Cu: goto label_1b7d0c;
            case 0x1B7D10u: goto label_1b7d10;
            case 0x1B7D14u: goto label_1b7d14;
            case 0x1B7D18u: goto label_1b7d18;
            case 0x1B7D1Cu: goto label_1b7d1c;
            case 0x1B7D20u: goto label_1b7d20;
            case 0x1B7D24u: goto label_1b7d24;
            case 0x1B7D28u: goto label_1b7d28;
            case 0x1B7D2Cu: goto label_1b7d2c;
            case 0x1B7D30u: goto label_1b7d30;
            case 0x1B7D34u: goto label_1b7d34;
            case 0x1B7D38u: goto label_1b7d38;
            case 0x1B7D3Cu: goto label_1b7d3c;
            case 0x1B7D40u: goto label_1b7d40;
            case 0x1B7D44u: goto label_1b7d44;
            case 0x1B7D48u: goto label_1b7d48;
            case 0x1B7D4Cu: goto label_1b7d4c;
            case 0x1B7D50u: goto label_1b7d50;
            case 0x1B7D54u: goto label_1b7d54;
            case 0x1B7D58u: goto label_1b7d58;
            case 0x1B7D5Cu: goto label_1b7d5c;
            case 0x1B7D60u: goto label_1b7d60;
            case 0x1B7D64u: goto label_1b7d64;
            case 0x1B7D68u: goto label_1b7d68;
            case 0x1B7D6Cu: goto label_1b7d6c;
            case 0x1B7D70u: goto label_1b7d70;
            case 0x1B7D74u: goto label_1b7d74;
            case 0x1B7D78u: goto label_1b7d78;
            case 0x1B7D7Cu: goto label_1b7d7c;
            case 0x1B7D80u: goto label_1b7d80;
            case 0x1B7D84u: goto label_1b7d84;
            case 0x1B7D88u: goto label_1b7d88;
            case 0x1B7D8Cu: goto label_1b7d8c;
            case 0x1B7D90u: goto label_1b7d90;
            case 0x1B7D94u: goto label_1b7d94;
            case 0x1B7D98u: goto label_1b7d98;
            case 0x1B7D9Cu: goto label_1b7d9c;
            case 0x1B7DA0u: goto label_1b7da0;
            case 0x1B7DA4u: goto label_1b7da4;
            case 0x1B7DA8u: goto label_1b7da8;
            case 0x1B7DACu: goto label_1b7dac;
            case 0x1B7DB0u: goto label_1b7db0;
            case 0x1B7DB4u: goto label_1b7db4;
            case 0x1B7DB8u: goto label_1b7db8;
            case 0x1B7DBCu: goto label_1b7dbc;
            case 0x1B7DC0u: goto label_1b7dc0;
            case 0x1B7DC4u: goto label_1b7dc4;
            case 0x1B7DC8u: goto label_1b7dc8;
            case 0x1B7DCCu: goto label_1b7dcc;
            case 0x1B7DD0u: goto label_1b7dd0;
            case 0x1B7DD4u: goto label_1b7dd4;
            case 0x1B7DD8u: goto label_1b7dd8;
            case 0x1B7DDCu: goto label_1b7ddc;
            case 0x1B7DE0u: goto label_1b7de0;
            case 0x1B7DE4u: goto label_1b7de4;
            case 0x1B7DE8u: goto label_1b7de8;
            case 0x1B7DECu: goto label_1b7dec;
            case 0x1B7DF0u: goto label_1b7df0;
            case 0x1B7DF4u: goto label_1b7df4;
            case 0x1B7DF8u: goto label_1b7df8;
            case 0x1B7DFCu: goto label_1b7dfc;
            case 0x1B7E00u: goto label_1b7e00;
            case 0x1B7E04u: goto label_1b7e04;
            case 0x1B7E08u: goto label_1b7e08;
            case 0x1B7E0Cu: goto label_1b7e0c;
            case 0x1B7E10u: goto label_1b7e10;
            case 0x1B7E14u: goto label_1b7e14;
            case 0x1B7E18u: goto label_1b7e18;
            case 0x1B7E1Cu: goto label_1b7e1c;
            case 0x1B7E20u: goto label_1b7e20;
            case 0x1B7E24u: goto label_1b7e24;
            case 0x1B7E28u: goto label_1b7e28;
            case 0x1B7E2Cu: goto label_1b7e2c;
            case 0x1B7E30u: goto label_1b7e30;
            case 0x1B7E34u: goto label_1b7e34;
            case 0x1B7E38u: goto label_1b7e38;
            case 0x1B7E3Cu: goto label_1b7e3c;
            case 0x1B7E40u: goto label_1b7e40;
            case 0x1B7E44u: goto label_1b7e44;
            case 0x1B7E48u: goto label_1b7e48;
            case 0x1B7E4Cu: goto label_1b7e4c;
            case 0x1B7E50u: goto label_1b7e50;
            case 0x1B7E54u: goto label_1b7e54;
            case 0x1B7E58u: goto label_1b7e58;
            case 0x1B7E5Cu: goto label_1b7e5c;
            case 0x1B7E60u: goto label_1b7e60;
            case 0x1B7E64u: goto label_1b7e64;
            case 0x1B7E68u: goto label_1b7e68;
            case 0x1B7E6Cu: goto label_1b7e6c;
            case 0x1B7E70u: goto label_1b7e70;
            case 0x1B7E74u: goto label_1b7e74;
            case 0x1B7E78u: goto label_1b7e78;
            case 0x1B7E7Cu: goto label_1b7e7c;
            case 0x1B7E80u: goto label_1b7e80;
            case 0x1B7E84u: goto label_1b7e84;
            case 0x1B7E88u: goto label_1b7e88;
            case 0x1B7E8Cu: goto label_1b7e8c;
            case 0x1B7E90u: goto label_1b7e90;
            case 0x1B7E94u: goto label_1b7e94;
            case 0x1B7E98u: goto label_1b7e98;
            case 0x1B7E9Cu: goto label_1b7e9c;
            case 0x1B7EA0u: goto label_1b7ea0;
            case 0x1B7EA4u: goto label_1b7ea4;
            case 0x1B7EA8u: goto label_1b7ea8;
            case 0x1B7EACu: goto label_1b7eac;
            case 0x1B7EB0u: goto label_1b7eb0;
            case 0x1B7EB4u: goto label_1b7eb4;
            case 0x1B7EB8u: goto label_1b7eb8;
            case 0x1B7EBCu: goto label_1b7ebc;
            case 0x1B7EC0u: goto label_1b7ec0;
            case 0x1B7EC4u: goto label_1b7ec4;
            case 0x1B7EC8u: goto label_1b7ec8;
            case 0x1B7ECCu: goto label_1b7ecc;
            case 0x1B7ED0u: goto label_1b7ed0;
            case 0x1B7ED4u: goto label_1b7ed4;
            case 0x1B7ED8u: goto label_1b7ed8;
            case 0x1B7EDCu: goto label_1b7edc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1B7E40u; }
            if (ctx->pc != 0x1B7E40u) { return; }
        }
    }
    ctx->pc = 0x1B7E40u;
label_1b7e40:
    // 0x1b7e40: 0x10000011
label_1b7e44:
    if (ctx->pc == 0x1B7E44u) {
        ctx->pc = 0x1B7E48u;
        goto label_1b7e48;
    }
    ctx->pc = 0x1B7E40u;
    {
        const bool branch_taken_0x1b7e40 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1b7e40) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E48u;
label_1b7e48:
    // 0x1b7e48: 0xa6000002
    ctx->pc = 0x1b7e48u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 0));
label_1b7e4c:
    // 0x1b7e4c: 0x24020004
    ctx->pc = 0x1b7e4cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
label_1b7e50:
    // 0x1b7e50: 0x1000000d
label_1b7e54:
    if (ctx->pc == 0x1B7E54u) {
        ctx->pc = 0x1B7E54u;
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x1B7E58u;
        goto label_1b7e58;
    }
    ctx->pc = 0x1B7E50u;
    {
        const bool branch_taken_0x1b7e50 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B7E54u;
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        if (branch_taken_0x1b7e50) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E58u;
label_1b7e58:
    // 0x1b7e58: 0x86020002
    ctx->pc = 0x1b7e58u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_1b7e5c:
    // 0x1b7e5c: 0x2442ffff
    ctx->pc = 0x1b7e5cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
label_1b7e60:
    // 0x1b7e60: 0xa6020002
    ctx->pc = 0x1b7e60u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
label_1b7e64:
    // 0x1b7e64: 0x86020002
    ctx->pc = 0x1b7e64u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_1b7e68:
    // 0x1b7e68: 0x4410003
label_1b7e6c:
    if (ctx->pc == 0x1B7E6Cu) {
        ctx->pc = 0x1B7E70u;
        goto label_1b7e70;
    }
    ctx->pc = 0x1B7E68u;
    {
        const bool branch_taken_0x1b7e68 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x1b7e68) {
            ctx->pc = 0x1B7E78u;
            goto label_1b7e78;
        }
    }
    ctx->pc = 0x1B7E70u;
label_1b7e70:
    // 0x1b7e70: 0x10000005
label_1b7e74:
    if (ctx->pc == 0x1B7E74u) {
        ctx->pc = 0x1B7E74u;
        WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 0));
        ctx->pc = 0x1B7E78u;
        goto label_1b7e78;
    }
    ctx->pc = 0x1B7E70u;
    {
        const bool branch_taken_0x1b7e70 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B7E74u;
        WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 0));
        if (branch_taken_0x1b7e70) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E78u;
label_1b7e78:
    // 0x1b7e78: 0x14400003
label_1b7e7c:
    if (ctx->pc == 0x1B7E7Cu) {
        ctx->pc = 0x1B7E80u;
        goto label_1b7e80;
    }
    ctx->pc = 0x1B7E78u;
    {
        const bool branch_taken_0x1b7e78 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1b7e78) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E80u;
label_1b7e80:
    // 0x1b7e80: 0x24020004
    ctx->pc = 0x1b7e80u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
label_1b7e84:
    // 0x1b7e84: 0xa6020000
    ctx->pc = 0x1b7e84u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
label_1b7e88:
    // 0x1b7e88: 0x26730001
    ctx->pc = 0x1b7e88u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 1));
label_1b7e8c:
    // 0x1b7e8c: 0x2a620010
    ctx->pc = 0x1b7e8cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 19), 16));
label_1b7e90:
    // 0x1b7e90: 0x1440ffcb
label_1b7e94:
    if (ctx->pc == 0x1B7E94u) {
        ctx->pc = 0x1B7E94u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 32));
        ctx->pc = 0x1B7E98u;
        goto label_1b7e98;
    }
    ctx->pc = 0x1B7E90u;
    {
        const bool branch_taken_0x1b7e90 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1B7E94u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 32));
        if (branch_taken_0x1b7e90) {
            ctx->pc = 0x1B7DC0u;
            goto label_1b7dc0;
        }
    }
    ctx->pc = 0x1B7E98u;
label_1b7e98:
    // 0x1b7e98: 0xc06e0a0
label_1b7e9c:
    if (ctx->pc == 0x1B7E9Cu) {
        ctx->pc = 0x1B7EA0u;
        goto label_1b7ea0;
    }
    ctx->pc = 0x1B7E98u;
    SET_GPR_U32(ctx, 31, 0x1B7EA0u);
    ctx->pc = 0x1B8280u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8280_0x1b8280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7EA0u; }
    }
    if (ctx->pc != 0x1B7EA0u) { return; }
    ctx->pc = 0x1B7EA0u;
label_1b7ea0:
    // 0x1b7ea0: 0x14400005
label_1b7ea4:
    if (ctx->pc == 0x1B7EA4u) {
        ctx->pc = 0x1B7EA8u;
        goto label_1b7ea8;
    }
    ctx->pc = 0x1B7EA0u;
    {
        const bool branch_taken_0x1b7ea0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1b7ea0) {
            ctx->pc = 0x1B7EB8u;
            goto label_1b7eb8;
        }
    }
    ctx->pc = 0x1B7EA8u;
label_1b7ea8:
    // 0x1b7ea8: 0xc06bec8
label_1b7eac:
    if (ctx->pc == 0x1B7EACu) {
        ctx->pc = 0x1B7EB0u;
        goto label_1b7eb0;
    }
    ctx->pc = 0x1B7EA8u;
    SET_GPR_U32(ctx, 31, 0x1B7EB0u);
    ctx->pc = 0x1AFB20u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AFB20_0x1afb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7EB0u; }
    }
    if (ctx->pc != 0x1B7EB0u) { return; }
    ctx->pc = 0x1B7EB0u;
label_1b7eb0:
    // 0x1b7eb0: 0xc06efe8
label_1b7eb4:
    if (ctx->pc == 0x1B7EB4u) {
        ctx->pc = 0x1B7EB8u;
        goto label_1b7eb8;
    }
    ctx->pc = 0x1B7EB0u;
    SET_GPR_U32(ctx, 31, 0x1B7EB8u);
    ctx->pc = 0x1BBFA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BBFA0_0x1bbfa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7EB8u; }
    }
    if (ctx->pc != 0x1B7EB8u) { return; }
    ctx->pc = 0x1B7EB8u;
label_1b7eb8:
    // 0x1b7eb8: 0xdfbf0040
    ctx->pc = 0x1b7eb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1b7ebc:
    // 0x1b7ebc: 0x7bb30030
    ctx->pc = 0x1b7ebcu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
label_1b7ec0:
    // 0x1b7ec0: 0x7bb20020
    ctx->pc = 0x1b7ec0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
label_1b7ec4:
    // 0x1b7ec4: 0x7bb10010
    ctx->pc = 0x1b7ec4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_1b7ec8:
    // 0x1b7ec8: 0x7bb00000
    ctx->pc = 0x1b7ec8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_1b7ecc:
    // 0x1b7ecc: 0x3e00008
label_1b7ed0:
    if (ctx->pc == 0x1B7ED0u) {
        ctx->pc = 0x1B7ED0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = 0x1B7ED4u;
        goto label_1b7ed4;
    }
    ctx->pc = 0x1B7ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7ED0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7CB0u: goto label_1b7cb0;
            case 0x1B7CB4u: goto label_1b7cb4;
            case 0x1B7CB8u: goto label_1b7cb8;
            case 0x1B7CBCu: goto label_1b7cbc;
            case 0x1B7CC0u: goto label_1b7cc0;
            case 0x1B7CC4u: goto label_1b7cc4;
            case 0x1B7CC8u: goto label_1b7cc8;
            case 0x1B7CCCu: goto label_1b7ccc;
            case 0x1B7CD0u: goto label_1b7cd0;
            case 0x1B7CD4u: goto label_1b7cd4;
            case 0x1B7CD8u: goto label_1b7cd8;
            case 0x1B7CDCu: goto label_1b7cdc;
            case 0x1B7CE0u: goto label_1b7ce0;
            case 0x1B7CE4u: goto label_1b7ce4;
            case 0x1B7CE8u: goto label_1b7ce8;
            case 0x1B7CECu: goto label_1b7cec;
            case 0x1B7CF0u: goto label_1b7cf0;
            case 0x1B7CF4u: goto label_1b7cf4;
            case 0x1B7CF8u: goto label_1b7cf8;
            case 0x1B7CFCu: goto label_1b7cfc;
            case 0x1B7D00u: goto label_1b7d00;
            case 0x1B7D04u: goto label_1b7d04;
            case 0x1B7D08u: goto label_1b7d08;
            case 0x1B7D0Cu: goto label_1b7d0c;
            case 0x1B7D10u: goto label_1b7d10;
            case 0x1B7D14u: goto label_1b7d14;
            case 0x1B7D18u: goto label_1b7d18;
            case 0x1B7D1Cu: goto label_1b7d1c;
            case 0x1B7D20u: goto label_1b7d20;
            case 0x1B7D24u: goto label_1b7d24;
            case 0x1B7D28u: goto label_1b7d28;
            case 0x1B7D2Cu: goto label_1b7d2c;
            case 0x1B7D30u: goto label_1b7d30;
            case 0x1B7D34u: goto label_1b7d34;
            case 0x1B7D38u: goto label_1b7d38;
            case 0x1B7D3Cu: goto label_1b7d3c;
            case 0x1B7D40u: goto label_1b7d40;
            case 0x1B7D44u: goto label_1b7d44;
            case 0x1B7D48u: goto label_1b7d48;
            case 0x1B7D4Cu: goto label_1b7d4c;
            case 0x1B7D50u: goto label_1b7d50;
            case 0x1B7D54u: goto label_1b7d54;
            case 0x1B7D58u: goto label_1b7d58;
            case 0x1B7D5Cu: goto label_1b7d5c;
            case 0x1B7D60u: goto label_1b7d60;
            case 0x1B7D64u: goto label_1b7d64;
            case 0x1B7D68u: goto label_1b7d68;
            case 0x1B7D6Cu: goto label_1b7d6c;
            case 0x1B7D70u: goto label_1b7d70;
            case 0x1B7D74u: goto label_1b7d74;
            case 0x1B7D78u: goto label_1b7d78;
            case 0x1B7D7Cu: goto label_1b7d7c;
            case 0x1B7D80u: goto label_1b7d80;
            case 0x1B7D84u: goto label_1b7d84;
            case 0x1B7D88u: goto label_1b7d88;
            case 0x1B7D8Cu: goto label_1b7d8c;
            case 0x1B7D90u: goto label_1b7d90;
            case 0x1B7D94u: goto label_1b7d94;
            case 0x1B7D98u: goto label_1b7d98;
            case 0x1B7D9Cu: goto label_1b7d9c;
            case 0x1B7DA0u: goto label_1b7da0;
            case 0x1B7DA4u: goto label_1b7da4;
            case 0x1B7DA8u: goto label_1b7da8;
            case 0x1B7DACu: goto label_1b7dac;
            case 0x1B7DB0u: goto label_1b7db0;
            case 0x1B7DB4u: goto label_1b7db4;
            case 0x1B7DB8u: goto label_1b7db8;
            case 0x1B7DBCu: goto label_1b7dbc;
            case 0x1B7DC0u: goto label_1b7dc0;
            case 0x1B7DC4u: goto label_1b7dc4;
            case 0x1B7DC8u: goto label_1b7dc8;
            case 0x1B7DCCu: goto label_1b7dcc;
            case 0x1B7DD0u: goto label_1b7dd0;
            case 0x1B7DD4u: goto label_1b7dd4;
            case 0x1B7DD8u: goto label_1b7dd8;
            case 0x1B7DDCu: goto label_1b7ddc;
            case 0x1B7DE0u: goto label_1b7de0;
            case 0x1B7DE4u: goto label_1b7de4;
            case 0x1B7DE8u: goto label_1b7de8;
            case 0x1B7DECu: goto label_1b7dec;
            case 0x1B7DF0u: goto label_1b7df0;
            case 0x1B7DF4u: goto label_1b7df4;
            case 0x1B7DF8u: goto label_1b7df8;
            case 0x1B7DFCu: goto label_1b7dfc;
            case 0x1B7E00u: goto label_1b7e00;
            case 0x1B7E04u: goto label_1b7e04;
            case 0x1B7E08u: goto label_1b7e08;
            case 0x1B7E0Cu: goto label_1b7e0c;
            case 0x1B7E10u: goto label_1b7e10;
            case 0x1B7E14u: goto label_1b7e14;
            case 0x1B7E18u: goto label_1b7e18;
            case 0x1B7E1Cu: goto label_1b7e1c;
            case 0x1B7E20u: goto label_1b7e20;
            case 0x1B7E24u: goto label_1b7e24;
            case 0x1B7E28u: goto label_1b7e28;
            case 0x1B7E2Cu: goto label_1b7e2c;
            case 0x1B7E30u: goto label_1b7e30;
            case 0x1B7E34u: goto label_1b7e34;
            case 0x1B7E38u: goto label_1b7e38;
            case 0x1B7E3Cu: goto label_1b7e3c;
            case 0x1B7E40u: goto label_1b7e40;
            case 0x1B7E44u: goto label_1b7e44;
            case 0x1B7E48u: goto label_1b7e48;
            case 0x1B7E4Cu: goto label_1b7e4c;
            case 0x1B7E50u: goto label_1b7e50;
            case 0x1B7E54u: goto label_1b7e54;
            case 0x1B7E58u: goto label_1b7e58;
            case 0x1B7E5Cu: goto label_1b7e5c;
            case 0x1B7E60u: goto label_1b7e60;
            case 0x1B7E64u: goto label_1b7e64;
            case 0x1B7E68u: goto label_1b7e68;
            case 0x1B7E6Cu: goto label_1b7e6c;
            case 0x1B7E70u: goto label_1b7e70;
            case 0x1B7E74u: goto label_1b7e74;
            case 0x1B7E78u: goto label_1b7e78;
            case 0x1B7E7Cu: goto label_1b7e7c;
            case 0x1B7E80u: goto label_1b7e80;
            case 0x1B7E84u: goto label_1b7e84;
            case 0x1B7E88u: goto label_1b7e88;
            case 0x1B7E8Cu: goto label_1b7e8c;
            case 0x1B7E90u: goto label_1b7e90;
            case 0x1B7E94u: goto label_1b7e94;
            case 0x1B7E98u: goto label_1b7e98;
            case 0x1B7E9Cu: goto label_1b7e9c;
            case 0x1B7EA0u: goto label_1b7ea0;
            case 0x1B7EA4u: goto label_1b7ea4;
            case 0x1B7EA8u: goto label_1b7ea8;
            case 0x1B7EACu: goto label_1b7eac;
            case 0x1B7EB0u: goto label_1b7eb0;
            case 0x1B7EB4u: goto label_1b7eb4;
            case 0x1B7EB8u: goto label_1b7eb8;
            case 0x1B7EBCu: goto label_1b7ebc;
            case 0x1B7EC0u: goto label_1b7ec0;
            case 0x1B7EC4u: goto label_1b7ec4;
            case 0x1B7EC8u: goto label_1b7ec8;
            case 0x1B7ECCu: goto label_1b7ecc;
            case 0x1B7ED0u: goto label_1b7ed0;
            case 0x1B7ED4u: goto label_1b7ed4;
            case 0x1B7ED8u: goto label_1b7ed8;
            case 0x1B7EDCu: goto label_1b7edc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7ED4u;
label_1b7ed4:
    // 0x1b7ed4: 0x0
    ctx->pc = 0x1b7ed4u;
    // NOP
label_1b7ed8:
    // 0x1b7ed8: 0x0
    ctx->pc = 0x1b7ed8u;
    // NOP
label_1b7edc:
    // 0x1b7edc: 0x0
    ctx->pc = 0x1b7edcu;
    // NOP
}
