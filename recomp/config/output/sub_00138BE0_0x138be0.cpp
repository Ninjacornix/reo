#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00138BE0
// Address: 0x138be0 - 0x138de8
void sub_00138BE0_0x138be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x138be0u;

label_138be0:
    // 0x138be0: 0x27bdffe0
    ctx->pc = 0x138be0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_138be4:
    // 0x138be4: 0x24030001
    ctx->pc = 0x138be4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
label_138be8:
    // 0x138be8: 0xffb20010
    ctx->pc = 0x138be8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_138bec:
    // 0x138bec: 0x80902d
    ctx->pc = 0x138becu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_138bf0:
    // 0x138bf0: 0xffb00000
    ctx->pc = 0x138bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_138bf4:
    // 0x138bf4: 0xffb10008
    ctx->pc = 0x138bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_138bf8:
    // 0x138bf8: 0xffbf0018
    ctx->pc = 0x138bf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_138bfc:
    // 0x138bfc: 0xa2400001
    ctx->pc = 0x138bfcu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 0));
label_138c00:
    // 0x138c00: 0x82420002
    ctx->pc = 0x138c00u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
label_138c04:
    // 0x138c04: 0x1443001d
label_138c08:
    if (ctx->pc == 0x138C08u) {
        ctx->pc = 0x138C08u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x138C0Cu;
        goto label_138c0c;
    }
    ctx->pc = 0x138C04u;
    {
        const bool branch_taken_0x138c04 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x138C08u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x138c04) {
            ctx->pc = 0x138C7Cu;
            goto label_138c7c;
        }
    }
    ctx->pc = 0x138C0Cu;
label_138c0c:
    // 0x138c0c: 0x0
    ctx->pc = 0x138c0cu;
    // NOP
label_138c10:
    // 0x138c10: 0xc045270
label_138c14:
    if (ctx->pc == 0x138C14u) {
        ctx->pc = 0x138C14u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 44)));
        ctx->pc = 0x138C18u;
        goto label_138c18;
    }
    ctx->pc = 0x138C10u;
    SET_GPR_U32(ctx, 31, 0x138C18u);
    ctx->pc = 0x138C14u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 44)));
    ctx->pc = 0x1149C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001149C0_0x1149c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138C18u; }
    }
    if (ctx->pc != 0x138C18u) { return; }
    ctx->pc = 0x138C18u;
label_138c18:
    // 0x138c18: 0x441fffd
label_138c1c:
    if (ctx->pc == 0x138C1Cu) {
        ctx->pc = 0x138C1Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 18), 12));
        ctx->pc = 0x138C20u;
        goto label_138c20;
    }
    ctx->pc = 0x138C18u;
    {
        const bool branch_taken_0x138c18 = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x138C1Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 18), 12));
        if (branch_taken_0x138c18) {
            ctx->pc = 0x138C10u;
            goto label_138c10;
        }
    }
    ctx->pc = 0x138C20u;
label_138c20:
    // 0x138c20: 0x8e440004
    ctx->pc = 0x138c20u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_138c24:
    // 0x138c24: 0x282d
    ctx->pc = 0x138c24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_138c28:
    // 0x138c28: 0x200302d
    ctx->pc = 0x138c28u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_138c2c:
    // 0x138c2c: 0x8c830000
    ctx->pc = 0x138c2cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_138c30:
    // 0x138c30: 0x8c620020
    ctx->pc = 0x138c30u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 32)));
label_138c34:
    // 0x138c34: 0x40f809
label_138c38:
    if (ctx->pc == 0x138C38u) {
        ctx->pc = 0x138C38u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 18), 20));
        ctx->pc = 0x138C3Cu;
        goto label_138c3c;
    }
    ctx->pc = 0x138C34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x138C3Cu);
        ctx->pc = 0x138C38u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 18), 20));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138BE0u: goto label_138be0;
            case 0x138BE4u: goto label_138be4;
            case 0x138BE8u: goto label_138be8;
            case 0x138BECu: goto label_138bec;
            case 0x138BF0u: goto label_138bf0;
            case 0x138BF4u: goto label_138bf4;
            case 0x138BF8u: goto label_138bf8;
            case 0x138BFCu: goto label_138bfc;
            case 0x138C00u: goto label_138c00;
            case 0x138C04u: goto label_138c04;
            case 0x138C08u: goto label_138c08;
            case 0x138C0Cu: goto label_138c0c;
            case 0x138C10u: goto label_138c10;
            case 0x138C14u: goto label_138c14;
            case 0x138C18u: goto label_138c18;
            case 0x138C1Cu: goto label_138c1c;
            case 0x138C20u: goto label_138c20;
            case 0x138C24u: goto label_138c24;
            case 0x138C28u: goto label_138c28;
            case 0x138C2Cu: goto label_138c2c;
            case 0x138C30u: goto label_138c30;
            case 0x138C34u: goto label_138c34;
            case 0x138C38u: goto label_138c38;
            case 0x138C3Cu: goto label_138c3c;
            case 0x138C40u: goto label_138c40;
            case 0x138C44u: goto label_138c44;
            case 0x138C48u: goto label_138c48;
            case 0x138C4Cu: goto label_138c4c;
            case 0x138C50u: goto label_138c50;
            case 0x138C54u: goto label_138c54;
            case 0x138C58u: goto label_138c58;
            case 0x138C5Cu: goto label_138c5c;
            case 0x138C60u: goto label_138c60;
            case 0x138C64u: goto label_138c64;
            case 0x138C68u: goto label_138c68;
            case 0x138C6Cu: goto label_138c6c;
            case 0x138C70u: goto label_138c70;
            case 0x138C74u: goto label_138c74;
            case 0x138C78u: goto label_138c78;
            case 0x138C7Cu: goto label_138c7c;
            case 0x138C80u: goto label_138c80;
            case 0x138C84u: goto label_138c84;
            case 0x138C88u: goto label_138c88;
            case 0x138C8Cu: goto label_138c8c;
            case 0x138C90u: goto label_138c90;
            case 0x138C94u: goto label_138c94;
            case 0x138C98u: goto label_138c98;
            case 0x138C9Cu: goto label_138c9c;
            case 0x138CA0u: goto label_138ca0;
            case 0x138CA4u: goto label_138ca4;
            case 0x138CA8u: goto label_138ca8;
            case 0x138CACu: goto label_138cac;
            case 0x138CB0u: goto label_138cb0;
            case 0x138CB4u: goto label_138cb4;
            case 0x138CB8u: goto label_138cb8;
            case 0x138CBCu: goto label_138cbc;
            case 0x138CC0u: goto label_138cc0;
            case 0x138CC4u: goto label_138cc4;
            case 0x138CC8u: goto label_138cc8;
            case 0x138CCCu: goto label_138ccc;
            case 0x138CD0u: goto label_138cd0;
            case 0x138CD4u: goto label_138cd4;
            case 0x138CD8u: goto label_138cd8;
            case 0x138CDCu: goto label_138cdc;
            case 0x138CE0u: goto label_138ce0;
            case 0x138CE4u: goto label_138ce4;
            case 0x138CE8u: goto label_138ce8;
            case 0x138CECu: goto label_138cec;
            case 0x138CF0u: goto label_138cf0;
            case 0x138CF4u: goto label_138cf4;
            case 0x138CF8u: goto label_138cf8;
            case 0x138CFCu: goto label_138cfc;
            case 0x138D00u: goto label_138d00;
            case 0x138D04u: goto label_138d04;
            case 0x138D08u: goto label_138d08;
            case 0x138D0Cu: goto label_138d0c;
            case 0x138D10u: goto label_138d10;
            case 0x138D14u: goto label_138d14;
            case 0x138D18u: goto label_138d18;
            case 0x138D1Cu: goto label_138d1c;
            case 0x138D20u: goto label_138d20;
            case 0x138D24u: goto label_138d24;
            case 0x138D28u: goto label_138d28;
            case 0x138D2Cu: goto label_138d2c;
            case 0x138D30u: goto label_138d30;
            case 0x138D34u: goto label_138d34;
            case 0x138D38u: goto label_138d38;
            case 0x138D3Cu: goto label_138d3c;
            case 0x138D40u: goto label_138d40;
            case 0x138D44u: goto label_138d44;
            case 0x138D48u: goto label_138d48;
            case 0x138D4Cu: goto label_138d4c;
            case 0x138D50u: goto label_138d50;
            case 0x138D54u: goto label_138d54;
            case 0x138D58u: goto label_138d58;
            case 0x138D5Cu: goto label_138d5c;
            case 0x138D60u: goto label_138d60;
            case 0x138D64u: goto label_138d64;
            case 0x138D68u: goto label_138d68;
            case 0x138D6Cu: goto label_138d6c;
            case 0x138D70u: goto label_138d70;
            case 0x138D74u: goto label_138d74;
            case 0x138D78u: goto label_138d78;
            case 0x138D7Cu: goto label_138d7c;
            case 0x138D80u: goto label_138d80;
            case 0x138D84u: goto label_138d84;
            case 0x138D88u: goto label_138d88;
            case 0x138D8Cu: goto label_138d8c;
            case 0x138D90u: goto label_138d90;
            case 0x138D94u: goto label_138d94;
            case 0x138D98u: goto label_138d98;
            case 0x138D9Cu: goto label_138d9c;
            case 0x138DA0u: goto label_138da0;
            case 0x138DA4u: goto label_138da4;
            case 0x138DA8u: goto label_138da8;
            case 0x138DACu: goto label_138dac;
            case 0x138DB0u: goto label_138db0;
            case 0x138DB4u: goto label_138db4;
            case 0x138DB8u: goto label_138db8;
            case 0x138DBCu: goto label_138dbc;
            case 0x138DC0u: goto label_138dc0;
            case 0x138DC4u: goto label_138dc4;
            case 0x138DC8u: goto label_138dc8;
            case 0x138DCCu: goto label_138dcc;
            case 0x138DD0u: goto label_138dd0;
            case 0x138DD4u: goto label_138dd4;
            case 0x138DD8u: goto label_138dd8;
            case 0x138DDCu: goto label_138ddc;
            case 0x138DE0u: goto label_138de0;
            case 0x138DE4u: goto label_138de4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x138C3Cu; }
            if (ctx->pc != 0x138C3Cu) { return; }
        }
    }
    ctx->pc = 0x138C3Cu;
label_138c3c:
    // 0x138c3c: 0xae000000
    ctx->pc = 0x138c3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_138c40:
    // 0x138c40: 0x8e440008
    ctx->pc = 0x138c40u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 8)));
label_138c44:
    // 0x138c44: 0x24050001
    ctx->pc = 0x138c44u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_138c48:
    // 0x138c48: 0xae400010
    ctx->pc = 0x138c48u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 0));
label_138c4c:
    // 0x138c4c: 0x8c830000
    ctx->pc = 0x138c4cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_138c50:
    // 0x138c50: 0x8c620020
    ctx->pc = 0x138c50u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 32)));
label_138c54:
    // 0x138c54: 0x40f809
label_138c58:
    if (ctx->pc == 0x138C58u) {
        ctx->pc = 0x138C58u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x138C5Cu;
        goto label_138c5c;
    }
    ctx->pc = 0x138C54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x138C5Cu);
        ctx->pc = 0x138C58u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138BE0u: goto label_138be0;
            case 0x138BE4u: goto label_138be4;
            case 0x138BE8u: goto label_138be8;
            case 0x138BECu: goto label_138bec;
            case 0x138BF0u: goto label_138bf0;
            case 0x138BF4u: goto label_138bf4;
            case 0x138BF8u: goto label_138bf8;
            case 0x138BFCu: goto label_138bfc;
            case 0x138C00u: goto label_138c00;
            case 0x138C04u: goto label_138c04;
            case 0x138C08u: goto label_138c08;
            case 0x138C0Cu: goto label_138c0c;
            case 0x138C10u: goto label_138c10;
            case 0x138C14u: goto label_138c14;
            case 0x138C18u: goto label_138c18;
            case 0x138C1Cu: goto label_138c1c;
            case 0x138C20u: goto label_138c20;
            case 0x138C24u: goto label_138c24;
            case 0x138C28u: goto label_138c28;
            case 0x138C2Cu: goto label_138c2c;
            case 0x138C30u: goto label_138c30;
            case 0x138C34u: goto label_138c34;
            case 0x138C38u: goto label_138c38;
            case 0x138C3Cu: goto label_138c3c;
            case 0x138C40u: goto label_138c40;
            case 0x138C44u: goto label_138c44;
            case 0x138C48u: goto label_138c48;
            case 0x138C4Cu: goto label_138c4c;
            case 0x138C50u: goto label_138c50;
            case 0x138C54u: goto label_138c54;
            case 0x138C58u: goto label_138c58;
            case 0x138C5Cu: goto label_138c5c;
            case 0x138C60u: goto label_138c60;
            case 0x138C64u: goto label_138c64;
            case 0x138C68u: goto label_138c68;
            case 0x138C6Cu: goto label_138c6c;
            case 0x138C70u: goto label_138c70;
            case 0x138C74u: goto label_138c74;
            case 0x138C78u: goto label_138c78;
            case 0x138C7Cu: goto label_138c7c;
            case 0x138C80u: goto label_138c80;
            case 0x138C84u: goto label_138c84;
            case 0x138C88u: goto label_138c88;
            case 0x138C8Cu: goto label_138c8c;
            case 0x138C90u: goto label_138c90;
            case 0x138C94u: goto label_138c94;
            case 0x138C98u: goto label_138c98;
            case 0x138C9Cu: goto label_138c9c;
            case 0x138CA0u: goto label_138ca0;
            case 0x138CA4u: goto label_138ca4;
            case 0x138CA8u: goto label_138ca8;
            case 0x138CACu: goto label_138cac;
            case 0x138CB0u: goto label_138cb0;
            case 0x138CB4u: goto label_138cb4;
            case 0x138CB8u: goto label_138cb8;
            case 0x138CBCu: goto label_138cbc;
            case 0x138CC0u: goto label_138cc0;
            case 0x138CC4u: goto label_138cc4;
            case 0x138CC8u: goto label_138cc8;
            case 0x138CCCu: goto label_138ccc;
            case 0x138CD0u: goto label_138cd0;
            case 0x138CD4u: goto label_138cd4;
            case 0x138CD8u: goto label_138cd8;
            case 0x138CDCu: goto label_138cdc;
            case 0x138CE0u: goto label_138ce0;
            case 0x138CE4u: goto label_138ce4;
            case 0x138CE8u: goto label_138ce8;
            case 0x138CECu: goto label_138cec;
            case 0x138CF0u: goto label_138cf0;
            case 0x138CF4u: goto label_138cf4;
            case 0x138CF8u: goto label_138cf8;
            case 0x138CFCu: goto label_138cfc;
            case 0x138D00u: goto label_138d00;
            case 0x138D04u: goto label_138d04;
            case 0x138D08u: goto label_138d08;
            case 0x138D0Cu: goto label_138d0c;
            case 0x138D10u: goto label_138d10;
            case 0x138D14u: goto label_138d14;
            case 0x138D18u: goto label_138d18;
            case 0x138D1Cu: goto label_138d1c;
            case 0x138D20u: goto label_138d20;
            case 0x138D24u: goto label_138d24;
            case 0x138D28u: goto label_138d28;
            case 0x138D2Cu: goto label_138d2c;
            case 0x138D30u: goto label_138d30;
            case 0x138D34u: goto label_138d34;
            case 0x138D38u: goto label_138d38;
            case 0x138D3Cu: goto label_138d3c;
            case 0x138D40u: goto label_138d40;
            case 0x138D44u: goto label_138d44;
            case 0x138D48u: goto label_138d48;
            case 0x138D4Cu: goto label_138d4c;
            case 0x138D50u: goto label_138d50;
            case 0x138D54u: goto label_138d54;
            case 0x138D58u: goto label_138d58;
            case 0x138D5Cu: goto label_138d5c;
            case 0x138D60u: goto label_138d60;
            case 0x138D64u: goto label_138d64;
            case 0x138D68u: goto label_138d68;
            case 0x138D6Cu: goto label_138d6c;
            case 0x138D70u: goto label_138d70;
            case 0x138D74u: goto label_138d74;
            case 0x138D78u: goto label_138d78;
            case 0x138D7Cu: goto label_138d7c;
            case 0x138D80u: goto label_138d80;
            case 0x138D84u: goto label_138d84;
            case 0x138D88u: goto label_138d88;
            case 0x138D8Cu: goto label_138d8c;
            case 0x138D90u: goto label_138d90;
            case 0x138D94u: goto label_138d94;
            case 0x138D98u: goto label_138d98;
            case 0x138D9Cu: goto label_138d9c;
            case 0x138DA0u: goto label_138da0;
            case 0x138DA4u: goto label_138da4;
            case 0x138DA8u: goto label_138da8;
            case 0x138DACu: goto label_138dac;
            case 0x138DB0u: goto label_138db0;
            case 0x138DB4u: goto label_138db4;
            case 0x138DB8u: goto label_138db8;
            case 0x138DBCu: goto label_138dbc;
            case 0x138DC0u: goto label_138dc0;
            case 0x138DC4u: goto label_138dc4;
            case 0x138DC8u: goto label_138dc8;
            case 0x138DCCu: goto label_138dcc;
            case 0x138DD0u: goto label_138dd0;
            case 0x138DD4u: goto label_138dd4;
            case 0x138DD8u: goto label_138dd8;
            case 0x138DDCu: goto label_138ddc;
            case 0x138DE0u: goto label_138de0;
            case 0x138DE4u: goto label_138de4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x138C5Cu; }
            if (ctx->pc != 0x138C5Cu) { return; }
        }
    }
    ctx->pc = 0x138C5Cu;
label_138c5c:
    // 0x138c5c: 0xae200000
    ctx->pc = 0x138c5cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
label_138c60:
    // 0x138c60: 0x8e42003c
    ctx->pc = 0x138c60u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 60)));
label_138c64:
    // 0x138c64: 0x8e430010
    ctx->pc = 0x138c64u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 16)));
label_138c68:
    // 0x138c68: 0xa2400002
    ctx->pc = 0x138c68u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 0));
label_138c6c:
    // 0x138c6c: 0x431021
    ctx->pc = 0x138c6cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_138c70:
    // 0x138c70: 0xae400018
    ctx->pc = 0x138c70u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 0));
label_138c74:
    // 0x138c74: 0xae42003c
    ctx->pc = 0x138c74u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 60), GPR_U32(ctx, 2));
label_138c78:
    // 0x138c78: 0xdfb00000
    ctx->pc = 0x138c78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_138c7c:
    // 0x138c7c: 0xdfb10008
    ctx->pc = 0x138c7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_138c80:
    // 0x138c80: 0xdfb20010
    ctx->pc = 0x138c80u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_138c84:
    // 0x138c84: 0xdfbf0018
    ctx->pc = 0x138c84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_138c88:
    // 0x138c88: 0x3e00008
label_138c8c:
    if (ctx->pc == 0x138C8Cu) {
        ctx->pc = 0x138C8Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x138C90u;
        goto label_138c90;
    }
    ctx->pc = 0x138C88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138C8Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138BE0u: goto label_138be0;
            case 0x138BE4u: goto label_138be4;
            case 0x138BE8u: goto label_138be8;
            case 0x138BECu: goto label_138bec;
            case 0x138BF0u: goto label_138bf0;
            case 0x138BF4u: goto label_138bf4;
            case 0x138BF8u: goto label_138bf8;
            case 0x138BFCu: goto label_138bfc;
            case 0x138C00u: goto label_138c00;
            case 0x138C04u: goto label_138c04;
            case 0x138C08u: goto label_138c08;
            case 0x138C0Cu: goto label_138c0c;
            case 0x138C10u: goto label_138c10;
            case 0x138C14u: goto label_138c14;
            case 0x138C18u: goto label_138c18;
            case 0x138C1Cu: goto label_138c1c;
            case 0x138C20u: goto label_138c20;
            case 0x138C24u: goto label_138c24;
            case 0x138C28u: goto label_138c28;
            case 0x138C2Cu: goto label_138c2c;
            case 0x138C30u: goto label_138c30;
            case 0x138C34u: goto label_138c34;
            case 0x138C38u: goto label_138c38;
            case 0x138C3Cu: goto label_138c3c;
            case 0x138C40u: goto label_138c40;
            case 0x138C44u: goto label_138c44;
            case 0x138C48u: goto label_138c48;
            case 0x138C4Cu: goto label_138c4c;
            case 0x138C50u: goto label_138c50;
            case 0x138C54u: goto label_138c54;
            case 0x138C58u: goto label_138c58;
            case 0x138C5Cu: goto label_138c5c;
            case 0x138C60u: goto label_138c60;
            case 0x138C64u: goto label_138c64;
            case 0x138C68u: goto label_138c68;
            case 0x138C6Cu: goto label_138c6c;
            case 0x138C70u: goto label_138c70;
            case 0x138C74u: goto label_138c74;
            case 0x138C78u: goto label_138c78;
            case 0x138C7Cu: goto label_138c7c;
            case 0x138C80u: goto label_138c80;
            case 0x138C84u: goto label_138c84;
            case 0x138C88u: goto label_138c88;
            case 0x138C8Cu: goto label_138c8c;
            case 0x138C90u: goto label_138c90;
            case 0x138C94u: goto label_138c94;
            case 0x138C98u: goto label_138c98;
            case 0x138C9Cu: goto label_138c9c;
            case 0x138CA0u: goto label_138ca0;
            case 0x138CA4u: goto label_138ca4;
            case 0x138CA8u: goto label_138ca8;
            case 0x138CACu: goto label_138cac;
            case 0x138CB0u: goto label_138cb0;
            case 0x138CB4u: goto label_138cb4;
            case 0x138CB8u: goto label_138cb8;
            case 0x138CBCu: goto label_138cbc;
            case 0x138CC0u: goto label_138cc0;
            case 0x138CC4u: goto label_138cc4;
            case 0x138CC8u: goto label_138cc8;
            case 0x138CCCu: goto label_138ccc;
            case 0x138CD0u: goto label_138cd0;
            case 0x138CD4u: goto label_138cd4;
            case 0x138CD8u: goto label_138cd8;
            case 0x138CDCu: goto label_138cdc;
            case 0x138CE0u: goto label_138ce0;
            case 0x138CE4u: goto label_138ce4;
            case 0x138CE8u: goto label_138ce8;
            case 0x138CECu: goto label_138cec;
            case 0x138CF0u: goto label_138cf0;
            case 0x138CF4u: goto label_138cf4;
            case 0x138CF8u: goto label_138cf8;
            case 0x138CFCu: goto label_138cfc;
            case 0x138D00u: goto label_138d00;
            case 0x138D04u: goto label_138d04;
            case 0x138D08u: goto label_138d08;
            case 0x138D0Cu: goto label_138d0c;
            case 0x138D10u: goto label_138d10;
            case 0x138D14u: goto label_138d14;
            case 0x138D18u: goto label_138d18;
            case 0x138D1Cu: goto label_138d1c;
            case 0x138D20u: goto label_138d20;
            case 0x138D24u: goto label_138d24;
            case 0x138D28u: goto label_138d28;
            case 0x138D2Cu: goto label_138d2c;
            case 0x138D30u: goto label_138d30;
            case 0x138D34u: goto label_138d34;
            case 0x138D38u: goto label_138d38;
            case 0x138D3Cu: goto label_138d3c;
            case 0x138D40u: goto label_138d40;
            case 0x138D44u: goto label_138d44;
            case 0x138D48u: goto label_138d48;
            case 0x138D4Cu: goto label_138d4c;
            case 0x138D50u: goto label_138d50;
            case 0x138D54u: goto label_138d54;
            case 0x138D58u: goto label_138d58;
            case 0x138D5Cu: goto label_138d5c;
            case 0x138D60u: goto label_138d60;
            case 0x138D64u: goto label_138d64;
            case 0x138D68u: goto label_138d68;
            case 0x138D6Cu: goto label_138d6c;
            case 0x138D70u: goto label_138d70;
            case 0x138D74u: goto label_138d74;
            case 0x138D78u: goto label_138d78;
            case 0x138D7Cu: goto label_138d7c;
            case 0x138D80u: goto label_138d80;
            case 0x138D84u: goto label_138d84;
            case 0x138D88u: goto label_138d88;
            case 0x138D8Cu: goto label_138d8c;
            case 0x138D90u: goto label_138d90;
            case 0x138D94u: goto label_138d94;
            case 0x138D98u: goto label_138d98;
            case 0x138D9Cu: goto label_138d9c;
            case 0x138DA0u: goto label_138da0;
            case 0x138DA4u: goto label_138da4;
            case 0x138DA8u: goto label_138da8;
            case 0x138DACu: goto label_138dac;
            case 0x138DB0u: goto label_138db0;
            case 0x138DB4u: goto label_138db4;
            case 0x138DB8u: goto label_138db8;
            case 0x138DBCu: goto label_138dbc;
            case 0x138DC0u: goto label_138dc0;
            case 0x138DC4u: goto label_138dc4;
            case 0x138DC8u: goto label_138dc8;
            case 0x138DCCu: goto label_138dcc;
            case 0x138DD0u: goto label_138dd0;
            case 0x138DD4u: goto label_138dd4;
            case 0x138DD8u: goto label_138dd8;
            case 0x138DDCu: goto label_138ddc;
            case 0x138DE0u: goto label_138de0;
            case 0x138DE4u: goto label_138de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138C90u;
label_138c90:
    // 0x138c90: 0x27bdffe0
    ctx->pc = 0x138c90u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_138c94:
    // 0x138c94: 0xffb00000
    ctx->pc = 0x138c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_138c98:
    // 0x138c98: 0x80802d
    ctx->pc = 0x138c98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_138c9c:
    // 0x138c9c: 0xffb10008
    ctx->pc = 0x138c9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_138ca0:
    // 0x138ca0: 0xa0882d
    ctx->pc = 0x138ca0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_138ca4:
    // 0x138ca4: 0xffb20010
    ctx->pc = 0x138ca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_138ca8:
    // 0x138ca8: 0xffbf0018
    ctx->pc = 0x138ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_138cac:
    // 0x138cac: 0xc04fc96
label_138cb0:
    if (ctx->pc == 0x138CB0u) {
        ctx->pc = 0x138CB0u;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x138CB4u;
        goto label_138cb4;
    }
    ctx->pc = 0x138CACu;
    SET_GPR_U32(ctx, 31, 0x138CB4u);
    ctx->pc = 0x138CB0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x13F258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138CB4u; }
    }
    if (ctx->pc != 0x138CB4u) { return; }
    ctx->pc = 0x138CB4u;
label_138cb4:
    // 0x138cb4: 0x24020002
    ctx->pc = 0x138cb4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
label_138cb8:
    // 0x138cb8: 0x12020007
label_138cbc:
    if (ctx->pc == 0x138CBCu) {
        ctx->pc = 0x138CBCu;
        SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 16), 2));
        ctx->pc = 0x138CC0u;
        goto label_138cc0;
    }
    ctx->pc = 0x138CB8u;
    {
        const bool branch_taken_0x138cb8 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x138CBCu;
        SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 16), 2));
        if (branch_taken_0x138cb8) {
            ctx->pc = 0x138CD8u;
            goto label_138cd8;
        }
    }
    ctx->pc = 0x138CC0u;
label_138cc0:
    // 0x138cc0: 0x1460001e
label_138cc4:
    if (ctx->pc == 0x138CC4u) {
        ctx->pc = 0x138CC4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
        ctx->pc = 0x138CC8u;
        goto label_138cc8;
    }
    ctx->pc = 0x138CC0u;
    {
        const bool branch_taken_0x138cc0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x138CC4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x138cc0) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138CC8u;
label_138cc8:
    // 0x138cc8: 0x1202000b
label_138ccc:
    if (ctx->pc == 0x138CCCu) {
        ctx->pc = 0x138CCCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 4294966272));
        ctx->pc = 0x138CD0u;
        goto label_138cd0;
    }
    ctx->pc = 0x138CC8u;
    {
        const bool branch_taken_0x138cc8 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x138CCCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 4294966272));
        if (branch_taken_0x138cc8) {
            ctx->pc = 0x138CF8u;
            goto label_138cf8;
        }
    }
    ctx->pc = 0x138CD0u;
label_138cd0:
    // 0x138cd0: 0x1000000d
label_138cd4:
    if (ctx->pc == 0x138CD4u) {
        ctx->pc = 0x138CD4u;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 2));
        ctx->pc = 0x138CD8u;
        goto label_138cd8;
    }
    ctx->pc = 0x138CD0u;
    {
        const bool branch_taken_0x138cd0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x138CD4u;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 2));
        if (branch_taken_0x138cd0) {
            ctx->pc = 0x138D08u;
            goto label_138d08;
        }
    }
    ctx->pc = 0x138CD8u;
label_138cd8:
    // 0x138cd8: 0x8e240000
    ctx->pc = 0x138cd8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_138cdc:
    // 0x138cdc: 0x8e250004
    ctx->pc = 0x138cdcu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_138ce0:
    // 0x138ce0: 0x8e260008
    ctx->pc = 0x138ce0u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 8)));
label_138ce4:
    // 0x138ce4: 0xc04e3de
label_138ce8:
    if (ctx->pc == 0x138CE8u) {
        ctx->pc = 0x138CE8u;
        SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->pc = 0x138CECu;
        goto label_138cec;
    }
    ctx->pc = 0x138CE4u;
    SET_GPR_U32(ctx, 31, 0x138CECu);
    ctx->pc = 0x138CE8u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 17), 12)));
    ctx->pc = 0x138F78u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138F78_0x138f78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138CECu; }
    }
    if (ctx->pc != 0x138CECu) { return; }
    ctx->pc = 0x138CECu;
label_138cec:
    // 0x138cec: 0x10000013
label_138cf0:
    if (ctx->pc == 0x138CF0u) {
        ctx->pc = 0x138CF0u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x138CF4u;
        goto label_138cf4;
    }
    ctx->pc = 0x138CECu;
    {
        const bool branch_taken_0x138cec = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x138CF0u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x138cec) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138CF4u;
label_138cf4:
    // 0x138cf4: 0x0
    ctx->pc = 0x138cf4u;
    // NOP
label_138cf8:
    // 0x138cf8: 0xc04e444
label_138cfc:
    if (ctx->pc == 0x138CFCu) {
        ctx->pc = 0x138CFCu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->pc = 0x138D00u;
        goto label_138d00;
    }
    ctx->pc = 0x138CF8u;
    SET_GPR_U32(ctx, 31, 0x138D00u);
    ctx->pc = 0x138CFCu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    ctx->pc = 0x139110u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00139110_0x139110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D00u; }
    }
    if (ctx->pc != 0x138D00u) { return; }
    ctx->pc = 0x138D00u;
label_138d00:
    // 0x138d00: 0x1000000e
label_138d04:
    if (ctx->pc == 0x138D04u) {
        ctx->pc = 0x138D08u;
        goto label_138d08;
    }
    ctx->pc = 0x138D00u;
    {
        const bool branch_taken_0x138d00 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x138d00) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138D08u;
label_138d08:
    // 0x138d08: 0x2c420040
    ctx->pc = 0x138d08u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 64));
label_138d0c:
    // 0x138d0c: 0x1040000b
label_138d10:
    if (ctx->pc == 0x138D10u) {
        ctx->pc = 0x138D14u;
        goto label_138d14;
    }
    ctx->pc = 0x138D0Cu;
    {
        const bool branch_taken_0x138d0c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x138d0c) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138D14u;
label_138d14:
    // 0x138d14: 0x3c020022
    ctx->pc = 0x138d14u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_138d18:
    // 0x138d18: 0x431021
    ctx->pc = 0x138d18u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_138d1c:
    // 0x138d1c: 0x8c42c9e0
    ctx->pc = 0x138d1cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4294953440)));
label_138d20:
    // 0x138d20: 0x10400006
label_138d24:
    if (ctx->pc == 0x138D24u) {
        ctx->pc = 0x138D24u;
        SET_GPR_U32(ctx, 6, SRL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x138D28u;
        goto label_138d28;
    }
    ctx->pc = 0x138D20u;
    {
        const bool branch_taken_0x138d20 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x138D24u;
        SET_GPR_U32(ctx, 6, SRL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x138d20) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138D28u;
label_138d28:
    // 0x138d28: 0x3c040022
    ctx->pc = 0x138d28u;
    SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
label_138d2c:
    // 0x138d2c: 0x832021
    ctx->pc = 0x138d2cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_138d30:
    // 0x138d30: 0x8c84cae0
    ctx->pc = 0x138d30u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 4294953696)));
label_138d34:
    // 0x138d34: 0x40f809
label_138d38:
    if (ctx->pc == 0x138D38u) {
        ctx->pc = 0x138D38u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x138D3Cu;
        goto label_138d3c;
    }
    ctx->pc = 0x138D34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x138D3Cu);
        ctx->pc = 0x138D38u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138BE0u: goto label_138be0;
            case 0x138BE4u: goto label_138be4;
            case 0x138BE8u: goto label_138be8;
            case 0x138BECu: goto label_138bec;
            case 0x138BF0u: goto label_138bf0;
            case 0x138BF4u: goto label_138bf4;
            case 0x138BF8u: goto label_138bf8;
            case 0x138BFCu: goto label_138bfc;
            case 0x138C00u: goto label_138c00;
            case 0x138C04u: goto label_138c04;
            case 0x138C08u: goto label_138c08;
            case 0x138C0Cu: goto label_138c0c;
            case 0x138C10u: goto label_138c10;
            case 0x138C14u: goto label_138c14;
            case 0x138C18u: goto label_138c18;
            case 0x138C1Cu: goto label_138c1c;
            case 0x138C20u: goto label_138c20;
            case 0x138C24u: goto label_138c24;
            case 0x138C28u: goto label_138c28;
            case 0x138C2Cu: goto label_138c2c;
            case 0x138C30u: goto label_138c30;
            case 0x138C34u: goto label_138c34;
            case 0x138C38u: goto label_138c38;
            case 0x138C3Cu: goto label_138c3c;
            case 0x138C40u: goto label_138c40;
            case 0x138C44u: goto label_138c44;
            case 0x138C48u: goto label_138c48;
            case 0x138C4Cu: goto label_138c4c;
            case 0x138C50u: goto label_138c50;
            case 0x138C54u: goto label_138c54;
            case 0x138C58u: goto label_138c58;
            case 0x138C5Cu: goto label_138c5c;
            case 0x138C60u: goto label_138c60;
            case 0x138C64u: goto label_138c64;
            case 0x138C68u: goto label_138c68;
            case 0x138C6Cu: goto label_138c6c;
            case 0x138C70u: goto label_138c70;
            case 0x138C74u: goto label_138c74;
            case 0x138C78u: goto label_138c78;
            case 0x138C7Cu: goto label_138c7c;
            case 0x138C80u: goto label_138c80;
            case 0x138C84u: goto label_138c84;
            case 0x138C88u: goto label_138c88;
            case 0x138C8Cu: goto label_138c8c;
            case 0x138C90u: goto label_138c90;
            case 0x138C94u: goto label_138c94;
            case 0x138C98u: goto label_138c98;
            case 0x138C9Cu: goto label_138c9c;
            case 0x138CA0u: goto label_138ca0;
            case 0x138CA4u: goto label_138ca4;
            case 0x138CA8u: goto label_138ca8;
            case 0x138CACu: goto label_138cac;
            case 0x138CB0u: goto label_138cb0;
            case 0x138CB4u: goto label_138cb4;
            case 0x138CB8u: goto label_138cb8;
            case 0x138CBCu: goto label_138cbc;
            case 0x138CC0u: goto label_138cc0;
            case 0x138CC4u: goto label_138cc4;
            case 0x138CC8u: goto label_138cc8;
            case 0x138CCCu: goto label_138ccc;
            case 0x138CD0u: goto label_138cd0;
            case 0x138CD4u: goto label_138cd4;
            case 0x138CD8u: goto label_138cd8;
            case 0x138CDCu: goto label_138cdc;
            case 0x138CE0u: goto label_138ce0;
            case 0x138CE4u: goto label_138ce4;
            case 0x138CE8u: goto label_138ce8;
            case 0x138CECu: goto label_138cec;
            case 0x138CF0u: goto label_138cf0;
            case 0x138CF4u: goto label_138cf4;
            case 0x138CF8u: goto label_138cf8;
            case 0x138CFCu: goto label_138cfc;
            case 0x138D00u: goto label_138d00;
            case 0x138D04u: goto label_138d04;
            case 0x138D08u: goto label_138d08;
            case 0x138D0Cu: goto label_138d0c;
            case 0x138D10u: goto label_138d10;
            case 0x138D14u: goto label_138d14;
            case 0x138D18u: goto label_138d18;
            case 0x138D1Cu: goto label_138d1c;
            case 0x138D20u: goto label_138d20;
            case 0x138D24u: goto label_138d24;
            case 0x138D28u: goto label_138d28;
            case 0x138D2Cu: goto label_138d2c;
            case 0x138D30u: goto label_138d30;
            case 0x138D34u: goto label_138d34;
            case 0x138D38u: goto label_138d38;
            case 0x138D3Cu: goto label_138d3c;
            case 0x138D40u: goto label_138d40;
            case 0x138D44u: goto label_138d44;
            case 0x138D48u: goto label_138d48;
            case 0x138D4Cu: goto label_138d4c;
            case 0x138D50u: goto label_138d50;
            case 0x138D54u: goto label_138d54;
            case 0x138D58u: goto label_138d58;
            case 0x138D5Cu: goto label_138d5c;
            case 0x138D60u: goto label_138d60;
            case 0x138D64u: goto label_138d64;
            case 0x138D68u: goto label_138d68;
            case 0x138D6Cu: goto label_138d6c;
            case 0x138D70u: goto label_138d70;
            case 0x138D74u: goto label_138d74;
            case 0x138D78u: goto label_138d78;
            case 0x138D7Cu: goto label_138d7c;
            case 0x138D80u: goto label_138d80;
            case 0x138D84u: goto label_138d84;
            case 0x138D88u: goto label_138d88;
            case 0x138D8Cu: goto label_138d8c;
            case 0x138D90u: goto label_138d90;
            case 0x138D94u: goto label_138d94;
            case 0x138D98u: goto label_138d98;
            case 0x138D9Cu: goto label_138d9c;
            case 0x138DA0u: goto label_138da0;
            case 0x138DA4u: goto label_138da4;
            case 0x138DA8u: goto label_138da8;
            case 0x138DACu: goto label_138dac;
            case 0x138DB0u: goto label_138db0;
            case 0x138DB4u: goto label_138db4;
            case 0x138DB8u: goto label_138db8;
            case 0x138DBCu: goto label_138dbc;
            case 0x138DC0u: goto label_138dc0;
            case 0x138DC4u: goto label_138dc4;
            case 0x138DC8u: goto label_138dc8;
            case 0x138DCCu: goto label_138dcc;
            case 0x138DD0u: goto label_138dd0;
            case 0x138DD4u: goto label_138dd4;
            case 0x138DD8u: goto label_138dd8;
            case 0x138DDCu: goto label_138ddc;
            case 0x138DE0u: goto label_138de0;
            case 0x138DE4u: goto label_138de4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x138D3Cu; }
            if (ctx->pc != 0x138D3Cu) { return; }
        }
    }
    ctx->pc = 0x138D3Cu;
label_138d3c:
    // 0x138d3c: 0xc04fc9c
label_138d40:
    if (ctx->pc == 0x138D40u) {
        ctx->pc = 0x138D44u;
        goto label_138d44;
    }
    ctx->pc = 0x138D3Cu;
    SET_GPR_U32(ctx, 31, 0x138D44u);
    ctx->pc = 0x13F270u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D44u; }
    }
    if (ctx->pc != 0x138D44u) { return; }
    ctx->pc = 0x138D44u;
label_138d44:
    // 0x138d44: 0x220102d
    ctx->pc = 0x138d44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_138d48:
    // 0x138d48: 0xdfb00000
    ctx->pc = 0x138d48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_138d4c:
    // 0x138d4c: 0xdfb10008
    ctx->pc = 0x138d4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_138d50:
    // 0x138d50: 0xdfb20010
    ctx->pc = 0x138d50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_138d54:
    // 0x138d54: 0xdfbf0018
    ctx->pc = 0x138d54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_138d58:
    // 0x138d58: 0x3e00008
label_138d5c:
    if (ctx->pc == 0x138D5Cu) {
        ctx->pc = 0x138D5Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x138D60u;
        goto label_138d60;
    }
    ctx->pc = 0x138D58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138D5Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138BE0u: goto label_138be0;
            case 0x138BE4u: goto label_138be4;
            case 0x138BE8u: goto label_138be8;
            case 0x138BECu: goto label_138bec;
            case 0x138BF0u: goto label_138bf0;
            case 0x138BF4u: goto label_138bf4;
            case 0x138BF8u: goto label_138bf8;
            case 0x138BFCu: goto label_138bfc;
            case 0x138C00u: goto label_138c00;
            case 0x138C04u: goto label_138c04;
            case 0x138C08u: goto label_138c08;
            case 0x138C0Cu: goto label_138c0c;
            case 0x138C10u: goto label_138c10;
            case 0x138C14u: goto label_138c14;
            case 0x138C18u: goto label_138c18;
            case 0x138C1Cu: goto label_138c1c;
            case 0x138C20u: goto label_138c20;
            case 0x138C24u: goto label_138c24;
            case 0x138C28u: goto label_138c28;
            case 0x138C2Cu: goto label_138c2c;
            case 0x138C30u: goto label_138c30;
            case 0x138C34u: goto label_138c34;
            case 0x138C38u: goto label_138c38;
            case 0x138C3Cu: goto label_138c3c;
            case 0x138C40u: goto label_138c40;
            case 0x138C44u: goto label_138c44;
            case 0x138C48u: goto label_138c48;
            case 0x138C4Cu: goto label_138c4c;
            case 0x138C50u: goto label_138c50;
            case 0x138C54u: goto label_138c54;
            case 0x138C58u: goto label_138c58;
            case 0x138C5Cu: goto label_138c5c;
            case 0x138C60u: goto label_138c60;
            case 0x138C64u: goto label_138c64;
            case 0x138C68u: goto label_138c68;
            case 0x138C6Cu: goto label_138c6c;
            case 0x138C70u: goto label_138c70;
            case 0x138C74u: goto label_138c74;
            case 0x138C78u: goto label_138c78;
            case 0x138C7Cu: goto label_138c7c;
            case 0x138C80u: goto label_138c80;
            case 0x138C84u: goto label_138c84;
            case 0x138C88u: goto label_138c88;
            case 0x138C8Cu: goto label_138c8c;
            case 0x138C90u: goto label_138c90;
            case 0x138C94u: goto label_138c94;
            case 0x138C98u: goto label_138c98;
            case 0x138C9Cu: goto label_138c9c;
            case 0x138CA0u: goto label_138ca0;
            case 0x138CA4u: goto label_138ca4;
            case 0x138CA8u: goto label_138ca8;
            case 0x138CACu: goto label_138cac;
            case 0x138CB0u: goto label_138cb0;
            case 0x138CB4u: goto label_138cb4;
            case 0x138CB8u: goto label_138cb8;
            case 0x138CBCu: goto label_138cbc;
            case 0x138CC0u: goto label_138cc0;
            case 0x138CC4u: goto label_138cc4;
            case 0x138CC8u: goto label_138cc8;
            case 0x138CCCu: goto label_138ccc;
            case 0x138CD0u: goto label_138cd0;
            case 0x138CD4u: goto label_138cd4;
            case 0x138CD8u: goto label_138cd8;
            case 0x138CDCu: goto label_138cdc;
            case 0x138CE0u: goto label_138ce0;
            case 0x138CE4u: goto label_138ce4;
            case 0x138CE8u: goto label_138ce8;
            case 0x138CECu: goto label_138cec;
            case 0x138CF0u: goto label_138cf0;
            case 0x138CF4u: goto label_138cf4;
            case 0x138CF8u: goto label_138cf8;
            case 0x138CFCu: goto label_138cfc;
            case 0x138D00u: goto label_138d00;
            case 0x138D04u: goto label_138d04;
            case 0x138D08u: goto label_138d08;
            case 0x138D0Cu: goto label_138d0c;
            case 0x138D10u: goto label_138d10;
            case 0x138D14u: goto label_138d14;
            case 0x138D18u: goto label_138d18;
            case 0x138D1Cu: goto label_138d1c;
            case 0x138D20u: goto label_138d20;
            case 0x138D24u: goto label_138d24;
            case 0x138D28u: goto label_138d28;
            case 0x138D2Cu: goto label_138d2c;
            case 0x138D30u: goto label_138d30;
            case 0x138D34u: goto label_138d34;
            case 0x138D38u: goto label_138d38;
            case 0x138D3Cu: goto label_138d3c;
            case 0x138D40u: goto label_138d40;
            case 0x138D44u: goto label_138d44;
            case 0x138D48u: goto label_138d48;
            case 0x138D4Cu: goto label_138d4c;
            case 0x138D50u: goto label_138d50;
            case 0x138D54u: goto label_138d54;
            case 0x138D58u: goto label_138d58;
            case 0x138D5Cu: goto label_138d5c;
            case 0x138D60u: goto label_138d60;
            case 0x138D64u: goto label_138d64;
            case 0x138D68u: goto label_138d68;
            case 0x138D6Cu: goto label_138d6c;
            case 0x138D70u: goto label_138d70;
            case 0x138D74u: goto label_138d74;
            case 0x138D78u: goto label_138d78;
            case 0x138D7Cu: goto label_138d7c;
            case 0x138D80u: goto label_138d80;
            case 0x138D84u: goto label_138d84;
            case 0x138D88u: goto label_138d88;
            case 0x138D8Cu: goto label_138d8c;
            case 0x138D90u: goto label_138d90;
            case 0x138D94u: goto label_138d94;
            case 0x138D98u: goto label_138d98;
            case 0x138D9Cu: goto label_138d9c;
            case 0x138DA0u: goto label_138da0;
            case 0x138DA4u: goto label_138da4;
            case 0x138DA8u: goto label_138da8;
            case 0x138DACu: goto label_138dac;
            case 0x138DB0u: goto label_138db0;
            case 0x138DB4u: goto label_138db4;
            case 0x138DB8u: goto label_138db8;
            case 0x138DBCu: goto label_138dbc;
            case 0x138DC0u: goto label_138dc0;
            case 0x138DC4u: goto label_138dc4;
            case 0x138DC8u: goto label_138dc8;
            case 0x138DCCu: goto label_138dcc;
            case 0x138DD0u: goto label_138dd0;
            case 0x138DD4u: goto label_138dd4;
            case 0x138DD8u: goto label_138dd8;
            case 0x138DDCu: goto label_138ddc;
            case 0x138DE0u: goto label_138de0;
            case 0x138DE4u: goto label_138de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138D60u;
label_138d60:
    // 0x138d60: 0x27bdffb0
    ctx->pc = 0x138d60u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
label_138d64:
    // 0x138d64: 0xffbf0040
    ctx->pc = 0x138d64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
label_138d68:
    // 0x138d68: 0xc045144
label_138d6c:
    if (ctx->pc == 0x138D6Cu) {
        ctx->pc = 0x138D70u;
        goto label_138d70;
    }
    ctx->pc = 0x138D68u;
    SET_GPR_U32(ctx, 31, 0x138D70u);
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D70u; }
    }
    if (ctx->pc != 0x138D70u) { return; }
    ctx->pc = 0x138D70u;
label_138d70:
    // 0x138d70: 0x3a0202d
    ctx->pc = 0x138d70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_138d74:
    // 0x138d74: 0xc045f08
label_138d78:
    if (ctx->pc == 0x138D78u) {
        ctx->pc = 0x138D78u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x138D7Cu;
        goto label_138d7c;
    }
    ctx->pc = 0x138D74u;
    SET_GPR_U32(ctx, 31, 0x138D7Cu);
    ctx->pc = 0x138D78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117C20u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117C20_0x117c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D7Cu; }
    }
    if (ctx->pc != 0x138D7Cu) { return; }
    ctx->pc = 0x138D7Cu;
label_138d7c:
    // 0x138d7c: 0xc045144
label_138d80:
    if (ctx->pc == 0x138D80u) {
        ctx->pc = 0x138D84u;
        goto label_138d84;
    }
    ctx->pc = 0x138D7Cu;
    SET_GPR_U32(ctx, 31, 0x138D84u);
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D84u; }
    }
    if (ctx->pc != 0x138D84u) { return; }
    ctx->pc = 0x138D84u;
label_138d84:
    // 0x138d84: 0x27a40020
    ctx->pc = 0x138d84u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
label_138d88:
    // 0x138d88: 0xc045f08
label_138d8c:
    if (ctx->pc == 0x138D8Cu) {
        ctx->pc = 0x138D8Cu;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x138D90u;
        goto label_138d90;
    }
    ctx->pc = 0x138D88u;
    SET_GPR_U32(ctx, 31, 0x138D90u);
    ctx->pc = 0x138D8Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117C20u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117C20_0x117c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D90u; }
    }
    if (ctx->pc != 0x138D90u) { return; }
    ctx->pc = 0x138D90u;
label_138d90:
    // 0x138d90: 0x3c040022
    ctx->pc = 0x138d90u;
    SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
label_138d94:
    // 0x138d94: 0x3c020022
    ctx->pc = 0x138d94u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_138d98:
    // 0x138d98: 0x3c060014
    ctx->pc = 0x138d98u;
    SET_GPR_U32(ctx, 6, ((uint32_t)20 << 16));
label_138d9c:
    // 0x138d9c: 0x8c45c414
    ctx->pc = 0x138d9cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 4294951956)));
label_138da0:
    // 0x138da0: 0x3c070022
    ctx->pc = 0x138da0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)34 << 16));
label_138da4:
    // 0x138da4: 0x24c68c90
    ctx->pc = 0x138da4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 4294937744));
label_138da8:
    // 0x138da8: 0x24e7c8e0
    ctx->pc = 0x138da8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294953184));
label_138dac:
    // 0x138dac: 0x402d
    ctx->pc = 0x138dacu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_138db0:
    // 0x138db0: 0x482d
    ctx->pc = 0x138db0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_138db4:
    // 0x138db4: 0x3a0502d
    ctx->pc = 0x138db4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_138db8:
    // 0x138db8: 0xc045f2e
label_138dbc:
    if (ctx->pc == 0x138DBCu) {
        ctx->pc = 0x138DBCu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294953112));
        ctx->pc = 0x138DC0u;
        goto label_138dc0;
    }
    ctx->pc = 0x138DB8u;
    SET_GPR_U32(ctx, 31, 0x138DC0u);
    ctx->pc = 0x138DBCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294953112));
    ctx->pc = 0x117CB8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117CB8_0x117cb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138DC0u; }
    }
    if (ctx->pc != 0x138DC0u) { return; }
    ctx->pc = 0x138DC0u;
label_138dc0:
    // 0x138dc0: 0x3c020022
    ctx->pc = 0x138dc0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_138dc4:
    // 0x138dc4: 0x2442c418
    ctx->pc = 0x138dc4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294951960));
label_138dc8:
    // 0x138dc8: 0x24030001
    ctx->pc = 0x138dc8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
label_138dcc:
    // 0x138dcc: 0x0
    ctx->pc = 0x138dccu;
    // NOP
label_138dd0:
    // 0x138dd0: 0xc046034
label_138dd4:
    if (ctx->pc == 0x138DD4u) {
        ctx->pc = 0x138DD4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x138DD8u;
        goto label_138dd8;
    }
    ctx->pc = 0x138DD0u;
    SET_GPR_U32(ctx, 31, 0x138DD8u);
    ctx->pc = 0x138DD4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1180D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001180D0_0x1180d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138DD8u; }
    }
    if (ctx->pc != 0x138DD8u) { return; }
    ctx->pc = 0x138DD8u;
label_138dd8:
    // 0x138dd8: 0x102d
    ctx->pc = 0x138dd8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_138ddc:
    // 0x138ddc: 0xdfbf0040
    ctx->pc = 0x138ddcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_138de0:
    // 0x138de0: 0x3e00008
label_138de4:
    if (ctx->pc == 0x138DE4u) {
        ctx->pc = 0x138DE4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = 0x138DE8u;
        goto label_fallthrough_0x138de0;
    }
    ctx->pc = 0x138DE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138DE4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138BE0u: goto label_138be0;
            case 0x138BE4u: goto label_138be4;
            case 0x138BE8u: goto label_138be8;
            case 0x138BECu: goto label_138bec;
            case 0x138BF0u: goto label_138bf0;
            case 0x138BF4u: goto label_138bf4;
            case 0x138BF8u: goto label_138bf8;
            case 0x138BFCu: goto label_138bfc;
            case 0x138C00u: goto label_138c00;
            case 0x138C04u: goto label_138c04;
            case 0x138C08u: goto label_138c08;
            case 0x138C0Cu: goto label_138c0c;
            case 0x138C10u: goto label_138c10;
            case 0x138C14u: goto label_138c14;
            case 0x138C18u: goto label_138c18;
            case 0x138C1Cu: goto label_138c1c;
            case 0x138C20u: goto label_138c20;
            case 0x138C24u: goto label_138c24;
            case 0x138C28u: goto label_138c28;
            case 0x138C2Cu: goto label_138c2c;
            case 0x138C30u: goto label_138c30;
            case 0x138C34u: goto label_138c34;
            case 0x138C38u: goto label_138c38;
            case 0x138C3Cu: goto label_138c3c;
            case 0x138C40u: goto label_138c40;
            case 0x138C44u: goto label_138c44;
            case 0x138C48u: goto label_138c48;
            case 0x138C4Cu: goto label_138c4c;
            case 0x138C50u: goto label_138c50;
            case 0x138C54u: goto label_138c54;
            case 0x138C58u: goto label_138c58;
            case 0x138C5Cu: goto label_138c5c;
            case 0x138C60u: goto label_138c60;
            case 0x138C64u: goto label_138c64;
            case 0x138C68u: goto label_138c68;
            case 0x138C6Cu: goto label_138c6c;
            case 0x138C70u: goto label_138c70;
            case 0x138C74u: goto label_138c74;
            case 0x138C78u: goto label_138c78;
            case 0x138C7Cu: goto label_138c7c;
            case 0x138C80u: goto label_138c80;
            case 0x138C84u: goto label_138c84;
            case 0x138C88u: goto label_138c88;
            case 0x138C8Cu: goto label_138c8c;
            case 0x138C90u: goto label_138c90;
            case 0x138C94u: goto label_138c94;
            case 0x138C98u: goto label_138c98;
            case 0x138C9Cu: goto label_138c9c;
            case 0x138CA0u: goto label_138ca0;
            case 0x138CA4u: goto label_138ca4;
            case 0x138CA8u: goto label_138ca8;
            case 0x138CACu: goto label_138cac;
            case 0x138CB0u: goto label_138cb0;
            case 0x138CB4u: goto label_138cb4;
            case 0x138CB8u: goto label_138cb8;
            case 0x138CBCu: goto label_138cbc;
            case 0x138CC0u: goto label_138cc0;
            case 0x138CC4u: goto label_138cc4;
            case 0x138CC8u: goto label_138cc8;
            case 0x138CCCu: goto label_138ccc;
            case 0x138CD0u: goto label_138cd0;
            case 0x138CD4u: goto label_138cd4;
            case 0x138CD8u: goto label_138cd8;
            case 0x138CDCu: goto label_138cdc;
            case 0x138CE0u: goto label_138ce0;
            case 0x138CE4u: goto label_138ce4;
            case 0x138CE8u: goto label_138ce8;
            case 0x138CECu: goto label_138cec;
            case 0x138CF0u: goto label_138cf0;
            case 0x138CF4u: goto label_138cf4;
            case 0x138CF8u: goto label_138cf8;
            case 0x138CFCu: goto label_138cfc;
            case 0x138D00u: goto label_138d00;
            case 0x138D04u: goto label_138d04;
            case 0x138D08u: goto label_138d08;
            case 0x138D0Cu: goto label_138d0c;
            case 0x138D10u: goto label_138d10;
            case 0x138D14u: goto label_138d14;
            case 0x138D18u: goto label_138d18;
            case 0x138D1Cu: goto label_138d1c;
            case 0x138D20u: goto label_138d20;
            case 0x138D24u: goto label_138d24;
            case 0x138D28u: goto label_138d28;
            case 0x138D2Cu: goto label_138d2c;
            case 0x138D30u: goto label_138d30;
            case 0x138D34u: goto label_138d34;
            case 0x138D38u: goto label_138d38;
            case 0x138D3Cu: goto label_138d3c;
            case 0x138D40u: goto label_138d40;
            case 0x138D44u: goto label_138d44;
            case 0x138D48u: goto label_138d48;
            case 0x138D4Cu: goto label_138d4c;
            case 0x138D50u: goto label_138d50;
            case 0x138D54u: goto label_138d54;
            case 0x138D58u: goto label_138d58;
            case 0x138D5Cu: goto label_138d5c;
            case 0x138D60u: goto label_138d60;
            case 0x138D64u: goto label_138d64;
            case 0x138D68u: goto label_138d68;
            case 0x138D6Cu: goto label_138d6c;
            case 0x138D70u: goto label_138d70;
            case 0x138D74u: goto label_138d74;
            case 0x138D78u: goto label_138d78;
            case 0x138D7Cu: goto label_138d7c;
            case 0x138D80u: goto label_138d80;
            case 0x138D84u: goto label_138d84;
            case 0x138D88u: goto label_138d88;
            case 0x138D8Cu: goto label_138d8c;
            case 0x138D90u: goto label_138d90;
            case 0x138D94u: goto label_138d94;
            case 0x138D98u: goto label_138d98;
            case 0x138D9Cu: goto label_138d9c;
            case 0x138DA0u: goto label_138da0;
            case 0x138DA4u: goto label_138da4;
            case 0x138DA8u: goto label_138da8;
            case 0x138DACu: goto label_138dac;
            case 0x138DB0u: goto label_138db0;
            case 0x138DB4u: goto label_138db4;
            case 0x138DB8u: goto label_138db8;
            case 0x138DBCu: goto label_138dbc;
            case 0x138DC0u: goto label_138dc0;
            case 0x138DC4u: goto label_138dc4;
            case 0x138DC8u: goto label_138dc8;
            case 0x138DCCu: goto label_138dcc;
            case 0x138DD0u: goto label_138dd0;
            case 0x138DD4u: goto label_138dd4;
            case 0x138DD8u: goto label_138dd8;
            case 0x138DDCu: goto label_138ddc;
            case 0x138DE0u: goto label_138de0;
            case 0x138DE4u: goto label_138de4;
            default: break;
        }
        return;
    }
label_fallthrough_0x138de0:
    ctx->pc = 0x138DE8u;
}
