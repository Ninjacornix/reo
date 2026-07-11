#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00100218
// Address: 0x100218 - 0x100590
void sub_00100218_0x100218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x100218u;

label_100218:
    // 0x100218: 0x8047742
label_10021c:
    if (ctx->pc == 0x10021Cu) {
        ctx->pc = 0x100220u;
        goto label_100220;
    }
    ctx->pc = 0x100218u;
    ctx->pc = 0x11DD08u;
    sub_0011DD08_0x11dd08(rdram, ctx, runtime); return;
    ctx->pc = 0x100220u;
label_100220:
    // 0x100220: 0x24030023
    ctx->pc = 0x100220u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 35));
label_100224:
    // 0x100224: 0xc
    ctx->pc = 0x100224u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
label_100228:
    // 0x100228: 0x0
    ctx->pc = 0x100228u;
    // NOP
label_10022c:
    // 0x10022c: 0x0
    ctx->pc = 0x10022cu;
    // NOP
label_100230:
    // 0x100230: 0x27bdffd0
    ctx->pc = 0x100230u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
label_100234:
    // 0x100234: 0xffb10010
    ctx->pc = 0x100234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
label_100238:
    // 0x100238: 0x80882d
    ctx->pc = 0x100238u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_10023c:
    // 0x10023c: 0xffbf0020
    ctx->pc = 0x10023cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
label_100240:
    // 0x100240: 0xffb00000
    ctx->pc = 0x100240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_100244:
    // 0x100244: 0xc04035e
label_100248:
    if (ctx->pc == 0x100248u) {
        ctx->pc = 0x100248u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x10024Cu;
        goto label_10024c;
    }
    ctx->pc = 0x100244u;
    SET_GPR_U32(ctx, 31, 0x10024Cu);
    ctx->pc = 0x100248u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x100D78u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10024Cu; }
    }
    if (ctx->pc != 0x10024Cu) { return; }
    ctx->pc = 0x10024Cu;
label_10024c:
    // 0x10024c: 0x1440000d
label_100250:
    if (ctx->pc == 0x100250u) {
        ctx->pc = 0x100250u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x100254u;
        goto label_100254;
    }
    ctx->pc = 0x10024Cu;
    {
        const bool branch_taken_0x10024c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x100250u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x10024c) {
            ctx->pc = 0x100284u;
            goto label_100284;
        }
    }
    ctx->pc = 0x100254u;
label_100254:
    // 0x100254: 0xc047598
label_100258:
    if (ctx->pc == 0x100258u) {
        ctx->pc = 0x10025Cu;
        goto label_10025c;
    }
    ctx->pc = 0x100254u;
    SET_GPR_U32(ctx, 31, 0x10025Cu);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10025Cu; }
    }
    if (ctx->pc != 0x10025Cu) { return; }
    ctx->pc = 0x10025Cu;
label_10025c:
    // 0x10025c: 0x3c030026
    ctx->pc = 0x10025cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
label_100260:
    // 0x100260: 0x3c040026
    ctx->pc = 0x100260u;
    SET_GPR_U32(ctx, 4, ((uint32_t)38 << 16));
label_100264:
    // 0x100264: 0x8c709f80
    ctx->pc = 0x100264u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 3), 4294942592)));
label_100268:
    // 0x100268: 0xac719f80
    ctx->pc = 0x100268u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942592), GPR_U32(ctx, 17));
label_10026c:
    // 0x10026c: 0xac9c9f84
    ctx->pc = 0x10026cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294942596), GPR_U32(ctx, 28));
label_100270:
    // 0x100270: 0x10400004
label_100274:
    if (ctx->pc == 0x100274u) {
        ctx->pc = 0x100274u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x100278u;
        goto label_100278;
    }
    ctx->pc = 0x100270u;
    {
        const bool branch_taken_0x100270 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x100274u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x100270) {
            ctx->pc = 0x100284u;
            goto label_100284;
        }
    }
    ctx->pc = 0x100278u;
label_100278:
    // 0x100278: 0xc0475ae
label_10027c:
    if (ctx->pc == 0x10027Cu) {
        ctx->pc = 0x100280u;
        goto label_100280;
    }
    ctx->pc = 0x100278u;
    SET_GPR_U32(ctx, 31, 0x100280u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100280u; }
    }
    if (ctx->pc != 0x100280u) { return; }
    ctx->pc = 0x100280u;
label_100280:
    // 0x100280: 0x200102d
    ctx->pc = 0x100280u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_100284:
    // 0x100284: 0xdfbf0020
    ctx->pc = 0x100284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_100288:
    // 0x100288: 0xdfb10010
    ctx->pc = 0x100288u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_10028c:
    // 0x10028c: 0xdfb00000
    ctx->pc = 0x10028cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_100290:
    // 0x100290: 0x3e00008
label_100294:
    if (ctx->pc == 0x100294u) {
        ctx->pc = 0x100294u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x100298u;
        goto label_100298;
    }
    ctx->pc = 0x100290u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100294u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100218u: goto label_100218;
            case 0x10021Cu: goto label_10021c;
            case 0x100220u: goto label_100220;
            case 0x100224u: goto label_100224;
            case 0x100228u: goto label_100228;
            case 0x10022Cu: goto label_10022c;
            case 0x100230u: goto label_100230;
            case 0x100234u: goto label_100234;
            case 0x100238u: goto label_100238;
            case 0x10023Cu: goto label_10023c;
            case 0x100240u: goto label_100240;
            case 0x100244u: goto label_100244;
            case 0x100248u: goto label_100248;
            case 0x10024Cu: goto label_10024c;
            case 0x100250u: goto label_100250;
            case 0x100254u: goto label_100254;
            case 0x100258u: goto label_100258;
            case 0x10025Cu: goto label_10025c;
            case 0x100260u: goto label_100260;
            case 0x100264u: goto label_100264;
            case 0x100268u: goto label_100268;
            case 0x10026Cu: goto label_10026c;
            case 0x100270u: goto label_100270;
            case 0x100274u: goto label_100274;
            case 0x100278u: goto label_100278;
            case 0x10027Cu: goto label_10027c;
            case 0x100280u: goto label_100280;
            case 0x100284u: goto label_100284;
            case 0x100288u: goto label_100288;
            case 0x10028Cu: goto label_10028c;
            case 0x100290u: goto label_100290;
            case 0x100294u: goto label_100294;
            case 0x100298u: goto label_100298;
            case 0x10029Cu: goto label_10029c;
            case 0x1002A0u: goto label_1002a0;
            case 0x1002A4u: goto label_1002a4;
            case 0x1002A8u: goto label_1002a8;
            case 0x1002ACu: goto label_1002ac;
            case 0x1002B0u: goto label_1002b0;
            case 0x1002B4u: goto label_1002b4;
            case 0x1002B8u: goto label_1002b8;
            case 0x1002BCu: goto label_1002bc;
            case 0x1002C0u: goto label_1002c0;
            case 0x1002C4u: goto label_1002c4;
            case 0x1002C8u: goto label_1002c8;
            case 0x1002CCu: goto label_1002cc;
            case 0x1002D0u: goto label_1002d0;
            case 0x1002D4u: goto label_1002d4;
            case 0x1002D8u: goto label_1002d8;
            case 0x1002DCu: goto label_1002dc;
            case 0x1002E0u: goto label_1002e0;
            case 0x1002E4u: goto label_1002e4;
            case 0x1002E8u: goto label_1002e8;
            case 0x1002ECu: goto label_1002ec;
            case 0x1002F0u: goto label_1002f0;
            case 0x1002F4u: goto label_1002f4;
            case 0x1002F8u: goto label_1002f8;
            case 0x1002FCu: goto label_1002fc;
            case 0x100300u: goto label_100300;
            case 0x100304u: goto label_100304;
            case 0x100308u: goto label_100308;
            case 0x10030Cu: goto label_10030c;
            case 0x100310u: goto label_100310;
            case 0x100314u: goto label_100314;
            case 0x100318u: goto label_100318;
            case 0x10031Cu: goto label_10031c;
            case 0x100320u: goto label_100320;
            case 0x100324u: goto label_100324;
            case 0x100328u: goto label_100328;
            case 0x10032Cu: goto label_10032c;
            case 0x100330u: goto label_100330;
            case 0x100334u: goto label_100334;
            case 0x100338u: goto label_100338;
            case 0x10033Cu: goto label_10033c;
            case 0x100340u: goto label_100340;
            case 0x100344u: goto label_100344;
            case 0x100348u: goto label_100348;
            case 0x10034Cu: goto label_10034c;
            case 0x100350u: goto label_100350;
            case 0x100354u: goto label_100354;
            case 0x100358u: goto label_100358;
            case 0x10035Cu: goto label_10035c;
            case 0x100360u: goto label_100360;
            case 0x100364u: goto label_100364;
            case 0x100368u: goto label_100368;
            case 0x10036Cu: goto label_10036c;
            case 0x100370u: goto label_100370;
            case 0x100374u: goto label_100374;
            case 0x100378u: goto label_100378;
            case 0x10037Cu: goto label_10037c;
            case 0x100380u: goto label_100380;
            case 0x100384u: goto label_100384;
            case 0x100388u: goto label_100388;
            case 0x10038Cu: goto label_10038c;
            case 0x100390u: goto label_100390;
            case 0x100394u: goto label_100394;
            case 0x100398u: goto label_100398;
            case 0x10039Cu: goto label_10039c;
            case 0x1003A0u: goto label_1003a0;
            case 0x1003A4u: goto label_1003a4;
            case 0x1003A8u: goto label_1003a8;
            case 0x1003ACu: goto label_1003ac;
            case 0x1003B0u: goto label_1003b0;
            case 0x1003B4u: goto label_1003b4;
            case 0x1003B8u: goto label_1003b8;
            case 0x1003BCu: goto label_1003bc;
            case 0x1003C0u: goto label_1003c0;
            case 0x1003C4u: goto label_1003c4;
            case 0x1003C8u: goto label_1003c8;
            case 0x1003CCu: goto label_1003cc;
            case 0x1003D0u: goto label_1003d0;
            case 0x1003D4u: goto label_1003d4;
            case 0x1003D8u: goto label_1003d8;
            case 0x1003DCu: goto label_1003dc;
            case 0x1003E0u: goto label_1003e0;
            case 0x1003E4u: goto label_1003e4;
            case 0x1003E8u: goto label_1003e8;
            case 0x1003ECu: goto label_1003ec;
            case 0x1003F0u: goto label_1003f0;
            case 0x1003F4u: goto label_1003f4;
            case 0x1003F8u: goto label_1003f8;
            case 0x1003FCu: goto label_1003fc;
            case 0x100400u: goto label_100400;
            case 0x100404u: goto label_100404;
            case 0x100408u: goto label_100408;
            case 0x10040Cu: goto label_10040c;
            case 0x100410u: goto label_100410;
            case 0x100414u: goto label_100414;
            case 0x100418u: goto label_100418;
            case 0x10041Cu: goto label_10041c;
            case 0x100420u: goto label_100420;
            case 0x100424u: goto label_100424;
            case 0x100428u: goto label_100428;
            case 0x10042Cu: goto label_10042c;
            case 0x100430u: goto label_100430;
            case 0x100434u: goto label_100434;
            case 0x100438u: goto label_100438;
            case 0x10043Cu: goto label_10043c;
            case 0x100440u: goto label_100440;
            case 0x100444u: goto label_100444;
            case 0x100448u: goto label_100448;
            case 0x10044Cu: goto label_10044c;
            case 0x100450u: goto label_100450;
            case 0x100454u: goto label_100454;
            case 0x100458u: goto label_100458;
            case 0x10045Cu: goto label_10045c;
            case 0x100460u: goto label_100460;
            case 0x100464u: goto label_100464;
            case 0x100468u: goto label_100468;
            case 0x10046Cu: goto label_10046c;
            case 0x100470u: goto label_100470;
            case 0x100474u: goto label_100474;
            case 0x100478u: goto label_100478;
            case 0x10047Cu: goto label_10047c;
            case 0x100480u: goto label_100480;
            case 0x100484u: goto label_100484;
            case 0x100488u: goto label_100488;
            case 0x10048Cu: goto label_10048c;
            case 0x100490u: goto label_100490;
            case 0x100494u: goto label_100494;
            case 0x100498u: goto label_100498;
            case 0x10049Cu: goto label_10049c;
            case 0x1004A0u: goto label_1004a0;
            case 0x1004A4u: goto label_1004a4;
            case 0x1004A8u: goto label_1004a8;
            case 0x1004ACu: goto label_1004ac;
            case 0x1004B0u: goto label_1004b0;
            case 0x1004B4u: goto label_1004b4;
            case 0x1004B8u: goto label_1004b8;
            case 0x1004BCu: goto label_1004bc;
            case 0x1004C0u: goto label_1004c0;
            case 0x1004C4u: goto label_1004c4;
            case 0x1004C8u: goto label_1004c8;
            case 0x1004CCu: goto label_1004cc;
            case 0x1004D0u: goto label_1004d0;
            case 0x1004D4u: goto label_1004d4;
            case 0x1004D8u: goto label_1004d8;
            case 0x1004DCu: goto label_1004dc;
            case 0x1004E0u: goto label_1004e0;
            case 0x1004E4u: goto label_1004e4;
            case 0x1004E8u: goto label_1004e8;
            case 0x1004ECu: goto label_1004ec;
            case 0x1004F0u: goto label_1004f0;
            case 0x1004F4u: goto label_1004f4;
            case 0x1004F8u: goto label_1004f8;
            case 0x1004FCu: goto label_1004fc;
            case 0x100500u: goto label_100500;
            case 0x100504u: goto label_100504;
            case 0x100508u: goto label_100508;
            case 0x10050Cu: goto label_10050c;
            case 0x100510u: goto label_100510;
            case 0x100514u: goto label_100514;
            case 0x100518u: goto label_100518;
            case 0x10051Cu: goto label_10051c;
            case 0x100520u: goto label_100520;
            case 0x100524u: goto label_100524;
            case 0x100528u: goto label_100528;
            case 0x10052Cu: goto label_10052c;
            case 0x100530u: goto label_100530;
            case 0x100534u: goto label_100534;
            case 0x100538u: goto label_100538;
            case 0x10053Cu: goto label_10053c;
            case 0x100540u: goto label_100540;
            case 0x100544u: goto label_100544;
            case 0x100548u: goto label_100548;
            case 0x10054Cu: goto label_10054c;
            case 0x100550u: goto label_100550;
            case 0x100554u: goto label_100554;
            case 0x100558u: goto label_100558;
            case 0x10055Cu: goto label_10055c;
            case 0x100560u: goto label_100560;
            case 0x100564u: goto label_100564;
            case 0x100568u: goto label_100568;
            case 0x10056Cu: goto label_10056c;
            case 0x100570u: goto label_100570;
            case 0x100574u: goto label_100574;
            case 0x100578u: goto label_100578;
            case 0x10057Cu: goto label_10057c;
            case 0x100580u: goto label_100580;
            case 0x100584u: goto label_100584;
            case 0x100588u: goto label_100588;
            case 0x10058Cu: goto label_10058c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100298u;
label_100298:
    // 0x100298: 0x27bdffe0
    ctx->pc = 0x100298u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_10029c:
    // 0x10029c: 0x2405000b
    ctx->pc = 0x10029cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 11));
label_1002a0:
    // 0x1002a0: 0xffb00000
    ctx->pc = 0x1002a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_1002a4:
    // 0x1002a4: 0xffbf0010
    ctx->pc = 0x1002a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
label_1002a8:
    // 0x1002a8: 0x3c100020
    ctx->pc = 0x1002a8u;
    SET_GPR_U32(ctx, 16, ((uint32_t)32 << 16));
label_1002ac:
    // 0x1002ac: 0x8c830000
    ctx->pc = 0x1002acu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_1002b0:
    // 0x1002b0: 0x3c040020
    ctx->pc = 0x1002b0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32 << 16));
label_1002b4:
    // 0x1002b4: 0xae037958
    ctx->pc = 0x1002b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 3));
label_1002b8:
    // 0x1002b8: 0x8e027958
    ctx->pc = 0x1002b8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 31064)));
label_1002bc:
    // 0x1002bc: 0xac82795c
    ctx->pc = 0x1002bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 31068), GPR_U32(ctx, 2));
label_1002c0:
    // 0x1002c0: 0x8e037958
    ctx->pc = 0x1002c0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 31064)));
label_1002c4:
    // 0x1002c4: 0x14650006
label_1002c8:
    if (ctx->pc == 0x1002C8u) {
        ctx->pc = 0x1002C8u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        ctx->pc = 0x1002CCu;
        goto label_1002cc;
    }
    ctx->pc = 0x1002C4u;
    {
        const bool branch_taken_0x1002c4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 5));
        ctx->pc = 0x1002C8u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x1002c4) {
            ctx->pc = 0x1002E0u;
            goto label_1002e0;
        }
    }
    ctx->pc = 0x1002CCu;
label_1002cc:
    // 0x1002cc: 0xae007958
    ctx->pc = 0x1002ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
label_1002d0:
    // 0x1002d0: 0x3c020020
    ctx->pc = 0x1002d0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
label_1002d4:
    // 0x1002d4: 0xac407934
    ctx->pc = 0x1002d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31028), GPR_U32(ctx, 0));
label_1002d8:
    // 0x1002d8: 0x10000014
label_1002dc:
    if (ctx->pc == 0x1002DCu) {
        ctx->pc = 0x1002DCu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->pc = 0x1002E0u;
        goto label_1002e0;
    }
    ctx->pc = 0x1002D8u;
    {
        const bool branch_taken_0x1002d8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1002DCu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x1002d8) {
            ctx->pc = 0x10032Cu;
            goto label_10032c;
        }
    }
    ctx->pc = 0x1002E0u;
label_1002e0:
    // 0x1002e0: 0x8c447928
    ctx->pc = 0x1002e0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 31016)));
label_1002e4:
    // 0x1002e4: 0xc045194
label_1002e8:
    if (ctx->pc == 0x1002E8u) {
        ctx->pc = 0x1002ECu;
        goto label_1002ec;
    }
    ctx->pc = 0x1002E4u;
    SET_GPR_U32(ctx, 31, 0x1002ECu);
    ctx->pc = 0x114650u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1002ECu; }
    }
    if (ctx->pc != 0x1002ECu) { return; }
    ctx->pc = 0x1002ECu;
label_1002ec:
    // 0x1002ec: 0x3c030020
    ctx->pc = 0x1002ecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
label_1002f0:
    // 0x1002f0: 0x8c627914
    ctx->pc = 0x1002f0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 30996)));
label_1002f4:
    // 0x1002f4: 0x10400009
label_1002f8:
    if (ctx->pc == 0x1002F8u) {
        ctx->pc = 0x1002F8u;
        SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
        ctx->pc = 0x1002FCu;
        goto label_1002fc;
    }
    ctx->pc = 0x1002F4u;
    {
        const bool branch_taken_0x1002f4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1002F8u;
        SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
        if (branch_taken_0x1002f4) {
            ctx->pc = 0x10031Cu;
            goto label_10031c;
        }
    }
    ctx->pc = 0x1002FCu;
label_1002fc:
    // 0x1002fc: 0x8c439f80
    ctx->pc = 0x1002fcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4294942592)));
label_100300:
    // 0x100300: 0x10600006
label_100304:
    if (ctx->pc == 0x100304u) {
        ctx->pc = 0x100304u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        ctx->pc = 0x100308u;
        goto label_100308;
    }
    ctx->pc = 0x100300u;
    {
        const bool branch_taken_0x100300 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x100304u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x100300) {
            ctx->pc = 0x10031Cu;
            goto label_10031c;
        }
    }
    ctx->pc = 0x100308u;
label_100308:
    // 0x100308: 0x8c447920
    ctx->pc = 0x100308u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 31008)));
label_10030c:
    // 0x10030c: 0xc045194
label_100310:
    if (ctx->pc == 0x100310u) {
        ctx->pc = 0x100314u;
        goto label_100314;
    }
    ctx->pc = 0x10030Cu;
    SET_GPR_U32(ctx, 31, 0x100314u);
    ctx->pc = 0x114650u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100314u; }
    }
    if (ctx->pc != 0x100314u) { return; }
    ctx->pc = 0x100314u;
label_100314:
    // 0x100314: 0x10000003
label_100318:
    if (ctx->pc == 0x100318u) {
        ctx->pc = 0x10031Cu;
        goto label_10031c;
    }
    ctx->pc = 0x100314u;
    {
        const bool branch_taken_0x100314 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x100314) {
            ctx->pc = 0x100324u;
            goto label_100324;
        }
    }
    ctx->pc = 0x10031Cu;
label_10031c:
    // 0x10031c: 0x3c020020
    ctx->pc = 0x10031cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
label_100320:
    // 0x100320: 0xac407934
    ctx->pc = 0x100320u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31028), GPR_U32(ctx, 0));
label_100324:
    // 0x100324: 0xae007958
    ctx->pc = 0x100324u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
label_100328:
    // 0x100328: 0xdfbf0010
    ctx->pc = 0x100328u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_10032c:
    // 0x10032c: 0xdfb00000
    ctx->pc = 0x10032cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_100330:
    // 0x100330: 0x3e00008
label_100334:
    if (ctx->pc == 0x100334u) {
        ctx->pc = 0x100334u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x100338u;
        goto label_100338;
    }
    ctx->pc = 0x100330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100334u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100218u: goto label_100218;
            case 0x10021Cu: goto label_10021c;
            case 0x100220u: goto label_100220;
            case 0x100224u: goto label_100224;
            case 0x100228u: goto label_100228;
            case 0x10022Cu: goto label_10022c;
            case 0x100230u: goto label_100230;
            case 0x100234u: goto label_100234;
            case 0x100238u: goto label_100238;
            case 0x10023Cu: goto label_10023c;
            case 0x100240u: goto label_100240;
            case 0x100244u: goto label_100244;
            case 0x100248u: goto label_100248;
            case 0x10024Cu: goto label_10024c;
            case 0x100250u: goto label_100250;
            case 0x100254u: goto label_100254;
            case 0x100258u: goto label_100258;
            case 0x10025Cu: goto label_10025c;
            case 0x100260u: goto label_100260;
            case 0x100264u: goto label_100264;
            case 0x100268u: goto label_100268;
            case 0x10026Cu: goto label_10026c;
            case 0x100270u: goto label_100270;
            case 0x100274u: goto label_100274;
            case 0x100278u: goto label_100278;
            case 0x10027Cu: goto label_10027c;
            case 0x100280u: goto label_100280;
            case 0x100284u: goto label_100284;
            case 0x100288u: goto label_100288;
            case 0x10028Cu: goto label_10028c;
            case 0x100290u: goto label_100290;
            case 0x100294u: goto label_100294;
            case 0x100298u: goto label_100298;
            case 0x10029Cu: goto label_10029c;
            case 0x1002A0u: goto label_1002a0;
            case 0x1002A4u: goto label_1002a4;
            case 0x1002A8u: goto label_1002a8;
            case 0x1002ACu: goto label_1002ac;
            case 0x1002B0u: goto label_1002b0;
            case 0x1002B4u: goto label_1002b4;
            case 0x1002B8u: goto label_1002b8;
            case 0x1002BCu: goto label_1002bc;
            case 0x1002C0u: goto label_1002c0;
            case 0x1002C4u: goto label_1002c4;
            case 0x1002C8u: goto label_1002c8;
            case 0x1002CCu: goto label_1002cc;
            case 0x1002D0u: goto label_1002d0;
            case 0x1002D4u: goto label_1002d4;
            case 0x1002D8u: goto label_1002d8;
            case 0x1002DCu: goto label_1002dc;
            case 0x1002E0u: goto label_1002e0;
            case 0x1002E4u: goto label_1002e4;
            case 0x1002E8u: goto label_1002e8;
            case 0x1002ECu: goto label_1002ec;
            case 0x1002F0u: goto label_1002f0;
            case 0x1002F4u: goto label_1002f4;
            case 0x1002F8u: goto label_1002f8;
            case 0x1002FCu: goto label_1002fc;
            case 0x100300u: goto label_100300;
            case 0x100304u: goto label_100304;
            case 0x100308u: goto label_100308;
            case 0x10030Cu: goto label_10030c;
            case 0x100310u: goto label_100310;
            case 0x100314u: goto label_100314;
            case 0x100318u: goto label_100318;
            case 0x10031Cu: goto label_10031c;
            case 0x100320u: goto label_100320;
            case 0x100324u: goto label_100324;
            case 0x100328u: goto label_100328;
            case 0x10032Cu: goto label_10032c;
            case 0x100330u: goto label_100330;
            case 0x100334u: goto label_100334;
            case 0x100338u: goto label_100338;
            case 0x10033Cu: goto label_10033c;
            case 0x100340u: goto label_100340;
            case 0x100344u: goto label_100344;
            case 0x100348u: goto label_100348;
            case 0x10034Cu: goto label_10034c;
            case 0x100350u: goto label_100350;
            case 0x100354u: goto label_100354;
            case 0x100358u: goto label_100358;
            case 0x10035Cu: goto label_10035c;
            case 0x100360u: goto label_100360;
            case 0x100364u: goto label_100364;
            case 0x100368u: goto label_100368;
            case 0x10036Cu: goto label_10036c;
            case 0x100370u: goto label_100370;
            case 0x100374u: goto label_100374;
            case 0x100378u: goto label_100378;
            case 0x10037Cu: goto label_10037c;
            case 0x100380u: goto label_100380;
            case 0x100384u: goto label_100384;
            case 0x100388u: goto label_100388;
            case 0x10038Cu: goto label_10038c;
            case 0x100390u: goto label_100390;
            case 0x100394u: goto label_100394;
            case 0x100398u: goto label_100398;
            case 0x10039Cu: goto label_10039c;
            case 0x1003A0u: goto label_1003a0;
            case 0x1003A4u: goto label_1003a4;
            case 0x1003A8u: goto label_1003a8;
            case 0x1003ACu: goto label_1003ac;
            case 0x1003B0u: goto label_1003b0;
            case 0x1003B4u: goto label_1003b4;
            case 0x1003B8u: goto label_1003b8;
            case 0x1003BCu: goto label_1003bc;
            case 0x1003C0u: goto label_1003c0;
            case 0x1003C4u: goto label_1003c4;
            case 0x1003C8u: goto label_1003c8;
            case 0x1003CCu: goto label_1003cc;
            case 0x1003D0u: goto label_1003d0;
            case 0x1003D4u: goto label_1003d4;
            case 0x1003D8u: goto label_1003d8;
            case 0x1003DCu: goto label_1003dc;
            case 0x1003E0u: goto label_1003e0;
            case 0x1003E4u: goto label_1003e4;
            case 0x1003E8u: goto label_1003e8;
            case 0x1003ECu: goto label_1003ec;
            case 0x1003F0u: goto label_1003f0;
            case 0x1003F4u: goto label_1003f4;
            case 0x1003F8u: goto label_1003f8;
            case 0x1003FCu: goto label_1003fc;
            case 0x100400u: goto label_100400;
            case 0x100404u: goto label_100404;
            case 0x100408u: goto label_100408;
            case 0x10040Cu: goto label_10040c;
            case 0x100410u: goto label_100410;
            case 0x100414u: goto label_100414;
            case 0x100418u: goto label_100418;
            case 0x10041Cu: goto label_10041c;
            case 0x100420u: goto label_100420;
            case 0x100424u: goto label_100424;
            case 0x100428u: goto label_100428;
            case 0x10042Cu: goto label_10042c;
            case 0x100430u: goto label_100430;
            case 0x100434u: goto label_100434;
            case 0x100438u: goto label_100438;
            case 0x10043Cu: goto label_10043c;
            case 0x100440u: goto label_100440;
            case 0x100444u: goto label_100444;
            case 0x100448u: goto label_100448;
            case 0x10044Cu: goto label_10044c;
            case 0x100450u: goto label_100450;
            case 0x100454u: goto label_100454;
            case 0x100458u: goto label_100458;
            case 0x10045Cu: goto label_10045c;
            case 0x100460u: goto label_100460;
            case 0x100464u: goto label_100464;
            case 0x100468u: goto label_100468;
            case 0x10046Cu: goto label_10046c;
            case 0x100470u: goto label_100470;
            case 0x100474u: goto label_100474;
            case 0x100478u: goto label_100478;
            case 0x10047Cu: goto label_10047c;
            case 0x100480u: goto label_100480;
            case 0x100484u: goto label_100484;
            case 0x100488u: goto label_100488;
            case 0x10048Cu: goto label_10048c;
            case 0x100490u: goto label_100490;
            case 0x100494u: goto label_100494;
            case 0x100498u: goto label_100498;
            case 0x10049Cu: goto label_10049c;
            case 0x1004A0u: goto label_1004a0;
            case 0x1004A4u: goto label_1004a4;
            case 0x1004A8u: goto label_1004a8;
            case 0x1004ACu: goto label_1004ac;
            case 0x1004B0u: goto label_1004b0;
            case 0x1004B4u: goto label_1004b4;
            case 0x1004B8u: goto label_1004b8;
            case 0x1004BCu: goto label_1004bc;
            case 0x1004C0u: goto label_1004c0;
            case 0x1004C4u: goto label_1004c4;
            case 0x1004C8u: goto label_1004c8;
            case 0x1004CCu: goto label_1004cc;
            case 0x1004D0u: goto label_1004d0;
            case 0x1004D4u: goto label_1004d4;
            case 0x1004D8u: goto label_1004d8;
            case 0x1004DCu: goto label_1004dc;
            case 0x1004E0u: goto label_1004e0;
            case 0x1004E4u: goto label_1004e4;
            case 0x1004E8u: goto label_1004e8;
            case 0x1004ECu: goto label_1004ec;
            case 0x1004F0u: goto label_1004f0;
            case 0x1004F4u: goto label_1004f4;
            case 0x1004F8u: goto label_1004f8;
            case 0x1004FCu: goto label_1004fc;
            case 0x100500u: goto label_100500;
            case 0x100504u: goto label_100504;
            case 0x100508u: goto label_100508;
            case 0x10050Cu: goto label_10050c;
            case 0x100510u: goto label_100510;
            case 0x100514u: goto label_100514;
            case 0x100518u: goto label_100518;
            case 0x10051Cu: goto label_10051c;
            case 0x100520u: goto label_100520;
            case 0x100524u: goto label_100524;
            case 0x100528u: goto label_100528;
            case 0x10052Cu: goto label_10052c;
            case 0x100530u: goto label_100530;
            case 0x100534u: goto label_100534;
            case 0x100538u: goto label_100538;
            case 0x10053Cu: goto label_10053c;
            case 0x100540u: goto label_100540;
            case 0x100544u: goto label_100544;
            case 0x100548u: goto label_100548;
            case 0x10054Cu: goto label_10054c;
            case 0x100550u: goto label_100550;
            case 0x100554u: goto label_100554;
            case 0x100558u: goto label_100558;
            case 0x10055Cu: goto label_10055c;
            case 0x100560u: goto label_100560;
            case 0x100564u: goto label_100564;
            case 0x100568u: goto label_100568;
            case 0x10056Cu: goto label_10056c;
            case 0x100570u: goto label_100570;
            case 0x100574u: goto label_100574;
            case 0x100578u: goto label_100578;
            case 0x10057Cu: goto label_10057c;
            case 0x100580u: goto label_100580;
            case 0x100584u: goto label_100584;
            case 0x100588u: goto label_100588;
            case 0x10058Cu: goto label_10058c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100338u;
label_100338:
    // 0x100338: 0x27bdff60
    ctx->pc = 0x100338u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967136));
label_10033c:
    // 0x10033c: 0xffbe0080
    ctx->pc = 0x10033cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 30));
label_100340:
    // 0x100340: 0xffb70070
    ctx->pc = 0x100340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
label_100344:
    // 0x100344: 0x3c1e0026
    ctx->pc = 0x100344u;
    SET_GPR_U32(ctx, 30, ((uint32_t)38 << 16));
label_100348:
    // 0x100348: 0xffb60060
    ctx->pc = 0x100348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
label_10034c:
    // 0x10034c: 0x3c170020
    ctx->pc = 0x10034cu;
    SET_GPR_U32(ctx, 23, ((uint32_t)32 << 16));
label_100350:
    // 0x100350: 0xffb50050
    ctx->pc = 0x100350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
label_100354:
    // 0x100354: 0x3c160023
    ctx->pc = 0x100354u;
    SET_GPR_U32(ctx, 22, ((uint32_t)35 << 16));
label_100358:
    // 0x100358: 0xffb40040
    ctx->pc = 0x100358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
label_10035c:
    // 0x10035c: 0x3c150026
    ctx->pc = 0x10035cu;
    SET_GPR_U32(ctx, 21, ((uint32_t)38 << 16));
label_100360:
    // 0x100360: 0xffb30030
    ctx->pc = 0x100360u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
label_100364:
    // 0x100364: 0x3c140020
    ctx->pc = 0x100364u;
    SET_GPR_U32(ctx, 20, ((uint32_t)32 << 16));
label_100368:
    // 0x100368: 0xffb20020
    ctx->pc = 0x100368u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
label_10036c:
    // 0x10036c: 0x3c130020
    ctx->pc = 0x10036cu;
    SET_GPR_U32(ctx, 19, ((uint32_t)32 << 16));
label_100370:
    // 0x100370: 0xffb10010
    ctx->pc = 0x100370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
label_100374:
    // 0x100374: 0x3c120026
    ctx->pc = 0x100374u;
    SET_GPR_U32(ctx, 18, ((uint32_t)38 << 16));
label_100378:
    // 0x100378: 0xffbf0090
    ctx->pc = 0x100378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
label_10037c:
    // 0x10037c: 0x3c110020
    ctx->pc = 0x10037cu;
    SET_GPR_U32(ctx, 17, ((uint32_t)32 << 16));
label_100380:
    // 0x100380: 0xffb00000
    ctx->pc = 0x100380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_100384:
    // 0x100384: 0x3c020020
    ctx->pc = 0x100384u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
label_100388:
    // 0x100388: 0xc045198
label_10038c:
    if (ctx->pc == 0x10038Cu) {
        ctx->pc = 0x10038Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 31008)));
        ctx->pc = 0x100390u;
        goto label_100390;
    }
    ctx->pc = 0x100388u;
    SET_GPR_U32(ctx, 31, 0x100390u);
    ctx->pc = 0x10038Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 31008)));
    ctx->pc = 0x114660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100390u; }
    }
    if (ctx->pc != 0x100390u) { return; }
    ctx->pc = 0x100390u;
label_100390:
    // 0x100390: 0x8e837958
    ctx->pc = 0x100390u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 20), 31064)));
label_100394:
    // 0x100394: 0x2402ffff
    ctx->pc = 0x100394u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_100398:
    // 0x100398: 0x14620008
label_10039c:
    if (ctx->pc == 0x10039Cu) {
        ctx->pc = 0x10039Cu;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 23), 30992)));
        ctx->pc = 0x1003A0u;
        goto label_1003a0;
    }
    ctx->pc = 0x100398u;
    {
        const bool branch_taken_0x100398 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x10039Cu;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 23), 30992)));
        if (branch_taken_0x100398) {
            ctx->pc = 0x1003BCu;
            goto label_1003bc;
        }
    }
    ctx->pc = 0x1003A0u;
label_1003a0:
    // 0x1003a0: 0xae607934
    ctx->pc = 0x1003a0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 31028), GPR_U32(ctx, 0));
label_1003a4:
    // 0x1003a4: 0x3c020020
    ctx->pc = 0x1003a4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
label_1003a8:
    // 0x1003a8: 0xae807958
    ctx->pc = 0x1003a8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 31064), GPR_U32(ctx, 0));
label_1003ac:
    // 0x1003ac: 0x0
    ctx->pc = 0x1003acu;
    // NOP
label_1003b0:
    // 0x1003b0: 0xc045118
label_1003b4:
    if (ctx->pc == 0x1003B4u) {
        ctx->pc = 0x1003B4u;
        WRITE32(ADD32(GPR_U32(ctx, 30), 4294942612), GPR_U32(ctx, 0));
        ctx->pc = 0x1003B8u;
        goto label_1003b8;
    }
    ctx->pc = 0x1003B0u;
    SET_GPR_U32(ctx, 31, 0x1003B8u);
    ctx->pc = 0x1003B4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4294942612), GPR_U32(ctx, 0));
    ctx->pc = 0x114460u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114460_0x114460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003B8u; }
    }
    if (ctx->pc != 0x1003B8u) { return; }
    ctx->pc = 0x1003B8u;
label_1003b8:
    // 0x1003b8: 0x8ee27910
    ctx->pc = 0x1003b8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 23), 30992)));
label_1003bc:
    // 0x1003bc: 0x18400004
label_1003c0:
    if (ctx->pc == 0x1003C0u) {
        ctx->pc = 0x1003C0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 22), 29824));
        ctx->pc = 0x1003C4u;
        goto label_1003c4;
    }
    ctx->pc = 0x1003BCu;
    {
        const bool branch_taken_0x1003bc = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1003C0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 22), 29824));
        if (branch_taken_0x1003bc) {
            ctx->pc = 0x1003D0u;
            goto label_1003d0;
        }
    }
    ctx->pc = 0x1003C4u;
label_1003c4:
    // 0x1003c4: 0x8e459f80
    ctx->pc = 0x1003c4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 4294942592)));
label_1003c8:
    // 0x1003c8: 0xc045a12
label_1003cc:
    if (ctx->pc == 0x1003CCu) {
        ctx->pc = 0x1003CCu;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 31068)));
        ctx->pc = 0x1003D0u;
        goto label_1003d0;
    }
    ctx->pc = 0x1003C8u;
    SET_GPR_U32(ctx, 31, 0x1003D0u);
    ctx->pc = 0x1003CCu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 31068)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003D0u; }
    }
    if (ctx->pc != 0x1003D0u) { return; }
    ctx->pc = 0x1003D0u;
label_1003d0:
    // 0x1003d0: 0x8e439f80
    ctx->pc = 0x1003d0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 4294942592)));
label_1003d4:
    // 0x1003d4: 0x10600009
label_1003d8:
    if (ctx->pc == 0x1003D8u) {
        ctx->pc = 0x1003DCu;
        goto label_1003dc;
    }
    ctx->pc = 0x1003D4u;
    {
        const bool branch_taken_0x1003d4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x1003d4) {
            ctx->pc = 0x1003FCu;
            goto label_1003fc;
        }
    }
    ctx->pc = 0x1003DCu;
label_1003dc:
    // 0x1003dc: 0x8e22795c
    ctx->pc = 0x1003dcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 31068)));
label_1003e0:
    // 0x1003e0: 0x10400006
label_1003e4:
    if (ctx->pc == 0x1003E4u) {
        ctx->pc = 0x1003E8u;
        goto label_1003e8;
    }
    ctx->pc = 0x1003E0u;
    {
        const bool branch_taken_0x1003e0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1003e0) {
            ctx->pc = 0x1003FCu;
            goto label_1003fc;
        }
    }
    ctx->pc = 0x1003E8u;
label_1003e8:
    // 0x1003e8: 0x380802d
    ctx->pc = 0x1003e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
label_1003ec:
    // 0x1003ec: 0x8ebc9f84
    ctx->pc = 0x1003ecu;
    SET_GPR_U32(ctx, 28, READ32(ADD32(GPR_U32(ctx, 21), 4294942596)));
label_1003f0:
    // 0x1003f0: 0x60f809
label_1003f4:
    if (ctx->pc == 0x1003F4u) {
        ctx->pc = 0x1003F4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 31068)));
        ctx->pc = 0x1003F8u;
        goto label_1003f8;
    }
    ctx->pc = 0x1003F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1003F8u);
        ctx->pc = 0x1003F4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 31068)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100218u: goto label_100218;
            case 0x10021Cu: goto label_10021c;
            case 0x100220u: goto label_100220;
            case 0x100224u: goto label_100224;
            case 0x100228u: goto label_100228;
            case 0x10022Cu: goto label_10022c;
            case 0x100230u: goto label_100230;
            case 0x100234u: goto label_100234;
            case 0x100238u: goto label_100238;
            case 0x10023Cu: goto label_10023c;
            case 0x100240u: goto label_100240;
            case 0x100244u: goto label_100244;
            case 0x100248u: goto label_100248;
            case 0x10024Cu: goto label_10024c;
            case 0x100250u: goto label_100250;
            case 0x100254u: goto label_100254;
            case 0x100258u: goto label_100258;
            case 0x10025Cu: goto label_10025c;
            case 0x100260u: goto label_100260;
            case 0x100264u: goto label_100264;
            case 0x100268u: goto label_100268;
            case 0x10026Cu: goto label_10026c;
            case 0x100270u: goto label_100270;
            case 0x100274u: goto label_100274;
            case 0x100278u: goto label_100278;
            case 0x10027Cu: goto label_10027c;
            case 0x100280u: goto label_100280;
            case 0x100284u: goto label_100284;
            case 0x100288u: goto label_100288;
            case 0x10028Cu: goto label_10028c;
            case 0x100290u: goto label_100290;
            case 0x100294u: goto label_100294;
            case 0x100298u: goto label_100298;
            case 0x10029Cu: goto label_10029c;
            case 0x1002A0u: goto label_1002a0;
            case 0x1002A4u: goto label_1002a4;
            case 0x1002A8u: goto label_1002a8;
            case 0x1002ACu: goto label_1002ac;
            case 0x1002B0u: goto label_1002b0;
            case 0x1002B4u: goto label_1002b4;
            case 0x1002B8u: goto label_1002b8;
            case 0x1002BCu: goto label_1002bc;
            case 0x1002C0u: goto label_1002c0;
            case 0x1002C4u: goto label_1002c4;
            case 0x1002C8u: goto label_1002c8;
            case 0x1002CCu: goto label_1002cc;
            case 0x1002D0u: goto label_1002d0;
            case 0x1002D4u: goto label_1002d4;
            case 0x1002D8u: goto label_1002d8;
            case 0x1002DCu: goto label_1002dc;
            case 0x1002E0u: goto label_1002e0;
            case 0x1002E4u: goto label_1002e4;
            case 0x1002E8u: goto label_1002e8;
            case 0x1002ECu: goto label_1002ec;
            case 0x1002F0u: goto label_1002f0;
            case 0x1002F4u: goto label_1002f4;
            case 0x1002F8u: goto label_1002f8;
            case 0x1002FCu: goto label_1002fc;
            case 0x100300u: goto label_100300;
            case 0x100304u: goto label_100304;
            case 0x100308u: goto label_100308;
            case 0x10030Cu: goto label_10030c;
            case 0x100310u: goto label_100310;
            case 0x100314u: goto label_100314;
            case 0x100318u: goto label_100318;
            case 0x10031Cu: goto label_10031c;
            case 0x100320u: goto label_100320;
            case 0x100324u: goto label_100324;
            case 0x100328u: goto label_100328;
            case 0x10032Cu: goto label_10032c;
            case 0x100330u: goto label_100330;
            case 0x100334u: goto label_100334;
            case 0x100338u: goto label_100338;
            case 0x10033Cu: goto label_10033c;
            case 0x100340u: goto label_100340;
            case 0x100344u: goto label_100344;
            case 0x100348u: goto label_100348;
            case 0x10034Cu: goto label_10034c;
            case 0x100350u: goto label_100350;
            case 0x100354u: goto label_100354;
            case 0x100358u: goto label_100358;
            case 0x10035Cu: goto label_10035c;
            case 0x100360u: goto label_100360;
            case 0x100364u: goto label_100364;
            case 0x100368u: goto label_100368;
            case 0x10036Cu: goto label_10036c;
            case 0x100370u: goto label_100370;
            case 0x100374u: goto label_100374;
            case 0x100378u: goto label_100378;
            case 0x10037Cu: goto label_10037c;
            case 0x100380u: goto label_100380;
            case 0x100384u: goto label_100384;
            case 0x100388u: goto label_100388;
            case 0x10038Cu: goto label_10038c;
            case 0x100390u: goto label_100390;
            case 0x100394u: goto label_100394;
            case 0x100398u: goto label_100398;
            case 0x10039Cu: goto label_10039c;
            case 0x1003A0u: goto label_1003a0;
            case 0x1003A4u: goto label_1003a4;
            case 0x1003A8u: goto label_1003a8;
            case 0x1003ACu: goto label_1003ac;
            case 0x1003B0u: goto label_1003b0;
            case 0x1003B4u: goto label_1003b4;
            case 0x1003B8u: goto label_1003b8;
            case 0x1003BCu: goto label_1003bc;
            case 0x1003C0u: goto label_1003c0;
            case 0x1003C4u: goto label_1003c4;
            case 0x1003C8u: goto label_1003c8;
            case 0x1003CCu: goto label_1003cc;
            case 0x1003D0u: goto label_1003d0;
            case 0x1003D4u: goto label_1003d4;
            case 0x1003D8u: goto label_1003d8;
            case 0x1003DCu: goto label_1003dc;
            case 0x1003E0u: goto label_1003e0;
            case 0x1003E4u: goto label_1003e4;
            case 0x1003E8u: goto label_1003e8;
            case 0x1003ECu: goto label_1003ec;
            case 0x1003F0u: goto label_1003f0;
            case 0x1003F4u: goto label_1003f4;
            case 0x1003F8u: goto label_1003f8;
            case 0x1003FCu: goto label_1003fc;
            case 0x100400u: goto label_100400;
            case 0x100404u: goto label_100404;
            case 0x100408u: goto label_100408;
            case 0x10040Cu: goto label_10040c;
            case 0x100410u: goto label_100410;
            case 0x100414u: goto label_100414;
            case 0x100418u: goto label_100418;
            case 0x10041Cu: goto label_10041c;
            case 0x100420u: goto label_100420;
            case 0x100424u: goto label_100424;
            case 0x100428u: goto label_100428;
            case 0x10042Cu: goto label_10042c;
            case 0x100430u: goto label_100430;
            case 0x100434u: goto label_100434;
            case 0x100438u: goto label_100438;
            case 0x10043Cu: goto label_10043c;
            case 0x100440u: goto label_100440;
            case 0x100444u: goto label_100444;
            case 0x100448u: goto label_100448;
            case 0x10044Cu: goto label_10044c;
            case 0x100450u: goto label_100450;
            case 0x100454u: goto label_100454;
            case 0x100458u: goto label_100458;
            case 0x10045Cu: goto label_10045c;
            case 0x100460u: goto label_100460;
            case 0x100464u: goto label_100464;
            case 0x100468u: goto label_100468;
            case 0x10046Cu: goto label_10046c;
            case 0x100470u: goto label_100470;
            case 0x100474u: goto label_100474;
            case 0x100478u: goto label_100478;
            case 0x10047Cu: goto label_10047c;
            case 0x100480u: goto label_100480;
            case 0x100484u: goto label_100484;
            case 0x100488u: goto label_100488;
            case 0x10048Cu: goto label_10048c;
            case 0x100490u: goto label_100490;
            case 0x100494u: goto label_100494;
            case 0x100498u: goto label_100498;
            case 0x10049Cu: goto label_10049c;
            case 0x1004A0u: goto label_1004a0;
            case 0x1004A4u: goto label_1004a4;
            case 0x1004A8u: goto label_1004a8;
            case 0x1004ACu: goto label_1004ac;
            case 0x1004B0u: goto label_1004b0;
            case 0x1004B4u: goto label_1004b4;
            case 0x1004B8u: goto label_1004b8;
            case 0x1004BCu: goto label_1004bc;
            case 0x1004C0u: goto label_1004c0;
            case 0x1004C4u: goto label_1004c4;
            case 0x1004C8u: goto label_1004c8;
            case 0x1004CCu: goto label_1004cc;
            case 0x1004D0u: goto label_1004d0;
            case 0x1004D4u: goto label_1004d4;
            case 0x1004D8u: goto label_1004d8;
            case 0x1004DCu: goto label_1004dc;
            case 0x1004E0u: goto label_1004e0;
            case 0x1004E4u: goto label_1004e4;
            case 0x1004E8u: goto label_1004e8;
            case 0x1004ECu: goto label_1004ec;
            case 0x1004F0u: goto label_1004f0;
            case 0x1004F4u: goto label_1004f4;
            case 0x1004F8u: goto label_1004f8;
            case 0x1004FCu: goto label_1004fc;
            case 0x100500u: goto label_100500;
            case 0x100504u: goto label_100504;
            case 0x100508u: goto label_100508;
            case 0x10050Cu: goto label_10050c;
            case 0x100510u: goto label_100510;
            case 0x100514u: goto label_100514;
            case 0x100518u: goto label_100518;
            case 0x10051Cu: goto label_10051c;
            case 0x100520u: goto label_100520;
            case 0x100524u: goto label_100524;
            case 0x100528u: goto label_100528;
            case 0x10052Cu: goto label_10052c;
            case 0x100530u: goto label_100530;
            case 0x100534u: goto label_100534;
            case 0x100538u: goto label_100538;
            case 0x10053Cu: goto label_10053c;
            case 0x100540u: goto label_100540;
            case 0x100544u: goto label_100544;
            case 0x100548u: goto label_100548;
            case 0x10054Cu: goto label_10054c;
            case 0x100550u: goto label_100550;
            case 0x100554u: goto label_100554;
            case 0x100558u: goto label_100558;
            case 0x10055Cu: goto label_10055c;
            case 0x100560u: goto label_100560;
            case 0x100564u: goto label_100564;
            case 0x100568u: goto label_100568;
            case 0x10056Cu: goto label_10056c;
            case 0x100570u: goto label_100570;
            case 0x100574u: goto label_100574;
            case 0x100578u: goto label_100578;
            case 0x10057Cu: goto label_10057c;
            case 0x100580u: goto label_100580;
            case 0x100584u: goto label_100584;
            case 0x100588u: goto label_100588;
            case 0x10058Cu: goto label_10058c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1003F8u; }
            if (ctx->pc != 0x1003F8u) { return; }
        }
    }
    ctx->pc = 0x1003F8u;
label_1003f8:
    // 0x1003f8: 0x200e02d
    ctx->pc = 0x1003f8u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1003fc:
    // 0x1003fc: 0xae607934
    ctx->pc = 0x1003fcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 31028), GPR_U32(ctx, 0));
label_100400:
    // 0x100400: 0x1000ffe1
label_100404:
    if (ctx->pc == 0x100404u) {
        ctx->pc = 0x100404u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        ctx->pc = 0x100408u;
        goto label_100408;
    }
    ctx->pc = 0x100400u;
    {
        const bool branch_taken_0x100400 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100404u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x100400) {
            ctx->pc = 0x100388u;
            goto label_100388;
        }
    }
    ctx->pc = 0x100408u;
label_100408:
    // 0x100408: 0x27bdffa0
    ctx->pc = 0x100408u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
label_10040c:
    // 0x10040c: 0xffb40040
    ctx->pc = 0x10040cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
label_100410:
    // 0x100410: 0xffb10010
    ctx->pc = 0x100410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
label_100414:
    // 0x100414: 0x3c140020
    ctx->pc = 0x100414u;
    SET_GPR_U32(ctx, 20, ((uint32_t)32 << 16));
label_100418:
    // 0x100418: 0x80882d
    ctx->pc = 0x100418u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_10041c:
    // 0x10041c: 0xffb30030
    ctx->pc = 0x10041cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
label_100420:
    // 0x100420: 0xffb20020
    ctx->pc = 0x100420u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
label_100424:
    // 0x100424: 0x24130001
    ctx->pc = 0x100424u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 0), 1));
label_100428:
    // 0x100428: 0xffb00000
    ctx->pc = 0x100428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_10042c:
    // 0x10042c: 0xa0902d
    ctx->pc = 0x10042cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_100430:
    // 0x100430: 0x8e847914
    ctx->pc = 0x100430u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 20), 30996)));
label_100434:
    // 0x100434: 0xc0802d
    ctx->pc = 0x100434u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_100438:
    // 0x100438: 0x1480001a
label_10043c:
    if (ctx->pc == 0x10043Cu) {
        ctx->pc = 0x10043Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
        ctx->pc = 0x100440u;
        goto label_100440;
    }
    ctx->pc = 0x100438u;
    {
        const bool branch_taken_0x100438 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x10043Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
        if (branch_taken_0x100438) {
            ctx->pc = 0x1004A4u;
            goto label_1004a4;
        }
    }
    ctx->pc = 0x100440u;
label_100440:
    // 0x100440: 0xc045144
label_100444:
    if (ctx->pc == 0x100444u) {
        ctx->pc = 0x100448u;
        goto label_100448;
    }
    ctx->pc = 0x100440u;
    SET_GPR_U32(ctx, 31, 0x100448u);
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100448u; }
    }
    if (ctx->pc != 0x100448u) { return; }
    ctx->pc = 0x100448u;
label_100448:
    // 0x100448: 0x3c030026
    ctx->pc = 0x100448u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
label_10044c:
    // 0x10044c: 0x3c050026
    ctx->pc = 0x10044cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)38 << 16));
label_100450:
    // 0x100450: 0xac629f98
    ctx->pc = 0x100450u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942616), GPR_U32(ctx, 2));
label_100454:
    // 0x100454: 0x40202d
    ctx->pc = 0x100454u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_100458:
    // 0x100458: 0xc045148
label_10045c:
    if (ctx->pc == 0x10045Cu) {
        ctx->pc = 0x10045Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294942624));
        ctx->pc = 0x100460u;
        goto label_100460;
    }
    ctx->pc = 0x100458u;
    SET_GPR_U32(ctx, 31, 0x100460u);
    ctx->pc = 0x10045Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294942624));
    ctx->pc = 0x114520u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100460u; }
    }
    if (ctx->pc != 0x100460u) { return; }
    ctx->pc = 0x100460u;
label_100460:
    // 0x100460: 0x3c030026
    ctx->pc = 0x100460u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
label_100464:
    // 0x100464: 0x3c020010
    ctx->pc = 0x100464u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
label_100468:
    // 0x100468: 0x24639fd0
    ctx->pc = 0x100468u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294942672));
label_10046c:
    // 0x10046c: 0x24420338
    ctx->pc = 0x10046cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 824));
label_100470:
    // 0x100470: 0xac70000c
    ctx->pc = 0x100470u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 16));
label_100474:
    // 0x100474: 0x60202d
    ctx->pc = 0x100474u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_100478:
    // 0x100478: 0xac620004
    ctx->pc = 0x100478u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
label_10047c:
    // 0x10047c: 0xac720008
    ctx->pc = 0x10047cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 18));
label_100480:
    // 0x100480: 0xac710014
    ctx->pc = 0x100480u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 17));
label_100484:
    // 0x100484: 0xc045108
label_100488:
    if (ctx->pc == 0x100488u) {
        ctx->pc = 0x100488u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
        ctx->pc = 0x10048Cu;
        goto label_10048c;
    }
    ctx->pc = 0x100484u;
    SET_GPR_U32(ctx, 31, 0x10048Cu);
    ctx->pc = 0x100488u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
    ctx->pc = 0x114420u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10048Cu; }
    }
    if (ctx->pc != 0x10048Cu) { return; }
    ctx->pc = 0x10048Cu;
label_10048c:
    // 0x10048c: 0x282d
    ctx->pc = 0x10048cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_100490:
    // 0x100490: 0xae827914
    ctx->pc = 0x100490u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 30996), GPR_U32(ctx, 2));
label_100494:
    // 0x100494: 0xc045110
label_100498:
    if (ctx->pc == 0x100498u) {
        ctx->pc = 0x100498u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x10049Cu;
        goto label_10049c;
    }
    ctx->pc = 0x100494u;
    SET_GPR_U32(ctx, 31, 0x10049Cu);
    ctx->pc = 0x100498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x114440u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10049Cu; }
    }
    if (ctx->pc != 0x10049Cu) { return; }
    ctx->pc = 0x10049Cu;
label_10049c:
    // 0x10049c: 0x10000005
label_1004a0:
    if (ctx->pc == 0x1004A0u) {
        ctx->pc = 0x1004A0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1004A4u;
        goto label_1004a4;
    }
    ctx->pc = 0x10049Cu;
    {
        const bool branch_taken_0x10049c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1004A0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x10049c) {
            ctx->pc = 0x1004B4u;
            goto label_1004b4;
        }
    }
    ctx->pc = 0x1004A4u;
label_1004a4:
    // 0x1004a4: 0x220282d
    ctx->pc = 0x1004a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1004a8:
    // 0x1004a8: 0xc04512c
label_1004ac:
    if (ctx->pc == 0x1004ACu) {
        ctx->pc = 0x1004ACu;
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1004B0u;
        goto label_1004b0;
    }
    ctx->pc = 0x1004A8u;
    SET_GPR_U32(ctx, 31, 0x1004B0u);
    ctx->pc = 0x1004ACu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1144B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1004B0u; }
    }
    if (ctx->pc != 0x1004B0u) { return; }
    ctx->pc = 0x1004B0u;
label_1004b0:
    // 0x1004b0: 0x260102d
    ctx->pc = 0x1004b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1004b4:
    // 0x1004b4: 0xdfbf0050
    ctx->pc = 0x1004b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_1004b8:
    // 0x1004b8: 0xdfb40040
    ctx->pc = 0x1004b8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1004bc:
    // 0x1004bc: 0xdfb30030
    ctx->pc = 0x1004bcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1004c0:
    // 0x1004c0: 0xdfb20020
    ctx->pc = 0x1004c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1004c4:
    // 0x1004c4: 0xdfb10010
    ctx->pc = 0x1004c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1004c8:
    // 0x1004c8: 0xdfb00000
    ctx->pc = 0x1004c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1004cc:
    // 0x1004cc: 0x3e00008
label_1004d0:
    if (ctx->pc == 0x1004D0u) {
        ctx->pc = 0x1004D0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = 0x1004D4u;
        goto label_1004d4;
    }
    ctx->pc = 0x1004CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1004D0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100218u: goto label_100218;
            case 0x10021Cu: goto label_10021c;
            case 0x100220u: goto label_100220;
            case 0x100224u: goto label_100224;
            case 0x100228u: goto label_100228;
            case 0x10022Cu: goto label_10022c;
            case 0x100230u: goto label_100230;
            case 0x100234u: goto label_100234;
            case 0x100238u: goto label_100238;
            case 0x10023Cu: goto label_10023c;
            case 0x100240u: goto label_100240;
            case 0x100244u: goto label_100244;
            case 0x100248u: goto label_100248;
            case 0x10024Cu: goto label_10024c;
            case 0x100250u: goto label_100250;
            case 0x100254u: goto label_100254;
            case 0x100258u: goto label_100258;
            case 0x10025Cu: goto label_10025c;
            case 0x100260u: goto label_100260;
            case 0x100264u: goto label_100264;
            case 0x100268u: goto label_100268;
            case 0x10026Cu: goto label_10026c;
            case 0x100270u: goto label_100270;
            case 0x100274u: goto label_100274;
            case 0x100278u: goto label_100278;
            case 0x10027Cu: goto label_10027c;
            case 0x100280u: goto label_100280;
            case 0x100284u: goto label_100284;
            case 0x100288u: goto label_100288;
            case 0x10028Cu: goto label_10028c;
            case 0x100290u: goto label_100290;
            case 0x100294u: goto label_100294;
            case 0x100298u: goto label_100298;
            case 0x10029Cu: goto label_10029c;
            case 0x1002A0u: goto label_1002a0;
            case 0x1002A4u: goto label_1002a4;
            case 0x1002A8u: goto label_1002a8;
            case 0x1002ACu: goto label_1002ac;
            case 0x1002B0u: goto label_1002b0;
            case 0x1002B4u: goto label_1002b4;
            case 0x1002B8u: goto label_1002b8;
            case 0x1002BCu: goto label_1002bc;
            case 0x1002C0u: goto label_1002c0;
            case 0x1002C4u: goto label_1002c4;
            case 0x1002C8u: goto label_1002c8;
            case 0x1002CCu: goto label_1002cc;
            case 0x1002D0u: goto label_1002d0;
            case 0x1002D4u: goto label_1002d4;
            case 0x1002D8u: goto label_1002d8;
            case 0x1002DCu: goto label_1002dc;
            case 0x1002E0u: goto label_1002e0;
            case 0x1002E4u: goto label_1002e4;
            case 0x1002E8u: goto label_1002e8;
            case 0x1002ECu: goto label_1002ec;
            case 0x1002F0u: goto label_1002f0;
            case 0x1002F4u: goto label_1002f4;
            case 0x1002F8u: goto label_1002f8;
            case 0x1002FCu: goto label_1002fc;
            case 0x100300u: goto label_100300;
            case 0x100304u: goto label_100304;
            case 0x100308u: goto label_100308;
            case 0x10030Cu: goto label_10030c;
            case 0x100310u: goto label_100310;
            case 0x100314u: goto label_100314;
            case 0x100318u: goto label_100318;
            case 0x10031Cu: goto label_10031c;
            case 0x100320u: goto label_100320;
            case 0x100324u: goto label_100324;
            case 0x100328u: goto label_100328;
            case 0x10032Cu: goto label_10032c;
            case 0x100330u: goto label_100330;
            case 0x100334u: goto label_100334;
            case 0x100338u: goto label_100338;
            case 0x10033Cu: goto label_10033c;
            case 0x100340u: goto label_100340;
            case 0x100344u: goto label_100344;
            case 0x100348u: goto label_100348;
            case 0x10034Cu: goto label_10034c;
            case 0x100350u: goto label_100350;
            case 0x100354u: goto label_100354;
            case 0x100358u: goto label_100358;
            case 0x10035Cu: goto label_10035c;
            case 0x100360u: goto label_100360;
            case 0x100364u: goto label_100364;
            case 0x100368u: goto label_100368;
            case 0x10036Cu: goto label_10036c;
            case 0x100370u: goto label_100370;
            case 0x100374u: goto label_100374;
            case 0x100378u: goto label_100378;
            case 0x10037Cu: goto label_10037c;
            case 0x100380u: goto label_100380;
            case 0x100384u: goto label_100384;
            case 0x100388u: goto label_100388;
            case 0x10038Cu: goto label_10038c;
            case 0x100390u: goto label_100390;
            case 0x100394u: goto label_100394;
            case 0x100398u: goto label_100398;
            case 0x10039Cu: goto label_10039c;
            case 0x1003A0u: goto label_1003a0;
            case 0x1003A4u: goto label_1003a4;
            case 0x1003A8u: goto label_1003a8;
            case 0x1003ACu: goto label_1003ac;
            case 0x1003B0u: goto label_1003b0;
            case 0x1003B4u: goto label_1003b4;
            case 0x1003B8u: goto label_1003b8;
            case 0x1003BCu: goto label_1003bc;
            case 0x1003C0u: goto label_1003c0;
            case 0x1003C4u: goto label_1003c4;
            case 0x1003C8u: goto label_1003c8;
            case 0x1003CCu: goto label_1003cc;
            case 0x1003D0u: goto label_1003d0;
            case 0x1003D4u: goto label_1003d4;
            case 0x1003D8u: goto label_1003d8;
            case 0x1003DCu: goto label_1003dc;
            case 0x1003E0u: goto label_1003e0;
            case 0x1003E4u: goto label_1003e4;
            case 0x1003E8u: goto label_1003e8;
            case 0x1003ECu: goto label_1003ec;
            case 0x1003F0u: goto label_1003f0;
            case 0x1003F4u: goto label_1003f4;
            case 0x1003F8u: goto label_1003f8;
            case 0x1003FCu: goto label_1003fc;
            case 0x100400u: goto label_100400;
            case 0x100404u: goto label_100404;
            case 0x100408u: goto label_100408;
            case 0x10040Cu: goto label_10040c;
            case 0x100410u: goto label_100410;
            case 0x100414u: goto label_100414;
            case 0x100418u: goto label_100418;
            case 0x10041Cu: goto label_10041c;
            case 0x100420u: goto label_100420;
            case 0x100424u: goto label_100424;
            case 0x100428u: goto label_100428;
            case 0x10042Cu: goto label_10042c;
            case 0x100430u: goto label_100430;
            case 0x100434u: goto label_100434;
            case 0x100438u: goto label_100438;
            case 0x10043Cu: goto label_10043c;
            case 0x100440u: goto label_100440;
            case 0x100444u: goto label_100444;
            case 0x100448u: goto label_100448;
            case 0x10044Cu: goto label_10044c;
            case 0x100450u: goto label_100450;
            case 0x100454u: goto label_100454;
            case 0x100458u: goto label_100458;
            case 0x10045Cu: goto label_10045c;
            case 0x100460u: goto label_100460;
            case 0x100464u: goto label_100464;
            case 0x100468u: goto label_100468;
            case 0x10046Cu: goto label_10046c;
            case 0x100470u: goto label_100470;
            case 0x100474u: goto label_100474;
            case 0x100478u: goto label_100478;
            case 0x10047Cu: goto label_10047c;
            case 0x100480u: goto label_100480;
            case 0x100484u: goto label_100484;
            case 0x100488u: goto label_100488;
            case 0x10048Cu: goto label_10048c;
            case 0x100490u: goto label_100490;
            case 0x100494u: goto label_100494;
            case 0x100498u: goto label_100498;
            case 0x10049Cu: goto label_10049c;
            case 0x1004A0u: goto label_1004a0;
            case 0x1004A4u: goto label_1004a4;
            case 0x1004A8u: goto label_1004a8;
            case 0x1004ACu: goto label_1004ac;
            case 0x1004B0u: goto label_1004b0;
            case 0x1004B4u: goto label_1004b4;
            case 0x1004B8u: goto label_1004b8;
            case 0x1004BCu: goto label_1004bc;
            case 0x1004C0u: goto label_1004c0;
            case 0x1004C4u: goto label_1004c4;
            case 0x1004C8u: goto label_1004c8;
            case 0x1004CCu: goto label_1004cc;
            case 0x1004D0u: goto label_1004d0;
            case 0x1004D4u: goto label_1004d4;
            case 0x1004D8u: goto label_1004d8;
            case 0x1004DCu: goto label_1004dc;
            case 0x1004E0u: goto label_1004e0;
            case 0x1004E4u: goto label_1004e4;
            case 0x1004E8u: goto label_1004e8;
            case 0x1004ECu: goto label_1004ec;
            case 0x1004F0u: goto label_1004f0;
            case 0x1004F4u: goto label_1004f4;
            case 0x1004F8u: goto label_1004f8;
            case 0x1004FCu: goto label_1004fc;
            case 0x100500u: goto label_100500;
            case 0x100504u: goto label_100504;
            case 0x100508u: goto label_100508;
            case 0x10050Cu: goto label_10050c;
            case 0x100510u: goto label_100510;
            case 0x100514u: goto label_100514;
            case 0x100518u: goto label_100518;
            case 0x10051Cu: goto label_10051c;
            case 0x100520u: goto label_100520;
            case 0x100524u: goto label_100524;
            case 0x100528u: goto label_100528;
            case 0x10052Cu: goto label_10052c;
            case 0x100530u: goto label_100530;
            case 0x100534u: goto label_100534;
            case 0x100538u: goto label_100538;
            case 0x10053Cu: goto label_10053c;
            case 0x100540u: goto label_100540;
            case 0x100544u: goto label_100544;
            case 0x100548u: goto label_100548;
            case 0x10054Cu: goto label_10054c;
            case 0x100550u: goto label_100550;
            case 0x100554u: goto label_100554;
            case 0x100558u: goto label_100558;
            case 0x10055Cu: goto label_10055c;
            case 0x100560u: goto label_100560;
            case 0x100564u: goto label_100564;
            case 0x100568u: goto label_100568;
            case 0x10056Cu: goto label_10056c;
            case 0x100570u: goto label_100570;
            case 0x100574u: goto label_100574;
            case 0x100578u: goto label_100578;
            case 0x10057Cu: goto label_10057c;
            case 0x100580u: goto label_100580;
            case 0x100584u: goto label_100584;
            case 0x100588u: goto label_100588;
            case 0x10058Cu: goto label_10058c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1004D4u;
label_1004d4:
    // 0x1004d4: 0x0
    ctx->pc = 0x1004d4u;
    // NOP
label_1004d8:
    // 0x1004d8: 0x3c052000
    ctx->pc = 0x1004d8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)8192 << 16));
label_1004dc:
    // 0x1004dc: 0x853825
    ctx->pc = 0x1004dcu;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
label_1004e0:
    // 0x1004e0: 0x8ce20000
    ctx->pc = 0x1004e0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 0)));
label_1004e4:
    // 0x1004e4: 0x18400014
label_1004e8:
    if (ctx->pc == 0x1004E8u) {
        ctx->pc = 0x1004E8u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1004ECu;
        goto label_1004ec;
    }
    ctx->pc = 0x1004E4u;
    {
        const bool branch_taken_0x1004e4 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1004E8u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1004e4) {
            ctx->pc = 0x100538u;
            goto label_100538;
        }
    }
    ctx->pc = 0x1004ECu;
label_1004ec:
    // 0x1004ec: 0x8ce90008
    ctx->pc = 0x1004ecu;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_1004f0:
    // 0x1004f0: 0x18400011
label_1004f4:
    if (ctx->pc == 0x1004F4u) {
        ctx->pc = 0x1004F4u;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 9), GPR_U32(ctx, 5)));
        ctx->pc = 0x1004F8u;
        goto label_1004f8;
    }
    ctx->pc = 0x1004F0u;
    {
        const bool branch_taken_0x1004f0 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1004F4u;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 9), GPR_U32(ctx, 5)));
        if (branch_taken_0x1004f0) {
            ctx->pc = 0x100538u;
            goto label_100538;
        }
    }
    ctx->pc = 0x1004F8u;
label_1004f8:
    // 0x1004f8: 0x24e80010
    ctx->pc = 0x1004f8u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 7), 16));
label_1004fc:
    // 0x1004fc: 0x3c0b0020
    ctx->pc = 0x1004fcu;
    SET_GPR_U32(ctx, 11, ((uint32_t)32 << 16));
label_100500:
    // 0x100500: 0x1061021
    ctx->pc = 0x100500u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
label_100504:
    // 0x100504: 0x0
    ctx->pc = 0x100504u;
    // NOP
label_100508:
    // 0x100508: 0x1462821
    ctx->pc = 0x100508u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
label_10050c:
    // 0x10050c: 0x90430000
    ctx->pc = 0x10050cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
label_100510:
    // 0x100510: 0x1262021
    ctx->pc = 0x100510u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
label_100514:
    // 0x100514: 0x24c60001
    ctx->pc = 0x100514u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
label_100518:
    // 0x100518: 0xa0a30000
    ctx->pc = 0x100518u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
label_10051c:
    // 0x10051c: 0xa0830000
    ctx->pc = 0x10051cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
label_100520:
    // 0x100520: 0x8ce20000
    ctx->pc = 0x100520u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 0)));
label_100524:
    // 0x100524: 0xc2102a
    ctx->pc = 0x100524u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 6), GPR_S32(ctx, 2)));
label_100528:
    // 0x100528: 0x1440fff7
label_10052c:
    if (ctx->pc == 0x10052Cu) {
        ctx->pc = 0x10052Cu;
        SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
        ctx->pc = 0x100530u;
        goto label_100530;
    }
    ctx->pc = 0x100528u;
    {
        const bool branch_taken_0x100528 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x10052Cu;
        SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
        if (branch_taken_0x100528) {
            ctx->pc = 0x100508u;
            goto label_100508;
        }
    }
    ctx->pc = 0x100530u;
label_100530:
    // 0x100530: 0x10000003
label_100534:
    if (ctx->pc == 0x100534u) {
        ctx->pc = 0x100534u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
        ctx->pc = 0x100538u;
        goto label_100538;
    }
    ctx->pc = 0x100530u;
    {
        const bool branch_taken_0x100530 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100534u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
        if (branch_taken_0x100530) {
            ctx->pc = 0x100540u;
            goto label_100540;
        }
    }
    ctx->pc = 0x100538u;
label_100538:
    // 0x100538: 0x3c0b0020
    ctx->pc = 0x100538u;
    SET_GPR_U32(ctx, 11, ((uint32_t)32 << 16));
label_10053c:
    // 0x10053c: 0x8ce30004
    ctx->pc = 0x10053cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_100540:
    // 0x100540: 0x18600011
label_100544:
    if (ctx->pc == 0x100544u) {
        ctx->pc = 0x100544u;
        SET_GPR_U32(ctx, 2, ((uint32_t)8192 << 16));
        ctx->pc = 0x100548u;
        goto label_100548;
    }
    ctx->pc = 0x100540u;
    {
        const bool branch_taken_0x100540 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x100544u;
        SET_GPR_U32(ctx, 2, ((uint32_t)8192 << 16));
        if (branch_taken_0x100540) {
            ctx->pc = 0x100588u;
            goto label_100588;
        }
    }
    ctx->pc = 0x100548u;
label_100548:
    // 0x100548: 0x8ce9000c
    ctx->pc = 0x100548u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 7), 12)));
label_10054c:
    // 0x10054c: 0x302d
    ctx->pc = 0x10054cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_100550:
    // 0x100550: 0x1860000d
label_100554:
    if (ctx->pc == 0x100554u) {
        ctx->pc = 0x100554u;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
        ctx->pc = 0x100558u;
        goto label_100558;
    }
    ctx->pc = 0x100550u;
    {
        const bool branch_taken_0x100550 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x100554u;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
        if (branch_taken_0x100550) {
            ctx->pc = 0x100588u;
            goto label_100588;
        }
    }
    ctx->pc = 0x100558u;
label_100558:
    // 0x100558: 0x24e80050
    ctx->pc = 0x100558u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 7), 80));
label_10055c:
    // 0x10055c: 0x1061021
    ctx->pc = 0x10055cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
label_100560:
    // 0x100560: 0x1462821
    ctx->pc = 0x100560u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
label_100564:
    // 0x100564: 0x90430000
    ctx->pc = 0x100564u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
label_100568:
    // 0x100568: 0x1262021
    ctx->pc = 0x100568u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
label_10056c:
    // 0x10056c: 0x24c60001
    ctx->pc = 0x10056cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
label_100570:
    // 0x100570: 0xa0a30000
    ctx->pc = 0x100570u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
label_100574:
    // 0x100574: 0xa0830000
    ctx->pc = 0x100574u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
label_100578:
    // 0x100578: 0x8ce20004
    ctx->pc = 0x100578u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_10057c:
    // 0x10057c: 0xc2102a
    ctx->pc = 0x10057cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 6), GPR_S32(ctx, 2)));
label_100580:
    // 0x100580: 0x1440fff7
label_100584:
    if (ctx->pc == 0x100584u) {
        ctx->pc = 0x100584u;
        SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
        ctx->pc = 0x100588u;
        goto label_100588;
    }
    ctx->pc = 0x100580u;
    {
        const bool branch_taken_0x100580 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x100584u;
        SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
        if (branch_taken_0x100580) {
            ctx->pc = 0x100560u;
            goto label_100560;
        }
    }
    ctx->pc = 0x100588u;
label_100588:
    // 0x100588: 0x80400a6
label_10058c:
    if (ctx->pc == 0x10058Cu) {
        ctx->pc = 0x10058Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 11), 31064));
        ctx->pc = 0x100590u;
        goto label_fallthrough_0x100588;
    }
    ctx->pc = 0x100588u;
    ctx->pc = 0x10058Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 11), 31064));
    ctx->pc = 0x100298u;
    goto label_100298;
label_fallthrough_0x100588:
    ctx->pc = 0x100590u;
}
