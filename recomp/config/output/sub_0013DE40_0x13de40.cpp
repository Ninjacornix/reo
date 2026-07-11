#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013DE40
// Address: 0x13de40 - 0x13df20
void sub_0013DE40_0x13de40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13de40u;

label_13de40:
    // 0x13de40: 0x27bdffe0
    ctx->pc = 0x13de40u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_13de44:
    // 0x13de44: 0xffb20010
    ctx->pc = 0x13de44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_13de48:
    // 0x13de48: 0x3c120022
    ctx->pc = 0x13de48u;
    SET_GPR_U32(ctx, 18, ((uint32_t)34 << 16));
label_13de4c:
    // 0x13de4c: 0x8e421438
    ctx->pc = 0x13de4cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 5176)));
label_13de50:
    // 0x13de50: 0xffb10008
    ctx->pc = 0x13de50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_13de54:
    // 0x13de54: 0x882d
    ctx->pc = 0x13de54u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13de58:
    // 0x13de58: 0xffb00000
    ctx->pc = 0x13de58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_13de5c:
    // 0x13de5c: 0x1840001e
label_13de60:
    if (ctx->pc == 0x13DE60u) {
        ctx->pc = 0x13DE60u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->pc = 0x13DE64u;
        goto label_13de64;
    }
    ctx->pc = 0x13DE5Cu;
    {
        const bool branch_taken_0x13de5c = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x13DE60u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        if (branch_taken_0x13de5c) {
            ctx->pc = 0x13DED8u;
            goto label_13ded8;
        }
    }
    ctx->pc = 0x13DE64u;
label_13de64:
    // 0x13de64: 0x3c020022
    ctx->pc = 0x13de64u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_13de68:
    // 0x13de68: 0x24501480
    ctx->pc = 0x13de68u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 5248));
label_13de6c:
    // 0x13de6c: 0x8e020004
    ctx->pc = 0x13de6cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_13de70:
    // 0x13de70: 0x10400003
label_13de74:
    if (ctx->pc == 0x13DE74u) {
        ctx->pc = 0x13DE74u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x13DE78u;
        goto label_13de78;
    }
    ctx->pc = 0x13DE70u;
    {
        const bool branch_taken_0x13de70 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x13DE74u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13de70) {
            ctx->pc = 0x13DE80u;
            goto label_13de80;
        }
    }
    ctx->pc = 0x13DE78u;
label_13de78:
    // 0x13de78: 0xc0502fc
label_13de7c:
    if (ctx->pc == 0x13DE7Cu) {
        ctx->pc = 0x13DE80u;
        goto label_13de80;
    }
    ctx->pc = 0x13DE78u;
    SET_GPR_U32(ctx, 31, 0x13DE80u);
    ctx->pc = 0x140BF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00140BF0_0x140bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DE80u; }
    }
    if (ctx->pc != 0x13DE80u) { return; }
    ctx->pc = 0x13DE80u;
label_13de80:
    // 0x13de80: 0x8e020008
    ctx->pc = 0x13de80u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_13de84:
    // 0x13de84: 0x10400005
label_13de88:
    if (ctx->pc == 0x13DE88u) {
        ctx->pc = 0x13DE88u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x13DE8Cu;
        goto label_13de8c;
    }
    ctx->pc = 0x13DE84u;
    {
        const bool branch_taken_0x13de84 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x13DE88u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13de84) {
            ctx->pc = 0x13DE9Cu;
            goto label_13de9c;
        }
    }
    ctx->pc = 0x13DE8Cu;
label_13de8c:
    // 0x13de8c: 0x8c420000
    ctx->pc = 0x13de8cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_13de90:
    // 0x13de90: 0x8c43000c
    ctx->pc = 0x13de90u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 12)));
label_13de94:
    // 0x13de94: 0x60f809
label_13de98:
    if (ctx->pc == 0x13DE98u) {
        ctx->pc = 0x13DE9Cu;
        goto label_13de9c;
    }
    ctx->pc = 0x13DE94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x13DE9Cu);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DE40u: goto label_13de40;
            case 0x13DE44u: goto label_13de44;
            case 0x13DE48u: goto label_13de48;
            case 0x13DE4Cu: goto label_13de4c;
            case 0x13DE50u: goto label_13de50;
            case 0x13DE54u: goto label_13de54;
            case 0x13DE58u: goto label_13de58;
            case 0x13DE5Cu: goto label_13de5c;
            case 0x13DE60u: goto label_13de60;
            case 0x13DE64u: goto label_13de64;
            case 0x13DE68u: goto label_13de68;
            case 0x13DE6Cu: goto label_13de6c;
            case 0x13DE70u: goto label_13de70;
            case 0x13DE74u: goto label_13de74;
            case 0x13DE78u: goto label_13de78;
            case 0x13DE7Cu: goto label_13de7c;
            case 0x13DE80u: goto label_13de80;
            case 0x13DE84u: goto label_13de84;
            case 0x13DE88u: goto label_13de88;
            case 0x13DE8Cu: goto label_13de8c;
            case 0x13DE90u: goto label_13de90;
            case 0x13DE94u: goto label_13de94;
            case 0x13DE98u: goto label_13de98;
            case 0x13DE9Cu: goto label_13de9c;
            case 0x13DEA0u: goto label_13dea0;
            case 0x13DEA4u: goto label_13dea4;
            case 0x13DEA8u: goto label_13dea8;
            case 0x13DEACu: goto label_13deac;
            case 0x13DEB0u: goto label_13deb0;
            case 0x13DEB4u: goto label_13deb4;
            case 0x13DEB8u: goto label_13deb8;
            case 0x13DEBCu: goto label_13debc;
            case 0x13DEC0u: goto label_13dec0;
            case 0x13DEC4u: goto label_13dec4;
            case 0x13DEC8u: goto label_13dec8;
            case 0x13DECCu: goto label_13decc;
            case 0x13DED0u: goto label_13ded0;
            case 0x13DED4u: goto label_13ded4;
            case 0x13DED8u: goto label_13ded8;
            case 0x13DEDCu: goto label_13dedc;
            case 0x13DEE0u: goto label_13dee0;
            case 0x13DEE4u: goto label_13dee4;
            case 0x13DEE8u: goto label_13dee8;
            case 0x13DEECu: goto label_13deec;
            case 0x13DEF0u: goto label_13def0;
            case 0x13DEF4u: goto label_13def4;
            case 0x13DEF8u: goto label_13def8;
            case 0x13DEFCu: goto label_13defc;
            case 0x13DF00u: goto label_13df00;
            case 0x13DF04u: goto label_13df04;
            case 0x13DF08u: goto label_13df08;
            case 0x13DF0Cu: goto label_13df0c;
            case 0x13DF10u: goto label_13df10;
            case 0x13DF14u: goto label_13df14;
            case 0x13DF18u: goto label_13df18;
            case 0x13DF1Cu: goto label_13df1c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13DE9Cu; }
            if (ctx->pc != 0x13DE9Cu) { return; }
        }
    }
    ctx->pc = 0x13DE9Cu;
label_13de9c:
    // 0x13de9c: 0x8e04000c
    ctx->pc = 0x13de9cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_13dea0:
    // 0x13dea0: 0x50800004
label_13dea4:
    if (ctx->pc == 0x13DEA4u) {
        ctx->pc = 0x13DEA4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x13DEA8u;
        goto label_13dea8;
    }
    ctx->pc = 0x13DEA0u;
    {
        const bool branch_taken_0x13dea0 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        if (branch_taken_0x13dea0) {
            ctx->pc = 0x13DEA4u;
            SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x13DEB4u;
            goto label_13deb4;
        }
    }
    ctx->pc = 0x13DEA8u;
label_13dea8:
    // 0x13dea8: 0xc050562
label_13deac:
    if (ctx->pc == 0x13DEACu) {
        ctx->pc = 0x13DEB0u;
        goto label_13deb0;
    }
    ctx->pc = 0x13DEA8u;
    SET_GPR_U32(ctx, 31, 0x13DEB0u);
    ctx->pc = 0x141588u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141588_0x141588(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DEB0u; }
    }
    if (ctx->pc != 0x13DEB0u) { return; }
    ctx->pc = 0x13DEB0u;
label_13deb0:
    // 0x13deb0: 0x200202d
    ctx->pc = 0x13deb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_13deb4:
    // 0x13deb4: 0x26100018
    ctx->pc = 0x13deb4u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 24));
label_13deb8:
    // 0x13deb8: 0x282d
    ctx->pc = 0x13deb8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13debc:
    // 0x13debc: 0xc041f1a
label_13dec0:
    if (ctx->pc == 0x13DEC0u) {
        ctx->pc = 0x13DEC0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 24));
        ctx->pc = 0x13DEC4u;
        goto label_13dec4;
    }
    ctx->pc = 0x13DEBCu;
    SET_GPR_U32(ctx, 31, 0x13DEC4u);
    ctx->pc = 0x13DEC0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 24));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DEC4u; }
    }
    if (ctx->pc != 0x13DEC4u) { return; }
    ctx->pc = 0x13DEC4u;
label_13dec4:
    // 0x13dec4: 0x8e431438
    ctx->pc = 0x13dec4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 5176)));
label_13dec8:
    // 0x13dec8: 0x26310001
    ctx->pc = 0x13dec8u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 1));
label_13decc:
    // 0x13decc: 0x223182a
    ctx->pc = 0x13deccu;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 17), GPR_S32(ctx, 3)));
label_13ded0:
    // 0x13ded0: 0x5460ffe7
label_13ded4:
    if (ctx->pc == 0x13DED4u) {
        ctx->pc = 0x13DED4u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->pc = 0x13DED8u;
        goto label_13ded8;
    }
    ctx->pc = 0x13DED0u;
    {
        const bool branch_taken_0x13ded0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x13ded0) {
            ctx->pc = 0x13DED4u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4)));
            ctx->pc = 0x13DE70u;
            goto label_13de70;
        }
    }
    ctx->pc = 0x13DED8u;
label_13ded8:
    // 0x13ded8: 0x3c020022
    ctx->pc = 0x13ded8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_13dedc:
    // 0x13dedc: 0x24040001
    ctx->pc = 0x13dedcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
label_13dee0:
    // 0x13dee0: 0x2451144c
    ctx->pc = 0x13dee0u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 2), 5196));
label_13dee4:
    // 0x13dee4: 0x82230000
    ctx->pc = 0x13dee4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_13dee8:
    // 0x13dee8: 0x14640008
label_13deec:
    if (ctx->pc == 0x13DEECu) {
        ctx->pc = 0x13DEECu;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x13DEF0u;
        goto label_13def0;
    }
    ctx->pc = 0x13DEE8u;
    {
        const bool branch_taken_0x13dee8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 4));
        ctx->pc = 0x13DEECu;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x13dee8) {
            ctx->pc = 0x13DF0Cu;
            goto label_13df0c;
        }
    }
    ctx->pc = 0x13DEF0u;
label_13def0:
    // 0x13def0: 0x3c100022
    ctx->pc = 0x13def0u;
    SET_GPR_U32(ctx, 16, ((uint32_t)34 << 16));
label_13def4:
    // 0x13def4: 0x26101444
    ctx->pc = 0x13def4u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 5188));
label_13def8:
    // 0x13def8: 0xc046e86
label_13defc:
    if (ctx->pc == 0x13DEFCu) {
        ctx->pc = 0x13DEFCu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->pc = 0x13DF00u;
        goto label_13df00;
    }
    ctx->pc = 0x13DEF8u;
    SET_GPR_U32(ctx, 31, 0x13DF00u);
    ctx->pc = 0x13DEFCu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    ctx->pc = 0x11BA18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BA18_0x11ba18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DF00u; }
    }
    if (ctx->pc != 0x13DF00u) { return; }
    ctx->pc = 0x13DF00u;
label_13df00:
    // 0x13df00: 0xae000000
    ctx->pc = 0x13df00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_13df04:
    // 0x13df04: 0xa2200000
    ctx->pc = 0x13df04u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
label_13df08:
    // 0x13df08: 0xdfb00000
    ctx->pc = 0x13df08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13df0c:
    // 0x13df0c: 0xdfb10008
    ctx->pc = 0x13df0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_13df10:
    // 0x13df10: 0xdfb20010
    ctx->pc = 0x13df10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_13df14:
    // 0x13df14: 0xdfbf0018
    ctx->pc = 0x13df14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_13df18:
    // 0x13df18: 0x3e00008
label_13df1c:
    if (ctx->pc == 0x13DF1Cu) {
        ctx->pc = 0x13DF1Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x13DF20u;
        goto label_fallthrough_0x13df18;
    }
    ctx->pc = 0x13DF18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13DF1Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DE40u: goto label_13de40;
            case 0x13DE44u: goto label_13de44;
            case 0x13DE48u: goto label_13de48;
            case 0x13DE4Cu: goto label_13de4c;
            case 0x13DE50u: goto label_13de50;
            case 0x13DE54u: goto label_13de54;
            case 0x13DE58u: goto label_13de58;
            case 0x13DE5Cu: goto label_13de5c;
            case 0x13DE60u: goto label_13de60;
            case 0x13DE64u: goto label_13de64;
            case 0x13DE68u: goto label_13de68;
            case 0x13DE6Cu: goto label_13de6c;
            case 0x13DE70u: goto label_13de70;
            case 0x13DE74u: goto label_13de74;
            case 0x13DE78u: goto label_13de78;
            case 0x13DE7Cu: goto label_13de7c;
            case 0x13DE80u: goto label_13de80;
            case 0x13DE84u: goto label_13de84;
            case 0x13DE88u: goto label_13de88;
            case 0x13DE8Cu: goto label_13de8c;
            case 0x13DE90u: goto label_13de90;
            case 0x13DE94u: goto label_13de94;
            case 0x13DE98u: goto label_13de98;
            case 0x13DE9Cu: goto label_13de9c;
            case 0x13DEA0u: goto label_13dea0;
            case 0x13DEA4u: goto label_13dea4;
            case 0x13DEA8u: goto label_13dea8;
            case 0x13DEACu: goto label_13deac;
            case 0x13DEB0u: goto label_13deb0;
            case 0x13DEB4u: goto label_13deb4;
            case 0x13DEB8u: goto label_13deb8;
            case 0x13DEBCu: goto label_13debc;
            case 0x13DEC0u: goto label_13dec0;
            case 0x13DEC4u: goto label_13dec4;
            case 0x13DEC8u: goto label_13dec8;
            case 0x13DECCu: goto label_13decc;
            case 0x13DED0u: goto label_13ded0;
            case 0x13DED4u: goto label_13ded4;
            case 0x13DED8u: goto label_13ded8;
            case 0x13DEDCu: goto label_13dedc;
            case 0x13DEE0u: goto label_13dee0;
            case 0x13DEE4u: goto label_13dee4;
            case 0x13DEE8u: goto label_13dee8;
            case 0x13DEECu: goto label_13deec;
            case 0x13DEF0u: goto label_13def0;
            case 0x13DEF4u: goto label_13def4;
            case 0x13DEF8u: goto label_13def8;
            case 0x13DEFCu: goto label_13defc;
            case 0x13DF00u: goto label_13df00;
            case 0x13DF04u: goto label_13df04;
            case 0x13DF08u: goto label_13df08;
            case 0x13DF0Cu: goto label_13df0c;
            case 0x13DF10u: goto label_13df10;
            case 0x13DF14u: goto label_13df14;
            case 0x13DF18u: goto label_13df18;
            case 0x13DF1Cu: goto label_13df1c;
            default: break;
        }
        return;
    }
label_fallthrough_0x13df18:
    ctx->pc = 0x13DF20u;
}
