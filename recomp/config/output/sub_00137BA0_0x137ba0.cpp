#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00137BA0
// Address: 0x137ba0 - 0x137d80
void sub_00137BA0_0x137ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x137ba0u;

label_137ba0:
    // 0x137ba0: 0x27bdffd0
    ctx->pc = 0x137ba0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
label_137ba4:
    // 0x137ba4: 0x24030001
    ctx->pc = 0x137ba4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
label_137ba8:
    // 0x137ba8: 0xffb10018
    ctx->pc = 0x137ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
label_137bac:
    // 0x137bac: 0x80882d
    ctx->pc = 0x137bacu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_137bb0:
    // 0x137bb0: 0xffb00010
    ctx->pc = 0x137bb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
label_137bb4:
    // 0x137bb4: 0xffbf0020
    ctx->pc = 0x137bb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
label_137bb8:
    // 0x137bb8: 0x8e220004
    ctx->pc = 0x137bb8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_137bbc:
    // 0x137bbc: 0x14430017
label_137bc0:
    if (ctx->pc == 0x137BC0u) {
        ctx->pc = 0x137BC0u;
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->pc = 0x137BC4u;
        goto label_137bc4;
    }
    ctx->pc = 0x137BBCu;
    {
        const bool branch_taken_0x137bbc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x137BC0u;
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        if (branch_taken_0x137bbc) {
            ctx->pc = 0x137C1Cu;
            goto label_137c1c;
        }
    }
    ctx->pc = 0x137BC4u;
label_137bc4:
    // 0x137bc4: 0x82230002
    ctx->pc = 0x137bc4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
label_137bc8:
    // 0x137bc8: 0x2c62000a
    ctx->pc = 0x137bc8u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 3), 10));
label_137bcc:
    // 0x137bcc: 0x50400013
label_137bd0:
    if (ctx->pc == 0x137BD0u) {
        ctx->pc = 0x137BD0u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->pc = 0x137BD4u;
        goto label_137bd4;
    }
    ctx->pc = 0x137BCCu;
    {
        const bool branch_taken_0x137bcc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x137bcc) {
            ctx->pc = 0x137BD0u;
            WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
            ctx->pc = 0x137C1Cu;
            goto label_137c1c;
        }
    }
    ctx->pc = 0x137BD4u;
label_137bd4:
    // 0x137bd4: 0x31080
    ctx->pc = 0x137bd4u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 3), 2));
label_137bd8:
    // 0x137bd8: 0x3c030024
    ctx->pc = 0x137bd8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)36 << 16));
label_137bdc:
    // 0x137bdc: 0x621821
    ctx->pc = 0x137bdcu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_137be0:
    // 0x137be0: 0x8c63c5a0
    ctx->pc = 0x137be0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 4294952352)));
label_137be4:
    // 0x137be4: 0x600008
label_137be8:
    if (ctx->pc == 0x137BE8u) {
        ctx->pc = 0x137BECu;
        goto label_137bec;
    }
    ctx->pc = 0x137BE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137BA0u: goto label_137ba0;
            case 0x137BA4u: goto label_137ba4;
            case 0x137BA8u: goto label_137ba8;
            case 0x137BACu: goto label_137bac;
            case 0x137BB0u: goto label_137bb0;
            case 0x137BB4u: goto label_137bb4;
            case 0x137BB8u: goto label_137bb8;
            case 0x137BBCu: goto label_137bbc;
            case 0x137BC0u: goto label_137bc0;
            case 0x137BC4u: goto label_137bc4;
            case 0x137BC8u: goto label_137bc8;
            case 0x137BCCu: goto label_137bcc;
            case 0x137BD0u: goto label_137bd0;
            case 0x137BD4u: goto label_137bd4;
            case 0x137BD8u: goto label_137bd8;
            case 0x137BDCu: goto label_137bdc;
            case 0x137BE0u: goto label_137be0;
            case 0x137BE4u: goto label_137be4;
            case 0x137BE8u: goto label_137be8;
            case 0x137BECu: goto label_137bec;
            case 0x137BF0u: goto label_137bf0;
            case 0x137BF4u: goto label_137bf4;
            case 0x137BF8u: goto label_137bf8;
            case 0x137BFCu: goto label_137bfc;
            case 0x137C00u: goto label_137c00;
            case 0x137C04u: goto label_137c04;
            case 0x137C08u: goto label_137c08;
            case 0x137C0Cu: goto label_137c0c;
            case 0x137C10u: goto label_137c10;
            case 0x137C14u: goto label_137c14;
            case 0x137C18u: goto label_137c18;
            case 0x137C1Cu: goto label_137c1c;
            case 0x137C20u: goto label_137c20;
            case 0x137C24u: goto label_137c24;
            case 0x137C28u: goto label_137c28;
            case 0x137C2Cu: goto label_137c2c;
            case 0x137C30u: goto label_137c30;
            case 0x137C34u: goto label_137c34;
            case 0x137C38u: goto label_137c38;
            case 0x137C3Cu: goto label_137c3c;
            case 0x137C40u: goto label_137c40;
            case 0x137C44u: goto label_137c44;
            case 0x137C48u: goto label_137c48;
            case 0x137C4Cu: goto label_137c4c;
            case 0x137C50u: goto label_137c50;
            case 0x137C54u: goto label_137c54;
            case 0x137C58u: goto label_137c58;
            case 0x137C5Cu: goto label_137c5c;
            case 0x137C60u: goto label_137c60;
            case 0x137C64u: goto label_137c64;
            case 0x137C68u: goto label_137c68;
            case 0x137C6Cu: goto label_137c6c;
            case 0x137C70u: goto label_137c70;
            case 0x137C74u: goto label_137c74;
            case 0x137C78u: goto label_137c78;
            case 0x137C7Cu: goto label_137c7c;
            case 0x137C80u: goto label_137c80;
            case 0x137C84u: goto label_137c84;
            case 0x137C88u: goto label_137c88;
            case 0x137C8Cu: goto label_137c8c;
            case 0x137C90u: goto label_137c90;
            case 0x137C94u: goto label_137c94;
            case 0x137C98u: goto label_137c98;
            case 0x137C9Cu: goto label_137c9c;
            case 0x137CA0u: goto label_137ca0;
            case 0x137CA4u: goto label_137ca4;
            case 0x137CA8u: goto label_137ca8;
            case 0x137CACu: goto label_137cac;
            case 0x137CB0u: goto label_137cb0;
            case 0x137CB4u: goto label_137cb4;
            case 0x137CB8u: goto label_137cb8;
            case 0x137CBCu: goto label_137cbc;
            case 0x137CC0u: goto label_137cc0;
            case 0x137CC4u: goto label_137cc4;
            case 0x137CC8u: goto label_137cc8;
            case 0x137CCCu: goto label_137ccc;
            case 0x137CD0u: goto label_137cd0;
            case 0x137CD4u: goto label_137cd4;
            case 0x137CD8u: goto label_137cd8;
            case 0x137CDCu: goto label_137cdc;
            case 0x137CE0u: goto label_137ce0;
            case 0x137CE4u: goto label_137ce4;
            case 0x137CE8u: goto label_137ce8;
            case 0x137CECu: goto label_137cec;
            case 0x137CF0u: goto label_137cf0;
            case 0x137CF4u: goto label_137cf4;
            case 0x137CF8u: goto label_137cf8;
            case 0x137CFCu: goto label_137cfc;
            case 0x137D00u: goto label_137d00;
            case 0x137D04u: goto label_137d04;
            case 0x137D08u: goto label_137d08;
            case 0x137D0Cu: goto label_137d0c;
            case 0x137D10u: goto label_137d10;
            case 0x137D14u: goto label_137d14;
            case 0x137D18u: goto label_137d18;
            case 0x137D1Cu: goto label_137d1c;
            case 0x137D20u: goto label_137d20;
            case 0x137D24u: goto label_137d24;
            case 0x137D28u: goto label_137d28;
            case 0x137D2Cu: goto label_137d2c;
            case 0x137D30u: goto label_137d30;
            case 0x137D34u: goto label_137d34;
            case 0x137D38u: goto label_137d38;
            case 0x137D3Cu: goto label_137d3c;
            case 0x137D40u: goto label_137d40;
            case 0x137D44u: goto label_137d44;
            case 0x137D48u: goto label_137d48;
            case 0x137D4Cu: goto label_137d4c;
            case 0x137D50u: goto label_137d50;
            case 0x137D54u: goto label_137d54;
            case 0x137D58u: goto label_137d58;
            case 0x137D5Cu: goto label_137d5c;
            case 0x137D60u: goto label_137d60;
            case 0x137D64u: goto label_137d64;
            case 0x137D68u: goto label_137d68;
            case 0x137D6Cu: goto label_137d6c;
            case 0x137D70u: goto label_137d70;
            case 0x137D74u: goto label_137d74;
            case 0x137D78u: goto label_137d78;
            case 0x137D7Cu: goto label_137d7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137BECu;
label_137bec:
    // 0x137bec: 0x0
    ctx->pc = 0x137becu;
    // NOP
label_137bf0:
    // 0x137bf0: 0xc04dd9a
label_137bf4:
    if (ctx->pc == 0x137BF4u) {
        ctx->pc = 0x137BF4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x137BF8u;
        goto label_137bf8;
    }
    ctx->pc = 0x137BF0u;
    SET_GPR_U32(ctx, 31, 0x137BF8u);
    ctx->pc = 0x137BF4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x137668u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00137668_0x137668(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137BF8u; }
    }
    if (ctx->pc != 0x137BF8u) { return; }
    ctx->pc = 0x137BF8u;
label_137bf8:
    // 0x137bf8: 0xa2200002
    ctx->pc = 0x137bf8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
label_137bfc:
    // 0x137bfc: 0x3c030022
    ctx->pc = 0x137bfcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_137c00:
    // 0x137c00: 0x2463bbe4
    ctx->pc = 0x137c00u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949860));
label_137c04:
    // 0x137c04: 0x8c620000
    ctx->pc = 0x137c04u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_137c08:
    // 0x137c08: 0x24420001
    ctx->pc = 0x137c08u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_137c0c:
    // 0x137c0c: 0xac620000
    ctx->pc = 0x137c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_137c10:
    // 0x137c10: 0xa2200002
    ctx->pc = 0x137c10u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
label_137c14:
    // 0x137c14: 0x202d
    ctx->pc = 0x137c14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_137c18:
    // 0x137c18: 0xae200004
    ctx->pc = 0x137c18u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
label_137c1c:
    // 0x137c1c: 0x41600
    ctx->pc = 0x137c1cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 24));
label_137c20:
    // 0x137c20: 0x24030001
    ctx->pc = 0x137c20u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
label_137c24:
    // 0x137c24: 0x21603
    ctx->pc = 0x137c24u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
label_137c28:
    // 0x137c28: 0x5443002c
label_137c2c:
    if (ctx->pc == 0x137C2Cu) {
        ctx->pc = 0x137C2Cu;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 24));
        ctx->pc = 0x137C30u;
        goto label_137c30;
    }
    ctx->pc = 0x137C28u;
    {
        const bool branch_taken_0x137c28 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x137c28) {
            ctx->pc = 0x137C2Cu;
            SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 24));
            ctx->pc = 0x137CDCu;
            goto label_137cdc;
        }
    }
    ctx->pc = 0x137C30u;
label_137c30:
    // 0x137c30: 0xc04e082
label_137c34:
    if (ctx->pc == 0x137C34u) {
        ctx->pc = 0x137C34u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8192));
        ctx->pc = 0x137C38u;
        goto label_137c38;
    }
    ctx->pc = 0x137C30u;
    SET_GPR_U32(ctx, 31, 0x137C38u);
    ctx->pc = 0x137C34u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8192));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C38u; }
    }
    if (ctx->pc != 0x137C38u) { return; }
    ctx->pc = 0x137C38u;
label_137c38:
    // 0x137c38: 0xde250028
    ctx->pc = 0x137c38u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 17), 40)));
label_137c3c:
    // 0x137c3c: 0x8e240030
    ctx->pc = 0x137c3cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 48)));
label_137c40:
    // 0x137c40: 0x302d
    ctx->pc = 0x137c40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_137c44:
    // 0x137c44: 0xc04e0fa
label_137c48:
    if (ctx->pc == 0x137C48u) {
        ctx->pc = 0x137C48u;
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 11);
        ctx->pc = 0x137C4Cu;
        goto label_137c4c;
    }
    ctx->pc = 0x137C44u;
    SET_GPR_U32(ctx, 31, 0x137C4Cu);
    ctx->pc = 0x137C48u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 11);
    ctx->pc = 0x1383E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001383E8_0x1383e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C4Cu; }
    }
    if (ctx->pc != 0x137C4Cu) { return; }
    ctx->pc = 0x137C4Cu;
label_137c4c:
    // 0x137c4c: 0x24042001
    ctx->pc = 0x137c4cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8193));
label_137c50:
    // 0x137c50: 0xc04e082
label_137c54:
    if (ctx->pc == 0x137C54u) {
        ctx->pc = 0x137C54u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x137C58u;
        goto label_137c58;
    }
    ctx->pc = 0x137C50u;
    SET_GPR_U32(ctx, 31, 0x137C58u);
    ctx->pc = 0x137C54u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C58u; }
    }
    if (ctx->pc != 0x137C58u) { return; }
    ctx->pc = 0x137C58u;
label_137c58:
    // 0x137c58: 0x6010005
label_137c5c:
    if (ctx->pc == 0x137C5Cu) {
        ctx->pc = 0x137C5Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 9));
        ctx->pc = 0x137C60u;
        goto label_137c60;
    }
    ctx->pc = 0x137C58u;
    {
        const bool branch_taken_0x137c58 = (GPR_S32(ctx, 16) >= 0);
        ctx->pc = 0x137C5Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 9));
        if (branch_taken_0x137c58) {
            ctx->pc = 0x137C70u;
            goto label_137c70;
        }
    }
    ctx->pc = 0x137C60u;
label_137c60:
    // 0x137c60: 0x10183c
    ctx->pc = 0x137c60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 0));
label_137c64:
    // 0x137c64: 0x3183f
    ctx->pc = 0x137c64u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
label_137c68:
    // 0x137c68: 0xa2220002
    ctx->pc = 0x137c68u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
label_137c6c:
    // 0x137c6c: 0xae230034
    ctx->pc = 0x137c6cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
label_137c70:
    // 0x137c70: 0xc04e082
label_137c74:
    if (ctx->pc == 0x137C74u) {
        ctx->pc = 0x137C74u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8448));
        ctx->pc = 0x137C78u;
        goto label_137c78;
    }
    ctx->pc = 0x137C70u;
    SET_GPR_U32(ctx, 31, 0x137C78u);
    ctx->pc = 0x137C74u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8448));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C78u; }
    }
    if (ctx->pc != 0x137C78u) { return; }
    ctx->pc = 0x137C78u;
label_137c78:
    // 0x137c78: 0x8e240030
    ctx->pc = 0x137c78u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 48)));
label_137c7c:
    // 0x137c7c: 0x8e250018
    ctx->pc = 0x137c7cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 24)));
label_137c80:
    // 0x137c80: 0xc04e176
label_137c84:
    if (ctx->pc == 0x137C84u) {
        ctx->pc = 0x137C84u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 32)));
        ctx->pc = 0x137C88u;
        goto label_137c88;
    }
    ctx->pc = 0x137C80u;
    SET_GPR_U32(ctx, 31, 0x137C88u);
    ctx->pc = 0x137C84u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 32)));
    ctx->pc = 0x1385D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001385D8_0x1385d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C88u; }
    }
    if (ctx->pc != 0x137C88u) { return; }
    ctx->pc = 0x137C88u;
label_137c88:
    // 0x137c88: 0x24042101
    ctx->pc = 0x137c88u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8449));
label_137c8c:
    // 0x137c8c: 0xc04e082
label_137c90:
    if (ctx->pc == 0x137C90u) {
        ctx->pc = 0x137C90u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x137C94u;
        goto label_137c94;
    }
    ctx->pc = 0x137C8Cu;
    SET_GPR_U32(ctx, 31, 0x137C94u);
    ctx->pc = 0x137C90u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C94u; }
    }
    if (ctx->pc != 0x137C94u) { return; }
    ctx->pc = 0x137C94u;
label_137c94:
    // 0x137c94: 0x600000a
label_137c98:
    if (ctx->pc == 0x137C98u) {
        ctx->pc = 0x137C98u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x137C9Cu;
        goto label_137c9c;
    }
    ctx->pc = 0x137C94u;
    {
        const bool branch_taken_0x137c94 = (GPR_S32(ctx, 16) < 0);
        ctx->pc = 0x137C98u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x137c94) {
            ctx->pc = 0x137CC0u;
            goto label_137cc0;
        }
    }
    ctx->pc = 0x137C9Cu;
label_137c9c:
    // 0x137c9c: 0x3c030022
    ctx->pc = 0x137c9cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_137ca0:
    // 0x137ca0: 0xa2220002
    ctx->pc = 0x137ca0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
label_137ca4:
    // 0x137ca4: 0x2463bbe0
    ctx->pc = 0x137ca4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949856));
label_137ca8:
    // 0x137ca8: 0x24040002
    ctx->pc = 0x137ca8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
label_137cac:
    // 0x137cac: 0x8c620000
    ctx->pc = 0x137cacu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_137cb0:
    // 0x137cb0: 0x24420001
    ctx->pc = 0x137cb0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_137cb4:
    // 0x137cb4: 0xac620000
    ctx->pc = 0x137cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_137cb8:
    // 0x137cb8: 0x10000008
label_137cbc:
    if (ctx->pc == 0x137CBCu) {
        ctx->pc = 0x137CBCu;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 24));
        ctx->pc = 0x137CC0u;
        goto label_137cc0;
    }
    ctx->pc = 0x137CB8u;
    {
        const bool branch_taken_0x137cb8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x137CBCu;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 24));
        if (branch_taken_0x137cb8) {
            ctx->pc = 0x137CDCu;
            goto label_137cdc;
        }
    }
    ctx->pc = 0x137CC0u;
label_137cc0:
    // 0x137cc0: 0x10183c
    ctx->pc = 0x137cc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 0));
label_137cc4:
    // 0x137cc4: 0x3183f
    ctx->pc = 0x137cc4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
label_137cc8:
    // 0x137cc8: 0x24020009
    ctx->pc = 0x137cc8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 9));
label_137ccc:
    // 0x137ccc: 0xa2220002
    ctx->pc = 0x137cccu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
label_137cd0:
    // 0x137cd0: 0x24040009
    ctx->pc = 0x137cd0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 9));
label_137cd4:
    // 0x137cd4: 0xae230034
    ctx->pc = 0x137cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
label_137cd8:
    // 0x137cd8: 0x41600
    ctx->pc = 0x137cd8u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 24));
label_137cdc:
    // 0x137cdc: 0x24030002
    ctx->pc = 0x137cdcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_137ce0:
    // 0x137ce0: 0x21603
    ctx->pc = 0x137ce0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
label_137ce4:
    // 0x137ce4: 0x1443001d
label_137ce8:
    if (ctx->pc == 0x137CE8u) {
        ctx->pc = 0x137CE8u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->pc = 0x137CECu;
        goto label_137cec;
    }
    ctx->pc = 0x137CE4u;
    {
        const bool branch_taken_0x137ce4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x137CE8u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x137ce4) {
            ctx->pc = 0x137D5Cu;
            goto label_137d5c;
        }
    }
    ctx->pc = 0x137CECu;
label_137cec:
    // 0x137cec: 0xc04e082
label_137cf0:
    if (ctx->pc == 0x137CF0u) {
        ctx->pc = 0x137CF0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8704));
        ctx->pc = 0x137CF4u;
        goto label_137cf4;
    }
    ctx->pc = 0x137CECu;
    SET_GPR_U32(ctx, 31, 0x137CF4u);
    ctx->pc = 0x137CF0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8704));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137CF4u; }
    }
    if (ctx->pc != 0x137CF4u) { return; }
    ctx->pc = 0x137CF4u;
label_137cf4:
    // 0x137cf4: 0x8e240030
    ctx->pc = 0x137cf4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 48)));
label_137cf8:
    // 0x137cf8: 0x24050001
    ctx->pc = 0x137cf8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_137cfc:
    // 0x137cfc: 0xc04e128
label_137d00:
    if (ctx->pc == 0x137D00u) {
        ctx->pc = 0x137D00u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x137D04u;
        goto label_137d04;
    }
    ctx->pc = 0x137CFCu;
    SET_GPR_U32(ctx, 31, 0x137D04u);
    ctx->pc = 0x137D00u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1384A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001384A0_0x1384a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137D04u; }
    }
    if (ctx->pc != 0x137D04u) { return; }
    ctx->pc = 0x137D04u;
label_137d04:
    // 0x137d04: 0x4410008
label_137d08:
    if (ctx->pc == 0x137D08u) {
        ctx->pc = 0x137D0Cu;
        goto label_137d0c;
    }
    ctx->pc = 0x137D04u;
    {
        const bool branch_taken_0x137d04 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x137d04) {
            ctx->pc = 0x137D28u;
            goto label_137d28;
        }
    }
    ctx->pc = 0x137D0Cu;
label_137d0c:
    // 0x137d0c: 0xc04e082
label_137d10:
    if (ctx->pc == 0x137D10u) {
        ctx->pc = 0x137D10u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8705));
        ctx->pc = 0x137D14u;
        goto label_137d14;
    }
    ctx->pc = 0x137D0Cu;
    SET_GPR_U32(ctx, 31, 0x137D14u);
    ctx->pc = 0x137D10u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8705));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137D14u; }
    }
    if (ctx->pc != 0x137D14u) { return; }
    ctx->pc = 0x137D14u;
label_137d14:
    // 0x137d14: 0x24020009
    ctx->pc = 0x137d14u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 9));
label_137d18:
    // 0x137d18: 0x2403ffff
    ctx->pc = 0x137d18u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_137d1c:
    // 0x137d1c: 0xa2220002
    ctx->pc = 0x137d1cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
label_137d20:
    // 0x137d20: 0x1000000d
label_137d24:
    if (ctx->pc == 0x137D24u) {
        ctx->pc = 0x137D24u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
        ctx->pc = 0x137D28u;
        goto label_137d28;
    }
    ctx->pc = 0x137D20u;
    {
        const bool branch_taken_0x137d20 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x137D24u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
        if (branch_taken_0x137d20) {
            ctx->pc = 0x137D58u;
            goto label_137d58;
        }
    }
    ctx->pc = 0x137D28u;
label_137d28:
    // 0x137d28: 0xc04e082
label_137d2c:
    if (ctx->pc == 0x137D2Cu) {
        ctx->pc = 0x137D2Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8706));
        ctx->pc = 0x137D30u;
        goto label_137d30;
    }
    ctx->pc = 0x137D28u;
    SET_GPR_U32(ctx, 31, 0x137D30u);
    ctx->pc = 0x137D2Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8706));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137D30u; }
    }
    if (ctx->pc != 0x137D30u) { return; }
    ctx->pc = 0x137D30u;
label_137d30:
    // 0x137d30: 0x8fa20000
    ctx->pc = 0x137d30u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_137d34:
    // 0x137d34: 0x14400009
label_137d38:
    if (ctx->pc == 0x137D38u) {
        ctx->pc = 0x137D38u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->pc = 0x137D3Cu;
        goto label_137d3c;
    }
    ctx->pc = 0x137D34u;
    {
        const bool branch_taken_0x137d34 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x137D38u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x137d34) {
            ctx->pc = 0x137D5Cu;
            goto label_137d5c;
        }
    }
    ctx->pc = 0x137D3Cu;
label_137d3c:
    // 0x137d3c: 0x24020003
    ctx->pc = 0x137d3cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
label_137d40:
    // 0x137d40: 0x3c030022
    ctx->pc = 0x137d40u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_137d44:
    // 0x137d44: 0xa2220002
    ctx->pc = 0x137d44u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
label_137d48:
    // 0x137d48: 0x2463bbe4
    ctx->pc = 0x137d48u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949860));
label_137d4c:
    // 0x137d4c: 0x8c620000
    ctx->pc = 0x137d4cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_137d50:
    // 0x137d50: 0x24420001
    ctx->pc = 0x137d50u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_137d54:
    // 0x137d54: 0xac620000
    ctx->pc = 0x137d54u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_137d58:
    // 0x137d58: 0xdfb00010
    ctx->pc = 0x137d58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_137d5c:
    // 0x137d5c: 0xdfb10018
    ctx->pc = 0x137d5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_137d60:
    // 0x137d60: 0xdfbf0020
    ctx->pc = 0x137d60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_137d64:
    // 0x137d64: 0x3e00008
label_137d68:
    if (ctx->pc == 0x137D68u) {
        ctx->pc = 0x137D68u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x137D6Cu;
        goto label_137d6c;
    }
    ctx->pc = 0x137D64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137D68u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137BA0u: goto label_137ba0;
            case 0x137BA4u: goto label_137ba4;
            case 0x137BA8u: goto label_137ba8;
            case 0x137BACu: goto label_137bac;
            case 0x137BB0u: goto label_137bb0;
            case 0x137BB4u: goto label_137bb4;
            case 0x137BB8u: goto label_137bb8;
            case 0x137BBCu: goto label_137bbc;
            case 0x137BC0u: goto label_137bc0;
            case 0x137BC4u: goto label_137bc4;
            case 0x137BC8u: goto label_137bc8;
            case 0x137BCCu: goto label_137bcc;
            case 0x137BD0u: goto label_137bd0;
            case 0x137BD4u: goto label_137bd4;
            case 0x137BD8u: goto label_137bd8;
            case 0x137BDCu: goto label_137bdc;
            case 0x137BE0u: goto label_137be0;
            case 0x137BE4u: goto label_137be4;
            case 0x137BE8u: goto label_137be8;
            case 0x137BECu: goto label_137bec;
            case 0x137BF0u: goto label_137bf0;
            case 0x137BF4u: goto label_137bf4;
            case 0x137BF8u: goto label_137bf8;
            case 0x137BFCu: goto label_137bfc;
            case 0x137C00u: goto label_137c00;
            case 0x137C04u: goto label_137c04;
            case 0x137C08u: goto label_137c08;
            case 0x137C0Cu: goto label_137c0c;
            case 0x137C10u: goto label_137c10;
            case 0x137C14u: goto label_137c14;
            case 0x137C18u: goto label_137c18;
            case 0x137C1Cu: goto label_137c1c;
            case 0x137C20u: goto label_137c20;
            case 0x137C24u: goto label_137c24;
            case 0x137C28u: goto label_137c28;
            case 0x137C2Cu: goto label_137c2c;
            case 0x137C30u: goto label_137c30;
            case 0x137C34u: goto label_137c34;
            case 0x137C38u: goto label_137c38;
            case 0x137C3Cu: goto label_137c3c;
            case 0x137C40u: goto label_137c40;
            case 0x137C44u: goto label_137c44;
            case 0x137C48u: goto label_137c48;
            case 0x137C4Cu: goto label_137c4c;
            case 0x137C50u: goto label_137c50;
            case 0x137C54u: goto label_137c54;
            case 0x137C58u: goto label_137c58;
            case 0x137C5Cu: goto label_137c5c;
            case 0x137C60u: goto label_137c60;
            case 0x137C64u: goto label_137c64;
            case 0x137C68u: goto label_137c68;
            case 0x137C6Cu: goto label_137c6c;
            case 0x137C70u: goto label_137c70;
            case 0x137C74u: goto label_137c74;
            case 0x137C78u: goto label_137c78;
            case 0x137C7Cu: goto label_137c7c;
            case 0x137C80u: goto label_137c80;
            case 0x137C84u: goto label_137c84;
            case 0x137C88u: goto label_137c88;
            case 0x137C8Cu: goto label_137c8c;
            case 0x137C90u: goto label_137c90;
            case 0x137C94u: goto label_137c94;
            case 0x137C98u: goto label_137c98;
            case 0x137C9Cu: goto label_137c9c;
            case 0x137CA0u: goto label_137ca0;
            case 0x137CA4u: goto label_137ca4;
            case 0x137CA8u: goto label_137ca8;
            case 0x137CACu: goto label_137cac;
            case 0x137CB0u: goto label_137cb0;
            case 0x137CB4u: goto label_137cb4;
            case 0x137CB8u: goto label_137cb8;
            case 0x137CBCu: goto label_137cbc;
            case 0x137CC0u: goto label_137cc0;
            case 0x137CC4u: goto label_137cc4;
            case 0x137CC8u: goto label_137cc8;
            case 0x137CCCu: goto label_137ccc;
            case 0x137CD0u: goto label_137cd0;
            case 0x137CD4u: goto label_137cd4;
            case 0x137CD8u: goto label_137cd8;
            case 0x137CDCu: goto label_137cdc;
            case 0x137CE0u: goto label_137ce0;
            case 0x137CE4u: goto label_137ce4;
            case 0x137CE8u: goto label_137ce8;
            case 0x137CECu: goto label_137cec;
            case 0x137CF0u: goto label_137cf0;
            case 0x137CF4u: goto label_137cf4;
            case 0x137CF8u: goto label_137cf8;
            case 0x137CFCu: goto label_137cfc;
            case 0x137D00u: goto label_137d00;
            case 0x137D04u: goto label_137d04;
            case 0x137D08u: goto label_137d08;
            case 0x137D0Cu: goto label_137d0c;
            case 0x137D10u: goto label_137d10;
            case 0x137D14u: goto label_137d14;
            case 0x137D18u: goto label_137d18;
            case 0x137D1Cu: goto label_137d1c;
            case 0x137D20u: goto label_137d20;
            case 0x137D24u: goto label_137d24;
            case 0x137D28u: goto label_137d28;
            case 0x137D2Cu: goto label_137d2c;
            case 0x137D30u: goto label_137d30;
            case 0x137D34u: goto label_137d34;
            case 0x137D38u: goto label_137d38;
            case 0x137D3Cu: goto label_137d3c;
            case 0x137D40u: goto label_137d40;
            case 0x137D44u: goto label_137d44;
            case 0x137D48u: goto label_137d48;
            case 0x137D4Cu: goto label_137d4c;
            case 0x137D50u: goto label_137d50;
            case 0x137D54u: goto label_137d54;
            case 0x137D58u: goto label_137d58;
            case 0x137D5Cu: goto label_137d5c;
            case 0x137D60u: goto label_137d60;
            case 0x137D64u: goto label_137d64;
            case 0x137D68u: goto label_137d68;
            case 0x137D6Cu: goto label_137d6c;
            case 0x137D70u: goto label_137d70;
            case 0x137D74u: goto label_137d74;
            case 0x137D78u: goto label_137d78;
            case 0x137D7Cu: goto label_137d7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137D6Cu;
label_137d6c:
    // 0x137d6c: 0x0
    ctx->pc = 0x137d6cu;
    // NOP
label_137d70:
    // 0x137d70: 0x3c030022
    ctx->pc = 0x137d70u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_137d74:
    // 0x137d74: 0x3e00008
label_137d78:
    if (ctx->pc == 0x137D78u) {
        ctx->pc = 0x137D78u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294949828)));
        ctx->pc = 0x137D7Cu;
        goto label_137d7c;
    }
    ctx->pc = 0x137D74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137D78u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294949828)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137BA0u: goto label_137ba0;
            case 0x137BA4u: goto label_137ba4;
            case 0x137BA8u: goto label_137ba8;
            case 0x137BACu: goto label_137bac;
            case 0x137BB0u: goto label_137bb0;
            case 0x137BB4u: goto label_137bb4;
            case 0x137BB8u: goto label_137bb8;
            case 0x137BBCu: goto label_137bbc;
            case 0x137BC0u: goto label_137bc0;
            case 0x137BC4u: goto label_137bc4;
            case 0x137BC8u: goto label_137bc8;
            case 0x137BCCu: goto label_137bcc;
            case 0x137BD0u: goto label_137bd0;
            case 0x137BD4u: goto label_137bd4;
            case 0x137BD8u: goto label_137bd8;
            case 0x137BDCu: goto label_137bdc;
            case 0x137BE0u: goto label_137be0;
            case 0x137BE4u: goto label_137be4;
            case 0x137BE8u: goto label_137be8;
            case 0x137BECu: goto label_137bec;
            case 0x137BF0u: goto label_137bf0;
            case 0x137BF4u: goto label_137bf4;
            case 0x137BF8u: goto label_137bf8;
            case 0x137BFCu: goto label_137bfc;
            case 0x137C00u: goto label_137c00;
            case 0x137C04u: goto label_137c04;
            case 0x137C08u: goto label_137c08;
            case 0x137C0Cu: goto label_137c0c;
            case 0x137C10u: goto label_137c10;
            case 0x137C14u: goto label_137c14;
            case 0x137C18u: goto label_137c18;
            case 0x137C1Cu: goto label_137c1c;
            case 0x137C20u: goto label_137c20;
            case 0x137C24u: goto label_137c24;
            case 0x137C28u: goto label_137c28;
            case 0x137C2Cu: goto label_137c2c;
            case 0x137C30u: goto label_137c30;
            case 0x137C34u: goto label_137c34;
            case 0x137C38u: goto label_137c38;
            case 0x137C3Cu: goto label_137c3c;
            case 0x137C40u: goto label_137c40;
            case 0x137C44u: goto label_137c44;
            case 0x137C48u: goto label_137c48;
            case 0x137C4Cu: goto label_137c4c;
            case 0x137C50u: goto label_137c50;
            case 0x137C54u: goto label_137c54;
            case 0x137C58u: goto label_137c58;
            case 0x137C5Cu: goto label_137c5c;
            case 0x137C60u: goto label_137c60;
            case 0x137C64u: goto label_137c64;
            case 0x137C68u: goto label_137c68;
            case 0x137C6Cu: goto label_137c6c;
            case 0x137C70u: goto label_137c70;
            case 0x137C74u: goto label_137c74;
            case 0x137C78u: goto label_137c78;
            case 0x137C7Cu: goto label_137c7c;
            case 0x137C80u: goto label_137c80;
            case 0x137C84u: goto label_137c84;
            case 0x137C88u: goto label_137c88;
            case 0x137C8Cu: goto label_137c8c;
            case 0x137C90u: goto label_137c90;
            case 0x137C94u: goto label_137c94;
            case 0x137C98u: goto label_137c98;
            case 0x137C9Cu: goto label_137c9c;
            case 0x137CA0u: goto label_137ca0;
            case 0x137CA4u: goto label_137ca4;
            case 0x137CA8u: goto label_137ca8;
            case 0x137CACu: goto label_137cac;
            case 0x137CB0u: goto label_137cb0;
            case 0x137CB4u: goto label_137cb4;
            case 0x137CB8u: goto label_137cb8;
            case 0x137CBCu: goto label_137cbc;
            case 0x137CC0u: goto label_137cc0;
            case 0x137CC4u: goto label_137cc4;
            case 0x137CC8u: goto label_137cc8;
            case 0x137CCCu: goto label_137ccc;
            case 0x137CD0u: goto label_137cd0;
            case 0x137CD4u: goto label_137cd4;
            case 0x137CD8u: goto label_137cd8;
            case 0x137CDCu: goto label_137cdc;
            case 0x137CE0u: goto label_137ce0;
            case 0x137CE4u: goto label_137ce4;
            case 0x137CE8u: goto label_137ce8;
            case 0x137CECu: goto label_137cec;
            case 0x137CF0u: goto label_137cf0;
            case 0x137CF4u: goto label_137cf4;
            case 0x137CF8u: goto label_137cf8;
            case 0x137CFCu: goto label_137cfc;
            case 0x137D00u: goto label_137d00;
            case 0x137D04u: goto label_137d04;
            case 0x137D08u: goto label_137d08;
            case 0x137D0Cu: goto label_137d0c;
            case 0x137D10u: goto label_137d10;
            case 0x137D14u: goto label_137d14;
            case 0x137D18u: goto label_137d18;
            case 0x137D1Cu: goto label_137d1c;
            case 0x137D20u: goto label_137d20;
            case 0x137D24u: goto label_137d24;
            case 0x137D28u: goto label_137d28;
            case 0x137D2Cu: goto label_137d2c;
            case 0x137D30u: goto label_137d30;
            case 0x137D34u: goto label_137d34;
            case 0x137D38u: goto label_137d38;
            case 0x137D3Cu: goto label_137d3c;
            case 0x137D40u: goto label_137d40;
            case 0x137D44u: goto label_137d44;
            case 0x137D48u: goto label_137d48;
            case 0x137D4Cu: goto label_137d4c;
            case 0x137D50u: goto label_137d50;
            case 0x137D54u: goto label_137d54;
            case 0x137D58u: goto label_137d58;
            case 0x137D5Cu: goto label_137d5c;
            case 0x137D60u: goto label_137d60;
            case 0x137D64u: goto label_137d64;
            case 0x137D68u: goto label_137d68;
            case 0x137D6Cu: goto label_137d6c;
            case 0x137D70u: goto label_137d70;
            case 0x137D74u: goto label_137d74;
            case 0x137D78u: goto label_137d78;
            case 0x137D7Cu: goto label_137d7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137D7Cu;
label_137d7c:
    // 0x137d7c: 0x0
    ctx->pc = 0x137d7cu;
    // NOP
}
