#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00165C08
// Address: 0x165c08 - 0x165d80
void sub_00165C08_0x165c08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x165c08u;

label_165c08:
    // 0x165c08: 0x27bdff90
    ctx->pc = 0x165c08u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
label_165c0c:
    // 0x165c0c: 0xffb00040
    ctx->pc = 0x165c0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
label_165c10:
    // 0x165c10: 0xa0802d
    ctx->pc = 0x165c10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_165c14:
    // 0x165c14: 0xffb10048
    ctx->pc = 0x165c14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
label_165c18:
    // 0x165c18: 0x80882d
    ctx->pc = 0x165c18u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_165c1c:
    // 0x165c1c: 0x200202d
    ctx->pc = 0x165c1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_165c20:
    // 0x165c20: 0xffb20050
    ctx->pc = 0x165c20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
label_165c24:
    // 0x165c24: 0xffb30058
    ctx->pc = 0x165c24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
label_165c28:
    // 0x165c28: 0xe0982d
    ctx->pc = 0x165c28u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_165c2c:
    // 0x165c2c: 0xffbf0060
    ctx->pc = 0x165c2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
label_165c30:
    // 0x165c30: 0xc04c7be
label_165c34:
    if (ctx->pc == 0x165C34u) {
        ctx->pc = 0x165C34u;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x165C38u;
        goto label_165c38;
    }
    ctx->pc = 0x165C30u;
    SET_GPR_U32(ctx, 31, 0x165C38u);
    ctx->pc = 0x165C34u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x131EF8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00131EF8_0x131ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165C38u; }
    }
    if (ctx->pc != 0x165C38u) { return; }
    ctx->pc = 0x165C38u;
label_165c38:
    // 0x165c38: 0x200202d
    ctx->pc = 0x165c38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_165c3c:
    // 0x165c3c: 0x27a50030
    ctx->pc = 0x165c3cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 48));
label_165c40:
    // 0x165c40: 0x27a60034
    ctx->pc = 0x165c40u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 29), 52));
label_165c44:
    // 0x165c44: 0x3c030023
    ctx->pc = 0x165c44u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
label_165c48:
    // 0x165c48: 0xc04c858
label_165c4c:
    if (ctx->pc == 0x165C4Cu) {
        ctx->pc = 0x165C4Cu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294963048), GPR_U32(ctx, 2));
        ctx->pc = 0x165C50u;
        goto label_165c50;
    }
    ctx->pc = 0x165C48u;
    SET_GPR_U32(ctx, 31, 0x165C50u);
    ctx->pc = 0x165C4Cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963048), GPR_U32(ctx, 2));
    ctx->pc = 0x132160u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00132160_0x132160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165C50u; }
    }
    if (ctx->pc != 0x165C50u) { return; }
    ctx->pc = 0x165C50u;
label_165c50:
    // 0x165c50: 0x8fa30034
    ctx->pc = 0x165c50u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_165c54:
    // 0x165c54: 0x8fa20030
    ctx->pc = 0x165c54u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_165c58:
    // 0x165c58: 0xffa30008
    ctx->pc = 0x165c58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 3));
label_165c5c:
    // 0x165c5c: 0xc05fa1c
label_165c60:
    if (ctx->pc == 0x165C60u) {
        ctx->pc = 0x165C60u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->pc = 0x165C64u;
        goto label_165c64;
    }
    ctx->pc = 0x165C5Cu;
    SET_GPR_U32(ctx, 31, 0x165C64u);
    ctx->pc = 0x165C60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
    ctx->pc = 0x17E870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E870_0x17e870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165C64u; }
    }
    if (ctx->pc != 0x165C64u) { return; }
    ctx->pc = 0x165C64u;
label_165c64:
    // 0x165c64: 0xc05fa66
label_165c68:
    if (ctx->pc == 0x165C68u) {
        ctx->pc = 0x165C68u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 2));
        ctx->pc = 0x165C6Cu;
        goto label_165c6c;
    }
    ctx->pc = 0x165C64u;
    SET_GPR_U32(ctx, 31, 0x165C6Cu);
    ctx->pc = 0x165C68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 2));
    ctx->pc = 0x17E998u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E998_0x17e998(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165C6Cu; }
    }
    if (ctx->pc != 0x165C6Cu) { return; }
    ctx->pc = 0x165C6Cu;
label_165c6c:
    // 0x165c6c: 0x3a0282d
    ctx->pc = 0x165c6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_165c70:
    // 0x165c70: 0x27a60010
    ctx->pc = 0x165c70u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 29), 16));
label_165c74:
    // 0x165c74: 0x220202d
    ctx->pc = 0x165c74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_165c78:
    // 0x165c78: 0x27a70020
    ctx->pc = 0x165c78u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 32));
label_165c7c:
    // 0x165c7c: 0xc05dfac
label_165c80:
    if (ctx->pc == 0x165C80u) {
        ctx->pc = 0x165C80u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 2));
        ctx->pc = 0x165C84u;
        goto label_165c84;
    }
    ctx->pc = 0x165C7Cu;
    SET_GPR_U32(ctx, 31, 0x165C84u);
    ctx->pc = 0x165C80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 2));
    ctx->pc = 0x177EB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00177EB0_0x177eb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165C84u; }
    }
    if (ctx->pc != 0x165C84u) { return; }
    ctx->pc = 0x165C84u;
label_165c84:
    // 0x165c84: 0x8fa20020
    ctx->pc = 0x165c84u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_165c88:
    // 0x165c88: 0x8fa30028
    ctx->pc = 0x165c88u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_165c8c:
    // 0x165c8c: 0xae420000
    ctx->pc = 0x165c8cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_165c90:
    // 0x165c90: 0xdfb00040
    ctx->pc = 0x165c90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_165c94:
    // 0x165c94: 0xae630000
    ctx->pc = 0x165c94u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
label_165c98:
    // 0x165c98: 0xdfb10048
    ctx->pc = 0x165c98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
label_165c9c:
    // 0x165c9c: 0xdfb20050
    ctx->pc = 0x165c9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_165ca0:
    // 0x165ca0: 0xdfb30058
    ctx->pc = 0x165ca0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
label_165ca4:
    // 0x165ca4: 0xdfbf0060
    ctx->pc = 0x165ca4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_165ca8:
    // 0x165ca8: 0x3e00008
label_165cac:
    if (ctx->pc == 0x165CACu) {
        ctx->pc = 0x165CACu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = 0x165CB0u;
        goto label_165cb0;
    }
    ctx->pc = 0x165CA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165CACu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165C08u: goto label_165c08;
            case 0x165C0Cu: goto label_165c0c;
            case 0x165C10u: goto label_165c10;
            case 0x165C14u: goto label_165c14;
            case 0x165C18u: goto label_165c18;
            case 0x165C1Cu: goto label_165c1c;
            case 0x165C20u: goto label_165c20;
            case 0x165C24u: goto label_165c24;
            case 0x165C28u: goto label_165c28;
            case 0x165C2Cu: goto label_165c2c;
            case 0x165C30u: goto label_165c30;
            case 0x165C34u: goto label_165c34;
            case 0x165C38u: goto label_165c38;
            case 0x165C3Cu: goto label_165c3c;
            case 0x165C40u: goto label_165c40;
            case 0x165C44u: goto label_165c44;
            case 0x165C48u: goto label_165c48;
            case 0x165C4Cu: goto label_165c4c;
            case 0x165C50u: goto label_165c50;
            case 0x165C54u: goto label_165c54;
            case 0x165C58u: goto label_165c58;
            case 0x165C5Cu: goto label_165c5c;
            case 0x165C60u: goto label_165c60;
            case 0x165C64u: goto label_165c64;
            case 0x165C68u: goto label_165c68;
            case 0x165C6Cu: goto label_165c6c;
            case 0x165C70u: goto label_165c70;
            case 0x165C74u: goto label_165c74;
            case 0x165C78u: goto label_165c78;
            case 0x165C7Cu: goto label_165c7c;
            case 0x165C80u: goto label_165c80;
            case 0x165C84u: goto label_165c84;
            case 0x165C88u: goto label_165c88;
            case 0x165C8Cu: goto label_165c8c;
            case 0x165C90u: goto label_165c90;
            case 0x165C94u: goto label_165c94;
            case 0x165C98u: goto label_165c98;
            case 0x165C9Cu: goto label_165c9c;
            case 0x165CA0u: goto label_165ca0;
            case 0x165CA4u: goto label_165ca4;
            case 0x165CA8u: goto label_165ca8;
            case 0x165CACu: goto label_165cac;
            case 0x165CB0u: goto label_165cb0;
            case 0x165CB4u: goto label_165cb4;
            case 0x165CB8u: goto label_165cb8;
            case 0x165CBCu: goto label_165cbc;
            case 0x165CC0u: goto label_165cc0;
            case 0x165CC4u: goto label_165cc4;
            case 0x165CC8u: goto label_165cc8;
            case 0x165CCCu: goto label_165ccc;
            case 0x165CD0u: goto label_165cd0;
            case 0x165CD4u: goto label_165cd4;
            case 0x165CD8u: goto label_165cd8;
            case 0x165CDCu: goto label_165cdc;
            case 0x165CE0u: goto label_165ce0;
            case 0x165CE4u: goto label_165ce4;
            case 0x165CE8u: goto label_165ce8;
            case 0x165CECu: goto label_165cec;
            case 0x165CF0u: goto label_165cf0;
            case 0x165CF4u: goto label_165cf4;
            case 0x165CF8u: goto label_165cf8;
            case 0x165CFCu: goto label_165cfc;
            case 0x165D00u: goto label_165d00;
            case 0x165D04u: goto label_165d04;
            case 0x165D08u: goto label_165d08;
            case 0x165D0Cu: goto label_165d0c;
            case 0x165D10u: goto label_165d10;
            case 0x165D14u: goto label_165d14;
            case 0x165D18u: goto label_165d18;
            case 0x165D1Cu: goto label_165d1c;
            case 0x165D20u: goto label_165d20;
            case 0x165D24u: goto label_165d24;
            case 0x165D28u: goto label_165d28;
            case 0x165D2Cu: goto label_165d2c;
            case 0x165D30u: goto label_165d30;
            case 0x165D34u: goto label_165d34;
            case 0x165D38u: goto label_165d38;
            case 0x165D3Cu: goto label_165d3c;
            case 0x165D40u: goto label_165d40;
            case 0x165D44u: goto label_165d44;
            case 0x165D48u: goto label_165d48;
            case 0x165D4Cu: goto label_165d4c;
            case 0x165D50u: goto label_165d50;
            case 0x165D54u: goto label_165d54;
            case 0x165D58u: goto label_165d58;
            case 0x165D5Cu: goto label_165d5c;
            case 0x165D60u: goto label_165d60;
            case 0x165D64u: goto label_165d64;
            case 0x165D68u: goto label_165d68;
            case 0x165D6Cu: goto label_165d6c;
            case 0x165D70u: goto label_165d70;
            case 0x165D74u: goto label_165d74;
            case 0x165D78u: goto label_165d78;
            case 0x165D7Cu: goto label_165d7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165CB0u;
label_165cb0:
    // 0x165cb0: 0x27bdffe0
    ctx->pc = 0x165cb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_165cb4:
    // 0x165cb4: 0x102d
    ctx->pc = 0x165cb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_165cb8:
    // 0x165cb8: 0xffb10008
    ctx->pc = 0x165cb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_165cbc:
    // 0x165cbc: 0x80882d
    ctx->pc = 0x165cbcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_165cc0:
    // 0x165cc0: 0xffb00000
    ctx->pc = 0x165cc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_165cc4:
    // 0x165cc4: 0xffb20010
    ctx->pc = 0x165cc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_165cc8:
    // 0x165cc8: 0xffbf0018
    ctx->pc = 0x165cc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_165ccc:
    // 0x165ccc: 0x8e231b74
    ctx->pc = 0x165cccu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 7028)));
label_165cd0:
    // 0x165cd0: 0x8c700000
    ctx->pc = 0x165cd0u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_165cd4:
    // 0x165cd4: 0x12000024
label_165cd8:
    if (ctx->pc == 0x165CD8u) {
        ctx->pc = 0x165CD8u;
        SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->pc = 0x165CDCu;
        goto label_165cdc;
    }
    ctx->pc = 0x165CD4u;
    {
        const bool branch_taken_0x165cd4 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x165CD8u;
        SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 3), 4)));
        if (branch_taken_0x165cd4) {
            ctx->pc = 0x165D68u;
            goto label_165d68;
        }
    }
    ctx->pc = 0x165CDCu;
label_165cdc:
    // 0x165cdc: 0x3c020027
    ctx->pc = 0x165cdcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)39 << 16));
label_165ce0:
    // 0x165ce0: 0x24470750
    ctx->pc = 0x165ce0u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 2), 1872));
label_165ce4:
    // 0x165ce4: 0x6864000f
    ctx->pc = 0x165ce4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data << shift) & mask)); }
label_165ce8:
    // 0x165ce8: 0x6c640008
    ctx->pc = 0x165ce8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data >> shift) & mask)); }
label_165cec:
    // 0x165cec: 0x68650017
    ctx->pc = 0x165cecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
label_165cf0:
    // 0x165cf0: 0x6c650010
    ctx->pc = 0x165cf0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
label_165cf4:
    // 0x165cf4: 0x6866001f
    ctx->pc = 0x165cf4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data << shift) & mask)); }
label_165cf8:
    // 0x165cf8: 0x6c660018
    ctx->pc = 0x165cf8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data >> shift) & mask)); }
label_165cfc:
    // 0x165cfc: 0xb0e40007
    ctx->pc = 0x165cfcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_165d00:
    // 0x165d00: 0xb4e40000
    ctx->pc = 0x165d00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_165d04:
    // 0x165d04: 0xb0e5000f
    ctx->pc = 0x165d04u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_165d08:
    // 0x165d08: 0xb4e50008
    ctx->pc = 0x165d08u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_165d0c:
    // 0x165d0c: 0xb0e60017
    ctx->pc = 0x165d0cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_165d10:
    // 0x165d10: 0xb4e60010
    ctx->pc = 0x165d10u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 16); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_165d14:
    // 0x165d14: 0x8c640020
    ctx->pc = 0x165d14u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 32)));
label_165d18:
    // 0x165d18: 0xc05cf00
label_165d1c:
    if (ctx->pc == 0x165D1Cu) {
        ctx->pc = 0x165D1Cu;
        WRITE32(ADD32(GPR_U32(ctx, 7), 24), GPR_U32(ctx, 4));
        ctx->pc = 0x165D20u;
        goto label_165d20;
    }
    ctx->pc = 0x165D18u;
    SET_GPR_U32(ctx, 31, 0x165D20u);
    ctx->pc = 0x165D1Cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 24), GPR_U32(ctx, 4));
    ctx->pc = 0x173C00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00173C00_0x173c00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D20u; }
    }
    if (ctx->pc != 0x165D20u) { return; }
    ctx->pc = 0x165D20u;
label_165d20:
    // 0x165d20: 0x24030001
    ctx->pc = 0x165d20u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
label_165d24:
    // 0x165d24: 0x10430006
label_165d28:
    if (ctx->pc == 0x165D28u) {
        ctx->pc = 0x165D28u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x165D2Cu;
        goto label_165d2c;
    }
    ctx->pc = 0x165D24u;
    {
        const bool branch_taken_0x165d24 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x165D28u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x165d24) {
            ctx->pc = 0x165D40u;
            goto label_165d40;
        }
    }
    ctx->pc = 0x165D2Cu;
label_165d2c:
    // 0x165d2c: 0xc059760
label_165d30:
    if (ctx->pc == 0x165D30u) {
        ctx->pc = 0x165D30u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x165D34u;
        goto label_165d34;
    }
    ctx->pc = 0x165D2Cu;
    SET_GPR_U32(ctx, 31, 0x165D34u);
    ctx->pc = 0x165D30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x165D80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00165D80_0x165d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D34u; }
    }
    if (ctx->pc != 0x165D34u) { return; }
    ctx->pc = 0x165D34u;
label_165d34:
    // 0x165d34: 0x10000007
label_165d38:
    if (ctx->pc == 0x165D38u) {
        ctx->pc = 0x165D38u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x165D3Cu;
        goto label_165d3c;
    }
    ctx->pc = 0x165D34u;
    {
        const bool branch_taken_0x165d34 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x165D38u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x165d34) {
            ctx->pc = 0x165D54u;
            goto label_165d54;
        }
    }
    ctx->pc = 0x165D3Cu;
label_165d3c:
    // 0x165d3c: 0x0
    ctx->pc = 0x165d3cu;
    // NOP
label_165d40:
    // 0x165d40: 0xc059776
label_165d44:
    if (ctx->pc == 0x165D44u) {
        ctx->pc = 0x165D48u;
        goto label_165d48;
    }
    ctx->pc = 0x165D40u;
    SET_GPR_U32(ctx, 31, 0x165D48u);
    ctx->pc = 0x165DD8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00165DD8_0x165dd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D48u; }
    }
    if (ctx->pc != 0x165D48u) { return; }
    ctx->pc = 0x165D48u;
label_165d48:
    // 0x165d48: 0xc059768
label_165d4c:
    if (ctx->pc == 0x165D4Cu) {
        ctx->pc = 0x165D4Cu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x165D50u;
        goto label_165d50;
    }
    ctx->pc = 0x165D48u;
    SET_GPR_U32(ctx, 31, 0x165D50u);
    ctx->pc = 0x165D4Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x165DA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00165DA0_0x165da0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D50u; }
    }
    if (ctx->pc != 0x165D50u) { return; }
    ctx->pc = 0x165D50u;
label_165d50:
    // 0x165d50: 0x40802d
    ctx->pc = 0x165d50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_165d54:
    // 0x165d54: 0x8e430000
    ctx->pc = 0x165d54u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_165d58:
    // 0x165d58: 0x8c62000c
    ctx->pc = 0x165d58u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 12)));
label_165d5c:
    // 0x165d5c: 0x40f809
label_165d60:
    if (ctx->pc == 0x165D60u) {
        ctx->pc = 0x165D60u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x165D64u;
        goto label_165d64;
    }
    ctx->pc = 0x165D5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x165D64u);
        ctx->pc = 0x165D60u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165C08u: goto label_165c08;
            case 0x165C0Cu: goto label_165c0c;
            case 0x165C10u: goto label_165c10;
            case 0x165C14u: goto label_165c14;
            case 0x165C18u: goto label_165c18;
            case 0x165C1Cu: goto label_165c1c;
            case 0x165C20u: goto label_165c20;
            case 0x165C24u: goto label_165c24;
            case 0x165C28u: goto label_165c28;
            case 0x165C2Cu: goto label_165c2c;
            case 0x165C30u: goto label_165c30;
            case 0x165C34u: goto label_165c34;
            case 0x165C38u: goto label_165c38;
            case 0x165C3Cu: goto label_165c3c;
            case 0x165C40u: goto label_165c40;
            case 0x165C44u: goto label_165c44;
            case 0x165C48u: goto label_165c48;
            case 0x165C4Cu: goto label_165c4c;
            case 0x165C50u: goto label_165c50;
            case 0x165C54u: goto label_165c54;
            case 0x165C58u: goto label_165c58;
            case 0x165C5Cu: goto label_165c5c;
            case 0x165C60u: goto label_165c60;
            case 0x165C64u: goto label_165c64;
            case 0x165C68u: goto label_165c68;
            case 0x165C6Cu: goto label_165c6c;
            case 0x165C70u: goto label_165c70;
            case 0x165C74u: goto label_165c74;
            case 0x165C78u: goto label_165c78;
            case 0x165C7Cu: goto label_165c7c;
            case 0x165C80u: goto label_165c80;
            case 0x165C84u: goto label_165c84;
            case 0x165C88u: goto label_165c88;
            case 0x165C8Cu: goto label_165c8c;
            case 0x165C90u: goto label_165c90;
            case 0x165C94u: goto label_165c94;
            case 0x165C98u: goto label_165c98;
            case 0x165C9Cu: goto label_165c9c;
            case 0x165CA0u: goto label_165ca0;
            case 0x165CA4u: goto label_165ca4;
            case 0x165CA8u: goto label_165ca8;
            case 0x165CACu: goto label_165cac;
            case 0x165CB0u: goto label_165cb0;
            case 0x165CB4u: goto label_165cb4;
            case 0x165CB8u: goto label_165cb8;
            case 0x165CBCu: goto label_165cbc;
            case 0x165CC0u: goto label_165cc0;
            case 0x165CC4u: goto label_165cc4;
            case 0x165CC8u: goto label_165cc8;
            case 0x165CCCu: goto label_165ccc;
            case 0x165CD0u: goto label_165cd0;
            case 0x165CD4u: goto label_165cd4;
            case 0x165CD8u: goto label_165cd8;
            case 0x165CDCu: goto label_165cdc;
            case 0x165CE0u: goto label_165ce0;
            case 0x165CE4u: goto label_165ce4;
            case 0x165CE8u: goto label_165ce8;
            case 0x165CECu: goto label_165cec;
            case 0x165CF0u: goto label_165cf0;
            case 0x165CF4u: goto label_165cf4;
            case 0x165CF8u: goto label_165cf8;
            case 0x165CFCu: goto label_165cfc;
            case 0x165D00u: goto label_165d00;
            case 0x165D04u: goto label_165d04;
            case 0x165D08u: goto label_165d08;
            case 0x165D0Cu: goto label_165d0c;
            case 0x165D10u: goto label_165d10;
            case 0x165D14u: goto label_165d14;
            case 0x165D18u: goto label_165d18;
            case 0x165D1Cu: goto label_165d1c;
            case 0x165D20u: goto label_165d20;
            case 0x165D24u: goto label_165d24;
            case 0x165D28u: goto label_165d28;
            case 0x165D2Cu: goto label_165d2c;
            case 0x165D30u: goto label_165d30;
            case 0x165D34u: goto label_165d34;
            case 0x165D38u: goto label_165d38;
            case 0x165D3Cu: goto label_165d3c;
            case 0x165D40u: goto label_165d40;
            case 0x165D44u: goto label_165d44;
            case 0x165D48u: goto label_165d48;
            case 0x165D4Cu: goto label_165d4c;
            case 0x165D50u: goto label_165d50;
            case 0x165D54u: goto label_165d54;
            case 0x165D58u: goto label_165d58;
            case 0x165D5Cu: goto label_165d5c;
            case 0x165D60u: goto label_165d60;
            case 0x165D64u: goto label_165d64;
            case 0x165D68u: goto label_165d68;
            case 0x165D6Cu: goto label_165d6c;
            case 0x165D70u: goto label_165d70;
            case 0x165D74u: goto label_165d74;
            case 0x165D78u: goto label_165d78;
            case 0x165D7Cu: goto label_165d7c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x165D64u; }
            if (ctx->pc != 0x165D64u) { return; }
        }
    }
    ctx->pc = 0x165D64u;
label_165d64:
    // 0x165d64: 0x200102d
    ctx->pc = 0x165d64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_165d68:
    // 0x165d68: 0xdfb00000
    ctx->pc = 0x165d68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_165d6c:
    // 0x165d6c: 0xdfb10008
    ctx->pc = 0x165d6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_165d70:
    // 0x165d70: 0xdfb20010
    ctx->pc = 0x165d70u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_165d74:
    // 0x165d74: 0xdfbf0018
    ctx->pc = 0x165d74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_165d78:
    // 0x165d78: 0x3e00008
label_165d7c:
    if (ctx->pc == 0x165D7Cu) {
        ctx->pc = 0x165D7Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x165D80u;
        goto label_fallthrough_0x165d78;
    }
    ctx->pc = 0x165D78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165D7Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165C08u: goto label_165c08;
            case 0x165C0Cu: goto label_165c0c;
            case 0x165C10u: goto label_165c10;
            case 0x165C14u: goto label_165c14;
            case 0x165C18u: goto label_165c18;
            case 0x165C1Cu: goto label_165c1c;
            case 0x165C20u: goto label_165c20;
            case 0x165C24u: goto label_165c24;
            case 0x165C28u: goto label_165c28;
            case 0x165C2Cu: goto label_165c2c;
            case 0x165C30u: goto label_165c30;
            case 0x165C34u: goto label_165c34;
            case 0x165C38u: goto label_165c38;
            case 0x165C3Cu: goto label_165c3c;
            case 0x165C40u: goto label_165c40;
            case 0x165C44u: goto label_165c44;
            case 0x165C48u: goto label_165c48;
            case 0x165C4Cu: goto label_165c4c;
            case 0x165C50u: goto label_165c50;
            case 0x165C54u: goto label_165c54;
            case 0x165C58u: goto label_165c58;
            case 0x165C5Cu: goto label_165c5c;
            case 0x165C60u: goto label_165c60;
            case 0x165C64u: goto label_165c64;
            case 0x165C68u: goto label_165c68;
            case 0x165C6Cu: goto label_165c6c;
            case 0x165C70u: goto label_165c70;
            case 0x165C74u: goto label_165c74;
            case 0x165C78u: goto label_165c78;
            case 0x165C7Cu: goto label_165c7c;
            case 0x165C80u: goto label_165c80;
            case 0x165C84u: goto label_165c84;
            case 0x165C88u: goto label_165c88;
            case 0x165C8Cu: goto label_165c8c;
            case 0x165C90u: goto label_165c90;
            case 0x165C94u: goto label_165c94;
            case 0x165C98u: goto label_165c98;
            case 0x165C9Cu: goto label_165c9c;
            case 0x165CA0u: goto label_165ca0;
            case 0x165CA4u: goto label_165ca4;
            case 0x165CA8u: goto label_165ca8;
            case 0x165CACu: goto label_165cac;
            case 0x165CB0u: goto label_165cb0;
            case 0x165CB4u: goto label_165cb4;
            case 0x165CB8u: goto label_165cb8;
            case 0x165CBCu: goto label_165cbc;
            case 0x165CC0u: goto label_165cc0;
            case 0x165CC4u: goto label_165cc4;
            case 0x165CC8u: goto label_165cc8;
            case 0x165CCCu: goto label_165ccc;
            case 0x165CD0u: goto label_165cd0;
            case 0x165CD4u: goto label_165cd4;
            case 0x165CD8u: goto label_165cd8;
            case 0x165CDCu: goto label_165cdc;
            case 0x165CE0u: goto label_165ce0;
            case 0x165CE4u: goto label_165ce4;
            case 0x165CE8u: goto label_165ce8;
            case 0x165CECu: goto label_165cec;
            case 0x165CF0u: goto label_165cf0;
            case 0x165CF4u: goto label_165cf4;
            case 0x165CF8u: goto label_165cf8;
            case 0x165CFCu: goto label_165cfc;
            case 0x165D00u: goto label_165d00;
            case 0x165D04u: goto label_165d04;
            case 0x165D08u: goto label_165d08;
            case 0x165D0Cu: goto label_165d0c;
            case 0x165D10u: goto label_165d10;
            case 0x165D14u: goto label_165d14;
            case 0x165D18u: goto label_165d18;
            case 0x165D1Cu: goto label_165d1c;
            case 0x165D20u: goto label_165d20;
            case 0x165D24u: goto label_165d24;
            case 0x165D28u: goto label_165d28;
            case 0x165D2Cu: goto label_165d2c;
            case 0x165D30u: goto label_165d30;
            case 0x165D34u: goto label_165d34;
            case 0x165D38u: goto label_165d38;
            case 0x165D3Cu: goto label_165d3c;
            case 0x165D40u: goto label_165d40;
            case 0x165D44u: goto label_165d44;
            case 0x165D48u: goto label_165d48;
            case 0x165D4Cu: goto label_165d4c;
            case 0x165D50u: goto label_165d50;
            case 0x165D54u: goto label_165d54;
            case 0x165D58u: goto label_165d58;
            case 0x165D5Cu: goto label_165d5c;
            case 0x165D60u: goto label_165d60;
            case 0x165D64u: goto label_165d64;
            case 0x165D68u: goto label_165d68;
            case 0x165D6Cu: goto label_165d6c;
            case 0x165D70u: goto label_165d70;
            case 0x165D74u: goto label_165d74;
            case 0x165D78u: goto label_165d78;
            case 0x165D7Cu: goto label_165d7c;
            default: break;
        }
        return;
    }
label_fallthrough_0x165d78:
    ctx->pc = 0x165D80u;
}
