#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00197BB0
// Address: 0x197bb0 - 0x1982d0
void sub_00197BB0_0x197bb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x197bb0u;

label_197bb0:
    // 0x197bb0: 0x27bdffc0
    ctx->pc = 0x197bb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
label_197bb4:
    // 0x197bb4: 0x24020002
    ctx->pc = 0x197bb4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
label_197bb8:
    // 0x197bb8: 0xffbf0030
    ctx->pc = 0x197bb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
label_197bbc:
    // 0x197bbc: 0x7fb20020
    ctx->pc = 0x197bbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
label_197bc0:
    // 0x197bc0: 0x7fb10010
    ctx->pc = 0x197bc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
label_197bc4:
    // 0x197bc4: 0x80902d
    ctx->pc = 0x197bc4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_197bc8:
    // 0x197bc8: 0xa0882d
    ctx->pc = 0x197bc8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_197bcc:
    // 0x197bcc: 0x12220006
label_197bd0:
    if (ctx->pc == 0x197BD0u) {
        ctx->pc = 0x197BD0u;
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->pc = 0x197BD4u;
        goto label_197bd4;
    }
    ctx->pc = 0x197BCCu;
    {
        const bool branch_taken_0x197bcc = (GPR_U32(ctx, 17) == GPR_U32(ctx, 2));
        ctx->pc = 0x197BD0u;
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        if (branch_taken_0x197bcc) {
            ctx->pc = 0x197BE8u;
            goto label_197be8;
        }
    }
    ctx->pc = 0x197BD4u;
label_197bd4:
    // 0x197bd4: 0x24040030
    ctx->pc = 0x197bd4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 48));
label_197bd8:
    // 0x197bd8: 0xc063774
label_197bdc:
    if (ctx->pc == 0x197BDCu) {
        ctx->pc = 0x197BDCu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x197BE0u;
        goto label_197be0;
    }
    ctx->pc = 0x197BD8u;
    SET_GPR_U32(ctx, 31, 0x197BE0u);
    ctx->pc = 0x197BDCu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197BE0u; }
    }
    if (ctx->pc != 0x197BE0u) { return; }
    ctx->pc = 0x197BE0u;
label_197be0:
    // 0x197be0: 0x10000005
label_197be4:
    if (ctx->pc == 0x197BE4u) {
        ctx->pc = 0x197BE4u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x197BE8u;
        goto label_197be8;
    }
    ctx->pc = 0x197BE0u;
    {
        const bool branch_taken_0x197be0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197BE4u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x197be0) {
            ctx->pc = 0x197BF8u;
            goto label_197bf8;
        }
    }
    ctx->pc = 0x197BE8u;
label_197be8:
    // 0x197be8: 0x24040040
    ctx->pc = 0x197be8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 64));
label_197bec:
    // 0x197bec: 0xc063774
label_197bf0:
    if (ctx->pc == 0x197BF0u) {
        ctx->pc = 0x197BF0u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x197BF4u;
        goto label_197bf4;
    }
    ctx->pc = 0x197BECu;
    SET_GPR_U32(ctx, 31, 0x197BF4u);
    ctx->pc = 0x197BF0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197BF4u; }
    }
    if (ctx->pc != 0x197BF4u) { return; }
    ctx->pc = 0x197BF4u;
label_197bf4:
    // 0x197bf4: 0x24070003
    ctx->pc = 0x197bf4u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 3));
label_197bf8:
    // 0x197bf8: 0x3c047000
    ctx->pc = 0x197bf8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)28672 << 16));
label_197bfc:
    // 0x197bfc: 0x3c038000
    ctx->pc = 0x197bfcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)32768 << 16));
label_197c00:
    // 0x197c00: 0xe42021
    ctx->pc = 0x197c00u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
label_197c04:
    // 0x197c04: 0x3c051300
    ctx->pc = 0x197c04u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
label_197c08:
    // 0x197c08: 0x832025
    ctx->pc = 0x197c08u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_197c0c:
    // 0x197c0c: 0x4303c
    ctx->pc = 0x197c0cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 0));
label_197c10:
    // 0x197c10: 0x3c035000
    ctx->pc = 0x197c10u;
    SET_GPR_U32(ctx, 3, ((uint32_t)20480 << 16));
label_197c14:
    // 0x197c14: 0x6303e
    ctx->pc = 0x197c14u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
label_197c18:
    // 0x197c18: 0xe32025
    ctx->pc = 0x197c18u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
label_197c1c:
    // 0x197c1c: 0xfc460000
    ctx->pc = 0x197c1cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
label_197c20:
    // 0x197c20: 0x24e3ffff
    ctx->pc = 0x197c20u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 7), 4294967295));
label_197c24:
    // 0x197c24: 0xac450008
    ctx->pc = 0x197c24u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 5));
label_197c28:
    // 0x197c28: 0x3283c
    ctx->pc = 0x197c28u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
label_197c2c:
    // 0x197c2c: 0xac44000c
    ctx->pc = 0x197c2cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 4));
label_197c30:
    // 0x197c30: 0x3c031000
    ctx->pc = 0x197c30u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_197c34:
    // 0x197c34: 0x5283e
    ctx->pc = 0x197c34u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
label_197c38:
    // 0x197c38: 0x3203c
    ctx->pc = 0x197c38u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
label_197c3c:
    // 0x197c3c: 0x34038000
    ctx->pc = 0x197c3cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 0), 32768));
label_197c40:
    // 0x197c40: 0x642025
    ctx->pc = 0x197c40u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_197c44:
    // 0x197c44: 0xa42025
    ctx->pc = 0x197c44u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
label_197c48:
    // 0x197c48: 0x2403000e
    ctx->pc = 0x197c48u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 14));
label_197c4c:
    // 0x197c4c: 0xfc440010
    ctx->pc = 0x197c4cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 4));
label_197c50:
    // 0x197c50: 0x32450c00
    ctx->pc = 0x197c50u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 18), 3072));
label_197c54:
    // 0x197c54: 0x14a0009d
label_197c58:
    if (ctx->pc == 0x197C58u) {
        ctx->pc = 0x197C58u;
        WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 3));
        ctx->pc = 0x197C5Cu;
        goto label_197c5c;
    }
    ctx->pc = 0x197C54u;
    {
        const bool branch_taken_0x197c54 = (GPR_U32(ctx, 5) != GPR_U32(ctx, 0));
        ctx->pc = 0x197C58u;
        WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 3));
        if (branch_taken_0x197c54) {
            ctx->pc = 0x197ECCu;
            goto label_197ecc;
        }
    }
    ctx->pc = 0x197C5Cu;
label_197c5c:
    // 0x197c5c: 0x3243000f
    ctx->pc = 0x197c5cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 18), 15));
label_197c60:
    // 0x197c60: 0x2c610006
    ctx->pc = 0x197c60u;
    SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 3), 6));
label_197c64:
    // 0x197c64: 0x10200097
label_197c68:
    if (ctx->pc == 0x197C68u) {
        ctx->pc = 0x197C68u;
        SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
        ctx->pc = 0x197C6Cu;
        goto label_197c6c;
    }
    ctx->pc = 0x197C64u;
    {
        const bool branch_taken_0x197c64 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x197C68u;
        SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
        if (branch_taken_0x197c64) {
            ctx->pc = 0x197EC4u;
            goto label_197ec4;
        }
    }
    ctx->pc = 0x197C6Cu;
label_197c6c:
    // 0x197c6c: 0x31880
    ctx->pc = 0x197c6cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
label_197c70:
    // 0x197c70: 0x24841d00
    ctx->pc = 0x197c70u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 7424));
label_197c74:
    // 0x197c74: 0x641821
    ctx->pc = 0x197c74u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_197c78:
    // 0x197c78: 0x8c630000
    ctx->pc = 0x197c78u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_197c7c:
    // 0x197c7c: 0x600008
label_197c80:
    if (ctx->pc == 0x197C80u) {
        ctx->pc = 0x197C84u;
        goto label_197c84;
    }
    ctx->pc = 0x197C7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x197BB0u: goto label_197bb0;
            case 0x197BB4u: goto label_197bb4;
            case 0x197BB8u: goto label_197bb8;
            case 0x197BBCu: goto label_197bbc;
            case 0x197BC0u: goto label_197bc0;
            case 0x197BC4u: goto label_197bc4;
            case 0x197BC8u: goto label_197bc8;
            case 0x197BCCu: goto label_197bcc;
            case 0x197BD0u: goto label_197bd0;
            case 0x197BD4u: goto label_197bd4;
            case 0x197BD8u: goto label_197bd8;
            case 0x197BDCu: goto label_197bdc;
            case 0x197BE0u: goto label_197be0;
            case 0x197BE4u: goto label_197be4;
            case 0x197BE8u: goto label_197be8;
            case 0x197BECu: goto label_197bec;
            case 0x197BF0u: goto label_197bf0;
            case 0x197BF4u: goto label_197bf4;
            case 0x197BF8u: goto label_197bf8;
            case 0x197BFCu: goto label_197bfc;
            case 0x197C00u: goto label_197c00;
            case 0x197C04u: goto label_197c04;
            case 0x197C08u: goto label_197c08;
            case 0x197C0Cu: goto label_197c0c;
            case 0x197C10u: goto label_197c10;
            case 0x197C14u: goto label_197c14;
            case 0x197C18u: goto label_197c18;
            case 0x197C1Cu: goto label_197c1c;
            case 0x197C20u: goto label_197c20;
            case 0x197C24u: goto label_197c24;
            case 0x197C28u: goto label_197c28;
            case 0x197C2Cu: goto label_197c2c;
            case 0x197C30u: goto label_197c30;
            case 0x197C34u: goto label_197c34;
            case 0x197C38u: goto label_197c38;
            case 0x197C3Cu: goto label_197c3c;
            case 0x197C40u: goto label_197c40;
            case 0x197C44u: goto label_197c44;
            case 0x197C48u: goto label_197c48;
            case 0x197C4Cu: goto label_197c4c;
            case 0x197C50u: goto label_197c50;
            case 0x197C54u: goto label_197c54;
            case 0x197C58u: goto label_197c58;
            case 0x197C5Cu: goto label_197c5c;
            case 0x197C60u: goto label_197c60;
            case 0x197C64u: goto label_197c64;
            case 0x197C68u: goto label_197c68;
            case 0x197C6Cu: goto label_197c6c;
            case 0x197C70u: goto label_197c70;
            case 0x197C74u: goto label_197c74;
            case 0x197C78u: goto label_197c78;
            case 0x197C7Cu: goto label_197c7c;
            case 0x197C80u: goto label_197c80;
            case 0x197C84u: goto label_197c84;
            case 0x197C88u: goto label_197c88;
            case 0x197C8Cu: goto label_197c8c;
            case 0x197C90u: goto label_197c90;
            case 0x197C94u: goto label_197c94;
            case 0x197C98u: goto label_197c98;
            case 0x197C9Cu: goto label_197c9c;
            case 0x197CA0u: goto label_197ca0;
            case 0x197CA4u: goto label_197ca4;
            case 0x197CA8u: goto label_197ca8;
            case 0x197CACu: goto label_197cac;
            case 0x197CB0u: goto label_197cb0;
            case 0x197CB4u: goto label_197cb4;
            case 0x197CB8u: goto label_197cb8;
            case 0x197CBCu: goto label_197cbc;
            case 0x197CC0u: goto label_197cc0;
            case 0x197CC4u: goto label_197cc4;
            case 0x197CC8u: goto label_197cc8;
            case 0x197CCCu: goto label_197ccc;
            case 0x197CD0u: goto label_197cd0;
            case 0x197CD4u: goto label_197cd4;
            case 0x197CD8u: goto label_197cd8;
            case 0x197CDCu: goto label_197cdc;
            case 0x197CE0u: goto label_197ce0;
            case 0x197CE4u: goto label_197ce4;
            case 0x197CE8u: goto label_197ce8;
            case 0x197CECu: goto label_197cec;
            case 0x197CF0u: goto label_197cf0;
            case 0x197CF4u: goto label_197cf4;
            case 0x197CF8u: goto label_197cf8;
            case 0x197CFCu: goto label_197cfc;
            case 0x197D00u: goto label_197d00;
            case 0x197D04u: goto label_197d04;
            case 0x197D08u: goto label_197d08;
            case 0x197D0Cu: goto label_197d0c;
            case 0x197D10u: goto label_197d10;
            case 0x197D14u: goto label_197d14;
            case 0x197D18u: goto label_197d18;
            case 0x197D1Cu: goto label_197d1c;
            case 0x197D20u: goto label_197d20;
            case 0x197D24u: goto label_197d24;
            case 0x197D28u: goto label_197d28;
            case 0x197D2Cu: goto label_197d2c;
            case 0x197D30u: goto label_197d30;
            case 0x197D34u: goto label_197d34;
            case 0x197D38u: goto label_197d38;
            case 0x197D3Cu: goto label_197d3c;
            case 0x197D40u: goto label_197d40;
            case 0x197D44u: goto label_197d44;
            case 0x197D48u: goto label_197d48;
            case 0x197D4Cu: goto label_197d4c;
            case 0x197D50u: goto label_197d50;
            case 0x197D54u: goto label_197d54;
            case 0x197D58u: goto label_197d58;
            case 0x197D5Cu: goto label_197d5c;
            case 0x197D60u: goto label_197d60;
            case 0x197D64u: goto label_197d64;
            case 0x197D68u: goto label_197d68;
            case 0x197D6Cu: goto label_197d6c;
            case 0x197D70u: goto label_197d70;
            case 0x197D74u: goto label_197d74;
            case 0x197D78u: goto label_197d78;
            case 0x197D7Cu: goto label_197d7c;
            case 0x197D80u: goto label_197d80;
            case 0x197D84u: goto label_197d84;
            case 0x197D88u: goto label_197d88;
            case 0x197D8Cu: goto label_197d8c;
            case 0x197D90u: goto label_197d90;
            case 0x197D94u: goto label_197d94;
            case 0x197D98u: goto label_197d98;
            case 0x197D9Cu: goto label_197d9c;
            case 0x197DA0u: goto label_197da0;
            case 0x197DA4u: goto label_197da4;
            case 0x197DA8u: goto label_197da8;
            case 0x197DACu: goto label_197dac;
            case 0x197DB0u: goto label_197db0;
            case 0x197DB4u: goto label_197db4;
            case 0x197DB8u: goto label_197db8;
            case 0x197DBCu: goto label_197dbc;
            case 0x197DC0u: goto label_197dc0;
            case 0x197DC4u: goto label_197dc4;
            case 0x197DC8u: goto label_197dc8;
            case 0x197DCCu: goto label_197dcc;
            case 0x197DD0u: goto label_197dd0;
            case 0x197DD4u: goto label_197dd4;
            case 0x197DD8u: goto label_197dd8;
            case 0x197DDCu: goto label_197ddc;
            case 0x197DE0u: goto label_197de0;
            case 0x197DE4u: goto label_197de4;
            case 0x197DE8u: goto label_197de8;
            case 0x197DECu: goto label_197dec;
            case 0x197DF0u: goto label_197df0;
            case 0x197DF4u: goto label_197df4;
            case 0x197DF8u: goto label_197df8;
            case 0x197DFCu: goto label_197dfc;
            case 0x197E00u: goto label_197e00;
            case 0x197E04u: goto label_197e04;
            case 0x197E08u: goto label_197e08;
            case 0x197E0Cu: goto label_197e0c;
            case 0x197E10u: goto label_197e10;
            case 0x197E14u: goto label_197e14;
            case 0x197E18u: goto label_197e18;
            case 0x197E1Cu: goto label_197e1c;
            case 0x197E20u: goto label_197e20;
            case 0x197E24u: goto label_197e24;
            case 0x197E28u: goto label_197e28;
            case 0x197E2Cu: goto label_197e2c;
            case 0x197E30u: goto label_197e30;
            case 0x197E34u: goto label_197e34;
            case 0x197E38u: goto label_197e38;
            case 0x197E3Cu: goto label_197e3c;
            case 0x197E40u: goto label_197e40;
            case 0x197E44u: goto label_197e44;
            case 0x197E48u: goto label_197e48;
            case 0x197E4Cu: goto label_197e4c;
            case 0x197E50u: goto label_197e50;
            case 0x197E54u: goto label_197e54;
            case 0x197E58u: goto label_197e58;
            case 0x197E5Cu: goto label_197e5c;
            case 0x197E60u: goto label_197e60;
            case 0x197E64u: goto label_197e64;
            case 0x197E68u: goto label_197e68;
            case 0x197E6Cu: goto label_197e6c;
            case 0x197E70u: goto label_197e70;
            case 0x197E74u: goto label_197e74;
            case 0x197E78u: goto label_197e78;
            case 0x197E7Cu: goto label_197e7c;
            case 0x197E80u: goto label_197e80;
            case 0x197E84u: goto label_197e84;
            case 0x197E88u: goto label_197e88;
            case 0x197E8Cu: goto label_197e8c;
            case 0x197E90u: goto label_197e90;
            case 0x197E94u: goto label_197e94;
            case 0x197E98u: goto label_197e98;
            case 0x197E9Cu: goto label_197e9c;
            case 0x197EA0u: goto label_197ea0;
            case 0x197EA4u: goto label_197ea4;
            case 0x197EA8u: goto label_197ea8;
            case 0x197EACu: goto label_197eac;
            case 0x197EB0u: goto label_197eb0;
            case 0x197EB4u: goto label_197eb4;
            case 0x197EB8u: goto label_197eb8;
            case 0x197EBCu: goto label_197ebc;
            case 0x197EC0u: goto label_197ec0;
            case 0x197EC4u: goto label_197ec4;
            case 0x197EC8u: goto label_197ec8;
            case 0x197ECCu: goto label_197ecc;
            case 0x197ED0u: goto label_197ed0;
            case 0x197ED4u: goto label_197ed4;
            case 0x197ED8u: goto label_197ed8;
            case 0x197EDCu: goto label_197edc;
            case 0x197EE0u: goto label_197ee0;
            case 0x197EE4u: goto label_197ee4;
            case 0x197EE8u: goto label_197ee8;
            case 0x197EECu: goto label_197eec;
            case 0x197EF0u: goto label_197ef0;
            case 0x197EF4u: goto label_197ef4;
            case 0x197EF8u: goto label_197ef8;
            case 0x197EFCu: goto label_197efc;
            case 0x197F00u: goto label_197f00;
            case 0x197F04u: goto label_197f04;
            case 0x197F08u: goto label_197f08;
            case 0x197F0Cu: goto label_197f0c;
            case 0x197F10u: goto label_197f10;
            case 0x197F14u: goto label_197f14;
            case 0x197F18u: goto label_197f18;
            case 0x197F1Cu: goto label_197f1c;
            case 0x197F20u: goto label_197f20;
            case 0x197F24u: goto label_197f24;
            case 0x197F28u: goto label_197f28;
            case 0x197F2Cu: goto label_197f2c;
            case 0x197F30u: goto label_197f30;
            case 0x197F34u: goto label_197f34;
            case 0x197F38u: goto label_197f38;
            case 0x197F3Cu: goto label_197f3c;
            case 0x197F40u: goto label_197f40;
            case 0x197F44u: goto label_197f44;
            case 0x197F48u: goto label_197f48;
            case 0x197F4Cu: goto label_197f4c;
            case 0x197F50u: goto label_197f50;
            case 0x197F54u: goto label_197f54;
            case 0x197F58u: goto label_197f58;
            case 0x197F5Cu: goto label_197f5c;
            case 0x197F60u: goto label_197f60;
            case 0x197F64u: goto label_197f64;
            case 0x197F68u: goto label_197f68;
            case 0x197F6Cu: goto label_197f6c;
            case 0x197F70u: goto label_197f70;
            case 0x197F74u: goto label_197f74;
            case 0x197F78u: goto label_197f78;
            case 0x197F7Cu: goto label_197f7c;
            case 0x197F80u: goto label_197f80;
            case 0x197F84u: goto label_197f84;
            case 0x197F88u: goto label_197f88;
            case 0x197F8Cu: goto label_197f8c;
            case 0x197F90u: goto label_197f90;
            case 0x197F94u: goto label_197f94;
            case 0x197F98u: goto label_197f98;
            case 0x197F9Cu: goto label_197f9c;
            case 0x197FA0u: goto label_197fa0;
            case 0x197FA4u: goto label_197fa4;
            case 0x197FA8u: goto label_197fa8;
            case 0x197FACu: goto label_197fac;
            case 0x197FB0u: goto label_197fb0;
            case 0x197FB4u: goto label_197fb4;
            case 0x197FB8u: goto label_197fb8;
            case 0x197FBCu: goto label_197fbc;
            case 0x197FC0u: goto label_197fc0;
            case 0x197FC4u: goto label_197fc4;
            case 0x197FC8u: goto label_197fc8;
            case 0x197FCCu: goto label_197fcc;
            case 0x197FD0u: goto label_197fd0;
            case 0x197FD4u: goto label_197fd4;
            case 0x197FD8u: goto label_197fd8;
            case 0x197FDCu: goto label_197fdc;
            case 0x197FE0u: goto label_197fe0;
            case 0x197FE4u: goto label_197fe4;
            case 0x197FE8u: goto label_197fe8;
            case 0x197FECu: goto label_197fec;
            case 0x197FF0u: goto label_197ff0;
            case 0x197FF4u: goto label_197ff4;
            case 0x197FF8u: goto label_197ff8;
            case 0x197FFCu: goto label_197ffc;
            case 0x198000u: goto label_198000;
            case 0x198004u: goto label_198004;
            case 0x198008u: goto label_198008;
            case 0x19800Cu: goto label_19800c;
            case 0x198010u: goto label_198010;
            case 0x198014u: goto label_198014;
            case 0x198018u: goto label_198018;
            case 0x19801Cu: goto label_19801c;
            case 0x198020u: goto label_198020;
            case 0x198024u: goto label_198024;
            case 0x198028u: goto label_198028;
            case 0x19802Cu: goto label_19802c;
            case 0x198030u: goto label_198030;
            case 0x198034u: goto label_198034;
            case 0x198038u: goto label_198038;
            case 0x19803Cu: goto label_19803c;
            case 0x198040u: goto label_198040;
            case 0x198044u: goto label_198044;
            case 0x198048u: goto label_198048;
            case 0x19804Cu: goto label_19804c;
            case 0x198050u: goto label_198050;
            case 0x198054u: goto label_198054;
            case 0x198058u: goto label_198058;
            case 0x19805Cu: goto label_19805c;
            case 0x198060u: goto label_198060;
            case 0x198064u: goto label_198064;
            case 0x198068u: goto label_198068;
            case 0x19806Cu: goto label_19806c;
            case 0x198070u: goto label_198070;
            case 0x198074u: goto label_198074;
            case 0x198078u: goto label_198078;
            case 0x19807Cu: goto label_19807c;
            case 0x198080u: goto label_198080;
            case 0x198084u: goto label_198084;
            case 0x198088u: goto label_198088;
            case 0x19808Cu: goto label_19808c;
            case 0x198090u: goto label_198090;
            case 0x198094u: goto label_198094;
            case 0x198098u: goto label_198098;
            case 0x19809Cu: goto label_19809c;
            case 0x1980A0u: goto label_1980a0;
            case 0x1980A4u: goto label_1980a4;
            case 0x1980A8u: goto label_1980a8;
            case 0x1980ACu: goto label_1980ac;
            case 0x1980B0u: goto label_1980b0;
            case 0x1980B4u: goto label_1980b4;
            case 0x1980B8u: goto label_1980b8;
            case 0x1980BCu: goto label_1980bc;
            case 0x1980C0u: goto label_1980c0;
            case 0x1980C4u: goto label_1980c4;
            case 0x1980C8u: goto label_1980c8;
            case 0x1980CCu: goto label_1980cc;
            case 0x1980D0u: goto label_1980d0;
            case 0x1980D4u: goto label_1980d4;
            case 0x1980D8u: goto label_1980d8;
            case 0x1980DCu: goto label_1980dc;
            case 0x1980E0u: goto label_1980e0;
            case 0x1980E4u: goto label_1980e4;
            case 0x1980E8u: goto label_1980e8;
            case 0x1980ECu: goto label_1980ec;
            case 0x1980F0u: goto label_1980f0;
            case 0x1980F4u: goto label_1980f4;
            case 0x1980F8u: goto label_1980f8;
            case 0x1980FCu: goto label_1980fc;
            case 0x198100u: goto label_198100;
            case 0x198104u: goto label_198104;
            case 0x198108u: goto label_198108;
            case 0x19810Cu: goto label_19810c;
            case 0x198110u: goto label_198110;
            case 0x198114u: goto label_198114;
            case 0x198118u: goto label_198118;
            case 0x19811Cu: goto label_19811c;
            case 0x198120u: goto label_198120;
            case 0x198124u: goto label_198124;
            case 0x198128u: goto label_198128;
            case 0x19812Cu: goto label_19812c;
            case 0x198130u: goto label_198130;
            case 0x198134u: goto label_198134;
            case 0x198138u: goto label_198138;
            case 0x19813Cu: goto label_19813c;
            case 0x198140u: goto label_198140;
            case 0x198144u: goto label_198144;
            case 0x198148u: goto label_198148;
            case 0x19814Cu: goto label_19814c;
            case 0x198150u: goto label_198150;
            case 0x198154u: goto label_198154;
            case 0x198158u: goto label_198158;
            case 0x19815Cu: goto label_19815c;
            case 0x198160u: goto label_198160;
            case 0x198164u: goto label_198164;
            case 0x198168u: goto label_198168;
            case 0x19816Cu: goto label_19816c;
            case 0x198170u: goto label_198170;
            case 0x198174u: goto label_198174;
            case 0x198178u: goto label_198178;
            case 0x19817Cu: goto label_19817c;
            case 0x198180u: goto label_198180;
            case 0x198184u: goto label_198184;
            case 0x198188u: goto label_198188;
            case 0x19818Cu: goto label_19818c;
            case 0x198190u: goto label_198190;
            case 0x198194u: goto label_198194;
            case 0x198198u: goto label_198198;
            case 0x19819Cu: goto label_19819c;
            case 0x1981A0u: goto label_1981a0;
            case 0x1981A4u: goto label_1981a4;
            case 0x1981A8u: goto label_1981a8;
            case 0x1981ACu: goto label_1981ac;
            case 0x1981B0u: goto label_1981b0;
            case 0x1981B4u: goto label_1981b4;
            case 0x1981B8u: goto label_1981b8;
            case 0x1981BCu: goto label_1981bc;
            case 0x1981C0u: goto label_1981c0;
            case 0x1981C4u: goto label_1981c4;
            case 0x1981C8u: goto label_1981c8;
            case 0x1981CCu: goto label_1981cc;
            case 0x1981D0u: goto label_1981d0;
            case 0x1981D4u: goto label_1981d4;
            case 0x1981D8u: goto label_1981d8;
            case 0x1981DCu: goto label_1981dc;
            case 0x1981E0u: goto label_1981e0;
            case 0x1981E4u: goto label_1981e4;
            case 0x1981E8u: goto label_1981e8;
            case 0x1981ECu: goto label_1981ec;
            case 0x1981F0u: goto label_1981f0;
            case 0x1981F4u: goto label_1981f4;
            case 0x1981F8u: goto label_1981f8;
            case 0x1981FCu: goto label_1981fc;
            case 0x198200u: goto label_198200;
            case 0x198204u: goto label_198204;
            case 0x198208u: goto label_198208;
            case 0x19820Cu: goto label_19820c;
            case 0x198210u: goto label_198210;
            case 0x198214u: goto label_198214;
            case 0x198218u: goto label_198218;
            case 0x19821Cu: goto label_19821c;
            case 0x198220u: goto label_198220;
            case 0x198224u: goto label_198224;
            case 0x198228u: goto label_198228;
            case 0x19822Cu: goto label_19822c;
            case 0x198230u: goto label_198230;
            case 0x198234u: goto label_198234;
            case 0x198238u: goto label_198238;
            case 0x19823Cu: goto label_19823c;
            case 0x198240u: goto label_198240;
            case 0x198244u: goto label_198244;
            case 0x198248u: goto label_198248;
            case 0x19824Cu: goto label_19824c;
            case 0x198250u: goto label_198250;
            case 0x198254u: goto label_198254;
            case 0x198258u: goto label_198258;
            case 0x19825Cu: goto label_19825c;
            case 0x198260u: goto label_198260;
            case 0x198264u: goto label_198264;
            case 0x198268u: goto label_198268;
            case 0x19826Cu: goto label_19826c;
            case 0x198270u: goto label_198270;
            case 0x198274u: goto label_198274;
            case 0x198278u: goto label_198278;
            case 0x19827Cu: goto label_19827c;
            case 0x198280u: goto label_198280;
            case 0x198284u: goto label_198284;
            case 0x198288u: goto label_198288;
            case 0x19828Cu: goto label_19828c;
            case 0x198290u: goto label_198290;
            case 0x198294u: goto label_198294;
            case 0x198298u: goto label_198298;
            case 0x19829Cu: goto label_19829c;
            case 0x1982A0u: goto label_1982a0;
            case 0x1982A4u: goto label_1982a4;
            case 0x1982A8u: goto label_1982a8;
            case 0x1982ACu: goto label_1982ac;
            case 0x1982B0u: goto label_1982b0;
            case 0x1982B4u: goto label_1982b4;
            case 0x1982B8u: goto label_1982b8;
            case 0x1982BCu: goto label_1982bc;
            case 0x1982C0u: goto label_1982c0;
            case 0x1982C4u: goto label_1982c4;
            case 0x1982C8u: goto label_1982c8;
            case 0x1982CCu: goto label_1982cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x197C84u;
label_197c84:
    // 0x197c84: 0x324400f0
    ctx->pc = 0x197c84u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_197c88:
    // 0x197c88: 0x24030050
    ctx->pc = 0x197c88u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 80));
label_197c8c:
    // 0x197c8c: 0x10830020
label_197c90:
    if (ctx->pc == 0x197C90u) {
        ctx->pc = 0x197C90u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 22));
        ctx->pc = 0x197C94u;
        goto label_197c94;
    }
    ctx->pc = 0x197C8Cu;
    {
        const bool branch_taken_0x197c8c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197C90u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 22));
        if (branch_taken_0x197c8c) {
            ctx->pc = 0x197D10u;
            goto label_197d10;
        }
    }
    ctx->pc = 0x197C94u;
label_197c94:
    // 0x197c94: 0x24030040
    ctx->pc = 0x197c94u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
label_197c98:
    // 0x197c98: 0x1083001b
label_197c9c:
    if (ctx->pc == 0x197C9Cu) {
        ctx->pc = 0x197C9Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 25));
        ctx->pc = 0x197CA0u;
        goto label_197ca0;
    }
    ctx->pc = 0x197C98u;
    {
        const bool branch_taken_0x197c98 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197C9Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 25));
        if (branch_taken_0x197c98) {
            ctx->pc = 0x197D08u;
            goto label_197d08;
        }
    }
    ctx->pc = 0x197CA0u;
label_197ca0:
    // 0x197ca0: 0x24030030
    ctx->pc = 0x197ca0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 48));
label_197ca4:
    // 0x197ca4: 0x10830016
label_197ca8:
    if (ctx->pc == 0x197CA8u) {
        ctx->pc = 0x197CA8u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 6));
        ctx->pc = 0x197CACu;
        goto label_197cac;
    }
    ctx->pc = 0x197CA4u;
    {
        const bool branch_taken_0x197ca4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197CA8u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 6));
        if (branch_taken_0x197ca4) {
            ctx->pc = 0x197D00u;
            goto label_197d00;
        }
    }
    ctx->pc = 0x197CACu;
label_197cac:
    // 0x197cac: 0x24030020
    ctx->pc = 0x197cacu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
label_197cb0:
    // 0x197cb0: 0x10830011
label_197cb4:
    if (ctx->pc == 0x197CB4u) {
        ctx->pc = 0x197CB4u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 9));
        ctx->pc = 0x197CB8u;
        goto label_197cb8;
    }
    ctx->pc = 0x197CB0u;
    {
        const bool branch_taken_0x197cb0 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197CB4u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 9));
        if (branch_taken_0x197cb0) {
            ctx->pc = 0x197CF8u;
            goto label_197cf8;
        }
    }
    ctx->pc = 0x197CB8u;
label_197cb8:
    // 0x197cb8: 0x1080000a
label_197cbc:
    if (ctx->pc == 0x197CBCu) {
        ctx->pc = 0x197CBCu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x197CC0u;
        goto label_197cc0;
    }
    ctx->pc = 0x197CB8u;
    {
        const bool branch_taken_0x197cb8 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x197CBCu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x197cb8) {
            ctx->pc = 0x197CE4u;
            goto label_197ce4;
        }
    }
    ctx->pc = 0x197CC0u;
label_197cc0:
    // 0x197cc0: 0x10830003
label_197cc4:
    if (ctx->pc == 0x197CC4u) {
        ctx->pc = 0x197CC8u;
        goto label_197cc8;
    }
    ctx->pc = 0x197CC0u;
    {
        const bool branch_taken_0x197cc0 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x197cc0) {
            ctx->pc = 0x197CD0u;
            goto label_197cd0;
        }
    }
    ctx->pc = 0x197CC8u;
label_197cc8:
    // 0x197cc8: 0x10000013
label_197ccc:
    if (ctx->pc == 0x197CCCu) {
        ctx->pc = 0x197CCCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197CD0u;
        goto label_197cd0;
    }
    ctx->pc = 0x197CC8u;
    {
        const bool branch_taken_0x197cc8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197CCCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197cc8) {
            ctx->pc = 0x197D18u;
            goto label_197d18;
        }
    }
    ctx->pc = 0x197CD0u;
label_197cd0:
    // 0x197cd0: 0x24040080
    ctx->pc = 0x197cd0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_197cd4:
    // 0x197cd4: 0x24030068
    ctx->pc = 0x197cd4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 104));
label_197cd8:
    // 0x197cd8: 0x4203c
    ctx->pc = 0x197cd8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_197cdc:
    // 0x197cdc: 0x1000014d
label_197ce0:
    if (ctx->pc == 0x197CE0u) {
        ctx->pc = 0x197CE0u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x197CE4u;
        goto label_197ce4;
    }
    ctx->pc = 0x197CDCu;
    {
        const bool branch_taken_0x197cdc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197CE0u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x197cdc) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197CE4u;
label_197ce4:
    // 0x197ce4: 0x24040080
    ctx->pc = 0x197ce4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_197ce8:
    // 0x197ce8: 0x240300a8
    ctx->pc = 0x197ce8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 168));
label_197cec:
    // 0x197cec: 0x4203c
    ctx->pc = 0x197cecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_197cf0:
    // 0x197cf0: 0x10000148
label_197cf4:
    if (ctx->pc == 0x197CF4u) {
        ctx->pc = 0x197CF4u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x197CF8u;
        goto label_197cf8;
    }
    ctx->pc = 0x197CF0u;
    {
        const bool branch_taken_0x197cf0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197CF4u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x197cf0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197CF8u;
label_197cf8:
    // 0x197cf8: 0x10000147
label_197cfc:
    if (ctx->pc == 0x197CFCu) {
        ctx->pc = 0x197CFCu;
        SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
        ctx->pc = 0x197D00u;
        goto label_197d00;
    }
    ctx->pc = 0x197CF8u;
    {
        const bool branch_taken_0x197cf8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197CFCu;
        SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
        if (branch_taken_0x197cf8) {
            ctx->pc = 0x198218u;
            goto label_198218;
        }
    }
    ctx->pc = 0x197D00u;
label_197d00:
    // 0x197d00: 0x10000144
label_197d04:
    if (ctx->pc == 0x197D04u) {
        ctx->pc = 0x197D08u;
        goto label_197d08;
    }
    ctx->pc = 0x197D00u;
    {
        const bool branch_taken_0x197d00 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197d00) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D08u;
label_197d08:
    // 0x197d08: 0x10000142
label_197d0c:
    if (ctx->pc == 0x197D0Cu) {
        ctx->pc = 0x197D10u;
        goto label_197d10;
    }
    ctx->pc = 0x197D08u;
    {
        const bool branch_taken_0x197d08 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197d08) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D10u;
label_197d10:
    // 0x197d10: 0x10000140
label_197d14:
    if (ctx->pc == 0x197D14u) {
        ctx->pc = 0x197D18u;
        goto label_197d18;
    }
    ctx->pc = 0x197D10u;
    {
        const bool branch_taken_0x197d10 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197d10) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D18u;
label_197d18:
    // 0x197d18: 0x10000166
label_197d1c:
    if (ctx->pc == 0x197D1Cu) {
        ctx->pc = 0x197D1Cu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->pc = 0x197D20u;
        goto label_197d20;
    }
    ctx->pc = 0x197D18u;
    {
        const bool branch_taken_0x197d18 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197D1Cu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x197d18) {
            ctx->pc = 0x1982B4u;
            goto label_1982b4;
        }
    }
    ctx->pc = 0x197D20u;
label_197d20:
    // 0x197d20: 0x324400f0
    ctx->pc = 0x197d20u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_197d24:
    // 0x197d24: 0x24030050
    ctx->pc = 0x197d24u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 80));
label_197d28:
    // 0x197d28: 0x10830020
label_197d2c:
    if (ctx->pc == 0x197D2Cu) {
        ctx->pc = 0x197D2Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 86));
        ctx->pc = 0x197D30u;
        goto label_197d30;
    }
    ctx->pc = 0x197D28u;
    {
        const bool branch_taken_0x197d28 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197D2Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 86));
        if (branch_taken_0x197d28) {
            ctx->pc = 0x197DACu;
            goto label_197dac;
        }
    }
    ctx->pc = 0x197D30u;
label_197d30:
    // 0x197d30: 0x24030040
    ctx->pc = 0x197d30u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
label_197d34:
    // 0x197d34: 0x1083001b
label_197d38:
    if (ctx->pc == 0x197D38u) {
        ctx->pc = 0x197D38u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 153));
        ctx->pc = 0x197D3Cu;
        goto label_197d3c;
    }
    ctx->pc = 0x197D34u;
    {
        const bool branch_taken_0x197d34 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197D38u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 153));
        if (branch_taken_0x197d34) {
            ctx->pc = 0x197DA4u;
            goto label_197da4;
        }
    }
    ctx->pc = 0x197D3Cu;
label_197d3c:
    // 0x197d3c: 0x24030030
    ctx->pc = 0x197d3cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 48));
label_197d40:
    // 0x197d40: 0x10830016
label_197d44:
    if (ctx->pc == 0x197D44u) {
        ctx->pc = 0x197D44u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 70));
        ctx->pc = 0x197D48u;
        goto label_197d48;
    }
    ctx->pc = 0x197D40u;
    {
        const bool branch_taken_0x197d40 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197D44u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 70));
        if (branch_taken_0x197d40) {
            ctx->pc = 0x197D9Cu;
            goto label_197d9c;
        }
    }
    ctx->pc = 0x197D48u;
label_197d48:
    // 0x197d48: 0x24030020
    ctx->pc = 0x197d48u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
label_197d4c:
    // 0x197d4c: 0x10830011
label_197d50:
    if (ctx->pc == 0x197D50u) {
        ctx->pc = 0x197D50u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 137));
        ctx->pc = 0x197D54u;
        goto label_197d54;
    }
    ctx->pc = 0x197D4Cu;
    {
        const bool branch_taken_0x197d4c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197D50u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 137));
        if (branch_taken_0x197d4c) {
            ctx->pc = 0x197D94u;
            goto label_197d94;
        }
    }
    ctx->pc = 0x197D54u;
label_197d54:
    // 0x197d54: 0x1080000a
label_197d58:
    if (ctx->pc == 0x197D58u) {
        ctx->pc = 0x197D58u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x197D5Cu;
        goto label_197d5c;
    }
    ctx->pc = 0x197D54u;
    {
        const bool branch_taken_0x197d54 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x197D58u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x197d54) {
            ctx->pc = 0x197D80u;
            goto label_197d80;
        }
    }
    ctx->pc = 0x197D5Cu;
label_197d5c:
    // 0x197d5c: 0x10830003
label_197d60:
    if (ctx->pc == 0x197D60u) {
        ctx->pc = 0x197D64u;
        goto label_197d64;
    }
    ctx->pc = 0x197D5Cu;
    {
        const bool branch_taken_0x197d5c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x197d5c) {
            ctx->pc = 0x197D6Cu;
            goto label_197d6c;
        }
    }
    ctx->pc = 0x197D64u;
label_197d64:
    // 0x197d64: 0x10000013
label_197d68:
    if (ctx->pc == 0x197D68u) {
        ctx->pc = 0x197D68u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197D6Cu;
        goto label_197d6c;
    }
    ctx->pc = 0x197D64u;
    {
        const bool branch_taken_0x197d64 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197D68u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197d64) {
            ctx->pc = 0x197DB4u;
            goto label_197db4;
        }
    }
    ctx->pc = 0x197D6Cu;
label_197d6c:
    // 0x197d6c: 0x24040080
    ctx->pc = 0x197d6cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_197d70:
    // 0x197d70: 0x2403006a
    ctx->pc = 0x197d70u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 106));
label_197d74:
    // 0x197d74: 0x4203c
    ctx->pc = 0x197d74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_197d78:
    // 0x197d78: 0x10000126
label_197d7c:
    if (ctx->pc == 0x197D7Cu) {
        ctx->pc = 0x197D7Cu;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x197D80u;
        goto label_197d80;
    }
    ctx->pc = 0x197D78u;
    {
        const bool branch_taken_0x197d78 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197D7Cu;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x197d78) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D80u;
label_197d80:
    // 0x197d80: 0x24040080
    ctx->pc = 0x197d80u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_197d84:
    // 0x197d84: 0x240300aa
    ctx->pc = 0x197d84u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 170));
label_197d88:
    // 0x197d88: 0x4203c
    ctx->pc = 0x197d88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_197d8c:
    // 0x197d8c: 0x10000121
label_197d90:
    if (ctx->pc == 0x197D90u) {
        ctx->pc = 0x197D90u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x197D94u;
        goto label_197d94;
    }
    ctx->pc = 0x197D8Cu;
    {
        const bool branch_taken_0x197d8c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197D90u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x197d8c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D94u;
label_197d94:
    // 0x197d94: 0x1000011f
label_197d98:
    if (ctx->pc == 0x197D98u) {
        ctx->pc = 0x197D9Cu;
        goto label_197d9c;
    }
    ctx->pc = 0x197D94u;
    {
        const bool branch_taken_0x197d94 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197d94) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D9Cu;
label_197d9c:
    // 0x197d9c: 0x1000011d
label_197da0:
    if (ctx->pc == 0x197DA0u) {
        ctx->pc = 0x197DA4u;
        goto label_197da4;
    }
    ctx->pc = 0x197D9Cu;
    {
        const bool branch_taken_0x197d9c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197d9c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DA4u;
label_197da4:
    // 0x197da4: 0x1000011b
label_197da8:
    if (ctx->pc == 0x197DA8u) {
        ctx->pc = 0x197DACu;
        goto label_197dac;
    }
    ctx->pc = 0x197DA4u;
    {
        const bool branch_taken_0x197da4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197da4) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DACu;
label_197dac:
    // 0x197dac: 0x10000119
label_197db0:
    if (ctx->pc == 0x197DB0u) {
        ctx->pc = 0x197DB4u;
        goto label_197db4;
    }
    ctx->pc = 0x197DACu;
    {
        const bool branch_taken_0x197dac = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197dac) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DB4u;
label_197db4:
    // 0x197db4: 0x1000013e
label_197db8:
    if (ctx->pc == 0x197DB8u) {
        ctx->pc = 0x197DBCu;
        goto label_197dbc;
    }
    ctx->pc = 0x197DB4u;
    {
        const bool branch_taken_0x197db4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197db4) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197DBCu;
label_197dbc:
    // 0x197dbc: 0x324400f0
    ctx->pc = 0x197dbcu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_197dc0:
    // 0x197dc0: 0x24030030
    ctx->pc = 0x197dc0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 48));
label_197dc4:
    // 0x197dc4: 0x1083000c
label_197dc8:
    if (ctx->pc == 0x197DC8u) {
        ctx->pc = 0x197DC8u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 68));
        ctx->pc = 0x197DCCu;
        goto label_197dcc;
    }
    ctx->pc = 0x197DC4u;
    {
        const bool branch_taken_0x197dc4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197DC8u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 68));
        if (branch_taken_0x197dc4) {
            ctx->pc = 0x197DF8u;
            goto label_197df8;
        }
    }
    ctx->pc = 0x197DCCu;
label_197dcc:
    // 0x197dcc: 0x10800008
label_197dd0:
    if (ctx->pc == 0x197DD0u) {
        ctx->pc = 0x197DD0u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 136));
        ctx->pc = 0x197DD4u;
        goto label_197dd4;
    }
    ctx->pc = 0x197DCCu;
    {
        const bool branch_taken_0x197dcc = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x197DD0u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 136));
        if (branch_taken_0x197dcc) {
            ctx->pc = 0x197DF0u;
            goto label_197df0;
        }
    }
    ctx->pc = 0x197DD4u;
label_197dd4:
    // 0x197dd4: 0x24030010
    ctx->pc = 0x197dd4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
label_197dd8:
    // 0x197dd8: 0x10830003
label_197ddc:
    if (ctx->pc == 0x197DDCu) {
        ctx->pc = 0x197DDCu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 72));
        ctx->pc = 0x197DE0u;
        goto label_197de0;
    }
    ctx->pc = 0x197DD8u;
    {
        const bool branch_taken_0x197dd8 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197DDCu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 72));
        if (branch_taken_0x197dd8) {
            ctx->pc = 0x197DE8u;
            goto label_197de8;
        }
    }
    ctx->pc = 0x197DE0u;
label_197de0:
    // 0x197de0: 0x10000007
label_197de4:
    if (ctx->pc == 0x197DE4u) {
        ctx->pc = 0x197DE4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197DE8u;
        goto label_197de8;
    }
    ctx->pc = 0x197DE0u;
    {
        const bool branch_taken_0x197de0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197DE4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197de0) {
            ctx->pc = 0x197E00u;
            goto label_197e00;
        }
    }
    ctx->pc = 0x197DE8u;
label_197de8:
    // 0x197de8: 0x1000010a
label_197dec:
    if (ctx->pc == 0x197DECu) {
        ctx->pc = 0x197DF0u;
        goto label_197df0;
    }
    ctx->pc = 0x197DE8u;
    {
        const bool branch_taken_0x197de8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197de8) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DF0u;
label_197df0:
    // 0x197df0: 0x10000108
label_197df4:
    if (ctx->pc == 0x197DF4u) {
        ctx->pc = 0x197DF8u;
        goto label_197df8;
    }
    ctx->pc = 0x197DF0u;
    {
        const bool branch_taken_0x197df0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197df0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DF8u;
label_197df8:
    // 0x197df8: 0x10000106
label_197dfc:
    if (ctx->pc == 0x197DFCu) {
        ctx->pc = 0x197E00u;
        goto label_197e00;
    }
    ctx->pc = 0x197DF8u;
    {
        const bool branch_taken_0x197df8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197df8) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E00u;
label_197e00:
    // 0x197e00: 0x1000012b
label_197e04:
    if (ctx->pc == 0x197E04u) {
        ctx->pc = 0x197E08u;
        goto label_197e08;
    }
    ctx->pc = 0x197E00u;
    {
        const bool branch_taken_0x197e00 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197e00) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197E08u;
label_197e08:
    // 0x197e08: 0x324400f0
    ctx->pc = 0x197e08u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_197e0c:
    // 0x197e0c: 0x24030020
    ctx->pc = 0x197e0cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
label_197e10:
    // 0x197e10: 0x10830007
label_197e14:
    if (ctx->pc == 0x197E14u) {
        ctx->pc = 0x197E14u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x197E18u;
        goto label_197e18;
    }
    ctx->pc = 0x197E10u;
    {
        const bool branch_taken_0x197e10 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197E14u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x197e10) {
            ctx->pc = 0x197E30u;
            goto label_197e30;
        }
    }
    ctx->pc = 0x197E18u;
label_197e18:
    // 0x197e18: 0x10800003
label_197e1c:
    if (ctx->pc == 0x197E1Cu) {
        ctx->pc = 0x197E1Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x197E20u;
        goto label_197e20;
    }
    ctx->pc = 0x197E18u;
    {
        const bool branch_taken_0x197e18 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x197E1Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x197e18) {
            ctx->pc = 0x197E28u;
            goto label_197e28;
        }
    }
    ctx->pc = 0x197E20u;
label_197e20:
    // 0x197e20: 0x10000005
label_197e24:
    if (ctx->pc == 0x197E24u) {
        ctx->pc = 0x197E24u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197E28u;
        goto label_197e28;
    }
    ctx->pc = 0x197E20u;
    {
        const bool branch_taken_0x197e20 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197E24u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197e20) {
            ctx->pc = 0x197E38u;
            goto label_197e38;
        }
    }
    ctx->pc = 0x197E28u;
label_197e28:
    // 0x197e28: 0x100000fa
label_197e2c:
    if (ctx->pc == 0x197E2Cu) {
        ctx->pc = 0x197E30u;
        goto label_197e30;
    }
    ctx->pc = 0x197E28u;
    {
        const bool branch_taken_0x197e28 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197e28) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E30u;
label_197e30:
    // 0x197e30: 0x100000f8
label_197e34:
    if (ctx->pc == 0x197E34u) {
        ctx->pc = 0x197E38u;
        goto label_197e38;
    }
    ctx->pc = 0x197E30u;
    {
        const bool branch_taken_0x197e30 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197e30) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E38u;
label_197e38:
    // 0x197e38: 0x1000011d
label_197e3c:
    if (ctx->pc == 0x197E3Cu) {
        ctx->pc = 0x197E40u;
        goto label_197e40;
    }
    ctx->pc = 0x197E38u;
    {
        const bool branch_taken_0x197e38 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197e38) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197E40u;
label_197e40:
    // 0x197e40: 0x324400f0
    ctx->pc = 0x197e40u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_197e44:
    // 0x197e44: 0x24030050
    ctx->pc = 0x197e44u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 80));
label_197e48:
    // 0x197e48: 0x1083000c
label_197e4c:
    if (ctx->pc == 0x197E4Cu) {
        ctx->pc = 0x197E4Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 84));
        ctx->pc = 0x197E50u;
        goto label_197e50;
    }
    ctx->pc = 0x197E48u;
    {
        const bool branch_taken_0x197e48 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197E4Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 84));
        if (branch_taken_0x197e48) {
            ctx->pc = 0x197E7Cu;
            goto label_197e7c;
        }
    }
    ctx->pc = 0x197E50u;
label_197e50:
    // 0x197e50: 0x10800008
label_197e54:
    if (ctx->pc == 0x197E54u) {
        ctx->pc = 0x197E54u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 152));
        ctx->pc = 0x197E58u;
        goto label_197e58;
    }
    ctx->pc = 0x197E50u;
    {
        const bool branch_taken_0x197e50 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x197E54u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 152));
        if (branch_taken_0x197e50) {
            ctx->pc = 0x197E74u;
            goto label_197e74;
        }
    }
    ctx->pc = 0x197E58u;
label_197e58:
    // 0x197e58: 0x24030010
    ctx->pc = 0x197e58u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
label_197e5c:
    // 0x197e5c: 0x10830003
label_197e60:
    if (ctx->pc == 0x197E60u) {
        ctx->pc = 0x197E60u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 88));
        ctx->pc = 0x197E64u;
        goto label_197e64;
    }
    ctx->pc = 0x197E5Cu;
    {
        const bool branch_taken_0x197e5c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197E60u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 88));
        if (branch_taken_0x197e5c) {
            ctx->pc = 0x197E6Cu;
            goto label_197e6c;
        }
    }
    ctx->pc = 0x197E64u;
label_197e64:
    // 0x197e64: 0x10000007
label_197e68:
    if (ctx->pc == 0x197E68u) {
        ctx->pc = 0x197E68u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197E6Cu;
        goto label_197e6c;
    }
    ctx->pc = 0x197E64u;
    {
        const bool branch_taken_0x197e64 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197E68u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197e64) {
            ctx->pc = 0x197E84u;
            goto label_197e84;
        }
    }
    ctx->pc = 0x197E6Cu;
label_197e6c:
    // 0x197e6c: 0x100000e9
label_197e70:
    if (ctx->pc == 0x197E70u) {
        ctx->pc = 0x197E74u;
        goto label_197e74;
    }
    ctx->pc = 0x197E6Cu;
    {
        const bool branch_taken_0x197e6c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197e6c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E74u;
label_197e74:
    // 0x197e74: 0x100000e7
label_197e78:
    if (ctx->pc == 0x197E78u) {
        ctx->pc = 0x197E7Cu;
        goto label_197e7c;
    }
    ctx->pc = 0x197E74u;
    {
        const bool branch_taken_0x197e74 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197e74) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E7Cu;
label_197e7c:
    // 0x197e7c: 0x100000e5
label_197e80:
    if (ctx->pc == 0x197E80u) {
        ctx->pc = 0x197E84u;
        goto label_197e84;
    }
    ctx->pc = 0x197E7Cu;
    {
        const bool branch_taken_0x197e7c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197e7c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E84u;
label_197e84:
    // 0x197e84: 0x1000010a
label_197e88:
    if (ctx->pc == 0x197E88u) {
        ctx->pc = 0x197E8Cu;
        goto label_197e8c;
    }
    ctx->pc = 0x197E84u;
    {
        const bool branch_taken_0x197e84 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197e84) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197E8Cu;
label_197e8c:
    // 0x197e8c: 0x324400f0
    ctx->pc = 0x197e8cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_197e90:
    // 0x197e90: 0x24030040
    ctx->pc = 0x197e90u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
label_197e94:
    // 0x197e94: 0x10830007
label_197e98:
    if (ctx->pc == 0x197E98u) {
        ctx->pc = 0x197E98u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 17));
        ctx->pc = 0x197E9Cu;
        goto label_197e9c;
    }
    ctx->pc = 0x197E94u;
    {
        const bool branch_taken_0x197e94 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197E98u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 17));
        if (branch_taken_0x197e94) {
            ctx->pc = 0x197EB4u;
            goto label_197eb4;
        }
    }
    ctx->pc = 0x197E9Cu;
label_197e9c:
    // 0x197e9c: 0x10800003
label_197ea0:
    if (ctx->pc == 0x197EA0u) {
        ctx->pc = 0x197EA0u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 18));
        ctx->pc = 0x197EA4u;
        goto label_197ea4;
    }
    ctx->pc = 0x197E9Cu;
    {
        const bool branch_taken_0x197e9c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x197EA0u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 18));
        if (branch_taken_0x197e9c) {
            ctx->pc = 0x197EACu;
            goto label_197eac;
        }
    }
    ctx->pc = 0x197EA4u;
label_197ea4:
    // 0x197ea4: 0x10000005
label_197ea8:
    if (ctx->pc == 0x197EA8u) {
        ctx->pc = 0x197EA8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197EACu;
        goto label_197eac;
    }
    ctx->pc = 0x197EA4u;
    {
        const bool branch_taken_0x197ea4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197EA8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197ea4) {
            ctx->pc = 0x197EBCu;
            goto label_197ebc;
        }
    }
    ctx->pc = 0x197EACu;
label_197eac:
    // 0x197eac: 0x100000d9
label_197eb0:
    if (ctx->pc == 0x197EB0u) {
        ctx->pc = 0x197EB4u;
        goto label_197eb4;
    }
    ctx->pc = 0x197EACu;
    {
        const bool branch_taken_0x197eac = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197eac) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197EB4u;
label_197eb4:
    // 0x197eb4: 0x100000d7
label_197eb8:
    if (ctx->pc == 0x197EB8u) {
        ctx->pc = 0x197EBCu;
        goto label_197ebc;
    }
    ctx->pc = 0x197EB4u;
    {
        const bool branch_taken_0x197eb4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197eb4) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197EBCu;
label_197ebc:
    // 0x197ebc: 0x100000fc
label_197ec0:
    if (ctx->pc == 0x197EC0u) {
        ctx->pc = 0x197EC4u;
        goto label_197ec4;
    }
    ctx->pc = 0x197EBCu;
    {
        const bool branch_taken_0x197ebc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197ebc) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197EC4u;
label_197ec4:
    // 0x197ec4: 0x100000fa
label_197ec8:
    if (ctx->pc == 0x197EC8u) {
        ctx->pc = 0x197EC8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197ECCu;
        goto label_197ecc;
    }
    ctx->pc = 0x197EC4u;
    {
        const bool branch_taken_0x197ec4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197EC8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197ec4) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197ECCu;
label_197ecc:
    // 0x197ecc: 0x24030400
    ctx->pc = 0x197eccu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1024));
label_197ed0:
    // 0x197ed0: 0x14a3006b
label_197ed4:
    if (ctx->pc == 0x197ED4u) {
        ctx->pc = 0x197ED4u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2048));
        ctx->pc = 0x197ED8u;
        goto label_197ed8;
    }
    ctx->pc = 0x197ED0u;
    {
        const bool branch_taken_0x197ed0 = (GPR_U32(ctx, 5) != GPR_U32(ctx, 3));
        ctx->pc = 0x197ED4u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2048));
        if (branch_taken_0x197ed0) {
            ctx->pc = 0x198080u;
            goto label_198080;
        }
    }
    ctx->pc = 0x197ED8u;
label_197ed8:
    // 0x197ed8: 0x3243000f
    ctx->pc = 0x197ed8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 18), 15));
label_197edc:
    // 0x197edc: 0x2c610006
    ctx->pc = 0x197edcu;
    SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 3), 6));
label_197ee0:
    // 0x197ee0: 0x10200065
label_197ee4:
    if (ctx->pc == 0x197EE4u) {
        ctx->pc = 0x197EE4u;
        SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
        ctx->pc = 0x197EE8u;
        goto label_197ee8;
    }
    ctx->pc = 0x197EE0u;
    {
        const bool branch_taken_0x197ee0 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x197EE4u;
        SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
        if (branch_taken_0x197ee0) {
            ctx->pc = 0x198078u;
            goto label_198078;
        }
    }
    ctx->pc = 0x197EE8u;
label_197ee8:
    // 0x197ee8: 0x31880
    ctx->pc = 0x197ee8u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
label_197eec:
    // 0x197eec: 0x24841ce0
    ctx->pc = 0x197eecu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 7392));
label_197ef0:
    // 0x197ef0: 0x641821
    ctx->pc = 0x197ef0u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_197ef4:
    // 0x197ef4: 0x8c630000
    ctx->pc = 0x197ef4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_197ef8:
    // 0x197ef8: 0x600008
label_197efc:
    if (ctx->pc == 0x197EFCu) {
        ctx->pc = 0x197F00u;
        goto label_197f00;
    }
    ctx->pc = 0x197EF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x197BB0u: goto label_197bb0;
            case 0x197BB4u: goto label_197bb4;
            case 0x197BB8u: goto label_197bb8;
            case 0x197BBCu: goto label_197bbc;
            case 0x197BC0u: goto label_197bc0;
            case 0x197BC4u: goto label_197bc4;
            case 0x197BC8u: goto label_197bc8;
            case 0x197BCCu: goto label_197bcc;
            case 0x197BD0u: goto label_197bd0;
            case 0x197BD4u: goto label_197bd4;
            case 0x197BD8u: goto label_197bd8;
            case 0x197BDCu: goto label_197bdc;
            case 0x197BE0u: goto label_197be0;
            case 0x197BE4u: goto label_197be4;
            case 0x197BE8u: goto label_197be8;
            case 0x197BECu: goto label_197bec;
            case 0x197BF0u: goto label_197bf0;
            case 0x197BF4u: goto label_197bf4;
            case 0x197BF8u: goto label_197bf8;
            case 0x197BFCu: goto label_197bfc;
            case 0x197C00u: goto label_197c00;
            case 0x197C04u: goto label_197c04;
            case 0x197C08u: goto label_197c08;
            case 0x197C0Cu: goto label_197c0c;
            case 0x197C10u: goto label_197c10;
            case 0x197C14u: goto label_197c14;
            case 0x197C18u: goto label_197c18;
            case 0x197C1Cu: goto label_197c1c;
            case 0x197C20u: goto label_197c20;
            case 0x197C24u: goto label_197c24;
            case 0x197C28u: goto label_197c28;
            case 0x197C2Cu: goto label_197c2c;
            case 0x197C30u: goto label_197c30;
            case 0x197C34u: goto label_197c34;
            case 0x197C38u: goto label_197c38;
            case 0x197C3Cu: goto label_197c3c;
            case 0x197C40u: goto label_197c40;
            case 0x197C44u: goto label_197c44;
            case 0x197C48u: goto label_197c48;
            case 0x197C4Cu: goto label_197c4c;
            case 0x197C50u: goto label_197c50;
            case 0x197C54u: goto label_197c54;
            case 0x197C58u: goto label_197c58;
            case 0x197C5Cu: goto label_197c5c;
            case 0x197C60u: goto label_197c60;
            case 0x197C64u: goto label_197c64;
            case 0x197C68u: goto label_197c68;
            case 0x197C6Cu: goto label_197c6c;
            case 0x197C70u: goto label_197c70;
            case 0x197C74u: goto label_197c74;
            case 0x197C78u: goto label_197c78;
            case 0x197C7Cu: goto label_197c7c;
            case 0x197C80u: goto label_197c80;
            case 0x197C84u: goto label_197c84;
            case 0x197C88u: goto label_197c88;
            case 0x197C8Cu: goto label_197c8c;
            case 0x197C90u: goto label_197c90;
            case 0x197C94u: goto label_197c94;
            case 0x197C98u: goto label_197c98;
            case 0x197C9Cu: goto label_197c9c;
            case 0x197CA0u: goto label_197ca0;
            case 0x197CA4u: goto label_197ca4;
            case 0x197CA8u: goto label_197ca8;
            case 0x197CACu: goto label_197cac;
            case 0x197CB0u: goto label_197cb0;
            case 0x197CB4u: goto label_197cb4;
            case 0x197CB8u: goto label_197cb8;
            case 0x197CBCu: goto label_197cbc;
            case 0x197CC0u: goto label_197cc0;
            case 0x197CC4u: goto label_197cc4;
            case 0x197CC8u: goto label_197cc8;
            case 0x197CCCu: goto label_197ccc;
            case 0x197CD0u: goto label_197cd0;
            case 0x197CD4u: goto label_197cd4;
            case 0x197CD8u: goto label_197cd8;
            case 0x197CDCu: goto label_197cdc;
            case 0x197CE0u: goto label_197ce0;
            case 0x197CE4u: goto label_197ce4;
            case 0x197CE8u: goto label_197ce8;
            case 0x197CECu: goto label_197cec;
            case 0x197CF0u: goto label_197cf0;
            case 0x197CF4u: goto label_197cf4;
            case 0x197CF8u: goto label_197cf8;
            case 0x197CFCu: goto label_197cfc;
            case 0x197D00u: goto label_197d00;
            case 0x197D04u: goto label_197d04;
            case 0x197D08u: goto label_197d08;
            case 0x197D0Cu: goto label_197d0c;
            case 0x197D10u: goto label_197d10;
            case 0x197D14u: goto label_197d14;
            case 0x197D18u: goto label_197d18;
            case 0x197D1Cu: goto label_197d1c;
            case 0x197D20u: goto label_197d20;
            case 0x197D24u: goto label_197d24;
            case 0x197D28u: goto label_197d28;
            case 0x197D2Cu: goto label_197d2c;
            case 0x197D30u: goto label_197d30;
            case 0x197D34u: goto label_197d34;
            case 0x197D38u: goto label_197d38;
            case 0x197D3Cu: goto label_197d3c;
            case 0x197D40u: goto label_197d40;
            case 0x197D44u: goto label_197d44;
            case 0x197D48u: goto label_197d48;
            case 0x197D4Cu: goto label_197d4c;
            case 0x197D50u: goto label_197d50;
            case 0x197D54u: goto label_197d54;
            case 0x197D58u: goto label_197d58;
            case 0x197D5Cu: goto label_197d5c;
            case 0x197D60u: goto label_197d60;
            case 0x197D64u: goto label_197d64;
            case 0x197D68u: goto label_197d68;
            case 0x197D6Cu: goto label_197d6c;
            case 0x197D70u: goto label_197d70;
            case 0x197D74u: goto label_197d74;
            case 0x197D78u: goto label_197d78;
            case 0x197D7Cu: goto label_197d7c;
            case 0x197D80u: goto label_197d80;
            case 0x197D84u: goto label_197d84;
            case 0x197D88u: goto label_197d88;
            case 0x197D8Cu: goto label_197d8c;
            case 0x197D90u: goto label_197d90;
            case 0x197D94u: goto label_197d94;
            case 0x197D98u: goto label_197d98;
            case 0x197D9Cu: goto label_197d9c;
            case 0x197DA0u: goto label_197da0;
            case 0x197DA4u: goto label_197da4;
            case 0x197DA8u: goto label_197da8;
            case 0x197DACu: goto label_197dac;
            case 0x197DB0u: goto label_197db0;
            case 0x197DB4u: goto label_197db4;
            case 0x197DB8u: goto label_197db8;
            case 0x197DBCu: goto label_197dbc;
            case 0x197DC0u: goto label_197dc0;
            case 0x197DC4u: goto label_197dc4;
            case 0x197DC8u: goto label_197dc8;
            case 0x197DCCu: goto label_197dcc;
            case 0x197DD0u: goto label_197dd0;
            case 0x197DD4u: goto label_197dd4;
            case 0x197DD8u: goto label_197dd8;
            case 0x197DDCu: goto label_197ddc;
            case 0x197DE0u: goto label_197de0;
            case 0x197DE4u: goto label_197de4;
            case 0x197DE8u: goto label_197de8;
            case 0x197DECu: goto label_197dec;
            case 0x197DF0u: goto label_197df0;
            case 0x197DF4u: goto label_197df4;
            case 0x197DF8u: goto label_197df8;
            case 0x197DFCu: goto label_197dfc;
            case 0x197E00u: goto label_197e00;
            case 0x197E04u: goto label_197e04;
            case 0x197E08u: goto label_197e08;
            case 0x197E0Cu: goto label_197e0c;
            case 0x197E10u: goto label_197e10;
            case 0x197E14u: goto label_197e14;
            case 0x197E18u: goto label_197e18;
            case 0x197E1Cu: goto label_197e1c;
            case 0x197E20u: goto label_197e20;
            case 0x197E24u: goto label_197e24;
            case 0x197E28u: goto label_197e28;
            case 0x197E2Cu: goto label_197e2c;
            case 0x197E30u: goto label_197e30;
            case 0x197E34u: goto label_197e34;
            case 0x197E38u: goto label_197e38;
            case 0x197E3Cu: goto label_197e3c;
            case 0x197E40u: goto label_197e40;
            case 0x197E44u: goto label_197e44;
            case 0x197E48u: goto label_197e48;
            case 0x197E4Cu: goto label_197e4c;
            case 0x197E50u: goto label_197e50;
            case 0x197E54u: goto label_197e54;
            case 0x197E58u: goto label_197e58;
            case 0x197E5Cu: goto label_197e5c;
            case 0x197E60u: goto label_197e60;
            case 0x197E64u: goto label_197e64;
            case 0x197E68u: goto label_197e68;
            case 0x197E6Cu: goto label_197e6c;
            case 0x197E70u: goto label_197e70;
            case 0x197E74u: goto label_197e74;
            case 0x197E78u: goto label_197e78;
            case 0x197E7Cu: goto label_197e7c;
            case 0x197E80u: goto label_197e80;
            case 0x197E84u: goto label_197e84;
            case 0x197E88u: goto label_197e88;
            case 0x197E8Cu: goto label_197e8c;
            case 0x197E90u: goto label_197e90;
            case 0x197E94u: goto label_197e94;
            case 0x197E98u: goto label_197e98;
            case 0x197E9Cu: goto label_197e9c;
            case 0x197EA0u: goto label_197ea0;
            case 0x197EA4u: goto label_197ea4;
            case 0x197EA8u: goto label_197ea8;
            case 0x197EACu: goto label_197eac;
            case 0x197EB0u: goto label_197eb0;
            case 0x197EB4u: goto label_197eb4;
            case 0x197EB8u: goto label_197eb8;
            case 0x197EBCu: goto label_197ebc;
            case 0x197EC0u: goto label_197ec0;
            case 0x197EC4u: goto label_197ec4;
            case 0x197EC8u: goto label_197ec8;
            case 0x197ECCu: goto label_197ecc;
            case 0x197ED0u: goto label_197ed0;
            case 0x197ED4u: goto label_197ed4;
            case 0x197ED8u: goto label_197ed8;
            case 0x197EDCu: goto label_197edc;
            case 0x197EE0u: goto label_197ee0;
            case 0x197EE4u: goto label_197ee4;
            case 0x197EE8u: goto label_197ee8;
            case 0x197EECu: goto label_197eec;
            case 0x197EF0u: goto label_197ef0;
            case 0x197EF4u: goto label_197ef4;
            case 0x197EF8u: goto label_197ef8;
            case 0x197EFCu: goto label_197efc;
            case 0x197F00u: goto label_197f00;
            case 0x197F04u: goto label_197f04;
            case 0x197F08u: goto label_197f08;
            case 0x197F0Cu: goto label_197f0c;
            case 0x197F10u: goto label_197f10;
            case 0x197F14u: goto label_197f14;
            case 0x197F18u: goto label_197f18;
            case 0x197F1Cu: goto label_197f1c;
            case 0x197F20u: goto label_197f20;
            case 0x197F24u: goto label_197f24;
            case 0x197F28u: goto label_197f28;
            case 0x197F2Cu: goto label_197f2c;
            case 0x197F30u: goto label_197f30;
            case 0x197F34u: goto label_197f34;
            case 0x197F38u: goto label_197f38;
            case 0x197F3Cu: goto label_197f3c;
            case 0x197F40u: goto label_197f40;
            case 0x197F44u: goto label_197f44;
            case 0x197F48u: goto label_197f48;
            case 0x197F4Cu: goto label_197f4c;
            case 0x197F50u: goto label_197f50;
            case 0x197F54u: goto label_197f54;
            case 0x197F58u: goto label_197f58;
            case 0x197F5Cu: goto label_197f5c;
            case 0x197F60u: goto label_197f60;
            case 0x197F64u: goto label_197f64;
            case 0x197F68u: goto label_197f68;
            case 0x197F6Cu: goto label_197f6c;
            case 0x197F70u: goto label_197f70;
            case 0x197F74u: goto label_197f74;
            case 0x197F78u: goto label_197f78;
            case 0x197F7Cu: goto label_197f7c;
            case 0x197F80u: goto label_197f80;
            case 0x197F84u: goto label_197f84;
            case 0x197F88u: goto label_197f88;
            case 0x197F8Cu: goto label_197f8c;
            case 0x197F90u: goto label_197f90;
            case 0x197F94u: goto label_197f94;
            case 0x197F98u: goto label_197f98;
            case 0x197F9Cu: goto label_197f9c;
            case 0x197FA0u: goto label_197fa0;
            case 0x197FA4u: goto label_197fa4;
            case 0x197FA8u: goto label_197fa8;
            case 0x197FACu: goto label_197fac;
            case 0x197FB0u: goto label_197fb0;
            case 0x197FB4u: goto label_197fb4;
            case 0x197FB8u: goto label_197fb8;
            case 0x197FBCu: goto label_197fbc;
            case 0x197FC0u: goto label_197fc0;
            case 0x197FC4u: goto label_197fc4;
            case 0x197FC8u: goto label_197fc8;
            case 0x197FCCu: goto label_197fcc;
            case 0x197FD0u: goto label_197fd0;
            case 0x197FD4u: goto label_197fd4;
            case 0x197FD8u: goto label_197fd8;
            case 0x197FDCu: goto label_197fdc;
            case 0x197FE0u: goto label_197fe0;
            case 0x197FE4u: goto label_197fe4;
            case 0x197FE8u: goto label_197fe8;
            case 0x197FECu: goto label_197fec;
            case 0x197FF0u: goto label_197ff0;
            case 0x197FF4u: goto label_197ff4;
            case 0x197FF8u: goto label_197ff8;
            case 0x197FFCu: goto label_197ffc;
            case 0x198000u: goto label_198000;
            case 0x198004u: goto label_198004;
            case 0x198008u: goto label_198008;
            case 0x19800Cu: goto label_19800c;
            case 0x198010u: goto label_198010;
            case 0x198014u: goto label_198014;
            case 0x198018u: goto label_198018;
            case 0x19801Cu: goto label_19801c;
            case 0x198020u: goto label_198020;
            case 0x198024u: goto label_198024;
            case 0x198028u: goto label_198028;
            case 0x19802Cu: goto label_19802c;
            case 0x198030u: goto label_198030;
            case 0x198034u: goto label_198034;
            case 0x198038u: goto label_198038;
            case 0x19803Cu: goto label_19803c;
            case 0x198040u: goto label_198040;
            case 0x198044u: goto label_198044;
            case 0x198048u: goto label_198048;
            case 0x19804Cu: goto label_19804c;
            case 0x198050u: goto label_198050;
            case 0x198054u: goto label_198054;
            case 0x198058u: goto label_198058;
            case 0x19805Cu: goto label_19805c;
            case 0x198060u: goto label_198060;
            case 0x198064u: goto label_198064;
            case 0x198068u: goto label_198068;
            case 0x19806Cu: goto label_19806c;
            case 0x198070u: goto label_198070;
            case 0x198074u: goto label_198074;
            case 0x198078u: goto label_198078;
            case 0x19807Cu: goto label_19807c;
            case 0x198080u: goto label_198080;
            case 0x198084u: goto label_198084;
            case 0x198088u: goto label_198088;
            case 0x19808Cu: goto label_19808c;
            case 0x198090u: goto label_198090;
            case 0x198094u: goto label_198094;
            case 0x198098u: goto label_198098;
            case 0x19809Cu: goto label_19809c;
            case 0x1980A0u: goto label_1980a0;
            case 0x1980A4u: goto label_1980a4;
            case 0x1980A8u: goto label_1980a8;
            case 0x1980ACu: goto label_1980ac;
            case 0x1980B0u: goto label_1980b0;
            case 0x1980B4u: goto label_1980b4;
            case 0x1980B8u: goto label_1980b8;
            case 0x1980BCu: goto label_1980bc;
            case 0x1980C0u: goto label_1980c0;
            case 0x1980C4u: goto label_1980c4;
            case 0x1980C8u: goto label_1980c8;
            case 0x1980CCu: goto label_1980cc;
            case 0x1980D0u: goto label_1980d0;
            case 0x1980D4u: goto label_1980d4;
            case 0x1980D8u: goto label_1980d8;
            case 0x1980DCu: goto label_1980dc;
            case 0x1980E0u: goto label_1980e0;
            case 0x1980E4u: goto label_1980e4;
            case 0x1980E8u: goto label_1980e8;
            case 0x1980ECu: goto label_1980ec;
            case 0x1980F0u: goto label_1980f0;
            case 0x1980F4u: goto label_1980f4;
            case 0x1980F8u: goto label_1980f8;
            case 0x1980FCu: goto label_1980fc;
            case 0x198100u: goto label_198100;
            case 0x198104u: goto label_198104;
            case 0x198108u: goto label_198108;
            case 0x19810Cu: goto label_19810c;
            case 0x198110u: goto label_198110;
            case 0x198114u: goto label_198114;
            case 0x198118u: goto label_198118;
            case 0x19811Cu: goto label_19811c;
            case 0x198120u: goto label_198120;
            case 0x198124u: goto label_198124;
            case 0x198128u: goto label_198128;
            case 0x19812Cu: goto label_19812c;
            case 0x198130u: goto label_198130;
            case 0x198134u: goto label_198134;
            case 0x198138u: goto label_198138;
            case 0x19813Cu: goto label_19813c;
            case 0x198140u: goto label_198140;
            case 0x198144u: goto label_198144;
            case 0x198148u: goto label_198148;
            case 0x19814Cu: goto label_19814c;
            case 0x198150u: goto label_198150;
            case 0x198154u: goto label_198154;
            case 0x198158u: goto label_198158;
            case 0x19815Cu: goto label_19815c;
            case 0x198160u: goto label_198160;
            case 0x198164u: goto label_198164;
            case 0x198168u: goto label_198168;
            case 0x19816Cu: goto label_19816c;
            case 0x198170u: goto label_198170;
            case 0x198174u: goto label_198174;
            case 0x198178u: goto label_198178;
            case 0x19817Cu: goto label_19817c;
            case 0x198180u: goto label_198180;
            case 0x198184u: goto label_198184;
            case 0x198188u: goto label_198188;
            case 0x19818Cu: goto label_19818c;
            case 0x198190u: goto label_198190;
            case 0x198194u: goto label_198194;
            case 0x198198u: goto label_198198;
            case 0x19819Cu: goto label_19819c;
            case 0x1981A0u: goto label_1981a0;
            case 0x1981A4u: goto label_1981a4;
            case 0x1981A8u: goto label_1981a8;
            case 0x1981ACu: goto label_1981ac;
            case 0x1981B0u: goto label_1981b0;
            case 0x1981B4u: goto label_1981b4;
            case 0x1981B8u: goto label_1981b8;
            case 0x1981BCu: goto label_1981bc;
            case 0x1981C0u: goto label_1981c0;
            case 0x1981C4u: goto label_1981c4;
            case 0x1981C8u: goto label_1981c8;
            case 0x1981CCu: goto label_1981cc;
            case 0x1981D0u: goto label_1981d0;
            case 0x1981D4u: goto label_1981d4;
            case 0x1981D8u: goto label_1981d8;
            case 0x1981DCu: goto label_1981dc;
            case 0x1981E0u: goto label_1981e0;
            case 0x1981E4u: goto label_1981e4;
            case 0x1981E8u: goto label_1981e8;
            case 0x1981ECu: goto label_1981ec;
            case 0x1981F0u: goto label_1981f0;
            case 0x1981F4u: goto label_1981f4;
            case 0x1981F8u: goto label_1981f8;
            case 0x1981FCu: goto label_1981fc;
            case 0x198200u: goto label_198200;
            case 0x198204u: goto label_198204;
            case 0x198208u: goto label_198208;
            case 0x19820Cu: goto label_19820c;
            case 0x198210u: goto label_198210;
            case 0x198214u: goto label_198214;
            case 0x198218u: goto label_198218;
            case 0x19821Cu: goto label_19821c;
            case 0x198220u: goto label_198220;
            case 0x198224u: goto label_198224;
            case 0x198228u: goto label_198228;
            case 0x19822Cu: goto label_19822c;
            case 0x198230u: goto label_198230;
            case 0x198234u: goto label_198234;
            case 0x198238u: goto label_198238;
            case 0x19823Cu: goto label_19823c;
            case 0x198240u: goto label_198240;
            case 0x198244u: goto label_198244;
            case 0x198248u: goto label_198248;
            case 0x19824Cu: goto label_19824c;
            case 0x198250u: goto label_198250;
            case 0x198254u: goto label_198254;
            case 0x198258u: goto label_198258;
            case 0x19825Cu: goto label_19825c;
            case 0x198260u: goto label_198260;
            case 0x198264u: goto label_198264;
            case 0x198268u: goto label_198268;
            case 0x19826Cu: goto label_19826c;
            case 0x198270u: goto label_198270;
            case 0x198274u: goto label_198274;
            case 0x198278u: goto label_198278;
            case 0x19827Cu: goto label_19827c;
            case 0x198280u: goto label_198280;
            case 0x198284u: goto label_198284;
            case 0x198288u: goto label_198288;
            case 0x19828Cu: goto label_19828c;
            case 0x198290u: goto label_198290;
            case 0x198294u: goto label_198294;
            case 0x198298u: goto label_198298;
            case 0x19829Cu: goto label_19829c;
            case 0x1982A0u: goto label_1982a0;
            case 0x1982A4u: goto label_1982a4;
            case 0x1982A8u: goto label_1982a8;
            case 0x1982ACu: goto label_1982ac;
            case 0x1982B0u: goto label_1982b0;
            case 0x1982B4u: goto label_1982b4;
            case 0x1982B8u: goto label_1982b8;
            case 0x1982BCu: goto label_1982bc;
            case 0x1982C0u: goto label_1982c0;
            case 0x1982C4u: goto label_1982c4;
            case 0x1982C8u: goto label_1982c8;
            case 0x1982CCu: goto label_1982cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x197F00u;
label_197f00:
    // 0x197f00: 0x324400f0
    ctx->pc = 0x197f00u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_197f04:
    // 0x197f04: 0x1080000a
label_197f08:
    if (ctx->pc == 0x197F08u) {
        ctx->pc = 0x197F08u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x197F0Cu;
        goto label_197f0c;
    }
    ctx->pc = 0x197F04u;
    {
        const bool branch_taken_0x197f04 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x197F08u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x197f04) {
            ctx->pc = 0x197F30u;
            goto label_197f30;
        }
    }
    ctx->pc = 0x197F0Cu;
label_197f0c:
    // 0x197f0c: 0x10830003
label_197f10:
    if (ctx->pc == 0x197F10u) {
        ctx->pc = 0x197F14u;
        goto label_197f14;
    }
    ctx->pc = 0x197F0Cu;
    {
        const bool branch_taken_0x197f0c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x197f0c) {
            ctx->pc = 0x197F1Cu;
            goto label_197f1c;
        }
    }
    ctx->pc = 0x197F14u;
label_197f14:
    // 0x197f14: 0x1000000b
label_197f18:
    if (ctx->pc == 0x197F18u) {
        ctx->pc = 0x197F18u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197F1Cu;
        goto label_197f1c;
    }
    ctx->pc = 0x197F14u;
    {
        const bool branch_taken_0x197f14 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197F18u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197f14) {
            ctx->pc = 0x197F44u;
            goto label_197f44;
        }
    }
    ctx->pc = 0x197F1Cu;
label_197f1c:
    // 0x197f1c: 0x24040080
    ctx->pc = 0x197f1cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_197f20:
    // 0x197f20: 0x240300a4
    ctx->pc = 0x197f20u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 164));
label_197f24:
    // 0x197f24: 0x4203c
    ctx->pc = 0x197f24u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_197f28:
    // 0x197f28: 0x100000ba
label_197f2c:
    if (ctx->pc == 0x197F2Cu) {
        ctx->pc = 0x197F2Cu;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x197F30u;
        goto label_197f30;
    }
    ctx->pc = 0x197F28u;
    {
        const bool branch_taken_0x197f28 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197F2Cu;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x197f28) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197F30u;
label_197f30:
    // 0x197f30: 0x24040080
    ctx->pc = 0x197f30u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_197f34:
    // 0x197f34: 0x2403002a
    ctx->pc = 0x197f34u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 42));
label_197f38:
    // 0x197f38: 0x4203c
    ctx->pc = 0x197f38u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_197f3c:
    // 0x197f3c: 0x100000b5
label_197f40:
    if (ctx->pc == 0x197F40u) {
        ctx->pc = 0x197F40u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x197F44u;
        goto label_197f44;
    }
    ctx->pc = 0x197F3Cu;
    {
        const bool branch_taken_0x197f3c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197F40u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x197f3c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197F44u;
label_197f44:
    // 0x197f44: 0x100000da
label_197f48:
    if (ctx->pc == 0x197F48u) {
        ctx->pc = 0x197F4Cu;
        goto label_197f4c;
    }
    ctx->pc = 0x197F44u;
    {
        const bool branch_taken_0x197f44 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197f44) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197F4Cu;
label_197f4c:
    // 0x197f4c: 0x324400f0
    ctx->pc = 0x197f4cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_197f50:
    // 0x197f50: 0x24030040
    ctx->pc = 0x197f50u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
label_197f54:
    // 0x197f54: 0x10830016
label_197f58:
    if (ctx->pc == 0x197F58u) {
        ctx->pc = 0x197F58u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 150));
        ctx->pc = 0x197F5Cu;
        goto label_197f5c;
    }
    ctx->pc = 0x197F54u;
    {
        const bool branch_taken_0x197f54 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197F58u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 150));
        if (branch_taken_0x197f54) {
            ctx->pc = 0x197FB0u;
            goto label_197fb0;
        }
    }
    ctx->pc = 0x197F5Cu;
label_197f5c:
    // 0x197f5c: 0x24030020
    ctx->pc = 0x197f5cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
label_197f60:
    // 0x197f60: 0x10830011
label_197f64:
    if (ctx->pc == 0x197F64u) {
        ctx->pc = 0x197F64u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 134));
        ctx->pc = 0x197F68u;
        goto label_197f68;
    }
    ctx->pc = 0x197F60u;
    {
        const bool branch_taken_0x197f60 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197F64u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 134));
        if (branch_taken_0x197f60) {
            ctx->pc = 0x197FA8u;
            goto label_197fa8;
        }
    }
    ctx->pc = 0x197F68u;
label_197f68:
    // 0x197f68: 0x1080000a
label_197f6c:
    if (ctx->pc == 0x197F6Cu) {
        ctx->pc = 0x197F6Cu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x197F70u;
        goto label_197f70;
    }
    ctx->pc = 0x197F68u;
    {
        const bool branch_taken_0x197f68 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x197F6Cu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x197f68) {
            ctx->pc = 0x197F94u;
            goto label_197f94;
        }
    }
    ctx->pc = 0x197F70u;
label_197f70:
    // 0x197f70: 0x10830003
label_197f74:
    if (ctx->pc == 0x197F74u) {
        ctx->pc = 0x197F78u;
        goto label_197f78;
    }
    ctx->pc = 0x197F70u;
    {
        const bool branch_taken_0x197f70 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x197f70) {
            ctx->pc = 0x197F80u;
            goto label_197f80;
        }
    }
    ctx->pc = 0x197F78u;
label_197f78:
    // 0x197f78: 0x1000000f
label_197f7c:
    if (ctx->pc == 0x197F7Cu) {
        ctx->pc = 0x197F7Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197F80u;
        goto label_197f80;
    }
    ctx->pc = 0x197F78u;
    {
        const bool branch_taken_0x197f78 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197F7Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197f78) {
            ctx->pc = 0x197FB8u;
            goto label_197fb8;
        }
    }
    ctx->pc = 0x197F80u;
label_197f80:
    // 0x197f80: 0x24040080
    ctx->pc = 0x197f80u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_197f84:
    // 0x197f84: 0x240300a6
    ctx->pc = 0x197f84u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 166));
label_197f88:
    // 0x197f88: 0x4203c
    ctx->pc = 0x197f88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_197f8c:
    // 0x197f8c: 0x100000a1
label_197f90:
    if (ctx->pc == 0x197F90u) {
        ctx->pc = 0x197F90u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x197F94u;
        goto label_197f94;
    }
    ctx->pc = 0x197F8Cu;
    {
        const bool branch_taken_0x197f8c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197F90u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x197f8c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197F94u;
label_197f94:
    // 0x197f94: 0x24040080
    ctx->pc = 0x197f94u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_197f98:
    // 0x197f98: 0x240300aa
    ctx->pc = 0x197f98u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 170));
label_197f9c:
    // 0x197f9c: 0x4203c
    ctx->pc = 0x197f9cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_197fa0:
    // 0x197fa0: 0x1000009c
label_197fa4:
    if (ctx->pc == 0x197FA4u) {
        ctx->pc = 0x197FA4u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x197FA8u;
        goto label_197fa8;
    }
    ctx->pc = 0x197FA0u;
    {
        const bool branch_taken_0x197fa0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197FA4u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x197fa0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FA8u;
label_197fa8:
    // 0x197fa8: 0x1000009a
label_197fac:
    if (ctx->pc == 0x197FACu) {
        ctx->pc = 0x197FB0u;
        goto label_197fb0;
    }
    ctx->pc = 0x197FA8u;
    {
        const bool branch_taken_0x197fa8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197fa8) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FB0u;
label_197fb0:
    // 0x197fb0: 0x10000098
label_197fb4:
    if (ctx->pc == 0x197FB4u) {
        ctx->pc = 0x197FB8u;
        goto label_197fb8;
    }
    ctx->pc = 0x197FB0u;
    {
        const bool branch_taken_0x197fb0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197fb0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FB8u;
label_197fb8:
    // 0x197fb8: 0x100000bd
label_197fbc:
    if (ctx->pc == 0x197FBCu) {
        ctx->pc = 0x197FC0u;
        goto label_197fc0;
    }
    ctx->pc = 0x197FB8u;
    {
        const bool branch_taken_0x197fb8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197fb8) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197FC0u;
label_197fc0:
    // 0x197fc0: 0x324400f0
    ctx->pc = 0x197fc0u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_197fc4:
    // 0x197fc4: 0x24030020
    ctx->pc = 0x197fc4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
label_197fc8:
    // 0x197fc8: 0x10830007
label_197fcc:
    if (ctx->pc == 0x197FCCu) {
        ctx->pc = 0x197FCCu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 132));
        ctx->pc = 0x197FD0u;
        goto label_197fd0;
    }
    ctx->pc = 0x197FC8u;
    {
        const bool branch_taken_0x197fc8 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x197FCCu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 132));
        if (branch_taken_0x197fc8) {
            ctx->pc = 0x197FE8u;
            goto label_197fe8;
        }
    }
    ctx->pc = 0x197FD0u;
label_197fd0:
    // 0x197fd0: 0x10800003
label_197fd4:
    if (ctx->pc == 0x197FD4u) {
        ctx->pc = 0x197FD4u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 136));
        ctx->pc = 0x197FD8u;
        goto label_197fd8;
    }
    ctx->pc = 0x197FD0u;
    {
        const bool branch_taken_0x197fd0 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x197FD4u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 136));
        if (branch_taken_0x197fd0) {
            ctx->pc = 0x197FE0u;
            goto label_197fe0;
        }
    }
    ctx->pc = 0x197FD8u;
label_197fd8:
    // 0x197fd8: 0x10000005
label_197fdc:
    if (ctx->pc == 0x197FDCu) {
        ctx->pc = 0x197FDCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x197FE0u;
        goto label_197fe0;
    }
    ctx->pc = 0x197FD8u;
    {
        const bool branch_taken_0x197fd8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197FDCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197fd8) {
            ctx->pc = 0x197FF0u;
            goto label_197ff0;
        }
    }
    ctx->pc = 0x197FE0u;
label_197fe0:
    // 0x197fe0: 0x1000008c
label_197fe4:
    if (ctx->pc == 0x197FE4u) {
        ctx->pc = 0x197FE8u;
        goto label_197fe8;
    }
    ctx->pc = 0x197FE0u;
    {
        const bool branch_taken_0x197fe0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197fe0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FE8u;
label_197fe8:
    // 0x197fe8: 0x1000008a
label_197fec:
    if (ctx->pc == 0x197FECu) {
        ctx->pc = 0x197FF0u;
        goto label_197ff0;
    }
    ctx->pc = 0x197FE8u;
    {
        const bool branch_taken_0x197fe8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197fe8) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FF0u;
label_197ff0:
    // 0x197ff0: 0x100000af
label_197ff4:
    if (ctx->pc == 0x197FF4u) {
        ctx->pc = 0x197FF8u;
        goto label_197ff8;
    }
    ctx->pc = 0x197FF0u;
    {
        const bool branch_taken_0x197ff0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x197ff0) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197FF8u;
label_197ff8:
    // 0x197ff8: 0x324300f0
    ctx->pc = 0x197ff8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 18), 240));
label_197ffc:
    // 0x197ffc: 0x10600003
label_198000:
    if (ctx->pc == 0x198000u) {
        ctx->pc = 0x198000u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x198004u;
        goto label_198004;
    }
    ctx->pc = 0x197FFCu;
    {
        const bool branch_taken_0x197ffc = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x198000u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x197ffc) {
            ctx->pc = 0x19800Cu;
            goto label_19800c;
        }
    }
    ctx->pc = 0x198004u;
label_198004:
    // 0x198004: 0x10000003
label_198008:
    if (ctx->pc == 0x198008u) {
        ctx->pc = 0x198008u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x19800Cu;
        goto label_19800c;
    }
    ctx->pc = 0x198004u;
    {
        const bool branch_taken_0x198004 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x198008u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x198004) {
            ctx->pc = 0x198014u;
            goto label_198014;
        }
    }
    ctx->pc = 0x19800Cu;
label_19800c:
    // 0x19800c: 0x10000081
label_198010:
    if (ctx->pc == 0x198010u) {
        ctx->pc = 0x198014u;
        goto label_198014;
    }
    ctx->pc = 0x19800Cu;
    {
        const bool branch_taken_0x19800c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x19800c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198014u;
label_198014:
    // 0x198014: 0x100000a6
label_198018:
    if (ctx->pc == 0x198018u) {
        ctx->pc = 0x19801Cu;
        goto label_19801c;
    }
    ctx->pc = 0x198014u;
    {
        const bool branch_taken_0x198014 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x198014) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x19801Cu;
label_19801c:
    // 0x19801c: 0x324400f0
    ctx->pc = 0x19801cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_198020:
    // 0x198020: 0x24030040
    ctx->pc = 0x198020u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
label_198024:
    // 0x198024: 0x10830007
label_198028:
    if (ctx->pc == 0x198028u) {
        ctx->pc = 0x198028u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 148));
        ctx->pc = 0x19802Cu;
        goto label_19802c;
    }
    ctx->pc = 0x198024u;
    {
        const bool branch_taken_0x198024 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x198028u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 148));
        if (branch_taken_0x198024) {
            ctx->pc = 0x198044u;
            goto label_198044;
        }
    }
    ctx->pc = 0x19802Cu;
label_19802c:
    // 0x19802c: 0x10800003
label_198030:
    if (ctx->pc == 0x198030u) {
        ctx->pc = 0x198030u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 152));
        ctx->pc = 0x198034u;
        goto label_198034;
    }
    ctx->pc = 0x19802Cu;
    {
        const bool branch_taken_0x19802c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x198030u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 152));
        if (branch_taken_0x19802c) {
            ctx->pc = 0x19803Cu;
            goto label_19803c;
        }
    }
    ctx->pc = 0x198034u;
label_198034:
    // 0x198034: 0x10000005
label_198038:
    if (ctx->pc == 0x198038u) {
        ctx->pc = 0x198038u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x19803Cu;
        goto label_19803c;
    }
    ctx->pc = 0x198034u;
    {
        const bool branch_taken_0x198034 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x198038u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x198034) {
            ctx->pc = 0x19804Cu;
            goto label_19804c;
        }
    }
    ctx->pc = 0x19803Cu;
label_19803c:
    // 0x19803c: 0x10000075
label_198040:
    if (ctx->pc == 0x198040u) {
        ctx->pc = 0x198044u;
        goto label_198044;
    }
    ctx->pc = 0x19803Cu;
    {
        const bool branch_taken_0x19803c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x19803c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198044u;
label_198044:
    // 0x198044: 0x10000073
label_198048:
    if (ctx->pc == 0x198048u) {
        ctx->pc = 0x19804Cu;
        goto label_19804c;
    }
    ctx->pc = 0x198044u;
    {
        const bool branch_taken_0x198044 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x198044) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x19804Cu;
label_19804c:
    // 0x19804c: 0x10000098
label_198050:
    if (ctx->pc == 0x198050u) {
        ctx->pc = 0x198054u;
        goto label_198054;
    }
    ctx->pc = 0x19804Cu;
    {
        const bool branch_taken_0x19804c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x19804c) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198054u;
label_198054:
    // 0x198054: 0x324300f0
    ctx->pc = 0x198054u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 18), 240));
label_198058:
    // 0x198058: 0x10600003
label_19805c:
    if (ctx->pc == 0x19805Cu) {
        ctx->pc = 0x19805Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 86));
        ctx->pc = 0x198060u;
        goto label_198060;
    }
    ctx->pc = 0x198058u;
    {
        const bool branch_taken_0x198058 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x19805Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 86));
        if (branch_taken_0x198058) {
            ctx->pc = 0x198068u;
            goto label_198068;
        }
    }
    ctx->pc = 0x198060u;
label_198060:
    // 0x198060: 0x10000003
label_198064:
    if (ctx->pc == 0x198064u) {
        ctx->pc = 0x198064u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x198068u;
        goto label_198068;
    }
    ctx->pc = 0x198060u;
    {
        const bool branch_taken_0x198060 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x198064u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x198060) {
            ctx->pc = 0x198070u;
            goto label_198070;
        }
    }
    ctx->pc = 0x198068u;
label_198068:
    // 0x198068: 0x1000006a
label_19806c:
    if (ctx->pc == 0x19806Cu) {
        ctx->pc = 0x198070u;
        goto label_198070;
    }
    ctx->pc = 0x198068u;
    {
        const bool branch_taken_0x198068 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x198068) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198070u;
label_198070:
    // 0x198070: 0x1000008f
label_198074:
    if (ctx->pc == 0x198074u) {
        ctx->pc = 0x198078u;
        goto label_198078;
    }
    ctx->pc = 0x198070u;
    {
        const bool branch_taken_0x198070 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x198070) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198078u;
label_198078:
    // 0x198078: 0x1000008d
label_19807c:
    if (ctx->pc == 0x19807Cu) {
        ctx->pc = 0x19807Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x198080u;
        goto label_198080;
    }
    ctx->pc = 0x198078u;
    {
        const bool branch_taken_0x198078 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19807Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x198078) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198080u;
label_198080:
    // 0x198080: 0x14a30064
label_198084:
    if (ctx->pc == 0x198084u) {
        ctx->pc = 0x198084u;
        SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 15));
        ctx->pc = 0x198088u;
        goto label_198088;
    }
    ctx->pc = 0x198080u;
    {
        const bool branch_taken_0x198080 = (GPR_U32(ctx, 5) != GPR_U32(ctx, 3));
        ctx->pc = 0x198084u;
        SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 15));
        if (branch_taken_0x198080) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198088u;
label_198088:
    // 0x198088: 0x24030004
    ctx->pc = 0x198088u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4));
label_19808c:
    // 0x19808c: 0x10830051
label_198090:
    if (ctx->pc == 0x198090u) {
        ctx->pc = 0x198090u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x198094u;
        goto label_198094;
    }
    ctx->pc = 0x19808Cu;
    {
        const bool branch_taken_0x19808c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x198090u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x19808c) {
            ctx->pc = 0x1981D4u;
            goto label_1981d4;
        }
    }
    ctx->pc = 0x198094u;
label_198094:
    // 0x198094: 0x10830041
label_198098:
    if (ctx->pc == 0x198098u) {
        ctx->pc = 0x19809Cu;
        goto label_19809c;
    }
    ctx->pc = 0x198094u;
    {
        const bool branch_taken_0x198094 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x198094) {
            ctx->pc = 0x19819Cu;
            goto label_19819c;
        }
    }
    ctx->pc = 0x19809Cu;
label_19809c:
    // 0x19809c: 0x10800018
label_1980a0:
    if (ctx->pc == 0x1980A0u) {
        ctx->pc = 0x1980A0u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1980A4u;
        goto label_1980a4;
    }
    ctx->pc = 0x19809Cu;
    {
        const bool branch_taken_0x19809c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x1980A0u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x19809c) {
            ctx->pc = 0x198100u;
            goto label_198100;
        }
    }
    ctx->pc = 0x1980A4u;
label_1980a4:
    // 0x1980a4: 0x10830003
label_1980a8:
    if (ctx->pc == 0x1980A8u) {
        ctx->pc = 0x1980ACu;
        goto label_1980ac;
    }
    ctx->pc = 0x1980A4u;
    {
        const bool branch_taken_0x1980a4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x1980a4) {
            ctx->pc = 0x1980B4u;
            goto label_1980b4;
        }
    }
    ctx->pc = 0x1980ACu;
label_1980ac:
    // 0x1980ac: 0x10000057
label_1980b0:
    if (ctx->pc == 0x1980B0u) {
        ctx->pc = 0x1980B0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1980B4u;
        goto label_1980b4;
    }
    ctx->pc = 0x1980ACu;
    {
        const bool branch_taken_0x1980ac = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1980B0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1980ac) {
            ctx->pc = 0x19820Cu;
            goto label_19820c;
        }
    }
    ctx->pc = 0x1980B4u;
label_1980b4:
    // 0x1980b4: 0x324400f0
    ctx->pc = 0x1980b4u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_1980b8:
    // 0x1980b8: 0x1080000a
label_1980bc:
    if (ctx->pc == 0x1980BCu) {
        ctx->pc = 0x1980BCu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x1980C0u;
        goto label_1980c0;
    }
    ctx->pc = 0x1980B8u;
    {
        const bool branch_taken_0x1980b8 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x1980BCu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x1980b8) {
            ctx->pc = 0x1980E4u;
            goto label_1980e4;
        }
    }
    ctx->pc = 0x1980C0u;
label_1980c0:
    // 0x1980c0: 0x10830003
label_1980c4:
    if (ctx->pc == 0x1980C4u) {
        ctx->pc = 0x1980C8u;
        goto label_1980c8;
    }
    ctx->pc = 0x1980C0u;
    {
        const bool branch_taken_0x1980c0 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x1980c0) {
            ctx->pc = 0x1980D0u;
            goto label_1980d0;
        }
    }
    ctx->pc = 0x1980C8u;
label_1980c8:
    // 0x1980c8: 0x1000000b
label_1980cc:
    if (ctx->pc == 0x1980CCu) {
        ctx->pc = 0x1980CCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1980D0u;
        goto label_1980d0;
    }
    ctx->pc = 0x1980C8u;
    {
        const bool branch_taken_0x1980c8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1980CCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1980c8) {
            ctx->pc = 0x1980F8u;
            goto label_1980f8;
        }
    }
    ctx->pc = 0x1980D0u;
label_1980d0:
    // 0x1980d0: 0x24040080
    ctx->pc = 0x1980d0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_1980d4:
    // 0x1980d4: 0x240300a1
    ctx->pc = 0x1980d4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 161));
label_1980d8:
    // 0x1980d8: 0x4203c
    ctx->pc = 0x1980d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_1980dc:
    // 0x1980dc: 0x1000004d
label_1980e0:
    if (ctx->pc == 0x1980E0u) {
        ctx->pc = 0x1980E0u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x1980E4u;
        goto label_1980e4;
    }
    ctx->pc = 0x1980DCu;
    {
        const bool branch_taken_0x1980dc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1980E0u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x1980dc) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1980E4u;
label_1980e4:
    // 0x1980e4: 0x24040080
    ctx->pc = 0x1980e4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_1980e8:
    // 0x1980e8: 0x240300a2
    ctx->pc = 0x1980e8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 162));
label_1980ec:
    // 0x1980ec: 0x4203c
    ctx->pc = 0x1980ecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_1980f0:
    // 0x1980f0: 0x10000048
label_1980f4:
    if (ctx->pc == 0x1980F4u) {
        ctx->pc = 0x1980F4u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x1980F8u;
        goto label_1980f8;
    }
    ctx->pc = 0x1980F0u;
    {
        const bool branch_taken_0x1980f0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1980F4u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x1980f0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1980F8u;
label_1980f8:
    // 0x1980f8: 0x1000006d
label_1980fc:
    if (ctx->pc == 0x1980FCu) {
        ctx->pc = 0x198100u;
        goto label_198100;
    }
    ctx->pc = 0x1980F8u;
    {
        const bool branch_taken_0x1980f8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1980f8) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198100u;
label_198100:
    // 0x198100: 0x324400f0
    ctx->pc = 0x198100u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_198104:
    // 0x198104: 0x24030050
    ctx->pc = 0x198104u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 80));
label_198108:
    // 0x198108: 0x10830020
label_19810c:
    if (ctx->pc == 0x19810Cu) {
        ctx->pc = 0x19810Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 86));
        ctx->pc = 0x198110u;
        goto label_198110;
    }
    ctx->pc = 0x198108u;
    {
        const bool branch_taken_0x198108 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x19810Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 86));
        if (branch_taken_0x198108) {
            ctx->pc = 0x19818Cu;
            goto label_19818c;
        }
    }
    ctx->pc = 0x198110u;
label_198110:
    // 0x198110: 0x24030040
    ctx->pc = 0x198110u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
label_198114:
    // 0x198114: 0x1083001b
label_198118:
    if (ctx->pc == 0x198118u) {
        ctx->pc = 0x198118u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 153));
        ctx->pc = 0x19811Cu;
        goto label_19811c;
    }
    ctx->pc = 0x198114u;
    {
        const bool branch_taken_0x198114 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x198118u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 153));
        if (branch_taken_0x198114) {
            ctx->pc = 0x198184u;
            goto label_198184;
        }
    }
    ctx->pc = 0x19811Cu;
label_19811c:
    // 0x19811c: 0x24030030
    ctx->pc = 0x19811cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 48));
label_198120:
    // 0x198120: 0x10830016
label_198124:
    if (ctx->pc == 0x198124u) {
        ctx->pc = 0x198124u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 70));
        ctx->pc = 0x198128u;
        goto label_198128;
    }
    ctx->pc = 0x198120u;
    {
        const bool branch_taken_0x198120 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x198124u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 70));
        if (branch_taken_0x198120) {
            ctx->pc = 0x19817Cu;
            goto label_19817c;
        }
    }
    ctx->pc = 0x198128u;
label_198128:
    // 0x198128: 0x24030020
    ctx->pc = 0x198128u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
label_19812c:
    // 0x19812c: 0x10830011
label_198130:
    if (ctx->pc == 0x198130u) {
        ctx->pc = 0x198130u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 137));
        ctx->pc = 0x198134u;
        goto label_198134;
    }
    ctx->pc = 0x19812Cu;
    {
        const bool branch_taken_0x19812c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x198130u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 137));
        if (branch_taken_0x19812c) {
            ctx->pc = 0x198174u;
            goto label_198174;
        }
    }
    ctx->pc = 0x198134u;
label_198134:
    // 0x198134: 0x1080000a
label_198138:
    if (ctx->pc == 0x198138u) {
        ctx->pc = 0x198138u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x19813Cu;
        goto label_19813c;
    }
    ctx->pc = 0x198134u;
    {
        const bool branch_taken_0x198134 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x198138u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x198134) {
            ctx->pc = 0x198160u;
            goto label_198160;
        }
    }
    ctx->pc = 0x19813Cu;
label_19813c:
    // 0x19813c: 0x10830003
label_198140:
    if (ctx->pc == 0x198140u) {
        ctx->pc = 0x198144u;
        goto label_198144;
    }
    ctx->pc = 0x19813Cu;
    {
        const bool branch_taken_0x19813c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x19813c) {
            ctx->pc = 0x19814Cu;
            goto label_19814c;
        }
    }
    ctx->pc = 0x198144u;
label_198144:
    // 0x198144: 0x10000013
label_198148:
    if (ctx->pc == 0x198148u) {
        ctx->pc = 0x198148u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x19814Cu;
        goto label_19814c;
    }
    ctx->pc = 0x198144u;
    {
        const bool branch_taken_0x198144 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x198148u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x198144) {
            ctx->pc = 0x198194u;
            goto label_198194;
        }
    }
    ctx->pc = 0x19814Cu;
label_19814c:
    // 0x19814c: 0x24040080
    ctx->pc = 0x19814cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_198150:
    // 0x198150: 0x240300a9
    ctx->pc = 0x198150u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 169));
label_198154:
    // 0x198154: 0x4203c
    ctx->pc = 0x198154u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_198158:
    // 0x198158: 0x1000002e
label_19815c:
    if (ctx->pc == 0x19815Cu) {
        ctx->pc = 0x19815Cu;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x198160u;
        goto label_198160;
    }
    ctx->pc = 0x198158u;
    {
        const bool branch_taken_0x198158 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19815Cu;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x198158) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198160u;
label_198160:
    // 0x198160: 0x24040080
    ctx->pc = 0x198160u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_198164:
    // 0x198164: 0x240300aa
    ctx->pc = 0x198164u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 170));
label_198168:
    // 0x198168: 0x4203c
    ctx->pc = 0x198168u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_19816c:
    // 0x19816c: 0x10000029
label_198170:
    if (ctx->pc == 0x198170u) {
        ctx->pc = 0x198170u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->pc = 0x198174u;
        goto label_198174;
    }
    ctx->pc = 0x19816Cu;
    {
        const bool branch_taken_0x19816c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x198170u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x19816c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198174u;
label_198174:
    // 0x198174: 0x10000027
label_198178:
    if (ctx->pc == 0x198178u) {
        ctx->pc = 0x19817Cu;
        goto label_19817c;
    }
    ctx->pc = 0x198174u;
    {
        const bool branch_taken_0x198174 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x198174) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x19817Cu;
label_19817c:
    // 0x19817c: 0x10000025
label_198180:
    if (ctx->pc == 0x198180u) {
        ctx->pc = 0x198184u;
        goto label_198184;
    }
    ctx->pc = 0x19817Cu;
    {
        const bool branch_taken_0x19817c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x19817c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198184u;
label_198184:
    // 0x198184: 0x10000023
label_198188:
    if (ctx->pc == 0x198188u) {
        ctx->pc = 0x19818Cu;
        goto label_19818c;
    }
    ctx->pc = 0x198184u;
    {
        const bool branch_taken_0x198184 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x198184) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x19818Cu;
label_19818c:
    // 0x19818c: 0x10000021
label_198190:
    if (ctx->pc == 0x198190u) {
        ctx->pc = 0x198194u;
        goto label_198194;
    }
    ctx->pc = 0x19818Cu;
    {
        const bool branch_taken_0x19818c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x19818c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198194u;
label_198194:
    // 0x198194: 0x10000046
label_198198:
    if (ctx->pc == 0x198198u) {
        ctx->pc = 0x19819Cu;
        goto label_19819c;
    }
    ctx->pc = 0x198194u;
    {
        const bool branch_taken_0x198194 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x198194) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x19819Cu;
label_19819c:
    // 0x19819c: 0x324400f0
    ctx->pc = 0x19819cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_1981a0:
    // 0x1981a0: 0x24030020
    ctx->pc = 0x1981a0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
label_1981a4:
    // 0x1981a4: 0x10830007
label_1981a8:
    if (ctx->pc == 0x1981A8u) {
        ctx->pc = 0x1981A8u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 129));
        ctx->pc = 0x1981ACu;
        goto label_1981ac;
    }
    ctx->pc = 0x1981A4u;
    {
        const bool branch_taken_0x1981a4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x1981A8u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 129));
        if (branch_taken_0x1981a4) {
            ctx->pc = 0x1981C4u;
            goto label_1981c4;
        }
    }
    ctx->pc = 0x1981ACu;
label_1981ac:
    // 0x1981ac: 0x10800003
label_1981b0:
    if (ctx->pc == 0x1981B0u) {
        ctx->pc = 0x1981B0u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 130));
        ctx->pc = 0x1981B4u;
        goto label_1981b4;
    }
    ctx->pc = 0x1981ACu;
    {
        const bool branch_taken_0x1981ac = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x1981B0u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 130));
        if (branch_taken_0x1981ac) {
            ctx->pc = 0x1981BCu;
            goto label_1981bc;
        }
    }
    ctx->pc = 0x1981B4u;
label_1981b4:
    // 0x1981b4: 0x10000005
label_1981b8:
    if (ctx->pc == 0x1981B8u) {
        ctx->pc = 0x1981B8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1981BCu;
        goto label_1981bc;
    }
    ctx->pc = 0x1981B4u;
    {
        const bool branch_taken_0x1981b4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1981B8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1981b4) {
            ctx->pc = 0x1981CCu;
            goto label_1981cc;
        }
    }
    ctx->pc = 0x1981BCu;
label_1981bc:
    // 0x1981bc: 0x10000015
label_1981c0:
    if (ctx->pc == 0x1981C0u) {
        ctx->pc = 0x1981C4u;
        goto label_1981c4;
    }
    ctx->pc = 0x1981BCu;
    {
        const bool branch_taken_0x1981bc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1981bc) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1981C4u;
label_1981c4:
    // 0x1981c4: 0x10000013
label_1981c8:
    if (ctx->pc == 0x1981C8u) {
        ctx->pc = 0x1981CCu;
        goto label_1981cc;
    }
    ctx->pc = 0x1981C4u;
    {
        const bool branch_taken_0x1981c4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1981c4) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1981CCu;
label_1981cc:
    // 0x1981cc: 0x10000038
label_1981d0:
    if (ctx->pc == 0x1981D0u) {
        ctx->pc = 0x1981D4u;
        goto label_1981d4;
    }
    ctx->pc = 0x1981CCu;
    {
        const bool branch_taken_0x1981cc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1981cc) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x1981D4u;
label_1981d4:
    // 0x1981d4: 0x324400f0
    ctx->pc = 0x1981d4u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), 240));
label_1981d8:
    // 0x1981d8: 0x24030040
    ctx->pc = 0x1981d8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 64));
label_1981dc:
    // 0x1981dc: 0x10830007
label_1981e0:
    if (ctx->pc == 0x1981E0u) {
        ctx->pc = 0x1981E0u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 145));
        ctx->pc = 0x1981E4u;
        goto label_1981e4;
    }
    ctx->pc = 0x1981DCu;
    {
        const bool branch_taken_0x1981dc = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x1981E0u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 145));
        if (branch_taken_0x1981dc) {
            ctx->pc = 0x1981FCu;
            goto label_1981fc;
        }
    }
    ctx->pc = 0x1981E4u;
label_1981e4:
    // 0x1981e4: 0x10800003
label_1981e8:
    if (ctx->pc == 0x1981E8u) {
        ctx->pc = 0x1981E8u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 146));
        ctx->pc = 0x1981ECu;
        goto label_1981ec;
    }
    ctx->pc = 0x1981E4u;
    {
        const bool branch_taken_0x1981e4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x1981E8u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 146));
        if (branch_taken_0x1981e4) {
            ctx->pc = 0x1981F4u;
            goto label_1981f4;
        }
    }
    ctx->pc = 0x1981ECu;
label_1981ec:
    // 0x1981ec: 0x10000005
label_1981f0:
    if (ctx->pc == 0x1981F0u) {
        ctx->pc = 0x1981F0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1981F4u;
        goto label_1981f4;
    }
    ctx->pc = 0x1981ECu;
    {
        const bool branch_taken_0x1981ec = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1981F0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1981ec) {
            ctx->pc = 0x198204u;
            goto label_198204;
        }
    }
    ctx->pc = 0x1981F4u;
label_1981f4:
    // 0x1981f4: 0x10000007
label_1981f8:
    if (ctx->pc == 0x1981F8u) {
        ctx->pc = 0x1981FCu;
        goto label_1981fc;
    }
    ctx->pc = 0x1981F4u;
    {
        const bool branch_taken_0x1981f4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1981f4) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1981FCu;
label_1981fc:
    // 0x1981fc: 0x10000005
label_198200:
    if (ctx->pc == 0x198200u) {
        ctx->pc = 0x198204u;
        goto label_198204;
    }
    ctx->pc = 0x1981FCu;
    {
        const bool branch_taken_0x1981fc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1981fc) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198204u;
label_198204:
    // 0x198204: 0x1000002a
label_198208:
    if (ctx->pc == 0x198208u) {
        ctx->pc = 0x19820Cu;
        goto label_19820c;
    }
    ctx->pc = 0x198204u;
    {
        const bool branch_taken_0x198204 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x198204) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x19820Cu;
label_19820c:
    // 0x19820c: 0x10000028
label_198210:
    if (ctx->pc == 0x198210u) {
        ctx->pc = 0x198214u;
        goto label_198214;
    }
    ctx->pc = 0x19820Cu;
    {
        const bool branch_taken_0x19820c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x19820c) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198214u;
label_198214:
    // 0x198214: 0x3c030100
    ctx->pc = 0x198214u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
label_198218:
    // 0x198218: 0x2431824
    ctx->pc = 0x198218u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
label_19821c:
    // 0x19821c: 0x14600006
label_198220:
    if (ctx->pc == 0x198220u) {
        ctx->pc = 0x198220u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x198224u;
        goto label_198224;
    }
    ctx->pc = 0x19821Cu;
    {
        const bool branch_taken_0x19821c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x198220u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x19821c) {
            ctx->pc = 0x198238u;
            goto label_198238;
        }
    }
    ctx->pc = 0x198224u;
label_198224:
    // 0x198224: 0x24040080
    ctx->pc = 0x198224u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 128));
label_198228:
    // 0x198228: 0x240300a8
    ctx->pc = 0x198228u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 168));
label_19822c:
    // 0x19822c: 0x4203c
    ctx->pc = 0x19822cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
label_198230:
    // 0x198230: 0x648025
    ctx->pc = 0x198230u;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_198234:
    // 0x198234: 0x24030002
    ctx->pc = 0x198234u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_198238:
    // 0x198238: 0x1223000f
label_19823c:
    if (ctx->pc == 0x19823Cu) {
        ctx->pc = 0x19823Cu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x198240u;
        goto label_198240;
    }
    ctx->pc = 0x198238u;
    {
        const bool branch_taken_0x198238 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 3));
        ctx->pc = 0x19823Cu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x198238) {
            ctx->pc = 0x198278u;
            goto label_198278;
        }
    }
    ctx->pc = 0x198240u;
label_198240:
    // 0x198240: 0x12230009
label_198244:
    if (ctx->pc == 0x198244u) {
        ctx->pc = 0x198248u;
        goto label_198248;
    }
    ctx->pc = 0x198240u;
    {
        const bool branch_taken_0x198240 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 3));
        if (branch_taken_0x198240) {
            ctx->pc = 0x198268u;
            goto label_198268;
        }
    }
    ctx->pc = 0x198248u;
label_198248:
    // 0x198248: 0x12200003
label_19824c:
    if (ctx->pc == 0x19824Cu) {
        ctx->pc = 0x198250u;
        goto label_198250;
    }
    ctx->pc = 0x198248u;
    {
        const bool branch_taken_0x198248 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        if (branch_taken_0x198248) {
            ctx->pc = 0x198258u;
            goto label_198258;
        }
    }
    ctx->pc = 0x198250u;
label_198250:
    // 0x198250: 0x10000010
label_198254:
    if (ctx->pc == 0x198254u) {
        ctx->pc = 0x198254u;
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
        ctx->pc = 0x198258u;
        goto label_198258;
    }
    ctx->pc = 0x198250u;
    {
        const bool branch_taken_0x198250 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x198254u;
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
        if (branch_taken_0x198250) {
            ctx->pc = 0x198294u;
            goto label_198294;
        }
    }
    ctx->pc = 0x198258u;
label_198258:
    // 0x198258: 0xfc500020
    ctx->pc = 0x198258u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
label_19825c:
    // 0x19825c: 0x24030042
    ctx->pc = 0x19825cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 66));
label_198260:
    // 0x198260: 0x1000000b
label_198264:
    if (ctx->pc == 0x198264u) {
        ctx->pc = 0x198264u;
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->pc = 0x198268u;
        goto label_198268;
    }
    ctx->pc = 0x198260u;
    {
        const bool branch_taken_0x198260 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x198264u;
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        if (branch_taken_0x198260) {
            ctx->pc = 0x198290u;
            goto label_198290;
        }
    }
    ctx->pc = 0x198268u;
label_198268:
    // 0x198268: 0xfc500020
    ctx->pc = 0x198268u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
label_19826c:
    // 0x19826c: 0x24030043
    ctx->pc = 0x19826cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 67));
label_198270:
    // 0x198270: 0x10000007
label_198274:
    if (ctx->pc == 0x198274u) {
        ctx->pc = 0x198274u;
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->pc = 0x198278u;
        goto label_198278;
    }
    ctx->pc = 0x198270u;
    {
        const bool branch_taken_0x198270 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x198274u;
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        if (branch_taken_0x198270) {
            ctx->pc = 0x198290u;
            goto label_198290;
        }
    }
    ctx->pc = 0x198278u;
label_198278:
    // 0x198278: 0xfc500020
    ctx->pc = 0x198278u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
label_19827c:
    // 0x19827c: 0x24030042
    ctx->pc = 0x19827cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 66));
label_198280:
    // 0x198280: 0xfc430028
    ctx->pc = 0x198280u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
label_198284:
    // 0x198284: 0x24030043
    ctx->pc = 0x198284u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 67));
label_198288:
    // 0x198288: 0xfc500030
    ctx->pc = 0x198288u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 48), GPR_U64(ctx, 16));
label_19828c:
    // 0x19828c: 0xfc430038
    ctx->pc = 0x19828cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 56), GPR_U64(ctx, 3));
label_198290:
    // 0x198290: 0x2293c
    ctx->pc = 0x198290u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
label_198294:
    // 0x198294: 0x3c07002a
    ctx->pc = 0x198294u;
    SET_GPR_U32(ctx, 7, ((uint32_t)42 << 16));
label_198298:
    // 0x198298: 0x5293e
    ctx->pc = 0x198298u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
label_19829c:
    // 0x19829c: 0x40302d
    ctx->pc = 0x19829cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1982a0:
    // 0x1982a0: 0x202d
    ctx->pc = 0x1982a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1982a4:
    // 0x1982a4: 0xc0633ec
label_1982a8:
    if (ctx->pc == 0x1982A8u) {
        ctx->pc = 0x1982A8u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->pc = 0x1982ACu;
        goto label_1982ac;
    }
    ctx->pc = 0x1982A4u;
    SET_GPR_U32(ctx, 31, 0x1982ACu);
    ctx->pc = 0x1982A8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
    ctx->pc = 0x18CFB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1982ACu; }
    }
    if (ctx->pc != 0x1982ACu) { return; }
    ctx->pc = 0x1982ACu;
label_1982ac:
    // 0x1982ac: 0x24020001
    ctx->pc = 0x1982acu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_1982b0:
    // 0x1982b0: 0xdfbf0030
    ctx->pc = 0x1982b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1982b4:
    // 0x1982b4: 0x7bb20020
    ctx->pc = 0x1982b4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
label_1982b8:
    // 0x1982b8: 0x7bb10010
    ctx->pc = 0x1982b8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_1982bc:
    // 0x1982bc: 0x7bb00000
    ctx->pc = 0x1982bcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_1982c0:
    // 0x1982c0: 0x3e00008
label_1982c4:
    if (ctx->pc == 0x1982C4u) {
        ctx->pc = 0x1982C4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x1982C8u;
        goto label_1982c8;
    }
    ctx->pc = 0x1982C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1982C4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x197BB0u: goto label_197bb0;
            case 0x197BB4u: goto label_197bb4;
            case 0x197BB8u: goto label_197bb8;
            case 0x197BBCu: goto label_197bbc;
            case 0x197BC0u: goto label_197bc0;
            case 0x197BC4u: goto label_197bc4;
            case 0x197BC8u: goto label_197bc8;
            case 0x197BCCu: goto label_197bcc;
            case 0x197BD0u: goto label_197bd0;
            case 0x197BD4u: goto label_197bd4;
            case 0x197BD8u: goto label_197bd8;
            case 0x197BDCu: goto label_197bdc;
            case 0x197BE0u: goto label_197be0;
            case 0x197BE4u: goto label_197be4;
            case 0x197BE8u: goto label_197be8;
            case 0x197BECu: goto label_197bec;
            case 0x197BF0u: goto label_197bf0;
            case 0x197BF4u: goto label_197bf4;
            case 0x197BF8u: goto label_197bf8;
            case 0x197BFCu: goto label_197bfc;
            case 0x197C00u: goto label_197c00;
            case 0x197C04u: goto label_197c04;
            case 0x197C08u: goto label_197c08;
            case 0x197C0Cu: goto label_197c0c;
            case 0x197C10u: goto label_197c10;
            case 0x197C14u: goto label_197c14;
            case 0x197C18u: goto label_197c18;
            case 0x197C1Cu: goto label_197c1c;
            case 0x197C20u: goto label_197c20;
            case 0x197C24u: goto label_197c24;
            case 0x197C28u: goto label_197c28;
            case 0x197C2Cu: goto label_197c2c;
            case 0x197C30u: goto label_197c30;
            case 0x197C34u: goto label_197c34;
            case 0x197C38u: goto label_197c38;
            case 0x197C3Cu: goto label_197c3c;
            case 0x197C40u: goto label_197c40;
            case 0x197C44u: goto label_197c44;
            case 0x197C48u: goto label_197c48;
            case 0x197C4Cu: goto label_197c4c;
            case 0x197C50u: goto label_197c50;
            case 0x197C54u: goto label_197c54;
            case 0x197C58u: goto label_197c58;
            case 0x197C5Cu: goto label_197c5c;
            case 0x197C60u: goto label_197c60;
            case 0x197C64u: goto label_197c64;
            case 0x197C68u: goto label_197c68;
            case 0x197C6Cu: goto label_197c6c;
            case 0x197C70u: goto label_197c70;
            case 0x197C74u: goto label_197c74;
            case 0x197C78u: goto label_197c78;
            case 0x197C7Cu: goto label_197c7c;
            case 0x197C80u: goto label_197c80;
            case 0x197C84u: goto label_197c84;
            case 0x197C88u: goto label_197c88;
            case 0x197C8Cu: goto label_197c8c;
            case 0x197C90u: goto label_197c90;
            case 0x197C94u: goto label_197c94;
            case 0x197C98u: goto label_197c98;
            case 0x197C9Cu: goto label_197c9c;
            case 0x197CA0u: goto label_197ca0;
            case 0x197CA4u: goto label_197ca4;
            case 0x197CA8u: goto label_197ca8;
            case 0x197CACu: goto label_197cac;
            case 0x197CB0u: goto label_197cb0;
            case 0x197CB4u: goto label_197cb4;
            case 0x197CB8u: goto label_197cb8;
            case 0x197CBCu: goto label_197cbc;
            case 0x197CC0u: goto label_197cc0;
            case 0x197CC4u: goto label_197cc4;
            case 0x197CC8u: goto label_197cc8;
            case 0x197CCCu: goto label_197ccc;
            case 0x197CD0u: goto label_197cd0;
            case 0x197CD4u: goto label_197cd4;
            case 0x197CD8u: goto label_197cd8;
            case 0x197CDCu: goto label_197cdc;
            case 0x197CE0u: goto label_197ce0;
            case 0x197CE4u: goto label_197ce4;
            case 0x197CE8u: goto label_197ce8;
            case 0x197CECu: goto label_197cec;
            case 0x197CF0u: goto label_197cf0;
            case 0x197CF4u: goto label_197cf4;
            case 0x197CF8u: goto label_197cf8;
            case 0x197CFCu: goto label_197cfc;
            case 0x197D00u: goto label_197d00;
            case 0x197D04u: goto label_197d04;
            case 0x197D08u: goto label_197d08;
            case 0x197D0Cu: goto label_197d0c;
            case 0x197D10u: goto label_197d10;
            case 0x197D14u: goto label_197d14;
            case 0x197D18u: goto label_197d18;
            case 0x197D1Cu: goto label_197d1c;
            case 0x197D20u: goto label_197d20;
            case 0x197D24u: goto label_197d24;
            case 0x197D28u: goto label_197d28;
            case 0x197D2Cu: goto label_197d2c;
            case 0x197D30u: goto label_197d30;
            case 0x197D34u: goto label_197d34;
            case 0x197D38u: goto label_197d38;
            case 0x197D3Cu: goto label_197d3c;
            case 0x197D40u: goto label_197d40;
            case 0x197D44u: goto label_197d44;
            case 0x197D48u: goto label_197d48;
            case 0x197D4Cu: goto label_197d4c;
            case 0x197D50u: goto label_197d50;
            case 0x197D54u: goto label_197d54;
            case 0x197D58u: goto label_197d58;
            case 0x197D5Cu: goto label_197d5c;
            case 0x197D60u: goto label_197d60;
            case 0x197D64u: goto label_197d64;
            case 0x197D68u: goto label_197d68;
            case 0x197D6Cu: goto label_197d6c;
            case 0x197D70u: goto label_197d70;
            case 0x197D74u: goto label_197d74;
            case 0x197D78u: goto label_197d78;
            case 0x197D7Cu: goto label_197d7c;
            case 0x197D80u: goto label_197d80;
            case 0x197D84u: goto label_197d84;
            case 0x197D88u: goto label_197d88;
            case 0x197D8Cu: goto label_197d8c;
            case 0x197D90u: goto label_197d90;
            case 0x197D94u: goto label_197d94;
            case 0x197D98u: goto label_197d98;
            case 0x197D9Cu: goto label_197d9c;
            case 0x197DA0u: goto label_197da0;
            case 0x197DA4u: goto label_197da4;
            case 0x197DA8u: goto label_197da8;
            case 0x197DACu: goto label_197dac;
            case 0x197DB0u: goto label_197db0;
            case 0x197DB4u: goto label_197db4;
            case 0x197DB8u: goto label_197db8;
            case 0x197DBCu: goto label_197dbc;
            case 0x197DC0u: goto label_197dc0;
            case 0x197DC4u: goto label_197dc4;
            case 0x197DC8u: goto label_197dc8;
            case 0x197DCCu: goto label_197dcc;
            case 0x197DD0u: goto label_197dd0;
            case 0x197DD4u: goto label_197dd4;
            case 0x197DD8u: goto label_197dd8;
            case 0x197DDCu: goto label_197ddc;
            case 0x197DE0u: goto label_197de0;
            case 0x197DE4u: goto label_197de4;
            case 0x197DE8u: goto label_197de8;
            case 0x197DECu: goto label_197dec;
            case 0x197DF0u: goto label_197df0;
            case 0x197DF4u: goto label_197df4;
            case 0x197DF8u: goto label_197df8;
            case 0x197DFCu: goto label_197dfc;
            case 0x197E00u: goto label_197e00;
            case 0x197E04u: goto label_197e04;
            case 0x197E08u: goto label_197e08;
            case 0x197E0Cu: goto label_197e0c;
            case 0x197E10u: goto label_197e10;
            case 0x197E14u: goto label_197e14;
            case 0x197E18u: goto label_197e18;
            case 0x197E1Cu: goto label_197e1c;
            case 0x197E20u: goto label_197e20;
            case 0x197E24u: goto label_197e24;
            case 0x197E28u: goto label_197e28;
            case 0x197E2Cu: goto label_197e2c;
            case 0x197E30u: goto label_197e30;
            case 0x197E34u: goto label_197e34;
            case 0x197E38u: goto label_197e38;
            case 0x197E3Cu: goto label_197e3c;
            case 0x197E40u: goto label_197e40;
            case 0x197E44u: goto label_197e44;
            case 0x197E48u: goto label_197e48;
            case 0x197E4Cu: goto label_197e4c;
            case 0x197E50u: goto label_197e50;
            case 0x197E54u: goto label_197e54;
            case 0x197E58u: goto label_197e58;
            case 0x197E5Cu: goto label_197e5c;
            case 0x197E60u: goto label_197e60;
            case 0x197E64u: goto label_197e64;
            case 0x197E68u: goto label_197e68;
            case 0x197E6Cu: goto label_197e6c;
            case 0x197E70u: goto label_197e70;
            case 0x197E74u: goto label_197e74;
            case 0x197E78u: goto label_197e78;
            case 0x197E7Cu: goto label_197e7c;
            case 0x197E80u: goto label_197e80;
            case 0x197E84u: goto label_197e84;
            case 0x197E88u: goto label_197e88;
            case 0x197E8Cu: goto label_197e8c;
            case 0x197E90u: goto label_197e90;
            case 0x197E94u: goto label_197e94;
            case 0x197E98u: goto label_197e98;
            case 0x197E9Cu: goto label_197e9c;
            case 0x197EA0u: goto label_197ea0;
            case 0x197EA4u: goto label_197ea4;
            case 0x197EA8u: goto label_197ea8;
            case 0x197EACu: goto label_197eac;
            case 0x197EB0u: goto label_197eb0;
            case 0x197EB4u: goto label_197eb4;
            case 0x197EB8u: goto label_197eb8;
            case 0x197EBCu: goto label_197ebc;
            case 0x197EC0u: goto label_197ec0;
            case 0x197EC4u: goto label_197ec4;
            case 0x197EC8u: goto label_197ec8;
            case 0x197ECCu: goto label_197ecc;
            case 0x197ED0u: goto label_197ed0;
            case 0x197ED4u: goto label_197ed4;
            case 0x197ED8u: goto label_197ed8;
            case 0x197EDCu: goto label_197edc;
            case 0x197EE0u: goto label_197ee0;
            case 0x197EE4u: goto label_197ee4;
            case 0x197EE8u: goto label_197ee8;
            case 0x197EECu: goto label_197eec;
            case 0x197EF0u: goto label_197ef0;
            case 0x197EF4u: goto label_197ef4;
            case 0x197EF8u: goto label_197ef8;
            case 0x197EFCu: goto label_197efc;
            case 0x197F00u: goto label_197f00;
            case 0x197F04u: goto label_197f04;
            case 0x197F08u: goto label_197f08;
            case 0x197F0Cu: goto label_197f0c;
            case 0x197F10u: goto label_197f10;
            case 0x197F14u: goto label_197f14;
            case 0x197F18u: goto label_197f18;
            case 0x197F1Cu: goto label_197f1c;
            case 0x197F20u: goto label_197f20;
            case 0x197F24u: goto label_197f24;
            case 0x197F28u: goto label_197f28;
            case 0x197F2Cu: goto label_197f2c;
            case 0x197F30u: goto label_197f30;
            case 0x197F34u: goto label_197f34;
            case 0x197F38u: goto label_197f38;
            case 0x197F3Cu: goto label_197f3c;
            case 0x197F40u: goto label_197f40;
            case 0x197F44u: goto label_197f44;
            case 0x197F48u: goto label_197f48;
            case 0x197F4Cu: goto label_197f4c;
            case 0x197F50u: goto label_197f50;
            case 0x197F54u: goto label_197f54;
            case 0x197F58u: goto label_197f58;
            case 0x197F5Cu: goto label_197f5c;
            case 0x197F60u: goto label_197f60;
            case 0x197F64u: goto label_197f64;
            case 0x197F68u: goto label_197f68;
            case 0x197F6Cu: goto label_197f6c;
            case 0x197F70u: goto label_197f70;
            case 0x197F74u: goto label_197f74;
            case 0x197F78u: goto label_197f78;
            case 0x197F7Cu: goto label_197f7c;
            case 0x197F80u: goto label_197f80;
            case 0x197F84u: goto label_197f84;
            case 0x197F88u: goto label_197f88;
            case 0x197F8Cu: goto label_197f8c;
            case 0x197F90u: goto label_197f90;
            case 0x197F94u: goto label_197f94;
            case 0x197F98u: goto label_197f98;
            case 0x197F9Cu: goto label_197f9c;
            case 0x197FA0u: goto label_197fa0;
            case 0x197FA4u: goto label_197fa4;
            case 0x197FA8u: goto label_197fa8;
            case 0x197FACu: goto label_197fac;
            case 0x197FB0u: goto label_197fb0;
            case 0x197FB4u: goto label_197fb4;
            case 0x197FB8u: goto label_197fb8;
            case 0x197FBCu: goto label_197fbc;
            case 0x197FC0u: goto label_197fc0;
            case 0x197FC4u: goto label_197fc4;
            case 0x197FC8u: goto label_197fc8;
            case 0x197FCCu: goto label_197fcc;
            case 0x197FD0u: goto label_197fd0;
            case 0x197FD4u: goto label_197fd4;
            case 0x197FD8u: goto label_197fd8;
            case 0x197FDCu: goto label_197fdc;
            case 0x197FE0u: goto label_197fe0;
            case 0x197FE4u: goto label_197fe4;
            case 0x197FE8u: goto label_197fe8;
            case 0x197FECu: goto label_197fec;
            case 0x197FF0u: goto label_197ff0;
            case 0x197FF4u: goto label_197ff4;
            case 0x197FF8u: goto label_197ff8;
            case 0x197FFCu: goto label_197ffc;
            case 0x198000u: goto label_198000;
            case 0x198004u: goto label_198004;
            case 0x198008u: goto label_198008;
            case 0x19800Cu: goto label_19800c;
            case 0x198010u: goto label_198010;
            case 0x198014u: goto label_198014;
            case 0x198018u: goto label_198018;
            case 0x19801Cu: goto label_19801c;
            case 0x198020u: goto label_198020;
            case 0x198024u: goto label_198024;
            case 0x198028u: goto label_198028;
            case 0x19802Cu: goto label_19802c;
            case 0x198030u: goto label_198030;
            case 0x198034u: goto label_198034;
            case 0x198038u: goto label_198038;
            case 0x19803Cu: goto label_19803c;
            case 0x198040u: goto label_198040;
            case 0x198044u: goto label_198044;
            case 0x198048u: goto label_198048;
            case 0x19804Cu: goto label_19804c;
            case 0x198050u: goto label_198050;
            case 0x198054u: goto label_198054;
            case 0x198058u: goto label_198058;
            case 0x19805Cu: goto label_19805c;
            case 0x198060u: goto label_198060;
            case 0x198064u: goto label_198064;
            case 0x198068u: goto label_198068;
            case 0x19806Cu: goto label_19806c;
            case 0x198070u: goto label_198070;
            case 0x198074u: goto label_198074;
            case 0x198078u: goto label_198078;
            case 0x19807Cu: goto label_19807c;
            case 0x198080u: goto label_198080;
            case 0x198084u: goto label_198084;
            case 0x198088u: goto label_198088;
            case 0x19808Cu: goto label_19808c;
            case 0x198090u: goto label_198090;
            case 0x198094u: goto label_198094;
            case 0x198098u: goto label_198098;
            case 0x19809Cu: goto label_19809c;
            case 0x1980A0u: goto label_1980a0;
            case 0x1980A4u: goto label_1980a4;
            case 0x1980A8u: goto label_1980a8;
            case 0x1980ACu: goto label_1980ac;
            case 0x1980B0u: goto label_1980b0;
            case 0x1980B4u: goto label_1980b4;
            case 0x1980B8u: goto label_1980b8;
            case 0x1980BCu: goto label_1980bc;
            case 0x1980C0u: goto label_1980c0;
            case 0x1980C4u: goto label_1980c4;
            case 0x1980C8u: goto label_1980c8;
            case 0x1980CCu: goto label_1980cc;
            case 0x1980D0u: goto label_1980d0;
            case 0x1980D4u: goto label_1980d4;
            case 0x1980D8u: goto label_1980d8;
            case 0x1980DCu: goto label_1980dc;
            case 0x1980E0u: goto label_1980e0;
            case 0x1980E4u: goto label_1980e4;
            case 0x1980E8u: goto label_1980e8;
            case 0x1980ECu: goto label_1980ec;
            case 0x1980F0u: goto label_1980f0;
            case 0x1980F4u: goto label_1980f4;
            case 0x1980F8u: goto label_1980f8;
            case 0x1980FCu: goto label_1980fc;
            case 0x198100u: goto label_198100;
            case 0x198104u: goto label_198104;
            case 0x198108u: goto label_198108;
            case 0x19810Cu: goto label_19810c;
            case 0x198110u: goto label_198110;
            case 0x198114u: goto label_198114;
            case 0x198118u: goto label_198118;
            case 0x19811Cu: goto label_19811c;
            case 0x198120u: goto label_198120;
            case 0x198124u: goto label_198124;
            case 0x198128u: goto label_198128;
            case 0x19812Cu: goto label_19812c;
            case 0x198130u: goto label_198130;
            case 0x198134u: goto label_198134;
            case 0x198138u: goto label_198138;
            case 0x19813Cu: goto label_19813c;
            case 0x198140u: goto label_198140;
            case 0x198144u: goto label_198144;
            case 0x198148u: goto label_198148;
            case 0x19814Cu: goto label_19814c;
            case 0x198150u: goto label_198150;
            case 0x198154u: goto label_198154;
            case 0x198158u: goto label_198158;
            case 0x19815Cu: goto label_19815c;
            case 0x198160u: goto label_198160;
            case 0x198164u: goto label_198164;
            case 0x198168u: goto label_198168;
            case 0x19816Cu: goto label_19816c;
            case 0x198170u: goto label_198170;
            case 0x198174u: goto label_198174;
            case 0x198178u: goto label_198178;
            case 0x19817Cu: goto label_19817c;
            case 0x198180u: goto label_198180;
            case 0x198184u: goto label_198184;
            case 0x198188u: goto label_198188;
            case 0x19818Cu: goto label_19818c;
            case 0x198190u: goto label_198190;
            case 0x198194u: goto label_198194;
            case 0x198198u: goto label_198198;
            case 0x19819Cu: goto label_19819c;
            case 0x1981A0u: goto label_1981a0;
            case 0x1981A4u: goto label_1981a4;
            case 0x1981A8u: goto label_1981a8;
            case 0x1981ACu: goto label_1981ac;
            case 0x1981B0u: goto label_1981b0;
            case 0x1981B4u: goto label_1981b4;
            case 0x1981B8u: goto label_1981b8;
            case 0x1981BCu: goto label_1981bc;
            case 0x1981C0u: goto label_1981c0;
            case 0x1981C4u: goto label_1981c4;
            case 0x1981C8u: goto label_1981c8;
            case 0x1981CCu: goto label_1981cc;
            case 0x1981D0u: goto label_1981d0;
            case 0x1981D4u: goto label_1981d4;
            case 0x1981D8u: goto label_1981d8;
            case 0x1981DCu: goto label_1981dc;
            case 0x1981E0u: goto label_1981e0;
            case 0x1981E4u: goto label_1981e4;
            case 0x1981E8u: goto label_1981e8;
            case 0x1981ECu: goto label_1981ec;
            case 0x1981F0u: goto label_1981f0;
            case 0x1981F4u: goto label_1981f4;
            case 0x1981F8u: goto label_1981f8;
            case 0x1981FCu: goto label_1981fc;
            case 0x198200u: goto label_198200;
            case 0x198204u: goto label_198204;
            case 0x198208u: goto label_198208;
            case 0x19820Cu: goto label_19820c;
            case 0x198210u: goto label_198210;
            case 0x198214u: goto label_198214;
            case 0x198218u: goto label_198218;
            case 0x19821Cu: goto label_19821c;
            case 0x198220u: goto label_198220;
            case 0x198224u: goto label_198224;
            case 0x198228u: goto label_198228;
            case 0x19822Cu: goto label_19822c;
            case 0x198230u: goto label_198230;
            case 0x198234u: goto label_198234;
            case 0x198238u: goto label_198238;
            case 0x19823Cu: goto label_19823c;
            case 0x198240u: goto label_198240;
            case 0x198244u: goto label_198244;
            case 0x198248u: goto label_198248;
            case 0x19824Cu: goto label_19824c;
            case 0x198250u: goto label_198250;
            case 0x198254u: goto label_198254;
            case 0x198258u: goto label_198258;
            case 0x19825Cu: goto label_19825c;
            case 0x198260u: goto label_198260;
            case 0x198264u: goto label_198264;
            case 0x198268u: goto label_198268;
            case 0x19826Cu: goto label_19826c;
            case 0x198270u: goto label_198270;
            case 0x198274u: goto label_198274;
            case 0x198278u: goto label_198278;
            case 0x19827Cu: goto label_19827c;
            case 0x198280u: goto label_198280;
            case 0x198284u: goto label_198284;
            case 0x198288u: goto label_198288;
            case 0x19828Cu: goto label_19828c;
            case 0x198290u: goto label_198290;
            case 0x198294u: goto label_198294;
            case 0x198298u: goto label_198298;
            case 0x19829Cu: goto label_19829c;
            case 0x1982A0u: goto label_1982a0;
            case 0x1982A4u: goto label_1982a4;
            case 0x1982A8u: goto label_1982a8;
            case 0x1982ACu: goto label_1982ac;
            case 0x1982B0u: goto label_1982b0;
            case 0x1982B4u: goto label_1982b4;
            case 0x1982B8u: goto label_1982b8;
            case 0x1982BCu: goto label_1982bc;
            case 0x1982C0u: goto label_1982c0;
            case 0x1982C4u: goto label_1982c4;
            case 0x1982C8u: goto label_1982c8;
            case 0x1982CCu: goto label_1982cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1982C8u;
label_1982c8:
    // 0x1982c8: 0x0
    ctx->pc = 0x1982c8u;
    // NOP
label_1982cc:
    // 0x1982cc: 0x0
    ctx->pc = 0x1982ccu;
    // NOP
}
