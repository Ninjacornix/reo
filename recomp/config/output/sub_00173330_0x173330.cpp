#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00173330
// Address: 0x173330 - 0x1734b8
void sub_00173330_0x173330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x173330u;

    // 0x173330: 0x27bdffe0
    ctx->pc = 0x173330u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x173334: 0x24030004
    ctx->pc = 0x173334u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4));
    // 0x173338: 0xffb00010
    ctx->pc = 0x173338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17333c: 0x80802d
    ctx->pc = 0x17333cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173340: 0xffbf0018
    ctx->pc = 0x173340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x173344: 0x8e020048
    ctx->pc = 0x173344u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x173348: 0x1443000c
    ctx->pc = 0x173348u;
    {
        const bool branch_taken_0x173348 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x17334Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 2380));
        if (branch_taken_0x173348) {
            ctx->pc = 0x17337Cu;
            goto label_17337c;
        }
    }
    ctx->pc = 0x173350u;
    // 0x173350: 0x8e020050
    ctx->pc = 0x173350u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x173354: 0x24030001
    ctx->pc = 0x173354u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x173358: 0x10430015
    ctx->pc = 0x173358u;
    {
        const bool branch_taken_0x173358 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x17335Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x173358) {
            ctx->pc = 0x1733B0u;
            goto label_1733b0;
        }
    }
    ctx->pc = 0x173360u;
    // 0x173360: 0x8ca20018
    ctx->pc = 0x173360u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x173364: 0x10430005
    ctx->pc = 0x173364u;
    {
        const bool branch_taken_0x173364 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x173368u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x173364) {
            ctx->pc = 0x17337Cu;
            goto label_17337c;
        }
    }
    ctx->pc = 0x17336Cu;
    // 0x17336c: 0xc05d884
    ctx->pc = 0x17336Cu;
    SET_GPR_U32(ctx, 31, 0x173374u);
    ctx->pc = 0x173370u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 29), 4));
    ctx->pc = 0x176210u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00176210_0x176210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173374u; }
    }
    if (ctx->pc != 0x173374u) { return; }
    ctx->pc = 0x173374u;
    // 0x173374: 0x10400004
    ctx->pc = 0x173374u;
    {
        const bool branch_taken_0x173374 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x173378u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x173374) {
            ctx->pc = 0x173388u;
            goto label_173388;
        }
    }
    ctx->pc = 0x17337Cu;
label_17337c:
    // 0x17337c: 0x1000000c
    ctx->pc = 0x17337Cu;
    {
        const bool branch_taken_0x17337c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x173380u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17337c) {
            ctx->pc = 0x1733B0u;
            goto label_1733b0;
        }
    }
    ctx->pc = 0x173384u;
    // 0x173384: 0x0
    ctx->pc = 0x173384u;
    // NOP
label_173388:
    // 0x173388: 0x4600009
    ctx->pc = 0x173388u;
    {
        const bool branch_taken_0x173388 = (GPR_S32(ctx, 3) < 0);
        ctx->pc = 0x17338Cu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x173388) {
            ctx->pc = 0x1733B0u;
            goto label_1733b0;
        }
    }
    ctx->pc = 0x173390u;
    // 0x173390: 0xc05d58a
    ctx->pc = 0x173390u;
    SET_GPR_U32(ctx, 31, 0x173398u);
    ctx->pc = 0x173394u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 54));
    ctx->pc = 0x175628u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173398u; }
    }
    if (ctx->pc != 0x173398u) { return; }
    ctx->pc = 0x173398u;
    // 0x173398: 0x240503e8
    ctx->pc = 0x173398u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1000));
    // 0x17339c: 0x8fa60000
    ctx->pc = 0x17339cu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1733a0: 0x40202d
    ctx->pc = 0x1733a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1733a4: 0xc05d9de
    ctx->pc = 0x1733A4u;
    SET_GPR_U32(ctx, 31, 0x1733ACu);
    ctx->pc = 0x1733A8u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 4)));
    ctx->pc = 0x176778u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00176778_0x176778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1733ACu; }
    }
    if (ctx->pc != 0x1733ACu) { return; }
    ctx->pc = 0x1733ACu;
    // 0x1733ac: 0x2102b
    ctx->pc = 0x1733acu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
label_1733b0:
    // 0x1733b0: 0xdfb00010
    ctx->pc = 0x1733b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1733b4: 0xdfbf0018
    ctx->pc = 0x1733b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1733b8: 0x3e00008
    ctx->pc = 0x1733B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1733BCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17337Cu: goto label_17337c;
            case 0x173388u: goto label_173388;
            case 0x1733B0u: goto label_1733b0;
            case 0x1733E8u: goto label_1733e8;
            case 0x173430u: goto label_173430;
            case 0x173458u: goto label_173458;
            case 0x17346Cu: goto label_17346c;
            case 0x173490u: goto label_173490;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1733C0u;
    // 0x1733c0: 0x27bdfff0
    ctx->pc = 0x1733c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1733c4: 0xffb00000
    ctx->pc = 0x1733c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1733c8: 0xffbf0008
    ctx->pc = 0x1733c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1733cc: 0xc05cf04
    ctx->pc = 0x1733CCu;
    SET_GPR_U32(ctx, 31, 0x1733D4u);
    ctx->pc = 0x1733D0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x173C10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00173C10_0x173c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1733D4u; }
    }
    if (ctx->pc != 0x1733D4u) { return; }
    ctx->pc = 0x1733D4u;
    // 0x1733d4: 0x54400004
    ctx->pc = 0x1733D4u;
    {
        const bool branch_taken_0x1733d4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1733d4) {
            ctx->pc = 0x1733D8u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x1733E8u;
            goto label_1733e8;
        }
    }
    ctx->pc = 0x1733DCu;
    // 0x1733dc: 0x24030006
    ctx->pc = 0x1733dcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 6));
    // 0x1733e0: 0xae03004c
    ctx->pc = 0x1733e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 3));
    // 0x1733e4: 0xdfb00000
    ctx->pc = 0x1733e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1733e8:
    // 0x1733e8: 0xdfbf0008
    ctx->pc = 0x1733e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1733ec: 0x3e00008
    ctx->pc = 0x1733ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1733F0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17337Cu: goto label_17337c;
            case 0x173388u: goto label_173388;
            case 0x1733B0u: goto label_1733b0;
            case 0x1733E8u: goto label_1733e8;
            case 0x173430u: goto label_173430;
            case 0x173458u: goto label_173458;
            case 0x17346Cu: goto label_17346c;
            case 0x173490u: goto label_173490;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1733F4u;
    // 0x1733f4: 0x0
    ctx->pc = 0x1733f4u;
    // NOP
    // 0x1733f8: 0x27bdffd0
    ctx->pc = 0x1733f8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1733fc: 0xffb00020
    ctx->pc = 0x1733fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x173400: 0xffbf0028
    ctx->pc = 0x173400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x173404: 0xc05a7b2
    ctx->pc = 0x173404u;
    SET_GPR_U32(ctx, 31, 0x17340Cu);
    ctx->pc = 0x173408u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x169EC8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17340Cu; }
    }
    if (ctx->pc != 0x17340Cu) { return; }
    ctx->pc = 0x17340Cu;
    // 0x17340c: 0xafa00000
    ctx->pc = 0x17340cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x173410: 0x3c020023
    ctx->pc = 0x173410u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x173414: 0xafa00004
    ctx->pc = 0x173414u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 0));
    // 0x173418: 0x2446f18c
    ctx->pc = 0x173418u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 4294963596));
    // 0x17341c: 0xafa00008
    ctx->pc = 0x17341cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x173420: 0x24070006
    ctx->pc = 0x173420u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 6));
    // 0x173424: 0x24050007
    ctx->pc = 0x173424u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 7));
    // 0x173428: 0x8cc20000
    ctx->pc = 0x173428u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x17342c: 0x0
    ctx->pc = 0x17342cu;
    // NOP
label_173430:
    // 0x173430: 0x1040000e
    ctx->pc = 0x173430u;
    {
        const bool branch_taken_0x173430 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x173434u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 4));
        if (branch_taken_0x173430) {
            ctx->pc = 0x17346Cu;
            goto label_17346c;
        }
    }
    ctx->pc = 0x173438u;
    // 0x173438: 0x8c420048
    ctx->pc = 0x173438u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x17343c: 0x10400006
    ctx->pc = 0x17343Cu;
    {
        const bool branch_taken_0x17343c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x173440u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17343c) {
            ctx->pc = 0x173458u;
            goto label_173458;
        }
    }
    ctx->pc = 0x173444u;
    // 0x173444: 0x10470004
    ctx->pc = 0x173444u;
    {
        const bool branch_taken_0x173444 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 7));
        ctx->pc = 0x173448u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x173444) {
            ctx->pc = 0x173458u;
            goto label_173458;
        }
    }
    ctx->pc = 0x17344Cu;
    // 0x17344c: 0x4410002
    ctx->pc = 0x17344Cu;
    {
        const bool branch_taken_0x17344c = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x173450u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x17344c) {
            ctx->pc = 0x173458u;
            goto label_173458;
        }
    }
    ctx->pc = 0x173454u;
    // 0x173454: 0x24100002
    ctx->pc = 0x173454u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
label_173458:
    // 0x173458: 0x101080
    ctx->pc = 0x173458u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 16), 2));
    // 0x17345c: 0x3a22021
    ctx->pc = 0x17345cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x173460: 0x8c830000
    ctx->pc = 0x173460u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x173464: 0x24630001
    ctx->pc = 0x173464u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1));
    // 0x173468: 0xac830000
    ctx->pc = 0x173468u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
label_17346c:
    // 0x17346c: 0x24a5ffff
    ctx->pc = 0x17346cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x173470: 0x4a3ffef
    ctx->pc = 0x173470u;
    {
        const bool branch_taken_0x173470 = (GPR_S32(ctx, 5) >= 0);
        if (branch_taken_0x173470) {
            ctx->pc = 0x173474u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
            ctx->pc = 0x173430u;
            goto label_173430;
        }
    }
    ctx->pc = 0x173478u;
    // 0x173478: 0x8fa20004
    ctx->pc = 0x173478u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x17347c: 0x14400004
    ctx->pc = 0x17347Cu;
    {
        const bool branch_taken_0x17347c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x173480u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x17347c) {
            ctx->pc = 0x173490u;
            goto label_173490;
        }
    }
    ctx->pc = 0x173484u;
    // 0x173484: 0x8fa20008
    ctx->pc = 0x173484u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173488: 0x24100002
    ctx->pc = 0x173488u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
    // 0x17348c: 0x2800a
    ctx->pc = 0x17348cu;
    if (GPR_U32(ctx, 2) == 0) SET_GPR_U32(ctx, 16, GPR_U32(ctx, 0));
label_173490:
    // 0x173490: 0x3c020023
    ctx->pc = 0x173490u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x173494: 0x27a40010
    ctx->pc = 0x173494u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    // 0x173498: 0xc05a7b8
    ctx->pc = 0x173498u;
    SET_GPR_U32(ctx, 31, 0x1734A0u);
    ctx->pc = 0x17349Cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963488), GPR_U32(ctx, 16));
    ctx->pc = 0x169EE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1734A0u; }
    }
    if (ctx->pc != 0x1734A0u) { return; }
    ctx->pc = 0x1734A0u;
    // 0x1734a0: 0xdfbf0028
    ctx->pc = 0x1734a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1734a4: 0x200102d
    ctx->pc = 0x1734a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1734a8: 0xdfb00020
    ctx->pc = 0x1734a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1734ac: 0x3e00008
    ctx->pc = 0x1734ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1734B0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17337Cu: goto label_17337c;
            case 0x173388u: goto label_173388;
            case 0x1733B0u: goto label_1733b0;
            case 0x1733E8u: goto label_1733e8;
            case 0x173430u: goto label_173430;
            case 0x173458u: goto label_173458;
            case 0x17346Cu: goto label_17346c;
            case 0x173490u: goto label_173490;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1734B4u;
    // 0x1734b4: 0x0
    ctx->pc = 0x1734b4u;
    // NOP
}
