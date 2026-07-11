#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001345F0
// Address: 0x1345f0 - 0x1347f8
void sub_001345F0_0x1345f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1345f0u;

label_1345f0:
    // 0x1345f0: 0x27bdff90
    ctx->pc = 0x1345f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
label_1345f4:
    // 0x1345f4: 0xffb40040
    ctx->pc = 0x1345f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
label_1345f8:
    // 0x1345f8: 0xa02d
    ctx->pc = 0x1345f8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1345fc:
    // 0x1345fc: 0xffb50048
    ctx->pc = 0x1345fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
label_134600:
    // 0x134600: 0xffb60050
    ctx->pc = 0x134600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
label_134604:
    // 0x134604: 0x80b02d
    ctx->pc = 0x134604u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_134608:
    // 0x134608: 0xffb70058
    ctx->pc = 0x134608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
label_13460c:
    // 0x13460c: 0xffb00020
    ctx->pc = 0x13460cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
label_134610:
    // 0x134610: 0xffb10028
    ctx->pc = 0x134610u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
label_134614:
    // 0x134614: 0xffb20030
    ctx->pc = 0x134614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
label_134618:
    // 0x134618: 0xffb30038
    ctx->pc = 0x134618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
label_13461c:
    // 0x13461c: 0xffbe0060
    ctx->pc = 0x13461cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
label_134620:
    // 0x134620: 0xffbf0068
    ctx->pc = 0x134620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
label_134624:
    // 0x134624: 0xc04b1cc
label_134628:
    if (ctx->pc == 0x134628u) {
        ctx->pc = 0x134628u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 12)));
        ctx->pc = 0x13462Cu;
        goto label_13462c;
    }
    ctx->pc = 0x134624u;
    SET_GPR_U32(ctx, 31, 0x13462Cu);
    ctx->pc = 0x134628u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 12)));
    ctx->pc = 0x12C730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C730_0x12c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13462Cu; }
    }
    if (ctx->pc != 0x13462Cu) { return; }
    ctx->pc = 0x13462Cu;
label_13462c:
    // 0x13462c: 0x3c030022
    ctx->pc = 0x13462cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_134630:
    // 0x134630: 0x0
    ctx->pc = 0x134630u;
    // NOP
label_134634:
    // 0x134634: 0xc04b5ea
label_134638:
    if (ctx->pc == 0x134638u) {
        ctx->pc = 0x134638u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 4)));
        ctx->pc = 0x13463Cu;
        goto label_13463c;
    }
    ctx->pc = 0x134634u;
    SET_GPR_U32(ctx, 31, 0x13463Cu);
    ctx->pc = 0x134638u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 4)));
    ctx->pc = 0x12D7A8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7A8_0x12d7a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13463Cu; }
    }
    if (ctx->pc != 0x13463Cu) { return; }
    ctx->pc = 0x13463Cu;
label_13463c:
    // 0x13463c: 0xc049938
label_134640:
    if (ctx->pc == 0x134640u) {
        ctx->pc = 0x134640u;
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x134644u;
        goto label_134644;
    }
    ctx->pc = 0x13463Cu;
    SET_GPR_U32(ctx, 31, 0x134644u);
    ctx->pc = 0x134640u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1264E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134644u; }
    }
    if (ctx->pc != 0x134644u) { return; }
    ctx->pc = 0x134644u;
label_134644:
    // 0x134644: 0x1ae00014
label_134648:
    if (ctx->pc == 0x134648u) {
        ctx->pc = 0x134648u;
        SET_GPR_U32(ctx, 21, READ32(ADD32(GPR_U32(ctx, 22), 72)));
        ctx->pc = 0x13464Cu;
        goto label_13464c;
    }
    ctx->pc = 0x134644u;
    {
        const bool branch_taken_0x134644 = (GPR_S32(ctx, 23) <= 0);
        ctx->pc = 0x134648u;
        SET_GPR_U32(ctx, 21, READ32(ADD32(GPR_U32(ctx, 22), 72)));
        if (branch_taken_0x134644) {
            ctx->pc = 0x134698u;
            goto label_134698;
        }
    }
    ctx->pc = 0x13464Cu;
label_13464c:
    // 0x13464c: 0x26d10018
    ctx->pc = 0x13464cu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 22), 24));
label_134650:
    // 0x134650: 0x8e240000
    ctx->pc = 0x134650u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_134654:
    // 0x134654: 0x26310004
    ctx->pc = 0x134654u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 4));
label_134658:
    // 0x134658: 0x1480c0
    ctx->pc = 0x134658u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 20), 3));
label_13465c:
    // 0x13465c: 0x26940001
    ctx->pc = 0x13465cu;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 20), 1));
label_134660:
    // 0x134660: 0x8c830000
    ctx->pc = 0x134660u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_134664:
    // 0x134664: 0x153040
    ctx->pc = 0x134664u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 21), 1));
label_134668:
    // 0x134668: 0x3b03821
    ctx->pc = 0x134668u;
    SET_GPR_U32(ctx, 7, ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 16)));
label_13466c:
    // 0x13466c: 0x8c620018
    ctx->pc = 0x13466cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 24)));
label_134670:
    // 0x134670: 0x40f809
label_134674:
    if (ctx->pc == 0x134674u) {
        ctx->pc = 0x134674u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x134678u;
        goto label_134678;
    }
    ctx->pc = 0x134670u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x134678u);
        ctx->pc = 0x134674u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1345F0u: goto label_1345f0;
            case 0x1345F4u: goto label_1345f4;
            case 0x1345F8u: goto label_1345f8;
            case 0x1345FCu: goto label_1345fc;
            case 0x134600u: goto label_134600;
            case 0x134604u: goto label_134604;
            case 0x134608u: goto label_134608;
            case 0x13460Cu: goto label_13460c;
            case 0x134610u: goto label_134610;
            case 0x134614u: goto label_134614;
            case 0x134618u: goto label_134618;
            case 0x13461Cu: goto label_13461c;
            case 0x134620u: goto label_134620;
            case 0x134624u: goto label_134624;
            case 0x134628u: goto label_134628;
            case 0x13462Cu: goto label_13462c;
            case 0x134630u: goto label_134630;
            case 0x134634u: goto label_134634;
            case 0x134638u: goto label_134638;
            case 0x13463Cu: goto label_13463c;
            case 0x134640u: goto label_134640;
            case 0x134644u: goto label_134644;
            case 0x134648u: goto label_134648;
            case 0x13464Cu: goto label_13464c;
            case 0x134650u: goto label_134650;
            case 0x134654u: goto label_134654;
            case 0x134658u: goto label_134658;
            case 0x13465Cu: goto label_13465c;
            case 0x134660u: goto label_134660;
            case 0x134664u: goto label_134664;
            case 0x134668u: goto label_134668;
            case 0x13466Cu: goto label_13466c;
            case 0x134670u: goto label_134670;
            case 0x134674u: goto label_134674;
            case 0x134678u: goto label_134678;
            case 0x13467Cu: goto label_13467c;
            case 0x134680u: goto label_134680;
            case 0x134684u: goto label_134684;
            case 0x134688u: goto label_134688;
            case 0x13468Cu: goto label_13468c;
            case 0x134690u: goto label_134690;
            case 0x134694u: goto label_134694;
            case 0x134698u: goto label_134698;
            case 0x13469Cu: goto label_13469c;
            case 0x1346A0u: goto label_1346a0;
            case 0x1346A4u: goto label_1346a4;
            case 0x1346A8u: goto label_1346a8;
            case 0x1346ACu: goto label_1346ac;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346B4u: goto label_1346b4;
            case 0x1346B8u: goto label_1346b8;
            case 0x1346BCu: goto label_1346bc;
            case 0x1346C0u: goto label_1346c0;
            case 0x1346C4u: goto label_1346c4;
            case 0x1346C8u: goto label_1346c8;
            case 0x1346CCu: goto label_1346cc;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346D4u: goto label_1346d4;
            case 0x1346D8u: goto label_1346d8;
            case 0x1346DCu: goto label_1346dc;
            case 0x1346E0u: goto label_1346e0;
            case 0x1346E4u: goto label_1346e4;
            case 0x1346E8u: goto label_1346e8;
            case 0x1346ECu: goto label_1346ec;
            case 0x1346F0u: goto label_1346f0;
            case 0x1346F4u: goto label_1346f4;
            case 0x1346F8u: goto label_1346f8;
            case 0x1346FCu: goto label_1346fc;
            case 0x134700u: goto label_134700;
            case 0x134704u: goto label_134704;
            case 0x134708u: goto label_134708;
            case 0x13470Cu: goto label_13470c;
            case 0x134710u: goto label_134710;
            case 0x134714u: goto label_134714;
            case 0x134718u: goto label_134718;
            case 0x13471Cu: goto label_13471c;
            case 0x134720u: goto label_134720;
            case 0x134724u: goto label_134724;
            case 0x134728u: goto label_134728;
            case 0x13472Cu: goto label_13472c;
            case 0x134730u: goto label_134730;
            case 0x134734u: goto label_134734;
            case 0x134738u: goto label_134738;
            case 0x13473Cu: goto label_13473c;
            case 0x134740u: goto label_134740;
            case 0x134744u: goto label_134744;
            case 0x134748u: goto label_134748;
            case 0x13474Cu: goto label_13474c;
            case 0x134750u: goto label_134750;
            case 0x134754u: goto label_134754;
            case 0x134758u: goto label_134758;
            case 0x13475Cu: goto label_13475c;
            case 0x134760u: goto label_134760;
            case 0x134764u: goto label_134764;
            case 0x134768u: goto label_134768;
            case 0x13476Cu: goto label_13476c;
            case 0x134770u: goto label_134770;
            case 0x134774u: goto label_134774;
            case 0x134778u: goto label_134778;
            case 0x13477Cu: goto label_13477c;
            case 0x134780u: goto label_134780;
            case 0x134784u: goto label_134784;
            case 0x134788u: goto label_134788;
            case 0x13478Cu: goto label_13478c;
            case 0x134790u: goto label_134790;
            case 0x134794u: goto label_134794;
            case 0x134798u: goto label_134798;
            case 0x13479Cu: goto label_13479c;
            case 0x1347A0u: goto label_1347a0;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347A8u: goto label_1347a8;
            case 0x1347ACu: goto label_1347ac;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347B4u: goto label_1347b4;
            case 0x1347B8u: goto label_1347b8;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C0u: goto label_1347c0;
            case 0x1347C4u: goto label_1347c4;
            case 0x1347C8u: goto label_1347c8;
            case 0x1347CCu: goto label_1347cc;
            case 0x1347D0u: goto label_1347d0;
            case 0x1347D4u: goto label_1347d4;
            case 0x1347D8u: goto label_1347d8;
            case 0x1347DCu: goto label_1347dc;
            case 0x1347E0u: goto label_1347e0;
            case 0x1347E4u: goto label_1347e4;
            case 0x1347E8u: goto label_1347e8;
            case 0x1347ECu: goto label_1347ec;
            case 0x1347F0u: goto label_1347f0;
            case 0x1347F4u: goto label_1347f4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x134678u; }
            if (ctx->pc != 0x134678u) { return; }
        }
    }
    ctx->pc = 0x134678u;
label_134678:
    // 0x134678: 0x297202a
    ctx->pc = 0x134678u;
    SET_GPR_U32(ctx, 4, SLT32(GPR_S32(ctx, 20), GPR_S32(ctx, 23)));
label_13467c:
    // 0x13467c: 0x27a20004
    ctx->pc = 0x13467cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 29), 4));
label_134680:
    // 0x134680: 0x508021
    ctx->pc = 0x134680u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_134684:
    // 0x134684: 0x8e030000
    ctx->pc = 0x134684u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_134688:
    // 0x134688: 0x31842
    ctx->pc = 0x134688u;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), 1));
label_13468c:
    // 0x13468c: 0x75102b
    ctx->pc = 0x13468cu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 3), GPR_U32(ctx, 21)));
label_134690:
    // 0x134690: 0x1480ffef
label_134694:
    if (ctx->pc == 0x134694u) {
        ctx->pc = 0x134694u;
        if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 21, GPR_U32(ctx, 3));
        ctx->pc = 0x134698u;
        goto label_134698;
    }
    ctx->pc = 0x134690u;
    {
        const bool branch_taken_0x134690 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x134694u;
        if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 21, GPR_U32(ctx, 3));
        if (branch_taken_0x134690) {
            ctx->pc = 0x134650u;
            goto label_134650;
        }
    }
    ctx->pc = 0x134698u;
label_134698:
    // 0x134698: 0x1ae00024
label_13469c:
    if (ctx->pc == 0x13469Cu) {
        ctx->pc = 0x13469Cu;
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1346A0u;
        goto label_1346a0;
    }
    ctx->pc = 0x134698u;
    {
        const bool branch_taken_0x134698 = (GPR_S32(ctx, 23) <= 0);
        ctx->pc = 0x13469Cu;
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x134698) {
            ctx->pc = 0x13472Cu;
            goto label_13472c;
        }
    }
    ctx->pc = 0x1346A0u;
label_1346a0:
    // 0x1346a0: 0x15f040
    ctx->pc = 0x1346a0u;
    SET_GPR_U32(ctx, 30, SLL32(GPR_U32(ctx, 21), 1));
label_1346a4:
    // 0x1346a4: 0x26d30018
    ctx->pc = 0x1346a4u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 22), 24));
label_1346a8:
    // 0x1346a8: 0x27a20010
    ctx->pc = 0x1346a8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 29), 16));
label_1346ac:
    // 0x1346ac: 0x0
    ctx->pc = 0x1346acu;
    // NOP
label_1346b0:
    // 0x1346b0: 0x1480c0
    ctx->pc = 0x1346b0u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 20), 3));
label_1346b4:
    // 0x1346b4: 0x3b08821
    ctx->pc = 0x1346b4u;
    SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 16)));
label_1346b8:
    // 0x1346b8: 0x509021
    ctx->pc = 0x1346b8u;
    SET_GPR_U32(ctx, 18, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_1346bc:
    // 0x1346bc: 0x240382d
    ctx->pc = 0x1346bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1346c0:
    // 0x1346c0: 0x220202d
    ctx->pc = 0x1346c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1346c4:
    // 0x1346c4: 0x3c0282d
    ctx->pc = 0x1346c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
label_1346c8:
    // 0x1346c8: 0xc0501f8
label_1346cc:
    if (ctx->pc == 0x1346CCu) {
        ctx->pc = 0x1346CCu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1346D0u;
        goto label_1346d0;
    }
    ctx->pc = 0x1346C8u;
    SET_GPR_U32(ctx, 31, 0x1346D0u);
    ctx->pc = 0x1346CCu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1407E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1346D0u; }
    }
    if (ctx->pc != 0x1346D0u) { return; }
    ctx->pc = 0x1346D0u;
label_1346d0:
    // 0x1346d0: 0x282d
    ctx->pc = 0x1346d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1346d4:
    // 0x1346d4: 0x27a20004
    ctx->pc = 0x1346d4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 29), 4));
label_1346d8:
    // 0x1346d8: 0x8e240000
    ctx->pc = 0x1346d8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_1346dc:
    // 0x1346dc: 0x508021
    ctx->pc = 0x1346dcu;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_1346e0:
    // 0x1346e0: 0x26940001
    ctx->pc = 0x1346e0u;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 20), 1));
label_1346e4:
    // 0x1346e4: 0xc041f1a
label_1346e8:
    if (ctx->pc == 0x1346E8u) {
        ctx->pc = 0x1346E8u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->pc = 0x1346ECu;
        goto label_1346ec;
    }
    ctx->pc = 0x1346E4u;
    SET_GPR_U32(ctx, 31, 0x1346ECu);
    ctx->pc = 0x1346E8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1346ECu; }
    }
    if (ctx->pc != 0x1346ECu) { return; }
    ctx->pc = 0x1346ECu;
label_1346ec:
    // 0x1346ec: 0x8e640000
    ctx->pc = 0x1346ecu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_1346f0:
    // 0x1346f0: 0x220302d
    ctx->pc = 0x1346f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1346f4:
    // 0x1346f4: 0x8c830000
    ctx->pc = 0x1346f4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_1346f8:
    // 0x1346f8: 0x8c620020
    ctx->pc = 0x1346f8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 32)));
label_1346fc:
    // 0x1346fc: 0x40f809
label_134700:
    if (ctx->pc == 0x134700u) {
        ctx->pc = 0x134700u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x134704u;
        goto label_134704;
    }
    ctx->pc = 0x1346FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x134704u);
        ctx->pc = 0x134700u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1345F0u: goto label_1345f0;
            case 0x1345F4u: goto label_1345f4;
            case 0x1345F8u: goto label_1345f8;
            case 0x1345FCu: goto label_1345fc;
            case 0x134600u: goto label_134600;
            case 0x134604u: goto label_134604;
            case 0x134608u: goto label_134608;
            case 0x13460Cu: goto label_13460c;
            case 0x134610u: goto label_134610;
            case 0x134614u: goto label_134614;
            case 0x134618u: goto label_134618;
            case 0x13461Cu: goto label_13461c;
            case 0x134620u: goto label_134620;
            case 0x134624u: goto label_134624;
            case 0x134628u: goto label_134628;
            case 0x13462Cu: goto label_13462c;
            case 0x134630u: goto label_134630;
            case 0x134634u: goto label_134634;
            case 0x134638u: goto label_134638;
            case 0x13463Cu: goto label_13463c;
            case 0x134640u: goto label_134640;
            case 0x134644u: goto label_134644;
            case 0x134648u: goto label_134648;
            case 0x13464Cu: goto label_13464c;
            case 0x134650u: goto label_134650;
            case 0x134654u: goto label_134654;
            case 0x134658u: goto label_134658;
            case 0x13465Cu: goto label_13465c;
            case 0x134660u: goto label_134660;
            case 0x134664u: goto label_134664;
            case 0x134668u: goto label_134668;
            case 0x13466Cu: goto label_13466c;
            case 0x134670u: goto label_134670;
            case 0x134674u: goto label_134674;
            case 0x134678u: goto label_134678;
            case 0x13467Cu: goto label_13467c;
            case 0x134680u: goto label_134680;
            case 0x134684u: goto label_134684;
            case 0x134688u: goto label_134688;
            case 0x13468Cu: goto label_13468c;
            case 0x134690u: goto label_134690;
            case 0x134694u: goto label_134694;
            case 0x134698u: goto label_134698;
            case 0x13469Cu: goto label_13469c;
            case 0x1346A0u: goto label_1346a0;
            case 0x1346A4u: goto label_1346a4;
            case 0x1346A8u: goto label_1346a8;
            case 0x1346ACu: goto label_1346ac;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346B4u: goto label_1346b4;
            case 0x1346B8u: goto label_1346b8;
            case 0x1346BCu: goto label_1346bc;
            case 0x1346C0u: goto label_1346c0;
            case 0x1346C4u: goto label_1346c4;
            case 0x1346C8u: goto label_1346c8;
            case 0x1346CCu: goto label_1346cc;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346D4u: goto label_1346d4;
            case 0x1346D8u: goto label_1346d8;
            case 0x1346DCu: goto label_1346dc;
            case 0x1346E0u: goto label_1346e0;
            case 0x1346E4u: goto label_1346e4;
            case 0x1346E8u: goto label_1346e8;
            case 0x1346ECu: goto label_1346ec;
            case 0x1346F0u: goto label_1346f0;
            case 0x1346F4u: goto label_1346f4;
            case 0x1346F8u: goto label_1346f8;
            case 0x1346FCu: goto label_1346fc;
            case 0x134700u: goto label_134700;
            case 0x134704u: goto label_134704;
            case 0x134708u: goto label_134708;
            case 0x13470Cu: goto label_13470c;
            case 0x134710u: goto label_134710;
            case 0x134714u: goto label_134714;
            case 0x134718u: goto label_134718;
            case 0x13471Cu: goto label_13471c;
            case 0x134720u: goto label_134720;
            case 0x134724u: goto label_134724;
            case 0x134728u: goto label_134728;
            case 0x13472Cu: goto label_13472c;
            case 0x134730u: goto label_134730;
            case 0x134734u: goto label_134734;
            case 0x134738u: goto label_134738;
            case 0x13473Cu: goto label_13473c;
            case 0x134740u: goto label_134740;
            case 0x134744u: goto label_134744;
            case 0x134748u: goto label_134748;
            case 0x13474Cu: goto label_13474c;
            case 0x134750u: goto label_134750;
            case 0x134754u: goto label_134754;
            case 0x134758u: goto label_134758;
            case 0x13475Cu: goto label_13475c;
            case 0x134760u: goto label_134760;
            case 0x134764u: goto label_134764;
            case 0x134768u: goto label_134768;
            case 0x13476Cu: goto label_13476c;
            case 0x134770u: goto label_134770;
            case 0x134774u: goto label_134774;
            case 0x134778u: goto label_134778;
            case 0x13477Cu: goto label_13477c;
            case 0x134780u: goto label_134780;
            case 0x134784u: goto label_134784;
            case 0x134788u: goto label_134788;
            case 0x13478Cu: goto label_13478c;
            case 0x134790u: goto label_134790;
            case 0x134794u: goto label_134794;
            case 0x134798u: goto label_134798;
            case 0x13479Cu: goto label_13479c;
            case 0x1347A0u: goto label_1347a0;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347A8u: goto label_1347a8;
            case 0x1347ACu: goto label_1347ac;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347B4u: goto label_1347b4;
            case 0x1347B8u: goto label_1347b8;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C0u: goto label_1347c0;
            case 0x1347C4u: goto label_1347c4;
            case 0x1347C8u: goto label_1347c8;
            case 0x1347CCu: goto label_1347cc;
            case 0x1347D0u: goto label_1347d0;
            case 0x1347D4u: goto label_1347d4;
            case 0x1347D8u: goto label_1347d8;
            case 0x1347DCu: goto label_1347dc;
            case 0x1347E0u: goto label_1347e0;
            case 0x1347E4u: goto label_1347e4;
            case 0x1347E8u: goto label_1347e8;
            case 0x1347ECu: goto label_1347ec;
            case 0x1347F0u: goto label_1347f0;
            case 0x1347F4u: goto label_1347f4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x134704u; }
            if (ctx->pc != 0x134704u) { return; }
        }
    }
    ctx->pc = 0x134704u;
label_134704:
    // 0x134704: 0x8e640000
    ctx->pc = 0x134704u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_134708:
    // 0x134708: 0x240302d
    ctx->pc = 0x134708u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_13470c:
    // 0x13470c: 0x282d
    ctx->pc = 0x13470cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_134710:
    // 0x134710: 0x8c830000
    ctx->pc = 0x134710u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_134714:
    // 0x134714: 0x8c62001c
    ctx->pc = 0x134714u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 28)));
label_134718:
    // 0x134718: 0x40f809
label_13471c:
    if (ctx->pc == 0x13471Cu) {
        ctx->pc = 0x13471Cu;
        SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 4));
        ctx->pc = 0x134720u;
        goto label_134720;
    }
    ctx->pc = 0x134718u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x134720u);
        ctx->pc = 0x13471Cu;
        SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1345F0u: goto label_1345f0;
            case 0x1345F4u: goto label_1345f4;
            case 0x1345F8u: goto label_1345f8;
            case 0x1345FCu: goto label_1345fc;
            case 0x134600u: goto label_134600;
            case 0x134604u: goto label_134604;
            case 0x134608u: goto label_134608;
            case 0x13460Cu: goto label_13460c;
            case 0x134610u: goto label_134610;
            case 0x134614u: goto label_134614;
            case 0x134618u: goto label_134618;
            case 0x13461Cu: goto label_13461c;
            case 0x134620u: goto label_134620;
            case 0x134624u: goto label_134624;
            case 0x134628u: goto label_134628;
            case 0x13462Cu: goto label_13462c;
            case 0x134630u: goto label_134630;
            case 0x134634u: goto label_134634;
            case 0x134638u: goto label_134638;
            case 0x13463Cu: goto label_13463c;
            case 0x134640u: goto label_134640;
            case 0x134644u: goto label_134644;
            case 0x134648u: goto label_134648;
            case 0x13464Cu: goto label_13464c;
            case 0x134650u: goto label_134650;
            case 0x134654u: goto label_134654;
            case 0x134658u: goto label_134658;
            case 0x13465Cu: goto label_13465c;
            case 0x134660u: goto label_134660;
            case 0x134664u: goto label_134664;
            case 0x134668u: goto label_134668;
            case 0x13466Cu: goto label_13466c;
            case 0x134670u: goto label_134670;
            case 0x134674u: goto label_134674;
            case 0x134678u: goto label_134678;
            case 0x13467Cu: goto label_13467c;
            case 0x134680u: goto label_134680;
            case 0x134684u: goto label_134684;
            case 0x134688u: goto label_134688;
            case 0x13468Cu: goto label_13468c;
            case 0x134690u: goto label_134690;
            case 0x134694u: goto label_134694;
            case 0x134698u: goto label_134698;
            case 0x13469Cu: goto label_13469c;
            case 0x1346A0u: goto label_1346a0;
            case 0x1346A4u: goto label_1346a4;
            case 0x1346A8u: goto label_1346a8;
            case 0x1346ACu: goto label_1346ac;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346B4u: goto label_1346b4;
            case 0x1346B8u: goto label_1346b8;
            case 0x1346BCu: goto label_1346bc;
            case 0x1346C0u: goto label_1346c0;
            case 0x1346C4u: goto label_1346c4;
            case 0x1346C8u: goto label_1346c8;
            case 0x1346CCu: goto label_1346cc;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346D4u: goto label_1346d4;
            case 0x1346D8u: goto label_1346d8;
            case 0x1346DCu: goto label_1346dc;
            case 0x1346E0u: goto label_1346e0;
            case 0x1346E4u: goto label_1346e4;
            case 0x1346E8u: goto label_1346e8;
            case 0x1346ECu: goto label_1346ec;
            case 0x1346F0u: goto label_1346f0;
            case 0x1346F4u: goto label_1346f4;
            case 0x1346F8u: goto label_1346f8;
            case 0x1346FCu: goto label_1346fc;
            case 0x134700u: goto label_134700;
            case 0x134704u: goto label_134704;
            case 0x134708u: goto label_134708;
            case 0x13470Cu: goto label_13470c;
            case 0x134710u: goto label_134710;
            case 0x134714u: goto label_134714;
            case 0x134718u: goto label_134718;
            case 0x13471Cu: goto label_13471c;
            case 0x134720u: goto label_134720;
            case 0x134724u: goto label_134724;
            case 0x134728u: goto label_134728;
            case 0x13472Cu: goto label_13472c;
            case 0x134730u: goto label_134730;
            case 0x134734u: goto label_134734;
            case 0x134738u: goto label_134738;
            case 0x13473Cu: goto label_13473c;
            case 0x134740u: goto label_134740;
            case 0x134744u: goto label_134744;
            case 0x134748u: goto label_134748;
            case 0x13474Cu: goto label_13474c;
            case 0x134750u: goto label_134750;
            case 0x134754u: goto label_134754;
            case 0x134758u: goto label_134758;
            case 0x13475Cu: goto label_13475c;
            case 0x134760u: goto label_134760;
            case 0x134764u: goto label_134764;
            case 0x134768u: goto label_134768;
            case 0x13476Cu: goto label_13476c;
            case 0x134770u: goto label_134770;
            case 0x134774u: goto label_134774;
            case 0x134778u: goto label_134778;
            case 0x13477Cu: goto label_13477c;
            case 0x134780u: goto label_134780;
            case 0x134784u: goto label_134784;
            case 0x134788u: goto label_134788;
            case 0x13478Cu: goto label_13478c;
            case 0x134790u: goto label_134790;
            case 0x134794u: goto label_134794;
            case 0x134798u: goto label_134798;
            case 0x13479Cu: goto label_13479c;
            case 0x1347A0u: goto label_1347a0;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347A8u: goto label_1347a8;
            case 0x1347ACu: goto label_1347ac;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347B4u: goto label_1347b4;
            case 0x1347B8u: goto label_1347b8;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C0u: goto label_1347c0;
            case 0x1347C4u: goto label_1347c4;
            case 0x1347C8u: goto label_1347c8;
            case 0x1347CCu: goto label_1347cc;
            case 0x1347D0u: goto label_1347d0;
            case 0x1347D4u: goto label_1347d4;
            case 0x1347D8u: goto label_1347d8;
            case 0x1347DCu: goto label_1347dc;
            case 0x1347E0u: goto label_1347e0;
            case 0x1347E4u: goto label_1347e4;
            case 0x1347E8u: goto label_1347e8;
            case 0x1347ECu: goto label_1347ec;
            case 0x1347F0u: goto label_1347f0;
            case 0x1347F4u: goto label_1347f4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x134720u; }
            if (ctx->pc != 0x134720u) { return; }
        }
    }
    ctx->pc = 0x134720u;
label_134720:
    // 0x134720: 0x297182a
    ctx->pc = 0x134720u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 20), GPR_S32(ctx, 23)));
label_134724:
    // 0x134724: 0x1460ffe2
label_134728:
    if (ctx->pc == 0x134728u) {
        ctx->pc = 0x134728u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x13472Cu;
        goto label_13472c;
    }
    ctx->pc = 0x134724u;
    {
        const bool branch_taken_0x134724 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x134728u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 29), 16));
        if (branch_taken_0x134724) {
            ctx->pc = 0x1346B0u;
            goto label_1346b0;
        }
    }
    ctx->pc = 0x13472Cu;
label_13472c:
    // 0x13472c: 0x8ec200a8
    ctx->pc = 0x13472cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 22), 168)));
label_134730:
    // 0x134730: 0x882d
    ctx->pc = 0x134730u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_134734:
    // 0x134734: 0x551021
    ctx->pc = 0x134734u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
label_134738:
    // 0x134738: 0xc04993e
label_13473c:
    if (ctx->pc == 0x13473Cu) {
        ctx->pc = 0x13473Cu;
        WRITE32(ADD32(GPR_U32(ctx, 22), 168), GPR_U32(ctx, 2));
        ctx->pc = 0x134740u;
        goto label_134740;
    }
    ctx->pc = 0x134738u;
    SET_GPR_U32(ctx, 31, 0x134740u);
    ctx->pc = 0x13473Cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 168), GPR_U32(ctx, 2));
    ctx->pc = 0x1264F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134740u; }
    }
    if (ctx->pc != 0x134740u) { return; }
    ctx->pc = 0x134740u;
label_134740:
    // 0x134740: 0x1ae0000e
label_134744:
    if (ctx->pc == 0x134744u) {
        ctx->pc = 0x134748u;
        goto label_134748;
    }
    ctx->pc = 0x134740u;
    {
        const bool branch_taken_0x134740 = (GPR_S32(ctx, 23) <= 0);
        if (branch_taken_0x134740) {
            ctx->pc = 0x13477Cu;
            goto label_13477c;
        }
    }
    ctx->pc = 0x134748u;
label_134748:
    // 0x134748: 0x2e0a02d
    ctx->pc = 0x134748u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
label_13474c:
    // 0x13474c: 0x26d00018
    ctx->pc = 0x13474cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 22), 24));
label_134750:
    // 0x134750: 0x8e040000
    ctx->pc = 0x134750u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_134754:
    // 0x134754: 0x26100004
    ctx->pc = 0x134754u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4));
label_134758:
    // 0x134758: 0x24050001
    ctx->pc = 0x134758u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_13475c:
    // 0x13475c: 0x8c830000
    ctx->pc = 0x13475cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_134760:
    // 0x134760: 0x8c620024
    ctx->pc = 0x134760u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 36)));
label_134764:
    // 0x134764: 0x40f809
label_134768:
    if (ctx->pc == 0x134768u) {
        ctx->pc = 0x134768u;
        SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 20), 4294967295));
        ctx->pc = 0x13476Cu;
        goto label_13476c;
    }
    ctx->pc = 0x134764u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13476Cu);
        ctx->pc = 0x134768u;
        SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 20), 4294967295));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1345F0u: goto label_1345f0;
            case 0x1345F4u: goto label_1345f4;
            case 0x1345F8u: goto label_1345f8;
            case 0x1345FCu: goto label_1345fc;
            case 0x134600u: goto label_134600;
            case 0x134604u: goto label_134604;
            case 0x134608u: goto label_134608;
            case 0x13460Cu: goto label_13460c;
            case 0x134610u: goto label_134610;
            case 0x134614u: goto label_134614;
            case 0x134618u: goto label_134618;
            case 0x13461Cu: goto label_13461c;
            case 0x134620u: goto label_134620;
            case 0x134624u: goto label_134624;
            case 0x134628u: goto label_134628;
            case 0x13462Cu: goto label_13462c;
            case 0x134630u: goto label_134630;
            case 0x134634u: goto label_134634;
            case 0x134638u: goto label_134638;
            case 0x13463Cu: goto label_13463c;
            case 0x134640u: goto label_134640;
            case 0x134644u: goto label_134644;
            case 0x134648u: goto label_134648;
            case 0x13464Cu: goto label_13464c;
            case 0x134650u: goto label_134650;
            case 0x134654u: goto label_134654;
            case 0x134658u: goto label_134658;
            case 0x13465Cu: goto label_13465c;
            case 0x134660u: goto label_134660;
            case 0x134664u: goto label_134664;
            case 0x134668u: goto label_134668;
            case 0x13466Cu: goto label_13466c;
            case 0x134670u: goto label_134670;
            case 0x134674u: goto label_134674;
            case 0x134678u: goto label_134678;
            case 0x13467Cu: goto label_13467c;
            case 0x134680u: goto label_134680;
            case 0x134684u: goto label_134684;
            case 0x134688u: goto label_134688;
            case 0x13468Cu: goto label_13468c;
            case 0x134690u: goto label_134690;
            case 0x134694u: goto label_134694;
            case 0x134698u: goto label_134698;
            case 0x13469Cu: goto label_13469c;
            case 0x1346A0u: goto label_1346a0;
            case 0x1346A4u: goto label_1346a4;
            case 0x1346A8u: goto label_1346a8;
            case 0x1346ACu: goto label_1346ac;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346B4u: goto label_1346b4;
            case 0x1346B8u: goto label_1346b8;
            case 0x1346BCu: goto label_1346bc;
            case 0x1346C0u: goto label_1346c0;
            case 0x1346C4u: goto label_1346c4;
            case 0x1346C8u: goto label_1346c8;
            case 0x1346CCu: goto label_1346cc;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346D4u: goto label_1346d4;
            case 0x1346D8u: goto label_1346d8;
            case 0x1346DCu: goto label_1346dc;
            case 0x1346E0u: goto label_1346e0;
            case 0x1346E4u: goto label_1346e4;
            case 0x1346E8u: goto label_1346e8;
            case 0x1346ECu: goto label_1346ec;
            case 0x1346F0u: goto label_1346f0;
            case 0x1346F4u: goto label_1346f4;
            case 0x1346F8u: goto label_1346f8;
            case 0x1346FCu: goto label_1346fc;
            case 0x134700u: goto label_134700;
            case 0x134704u: goto label_134704;
            case 0x134708u: goto label_134708;
            case 0x13470Cu: goto label_13470c;
            case 0x134710u: goto label_134710;
            case 0x134714u: goto label_134714;
            case 0x134718u: goto label_134718;
            case 0x13471Cu: goto label_13471c;
            case 0x134720u: goto label_134720;
            case 0x134724u: goto label_134724;
            case 0x134728u: goto label_134728;
            case 0x13472Cu: goto label_13472c;
            case 0x134730u: goto label_134730;
            case 0x134734u: goto label_134734;
            case 0x134738u: goto label_134738;
            case 0x13473Cu: goto label_13473c;
            case 0x134740u: goto label_134740;
            case 0x134744u: goto label_134744;
            case 0x134748u: goto label_134748;
            case 0x13474Cu: goto label_13474c;
            case 0x134750u: goto label_134750;
            case 0x134754u: goto label_134754;
            case 0x134758u: goto label_134758;
            case 0x13475Cu: goto label_13475c;
            case 0x134760u: goto label_134760;
            case 0x134764u: goto label_134764;
            case 0x134768u: goto label_134768;
            case 0x13476Cu: goto label_13476c;
            case 0x134770u: goto label_134770;
            case 0x134774u: goto label_134774;
            case 0x134778u: goto label_134778;
            case 0x13477Cu: goto label_13477c;
            case 0x134780u: goto label_134780;
            case 0x134784u: goto label_134784;
            case 0x134788u: goto label_134788;
            case 0x13478Cu: goto label_13478c;
            case 0x134790u: goto label_134790;
            case 0x134794u: goto label_134794;
            case 0x134798u: goto label_134798;
            case 0x13479Cu: goto label_13479c;
            case 0x1347A0u: goto label_1347a0;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347A8u: goto label_1347a8;
            case 0x1347ACu: goto label_1347ac;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347B4u: goto label_1347b4;
            case 0x1347B8u: goto label_1347b8;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C0u: goto label_1347c0;
            case 0x1347C4u: goto label_1347c4;
            case 0x1347C8u: goto label_1347c8;
            case 0x1347CCu: goto label_1347cc;
            case 0x1347D0u: goto label_1347d0;
            case 0x1347D4u: goto label_1347d4;
            case 0x1347D8u: goto label_1347d8;
            case 0x1347DCu: goto label_1347dc;
            case 0x1347E0u: goto label_1347e0;
            case 0x1347E4u: goto label_1347e4;
            case 0x1347E8u: goto label_1347e8;
            case 0x1347ECu: goto label_1347ec;
            case 0x1347F0u: goto label_1347f0;
            case 0x1347F4u: goto label_1347f4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13476Cu; }
            if (ctx->pc != 0x13476Cu) { return; }
        }
    }
    ctx->pc = 0x13476Cu;
label_13476c:
    // 0x13476c: 0x21042
    ctx->pc = 0x13476cu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 1));
label_134770:
    // 0x134770: 0x51182a
    ctx->pc = 0x134770u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 17)));
label_134774:
    // 0x134774: 0x1680fff6
label_134778:
    if (ctx->pc == 0x134778u) {
        ctx->pc = 0x134778u;
        if (GPR_U32(ctx, 3) == 0) SET_GPR_U32(ctx, 17, GPR_U32(ctx, 2));
        ctx->pc = 0x13477Cu;
        goto label_13477c;
    }
    ctx->pc = 0x134774u;
    {
        const bool branch_taken_0x134774 = (GPR_U32(ctx, 20) != GPR_U32(ctx, 0));
        ctx->pc = 0x134778u;
        if (GPR_U32(ctx, 3) == 0) SET_GPR_U32(ctx, 17, GPR_U32(ctx, 2));
        if (branch_taken_0x134774) {
            ctx->pc = 0x134750u;
            goto label_134750;
        }
    }
    ctx->pc = 0x13477Cu;
label_13477c:
    // 0x13477c: 0xc04b1cc
label_134780:
    if (ctx->pc == 0x134780u) {
        ctx->pc = 0x134780u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 12)));
        ctx->pc = 0x134784u;
        goto label_134784;
    }
    ctx->pc = 0x13477Cu;
    SET_GPR_U32(ctx, 31, 0x134784u);
    ctx->pc = 0x134780u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 12)));
    ctx->pc = 0x12C730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C730_0x12c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134784u; }
    }
    if (ctx->pc != 0x134784u) { return; }
    ctx->pc = 0x134784u;
label_134784:
    // 0x134784: 0x8ec300a8
    ctx->pc = 0x134784u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 22), 168)));
label_134788:
    // 0x134788: 0x2221021
    ctx->pc = 0x134788u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_13478c:
    // 0x13478c: 0x431023
    ctx->pc = 0x13478cu;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_134790:
    // 0x134790: 0x5c40000d
label_134794:
    if (ctx->pc == 0x134794u) {
        ctx->pc = 0x134794u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->pc = 0x134798u;
        goto label_134798;
    }
    ctx->pc = 0x134790u;
    {
        const bool branch_taken_0x134790 = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x134790) {
            ctx->pc = 0x134794u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
            ctx->pc = 0x1347C8u;
            goto label_1347c8;
        }
    }
    ctx->pc = 0x134798u;
label_134798:
    // 0x134798: 0x8ec4000c
    ctx->pc = 0x134798u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 12)));
label_13479c:
    // 0x13479c: 0xc04b1ba
label_1347a0:
    if (ctx->pc == 0x1347A0u) {
        ctx->pc = 0x1347A0u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1347A4u;
        goto label_1347a4;
    }
    ctx->pc = 0x13479Cu;
    SET_GPR_U32(ctx, 31, 0x1347A4u);
    ctx->pc = 0x1347A0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x12C6E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C6E8_0x12c6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1347A4u; }
    }
    if (ctx->pc != 0x1347A4u) { return; }
    ctx->pc = 0x1347A4u;
label_1347a4:
    // 0x1347a4: 0x8ec4000c
    ctx->pc = 0x1347a4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 12)));
label_1347a8:
    // 0x1347a8: 0xc04b1c0
label_1347ac:
    if (ctx->pc == 0x1347ACu) {
        ctx->pc = 0x1347ACu;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1347B0u;
        goto label_1347b0;
    }
    ctx->pc = 0x1347A8u;
    SET_GPR_U32(ctx, 31, 0x1347B0u);
    ctx->pc = 0x1347ACu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x12C700u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C700_0x12c700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1347B0u; }
    }
    if (ctx->pc != 0x1347B0u) { return; }
    ctx->pc = 0x1347B0u;
label_1347b0:
    // 0x1347b0: 0x8ec4000c
    ctx->pc = 0x1347b0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 12)));
label_1347b4:
    // 0x1347b4: 0xc04fb16
label_1347b8:
    if (ctx->pc == 0x1347B8u) {
        ctx->pc = 0x1347B8u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1347BCu;
        goto label_1347bc;
    }
    ctx->pc = 0x1347B4u;
    SET_GPR_U32(ctx, 31, 0x1347BCu);
    ctx->pc = 0x1347B8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x13EC58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013EC58_0x13ec58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1347BCu; }
    }
    if (ctx->pc != 0x1347BCu) { return; }
    ctx->pc = 0x1347BCu;
label_1347bc:
    // 0x1347bc: 0x24020005
    ctx->pc = 0x1347bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 5));
label_1347c0:
    // 0x1347c0: 0xa2c20001
    ctx->pc = 0x1347c0u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 1), (uint8_t)GPR_U32(ctx, 2));
label_1347c4:
    // 0x1347c4: 0xdfb00020
    ctx->pc = 0x1347c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1347c8:
    // 0x1347c8: 0xdfb10028
    ctx->pc = 0x1347c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_1347cc:
    // 0x1347cc: 0xdfb20030
    ctx->pc = 0x1347ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1347d0:
    // 0x1347d0: 0xdfb30038
    ctx->pc = 0x1347d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
label_1347d4:
    // 0x1347d4: 0xdfb40040
    ctx->pc = 0x1347d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1347d8:
    // 0x1347d8: 0xdfb50048
    ctx->pc = 0x1347d8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
label_1347dc:
    // 0x1347dc: 0xdfb60050
    ctx->pc = 0x1347dcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_1347e0:
    // 0x1347e0: 0xdfb70058
    ctx->pc = 0x1347e0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
label_1347e4:
    // 0x1347e4: 0xdfbe0060
    ctx->pc = 0x1347e4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_1347e8:
    // 0x1347e8: 0xdfbf0068
    ctx->pc = 0x1347e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
label_1347ec:
    // 0x1347ec: 0x3e00008
label_1347f0:
    if (ctx->pc == 0x1347F0u) {
        ctx->pc = 0x1347F0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = 0x1347F4u;
        goto label_1347f4;
    }
    ctx->pc = 0x1347ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1347F0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1345F0u: goto label_1345f0;
            case 0x1345F4u: goto label_1345f4;
            case 0x1345F8u: goto label_1345f8;
            case 0x1345FCu: goto label_1345fc;
            case 0x134600u: goto label_134600;
            case 0x134604u: goto label_134604;
            case 0x134608u: goto label_134608;
            case 0x13460Cu: goto label_13460c;
            case 0x134610u: goto label_134610;
            case 0x134614u: goto label_134614;
            case 0x134618u: goto label_134618;
            case 0x13461Cu: goto label_13461c;
            case 0x134620u: goto label_134620;
            case 0x134624u: goto label_134624;
            case 0x134628u: goto label_134628;
            case 0x13462Cu: goto label_13462c;
            case 0x134630u: goto label_134630;
            case 0x134634u: goto label_134634;
            case 0x134638u: goto label_134638;
            case 0x13463Cu: goto label_13463c;
            case 0x134640u: goto label_134640;
            case 0x134644u: goto label_134644;
            case 0x134648u: goto label_134648;
            case 0x13464Cu: goto label_13464c;
            case 0x134650u: goto label_134650;
            case 0x134654u: goto label_134654;
            case 0x134658u: goto label_134658;
            case 0x13465Cu: goto label_13465c;
            case 0x134660u: goto label_134660;
            case 0x134664u: goto label_134664;
            case 0x134668u: goto label_134668;
            case 0x13466Cu: goto label_13466c;
            case 0x134670u: goto label_134670;
            case 0x134674u: goto label_134674;
            case 0x134678u: goto label_134678;
            case 0x13467Cu: goto label_13467c;
            case 0x134680u: goto label_134680;
            case 0x134684u: goto label_134684;
            case 0x134688u: goto label_134688;
            case 0x13468Cu: goto label_13468c;
            case 0x134690u: goto label_134690;
            case 0x134694u: goto label_134694;
            case 0x134698u: goto label_134698;
            case 0x13469Cu: goto label_13469c;
            case 0x1346A0u: goto label_1346a0;
            case 0x1346A4u: goto label_1346a4;
            case 0x1346A8u: goto label_1346a8;
            case 0x1346ACu: goto label_1346ac;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346B4u: goto label_1346b4;
            case 0x1346B8u: goto label_1346b8;
            case 0x1346BCu: goto label_1346bc;
            case 0x1346C0u: goto label_1346c0;
            case 0x1346C4u: goto label_1346c4;
            case 0x1346C8u: goto label_1346c8;
            case 0x1346CCu: goto label_1346cc;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346D4u: goto label_1346d4;
            case 0x1346D8u: goto label_1346d8;
            case 0x1346DCu: goto label_1346dc;
            case 0x1346E0u: goto label_1346e0;
            case 0x1346E4u: goto label_1346e4;
            case 0x1346E8u: goto label_1346e8;
            case 0x1346ECu: goto label_1346ec;
            case 0x1346F0u: goto label_1346f0;
            case 0x1346F4u: goto label_1346f4;
            case 0x1346F8u: goto label_1346f8;
            case 0x1346FCu: goto label_1346fc;
            case 0x134700u: goto label_134700;
            case 0x134704u: goto label_134704;
            case 0x134708u: goto label_134708;
            case 0x13470Cu: goto label_13470c;
            case 0x134710u: goto label_134710;
            case 0x134714u: goto label_134714;
            case 0x134718u: goto label_134718;
            case 0x13471Cu: goto label_13471c;
            case 0x134720u: goto label_134720;
            case 0x134724u: goto label_134724;
            case 0x134728u: goto label_134728;
            case 0x13472Cu: goto label_13472c;
            case 0x134730u: goto label_134730;
            case 0x134734u: goto label_134734;
            case 0x134738u: goto label_134738;
            case 0x13473Cu: goto label_13473c;
            case 0x134740u: goto label_134740;
            case 0x134744u: goto label_134744;
            case 0x134748u: goto label_134748;
            case 0x13474Cu: goto label_13474c;
            case 0x134750u: goto label_134750;
            case 0x134754u: goto label_134754;
            case 0x134758u: goto label_134758;
            case 0x13475Cu: goto label_13475c;
            case 0x134760u: goto label_134760;
            case 0x134764u: goto label_134764;
            case 0x134768u: goto label_134768;
            case 0x13476Cu: goto label_13476c;
            case 0x134770u: goto label_134770;
            case 0x134774u: goto label_134774;
            case 0x134778u: goto label_134778;
            case 0x13477Cu: goto label_13477c;
            case 0x134780u: goto label_134780;
            case 0x134784u: goto label_134784;
            case 0x134788u: goto label_134788;
            case 0x13478Cu: goto label_13478c;
            case 0x134790u: goto label_134790;
            case 0x134794u: goto label_134794;
            case 0x134798u: goto label_134798;
            case 0x13479Cu: goto label_13479c;
            case 0x1347A0u: goto label_1347a0;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347A8u: goto label_1347a8;
            case 0x1347ACu: goto label_1347ac;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347B4u: goto label_1347b4;
            case 0x1347B8u: goto label_1347b8;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C0u: goto label_1347c0;
            case 0x1347C4u: goto label_1347c4;
            case 0x1347C8u: goto label_1347c8;
            case 0x1347CCu: goto label_1347cc;
            case 0x1347D0u: goto label_1347d0;
            case 0x1347D4u: goto label_1347d4;
            case 0x1347D8u: goto label_1347d8;
            case 0x1347DCu: goto label_1347dc;
            case 0x1347E0u: goto label_1347e0;
            case 0x1347E4u: goto label_1347e4;
            case 0x1347E8u: goto label_1347e8;
            case 0x1347ECu: goto label_1347ec;
            case 0x1347F0u: goto label_1347f0;
            case 0x1347F4u: goto label_1347f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1347F4u;
label_1347f4:
    // 0x1347f4: 0x0
    ctx->pc = 0x1347f4u;
    // NOP
}
