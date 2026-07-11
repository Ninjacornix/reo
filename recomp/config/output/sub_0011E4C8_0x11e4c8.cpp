#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011E4C8
// Address: 0x11e4c8 - 0x11e7a0
void sub_0011E4C8_0x11e4c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11e4c8u;

label_11e4c8:
    // 0x11e4c8: 0x8c820004
    ctx->pc = 0x11e4c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 4)));
label_11e4cc:
    // 0x11e4cc: 0x10400003
label_11e4d0:
    if (ctx->pc == 0x11E4D0u) {
        ctx->pc = 0x11E4D0u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->pc = 0x11E4D4u;
        goto label_11e4d4;
    }
    ctx->pc = 0x11E4CCu;
    {
        const bool branch_taken_0x11e4cc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E4D0u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
        if (branch_taken_0x11e4cc) {
            ctx->pc = 0x11E4DCu;
            goto label_11e4dc;
        }
    }
    ctx->pc = 0x11E4D4u;
label_11e4d4:
    // 0x11e4d4: 0x10000003
label_11e4d8:
    if (ctx->pc == 0x11E4D8u) {
        ctx->pc = 0x11E4D8u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->pc = 0x11E4DCu;
        goto label_11e4dc;
    }
    ctx->pc = 0x11E4D4u;
    {
        const bool branch_taken_0x11e4d4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E4D8u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        if (branch_taken_0x11e4d4) {
            ctx->pc = 0x11E4E4u;
            goto label_11e4e4;
        }
    }
    ctx->pc = 0x11E4DCu;
label_11e4dc:
    // 0x11e4dc: 0x3c020021
    ctx->pc = 0x11e4dcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
label_11e4e0:
    // 0x11e4e0: 0xac43b400
    ctx->pc = 0x11e4e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294947840), GPR_U32(ctx, 3));
label_11e4e4:
    // 0x11e4e4: 0x50600004
label_11e4e8:
    if (ctx->pc == 0x11E4E8u) {
        ctx->pc = 0x11E4E8u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
        ctx->pc = 0x11E4ECu;
        goto label_11e4ec;
    }
    ctx->pc = 0x11E4E4u;
    {
        const bool branch_taken_0x11e4e4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x11e4e4) {
            ctx->pc = 0x11E4E8u;
            WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
            ctx->pc = 0x11E4F8u;
            goto label_11e4f8;
        }
    }
    ctx->pc = 0x11E4ECu;
label_11e4ec:
    // 0x11e4ec: 0x8c820004
    ctx->pc = 0x11e4ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 4)));
label_11e4f0:
    // 0x11e4f0: 0xac620004
    ctx->pc = 0x11e4f0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
label_11e4f4:
    // 0x11e4f4: 0xac800004
    ctx->pc = 0x11e4f4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
label_11e4f8:
    // 0x11e4f8: 0x3e00008
label_11e4fc:
    if (ctx->pc == 0x11E4FCu) {
        ctx->pc = 0x11E4FCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x11E500u;
        goto label_11e500;
    }
    ctx->pc = 0x11E4F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E4FCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E4C8u: goto label_11e4c8;
            case 0x11E4CCu: goto label_11e4cc;
            case 0x11E4D0u: goto label_11e4d0;
            case 0x11E4D4u: goto label_11e4d4;
            case 0x11E4D8u: goto label_11e4d8;
            case 0x11E4DCu: goto label_11e4dc;
            case 0x11E4E0u: goto label_11e4e0;
            case 0x11E4E4u: goto label_11e4e4;
            case 0x11E4E8u: goto label_11e4e8;
            case 0x11E4ECu: goto label_11e4ec;
            case 0x11E4F0u: goto label_11e4f0;
            case 0x11E4F4u: goto label_11e4f4;
            case 0x11E4F8u: goto label_11e4f8;
            case 0x11E4FCu: goto label_11e4fc;
            case 0x11E500u: goto label_11e500;
            case 0x11E504u: goto label_11e504;
            case 0x11E508u: goto label_11e508;
            case 0x11E50Cu: goto label_11e50c;
            case 0x11E510u: goto label_11e510;
            case 0x11E514u: goto label_11e514;
            case 0x11E518u: goto label_11e518;
            case 0x11E51Cu: goto label_11e51c;
            case 0x11E520u: goto label_11e520;
            case 0x11E524u: goto label_11e524;
            case 0x11E528u: goto label_11e528;
            case 0x11E52Cu: goto label_11e52c;
            case 0x11E530u: goto label_11e530;
            case 0x11E534u: goto label_11e534;
            case 0x11E538u: goto label_11e538;
            case 0x11E53Cu: goto label_11e53c;
            case 0x11E540u: goto label_11e540;
            case 0x11E544u: goto label_11e544;
            case 0x11E548u: goto label_11e548;
            case 0x11E54Cu: goto label_11e54c;
            case 0x11E550u: goto label_11e550;
            case 0x11E554u: goto label_11e554;
            case 0x11E558u: goto label_11e558;
            case 0x11E55Cu: goto label_11e55c;
            case 0x11E560u: goto label_11e560;
            case 0x11E564u: goto label_11e564;
            case 0x11E568u: goto label_11e568;
            case 0x11E56Cu: goto label_11e56c;
            case 0x11E570u: goto label_11e570;
            case 0x11E574u: goto label_11e574;
            case 0x11E578u: goto label_11e578;
            case 0x11E57Cu: goto label_11e57c;
            case 0x11E580u: goto label_11e580;
            case 0x11E584u: goto label_11e584;
            case 0x11E588u: goto label_11e588;
            case 0x11E58Cu: goto label_11e58c;
            case 0x11E590u: goto label_11e590;
            case 0x11E594u: goto label_11e594;
            case 0x11E598u: goto label_11e598;
            case 0x11E59Cu: goto label_11e59c;
            case 0x11E5A0u: goto label_11e5a0;
            case 0x11E5A4u: goto label_11e5a4;
            case 0x11E5A8u: goto label_11e5a8;
            case 0x11E5ACu: goto label_11e5ac;
            case 0x11E5B0u: goto label_11e5b0;
            case 0x11E5B4u: goto label_11e5b4;
            case 0x11E5B8u: goto label_11e5b8;
            case 0x11E5BCu: goto label_11e5bc;
            case 0x11E5C0u: goto label_11e5c0;
            case 0x11E5C4u: goto label_11e5c4;
            case 0x11E5C8u: goto label_11e5c8;
            case 0x11E5CCu: goto label_11e5cc;
            case 0x11E5D0u: goto label_11e5d0;
            case 0x11E5D4u: goto label_11e5d4;
            case 0x11E5D8u: goto label_11e5d8;
            case 0x11E5DCu: goto label_11e5dc;
            case 0x11E5E0u: goto label_11e5e0;
            case 0x11E5E4u: goto label_11e5e4;
            case 0x11E5E8u: goto label_11e5e8;
            case 0x11E5ECu: goto label_11e5ec;
            case 0x11E5F0u: goto label_11e5f0;
            case 0x11E5F4u: goto label_11e5f4;
            case 0x11E5F8u: goto label_11e5f8;
            case 0x11E5FCu: goto label_11e5fc;
            case 0x11E600u: goto label_11e600;
            case 0x11E604u: goto label_11e604;
            case 0x11E608u: goto label_11e608;
            case 0x11E60Cu: goto label_11e60c;
            case 0x11E610u: goto label_11e610;
            case 0x11E614u: goto label_11e614;
            case 0x11E618u: goto label_11e618;
            case 0x11E61Cu: goto label_11e61c;
            case 0x11E620u: goto label_11e620;
            case 0x11E624u: goto label_11e624;
            case 0x11E628u: goto label_11e628;
            case 0x11E62Cu: goto label_11e62c;
            case 0x11E630u: goto label_11e630;
            case 0x11E634u: goto label_11e634;
            case 0x11E638u: goto label_11e638;
            case 0x11E63Cu: goto label_11e63c;
            case 0x11E640u: goto label_11e640;
            case 0x11E644u: goto label_11e644;
            case 0x11E648u: goto label_11e648;
            case 0x11E64Cu: goto label_11e64c;
            case 0x11E650u: goto label_11e650;
            case 0x11E654u: goto label_11e654;
            case 0x11E658u: goto label_11e658;
            case 0x11E65Cu: goto label_11e65c;
            case 0x11E660u: goto label_11e660;
            case 0x11E664u: goto label_11e664;
            case 0x11E668u: goto label_11e668;
            case 0x11E66Cu: goto label_11e66c;
            case 0x11E670u: goto label_11e670;
            case 0x11E674u: goto label_11e674;
            case 0x11E678u: goto label_11e678;
            case 0x11E67Cu: goto label_11e67c;
            case 0x11E680u: goto label_11e680;
            case 0x11E684u: goto label_11e684;
            case 0x11E688u: goto label_11e688;
            case 0x11E68Cu: goto label_11e68c;
            case 0x11E690u: goto label_11e690;
            case 0x11E694u: goto label_11e694;
            case 0x11E698u: goto label_11e698;
            case 0x11E69Cu: goto label_11e69c;
            case 0x11E6A0u: goto label_11e6a0;
            case 0x11E6A4u: goto label_11e6a4;
            case 0x11E6A8u: goto label_11e6a8;
            case 0x11E6ACu: goto label_11e6ac;
            case 0x11E6B0u: goto label_11e6b0;
            case 0x11E6B4u: goto label_11e6b4;
            case 0x11E6B8u: goto label_11e6b8;
            case 0x11E6BCu: goto label_11e6bc;
            case 0x11E6C0u: goto label_11e6c0;
            case 0x11E6C4u: goto label_11e6c4;
            case 0x11E6C8u: goto label_11e6c8;
            case 0x11E6CCu: goto label_11e6cc;
            case 0x11E6D0u: goto label_11e6d0;
            case 0x11E6D4u: goto label_11e6d4;
            case 0x11E6D8u: goto label_11e6d8;
            case 0x11E6DCu: goto label_11e6dc;
            case 0x11E6E0u: goto label_11e6e0;
            case 0x11E6E4u: goto label_11e6e4;
            case 0x11E6E8u: goto label_11e6e8;
            case 0x11E6ECu: goto label_11e6ec;
            case 0x11E6F0u: goto label_11e6f0;
            case 0x11E6F4u: goto label_11e6f4;
            case 0x11E6F8u: goto label_11e6f8;
            case 0x11E6FCu: goto label_11e6fc;
            case 0x11E700u: goto label_11e700;
            case 0x11E704u: goto label_11e704;
            case 0x11E708u: goto label_11e708;
            case 0x11E70Cu: goto label_11e70c;
            case 0x11E710u: goto label_11e710;
            case 0x11E714u: goto label_11e714;
            case 0x11E718u: goto label_11e718;
            case 0x11E71Cu: goto label_11e71c;
            case 0x11E720u: goto label_11e720;
            case 0x11E724u: goto label_11e724;
            case 0x11E728u: goto label_11e728;
            case 0x11E72Cu: goto label_11e72c;
            case 0x11E730u: goto label_11e730;
            case 0x11E734u: goto label_11e734;
            case 0x11E738u: goto label_11e738;
            case 0x11E73Cu: goto label_11e73c;
            case 0x11E740u: goto label_11e740;
            case 0x11E744u: goto label_11e744;
            case 0x11E748u: goto label_11e748;
            case 0x11E74Cu: goto label_11e74c;
            case 0x11E750u: goto label_11e750;
            case 0x11E754u: goto label_11e754;
            case 0x11E758u: goto label_11e758;
            case 0x11E75Cu: goto label_11e75c;
            case 0x11E760u: goto label_11e760;
            case 0x11E764u: goto label_11e764;
            case 0x11E768u: goto label_11e768;
            case 0x11E76Cu: goto label_11e76c;
            case 0x11E770u: goto label_11e770;
            case 0x11E774u: goto label_11e774;
            case 0x11E778u: goto label_11e778;
            case 0x11E77Cu: goto label_11e77c;
            case 0x11E780u: goto label_11e780;
            case 0x11E784u: goto label_11e784;
            case 0x11E788u: goto label_11e788;
            case 0x11E78Cu: goto label_11e78c;
            case 0x11E790u: goto label_11e790;
            case 0x11E794u: goto label_11e794;
            case 0x11E798u: goto label_11e798;
            case 0x11E79Cu: goto label_11e79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E500u;
label_11e500:
    // 0x11e500: 0x27bdff70
    ctx->pc = 0x11e500u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967152));
label_11e504:
    // 0x11e504: 0x3c031000
    ctx->pc = 0x11e504u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_11e508:
    // 0x11e508: 0xffb60060
    ctx->pc = 0x11e508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
label_11e50c:
    // 0x11e50c: 0x34631010
    ctx->pc = 0x11e50cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 4112));
label_11e510:
    // 0x11e510: 0xffbf0080
    ctx->pc = 0x11e510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
label_11e514:
    // 0x11e514: 0xc0b02d
    ctx->pc = 0x11e514u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_11e518:
    // 0x11e518: 0xffb70070
    ctx->pc = 0x11e518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
label_11e51c:
    // 0x11e51c: 0xffb50050
    ctx->pc = 0x11e51cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
label_11e520:
    // 0x11e520: 0xffb40040
    ctx->pc = 0x11e520u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
label_11e524:
    // 0x11e524: 0xffb30030
    ctx->pc = 0x11e524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
label_11e528:
    // 0x11e528: 0xffb20020
    ctx->pc = 0x11e528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
label_11e52c:
    // 0x11e52c: 0xffb10010
    ctx->pc = 0x11e52cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
label_11e530:
    // 0x11e530: 0xffb00000
    ctx->pc = 0x11e530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_11e534:
    // 0x11e534: 0x8c620000
    ctx->pc = 0x11e534u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_11e538:
    // 0x11e538: 0x30420400
    ctx->pc = 0x11e538u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1024));
label_11e53c:
    // 0x11e53c: 0x10400059
label_11e540:
    if (ctx->pc == 0x11E540u) {
        ctx->pc = 0x11E540u;
        SET_GPR_U32(ctx, 21, ((uint32_t)33 << 16));
        ctx->pc = 0x11E544u;
        goto label_11e544;
    }
    ctx->pc = 0x11E53Cu;
    {
        const bool branch_taken_0x11e53c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E540u;
        SET_GPR_U32(ctx, 21, ((uint32_t)33 << 16));
        if (branch_taken_0x11e53c) {
            ctx->pc = 0x11E6A4u;
            goto label_11e6a4;
        }
    }
    ctx->pc = 0x11E544u;
label_11e544:
    // 0x11e544: 0x26a2b3e8
    ctx->pc = 0x11e544u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 21), 4294947816));
label_11e548:
    // 0x11e548: 0x8c500018
    ctx->pc = 0x11e548u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 2), 24)));
label_11e54c:
    // 0x11e54c: 0x12000055
label_11e550:
    if (ctx->pc == 0x11E550u) {
        ctx->pc = 0x11E550u;
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x11E554u;
        goto label_11e554;
    }
    ctx->pc = 0x11E54Cu;
    {
        const bool branch_taken_0x11e54c = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E550u;
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x11e54c) {
            ctx->pc = 0x11E6A4u;
            goto label_11e6a4;
        }
    }
    ctx->pc = 0x11E554u;
label_11e554:
    // 0x11e554: 0x24173999
    ctx->pc = 0x11e554u;
    SET_GPR_S32(ctx, 23, ADD32(GPR_U32(ctx, 0), 14745));
label_11e558:
    // 0x11e558: 0x3c021000
    ctx->pc = 0x11e558u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_11e55c:
    // 0x11e55c: 0x0
    ctx->pc = 0x11e55cu;
    // NOP
label_11e560:
    // 0x11e560: 0x3c031000
    ctx->pc = 0x11e560u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_11e564:
    // 0x11e564: 0x34421000
    ctx->pc = 0x11e564u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 4096));
label_11e568:
    // 0x11e568: 0x34631010
    ctx->pc = 0x11e568u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 4112));
label_11e56c:
    // 0x11e56c: 0x8c460000
    ctx->pc = 0x11e56cu;
    SET_GPR_U32(ctx, 6, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
label_11e570:
    // 0x11e570: 0x8c710000
    ctx->pc = 0x11e570u;
    SET_GPR_U32(ctx, 17, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
label_11e574:
    // 0x11e574: 0xde040020
    ctx->pc = 0x11e574u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 32)));
label_11e578:
    // 0x11e578: 0xde020010
    ctx->pc = 0x11e578u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 16)));
label_11e57c:
    // 0x11e57c: 0x32250800
    ctx->pc = 0x11e57cu;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 17), 2048));
label_11e580:
    // 0x11e580: 0xde030018
    ctx->pc = 0x11e580u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 24)));
label_11e584:
    // 0x11e584: 0x82202d
    ctx->pc = 0x11e584u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 2));
label_11e588:
    // 0x11e588: 0x10a0000b
label_11e58c:
    if (ctx->pc == 0x11E58Cu) {
        ctx->pc = 0x11E58Cu;
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 4) - GPR_U64(ctx, 3));
        ctx->pc = 0x11E590u;
        goto label_11e590;
    }
    ctx->pc = 0x11E588u;
    {
        const bool branch_taken_0x11e588 = (GPR_U32(ctx, 5) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E58Cu;
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 4) - GPR_U64(ctx, 3));
        if (branch_taken_0x11e588) {
            ctx->pc = 0x11E5B8u;
            goto label_11e5b8;
        }
    }
    ctx->pc = 0x11E590u;
label_11e590:
    // 0x11e590: 0xde82b3e8
    ctx->pc = 0x11e590u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 20), 4294947816)));
label_11e594:
    // 0x11e594: 0x3c04ffff
    ctx->pc = 0x11e594u;
    SET_GPR_U32(ctx, 4, ((uint32_t)65535 << 16));
label_11e598:
    // 0x11e598: 0x3484fbff
    ctx->pc = 0x11e598u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 64511));
label_11e59c:
    // 0x11e59c: 0x64420001
    ctx->pc = 0x11e59cu;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)1);
label_11e5a0:
    // 0x11e5a0: 0x2242024
    ctx->pc = 0x11e5a0u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
label_11e5a4:
    // 0x11e5a4: 0xfe82b3e8
    ctx->pc = 0x11e5a4u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 4294947816), GPR_U64(ctx, 2));
label_11e5a8:
    // 0x11e5a8: 0xc0477d0
label_11e5ac:
    if (ctx->pc == 0x11E5ACu) {
        ctx->pc = 0x11E5B0u;
        goto label_11e5b0;
    }
    ctx->pc = 0x11E5A8u;
    SET_GPR_U32(ctx, 31, 0x11E5B0u);
    ctx->pc = 0x11DF40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E5B0u; }
    }
    if (ctx->pc != 0x11E5B0u) { return; }
    ctx->pc = 0x11E5B0u;
label_11e5b0:
    // 0x11e5b0: 0x3c061000
    ctx->pc = 0x11e5b0u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
label_11e5b4:
    // 0x11e5b4: 0x8cc61000
    ctx->pc = 0x11e5b4u;
    SET_GPR_U32(ctx, 6, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 4096))); // MMIO: 0x10001000
label_11e5b8:
    // 0x11e5b8: 0xde84b3e8
    ctx->pc = 0x11e5b8u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 20), 4294947816)));
label_11e5bc:
    // 0x11e5bc: 0x6103c
    ctx->pc = 0x11e5bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
label_11e5c0:
    // 0x11e5c0: 0x2103e
    ctx->pc = 0x11e5c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
label_11e5c4:
    // 0x11e5c4: 0x32230003
    ctx->pc = 0x11e5c4u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 17), 3));
label_11e5c8:
    // 0x11e5c8: 0x42438
    ctx->pc = 0x11e5c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
label_11e5cc:
    // 0x11e5cc: 0x31880
    ctx->pc = 0x11e5ccu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
label_11e5d0:
    // 0x11e5d0: 0x822025
    ctx->pc = 0x11e5d0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_11e5d4:
    // 0x11e5d4: 0x648814
    ctx->pc = 0x11e5d4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 4) << (GPR_U32(ctx, 3) & 0x3F));
label_11e5d8:
    // 0x11e5d8: 0x232102b
    ctx->pc = 0x11e5d8u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 17), GPR_U32(ctx, 18)));
label_11e5dc:
    // 0x11e5dc: 0x14400031
label_11e5e0:
    if (ctx->pc == 0x11E5E0u) {
        ctx->pc = 0x11E5E0u;
        SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 20), 4294947816));
        ctx->pc = 0x11E5E4u;
        goto label_11e5e4;
    }
    ctx->pc = 0x11E5DCu;
    {
        const bool branch_taken_0x11e5dc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x11E5E0u;
        SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 20), 4294947816));
        if (branch_taken_0x11e5dc) {
            ctx->pc = 0x11E6A4u;
            goto label_11e6a4;
        }
    }
    ctx->pc = 0x11E5E4u;
label_11e5e4:
    // 0x11e5e4: 0xc047932
label_11e5e8:
    if (ctx->pc == 0x11E5E8u) {
        ctx->pc = 0x11E5E8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x11E5ECu;
        goto label_11e5ec;
    }
    ctx->pc = 0x11E5E4u;
    SET_GPR_U32(ctx, 31, 0x11E5ECu);
    ctx->pc = 0x11E5E8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11E4C8u;
    goto label_11e4c8;
    ctx->pc = 0x11E5ECu;
label_11e5ec:
    // 0x11e5ec: 0x40902d
    ctx->pc = 0x11e5ecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_11e5f0:
    // 0x11e5f0: 0xde060018
    ctx->pc = 0x11e5f0u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 16), 24)));
label_11e5f4:
    // 0x11e5f4: 0x8e020008
    ctx->pc = 0x11e5f4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_11e5f8:
    // 0x11e5f8: 0x103900
    ctx->pc = 0x11e5f8u;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 16), 4));
label_11e5fc:
    // 0x11e5fc: 0xde030010
    ctx->pc = 0x11e5fcu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 16)));
label_11e600:
    // 0x11e600: 0x226302d
    ctx->pc = 0x11e600u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 6));
label_11e604:
    // 0x11e604: 0xe21025
    ctx->pc = 0x11e604u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
label_11e608:
    // 0x11e608: 0xae62001c
    ctx->pc = 0x11e608u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
label_11e60c:
    // 0x11e60c: 0xc3302f
    ctx->pc = 0x11e60cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) - GPR_U64(ctx, 3));
label_11e610:
    // 0x11e610: 0x8e1c002c
    ctx->pc = 0x11e610u;
    SET_GPR_U32(ctx, 28, READ32(ADD32(GPR_U32(ctx, 16), 44)));
label_11e614:
    // 0x11e614: 0x8e040008
    ctx->pc = 0x11e614u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_11e618:
    // 0x11e618: 0x2c0402d
    ctx->pc = 0x11e618u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
label_11e61c:
    // 0x11e61c: 0x8e020028
    ctx->pc = 0x11e61cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 40)));
label_11e620:
    // 0x11e620: 0xe42025
    ctx->pc = 0x11e620u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
label_11e624:
    // 0x11e624: 0xde050020
    ctx->pc = 0x11e624u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 32)));
label_11e628:
    // 0x11e628: 0x40f809
label_11e62c:
    if (ctx->pc == 0x11E62Cu) {
        ctx->pc = 0x11E62Cu;
        SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 16), 48)));
        ctx->pc = 0x11E630u;
        goto label_11e630;
    }
    ctx->pc = 0x11E628u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x11E630u);
        ctx->pc = 0x11E62Cu;
        SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 16), 48)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E4C8u: goto label_11e4c8;
            case 0x11E4CCu: goto label_11e4cc;
            case 0x11E4D0u: goto label_11e4d0;
            case 0x11E4D4u: goto label_11e4d4;
            case 0x11E4D8u: goto label_11e4d8;
            case 0x11E4DCu: goto label_11e4dc;
            case 0x11E4E0u: goto label_11e4e0;
            case 0x11E4E4u: goto label_11e4e4;
            case 0x11E4E8u: goto label_11e4e8;
            case 0x11E4ECu: goto label_11e4ec;
            case 0x11E4F0u: goto label_11e4f0;
            case 0x11E4F4u: goto label_11e4f4;
            case 0x11E4F8u: goto label_11e4f8;
            case 0x11E4FCu: goto label_11e4fc;
            case 0x11E500u: goto label_11e500;
            case 0x11E504u: goto label_11e504;
            case 0x11E508u: goto label_11e508;
            case 0x11E50Cu: goto label_11e50c;
            case 0x11E510u: goto label_11e510;
            case 0x11E514u: goto label_11e514;
            case 0x11E518u: goto label_11e518;
            case 0x11E51Cu: goto label_11e51c;
            case 0x11E520u: goto label_11e520;
            case 0x11E524u: goto label_11e524;
            case 0x11E528u: goto label_11e528;
            case 0x11E52Cu: goto label_11e52c;
            case 0x11E530u: goto label_11e530;
            case 0x11E534u: goto label_11e534;
            case 0x11E538u: goto label_11e538;
            case 0x11E53Cu: goto label_11e53c;
            case 0x11E540u: goto label_11e540;
            case 0x11E544u: goto label_11e544;
            case 0x11E548u: goto label_11e548;
            case 0x11E54Cu: goto label_11e54c;
            case 0x11E550u: goto label_11e550;
            case 0x11E554u: goto label_11e554;
            case 0x11E558u: goto label_11e558;
            case 0x11E55Cu: goto label_11e55c;
            case 0x11E560u: goto label_11e560;
            case 0x11E564u: goto label_11e564;
            case 0x11E568u: goto label_11e568;
            case 0x11E56Cu: goto label_11e56c;
            case 0x11E570u: goto label_11e570;
            case 0x11E574u: goto label_11e574;
            case 0x11E578u: goto label_11e578;
            case 0x11E57Cu: goto label_11e57c;
            case 0x11E580u: goto label_11e580;
            case 0x11E584u: goto label_11e584;
            case 0x11E588u: goto label_11e588;
            case 0x11E58Cu: goto label_11e58c;
            case 0x11E590u: goto label_11e590;
            case 0x11E594u: goto label_11e594;
            case 0x11E598u: goto label_11e598;
            case 0x11E59Cu: goto label_11e59c;
            case 0x11E5A0u: goto label_11e5a0;
            case 0x11E5A4u: goto label_11e5a4;
            case 0x11E5A8u: goto label_11e5a8;
            case 0x11E5ACu: goto label_11e5ac;
            case 0x11E5B0u: goto label_11e5b0;
            case 0x11E5B4u: goto label_11e5b4;
            case 0x11E5B8u: goto label_11e5b8;
            case 0x11E5BCu: goto label_11e5bc;
            case 0x11E5C0u: goto label_11e5c0;
            case 0x11E5C4u: goto label_11e5c4;
            case 0x11E5C8u: goto label_11e5c8;
            case 0x11E5CCu: goto label_11e5cc;
            case 0x11E5D0u: goto label_11e5d0;
            case 0x11E5D4u: goto label_11e5d4;
            case 0x11E5D8u: goto label_11e5d8;
            case 0x11E5DCu: goto label_11e5dc;
            case 0x11E5E0u: goto label_11e5e0;
            case 0x11E5E4u: goto label_11e5e4;
            case 0x11E5E8u: goto label_11e5e8;
            case 0x11E5ECu: goto label_11e5ec;
            case 0x11E5F0u: goto label_11e5f0;
            case 0x11E5F4u: goto label_11e5f4;
            case 0x11E5F8u: goto label_11e5f8;
            case 0x11E5FCu: goto label_11e5fc;
            case 0x11E600u: goto label_11e600;
            case 0x11E604u: goto label_11e604;
            case 0x11E608u: goto label_11e608;
            case 0x11E60Cu: goto label_11e60c;
            case 0x11E610u: goto label_11e610;
            case 0x11E614u: goto label_11e614;
            case 0x11E618u: goto label_11e618;
            case 0x11E61Cu: goto label_11e61c;
            case 0x11E620u: goto label_11e620;
            case 0x11E624u: goto label_11e624;
            case 0x11E628u: goto label_11e628;
            case 0x11E62Cu: goto label_11e62c;
            case 0x11E630u: goto label_11e630;
            case 0x11E634u: goto label_11e634;
            case 0x11E638u: goto label_11e638;
            case 0x11E63Cu: goto label_11e63c;
            case 0x11E640u: goto label_11e640;
            case 0x11E644u: goto label_11e644;
            case 0x11E648u: goto label_11e648;
            case 0x11E64Cu: goto label_11e64c;
            case 0x11E650u: goto label_11e650;
            case 0x11E654u: goto label_11e654;
            case 0x11E658u: goto label_11e658;
            case 0x11E65Cu: goto label_11e65c;
            case 0x11E660u: goto label_11e660;
            case 0x11E664u: goto label_11e664;
            case 0x11E668u: goto label_11e668;
            case 0x11E66Cu: goto label_11e66c;
            case 0x11E670u: goto label_11e670;
            case 0x11E674u: goto label_11e674;
            case 0x11E678u: goto label_11e678;
            case 0x11E67Cu: goto label_11e67c;
            case 0x11E680u: goto label_11e680;
            case 0x11E684u: goto label_11e684;
            case 0x11E688u: goto label_11e688;
            case 0x11E68Cu: goto label_11e68c;
            case 0x11E690u: goto label_11e690;
            case 0x11E694u: goto label_11e694;
            case 0x11E698u: goto label_11e698;
            case 0x11E69Cu: goto label_11e69c;
            case 0x11E6A0u: goto label_11e6a0;
            case 0x11E6A4u: goto label_11e6a4;
            case 0x11E6A8u: goto label_11e6a8;
            case 0x11E6ACu: goto label_11e6ac;
            case 0x11E6B0u: goto label_11e6b0;
            case 0x11E6B4u: goto label_11e6b4;
            case 0x11E6B8u: goto label_11e6b8;
            case 0x11E6BCu: goto label_11e6bc;
            case 0x11E6C0u: goto label_11e6c0;
            case 0x11E6C4u: goto label_11e6c4;
            case 0x11E6C8u: goto label_11e6c8;
            case 0x11E6CCu: goto label_11e6cc;
            case 0x11E6D0u: goto label_11e6d0;
            case 0x11E6D4u: goto label_11e6d4;
            case 0x11E6D8u: goto label_11e6d8;
            case 0x11E6DCu: goto label_11e6dc;
            case 0x11E6E0u: goto label_11e6e0;
            case 0x11E6E4u: goto label_11e6e4;
            case 0x11E6E8u: goto label_11e6e8;
            case 0x11E6ECu: goto label_11e6ec;
            case 0x11E6F0u: goto label_11e6f0;
            case 0x11E6F4u: goto label_11e6f4;
            case 0x11E6F8u: goto label_11e6f8;
            case 0x11E6FCu: goto label_11e6fc;
            case 0x11E700u: goto label_11e700;
            case 0x11E704u: goto label_11e704;
            case 0x11E708u: goto label_11e708;
            case 0x11E70Cu: goto label_11e70c;
            case 0x11E710u: goto label_11e710;
            case 0x11E714u: goto label_11e714;
            case 0x11E718u: goto label_11e718;
            case 0x11E71Cu: goto label_11e71c;
            case 0x11E720u: goto label_11e720;
            case 0x11E724u: goto label_11e724;
            case 0x11E728u: goto label_11e728;
            case 0x11E72Cu: goto label_11e72c;
            case 0x11E730u: goto label_11e730;
            case 0x11E734u: goto label_11e734;
            case 0x11E738u: goto label_11e738;
            case 0x11E73Cu: goto label_11e73c;
            case 0x11E740u: goto label_11e740;
            case 0x11E744u: goto label_11e744;
            case 0x11E748u: goto label_11e748;
            case 0x11E74Cu: goto label_11e74c;
            case 0x11E750u: goto label_11e750;
            case 0x11E754u: goto label_11e754;
            case 0x11E758u: goto label_11e758;
            case 0x11E75Cu: goto label_11e75c;
            case 0x11E760u: goto label_11e760;
            case 0x11E764u: goto label_11e764;
            case 0x11E768u: goto label_11e768;
            case 0x11E76Cu: goto label_11e76c;
            case 0x11E770u: goto label_11e770;
            case 0x11E774u: goto label_11e774;
            case 0x11E778u: goto label_11e778;
            case 0x11E77Cu: goto label_11e77c;
            case 0x11E780u: goto label_11e780;
            case 0x11E784u: goto label_11e784;
            case 0x11E788u: goto label_11e788;
            case 0x11E78Cu: goto label_11e78c;
            case 0x11E790u: goto label_11e790;
            case 0x11E794u: goto label_11e794;
            case 0x11E798u: goto label_11e798;
            case 0x11E79Cu: goto label_11e79c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11E630u; }
            if (ctx->pc != 0x11E630u) { return; }
        }
    }
    ctx->pc = 0x11E630u;
label_11e630:
    // 0x11e630: 0x40282d
    ctx->pc = 0x11e630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_11e634:
    // 0x11e634: 0x14a00007
label_11e638:
    if (ctx->pc == 0x11E638u) {
        ctx->pc = 0x11E638u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x11E63Cu;
        goto label_11e63c;
    }
    ctx->pc = 0x11E634u;
    {
        const bool branch_taken_0x11e634 = (GPR_U32(ctx, 5) != GPR_U32(ctx, 0));
        ctx->pc = 0x11E638u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x11e634) {
            ctx->pc = 0x11E654u;
            goto label_11e654;
        }
    }
    ctx->pc = 0x11E63Cu;
label_11e63c:
    // 0x11e63c: 0x8e03000c
    ctx->pc = 0x11e63cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_11e640:
    // 0x11e640: 0x3c02ffff
    ctx->pc = 0x11e640u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65535 << 16));
label_11e644:
    // 0x11e644: 0x3442fffd
    ctx->pc = 0x11e644u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65533));
label_11e648:
    // 0x11e648: 0x621824
    ctx->pc = 0x11e648u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_11e64c:
    // 0x11e64c: 0x10000010
label_11e650:
    if (ctx->pc == 0x11E650u) {
        ctx->pc = 0x11E650u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        ctx->pc = 0x11E654u;
        goto label_11e654;
    }
    ctx->pc = 0x11E64Cu;
    {
        const bool branch_taken_0x11e64c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E650u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        if (branch_taken_0x11e64c) {
            ctx->pc = 0x11E690u;
            goto label_11e690;
        }
    }
    ctx->pc = 0x11E654u;
label_11e654:
    // 0x11e654: 0x14a20007
label_11e658:
    if (ctx->pc == 0x11E658u) {
        ctx->pc = 0x11E658u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14744));
        ctx->pc = 0x11E65Cu;
        goto label_11e65c;
    }
    ctx->pc = 0x11E654u;
    {
        const bool branch_taken_0x11e654 = (GPR_U32(ctx, 5) != GPR_U32(ctx, 2));
        ctx->pc = 0x11E658u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14744));
        if (branch_taken_0x11e654) {
            ctx->pc = 0x11E674u;
            goto label_11e674;
        }
    }
    ctx->pc = 0x11E65Cu;
label_11e65c:
    // 0x11e65c: 0x8e620014
    ctx->pc = 0x11e65cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 19), 20)));
label_11e660:
    // 0x11e660: 0xae700014
    ctx->pc = 0x11e660u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 16));
label_11e664:
    // 0x11e664: 0xae020000
    ctx->pc = 0x11e664u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_11e668:
    // 0x11e668: 0xae000008
    ctx->pc = 0x11e668u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
label_11e66c:
    // 0x11e66c: 0x10000008
label_11e670:
    if (ctx->pc == 0x11E670u) {
        ctx->pc = 0x11E670u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
        ctx->pc = 0x11E674u;
        goto label_11e674;
    }
    ctx->pc = 0x11E66Cu;
    {
        const bool branch_taken_0x11e66c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E670u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
        if (branch_taken_0x11e66c) {
            ctx->pc = 0x11E690u;
            goto label_11e690;
        }
    }
    ctx->pc = 0x11E674u;
label_11e674:
    // 0x11e674: 0xde030020
    ctx->pc = 0x11e674u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 32)));
label_11e678:
    // 0x11e678: 0x45102b
    ctx->pc = 0x11e678u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_11e67c:
    // 0x11e67c: 0x200202d
    ctx->pc = 0x11e67cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_11e680:
    // 0x11e680: 0x2e2280a
    ctx->pc = 0x11e680u;
    if (GPR_U32(ctx, 2) == 0) SET_GPR_U32(ctx, 5, GPR_U32(ctx, 23));
label_11e684:
    // 0x11e684: 0x65182d
    ctx->pc = 0x11e684u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 5));
label_11e688:
    // 0x11e688: 0xc047910
label_11e68c:
    if (ctx->pc == 0x11E68Cu) {
        ctx->pc = 0x11E68Cu;
        WRITE64(ADD32(GPR_U32(ctx, 16), 32), GPR_U64(ctx, 3));
        ctx->pc = 0x11E690u;
        goto label_11e690;
    }
    ctx->pc = 0x11E688u;
    SET_GPR_U32(ctx, 31, 0x11E690u);
    ctx->pc = 0x11E68Cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 32), GPR_U64(ctx, 3));
    ctx->pc = 0x11E440u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E440_0x11e440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E690u; }
    }
    if (ctx->pc != 0x11E690u) { return; }
    ctx->pc = 0x11E690u;
label_11e690:
    // 0x11e690: 0x240802d
    ctx->pc = 0x11e690u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_11e694:
    // 0x11e694: 0x1600ffb2
label_11e698:
    if (ctx->pc == 0x11E698u) {
        ctx->pc = 0x11E698u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        ctx->pc = 0x11E69Cu;
        goto label_11e69c;
    }
    ctx->pc = 0x11E694u;
    {
        const bool branch_taken_0x11e694 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x11E698u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x11e694) {
            ctx->pc = 0x11E560u;
            goto label_11e560;
        }
    }
    ctx->pc = 0x11E69Cu;
label_11e69c:
    // 0x11e69c: 0x10000002
label_11e6a0:
    if (ctx->pc == 0x11E6A0u) {
        ctx->pc = 0x11E6A0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 21), 4294947816));
        ctx->pc = 0x11E6A4u;
        goto label_11e6a4;
    }
    ctx->pc = 0x11E69Cu;
    {
        const bool branch_taken_0x11e69c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E6A0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 21), 4294947816));
        if (branch_taken_0x11e69c) {
            ctx->pc = 0x11E6A8u;
            goto label_11e6a8;
        }
    }
    ctx->pc = 0x11E6A4u;
label_11e6a4:
    // 0x11e6a4: 0x26a4b3e8
    ctx->pc = 0x11e6a4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 21), 4294947816));
label_11e6a8:
    // 0x11e6a8: 0x2403ffff
    ctx->pc = 0x11e6a8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_11e6ac:
    // 0x11e6ac: 0xac83001c
    ctx->pc = 0x11e6acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
label_11e6b0:
    // 0x11e6b0: 0x3c021000
    ctx->pc = 0x11e6b0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_11e6b4:
    // 0x11e6b4: 0x34421000
    ctx->pc = 0x11e6b4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 4096));
label_11e6b8:
    // 0x11e6b8: 0x3c031000
    ctx->pc = 0x11e6b8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_11e6bc:
    // 0x11e6bc: 0x8c440000
    ctx->pc = 0x11e6bcu;
    SET_GPR_U32(ctx, 4, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
label_11e6c0:
    // 0x11e6c0: 0x34631010
    ctx->pc = 0x11e6c0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 4112));
label_11e6c4:
    // 0x11e6c4: 0x8c700000
    ctx->pc = 0x11e6c4u;
    SET_GPR_U32(ctx, 16, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
label_11e6c8:
    // 0x11e6c8: 0x32020800
    ctx->pc = 0x11e6c8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 16), 2048));
label_11e6cc:
    // 0x11e6cc: 0x1040000b
label_11e6d0:
    if (ctx->pc == 0x11E6D0u) {
        ctx->pc = 0x11E6D4u;
        goto label_11e6d4;
    }
    ctx->pc = 0x11E6CCu;
    {
        const bool branch_taken_0x11e6cc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x11e6cc) {
            ctx->pc = 0x11E6FCu;
            goto label_11e6fc;
        }
    }
    ctx->pc = 0x11E6D4u;
label_11e6d4:
    // 0x11e6d4: 0xdea2b3e8
    ctx->pc = 0x11e6d4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 4294947816)));
label_11e6d8:
    // 0x11e6d8: 0x3c04ffff
    ctx->pc = 0x11e6d8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)65535 << 16));
label_11e6dc:
    // 0x11e6dc: 0x3484fbff
    ctx->pc = 0x11e6dcu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 64511));
label_11e6e0:
    // 0x11e6e0: 0x64420001
    ctx->pc = 0x11e6e0u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)1);
label_11e6e4:
    // 0x11e6e4: 0x2042024
    ctx->pc = 0x11e6e4u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_11e6e8:
    // 0x11e6e8: 0xfea2b3e8
    ctx->pc = 0x11e6e8u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 4294947816), GPR_U64(ctx, 2));
label_11e6ec:
    // 0x11e6ec: 0xc0477d0
label_11e6f0:
    if (ctx->pc == 0x11E6F0u) {
        ctx->pc = 0x11E6F4u;
        goto label_11e6f4;
    }
    ctx->pc = 0x11E6ECu;
    SET_GPR_U32(ctx, 31, 0x11E6F4u);
    ctx->pc = 0x11DF40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E6F4u; }
    }
    if (ctx->pc != 0x11E6F4u) { return; }
    ctx->pc = 0x11E6F4u;
label_11e6f4:
    // 0x11e6f4: 0x3c041000
    ctx->pc = 0x11e6f4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
label_11e6f8:
    // 0x11e6f8: 0x8c841000
    ctx->pc = 0x11e6f8u;
    SET_GPR_U32(ctx, 4, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 4096))); // MMIO: 0x10001000
label_11e6fc:
    // 0x11e6fc: 0xdea2b3e8
    ctx->pc = 0x11e6fcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 4294947816)));
label_11e700:
    // 0x11e700: 0x4183c
    ctx->pc = 0x11e700u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
label_11e704:
    // 0x11e704: 0x3183e
    ctx->pc = 0x11e704u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
label_11e708:
    // 0x11e708: 0x32040003
    ctx->pc = 0x11e708u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 16), 3));
label_11e70c:
    // 0x11e70c: 0x21438
    ctx->pc = 0x11e70cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
label_11e710:
    // 0x11e710: 0x42080
    ctx->pc = 0x11e710u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 2));
label_11e714:
    // 0x11e714: 0x431025
    ctx->pc = 0x11e714u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_11e718:
    // 0x11e718: 0xc0478ac
label_11e71c:
    if (ctx->pc == 0x11E71Cu) {
        ctx->pc = 0x11E71Cu;
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (GPR_U32(ctx, 4) & 0x3F));
        ctx->pc = 0x11E720u;
        goto label_11e720;
    }
    ctx->pc = 0x11E718u;
    SET_GPR_U32(ctx, 31, 0x11E720u);
    ctx->pc = 0x11E71Cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (GPR_U32(ctx, 4) & 0x3F));
    ctx->pc = 0x11E2B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E2B0_0x11e2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E720u; }
    }
    if (ctx->pc != 0x11E720u) { return; }
    ctx->pc = 0x11E720u;
label_11e720:
    // 0x11e720: 0x3c021000
    ctx->pc = 0x11e720u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_11e724:
    // 0x11e724: 0x8c421000
    ctx->pc = 0x11e724u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 4096))); // MMIO: 0x10001000
label_11e728:
    // 0x11e728: 0x3c031000
    ctx->pc = 0x11e728u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_11e72c:
    // 0x11e72c: 0x8c631010
    ctx->pc = 0x11e72cu;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 4112))); // MMIO: 0x10001010
label_11e730:
    // 0x11e730: 0x30620800
    ctx->pc = 0x11e730u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 2048));
label_11e734:
    // 0x11e734: 0x1040000b
label_11e738:
    if (ctx->pc == 0x11E738u) {
        ctx->pc = 0x11E73Cu;
        goto label_11e73c;
    }
    ctx->pc = 0x11E734u;
    {
        const bool branch_taken_0x11e734 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x11e734) {
            ctx->pc = 0x11E764u;
            goto label_11e764;
        }
    }
    ctx->pc = 0x11E73Cu;
label_11e73c:
    // 0x11e73c: 0xdea2b3e8
    ctx->pc = 0x11e73cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 4294947816)));
label_11e740:
    // 0x11e740: 0x3c04ffff
    ctx->pc = 0x11e740u;
    SET_GPR_U32(ctx, 4, ((uint32_t)65535 << 16));
label_11e744:
    // 0x11e744: 0x3484fbff
    ctx->pc = 0x11e744u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 64511));
label_11e748:
    // 0x11e748: 0x64420001
    ctx->pc = 0x11e748u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)1);
label_11e74c:
    // 0x11e74c: 0x642024
    ctx->pc = 0x11e74cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_11e750:
    // 0x11e750: 0xfea2b3e8
    ctx->pc = 0x11e750u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 4294947816), GPR_U64(ctx, 2));
label_11e754:
    // 0x11e754: 0xc0477d0
label_11e758:
    if (ctx->pc == 0x11E758u) {
        ctx->pc = 0x11E75Cu;
        goto label_11e75c;
    }
    ctx->pc = 0x11E754u;
    SET_GPR_U32(ctx, 31, 0x11E75Cu);
    ctx->pc = 0x11DF40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E75Cu; }
    }
    if (ctx->pc != 0x11E75Cu) { return; }
    ctx->pc = 0x11E75Cu;
label_11e75c:
    // 0x11e75c: 0x3c021000
    ctx->pc = 0x11e75cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_11e760:
    // 0x11e760: 0x8c421000
    ctx->pc = 0x11e760u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 4096))); // MMIO: 0x10001000
label_11e764:
    // 0x11e764: 0xdea2b3e8
    ctx->pc = 0x11e764u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 4294947816)));
label_11e768:
    // 0x11e768: 0xf
    ctx->pc = 0x11e768u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
label_11e76c:
    // 0x11e76c: 0x42000038
    ctx->pc = 0x11e76cu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
label_11e770:
    // 0x11e770: 0xdfbf0080
    ctx->pc = 0x11e770u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
label_11e774:
    // 0x11e774: 0x102d
    ctx->pc = 0x11e774u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11e778:
    // 0x11e778: 0xdfb70070
    ctx->pc = 0x11e778u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_11e77c:
    // 0x11e77c: 0xdfb60060
    ctx->pc = 0x11e77cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_11e780:
    // 0x11e780: 0xdfb50050
    ctx->pc = 0x11e780u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_11e784:
    // 0x11e784: 0xdfb40040
    ctx->pc = 0x11e784u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_11e788:
    // 0x11e788: 0xdfb30030
    ctx->pc = 0x11e788u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_11e78c:
    // 0x11e78c: 0xdfb20020
    ctx->pc = 0x11e78cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_11e790:
    // 0x11e790: 0xdfb10010
    ctx->pc = 0x11e790u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_11e794:
    // 0x11e794: 0xdfb00000
    ctx->pc = 0x11e794u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_11e798:
    // 0x11e798: 0x3e00008
label_11e79c:
    if (ctx->pc == 0x11E79Cu) {
        ctx->pc = 0x11E79Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 144));
        ctx->pc = 0x11E7A0u;
        goto label_fallthrough_0x11e798;
    }
    ctx->pc = 0x11E798u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E79Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 144));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E4C8u: goto label_11e4c8;
            case 0x11E4CCu: goto label_11e4cc;
            case 0x11E4D0u: goto label_11e4d0;
            case 0x11E4D4u: goto label_11e4d4;
            case 0x11E4D8u: goto label_11e4d8;
            case 0x11E4DCu: goto label_11e4dc;
            case 0x11E4E0u: goto label_11e4e0;
            case 0x11E4E4u: goto label_11e4e4;
            case 0x11E4E8u: goto label_11e4e8;
            case 0x11E4ECu: goto label_11e4ec;
            case 0x11E4F0u: goto label_11e4f0;
            case 0x11E4F4u: goto label_11e4f4;
            case 0x11E4F8u: goto label_11e4f8;
            case 0x11E4FCu: goto label_11e4fc;
            case 0x11E500u: goto label_11e500;
            case 0x11E504u: goto label_11e504;
            case 0x11E508u: goto label_11e508;
            case 0x11E50Cu: goto label_11e50c;
            case 0x11E510u: goto label_11e510;
            case 0x11E514u: goto label_11e514;
            case 0x11E518u: goto label_11e518;
            case 0x11E51Cu: goto label_11e51c;
            case 0x11E520u: goto label_11e520;
            case 0x11E524u: goto label_11e524;
            case 0x11E528u: goto label_11e528;
            case 0x11E52Cu: goto label_11e52c;
            case 0x11E530u: goto label_11e530;
            case 0x11E534u: goto label_11e534;
            case 0x11E538u: goto label_11e538;
            case 0x11E53Cu: goto label_11e53c;
            case 0x11E540u: goto label_11e540;
            case 0x11E544u: goto label_11e544;
            case 0x11E548u: goto label_11e548;
            case 0x11E54Cu: goto label_11e54c;
            case 0x11E550u: goto label_11e550;
            case 0x11E554u: goto label_11e554;
            case 0x11E558u: goto label_11e558;
            case 0x11E55Cu: goto label_11e55c;
            case 0x11E560u: goto label_11e560;
            case 0x11E564u: goto label_11e564;
            case 0x11E568u: goto label_11e568;
            case 0x11E56Cu: goto label_11e56c;
            case 0x11E570u: goto label_11e570;
            case 0x11E574u: goto label_11e574;
            case 0x11E578u: goto label_11e578;
            case 0x11E57Cu: goto label_11e57c;
            case 0x11E580u: goto label_11e580;
            case 0x11E584u: goto label_11e584;
            case 0x11E588u: goto label_11e588;
            case 0x11E58Cu: goto label_11e58c;
            case 0x11E590u: goto label_11e590;
            case 0x11E594u: goto label_11e594;
            case 0x11E598u: goto label_11e598;
            case 0x11E59Cu: goto label_11e59c;
            case 0x11E5A0u: goto label_11e5a0;
            case 0x11E5A4u: goto label_11e5a4;
            case 0x11E5A8u: goto label_11e5a8;
            case 0x11E5ACu: goto label_11e5ac;
            case 0x11E5B0u: goto label_11e5b0;
            case 0x11E5B4u: goto label_11e5b4;
            case 0x11E5B8u: goto label_11e5b8;
            case 0x11E5BCu: goto label_11e5bc;
            case 0x11E5C0u: goto label_11e5c0;
            case 0x11E5C4u: goto label_11e5c4;
            case 0x11E5C8u: goto label_11e5c8;
            case 0x11E5CCu: goto label_11e5cc;
            case 0x11E5D0u: goto label_11e5d0;
            case 0x11E5D4u: goto label_11e5d4;
            case 0x11E5D8u: goto label_11e5d8;
            case 0x11E5DCu: goto label_11e5dc;
            case 0x11E5E0u: goto label_11e5e0;
            case 0x11E5E4u: goto label_11e5e4;
            case 0x11E5E8u: goto label_11e5e8;
            case 0x11E5ECu: goto label_11e5ec;
            case 0x11E5F0u: goto label_11e5f0;
            case 0x11E5F4u: goto label_11e5f4;
            case 0x11E5F8u: goto label_11e5f8;
            case 0x11E5FCu: goto label_11e5fc;
            case 0x11E600u: goto label_11e600;
            case 0x11E604u: goto label_11e604;
            case 0x11E608u: goto label_11e608;
            case 0x11E60Cu: goto label_11e60c;
            case 0x11E610u: goto label_11e610;
            case 0x11E614u: goto label_11e614;
            case 0x11E618u: goto label_11e618;
            case 0x11E61Cu: goto label_11e61c;
            case 0x11E620u: goto label_11e620;
            case 0x11E624u: goto label_11e624;
            case 0x11E628u: goto label_11e628;
            case 0x11E62Cu: goto label_11e62c;
            case 0x11E630u: goto label_11e630;
            case 0x11E634u: goto label_11e634;
            case 0x11E638u: goto label_11e638;
            case 0x11E63Cu: goto label_11e63c;
            case 0x11E640u: goto label_11e640;
            case 0x11E644u: goto label_11e644;
            case 0x11E648u: goto label_11e648;
            case 0x11E64Cu: goto label_11e64c;
            case 0x11E650u: goto label_11e650;
            case 0x11E654u: goto label_11e654;
            case 0x11E658u: goto label_11e658;
            case 0x11E65Cu: goto label_11e65c;
            case 0x11E660u: goto label_11e660;
            case 0x11E664u: goto label_11e664;
            case 0x11E668u: goto label_11e668;
            case 0x11E66Cu: goto label_11e66c;
            case 0x11E670u: goto label_11e670;
            case 0x11E674u: goto label_11e674;
            case 0x11E678u: goto label_11e678;
            case 0x11E67Cu: goto label_11e67c;
            case 0x11E680u: goto label_11e680;
            case 0x11E684u: goto label_11e684;
            case 0x11E688u: goto label_11e688;
            case 0x11E68Cu: goto label_11e68c;
            case 0x11E690u: goto label_11e690;
            case 0x11E694u: goto label_11e694;
            case 0x11E698u: goto label_11e698;
            case 0x11E69Cu: goto label_11e69c;
            case 0x11E6A0u: goto label_11e6a0;
            case 0x11E6A4u: goto label_11e6a4;
            case 0x11E6A8u: goto label_11e6a8;
            case 0x11E6ACu: goto label_11e6ac;
            case 0x11E6B0u: goto label_11e6b0;
            case 0x11E6B4u: goto label_11e6b4;
            case 0x11E6B8u: goto label_11e6b8;
            case 0x11E6BCu: goto label_11e6bc;
            case 0x11E6C0u: goto label_11e6c0;
            case 0x11E6C4u: goto label_11e6c4;
            case 0x11E6C8u: goto label_11e6c8;
            case 0x11E6CCu: goto label_11e6cc;
            case 0x11E6D0u: goto label_11e6d0;
            case 0x11E6D4u: goto label_11e6d4;
            case 0x11E6D8u: goto label_11e6d8;
            case 0x11E6DCu: goto label_11e6dc;
            case 0x11E6E0u: goto label_11e6e0;
            case 0x11E6E4u: goto label_11e6e4;
            case 0x11E6E8u: goto label_11e6e8;
            case 0x11E6ECu: goto label_11e6ec;
            case 0x11E6F0u: goto label_11e6f0;
            case 0x11E6F4u: goto label_11e6f4;
            case 0x11E6F8u: goto label_11e6f8;
            case 0x11E6FCu: goto label_11e6fc;
            case 0x11E700u: goto label_11e700;
            case 0x11E704u: goto label_11e704;
            case 0x11E708u: goto label_11e708;
            case 0x11E70Cu: goto label_11e70c;
            case 0x11E710u: goto label_11e710;
            case 0x11E714u: goto label_11e714;
            case 0x11E718u: goto label_11e718;
            case 0x11E71Cu: goto label_11e71c;
            case 0x11E720u: goto label_11e720;
            case 0x11E724u: goto label_11e724;
            case 0x11E728u: goto label_11e728;
            case 0x11E72Cu: goto label_11e72c;
            case 0x11E730u: goto label_11e730;
            case 0x11E734u: goto label_11e734;
            case 0x11E738u: goto label_11e738;
            case 0x11E73Cu: goto label_11e73c;
            case 0x11E740u: goto label_11e740;
            case 0x11E744u: goto label_11e744;
            case 0x11E748u: goto label_11e748;
            case 0x11E74Cu: goto label_11e74c;
            case 0x11E750u: goto label_11e750;
            case 0x11E754u: goto label_11e754;
            case 0x11E758u: goto label_11e758;
            case 0x11E75Cu: goto label_11e75c;
            case 0x11E760u: goto label_11e760;
            case 0x11E764u: goto label_11e764;
            case 0x11E768u: goto label_11e768;
            case 0x11E76Cu: goto label_11e76c;
            case 0x11E770u: goto label_11e770;
            case 0x11E774u: goto label_11e774;
            case 0x11E778u: goto label_11e778;
            case 0x11E77Cu: goto label_11e77c;
            case 0x11E780u: goto label_11e780;
            case 0x11E784u: goto label_11e784;
            case 0x11E788u: goto label_11e788;
            case 0x11E78Cu: goto label_11e78c;
            case 0x11E790u: goto label_11e790;
            case 0x11E794u: goto label_11e794;
            case 0x11E798u: goto label_11e798;
            case 0x11E79Cu: goto label_11e79c;
            default: break;
        }
        return;
    }
label_fallthrough_0x11e798:
    ctx->pc = 0x11E7A0u;
}
