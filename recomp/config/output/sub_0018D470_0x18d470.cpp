#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018D470
// Address: 0x18d470 - 0x18d650
void sub_0018D470_0x18d470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18d470u;

label_18d470:
    // 0x18d470: 0x27bdffc0
    ctx->pc = 0x18d470u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
label_18d474:
    // 0x18d474: 0x3c03002a
    ctx->pc = 0x18d474u;
    SET_GPR_U32(ctx, 3, ((uint32_t)42 << 16));
label_18d478:
    // 0x18d478: 0xffbf0030
    ctx->pc = 0x18d478u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
label_18d47c:
    // 0x18d47c: 0x3c01002a
    ctx->pc = 0x18d47cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18d480:
    // 0x18d480: 0x7fb20020
    ctx->pc = 0x18d480u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
label_18d484:
    // 0x18d484: 0x2463f704
    ctx->pc = 0x18d484u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294964996));
label_18d488:
    // 0x18d488: 0x7fb10010
    ctx->pc = 0x18d488u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
label_18d48c:
    // 0x18d48c: 0x3c12002a
    ctx->pc = 0x18d48cu;
    SET_GPR_U32(ctx, 18, ((uint32_t)42 << 16));
label_18d490:
    // 0x18d490: 0x7fb00000
    ctx->pc = 0x18d490u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_18d494:
    // 0x18d494: 0xac20f724
    ctx->pc = 0x18d494u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965028), GPR_U32(ctx, 0));
label_18d498:
    // 0x18d498: 0x3c01002a
    ctx->pc = 0x18d498u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18d49c:
    // 0x18d49c: 0xac20f728
    ctx->pc = 0x18d49cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965032), GPR_U32(ctx, 0));
label_18d4a0:
    // 0x18d4a0: 0x3c01002a
    ctx->pc = 0x18d4a0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18d4a4:
    // 0x18d4a4: 0x8c25fdb4
    ctx->pc = 0x18d4a4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
label_18d4a8:
    // 0x18d4a8: 0x58080
    ctx->pc = 0x18d4a8u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 5), 2));
label_18d4ac:
    // 0x18d4ac: 0x38a40001
    ctx->pc = 0x18d4acu;
    SET_GPR_U32(ctx, 4, XOR32(GPR_U32(ctx, 5), 1));
label_18d4b0:
    // 0x18d4b0: 0x3c01002a
    ctx->pc = 0x18d4b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18d4b4:
    // 0x18d4b4: 0x701821
    ctx->pc = 0x18d4b4u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
label_18d4b8:
    // 0x18d4b8: 0xac24fdb4
    ctx->pc = 0x18d4b8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966708), GPR_U32(ctx, 4));
label_18d4bc:
    // 0x18d4bc: 0x8c630000
    ctx->pc = 0x18d4bcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_18d4c0:
    // 0x18d4c0: 0x1060005a
label_18d4c4:
    if (ctx->pc == 0x18D4C4u) {
        ctx->pc = 0x18D4C4u;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 4294964976));
        ctx->pc = 0x18D4C8u;
        goto label_18d4c8;
    }
    ctx->pc = 0x18D4C0u;
    {
        const bool branch_taken_0x18d4c0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D4C4u;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 4294964976));
        if (branch_taken_0x18d4c0) {
            ctx->pc = 0x18D62Cu;
            goto label_18d62c;
        }
    }
    ctx->pc = 0x18D4C8u;
label_18d4c8:
    // 0x18d4c8: 0x2121021
    ctx->pc = 0x18d4c8u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
label_18d4cc:
    // 0x18d4cc: 0x3c03002a
    ctx->pc = 0x18d4ccu;
    SET_GPR_U32(ctx, 3, ((uint32_t)42 << 16));
label_18d4d0:
    // 0x18d4d0: 0x8e450000
    ctx->pc = 0x18d4d0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_18d4d4:
    // 0x18d4d4: 0x2463fd74
    ctx->pc = 0x18d4d4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294966644));
label_18d4d8:
    // 0x18d4d8: 0x8c44000c
    ctx->pc = 0x18d4d8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 12)));
label_18d4dc:
    // 0x18d4dc: 0x51080
    ctx->pc = 0x18d4dcu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 2));
label_18d4e0:
    // 0x18d4e0: 0x621021
    ctx->pc = 0x18d4e0u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_18d4e4:
    // 0x18d4e4: 0xc063728
label_18d4e8:
    if (ctx->pc == 0x18D4E8u) {
        ctx->pc = 0x18D4E8u;
        SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->pc = 0x18D4ECu;
        goto label_18d4ec;
    }
    ctx->pc = 0x18D4E4u;
    SET_GPR_U32(ctx, 31, 0x18D4ECu);
    ctx->pc = 0x18D4E8u;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x18DCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D4ECu; }
    }
    if (ctx->pc != 0x18D4ECu) { return; }
    ctx->pc = 0x18D4ECu;
label_18d4ec:
    // 0x18d4ec: 0x2122021
    ctx->pc = 0x18d4ecu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
label_18d4f0:
    // 0x18d4f0: 0x3c03f000
    ctx->pc = 0x18d4f0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)61440 << 16));
label_18d4f4:
    // 0x18d4f4: 0x8c840024
    ctx->pc = 0x18d4f4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 36)));
label_18d4f8:
    // 0x18d4f8: 0x42080
    ctx->pc = 0x18d4f8u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 2));
label_18d4fc:
    // 0x18d4fc: 0x442021
    ctx->pc = 0x18d4fcu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_18d500:
    // 0x18d500: 0x8c900000
    ctx->pc = 0x18d500u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_18d504:
    // 0x18d504: 0x2031824
    ctx->pc = 0x18d504u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_18d508:
    // 0x18d508: 0x31f02
    ctx->pc = 0x18d508u;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), 28));
label_18d50c:
    // 0x18d50c: 0x2c610006
    ctx->pc = 0x18d50cu;
    SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 3), 6));
label_18d510:
    // 0x18d510: 0x10200046
label_18d514:
    if (ctx->pc == 0x18D514u) {
        ctx->pc = 0x18D514u;
        WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 16));
        ctx->pc = 0x18D518u;
        goto label_18d518;
    }
    ctx->pc = 0x18D510u;
    {
        const bool branch_taken_0x18d510 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D514u;
        WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 16));
        if (branch_taken_0x18d510) {
            ctx->pc = 0x18D62Cu;
            goto label_18d62c;
        }
    }
    ctx->pc = 0x18D518u;
label_18d518:
    // 0x18d518: 0x3c040024
    ctx->pc = 0x18d518u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_18d51c:
    // 0x18d51c: 0x31880
    ctx->pc = 0x18d51cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
label_18d520:
    // 0x18d520: 0x24841c30
    ctx->pc = 0x18d520u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 7216));
label_18d524:
    // 0x18d524: 0x641821
    ctx->pc = 0x18d524u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_18d528:
    // 0x18d528: 0x8c630000
    ctx->pc = 0x18d528u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_18d52c:
    // 0x18d52c: 0x600008
label_18d530:
    if (ctx->pc == 0x18D530u) {
        ctx->pc = 0x18D534u;
        goto label_18d534;
    }
    ctx->pc = 0x18D52Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18D470u: goto label_18d470;
            case 0x18D474u: goto label_18d474;
            case 0x18D478u: goto label_18d478;
            case 0x18D47Cu: goto label_18d47c;
            case 0x18D480u: goto label_18d480;
            case 0x18D484u: goto label_18d484;
            case 0x18D488u: goto label_18d488;
            case 0x18D48Cu: goto label_18d48c;
            case 0x18D490u: goto label_18d490;
            case 0x18D494u: goto label_18d494;
            case 0x18D498u: goto label_18d498;
            case 0x18D49Cu: goto label_18d49c;
            case 0x18D4A0u: goto label_18d4a0;
            case 0x18D4A4u: goto label_18d4a4;
            case 0x18D4A8u: goto label_18d4a8;
            case 0x18D4ACu: goto label_18d4ac;
            case 0x18D4B0u: goto label_18d4b0;
            case 0x18D4B4u: goto label_18d4b4;
            case 0x18D4B8u: goto label_18d4b8;
            case 0x18D4BCu: goto label_18d4bc;
            case 0x18D4C0u: goto label_18d4c0;
            case 0x18D4C4u: goto label_18d4c4;
            case 0x18D4C8u: goto label_18d4c8;
            case 0x18D4CCu: goto label_18d4cc;
            case 0x18D4D0u: goto label_18d4d0;
            case 0x18D4D4u: goto label_18d4d4;
            case 0x18D4D8u: goto label_18d4d8;
            case 0x18D4DCu: goto label_18d4dc;
            case 0x18D4E0u: goto label_18d4e0;
            case 0x18D4E4u: goto label_18d4e4;
            case 0x18D4E8u: goto label_18d4e8;
            case 0x18D4ECu: goto label_18d4ec;
            case 0x18D4F0u: goto label_18d4f0;
            case 0x18D4F4u: goto label_18d4f4;
            case 0x18D4F8u: goto label_18d4f8;
            case 0x18D4FCu: goto label_18d4fc;
            case 0x18D500u: goto label_18d500;
            case 0x18D504u: goto label_18d504;
            case 0x18D508u: goto label_18d508;
            case 0x18D50Cu: goto label_18d50c;
            case 0x18D510u: goto label_18d510;
            case 0x18D514u: goto label_18d514;
            case 0x18D518u: goto label_18d518;
            case 0x18D51Cu: goto label_18d51c;
            case 0x18D520u: goto label_18d520;
            case 0x18D524u: goto label_18d524;
            case 0x18D528u: goto label_18d528;
            case 0x18D52Cu: goto label_18d52c;
            case 0x18D530u: goto label_18d530;
            case 0x18D534u: goto label_18d534;
            case 0x18D538u: goto label_18d538;
            case 0x18D53Cu: goto label_18d53c;
            case 0x18D540u: goto label_18d540;
            case 0x18D544u: goto label_18d544;
            case 0x18D548u: goto label_18d548;
            case 0x18D54Cu: goto label_18d54c;
            case 0x18D550u: goto label_18d550;
            case 0x18D554u: goto label_18d554;
            case 0x18D558u: goto label_18d558;
            case 0x18D55Cu: goto label_18d55c;
            case 0x18D560u: goto label_18d560;
            case 0x18D564u: goto label_18d564;
            case 0x18D568u: goto label_18d568;
            case 0x18D56Cu: goto label_18d56c;
            case 0x18D570u: goto label_18d570;
            case 0x18D574u: goto label_18d574;
            case 0x18D578u: goto label_18d578;
            case 0x18D57Cu: goto label_18d57c;
            case 0x18D580u: goto label_18d580;
            case 0x18D584u: goto label_18d584;
            case 0x18D588u: goto label_18d588;
            case 0x18D58Cu: goto label_18d58c;
            case 0x18D590u: goto label_18d590;
            case 0x18D594u: goto label_18d594;
            case 0x18D598u: goto label_18d598;
            case 0x18D59Cu: goto label_18d59c;
            case 0x18D5A0u: goto label_18d5a0;
            case 0x18D5A4u: goto label_18d5a4;
            case 0x18D5A8u: goto label_18d5a8;
            case 0x18D5ACu: goto label_18d5ac;
            case 0x18D5B0u: goto label_18d5b0;
            case 0x18D5B4u: goto label_18d5b4;
            case 0x18D5B8u: goto label_18d5b8;
            case 0x18D5BCu: goto label_18d5bc;
            case 0x18D5C0u: goto label_18d5c0;
            case 0x18D5C4u: goto label_18d5c4;
            case 0x18D5C8u: goto label_18d5c8;
            case 0x18D5CCu: goto label_18d5cc;
            case 0x18D5D0u: goto label_18d5d0;
            case 0x18D5D4u: goto label_18d5d4;
            case 0x18D5D8u: goto label_18d5d8;
            case 0x18D5DCu: goto label_18d5dc;
            case 0x18D5E0u: goto label_18d5e0;
            case 0x18D5E4u: goto label_18d5e4;
            case 0x18D5E8u: goto label_18d5e8;
            case 0x18D5ECu: goto label_18d5ec;
            case 0x18D5F0u: goto label_18d5f0;
            case 0x18D5F4u: goto label_18d5f4;
            case 0x18D5F8u: goto label_18d5f8;
            case 0x18D5FCu: goto label_18d5fc;
            case 0x18D600u: goto label_18d600;
            case 0x18D604u: goto label_18d604;
            case 0x18D608u: goto label_18d608;
            case 0x18D60Cu: goto label_18d60c;
            case 0x18D610u: goto label_18d610;
            case 0x18D614u: goto label_18d614;
            case 0x18D618u: goto label_18d618;
            case 0x18D61Cu: goto label_18d61c;
            case 0x18D620u: goto label_18d620;
            case 0x18D624u: goto label_18d624;
            case 0x18D628u: goto label_18d628;
            case 0x18D62Cu: goto label_18d62c;
            case 0x18D630u: goto label_18d630;
            case 0x18D634u: goto label_18d634;
            case 0x18D638u: goto label_18d638;
            case 0x18D63Cu: goto label_18d63c;
            case 0x18D640u: goto label_18d640;
            case 0x18D644u: goto label_18d644;
            case 0x18D648u: goto label_18d648;
            case 0x18D64Cu: goto label_18d64c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D534u;
label_18d534:
    // 0x18d534: 0x92270000
    ctx->pc = 0x18d534u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_18d538:
    // 0x18d538: 0x2405ffbf
    ctx->pc = 0x18d538u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4294967231));
label_18d53c:
    // 0x18d53c: 0x64060040
    ctx->pc = 0x18d53cu;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)64);
label_18d540:
    // 0x18d540: 0x2402ff7f
    ctx->pc = 0x18d540u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967167));
label_18d544:
    // 0x18d544: 0x64030080
    ctx->pc = 0x18d544u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 0) + (int64_t)128);
label_18d548:
    // 0x18d548: 0x202d
    ctx->pc = 0x18d548u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18d54c:
    // 0x18d54c: 0xe52824
    ctx->pc = 0x18d54cu;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
label_18d550:
    // 0x18d550: 0xa62825
    ctx->pc = 0x18d550u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
label_18d554:
    // 0x18d554: 0xa2250000
    ctx->pc = 0x18d554u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 5));
label_18d558:
    // 0x18d558: 0x92250000
    ctx->pc = 0x18d558u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_18d55c:
    // 0x18d55c: 0xa21024
    ctx->pc = 0x18d55cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_18d560:
    // 0x18d560: 0x431025
    ctx->pc = 0x18d560u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18d564:
    // 0x18d564: 0xc045228
label_18d568:
    if (ctx->pc == 0x18D568u) {
        ctx->pc = 0x18D568u;
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->pc = 0x18D56Cu;
        goto label_18d56c;
    }
    ctx->pc = 0x18D564u;
    SET_GPR_U32(ctx, 31, 0x18D56Cu);
    ctx->pc = 0x18D568u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D56Cu; }
    }
    if (ctx->pc != 0x18D56Cu) { return; }
    ctx->pc = 0x18D56Cu;
label_18d56c:
    // 0x18d56c: 0x10293c
    ctx->pc = 0x18d56cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 4));
label_18d570:
    // 0x18d570: 0x220202d
    ctx->pc = 0x18d570u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_18d574:
    // 0x18d574: 0xc040ce4
label_18d578:
    if (ctx->pc == 0x18D578u) {
        ctx->pc = 0x18D578u;
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
        ctx->pc = 0x18D57Cu;
        goto label_18d57c;
    }
    ctx->pc = 0x18D574u;
    SET_GPR_U32(ctx, 31, 0x18D57Cu);
    ctx->pc = 0x18D578u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    ctx->pc = 0x103390u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D57Cu; }
    }
    if (ctx->pc != 0x18D57Cu) { return; }
    ctx->pc = 0x18D57Cu;
label_18d57c:
    // 0x18d57c: 0x1000002c
label_18d580:
    if (ctx->pc == 0x18D580u) {
        ctx->pc = 0x18D580u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->pc = 0x18D584u;
        goto label_18d584;
    }
    ctx->pc = 0x18D57Cu;
    {
        const bool branch_taken_0x18d57c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D580u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x18d57c) {
            ctx->pc = 0x18D630u;
            goto label_18d630;
        }
    }
    ctx->pc = 0x18D584u;
label_18d584:
    // 0x18d584: 0x10813c
    ctx->pc = 0x18d584u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 4));
label_18d588:
    // 0x18d588: 0x2402fdff
    ctx->pc = 0x18d588u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294966783));
label_18d58c:
    // 0x18d58c: 0x10813e
    ctx->pc = 0x18d58cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 4));
label_18d590:
    // 0x18d590: 0x3c010029
    ctx->pc = 0x18d590u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
label_18d594:
    // 0x18d594: 0x8e050080
    ctx->pc = 0x18d594u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 128)));
label_18d598:
    // 0x18d598: 0x24030002
    ctx->pc = 0x18d598u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_18d59c:
    // 0x18d59c: 0x70021389
    ctx->pc = 0x18d59cu;
    SET_GPR_VEC(ctx, 2, _mm_unpacklo_epi64(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
label_18d5a0:
    // 0x18d5a0: 0x202d
    ctx->pc = 0x18d5a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18d5a4:
    // 0x18d5a4: 0xac254148
    ctx->pc = 0x18d5a4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16712), GPR_U32(ctx, 5));
label_18d5a8:
    // 0x18d5a8: 0x8e050084
    ctx->pc = 0x18d5a8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 132)));
label_18d5ac:
    // 0x18d5ac: 0x3c010029
    ctx->pc = 0x18d5acu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
label_18d5b0:
    // 0x18d5b0: 0xac254150
    ctx->pc = 0x18d5b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16720), GPR_U32(ctx, 5));
label_18d5b4:
    // 0x18d5b4: 0x3c011200
    ctx->pc = 0x18d5b4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
label_18d5b8:
    // 0x18d5b8: 0xfc231000
    ctx->pc = 0x18d5b8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4096), GPR_U64(ctx, 3));
label_18d5bc:
    // 0x18d5bc: 0x3c011200
    ctx->pc = 0x18d5bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
label_18d5c0:
    // 0x18d5c0: 0xdc231010
    ctx->pc = 0x18d5c0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 1), 4112)));
label_18d5c4:
    // 0x18d5c4: 0x3c010029
    ctx->pc = 0x18d5c4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
label_18d5c8:
    // 0x18d5c8: 0xfc234158
    ctx->pc = 0x18d5c8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 16728), GPR_U64(ctx, 3));
label_18d5cc:
    // 0x18d5cc: 0x3c011200
    ctx->pc = 0x18d5ccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
label_18d5d0:
    // 0x18d5d0: 0xc04545a
label_18d5d4:
    if (ctx->pc == 0x18D5D4u) {
        ctx->pc = 0x18D5D4u;
        WRITE64(ADD32(GPR_U32(ctx, 1), 4112), GPR_U64(ctx, 2));
        ctx->pc = 0x18D5D8u;
        goto label_18d5d8;
    }
    ctx->pc = 0x18D5D0u;
    SET_GPR_U32(ctx, 31, 0x18D5D8u);
    ctx->pc = 0x18D5D4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4112), GPR_U64(ctx, 2));
    ctx->pc = 0x115168u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00115168_0x115168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D5D8u; }
    }
    if (ctx->pc != 0x18D5D8u) { return; }
    ctx->pc = 0x18D5D8u;
label_18d5d8:
    // 0x18d5d8: 0x8e470030
    ctx->pc = 0x18d5d8u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 18), 48)));
label_18d5dc:
    // 0x18d5dc: 0x30020001
    ctx->pc = 0x18d5dcu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 0), 1));
label_18d5e0:
    // 0x18d5e0: 0x2405ffbf
    ctx->pc = 0x18d5e0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4294967231));
label_18d5e4:
    // 0x18d5e4: 0x23180
    ctx->pc = 0x18d5e4u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 2), 6));
label_18d5e8:
    // 0x18d5e8: 0x219c0
    ctx->pc = 0x18d5e8u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 7));
label_18d5ec:
    // 0x18d5ec: 0x202d
    ctx->pc = 0x18d5ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18d5f0:
    // 0x18d5f0: 0x2402ff7f
    ctx->pc = 0x18d5f0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967167));
label_18d5f4:
    // 0x18d5f4: 0x34e70001
    ctx->pc = 0x18d5f4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 1));
label_18d5f8:
    // 0x18d5f8: 0xae470030
    ctx->pc = 0x18d5f8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 7));
label_18d5fc:
    // 0x18d5fc: 0x92270000
    ctx->pc = 0x18d5fcu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_18d600:
    // 0x18d600: 0xe52824
    ctx->pc = 0x18d600u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
label_18d604:
    // 0x18d604: 0xa62825
    ctx->pc = 0x18d604u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
label_18d608:
    // 0x18d608: 0xa2250000
    ctx->pc = 0x18d608u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 5));
label_18d60c:
    // 0x18d60c: 0x92250000
    ctx->pc = 0x18d60cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_18d610:
    // 0x18d610: 0xa21024
    ctx->pc = 0x18d610u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_18d614:
    // 0x18d614: 0x431025
    ctx->pc = 0x18d614u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18d618:
    // 0x18d618: 0xc045228
label_18d61c:
    if (ctx->pc == 0x18D61Cu) {
        ctx->pc = 0x18D61Cu;
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->pc = 0x18D620u;
        goto label_18d620;
    }
    ctx->pc = 0x18D618u;
    SET_GPR_U32(ctx, 31, 0x18D620u);
    ctx->pc = 0x18D61Cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D620u; }
    }
    if (ctx->pc != 0x18D620u) { return; }
    ctx->pc = 0x18D620u;
label_18d620:
    // 0x18d620: 0x220202d
    ctx->pc = 0x18d620u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_18d624:
    // 0x18d624: 0xc040ce4
label_18d628:
    if (ctx->pc == 0x18D628u) {
        ctx->pc = 0x18D628u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18D62Cu;
        goto label_18d62c;
    }
    ctx->pc = 0x18D624u;
    SET_GPR_U32(ctx, 31, 0x18D62Cu);
    ctx->pc = 0x18D628u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x103390u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D62Cu; }
    }
    if (ctx->pc != 0x18D62Cu) { return; }
    ctx->pc = 0x18D62Cu;
label_18d62c:
    // 0x18d62c: 0xdfbf0030
    ctx->pc = 0x18d62cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_18d630:
    // 0x18d630: 0x7bb20020
    ctx->pc = 0x18d630u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
label_18d634:
    // 0x18d634: 0x7bb10010
    ctx->pc = 0x18d634u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_18d638:
    // 0x18d638: 0x7bb00000
    ctx->pc = 0x18d638u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_18d63c:
    // 0x18d63c: 0x3e00008
label_18d640:
    if (ctx->pc == 0x18D640u) {
        ctx->pc = 0x18D640u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x18D644u;
        goto label_18d644;
    }
    ctx->pc = 0x18D63Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18D640u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18D470u: goto label_18d470;
            case 0x18D474u: goto label_18d474;
            case 0x18D478u: goto label_18d478;
            case 0x18D47Cu: goto label_18d47c;
            case 0x18D480u: goto label_18d480;
            case 0x18D484u: goto label_18d484;
            case 0x18D488u: goto label_18d488;
            case 0x18D48Cu: goto label_18d48c;
            case 0x18D490u: goto label_18d490;
            case 0x18D494u: goto label_18d494;
            case 0x18D498u: goto label_18d498;
            case 0x18D49Cu: goto label_18d49c;
            case 0x18D4A0u: goto label_18d4a0;
            case 0x18D4A4u: goto label_18d4a4;
            case 0x18D4A8u: goto label_18d4a8;
            case 0x18D4ACu: goto label_18d4ac;
            case 0x18D4B0u: goto label_18d4b0;
            case 0x18D4B4u: goto label_18d4b4;
            case 0x18D4B8u: goto label_18d4b8;
            case 0x18D4BCu: goto label_18d4bc;
            case 0x18D4C0u: goto label_18d4c0;
            case 0x18D4C4u: goto label_18d4c4;
            case 0x18D4C8u: goto label_18d4c8;
            case 0x18D4CCu: goto label_18d4cc;
            case 0x18D4D0u: goto label_18d4d0;
            case 0x18D4D4u: goto label_18d4d4;
            case 0x18D4D8u: goto label_18d4d8;
            case 0x18D4DCu: goto label_18d4dc;
            case 0x18D4E0u: goto label_18d4e0;
            case 0x18D4E4u: goto label_18d4e4;
            case 0x18D4E8u: goto label_18d4e8;
            case 0x18D4ECu: goto label_18d4ec;
            case 0x18D4F0u: goto label_18d4f0;
            case 0x18D4F4u: goto label_18d4f4;
            case 0x18D4F8u: goto label_18d4f8;
            case 0x18D4FCu: goto label_18d4fc;
            case 0x18D500u: goto label_18d500;
            case 0x18D504u: goto label_18d504;
            case 0x18D508u: goto label_18d508;
            case 0x18D50Cu: goto label_18d50c;
            case 0x18D510u: goto label_18d510;
            case 0x18D514u: goto label_18d514;
            case 0x18D518u: goto label_18d518;
            case 0x18D51Cu: goto label_18d51c;
            case 0x18D520u: goto label_18d520;
            case 0x18D524u: goto label_18d524;
            case 0x18D528u: goto label_18d528;
            case 0x18D52Cu: goto label_18d52c;
            case 0x18D530u: goto label_18d530;
            case 0x18D534u: goto label_18d534;
            case 0x18D538u: goto label_18d538;
            case 0x18D53Cu: goto label_18d53c;
            case 0x18D540u: goto label_18d540;
            case 0x18D544u: goto label_18d544;
            case 0x18D548u: goto label_18d548;
            case 0x18D54Cu: goto label_18d54c;
            case 0x18D550u: goto label_18d550;
            case 0x18D554u: goto label_18d554;
            case 0x18D558u: goto label_18d558;
            case 0x18D55Cu: goto label_18d55c;
            case 0x18D560u: goto label_18d560;
            case 0x18D564u: goto label_18d564;
            case 0x18D568u: goto label_18d568;
            case 0x18D56Cu: goto label_18d56c;
            case 0x18D570u: goto label_18d570;
            case 0x18D574u: goto label_18d574;
            case 0x18D578u: goto label_18d578;
            case 0x18D57Cu: goto label_18d57c;
            case 0x18D580u: goto label_18d580;
            case 0x18D584u: goto label_18d584;
            case 0x18D588u: goto label_18d588;
            case 0x18D58Cu: goto label_18d58c;
            case 0x18D590u: goto label_18d590;
            case 0x18D594u: goto label_18d594;
            case 0x18D598u: goto label_18d598;
            case 0x18D59Cu: goto label_18d59c;
            case 0x18D5A0u: goto label_18d5a0;
            case 0x18D5A4u: goto label_18d5a4;
            case 0x18D5A8u: goto label_18d5a8;
            case 0x18D5ACu: goto label_18d5ac;
            case 0x18D5B0u: goto label_18d5b0;
            case 0x18D5B4u: goto label_18d5b4;
            case 0x18D5B8u: goto label_18d5b8;
            case 0x18D5BCu: goto label_18d5bc;
            case 0x18D5C0u: goto label_18d5c0;
            case 0x18D5C4u: goto label_18d5c4;
            case 0x18D5C8u: goto label_18d5c8;
            case 0x18D5CCu: goto label_18d5cc;
            case 0x18D5D0u: goto label_18d5d0;
            case 0x18D5D4u: goto label_18d5d4;
            case 0x18D5D8u: goto label_18d5d8;
            case 0x18D5DCu: goto label_18d5dc;
            case 0x18D5E0u: goto label_18d5e0;
            case 0x18D5E4u: goto label_18d5e4;
            case 0x18D5E8u: goto label_18d5e8;
            case 0x18D5ECu: goto label_18d5ec;
            case 0x18D5F0u: goto label_18d5f0;
            case 0x18D5F4u: goto label_18d5f4;
            case 0x18D5F8u: goto label_18d5f8;
            case 0x18D5FCu: goto label_18d5fc;
            case 0x18D600u: goto label_18d600;
            case 0x18D604u: goto label_18d604;
            case 0x18D608u: goto label_18d608;
            case 0x18D60Cu: goto label_18d60c;
            case 0x18D610u: goto label_18d610;
            case 0x18D614u: goto label_18d614;
            case 0x18D618u: goto label_18d618;
            case 0x18D61Cu: goto label_18d61c;
            case 0x18D620u: goto label_18d620;
            case 0x18D624u: goto label_18d624;
            case 0x18D628u: goto label_18d628;
            case 0x18D62Cu: goto label_18d62c;
            case 0x18D630u: goto label_18d630;
            case 0x18D634u: goto label_18d634;
            case 0x18D638u: goto label_18d638;
            case 0x18D63Cu: goto label_18d63c;
            case 0x18D640u: goto label_18d640;
            case 0x18D644u: goto label_18d644;
            case 0x18D648u: goto label_18d648;
            case 0x18D64Cu: goto label_18d64c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D644u;
label_18d644:
    // 0x18d644: 0x0
    ctx->pc = 0x18d644u;
    // NOP
label_18d648:
    // 0x18d648: 0x0
    ctx->pc = 0x18d648u;
    // NOP
label_18d64c:
    // 0x18d64c: 0x0
    ctx->pc = 0x18d64cu;
    // NOP
}
