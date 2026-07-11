#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001A95A0
// Address: 0x1a95a0 - 0x1a9750
void sub_001A95A0_0x1a95a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1a95a0u;

label_1a95a0:
    // 0x1a95a0: 0x27bdffa0
    ctx->pc = 0x1a95a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
label_1a95a4:
    // 0x1a95a4: 0xffbf0030
    ctx->pc = 0x1a95a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
label_1a95a8:
    // 0x1a95a8: 0x7fb20020
    ctx->pc = 0x1a95a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
label_1a95ac:
    // 0x1a95ac: 0x7fb10010
    ctx->pc = 0x1a95acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
label_1a95b0:
    // 0x1a95b0: 0x80882d
    ctx->pc = 0x1a95b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1a95b4:
    // 0x1a95b4: 0x2e21000a
    ctx->pc = 0x1a95b4u;
    SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 17), 10));
label_1a95b8:
    // 0x1a95b8: 0x10200036
label_1a95bc:
    if (ctx->pc == 0x1A95BCu) {
        ctx->pc = 0x1A95BCu;
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->pc = 0x1A95C0u;
        goto label_1a95c0;
    }
    ctx->pc = 0x1A95B8u;
    {
        const bool branch_taken_0x1a95b8 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A95BCu;
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        if (branch_taken_0x1a95b8) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A95C0u;
label_1a95c0:
    // 0x1a95c0: 0x3c040024
    ctx->pc = 0x1a95c0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_1a95c4:
    // 0x1a95c4: 0x111880
    ctx->pc = 0x1a95c4u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 17), 2));
label_1a95c8:
    // 0x1a95c8: 0x24842650
    ctx->pc = 0x1a95c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 9808));
label_1a95cc:
    // 0x1a95cc: 0x641821
    ctx->pc = 0x1a95ccu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_1a95d0:
    // 0x1a95d0: 0x8c630000
    ctx->pc = 0x1a95d0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_1a95d4:
    // 0x1a95d4: 0x600008
label_1a95d8:
    if (ctx->pc == 0x1A95D8u) {
        ctx->pc = 0x1A95DCu;
        goto label_1a95dc;
    }
    ctx->pc = 0x1A95D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A95A0u: goto label_1a95a0;
            case 0x1A95A4u: goto label_1a95a4;
            case 0x1A95A8u: goto label_1a95a8;
            case 0x1A95ACu: goto label_1a95ac;
            case 0x1A95B0u: goto label_1a95b0;
            case 0x1A95B4u: goto label_1a95b4;
            case 0x1A95B8u: goto label_1a95b8;
            case 0x1A95BCu: goto label_1a95bc;
            case 0x1A95C0u: goto label_1a95c0;
            case 0x1A95C4u: goto label_1a95c4;
            case 0x1A95C8u: goto label_1a95c8;
            case 0x1A95CCu: goto label_1a95cc;
            case 0x1A95D0u: goto label_1a95d0;
            case 0x1A95D4u: goto label_1a95d4;
            case 0x1A95D8u: goto label_1a95d8;
            case 0x1A95DCu: goto label_1a95dc;
            case 0x1A95E0u: goto label_1a95e0;
            case 0x1A95E4u: goto label_1a95e4;
            case 0x1A95E8u: goto label_1a95e8;
            case 0x1A95ECu: goto label_1a95ec;
            case 0x1A95F0u: goto label_1a95f0;
            case 0x1A95F4u: goto label_1a95f4;
            case 0x1A95F8u: goto label_1a95f8;
            case 0x1A95FCu: goto label_1a95fc;
            case 0x1A9600u: goto label_1a9600;
            case 0x1A9604u: goto label_1a9604;
            case 0x1A9608u: goto label_1a9608;
            case 0x1A960Cu: goto label_1a960c;
            case 0x1A9610u: goto label_1a9610;
            case 0x1A9614u: goto label_1a9614;
            case 0x1A9618u: goto label_1a9618;
            case 0x1A961Cu: goto label_1a961c;
            case 0x1A9620u: goto label_1a9620;
            case 0x1A9624u: goto label_1a9624;
            case 0x1A9628u: goto label_1a9628;
            case 0x1A962Cu: goto label_1a962c;
            case 0x1A9630u: goto label_1a9630;
            case 0x1A9634u: goto label_1a9634;
            case 0x1A9638u: goto label_1a9638;
            case 0x1A963Cu: goto label_1a963c;
            case 0x1A9640u: goto label_1a9640;
            case 0x1A9644u: goto label_1a9644;
            case 0x1A9648u: goto label_1a9648;
            case 0x1A964Cu: goto label_1a964c;
            case 0x1A9650u: goto label_1a9650;
            case 0x1A9654u: goto label_1a9654;
            case 0x1A9658u: goto label_1a9658;
            case 0x1A965Cu: goto label_1a965c;
            case 0x1A9660u: goto label_1a9660;
            case 0x1A9664u: goto label_1a9664;
            case 0x1A9668u: goto label_1a9668;
            case 0x1A966Cu: goto label_1a966c;
            case 0x1A9670u: goto label_1a9670;
            case 0x1A9674u: goto label_1a9674;
            case 0x1A9678u: goto label_1a9678;
            case 0x1A967Cu: goto label_1a967c;
            case 0x1A9680u: goto label_1a9680;
            case 0x1A9684u: goto label_1a9684;
            case 0x1A9688u: goto label_1a9688;
            case 0x1A968Cu: goto label_1a968c;
            case 0x1A9690u: goto label_1a9690;
            case 0x1A9694u: goto label_1a9694;
            case 0x1A9698u: goto label_1a9698;
            case 0x1A969Cu: goto label_1a969c;
            case 0x1A96A0u: goto label_1a96a0;
            case 0x1A96A4u: goto label_1a96a4;
            case 0x1A96A8u: goto label_1a96a8;
            case 0x1A96ACu: goto label_1a96ac;
            case 0x1A96B0u: goto label_1a96b0;
            case 0x1A96B4u: goto label_1a96b4;
            case 0x1A96B8u: goto label_1a96b8;
            case 0x1A96BCu: goto label_1a96bc;
            case 0x1A96C0u: goto label_1a96c0;
            case 0x1A96C4u: goto label_1a96c4;
            case 0x1A96C8u: goto label_1a96c8;
            case 0x1A96CCu: goto label_1a96cc;
            case 0x1A96D0u: goto label_1a96d0;
            case 0x1A96D4u: goto label_1a96d4;
            case 0x1A96D8u: goto label_1a96d8;
            case 0x1A96DCu: goto label_1a96dc;
            case 0x1A96E0u: goto label_1a96e0;
            case 0x1A96E4u: goto label_1a96e4;
            case 0x1A96E8u: goto label_1a96e8;
            case 0x1A96ECu: goto label_1a96ec;
            case 0x1A96F0u: goto label_1a96f0;
            case 0x1A96F4u: goto label_1a96f4;
            case 0x1A96F8u: goto label_1a96f8;
            case 0x1A96FCu: goto label_1a96fc;
            case 0x1A9700u: goto label_1a9700;
            case 0x1A9704u: goto label_1a9704;
            case 0x1A9708u: goto label_1a9708;
            case 0x1A970Cu: goto label_1a970c;
            case 0x1A9710u: goto label_1a9710;
            case 0x1A9714u: goto label_1a9714;
            case 0x1A9718u: goto label_1a9718;
            case 0x1A971Cu: goto label_1a971c;
            case 0x1A9720u: goto label_1a9720;
            case 0x1A9724u: goto label_1a9724;
            case 0x1A9728u: goto label_1a9728;
            case 0x1A972Cu: goto label_1a972c;
            case 0x1A9730u: goto label_1a9730;
            case 0x1A9734u: goto label_1a9734;
            case 0x1A9738u: goto label_1a9738;
            case 0x1A973Cu: goto label_1a973c;
            case 0x1A9740u: goto label_1a9740;
            case 0x1A9744u: goto label_1a9744;
            case 0x1A9748u: goto label_1a9748;
            case 0x1A974Cu: goto label_1a974c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A95DCu;
label_1a95dc:
    // 0x1a95dc: 0x2402ffff
    ctx->pc = 0x1a95dcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1a95e0:
    // 0x1a95e0: 0x3c010023
    ctx->pc = 0x1a95e0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1a95e4:
    // 0x1a95e4: 0xa0222210
    ctx->pc = 0x1a95e4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 8720), (uint8_t)GPR_U32(ctx, 2));
label_1a95e8:
    // 0x1a95e8: 0x3c010023
    ctx->pc = 0x1a95e8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1a95ec:
    // 0x1a95ec: 0xa0222218
    ctx->pc = 0x1a95ecu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 8728), (uint8_t)GPR_U32(ctx, 2));
label_1a95f0:
    // 0x1a95f0: 0x3c010023
    ctx->pc = 0x1a95f0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1a95f4:
    // 0x1a95f4: 0x10000027
label_1a95f8:
    if (ctx->pc == 0x1A95F8u) {
        ctx->pc = 0x1A95F8u;
        WRITE8(ADD32(GPR_U32(ctx, 1), 8736), (uint8_t)GPR_U32(ctx, 2));
        ctx->pc = 0x1A95FCu;
        goto label_1a95fc;
    }
    ctx->pc = 0x1A95F4u;
    {
        const bool branch_taken_0x1a95f4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A95F8u;
        WRITE8(ADD32(GPR_U32(ctx, 1), 8736), (uint8_t)GPR_U32(ctx, 2));
        if (branch_taken_0x1a95f4) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A95FCu;
label_1a95fc:
    // 0x1a95fc: 0x3c010023
    ctx->pc = 0x1a95fcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1a9600:
    // 0x1a9600: 0x3c100023
    ctx->pc = 0x1a9600u;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
label_1a9604:
    // 0x1a9604: 0x80232210
    ctx->pc = 0x1a9604u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 8720)));
label_1a9608:
    // 0x1a9608: 0x1223004b
label_1a960c:
    if (ctx->pc == 0x1A960Cu) {
        ctx->pc = 0x1A960Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 8720));
        ctx->pc = 0x1A9610u;
        goto label_1a9610;
    }
    ctx->pc = 0x1A9608u;
    {
        const bool branch_taken_0x1a9608 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 3));
        ctx->pc = 0x1A960Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 8720));
        if (branch_taken_0x1a9608) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9610u;
label_1a9610:
    // 0x1a9610: 0x24020002
    ctx->pc = 0x1a9610u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
label_1a9614:
    // 0x1a9614: 0x1622001f
label_1a9618:
    if (ctx->pc == 0x1A9618u) {
        ctx->pc = 0x1A961Cu;
        goto label_1a961c;
    }
    ctx->pc = 0x1A9614u;
    {
        const bool branch_taken_0x1a9614 = (GPR_U32(ctx, 17) != GPR_U32(ctx, 2));
        if (branch_taken_0x1a9614) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A961Cu;
label_1a961c:
    // 0x1a961c: 0x2402ffff
    ctx->pc = 0x1a961cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1a9620:
    // 0x1a9620: 0x3c010023
    ctx->pc = 0x1a9620u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1a9624:
    // 0x1a9624: 0x1000001b
label_1a9628:
    if (ctx->pc == 0x1A9628u) {
        ctx->pc = 0x1A9628u;
        WRITE8(ADD32(GPR_U32(ctx, 1), 8736), (uint8_t)GPR_U32(ctx, 2));
        ctx->pc = 0x1A962Cu;
        goto label_1a962c;
    }
    ctx->pc = 0x1A9624u;
    {
        const bool branch_taken_0x1a9624 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A9628u;
        WRITE8(ADD32(GPR_U32(ctx, 1), 8736), (uint8_t)GPR_U32(ctx, 2));
        if (branch_taken_0x1a9624) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A962Cu;
label_1a962c:
    // 0x1a962c: 0x3c010023
    ctx->pc = 0x1a962cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1a9630:
    // 0x1a9630: 0x24030003
    ctx->pc = 0x1a9630u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
label_1a9634:
    // 0x1a9634: 0x80242210
    ctx->pc = 0x1a9634u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 8720)));
label_1a9638:
    // 0x1a9638: 0x10830007
label_1a963c:
    if (ctx->pc == 0x1A963Cu) {
        ctx->pc = 0x1A9640u;
        goto label_1a9640;
    }
    ctx->pc = 0x1A9638u;
    {
        const bool branch_taken_0x1a9638 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x1a9638) {
            ctx->pc = 0x1A9658u;
            goto label_1a9658;
        }
    }
    ctx->pc = 0x1A9640u;
label_1a9640:
    // 0x1a9640: 0x24030001
    ctx->pc = 0x1a9640u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
label_1a9644:
    // 0x1a9644: 0x10830004
label_1a9648:
    if (ctx->pc == 0x1A9648u) {
        ctx->pc = 0x1A964Cu;
        goto label_1a964c;
    }
    ctx->pc = 0x1A9644u;
    {
        const bool branch_taken_0x1a9644 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x1a9644) {
            ctx->pc = 0x1A9658u;
            goto label_1a9658;
        }
    }
    ctx->pc = 0x1A964Cu;
label_1a964c:
    // 0x1a964c: 0x2403ffff
    ctx->pc = 0x1a964cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1a9650:
    // 0x1a9650: 0x14830039
label_1a9654:
    if (ctx->pc == 0x1A9654u) {
        ctx->pc = 0x1A9658u;
        goto label_1a9658;
    }
    ctx->pc = 0x1A9650u;
    {
        const bool branch_taken_0x1a9650 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 3));
        if (branch_taken_0x1a9650) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9658u;
label_1a9658:
    // 0x1a9658: 0x3c100023
    ctx->pc = 0x1a9658u;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
label_1a965c:
    // 0x1a965c: 0x1000000d
label_1a9660:
    if (ctx->pc == 0x1A9660u) {
        ctx->pc = 0x1A9660u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 8736));
        ctx->pc = 0x1A9664u;
        goto label_1a9664;
    }
    ctx->pc = 0x1A965Cu;
    {
        const bool branch_taken_0x1a965c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A9660u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 8736));
        if (branch_taken_0x1a965c) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A9664u;
label_1a9664:
    // 0x1a9664: 0x3c010023
    ctx->pc = 0x1a9664u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1a9668:
    // 0x1a9668: 0x24030003
    ctx->pc = 0x1a9668u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
label_1a966c:
    // 0x1a966c: 0x80242210
    ctx->pc = 0x1a966cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 8720)));
label_1a9670:
    // 0x1a9670: 0x14830031
label_1a9674:
    if (ctx->pc == 0x1A9674u) {
        ctx->pc = 0x1A9674u;
        SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
        ctx->pc = 0x1A9678u;
        goto label_1a9678;
    }
    ctx->pc = 0x1A9670u;
    {
        const bool branch_taken_0x1a9670 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 3));
        ctx->pc = 0x1A9674u;
        SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
        if (branch_taken_0x1a9670) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9678u;
label_1a9678:
    // 0x1a9678: 0x10000006
label_1a967c:
    if (ctx->pc == 0x1A967Cu) {
        ctx->pc = 0x1A967Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 8736));
        ctx->pc = 0x1A9680u;
        goto label_1a9680;
    }
    ctx->pc = 0x1A9678u;
    {
        const bool branch_taken_0x1a9678 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A967Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 8736));
        if (branch_taken_0x1a9678) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A9680u;
label_1a9680:
    // 0x1a9680: 0x3c010023
    ctx->pc = 0x1a9680u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_1a9684:
    // 0x1a9684: 0x3c100023
    ctx->pc = 0x1a9684u;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
label_1a9688:
    // 0x1a9688: 0x80232218
    ctx->pc = 0x1a9688u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 8728)));
label_1a968c:
    // 0x1a968c: 0x1223002a
label_1a9690:
    if (ctx->pc == 0x1A9690u) {
        ctx->pc = 0x1A9690u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 8728));
        ctx->pc = 0x1A9694u;
        goto label_1a9694;
    }
    ctx->pc = 0x1A968Cu;
    {
        const bool branch_taken_0x1a968c = (GPR_U32(ctx, 17) == GPR_U32(ctx, 3));
        ctx->pc = 0x1A9690u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 8728));
        if (branch_taken_0x1a968c) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9694u;
label_1a9694:
    // 0x1a9694: 0x3c020023
    ctx->pc = 0x1a9694u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
label_1a9698:
    // 0x1a9698: 0x3c050024
    ctx->pc = 0x1a9698u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
label_1a969c:
    // 0x1a969c: 0x111880
    ctx->pc = 0x1a969cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 17), 2));
label_1a96a0:
    // 0x1a96a0: 0x244211a0
    ctx->pc = 0x1a96a0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4512));
label_1a96a4:
    // 0x1a96a4: 0x431021
    ctx->pc = 0x1a96a4u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1a96a8:
    // 0x1a96a8: 0x27a40040
    ctx->pc = 0x1a96a8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
label_1a96ac:
    // 0x1a96ac: 0x8c520000
    ctx->pc = 0x1a96acu;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1a96b0:
    // 0x1a96b0: 0x24a52638
    ctx->pc = 0x1a96b0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 9784));
label_1a96b4:
    // 0x1a96b4: 0xc042a0c
label_1a96b8:
    if (ctx->pc == 0x1A96B8u) {
        ctx->pc = 0x1A96B8u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1A96BCu;
        goto label_1a96bc;
    }
    ctx->pc = 0x1A96B4u;
    SET_GPR_U32(ctx, 31, 0x1A96BCu);
    ctx->pc = 0x1A96B8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A96BCu; }
    }
    if (ctx->pc != 0x1A96BCu) { return; }
    ctx->pc = 0x1A96BCu;
label_1a96bc:
    // 0x1a96bc: 0x27a40040
    ctx->pc = 0x1a96bcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
label_1a96c0:
    // 0x1a96c0: 0xc06a540
label_1a96c4:
    if (ctx->pc == 0x1A96C4u) {
        ctx->pc = 0x1A96C4u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1A96C8u;
        goto label_1a96c8;
    }
    ctx->pc = 0x1A96C0u;
    SET_GPR_U32(ctx, 31, 0x1A96C8u);
    ctx->pc = 0x1A96C4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1A9500u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9500_0x1a9500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A96C8u; }
    }
    if (ctx->pc != 0x1A96C8u) { return; }
    ctx->pc = 0x1A96C8u;
label_1a96c8:
    // 0x1a96c8: 0x1040001b
label_1a96cc:
    if (ctx->pc == 0x1A96CCu) {
        ctx->pc = 0x1A96D0u;
        goto label_1a96d0;
    }
    ctx->pc = 0x1A96C8u;
    {
        const bool branch_taken_0x1a96c8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1a96c8) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A96D0u;
label_1a96d0:
    // 0x1a96d0: 0x24020004
    ctx->pc = 0x1a96d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
label_1a96d4:
    // 0x1a96d4: 0x1222000e
label_1a96d8:
    if (ctx->pc == 0x1A96D8u) {
        ctx->pc = 0x1A96D8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1A96DCu;
        goto label_1a96dc;
    }
    ctx->pc = 0x1A96D4u;
    {
        const bool branch_taken_0x1a96d4 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 2));
        ctx->pc = 0x1A96D8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1a96d4) {
            ctx->pc = 0x1A9710u;
            goto label_1a9710;
        }
    }
    ctx->pc = 0x1A96DCu;
label_1a96dc:
    // 0x1a96dc: 0x24020005
    ctx->pc = 0x1a96dcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 5));
label_1a96e0:
    // 0x1a96e0: 0x1222000a
label_1a96e4:
    if (ctx->pc == 0x1A96E4u) {
        ctx->pc = 0x1A96E4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 6));
        ctx->pc = 0x1A96E8u;
        goto label_1a96e8;
    }
    ctx->pc = 0x1A96E0u;
    {
        const bool branch_taken_0x1a96e0 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 2));
        ctx->pc = 0x1A96E4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 6));
        if (branch_taken_0x1a96e0) {
            ctx->pc = 0x1A970Cu;
            goto label_1a970c;
        }
    }
    ctx->pc = 0x1A96E8u;
label_1a96e8:
    // 0x1a96e8: 0x12220008
label_1a96ec:
    if (ctx->pc == 0x1A96ECu) {
        ctx->pc = 0x1A96ECu;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        ctx->pc = 0x1A96F0u;
        goto label_1a96f0;
    }
    ctx->pc = 0x1A96E8u;
    {
        const bool branch_taken_0x1a96e8 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 2));
        ctx->pc = 0x1A96ECu;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1a96e8) {
            ctx->pc = 0x1A970Cu;
            goto label_1a970c;
        }
    }
    ctx->pc = 0x1A96F0u;
label_1a96f0:
    // 0x1a96f0: 0x8c25440c
    ctx->pc = 0x1a96f0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
label_1a96f4:
    // 0x1a96f4: 0xc06bd74
label_1a96f8:
    if (ctx->pc == 0x1A96F8u) {
        ctx->pc = 0x1A96F8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1A96FCu;
        goto label_1a96fc;
    }
    ctx->pc = 0x1A96F4u;
    SET_GPR_U32(ctx, 31, 0x1A96FCu);
    ctx->pc = 0x1A96F8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AF5D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A96FCu; }
    }
    if (ctx->pc != 0x1A96FCu) { return; }
    ctx->pc = 0x1A96FCu;
label_1a96fc:
    // 0x1a96fc: 0xc045228
label_1a9700:
    if (ctx->pc == 0x1A9700u) {
        ctx->pc = 0x1A9700u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1A9704u;
        goto label_1a9704;
    }
    ctx->pc = 0x1A96FCu;
    SET_GPR_U32(ctx, 31, 0x1A9704u);
    ctx->pc = 0x1A9700u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9704u; }
    }
    if (ctx->pc != 0x1A9704u) { return; }
    ctx->pc = 0x1A9704u;
label_1a9704:
    // 0x1a9704: 0x3c010032
    ctx->pc = 0x1a9704u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
label_1a9708:
    // 0x1a9708: 0x8c32440c
    ctx->pc = 0x1a9708u;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
label_1a970c:
    // 0x1a970c: 0x240202d
    ctx->pc = 0x1a970cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1a9710:
    // 0x1a9710: 0xc06a520
label_1a9714:
    if (ctx->pc == 0x1A9714u) {
        ctx->pc = 0x1A9718u;
        goto label_1a9718;
    }
    ctx->pc = 0x1A9710u;
    SET_GPR_U32(ctx, 31, 0x1A9718u);
    ctx->pc = 0x1A9480u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9480_0x1a9480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9718u; }
    }
    if (ctx->pc != 0x1A9718u) { return; }
    ctx->pc = 0x1A9718u;
label_1a9718:
    // 0x1a9718: 0x40902d
    ctx->pc = 0x1a9718u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1a971c:
    // 0x1a971c: 0xc07dc7c
label_1a9720:
    if (ctx->pc == 0x1A9720u) {
        ctx->pc = 0x1A9720u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 17), 1));
        ctx->pc = 0x1A9724u;
        goto label_1a9724;
    }
    ctx->pc = 0x1A971Cu;
    SET_GPR_U32(ctx, 31, 0x1A9724u);
    ctx->pc = 0x1A9720u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 17), 1));
    ctx->pc = 0x1F71F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F71F0_0x1f71f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9724u; }
    }
    if (ctx->pc != 0x1A9724u) { return; }
    ctx->pc = 0x1A9724u;
label_1a9724:
    // 0x1a9724: 0x12200004
label_1a9728:
    if (ctx->pc == 0x1A9728u) {
        ctx->pc = 0x1A9728u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1A972Cu;
        goto label_1a972c;
    }
    ctx->pc = 0x1A9724u;
    {
        const bool branch_taken_0x1a9724 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A9728u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1a9724) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A972Cu;
label_1a972c:
    // 0x1a972c: 0x16430002
label_1a9730:
    if (ctx->pc == 0x1A9730u) {
        ctx->pc = 0x1A9734u;
        goto label_1a9734;
    }
    ctx->pc = 0x1A972Cu;
    {
        const bool branch_taken_0x1a972c = (GPR_U32(ctx, 18) != GPR_U32(ctx, 3));
        if (branch_taken_0x1a972c) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9734u;
label_1a9734:
    // 0x1a9734: 0xa2110000
    ctx->pc = 0x1a9734u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 17));
label_1a9738:
    // 0x1a9738: 0xdfbf0030
    ctx->pc = 0x1a9738u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1a973c:
    // 0x1a973c: 0x7bb20020
    ctx->pc = 0x1a973cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
label_1a9740:
    // 0x1a9740: 0x7bb10010
    ctx->pc = 0x1a9740u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_1a9744:
    // 0x1a9744: 0x7bb00000
    ctx->pc = 0x1a9744u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_1a9748:
    // 0x1a9748: 0x3e00008
label_1a974c:
    if (ctx->pc == 0x1A974Cu) {
        ctx->pc = 0x1A974Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = 0x1A9750u;
        goto label_fallthrough_0x1a9748;
    }
    ctx->pc = 0x1A9748u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A974Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A95A0u: goto label_1a95a0;
            case 0x1A95A4u: goto label_1a95a4;
            case 0x1A95A8u: goto label_1a95a8;
            case 0x1A95ACu: goto label_1a95ac;
            case 0x1A95B0u: goto label_1a95b0;
            case 0x1A95B4u: goto label_1a95b4;
            case 0x1A95B8u: goto label_1a95b8;
            case 0x1A95BCu: goto label_1a95bc;
            case 0x1A95C0u: goto label_1a95c0;
            case 0x1A95C4u: goto label_1a95c4;
            case 0x1A95C8u: goto label_1a95c8;
            case 0x1A95CCu: goto label_1a95cc;
            case 0x1A95D0u: goto label_1a95d0;
            case 0x1A95D4u: goto label_1a95d4;
            case 0x1A95D8u: goto label_1a95d8;
            case 0x1A95DCu: goto label_1a95dc;
            case 0x1A95E0u: goto label_1a95e0;
            case 0x1A95E4u: goto label_1a95e4;
            case 0x1A95E8u: goto label_1a95e8;
            case 0x1A95ECu: goto label_1a95ec;
            case 0x1A95F0u: goto label_1a95f0;
            case 0x1A95F4u: goto label_1a95f4;
            case 0x1A95F8u: goto label_1a95f8;
            case 0x1A95FCu: goto label_1a95fc;
            case 0x1A9600u: goto label_1a9600;
            case 0x1A9604u: goto label_1a9604;
            case 0x1A9608u: goto label_1a9608;
            case 0x1A960Cu: goto label_1a960c;
            case 0x1A9610u: goto label_1a9610;
            case 0x1A9614u: goto label_1a9614;
            case 0x1A9618u: goto label_1a9618;
            case 0x1A961Cu: goto label_1a961c;
            case 0x1A9620u: goto label_1a9620;
            case 0x1A9624u: goto label_1a9624;
            case 0x1A9628u: goto label_1a9628;
            case 0x1A962Cu: goto label_1a962c;
            case 0x1A9630u: goto label_1a9630;
            case 0x1A9634u: goto label_1a9634;
            case 0x1A9638u: goto label_1a9638;
            case 0x1A963Cu: goto label_1a963c;
            case 0x1A9640u: goto label_1a9640;
            case 0x1A9644u: goto label_1a9644;
            case 0x1A9648u: goto label_1a9648;
            case 0x1A964Cu: goto label_1a964c;
            case 0x1A9650u: goto label_1a9650;
            case 0x1A9654u: goto label_1a9654;
            case 0x1A9658u: goto label_1a9658;
            case 0x1A965Cu: goto label_1a965c;
            case 0x1A9660u: goto label_1a9660;
            case 0x1A9664u: goto label_1a9664;
            case 0x1A9668u: goto label_1a9668;
            case 0x1A966Cu: goto label_1a966c;
            case 0x1A9670u: goto label_1a9670;
            case 0x1A9674u: goto label_1a9674;
            case 0x1A9678u: goto label_1a9678;
            case 0x1A967Cu: goto label_1a967c;
            case 0x1A9680u: goto label_1a9680;
            case 0x1A9684u: goto label_1a9684;
            case 0x1A9688u: goto label_1a9688;
            case 0x1A968Cu: goto label_1a968c;
            case 0x1A9690u: goto label_1a9690;
            case 0x1A9694u: goto label_1a9694;
            case 0x1A9698u: goto label_1a9698;
            case 0x1A969Cu: goto label_1a969c;
            case 0x1A96A0u: goto label_1a96a0;
            case 0x1A96A4u: goto label_1a96a4;
            case 0x1A96A8u: goto label_1a96a8;
            case 0x1A96ACu: goto label_1a96ac;
            case 0x1A96B0u: goto label_1a96b0;
            case 0x1A96B4u: goto label_1a96b4;
            case 0x1A96B8u: goto label_1a96b8;
            case 0x1A96BCu: goto label_1a96bc;
            case 0x1A96C0u: goto label_1a96c0;
            case 0x1A96C4u: goto label_1a96c4;
            case 0x1A96C8u: goto label_1a96c8;
            case 0x1A96CCu: goto label_1a96cc;
            case 0x1A96D0u: goto label_1a96d0;
            case 0x1A96D4u: goto label_1a96d4;
            case 0x1A96D8u: goto label_1a96d8;
            case 0x1A96DCu: goto label_1a96dc;
            case 0x1A96E0u: goto label_1a96e0;
            case 0x1A96E4u: goto label_1a96e4;
            case 0x1A96E8u: goto label_1a96e8;
            case 0x1A96ECu: goto label_1a96ec;
            case 0x1A96F0u: goto label_1a96f0;
            case 0x1A96F4u: goto label_1a96f4;
            case 0x1A96F8u: goto label_1a96f8;
            case 0x1A96FCu: goto label_1a96fc;
            case 0x1A9700u: goto label_1a9700;
            case 0x1A9704u: goto label_1a9704;
            case 0x1A9708u: goto label_1a9708;
            case 0x1A970Cu: goto label_1a970c;
            case 0x1A9710u: goto label_1a9710;
            case 0x1A9714u: goto label_1a9714;
            case 0x1A9718u: goto label_1a9718;
            case 0x1A971Cu: goto label_1a971c;
            case 0x1A9720u: goto label_1a9720;
            case 0x1A9724u: goto label_1a9724;
            case 0x1A9728u: goto label_1a9728;
            case 0x1A972Cu: goto label_1a972c;
            case 0x1A9730u: goto label_1a9730;
            case 0x1A9734u: goto label_1a9734;
            case 0x1A9738u: goto label_1a9738;
            case 0x1A973Cu: goto label_1a973c;
            case 0x1A9740u: goto label_1a9740;
            case 0x1A9744u: goto label_1a9744;
            case 0x1A9748u: goto label_1a9748;
            case 0x1A974Cu: goto label_1a974c;
            default: break;
        }
        return;
    }
label_fallthrough_0x1a9748:
    ctx->pc = 0x1A9750u;
}
