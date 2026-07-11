#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00134530
// Address: 0x134530 - 0x1345f0
void sub_00134530_0x134530(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x134530u;

label_134530:
    // 0x134530: 0x27bdffd0
    ctx->pc = 0x134530u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
label_134534:
    // 0x134534: 0xffb30018
    ctx->pc = 0x134534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
label_134538:
    // 0x134538: 0x80982d
    ctx->pc = 0x134538u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_13453c:
    // 0x13453c: 0xffb00000
    ctx->pc = 0x13453cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_134540:
    // 0x134540: 0xffb10008
    ctx->pc = 0x134540u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_134544:
    // 0x134544: 0xffb20010
    ctx->pc = 0x134544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_134548:
    // 0x134548: 0xffb40020
    ctx->pc = 0x134548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
label_13454c:
    // 0x13454c: 0xffbf0028
    ctx->pc = 0x13454cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
label_134550:
    // 0x134550: 0xc04b2ee
label_134554:
    if (ctx->pc == 0x134554u) {
        ctx->pc = 0x134554u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 19), 4)));
        ctx->pc = 0x134558u;
        goto label_134558;
    }
    ctx->pc = 0x134550u;
    SET_GPR_U32(ctx, 31, 0x134558u);
    ctx->pc = 0x134554u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 19), 4)));
    ctx->pc = 0x12CBB8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CBB8_0x12cbb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134558u; }
    }
    if (ctx->pc != 0x134558u) { return; }
    ctx->pc = 0x134558u;
label_134558:
    // 0x134558: 0x24030003
    ctx->pc = 0x134558u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
label_13455c:
    // 0x13455c: 0x5443001c
label_134560:
    if (ctx->pc == 0x134560u) {
        ctx->pc = 0x134560u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x134564u;
        goto label_134564;
    }
    ctx->pc = 0x13455Cu;
    {
        const bool branch_taken_0x13455c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x13455c) {
            ctx->pc = 0x134560u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x1345D0u;
            goto label_1345d0;
        }
    }
    ctx->pc = 0x134564u;
label_134564:
    // 0x134564: 0x8e640004
    ctx->pc = 0x134564u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 19), 4)));
label_134568:
    // 0x134568: 0x902d
    ctx->pc = 0x134568u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13456c:
    // 0x13456c: 0x3c140022
    ctx->pc = 0x13456cu;
    SET_GPR_U32(ctx, 20, ((uint32_t)34 << 16));
label_134570:
    // 0x134570: 0xc04b5ea
label_134574:
    if (ctx->pc == 0x134574u) {
        ctx->pc = 0x134574u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 19), 24));
        ctx->pc = 0x134578u;
        goto label_134578;
    }
    ctx->pc = 0x134570u;
    SET_GPR_U32(ctx, 31, 0x134578u);
    ctx->pc = 0x134574u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 19), 24));
    ctx->pc = 0x12D7A8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7A8_0x12d7a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134578u; }
    }
    if (ctx->pc != 0x134578u) { return; }
    ctx->pc = 0x134578u;
label_134578:
    // 0x134578: 0x40882d
    ctx->pc = 0x134578u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_13457c:
    // 0x13457c: 0x3c020022
    ctx->pc = 0x13457cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_134580:
    // 0x134580: 0x10000002
label_134584:
    if (ctx->pc == 0x134584u) {
        ctx->pc = 0x134584u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294948768), GPR_U32(ctx, 17));
        ctx->pc = 0x134588u;
        goto label_134588;
    }
    ctx->pc = 0x134580u;
    {
        const bool branch_taken_0x134580 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x134584u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294948768), GPR_U32(ctx, 17));
        if (branch_taken_0x134580) {
            ctx->pc = 0x13458Cu;
            goto label_13458c;
        }
    }
    ctx->pc = 0x134588u;
label_134588:
    // 0x134588: 0x26520001
    ctx->pc = 0x134588u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
label_13458c:
    // 0x13458c: 0x251102a
    ctx->pc = 0x13458cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 18), GPR_S32(ctx, 17)));
label_134590:
    // 0x134590: 0x1040000a
label_134594:
    if (ctx->pc == 0x134594u) {
        ctx->pc = 0x134598u;
        goto label_134598;
    }
    ctx->pc = 0x134590u;
    {
        const bool branch_taken_0x134590 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x134590) {
            ctx->pc = 0x1345BCu;
            goto label_1345bc;
        }
    }
    ctx->pc = 0x134598u;
label_134598:
    // 0x134598: 0x8e040000
    ctx->pc = 0x134598u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_13459c:
    // 0x13459c: 0x26100004
    ctx->pc = 0x13459cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4));
label_1345a0:
    // 0x1345a0: 0x8c830000
    ctx->pc = 0x1345a0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_1345a4:
    // 0x1345a4: 0x8c620024
    ctx->pc = 0x1345a4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 36)));
label_1345a8:
    // 0x1345a8: 0x40f809
label_1345ac:
    if (ctx->pc == 0x1345ACu) {
        ctx->pc = 0x1345ACu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1345B0u;
        goto label_1345b0;
    }
    ctx->pc = 0x1345A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1345B0u);
        ctx->pc = 0x1345ACu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134530u: goto label_134530;
            case 0x134534u: goto label_134534;
            case 0x134538u: goto label_134538;
            case 0x13453Cu: goto label_13453c;
            case 0x134540u: goto label_134540;
            case 0x134544u: goto label_134544;
            case 0x134548u: goto label_134548;
            case 0x13454Cu: goto label_13454c;
            case 0x134550u: goto label_134550;
            case 0x134554u: goto label_134554;
            case 0x134558u: goto label_134558;
            case 0x13455Cu: goto label_13455c;
            case 0x134560u: goto label_134560;
            case 0x134564u: goto label_134564;
            case 0x134568u: goto label_134568;
            case 0x13456Cu: goto label_13456c;
            case 0x134570u: goto label_134570;
            case 0x134574u: goto label_134574;
            case 0x134578u: goto label_134578;
            case 0x13457Cu: goto label_13457c;
            case 0x134580u: goto label_134580;
            case 0x134584u: goto label_134584;
            case 0x134588u: goto label_134588;
            case 0x13458Cu: goto label_13458c;
            case 0x134590u: goto label_134590;
            case 0x134594u: goto label_134594;
            case 0x134598u: goto label_134598;
            case 0x13459Cu: goto label_13459c;
            case 0x1345A0u: goto label_1345a0;
            case 0x1345A4u: goto label_1345a4;
            case 0x1345A8u: goto label_1345a8;
            case 0x1345ACu: goto label_1345ac;
            case 0x1345B0u: goto label_1345b0;
            case 0x1345B4u: goto label_1345b4;
            case 0x1345B8u: goto label_1345b8;
            case 0x1345BCu: goto label_1345bc;
            case 0x1345C0u: goto label_1345c0;
            case 0x1345C4u: goto label_1345c4;
            case 0x1345C8u: goto label_1345c8;
            case 0x1345CCu: goto label_1345cc;
            case 0x1345D0u: goto label_1345d0;
            case 0x1345D4u: goto label_1345d4;
            case 0x1345D8u: goto label_1345d8;
            case 0x1345DCu: goto label_1345dc;
            case 0x1345E0u: goto label_1345e0;
            case 0x1345E4u: goto label_1345e4;
            case 0x1345E8u: goto label_1345e8;
            case 0x1345ECu: goto label_1345ec;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1345B0u; }
            if (ctx->pc != 0x1345B0u) { return; }
        }
    }
    ctx->pc = 0x1345B0u;
label_1345b0:
    // 0x1345b0: 0x28430040
    ctx->pc = 0x1345b0u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 2), 64));
label_1345b4:
    // 0x1345b4: 0x1460fff4
label_1345b8:
    if (ctx->pc == 0x1345B8u) {
        ctx->pc = 0x1345B8u;
        WRITE32(ADD32(GPR_U32(ctx, 20), 4294948772), GPR_U32(ctx, 2));
        ctx->pc = 0x1345BCu;
        goto label_1345bc;
    }
    ctx->pc = 0x1345B4u;
    {
        const bool branch_taken_0x1345b4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1345B8u;
        WRITE32(ADD32(GPR_U32(ctx, 20), 4294948772), GPR_U32(ctx, 2));
        if (branch_taken_0x1345b4) {
            ctx->pc = 0x134588u;
            goto label_134588;
        }
    }
    ctx->pc = 0x1345BCu;
label_1345bc:
    // 0x1345bc: 0x16510004
label_1345c0:
    if (ctx->pc == 0x1345C0u) {
        ctx->pc = 0x1345C0u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x1345C4u;
        goto label_1345c4;
    }
    ctx->pc = 0x1345BCu;
    {
        const bool branch_taken_0x1345bc = (GPR_U32(ctx, 18) != GPR_U32(ctx, 17));
        ctx->pc = 0x1345C0u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x1345bc) {
            ctx->pc = 0x1345D0u;
            goto label_1345d0;
        }
    }
    ctx->pc = 0x1345C4u;
label_1345c4:
    // 0x1345c4: 0x24020004
    ctx->pc = 0x1345c4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
label_1345c8:
    // 0x1345c8: 0xae6000a8
    ctx->pc = 0x1345c8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 168), GPR_U32(ctx, 0));
label_1345cc:
    // 0x1345cc: 0xa2620001
    ctx->pc = 0x1345ccu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 2));
label_1345d0:
    // 0x1345d0: 0xdfb10008
    ctx->pc = 0x1345d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_1345d4:
    // 0x1345d4: 0xdfb20010
    ctx->pc = 0x1345d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1345d8:
    // 0x1345d8: 0xdfb30018
    ctx->pc = 0x1345d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_1345dc:
    // 0x1345dc: 0xdfb40020
    ctx->pc = 0x1345dcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1345e0:
    // 0x1345e0: 0xdfbf0028
    ctx->pc = 0x1345e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_1345e4:
    // 0x1345e4: 0x3e00008
label_1345e8:
    if (ctx->pc == 0x1345E8u) {
        ctx->pc = 0x1345E8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x1345ECu;
        goto label_1345ec;
    }
    ctx->pc = 0x1345E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1345E8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134530u: goto label_134530;
            case 0x134534u: goto label_134534;
            case 0x134538u: goto label_134538;
            case 0x13453Cu: goto label_13453c;
            case 0x134540u: goto label_134540;
            case 0x134544u: goto label_134544;
            case 0x134548u: goto label_134548;
            case 0x13454Cu: goto label_13454c;
            case 0x134550u: goto label_134550;
            case 0x134554u: goto label_134554;
            case 0x134558u: goto label_134558;
            case 0x13455Cu: goto label_13455c;
            case 0x134560u: goto label_134560;
            case 0x134564u: goto label_134564;
            case 0x134568u: goto label_134568;
            case 0x13456Cu: goto label_13456c;
            case 0x134570u: goto label_134570;
            case 0x134574u: goto label_134574;
            case 0x134578u: goto label_134578;
            case 0x13457Cu: goto label_13457c;
            case 0x134580u: goto label_134580;
            case 0x134584u: goto label_134584;
            case 0x134588u: goto label_134588;
            case 0x13458Cu: goto label_13458c;
            case 0x134590u: goto label_134590;
            case 0x134594u: goto label_134594;
            case 0x134598u: goto label_134598;
            case 0x13459Cu: goto label_13459c;
            case 0x1345A0u: goto label_1345a0;
            case 0x1345A4u: goto label_1345a4;
            case 0x1345A8u: goto label_1345a8;
            case 0x1345ACu: goto label_1345ac;
            case 0x1345B0u: goto label_1345b0;
            case 0x1345B4u: goto label_1345b4;
            case 0x1345B8u: goto label_1345b8;
            case 0x1345BCu: goto label_1345bc;
            case 0x1345C0u: goto label_1345c0;
            case 0x1345C4u: goto label_1345c4;
            case 0x1345C8u: goto label_1345c8;
            case 0x1345CCu: goto label_1345cc;
            case 0x1345D0u: goto label_1345d0;
            case 0x1345D4u: goto label_1345d4;
            case 0x1345D8u: goto label_1345d8;
            case 0x1345DCu: goto label_1345dc;
            case 0x1345E0u: goto label_1345e0;
            case 0x1345E4u: goto label_1345e4;
            case 0x1345E8u: goto label_1345e8;
            case 0x1345ECu: goto label_1345ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1345ECu;
label_1345ec:
    // 0x1345ec: 0x0
    ctx->pc = 0x1345ecu;
    // NOP
}
