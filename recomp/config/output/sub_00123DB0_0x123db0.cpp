#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00123DB0
// Address: 0x123db0 - 0x124518
void sub_00123DB0_0x123db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x123db0u;

label_123db0:
    // 0x123db0: 0x27bdffb0
    ctx->pc = 0x123db0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
label_123db4:
    // 0x123db4: 0x28a20008
    ctx->pc = 0x123db4u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), 8));
label_123db8:
    // 0x123db8: 0xffb00010
    ctx->pc = 0x123db8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
label_123dbc:
    // 0x123dbc: 0x80802d
    ctx->pc = 0x123dbcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_123dc0:
    // 0x123dc0: 0xffb10018
    ctx->pc = 0x123dc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
label_123dc4:
    // 0x123dc4: 0xc0882d
    ctx->pc = 0x123dc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_123dc8:
    // 0x123dc8: 0xffb20020
    ctx->pc = 0x123dc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
label_123dcc:
    // 0x123dcc: 0x140902d
    ctx->pc = 0x123dccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
label_123dd0:
    // 0x123dd0: 0xffb30028
    ctx->pc = 0x123dd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
label_123dd4:
    // 0x123dd4: 0x160982d
    ctx->pc = 0x123dd4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
label_123dd8:
    // 0x123dd8: 0xffb40030
    ctx->pc = 0x123dd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
label_123ddc:
    // 0x123ddc: 0x100a02d
    ctx->pc = 0x123ddcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_123de0:
    // 0x123de0: 0xffb50038
    ctx->pc = 0x123de0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
label_123de4:
    // 0x123de4: 0xe0a82d
    ctx->pc = 0x123de4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_123de8:
    // 0x123de8: 0xffb60040
    ctx->pc = 0x123de8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
label_123dec:
    // 0x123dec: 0x120b02d
    ctx->pc = 0x123decu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
label_123df0:
    // 0x123df0: 0xffbf0048
    ctx->pc = 0x123df0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
label_123df4:
    // 0x123df4: 0x3a0302d
    ctx->pc = 0x123df4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_123df8:
    // 0x123df8: 0x27a80008
    ctx->pc = 0x123df8u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 29), 8));
label_123dfc:
    // 0x123dfc: 0x27a70004
    ctx->pc = 0x123dfcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 4));
label_123e00:
    // 0x123e00: 0x27a9000c
    ctx->pc = 0x123e00u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 29), 12));
label_123e04:
    // 0x123e04: 0x10400004
label_123e08:
    if (ctx->pc == 0x123E08u) {
        ctx->pc = 0x123E08u;
        SET_GPR_U32(ctx, 10, READ32(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->pc = 0x123E0Cu;
        goto label_123e0c;
    }
    ctx->pc = 0x123E04u;
    {
        const bool branch_taken_0x123e04 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x123E08u;
        SET_GPR_U32(ctx, 10, READ32(ADD32(GPR_U32(ctx, 29), 96)));
        if (branch_taken_0x123e04) {
            ctx->pc = 0x123E18u;
            goto label_123e18;
        }
    }
    ctx->pc = 0x123E0Cu;
label_123e0c:
    // 0x123e0c: 0xa6200000
    ctx->pc = 0x123e0cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
label_123e10:
    // 0x123e10: 0x10000021
label_123e14:
    if (ctx->pc == 0x123E14u) {
        ctx->pc = 0x123E14u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x123E18u;
        goto label_123e18;
    }
    ctx->pc = 0x123E10u;
    {
        const bool branch_taken_0x123e10 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x123E14u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x123e10) {
            ctx->pc = 0x123E98u;
            goto label_123e98;
        }
    }
    ctx->pc = 0x123E18u;
label_123e18:
    // 0x123e18: 0xc048e90
label_123e1c:
    if (ctx->pc == 0x123E1Cu) {
        ctx->pc = 0x123E20u;
        goto label_123e20;
    }
    ctx->pc = 0x123E18u;
    SET_GPR_U32(ctx, 31, 0x123E20u);
    ctx->pc = 0x123A40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00123A40_0x123a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123E20u; }
    }
    if (ctx->pc != 0x123E20u) { return; }
    ctx->pc = 0x123E20u;
label_123e20:
    // 0x123e20: 0x40182d
    ctx->pc = 0x123e20u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_123e24:
    // 0x123e24: 0x2402ffff
    ctx->pc = 0x123e24u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_123e28:
    // 0x123e28: 0x1060001b
label_123e2c:
    if (ctx->pc == 0x123E2Cu) {
        ctx->pc = 0x123E2Cu;
        SET_GPR_U32(ctx, 4, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
        ctx->pc = 0x123E30u;
        goto label_123e30;
    }
    ctx->pc = 0x123E28u;
    {
        const bool branch_taken_0x123e28 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x123E2Cu;
        SET_GPR_U32(ctx, 4, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
        if (branch_taken_0x123e28) {
            ctx->pc = 0x123E98u;
            goto label_123e98;
        }
    }
    ctx->pc = 0x123E30u;
label_123e30:
    // 0x123e30: 0x41c00
    ctx->pc = 0x123e30u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 4), 16));
label_123e34:
    // 0x123e34: 0x18600018
label_123e38:
    if (ctx->pc == 0x123E38u) {
        ctx->pc = 0x123E38u;
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->pc = 0x123E3Cu;
        goto label_123e3c;
    }
    ctx->pc = 0x123E34u;
    {
        const bool branch_taken_0x123e34 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x123E38u;
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 4));
        if (branch_taken_0x123e34) {
            ctx->pc = 0x123E98u;
            goto label_123e98;
        }
    }
    ctx->pc = 0x123E3Cu;
label_123e3c:
    // 0x123e3c: 0x8fa60000
    ctx->pc = 0x123e3cu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_123e40:
    // 0x123e40: 0x2407ffff
    ctx->pc = 0x123e40u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 4294967295));
label_123e44:
    // 0x123e44: 0x93a30004
    ctx->pc = 0x123e44u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 4)));
label_123e48:
    // 0x123e48: 0x24080001
    ctx->pc = 0x123e48u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 1));
label_123e4c:
    // 0x123e4c: 0x93a40008
    ctx->pc = 0x123e4cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 8)));
label_123e50:
    // 0x123e50: 0x102d
    ctx->pc = 0x123e50u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_123e54:
    // 0x123e54: 0xae660000
    ctx->pc = 0x123e54u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 6));
label_123e58:
    // 0x123e58: 0x8fa5000c
    ctx->pc = 0x123e58u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 12)));
label_123e5c:
    // 0x123e5c: 0xa2430000
    ctx->pc = 0x123e5cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
label_123e60:
    // 0x123e60: 0xa2840000
    ctx->pc = 0x123e60u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 4));
label_123e64:
    // 0x123e64: 0x8fa30050
    ctx->pc = 0x123e64u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 80)));
label_123e68:
    // 0x123e68: 0xac650000
    ctx->pc = 0x123e68u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
label_123e6c:
    // 0x123e6c: 0xa2a70000
    ctx->pc = 0x123e6cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 7));
label_123e70:
    // 0x123e70: 0x82840000
    ctx->pc = 0x123e70u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
label_123e74:
    // 0x123e74: 0x82430000
    ctx->pc = 0x123e74u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
label_123e78:
    // 0x123e78: 0x641818
    ctx->pc = 0x123e78u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
label_123e7c:
    // 0x123e7c: 0x28640000
    ctx->pc = 0x123e7cu;
    SET_GPR_U32(ctx, 4, SLT32(GPR_S32(ctx, 3), 0));
label_123e80:
    // 0x123e80: 0x24650007
    ctx->pc = 0x123e80u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 3), 7));
label_123e84:
    // 0x123e84: 0xa4180b
    ctx->pc = 0x123e84u;
    if (GPR_U32(ctx, 4) != 0) SET_GPR_U32(ctx, 3, GPR_U32(ctx, 5));
label_123e88:
    // 0x123e88: 0x318c3
    ctx->pc = 0x123e88u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 3));
label_123e8c:
    // 0x123e8c: 0xa2c30000
    ctx->pc = 0x123e8cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
label_123e90:
    // 0x123e90: 0x8fa40058
    ctx->pc = 0x123e90u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 88)));
label_123e94:
    // 0x123e94: 0xac880000
    ctx->pc = 0x123e94u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 8));
label_123e98:
    // 0x123e98: 0xdfb00010
    ctx->pc = 0x123e98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_123e9c:
    // 0x123e9c: 0xdfb10018
    ctx->pc = 0x123e9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_123ea0:
    // 0x123ea0: 0xdfb20020
    ctx->pc = 0x123ea0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_123ea4:
    // 0x123ea4: 0xdfb30028
    ctx->pc = 0x123ea4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_123ea8:
    // 0x123ea8: 0xdfb40030
    ctx->pc = 0x123ea8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_123eac:
    // 0x123eac: 0xdfb50038
    ctx->pc = 0x123eacu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
label_123eb0:
    // 0x123eb0: 0xdfb60040
    ctx->pc = 0x123eb0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_123eb4:
    // 0x123eb4: 0xdfbf0048
    ctx->pc = 0x123eb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
label_123eb8:
    // 0x123eb8: 0x3e00008
label_123ebc:
    if (ctx->pc == 0x123EBCu) {
        ctx->pc = 0x123EBCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = 0x123EC0u;
        goto label_123ec0;
    }
    ctx->pc = 0x123EB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123EBCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123EC0u;
label_123ec0:
    // 0x123ec0: 0x27bdffa0
    ctx->pc = 0x123ec0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
label_123ec4:
    // 0x123ec4: 0x24020001
    ctx->pc = 0x123ec4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_123ec8:
    // 0x123ec8: 0xffb00030
    ctx->pc = 0x123ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
label_123ecc:
    // 0x123ecc: 0x80802d
    ctx->pc = 0x123eccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_123ed0:
    // 0x123ed0: 0xffb10038
    ctx->pc = 0x123ed0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
label_123ed4:
    // 0x123ed4: 0x2611000e
    ctx->pc = 0x123ed4u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 14));
label_123ed8:
    // 0x123ed8: 0xffb20040
    ctx->pc = 0x123ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
label_123edc:
    // 0x123edc: 0x26120010
    ctx->pc = 0x123edcu;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 16), 16));
label_123ee0:
    // 0x123ee0: 0xffb30048
    ctx->pc = 0x123ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
label_123ee4:
    // 0x123ee4: 0x2613000f
    ctx->pc = 0x123ee4u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 16), 15));
label_123ee8:
    // 0x123ee8: 0xffbf0050
    ctx->pc = 0x123ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
label_123eec:
    // 0x123eec: 0xa0202d
    ctx->pc = 0x123eecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_123ef0:
    // 0x123ef0: 0xa6020002
    ctx->pc = 0x123ef0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
label_123ef4:
    // 0x123ef4: 0x26020018
    ctx->pc = 0x123ef4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 24));
label_123ef8:
    // 0x123ef8: 0xc0282d
    ctx->pc = 0x123ef8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_123efc:
    // 0x123efc: 0x27a60020
    ctx->pc = 0x123efcu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 29), 32));
label_123f00:
    // 0x123f00: 0x27a30024
    ctx->pc = 0x123f00u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 29), 36));
label_123f04:
    // 0x123f04: 0x2607000c
    ctx->pc = 0x123f04u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 12));
label_123f08:
    // 0x123f08: 0x2608000d
    ctx->pc = 0x123f08u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 16), 13));
label_123f0c:
    // 0x123f0c: 0x260482d
    ctx->pc = 0x123f0cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_123f10:
    // 0x123f10: 0x220502d
    ctx->pc = 0x123f10u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_123f14:
    // 0x123f14: 0x260b0014
    ctx->pc = 0x123f14u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 16), 20));
label_123f18:
    // 0x123f18: 0xafa20000
    ctx->pc = 0x123f18u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
label_123f1c:
    // 0x123f1c: 0xafa30010
    ctx->pc = 0x123f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
label_123f20:
    // 0x123f20: 0xc048f6c
label_123f24:
    if (ctx->pc == 0x123F24u) {
        ctx->pc = 0x123F24u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
        ctx->pc = 0x123F28u;
        goto label_123f28;
    }
    ctx->pc = 0x123F20u;
    SET_GPR_U32(ctx, 31, 0x123F28u);
    ctx->pc = 0x123F24u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
    ctx->pc = 0x123DB0u;
    goto label_123db0;
    ctx->pc = 0x123F28u;
label_123f28:
    // 0x123f28: 0x4430003
label_123f2c:
    if (ctx->pc == 0x123F2Cu) {
        ctx->pc = 0x123F2Cu;
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
        ctx->pc = 0x123F30u;
        goto label_123f30;
    }
    ctx->pc = 0x123F28u;
    {
        const bool branch_taken_0x123f28 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x123f28) {
            ctx->pc = 0x123F2Cu;
            WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
            ctx->pc = 0x123F38u;
            goto label_123f38;
        }
    }
    ctx->pc = 0x123F30u;
label_123f30:
    // 0x123f30: 0x1000001b
label_123f34:
    if (ctx->pc == 0x123F34u) {
        ctx->pc = 0x123F34u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x123F38u;
        goto label_123f38;
    }
    ctx->pc = 0x123F30u;
    {
        const bool branch_taken_0x123f30 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x123F34u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x123f30) {
            ctx->pc = 0x123FA0u;
            goto label_123fa0;
        }
    }
    ctx->pc = 0x123F38u;
label_123f38:
    // 0x123f38: 0xae000030
    ctx->pc = 0x123f38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
label_123f3c:
    // 0x123f3c: 0xae00002c
    ctx->pc = 0x123f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
label_123f40:
    // 0x123f40: 0xae000028
    ctx->pc = 0x123f40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
label_123f44:
    // 0x123f44: 0xae000020
    ctx->pc = 0x123f44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
label_123f48:
    // 0x123f48: 0xa600001c
    ctx->pc = 0x123f48u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
label_123f4c:
    // 0x123f4c: 0xa6000026
    ctx->pc = 0x123f4cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
label_123f50:
    // 0x123f50: 0xa6000024
    ctx->pc = 0x123f50u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
label_123f54:
    // 0x123f54: 0x8e05003c
    ctx->pc = 0x123f54u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 60)));
label_123f58:
    // 0x123f58: 0x82220000
    ctx->pc = 0x123f58u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_123f5c:
    // 0x123f5c: 0x97a40024
    ctx->pc = 0x123f5cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 36)));
label_123f60:
    // 0x123f60: 0xae020050
    ctx->pc = 0x123f60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 2));
label_123f64:
    // 0x123f64: 0x8e060040
    ctx->pc = 0x123f64u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 64)));
label_123f68:
    // 0x123f68: 0x82630000
    ctx->pc = 0x123f68u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
label_123f6c:
    // 0x123f6c: 0x87a20020
    ctx->pc = 0x123f6cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
label_123f70:
    // 0x123f70: 0xae030054
    ctx->pc = 0x123f70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
label_123f74:
    // 0x123f74: 0x24030004
    ctx->pc = 0x123f74u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4));
label_123f78:
    // 0x123f78: 0x8e070044
    ctx->pc = 0x123f78u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 16), 68)));
label_123f7c:
    // 0x123f7c: 0xa604009a
    ctx->pc = 0x123f7cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 154), (uint16_t)GPR_U32(ctx, 4));
label_123f80:
    // 0x123f80: 0x8e440000
    ctx->pc = 0x123f80u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_123f84:
    // 0x123f84: 0xae05005c
    ctx->pc = 0x123f84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 5));
label_123f88:
    // 0x123f88: 0xa6030098
    ctx->pc = 0x123f88u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 3));
label_123f8c:
    // 0x123f8c: 0xae040058
    ctx->pc = 0x123f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 4));
label_123f90:
    // 0x123f90: 0xae060060
    ctx->pc = 0x123f90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 6));
label_123f94:
    // 0x123f94: 0xae070064
    ctx->pc = 0x123f94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 7));
label_123f98:
    // 0x123f98: 0xae00008c
    ctx->pc = 0x123f98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
label_123f9c:
    // 0x123f9c: 0xae000088
    ctx->pc = 0x123f9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
label_123fa0:
    // 0x123fa0: 0xdfb00030
    ctx->pc = 0x123fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_123fa4:
    // 0x123fa4: 0xdfb10038
    ctx->pc = 0x123fa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
label_123fa8:
    // 0x123fa8: 0xdfb20040
    ctx->pc = 0x123fa8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_123fac:
    // 0x123fac: 0xdfb30048
    ctx->pc = 0x123facu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
label_123fb0:
    // 0x123fb0: 0xdfbf0050
    ctx->pc = 0x123fb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_123fb4:
    // 0x123fb4: 0x3e00008
label_123fb8:
    if (ctx->pc == 0x123FB8u) {
        ctx->pc = 0x123FB8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = 0x123FBCu;
        goto label_123fbc;
    }
    ctx->pc = 0x123FB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123FB8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123FBCu;
label_123fbc:
    // 0x123fbc: 0x0
    ctx->pc = 0x123fbcu;
    // NOP
label_123fc0:
    // 0x123fc0: 0x27bdffe0
    ctx->pc = 0x123fc0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_123fc4:
    // 0x123fc4: 0x24020001
    ctx->pc = 0x123fc4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_123fc8:
    // 0x123fc8: 0xffb00000
    ctx->pc = 0x123fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_123fcc:
    // 0x123fcc: 0x80802d
    ctx->pc = 0x123fccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_123fd0:
    // 0x123fd0: 0xffb10008
    ctx->pc = 0x123fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_123fd4:
    // 0x123fd4: 0x26110048
    ctx->pc = 0x123fd4u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 72));
label_123fd8:
    // 0x123fd8: 0xffb20010
    ctx->pc = 0x123fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_123fdc:
    // 0x123fdc: 0xffbf0018
    ctx->pc = 0x123fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_123fe0:
    // 0x123fe0: 0x8e030004
    ctx->pc = 0x123fe0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_123fe4:
    // 0x123fe4: 0x1462004c
label_123fe8:
    if (ctx->pc == 0x123FE8u) {
        ctx->pc = 0x123FE8u;
        SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->pc = 0x123FECu;
        goto label_123fec;
    }
    ctx->pc = 0x123FE4u;
    {
        const bool branch_taken_0x123fe4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x123FE8u;
        SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 17), 0)));
        if (branch_taken_0x123fe4) {
            ctx->pc = 0x124118u;
            goto label_124118;
        }
    }
    ctx->pc = 0x123FECu;
label_123fec:
    // 0x123fec: 0xc04d3e6
label_123ff0:
    if (ctx->pc == 0x123FF0u) {
        ctx->pc = 0x123FF0u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->pc = 0x123FF4u;
        goto label_123ff4;
    }
    ctx->pc = 0x123FECu;
    SET_GPR_U32(ctx, 31, 0x123FF4u);
    ctx->pc = 0x123FF0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    ctx->pc = 0x134F98u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123FF4u; }
    }
    if (ctx->pc != 0x123FF4u) { return; }
    ctx->pc = 0x123FF4u;
label_123ff4:
    // 0x123ff4: 0x54400048
label_123ff8:
    if (ctx->pc == 0x123FF8u) {
        ctx->pc = 0x123FF8u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->pc = 0x123FFCu;
        goto label_123ffc;
    }
    ctx->pc = 0x123FF4u;
    {
        const bool branch_taken_0x123ff4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x123ff4) {
            ctx->pc = 0x123FF8u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
            ctx->pc = 0x124118u;
            goto label_124118;
        }
    }
    ctx->pc = 0x123FFCu;
label_123ffc:
    // 0x123ffc: 0x8e04007c
    ctx->pc = 0x123ffcu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 124)));
label_124000:
    // 0x124000: 0x26050068
    ctx->pc = 0x124000u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 104));
label_124004:
    // 0x124004: 0x8e020078
    ctx->pc = 0x124004u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 120)));
label_124008:
    // 0x124008: 0x2606006c
    ctx->pc = 0x124008u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 108));
label_12400c:
    // 0x12400c: 0x40f809
label_124010:
    if (ctx->pc == 0x124010u) {
        ctx->pc = 0x124010u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 112));
        ctx->pc = 0x124014u;
        goto label_124014;
    }
    ctx->pc = 0x12400Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x124014u);
        ctx->pc = 0x124010u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124014u; }
            if (ctx->pc != 0x124014u) { return; }
        }
    }
    ctx->pc = 0x124014u;
label_124014:
    // 0x124014: 0x8e240018
    ctx->pc = 0x124014u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 24)));
label_124018:
    // 0x124018: 0x8e270020
    ctx->pc = 0x124018u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 17), 32)));
label_12401c:
    // 0x12401c: 0x24060002
    ctx->pc = 0x12401cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
label_124020:
    // 0x124020: 0x8e230024
    ctx->pc = 0x124020u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 36)));
label_124024:
    // 0x124024: 0x874823
    ctx->pc = 0x124024u;
    SET_GPR_U32(ctx, 9, SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
label_124028:
    // 0x124028: 0x8204000e
    ctx->pc = 0x124028u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_12402c:
    // 0x12402c: 0x69102a
    ctx->pc = 0x12402cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 9)));
label_124030:
    // 0x124030: 0x8e250004
    ctx->pc = 0x124030u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_124034:
    // 0x124034: 0x62480b
    ctx->pc = 0x124034u;
    if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 9, GPR_U32(ctx, 3));
label_124038:
    // 0x124038: 0x71840
    ctx->pc = 0x124038u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 7), 1));
label_12403c:
    // 0x12403c: 0x8e2b0014
    ctx->pc = 0x12403cu;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_124040:
    // 0x124040: 0xa9102a
    ctx->pc = 0x124040u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 9)));
label_124044:
    // 0x124044: 0xa2480b
    ctx->pc = 0x124044u;
    if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 9, GPR_U32(ctx, 5));
label_124048:
    // 0x124048: 0x1635021
    ctx->pc = 0x124048u;
    SET_GPR_U32(ctx, 10, ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
label_12404c:
    // 0x12404c: 0x1486001c
label_124050:
    if (ctx->pc == 0x124050u) {
        ctx->pc = 0x124050u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->pc = 0x124054u;
        goto label_124054;
    }
    ctx->pc = 0x12404Cu;
    {
        const bool branch_taken_0x12404c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 6));
        ctx->pc = 0x124050u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        if (branch_taken_0x12404c) {
            ctx->pc = 0x1240C0u;
            goto label_1240c0;
        }
    }
    ctx->pc = 0x124054u;
label_124054:
    // 0x124054: 0x8e22001c
    ctx->pc = 0x124054u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 28)));
label_124058:
    // 0x124058: 0x402d
    ctx->pc = 0x124058u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12405c:
    // 0x12405c: 0x471021
    ctx->pc = 0x12405cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
label_124060:
    // 0x124060: 0x21040
    ctx->pc = 0x124060u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 1));
label_124064:
    // 0x124064: 0x19200024
label_124068:
    if (ctx->pc == 0x124068u) {
        ctx->pc = 0x124068u;
        SET_GPR_U32(ctx, 11, ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->pc = 0x12406Cu;
        goto label_12406c;
    }
    ctx->pc = 0x124064u;
    {
        const bool branch_taken_0x124064 = (GPR_S32(ctx, 9) <= 0);
        ctx->pc = 0x124068u;
        SET_GPR_U32(ctx, 11, ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        if (branch_taken_0x124064) {
            ctx->pc = 0x1240F8u;
            goto label_1240f8;
        }
    }
    ctx->pc = 0x12406Cu;
label_12406c:
    // 0x12406c: 0x240382d
    ctx->pc = 0x12406cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_124070:
    // 0x124070: 0x94e20000
    ctx->pc = 0x124070u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
label_124074:
    // 0x124074: 0x82040
    ctx->pc = 0x124074u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 8), 1));
label_124078:
    // 0x124078: 0x8a2821
    ctx->pc = 0x124078u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
label_12407c:
    // 0x12407c: 0x8b2021
    ctx->pc = 0x12407cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
label_124080:
    // 0x124080: 0x21a00
    ctx->pc = 0x124080u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 8));
label_124084:
    // 0x124084: 0x21202
    ctx->pc = 0x124084u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
label_124088:
    // 0x124088: 0x431025
    ctx->pc = 0x124088u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_12408c:
    // 0x12408c: 0x25080001
    ctx->pc = 0x12408cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
label_124090:
    // 0x124090: 0xa4a20000
    ctx->pc = 0x124090u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
label_124094:
    // 0x124094: 0x109302a
    ctx->pc = 0x124094u;
    SET_GPR_U32(ctx, 6, SLT32(GPR_S32(ctx, 8), GPR_S32(ctx, 9)));
label_124098:
    // 0x124098: 0x94e20002
    ctx->pc = 0x124098u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
label_12409c:
    // 0x12409c: 0x24e70004
    ctx->pc = 0x12409cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4));
label_1240a0:
    // 0x1240a0: 0x21a00
    ctx->pc = 0x1240a0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 8));
label_1240a4:
    // 0x1240a4: 0x21202
    ctx->pc = 0x1240a4u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
label_1240a8:
    // 0x1240a8: 0x431025
    ctx->pc = 0x1240a8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1240ac:
    // 0x1240ac: 0x14c0fff0
label_1240b0:
    if (ctx->pc == 0x1240B0u) {
        ctx->pc = 0x1240B0u;
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x1240B4u;
        goto label_1240b4;
    }
    ctx->pc = 0x1240ACu;
    {
        const bool branch_taken_0x1240ac = (GPR_U32(ctx, 6) != GPR_U32(ctx, 0));
        ctx->pc = 0x1240B0u;
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        if (branch_taken_0x1240ac) {
            ctx->pc = 0x124070u;
            goto label_124070;
        }
    }
    ctx->pc = 0x1240B4u;
label_1240b4:
    // 0x1240b4: 0x10000010
label_1240b8:
    if (ctx->pc == 0x1240B8u) {
        ctx->pc = 0x1240B8u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->pc = 0x1240BCu;
        goto label_1240bc;
    }
    ctx->pc = 0x1240B4u;
    {
        const bool branch_taken_0x1240b4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1240B8u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        if (branch_taken_0x1240b4) {
            ctx->pc = 0x1240F8u;
            goto label_1240f8;
        }
    }
    ctx->pc = 0x1240BCu;
label_1240bc:
    // 0x1240bc: 0x0
    ctx->pc = 0x1240bcu;
    // NOP
label_1240c0:
    // 0x1240c0: 0x1920000d
label_1240c4:
    if (ctx->pc == 0x1240C4u) {
        ctx->pc = 0x1240C4u;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1240C8u;
        goto label_1240c8;
    }
    ctx->pc = 0x1240C0u;
    {
        const bool branch_taken_0x1240c0 = (GPR_S32(ctx, 9) <= 0);
        ctx->pc = 0x1240C4u;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1240c0) {
            ctx->pc = 0x1240F8u;
            goto label_1240f8;
        }
    }
    ctx->pc = 0x1240C8u;
label_1240c8:
    // 0x1240c8: 0x82040
    ctx->pc = 0x1240c8u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 8), 1));
label_1240cc:
    // 0x1240cc: 0x25080001
    ctx->pc = 0x1240ccu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
label_1240d0:
    // 0x1240d0: 0x921021
    ctx->pc = 0x1240d0u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
label_1240d4:
    // 0x1240d4: 0x8a2021
    ctx->pc = 0x1240d4u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
label_1240d8:
    // 0x1240d8: 0x94420000
    ctx->pc = 0x1240d8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_1240dc:
    // 0x1240dc: 0x109282a
    ctx->pc = 0x1240dcu;
    SET_GPR_U32(ctx, 5, SLT32(GPR_S32(ctx, 8), GPR_S32(ctx, 9)));
label_1240e0:
    // 0x1240e0: 0x21a00
    ctx->pc = 0x1240e0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 8));
label_1240e4:
    // 0x1240e4: 0x21202
    ctx->pc = 0x1240e4u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
label_1240e8:
    // 0x1240e8: 0x431025
    ctx->pc = 0x1240e8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1240ec:
    // 0x1240ec: 0x14a0fff6
label_1240f0:
    if (ctx->pc == 0x1240F0u) {
        ctx->pc = 0x1240F0u;
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x1240F4u;
        goto label_1240f4;
    }
    ctx->pc = 0x1240ECu;
    {
        const bool branch_taken_0x1240ec = (GPR_U32(ctx, 5) != GPR_U32(ctx, 0));
        ctx->pc = 0x1240F0u;
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        if (branch_taken_0x1240ec) {
            ctx->pc = 0x1240C8u;
            goto label_1240c8;
        }
    }
    ctx->pc = 0x1240F4u;
label_1240f4:
    // 0x1240f4: 0x9203000e
    ctx->pc = 0x1240f4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_1240f8:
    // 0x1240f8: 0x31600
    ctx->pc = 0x1240f8u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 3), 24));
label_1240fc:
    // 0x1240fc: 0x24030002
    ctx->pc = 0x1240fcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_124100:
    // 0x124100: 0x21603
    ctx->pc = 0x124100u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
label_124104:
    // 0x124104: 0xae030004
    ctx->pc = 0x124104u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
label_124108:
    // 0x124108: 0x1221018
    ctx->pc = 0x124108u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
label_12410c:
    // 0x12410c: 0xae090090
    ctx->pc = 0x12410cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
label_124110:
    // 0x124110: 0x21040
    ctx->pc = 0x124110u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 1));
label_124114:
    // 0x124114: 0xae020094
    ctx->pc = 0x124114u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_124118:
    // 0x124118: 0x24020002
    ctx->pc = 0x124118u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
label_12411c:
    // 0x12411c: 0x54620009
label_124120:
    if (ctx->pc == 0x124120u) {
        ctx->pc = 0x124120u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x124124u;
        goto label_124124;
    }
    ctx->pc = 0x12411Cu;
    {
        const bool branch_taken_0x12411c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x12411c) {
            ctx->pc = 0x124120u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x124144u;
            goto label_124144;
        }
    }
    ctx->pc = 0x124124u;
label_124124:
    // 0x124124: 0x8e030080
    ctx->pc = 0x124124u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 128)));
label_124128:
    // 0x124128: 0x8e040084
    ctx->pc = 0x124128u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 132)));
label_12412c:
    // 0x12412c: 0x8e050094
    ctx->pc = 0x12412cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 148)));
label_124130:
    // 0x124130: 0x60f809
label_124134:
    if (ctx->pc == 0x124134u) {
        ctx->pc = 0x124134u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->pc = 0x124138u;
        goto label_124138;
    }
    ctx->pc = 0x124130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x124138u);
        ctx->pc = 0x124134u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124138u; }
            if (ctx->pc != 0x124138u) { return; }
        }
    }
    ctx->pc = 0x124138u;
label_124138:
    // 0x124138: 0x24020003
    ctx->pc = 0x124138u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
label_12413c:
    // 0x12413c: 0xae020004
    ctx->pc = 0x12413cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
label_124140:
    // 0x124140: 0xdfb00000
    ctx->pc = 0x124140u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_124144:
    // 0x124144: 0xdfb10008
    ctx->pc = 0x124144u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_124148:
    // 0x124148: 0xdfb20010
    ctx->pc = 0x124148u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_12414c:
    // 0x12414c: 0xdfbf0018
    ctx->pc = 0x12414cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_124150:
    // 0x124150: 0x3e00008
label_124154:
    if (ctx->pc == 0x124154u) {
        ctx->pc = 0x124154u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x124158u;
        goto label_124158;
    }
    ctx->pc = 0x124150u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124154u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124158u;
label_124158:
    // 0x124158: 0x27bdffe0
    ctx->pc = 0x124158u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_12415c:
    // 0x12415c: 0x24020001
    ctx->pc = 0x12415cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_124160:
    // 0x124160: 0xffb00000
    ctx->pc = 0x124160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_124164:
    // 0x124164: 0x80802d
    ctx->pc = 0x124164u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_124168:
    // 0x124168: 0xffb10008
    ctx->pc = 0x124168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_12416c:
    // 0x12416c: 0x26110048
    ctx->pc = 0x12416cu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 72));
label_124170:
    // 0x124170: 0xffb20010
    ctx->pc = 0x124170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_124174:
    // 0x124174: 0xffbf0018
    ctx->pc = 0x124174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_124178:
    // 0x124178: 0x8e030004
    ctx->pc = 0x124178u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_12417c:
    // 0x12417c: 0x14620046
label_124180:
    if (ctx->pc == 0x124180u) {
        ctx->pc = 0x124180u;
        SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->pc = 0x124184u;
        goto label_124184;
    }
    ctx->pc = 0x12417Cu;
    {
        const bool branch_taken_0x12417c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x124180u;
        SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 17), 0)));
        if (branch_taken_0x12417c) {
            ctx->pc = 0x124298u;
            goto label_124298;
        }
    }
    ctx->pc = 0x124184u;
label_124184:
    // 0x124184: 0xc04d3e6
label_124188:
    if (ctx->pc == 0x124188u) {
        ctx->pc = 0x124188u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->pc = 0x12418Cu;
        goto label_12418c;
    }
    ctx->pc = 0x124184u;
    SET_GPR_U32(ctx, 31, 0x12418Cu);
    ctx->pc = 0x124188u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    ctx->pc = 0x134F98u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12418Cu; }
    }
    if (ctx->pc != 0x12418Cu) { return; }
    ctx->pc = 0x12418Cu;
label_12418c:
    // 0x12418c: 0x54400042
label_124190:
    if (ctx->pc == 0x124190u) {
        ctx->pc = 0x124190u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->pc = 0x124194u;
        goto label_124194;
    }
    ctx->pc = 0x12418Cu;
    {
        const bool branch_taken_0x12418c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x12418c) {
            ctx->pc = 0x124190u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
            ctx->pc = 0x124298u;
            goto label_124298;
        }
    }
    ctx->pc = 0x124194u;
label_124194:
    // 0x124194: 0x8e04007c
    ctx->pc = 0x124194u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 124)));
label_124198:
    // 0x124198: 0x26050068
    ctx->pc = 0x124198u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 104));
label_12419c:
    // 0x12419c: 0x8e020078
    ctx->pc = 0x12419cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 120)));
label_1241a0:
    // 0x1241a0: 0x2606006c
    ctx->pc = 0x1241a0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 108));
label_1241a4:
    // 0x1241a4: 0x40f809
label_1241a8:
    if (ctx->pc == 0x1241A8u) {
        ctx->pc = 0x1241A8u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 112));
        ctx->pc = 0x1241ACu;
        goto label_1241ac;
    }
    ctx->pc = 0x1241A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1241ACu);
        ctx->pc = 0x1241A8u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1241ACu; }
            if (ctx->pc != 0x1241ACu) { return; }
        }
    }
    ctx->pc = 0x1241ACu;
label_1241ac:
    // 0x1241ac: 0x8e240018
    ctx->pc = 0x1241acu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 24)));
label_1241b0:
    // 0x1241b0: 0x8e290020
    ctx->pc = 0x1241b0u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 17), 32)));
label_1241b4:
    // 0x1241b4: 0x24060002
    ctx->pc = 0x1241b4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
label_1241b8:
    // 0x1241b8: 0x8e230024
    ctx->pc = 0x1241b8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 36)));
label_1241bc:
    // 0x1241bc: 0x894023
    ctx->pc = 0x1241bcu;
    SET_GPR_U32(ctx, 8, SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
label_1241c0:
    // 0x1241c0: 0x8204000e
    ctx->pc = 0x1241c0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_1241c4:
    // 0x1241c4: 0x68102a
    ctx->pc = 0x1241c4u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 8)));
label_1241c8:
    // 0x1241c8: 0x8e250004
    ctx->pc = 0x1241c8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_1241cc:
    // 0x1241cc: 0x62400b
    ctx->pc = 0x1241ccu;
    if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 8, GPR_U32(ctx, 3));
label_1241d0:
    // 0x1241d0: 0x91840
    ctx->pc = 0x1241d0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 9), 1));
label_1241d4:
    // 0x1241d4: 0x8e2b0014
    ctx->pc = 0x1241d4u;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_1241d8:
    // 0x1241d8: 0xa8102a
    ctx->pc = 0x1241d8u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 8)));
label_1241dc:
    // 0x1241dc: 0xa2400b
    ctx->pc = 0x1241dcu;
    if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 8, GPR_U32(ctx, 5));
label_1241e0:
    // 0x1241e0: 0x1635021
    ctx->pc = 0x1241e0u;
    SET_GPR_U32(ctx, 10, ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
label_1241e4:
    // 0x1241e4: 0x14860018
label_1241e8:
    if (ctx->pc == 0x1241E8u) {
        ctx->pc = 0x1241E8u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->pc = 0x1241ECu;
        goto label_1241ec;
    }
    ctx->pc = 0x1241E4u;
    {
        const bool branch_taken_0x1241e4 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 6));
        ctx->pc = 0x1241E8u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        if (branch_taken_0x1241e4) {
            ctx->pc = 0x124248u;
            goto label_124248;
        }
    }
    ctx->pc = 0x1241ECu;
label_1241ec:
    // 0x1241ec: 0x8e22001c
    ctx->pc = 0x1241ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 28)));
label_1241f0:
    // 0x1241f0: 0x382d
    ctx->pc = 0x1241f0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1241f4:
    // 0x1241f4: 0x491021
    ctx->pc = 0x1241f4u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
label_1241f8:
    // 0x1241f8: 0x21040
    ctx->pc = 0x1241f8u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 1));
label_1241fc:
    // 0x1241fc: 0x1900001f
label_124200:
    if (ctx->pc == 0x124200u) {
        ctx->pc = 0x124200u;
        SET_GPR_U32(ctx, 9, ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->pc = 0x124204u;
        goto label_124204;
    }
    ctx->pc = 0x1241FCu;
    {
        const bool branch_taken_0x1241fc = (GPR_S32(ctx, 8) <= 0);
        ctx->pc = 0x124200u;
        SET_GPR_U32(ctx, 9, ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        if (branch_taken_0x1241fc) {
            ctx->pc = 0x12427Cu;
            goto label_12427c;
        }
    }
    ctx->pc = 0x124204u;
label_124204:
    // 0x124204: 0x240302d
    ctx->pc = 0x124204u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_124208:
    // 0x124208: 0x90c20000
    ctx->pc = 0x124208u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
label_12420c:
    // 0x12420c: 0x71840
    ctx->pc = 0x12420cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 7), 1));
label_124210:
    // 0x124210: 0x6a2021
    ctx->pc = 0x124210u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
label_124214:
    // 0x124214: 0x691821
    ctx->pc = 0x124214u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
label_124218:
    // 0x124218: 0x21200
    ctx->pc = 0x124218u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 8));
label_12421c:
    // 0x12421c: 0x24e70001
    ctx->pc = 0x12421cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 1));
label_124220:
    // 0x124220: 0xa4820000
    ctx->pc = 0x124220u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_124224:
    // 0x124224: 0xe8282a
    ctx->pc = 0x124224u;
    SET_GPR_U32(ctx, 5, SLT32(GPR_S32(ctx, 7), GPR_S32(ctx, 8)));
label_124228:
    // 0x124228: 0x90c20001
    ctx->pc = 0x124228u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
label_12422c:
    // 0x12422c: 0x24c60002
    ctx->pc = 0x12422cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 2));
label_124230:
    // 0x124230: 0x21200
    ctx->pc = 0x124230u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 8));
label_124234:
    // 0x124234: 0x14a0fff4
label_124238:
    if (ctx->pc == 0x124238u) {
        ctx->pc = 0x124238u;
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x12423Cu;
        goto label_12423c;
    }
    ctx->pc = 0x124234u;
    {
        const bool branch_taken_0x124234 = (GPR_U32(ctx, 5) != GPR_U32(ctx, 0));
        ctx->pc = 0x124238u;
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        if (branch_taken_0x124234) {
            ctx->pc = 0x124208u;
            goto label_124208;
        }
    }
    ctx->pc = 0x12423Cu;
label_12423c:
    // 0x12423c: 0x1000000f
label_124240:
    if (ctx->pc == 0x124240u) {
        ctx->pc = 0x124240u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->pc = 0x124244u;
        goto label_124244;
    }
    ctx->pc = 0x12423Cu;
    {
        const bool branch_taken_0x12423c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x124240u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        if (branch_taken_0x12423c) {
            ctx->pc = 0x12427Cu;
            goto label_12427c;
        }
    }
    ctx->pc = 0x124244u;
label_124244:
    // 0x124244: 0x0
    ctx->pc = 0x124244u;
    // NOP
label_124248:
    // 0x124248: 0x1900000c
label_12424c:
    if (ctx->pc == 0x12424Cu) {
        ctx->pc = 0x12424Cu;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x124250u;
        goto label_124250;
    }
    ctx->pc = 0x124248u;
    {
        const bool branch_taken_0x124248 = (GPR_S32(ctx, 8) <= 0);
        ctx->pc = 0x12424Cu;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x124248) {
            ctx->pc = 0x12427Cu;
            goto label_12427c;
        }
    }
    ctx->pc = 0x124250u;
label_124250:
    // 0x124250: 0x140282d
    ctx->pc = 0x124250u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
label_124254:
    // 0x124254: 0x0
    ctx->pc = 0x124254u;
    // NOP
label_124258:
    // 0x124258: 0x2471021
    ctx->pc = 0x124258u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 7)));
label_12425c:
    // 0x12425c: 0x24e70001
    ctx->pc = 0x12425cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 1));
label_124260:
    // 0x124260: 0x90430000
    ctx->pc = 0x124260u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
label_124264:
    // 0x124264: 0xe8202a
    ctx->pc = 0x124264u;
    SET_GPR_U32(ctx, 4, SLT32(GPR_S32(ctx, 7), GPR_S32(ctx, 8)));
label_124268:
    // 0x124268: 0x31a00
    ctx->pc = 0x124268u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 8));
label_12426c:
    // 0x12426c: 0xa4a30000
    ctx->pc = 0x12426cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
label_124270:
    // 0x124270: 0x1480fff9
label_124274:
    if (ctx->pc == 0x124274u) {
        ctx->pc = 0x124274u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 2));
        ctx->pc = 0x124278u;
        goto label_124278;
    }
    ctx->pc = 0x124270u;
    {
        const bool branch_taken_0x124270 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x124274u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 2));
        if (branch_taken_0x124270) {
            ctx->pc = 0x124258u;
            goto label_124258;
        }
    }
    ctx->pc = 0x124278u;
label_124278:
    // 0x124278: 0x9203000e
    ctx->pc = 0x124278u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_12427c:
    // 0x12427c: 0x31600
    ctx->pc = 0x12427cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 3), 24));
label_124280:
    // 0x124280: 0x24030002
    ctx->pc = 0x124280u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_124284:
    // 0x124284: 0x21603
    ctx->pc = 0x124284u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
label_124288:
    // 0x124288: 0xae030004
    ctx->pc = 0x124288u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
label_12428c:
    // 0x12428c: 0x1021018
    ctx->pc = 0x12428cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
label_124290:
    // 0x124290: 0xae080090
    ctx->pc = 0x124290u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 8));
label_124294:
    // 0x124294: 0xae020094
    ctx->pc = 0x124294u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_124298:
    // 0x124298: 0x24020002
    ctx->pc = 0x124298u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
label_12429c:
    // 0x12429c: 0x54620009
label_1242a0:
    if (ctx->pc == 0x1242A0u) {
        ctx->pc = 0x1242A0u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x1242A4u;
        goto label_1242a4;
    }
    ctx->pc = 0x12429Cu;
    {
        const bool branch_taken_0x12429c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x12429c) {
            ctx->pc = 0x1242A0u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x1242C4u;
            goto label_1242c4;
        }
    }
    ctx->pc = 0x1242A4u;
label_1242a4:
    // 0x1242a4: 0x8e030080
    ctx->pc = 0x1242a4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 128)));
label_1242a8:
    // 0x1242a8: 0x8e040084
    ctx->pc = 0x1242a8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 132)));
label_1242ac:
    // 0x1242ac: 0x8e050094
    ctx->pc = 0x1242acu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 148)));
label_1242b0:
    // 0x1242b0: 0x60f809
label_1242b4:
    if (ctx->pc == 0x1242B4u) {
        ctx->pc = 0x1242B4u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->pc = 0x1242B8u;
        goto label_1242b8;
    }
    ctx->pc = 0x1242B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1242B8u);
        ctx->pc = 0x1242B4u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1242B8u; }
            if (ctx->pc != 0x1242B8u) { return; }
        }
    }
    ctx->pc = 0x1242B8u;
label_1242b8:
    // 0x1242b8: 0x24020003
    ctx->pc = 0x1242b8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
label_1242bc:
    // 0x1242bc: 0xae020004
    ctx->pc = 0x1242bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
label_1242c0:
    // 0x1242c0: 0xdfb00000
    ctx->pc = 0x1242c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1242c4:
    // 0x1242c4: 0xdfb10008
    ctx->pc = 0x1242c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_1242c8:
    // 0x1242c8: 0xdfb20010
    ctx->pc = 0x1242c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1242cc:
    // 0x1242cc: 0xdfbf0018
    ctx->pc = 0x1242ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_1242d0:
    // 0x1242d0: 0x3e00008
label_1242d4:
    if (ctx->pc == 0x1242D4u) {
        ctx->pc = 0x1242D4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x1242D8u;
        goto label_1242d8;
    }
    ctx->pc = 0x1242D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1242D4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1242D8u;
label_1242d8:
    // 0x1242d8: 0x27bdffe0
    ctx->pc = 0x1242d8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_1242dc:
    // 0x1242dc: 0x24020001
    ctx->pc = 0x1242dcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_1242e0:
    // 0x1242e0: 0xffb00000
    ctx->pc = 0x1242e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_1242e4:
    // 0x1242e4: 0x80802d
    ctx->pc = 0x1242e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1242e8:
    // 0x1242e8: 0xffb10008
    ctx->pc = 0x1242e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_1242ec:
    // 0x1242ec: 0x26110048
    ctx->pc = 0x1242ecu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 72));
label_1242f0:
    // 0x1242f0: 0xffb20010
    ctx->pc = 0x1242f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_1242f4:
    // 0x1242f4: 0xffbf0018
    ctx->pc = 0x1242f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_1242f8:
    // 0x1242f8: 0x8e030004
    ctx->pc = 0x1242f8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_1242fc:
    // 0x1242fc: 0x14620050
label_124300:
    if (ctx->pc == 0x124300u) {
        ctx->pc = 0x124300u;
        SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->pc = 0x124304u;
        goto label_124304;
    }
    ctx->pc = 0x1242FCu;
    {
        const bool branch_taken_0x1242fc = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x124300u;
        SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 17), 0)));
        if (branch_taken_0x1242fc) {
            ctx->pc = 0x124440u;
            goto label_124440;
        }
    }
    ctx->pc = 0x124304u;
label_124304:
    // 0x124304: 0xc04d3e6
label_124308:
    if (ctx->pc == 0x124308u) {
        ctx->pc = 0x124308u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->pc = 0x12430Cu;
        goto label_12430c;
    }
    ctx->pc = 0x124304u;
    SET_GPR_U32(ctx, 31, 0x12430Cu);
    ctx->pc = 0x124308u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    ctx->pc = 0x134F98u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12430Cu; }
    }
    if (ctx->pc != 0x12430Cu) { return; }
    ctx->pc = 0x12430Cu;
label_12430c:
    // 0x12430c: 0x5440004c
label_124310:
    if (ctx->pc == 0x124310u) {
        ctx->pc = 0x124310u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->pc = 0x124314u;
        goto label_124314;
    }
    ctx->pc = 0x12430Cu;
    {
        const bool branch_taken_0x12430c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x12430c) {
            ctx->pc = 0x124310u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
            ctx->pc = 0x124440u;
            goto label_124440;
        }
    }
    ctx->pc = 0x124314u;
label_124314:
    // 0x124314: 0x8e04007c
    ctx->pc = 0x124314u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 124)));
label_124318:
    // 0x124318: 0x26050068
    ctx->pc = 0x124318u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 104));
label_12431c:
    // 0x12431c: 0x8e020078
    ctx->pc = 0x12431cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 120)));
label_124320:
    // 0x124320: 0x2606006c
    ctx->pc = 0x124320u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 108));
label_124324:
    // 0x124324: 0x40f809
label_124328:
    if (ctx->pc == 0x124328u) {
        ctx->pc = 0x124328u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 112));
        ctx->pc = 0x12432Cu;
        goto label_12432c;
    }
    ctx->pc = 0x124324u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12432Cu);
        ctx->pc = 0x124328u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12432Cu; }
            if (ctx->pc != 0x12432Cu) { return; }
        }
    }
    ctx->pc = 0x12432Cu;
label_12432c:
    // 0x12432c: 0x8e240018
    ctx->pc = 0x12432cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 24)));
label_124330:
    // 0x124330: 0x8e270020
    ctx->pc = 0x124330u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 17), 32)));
label_124334:
    // 0x124334: 0x24060002
    ctx->pc = 0x124334u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
label_124338:
    // 0x124338: 0x8e230024
    ctx->pc = 0x124338u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 36)));
label_12433c:
    // 0x12433c: 0x874823
    ctx->pc = 0x12433cu;
    SET_GPR_U32(ctx, 9, SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
label_124340:
    // 0x124340: 0x8204000e
    ctx->pc = 0x124340u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_124344:
    // 0x124344: 0x69102a
    ctx->pc = 0x124344u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 9)));
label_124348:
    // 0x124348: 0x8e250004
    ctx->pc = 0x124348u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_12434c:
    // 0x12434c: 0x62480b
    ctx->pc = 0x12434cu;
    if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 9, GPR_U32(ctx, 3));
label_124350:
    // 0x124350: 0x71840
    ctx->pc = 0x124350u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 7), 1));
label_124354:
    // 0x124354: 0x8e2a0014
    ctx->pc = 0x124354u;
    SET_GPR_U32(ctx, 10, READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_124358:
    // 0x124358: 0xa9102a
    ctx->pc = 0x124358u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 9)));
label_12435c:
    // 0x12435c: 0xa2480b
    ctx->pc = 0x12435cu;
    if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 9, GPR_U32(ctx, 5));
label_124360:
    // 0x124360: 0x1435821
    ctx->pc = 0x124360u;
    SET_GPR_U32(ctx, 11, ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
label_124364:
    // 0x124364: 0x1486001e
label_124368:
    if (ctx->pc == 0x124368u) {
        ctx->pc = 0x124368u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->pc = 0x12436Cu;
        goto label_12436c;
    }
    ctx->pc = 0x124364u;
    {
        const bool branch_taken_0x124364 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 6));
        ctx->pc = 0x124368u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        if (branch_taken_0x124364) {
            ctx->pc = 0x1243E0u;
            goto label_1243e0;
        }
    }
    ctx->pc = 0x12436Cu;
label_12436c:
    // 0x12436c: 0x8e22001c
    ctx->pc = 0x12436cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 28)));
label_124370:
    // 0x124370: 0x402d
    ctx->pc = 0x124370u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_124374:
    // 0x124374: 0x471021
    ctx->pc = 0x124374u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
label_124378:
    // 0x124378: 0x21040
    ctx->pc = 0x124378u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 1));
label_12437c:
    // 0x12437c: 0x19200029
label_124380:
    if (ctx->pc == 0x124380u) {
        ctx->pc = 0x124380u;
        SET_GPR_U32(ctx, 12, ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
        ctx->pc = 0x124384u;
        goto label_124384;
    }
    ctx->pc = 0x12437Cu;
    {
        const bool branch_taken_0x12437c = (GPR_S32(ctx, 9) <= 0);
        ctx->pc = 0x124380u;
        SET_GPR_U32(ctx, 12, ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
        if (branch_taken_0x12437c) {
            ctx->pc = 0x124424u;
            goto label_124424;
        }
    }
    ctx->pc = 0x124384u;
label_124384:
    // 0x124384: 0x3c020021
    ctx->pc = 0x124384u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
label_124388:
    // 0x124388: 0x240382d
    ctx->pc = 0x124388u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_12438c:
    // 0x12438c: 0x244ab738
    ctx->pc = 0x12438cu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 2), 4294948664));
label_124390:
    // 0x124390: 0x90e20000
    ctx->pc = 0x124390u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
label_124394:
    // 0x124394: 0x82040
    ctx->pc = 0x124394u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 8), 1));
label_124398:
    // 0x124398: 0x8b2821
    ctx->pc = 0x124398u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
label_12439c:
    // 0x12439c: 0x8c2021
    ctx->pc = 0x12439cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
label_1243a0:
    // 0x1243a0: 0x21040
    ctx->pc = 0x1243a0u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 1));
label_1243a4:
    // 0x1243a4: 0x25080001
    ctx->pc = 0x1243a4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
label_1243a8:
    // 0x1243a8: 0x4a1021
    ctx->pc = 0x1243a8u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
label_1243ac:
    // 0x1243ac: 0x109302a
    ctx->pc = 0x1243acu;
    SET_GPR_U32(ctx, 6, SLT32(GPR_S32(ctx, 8), GPR_S32(ctx, 9)));
label_1243b0:
    // 0x1243b0: 0x94430000
    ctx->pc = 0x1243b0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_1243b4:
    // 0x1243b4: 0xa4a30000
    ctx->pc = 0x1243b4u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
label_1243b8:
    // 0x1243b8: 0x90e20001
    ctx->pc = 0x1243b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
label_1243bc:
    // 0x1243bc: 0x24e70002
    ctx->pc = 0x1243bcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 2));
label_1243c0:
    // 0x1243c0: 0x21040
    ctx->pc = 0x1243c0u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 1));
label_1243c4:
    // 0x1243c4: 0x4a1021
    ctx->pc = 0x1243c4u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
label_1243c8:
    // 0x1243c8: 0x94430000
    ctx->pc = 0x1243c8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_1243cc:
    // 0x1243cc: 0x14c0fff0
label_1243d0:
    if (ctx->pc == 0x1243D0u) {
        ctx->pc = 0x1243D0u;
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->pc = 0x1243D4u;
        goto label_1243d4;
    }
    ctx->pc = 0x1243CCu;
    {
        const bool branch_taken_0x1243cc = (GPR_U32(ctx, 6) != GPR_U32(ctx, 0));
        ctx->pc = 0x1243D0u;
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
        if (branch_taken_0x1243cc) {
            ctx->pc = 0x124390u;
            goto label_124390;
        }
    }
    ctx->pc = 0x1243D4u;
label_1243d4:
    // 0x1243d4: 0x10000013
label_1243d8:
    if (ctx->pc == 0x1243D8u) {
        ctx->pc = 0x1243D8u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->pc = 0x1243DCu;
        goto label_1243dc;
    }
    ctx->pc = 0x1243D4u;
    {
        const bool branch_taken_0x1243d4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1243D8u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        if (branch_taken_0x1243d4) {
            ctx->pc = 0x124424u;
            goto label_124424;
        }
    }
    ctx->pc = 0x1243DCu;
label_1243dc:
    // 0x1243dc: 0x0
    ctx->pc = 0x1243dcu;
    // NOP
label_1243e0:
    // 0x1243e0: 0x19200010
label_1243e4:
    if (ctx->pc == 0x1243E4u) {
        ctx->pc = 0x1243E4u;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1243E8u;
        goto label_1243e8;
    }
    ctx->pc = 0x1243E0u;
    {
        const bool branch_taken_0x1243e0 = (GPR_S32(ctx, 9) <= 0);
        ctx->pc = 0x1243E4u;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1243e0) {
            ctx->pc = 0x124424u;
            goto label_124424;
        }
    }
    ctx->pc = 0x1243E8u;
label_1243e8:
    // 0x1243e8: 0x3c020021
    ctx->pc = 0x1243e8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
label_1243ec:
    // 0x1243ec: 0x160282d
    ctx->pc = 0x1243ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
label_1243f0:
    // 0x1243f0: 0x2446b738
    ctx->pc = 0x1243f0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 4294948664));
label_1243f4:
    // 0x1243f4: 0x0
    ctx->pc = 0x1243f4u;
    // NOP
label_1243f8:
    // 0x1243f8: 0x2481821
    ctx->pc = 0x1243f8u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
label_1243fc:
    // 0x1243fc: 0x25080001
    ctx->pc = 0x1243fcu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
label_124400:
    // 0x124400: 0x90620000
    ctx->pc = 0x124400u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
label_124404:
    // 0x124404: 0x109202a
    ctx->pc = 0x124404u;
    SET_GPR_U32(ctx, 4, SLT32(GPR_S32(ctx, 8), GPR_S32(ctx, 9)));
label_124408:
    // 0x124408: 0x21040
    ctx->pc = 0x124408u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 1));
label_12440c:
    // 0x12440c: 0x461021
    ctx->pc = 0x12440cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_124410:
    // 0x124410: 0x94430000
    ctx->pc = 0x124410u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_124414:
    // 0x124414: 0xa4a30000
    ctx->pc = 0x124414u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
label_124418:
    // 0x124418: 0x1480fff7
label_12441c:
    if (ctx->pc == 0x12441Cu) {
        ctx->pc = 0x12441Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 2));
        ctx->pc = 0x124420u;
        goto label_124420;
    }
    ctx->pc = 0x124418u;
    {
        const bool branch_taken_0x124418 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x12441Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 2));
        if (branch_taken_0x124418) {
            ctx->pc = 0x1243F8u;
            goto label_1243f8;
        }
    }
    ctx->pc = 0x124420u;
label_124420:
    // 0x124420: 0x9203000e
    ctx->pc = 0x124420u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_124424:
    // 0x124424: 0x31600
    ctx->pc = 0x124424u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 3), 24));
label_124428:
    // 0x124428: 0x24030002
    ctx->pc = 0x124428u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_12442c:
    // 0x12442c: 0x21603
    ctx->pc = 0x12442cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
label_124430:
    // 0x124430: 0xae030004
    ctx->pc = 0x124430u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
label_124434:
    // 0x124434: 0x1221018
    ctx->pc = 0x124434u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
label_124438:
    // 0x124438: 0xae090090
    ctx->pc = 0x124438u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
label_12443c:
    // 0x12443c: 0xae020094
    ctx->pc = 0x12443cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_124440:
    // 0x124440: 0x24020002
    ctx->pc = 0x124440u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
label_124444:
    // 0x124444: 0x54620009
label_124448:
    if (ctx->pc == 0x124448u) {
        ctx->pc = 0x124448u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x12444Cu;
        goto label_12444c;
    }
    ctx->pc = 0x124444u;
    {
        const bool branch_taken_0x124444 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x124444) {
            ctx->pc = 0x124448u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x12446Cu;
            goto label_12446c;
        }
    }
    ctx->pc = 0x12444Cu;
label_12444c:
    // 0x12444c: 0x8e030080
    ctx->pc = 0x12444cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 128)));
label_124450:
    // 0x124450: 0x8e040084
    ctx->pc = 0x124450u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 132)));
label_124454:
    // 0x124454: 0x8e050094
    ctx->pc = 0x124454u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 148)));
label_124458:
    // 0x124458: 0x60f809
label_12445c:
    if (ctx->pc == 0x12445Cu) {
        ctx->pc = 0x12445Cu;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->pc = 0x124460u;
        goto label_124460;
    }
    ctx->pc = 0x124458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x124460u);
        ctx->pc = 0x12445Cu;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124460u; }
            if (ctx->pc != 0x124460u) { return; }
        }
    }
    ctx->pc = 0x124460u;
label_124460:
    // 0x124460: 0x24020003
    ctx->pc = 0x124460u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
label_124464:
    // 0x124464: 0xae020004
    ctx->pc = 0x124464u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
label_124468:
    // 0x124468: 0xdfb00000
    ctx->pc = 0x124468u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12446c:
    // 0x12446c: 0xdfb10008
    ctx->pc = 0x12446cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_124470:
    // 0x124470: 0xdfb20010
    ctx->pc = 0x124470u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_124474:
    // 0x124474: 0xdfbf0018
    ctx->pc = 0x124474u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_124478:
    // 0x124478: 0x3e00008
label_12447c:
    if (ctx->pc == 0x12447Cu) {
        ctx->pc = 0x12447Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x124480u;
        goto label_124480;
    }
    ctx->pc = 0x124478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12447Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124480u;
label_124480:
    // 0x124480: 0x27bdfff0
    ctx->pc = 0x124480u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
label_124484:
    // 0x124484: 0x24020002
    ctx->pc = 0x124484u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
label_124488:
    // 0x124488: 0xffbf0000
    ctx->pc = 0x124488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
label_12448c:
    // 0x12448c: 0x8483009a
    ctx->pc = 0x12448cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 154)));
label_124490:
    // 0x124490: 0x14620005
label_124494:
    if (ctx->pc == 0x124494u) {
        ctx->pc = 0x124494u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x124498u;
        goto label_124498;
    }
    ctx->pc = 0x124490u;
    {
        const bool branch_taken_0x124490 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x124494u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x124490) {
            ctx->pc = 0x1244A8u;
            goto label_1244a8;
        }
    }
    ctx->pc = 0x124498u;
label_124498:
    // 0x124498: 0xdfbf0000
    ctx->pc = 0x124498u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12449c:
    // 0x12449c: 0x80490b6
label_1244a0:
    if (ctx->pc == 0x1244A0u) {
        ctx->pc = 0x1244A0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x1244A4u;
        goto label_1244a4;
    }
    ctx->pc = 0x12449Cu;
    ctx->pc = 0x1244A0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1242D8u;
    goto label_1242d8;
    ctx->pc = 0x1244A4u;
label_1244a4:
    // 0x1244a4: 0x0
    ctx->pc = 0x1244a4u;
    // NOP
label_1244a8:
    // 0x1244a8: 0x14620003
label_1244ac:
    if (ctx->pc == 0x1244ACu) {
        ctx->pc = 0x1244ACu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x1244B0u;
        goto label_1244b0;
    }
    ctx->pc = 0x1244A8u;
    {
        const bool branch_taken_0x1244a8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x1244ACu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x1244a8) {
            ctx->pc = 0x1244B8u;
            goto label_1244b8;
        }
    }
    ctx->pc = 0x1244B0u;
label_1244b0:
    // 0x1244b0: 0x8049056
label_1244b4:
    if (ctx->pc == 0x1244B4u) {
        ctx->pc = 0x1244B4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x1244B8u;
        goto label_1244b8;
    }
    ctx->pc = 0x1244B0u;
    ctx->pc = 0x1244B4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x124158u;
    goto label_124158;
    ctx->pc = 0x1244B8u;
label_1244b8:
    // 0x1244b8: 0x8048ff0
label_1244bc:
    if (ctx->pc == 0x1244BCu) {
        ctx->pc = 0x1244BCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x1244C0u;
        goto label_1244c0;
    }
    ctx->pc = 0x1244B8u;
    ctx->pc = 0x1244BCu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x123FC0u;
    goto label_123fc0;
    ctx->pc = 0x1244C0u;
label_1244c0:
    // 0x1244c0: 0x3e00008
label_1244c4:
    if (ctx->pc == 0x1244C4u) {
        ctx->pc = 0x1244C4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1244C8u;
        goto label_1244c8;
    }
    ctx->pc = 0x1244C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1244C4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1244C8u;
label_1244c8:
    // 0x1244c8: 0x3c020021
    ctx->pc = 0x1244c8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
label_1244cc:
    // 0x1244cc: 0x3c030021
    ctx->pc = 0x1244ccu;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
label_1244d0:
    // 0x1244d0: 0xac44b940
    ctx->pc = 0x1244d0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294949184), GPR_U32(ctx, 4));
label_1244d4:
    // 0x1244d4: 0x102d
    ctx->pc = 0x1244d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1244d8:
    // 0x1244d8: 0x3e00008
label_1244dc:
    if (ctx->pc == 0x1244DCu) {
        ctx->pc = 0x1244DCu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949188), GPR_U32(ctx, 5));
        ctx->pc = 0x1244E0u;
        goto label_1244e0;
    }
    ctx->pc = 0x1244D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1244DCu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949188), GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1244E0u;
label_1244e0:
    // 0x1244e0: 0x3c020021
    ctx->pc = 0x1244e0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
label_1244e4:
    // 0x1244e4: 0x27bdfff0
    ctx->pc = 0x1244e4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
label_1244e8:
    // 0x1244e8: 0x8c43b940
    ctx->pc = 0x1244e8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4294949184)));
label_1244ec:
    // 0x1244ec: 0x80282d
    ctx->pc = 0x1244ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1244f0:
    // 0x1244f0: 0x10600004
label_1244f4:
    if (ctx->pc == 0x1244F4u) {
        ctx->pc = 0x1244F4u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->pc = 0x1244F8u;
        goto label_1244f8;
    }
    ctx->pc = 0x1244F0u;
    {
        const bool branch_taken_0x1244f0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x1244F4u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x1244f0) {
            ctx->pc = 0x124504u;
            goto label_124504;
        }
    }
    ctx->pc = 0x1244F8u;
label_1244f8:
    // 0x1244f8: 0x3c020021
    ctx->pc = 0x1244f8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
label_1244fc:
    // 0x1244fc: 0x60f809
label_124500:
    if (ctx->pc == 0x124500u) {
        ctx->pc = 0x124500u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294949188)));
        ctx->pc = 0x124504u;
        goto label_124504;
    }
    ctx->pc = 0x1244FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x124504u);
        ctx->pc = 0x124500u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294949188)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124504u; }
            if (ctx->pc != 0x124504u) { return; }
        }
    }
    ctx->pc = 0x124504u;
label_124504:
    // 0x124504: 0xdfbf0000
    ctx->pc = 0x124504u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_124508:
    // 0x124508: 0x102d
    ctx->pc = 0x124508u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12450c:
    // 0x12450c: 0x3e00008
label_124510:
    if (ctx->pc == 0x124510u) {
        ctx->pc = 0x124510u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x124514u;
        goto label_124514;
    }
    ctx->pc = 0x12450Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124510u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123DB4u: goto label_123db4;
            case 0x123DB8u: goto label_123db8;
            case 0x123DBCu: goto label_123dbc;
            case 0x123DC0u: goto label_123dc0;
            case 0x123DC4u: goto label_123dc4;
            case 0x123DC8u: goto label_123dc8;
            case 0x123DCCu: goto label_123dcc;
            case 0x123DD0u: goto label_123dd0;
            case 0x123DD4u: goto label_123dd4;
            case 0x123DD8u: goto label_123dd8;
            case 0x123DDCu: goto label_123ddc;
            case 0x123DE0u: goto label_123de0;
            case 0x123DE4u: goto label_123de4;
            case 0x123DE8u: goto label_123de8;
            case 0x123DECu: goto label_123dec;
            case 0x123DF0u: goto label_123df0;
            case 0x123DF4u: goto label_123df4;
            case 0x123DF8u: goto label_123df8;
            case 0x123DFCu: goto label_123dfc;
            case 0x123E00u: goto label_123e00;
            case 0x123E04u: goto label_123e04;
            case 0x123E08u: goto label_123e08;
            case 0x123E0Cu: goto label_123e0c;
            case 0x123E10u: goto label_123e10;
            case 0x123E14u: goto label_123e14;
            case 0x123E18u: goto label_123e18;
            case 0x123E1Cu: goto label_123e1c;
            case 0x123E20u: goto label_123e20;
            case 0x123E24u: goto label_123e24;
            case 0x123E28u: goto label_123e28;
            case 0x123E2Cu: goto label_123e2c;
            case 0x123E30u: goto label_123e30;
            case 0x123E34u: goto label_123e34;
            case 0x123E38u: goto label_123e38;
            case 0x123E3Cu: goto label_123e3c;
            case 0x123E40u: goto label_123e40;
            case 0x123E44u: goto label_123e44;
            case 0x123E48u: goto label_123e48;
            case 0x123E4Cu: goto label_123e4c;
            case 0x123E50u: goto label_123e50;
            case 0x123E54u: goto label_123e54;
            case 0x123E58u: goto label_123e58;
            case 0x123E5Cu: goto label_123e5c;
            case 0x123E60u: goto label_123e60;
            case 0x123E64u: goto label_123e64;
            case 0x123E68u: goto label_123e68;
            case 0x123E6Cu: goto label_123e6c;
            case 0x123E70u: goto label_123e70;
            case 0x123E74u: goto label_123e74;
            case 0x123E78u: goto label_123e78;
            case 0x123E7Cu: goto label_123e7c;
            case 0x123E80u: goto label_123e80;
            case 0x123E84u: goto label_123e84;
            case 0x123E88u: goto label_123e88;
            case 0x123E8Cu: goto label_123e8c;
            case 0x123E90u: goto label_123e90;
            case 0x123E94u: goto label_123e94;
            case 0x123E98u: goto label_123e98;
            case 0x123E9Cu: goto label_123e9c;
            case 0x123EA0u: goto label_123ea0;
            case 0x123EA4u: goto label_123ea4;
            case 0x123EA8u: goto label_123ea8;
            case 0x123EACu: goto label_123eac;
            case 0x123EB0u: goto label_123eb0;
            case 0x123EB4u: goto label_123eb4;
            case 0x123EB8u: goto label_123eb8;
            case 0x123EBCu: goto label_123ebc;
            case 0x123EC0u: goto label_123ec0;
            case 0x123EC4u: goto label_123ec4;
            case 0x123EC8u: goto label_123ec8;
            case 0x123ECCu: goto label_123ecc;
            case 0x123ED0u: goto label_123ed0;
            case 0x123ED4u: goto label_123ed4;
            case 0x123ED8u: goto label_123ed8;
            case 0x123EDCu: goto label_123edc;
            case 0x123EE0u: goto label_123ee0;
            case 0x123EE4u: goto label_123ee4;
            case 0x123EE8u: goto label_123ee8;
            case 0x123EECu: goto label_123eec;
            case 0x123EF0u: goto label_123ef0;
            case 0x123EF4u: goto label_123ef4;
            case 0x123EF8u: goto label_123ef8;
            case 0x123EFCu: goto label_123efc;
            case 0x123F00u: goto label_123f00;
            case 0x123F04u: goto label_123f04;
            case 0x123F08u: goto label_123f08;
            case 0x123F0Cu: goto label_123f0c;
            case 0x123F10u: goto label_123f10;
            case 0x123F14u: goto label_123f14;
            case 0x123F18u: goto label_123f18;
            case 0x123F1Cu: goto label_123f1c;
            case 0x123F20u: goto label_123f20;
            case 0x123F24u: goto label_123f24;
            case 0x123F28u: goto label_123f28;
            case 0x123F2Cu: goto label_123f2c;
            case 0x123F30u: goto label_123f30;
            case 0x123F34u: goto label_123f34;
            case 0x123F38u: goto label_123f38;
            case 0x123F3Cu: goto label_123f3c;
            case 0x123F40u: goto label_123f40;
            case 0x123F44u: goto label_123f44;
            case 0x123F48u: goto label_123f48;
            case 0x123F4Cu: goto label_123f4c;
            case 0x123F50u: goto label_123f50;
            case 0x123F54u: goto label_123f54;
            case 0x123F58u: goto label_123f58;
            case 0x123F5Cu: goto label_123f5c;
            case 0x123F60u: goto label_123f60;
            case 0x123F64u: goto label_123f64;
            case 0x123F68u: goto label_123f68;
            case 0x123F6Cu: goto label_123f6c;
            case 0x123F70u: goto label_123f70;
            case 0x123F74u: goto label_123f74;
            case 0x123F78u: goto label_123f78;
            case 0x123F7Cu: goto label_123f7c;
            case 0x123F80u: goto label_123f80;
            case 0x123F84u: goto label_123f84;
            case 0x123F88u: goto label_123f88;
            case 0x123F8Cu: goto label_123f8c;
            case 0x123F90u: goto label_123f90;
            case 0x123F94u: goto label_123f94;
            case 0x123F98u: goto label_123f98;
            case 0x123F9Cu: goto label_123f9c;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FA4u: goto label_123fa4;
            case 0x123FA8u: goto label_123fa8;
            case 0x123FACu: goto label_123fac;
            case 0x123FB0u: goto label_123fb0;
            case 0x123FB4u: goto label_123fb4;
            case 0x123FB8u: goto label_123fb8;
            case 0x123FBCu: goto label_123fbc;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FC4u: goto label_123fc4;
            case 0x123FC8u: goto label_123fc8;
            case 0x123FCCu: goto label_123fcc;
            case 0x123FD0u: goto label_123fd0;
            case 0x123FD4u: goto label_123fd4;
            case 0x123FD8u: goto label_123fd8;
            case 0x123FDCu: goto label_123fdc;
            case 0x123FE0u: goto label_123fe0;
            case 0x123FE4u: goto label_123fe4;
            case 0x123FE8u: goto label_123fe8;
            case 0x123FECu: goto label_123fec;
            case 0x123FF0u: goto label_123ff0;
            case 0x123FF4u: goto label_123ff4;
            case 0x123FF8u: goto label_123ff8;
            case 0x123FFCu: goto label_123ffc;
            case 0x124000u: goto label_124000;
            case 0x124004u: goto label_124004;
            case 0x124008u: goto label_124008;
            case 0x12400Cu: goto label_12400c;
            case 0x124010u: goto label_124010;
            case 0x124014u: goto label_124014;
            case 0x124018u: goto label_124018;
            case 0x12401Cu: goto label_12401c;
            case 0x124020u: goto label_124020;
            case 0x124024u: goto label_124024;
            case 0x124028u: goto label_124028;
            case 0x12402Cu: goto label_12402c;
            case 0x124030u: goto label_124030;
            case 0x124034u: goto label_124034;
            case 0x124038u: goto label_124038;
            case 0x12403Cu: goto label_12403c;
            case 0x124040u: goto label_124040;
            case 0x124044u: goto label_124044;
            case 0x124048u: goto label_124048;
            case 0x12404Cu: goto label_12404c;
            case 0x124050u: goto label_124050;
            case 0x124054u: goto label_124054;
            case 0x124058u: goto label_124058;
            case 0x12405Cu: goto label_12405c;
            case 0x124060u: goto label_124060;
            case 0x124064u: goto label_124064;
            case 0x124068u: goto label_124068;
            case 0x12406Cu: goto label_12406c;
            case 0x124070u: goto label_124070;
            case 0x124074u: goto label_124074;
            case 0x124078u: goto label_124078;
            case 0x12407Cu: goto label_12407c;
            case 0x124080u: goto label_124080;
            case 0x124084u: goto label_124084;
            case 0x124088u: goto label_124088;
            case 0x12408Cu: goto label_12408c;
            case 0x124090u: goto label_124090;
            case 0x124094u: goto label_124094;
            case 0x124098u: goto label_124098;
            case 0x12409Cu: goto label_12409c;
            case 0x1240A0u: goto label_1240a0;
            case 0x1240A4u: goto label_1240a4;
            case 0x1240A8u: goto label_1240a8;
            case 0x1240ACu: goto label_1240ac;
            case 0x1240B0u: goto label_1240b0;
            case 0x1240B4u: goto label_1240b4;
            case 0x1240B8u: goto label_1240b8;
            case 0x1240BCu: goto label_1240bc;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C4u: goto label_1240c4;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240CCu: goto label_1240cc;
            case 0x1240D0u: goto label_1240d0;
            case 0x1240D4u: goto label_1240d4;
            case 0x1240D8u: goto label_1240d8;
            case 0x1240DCu: goto label_1240dc;
            case 0x1240E0u: goto label_1240e0;
            case 0x1240E4u: goto label_1240e4;
            case 0x1240E8u: goto label_1240e8;
            case 0x1240ECu: goto label_1240ec;
            case 0x1240F0u: goto label_1240f0;
            case 0x1240F4u: goto label_1240f4;
            case 0x1240F8u: goto label_1240f8;
            case 0x1240FCu: goto label_1240fc;
            case 0x124100u: goto label_124100;
            case 0x124104u: goto label_124104;
            case 0x124108u: goto label_124108;
            case 0x12410Cu: goto label_12410c;
            case 0x124110u: goto label_124110;
            case 0x124114u: goto label_124114;
            case 0x124118u: goto label_124118;
            case 0x12411Cu: goto label_12411c;
            case 0x124120u: goto label_124120;
            case 0x124124u: goto label_124124;
            case 0x124128u: goto label_124128;
            case 0x12412Cu: goto label_12412c;
            case 0x124130u: goto label_124130;
            case 0x124134u: goto label_124134;
            case 0x124138u: goto label_124138;
            case 0x12413Cu: goto label_12413c;
            case 0x124140u: goto label_124140;
            case 0x124144u: goto label_124144;
            case 0x124148u: goto label_124148;
            case 0x12414Cu: goto label_12414c;
            case 0x124150u: goto label_124150;
            case 0x124154u: goto label_124154;
            case 0x124158u: goto label_124158;
            case 0x12415Cu: goto label_12415c;
            case 0x124160u: goto label_124160;
            case 0x124164u: goto label_124164;
            case 0x124168u: goto label_124168;
            case 0x12416Cu: goto label_12416c;
            case 0x124170u: goto label_124170;
            case 0x124174u: goto label_124174;
            case 0x124178u: goto label_124178;
            case 0x12417Cu: goto label_12417c;
            case 0x124180u: goto label_124180;
            case 0x124184u: goto label_124184;
            case 0x124188u: goto label_124188;
            case 0x12418Cu: goto label_12418c;
            case 0x124190u: goto label_124190;
            case 0x124194u: goto label_124194;
            case 0x124198u: goto label_124198;
            case 0x12419Cu: goto label_12419c;
            case 0x1241A0u: goto label_1241a0;
            case 0x1241A4u: goto label_1241a4;
            case 0x1241A8u: goto label_1241a8;
            case 0x1241ACu: goto label_1241ac;
            case 0x1241B0u: goto label_1241b0;
            case 0x1241B4u: goto label_1241b4;
            case 0x1241B8u: goto label_1241b8;
            case 0x1241BCu: goto label_1241bc;
            case 0x1241C0u: goto label_1241c0;
            case 0x1241C4u: goto label_1241c4;
            case 0x1241C8u: goto label_1241c8;
            case 0x1241CCu: goto label_1241cc;
            case 0x1241D0u: goto label_1241d0;
            case 0x1241D4u: goto label_1241d4;
            case 0x1241D8u: goto label_1241d8;
            case 0x1241DCu: goto label_1241dc;
            case 0x1241E0u: goto label_1241e0;
            case 0x1241E4u: goto label_1241e4;
            case 0x1241E8u: goto label_1241e8;
            case 0x1241ECu: goto label_1241ec;
            case 0x1241F0u: goto label_1241f0;
            case 0x1241F4u: goto label_1241f4;
            case 0x1241F8u: goto label_1241f8;
            case 0x1241FCu: goto label_1241fc;
            case 0x124200u: goto label_124200;
            case 0x124204u: goto label_124204;
            case 0x124208u: goto label_124208;
            case 0x12420Cu: goto label_12420c;
            case 0x124210u: goto label_124210;
            case 0x124214u: goto label_124214;
            case 0x124218u: goto label_124218;
            case 0x12421Cu: goto label_12421c;
            case 0x124220u: goto label_124220;
            case 0x124224u: goto label_124224;
            case 0x124228u: goto label_124228;
            case 0x12422Cu: goto label_12422c;
            case 0x124230u: goto label_124230;
            case 0x124234u: goto label_124234;
            case 0x124238u: goto label_124238;
            case 0x12423Cu: goto label_12423c;
            case 0x124240u: goto label_124240;
            case 0x124244u: goto label_124244;
            case 0x124248u: goto label_124248;
            case 0x12424Cu: goto label_12424c;
            case 0x124250u: goto label_124250;
            case 0x124254u: goto label_124254;
            case 0x124258u: goto label_124258;
            case 0x12425Cu: goto label_12425c;
            case 0x124260u: goto label_124260;
            case 0x124264u: goto label_124264;
            case 0x124268u: goto label_124268;
            case 0x12426Cu: goto label_12426c;
            case 0x124270u: goto label_124270;
            case 0x124274u: goto label_124274;
            case 0x124278u: goto label_124278;
            case 0x12427Cu: goto label_12427c;
            case 0x124280u: goto label_124280;
            case 0x124284u: goto label_124284;
            case 0x124288u: goto label_124288;
            case 0x12428Cu: goto label_12428c;
            case 0x124290u: goto label_124290;
            case 0x124294u: goto label_124294;
            case 0x124298u: goto label_124298;
            case 0x12429Cu: goto label_12429c;
            case 0x1242A0u: goto label_1242a0;
            case 0x1242A4u: goto label_1242a4;
            case 0x1242A8u: goto label_1242a8;
            case 0x1242ACu: goto label_1242ac;
            case 0x1242B0u: goto label_1242b0;
            case 0x1242B4u: goto label_1242b4;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242BCu: goto label_1242bc;
            case 0x1242C0u: goto label_1242c0;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242C8u: goto label_1242c8;
            case 0x1242CCu: goto label_1242cc;
            case 0x1242D0u: goto label_1242d0;
            case 0x1242D4u: goto label_1242d4;
            case 0x1242D8u: goto label_1242d8;
            case 0x1242DCu: goto label_1242dc;
            case 0x1242E0u: goto label_1242e0;
            case 0x1242E4u: goto label_1242e4;
            case 0x1242E8u: goto label_1242e8;
            case 0x1242ECu: goto label_1242ec;
            case 0x1242F0u: goto label_1242f0;
            case 0x1242F4u: goto label_1242f4;
            case 0x1242F8u: goto label_1242f8;
            case 0x1242FCu: goto label_1242fc;
            case 0x124300u: goto label_124300;
            case 0x124304u: goto label_124304;
            case 0x124308u: goto label_124308;
            case 0x12430Cu: goto label_12430c;
            case 0x124310u: goto label_124310;
            case 0x124314u: goto label_124314;
            case 0x124318u: goto label_124318;
            case 0x12431Cu: goto label_12431c;
            case 0x124320u: goto label_124320;
            case 0x124324u: goto label_124324;
            case 0x124328u: goto label_124328;
            case 0x12432Cu: goto label_12432c;
            case 0x124330u: goto label_124330;
            case 0x124334u: goto label_124334;
            case 0x124338u: goto label_124338;
            case 0x12433Cu: goto label_12433c;
            case 0x124340u: goto label_124340;
            case 0x124344u: goto label_124344;
            case 0x124348u: goto label_124348;
            case 0x12434Cu: goto label_12434c;
            case 0x124350u: goto label_124350;
            case 0x124354u: goto label_124354;
            case 0x124358u: goto label_124358;
            case 0x12435Cu: goto label_12435c;
            case 0x124360u: goto label_124360;
            case 0x124364u: goto label_124364;
            case 0x124368u: goto label_124368;
            case 0x12436Cu: goto label_12436c;
            case 0x124370u: goto label_124370;
            case 0x124374u: goto label_124374;
            case 0x124378u: goto label_124378;
            case 0x12437Cu: goto label_12437c;
            case 0x124380u: goto label_124380;
            case 0x124384u: goto label_124384;
            case 0x124388u: goto label_124388;
            case 0x12438Cu: goto label_12438c;
            case 0x124390u: goto label_124390;
            case 0x124394u: goto label_124394;
            case 0x124398u: goto label_124398;
            case 0x12439Cu: goto label_12439c;
            case 0x1243A0u: goto label_1243a0;
            case 0x1243A4u: goto label_1243a4;
            case 0x1243A8u: goto label_1243a8;
            case 0x1243ACu: goto label_1243ac;
            case 0x1243B0u: goto label_1243b0;
            case 0x1243B4u: goto label_1243b4;
            case 0x1243B8u: goto label_1243b8;
            case 0x1243BCu: goto label_1243bc;
            case 0x1243C0u: goto label_1243c0;
            case 0x1243C4u: goto label_1243c4;
            case 0x1243C8u: goto label_1243c8;
            case 0x1243CCu: goto label_1243cc;
            case 0x1243D0u: goto label_1243d0;
            case 0x1243D4u: goto label_1243d4;
            case 0x1243D8u: goto label_1243d8;
            case 0x1243DCu: goto label_1243dc;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243E4u: goto label_1243e4;
            case 0x1243E8u: goto label_1243e8;
            case 0x1243ECu: goto label_1243ec;
            case 0x1243F0u: goto label_1243f0;
            case 0x1243F4u: goto label_1243f4;
            case 0x1243F8u: goto label_1243f8;
            case 0x1243FCu: goto label_1243fc;
            case 0x124400u: goto label_124400;
            case 0x124404u: goto label_124404;
            case 0x124408u: goto label_124408;
            case 0x12440Cu: goto label_12440c;
            case 0x124410u: goto label_124410;
            case 0x124414u: goto label_124414;
            case 0x124418u: goto label_124418;
            case 0x12441Cu: goto label_12441c;
            case 0x124420u: goto label_124420;
            case 0x124424u: goto label_124424;
            case 0x124428u: goto label_124428;
            case 0x12442Cu: goto label_12442c;
            case 0x124430u: goto label_124430;
            case 0x124434u: goto label_124434;
            case 0x124438u: goto label_124438;
            case 0x12443Cu: goto label_12443c;
            case 0x124440u: goto label_124440;
            case 0x124444u: goto label_124444;
            case 0x124448u: goto label_124448;
            case 0x12444Cu: goto label_12444c;
            case 0x124450u: goto label_124450;
            case 0x124454u: goto label_124454;
            case 0x124458u: goto label_124458;
            case 0x12445Cu: goto label_12445c;
            case 0x124460u: goto label_124460;
            case 0x124464u: goto label_124464;
            case 0x124468u: goto label_124468;
            case 0x12446Cu: goto label_12446c;
            case 0x124470u: goto label_124470;
            case 0x124474u: goto label_124474;
            case 0x124478u: goto label_124478;
            case 0x12447Cu: goto label_12447c;
            case 0x124480u: goto label_124480;
            case 0x124484u: goto label_124484;
            case 0x124488u: goto label_124488;
            case 0x12448Cu: goto label_12448c;
            case 0x124490u: goto label_124490;
            case 0x124494u: goto label_124494;
            case 0x124498u: goto label_124498;
            case 0x12449Cu: goto label_12449c;
            case 0x1244A0u: goto label_1244a0;
            case 0x1244A4u: goto label_1244a4;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244ACu: goto label_1244ac;
            case 0x1244B0u: goto label_1244b0;
            case 0x1244B4u: goto label_1244b4;
            case 0x1244B8u: goto label_1244b8;
            case 0x1244BCu: goto label_1244bc;
            case 0x1244C0u: goto label_1244c0;
            case 0x1244C4u: goto label_1244c4;
            case 0x1244C8u: goto label_1244c8;
            case 0x1244CCu: goto label_1244cc;
            case 0x1244D0u: goto label_1244d0;
            case 0x1244D4u: goto label_1244d4;
            case 0x1244D8u: goto label_1244d8;
            case 0x1244DCu: goto label_1244dc;
            case 0x1244E0u: goto label_1244e0;
            case 0x1244E4u: goto label_1244e4;
            case 0x1244E8u: goto label_1244e8;
            case 0x1244ECu: goto label_1244ec;
            case 0x1244F0u: goto label_1244f0;
            case 0x1244F4u: goto label_1244f4;
            case 0x1244F8u: goto label_1244f8;
            case 0x1244FCu: goto label_1244fc;
            case 0x124500u: goto label_124500;
            case 0x124504u: goto label_124504;
            case 0x124508u: goto label_124508;
            case 0x12450Cu: goto label_12450c;
            case 0x124510u: goto label_124510;
            case 0x124514u: goto label_124514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124514u;
label_124514:
    // 0x124514: 0x0
    ctx->pc = 0x124514u;
    // NOP
}
