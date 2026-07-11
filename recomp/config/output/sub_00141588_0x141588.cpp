#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00141588
// Address: 0x141588 - 0x1416d0
void sub_00141588_0x141588(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x141588u;

label_141588:
    // 0x141588: 0x27bdffe0
    ctx->pc = 0x141588u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_14158c:
    // 0x14158c: 0x24060001
    ctx->pc = 0x14158cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
label_141590:
    // 0x141590: 0xffb00010
    ctx->pc = 0x141590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
label_141594:
    // 0x141594: 0x80802d
    ctx->pc = 0x141594u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_141598:
    // 0x141598: 0xffbf0018
    ctx->pc = 0x141598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_14159c:
    // 0x14159c: 0x3a0282d
    ctx->pc = 0x14159cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_1415a0:
    // 0x1415a0: 0x24040001
    ctx->pc = 0x1415a0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
label_1415a4:
    // 0x1415a4: 0x382d
    ctx->pc = 0x1415a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1415a8:
    // 0x1415a8: 0x8e020010
    ctx->pc = 0x1415a8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 16)));
label_1415ac:
    // 0x1415ac: 0x402d
    ctx->pc = 0x1415acu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1415b0:
    // 0x1415b0: 0xc04e518
label_1415b4:
    if (ctx->pc == 0x1415B4u) {
        ctx->pc = 0x1415B4u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x1415B8u;
        goto label_1415b8;
    }
    ctx->pc = 0x1415B0u;
    SET_GPR_U32(ctx, 31, 0x1415B8u);
    ctx->pc = 0x1415B4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x139460u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1415B8u; }
    }
    if (ctx->pc != 0x1415B8u) { return; }
    ctx->pc = 0x1415B8u;
label_1415b8:
    // 0x1415b8: 0xdfbf0018
    ctx->pc = 0x1415b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_1415bc:
    // 0x1415bc: 0xa2000000
    ctx->pc = 0x1415bcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1415c0:
    // 0x1415c0: 0xdfb00010
    ctx->pc = 0x1415c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1415c4:
    // 0x1415c4: 0x3e00008
label_1415c8:
    if (ctx->pc == 0x1415C8u) {
        ctx->pc = 0x1415C8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x1415CCu;
        goto label_1415cc;
    }
    ctx->pc = 0x1415C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1415C8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141588u: goto label_141588;
            case 0x14158Cu: goto label_14158c;
            case 0x141590u: goto label_141590;
            case 0x141594u: goto label_141594;
            case 0x141598u: goto label_141598;
            case 0x14159Cu: goto label_14159c;
            case 0x1415A0u: goto label_1415a0;
            case 0x1415A4u: goto label_1415a4;
            case 0x1415A8u: goto label_1415a8;
            case 0x1415ACu: goto label_1415ac;
            case 0x1415B0u: goto label_1415b0;
            case 0x1415B4u: goto label_1415b4;
            case 0x1415B8u: goto label_1415b8;
            case 0x1415BCu: goto label_1415bc;
            case 0x1415C0u: goto label_1415c0;
            case 0x1415C4u: goto label_1415c4;
            case 0x1415C8u: goto label_1415c8;
            case 0x1415CCu: goto label_1415cc;
            case 0x1415D0u: goto label_1415d0;
            case 0x1415D4u: goto label_1415d4;
            case 0x1415D8u: goto label_1415d8;
            case 0x1415DCu: goto label_1415dc;
            case 0x1415E0u: goto label_1415e0;
            case 0x1415E4u: goto label_1415e4;
            case 0x1415E8u: goto label_1415e8;
            case 0x1415ECu: goto label_1415ec;
            case 0x1415F0u: goto label_1415f0;
            case 0x1415F4u: goto label_1415f4;
            case 0x1415F8u: goto label_1415f8;
            case 0x1415FCu: goto label_1415fc;
            case 0x141600u: goto label_141600;
            case 0x141604u: goto label_141604;
            case 0x141608u: goto label_141608;
            case 0x14160Cu: goto label_14160c;
            case 0x141610u: goto label_141610;
            case 0x141614u: goto label_141614;
            case 0x141618u: goto label_141618;
            case 0x14161Cu: goto label_14161c;
            case 0x141620u: goto label_141620;
            case 0x141624u: goto label_141624;
            case 0x141628u: goto label_141628;
            case 0x14162Cu: goto label_14162c;
            case 0x141630u: goto label_141630;
            case 0x141634u: goto label_141634;
            case 0x141638u: goto label_141638;
            case 0x14163Cu: goto label_14163c;
            case 0x141640u: goto label_141640;
            case 0x141644u: goto label_141644;
            case 0x141648u: goto label_141648;
            case 0x14164Cu: goto label_14164c;
            case 0x141650u: goto label_141650;
            case 0x141654u: goto label_141654;
            case 0x141658u: goto label_141658;
            case 0x14165Cu: goto label_14165c;
            case 0x141660u: goto label_141660;
            case 0x141664u: goto label_141664;
            case 0x141668u: goto label_141668;
            case 0x14166Cu: goto label_14166c;
            case 0x141670u: goto label_141670;
            case 0x141674u: goto label_141674;
            case 0x141678u: goto label_141678;
            case 0x14167Cu: goto label_14167c;
            case 0x141680u: goto label_141680;
            case 0x141684u: goto label_141684;
            case 0x141688u: goto label_141688;
            case 0x14168Cu: goto label_14168c;
            case 0x141690u: goto label_141690;
            case 0x141694u: goto label_141694;
            case 0x141698u: goto label_141698;
            case 0x14169Cu: goto label_14169c;
            case 0x1416A0u: goto label_1416a0;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416A8u: goto label_1416a8;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B0u: goto label_1416b0;
            case 0x1416B4u: goto label_1416b4;
            case 0x1416B8u: goto label_1416b8;
            case 0x1416BCu: goto label_1416bc;
            case 0x1416C0u: goto label_1416c0;
            case 0x1416C4u: goto label_1416c4;
            case 0x1416C8u: goto label_1416c8;
            case 0x1416CCu: goto label_1416cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1415CCu;
label_1415cc:
    // 0x1415cc: 0x0
    ctx->pc = 0x1415ccu;
    // NOP
label_1415d0:
    // 0x1415d0: 0x94820002
    ctx->pc = 0x1415d0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
label_1415d4:
    // 0x1415d4: 0x24420001
    ctx->pc = 0x1415d4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_1415d8:
    // 0x1415d8: 0x3e00008
label_1415dc:
    if (ctx->pc == 0x1415DCu) {
        ctx->pc = 0x1415DCu;
        WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x1415E0u;
        goto label_1415e0;
    }
    ctx->pc = 0x1415D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1415DCu;
        WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141588u: goto label_141588;
            case 0x14158Cu: goto label_14158c;
            case 0x141590u: goto label_141590;
            case 0x141594u: goto label_141594;
            case 0x141598u: goto label_141598;
            case 0x14159Cu: goto label_14159c;
            case 0x1415A0u: goto label_1415a0;
            case 0x1415A4u: goto label_1415a4;
            case 0x1415A8u: goto label_1415a8;
            case 0x1415ACu: goto label_1415ac;
            case 0x1415B0u: goto label_1415b0;
            case 0x1415B4u: goto label_1415b4;
            case 0x1415B8u: goto label_1415b8;
            case 0x1415BCu: goto label_1415bc;
            case 0x1415C0u: goto label_1415c0;
            case 0x1415C4u: goto label_1415c4;
            case 0x1415C8u: goto label_1415c8;
            case 0x1415CCu: goto label_1415cc;
            case 0x1415D0u: goto label_1415d0;
            case 0x1415D4u: goto label_1415d4;
            case 0x1415D8u: goto label_1415d8;
            case 0x1415DCu: goto label_1415dc;
            case 0x1415E0u: goto label_1415e0;
            case 0x1415E4u: goto label_1415e4;
            case 0x1415E8u: goto label_1415e8;
            case 0x1415ECu: goto label_1415ec;
            case 0x1415F0u: goto label_1415f0;
            case 0x1415F4u: goto label_1415f4;
            case 0x1415F8u: goto label_1415f8;
            case 0x1415FCu: goto label_1415fc;
            case 0x141600u: goto label_141600;
            case 0x141604u: goto label_141604;
            case 0x141608u: goto label_141608;
            case 0x14160Cu: goto label_14160c;
            case 0x141610u: goto label_141610;
            case 0x141614u: goto label_141614;
            case 0x141618u: goto label_141618;
            case 0x14161Cu: goto label_14161c;
            case 0x141620u: goto label_141620;
            case 0x141624u: goto label_141624;
            case 0x141628u: goto label_141628;
            case 0x14162Cu: goto label_14162c;
            case 0x141630u: goto label_141630;
            case 0x141634u: goto label_141634;
            case 0x141638u: goto label_141638;
            case 0x14163Cu: goto label_14163c;
            case 0x141640u: goto label_141640;
            case 0x141644u: goto label_141644;
            case 0x141648u: goto label_141648;
            case 0x14164Cu: goto label_14164c;
            case 0x141650u: goto label_141650;
            case 0x141654u: goto label_141654;
            case 0x141658u: goto label_141658;
            case 0x14165Cu: goto label_14165c;
            case 0x141660u: goto label_141660;
            case 0x141664u: goto label_141664;
            case 0x141668u: goto label_141668;
            case 0x14166Cu: goto label_14166c;
            case 0x141670u: goto label_141670;
            case 0x141674u: goto label_141674;
            case 0x141678u: goto label_141678;
            case 0x14167Cu: goto label_14167c;
            case 0x141680u: goto label_141680;
            case 0x141684u: goto label_141684;
            case 0x141688u: goto label_141688;
            case 0x14168Cu: goto label_14168c;
            case 0x141690u: goto label_141690;
            case 0x141694u: goto label_141694;
            case 0x141698u: goto label_141698;
            case 0x14169Cu: goto label_14169c;
            case 0x1416A0u: goto label_1416a0;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416A8u: goto label_1416a8;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B0u: goto label_1416b0;
            case 0x1416B4u: goto label_1416b4;
            case 0x1416B8u: goto label_1416b8;
            case 0x1416BCu: goto label_1416bc;
            case 0x1416C0u: goto label_1416c0;
            case 0x1416C4u: goto label_1416c4;
            case 0x1416C8u: goto label_1416c8;
            case 0x1416CCu: goto label_1416cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1415E0u;
label_1415e0:
    // 0x1415e0: 0x27bdfff0
    ctx->pc = 0x1415e0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
label_1415e4:
    // 0x1415e4: 0x3c020026
    ctx->pc = 0x1415e4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
label_1415e8:
    // 0x1415e8: 0xffb00000
    ctx->pc = 0x1415e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_1415ec:
    // 0x1415ec: 0xffbf0008
    ctx->pc = 0x1415ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
label_1415f0:
    // 0x1415f0: 0x244249e0
    ctx->pc = 0x1415f0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 18912));
label_1415f4:
    // 0x1415f4: 0x8c430000
    ctx->pc = 0x1415f4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1415f8:
    // 0x1415f8: 0x1060000d
label_1415fc:
    if (ctx->pc == 0x1415FCu) {
        ctx->pc = 0x1415FCu;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x141600u;
        goto label_141600;
    }
    ctx->pc = 0x1415F8u;
    {
        const bool branch_taken_0x1415f8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x1415FCu;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1415f8) {
            ctx->pc = 0x141630u;
            goto label_141630;
        }
    }
    ctx->pc = 0x141600u;
label_141600:
    // 0x141600: 0x60f809
label_141604:
    if (ctx->pc == 0x141604u) {
        ctx->pc = 0x141604u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->pc = 0x141608u;
        goto label_141608;
    }
    ctx->pc = 0x141600u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x141608u);
        ctx->pc = 0x141604u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141588u: goto label_141588;
            case 0x14158Cu: goto label_14158c;
            case 0x141590u: goto label_141590;
            case 0x141594u: goto label_141594;
            case 0x141598u: goto label_141598;
            case 0x14159Cu: goto label_14159c;
            case 0x1415A0u: goto label_1415a0;
            case 0x1415A4u: goto label_1415a4;
            case 0x1415A8u: goto label_1415a8;
            case 0x1415ACu: goto label_1415ac;
            case 0x1415B0u: goto label_1415b0;
            case 0x1415B4u: goto label_1415b4;
            case 0x1415B8u: goto label_1415b8;
            case 0x1415BCu: goto label_1415bc;
            case 0x1415C0u: goto label_1415c0;
            case 0x1415C4u: goto label_1415c4;
            case 0x1415C8u: goto label_1415c8;
            case 0x1415CCu: goto label_1415cc;
            case 0x1415D0u: goto label_1415d0;
            case 0x1415D4u: goto label_1415d4;
            case 0x1415D8u: goto label_1415d8;
            case 0x1415DCu: goto label_1415dc;
            case 0x1415E0u: goto label_1415e0;
            case 0x1415E4u: goto label_1415e4;
            case 0x1415E8u: goto label_1415e8;
            case 0x1415ECu: goto label_1415ec;
            case 0x1415F0u: goto label_1415f0;
            case 0x1415F4u: goto label_1415f4;
            case 0x1415F8u: goto label_1415f8;
            case 0x1415FCu: goto label_1415fc;
            case 0x141600u: goto label_141600;
            case 0x141604u: goto label_141604;
            case 0x141608u: goto label_141608;
            case 0x14160Cu: goto label_14160c;
            case 0x141610u: goto label_141610;
            case 0x141614u: goto label_141614;
            case 0x141618u: goto label_141618;
            case 0x14161Cu: goto label_14161c;
            case 0x141620u: goto label_141620;
            case 0x141624u: goto label_141624;
            case 0x141628u: goto label_141628;
            case 0x14162Cu: goto label_14162c;
            case 0x141630u: goto label_141630;
            case 0x141634u: goto label_141634;
            case 0x141638u: goto label_141638;
            case 0x14163Cu: goto label_14163c;
            case 0x141640u: goto label_141640;
            case 0x141644u: goto label_141644;
            case 0x141648u: goto label_141648;
            case 0x14164Cu: goto label_14164c;
            case 0x141650u: goto label_141650;
            case 0x141654u: goto label_141654;
            case 0x141658u: goto label_141658;
            case 0x14165Cu: goto label_14165c;
            case 0x141660u: goto label_141660;
            case 0x141664u: goto label_141664;
            case 0x141668u: goto label_141668;
            case 0x14166Cu: goto label_14166c;
            case 0x141670u: goto label_141670;
            case 0x141674u: goto label_141674;
            case 0x141678u: goto label_141678;
            case 0x14167Cu: goto label_14167c;
            case 0x141680u: goto label_141680;
            case 0x141684u: goto label_141684;
            case 0x141688u: goto label_141688;
            case 0x14168Cu: goto label_14168c;
            case 0x141690u: goto label_141690;
            case 0x141694u: goto label_141694;
            case 0x141698u: goto label_141698;
            case 0x14169Cu: goto label_14169c;
            case 0x1416A0u: goto label_1416a0;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416A8u: goto label_1416a8;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B0u: goto label_1416b0;
            case 0x1416B4u: goto label_1416b4;
            case 0x1416B8u: goto label_1416b8;
            case 0x1416BCu: goto label_1416bc;
            case 0x1416C0u: goto label_1416c0;
            case 0x1416C4u: goto label_1416c4;
            case 0x1416C8u: goto label_1416c8;
            case 0x1416CCu: goto label_1416cc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141608u; }
            if (ctx->pc != 0x141608u) { return; }
        }
    }
    ctx->pc = 0x141608u;
label_141608:
    // 0x141608: 0x3c020023
    ctx->pc = 0x141608u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
label_14160c:
    // 0x14160c: 0x3c030023
    ctx->pc = 0x14160cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
label_141610:
    // 0x141610: 0x2444a5f4
    ctx->pc = 0x141610u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294944244));
label_141614:
    // 0x141614: 0x2463a5f0
    ctx->pc = 0x141614u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294944240));
label_141618:
    // 0x141618: 0x8c620000
    ctx->pc = 0x141618u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_14161c:
    // 0x14161c: 0x50400001
label_141620:
    if (ctx->pc == 0x141620u) {
        ctx->pc = 0x141620u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
        ctx->pc = 0x141624u;
        goto label_141624;
    }
    ctx->pc = 0x14161Cu;
    {
        const bool branch_taken_0x14161c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x14161c) {
            ctx->pc = 0x141620u;
            WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
            ctx->pc = 0x141624u;
            goto label_141624;
        }
    }
    ctx->pc = 0x141624u;
label_141624:
    // 0x141624: 0x8c620000
    ctx->pc = 0x141624u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_141628:
    // 0x141628: 0x24420001
    ctx->pc = 0x141628u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_14162c:
    // 0x14162c: 0xac620000
    ctx->pc = 0x14162cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_141630:
    // 0x141630: 0xdfb00000
    ctx->pc = 0x141630u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_141634:
    // 0x141634: 0xdfbf0008
    ctx->pc = 0x141634u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_141638:
    // 0x141638: 0x3e00008
label_14163c:
    if (ctx->pc == 0x14163Cu) {
        ctx->pc = 0x14163Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x141640u;
        goto label_141640;
    }
    ctx->pc = 0x141638u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14163Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141588u: goto label_141588;
            case 0x14158Cu: goto label_14158c;
            case 0x141590u: goto label_141590;
            case 0x141594u: goto label_141594;
            case 0x141598u: goto label_141598;
            case 0x14159Cu: goto label_14159c;
            case 0x1415A0u: goto label_1415a0;
            case 0x1415A4u: goto label_1415a4;
            case 0x1415A8u: goto label_1415a8;
            case 0x1415ACu: goto label_1415ac;
            case 0x1415B0u: goto label_1415b0;
            case 0x1415B4u: goto label_1415b4;
            case 0x1415B8u: goto label_1415b8;
            case 0x1415BCu: goto label_1415bc;
            case 0x1415C0u: goto label_1415c0;
            case 0x1415C4u: goto label_1415c4;
            case 0x1415C8u: goto label_1415c8;
            case 0x1415CCu: goto label_1415cc;
            case 0x1415D0u: goto label_1415d0;
            case 0x1415D4u: goto label_1415d4;
            case 0x1415D8u: goto label_1415d8;
            case 0x1415DCu: goto label_1415dc;
            case 0x1415E0u: goto label_1415e0;
            case 0x1415E4u: goto label_1415e4;
            case 0x1415E8u: goto label_1415e8;
            case 0x1415ECu: goto label_1415ec;
            case 0x1415F0u: goto label_1415f0;
            case 0x1415F4u: goto label_1415f4;
            case 0x1415F8u: goto label_1415f8;
            case 0x1415FCu: goto label_1415fc;
            case 0x141600u: goto label_141600;
            case 0x141604u: goto label_141604;
            case 0x141608u: goto label_141608;
            case 0x14160Cu: goto label_14160c;
            case 0x141610u: goto label_141610;
            case 0x141614u: goto label_141614;
            case 0x141618u: goto label_141618;
            case 0x14161Cu: goto label_14161c;
            case 0x141620u: goto label_141620;
            case 0x141624u: goto label_141624;
            case 0x141628u: goto label_141628;
            case 0x14162Cu: goto label_14162c;
            case 0x141630u: goto label_141630;
            case 0x141634u: goto label_141634;
            case 0x141638u: goto label_141638;
            case 0x14163Cu: goto label_14163c;
            case 0x141640u: goto label_141640;
            case 0x141644u: goto label_141644;
            case 0x141648u: goto label_141648;
            case 0x14164Cu: goto label_14164c;
            case 0x141650u: goto label_141650;
            case 0x141654u: goto label_141654;
            case 0x141658u: goto label_141658;
            case 0x14165Cu: goto label_14165c;
            case 0x141660u: goto label_141660;
            case 0x141664u: goto label_141664;
            case 0x141668u: goto label_141668;
            case 0x14166Cu: goto label_14166c;
            case 0x141670u: goto label_141670;
            case 0x141674u: goto label_141674;
            case 0x141678u: goto label_141678;
            case 0x14167Cu: goto label_14167c;
            case 0x141680u: goto label_141680;
            case 0x141684u: goto label_141684;
            case 0x141688u: goto label_141688;
            case 0x14168Cu: goto label_14168c;
            case 0x141690u: goto label_141690;
            case 0x141694u: goto label_141694;
            case 0x141698u: goto label_141698;
            case 0x14169Cu: goto label_14169c;
            case 0x1416A0u: goto label_1416a0;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416A8u: goto label_1416a8;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B0u: goto label_1416b0;
            case 0x1416B4u: goto label_1416b4;
            case 0x1416B8u: goto label_1416b8;
            case 0x1416BCu: goto label_1416bc;
            case 0x1416C0u: goto label_1416c0;
            case 0x1416C4u: goto label_1416c4;
            case 0x1416C8u: goto label_1416c8;
            case 0x1416CCu: goto label_1416cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141640u;
label_141640:
    // 0x141640: 0x27bdffe0
    ctx->pc = 0x141640u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_141644:
    // 0x141644: 0x80302d
    ctx->pc = 0x141644u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_141648:
    // 0x141648: 0xffb10008
    ctx->pc = 0x141648u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_14164c:
    // 0x14164c: 0x3c110026
    ctx->pc = 0x14164cu;
    SET_GPR_U32(ctx, 17, ((uint32_t)38 << 16));
label_141650:
    // 0x141650: 0x8e2249e8
    ctx->pc = 0x141650u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 18920)));
label_141654:
    // 0x141654: 0xffb00000
    ctx->pc = 0x141654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_141658:
    // 0x141658: 0x10400017
label_14165c:
    if (ctx->pc == 0x14165Cu) {
        ctx->pc = 0x14165Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->pc = 0x141660u;
        goto label_141660;
    }
    ctx->pc = 0x141658u;
    {
        const bool branch_taken_0x141658 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x14165Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        if (branch_taken_0x141658) {
            ctx->pc = 0x1416B8u;
            goto label_1416b8;
        }
    }
    ctx->pc = 0x141660u;
label_141660:
    // 0x141660: 0x3c020023
    ctx->pc = 0x141660u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
label_141664:
    // 0x141664: 0x2442a5f0
    ctx->pc = 0x141664u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294944240));
label_141668:
    // 0x141668: 0x8c430000
    ctx->pc = 0x141668u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_14166c:
    // 0x14166c: 0x2463ffff
    ctx->pc = 0x14166cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
label_141670:
    // 0x141670: 0xac430000
    ctx->pc = 0x141670u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_141674:
    // 0x141674: 0x8c440000
    ctx->pc = 0x141674u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_141678:
    // 0x141678: 0x1480000c
label_14167c:
    if (ctx->pc == 0x14167Cu) {
        ctx->pc = 0x14167Cu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 17), 18920));
        ctx->pc = 0x141680u;
        goto label_141680;
    }
    ctx->pc = 0x141678u;
    {
        const bool branch_taken_0x141678 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x14167Cu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 17), 18920));
        if (branch_taken_0x141678) {
            ctx->pc = 0x1416ACu;
            goto label_1416ac;
        }
    }
    ctx->pc = 0x141680u;
label_141680:
    // 0x141680: 0x3c020023
    ctx->pc = 0x141680u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
label_141684:
    // 0x141684: 0x2450a5f4
    ctx->pc = 0x141684u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294944244));
label_141688:
    // 0x141688: 0x8e030000
    ctx->pc = 0x141688u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_14168c:
    // 0x14168c: 0x10660005
label_141690:
    if (ctx->pc == 0x141690u) {
        ctx->pc = 0x141694u;
        goto label_141694;
    }
    ctx->pc = 0x14168Cu;
    {
        const bool branch_taken_0x14168c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 6));
        if (branch_taken_0x14168c) {
            ctx->pc = 0x1416A4u;
            goto label_1416a4;
        }
    }
    ctx->pc = 0x141694u;
label_141694:
    // 0x141694: 0x3c040024
    ctx->pc = 0x141694u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_141698:
    // 0x141698: 0x8e050000
    ctx->pc = 0x141698u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_14169c:
    // 0x14169c: 0xc050600
label_1416a0:
    if (ctx->pc == 0x1416A0u) {
        ctx->pc = 0x1416A0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294957992));
        ctx->pc = 0x1416A4u;
        goto label_1416a4;
    }
    ctx->pc = 0x14169Cu;
    SET_GPR_U32(ctx, 31, 0x1416A4u);
    ctx->pc = 0x1416A0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294957992));
    ctx->pc = 0x141800u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141800_0x141800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1416A4u; }
    }
    if (ctx->pc != 0x1416A4u) { return; }
    ctx->pc = 0x1416A4u;
label_1416a4:
    // 0x1416a4: 0xae000000
    ctx->pc = 0x1416a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_1416a8:
    // 0x1416a8: 0x262349e8
    ctx->pc = 0x1416a8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 17), 18920));
label_1416ac:
    // 0x1416ac: 0x8c620000
    ctx->pc = 0x1416acu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_1416b0:
    // 0x1416b0: 0x40f809
label_1416b4:
    if (ctx->pc == 0x1416B4u) {
        ctx->pc = 0x1416B4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->pc = 0x1416B8u;
        goto label_1416b8;
    }
    ctx->pc = 0x1416B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1416B8u);
        ctx->pc = 0x1416B4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141588u: goto label_141588;
            case 0x14158Cu: goto label_14158c;
            case 0x141590u: goto label_141590;
            case 0x141594u: goto label_141594;
            case 0x141598u: goto label_141598;
            case 0x14159Cu: goto label_14159c;
            case 0x1415A0u: goto label_1415a0;
            case 0x1415A4u: goto label_1415a4;
            case 0x1415A8u: goto label_1415a8;
            case 0x1415ACu: goto label_1415ac;
            case 0x1415B0u: goto label_1415b0;
            case 0x1415B4u: goto label_1415b4;
            case 0x1415B8u: goto label_1415b8;
            case 0x1415BCu: goto label_1415bc;
            case 0x1415C0u: goto label_1415c0;
            case 0x1415C4u: goto label_1415c4;
            case 0x1415C8u: goto label_1415c8;
            case 0x1415CCu: goto label_1415cc;
            case 0x1415D0u: goto label_1415d0;
            case 0x1415D4u: goto label_1415d4;
            case 0x1415D8u: goto label_1415d8;
            case 0x1415DCu: goto label_1415dc;
            case 0x1415E0u: goto label_1415e0;
            case 0x1415E4u: goto label_1415e4;
            case 0x1415E8u: goto label_1415e8;
            case 0x1415ECu: goto label_1415ec;
            case 0x1415F0u: goto label_1415f0;
            case 0x1415F4u: goto label_1415f4;
            case 0x1415F8u: goto label_1415f8;
            case 0x1415FCu: goto label_1415fc;
            case 0x141600u: goto label_141600;
            case 0x141604u: goto label_141604;
            case 0x141608u: goto label_141608;
            case 0x14160Cu: goto label_14160c;
            case 0x141610u: goto label_141610;
            case 0x141614u: goto label_141614;
            case 0x141618u: goto label_141618;
            case 0x14161Cu: goto label_14161c;
            case 0x141620u: goto label_141620;
            case 0x141624u: goto label_141624;
            case 0x141628u: goto label_141628;
            case 0x14162Cu: goto label_14162c;
            case 0x141630u: goto label_141630;
            case 0x141634u: goto label_141634;
            case 0x141638u: goto label_141638;
            case 0x14163Cu: goto label_14163c;
            case 0x141640u: goto label_141640;
            case 0x141644u: goto label_141644;
            case 0x141648u: goto label_141648;
            case 0x14164Cu: goto label_14164c;
            case 0x141650u: goto label_141650;
            case 0x141654u: goto label_141654;
            case 0x141658u: goto label_141658;
            case 0x14165Cu: goto label_14165c;
            case 0x141660u: goto label_141660;
            case 0x141664u: goto label_141664;
            case 0x141668u: goto label_141668;
            case 0x14166Cu: goto label_14166c;
            case 0x141670u: goto label_141670;
            case 0x141674u: goto label_141674;
            case 0x141678u: goto label_141678;
            case 0x14167Cu: goto label_14167c;
            case 0x141680u: goto label_141680;
            case 0x141684u: goto label_141684;
            case 0x141688u: goto label_141688;
            case 0x14168Cu: goto label_14168c;
            case 0x141690u: goto label_141690;
            case 0x141694u: goto label_141694;
            case 0x141698u: goto label_141698;
            case 0x14169Cu: goto label_14169c;
            case 0x1416A0u: goto label_1416a0;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416A8u: goto label_1416a8;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B0u: goto label_1416b0;
            case 0x1416B4u: goto label_1416b4;
            case 0x1416B8u: goto label_1416b8;
            case 0x1416BCu: goto label_1416bc;
            case 0x1416C0u: goto label_1416c0;
            case 0x1416C4u: goto label_1416c4;
            case 0x1416C8u: goto label_1416c8;
            case 0x1416CCu: goto label_1416cc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1416B8u; }
            if (ctx->pc != 0x1416B8u) { return; }
        }
    }
    ctx->pc = 0x1416B8u;
label_1416b8:
    // 0x1416b8: 0xdfb00000
    ctx->pc = 0x1416b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1416bc:
    // 0x1416bc: 0xdfb10008
    ctx->pc = 0x1416bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_1416c0:
    // 0x1416c0: 0xdfbf0010
    ctx->pc = 0x1416c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1416c4:
    // 0x1416c4: 0x3e00008
label_1416c8:
    if (ctx->pc == 0x1416C8u) {
        ctx->pc = 0x1416C8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x1416CCu;
        goto label_1416cc;
    }
    ctx->pc = 0x1416C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1416C8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141588u: goto label_141588;
            case 0x14158Cu: goto label_14158c;
            case 0x141590u: goto label_141590;
            case 0x141594u: goto label_141594;
            case 0x141598u: goto label_141598;
            case 0x14159Cu: goto label_14159c;
            case 0x1415A0u: goto label_1415a0;
            case 0x1415A4u: goto label_1415a4;
            case 0x1415A8u: goto label_1415a8;
            case 0x1415ACu: goto label_1415ac;
            case 0x1415B0u: goto label_1415b0;
            case 0x1415B4u: goto label_1415b4;
            case 0x1415B8u: goto label_1415b8;
            case 0x1415BCu: goto label_1415bc;
            case 0x1415C0u: goto label_1415c0;
            case 0x1415C4u: goto label_1415c4;
            case 0x1415C8u: goto label_1415c8;
            case 0x1415CCu: goto label_1415cc;
            case 0x1415D0u: goto label_1415d0;
            case 0x1415D4u: goto label_1415d4;
            case 0x1415D8u: goto label_1415d8;
            case 0x1415DCu: goto label_1415dc;
            case 0x1415E0u: goto label_1415e0;
            case 0x1415E4u: goto label_1415e4;
            case 0x1415E8u: goto label_1415e8;
            case 0x1415ECu: goto label_1415ec;
            case 0x1415F0u: goto label_1415f0;
            case 0x1415F4u: goto label_1415f4;
            case 0x1415F8u: goto label_1415f8;
            case 0x1415FCu: goto label_1415fc;
            case 0x141600u: goto label_141600;
            case 0x141604u: goto label_141604;
            case 0x141608u: goto label_141608;
            case 0x14160Cu: goto label_14160c;
            case 0x141610u: goto label_141610;
            case 0x141614u: goto label_141614;
            case 0x141618u: goto label_141618;
            case 0x14161Cu: goto label_14161c;
            case 0x141620u: goto label_141620;
            case 0x141624u: goto label_141624;
            case 0x141628u: goto label_141628;
            case 0x14162Cu: goto label_14162c;
            case 0x141630u: goto label_141630;
            case 0x141634u: goto label_141634;
            case 0x141638u: goto label_141638;
            case 0x14163Cu: goto label_14163c;
            case 0x141640u: goto label_141640;
            case 0x141644u: goto label_141644;
            case 0x141648u: goto label_141648;
            case 0x14164Cu: goto label_14164c;
            case 0x141650u: goto label_141650;
            case 0x141654u: goto label_141654;
            case 0x141658u: goto label_141658;
            case 0x14165Cu: goto label_14165c;
            case 0x141660u: goto label_141660;
            case 0x141664u: goto label_141664;
            case 0x141668u: goto label_141668;
            case 0x14166Cu: goto label_14166c;
            case 0x141670u: goto label_141670;
            case 0x141674u: goto label_141674;
            case 0x141678u: goto label_141678;
            case 0x14167Cu: goto label_14167c;
            case 0x141680u: goto label_141680;
            case 0x141684u: goto label_141684;
            case 0x141688u: goto label_141688;
            case 0x14168Cu: goto label_14168c;
            case 0x141690u: goto label_141690;
            case 0x141694u: goto label_141694;
            case 0x141698u: goto label_141698;
            case 0x14169Cu: goto label_14169c;
            case 0x1416A0u: goto label_1416a0;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416A8u: goto label_1416a8;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B0u: goto label_1416b0;
            case 0x1416B4u: goto label_1416b4;
            case 0x1416B8u: goto label_1416b8;
            case 0x1416BCu: goto label_1416bc;
            case 0x1416C0u: goto label_1416c0;
            case 0x1416C4u: goto label_1416c4;
            case 0x1416C8u: goto label_1416c8;
            case 0x1416CCu: goto label_1416cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1416CCu;
label_1416cc:
    // 0x1416cc: 0x0
    ctx->pc = 0x1416ccu;
    // NOP
}
