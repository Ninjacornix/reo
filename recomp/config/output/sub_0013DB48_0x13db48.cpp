#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013DB48
// Address: 0x13db48 - 0x13de40
void sub_0013DB48_0x13db48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13db48u;

label_13db48:
    // 0x13db48: 0x3c020022
    ctx->pc = 0x13db48u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_13db4c:
    // 0x13db4c: 0x27bdffb0
    ctx->pc = 0x13db4cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
label_13db50:
    // 0x13db50: 0x8c431440
    ctx->pc = 0x13db50u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 5184)));
label_13db54:
    // 0x13db54: 0xffb00000
    ctx->pc = 0x13db54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_13db58:
    // 0x13db58: 0xffb10008
    ctx->pc = 0x13db58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_13db5c:
    // 0x13db5c: 0xffb20010
    ctx->pc = 0x13db5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_13db60:
    // 0x13db60: 0xffb30018
    ctx->pc = 0x13db60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
label_13db64:
    // 0x13db64: 0xffb40020
    ctx->pc = 0x13db64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
label_13db68:
    // 0x13db68: 0xffb50028
    ctx->pc = 0x13db68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
label_13db6c:
    // 0x13db6c: 0xffb60030
    ctx->pc = 0x13db6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
label_13db70:
    // 0x13db70: 0xffb70038
    ctx->pc = 0x13db70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
label_13db74:
    // 0x13db74: 0xffbe0040
    ctx->pc = 0x13db74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
label_13db78:
    // 0x13db78: 0x14600009
label_13db7c:
    if (ctx->pc == 0x13DB7Cu) {
        ctx->pc = 0x13DB7Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
        ctx->pc = 0x13DB80u;
        goto label_13db80;
    }
    ctx->pc = 0x13DB78u;
    {
        const bool branch_taken_0x13db78 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x13DB7Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
        if (branch_taken_0x13db78) {
            ctx->pc = 0x13DBA0u;
            goto label_13dba0;
        }
    }
    ctx->pc = 0x13DB80u;
label_13db80:
    // 0x13db80: 0x3c020004
    ctx->pc = 0x13db80u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4 << 16));
label_13db84:
    // 0x13db84: 0x3c150022
    ctx->pc = 0x13db84u;
    SET_GPR_U32(ctx, 21, ((uint32_t)34 << 16));
label_13db88:
    // 0x13db88: 0x24030010
    ctx->pc = 0x13db88u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
label_13db8c:
    // 0x13db8c: 0x3c040022
    ctx->pc = 0x13db8cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
label_13db90:
    // 0x13db90: 0x34421000
    ctx->pc = 0x13db90u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 4096));
label_13db94:
    // 0x13db94: 0xaea31438
    ctx->pc = 0x13db94u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 5176), GPR_U32(ctx, 3));
label_13db98:
    // 0x13db98: 0x10000002
label_13db9c:
    if (ctx->pc == 0x13DB9Cu) {
        ctx->pc = 0x13DB9Cu;
        WRITE32(ADD32(GPR_U32(ctx, 4), 5180), GPR_U32(ctx, 2));
        ctx->pc = 0x13DBA0u;
        goto label_13dba0;
    }
    ctx->pc = 0x13DB98u;
    {
        const bool branch_taken_0x13db98 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x13DB9Cu;
        WRITE32(ADD32(GPR_U32(ctx, 4), 5180), GPR_U32(ctx, 2));
        if (branch_taken_0x13db98) {
            ctx->pc = 0x13DBA4u;
            goto label_13dba4;
        }
    }
    ctx->pc = 0x13DBA0u;
label_13dba0:
    // 0x13dba0: 0x3c150022
    ctx->pc = 0x13dba0u;
    SET_GPR_U32(ctx, 21, ((uint32_t)34 << 16));
label_13dba4:
    // 0x13dba4: 0x3c130022
    ctx->pc = 0x13dba4u;
    SET_GPR_U32(ctx, 19, ((uint32_t)34 << 16));
label_13dba8:
    // 0x13dba8: 0x26701444
    ctx->pc = 0x13dba8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 19), 5188));
label_13dbac:
    // 0x13dbac: 0x8e020000
    ctx->pc = 0x13dbacu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_13dbb0:
    // 0x13dbb0: 0x54400025
label_13dbb4:
    if (ctx->pc == 0x13DBB4u) {
        ctx->pc = 0x13DBB4u;
        SET_GPR_U32(ctx, 16, ((uint32_t)34 << 16));
        ctx->pc = 0x13DBB8u;
        goto label_13dbb8;
    }
    ctx->pc = 0x13DBB0u;
    {
        const bool branch_taken_0x13dbb0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x13dbb0) {
            ctx->pc = 0x13DBB4u;
            SET_GPR_U32(ctx, 16, ((uint32_t)34 << 16));
            ctx->pc = 0x13DC48u;
            goto label_13dc48;
        }
    }
    ctx->pc = 0x13DBB8u;
label_13dbb8:
    // 0x13dbb8: 0x3c120022
    ctx->pc = 0x13dbb8u;
    SET_GPR_U32(ctx, 18, ((uint32_t)34 << 16));
label_13dbbc:
    // 0x13dbbc: 0x2651143c
    ctx->pc = 0x13dbbcu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 18), 5180));
label_13dbc0:
    // 0x13dbc0: 0x8e240000
    ctx->pc = 0x13dbc0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_13dbc4:
    // 0x13dbc4: 0xc046e2c
label_13dbc8:
    if (ctx->pc == 0x13DBC8u) {
        ctx->pc = 0x13DBC8u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 64));
        ctx->pc = 0x13DBCCu;
        goto label_13dbcc;
    }
    ctx->pc = 0x13DBC4u;
    SET_GPR_U32(ctx, 31, 0x13DBCCu);
    ctx->pc = 0x13DBC8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 64));
    ctx->pc = 0x11B8B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B8B0_0x11b8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DBCCu; }
    }
    if (ctx->pc != 0x13DBCCu) { return; }
    ctx->pc = 0x13DBCCu;
label_13dbcc:
    // 0x13dbcc: 0x1440000e
label_13dbd0:
    if (ctx->pc == 0x13DBD0u) {
        ctx->pc = 0x13DBD0u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x13DBD4u;
        goto label_13dbd4;
    }
    ctx->pc = 0x13DBCCu;
    {
        const bool branch_taken_0x13dbcc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13DBD0u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x13dbcc) {
            ctx->pc = 0x13DC08u;
            goto label_13dc08;
        }
    }
    ctx->pc = 0x13DBD4u;
label_13dbd4:
    // 0x13dbd4: 0x8e250000
    ctx->pc = 0x13dbd4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_13dbd8:
    // 0x13dbd8: 0x3c040024
    ctx->pc = 0x13dbd8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_13dbdc:
    // 0x13dbdc: 0x2484d580
    ctx->pc = 0x13dbdcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294956416));
label_13dbe0:
    // 0x13dbe0: 0xc045a12
label_13dbe4:
    if (ctx->pc == 0x13DBE4u) {
        ctx->pc = 0x13DBE4u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 64));
        ctx->pc = 0x13DBE8u;
        goto label_13dbe8;
    }
    ctx->pc = 0x13DBE0u;
    SET_GPR_U32(ctx, 31, 0x13DBE8u);
    ctx->pc = 0x13DBE4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 64));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DBE8u; }
    }
    if (ctx->pc != 0x13DBE8u) { return; }
    ctx->pc = 0x13DBE8u;
label_13dbe8:
    // 0x13dbe8: 0x0
    ctx->pc = 0x13dbe8u;
    // NOP
label_13dbec:
    // 0x13dbec: 0x0
    ctx->pc = 0x13dbecu;
    // NOP
label_13dbf0:
    // 0x13dbf0: 0x0
    ctx->pc = 0x13dbf0u;
    // NOP
label_13dbf4:
    // 0x13dbf4: 0x0
    ctx->pc = 0x13dbf4u;
    // NOP
label_13dbf8:
    // 0x13dbf8: 0x0
    ctx->pc = 0x13dbf8u;
    // NOP
label_13dbfc:
    // 0x13dbfc: 0x1000fffa
label_13dc00:
    if (ctx->pc == 0x13DC00u) {
        ctx->pc = 0x13DC04u;
        goto label_13dc04;
    }
    ctx->pc = 0x13DBFCu;
    {
        const bool branch_taken_0x13dbfc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x13dbfc) {
            ctx->pc = 0x13DBE8u;
            goto label_13dbe8;
        }
    }
    ctx->pc = 0x13DC04u;
label_13dc04:
    // 0x13dc04: 0x0
    ctx->pc = 0x13dc04u;
    // NOP
label_13dc08:
    // 0x13dc08: 0x26701444
    ctx->pc = 0x13dc08u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 19), 5188));
label_13dc0c:
    // 0x13dc0c: 0x8e45143c
    ctx->pc = 0x13dc0cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 5180)));
label_13dc10:
    // 0x13dc10: 0x8e060000
    ctx->pc = 0x13dc10u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_13dc14:
    // 0x13dc14: 0x3c040024
    ctx->pc = 0x13dc14u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_13dc18:
    // 0x13dc18: 0x2484d5c8
    ctx->pc = 0x13dc18u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294956488));
label_13dc1c:
    // 0x13dc1c: 0xc045a12
label_13dc20:
    if (ctx->pc == 0x13DC20u) {
        ctx->pc = 0x13DC20u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 64));
        ctx->pc = 0x13DC24u;
        goto label_13dc24;
    }
    ctx->pc = 0x13DC1Cu;
    SET_GPR_U32(ctx, 31, 0x13DC24u);
    ctx->pc = 0x13DC20u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 64));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DC24u; }
    }
    if (ctx->pc != 0x13DC24u) { return; }
    ctx->pc = 0x13DC24u;
label_13dc24:
    // 0x13dc24: 0x8e030000
    ctx->pc = 0x13dc24u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_13dc28:
    // 0x13dc28: 0x2405ffc0
    ctx->pc = 0x13dc28u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4294967232));
label_13dc2c:
    // 0x13dc2c: 0x3c040022
    ctx->pc = 0x13dc2cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
label_13dc30:
    // 0x13dc30: 0x24630040
    ctx->pc = 0x13dc30u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 64));
label_13dc34:
    // 0x13dc34: 0x3c100022
    ctx->pc = 0x13dc34u;
    SET_GPR_U32(ctx, 16, ((uint32_t)34 << 16));
label_13dc38:
    // 0x13dc38: 0x651824
    ctx->pc = 0x13dc38u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_13dc3c:
    // 0x13dc3c: 0x24020001
    ctx->pc = 0x13dc3cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_13dc40:
    // 0x13dc40: 0xa082144c
    ctx->pc = 0x13dc40u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 5196), (uint8_t)GPR_U32(ctx, 2));
label_13dc44:
    // 0x13dc44: 0xae031448
    ctx->pc = 0x13dc44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 5192), GPR_U32(ctx, 3));
label_13dc48:
    // 0x13dc48: 0x3c140022
    ctx->pc = 0x13dc48u;
    SET_GPR_U32(ctx, 20, ((uint32_t)34 << 16));
label_13dc4c:
    // 0x13dc4c: 0x282d
    ctx->pc = 0x13dc4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13dc50:
    // 0x13dc50: 0x26841480
    ctx->pc = 0x13dc50u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 5248));
label_13dc54:
    // 0x13dc54: 0xc041f1a
label_13dc58:
    if (ctx->pc == 0x13DC58u) {
        ctx->pc = 0x13DC58u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 768));
        ctx->pc = 0x13DC5Cu;
        goto label_13dc5c;
    }
    ctx->pc = 0x13DC54u;
    SET_GPR_U32(ctx, 31, 0x13DC5Cu);
    ctx->pc = 0x13DC58u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 768));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DC5Cu; }
    }
    if (ctx->pc != 0x13DC5Cu) { return; }
    ctx->pc = 0x13DC5Cu;
label_13dc5c:
    // 0x13dc5c: 0x8e111448
    ctx->pc = 0x13dc5cu;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 16), 5192)));
label_13dc60:
    // 0x13dc60: 0x8ea21438
    ctx->pc = 0x13dc60u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 21), 5176)));
label_13dc64:
    // 0x13dc64: 0x1840006a
label_13dc68:
    if (ctx->pc == 0x13DC68u) {
        ctx->pc = 0x13DC68u;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x13DC6Cu;
        goto label_13dc6c;
    }
    ctx->pc = 0x13DC64u;
    {
        const bool branch_taken_0x13dc64 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x13DC68u;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13dc64) {
            ctx->pc = 0x13DE10u;
            goto label_13de10;
        }
    }
    ctx->pc = 0x13DC6Cu;
label_13dc6c:
    // 0x13dc6c: 0x3c160022
    ctx->pc = 0x13dc6cu;
    SET_GPR_U32(ctx, 22, ((uint32_t)34 << 16));
label_13dc70:
    // 0x13dc70: 0x982d
    ctx->pc = 0x13dc70u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13dc74:
    // 0x13dc74: 0x3c1e0024
    ctx->pc = 0x13dc74u;
    SET_GPR_U32(ctx, 30, ((uint32_t)36 << 16));
label_13dc78:
    // 0x13dc78: 0x3c170024
    ctx->pc = 0x13dc78u;
    SET_GPR_U32(ctx, 23, ((uint32_t)36 << 16));
label_13dc7c:
    // 0x13dc7c: 0x26821480
    ctx->pc = 0x13dc7cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 20), 5248));
label_13dc80:
    // 0x13dc80: 0x3223003f
    ctx->pc = 0x13dc80u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 17), 63));
label_13dc84:
    // 0x13dc84: 0x2628021
    ctx->pc = 0x13dc84u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
label_13dc88:
    // 0x13dc88: 0x26730018
    ctx->pc = 0x13dc88u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 24));
label_13dc8c:
    // 0x13dc8c: 0x1060000c
label_13dc90:
    if (ctx->pc == 0x13DC90u) {
        ctx->pc = 0x13DC90u;
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->pc = 0x13DC94u;
        goto label_13dc94;
    }
    ctx->pc = 0x13DC8Cu;
    {
        const bool branch_taken_0x13dc8c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x13DC90u;
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        if (branch_taken_0x13dc8c) {
            ctx->pc = 0x13DCC0u;
            goto label_13dcc0;
        }
    }
    ctx->pc = 0x13DC94u;
label_13dc94:
    // 0x13dc94: 0x3c020024
    ctx->pc = 0x13dc94u;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
label_13dc98:
    // 0x13dc98: 0xc045a12
label_13dc9c:
    if (ctx->pc == 0x13DC9Cu) {
        ctx->pc = 0x13DC9Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294956536));
        ctx->pc = 0x13DCA0u;
        goto label_13dca0;
    }
    ctx->pc = 0x13DC98u;
    SET_GPR_U32(ctx, 31, 0x13DCA0u);
    ctx->pc = 0x13DC9Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294956536));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DCA0u; }
    }
    if (ctx->pc != 0x13DCA0u) { return; }
    ctx->pc = 0x13DCA0u;
label_13dca0:
    // 0x13dca0: 0x0
    ctx->pc = 0x13dca0u;
    // NOP
label_13dca4:
    // 0x13dca4: 0x0
    ctx->pc = 0x13dca4u;
    // NOP
label_13dca8:
    // 0x13dca8: 0x0
    ctx->pc = 0x13dca8u;
    // NOP
label_13dcac:
    // 0x13dcac: 0x0
    ctx->pc = 0x13dcacu;
    // NOP
label_13dcb0:
    // 0x13dcb0: 0x0
    ctx->pc = 0x13dcb0u;
    // NOP
label_13dcb4:
    // 0x13dcb4: 0x1000fffa
label_13dcb8:
    if (ctx->pc == 0x13DCB8u) {
        ctx->pc = 0x13DCBCu;
        goto label_13dcbc;
    }
    ctx->pc = 0x13DCB4u;
    {
        const bool branch_taken_0x13dcb4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x13dcb4) {
            ctx->pc = 0x13DCA0u;
            goto label_13dca0;
        }
    }
    ctx->pc = 0x13DCBCu;
label_13dcbc:
    // 0x13dcbc: 0x0
    ctx->pc = 0x13dcbcu;
    // NOP
label_13dcc0:
    // 0x13dcc0: 0x220282d
    ctx->pc = 0x13dcc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_13dcc4:
    // 0x13dcc4: 0x26310100
    ctx->pc = 0x13dcc4u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 256));
label_13dcc8:
    // 0x13dcc8: 0x24040001
    ctx->pc = 0x13dcc8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
label_13dccc:
    // 0x13dccc: 0xc0502e6
label_13dcd0:
    if (ctx->pc == 0x13DCD0u) {
        ctx->pc = 0x13DCD0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
        ctx->pc = 0x13DCD4u;
        goto label_13dcd4;
    }
    ctx->pc = 0x13DCCCu;
    SET_GPR_U32(ctx, 31, 0x13DCD4u);
    ctx->pc = 0x13DCD0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
    ctx->pc = 0x140B98u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00140B98_0x140b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DCD4u; }
    }
    if (ctx->pc != 0x13DCD4u) { return; }
    ctx->pc = 0x13DCD4u;
label_13dcd4:
    // 0x13dcd4: 0x121a00
    ctx->pc = 0x13dcd4u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 18), 8));
label_13dcd8:
    // 0x13dcd8: 0x26c51780
    ctx->pc = 0x13dcd8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 22), 6016));
label_13dcdc:
    // 0x13dcdc: 0x24040001
    ctx->pc = 0x13dcdcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
label_13dce0:
    // 0x13dce0: 0x652821
    ctx->pc = 0x13dce0u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_13dce4:
    // 0x13dce4: 0x3223003f
    ctx->pc = 0x13dce4u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 17), 63));
label_13dce8:
    // 0x13dce8: 0x26520001
    ctx->pc = 0x13dce8u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
label_13dcec:
    // 0x13dcec: 0x24060100
    ctx->pc = 0x13dcecu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
label_13dcf0:
    // 0x13dcf0: 0x1440000d
label_13dcf4:
    if (ctx->pc == 0x13DCF4u) {
        ctx->pc = 0x13DCF4u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->pc = 0x13DCF8u;
        goto label_13dcf8;
    }
    ctx->pc = 0x13DCF0u;
    {
        const bool branch_taken_0x13dcf0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13DCF4u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        if (branch_taken_0x13dcf0) {
            ctx->pc = 0x13DD28u;
            goto label_13dd28;
        }
    }
    ctx->pc = 0x13DCF8u;
label_13dcf8:
    // 0x13dcf8: 0x3c020024
    ctx->pc = 0x13dcf8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
label_13dcfc:
    // 0x13dcfc: 0xc045a12
label_13dd00:
    if (ctx->pc == 0x13DD00u) {
        ctx->pc = 0x13DD00u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294956584));
        ctx->pc = 0x13DD04u;
        goto label_13dd04;
    }
    ctx->pc = 0x13DCFCu;
    SET_GPR_U32(ctx, 31, 0x13DD04u);
    ctx->pc = 0x13DD00u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294956584));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD04u; }
    }
    if (ctx->pc != 0x13DD04u) { return; }
    ctx->pc = 0x13DD04u;
label_13dd04:
    // 0x13dd04: 0x0
    ctx->pc = 0x13dd04u;
    // NOP
label_13dd08:
    // 0x13dd08: 0x0
    ctx->pc = 0x13dd08u;
    // NOP
label_13dd0c:
    // 0x13dd0c: 0x0
    ctx->pc = 0x13dd0cu;
    // NOP
label_13dd10:
    // 0x13dd10: 0x0
    ctx->pc = 0x13dd10u;
    // NOP
label_13dd14:
    // 0x13dd14: 0x0
    ctx->pc = 0x13dd14u;
    // NOP
label_13dd18:
    // 0x13dd18: 0x0
    ctx->pc = 0x13dd18u;
    // NOP
label_13dd1c:
    // 0x13dd1c: 0x1000fffa
label_13dd20:
    if (ctx->pc == 0x13DD20u) {
        ctx->pc = 0x13DD24u;
        goto label_13dd24;
    }
    ctx->pc = 0x13DD1Cu;
    {
        const bool branch_taken_0x13dd1c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x13dd1c) {
            ctx->pc = 0x13DD08u;
            goto label_13dd08;
        }
    }
    ctx->pc = 0x13DD24u;
label_13dd24:
    // 0x13dd24: 0x0
    ctx->pc = 0x13dd24u;
    // NOP
label_13dd28:
    // 0x13dd28: 0x1060000b
label_13dd2c:
    if (ctx->pc == 0x13DD2Cu) {
        ctx->pc = 0x13DD2Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
        ctx->pc = 0x13DD30u;
        goto label_13dd30;
    }
    ctx->pc = 0x13DD28u;
    {
        const bool branch_taken_0x13dd28 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x13DD2Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
        if (branch_taken_0x13dd28) {
            ctx->pc = 0x13DD58u;
            goto label_13dd58;
        }
    }
    ctx->pc = 0x13DD30u;
label_13dd30:
    // 0x13dd30: 0xc045a12
label_13dd34:
    if (ctx->pc == 0x13DD34u) {
        ctx->pc = 0x13DD34u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294956640));
        ctx->pc = 0x13DD38u;
        goto label_13dd38;
    }
    ctx->pc = 0x13DD30u;
    SET_GPR_U32(ctx, 31, 0x13DD38u);
    ctx->pc = 0x13DD34u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294956640));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD38u; }
    }
    if (ctx->pc != 0x13DD38u) { return; }
    ctx->pc = 0x13DD38u;
label_13dd38:
    // 0x13dd38: 0x0
    ctx->pc = 0x13dd38u;
    // NOP
label_13dd3c:
    // 0x13dd3c: 0x0
    ctx->pc = 0x13dd3cu;
    // NOP
label_13dd40:
    // 0x13dd40: 0x0
    ctx->pc = 0x13dd40u;
    // NOP
label_13dd44:
    // 0x13dd44: 0x0
    ctx->pc = 0x13dd44u;
    // NOP
label_13dd48:
    // 0x13dd48: 0x0
    ctx->pc = 0x13dd48u;
    // NOP
label_13dd4c:
    // 0x13dd4c: 0x1000fffa
label_13dd50:
    if (ctx->pc == 0x13DD50u) {
        ctx->pc = 0x13DD54u;
        goto label_13dd54;
    }
    ctx->pc = 0x13DD4Cu;
    {
        const bool branch_taken_0x13dd4c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x13dd4c) {
            ctx->pc = 0x13DD38u;
            goto label_13dd38;
        }
    }
    ctx->pc = 0x13DD54u;
label_13dd54:
    // 0x13dd54: 0x0
    ctx->pc = 0x13dd54u;
    // NOP
label_13dd58:
    // 0x13dd58: 0xc050030
label_13dd5c:
    if (ctx->pc == 0x13DD5Cu) {
        ctx->pc = 0x13DD60u;
        goto label_13dd60;
    }
    ctx->pc = 0x13DD58u;
    SET_GPR_U32(ctx, 31, 0x13DD60u);
    ctx->pc = 0x1400C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001400C0_0x1400c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD60u; }
    }
    if (ctx->pc != 0x13DD60u) { return; }
    ctx->pc = 0x13DD60u;
label_13dd60:
    // 0x13dd60: 0x24034000
    ctx->pc = 0x13dd60u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16384));
label_13dd64:
    // 0x13dd64: 0xae020008
    ctx->pc = 0x13dd64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
label_13dd68:
    // 0x13dd68: 0x282d
    ctx->pc = 0x13dd68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13dd6c:
    // 0x13dd6c: 0x1440000c
label_13dd70:
    if (ctx->pc == 0x13DD70u) {
        ctx->pc = 0x13DD70u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 16));
        ctx->pc = 0x13DD74u;
        goto label_13dd74;
    }
    ctx->pc = 0x13DD6Cu;
    {
        const bool branch_taken_0x13dd6c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13DD70u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 16));
        if (branch_taken_0x13dd6c) {
            ctx->pc = 0x13DDA0u;
            goto label_13dda0;
        }
    }
    ctx->pc = 0x13DD74u;
label_13dd74:
    // 0x13dd74: 0xc045a12
label_13dd78:
    if (ctx->pc == 0x13DD78u) {
        ctx->pc = 0x13DD78u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 30), 4294956688));
        ctx->pc = 0x13DD7Cu;
        goto label_13dd7c;
    }
    ctx->pc = 0x13DD74u;
    SET_GPR_U32(ctx, 31, 0x13DD7Cu);
    ctx->pc = 0x13DD78u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 30), 4294956688));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD7Cu; }
    }
    if (ctx->pc != 0x13DD7Cu) { return; }
    ctx->pc = 0x13DD7Cu;
label_13dd7c:
    // 0x13dd7c: 0x0
    ctx->pc = 0x13dd7cu;
    // NOP
label_13dd80:
    // 0x13dd80: 0x0
    ctx->pc = 0x13dd80u;
    // NOP
label_13dd84:
    // 0x13dd84: 0x0
    ctx->pc = 0x13dd84u;
    // NOP
label_13dd88:
    // 0x13dd88: 0x0
    ctx->pc = 0x13dd88u;
    // NOP
label_13dd8c:
    // 0x13dd8c: 0x0
    ctx->pc = 0x13dd8cu;
    // NOP
label_13dd90:
    // 0x13dd90: 0x0
    ctx->pc = 0x13dd90u;
    // NOP
label_13dd94:
    // 0x13dd94: 0x1000fffa
label_13dd98:
    if (ctx->pc == 0x13DD98u) {
        ctx->pc = 0x13DD9Cu;
        goto label_13dd9c;
    }
    ctx->pc = 0x13DD94u;
    {
        const bool branch_taken_0x13dd94 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x13dd94) {
            ctx->pc = 0x13DD80u;
            goto label_13dd80;
        }
    }
    ctx->pc = 0x13DD9Cu;
label_13dd9c:
    // 0x13dd9c: 0x0
    ctx->pc = 0x13dd9cu;
    // NOP
label_13dda0:
    // 0x13dda0: 0x8e040008
    ctx->pc = 0x13dda0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_13dda4:
    // 0x13dda4: 0xae030014
    ctx->pc = 0x13dda4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
label_13dda8:
    // 0x13dda8: 0x8c830000
    ctx->pc = 0x13dda8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_13ddac:
    // 0x13ddac: 0xae110010
    ctx->pc = 0x13ddacu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 17));
label_13ddb0:
    // 0x13ddb0: 0x8c620020
    ctx->pc = 0x13ddb0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 32)));
label_13ddb4:
    // 0x13ddb4: 0x40f809
label_13ddb8:
    if (ctx->pc == 0x13DDB8u) {
        ctx->pc = 0x13DDB8u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 16384));
        ctx->pc = 0x13DDBCu;
        goto label_13ddbc;
    }
    ctx->pc = 0x13DDB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13DDBCu);
        ctx->pc = 0x13DDB8u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 16384));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DB48u: goto label_13db48;
            case 0x13DB4Cu: goto label_13db4c;
            case 0x13DB50u: goto label_13db50;
            case 0x13DB54u: goto label_13db54;
            case 0x13DB58u: goto label_13db58;
            case 0x13DB5Cu: goto label_13db5c;
            case 0x13DB60u: goto label_13db60;
            case 0x13DB64u: goto label_13db64;
            case 0x13DB68u: goto label_13db68;
            case 0x13DB6Cu: goto label_13db6c;
            case 0x13DB70u: goto label_13db70;
            case 0x13DB74u: goto label_13db74;
            case 0x13DB78u: goto label_13db78;
            case 0x13DB7Cu: goto label_13db7c;
            case 0x13DB80u: goto label_13db80;
            case 0x13DB84u: goto label_13db84;
            case 0x13DB88u: goto label_13db88;
            case 0x13DB8Cu: goto label_13db8c;
            case 0x13DB90u: goto label_13db90;
            case 0x13DB94u: goto label_13db94;
            case 0x13DB98u: goto label_13db98;
            case 0x13DB9Cu: goto label_13db9c;
            case 0x13DBA0u: goto label_13dba0;
            case 0x13DBA4u: goto label_13dba4;
            case 0x13DBA8u: goto label_13dba8;
            case 0x13DBACu: goto label_13dbac;
            case 0x13DBB0u: goto label_13dbb0;
            case 0x13DBB4u: goto label_13dbb4;
            case 0x13DBB8u: goto label_13dbb8;
            case 0x13DBBCu: goto label_13dbbc;
            case 0x13DBC0u: goto label_13dbc0;
            case 0x13DBC4u: goto label_13dbc4;
            case 0x13DBC8u: goto label_13dbc8;
            case 0x13DBCCu: goto label_13dbcc;
            case 0x13DBD0u: goto label_13dbd0;
            case 0x13DBD4u: goto label_13dbd4;
            case 0x13DBD8u: goto label_13dbd8;
            case 0x13DBDCu: goto label_13dbdc;
            case 0x13DBE0u: goto label_13dbe0;
            case 0x13DBE4u: goto label_13dbe4;
            case 0x13DBE8u: goto label_13dbe8;
            case 0x13DBECu: goto label_13dbec;
            case 0x13DBF0u: goto label_13dbf0;
            case 0x13DBF4u: goto label_13dbf4;
            case 0x13DBF8u: goto label_13dbf8;
            case 0x13DBFCu: goto label_13dbfc;
            case 0x13DC00u: goto label_13dc00;
            case 0x13DC04u: goto label_13dc04;
            case 0x13DC08u: goto label_13dc08;
            case 0x13DC0Cu: goto label_13dc0c;
            case 0x13DC10u: goto label_13dc10;
            case 0x13DC14u: goto label_13dc14;
            case 0x13DC18u: goto label_13dc18;
            case 0x13DC1Cu: goto label_13dc1c;
            case 0x13DC20u: goto label_13dc20;
            case 0x13DC24u: goto label_13dc24;
            case 0x13DC28u: goto label_13dc28;
            case 0x13DC2Cu: goto label_13dc2c;
            case 0x13DC30u: goto label_13dc30;
            case 0x13DC34u: goto label_13dc34;
            case 0x13DC38u: goto label_13dc38;
            case 0x13DC3Cu: goto label_13dc3c;
            case 0x13DC40u: goto label_13dc40;
            case 0x13DC44u: goto label_13dc44;
            case 0x13DC48u: goto label_13dc48;
            case 0x13DC4Cu: goto label_13dc4c;
            case 0x13DC50u: goto label_13dc50;
            case 0x13DC54u: goto label_13dc54;
            case 0x13DC58u: goto label_13dc58;
            case 0x13DC5Cu: goto label_13dc5c;
            case 0x13DC60u: goto label_13dc60;
            case 0x13DC64u: goto label_13dc64;
            case 0x13DC68u: goto label_13dc68;
            case 0x13DC6Cu: goto label_13dc6c;
            case 0x13DC70u: goto label_13dc70;
            case 0x13DC74u: goto label_13dc74;
            case 0x13DC78u: goto label_13dc78;
            case 0x13DC7Cu: goto label_13dc7c;
            case 0x13DC80u: goto label_13dc80;
            case 0x13DC84u: goto label_13dc84;
            case 0x13DC88u: goto label_13dc88;
            case 0x13DC8Cu: goto label_13dc8c;
            case 0x13DC90u: goto label_13dc90;
            case 0x13DC94u: goto label_13dc94;
            case 0x13DC98u: goto label_13dc98;
            case 0x13DC9Cu: goto label_13dc9c;
            case 0x13DCA0u: goto label_13dca0;
            case 0x13DCA4u: goto label_13dca4;
            case 0x13DCA8u: goto label_13dca8;
            case 0x13DCACu: goto label_13dcac;
            case 0x13DCB0u: goto label_13dcb0;
            case 0x13DCB4u: goto label_13dcb4;
            case 0x13DCB8u: goto label_13dcb8;
            case 0x13DCBCu: goto label_13dcbc;
            case 0x13DCC0u: goto label_13dcc0;
            case 0x13DCC4u: goto label_13dcc4;
            case 0x13DCC8u: goto label_13dcc8;
            case 0x13DCCCu: goto label_13dccc;
            case 0x13DCD0u: goto label_13dcd0;
            case 0x13DCD4u: goto label_13dcd4;
            case 0x13DCD8u: goto label_13dcd8;
            case 0x13DCDCu: goto label_13dcdc;
            case 0x13DCE0u: goto label_13dce0;
            case 0x13DCE4u: goto label_13dce4;
            case 0x13DCE8u: goto label_13dce8;
            case 0x13DCECu: goto label_13dcec;
            case 0x13DCF0u: goto label_13dcf0;
            case 0x13DCF4u: goto label_13dcf4;
            case 0x13DCF8u: goto label_13dcf8;
            case 0x13DCFCu: goto label_13dcfc;
            case 0x13DD00u: goto label_13dd00;
            case 0x13DD04u: goto label_13dd04;
            case 0x13DD08u: goto label_13dd08;
            case 0x13DD0Cu: goto label_13dd0c;
            case 0x13DD10u: goto label_13dd10;
            case 0x13DD14u: goto label_13dd14;
            case 0x13DD18u: goto label_13dd18;
            case 0x13DD1Cu: goto label_13dd1c;
            case 0x13DD20u: goto label_13dd20;
            case 0x13DD24u: goto label_13dd24;
            case 0x13DD28u: goto label_13dd28;
            case 0x13DD2Cu: goto label_13dd2c;
            case 0x13DD30u: goto label_13dd30;
            case 0x13DD34u: goto label_13dd34;
            case 0x13DD38u: goto label_13dd38;
            case 0x13DD3Cu: goto label_13dd3c;
            case 0x13DD40u: goto label_13dd40;
            case 0x13DD44u: goto label_13dd44;
            case 0x13DD48u: goto label_13dd48;
            case 0x13DD4Cu: goto label_13dd4c;
            case 0x13DD50u: goto label_13dd50;
            case 0x13DD54u: goto label_13dd54;
            case 0x13DD58u: goto label_13dd58;
            case 0x13DD5Cu: goto label_13dd5c;
            case 0x13DD60u: goto label_13dd60;
            case 0x13DD64u: goto label_13dd64;
            case 0x13DD68u: goto label_13dd68;
            case 0x13DD6Cu: goto label_13dd6c;
            case 0x13DD70u: goto label_13dd70;
            case 0x13DD74u: goto label_13dd74;
            case 0x13DD78u: goto label_13dd78;
            case 0x13DD7Cu: goto label_13dd7c;
            case 0x13DD80u: goto label_13dd80;
            case 0x13DD84u: goto label_13dd84;
            case 0x13DD88u: goto label_13dd88;
            case 0x13DD8Cu: goto label_13dd8c;
            case 0x13DD90u: goto label_13dd90;
            case 0x13DD94u: goto label_13dd94;
            case 0x13DD98u: goto label_13dd98;
            case 0x13DD9Cu: goto label_13dd9c;
            case 0x13DDA0u: goto label_13dda0;
            case 0x13DDA4u: goto label_13dda4;
            case 0x13DDA8u: goto label_13dda8;
            case 0x13DDACu: goto label_13ddac;
            case 0x13DDB0u: goto label_13ddb0;
            case 0x13DDB4u: goto label_13ddb4;
            case 0x13DDB8u: goto label_13ddb8;
            case 0x13DDBCu: goto label_13ddbc;
            case 0x13DDC0u: goto label_13ddc0;
            case 0x13DDC4u: goto label_13ddc4;
            case 0x13DDC8u: goto label_13ddc8;
            case 0x13DDCCu: goto label_13ddcc;
            case 0x13DDD0u: goto label_13ddd0;
            case 0x13DDD4u: goto label_13ddd4;
            case 0x13DDD8u: goto label_13ddd8;
            case 0x13DDDCu: goto label_13dddc;
            case 0x13DDE0u: goto label_13dde0;
            case 0x13DDE4u: goto label_13dde4;
            case 0x13DDE8u: goto label_13dde8;
            case 0x13DDECu: goto label_13ddec;
            case 0x13DDF0u: goto label_13ddf0;
            case 0x13DDF4u: goto label_13ddf4;
            case 0x13DDF8u: goto label_13ddf8;
            case 0x13DDFCu: goto label_13ddfc;
            case 0x13DE00u: goto label_13de00;
            case 0x13DE04u: goto label_13de04;
            case 0x13DE08u: goto label_13de08;
            case 0x13DE0Cu: goto label_13de0c;
            case 0x13DE10u: goto label_13de10;
            case 0x13DE14u: goto label_13de14;
            case 0x13DE18u: goto label_13de18;
            case 0x13DE1Cu: goto label_13de1c;
            case 0x13DE20u: goto label_13de20;
            case 0x13DE24u: goto label_13de24;
            case 0x13DE28u: goto label_13de28;
            case 0x13DE2Cu: goto label_13de2c;
            case 0x13DE30u: goto label_13de30;
            case 0x13DE34u: goto label_13de34;
            case 0x13DE38u: goto label_13de38;
            case 0x13DE3Cu: goto label_13de3c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13DDBCu; }
            if (ctx->pc != 0x13DDBCu) { return; }
        }
    }
    ctx->pc = 0x13DDBCu;
label_13ddbc:
    // 0x13ddbc: 0x8e040008
    ctx->pc = 0x13ddbcu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_13ddc0:
    // 0x13ddc0: 0x8e050004
    ctx->pc = 0x13ddc0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_13ddc4:
    // 0x13ddc4: 0xc050524
label_13ddc8:
    if (ctx->pc == 0x13DDC8u) {
        ctx->pc = 0x13DDC8u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x13DDCCu;
        goto label_13ddcc;
    }
    ctx->pc = 0x13DDC4u;
    SET_GPR_U32(ctx, 31, 0x13DDCCu);
    ctx->pc = 0x13DDC8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x141490u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141490_0x141490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DDCCu; }
    }
    if (ctx->pc != 0x13DDCCu) { return; }
    ctx->pc = 0x13DDCCu;
label_13ddcc:
    // 0x13ddcc: 0x1440000c
label_13ddd0:
    if (ctx->pc == 0x13DDD0u) {
        ctx->pc = 0x13DDD0u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->pc = 0x13DDD4u;
        goto label_13ddd4;
    }
    ctx->pc = 0x13DDCCu;
    {
        const bool branch_taken_0x13ddcc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13DDD0u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        if (branch_taken_0x13ddcc) {
            ctx->pc = 0x13DE00u;
            goto label_13de00;
        }
    }
    ctx->pc = 0x13DDD4u;
label_13ddd4:
    // 0x13ddd4: 0xc045a12
label_13ddd8:
    if (ctx->pc == 0x13DDD8u) {
        ctx->pc = 0x13DDD8u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 23), 4294956744));
        ctx->pc = 0x13DDDCu;
        goto label_13dddc;
    }
    ctx->pc = 0x13DDD4u;
    SET_GPR_U32(ctx, 31, 0x13DDDCu);
    ctx->pc = 0x13DDD8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 23), 4294956744));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DDDCu; }
    }
    if (ctx->pc != 0x13DDDCu) { return; }
    ctx->pc = 0x13DDDCu;
label_13dddc:
    // 0x13dddc: 0x0
    ctx->pc = 0x13dddcu;
    // NOP
label_13dde0:
    // 0x13dde0: 0x0
    ctx->pc = 0x13dde0u;
    // NOP
label_13dde4:
    // 0x13dde4: 0x0
    ctx->pc = 0x13dde4u;
    // NOP
label_13dde8:
    // 0x13dde8: 0x0
    ctx->pc = 0x13dde8u;
    // NOP
label_13ddec:
    // 0x13ddec: 0x0
    ctx->pc = 0x13ddecu;
    // NOP
label_13ddf0:
    // 0x13ddf0: 0x0
    ctx->pc = 0x13ddf0u;
    // NOP
label_13ddf4:
    // 0x13ddf4: 0x1000fffa
label_13ddf8:
    if (ctx->pc == 0x13DDF8u) {
        ctx->pc = 0x13DDFCu;
        goto label_13ddfc;
    }
    ctx->pc = 0x13DDF4u;
    {
        const bool branch_taken_0x13ddf4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x13ddf4) {
            ctx->pc = 0x13DDE0u;
            goto label_13dde0;
        }
    }
    ctx->pc = 0x13DDFCu;
label_13ddfc:
    // 0x13ddfc: 0x0
    ctx->pc = 0x13ddfcu;
    // NOP
label_13de00:
    // 0x13de00: 0x8ea21438
    ctx->pc = 0x13de00u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 21), 5176)));
label_13de04:
    // 0x13de04: 0x242102a
    ctx->pc = 0x13de04u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 18), GPR_S32(ctx, 2)));
label_13de08:
    // 0x13de08: 0x1440ff9d
label_13de0c:
    if (ctx->pc == 0x13DE0Cu) {
        ctx->pc = 0x13DE0Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 20), 5248));
        ctx->pc = 0x13DE10u;
        goto label_13de10;
    }
    ctx->pc = 0x13DE08u;
    {
        const bool branch_taken_0x13de08 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13DE0Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 20), 5248));
        if (branch_taken_0x13de08) {
            ctx->pc = 0x13DC80u;
            goto label_13dc80;
        }
    }
    ctx->pc = 0x13DE10u;
label_13de10:
    // 0x13de10: 0xdfb00000
    ctx->pc = 0x13de10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13de14:
    // 0x13de14: 0xdfb10008
    ctx->pc = 0x13de14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_13de18:
    // 0x13de18: 0xdfb20010
    ctx->pc = 0x13de18u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_13de1c:
    // 0x13de1c: 0xdfb30018
    ctx->pc = 0x13de1cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_13de20:
    // 0x13de20: 0xdfb40020
    ctx->pc = 0x13de20u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_13de24:
    // 0x13de24: 0xdfb50028
    ctx->pc = 0x13de24u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_13de28:
    // 0x13de28: 0xdfb60030
    ctx->pc = 0x13de28u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_13de2c:
    // 0x13de2c: 0xdfb70038
    ctx->pc = 0x13de2cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
label_13de30:
    // 0x13de30: 0xdfbe0040
    ctx->pc = 0x13de30u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_13de34:
    // 0x13de34: 0xdfbf0048
    ctx->pc = 0x13de34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
label_13de38:
    // 0x13de38: 0x3e00008
label_13de3c:
    if (ctx->pc == 0x13DE3Cu) {
        ctx->pc = 0x13DE3Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = 0x13DE40u;
        goto label_fallthrough_0x13de38;
    }
    ctx->pc = 0x13DE38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13DE3Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DB48u: goto label_13db48;
            case 0x13DB4Cu: goto label_13db4c;
            case 0x13DB50u: goto label_13db50;
            case 0x13DB54u: goto label_13db54;
            case 0x13DB58u: goto label_13db58;
            case 0x13DB5Cu: goto label_13db5c;
            case 0x13DB60u: goto label_13db60;
            case 0x13DB64u: goto label_13db64;
            case 0x13DB68u: goto label_13db68;
            case 0x13DB6Cu: goto label_13db6c;
            case 0x13DB70u: goto label_13db70;
            case 0x13DB74u: goto label_13db74;
            case 0x13DB78u: goto label_13db78;
            case 0x13DB7Cu: goto label_13db7c;
            case 0x13DB80u: goto label_13db80;
            case 0x13DB84u: goto label_13db84;
            case 0x13DB88u: goto label_13db88;
            case 0x13DB8Cu: goto label_13db8c;
            case 0x13DB90u: goto label_13db90;
            case 0x13DB94u: goto label_13db94;
            case 0x13DB98u: goto label_13db98;
            case 0x13DB9Cu: goto label_13db9c;
            case 0x13DBA0u: goto label_13dba0;
            case 0x13DBA4u: goto label_13dba4;
            case 0x13DBA8u: goto label_13dba8;
            case 0x13DBACu: goto label_13dbac;
            case 0x13DBB0u: goto label_13dbb0;
            case 0x13DBB4u: goto label_13dbb4;
            case 0x13DBB8u: goto label_13dbb8;
            case 0x13DBBCu: goto label_13dbbc;
            case 0x13DBC0u: goto label_13dbc0;
            case 0x13DBC4u: goto label_13dbc4;
            case 0x13DBC8u: goto label_13dbc8;
            case 0x13DBCCu: goto label_13dbcc;
            case 0x13DBD0u: goto label_13dbd0;
            case 0x13DBD4u: goto label_13dbd4;
            case 0x13DBD8u: goto label_13dbd8;
            case 0x13DBDCu: goto label_13dbdc;
            case 0x13DBE0u: goto label_13dbe0;
            case 0x13DBE4u: goto label_13dbe4;
            case 0x13DBE8u: goto label_13dbe8;
            case 0x13DBECu: goto label_13dbec;
            case 0x13DBF0u: goto label_13dbf0;
            case 0x13DBF4u: goto label_13dbf4;
            case 0x13DBF8u: goto label_13dbf8;
            case 0x13DBFCu: goto label_13dbfc;
            case 0x13DC00u: goto label_13dc00;
            case 0x13DC04u: goto label_13dc04;
            case 0x13DC08u: goto label_13dc08;
            case 0x13DC0Cu: goto label_13dc0c;
            case 0x13DC10u: goto label_13dc10;
            case 0x13DC14u: goto label_13dc14;
            case 0x13DC18u: goto label_13dc18;
            case 0x13DC1Cu: goto label_13dc1c;
            case 0x13DC20u: goto label_13dc20;
            case 0x13DC24u: goto label_13dc24;
            case 0x13DC28u: goto label_13dc28;
            case 0x13DC2Cu: goto label_13dc2c;
            case 0x13DC30u: goto label_13dc30;
            case 0x13DC34u: goto label_13dc34;
            case 0x13DC38u: goto label_13dc38;
            case 0x13DC3Cu: goto label_13dc3c;
            case 0x13DC40u: goto label_13dc40;
            case 0x13DC44u: goto label_13dc44;
            case 0x13DC48u: goto label_13dc48;
            case 0x13DC4Cu: goto label_13dc4c;
            case 0x13DC50u: goto label_13dc50;
            case 0x13DC54u: goto label_13dc54;
            case 0x13DC58u: goto label_13dc58;
            case 0x13DC5Cu: goto label_13dc5c;
            case 0x13DC60u: goto label_13dc60;
            case 0x13DC64u: goto label_13dc64;
            case 0x13DC68u: goto label_13dc68;
            case 0x13DC6Cu: goto label_13dc6c;
            case 0x13DC70u: goto label_13dc70;
            case 0x13DC74u: goto label_13dc74;
            case 0x13DC78u: goto label_13dc78;
            case 0x13DC7Cu: goto label_13dc7c;
            case 0x13DC80u: goto label_13dc80;
            case 0x13DC84u: goto label_13dc84;
            case 0x13DC88u: goto label_13dc88;
            case 0x13DC8Cu: goto label_13dc8c;
            case 0x13DC90u: goto label_13dc90;
            case 0x13DC94u: goto label_13dc94;
            case 0x13DC98u: goto label_13dc98;
            case 0x13DC9Cu: goto label_13dc9c;
            case 0x13DCA0u: goto label_13dca0;
            case 0x13DCA4u: goto label_13dca4;
            case 0x13DCA8u: goto label_13dca8;
            case 0x13DCACu: goto label_13dcac;
            case 0x13DCB0u: goto label_13dcb0;
            case 0x13DCB4u: goto label_13dcb4;
            case 0x13DCB8u: goto label_13dcb8;
            case 0x13DCBCu: goto label_13dcbc;
            case 0x13DCC0u: goto label_13dcc0;
            case 0x13DCC4u: goto label_13dcc4;
            case 0x13DCC8u: goto label_13dcc8;
            case 0x13DCCCu: goto label_13dccc;
            case 0x13DCD0u: goto label_13dcd0;
            case 0x13DCD4u: goto label_13dcd4;
            case 0x13DCD8u: goto label_13dcd8;
            case 0x13DCDCu: goto label_13dcdc;
            case 0x13DCE0u: goto label_13dce0;
            case 0x13DCE4u: goto label_13dce4;
            case 0x13DCE8u: goto label_13dce8;
            case 0x13DCECu: goto label_13dcec;
            case 0x13DCF0u: goto label_13dcf0;
            case 0x13DCF4u: goto label_13dcf4;
            case 0x13DCF8u: goto label_13dcf8;
            case 0x13DCFCu: goto label_13dcfc;
            case 0x13DD00u: goto label_13dd00;
            case 0x13DD04u: goto label_13dd04;
            case 0x13DD08u: goto label_13dd08;
            case 0x13DD0Cu: goto label_13dd0c;
            case 0x13DD10u: goto label_13dd10;
            case 0x13DD14u: goto label_13dd14;
            case 0x13DD18u: goto label_13dd18;
            case 0x13DD1Cu: goto label_13dd1c;
            case 0x13DD20u: goto label_13dd20;
            case 0x13DD24u: goto label_13dd24;
            case 0x13DD28u: goto label_13dd28;
            case 0x13DD2Cu: goto label_13dd2c;
            case 0x13DD30u: goto label_13dd30;
            case 0x13DD34u: goto label_13dd34;
            case 0x13DD38u: goto label_13dd38;
            case 0x13DD3Cu: goto label_13dd3c;
            case 0x13DD40u: goto label_13dd40;
            case 0x13DD44u: goto label_13dd44;
            case 0x13DD48u: goto label_13dd48;
            case 0x13DD4Cu: goto label_13dd4c;
            case 0x13DD50u: goto label_13dd50;
            case 0x13DD54u: goto label_13dd54;
            case 0x13DD58u: goto label_13dd58;
            case 0x13DD5Cu: goto label_13dd5c;
            case 0x13DD60u: goto label_13dd60;
            case 0x13DD64u: goto label_13dd64;
            case 0x13DD68u: goto label_13dd68;
            case 0x13DD6Cu: goto label_13dd6c;
            case 0x13DD70u: goto label_13dd70;
            case 0x13DD74u: goto label_13dd74;
            case 0x13DD78u: goto label_13dd78;
            case 0x13DD7Cu: goto label_13dd7c;
            case 0x13DD80u: goto label_13dd80;
            case 0x13DD84u: goto label_13dd84;
            case 0x13DD88u: goto label_13dd88;
            case 0x13DD8Cu: goto label_13dd8c;
            case 0x13DD90u: goto label_13dd90;
            case 0x13DD94u: goto label_13dd94;
            case 0x13DD98u: goto label_13dd98;
            case 0x13DD9Cu: goto label_13dd9c;
            case 0x13DDA0u: goto label_13dda0;
            case 0x13DDA4u: goto label_13dda4;
            case 0x13DDA8u: goto label_13dda8;
            case 0x13DDACu: goto label_13ddac;
            case 0x13DDB0u: goto label_13ddb0;
            case 0x13DDB4u: goto label_13ddb4;
            case 0x13DDB8u: goto label_13ddb8;
            case 0x13DDBCu: goto label_13ddbc;
            case 0x13DDC0u: goto label_13ddc0;
            case 0x13DDC4u: goto label_13ddc4;
            case 0x13DDC8u: goto label_13ddc8;
            case 0x13DDCCu: goto label_13ddcc;
            case 0x13DDD0u: goto label_13ddd0;
            case 0x13DDD4u: goto label_13ddd4;
            case 0x13DDD8u: goto label_13ddd8;
            case 0x13DDDCu: goto label_13dddc;
            case 0x13DDE0u: goto label_13dde0;
            case 0x13DDE4u: goto label_13dde4;
            case 0x13DDE8u: goto label_13dde8;
            case 0x13DDECu: goto label_13ddec;
            case 0x13DDF0u: goto label_13ddf0;
            case 0x13DDF4u: goto label_13ddf4;
            case 0x13DDF8u: goto label_13ddf8;
            case 0x13DDFCu: goto label_13ddfc;
            case 0x13DE00u: goto label_13de00;
            case 0x13DE04u: goto label_13de04;
            case 0x13DE08u: goto label_13de08;
            case 0x13DE0Cu: goto label_13de0c;
            case 0x13DE10u: goto label_13de10;
            case 0x13DE14u: goto label_13de14;
            case 0x13DE18u: goto label_13de18;
            case 0x13DE1Cu: goto label_13de1c;
            case 0x13DE20u: goto label_13de20;
            case 0x13DE24u: goto label_13de24;
            case 0x13DE28u: goto label_13de28;
            case 0x13DE2Cu: goto label_13de2c;
            case 0x13DE30u: goto label_13de30;
            case 0x13DE34u: goto label_13de34;
            case 0x13DE38u: goto label_13de38;
            case 0x13DE3Cu: goto label_13de3c;
            default: break;
        }
        return;
    }
label_fallthrough_0x13de38:
    ctx->pc = 0x13DE40u;
}
