#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0016F4E0
// Address: 0x16f4e0 - 0x16f658
void sub_0016F4E0_0x16f4e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x16f4e0u;

label_16f4e0:
    // 0x16f4e0: 0x27bdffb0
    ctx->pc = 0x16f4e0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
label_16f4e4:
    // 0x16f4e4: 0xffb00010
    ctx->pc = 0x16f4e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
label_16f4e8:
    // 0x16f4e8: 0xffb10018
    ctx->pc = 0x16f4e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
label_16f4ec:
    // 0x16f4ec: 0xa0882d
    ctx->pc = 0x16f4ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_16f4f0:
    // 0x16f4f0: 0xffb30028
    ctx->pc = 0x16f4f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
label_16f4f4:
    // 0x16f4f4: 0x80982d
    ctx->pc = 0x16f4f4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_16f4f8:
    // 0x16f4f8: 0xffb40030
    ctx->pc = 0x16f4f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
label_16f4fc:
    // 0x16f4fc: 0xc0a02d
    ctx->pc = 0x16f4fcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_16f500:
    // 0x16f500: 0xffb50038
    ctx->pc = 0x16f500u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
label_16f504:
    // 0x16f504: 0xe0a82d
    ctx->pc = 0x16f504u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_16f508:
    // 0x16f508: 0xffb20020
    ctx->pc = 0x16f508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
label_16f50c:
    // 0x16f50c: 0x3c067fff
    ctx->pc = 0x16f50cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)32767 << 16));
label_16f510:
    // 0x16f510: 0xffbf0040
    ctx->pc = 0x16f510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
label_16f514:
    // 0x16f514: 0x3a0382d
    ctx->pc = 0x16f514u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_16f518:
    // 0x16f518: 0xae200000
    ctx->pc = 0x16f518u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
label_16f51c:
    // 0x16f51c: 0x24050001
    ctx->pc = 0x16f51cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_16f520:
    // 0x16f520: 0x8e630000
    ctx->pc = 0x16f520u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_16f524:
    // 0x16f524: 0x34c6ffff
    ctx->pc = 0x16f524u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 65535));
label_16f528:
    // 0x16f528: 0xae800000
    ctx->pc = 0x16f528u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
label_16f52c:
    // 0x16f52c: 0x8c620018
    ctx->pc = 0x16f52cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 24)));
label_16f530:
    // 0x16f530: 0x40f809
label_16f534:
    if (ctx->pc == 0x16F534u) {
        ctx->pc = 0x16F534u;
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
        ctx->pc = 0x16F538u;
        goto label_16f538;
    }
    ctx->pc = 0x16F530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16F538u);
        ctx->pc = 0x16F534u;
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F4E0u: goto label_16f4e0;
            case 0x16F4E4u: goto label_16f4e4;
            case 0x16F4E8u: goto label_16f4e8;
            case 0x16F4ECu: goto label_16f4ec;
            case 0x16F4F0u: goto label_16f4f0;
            case 0x16F4F4u: goto label_16f4f4;
            case 0x16F4F8u: goto label_16f4f8;
            case 0x16F4FCu: goto label_16f4fc;
            case 0x16F500u: goto label_16f500;
            case 0x16F504u: goto label_16f504;
            case 0x16F508u: goto label_16f508;
            case 0x16F50Cu: goto label_16f50c;
            case 0x16F510u: goto label_16f510;
            case 0x16F514u: goto label_16f514;
            case 0x16F518u: goto label_16f518;
            case 0x16F51Cu: goto label_16f51c;
            case 0x16F520u: goto label_16f520;
            case 0x16F524u: goto label_16f524;
            case 0x16F528u: goto label_16f528;
            case 0x16F52Cu: goto label_16f52c;
            case 0x16F530u: goto label_16f530;
            case 0x16F534u: goto label_16f534;
            case 0x16F538u: goto label_16f538;
            case 0x16F53Cu: goto label_16f53c;
            case 0x16F540u: goto label_16f540;
            case 0x16F544u: goto label_16f544;
            case 0x16F548u: goto label_16f548;
            case 0x16F54Cu: goto label_16f54c;
            case 0x16F550u: goto label_16f550;
            case 0x16F554u: goto label_16f554;
            case 0x16F558u: goto label_16f558;
            case 0x16F55Cu: goto label_16f55c;
            case 0x16F560u: goto label_16f560;
            case 0x16F564u: goto label_16f564;
            case 0x16F568u: goto label_16f568;
            case 0x16F56Cu: goto label_16f56c;
            case 0x16F570u: goto label_16f570;
            case 0x16F574u: goto label_16f574;
            case 0x16F578u: goto label_16f578;
            case 0x16F57Cu: goto label_16f57c;
            case 0x16F580u: goto label_16f580;
            case 0x16F584u: goto label_16f584;
            case 0x16F588u: goto label_16f588;
            case 0x16F58Cu: goto label_16f58c;
            case 0x16F590u: goto label_16f590;
            case 0x16F594u: goto label_16f594;
            case 0x16F598u: goto label_16f598;
            case 0x16F59Cu: goto label_16f59c;
            case 0x16F5A0u: goto label_16f5a0;
            case 0x16F5A4u: goto label_16f5a4;
            case 0x16F5A8u: goto label_16f5a8;
            case 0x16F5ACu: goto label_16f5ac;
            case 0x16F5B0u: goto label_16f5b0;
            case 0x16F5B4u: goto label_16f5b4;
            case 0x16F5B8u: goto label_16f5b8;
            case 0x16F5BCu: goto label_16f5bc;
            case 0x16F5C0u: goto label_16f5c0;
            case 0x16F5C4u: goto label_16f5c4;
            case 0x16F5C8u: goto label_16f5c8;
            case 0x16F5CCu: goto label_16f5cc;
            case 0x16F5D0u: goto label_16f5d0;
            case 0x16F5D4u: goto label_16f5d4;
            case 0x16F5D8u: goto label_16f5d8;
            case 0x16F5DCu: goto label_16f5dc;
            case 0x16F5E0u: goto label_16f5e0;
            case 0x16F5E4u: goto label_16f5e4;
            case 0x16F5E8u: goto label_16f5e8;
            case 0x16F5ECu: goto label_16f5ec;
            case 0x16F5F0u: goto label_16f5f0;
            case 0x16F5F4u: goto label_16f5f4;
            case 0x16F5F8u: goto label_16f5f8;
            case 0x16F5FCu: goto label_16f5fc;
            case 0x16F600u: goto label_16f600;
            case 0x16F604u: goto label_16f604;
            case 0x16F608u: goto label_16f608;
            case 0x16F60Cu: goto label_16f60c;
            case 0x16F610u: goto label_16f610;
            case 0x16F614u: goto label_16f614;
            case 0x16F618u: goto label_16f618;
            case 0x16F61Cu: goto label_16f61c;
            case 0x16F620u: goto label_16f620;
            case 0x16F624u: goto label_16f624;
            case 0x16F628u: goto label_16f628;
            case 0x16F62Cu: goto label_16f62c;
            case 0x16F630u: goto label_16f630;
            case 0x16F634u: goto label_16f634;
            case 0x16F638u: goto label_16f638;
            case 0x16F63Cu: goto label_16f63c;
            case 0x16F640u: goto label_16f640;
            case 0x16F644u: goto label_16f644;
            case 0x16F648u: goto label_16f648;
            case 0x16F64Cu: goto label_16f64c;
            case 0x16F650u: goto label_16f650;
            case 0x16F654u: goto label_16f654;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16F538u; }
            if (ctx->pc != 0x16F538u) { return; }
        }
    }
    ctx->pc = 0x16F538u;
label_16f538:
    // 0x16f538: 0x240600cc
    ctx->pc = 0x16f538u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 204));
label_16f53c:
    // 0x16f53c: 0x8fa40000
    ctx->pc = 0x16f53cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_16f540:
    // 0x16f540: 0xc0561d4
label_16f544:
    if (ctx->pc == 0x16F544u) {
        ctx->pc = 0x16F544u;
        SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->pc = 0x16F548u;
        goto label_16f548;
    }
    ctx->pc = 0x16F540u;
    SET_GPR_U32(ctx, 31, 0x16F548u);
    ctx->pc = 0x16F544u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 4)));
    ctx->pc = 0x158750u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F548u; }
    }
    if (ctx->pc != 0x16F548u) { return; }
    ctx->pc = 0x16F548u;
label_16f548:
    // 0x16f548: 0x40802d
    ctx->pc = 0x16f548u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_16f54c:
    // 0x16f54c: 0x1200002a
label_16f550:
    if (ctx->pc == 0x16F550u) {
        ctx->pc = 0x16F550u;
        SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
        ctx->pc = 0x16F554u;
        goto label_16f554;
    }
    ctx->pc = 0x16F54Cu;
    {
        const bool branch_taken_0x16f54c = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x16F550u;
        SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
        if (branch_taken_0x16f54c) {
            ctx->pc = 0x16F5F8u;
            goto label_16f5f8;
        }
    }
    ctx->pc = 0x16F554u;
label_16f554:
    // 0x16f554: 0xc05616e
label_16f558:
    if (ctx->pc == 0x16F558u) {
        ctx->pc = 0x16F558u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x16F55Cu;
        goto label_16f55c;
    }
    ctx->pc = 0x16F554u;
    SET_GPR_U32(ctx, 31, 0x16F55Cu);
    ctx->pc = 0x16F558u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1585B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F55Cu; }
    }
    if (ctx->pc != 0x16F55Cu) { return; }
    ctx->pc = 0x16F55Cu;
label_16f55c:
    // 0x16f55c: 0x30420004
    ctx->pc = 0x16f55cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 4));
label_16f560:
    // 0x16f560: 0x1040002d
label_16f564:
    if (ctx->pc == 0x16F564u) {
        ctx->pc = 0x16F564u;
        SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->pc = 0x16F568u;
        goto label_16f568;
    }
    ctx->pc = 0x16F560u;
    {
        const bool branch_taken_0x16f560 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16F564u;
        SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 4)));
        if (branch_taken_0x16f560) {
            ctx->pc = 0x16F618u;
            goto label_16f618;
        }
    }
    ctx->pc = 0x16F568u;
label_16f568:
    // 0x16f568: 0x8fa60000
    ctx->pc = 0x16f568u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_16f56c:
    // 0x16f56c: 0x2061023
    ctx->pc = 0x16f56cu;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
label_16f570:
    // 0x16f570: 0x24420006
    ctx->pc = 0x16f570u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 6));
label_16f574:
    // 0x16f574: 0xa2102a
    ctx->pc = 0x16f574u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 2)));
label_16f578:
    // 0x16f578: 0x1440001f
label_16f57c:
    if (ctx->pc == 0x16F57Cu) {
        ctx->pc = 0x16F57Cu;
        SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
        ctx->pc = 0x16F580u;
        goto label_16f580;
    }
    ctx->pc = 0x16F578u;
    {
        const bool branch_taken_0x16f578 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x16F57Cu;
        SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
        if (branch_taken_0x16f578) {
            ctx->pc = 0x16F5F8u;
            goto label_16f5f8;
        }
    }
    ctx->pc = 0x16F580u;
label_16f580:
    // 0x16f580: 0x92020005
    ctx->pc = 0x16f580u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
label_16f584:
    // 0x16f584: 0x24040003
    ctx->pc = 0x16f584u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
label_16f588:
    // 0x16f588: 0x210fa
    ctx->pc = 0x16f588u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 3);
label_16f58c:
    // 0x16f58c: 0x30420007
    ctx->pc = 0x16f58cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 7));
label_16f590:
    // 0x16f590: 0x21080
    ctx->pc = 0x16f590u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
label_16f594:
    // 0x16f594: 0x3c030024
    ctx->pc = 0x16f594u;
    SET_GPR_U32(ctx, 3, ((uint32_t)36 << 16));
label_16f598:
    // 0x16f598: 0x621821
    ctx->pc = 0x16f598u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_16f59c:
    // 0x16f59c: 0x8c630900
    ctx->pc = 0x16f59cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 2304)));
label_16f5a0:
    // 0x16f5a0: 0x1464001d
label_16f5a4:
    if (ctx->pc == 0x16F5A4u) {
        ctx->pc = 0x16F5A4u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->pc = 0x16F5A8u;
        goto label_16f5a8;
    }
    ctx->pc = 0x16F5A0u;
    {
        const bool branch_taken_0x16f5a0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 4));
        ctx->pc = 0x16F5A4u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        if (branch_taken_0x16f5a0) {
            ctx->pc = 0x16F618u;
            goto label_16f618;
        }
    }
    ctx->pc = 0x16F5A8u;
label_16f5a8:
    // 0x16f5a8: 0xd01023
    ctx->pc = 0x16f5a8u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
label_16f5ac:
    // 0x16f5ac: 0x24060022
    ctx->pc = 0x16f5acu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 34));
label_16f5b0:
    // 0x16f5b0: 0x459021
    ctx->pc = 0x16f5b0u;
    SET_GPR_U32(ctx, 18, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_16f5b4:
    // 0x16f5b4: 0x200202d
    ctx->pc = 0x16f5b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_16f5b8:
    // 0x16f5b8: 0xc0561d4
label_16f5bc:
    if (ctx->pc == 0x16F5BCu) {
        ctx->pc = 0x16F5BCu;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x16F5C0u;
        goto label_16f5c0;
    }
    ctx->pc = 0x16F5B8u;
    SET_GPR_U32(ctx, 31, 0x16F5C0u);
    ctx->pc = 0x16F5BCu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x158750u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F5C0u; }
    }
    if (ctx->pc != 0x16F5C0u) { return; }
    ctx->pc = 0x16F5C0u;
label_16f5c0:
    // 0x16f5c0: 0x40882d
    ctx->pc = 0x16f5c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_16f5c4:
    // 0x16f5c4: 0x52200015
label_16f5c8:
    if (ctx->pc == 0x16F5C8u) {
        ctx->pc = 0x16F5C8u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->pc = 0x16F5CCu;
        goto label_16f5cc;
    }
    ctx->pc = 0x16F5C4u;
    {
        const bool branch_taken_0x16f5c4 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        if (branch_taken_0x16f5c4) {
            ctx->pc = 0x16F5C8u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 0)));
            ctx->pc = 0x16F61Cu;
            goto label_16f61c;
        }
    }
    ctx->pc = 0x16F5CCu;
label_16f5cc:
    // 0x16f5cc: 0xc05616e
label_16f5d0:
    if (ctx->pc == 0x16F5D0u) {
        ctx->pc = 0x16F5D0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x16F5D4u;
        goto label_16f5d4;
    }
    ctx->pc = 0x16F5CCu;
    SET_GPR_U32(ctx, 31, 0x16F5D4u);
    ctx->pc = 0x16F5D0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1585B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F5D4u; }
    }
    if (ctx->pc != 0x16F5D4u) { return; }
    ctx->pc = 0x16F5D4u;
label_16f5d4:
    // 0x16f5d4: 0x30420020
    ctx->pc = 0x16f5d4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 32));
label_16f5d8:
    // 0x16f5d8: 0x1040000f
label_16f5dc:
    if (ctx->pc == 0x16F5DCu) {
        ctx->pc = 0x16F5DCu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x16F5E0u;
        goto label_16f5e0;
    }
    ctx->pc = 0x16F5D8u;
    {
        const bool branch_taken_0x16f5d8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16F5DCu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x16f5d8) {
            ctx->pc = 0x16F618u;
            goto label_16f618;
        }
    }
    ctx->pc = 0x16F5E0u;
label_16f5e0:
    // 0x16f5e0: 0x240282d
    ctx->pc = 0x16f5e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_16f5e4:
    // 0x16f5e4: 0xc0561d4
label_16f5e8:
    if (ctx->pc == 0x16F5E8u) {
        ctx->pc = 0x16F5E8u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x16F5ECu;
        goto label_16f5ec;
    }
    ctx->pc = 0x16F5E4u;
    SET_GPR_U32(ctx, 31, 0x16F5ECu);
    ctx->pc = 0x16F5E8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x158750u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F5ECu; }
    }
    if (ctx->pc != 0x16F5ECu) { return; }
    ctx->pc = 0x16F5ECu;
label_16f5ec:
    // 0x16f5ec: 0x14400008
label_16f5f0:
    if (ctx->pc == 0x16F5F0u) {
        ctx->pc = 0x16F5F0u;
        SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
        ctx->pc = 0x16F5F4u;
        goto label_16f5f4;
    }
    ctx->pc = 0x16F5ECu;
    {
        const bool branch_taken_0x16f5ec = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x16F5F0u;
        SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
        if (branch_taken_0x16f5ec) {
            ctx->pc = 0x16F610u;
            goto label_16f610;
        }
    }
    ctx->pc = 0x16F5F4u;
label_16f5f4:
    // 0x16f5f4: 0x3c030023
    ctx->pc = 0x16f5f4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
label_16f5f8:
    // 0x16f5f8: 0x2463f1bc
    ctx->pc = 0x16f5f8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294963644));
label_16f5fc:
    // 0x16f5fc: 0x8c620000
    ctx->pc = 0x16f5fcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_16f600:
    // 0x16f600: 0x24420001
    ctx->pc = 0x16f600u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_16f604:
    // 0x16f604: 0x10000004
label_16f608:
    if (ctx->pc == 0x16F608u) {
        ctx->pc = 0x16F608u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x16F60Cu;
        goto label_16f60c;
    }
    ctx->pc = 0x16F604u;
    {
        const bool branch_taken_0x16f604 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x16F608u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x16f604) {
            ctx->pc = 0x16F618u;
            goto label_16f618;
        }
    }
    ctx->pc = 0x16F60Cu;
label_16f60c:
    // 0x16f60c: 0x0
    ctx->pc = 0x16f60cu;
    // NOP
label_16f610:
    // 0x16f610: 0xae910000
    ctx->pc = 0x16f610u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 17));
label_16f614:
    // 0x16f614: 0xaea20000
    ctx->pc = 0x16f614u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
label_16f618:
    // 0x16f618: 0x8e630000
    ctx->pc = 0x16f618u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_16f61c:
    // 0x16f61c: 0x260202d
    ctx->pc = 0x16f61cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_16f620:
    // 0x16f620: 0x24050001
    ctx->pc = 0x16f620u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_16f624:
    // 0x16f624: 0x8c62001c
    ctx->pc = 0x16f624u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 28)));
label_16f628:
    // 0x16f628: 0x40f809
label_16f62c:
    if (ctx->pc == 0x16F62Cu) {
        ctx->pc = 0x16F62Cu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x16F630u;
        goto label_16f630;
    }
    ctx->pc = 0x16F628u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16F630u);
        ctx->pc = 0x16F62Cu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F4E0u: goto label_16f4e0;
            case 0x16F4E4u: goto label_16f4e4;
            case 0x16F4E8u: goto label_16f4e8;
            case 0x16F4ECu: goto label_16f4ec;
            case 0x16F4F0u: goto label_16f4f0;
            case 0x16F4F4u: goto label_16f4f4;
            case 0x16F4F8u: goto label_16f4f8;
            case 0x16F4FCu: goto label_16f4fc;
            case 0x16F500u: goto label_16f500;
            case 0x16F504u: goto label_16f504;
            case 0x16F508u: goto label_16f508;
            case 0x16F50Cu: goto label_16f50c;
            case 0x16F510u: goto label_16f510;
            case 0x16F514u: goto label_16f514;
            case 0x16F518u: goto label_16f518;
            case 0x16F51Cu: goto label_16f51c;
            case 0x16F520u: goto label_16f520;
            case 0x16F524u: goto label_16f524;
            case 0x16F528u: goto label_16f528;
            case 0x16F52Cu: goto label_16f52c;
            case 0x16F530u: goto label_16f530;
            case 0x16F534u: goto label_16f534;
            case 0x16F538u: goto label_16f538;
            case 0x16F53Cu: goto label_16f53c;
            case 0x16F540u: goto label_16f540;
            case 0x16F544u: goto label_16f544;
            case 0x16F548u: goto label_16f548;
            case 0x16F54Cu: goto label_16f54c;
            case 0x16F550u: goto label_16f550;
            case 0x16F554u: goto label_16f554;
            case 0x16F558u: goto label_16f558;
            case 0x16F55Cu: goto label_16f55c;
            case 0x16F560u: goto label_16f560;
            case 0x16F564u: goto label_16f564;
            case 0x16F568u: goto label_16f568;
            case 0x16F56Cu: goto label_16f56c;
            case 0x16F570u: goto label_16f570;
            case 0x16F574u: goto label_16f574;
            case 0x16F578u: goto label_16f578;
            case 0x16F57Cu: goto label_16f57c;
            case 0x16F580u: goto label_16f580;
            case 0x16F584u: goto label_16f584;
            case 0x16F588u: goto label_16f588;
            case 0x16F58Cu: goto label_16f58c;
            case 0x16F590u: goto label_16f590;
            case 0x16F594u: goto label_16f594;
            case 0x16F598u: goto label_16f598;
            case 0x16F59Cu: goto label_16f59c;
            case 0x16F5A0u: goto label_16f5a0;
            case 0x16F5A4u: goto label_16f5a4;
            case 0x16F5A8u: goto label_16f5a8;
            case 0x16F5ACu: goto label_16f5ac;
            case 0x16F5B0u: goto label_16f5b0;
            case 0x16F5B4u: goto label_16f5b4;
            case 0x16F5B8u: goto label_16f5b8;
            case 0x16F5BCu: goto label_16f5bc;
            case 0x16F5C0u: goto label_16f5c0;
            case 0x16F5C4u: goto label_16f5c4;
            case 0x16F5C8u: goto label_16f5c8;
            case 0x16F5CCu: goto label_16f5cc;
            case 0x16F5D0u: goto label_16f5d0;
            case 0x16F5D4u: goto label_16f5d4;
            case 0x16F5D8u: goto label_16f5d8;
            case 0x16F5DCu: goto label_16f5dc;
            case 0x16F5E0u: goto label_16f5e0;
            case 0x16F5E4u: goto label_16f5e4;
            case 0x16F5E8u: goto label_16f5e8;
            case 0x16F5ECu: goto label_16f5ec;
            case 0x16F5F0u: goto label_16f5f0;
            case 0x16F5F4u: goto label_16f5f4;
            case 0x16F5F8u: goto label_16f5f8;
            case 0x16F5FCu: goto label_16f5fc;
            case 0x16F600u: goto label_16f600;
            case 0x16F604u: goto label_16f604;
            case 0x16F608u: goto label_16f608;
            case 0x16F60Cu: goto label_16f60c;
            case 0x16F610u: goto label_16f610;
            case 0x16F614u: goto label_16f614;
            case 0x16F618u: goto label_16f618;
            case 0x16F61Cu: goto label_16f61c;
            case 0x16F620u: goto label_16f620;
            case 0x16F624u: goto label_16f624;
            case 0x16F628u: goto label_16f628;
            case 0x16F62Cu: goto label_16f62c;
            case 0x16F630u: goto label_16f630;
            case 0x16F634u: goto label_16f634;
            case 0x16F638u: goto label_16f638;
            case 0x16F63Cu: goto label_16f63c;
            case 0x16F640u: goto label_16f640;
            case 0x16F644u: goto label_16f644;
            case 0x16F648u: goto label_16f648;
            case 0x16F64Cu: goto label_16f64c;
            case 0x16F650u: goto label_16f650;
            case 0x16F654u: goto label_16f654;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16F630u; }
            if (ctx->pc != 0x16F630u) { return; }
        }
    }
    ctx->pc = 0x16F630u;
label_16f630:
    // 0x16f630: 0xdfb00010
    ctx->pc = 0x16f630u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_16f634:
    // 0x16f634: 0xdfb10018
    ctx->pc = 0x16f634u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_16f638:
    // 0x16f638: 0xdfb20020
    ctx->pc = 0x16f638u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_16f63c:
    // 0x16f63c: 0xdfb30028
    ctx->pc = 0x16f63cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_16f640:
    // 0x16f640: 0xdfb40030
    ctx->pc = 0x16f640u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_16f644:
    // 0x16f644: 0xdfb50038
    ctx->pc = 0x16f644u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
label_16f648:
    // 0x16f648: 0xdfbf0040
    ctx->pc = 0x16f648u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_16f64c:
    // 0x16f64c: 0x3e00008
label_16f650:
    if (ctx->pc == 0x16F650u) {
        ctx->pc = 0x16F650u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = 0x16F654u;
        goto label_16f654;
    }
    ctx->pc = 0x16F64Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16F650u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F4E0u: goto label_16f4e0;
            case 0x16F4E4u: goto label_16f4e4;
            case 0x16F4E8u: goto label_16f4e8;
            case 0x16F4ECu: goto label_16f4ec;
            case 0x16F4F0u: goto label_16f4f0;
            case 0x16F4F4u: goto label_16f4f4;
            case 0x16F4F8u: goto label_16f4f8;
            case 0x16F4FCu: goto label_16f4fc;
            case 0x16F500u: goto label_16f500;
            case 0x16F504u: goto label_16f504;
            case 0x16F508u: goto label_16f508;
            case 0x16F50Cu: goto label_16f50c;
            case 0x16F510u: goto label_16f510;
            case 0x16F514u: goto label_16f514;
            case 0x16F518u: goto label_16f518;
            case 0x16F51Cu: goto label_16f51c;
            case 0x16F520u: goto label_16f520;
            case 0x16F524u: goto label_16f524;
            case 0x16F528u: goto label_16f528;
            case 0x16F52Cu: goto label_16f52c;
            case 0x16F530u: goto label_16f530;
            case 0x16F534u: goto label_16f534;
            case 0x16F538u: goto label_16f538;
            case 0x16F53Cu: goto label_16f53c;
            case 0x16F540u: goto label_16f540;
            case 0x16F544u: goto label_16f544;
            case 0x16F548u: goto label_16f548;
            case 0x16F54Cu: goto label_16f54c;
            case 0x16F550u: goto label_16f550;
            case 0x16F554u: goto label_16f554;
            case 0x16F558u: goto label_16f558;
            case 0x16F55Cu: goto label_16f55c;
            case 0x16F560u: goto label_16f560;
            case 0x16F564u: goto label_16f564;
            case 0x16F568u: goto label_16f568;
            case 0x16F56Cu: goto label_16f56c;
            case 0x16F570u: goto label_16f570;
            case 0x16F574u: goto label_16f574;
            case 0x16F578u: goto label_16f578;
            case 0x16F57Cu: goto label_16f57c;
            case 0x16F580u: goto label_16f580;
            case 0x16F584u: goto label_16f584;
            case 0x16F588u: goto label_16f588;
            case 0x16F58Cu: goto label_16f58c;
            case 0x16F590u: goto label_16f590;
            case 0x16F594u: goto label_16f594;
            case 0x16F598u: goto label_16f598;
            case 0x16F59Cu: goto label_16f59c;
            case 0x16F5A0u: goto label_16f5a0;
            case 0x16F5A4u: goto label_16f5a4;
            case 0x16F5A8u: goto label_16f5a8;
            case 0x16F5ACu: goto label_16f5ac;
            case 0x16F5B0u: goto label_16f5b0;
            case 0x16F5B4u: goto label_16f5b4;
            case 0x16F5B8u: goto label_16f5b8;
            case 0x16F5BCu: goto label_16f5bc;
            case 0x16F5C0u: goto label_16f5c0;
            case 0x16F5C4u: goto label_16f5c4;
            case 0x16F5C8u: goto label_16f5c8;
            case 0x16F5CCu: goto label_16f5cc;
            case 0x16F5D0u: goto label_16f5d0;
            case 0x16F5D4u: goto label_16f5d4;
            case 0x16F5D8u: goto label_16f5d8;
            case 0x16F5DCu: goto label_16f5dc;
            case 0x16F5E0u: goto label_16f5e0;
            case 0x16F5E4u: goto label_16f5e4;
            case 0x16F5E8u: goto label_16f5e8;
            case 0x16F5ECu: goto label_16f5ec;
            case 0x16F5F0u: goto label_16f5f0;
            case 0x16F5F4u: goto label_16f5f4;
            case 0x16F5F8u: goto label_16f5f8;
            case 0x16F5FCu: goto label_16f5fc;
            case 0x16F600u: goto label_16f600;
            case 0x16F604u: goto label_16f604;
            case 0x16F608u: goto label_16f608;
            case 0x16F60Cu: goto label_16f60c;
            case 0x16F610u: goto label_16f610;
            case 0x16F614u: goto label_16f614;
            case 0x16F618u: goto label_16f618;
            case 0x16F61Cu: goto label_16f61c;
            case 0x16F620u: goto label_16f620;
            case 0x16F624u: goto label_16f624;
            case 0x16F628u: goto label_16f628;
            case 0x16F62Cu: goto label_16f62c;
            case 0x16F630u: goto label_16f630;
            case 0x16F634u: goto label_16f634;
            case 0x16F638u: goto label_16f638;
            case 0x16F63Cu: goto label_16f63c;
            case 0x16F640u: goto label_16f640;
            case 0x16F644u: goto label_16f644;
            case 0x16F648u: goto label_16f648;
            case 0x16F64Cu: goto label_16f64c;
            case 0x16F650u: goto label_16f650;
            case 0x16F654u: goto label_16f654;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16F654u;
label_16f654:
    // 0x16f654: 0x0
    ctx->pc = 0x16f654u;
    // NOP
}
