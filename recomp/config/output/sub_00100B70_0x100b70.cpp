#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00100B70
// Address: 0x100b70 - 0x100ce0
void sub_00100B70_0x100b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x100b70u;

    // 0x100b70: 0x27bdffc0
    ctx->pc = 0x100b70u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x100b74: 0xffb10010
    ctx->pc = 0x100b74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100b78: 0xffb00000
    ctx->pc = 0x100b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x100b7c: 0x80882d
    ctx->pc = 0x100b7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100b80: 0xffbf0030
    ctx->pc = 0x100b80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x100b84: 0x3c100020
    ctx->pc = 0x100b84u;
    SET_GPR_U32(ctx, 16, ((uint32_t)32 << 16));
    // 0x100b88: 0xc040164
    ctx->pc = 0x100B88u;
    SET_GPR_U32(ctx, 31, 0x100B90u);
    ctx->pc = 0x100B8Cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    ctx->pc = 0x100590u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B90u; }
    }
    if (ctx->pc != 0x100B90u) { return; }
    ctx->pc = 0x100B90u;
    // 0x100b90: 0x8e047928
    ctx->pc = 0x100b90u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 31016)));
    // 0x100b94: 0xc04519c
    ctx->pc = 0x100B94u;
    SET_GPR_U32(ctx, 31, 0x100B9Cu);
    ctx->pc = 0x114670u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B9Cu; }
    }
    if (ctx->pc != 0x100B9Cu) { return; }
    ctx->pc = 0x100B9Cu;
    // 0x100b9c: 0x8e037928
    ctx->pc = 0x100b9cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 31016)));
    // 0x100ba0: 0x1062000b
    ctx->pc = 0x100BA0u;
    {
        const bool branch_taken_0x100ba0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x100BA4u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x100ba0) {
            ctx->pc = 0x100BD0u;
            goto label_100bd0;
        }
    }
    ctx->pc = 0x100BA8u;
    // 0x100ba8: 0x8c437910
    ctx->pc = 0x100ba8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100bac: 0x18600016
    ctx->pc = 0x100BACu;
    {
        const bool branch_taken_0x100bac = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x100BB0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x100bac) {
            ctx->pc = 0x100C08u;
            goto label_100c08;
        }
    }
    ctx->pc = 0x100BB4u;
    // 0x100bb4: 0x3c040023
    ctx->pc = 0x100bb4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x100bb8: 0x8c46791c
    ctx->pc = 0x100bb8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 31004)));
    // 0x100bbc: 0x24847518
    ctx->pc = 0x100bbcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 29976));
    // 0x100bc0: 0xc045a12
    ctx->pc = 0x100BC0u;
    SET_GPR_U32(ctx, 31, 0x100BC8u);
    ctx->pc = 0x100BC4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100BC8u; }
    }
    if (ctx->pc != 0x100BC8u) { return; }
    ctx->pc = 0x100BC8u;
    // 0x100bc8: 0x1000003f
    ctx->pc = 0x100BC8u;
    {
        const bool branch_taken_0x100bc8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100BCCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x100bc8) {
            ctx->pc = 0x100CC8u;
            goto label_100cc8;
        }
    }
    ctx->pc = 0x100BD0u;
label_100bd0:
    // 0x100bd0: 0x3c020026
    ctx->pc = 0x100bd0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
    // 0x100bd4: 0x3c030020
    ctx->pc = 0x100bd4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
    // 0x100bd8: 0x8c449f98
    ctx->pc = 0x100bd8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294942616)));
    // 0x100bdc: 0x3c050026
    ctx->pc = 0x100bdcu;
    SET_GPR_U32(ctx, 5, ((uint32_t)38 << 16));
    // 0x100be0: 0x0
    ctx->pc = 0x100be0u;
    // NOP
    // 0x100be4: 0xc045148
    ctx->pc = 0x100BE4u;
    SET_GPR_U32(ctx, 31, 0x100BECu);
    ctx->pc = 0x100BE8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294942624));
    ctx->pc = 0x114520u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100BECu; }
    }
    if (ctx->pc != 0x100BECu) { return; }
    ctx->pc = 0x100BECu;
    // 0x100bec: 0xc04035e
    ctx->pc = 0x100BECu;
    SET_GPR_U32(ctx, 31, 0x100BF4u);
    ctx->pc = 0x100BF0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x100D78u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100BF4u; }
    }
    if (ctx->pc != 0x100BF4u) { return; }
    ctx->pc = 0x100BF4u;
    // 0x100bf4: 0x10400006
    ctx->pc = 0x100BF4u;
    {
        const bool branch_taken_0x100bf4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x100BF8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x100bf4) {
            ctx->pc = 0x100C10u;
            goto label_100c10;
        }
    }
    ctx->pc = 0x100BFCu;
    // 0x100bfc: 0x8e047928
    ctx->pc = 0x100bfcu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 31016)));
    // 0x100c00: 0xc045190
    ctx->pc = 0x100C00u;
    SET_GPR_U32(ctx, 31, 0x100C08u);
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C08u; }
    }
    if (ctx->pc != 0x100C08u) { return; }
    ctx->pc = 0x100C08u;
label_100c08:
    // 0x100c08: 0x1000002f
    ctx->pc = 0x100C08u;
    {
        const bool branch_taken_0x100c08 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100C0Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x100c08) {
            ctx->pc = 0x100CC8u;
            goto label_100cc8;
        }
    }
    ctx->pc = 0x100C10u;
label_100c10:
    // 0x100c10: 0xc045c20
    ctx->pc = 0x100C10u;
    SET_GPR_U32(ctx, 31, 0x100C18u);
    ctx->pc = 0x100C14u;
    SET_GPR_U32(ctx, 18, ((uint32_t)32 << 16));
    ctx->pc = 0x117080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C18u; }
    }
    if (ctx->pc != 0x100C18u) { return; }
    ctx->pc = 0x100C18u;
    // 0x100c18: 0x8e42793c
    ctx->pc = 0x100c18u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 31036)));
    // 0x100c1c: 0x441002a
    ctx->pc = 0x100C1Cu;
    {
        const bool branch_taken_0x100c1c = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x100C20u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x100c1c) {
            ctx->pc = 0x100CC8u;
            goto label_100cc8;
        }
    }
    ctx->pc = 0x100C24u;
    // 0x100c24: 0x1000000b
    ctx->pc = 0x100C24u;
    {
        const bool branch_taken_0x100c24 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100C28u;
        SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
        if (branch_taken_0x100c24) {
            ctx->pc = 0x100C54u;
            goto label_100c54;
        }
    }
    ctx->pc = 0x100C2Cu;
    // 0x100c2c: 0x0
    ctx->pc = 0x100c2cu;
    // NOP
label_100c30:
    // 0x100c30: 0x3c020010
    ctx->pc = 0x100c30u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
    // 0x100c34: 0x2403ffff
    ctx->pc = 0x100c34u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_100c38:
    // 0x100c38: 0x2442ffff
    ctx->pc = 0x100c38u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100c3c: 0x0
    ctx->pc = 0x100c3cu;
    // NOP
    // 0x100c40: 0x0
    ctx->pc = 0x100c40u;
    // NOP
    // 0x100c44: 0x0
    ctx->pc = 0x100c44u;
    // NOP
    // 0x100c48: 0x0
    ctx->pc = 0x100c48u;
    // NOP
    // 0x100c4c: 0x1443fffa
    ctx->pc = 0x100C4Cu;
    {
        const bool branch_taken_0x100c4c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x100c4c) {
            ctx->pc = 0x100C38u;
            goto label_100c38;
        }
    }
    ctx->pc = 0x100C54u;
label_100c54:
    // 0x100c54: 0x26308ad0
    ctx->pc = 0x100c54u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 17), 4294937296));
label_100c58:
    // 0x100c58: 0x3c058000
    ctx->pc = 0x100c58u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x100c5c: 0x200202d
    ctx->pc = 0x100c5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100c60: 0x34a50595
    ctx->pc = 0x100c60u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 1429));
    // 0x100c64: 0xc045e06
    ctx->pc = 0x100C64u;
    SET_GPR_U32(ctx, 31, 0x100C6Cu);
    ctx->pc = 0x100C68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117818u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C6Cu; }
    }
    if (ctx->pc != 0x100C6Cu) { return; }
    ctx->pc = 0x100C6Cu;
    // 0x100c6c: 0x4430013
    ctx->pc = 0x100C6Cu;
    {
        const bool branch_taken_0x100c6c = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x100c6c) {
            ctx->pc = 0x100C70u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 36)));
            ctx->pc = 0x100CBCu;
            goto label_100cbc;
        }
    }
    ctx->pc = 0x100C74u;
    // 0x100c74: 0x3c020020
    ctx->pc = 0x100c74u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x100c78: 0x8c437910
    ctx->pc = 0x100c78u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100c7c: 0x18600005
    ctx->pc = 0x100C7Cu;
    {
        const bool branch_taken_0x100c7c = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x100C80u;
        SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
        if (branch_taken_0x100c7c) {
            ctx->pc = 0x100C94u;
            goto label_100c94;
        }
    }
    ctx->pc = 0x100C84u;
    // 0x100c84: 0x3c040023
    ctx->pc = 0x100c84u;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x100c88: 0xc045a12
    ctx->pc = 0x100C88u;
    SET_GPR_U32(ctx, 31, 0x100C90u);
    ctx->pc = 0x100C8Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 30016));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C90u; }
    }
    if (ctx->pc != 0x100C90u) { return; }
    ctx->pc = 0x100C90u;
    // 0x100c90: 0x3c020010
    ctx->pc = 0x100c90u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
label_100c94:
    // 0x100c94: 0x2403ffff
    ctx->pc = 0x100c94u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_100c98:
    // 0x100c98: 0x2442ffff
    ctx->pc = 0x100c98u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100c9c: 0x0
    ctx->pc = 0x100c9cu;
    // NOP
    // 0x100ca0: 0x0
    ctx->pc = 0x100ca0u;
    // NOP
    // 0x100ca4: 0x0
    ctx->pc = 0x100ca4u;
    // NOP
    // 0x100ca8: 0x0
    ctx->pc = 0x100ca8u;
    // NOP
    // 0x100cac: 0x1443fffa
    ctx->pc = 0x100CACu;
    {
        const bool branch_taken_0x100cac = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x100cac) {
            ctx->pc = 0x100C98u;
            goto label_100c98;
        }
    }
    ctx->pc = 0x100CB4u;
    // 0x100cb4: 0x1000ffe8
    ctx->pc = 0x100CB4u;
    {
        const bool branch_taken_0x100cb4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100CB8u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 17), 4294937296));
        if (branch_taken_0x100cb4) {
            ctx->pc = 0x100C58u;
            goto label_100c58;
        }
    }
    ctx->pc = 0x100CBCu;
label_100cbc:
    // 0x100cbc: 0x1040ffdc
    ctx->pc = 0x100CBCu;
    {
        const bool branch_taken_0x100cbc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x100CC0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x100cbc) {
            ctx->pc = 0x100C30u;
            goto label_100c30;
        }
    }
    ctx->pc = 0x100CC4u;
    // 0x100cc4: 0xae40793c
    ctx->pc = 0x100cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 31036), GPR_U32(ctx, 0));
label_100cc8:
    // 0x100cc8: 0xdfbf0030
    ctx->pc = 0x100cc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x100ccc: 0xdfb20020
    ctx->pc = 0x100cccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100cd0: 0xdfb10010
    ctx->pc = 0x100cd0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x100cd4: 0xdfb00000
    ctx->pc = 0x100cd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100cd8: 0x3e00008
    ctx->pc = 0x100CD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100CDCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100BD0u: goto label_100bd0;
            case 0x100C08u: goto label_100c08;
            case 0x100C10u: goto label_100c10;
            case 0x100C30u: goto label_100c30;
            case 0x100C38u: goto label_100c38;
            case 0x100C54u: goto label_100c54;
            case 0x100C58u: goto label_100c58;
            case 0x100C94u: goto label_100c94;
            case 0x100C98u: goto label_100c98;
            case 0x100CBCu: goto label_100cbc;
            case 0x100CC8u: goto label_100cc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100CE0u;
}
