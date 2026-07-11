#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001181F8
// Address: 0x1181f8 - 0x118620
void sub_001181F8_0x1181f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1181f8u;

label_1181f8:
    // 0x1181f8: 0x27bdffd0
    ctx->pc = 0x1181f8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
label_1181fc:
    // 0x1181fc: 0xffb00000
    ctx->pc = 0x1181fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_118200:
    // 0x118200: 0xffb10010
    ctx->pc = 0x118200u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
label_118204:
    // 0x118204: 0x80802d
    ctx->pc = 0x118204u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_118208:
    // 0x118208: 0xffbf0020
    ctx->pc = 0x118208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
label_11820c:
    // 0x11820c: 0xc046044
label_118210:
    if (ctx->pc == 0x118210u) {
        ctx->pc = 0x118210u;
        SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
        ctx->pc = 0x118214u;
        goto label_118214;
    }
    ctx->pc = 0x11820Cu;
    SET_GPR_U32(ctx, 31, 0x118214u);
    ctx->pc = 0x118210u;
    SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
    ctx->pc = 0x118110u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00118110_0x118110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118214u; }
    }
    if (ctx->pc != 0x118214u) { return; }
    ctx->pc = 0x118214u;
label_118214:
    // 0x118214: 0xc045198
label_118218:
    if (ctx->pc == 0x118218u) {
        ctx->pc = 0x118218u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
        ctx->pc = 0x11821Cu;
        goto label_11821c;
    }
    ctx->pc = 0x118214u;
    SET_GPR_U32(ctx, 31, 0x11821Cu);
    ctx->pc = 0x118218u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
    ctx->pc = 0x114660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11821Cu; }
    }
    if (ctx->pc != 0x11821Cu) { return; }
    ctx->pc = 0x11821Cu;
label_11821c:
    // 0x11821c: 0x2e030020
    ctx->pc = 0x11821cu;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 16), 32));
label_118220:
    // 0x118220: 0x14600005
label_118224:
    if (ctx->pc == 0x118224u) {
        ctx->pc = 0x118224u;
        SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
        ctx->pc = 0x118228u;
        goto label_118228;
    }
    ctx->pc = 0x118220u;
    {
        const bool branch_taken_0x118220 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x118224u;
        SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
        if (branch_taken_0x118220) {
            ctx->pc = 0x118238u;
            goto label_118238;
        }
    }
    ctx->pc = 0x118228u;
label_118228:
    // 0x118228: 0xc045190
label_11822c:
    if (ctx->pc == 0x11822Cu) {
        ctx->pc = 0x11822Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
        ctx->pc = 0x118230u;
        goto label_118230;
    }
    ctx->pc = 0x118228u;
    SET_GPR_U32(ctx, 31, 0x118230u);
    ctx->pc = 0x11822Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118230u; }
    }
    if (ctx->pc != 0x118230u) { return; }
    ctx->pc = 0x118230u;
label_118230:
    // 0x118230: 0x10000007
label_118234:
    if (ctx->pc == 0x118234u) {
        ctx->pc = 0x118234u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x118238u;
        goto label_118238;
    }
    ctx->pc = 0x118230u;
    {
        const bool branch_taken_0x118230 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x118234u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x118230) {
            ctx->pc = 0x118250u;
            goto label_118250;
        }
    }
    ctx->pc = 0x118238u;
label_118238:
    // 0x118238: 0x108100
    ctx->pc = 0x118238u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 16), 4));
label_11823c:
    // 0x11823c: 0x2442df40
    ctx->pc = 0x11823cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294958912));
label_118240:
    // 0x118240: 0x8e249de8
    ctx->pc = 0x118240u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
label_118244:
    // 0x118244: 0xc045190
label_118248:
    if (ctx->pc == 0x118248u) {
        ctx->pc = 0x118248u;
        SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->pc = 0x11824Cu;
        goto label_11824c;
    }
    ctx->pc = 0x118244u;
    SET_GPR_U32(ctx, 31, 0x11824Cu);
    ctx->pc = 0x118248u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11824Cu; }
    }
    if (ctx->pc != 0x11824Cu) { return; }
    ctx->pc = 0x11824Cu;
label_11824c:
    // 0x11824c: 0x200102d
    ctx->pc = 0x11824cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_118250:
    // 0x118250: 0xdfbf0020
    ctx->pc = 0x118250u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_118254:
    // 0x118254: 0xdfb10010
    ctx->pc = 0x118254u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_118258:
    // 0x118258: 0xdfb00000
    ctx->pc = 0x118258u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_11825c:
    // 0x11825c: 0x3e00008
label_118260:
    if (ctx->pc == 0x118260u) {
        ctx->pc = 0x118260u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x118264u;
        goto label_118264;
    }
    ctx->pc = 0x11825Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118260u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1181F8u: goto label_1181f8;
            case 0x1181FCu: goto label_1181fc;
            case 0x118200u: goto label_118200;
            case 0x118204u: goto label_118204;
            case 0x118208u: goto label_118208;
            case 0x11820Cu: goto label_11820c;
            case 0x118210u: goto label_118210;
            case 0x118214u: goto label_118214;
            case 0x118218u: goto label_118218;
            case 0x11821Cu: goto label_11821c;
            case 0x118220u: goto label_118220;
            case 0x118224u: goto label_118224;
            case 0x118228u: goto label_118228;
            case 0x11822Cu: goto label_11822c;
            case 0x118230u: goto label_118230;
            case 0x118234u: goto label_118234;
            case 0x118238u: goto label_118238;
            case 0x11823Cu: goto label_11823c;
            case 0x118240u: goto label_118240;
            case 0x118244u: goto label_118244;
            case 0x118248u: goto label_118248;
            case 0x11824Cu: goto label_11824c;
            case 0x118250u: goto label_118250;
            case 0x118254u: goto label_118254;
            case 0x118258u: goto label_118258;
            case 0x11825Cu: goto label_11825c;
            case 0x118260u: goto label_118260;
            case 0x118264u: goto label_118264;
            case 0x118268u: goto label_118268;
            case 0x11826Cu: goto label_11826c;
            case 0x118270u: goto label_118270;
            case 0x118274u: goto label_118274;
            case 0x118278u: goto label_118278;
            case 0x11827Cu: goto label_11827c;
            case 0x118280u: goto label_118280;
            case 0x118284u: goto label_118284;
            case 0x118288u: goto label_118288;
            case 0x11828Cu: goto label_11828c;
            case 0x118290u: goto label_118290;
            case 0x118294u: goto label_118294;
            case 0x118298u: goto label_118298;
            case 0x11829Cu: goto label_11829c;
            case 0x1182A0u: goto label_1182a0;
            case 0x1182A4u: goto label_1182a4;
            case 0x1182A8u: goto label_1182a8;
            case 0x1182ACu: goto label_1182ac;
            case 0x1182B0u: goto label_1182b0;
            case 0x1182B4u: goto label_1182b4;
            case 0x1182B8u: goto label_1182b8;
            case 0x1182BCu: goto label_1182bc;
            case 0x1182C0u: goto label_1182c0;
            case 0x1182C4u: goto label_1182c4;
            case 0x1182C8u: goto label_1182c8;
            case 0x1182CCu: goto label_1182cc;
            case 0x1182D0u: goto label_1182d0;
            case 0x1182D4u: goto label_1182d4;
            case 0x1182D8u: goto label_1182d8;
            case 0x1182DCu: goto label_1182dc;
            case 0x1182E0u: goto label_1182e0;
            case 0x1182E4u: goto label_1182e4;
            case 0x1182E8u: goto label_1182e8;
            case 0x1182ECu: goto label_1182ec;
            case 0x1182F0u: goto label_1182f0;
            case 0x1182F4u: goto label_1182f4;
            case 0x1182F8u: goto label_1182f8;
            case 0x1182FCu: goto label_1182fc;
            case 0x118300u: goto label_118300;
            case 0x118304u: goto label_118304;
            case 0x118308u: goto label_118308;
            case 0x11830Cu: goto label_11830c;
            case 0x118310u: goto label_118310;
            case 0x118314u: goto label_118314;
            case 0x118318u: goto label_118318;
            case 0x11831Cu: goto label_11831c;
            case 0x118320u: goto label_118320;
            case 0x118324u: goto label_118324;
            case 0x118328u: goto label_118328;
            case 0x11832Cu: goto label_11832c;
            case 0x118330u: goto label_118330;
            case 0x118334u: goto label_118334;
            case 0x118338u: goto label_118338;
            case 0x11833Cu: goto label_11833c;
            case 0x118340u: goto label_118340;
            case 0x118344u: goto label_118344;
            case 0x118348u: goto label_118348;
            case 0x11834Cu: goto label_11834c;
            case 0x118350u: goto label_118350;
            case 0x118354u: goto label_118354;
            case 0x118358u: goto label_118358;
            case 0x11835Cu: goto label_11835c;
            case 0x118360u: goto label_118360;
            case 0x118364u: goto label_118364;
            case 0x118368u: goto label_118368;
            case 0x11836Cu: goto label_11836c;
            case 0x118370u: goto label_118370;
            case 0x118374u: goto label_118374;
            case 0x118378u: goto label_118378;
            case 0x11837Cu: goto label_11837c;
            case 0x118380u: goto label_118380;
            case 0x118384u: goto label_118384;
            case 0x118388u: goto label_118388;
            case 0x11838Cu: goto label_11838c;
            case 0x118390u: goto label_118390;
            case 0x118394u: goto label_118394;
            case 0x118398u: goto label_118398;
            case 0x11839Cu: goto label_11839c;
            case 0x1183A0u: goto label_1183a0;
            case 0x1183A4u: goto label_1183a4;
            case 0x1183A8u: goto label_1183a8;
            case 0x1183ACu: goto label_1183ac;
            case 0x1183B0u: goto label_1183b0;
            case 0x1183B4u: goto label_1183b4;
            case 0x1183B8u: goto label_1183b8;
            case 0x1183BCu: goto label_1183bc;
            case 0x1183C0u: goto label_1183c0;
            case 0x1183C4u: goto label_1183c4;
            case 0x1183C8u: goto label_1183c8;
            case 0x1183CCu: goto label_1183cc;
            case 0x1183D0u: goto label_1183d0;
            case 0x1183D4u: goto label_1183d4;
            case 0x1183D8u: goto label_1183d8;
            case 0x1183DCu: goto label_1183dc;
            case 0x1183E0u: goto label_1183e0;
            case 0x1183E4u: goto label_1183e4;
            case 0x1183E8u: goto label_1183e8;
            case 0x1183ECu: goto label_1183ec;
            case 0x1183F0u: goto label_1183f0;
            case 0x1183F4u: goto label_1183f4;
            case 0x1183F8u: goto label_1183f8;
            case 0x1183FCu: goto label_1183fc;
            case 0x118400u: goto label_118400;
            case 0x118404u: goto label_118404;
            case 0x118408u: goto label_118408;
            case 0x11840Cu: goto label_11840c;
            case 0x118410u: goto label_118410;
            case 0x118414u: goto label_118414;
            case 0x118418u: goto label_118418;
            case 0x11841Cu: goto label_11841c;
            case 0x118420u: goto label_118420;
            case 0x118424u: goto label_118424;
            case 0x118428u: goto label_118428;
            case 0x11842Cu: goto label_11842c;
            case 0x118430u: goto label_118430;
            case 0x118434u: goto label_118434;
            case 0x118438u: goto label_118438;
            case 0x11843Cu: goto label_11843c;
            case 0x118440u: goto label_118440;
            case 0x118444u: goto label_118444;
            case 0x118448u: goto label_118448;
            case 0x11844Cu: goto label_11844c;
            case 0x118450u: goto label_118450;
            case 0x118454u: goto label_118454;
            case 0x118458u: goto label_118458;
            case 0x11845Cu: goto label_11845c;
            case 0x118460u: goto label_118460;
            case 0x118464u: goto label_118464;
            case 0x118468u: goto label_118468;
            case 0x11846Cu: goto label_11846c;
            case 0x118470u: goto label_118470;
            case 0x118474u: goto label_118474;
            case 0x118478u: goto label_118478;
            case 0x11847Cu: goto label_11847c;
            case 0x118480u: goto label_118480;
            case 0x118484u: goto label_118484;
            case 0x118488u: goto label_118488;
            case 0x11848Cu: goto label_11848c;
            case 0x118490u: goto label_118490;
            case 0x118494u: goto label_118494;
            case 0x118498u: goto label_118498;
            case 0x11849Cu: goto label_11849c;
            case 0x1184A0u: goto label_1184a0;
            case 0x1184A4u: goto label_1184a4;
            case 0x1184A8u: goto label_1184a8;
            case 0x1184ACu: goto label_1184ac;
            case 0x1184B0u: goto label_1184b0;
            case 0x1184B4u: goto label_1184b4;
            case 0x1184B8u: goto label_1184b8;
            case 0x1184BCu: goto label_1184bc;
            case 0x1184C0u: goto label_1184c0;
            case 0x1184C4u: goto label_1184c4;
            case 0x1184C8u: goto label_1184c8;
            case 0x1184CCu: goto label_1184cc;
            case 0x1184D0u: goto label_1184d0;
            case 0x1184D4u: goto label_1184d4;
            case 0x1184D8u: goto label_1184d8;
            case 0x1184DCu: goto label_1184dc;
            case 0x1184E0u: goto label_1184e0;
            case 0x1184E4u: goto label_1184e4;
            case 0x1184E8u: goto label_1184e8;
            case 0x1184ECu: goto label_1184ec;
            case 0x1184F0u: goto label_1184f0;
            case 0x1184F4u: goto label_1184f4;
            case 0x1184F8u: goto label_1184f8;
            case 0x1184FCu: goto label_1184fc;
            case 0x118500u: goto label_118500;
            case 0x118504u: goto label_118504;
            case 0x118508u: goto label_118508;
            case 0x11850Cu: goto label_11850c;
            case 0x118510u: goto label_118510;
            case 0x118514u: goto label_118514;
            case 0x118518u: goto label_118518;
            case 0x11851Cu: goto label_11851c;
            case 0x118520u: goto label_118520;
            case 0x118524u: goto label_118524;
            case 0x118528u: goto label_118528;
            case 0x11852Cu: goto label_11852c;
            case 0x118530u: goto label_118530;
            case 0x118534u: goto label_118534;
            case 0x118538u: goto label_118538;
            case 0x11853Cu: goto label_11853c;
            case 0x118540u: goto label_118540;
            case 0x118544u: goto label_118544;
            case 0x118548u: goto label_118548;
            case 0x11854Cu: goto label_11854c;
            case 0x118550u: goto label_118550;
            case 0x118554u: goto label_118554;
            case 0x118558u: goto label_118558;
            case 0x11855Cu: goto label_11855c;
            case 0x118560u: goto label_118560;
            case 0x118564u: goto label_118564;
            case 0x118568u: goto label_118568;
            case 0x11856Cu: goto label_11856c;
            case 0x118570u: goto label_118570;
            case 0x118574u: goto label_118574;
            case 0x118578u: goto label_118578;
            case 0x11857Cu: goto label_11857c;
            case 0x118580u: goto label_118580;
            case 0x118584u: goto label_118584;
            case 0x118588u: goto label_118588;
            case 0x11858Cu: goto label_11858c;
            case 0x118590u: goto label_118590;
            case 0x118594u: goto label_118594;
            case 0x118598u: goto label_118598;
            case 0x11859Cu: goto label_11859c;
            case 0x1185A0u: goto label_1185a0;
            case 0x1185A4u: goto label_1185a4;
            case 0x1185A8u: goto label_1185a8;
            case 0x1185ACu: goto label_1185ac;
            case 0x1185B0u: goto label_1185b0;
            case 0x1185B4u: goto label_1185b4;
            case 0x1185B8u: goto label_1185b8;
            case 0x1185BCu: goto label_1185bc;
            case 0x1185C0u: goto label_1185c0;
            case 0x1185C4u: goto label_1185c4;
            case 0x1185C8u: goto label_1185c8;
            case 0x1185CCu: goto label_1185cc;
            case 0x1185D0u: goto label_1185d0;
            case 0x1185D4u: goto label_1185d4;
            case 0x1185D8u: goto label_1185d8;
            case 0x1185DCu: goto label_1185dc;
            case 0x1185E0u: goto label_1185e0;
            case 0x1185E4u: goto label_1185e4;
            case 0x1185E8u: goto label_1185e8;
            case 0x1185ECu: goto label_1185ec;
            case 0x1185F0u: goto label_1185f0;
            case 0x1185F4u: goto label_1185f4;
            case 0x1185F8u: goto label_1185f8;
            case 0x1185FCu: goto label_1185fc;
            case 0x118600u: goto label_118600;
            case 0x118604u: goto label_118604;
            case 0x118608u: goto label_118608;
            case 0x11860Cu: goto label_11860c;
            case 0x118610u: goto label_118610;
            case 0x118614u: goto label_118614;
            case 0x118618u: goto label_118618;
            case 0x11861Cu: goto label_11861c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x118264u;
label_118264:
    // 0x118264: 0x0
    ctx->pc = 0x118264u;
    // NOP
label_118268:
    // 0x118268: 0x3c020021
    ctx->pc = 0x118268u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
label_11826c:
    // 0x11826c: 0x27bdffc0
    ctx->pc = 0x11826cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
label_118270:
    // 0x118270: 0x8c439de0
    ctx->pc = 0x118270u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4294942176)));
label_118274:
    // 0x118274: 0x282d
    ctx->pc = 0x118274u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_118278:
    // 0x118278: 0xffbf0030
    ctx->pc = 0x118278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
label_11827c:
    // 0x11827c: 0x10600002
label_118280:
    if (ctx->pc == 0x118280u) {
        ctx->pc = 0x118280u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
        ctx->pc = 0x118284u;
        goto label_118284;
    }
    ctx->pc = 0x11827Cu;
    {
        const bool branch_taken_0x11827c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x118280u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
        if (branch_taken_0x11827c) {
            ctx->pc = 0x118288u;
            goto label_118288;
        }
    }
    ctx->pc = 0x118284u;
label_118284:
    // 0x118284: 0x8c85000c
    ctx->pc = 0x118284u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 4), 12)));
label_118288:
    // 0x118288: 0x24030440
    ctx->pc = 0x118288u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1088));
label_11828c:
    // 0x11828c: 0x3c020021
    ctx->pc = 0x11828cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
label_118290:
    // 0x118290: 0xa31818
    ctx->pc = 0x118290u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
label_118294:
    // 0x118294: 0x3c040026
    ctx->pc = 0x118294u;
    SET_GPR_U32(ctx, 4, ((uint32_t)38 << 16));
label_118298:
    // 0x118298: 0xac459dd8
    ctx->pc = 0x118298u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294942168), GPR_U32(ctx, 5));
label_11829c:
    // 0x11829c: 0x2484d6c0
    ctx->pc = 0x11829cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294956736));
label_1182a0:
    // 0x1182a0: 0x3c052000
    ctx->pc = 0x1182a0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)8192 << 16));
label_1182a4:
    // 0x1182a4: 0x641821
    ctx->pc = 0x1182a4u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_1182a8:
    // 0x1182a8: 0x658025
    ctx->pc = 0x1182a8u;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_1182ac:
    // 0x1182ac: 0x8a020003
    ctx->pc = 0x1182acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 2, (GPR_U32(ctx, 2) & ~mask) | ((aligned_word << shift) & mask)); }
label_1182b0:
    // 0x1182b0: 0x9a020000
    ctx->pc = 0x1182b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 2, (GPR_U32(ctx, 2) & ~mask) | ((aligned_word >> shift) & mask)); }
label_1182b4:
    // 0x1182b4: 0xaba20003
    ctx->pc = 0x1182b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 3); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 2) >> shift) & mask); WRITE32(aligned_addr, new_data); }
label_1182b8:
    // 0x1182b8: 0xbba20000
    ctx->pc = 0x1182b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 2) << shift) & mask); WRITE32(aligned_addr, new_data); }
label_1182bc:
    // 0x1182bc: 0x8a060007
    ctx->pc = 0x1182bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 6, (GPR_U32(ctx, 6) & ~mask) | ((aligned_word << shift) & mask)); }
label_1182c0:
    // 0x1182c0: 0x9a060004
    ctx->pc = 0x1182c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 4); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 6, (GPR_U32(ctx, 6) & ~mask) | ((aligned_word >> shift) & mask)); }
label_1182c4:
    // 0x1182c4: 0xaba60007
    ctx->pc = 0x1182c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 6) >> shift) & mask); WRITE32(aligned_addr, new_data); }
label_1182c8:
    // 0x1182c8: 0xbba60004
    ctx->pc = 0x1182c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 4); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 6) << shift) & mask); WRITE32(aligned_addr, new_data); }
label_1182cc:
    // 0x1182cc: 0x8a03000b
    ctx->pc = 0x1182ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 3, (GPR_U32(ctx, 3) & ~mask) | ((aligned_word << shift) & mask)); }
label_1182d0:
    // 0x1182d0: 0x9a030008
    ctx->pc = 0x1182d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 3, (GPR_U32(ctx, 3) & ~mask) | ((aligned_word >> shift) & mask)); }
label_1182d4:
    // 0x1182d4: 0xaba3000b
    ctx->pc = 0x1182d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 11); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 3) >> shift) & mask); WRITE32(aligned_addr, new_data); }
label_1182d8:
    // 0x1182d8: 0xbba30008
    ctx->pc = 0x1182d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 3) << shift) & mask); WRITE32(aligned_addr, new_data); }
label_1182dc:
    // 0x1182dc: 0x8a07000f
    ctx->pc = 0x1182dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 7, (GPR_U32(ctx, 7) & ~mask) | ((aligned_word << shift) & mask)); }
label_1182e0:
    // 0x1182e0: 0x9a07000c
    ctx->pc = 0x1182e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 12); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 7, (GPR_U32(ctx, 7) & ~mask) | ((aligned_word >> shift) & mask)); }
label_1182e4:
    // 0x1182e4: 0xaba7000f
    ctx->pc = 0x1182e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 7) >> shift) & mask); WRITE32(aligned_addr, new_data); }
label_1182e8:
    // 0x1182e8: 0xbba7000c
    ctx->pc = 0x1182e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 12); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 7) << shift) & mask); WRITE32(aligned_addr, new_data); }
label_1182ec:
    // 0x1182ec: 0x8fa20000
    ctx->pc = 0x1182ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_1182f0:
    // 0x1182f0: 0x4400004
label_1182f4:
    if (ctx->pc == 0x1182F4u) {
        ctx->pc = 0x1182F4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->pc = 0x1182F8u;
        goto label_1182f8;
    }
    ctx->pc = 0x1182F0u;
    {
        const bool branch_taken_0x1182f0 = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x1182F4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 8)));
        if (branch_taken_0x1182f0) {
            ctx->pc = 0x118304u;
            goto label_118304;
        }
    }
    ctx->pc = 0x1182F8u;
label_1182f8:
    // 0x1182f8: 0x26050010
    ctx->pc = 0x1182f8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 16));
label_1182fc:
    // 0x1182fc: 0xc041eac
label_118300:
    if (ctx->pc == 0x118300u) {
        ctx->pc = 0x118300u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 12)));
        ctx->pc = 0x118304u;
        goto label_118304;
    }
    ctx->pc = 0x1182FCu;
    SET_GPR_U32(ctx, 31, 0x118304u);
    ctx->pc = 0x118300u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 12)));
    ctx->pc = 0x107AB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118304u; }
    }
    if (ctx->pc != 0x118304u) { return; }
    ctx->pc = 0x118304u;
label_118304:
    // 0x118304: 0x8fa20004
    ctx->pc = 0x118304u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_118308:
    // 0x118308: 0x2444fffe
    ctx->pc = 0x118308u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294967294));
label_11830c:
    // 0x11830c: 0x2c830019
    ctx->pc = 0x11830cu;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 4), 25));
label_118310:
    // 0x118310: 0x106000a1
label_118314:
    if (ctx->pc == 0x118314u) {
        ctx->pc = 0x118314u;
        SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
        ctx->pc = 0x118318u;
        goto label_118318;
    }
    ctx->pc = 0x118310u;
    {
        const bool branch_taken_0x118310 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x118314u;
        SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
        if (branch_taken_0x118310) {
            ctx->pc = 0x118598u;
            goto label_118598;
        }
    }
    ctx->pc = 0x118318u;
label_118318:
    // 0x118318: 0x41880
    ctx->pc = 0x118318u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 4), 2));
label_11831c:
    // 0x11831c: 0x24428b20
    ctx->pc = 0x11831cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294937376));
label_118320:
    // 0x118320: 0x621821
    ctx->pc = 0x118320u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_118324:
    // 0x118324: 0x8c640000
    ctx->pc = 0x118324u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_118328:
    // 0x118328: 0x800008
label_11832c:
    if (ctx->pc == 0x11832Cu) {
        ctx->pc = 0x118330u;
        goto label_118330;
    }
    ctx->pc = 0x118328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1181F8u: goto label_1181f8;
            case 0x1181FCu: goto label_1181fc;
            case 0x118200u: goto label_118200;
            case 0x118204u: goto label_118204;
            case 0x118208u: goto label_118208;
            case 0x11820Cu: goto label_11820c;
            case 0x118210u: goto label_118210;
            case 0x118214u: goto label_118214;
            case 0x118218u: goto label_118218;
            case 0x11821Cu: goto label_11821c;
            case 0x118220u: goto label_118220;
            case 0x118224u: goto label_118224;
            case 0x118228u: goto label_118228;
            case 0x11822Cu: goto label_11822c;
            case 0x118230u: goto label_118230;
            case 0x118234u: goto label_118234;
            case 0x118238u: goto label_118238;
            case 0x11823Cu: goto label_11823c;
            case 0x118240u: goto label_118240;
            case 0x118244u: goto label_118244;
            case 0x118248u: goto label_118248;
            case 0x11824Cu: goto label_11824c;
            case 0x118250u: goto label_118250;
            case 0x118254u: goto label_118254;
            case 0x118258u: goto label_118258;
            case 0x11825Cu: goto label_11825c;
            case 0x118260u: goto label_118260;
            case 0x118264u: goto label_118264;
            case 0x118268u: goto label_118268;
            case 0x11826Cu: goto label_11826c;
            case 0x118270u: goto label_118270;
            case 0x118274u: goto label_118274;
            case 0x118278u: goto label_118278;
            case 0x11827Cu: goto label_11827c;
            case 0x118280u: goto label_118280;
            case 0x118284u: goto label_118284;
            case 0x118288u: goto label_118288;
            case 0x11828Cu: goto label_11828c;
            case 0x118290u: goto label_118290;
            case 0x118294u: goto label_118294;
            case 0x118298u: goto label_118298;
            case 0x11829Cu: goto label_11829c;
            case 0x1182A0u: goto label_1182a0;
            case 0x1182A4u: goto label_1182a4;
            case 0x1182A8u: goto label_1182a8;
            case 0x1182ACu: goto label_1182ac;
            case 0x1182B0u: goto label_1182b0;
            case 0x1182B4u: goto label_1182b4;
            case 0x1182B8u: goto label_1182b8;
            case 0x1182BCu: goto label_1182bc;
            case 0x1182C0u: goto label_1182c0;
            case 0x1182C4u: goto label_1182c4;
            case 0x1182C8u: goto label_1182c8;
            case 0x1182CCu: goto label_1182cc;
            case 0x1182D0u: goto label_1182d0;
            case 0x1182D4u: goto label_1182d4;
            case 0x1182D8u: goto label_1182d8;
            case 0x1182DCu: goto label_1182dc;
            case 0x1182E0u: goto label_1182e0;
            case 0x1182E4u: goto label_1182e4;
            case 0x1182E8u: goto label_1182e8;
            case 0x1182ECu: goto label_1182ec;
            case 0x1182F0u: goto label_1182f0;
            case 0x1182F4u: goto label_1182f4;
            case 0x1182F8u: goto label_1182f8;
            case 0x1182FCu: goto label_1182fc;
            case 0x118300u: goto label_118300;
            case 0x118304u: goto label_118304;
            case 0x118308u: goto label_118308;
            case 0x11830Cu: goto label_11830c;
            case 0x118310u: goto label_118310;
            case 0x118314u: goto label_118314;
            case 0x118318u: goto label_118318;
            case 0x11831Cu: goto label_11831c;
            case 0x118320u: goto label_118320;
            case 0x118324u: goto label_118324;
            case 0x118328u: goto label_118328;
            case 0x11832Cu: goto label_11832c;
            case 0x118330u: goto label_118330;
            case 0x118334u: goto label_118334;
            case 0x118338u: goto label_118338;
            case 0x11833Cu: goto label_11833c;
            case 0x118340u: goto label_118340;
            case 0x118344u: goto label_118344;
            case 0x118348u: goto label_118348;
            case 0x11834Cu: goto label_11834c;
            case 0x118350u: goto label_118350;
            case 0x118354u: goto label_118354;
            case 0x118358u: goto label_118358;
            case 0x11835Cu: goto label_11835c;
            case 0x118360u: goto label_118360;
            case 0x118364u: goto label_118364;
            case 0x118368u: goto label_118368;
            case 0x11836Cu: goto label_11836c;
            case 0x118370u: goto label_118370;
            case 0x118374u: goto label_118374;
            case 0x118378u: goto label_118378;
            case 0x11837Cu: goto label_11837c;
            case 0x118380u: goto label_118380;
            case 0x118384u: goto label_118384;
            case 0x118388u: goto label_118388;
            case 0x11838Cu: goto label_11838c;
            case 0x118390u: goto label_118390;
            case 0x118394u: goto label_118394;
            case 0x118398u: goto label_118398;
            case 0x11839Cu: goto label_11839c;
            case 0x1183A0u: goto label_1183a0;
            case 0x1183A4u: goto label_1183a4;
            case 0x1183A8u: goto label_1183a8;
            case 0x1183ACu: goto label_1183ac;
            case 0x1183B0u: goto label_1183b0;
            case 0x1183B4u: goto label_1183b4;
            case 0x1183B8u: goto label_1183b8;
            case 0x1183BCu: goto label_1183bc;
            case 0x1183C0u: goto label_1183c0;
            case 0x1183C4u: goto label_1183c4;
            case 0x1183C8u: goto label_1183c8;
            case 0x1183CCu: goto label_1183cc;
            case 0x1183D0u: goto label_1183d0;
            case 0x1183D4u: goto label_1183d4;
            case 0x1183D8u: goto label_1183d8;
            case 0x1183DCu: goto label_1183dc;
            case 0x1183E0u: goto label_1183e0;
            case 0x1183E4u: goto label_1183e4;
            case 0x1183E8u: goto label_1183e8;
            case 0x1183ECu: goto label_1183ec;
            case 0x1183F0u: goto label_1183f0;
            case 0x1183F4u: goto label_1183f4;
            case 0x1183F8u: goto label_1183f8;
            case 0x1183FCu: goto label_1183fc;
            case 0x118400u: goto label_118400;
            case 0x118404u: goto label_118404;
            case 0x118408u: goto label_118408;
            case 0x11840Cu: goto label_11840c;
            case 0x118410u: goto label_118410;
            case 0x118414u: goto label_118414;
            case 0x118418u: goto label_118418;
            case 0x11841Cu: goto label_11841c;
            case 0x118420u: goto label_118420;
            case 0x118424u: goto label_118424;
            case 0x118428u: goto label_118428;
            case 0x11842Cu: goto label_11842c;
            case 0x118430u: goto label_118430;
            case 0x118434u: goto label_118434;
            case 0x118438u: goto label_118438;
            case 0x11843Cu: goto label_11843c;
            case 0x118440u: goto label_118440;
            case 0x118444u: goto label_118444;
            case 0x118448u: goto label_118448;
            case 0x11844Cu: goto label_11844c;
            case 0x118450u: goto label_118450;
            case 0x118454u: goto label_118454;
            case 0x118458u: goto label_118458;
            case 0x11845Cu: goto label_11845c;
            case 0x118460u: goto label_118460;
            case 0x118464u: goto label_118464;
            case 0x118468u: goto label_118468;
            case 0x11846Cu: goto label_11846c;
            case 0x118470u: goto label_118470;
            case 0x118474u: goto label_118474;
            case 0x118478u: goto label_118478;
            case 0x11847Cu: goto label_11847c;
            case 0x118480u: goto label_118480;
            case 0x118484u: goto label_118484;
            case 0x118488u: goto label_118488;
            case 0x11848Cu: goto label_11848c;
            case 0x118490u: goto label_118490;
            case 0x118494u: goto label_118494;
            case 0x118498u: goto label_118498;
            case 0x11849Cu: goto label_11849c;
            case 0x1184A0u: goto label_1184a0;
            case 0x1184A4u: goto label_1184a4;
            case 0x1184A8u: goto label_1184a8;
            case 0x1184ACu: goto label_1184ac;
            case 0x1184B0u: goto label_1184b0;
            case 0x1184B4u: goto label_1184b4;
            case 0x1184B8u: goto label_1184b8;
            case 0x1184BCu: goto label_1184bc;
            case 0x1184C0u: goto label_1184c0;
            case 0x1184C4u: goto label_1184c4;
            case 0x1184C8u: goto label_1184c8;
            case 0x1184CCu: goto label_1184cc;
            case 0x1184D0u: goto label_1184d0;
            case 0x1184D4u: goto label_1184d4;
            case 0x1184D8u: goto label_1184d8;
            case 0x1184DCu: goto label_1184dc;
            case 0x1184E0u: goto label_1184e0;
            case 0x1184E4u: goto label_1184e4;
            case 0x1184E8u: goto label_1184e8;
            case 0x1184ECu: goto label_1184ec;
            case 0x1184F0u: goto label_1184f0;
            case 0x1184F4u: goto label_1184f4;
            case 0x1184F8u: goto label_1184f8;
            case 0x1184FCu: goto label_1184fc;
            case 0x118500u: goto label_118500;
            case 0x118504u: goto label_118504;
            case 0x118508u: goto label_118508;
            case 0x11850Cu: goto label_11850c;
            case 0x118510u: goto label_118510;
            case 0x118514u: goto label_118514;
            case 0x118518u: goto label_118518;
            case 0x11851Cu: goto label_11851c;
            case 0x118520u: goto label_118520;
            case 0x118524u: goto label_118524;
            case 0x118528u: goto label_118528;
            case 0x11852Cu: goto label_11852c;
            case 0x118530u: goto label_118530;
            case 0x118534u: goto label_118534;
            case 0x118538u: goto label_118538;
            case 0x11853Cu: goto label_11853c;
            case 0x118540u: goto label_118540;
            case 0x118544u: goto label_118544;
            case 0x118548u: goto label_118548;
            case 0x11854Cu: goto label_11854c;
            case 0x118550u: goto label_118550;
            case 0x118554u: goto label_118554;
            case 0x118558u: goto label_118558;
            case 0x11855Cu: goto label_11855c;
            case 0x118560u: goto label_118560;
            case 0x118564u: goto label_118564;
            case 0x118568u: goto label_118568;
            case 0x11856Cu: goto label_11856c;
            case 0x118570u: goto label_118570;
            case 0x118574u: goto label_118574;
            case 0x118578u: goto label_118578;
            case 0x11857Cu: goto label_11857c;
            case 0x118580u: goto label_118580;
            case 0x118584u: goto label_118584;
            case 0x118588u: goto label_118588;
            case 0x11858Cu: goto label_11858c;
            case 0x118590u: goto label_118590;
            case 0x118594u: goto label_118594;
            case 0x118598u: goto label_118598;
            case 0x11859Cu: goto label_11859c;
            case 0x1185A0u: goto label_1185a0;
            case 0x1185A4u: goto label_1185a4;
            case 0x1185A8u: goto label_1185a8;
            case 0x1185ACu: goto label_1185ac;
            case 0x1185B0u: goto label_1185b0;
            case 0x1185B4u: goto label_1185b4;
            case 0x1185B8u: goto label_1185b8;
            case 0x1185BCu: goto label_1185bc;
            case 0x1185C0u: goto label_1185c0;
            case 0x1185C4u: goto label_1185c4;
            case 0x1185C8u: goto label_1185c8;
            case 0x1185CCu: goto label_1185cc;
            case 0x1185D0u: goto label_1185d0;
            case 0x1185D4u: goto label_1185d4;
            case 0x1185D8u: goto label_1185d8;
            case 0x1185DCu: goto label_1185dc;
            case 0x1185E0u: goto label_1185e0;
            case 0x1185E4u: goto label_1185e4;
            case 0x1185E8u: goto label_1185e8;
            case 0x1185ECu: goto label_1185ec;
            case 0x1185F0u: goto label_1185f0;
            case 0x1185F4u: goto label_1185f4;
            case 0x1185F8u: goto label_1185f8;
            case 0x1185FCu: goto label_1185fc;
            case 0x118600u: goto label_118600;
            case 0x118604u: goto label_118604;
            case 0x118608u: goto label_118608;
            case 0x11860Cu: goto label_11860c;
            case 0x118610u: goto label_118610;
            case 0x118614u: goto label_118614;
            case 0x118618u: goto label_118618;
            case 0x11861Cu: goto label_11861c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x118330u;
label_118330:
    // 0x118330: 0x8e030014
    ctx->pc = 0x118330u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_118334:
    // 0x118334: 0x18600012
label_118338:
    if (ctx->pc == 0x118338u) {
        ctx->pc = 0x118338u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 20));
        ctx->pc = 0x11833Cu;
        goto label_11833c;
    }
    ctx->pc = 0x118334u;
    {
        const bool branch_taken_0x118334 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x118338u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 20));
        if (branch_taken_0x118334) {
            ctx->pc = 0x118380u;
            goto label_118380;
        }
    }
    ctx->pc = 0x11833Cu;
label_11833c:
    // 0x11833c: 0x8ce80008
    ctx->pc = 0x11833cu;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_118340:
    // 0x118340: 0x3c022000
    ctx->pc = 0x118340u;
    SET_GPR_U32(ctx, 2, ((uint32_t)8192 << 16));
label_118344:
    // 0x118344: 0x302d
    ctx->pc = 0x118344u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_118348:
    // 0x118348: 0x1860000d
label_11834c:
    if (ctx->pc == 0x11834Cu) {
        ctx->pc = 0x11834Cu;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
        ctx->pc = 0x118350u;
        goto label_118350;
    }
    ctx->pc = 0x118348u;
    {
        const bool branch_taken_0x118348 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x11834Cu;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
        if (branch_taken_0x118348) {
            ctx->pc = 0x118380u;
            goto label_118380;
        }
    }
    ctx->pc = 0x118350u;
label_118350:
    // 0x118350: 0x26090024
    ctx->pc = 0x118350u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 16), 36));
label_118354:
    // 0x118354: 0x1261021
    ctx->pc = 0x118354u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
label_118358:
    // 0x118358: 0x1462821
    ctx->pc = 0x118358u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
label_11835c:
    // 0x11835c: 0x90430000
    ctx->pc = 0x11835cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
label_118360:
    // 0x118360: 0x1062021
    ctx->pc = 0x118360u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
label_118364:
    // 0x118364: 0x24c60001
    ctx->pc = 0x118364u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
label_118368:
    // 0x118368: 0xa0a30000
    ctx->pc = 0x118368u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
label_11836c:
    // 0x11836c: 0xa0830000
    ctx->pc = 0x11836cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
label_118370:
    // 0x118370: 0x8ce20000
    ctx->pc = 0x118370u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 0)));
label_118374:
    // 0x118374: 0xc2102a
    ctx->pc = 0x118374u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 6), GPR_S32(ctx, 2)));
label_118378:
    // 0x118378: 0x1440fff7
label_11837c:
    if (ctx->pc == 0x11837Cu) {
        ctx->pc = 0x11837Cu;
        SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
        ctx->pc = 0x118380u;
        goto label_118380;
    }
    ctx->pc = 0x118378u;
    {
        const bool branch_taken_0x118378 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x11837Cu;
        SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
        if (branch_taken_0x118378) {
            ctx->pc = 0x118358u;
            goto label_118358;
        }
    }
    ctx->pc = 0x118380u;
label_118380:
    // 0x118380: 0x8ce30004
    ctx->pc = 0x118380u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_118384:
    // 0x118384: 0x18600084
label_118388:
    if (ctx->pc == 0x118388u) {
        ctx->pc = 0x118388u;
        SET_GPR_U32(ctx, 2, ((uint32_t)8192 << 16));
        ctx->pc = 0x11838Cu;
        goto label_11838c;
    }
    ctx->pc = 0x118384u;
    {
        const bool branch_taken_0x118384 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x118388u;
        SET_GPR_U32(ctx, 2, ((uint32_t)8192 << 16));
        if (branch_taken_0x118384) {
            ctx->pc = 0x118598u;
            goto label_118598;
        }
    }
    ctx->pc = 0x11838Cu;
label_11838c:
    // 0x11838c: 0x8ce8000c
    ctx->pc = 0x11838cu;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 7), 12)));
label_118390:
    // 0x118390: 0x302d
    ctx->pc = 0x118390u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_118394:
    // 0x118394: 0x18600080
label_118398:
    if (ctx->pc == 0x118398u) {
        ctx->pc = 0x118398u;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
        ctx->pc = 0x11839Cu;
        goto label_11839c;
    }
    ctx->pc = 0x118394u;
    {
        const bool branch_taken_0x118394 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x118398u;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
        if (branch_taken_0x118394) {
            ctx->pc = 0x118598u;
            goto label_118598;
        }
    }
    ctx->pc = 0x11839Cu;
label_11839c:
    // 0x11839c: 0x24e90050
    ctx->pc = 0x11839cu;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 7), 80));
label_1183a0:
    // 0x1183a0: 0x1261021
    ctx->pc = 0x1183a0u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
label_1183a4:
    // 0x1183a4: 0x0
    ctx->pc = 0x1183a4u;
    // NOP
label_1183a8:
    // 0x1183a8: 0x1462821
    ctx->pc = 0x1183a8u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
label_1183ac:
    // 0x1183ac: 0x90430000
    ctx->pc = 0x1183acu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
label_1183b0:
    // 0x1183b0: 0x1062021
    ctx->pc = 0x1183b0u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
label_1183b4:
    // 0x1183b4: 0x24c60001
    ctx->pc = 0x1183b4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
label_1183b8:
    // 0x1183b8: 0xa0a30000
    ctx->pc = 0x1183b8u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
label_1183bc:
    // 0x1183bc: 0xa0830000
    ctx->pc = 0x1183bcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
label_1183c0:
    // 0x1183c0: 0x8ce20004
    ctx->pc = 0x1183c0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_1183c4:
    // 0x1183c4: 0xc2102a
    ctx->pc = 0x1183c4u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 6), GPR_S32(ctx, 2)));
label_1183c8:
    // 0x1183c8: 0x1440fff7
label_1183cc:
    if (ctx->pc == 0x1183CCu) {
        ctx->pc = 0x1183CCu;
        SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
        ctx->pc = 0x1183D0u;
        goto label_1183d0;
    }
    ctx->pc = 0x1183C8u;
    {
        const bool branch_taken_0x1183c8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1183CCu;
        SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
        if (branch_taken_0x1183c8) {
            ctx->pc = 0x1183A8u;
            goto label_1183a8;
        }
    }
    ctx->pc = 0x1183D0u;
label_1183d0:
    // 0x1183d0: 0x10000072
label_1183d4:
    if (ctx->pc == 0x1183D4u) {
        ctx->pc = 0x1183D4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x1183D8u;
        goto label_1183d8;
    }
    ctx->pc = 0x1183D0u;
    {
        const bool branch_taken_0x1183d0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1183D4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x1183d0) {
            ctx->pc = 0x11859Cu;
            goto label_11859c;
        }
    }
    ctx->pc = 0x1183D8u;
label_1183d8:
    // 0x1183d8: 0x8fa20008
    ctx->pc = 0x1183d8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 8)));
label_1183dc:
    // 0x1183dc: 0x8c430000
    ctx->pc = 0x1183dcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1183e0:
    // 0x1183e0: 0x1860006e
label_1183e4:
    if (ctx->pc == 0x1183E4u) {
        ctx->pc = 0x1183E4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x1183E8u;
        goto label_1183e8;
    }
    ctx->pc = 0x1183E0u;
    {
        const bool branch_taken_0x1183e0 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x1183E4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x1183e0) {
            ctx->pc = 0x11859Cu;
            goto label_11859c;
        }
    }
    ctx->pc = 0x1183E8u;
label_1183e8:
    // 0x1183e8: 0x8a040017
    ctx->pc = 0x1183e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 4, (GPR_U32(ctx, 4) & ~mask) | ((aligned_word << shift) & mask)); }
label_1183ec:
    // 0x1183ec: 0x9a040014
    ctx->pc = 0x1183ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 4, (GPR_U32(ctx, 4) & ~mask) | ((aligned_word >> shift) & mask)); }
label_1183f0:
    // 0x1183f0: 0xaba40013
    ctx->pc = 0x1183f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 19); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 4) >> shift) & mask); WRITE32(aligned_addr, new_data); }
label_1183f4:
    // 0x1183f4: 0xbba40010
    ctx->pc = 0x1183f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 4) << shift) & mask); WRITE32(aligned_addr, new_data); }
label_1183f8:
    // 0x1183f8: 0x26040018
    ctx->pc = 0x1183f8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 24));
label_1183fc:
    // 0x1183fc: 0x8fa60010
    ctx->pc = 0x1183fcu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_118400:
    // 0x118400: 0x861025
    ctx->pc = 0x118400u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
label_118404:
    // 0x118404: 0x30420007
    ctx->pc = 0x118404u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 7));
label_118408:
    // 0x118408: 0x10400018
label_11840c:
    if (ctx->pc == 0x11840Cu) {
        ctx->pc = 0x11840Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 344));
        ctx->pc = 0x118410u;
        goto label_118410;
    }
    ctx->pc = 0x118408u;
    {
        const bool branch_taken_0x118408 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x11840Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 344));
        if (branch_taken_0x118408) {
            ctx->pc = 0x11846Cu;
            goto label_11846c;
        }
    }
    ctx->pc = 0x118410u;
label_118410:
    // 0x118410: 0x68880007
    ctx->pc = 0x118410u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & ~mask) | ((aligned_data << shift) & mask)); }
label_118414:
    // 0x118414: 0x6c880000
    ctx->pc = 0x118414u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & ~mask) | ((aligned_data >> shift) & mask)); }
label_118418:
    // 0x118418: 0x6883000f
    ctx->pc = 0x118418u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data << shift) & mask)); }
label_11841c:
    // 0x11841c: 0x6c830008
    ctx->pc = 0x11841cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data >> shift) & mask)); }
label_118420:
    // 0x118420: 0x68850017
    ctx->pc = 0x118420u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
label_118424:
    // 0x118424: 0x6c850010
    ctx->pc = 0x118424u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
label_118428:
    // 0x118428: 0x6887001f
    ctx->pc = 0x118428u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & ~mask) | ((aligned_data << shift) & mask)); }
label_11842c:
    // 0x11842c: 0x6c870018
    ctx->pc = 0x11842cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & ~mask) | ((aligned_data >> shift) & mask)); }
label_118430:
    // 0x118430: 0xb0c80007
    ctx->pc = 0x118430u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 8) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_118434:
    // 0x118434: 0xb4c80000
    ctx->pc = 0x118434u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 8) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118438:
    // 0x118438: 0xb0c3000f
    ctx->pc = 0x118438u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_11843c:
    // 0x11843c: 0xb4c30008
    ctx->pc = 0x11843cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118440:
    // 0x118440: 0xb0c50017
    ctx->pc = 0x118440u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_118444:
    // 0x118444: 0xb4c50010
    ctx->pc = 0x118444u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118448:
    // 0x118448: 0xb0c7001f
    ctx->pc = 0x118448u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 7) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_11844c:
    // 0x11844c: 0xb4c70018
    ctx->pc = 0x11844cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 7) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118450:
    // 0x118450: 0x24840020
    ctx->pc = 0x118450u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 32));
label_118454:
    // 0x118454: 0x24c60020
    ctx->pc = 0x118454u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 32));
label_118458:
    // 0x118458: 0x0
    ctx->pc = 0x118458u;
    // NOP
label_11845c:
    // 0x11845c: 0x1482ffec
label_118460:
    if (ctx->pc == 0x118460u) {
        ctx->pc = 0x118464u;
        goto label_118464;
    }
    ctx->pc = 0x11845Cu;
    {
        const bool branch_taken_0x11845c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        if (branch_taken_0x11845c) {
            ctx->pc = 0x118410u;
            goto label_118410;
        }
    }
    ctx->pc = 0x118464u;
label_118464:
    // 0x118464: 0x1000000e
label_118468:
    if (ctx->pc == 0x118468u) {
        ctx->pc = 0x11846Cu;
        goto label_11846c;
    }
    ctx->pc = 0x118464u;
    {
        const bool branch_taken_0x118464 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x118464) {
            ctx->pc = 0x1184A0u;
            goto label_1184a0;
        }
    }
    ctx->pc = 0x11846Cu;
label_11846c:
    // 0x11846c: 0xdc880000
    ctx->pc = 0x11846cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 4), 0)));
label_118470:
    // 0x118470: 0xdc830008
    ctx->pc = 0x118470u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 8)));
label_118474:
    // 0x118474: 0xdc850010
    ctx->pc = 0x118474u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 4), 16)));
label_118478:
    // 0x118478: 0xdc870018
    ctx->pc = 0x118478u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 4), 24)));
label_11847c:
    // 0x11847c: 0xfcc80000
    ctx->pc = 0x11847cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 8));
label_118480:
    // 0x118480: 0xfcc30008
    ctx->pc = 0x118480u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 8), GPR_U64(ctx, 3));
label_118484:
    // 0x118484: 0xfcc50010
    ctx->pc = 0x118484u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 5));
label_118488:
    // 0x118488: 0xfcc70018
    ctx->pc = 0x118488u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 24), GPR_U64(ctx, 7));
label_11848c:
    // 0x11848c: 0x24840020
    ctx->pc = 0x11848cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 32));
label_118490:
    // 0x118490: 0x24c60020
    ctx->pc = 0x118490u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 32));
label_118494:
    // 0x118494: 0x0
    ctx->pc = 0x118494u;
    // NOP
label_118498:
    // 0x118498: 0x1482fff4
label_11849c:
    if (ctx->pc == 0x11849Cu) {
        ctx->pc = 0x1184A0u;
        goto label_1184a0;
    }
    ctx->pc = 0x118498u;
    {
        const bool branch_taken_0x118498 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        if (branch_taken_0x118498) {
            ctx->pc = 0x11846Cu;
            goto label_11846c;
        }
    }
    ctx->pc = 0x1184A0u;
label_1184a0:
    // 0x1184a0: 0x88880003
    ctx->pc = 0x1184a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 8, (GPR_U32(ctx, 8) & ~mask) | ((aligned_word << shift) & mask)); }
label_1184a4:
    // 0x1184a4: 0x98880000
    ctx->pc = 0x1184a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 8, (GPR_U32(ctx, 8) & ~mask) | ((aligned_word >> shift) & mask)); }
label_1184a8:
    // 0x1184a8: 0xa8c80003
    ctx->pc = 0x1184a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 3); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 8) >> shift) & mask); WRITE32(aligned_addr, new_data); }
label_1184ac:
    // 0x1184ac: 0x1000003a
label_1184b0:
    if (ctx->pc == 0x1184B0u) {
        ctx->pc = 0x1184B0u;
        { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 8) << shift) & mask); WRITE32(aligned_addr, new_data); }
        ctx->pc = 0x1184B4u;
        goto label_1184b4;
    }
    ctx->pc = 0x1184ACu;
    {
        const bool branch_taken_0x1184ac = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1184B0u;
        { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 8) << shift) & mask); WRITE32(aligned_addr, new_data); }
        if (branch_taken_0x1184ac) {
            ctx->pc = 0x118598u;
            goto label_118598;
        }
    }
    ctx->pc = 0x1184B4u;
label_1184b4:
    // 0x1184b4: 0x8a060017
    ctx->pc = 0x1184b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 6, (GPR_U32(ctx, 6) & ~mask) | ((aligned_word << shift) & mask)); }
label_1184b8:
    // 0x1184b8: 0x9a060014
    ctx->pc = 0x1184b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 6, (GPR_U32(ctx, 6) & ~mask) | ((aligned_word >> shift) & mask)); }
label_1184bc:
    // 0x1184bc: 0xaba60013
    ctx->pc = 0x1184bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 19); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 6) >> shift) & mask); WRITE32(aligned_addr, new_data); }
label_1184c0:
    // 0x1184c0: 0xbba60010
    ctx->pc = 0x1184c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 6) << shift) & mask); WRITE32(aligned_addr, new_data); }
label_1184c4:
    // 0x1184c4: 0x8fa20010
    ctx->pc = 0x1184c4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1184c8:
    // 0x1184c8: 0x6a03001f
    ctx->pc = 0x1184c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data << shift) & mask)); }
label_1184cc:
    // 0x1184cc: 0x6e030018
    ctx->pc = 0x1184ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data >> shift) & mask)); }
label_1184d0:
    // 0x1184d0: 0x6a040027
    ctx->pc = 0x1184d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 39); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data << shift) & mask)); }
label_1184d4:
    // 0x1184d4: 0x6e040020
    ctx->pc = 0x1184d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 32); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data >> shift) & mask)); }
label_1184d8:
    // 0x1184d8: 0x6a05002f
    ctx->pc = 0x1184d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 47); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
label_1184dc:
    // 0x1184dc: 0x6e050028
    ctx->pc = 0x1184dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 40); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
label_1184e0:
    // 0x1184e0: 0x6a060037
    ctx->pc = 0x1184e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 55); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data << shift) & mask)); }
label_1184e4:
    // 0x1184e4: 0x6e060030
    ctx->pc = 0x1184e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 48); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data >> shift) & mask)); }
label_1184e8:
    // 0x1184e8: 0xb0430007
    ctx->pc = 0x1184e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_1184ec:
    // 0x1184ec: 0xb4430000
    ctx->pc = 0x1184ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_1184f0:
    // 0x1184f0: 0xb044000f
    ctx->pc = 0x1184f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_1184f4:
    // 0x1184f4: 0xb4440008
    ctx->pc = 0x1184f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_1184f8:
    // 0x1184f8: 0xb0450017
    ctx->pc = 0x1184f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_1184fc:
    // 0x1184fc: 0xb4450010
    ctx->pc = 0x1184fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118500:
    // 0x118500: 0xb046001f
    ctx->pc = 0x118500u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_118504:
    // 0x118504: 0xb4460018
    ctx->pc = 0x118504u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118508:
    // 0x118508: 0x6a03003f
    ctx->pc = 0x118508u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 63); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data << shift) & mask)); }
label_11850c:
    // 0x11850c: 0x6e030038
    ctx->pc = 0x11850cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 56); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data >> shift) & mask)); }
label_118510:
    // 0x118510: 0x6a040047
    ctx->pc = 0x118510u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 71); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data << shift) & mask)); }
label_118514:
    // 0x118514: 0x6e040040
    ctx->pc = 0x118514u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 64); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data >> shift) & mask)); }
label_118518:
    // 0x118518: 0x6a05004f
    ctx->pc = 0x118518u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 79); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
label_11851c:
    // 0x11851c: 0x6e050048
    ctx->pc = 0x11851cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 72); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
label_118520:
    // 0x118520: 0x6a060057
    ctx->pc = 0x118520u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 87); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data << shift) & mask)); }
label_118524:
    // 0x118524: 0x6e060050
    ctx->pc = 0x118524u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 80); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data >> shift) & mask)); }
label_118528:
    // 0x118528: 0xb0430027
    ctx->pc = 0x118528u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 39); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_11852c:
    // 0x11852c: 0xb4430020
    ctx->pc = 0x11852cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 32); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118530:
    // 0x118530: 0xb044002f
    ctx->pc = 0x118530u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 47); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_118534:
    // 0x118534: 0xb4440028
    ctx->pc = 0x118534u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 40); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118538:
    // 0x118538: 0xb0450037
    ctx->pc = 0x118538u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 55); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_11853c:
    // 0x11853c: 0xb4450030
    ctx->pc = 0x11853cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 48); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118540:
    // 0x118540: 0xb046003f
    ctx->pc = 0x118540u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 63); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_118544:
    // 0x118544: 0xb4460038
    ctx->pc = 0x118544u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 56); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_118548:
    // 0x118548: 0x10000014
label_11854c:
    if (ctx->pc == 0x11854Cu) {
        ctx->pc = 0x11854Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x118550u;
        goto label_118550;
    }
    ctx->pc = 0x118548u;
    {
        const bool branch_taken_0x118548 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11854Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x118548) {
            ctx->pc = 0x11859Cu;
            goto label_11859c;
        }
    }
    ctx->pc = 0x118550u;
label_118550:
    // 0x118550: 0x8a070017
    ctx->pc = 0x118550u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 7, (GPR_U32(ctx, 7) & ~mask) | ((aligned_word << shift) & mask)); }
label_118554:
    // 0x118554: 0x9a070014
    ctx->pc = 0x118554u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 7, (GPR_U32(ctx, 7) & ~mask) | ((aligned_word >> shift) & mask)); }
label_118558:
    // 0x118558: 0xaba70013
    ctx->pc = 0x118558u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 19); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 7) >> shift) & mask); WRITE32(aligned_addr, new_data); }
label_11855c:
    // 0x11855c: 0xbba70010
    ctx->pc = 0x11855cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 7) << shift) & mask); WRITE32(aligned_addr, new_data); }
label_118560:
    // 0x118560: 0x8a04001b
    ctx->pc = 0x118560u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 27); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 4, (GPR_U32(ctx, 4) & ~mask) | ((aligned_word << shift) & mask)); }
label_118564:
    // 0x118564: 0x9a040018
    ctx->pc = 0x118564u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 4, (GPR_U32(ctx, 4) & ~mask) | ((aligned_word >> shift) & mask)); }
label_118568:
    // 0x118568: 0xaba40017
    ctx->pc = 0x118568u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 4) >> shift) & mask); WRITE32(aligned_addr, new_data); }
label_11856c:
    // 0x11856c: 0xbba40014
    ctx->pc = 0x11856cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 20); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 4) << shift) & mask); WRITE32(aligned_addr, new_data); }
label_118570:
    // 0x118570: 0x8fa60014
    ctx->pc = 0x118570u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_118574:
    // 0x118574: 0x2cc20401
    ctx->pc = 0x118574u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 6), 1025));
label_118578:
    // 0x118578: 0x14400005
label_11857c:
    if (ctx->pc == 0x11857Cu) {
        ctx->pc = 0x11857Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->pc = 0x118580u;
        goto label_118580;
    }
    ctx->pc = 0x118578u;
    {
        const bool branch_taken_0x118578 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x11857Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x118578) {
            ctx->pc = 0x118590u;
            goto label_118590;
        }
    }
    ctx->pc = 0x118580u;
label_118580:
    // 0x118580: 0x24020400
    ctx->pc = 0x118580u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1024));
label_118584:
    // 0x118584: 0x24060400
    ctx->pc = 0x118584u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1024));
label_118588:
    // 0x118588: 0xafa20014
    ctx->pc = 0x118588u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
label_11858c:
    // 0x11858c: 0x8fa40010
    ctx->pc = 0x11858cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_118590:
    // 0x118590: 0xc041eac
label_118594:
    if (ctx->pc == 0x118594u) {
        ctx->pc = 0x118594u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 28));
        ctx->pc = 0x118598u;
        goto label_118598;
    }
    ctx->pc = 0x118590u;
    SET_GPR_U32(ctx, 31, 0x118598u);
    ctx->pc = 0x118594u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 28));
    ctx->pc = 0x107AB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118598u; }
    }
    if (ctx->pc != 0x118598u) { return; }
    ctx->pc = 0x118598u;
label_118598:
    // 0x118598: 0x8fa40000
    ctx->pc = 0x118598u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_11859c:
    // 0x11859c: 0x4810019
label_1185a0:
    if (ctx->pc == 0x1185A0u) {
        ctx->pc = 0x1185A0u;
        SET_GPR_U32(ctx, 7, ((uint32_t)33 << 16));
        ctx->pc = 0x1185A4u;
        goto label_1185a4;
    }
    ctx->pc = 0x11859Cu;
    {
        const bool branch_taken_0x11859c = (GPR_S32(ctx, 4) >= 0);
        ctx->pc = 0x1185A0u;
        SET_GPR_U32(ctx, 7, ((uint32_t)33 << 16));
        if (branch_taken_0x11859c) {
            ctx->pc = 0x118604u;
            goto label_118604;
        }
    }
    ctx->pc = 0x1185A4u;
label_1185a4:
    // 0x1185a4: 0x41023
    ctx->pc = 0x1185a4u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
label_1185a8:
    // 0x1185a8: 0x8ce39d58
    ctx->pc = 0x1185a8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4294942040)));
label_1185ac:
    // 0x1185ac: 0x40282d
    ctx->pc = 0x1185acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1185b0:
    // 0x1185b0: 0xafa20000
    ctx->pc = 0x1185b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
label_1185b4:
    // 0x1185b4: 0x14650006
label_1185b8:
    if (ctx->pc == 0x1185B8u) {
        ctx->pc = 0x1185B8u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1185BCu;
        goto label_1185bc;
    }
    ctx->pc = 0x1185B4u;
    {
        const bool branch_taken_0x1185b4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 5));
        ctx->pc = 0x1185B8u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1185b4) {
            ctx->pc = 0x1185D0u;
            goto label_1185d0;
        }
    }
    ctx->pc = 0x1185BCu;
label_1185bc:
    // 0x1185bc: 0x2402ffff
    ctx->pc = 0x1185bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1185c0:
    // 0x1185c0: 0xace29d58
    ctx->pc = 0x1185c0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294942040), GPR_U32(ctx, 2));
label_1185c4:
    // 0x1185c4: 0x10000012
label_1185c8:
    if (ctx->pc == 0x1185C8u) {
        ctx->pc = 0x1185C8u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->pc = 0x1185CCu;
        goto label_1185cc;
    }
    ctx->pc = 0x1185C4u;
    {
        const bool branch_taken_0x1185c4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1185C8u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x1185c4) {
            ctx->pc = 0x118610u;
            goto label_118610;
        }
    }
    ctx->pc = 0x1185CCu;
label_1185cc:
    // 0x1185cc: 0x0
    ctx->pc = 0x1185ccu;
    // NOP
label_1185d0:
    // 0x1185d0: 0x24c60001
    ctx->pc = 0x1185d0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
label_1185d4:
    // 0x1185d4: 0x28c20020
    ctx->pc = 0x1185d4u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 6), 32));
label_1185d8:
    // 0x1185d8: 0x1040000c
label_1185dc:
    if (ctx->pc == 0x1185DCu) {
        ctx->pc = 0x1185DCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 7), 4294942040));
        ctx->pc = 0x1185E0u;
        goto label_1185e0;
    }
    ctx->pc = 0x1185D8u;
    {
        const bool branch_taken_0x1185d8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1185DCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 7), 4294942040));
        if (branch_taken_0x1185d8) {
            ctx->pc = 0x11860Cu;
            goto label_11860c;
        }
    }
    ctx->pc = 0x1185E0u;
label_1185e0:
    // 0x1185e0: 0x61880
    ctx->pc = 0x1185e0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 6), 2));
label_1185e4:
    // 0x1185e4: 0x621821
    ctx->pc = 0x1185e4u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1185e8:
    // 0x1185e8: 0x8c640000
    ctx->pc = 0x1185e8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_1185ec:
    // 0x1185ec: 0x1485fff9
label_1185f0:
    if (ctx->pc == 0x1185F0u) {
        ctx->pc = 0x1185F0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
        ctx->pc = 0x1185F4u;
        goto label_1185f4;
    }
    ctx->pc = 0x1185ECu;
    {
        const bool branch_taken_0x1185ec = (GPR_U32(ctx, 4) != GPR_U32(ctx, 5));
        ctx->pc = 0x1185F0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0x1185ec) {
            ctx->pc = 0x1185D4u;
            goto label_1185d4;
        }
    }
    ctx->pc = 0x1185F4u;
label_1185f4:
    // 0x1185f4: 0x2402ffff
    ctx->pc = 0x1185f4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1185f8:
    // 0x1185f8: 0xac620000
    ctx->pc = 0x1185f8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_1185fc:
    // 0x1185fc: 0x10000004
label_118600:
    if (ctx->pc == 0x118600u) {
        ctx->pc = 0x118600u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->pc = 0x118604u;
        goto label_118604;
    }
    ctx->pc = 0x1185FCu;
    {
        const bool branch_taken_0x1185fc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x118600u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x1185fc) {
            ctx->pc = 0x118610u;
            goto label_118610;
        }
    }
    ctx->pc = 0x118604u;
label_118604:
    // 0x118604: 0xc045194
label_118608:
    if (ctx->pc == 0x118608u) {
        ctx->pc = 0x11860Cu;
        goto label_11860c;
    }
    ctx->pc = 0x118604u;
    SET_GPR_U32(ctx, 31, 0x11860Cu);
    ctx->pc = 0x114650u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11860Cu; }
    }
    if (ctx->pc != 0x11860Cu) { return; }
    ctx->pc = 0x11860Cu;
label_11860c:
    // 0x11860c: 0xdfbf0030
    ctx->pc = 0x11860cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_118610:
    // 0x118610: 0xdfb00020
    ctx->pc = 0x118610u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_118614:
    // 0x118614: 0x3e00008
label_118618:
    if (ctx->pc == 0x118618u) {
        ctx->pc = 0x118618u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x11861Cu;
        goto label_11861c;
    }
    ctx->pc = 0x118614u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118618u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1181F8u: goto label_1181f8;
            case 0x1181FCu: goto label_1181fc;
            case 0x118200u: goto label_118200;
            case 0x118204u: goto label_118204;
            case 0x118208u: goto label_118208;
            case 0x11820Cu: goto label_11820c;
            case 0x118210u: goto label_118210;
            case 0x118214u: goto label_118214;
            case 0x118218u: goto label_118218;
            case 0x11821Cu: goto label_11821c;
            case 0x118220u: goto label_118220;
            case 0x118224u: goto label_118224;
            case 0x118228u: goto label_118228;
            case 0x11822Cu: goto label_11822c;
            case 0x118230u: goto label_118230;
            case 0x118234u: goto label_118234;
            case 0x118238u: goto label_118238;
            case 0x11823Cu: goto label_11823c;
            case 0x118240u: goto label_118240;
            case 0x118244u: goto label_118244;
            case 0x118248u: goto label_118248;
            case 0x11824Cu: goto label_11824c;
            case 0x118250u: goto label_118250;
            case 0x118254u: goto label_118254;
            case 0x118258u: goto label_118258;
            case 0x11825Cu: goto label_11825c;
            case 0x118260u: goto label_118260;
            case 0x118264u: goto label_118264;
            case 0x118268u: goto label_118268;
            case 0x11826Cu: goto label_11826c;
            case 0x118270u: goto label_118270;
            case 0x118274u: goto label_118274;
            case 0x118278u: goto label_118278;
            case 0x11827Cu: goto label_11827c;
            case 0x118280u: goto label_118280;
            case 0x118284u: goto label_118284;
            case 0x118288u: goto label_118288;
            case 0x11828Cu: goto label_11828c;
            case 0x118290u: goto label_118290;
            case 0x118294u: goto label_118294;
            case 0x118298u: goto label_118298;
            case 0x11829Cu: goto label_11829c;
            case 0x1182A0u: goto label_1182a0;
            case 0x1182A4u: goto label_1182a4;
            case 0x1182A8u: goto label_1182a8;
            case 0x1182ACu: goto label_1182ac;
            case 0x1182B0u: goto label_1182b0;
            case 0x1182B4u: goto label_1182b4;
            case 0x1182B8u: goto label_1182b8;
            case 0x1182BCu: goto label_1182bc;
            case 0x1182C0u: goto label_1182c0;
            case 0x1182C4u: goto label_1182c4;
            case 0x1182C8u: goto label_1182c8;
            case 0x1182CCu: goto label_1182cc;
            case 0x1182D0u: goto label_1182d0;
            case 0x1182D4u: goto label_1182d4;
            case 0x1182D8u: goto label_1182d8;
            case 0x1182DCu: goto label_1182dc;
            case 0x1182E0u: goto label_1182e0;
            case 0x1182E4u: goto label_1182e4;
            case 0x1182E8u: goto label_1182e8;
            case 0x1182ECu: goto label_1182ec;
            case 0x1182F0u: goto label_1182f0;
            case 0x1182F4u: goto label_1182f4;
            case 0x1182F8u: goto label_1182f8;
            case 0x1182FCu: goto label_1182fc;
            case 0x118300u: goto label_118300;
            case 0x118304u: goto label_118304;
            case 0x118308u: goto label_118308;
            case 0x11830Cu: goto label_11830c;
            case 0x118310u: goto label_118310;
            case 0x118314u: goto label_118314;
            case 0x118318u: goto label_118318;
            case 0x11831Cu: goto label_11831c;
            case 0x118320u: goto label_118320;
            case 0x118324u: goto label_118324;
            case 0x118328u: goto label_118328;
            case 0x11832Cu: goto label_11832c;
            case 0x118330u: goto label_118330;
            case 0x118334u: goto label_118334;
            case 0x118338u: goto label_118338;
            case 0x11833Cu: goto label_11833c;
            case 0x118340u: goto label_118340;
            case 0x118344u: goto label_118344;
            case 0x118348u: goto label_118348;
            case 0x11834Cu: goto label_11834c;
            case 0x118350u: goto label_118350;
            case 0x118354u: goto label_118354;
            case 0x118358u: goto label_118358;
            case 0x11835Cu: goto label_11835c;
            case 0x118360u: goto label_118360;
            case 0x118364u: goto label_118364;
            case 0x118368u: goto label_118368;
            case 0x11836Cu: goto label_11836c;
            case 0x118370u: goto label_118370;
            case 0x118374u: goto label_118374;
            case 0x118378u: goto label_118378;
            case 0x11837Cu: goto label_11837c;
            case 0x118380u: goto label_118380;
            case 0x118384u: goto label_118384;
            case 0x118388u: goto label_118388;
            case 0x11838Cu: goto label_11838c;
            case 0x118390u: goto label_118390;
            case 0x118394u: goto label_118394;
            case 0x118398u: goto label_118398;
            case 0x11839Cu: goto label_11839c;
            case 0x1183A0u: goto label_1183a0;
            case 0x1183A4u: goto label_1183a4;
            case 0x1183A8u: goto label_1183a8;
            case 0x1183ACu: goto label_1183ac;
            case 0x1183B0u: goto label_1183b0;
            case 0x1183B4u: goto label_1183b4;
            case 0x1183B8u: goto label_1183b8;
            case 0x1183BCu: goto label_1183bc;
            case 0x1183C0u: goto label_1183c0;
            case 0x1183C4u: goto label_1183c4;
            case 0x1183C8u: goto label_1183c8;
            case 0x1183CCu: goto label_1183cc;
            case 0x1183D0u: goto label_1183d0;
            case 0x1183D4u: goto label_1183d4;
            case 0x1183D8u: goto label_1183d8;
            case 0x1183DCu: goto label_1183dc;
            case 0x1183E0u: goto label_1183e0;
            case 0x1183E4u: goto label_1183e4;
            case 0x1183E8u: goto label_1183e8;
            case 0x1183ECu: goto label_1183ec;
            case 0x1183F0u: goto label_1183f0;
            case 0x1183F4u: goto label_1183f4;
            case 0x1183F8u: goto label_1183f8;
            case 0x1183FCu: goto label_1183fc;
            case 0x118400u: goto label_118400;
            case 0x118404u: goto label_118404;
            case 0x118408u: goto label_118408;
            case 0x11840Cu: goto label_11840c;
            case 0x118410u: goto label_118410;
            case 0x118414u: goto label_118414;
            case 0x118418u: goto label_118418;
            case 0x11841Cu: goto label_11841c;
            case 0x118420u: goto label_118420;
            case 0x118424u: goto label_118424;
            case 0x118428u: goto label_118428;
            case 0x11842Cu: goto label_11842c;
            case 0x118430u: goto label_118430;
            case 0x118434u: goto label_118434;
            case 0x118438u: goto label_118438;
            case 0x11843Cu: goto label_11843c;
            case 0x118440u: goto label_118440;
            case 0x118444u: goto label_118444;
            case 0x118448u: goto label_118448;
            case 0x11844Cu: goto label_11844c;
            case 0x118450u: goto label_118450;
            case 0x118454u: goto label_118454;
            case 0x118458u: goto label_118458;
            case 0x11845Cu: goto label_11845c;
            case 0x118460u: goto label_118460;
            case 0x118464u: goto label_118464;
            case 0x118468u: goto label_118468;
            case 0x11846Cu: goto label_11846c;
            case 0x118470u: goto label_118470;
            case 0x118474u: goto label_118474;
            case 0x118478u: goto label_118478;
            case 0x11847Cu: goto label_11847c;
            case 0x118480u: goto label_118480;
            case 0x118484u: goto label_118484;
            case 0x118488u: goto label_118488;
            case 0x11848Cu: goto label_11848c;
            case 0x118490u: goto label_118490;
            case 0x118494u: goto label_118494;
            case 0x118498u: goto label_118498;
            case 0x11849Cu: goto label_11849c;
            case 0x1184A0u: goto label_1184a0;
            case 0x1184A4u: goto label_1184a4;
            case 0x1184A8u: goto label_1184a8;
            case 0x1184ACu: goto label_1184ac;
            case 0x1184B0u: goto label_1184b0;
            case 0x1184B4u: goto label_1184b4;
            case 0x1184B8u: goto label_1184b8;
            case 0x1184BCu: goto label_1184bc;
            case 0x1184C0u: goto label_1184c0;
            case 0x1184C4u: goto label_1184c4;
            case 0x1184C8u: goto label_1184c8;
            case 0x1184CCu: goto label_1184cc;
            case 0x1184D0u: goto label_1184d0;
            case 0x1184D4u: goto label_1184d4;
            case 0x1184D8u: goto label_1184d8;
            case 0x1184DCu: goto label_1184dc;
            case 0x1184E0u: goto label_1184e0;
            case 0x1184E4u: goto label_1184e4;
            case 0x1184E8u: goto label_1184e8;
            case 0x1184ECu: goto label_1184ec;
            case 0x1184F0u: goto label_1184f0;
            case 0x1184F4u: goto label_1184f4;
            case 0x1184F8u: goto label_1184f8;
            case 0x1184FCu: goto label_1184fc;
            case 0x118500u: goto label_118500;
            case 0x118504u: goto label_118504;
            case 0x118508u: goto label_118508;
            case 0x11850Cu: goto label_11850c;
            case 0x118510u: goto label_118510;
            case 0x118514u: goto label_118514;
            case 0x118518u: goto label_118518;
            case 0x11851Cu: goto label_11851c;
            case 0x118520u: goto label_118520;
            case 0x118524u: goto label_118524;
            case 0x118528u: goto label_118528;
            case 0x11852Cu: goto label_11852c;
            case 0x118530u: goto label_118530;
            case 0x118534u: goto label_118534;
            case 0x118538u: goto label_118538;
            case 0x11853Cu: goto label_11853c;
            case 0x118540u: goto label_118540;
            case 0x118544u: goto label_118544;
            case 0x118548u: goto label_118548;
            case 0x11854Cu: goto label_11854c;
            case 0x118550u: goto label_118550;
            case 0x118554u: goto label_118554;
            case 0x118558u: goto label_118558;
            case 0x11855Cu: goto label_11855c;
            case 0x118560u: goto label_118560;
            case 0x118564u: goto label_118564;
            case 0x118568u: goto label_118568;
            case 0x11856Cu: goto label_11856c;
            case 0x118570u: goto label_118570;
            case 0x118574u: goto label_118574;
            case 0x118578u: goto label_118578;
            case 0x11857Cu: goto label_11857c;
            case 0x118580u: goto label_118580;
            case 0x118584u: goto label_118584;
            case 0x118588u: goto label_118588;
            case 0x11858Cu: goto label_11858c;
            case 0x118590u: goto label_118590;
            case 0x118594u: goto label_118594;
            case 0x118598u: goto label_118598;
            case 0x11859Cu: goto label_11859c;
            case 0x1185A0u: goto label_1185a0;
            case 0x1185A4u: goto label_1185a4;
            case 0x1185A8u: goto label_1185a8;
            case 0x1185ACu: goto label_1185ac;
            case 0x1185B0u: goto label_1185b0;
            case 0x1185B4u: goto label_1185b4;
            case 0x1185B8u: goto label_1185b8;
            case 0x1185BCu: goto label_1185bc;
            case 0x1185C0u: goto label_1185c0;
            case 0x1185C4u: goto label_1185c4;
            case 0x1185C8u: goto label_1185c8;
            case 0x1185CCu: goto label_1185cc;
            case 0x1185D0u: goto label_1185d0;
            case 0x1185D4u: goto label_1185d4;
            case 0x1185D8u: goto label_1185d8;
            case 0x1185DCu: goto label_1185dc;
            case 0x1185E0u: goto label_1185e0;
            case 0x1185E4u: goto label_1185e4;
            case 0x1185E8u: goto label_1185e8;
            case 0x1185ECu: goto label_1185ec;
            case 0x1185F0u: goto label_1185f0;
            case 0x1185F4u: goto label_1185f4;
            case 0x1185F8u: goto label_1185f8;
            case 0x1185FCu: goto label_1185fc;
            case 0x118600u: goto label_118600;
            case 0x118604u: goto label_118604;
            case 0x118608u: goto label_118608;
            case 0x11860Cu: goto label_11860c;
            case 0x118610u: goto label_118610;
            case 0x118614u: goto label_118614;
            case 0x118618u: goto label_118618;
            case 0x11861Cu: goto label_11861c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11861Cu;
label_11861c:
    // 0x11861c: 0x0
    ctx->pc = 0x11861cu;
    // NOP
}
