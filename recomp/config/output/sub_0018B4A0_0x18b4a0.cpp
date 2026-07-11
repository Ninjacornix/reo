#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018B4A0
// Address: 0x18b4a0 - 0x18baa0
void sub_0018B4A0_0x18b4a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18b4a0u;

label_18b4a0:
    // 0x18b4a0: 0x740c0
    ctx->pc = 0x18b4a0u;
    SET_GPR_U32(ctx, 8, SLL32(GPR_U32(ctx, 7), 3));
label_18b4a4:
    // 0x18b4a4: 0x27bdffa0
    ctx->pc = 0x18b4a4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
label_18b4a8:
    // 0x18b4a8: 0x1074021
    ctx->pc = 0x18b4a8u;
    SET_GPR_U32(ctx, 8, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
label_18b4ac:
    // 0x18b4ac: 0xffbf0050
    ctx->pc = 0x18b4acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
label_18b4b0:
    // 0x18b4b0: 0x84040
    ctx->pc = 0x18b4b0u;
    SET_GPR_U32(ctx, 8, SLL32(GPR_U32(ctx, 8), 1));
label_18b4b4:
    // 0x18b4b4: 0x3c030029
    ctx->pc = 0x18b4b4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)41 << 16));
label_18b4b8:
    // 0x18b4b8: 0x1073821
    ctx->pc = 0x18b4b8u;
    SET_GPR_U32(ctx, 7, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
label_18b4bc:
    // 0x18b4bc: 0x7fb10040
    ctx->pc = 0x18b4bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 17));
label_18b4c0:
    // 0x18b4c0: 0x24634340
    ctx->pc = 0x18b4c0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 17216));
label_18b4c4:
    // 0x18b4c4: 0x73880
    ctx->pc = 0x18b4c4u;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 7), 2));
label_18b4c8:
    // 0x18b4c8: 0x2cc10006
    ctx->pc = 0x18b4c8u;
    SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 6), 6));
label_18b4cc:
    // 0x18b4cc: 0x7fb00030
    ctx->pc = 0x18b4ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 16));
label_18b4d0:
    // 0x18b4d0: 0x1020016c
label_18b4d4:
    if (ctx->pc == 0x18B4D4u) {
        ctx->pc = 0x18B4D4u;
        SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
        ctx->pc = 0x18B4D8u;
        goto label_18b4d8;
    }
    ctx->pc = 0x18B4D0u;
    {
        const bool branch_taken_0x18b4d0 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B4D4u;
        SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
        if (branch_taken_0x18b4d0) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B4D8u;
label_18b4d8:
    // 0x18b4d8: 0x61880
    ctx->pc = 0x18b4d8u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 6), 2));
label_18b4dc:
    // 0x18b4dc: 0x3c060024
    ctx->pc = 0x18b4dcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)36 << 16));
label_18b4e0:
    // 0x18b4e0: 0x24c61bb0
    ctx->pc = 0x18b4e0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 7088));
label_18b4e4:
    // 0x18b4e4: 0x661821
    ctx->pc = 0x18b4e4u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
label_18b4e8:
    // 0x18b4e8: 0x8c630000
    ctx->pc = 0x18b4e8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_18b4ec:
    // 0x18b4ec: 0x600008
label_18b4f0:
    if (ctx->pc == 0x18B4F0u) {
        ctx->pc = 0x18B4F4u;
        goto label_18b4f4;
    }
    ctx->pc = 0x18B4ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18B4A0u: goto label_18b4a0;
            case 0x18B4A4u: goto label_18b4a4;
            case 0x18B4A8u: goto label_18b4a8;
            case 0x18B4ACu: goto label_18b4ac;
            case 0x18B4B0u: goto label_18b4b0;
            case 0x18B4B4u: goto label_18b4b4;
            case 0x18B4B8u: goto label_18b4b8;
            case 0x18B4BCu: goto label_18b4bc;
            case 0x18B4C0u: goto label_18b4c0;
            case 0x18B4C4u: goto label_18b4c4;
            case 0x18B4C8u: goto label_18b4c8;
            case 0x18B4CCu: goto label_18b4cc;
            case 0x18B4D0u: goto label_18b4d0;
            case 0x18B4D4u: goto label_18b4d4;
            case 0x18B4D8u: goto label_18b4d8;
            case 0x18B4DCu: goto label_18b4dc;
            case 0x18B4E0u: goto label_18b4e0;
            case 0x18B4E4u: goto label_18b4e4;
            case 0x18B4E8u: goto label_18b4e8;
            case 0x18B4ECu: goto label_18b4ec;
            case 0x18B4F0u: goto label_18b4f0;
            case 0x18B4F4u: goto label_18b4f4;
            case 0x18B4F8u: goto label_18b4f8;
            case 0x18B4FCu: goto label_18b4fc;
            case 0x18B500u: goto label_18b500;
            case 0x18B504u: goto label_18b504;
            case 0x18B508u: goto label_18b508;
            case 0x18B50Cu: goto label_18b50c;
            case 0x18B510u: goto label_18b510;
            case 0x18B514u: goto label_18b514;
            case 0x18B518u: goto label_18b518;
            case 0x18B51Cu: goto label_18b51c;
            case 0x18B520u: goto label_18b520;
            case 0x18B524u: goto label_18b524;
            case 0x18B528u: goto label_18b528;
            case 0x18B52Cu: goto label_18b52c;
            case 0x18B530u: goto label_18b530;
            case 0x18B534u: goto label_18b534;
            case 0x18B538u: goto label_18b538;
            case 0x18B53Cu: goto label_18b53c;
            case 0x18B540u: goto label_18b540;
            case 0x18B544u: goto label_18b544;
            case 0x18B548u: goto label_18b548;
            case 0x18B54Cu: goto label_18b54c;
            case 0x18B550u: goto label_18b550;
            case 0x18B554u: goto label_18b554;
            case 0x18B558u: goto label_18b558;
            case 0x18B55Cu: goto label_18b55c;
            case 0x18B560u: goto label_18b560;
            case 0x18B564u: goto label_18b564;
            case 0x18B568u: goto label_18b568;
            case 0x18B56Cu: goto label_18b56c;
            case 0x18B570u: goto label_18b570;
            case 0x18B574u: goto label_18b574;
            case 0x18B578u: goto label_18b578;
            case 0x18B57Cu: goto label_18b57c;
            case 0x18B580u: goto label_18b580;
            case 0x18B584u: goto label_18b584;
            case 0x18B588u: goto label_18b588;
            case 0x18B58Cu: goto label_18b58c;
            case 0x18B590u: goto label_18b590;
            case 0x18B594u: goto label_18b594;
            case 0x18B598u: goto label_18b598;
            case 0x18B59Cu: goto label_18b59c;
            case 0x18B5A0u: goto label_18b5a0;
            case 0x18B5A4u: goto label_18b5a4;
            case 0x18B5A8u: goto label_18b5a8;
            case 0x18B5ACu: goto label_18b5ac;
            case 0x18B5B0u: goto label_18b5b0;
            case 0x18B5B4u: goto label_18b5b4;
            case 0x18B5B8u: goto label_18b5b8;
            case 0x18B5BCu: goto label_18b5bc;
            case 0x18B5C0u: goto label_18b5c0;
            case 0x18B5C4u: goto label_18b5c4;
            case 0x18B5C8u: goto label_18b5c8;
            case 0x18B5CCu: goto label_18b5cc;
            case 0x18B5D0u: goto label_18b5d0;
            case 0x18B5D4u: goto label_18b5d4;
            case 0x18B5D8u: goto label_18b5d8;
            case 0x18B5DCu: goto label_18b5dc;
            case 0x18B5E0u: goto label_18b5e0;
            case 0x18B5E4u: goto label_18b5e4;
            case 0x18B5E8u: goto label_18b5e8;
            case 0x18B5ECu: goto label_18b5ec;
            case 0x18B5F0u: goto label_18b5f0;
            case 0x18B5F4u: goto label_18b5f4;
            case 0x18B5F8u: goto label_18b5f8;
            case 0x18B5FCu: goto label_18b5fc;
            case 0x18B600u: goto label_18b600;
            case 0x18B604u: goto label_18b604;
            case 0x18B608u: goto label_18b608;
            case 0x18B60Cu: goto label_18b60c;
            case 0x18B610u: goto label_18b610;
            case 0x18B614u: goto label_18b614;
            case 0x18B618u: goto label_18b618;
            case 0x18B61Cu: goto label_18b61c;
            case 0x18B620u: goto label_18b620;
            case 0x18B624u: goto label_18b624;
            case 0x18B628u: goto label_18b628;
            case 0x18B62Cu: goto label_18b62c;
            case 0x18B630u: goto label_18b630;
            case 0x18B634u: goto label_18b634;
            case 0x18B638u: goto label_18b638;
            case 0x18B63Cu: goto label_18b63c;
            case 0x18B640u: goto label_18b640;
            case 0x18B644u: goto label_18b644;
            case 0x18B648u: goto label_18b648;
            case 0x18B64Cu: goto label_18b64c;
            case 0x18B650u: goto label_18b650;
            case 0x18B654u: goto label_18b654;
            case 0x18B658u: goto label_18b658;
            case 0x18B65Cu: goto label_18b65c;
            case 0x18B660u: goto label_18b660;
            case 0x18B664u: goto label_18b664;
            case 0x18B668u: goto label_18b668;
            case 0x18B66Cu: goto label_18b66c;
            case 0x18B670u: goto label_18b670;
            case 0x18B674u: goto label_18b674;
            case 0x18B678u: goto label_18b678;
            case 0x18B67Cu: goto label_18b67c;
            case 0x18B680u: goto label_18b680;
            case 0x18B684u: goto label_18b684;
            case 0x18B688u: goto label_18b688;
            case 0x18B68Cu: goto label_18b68c;
            case 0x18B690u: goto label_18b690;
            case 0x18B694u: goto label_18b694;
            case 0x18B698u: goto label_18b698;
            case 0x18B69Cu: goto label_18b69c;
            case 0x18B6A0u: goto label_18b6a0;
            case 0x18B6A4u: goto label_18b6a4;
            case 0x18B6A8u: goto label_18b6a8;
            case 0x18B6ACu: goto label_18b6ac;
            case 0x18B6B0u: goto label_18b6b0;
            case 0x18B6B4u: goto label_18b6b4;
            case 0x18B6B8u: goto label_18b6b8;
            case 0x18B6BCu: goto label_18b6bc;
            case 0x18B6C0u: goto label_18b6c0;
            case 0x18B6C4u: goto label_18b6c4;
            case 0x18B6C8u: goto label_18b6c8;
            case 0x18B6CCu: goto label_18b6cc;
            case 0x18B6D0u: goto label_18b6d0;
            case 0x18B6D4u: goto label_18b6d4;
            case 0x18B6D8u: goto label_18b6d8;
            case 0x18B6DCu: goto label_18b6dc;
            case 0x18B6E0u: goto label_18b6e0;
            case 0x18B6E4u: goto label_18b6e4;
            case 0x18B6E8u: goto label_18b6e8;
            case 0x18B6ECu: goto label_18b6ec;
            case 0x18B6F0u: goto label_18b6f0;
            case 0x18B6F4u: goto label_18b6f4;
            case 0x18B6F8u: goto label_18b6f8;
            case 0x18B6FCu: goto label_18b6fc;
            case 0x18B700u: goto label_18b700;
            case 0x18B704u: goto label_18b704;
            case 0x18B708u: goto label_18b708;
            case 0x18B70Cu: goto label_18b70c;
            case 0x18B710u: goto label_18b710;
            case 0x18B714u: goto label_18b714;
            case 0x18B718u: goto label_18b718;
            case 0x18B71Cu: goto label_18b71c;
            case 0x18B720u: goto label_18b720;
            case 0x18B724u: goto label_18b724;
            case 0x18B728u: goto label_18b728;
            case 0x18B72Cu: goto label_18b72c;
            case 0x18B730u: goto label_18b730;
            case 0x18B734u: goto label_18b734;
            case 0x18B738u: goto label_18b738;
            case 0x18B73Cu: goto label_18b73c;
            case 0x18B740u: goto label_18b740;
            case 0x18B744u: goto label_18b744;
            case 0x18B748u: goto label_18b748;
            case 0x18B74Cu: goto label_18b74c;
            case 0x18B750u: goto label_18b750;
            case 0x18B754u: goto label_18b754;
            case 0x18B758u: goto label_18b758;
            case 0x18B75Cu: goto label_18b75c;
            case 0x18B760u: goto label_18b760;
            case 0x18B764u: goto label_18b764;
            case 0x18B768u: goto label_18b768;
            case 0x18B76Cu: goto label_18b76c;
            case 0x18B770u: goto label_18b770;
            case 0x18B774u: goto label_18b774;
            case 0x18B778u: goto label_18b778;
            case 0x18B77Cu: goto label_18b77c;
            case 0x18B780u: goto label_18b780;
            case 0x18B784u: goto label_18b784;
            case 0x18B788u: goto label_18b788;
            case 0x18B78Cu: goto label_18b78c;
            case 0x18B790u: goto label_18b790;
            case 0x18B794u: goto label_18b794;
            case 0x18B798u: goto label_18b798;
            case 0x18B79Cu: goto label_18b79c;
            case 0x18B7A0u: goto label_18b7a0;
            case 0x18B7A4u: goto label_18b7a4;
            case 0x18B7A8u: goto label_18b7a8;
            case 0x18B7ACu: goto label_18b7ac;
            case 0x18B7B0u: goto label_18b7b0;
            case 0x18B7B4u: goto label_18b7b4;
            case 0x18B7B8u: goto label_18b7b8;
            case 0x18B7BCu: goto label_18b7bc;
            case 0x18B7C0u: goto label_18b7c0;
            case 0x18B7C4u: goto label_18b7c4;
            case 0x18B7C8u: goto label_18b7c8;
            case 0x18B7CCu: goto label_18b7cc;
            case 0x18B7D0u: goto label_18b7d0;
            case 0x18B7D4u: goto label_18b7d4;
            case 0x18B7D8u: goto label_18b7d8;
            case 0x18B7DCu: goto label_18b7dc;
            case 0x18B7E0u: goto label_18b7e0;
            case 0x18B7E4u: goto label_18b7e4;
            case 0x18B7E8u: goto label_18b7e8;
            case 0x18B7ECu: goto label_18b7ec;
            case 0x18B7F0u: goto label_18b7f0;
            case 0x18B7F4u: goto label_18b7f4;
            case 0x18B7F8u: goto label_18b7f8;
            case 0x18B7FCu: goto label_18b7fc;
            case 0x18B800u: goto label_18b800;
            case 0x18B804u: goto label_18b804;
            case 0x18B808u: goto label_18b808;
            case 0x18B80Cu: goto label_18b80c;
            case 0x18B810u: goto label_18b810;
            case 0x18B814u: goto label_18b814;
            case 0x18B818u: goto label_18b818;
            case 0x18B81Cu: goto label_18b81c;
            case 0x18B820u: goto label_18b820;
            case 0x18B824u: goto label_18b824;
            case 0x18B828u: goto label_18b828;
            case 0x18B82Cu: goto label_18b82c;
            case 0x18B830u: goto label_18b830;
            case 0x18B834u: goto label_18b834;
            case 0x18B838u: goto label_18b838;
            case 0x18B83Cu: goto label_18b83c;
            case 0x18B840u: goto label_18b840;
            case 0x18B844u: goto label_18b844;
            case 0x18B848u: goto label_18b848;
            case 0x18B84Cu: goto label_18b84c;
            case 0x18B850u: goto label_18b850;
            case 0x18B854u: goto label_18b854;
            case 0x18B858u: goto label_18b858;
            case 0x18B85Cu: goto label_18b85c;
            case 0x18B860u: goto label_18b860;
            case 0x18B864u: goto label_18b864;
            case 0x18B868u: goto label_18b868;
            case 0x18B86Cu: goto label_18b86c;
            case 0x18B870u: goto label_18b870;
            case 0x18B874u: goto label_18b874;
            case 0x18B878u: goto label_18b878;
            case 0x18B87Cu: goto label_18b87c;
            case 0x18B880u: goto label_18b880;
            case 0x18B884u: goto label_18b884;
            case 0x18B888u: goto label_18b888;
            case 0x18B88Cu: goto label_18b88c;
            case 0x18B890u: goto label_18b890;
            case 0x18B894u: goto label_18b894;
            case 0x18B898u: goto label_18b898;
            case 0x18B89Cu: goto label_18b89c;
            case 0x18B8A0u: goto label_18b8a0;
            case 0x18B8A4u: goto label_18b8a4;
            case 0x18B8A8u: goto label_18b8a8;
            case 0x18B8ACu: goto label_18b8ac;
            case 0x18B8B0u: goto label_18b8b0;
            case 0x18B8B4u: goto label_18b8b4;
            case 0x18B8B8u: goto label_18b8b8;
            case 0x18B8BCu: goto label_18b8bc;
            case 0x18B8C0u: goto label_18b8c0;
            case 0x18B8C4u: goto label_18b8c4;
            case 0x18B8C8u: goto label_18b8c8;
            case 0x18B8CCu: goto label_18b8cc;
            case 0x18B8D0u: goto label_18b8d0;
            case 0x18B8D4u: goto label_18b8d4;
            case 0x18B8D8u: goto label_18b8d8;
            case 0x18B8DCu: goto label_18b8dc;
            case 0x18B8E0u: goto label_18b8e0;
            case 0x18B8E4u: goto label_18b8e4;
            case 0x18B8E8u: goto label_18b8e8;
            case 0x18B8ECu: goto label_18b8ec;
            case 0x18B8F0u: goto label_18b8f0;
            case 0x18B8F4u: goto label_18b8f4;
            case 0x18B8F8u: goto label_18b8f8;
            case 0x18B8FCu: goto label_18b8fc;
            case 0x18B900u: goto label_18b900;
            case 0x18B904u: goto label_18b904;
            case 0x18B908u: goto label_18b908;
            case 0x18B90Cu: goto label_18b90c;
            case 0x18B910u: goto label_18b910;
            case 0x18B914u: goto label_18b914;
            case 0x18B918u: goto label_18b918;
            case 0x18B91Cu: goto label_18b91c;
            case 0x18B920u: goto label_18b920;
            case 0x18B924u: goto label_18b924;
            case 0x18B928u: goto label_18b928;
            case 0x18B92Cu: goto label_18b92c;
            case 0x18B930u: goto label_18b930;
            case 0x18B934u: goto label_18b934;
            case 0x18B938u: goto label_18b938;
            case 0x18B93Cu: goto label_18b93c;
            case 0x18B940u: goto label_18b940;
            case 0x18B944u: goto label_18b944;
            case 0x18B948u: goto label_18b948;
            case 0x18B94Cu: goto label_18b94c;
            case 0x18B950u: goto label_18b950;
            case 0x18B954u: goto label_18b954;
            case 0x18B958u: goto label_18b958;
            case 0x18B95Cu: goto label_18b95c;
            case 0x18B960u: goto label_18b960;
            case 0x18B964u: goto label_18b964;
            case 0x18B968u: goto label_18b968;
            case 0x18B96Cu: goto label_18b96c;
            case 0x18B970u: goto label_18b970;
            case 0x18B974u: goto label_18b974;
            case 0x18B978u: goto label_18b978;
            case 0x18B97Cu: goto label_18b97c;
            case 0x18B980u: goto label_18b980;
            case 0x18B984u: goto label_18b984;
            case 0x18B988u: goto label_18b988;
            case 0x18B98Cu: goto label_18b98c;
            case 0x18B990u: goto label_18b990;
            case 0x18B994u: goto label_18b994;
            case 0x18B998u: goto label_18b998;
            case 0x18B99Cu: goto label_18b99c;
            case 0x18B9A0u: goto label_18b9a0;
            case 0x18B9A4u: goto label_18b9a4;
            case 0x18B9A8u: goto label_18b9a8;
            case 0x18B9ACu: goto label_18b9ac;
            case 0x18B9B0u: goto label_18b9b0;
            case 0x18B9B4u: goto label_18b9b4;
            case 0x18B9B8u: goto label_18b9b8;
            case 0x18B9BCu: goto label_18b9bc;
            case 0x18B9C0u: goto label_18b9c0;
            case 0x18B9C4u: goto label_18b9c4;
            case 0x18B9C8u: goto label_18b9c8;
            case 0x18B9CCu: goto label_18b9cc;
            case 0x18B9D0u: goto label_18b9d0;
            case 0x18B9D4u: goto label_18b9d4;
            case 0x18B9D8u: goto label_18b9d8;
            case 0x18B9DCu: goto label_18b9dc;
            case 0x18B9E0u: goto label_18b9e0;
            case 0x18B9E4u: goto label_18b9e4;
            case 0x18B9E8u: goto label_18b9e8;
            case 0x18B9ECu: goto label_18b9ec;
            case 0x18B9F0u: goto label_18b9f0;
            case 0x18B9F4u: goto label_18b9f4;
            case 0x18B9F8u: goto label_18b9f8;
            case 0x18B9FCu: goto label_18b9fc;
            case 0x18BA00u: goto label_18ba00;
            case 0x18BA04u: goto label_18ba04;
            case 0x18BA08u: goto label_18ba08;
            case 0x18BA0Cu: goto label_18ba0c;
            case 0x18BA10u: goto label_18ba10;
            case 0x18BA14u: goto label_18ba14;
            case 0x18BA18u: goto label_18ba18;
            case 0x18BA1Cu: goto label_18ba1c;
            case 0x18BA20u: goto label_18ba20;
            case 0x18BA24u: goto label_18ba24;
            case 0x18BA28u: goto label_18ba28;
            case 0x18BA2Cu: goto label_18ba2c;
            case 0x18BA30u: goto label_18ba30;
            case 0x18BA34u: goto label_18ba34;
            case 0x18BA38u: goto label_18ba38;
            case 0x18BA3Cu: goto label_18ba3c;
            case 0x18BA40u: goto label_18ba40;
            case 0x18BA44u: goto label_18ba44;
            case 0x18BA48u: goto label_18ba48;
            case 0x18BA4Cu: goto label_18ba4c;
            case 0x18BA50u: goto label_18ba50;
            case 0x18BA54u: goto label_18ba54;
            case 0x18BA58u: goto label_18ba58;
            case 0x18BA5Cu: goto label_18ba5c;
            case 0x18BA60u: goto label_18ba60;
            case 0x18BA64u: goto label_18ba64;
            case 0x18BA68u: goto label_18ba68;
            case 0x18BA6Cu: goto label_18ba6c;
            case 0x18BA70u: goto label_18ba70;
            case 0x18BA74u: goto label_18ba74;
            case 0x18BA78u: goto label_18ba78;
            case 0x18BA7Cu: goto label_18ba7c;
            case 0x18BA80u: goto label_18ba80;
            case 0x18BA84u: goto label_18ba84;
            case 0x18BA88u: goto label_18ba88;
            case 0x18BA8Cu: goto label_18ba8c;
            case 0x18BA90u: goto label_18ba90;
            case 0x18BA94u: goto label_18ba94;
            case 0x18BA98u: goto label_18ba98;
            case 0x18BA9Cu: goto label_18ba9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18B4F4u;
label_18b4f4:
    // 0x18b4f4: 0xa0802d
    ctx->pc = 0x18b4f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_18b4f8:
    // 0x18b4f8: 0x80302d
    ctx->pc = 0x18b4f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_18b4fc:
    // 0x18b4fc: 0x200202d
    ctx->pc = 0x18b4fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_18b500:
    // 0x18b500: 0x2405000c
    ctx->pc = 0x18b500u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 12));
label_18b504:
    // 0x18b504: 0x382d
    ctx->pc = 0x18b504u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18b508:
    // 0x18b508: 0xc0631cc
label_18b50c:
    if (ctx->pc == 0x18B50Cu) {
        ctx->pc = 0x18B50Cu;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B510u;
        goto label_18b510;
    }
    ctx->pc = 0x18B508u;
    SET_GPR_U32(ctx, 31, 0x18B510u);
    ctx->pc = 0x18B50Cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B510u; }
    }
    if (ctx->pc != 0x18B510u) { return; }
    ctx->pc = 0x18B510u;
label_18b510:
    // 0x18b510: 0x26040010
    ctx->pc = 0x18b510u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 16));
label_18b514:
    // 0x18b514: 0x2405000a
    ctx->pc = 0x18b514u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 10));
label_18b518:
    // 0x18b518: 0xc063204
label_18b51c:
    if (ctx->pc == 0x18B51Cu) {
        ctx->pc = 0x18B51Cu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B520u;
        goto label_18b520;
    }
    ctx->pc = 0x18B518u;
    SET_GPR_U32(ctx, 31, 0x18B520u);
    ctx->pc = 0x18B51Cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B520u; }
    }
    if (ctx->pc != 0x18B520u) { return; }
    ctx->pc = 0x18B520u;
label_18b520:
    // 0x18b520: 0x3c021000
    ctx->pc = 0x18b520u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_18b524:
    // 0x18b524: 0x7e000020
    ctx->pc = 0x18b524u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
label_18b528:
    // 0x18b528: 0x2183c
    ctx->pc = 0x18b528u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
label_18b52c:
    // 0x18b52c: 0x26050040
    ctx->pc = 0x18b52cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 64));
label_18b530:
    // 0x18b530: 0x34028006
    ctx->pc = 0x18b530u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32774));
label_18b534:
    // 0x18b534: 0x26060050
    ctx->pc = 0x18b534u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 80));
label_18b538:
    // 0x18b538: 0x431825
    ctx->pc = 0x18b538u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18b53c:
    // 0x18b53c: 0x26070060
    ctx->pc = 0x18b53cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 96));
label_18b540:
    // 0x18b540: 0x2402000e
    ctx->pc = 0x18b540u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14));
label_18b544:
    // 0x18b544: 0xfe030030
    ctx->pc = 0x18b544u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
label_18b548:
    // 0x18b548: 0xae020038
    ctx->pc = 0x18b548u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
label_18b54c:
    // 0x18b54c: 0x26080070
    ctx->pc = 0x18b54cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 16), 112));
label_18b550:
    // 0x18b550: 0xae00003c
    ctx->pc = 0x18b550u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
label_18b554:
    // 0x18b554: 0x26090080
    ctx->pc = 0x18b554u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 16), 128));
label_18b558:
    // 0x18b558: 0x8e240044
    ctx->pc = 0x18b558u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 68)));
label_18b55c:
    // 0x18b55c: 0xc062f1c
label_18b560:
    if (ctx->pc == 0x18B560u) {
        ctx->pc = 0x18B560u;
        SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 16), 144));
        ctx->pc = 0x18B564u;
        goto label_18b564;
    }
    ctx->pc = 0x18B55Cu;
    SET_GPR_U32(ctx, 31, 0x18B564u);
    ctx->pc = 0x18B560u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 16), 144));
    ctx->pc = 0x18BC70u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BC70_0x18bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B564u; }
    }
    if (ctx->pc != 0x18B564u) { return; }
    ctx->pc = 0x18B564u;
label_18b564:
    // 0x18b564: 0xc6200004
    ctx->pc = 0x18b564u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b568:
    // 0x18b568: 0x3c024300
    ctx->pc = 0x18b568u;
    SET_GPR_U32(ctx, 2, ((uint32_t)17152 << 16));
label_18b56c:
    // 0x18b56c: 0x44820800
    ctx->pc = 0x18b56cu;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 2);
label_18b570:
    // 0x18b570: 0x260400c0
    ctx->pc = 0x18b570u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 192));
label_18b574:
    // 0x18b574: 0xe60000a0
    ctx->pc = 0x18b574u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 160), bits); }
label_18b578:
    // 0x18b578: 0xc6200008
    ctx->pc = 0x18b578u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b57c:
    // 0x18b57c: 0xe60000a4
    ctx->pc = 0x18b57cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 164), bits); }
label_18b580:
    // 0x18b580: 0xc620000c
    ctx->pc = 0x18b580u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b584:
    // 0x18b584: 0xe60000a8
    ctx->pc = 0x18b584u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 168), bits); }
label_18b588:
    // 0x18b588: 0xc6200010
    ctx->pc = 0x18b588u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b58c:
    // 0x18b58c: 0x46000802
    ctx->pc = 0x18b58cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
label_18b590:
    // 0x18b590: 0xe60000ac
    ctx->pc = 0x18b590u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 172), bits); }
label_18b594:
    // 0x18b594: 0xc6200024
    ctx->pc = 0x18b594u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b598:
    // 0x18b598: 0xe60000b0
    ctx->pc = 0x18b598u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 176), bits); }
label_18b59c:
    // 0x18b59c: 0xc6200028
    ctx->pc = 0x18b59cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b5a0:
    // 0x18b5a0: 0xe60000b4
    ctx->pc = 0x18b5a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 180), bits); }
label_18b5a4:
    // 0x18b5a4: 0xc620002c
    ctx->pc = 0x18b5a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b5a8:
    // 0x18b5a8: 0xe60000b8
    ctx->pc = 0x18b5a8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 184), bits); }
label_18b5ac:
    // 0x18b5ac: 0xc6200030
    ctx->pc = 0x18b5acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b5b0:
    // 0x18b5b0: 0xc0631fc
label_18b5b4:
    if (ctx->pc == 0x18B5B4u) {
        ctx->pc = 0x18B5B4u;
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 188), bits); }
        ctx->pc = 0x18B5B8u;
        goto label_18b5b8;
    }
    ctx->pc = 0x18B5B0u;
    SET_GPR_U32(ctx, 31, 0x18B5B8u);
    ctx->pc = 0x18B5B4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 188), bits); }
    ctx->pc = 0x18C7F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B5B8u; }
    }
    if (ctx->pc != 0x18B5B8u) { return; }
    ctx->pc = 0x18B5B8u;
label_18b5b8:
    // 0x18b5b8: 0x10000133
label_18b5bc:
    if (ctx->pc == 0x18B5BCu) {
        ctx->pc = 0x18B5BCu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->pc = 0x18B5C0u;
        goto label_18b5c0;
    }
    ctx->pc = 0x18B5B8u;
    {
        const bool branch_taken_0x18b5b8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B5BCu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        if (branch_taken_0x18b5b8) {
            ctx->pc = 0x18BA88u;
            goto label_18ba88;
        }
    }
    ctx->pc = 0x18B5C0u;
label_18b5c0:
    // 0x18b5c0: 0xa0802d
    ctx->pc = 0x18b5c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_18b5c4:
    // 0x18b5c4: 0x80302d
    ctx->pc = 0x18b5c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_18b5c8:
    // 0x18b5c8: 0x200202d
    ctx->pc = 0x18b5c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_18b5cc:
    // 0x18b5cc: 0x2405000c
    ctx->pc = 0x18b5ccu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 12));
label_18b5d0:
    // 0x18b5d0: 0x382d
    ctx->pc = 0x18b5d0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18b5d4:
    // 0x18b5d4: 0xc0631cc
label_18b5d8:
    if (ctx->pc == 0x18B5D8u) {
        ctx->pc = 0x18B5D8u;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B5DCu;
        goto label_18b5dc;
    }
    ctx->pc = 0x18B5D4u;
    SET_GPR_U32(ctx, 31, 0x18B5DCu);
    ctx->pc = 0x18B5D8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B5DCu; }
    }
    if (ctx->pc != 0x18B5DCu) { return; }
    ctx->pc = 0x18B5DCu;
label_18b5dc:
    // 0x18b5dc: 0x26040010
    ctx->pc = 0x18b5dcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 16));
label_18b5e0:
    // 0x18b5e0: 0x2405000a
    ctx->pc = 0x18b5e0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 10));
label_18b5e4:
    // 0x18b5e4: 0xc063204
label_18b5e8:
    if (ctx->pc == 0x18B5E8u) {
        ctx->pc = 0x18B5E8u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B5ECu;
        goto label_18b5ec;
    }
    ctx->pc = 0x18B5E4u;
    SET_GPR_U32(ctx, 31, 0x18B5ECu);
    ctx->pc = 0x18B5E8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B5ECu; }
    }
    if (ctx->pc != 0x18B5ECu) { return; }
    ctx->pc = 0x18B5ECu;
label_18b5ec:
    // 0x18b5ec: 0x3c021000
    ctx->pc = 0x18b5ecu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_18b5f0:
    // 0x18b5f0: 0x7e000020
    ctx->pc = 0x18b5f0u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
label_18b5f4:
    // 0x18b5f4: 0x2183c
    ctx->pc = 0x18b5f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
label_18b5f8:
    // 0x18b5f8: 0x24040006
    ctx->pc = 0x18b5f8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 6));
label_18b5fc:
    // 0x18b5fc: 0x34028006
    ctx->pc = 0x18b5fcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32774));
label_18b600:
    // 0x18b600: 0x24060008
    ctx->pc = 0x18b600u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 8));
label_18b604:
    // 0x18b604: 0x431825
    ctx->pc = 0x18b604u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18b608:
    // 0x18b608: 0x24050034
    ctx->pc = 0x18b608u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 52));
label_18b60c:
    // 0x18b60c: 0xfe030030
    ctx->pc = 0x18b60cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
label_18b610:
    // 0x18b610: 0x2402000e
    ctx->pc = 0x18b610u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14));
label_18b614:
    // 0x18b614: 0xae020038
    ctx->pc = 0x18b614u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
label_18b618:
    // 0x18b618: 0x2403003b
    ctx->pc = 0x18b618u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 59));
label_18b61c:
    // 0x18b61c: 0xae00003c
    ctx->pc = 0x18b61cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
label_18b620:
    // 0x18b620: 0x24020014
    ctx->pc = 0x18b620u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 20));
label_18b624:
    // 0x18b624: 0xfe000040
    ctx->pc = 0x18b624u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 64), GPR_U64(ctx, 0));
label_18b628:
    // 0x18b628: 0xfe030048
    ctx->pc = 0x18b628u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 72), GPR_U64(ctx, 3));
label_18b62c:
    // 0x18b62c: 0xfe000050
    ctx->pc = 0x18b62cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 80), GPR_U64(ctx, 0));
label_18b630:
    // 0x18b630: 0x24030036
    ctx->pc = 0x18b630u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 54));
label_18b634:
    // 0x18b634: 0xfe020058
    ctx->pc = 0x18b634u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 88), GPR_U64(ctx, 2));
label_18b638:
    // 0x18b638: 0xfe000060
    ctx->pc = 0x18b638u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 96), GPR_U64(ctx, 0));
label_18b63c:
    // 0x18b63c: 0x3c024300
    ctx->pc = 0x18b63cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)17152 << 16));
label_18b640:
    // 0x18b640: 0xfe040068
    ctx->pc = 0x18b640u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 104), GPR_U64(ctx, 4));
label_18b644:
    // 0x18b644: 0x44820800
    ctx->pc = 0x18b644u;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 2);
label_18b648:
    // 0x18b648: 0xfe000070
    ctx->pc = 0x18b648u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 112), GPR_U64(ctx, 0));
label_18b64c:
    // 0x18b64c: 0x260400c0
    ctx->pc = 0x18b64cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 192));
label_18b650:
    // 0x18b650: 0xfe060078
    ctx->pc = 0x18b650u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 120), GPR_U64(ctx, 6));
label_18b654:
    // 0x18b654: 0xfe000080
    ctx->pc = 0x18b654u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 128), GPR_U64(ctx, 0));
label_18b658:
    // 0x18b658: 0xfe050088
    ctx->pc = 0x18b658u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 136), GPR_U64(ctx, 5));
label_18b65c:
    // 0x18b65c: 0xfe000090
    ctx->pc = 0x18b65cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 144), GPR_U64(ctx, 0));
label_18b660:
    // 0x18b660: 0xfe030098
    ctx->pc = 0x18b660u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 152), GPR_U64(ctx, 3));
label_18b664:
    // 0x18b664: 0xc6200004
    ctx->pc = 0x18b664u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b668:
    // 0x18b668: 0xe60000a0
    ctx->pc = 0x18b668u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 160), bits); }
label_18b66c:
    // 0x18b66c: 0xc6200008
    ctx->pc = 0x18b66cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b670:
    // 0x18b670: 0xe60000a4
    ctx->pc = 0x18b670u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 164), bits); }
label_18b674:
    // 0x18b674: 0xc620000c
    ctx->pc = 0x18b674u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b678:
    // 0x18b678: 0xe60000a8
    ctx->pc = 0x18b678u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 168), bits); }
label_18b67c:
    // 0x18b67c: 0xc6200010
    ctx->pc = 0x18b67cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b680:
    // 0x18b680: 0x46000802
    ctx->pc = 0x18b680u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
label_18b684:
    // 0x18b684: 0xe60000ac
    ctx->pc = 0x18b684u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 172), bits); }
label_18b688:
    // 0x18b688: 0xc6200024
    ctx->pc = 0x18b688u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b68c:
    // 0x18b68c: 0xe60000b0
    ctx->pc = 0x18b68cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 176), bits); }
label_18b690:
    // 0x18b690: 0xc6200028
    ctx->pc = 0x18b690u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b694:
    // 0x18b694: 0xe60000b4
    ctx->pc = 0x18b694u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 180), bits); }
label_18b698:
    // 0x18b698: 0xc620002c
    ctx->pc = 0x18b698u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b69c:
    // 0x18b69c: 0xe60000b8
    ctx->pc = 0x18b69cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 184), bits); }
label_18b6a0:
    // 0x18b6a0: 0xc6200030
    ctx->pc = 0x18b6a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b6a4:
    // 0x18b6a4: 0xc0631fc
label_18b6a8:
    if (ctx->pc == 0x18B6A8u) {
        ctx->pc = 0x18B6A8u;
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 188), bits); }
        ctx->pc = 0x18B6ACu;
        goto label_18b6ac;
    }
    ctx->pc = 0x18B6A4u;
    SET_GPR_U32(ctx, 31, 0x18B6ACu);
    ctx->pc = 0x18B6A8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 188), bits); }
    ctx->pc = 0x18C7F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B6ACu; }
    }
    if (ctx->pc != 0x18B6ACu) { return; }
    ctx->pc = 0x18B6ACu;
label_18b6ac:
    // 0x18b6ac: 0x100000f5
label_18b6b0:
    if (ctx->pc == 0x18B6B0u) {
        ctx->pc = 0x18B6B4u;
        goto label_18b6b4;
    }
    ctx->pc = 0x18B6ACu;
    {
        const bool branch_taken_0x18b6ac = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18b6ac) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B6B4u;
label_18b6b4:
    // 0x18b6b4: 0xa0802d
    ctx->pc = 0x18b6b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_18b6b8:
    // 0x18b6b8: 0x80302d
    ctx->pc = 0x18b6b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_18b6bc:
    // 0x18b6bc: 0x200202d
    ctx->pc = 0x18b6bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_18b6c0:
    // 0x18b6c0: 0x2405000e
    ctx->pc = 0x18b6c0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 14));
label_18b6c4:
    // 0x18b6c4: 0x382d
    ctx->pc = 0x18b6c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18b6c8:
    // 0x18b6c8: 0xc0631cc
label_18b6cc:
    if (ctx->pc == 0x18B6CCu) {
        ctx->pc = 0x18B6CCu;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B6D0u;
        goto label_18b6d0;
    }
    ctx->pc = 0x18B6C8u;
    SET_GPR_U32(ctx, 31, 0x18B6D0u);
    ctx->pc = 0x18B6CCu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B6D0u; }
    }
    if (ctx->pc != 0x18B6D0u) { return; }
    ctx->pc = 0x18B6D0u;
label_18b6d0:
    // 0x18b6d0: 0x26040010
    ctx->pc = 0x18b6d0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 16));
label_18b6d4:
    // 0x18b6d4: 0x2405000c
    ctx->pc = 0x18b6d4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 12));
label_18b6d8:
    // 0x18b6d8: 0xc063204
label_18b6dc:
    if (ctx->pc == 0x18B6DCu) {
        ctx->pc = 0x18B6DCu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B6E0u;
        goto label_18b6e0;
    }
    ctx->pc = 0x18B6D8u;
    SET_GPR_U32(ctx, 31, 0x18B6E0u);
    ctx->pc = 0x18B6DCu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B6E0u; }
    }
    if (ctx->pc != 0x18B6E0u) { return; }
    ctx->pc = 0x18B6E0u;
label_18b6e0:
    // 0x18b6e0: 0x3c021000
    ctx->pc = 0x18b6e0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_18b6e4:
    // 0x18b6e4: 0x7e000020
    ctx->pc = 0x18b6e4u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
label_18b6e8:
    // 0x18b6e8: 0x2183c
    ctx->pc = 0x18b6e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
label_18b6ec:
    // 0x18b6ec: 0x26050040
    ctx->pc = 0x18b6ecu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 64));
label_18b6f0:
    // 0x18b6f0: 0x34028006
    ctx->pc = 0x18b6f0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32774));
label_18b6f4:
    // 0x18b6f4: 0x26060050
    ctx->pc = 0x18b6f4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 80));
label_18b6f8:
    // 0x18b6f8: 0x431825
    ctx->pc = 0x18b6f8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18b6fc:
    // 0x18b6fc: 0x26070060
    ctx->pc = 0x18b6fcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 96));
label_18b700:
    // 0x18b700: 0x2402000e
    ctx->pc = 0x18b700u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14));
label_18b704:
    // 0x18b704: 0xfe030030
    ctx->pc = 0x18b704u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
label_18b708:
    // 0x18b708: 0xae020038
    ctx->pc = 0x18b708u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
label_18b70c:
    // 0x18b70c: 0x26080070
    ctx->pc = 0x18b70cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 16), 112));
label_18b710:
    // 0x18b710: 0xae00003c
    ctx->pc = 0x18b710u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
label_18b714:
    // 0x18b714: 0x26090080
    ctx->pc = 0x18b714u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 16), 128));
label_18b718:
    // 0x18b718: 0x8e240044
    ctx->pc = 0x18b718u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 68)));
label_18b71c:
    // 0x18b71c: 0xc062f1c
label_18b720:
    if (ctx->pc == 0x18B720u) {
        ctx->pc = 0x18B720u;
        SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 16), 144));
        ctx->pc = 0x18B724u;
        goto label_18b724;
    }
    ctx->pc = 0x18B71Cu;
    SET_GPR_U32(ctx, 31, 0x18B724u);
    ctx->pc = 0x18B720u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 16), 144));
    ctx->pc = 0x18BC70u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BC70_0x18bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B724u; }
    }
    if (ctx->pc != 0x18B724u) { return; }
    ctx->pc = 0x18B724u;
label_18b724:
    // 0x18b724: 0xc6200004
    ctx->pc = 0x18b724u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b728:
    // 0x18b728: 0x3c024300
    ctx->pc = 0x18b728u;
    SET_GPR_U32(ctx, 2, ((uint32_t)17152 << 16));
label_18b72c:
    // 0x18b72c: 0x44820800
    ctx->pc = 0x18b72cu;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 2);
label_18b730:
    // 0x18b730: 0x24020100
    ctx->pc = 0x18b730u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 256));
label_18b734:
    // 0x18b734: 0xe60000a0
    ctx->pc = 0x18b734u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 160), bits); }
label_18b738:
    // 0x18b738: 0xc6200008
    ctx->pc = 0x18b738u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b73c:
    // 0x18b73c: 0xe60000a4
    ctx->pc = 0x18b73cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 164), bits); }
label_18b740:
    // 0x18b740: 0xc620000c
    ctx->pc = 0x18b740u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b744:
    // 0x18b744: 0xe60000a8
    ctx->pc = 0x18b744u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 168), bits); }
label_18b748:
    // 0x18b748: 0xc6200010
    ctx->pc = 0x18b748u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b74c:
    // 0x18b74c: 0x46000802
    ctx->pc = 0x18b74cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
label_18b750:
    // 0x18b750: 0xe60000ac
    ctx->pc = 0x18b750u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 172), bits); }
label_18b754:
    // 0x18b754: 0xc6200024
    ctx->pc = 0x18b754u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b758:
    // 0x18b758: 0xe60000b0
    ctx->pc = 0x18b758u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 176), bits); }
label_18b75c:
    // 0x18b75c: 0xc6200028
    ctx->pc = 0x18b75cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b760:
    // 0x18b760: 0xe60000b4
    ctx->pc = 0x18b760u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 180), bits); }
label_18b764:
    // 0x18b764: 0xc620002c
    ctx->pc = 0x18b764u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b768:
    // 0x18b768: 0xe60000b8
    ctx->pc = 0x18b768u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 184), bits); }
label_18b76c:
    // 0x18b76c: 0xc6200030
    ctx->pc = 0x18b76cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b770:
    // 0x18b770: 0xe60000bc
    ctx->pc = 0x18b770u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 188), bits); }
label_18b774:
    // 0x18b774: 0xc6200014
    ctx->pc = 0x18b774u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b778:
    // 0x18b778: 0xe60000c0
    ctx->pc = 0x18b778u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 192), bits); }
label_18b77c:
    // 0x18b77c: 0xc6200018
    ctx->pc = 0x18b77cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b780:
    // 0x18b780: 0xe60000c4
    ctx->pc = 0x18b780u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 196), bits); }
label_18b784:
    // 0x18b784: 0xc620001c
    ctx->pc = 0x18b784u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b788:
    // 0x18b788: 0xe60000c8
    ctx->pc = 0x18b788u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 200), bits); }
label_18b78c:
    // 0x18b78c: 0xc6200020
    ctx->pc = 0x18b78cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18b790:
    // 0x18b790: 0xe60000cc
    ctx->pc = 0x18b790u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 204), bits); }
label_18b794:
    // 0x18b794: 0x8e230048
    ctx->pc = 0x18b794u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 72)));
label_18b798:
    // 0x18b798: 0x1062002e
label_18b79c:
    if (ctx->pc == 0x18B79Cu) {
        ctx->pc = 0x18B79Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 128));
        ctx->pc = 0x18B7A0u;
        goto label_18b7a0;
    }
    ctx->pc = 0x18B798u;
    {
        const bool branch_taken_0x18b798 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x18B79Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 128));
        if (branch_taken_0x18b798) {
            ctx->pc = 0x18B854u;
            goto label_18b854;
        }
    }
    ctx->pc = 0x18B7A0u;
label_18b7a0:
    // 0x18b7a0: 0x10620029
label_18b7a4:
    if (ctx->pc == 0x18B7A4u) {
        ctx->pc = 0x18B7A8u;
        goto label_18b7a8;
    }
    ctx->pc = 0x18B7A0u;
    {
        const bool branch_taken_0x18b7a0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x18b7a0) {
            ctx->pc = 0x18B848u;
            goto label_18b848;
        }
    }
    ctx->pc = 0x18B7A8u;
label_18b7a8:
    // 0x18b7a8: 0x24020040
    ctx->pc = 0x18b7a8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 64));
label_18b7ac:
    // 0x18b7ac: 0x10620023
label_18b7b0:
    if (ctx->pc == 0x18B7B0u) {
        ctx->pc = 0x18B7B0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 32));
        ctx->pc = 0x18B7B4u;
        goto label_18b7b4;
    }
    ctx->pc = 0x18B7ACu;
    {
        const bool branch_taken_0x18b7ac = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x18B7B0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 32));
        if (branch_taken_0x18b7ac) {
            ctx->pc = 0x18B83Cu;
            goto label_18b83c;
        }
    }
    ctx->pc = 0x18B7B4u;
label_18b7b4:
    // 0x18b7b4: 0x1062001e
label_18b7b8:
    if (ctx->pc == 0x18B7B8u) {
        ctx->pc = 0x18B7BCu;
        goto label_18b7bc;
    }
    ctx->pc = 0x18B7B4u;
    {
        const bool branch_taken_0x18b7b4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x18b7b4) {
            ctx->pc = 0x18B830u;
            goto label_18b830;
        }
    }
    ctx->pc = 0x18B7BCu;
label_18b7bc:
    // 0x18b7bc: 0x24020010
    ctx->pc = 0x18b7bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 16));
label_18b7c0:
    // 0x18b7c0: 0x10620018
label_18b7c4:
    if (ctx->pc == 0x18B7C4u) {
        ctx->pc = 0x18B7C4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8));
        ctx->pc = 0x18B7C8u;
        goto label_18b7c8;
    }
    ctx->pc = 0x18B7C0u;
    {
        const bool branch_taken_0x18b7c0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x18B7C4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8));
        if (branch_taken_0x18b7c0) {
            ctx->pc = 0x18B824u;
            goto label_18b824;
        }
    }
    ctx->pc = 0x18B7C8u;
label_18b7c8:
    // 0x18b7c8: 0x10620013
label_18b7cc:
    if (ctx->pc == 0x18B7CCu) {
        ctx->pc = 0x18B7D0u;
        goto label_18b7d0;
    }
    ctx->pc = 0x18B7C8u;
    {
        const bool branch_taken_0x18b7c8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x18b7c8) {
            ctx->pc = 0x18B818u;
            goto label_18b818;
        }
    }
    ctx->pc = 0x18B7D0u;
label_18b7d0:
    // 0x18b7d0: 0x24020004
    ctx->pc = 0x18b7d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
label_18b7d4:
    // 0x18b7d4: 0x1062000d
label_18b7d8:
    if (ctx->pc == 0x18B7D8u) {
        ctx->pc = 0x18B7D8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x18B7DCu;
        goto label_18b7dc;
    }
    ctx->pc = 0x18B7D4u;
    {
        const bool branch_taken_0x18b7d4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x18B7D8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x18b7d4) {
            ctx->pc = 0x18B80Cu;
            goto label_18b80c;
        }
    }
    ctx->pc = 0x18B7DCu;
label_18b7dc:
    // 0x18b7dc: 0x10620008
label_18b7e0:
    if (ctx->pc == 0x18B7E0u) {
        ctx->pc = 0x18B7E4u;
        goto label_18b7e4;
    }
    ctx->pc = 0x18B7DCu;
    {
        const bool branch_taken_0x18b7dc = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x18b7dc) {
            ctx->pc = 0x18B800u;
            goto label_18b800;
        }
    }
    ctx->pc = 0x18B7E4u;
label_18b7e4:
    // 0x18b7e4: 0x24020001
    ctx->pc = 0x18b7e4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_18b7e8:
    // 0x18b7e8: 0x10620005
label_18b7ec:
    if (ctx->pc == 0x18B7ECu) {
        ctx->pc = 0x18B7F0u;
        goto label_18b7f0;
    }
    ctx->pc = 0x18B7E8u;
    {
        const bool branch_taken_0x18b7e8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x18b7e8) {
            ctx->pc = 0x18B800u;
            goto label_18b800;
        }
    }
    ctx->pc = 0x18B7F0u;
label_18b7f0:
    // 0x18b7f0: 0x10600003
label_18b7f4:
    if (ctx->pc == 0x18B7F4u) {
        ctx->pc = 0x18B7F8u;
        goto label_18b7f8;
    }
    ctx->pc = 0x18B7F0u;
    {
        const bool branch_taken_0x18b7f0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x18b7f0) {
            ctx->pc = 0x18B800u;
            goto label_18b800;
        }
    }
    ctx->pc = 0x18B7F8u;
label_18b7f8:
    // 0x18b7f8: 0x10000019
label_18b7fc:
    if (ctx->pc == 0x18B7FCu) {
        ctx->pc = 0x18B7FCu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->pc = 0x18B800u;
        goto label_18b800;
    }
    ctx->pc = 0x18B7F8u;
    {
        const bool branch_taken_0x18b7f8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B7FCu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
        if (branch_taken_0x18b7f8) {
            ctx->pc = 0x18B860u;
            goto label_18b860;
        }
    }
    ctx->pc = 0x18B800u;
label_18b800:
    // 0x18b800: 0x24030001
    ctx->pc = 0x18b800u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
label_18b804:
    // 0x18b804: 0x10000017
label_18b808:
    if (ctx->pc == 0x18B808u) {
        ctx->pc = 0x18B808u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B80Cu;
        goto label_18b80c;
    }
    ctx->pc = 0x18B804u;
    {
        const bool branch_taken_0x18b804 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B808u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18b804) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B80Cu;
label_18b80c:
    // 0x18b80c: 0x24030002
    ctx->pc = 0x18b80cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_18b810:
    // 0x18b810: 0x10000014
label_18b814:
    if (ctx->pc == 0x18B814u) {
        ctx->pc = 0x18B814u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x18B818u;
        goto label_18b818;
    }
    ctx->pc = 0x18B810u;
    {
        const bool branch_taken_0x18b810 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B814u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18b810) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B818u;
label_18b818:
    // 0x18b818: 0x24030003
    ctx->pc = 0x18b818u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
label_18b81c:
    // 0x18b81c: 0x10000011
label_18b820:
    if (ctx->pc == 0x18B820u) {
        ctx->pc = 0x18B820u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x18B824u;
        goto label_18b824;
    }
    ctx->pc = 0x18B81Cu;
    {
        const bool branch_taken_0x18b81c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B820u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18b81c) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B824u;
label_18b824:
    // 0x18b824: 0x24030004
    ctx->pc = 0x18b824u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4));
label_18b828:
    // 0x18b828: 0x1000000e
label_18b82c:
    if (ctx->pc == 0x18B82Cu) {
        ctx->pc = 0x18B82Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x18B830u;
        goto label_18b830;
    }
    ctx->pc = 0x18B828u;
    {
        const bool branch_taken_0x18b828 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B82Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18b828) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B830u;
label_18b830:
    // 0x18b830: 0x24030005
    ctx->pc = 0x18b830u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 5));
label_18b834:
    // 0x18b834: 0x1000000b
label_18b838:
    if (ctx->pc == 0x18B838u) {
        ctx->pc = 0x18B838u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x18B83Cu;
        goto label_18b83c;
    }
    ctx->pc = 0x18B834u;
    {
        const bool branch_taken_0x18b834 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B838u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18b834) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B83Cu;
label_18b83c:
    // 0x18b83c: 0x24030006
    ctx->pc = 0x18b83cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 6));
label_18b840:
    // 0x18b840: 0x10000008
label_18b844:
    if (ctx->pc == 0x18B844u) {
        ctx->pc = 0x18B844u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x18B848u;
        goto label_18b848;
    }
    ctx->pc = 0x18B840u;
    {
        const bool branch_taken_0x18b840 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B844u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18b840) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B848u;
label_18b848:
    // 0x18b848: 0x24030007
    ctx->pc = 0x18b848u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 7));
label_18b84c:
    // 0x18b84c: 0x10000005
label_18b850:
    if (ctx->pc == 0x18B850u) {
        ctx->pc = 0x18B850u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x18B854u;
        goto label_18b854;
    }
    ctx->pc = 0x18B84Cu;
    {
        const bool branch_taken_0x18b84c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B850u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18b84c) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B854u;
label_18b854:
    // 0x18b854: 0x24030008
    ctx->pc = 0x18b854u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
label_18b858:
    // 0x18b858: 0x10000002
label_18b85c:
    if (ctx->pc == 0x18B85Cu) {
        ctx->pc = 0x18B85Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x18B860u;
        goto label_18b860;
    }
    ctx->pc = 0x18B858u;
    {
        const bool branch_taken_0x18b858 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18B85Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18b858) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B860u;
label_18b860:
    // 0x18b860: 0x102d
    ctx->pc = 0x18b860u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18b864:
    // 0x18b864: 0xae0300d0
    ctx->pc = 0x18b864u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 208), GPR_U32(ctx, 3));
label_18b868:
    // 0x18b868: 0x260400e0
    ctx->pc = 0x18b868u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 224));
label_18b86c:
    // 0x18b86c: 0xae0200d4
    ctx->pc = 0x18b86cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 212), GPR_U32(ctx, 2));
label_18b870:
    // 0x18b870: 0xae0000d8
    ctx->pc = 0x18b870u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 216), GPR_U32(ctx, 0));
label_18b874:
    // 0x18b874: 0xc0631fc
label_18b878:
    if (ctx->pc == 0x18B878u) {
        ctx->pc = 0x18B878u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 220), GPR_U32(ctx, 0));
        ctx->pc = 0x18B87Cu;
        goto label_18b87c;
    }
    ctx->pc = 0x18B874u;
    SET_GPR_U32(ctx, 31, 0x18B87Cu);
    ctx->pc = 0x18B878u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 220), GPR_U32(ctx, 0));
    ctx->pc = 0x18C7F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B87Cu; }
    }
    if (ctx->pc != 0x18B87Cu) { return; }
    ctx->pc = 0x18B87Cu;
label_18b87c:
    // 0x18b87c: 0x10000081
label_18b880:
    if (ctx->pc == 0x18B880u) {
        ctx->pc = 0x18B884u;
        goto label_18b884;
    }
    ctx->pc = 0x18B87Cu;
    {
        const bool branch_taken_0x18b87c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18b87c) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B884u;
label_18b884:
    // 0x18b884: 0xa0802d
    ctx->pc = 0x18b884u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_18b888:
    // 0x18b888: 0x80302d
    ctx->pc = 0x18b888u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_18b88c:
    // 0x18b88c: 0x200202d
    ctx->pc = 0x18b88cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_18b890:
    // 0x18b890: 0x2405000a
    ctx->pc = 0x18b890u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 10));
label_18b894:
    // 0x18b894: 0x382d
    ctx->pc = 0x18b894u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18b898:
    // 0x18b898: 0xc0631cc
label_18b89c:
    if (ctx->pc == 0x18B89Cu) {
        ctx->pc = 0x18B89Cu;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B8A0u;
        goto label_18b8a0;
    }
    ctx->pc = 0x18B898u;
    SET_GPR_U32(ctx, 31, 0x18B8A0u);
    ctx->pc = 0x18B89Cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8A0u; }
    }
    if (ctx->pc != 0x18B8A0u) { return; }
    ctx->pc = 0x18B8A0u;
label_18b8a0:
    // 0x18b8a0: 0x26040010
    ctx->pc = 0x18b8a0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 16));
label_18b8a4:
    // 0x18b8a4: 0x24050008
    ctx->pc = 0x18b8a4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_18b8a8:
    // 0x18b8a8: 0xc063204
label_18b8ac:
    if (ctx->pc == 0x18B8ACu) {
        ctx->pc = 0x18B8ACu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B8B0u;
        goto label_18b8b0;
    }
    ctx->pc = 0x18B8A8u;
    SET_GPR_U32(ctx, 31, 0x18B8B0u);
    ctx->pc = 0x18B8ACu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8B0u; }
    }
    if (ctx->pc != 0x18B8B0u) { return; }
    ctx->pc = 0x18B8B0u;
label_18b8b0:
    // 0x18b8b0: 0x3c021000
    ctx->pc = 0x18b8b0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_18b8b4:
    // 0x18b8b4: 0x7e000020
    ctx->pc = 0x18b8b4u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
label_18b8b8:
    // 0x18b8b8: 0x2183c
    ctx->pc = 0x18b8b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
label_18b8bc:
    // 0x18b8bc: 0x26050040
    ctx->pc = 0x18b8bcu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 64));
label_18b8c0:
    // 0x18b8c0: 0x34028006
    ctx->pc = 0x18b8c0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32774));
label_18b8c4:
    // 0x18b8c4: 0x26060050
    ctx->pc = 0x18b8c4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 80));
label_18b8c8:
    // 0x18b8c8: 0x431825
    ctx->pc = 0x18b8c8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18b8cc:
    // 0x18b8cc: 0x26070060
    ctx->pc = 0x18b8ccu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 96));
label_18b8d0:
    // 0x18b8d0: 0x2402000e
    ctx->pc = 0x18b8d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14));
label_18b8d4:
    // 0x18b8d4: 0xfe030030
    ctx->pc = 0x18b8d4u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
label_18b8d8:
    // 0x18b8d8: 0xae020038
    ctx->pc = 0x18b8d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
label_18b8dc:
    // 0x18b8dc: 0x26080070
    ctx->pc = 0x18b8dcu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 16), 112));
label_18b8e0:
    // 0x18b8e0: 0xae00003c
    ctx->pc = 0x18b8e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
label_18b8e4:
    // 0x18b8e4: 0x26090080
    ctx->pc = 0x18b8e4u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 16), 128));
label_18b8e8:
    // 0x18b8e8: 0x8e240044
    ctx->pc = 0x18b8e8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 68)));
label_18b8ec:
    // 0x18b8ec: 0xc062f1c
label_18b8f0:
    if (ctx->pc == 0x18B8F0u) {
        ctx->pc = 0x18B8F0u;
        SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 16), 144));
        ctx->pc = 0x18B8F4u;
        goto label_18b8f4;
    }
    ctx->pc = 0x18B8ECu;
    SET_GPR_U32(ctx, 31, 0x18B8F4u);
    ctx->pc = 0x18B8F0u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 16), 144));
    ctx->pc = 0x18BC70u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BC70_0x18bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8F4u; }
    }
    if (ctx->pc != 0x18B8F4u) { return; }
    ctx->pc = 0x18B8F4u;
label_18b8f4:
    // 0x18b8f4: 0xc0631fc
label_18b8f8:
    if (ctx->pc == 0x18B8F8u) {
        ctx->pc = 0x18B8F8u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 160));
        ctx->pc = 0x18B8FCu;
        goto label_18b8fc;
    }
    ctx->pc = 0x18B8F4u;
    SET_GPR_U32(ctx, 31, 0x18B8FCu);
    ctx->pc = 0x18B8F8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 160));
    ctx->pc = 0x18C7F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8FCu; }
    }
    if (ctx->pc != 0x18B8FCu) { return; }
    ctx->pc = 0x18B8FCu;
label_18b8fc:
    // 0x18b8fc: 0x10000061
label_18b900:
    if (ctx->pc == 0x18B900u) {
        ctx->pc = 0x18B904u;
        goto label_18b904;
    }
    ctx->pc = 0x18B8FCu;
    {
        const bool branch_taken_0x18b8fc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18b8fc) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B904u;
label_18b904:
    // 0x18b904: 0xa0802d
    ctx->pc = 0x18b904u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_18b908:
    // 0x18b908: 0x80302d
    ctx->pc = 0x18b908u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_18b90c:
    // 0x18b90c: 0x200202d
    ctx->pc = 0x18b90cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_18b910:
    // 0x18b910: 0x2405000b
    ctx->pc = 0x18b910u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 11));
label_18b914:
    // 0x18b914: 0x382d
    ctx->pc = 0x18b914u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18b918:
    // 0x18b918: 0xc0631cc
label_18b91c:
    if (ctx->pc == 0x18B91Cu) {
        ctx->pc = 0x18B91Cu;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B920u;
        goto label_18b920;
    }
    ctx->pc = 0x18B918u;
    SET_GPR_U32(ctx, 31, 0x18B920u);
    ctx->pc = 0x18B91Cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B920u; }
    }
    if (ctx->pc != 0x18B920u) { return; }
    ctx->pc = 0x18B920u;
label_18b920:
    // 0x18b920: 0x26040010
    ctx->pc = 0x18b920u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 16));
label_18b924:
    // 0x18b924: 0x24050009
    ctx->pc = 0x18b924u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 9));
label_18b928:
    // 0x18b928: 0xc063204
label_18b92c:
    if (ctx->pc == 0x18B92Cu) {
        ctx->pc = 0x18B92Cu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B930u;
        goto label_18b930;
    }
    ctx->pc = 0x18B928u;
    SET_GPR_U32(ctx, 31, 0x18B930u);
    ctx->pc = 0x18B92Cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B930u; }
    }
    if (ctx->pc != 0x18B930u) { return; }
    ctx->pc = 0x18B930u;
label_18b930:
    // 0x18b930: 0x3c021000
    ctx->pc = 0x18b930u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_18b934:
    // 0x18b934: 0x7e000020
    ctx->pc = 0x18b934u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
label_18b938:
    // 0x18b938: 0x2183c
    ctx->pc = 0x18b938u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
label_18b93c:
    // 0x18b93c: 0x24040014
    ctx->pc = 0x18b93cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 20));
label_18b940:
    // 0x18b940: 0x34028006
    ctx->pc = 0x18b940u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32774));
label_18b944:
    // 0x18b944: 0x24060006
    ctx->pc = 0x18b944u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 6));
label_18b948:
    // 0x18b948: 0x431025
    ctx->pc = 0x18b948u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18b94c:
    // 0x18b94c: 0x24050008
    ctx->pc = 0x18b94cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_18b950:
    // 0x18b950: 0xfe020030
    ctx->pc = 0x18b950u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 2));
label_18b954:
    // 0x18b954: 0x2403000e
    ctx->pc = 0x18b954u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 14));
label_18b958:
    // 0x18b958: 0xae030038
    ctx->pc = 0x18b958u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
label_18b95c:
    // 0x18b95c: 0x2402003b
    ctx->pc = 0x18b95cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 59));
label_18b960:
    // 0x18b960: 0xae00003c
    ctx->pc = 0x18b960u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
label_18b964:
    // 0x18b964: 0x24030034
    ctx->pc = 0x18b964u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 52));
label_18b968:
    // 0x18b968: 0xfe000040
    ctx->pc = 0x18b968u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 64), GPR_U64(ctx, 0));
label_18b96c:
    // 0x18b96c: 0xfe020048
    ctx->pc = 0x18b96cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 72), GPR_U64(ctx, 2));
label_18b970:
    // 0x18b970: 0xfe000050
    ctx->pc = 0x18b970u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 80), GPR_U64(ctx, 0));
label_18b974:
    // 0x18b974: 0x24020036
    ctx->pc = 0x18b974u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 54));
label_18b978:
    // 0x18b978: 0xfe040058
    ctx->pc = 0x18b978u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 88), GPR_U64(ctx, 4));
label_18b97c:
    // 0x18b97c: 0xfe000060
    ctx->pc = 0x18b97cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 96), GPR_U64(ctx, 0));
label_18b980:
    // 0x18b980: 0x260400b0
    ctx->pc = 0x18b980u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 176));
label_18b984:
    // 0x18b984: 0xfe060068
    ctx->pc = 0x18b984u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 104), GPR_U64(ctx, 6));
label_18b988:
    // 0x18b988: 0xfe000070
    ctx->pc = 0x18b988u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 112), GPR_U64(ctx, 0));
label_18b98c:
    // 0x18b98c: 0xfe050078
    ctx->pc = 0x18b98cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 120), GPR_U64(ctx, 5));
label_18b990:
    // 0x18b990: 0xfe000080
    ctx->pc = 0x18b990u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 128), GPR_U64(ctx, 0));
label_18b994:
    // 0x18b994: 0xfe030088
    ctx->pc = 0x18b994u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 136), GPR_U64(ctx, 3));
label_18b998:
    // 0x18b998: 0xfe000090
    ctx->pc = 0x18b998u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 144), GPR_U64(ctx, 0));
label_18b99c:
    // 0x18b99c: 0xfe020098
    ctx->pc = 0x18b99cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 152), GPR_U64(ctx, 2));
label_18b9a0:
    // 0x18b9a0: 0xc0631fc
label_18b9a4:
    if (ctx->pc == 0x18B9A4u) {
        ctx->pc = 0x18B9A4u;
        WRITE128(ADD32(GPR_U32(ctx, 16), 160), GPR_VEC(ctx, 0));
        ctx->pc = 0x18B9A8u;
        goto label_18b9a8;
    }
    ctx->pc = 0x18B9A0u;
    SET_GPR_U32(ctx, 31, 0x18B9A8u);
    ctx->pc = 0x18B9A4u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 160), GPR_VEC(ctx, 0));
    ctx->pc = 0x18C7F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B9A8u; }
    }
    if (ctx->pc != 0x18B9A8u) { return; }
    ctx->pc = 0x18B9A8u;
label_18b9a8:
    // 0x18b9a8: 0x10000036
label_18b9ac:
    if (ctx->pc == 0x18B9ACu) {
        ctx->pc = 0x18B9B0u;
        goto label_18b9b0;
    }
    ctx->pc = 0x18B9A8u;
    {
        const bool branch_taken_0x18b9a8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18b9a8) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B9B0u;
label_18b9b0:
    // 0x18b9b0: 0xa0802d
    ctx->pc = 0x18b9b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_18b9b4:
    // 0x18b9b4: 0x80302d
    ctx->pc = 0x18b9b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_18b9b8:
    // 0x18b9b8: 0x200202d
    ctx->pc = 0x18b9b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_18b9bc:
    // 0x18b9bc: 0x24050010
    ctx->pc = 0x18b9bcu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
label_18b9c0:
    // 0x18b9c0: 0x382d
    ctx->pc = 0x18b9c0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18b9c4:
    // 0x18b9c4: 0xc0631cc
label_18b9c8:
    if (ctx->pc == 0x18B9C8u) {
        ctx->pc = 0x18B9C8u;
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B9CCu;
        goto label_18b9cc;
    }
    ctx->pc = 0x18B9C4u;
    SET_GPR_U32(ctx, 31, 0x18B9CCu);
    ctx->pc = 0x18B9C8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B9CCu; }
    }
    if (ctx->pc != 0x18B9CCu) { return; }
    ctx->pc = 0x18B9CCu;
label_18b9cc:
    // 0x18b9cc: 0x26040010
    ctx->pc = 0x18b9ccu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 16));
label_18b9d0:
    // 0x18b9d0: 0x2405000e
    ctx->pc = 0x18b9d0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 14));
label_18b9d4:
    // 0x18b9d4: 0xc063204
label_18b9d8:
    if (ctx->pc == 0x18B9D8u) {
        ctx->pc = 0x18B9D8u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18B9DCu;
        goto label_18b9dc;
    }
    ctx->pc = 0x18B9D4u;
    SET_GPR_U32(ctx, 31, 0x18B9DCu);
    ctx->pc = 0x18B9D8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B9DCu; }
    }
    if (ctx->pc != 0x18B9DCu) { return; }
    ctx->pc = 0x18B9DCu;
label_18b9dc:
    // 0x18b9dc: 0x3c021000
    ctx->pc = 0x18b9dcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_18b9e0:
    // 0x18b9e0: 0x7e000020
    ctx->pc = 0x18b9e0u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
label_18b9e4:
    // 0x18b9e4: 0x2183c
    ctx->pc = 0x18b9e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
label_18b9e8:
    // 0x18b9e8: 0x260400c0
    ctx->pc = 0x18b9e8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 192));
label_18b9ec:
    // 0x18b9ec: 0x3402800b
    ctx->pc = 0x18b9ecu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32779));
label_18b9f0:
    // 0x18b9f0: 0x3c010029
    ctx->pc = 0x18b9f0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
label_18b9f4:
    // 0x18b9f4: 0x431825
    ctx->pc = 0x18b9f4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18b9f8:
    // 0x18b9f8: 0x26050040
    ctx->pc = 0x18b9f8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 64));
label_18b9fc:
    // 0x18b9fc: 0xfe030030
    ctx->pc = 0x18b9fcu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
label_18ba00:
    // 0x18ba00: 0x2402000e
    ctx->pc = 0x18ba00u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14));
label_18ba04:
    // 0x18ba04: 0xae020038
    ctx->pc = 0x18ba04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
label_18ba08:
    // 0x18ba08: 0x260300a0
    ctx->pc = 0x18ba08u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 16), 160));
label_18ba0c:
    // 0x18ba0c: 0xae00003c
    ctx->pc = 0x18ba0cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
label_18ba10:
    // 0x18ba10: 0x260200b0
    ctx->pc = 0x18ba10u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 176));
label_18ba14:
    // 0x18ba14: 0xffa30000
    ctx->pc = 0x18ba14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 3));
label_18ba18:
    // 0x18ba18: 0x26060050
    ctx->pc = 0x18ba18u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 80));
label_18ba1c:
    // 0x18ba1c: 0xffa20008
    ctx->pc = 0x18ba1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 2));
label_18ba20:
    // 0x18ba20: 0x260300d0
    ctx->pc = 0x18ba20u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 16), 208));
label_18ba24:
    // 0x18ba24: 0xffa40010
    ctx->pc = 0x18ba24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 4));
label_18ba28:
    // 0x18ba28: 0x260200e0
    ctx->pc = 0x18ba28u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 224));
label_18ba2c:
    // 0x18ba2c: 0xffa30018
    ctx->pc = 0x18ba2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 3));
label_18ba30:
    // 0x18ba30: 0x26070060
    ctx->pc = 0x18ba30u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 96));
label_18ba34:
    // 0x18ba34: 0xffa20020
    ctx->pc = 0x18ba34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 2));
label_18ba38:
    // 0x18ba38: 0x26080070
    ctx->pc = 0x18ba38u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 16), 112));
label_18ba3c:
    // 0x18ba3c: 0x8e240044
    ctx->pc = 0x18ba3cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 68)));
label_18ba40:
    // 0x18ba40: 0x26090080
    ctx->pc = 0x18ba40u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 16), 128));
label_18ba44:
    // 0x18ba44: 0x8c2b4e64
    ctx->pc = 0x18ba44u;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 1), 20068)));
label_18ba48:
    // 0x18ba48: 0xc062f58
label_18ba4c:
    if (ctx->pc == 0x18BA4Cu) {
        ctx->pc = 0x18BA4Cu;
        SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 16), 144));
        ctx->pc = 0x18BA50u;
        goto label_18ba50;
    }
    ctx->pc = 0x18BA48u;
    SET_GPR_U32(ctx, 31, 0x18BA50u);
    ctx->pc = 0x18BA4Cu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 16), 144));
    ctx->pc = 0x18BD60u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BD60_0x18bd60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BA50u; }
    }
    if (ctx->pc != 0x18BA50u) { return; }
    ctx->pc = 0x18BA50u;
label_18ba50:
    // 0x18ba50: 0xc6200004
    ctx->pc = 0x18ba50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18ba54:
    // 0x18ba54: 0x3c024300
    ctx->pc = 0x18ba54u;
    SET_GPR_U32(ctx, 2, ((uint32_t)17152 << 16));
label_18ba58:
    // 0x18ba58: 0x44820800
    ctx->pc = 0x18ba58u;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 2);
label_18ba5c:
    // 0x18ba5c: 0x26040100
    ctx->pc = 0x18ba5cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 256));
label_18ba60:
    // 0x18ba60: 0xe60000f0
    ctx->pc = 0x18ba60u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 240), bits); }
label_18ba64:
    // 0x18ba64: 0xc6200008
    ctx->pc = 0x18ba64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18ba68:
    // 0x18ba68: 0xe60000f4
    ctx->pc = 0x18ba68u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 244), bits); }
label_18ba6c:
    // 0x18ba6c: 0xc620000c
    ctx->pc = 0x18ba6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18ba70:
    // 0x18ba70: 0xe60000f8
    ctx->pc = 0x18ba70u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 248), bits); }
label_18ba74:
    // 0x18ba74: 0xc6200010
    ctx->pc = 0x18ba74u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_18ba78:
    // 0x18ba78: 0x46000802
    ctx->pc = 0x18ba78u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
label_18ba7c:
    // 0x18ba7c: 0xc0631fc
label_18ba80:
    if (ctx->pc == 0x18BA80u) {
        ctx->pc = 0x18BA80u;
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 252), bits); }
        ctx->pc = 0x18BA84u;
        goto label_18ba84;
    }
    ctx->pc = 0x18BA7Cu;
    SET_GPR_U32(ctx, 31, 0x18BA84u);
    ctx->pc = 0x18BA80u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 252), bits); }
    ctx->pc = 0x18C7F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BA84u; }
    }
    if (ctx->pc != 0x18BA84u) { return; }
    ctx->pc = 0x18BA84u;
label_18ba84:
    // 0x18ba84: 0xdfbf0050
    ctx->pc = 0x18ba84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_18ba88:
    // 0x18ba88: 0x7bb10040
    ctx->pc = 0x18ba88u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 64)));
label_18ba8c:
    // 0x18ba8c: 0x7bb00030
    ctx->pc = 0x18ba8cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 48)));
label_18ba90:
    // 0x18ba90: 0x3e00008
label_18ba94:
    if (ctx->pc == 0x18BA94u) {
        ctx->pc = 0x18BA94u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = 0x18BA98u;
        goto label_18ba98;
    }
    ctx->pc = 0x18BA90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18BA94u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18B4A0u: goto label_18b4a0;
            case 0x18B4A4u: goto label_18b4a4;
            case 0x18B4A8u: goto label_18b4a8;
            case 0x18B4ACu: goto label_18b4ac;
            case 0x18B4B0u: goto label_18b4b0;
            case 0x18B4B4u: goto label_18b4b4;
            case 0x18B4B8u: goto label_18b4b8;
            case 0x18B4BCu: goto label_18b4bc;
            case 0x18B4C0u: goto label_18b4c0;
            case 0x18B4C4u: goto label_18b4c4;
            case 0x18B4C8u: goto label_18b4c8;
            case 0x18B4CCu: goto label_18b4cc;
            case 0x18B4D0u: goto label_18b4d0;
            case 0x18B4D4u: goto label_18b4d4;
            case 0x18B4D8u: goto label_18b4d8;
            case 0x18B4DCu: goto label_18b4dc;
            case 0x18B4E0u: goto label_18b4e0;
            case 0x18B4E4u: goto label_18b4e4;
            case 0x18B4E8u: goto label_18b4e8;
            case 0x18B4ECu: goto label_18b4ec;
            case 0x18B4F0u: goto label_18b4f0;
            case 0x18B4F4u: goto label_18b4f4;
            case 0x18B4F8u: goto label_18b4f8;
            case 0x18B4FCu: goto label_18b4fc;
            case 0x18B500u: goto label_18b500;
            case 0x18B504u: goto label_18b504;
            case 0x18B508u: goto label_18b508;
            case 0x18B50Cu: goto label_18b50c;
            case 0x18B510u: goto label_18b510;
            case 0x18B514u: goto label_18b514;
            case 0x18B518u: goto label_18b518;
            case 0x18B51Cu: goto label_18b51c;
            case 0x18B520u: goto label_18b520;
            case 0x18B524u: goto label_18b524;
            case 0x18B528u: goto label_18b528;
            case 0x18B52Cu: goto label_18b52c;
            case 0x18B530u: goto label_18b530;
            case 0x18B534u: goto label_18b534;
            case 0x18B538u: goto label_18b538;
            case 0x18B53Cu: goto label_18b53c;
            case 0x18B540u: goto label_18b540;
            case 0x18B544u: goto label_18b544;
            case 0x18B548u: goto label_18b548;
            case 0x18B54Cu: goto label_18b54c;
            case 0x18B550u: goto label_18b550;
            case 0x18B554u: goto label_18b554;
            case 0x18B558u: goto label_18b558;
            case 0x18B55Cu: goto label_18b55c;
            case 0x18B560u: goto label_18b560;
            case 0x18B564u: goto label_18b564;
            case 0x18B568u: goto label_18b568;
            case 0x18B56Cu: goto label_18b56c;
            case 0x18B570u: goto label_18b570;
            case 0x18B574u: goto label_18b574;
            case 0x18B578u: goto label_18b578;
            case 0x18B57Cu: goto label_18b57c;
            case 0x18B580u: goto label_18b580;
            case 0x18B584u: goto label_18b584;
            case 0x18B588u: goto label_18b588;
            case 0x18B58Cu: goto label_18b58c;
            case 0x18B590u: goto label_18b590;
            case 0x18B594u: goto label_18b594;
            case 0x18B598u: goto label_18b598;
            case 0x18B59Cu: goto label_18b59c;
            case 0x18B5A0u: goto label_18b5a0;
            case 0x18B5A4u: goto label_18b5a4;
            case 0x18B5A8u: goto label_18b5a8;
            case 0x18B5ACu: goto label_18b5ac;
            case 0x18B5B0u: goto label_18b5b0;
            case 0x18B5B4u: goto label_18b5b4;
            case 0x18B5B8u: goto label_18b5b8;
            case 0x18B5BCu: goto label_18b5bc;
            case 0x18B5C0u: goto label_18b5c0;
            case 0x18B5C4u: goto label_18b5c4;
            case 0x18B5C8u: goto label_18b5c8;
            case 0x18B5CCu: goto label_18b5cc;
            case 0x18B5D0u: goto label_18b5d0;
            case 0x18B5D4u: goto label_18b5d4;
            case 0x18B5D8u: goto label_18b5d8;
            case 0x18B5DCu: goto label_18b5dc;
            case 0x18B5E0u: goto label_18b5e0;
            case 0x18B5E4u: goto label_18b5e4;
            case 0x18B5E8u: goto label_18b5e8;
            case 0x18B5ECu: goto label_18b5ec;
            case 0x18B5F0u: goto label_18b5f0;
            case 0x18B5F4u: goto label_18b5f4;
            case 0x18B5F8u: goto label_18b5f8;
            case 0x18B5FCu: goto label_18b5fc;
            case 0x18B600u: goto label_18b600;
            case 0x18B604u: goto label_18b604;
            case 0x18B608u: goto label_18b608;
            case 0x18B60Cu: goto label_18b60c;
            case 0x18B610u: goto label_18b610;
            case 0x18B614u: goto label_18b614;
            case 0x18B618u: goto label_18b618;
            case 0x18B61Cu: goto label_18b61c;
            case 0x18B620u: goto label_18b620;
            case 0x18B624u: goto label_18b624;
            case 0x18B628u: goto label_18b628;
            case 0x18B62Cu: goto label_18b62c;
            case 0x18B630u: goto label_18b630;
            case 0x18B634u: goto label_18b634;
            case 0x18B638u: goto label_18b638;
            case 0x18B63Cu: goto label_18b63c;
            case 0x18B640u: goto label_18b640;
            case 0x18B644u: goto label_18b644;
            case 0x18B648u: goto label_18b648;
            case 0x18B64Cu: goto label_18b64c;
            case 0x18B650u: goto label_18b650;
            case 0x18B654u: goto label_18b654;
            case 0x18B658u: goto label_18b658;
            case 0x18B65Cu: goto label_18b65c;
            case 0x18B660u: goto label_18b660;
            case 0x18B664u: goto label_18b664;
            case 0x18B668u: goto label_18b668;
            case 0x18B66Cu: goto label_18b66c;
            case 0x18B670u: goto label_18b670;
            case 0x18B674u: goto label_18b674;
            case 0x18B678u: goto label_18b678;
            case 0x18B67Cu: goto label_18b67c;
            case 0x18B680u: goto label_18b680;
            case 0x18B684u: goto label_18b684;
            case 0x18B688u: goto label_18b688;
            case 0x18B68Cu: goto label_18b68c;
            case 0x18B690u: goto label_18b690;
            case 0x18B694u: goto label_18b694;
            case 0x18B698u: goto label_18b698;
            case 0x18B69Cu: goto label_18b69c;
            case 0x18B6A0u: goto label_18b6a0;
            case 0x18B6A4u: goto label_18b6a4;
            case 0x18B6A8u: goto label_18b6a8;
            case 0x18B6ACu: goto label_18b6ac;
            case 0x18B6B0u: goto label_18b6b0;
            case 0x18B6B4u: goto label_18b6b4;
            case 0x18B6B8u: goto label_18b6b8;
            case 0x18B6BCu: goto label_18b6bc;
            case 0x18B6C0u: goto label_18b6c0;
            case 0x18B6C4u: goto label_18b6c4;
            case 0x18B6C8u: goto label_18b6c8;
            case 0x18B6CCu: goto label_18b6cc;
            case 0x18B6D0u: goto label_18b6d0;
            case 0x18B6D4u: goto label_18b6d4;
            case 0x18B6D8u: goto label_18b6d8;
            case 0x18B6DCu: goto label_18b6dc;
            case 0x18B6E0u: goto label_18b6e0;
            case 0x18B6E4u: goto label_18b6e4;
            case 0x18B6E8u: goto label_18b6e8;
            case 0x18B6ECu: goto label_18b6ec;
            case 0x18B6F0u: goto label_18b6f0;
            case 0x18B6F4u: goto label_18b6f4;
            case 0x18B6F8u: goto label_18b6f8;
            case 0x18B6FCu: goto label_18b6fc;
            case 0x18B700u: goto label_18b700;
            case 0x18B704u: goto label_18b704;
            case 0x18B708u: goto label_18b708;
            case 0x18B70Cu: goto label_18b70c;
            case 0x18B710u: goto label_18b710;
            case 0x18B714u: goto label_18b714;
            case 0x18B718u: goto label_18b718;
            case 0x18B71Cu: goto label_18b71c;
            case 0x18B720u: goto label_18b720;
            case 0x18B724u: goto label_18b724;
            case 0x18B728u: goto label_18b728;
            case 0x18B72Cu: goto label_18b72c;
            case 0x18B730u: goto label_18b730;
            case 0x18B734u: goto label_18b734;
            case 0x18B738u: goto label_18b738;
            case 0x18B73Cu: goto label_18b73c;
            case 0x18B740u: goto label_18b740;
            case 0x18B744u: goto label_18b744;
            case 0x18B748u: goto label_18b748;
            case 0x18B74Cu: goto label_18b74c;
            case 0x18B750u: goto label_18b750;
            case 0x18B754u: goto label_18b754;
            case 0x18B758u: goto label_18b758;
            case 0x18B75Cu: goto label_18b75c;
            case 0x18B760u: goto label_18b760;
            case 0x18B764u: goto label_18b764;
            case 0x18B768u: goto label_18b768;
            case 0x18B76Cu: goto label_18b76c;
            case 0x18B770u: goto label_18b770;
            case 0x18B774u: goto label_18b774;
            case 0x18B778u: goto label_18b778;
            case 0x18B77Cu: goto label_18b77c;
            case 0x18B780u: goto label_18b780;
            case 0x18B784u: goto label_18b784;
            case 0x18B788u: goto label_18b788;
            case 0x18B78Cu: goto label_18b78c;
            case 0x18B790u: goto label_18b790;
            case 0x18B794u: goto label_18b794;
            case 0x18B798u: goto label_18b798;
            case 0x18B79Cu: goto label_18b79c;
            case 0x18B7A0u: goto label_18b7a0;
            case 0x18B7A4u: goto label_18b7a4;
            case 0x18B7A8u: goto label_18b7a8;
            case 0x18B7ACu: goto label_18b7ac;
            case 0x18B7B0u: goto label_18b7b0;
            case 0x18B7B4u: goto label_18b7b4;
            case 0x18B7B8u: goto label_18b7b8;
            case 0x18B7BCu: goto label_18b7bc;
            case 0x18B7C0u: goto label_18b7c0;
            case 0x18B7C4u: goto label_18b7c4;
            case 0x18B7C8u: goto label_18b7c8;
            case 0x18B7CCu: goto label_18b7cc;
            case 0x18B7D0u: goto label_18b7d0;
            case 0x18B7D4u: goto label_18b7d4;
            case 0x18B7D8u: goto label_18b7d8;
            case 0x18B7DCu: goto label_18b7dc;
            case 0x18B7E0u: goto label_18b7e0;
            case 0x18B7E4u: goto label_18b7e4;
            case 0x18B7E8u: goto label_18b7e8;
            case 0x18B7ECu: goto label_18b7ec;
            case 0x18B7F0u: goto label_18b7f0;
            case 0x18B7F4u: goto label_18b7f4;
            case 0x18B7F8u: goto label_18b7f8;
            case 0x18B7FCu: goto label_18b7fc;
            case 0x18B800u: goto label_18b800;
            case 0x18B804u: goto label_18b804;
            case 0x18B808u: goto label_18b808;
            case 0x18B80Cu: goto label_18b80c;
            case 0x18B810u: goto label_18b810;
            case 0x18B814u: goto label_18b814;
            case 0x18B818u: goto label_18b818;
            case 0x18B81Cu: goto label_18b81c;
            case 0x18B820u: goto label_18b820;
            case 0x18B824u: goto label_18b824;
            case 0x18B828u: goto label_18b828;
            case 0x18B82Cu: goto label_18b82c;
            case 0x18B830u: goto label_18b830;
            case 0x18B834u: goto label_18b834;
            case 0x18B838u: goto label_18b838;
            case 0x18B83Cu: goto label_18b83c;
            case 0x18B840u: goto label_18b840;
            case 0x18B844u: goto label_18b844;
            case 0x18B848u: goto label_18b848;
            case 0x18B84Cu: goto label_18b84c;
            case 0x18B850u: goto label_18b850;
            case 0x18B854u: goto label_18b854;
            case 0x18B858u: goto label_18b858;
            case 0x18B85Cu: goto label_18b85c;
            case 0x18B860u: goto label_18b860;
            case 0x18B864u: goto label_18b864;
            case 0x18B868u: goto label_18b868;
            case 0x18B86Cu: goto label_18b86c;
            case 0x18B870u: goto label_18b870;
            case 0x18B874u: goto label_18b874;
            case 0x18B878u: goto label_18b878;
            case 0x18B87Cu: goto label_18b87c;
            case 0x18B880u: goto label_18b880;
            case 0x18B884u: goto label_18b884;
            case 0x18B888u: goto label_18b888;
            case 0x18B88Cu: goto label_18b88c;
            case 0x18B890u: goto label_18b890;
            case 0x18B894u: goto label_18b894;
            case 0x18B898u: goto label_18b898;
            case 0x18B89Cu: goto label_18b89c;
            case 0x18B8A0u: goto label_18b8a0;
            case 0x18B8A4u: goto label_18b8a4;
            case 0x18B8A8u: goto label_18b8a8;
            case 0x18B8ACu: goto label_18b8ac;
            case 0x18B8B0u: goto label_18b8b0;
            case 0x18B8B4u: goto label_18b8b4;
            case 0x18B8B8u: goto label_18b8b8;
            case 0x18B8BCu: goto label_18b8bc;
            case 0x18B8C0u: goto label_18b8c0;
            case 0x18B8C4u: goto label_18b8c4;
            case 0x18B8C8u: goto label_18b8c8;
            case 0x18B8CCu: goto label_18b8cc;
            case 0x18B8D0u: goto label_18b8d0;
            case 0x18B8D4u: goto label_18b8d4;
            case 0x18B8D8u: goto label_18b8d8;
            case 0x18B8DCu: goto label_18b8dc;
            case 0x18B8E0u: goto label_18b8e0;
            case 0x18B8E4u: goto label_18b8e4;
            case 0x18B8E8u: goto label_18b8e8;
            case 0x18B8ECu: goto label_18b8ec;
            case 0x18B8F0u: goto label_18b8f0;
            case 0x18B8F4u: goto label_18b8f4;
            case 0x18B8F8u: goto label_18b8f8;
            case 0x18B8FCu: goto label_18b8fc;
            case 0x18B900u: goto label_18b900;
            case 0x18B904u: goto label_18b904;
            case 0x18B908u: goto label_18b908;
            case 0x18B90Cu: goto label_18b90c;
            case 0x18B910u: goto label_18b910;
            case 0x18B914u: goto label_18b914;
            case 0x18B918u: goto label_18b918;
            case 0x18B91Cu: goto label_18b91c;
            case 0x18B920u: goto label_18b920;
            case 0x18B924u: goto label_18b924;
            case 0x18B928u: goto label_18b928;
            case 0x18B92Cu: goto label_18b92c;
            case 0x18B930u: goto label_18b930;
            case 0x18B934u: goto label_18b934;
            case 0x18B938u: goto label_18b938;
            case 0x18B93Cu: goto label_18b93c;
            case 0x18B940u: goto label_18b940;
            case 0x18B944u: goto label_18b944;
            case 0x18B948u: goto label_18b948;
            case 0x18B94Cu: goto label_18b94c;
            case 0x18B950u: goto label_18b950;
            case 0x18B954u: goto label_18b954;
            case 0x18B958u: goto label_18b958;
            case 0x18B95Cu: goto label_18b95c;
            case 0x18B960u: goto label_18b960;
            case 0x18B964u: goto label_18b964;
            case 0x18B968u: goto label_18b968;
            case 0x18B96Cu: goto label_18b96c;
            case 0x18B970u: goto label_18b970;
            case 0x18B974u: goto label_18b974;
            case 0x18B978u: goto label_18b978;
            case 0x18B97Cu: goto label_18b97c;
            case 0x18B980u: goto label_18b980;
            case 0x18B984u: goto label_18b984;
            case 0x18B988u: goto label_18b988;
            case 0x18B98Cu: goto label_18b98c;
            case 0x18B990u: goto label_18b990;
            case 0x18B994u: goto label_18b994;
            case 0x18B998u: goto label_18b998;
            case 0x18B99Cu: goto label_18b99c;
            case 0x18B9A0u: goto label_18b9a0;
            case 0x18B9A4u: goto label_18b9a4;
            case 0x18B9A8u: goto label_18b9a8;
            case 0x18B9ACu: goto label_18b9ac;
            case 0x18B9B0u: goto label_18b9b0;
            case 0x18B9B4u: goto label_18b9b4;
            case 0x18B9B8u: goto label_18b9b8;
            case 0x18B9BCu: goto label_18b9bc;
            case 0x18B9C0u: goto label_18b9c0;
            case 0x18B9C4u: goto label_18b9c4;
            case 0x18B9C8u: goto label_18b9c8;
            case 0x18B9CCu: goto label_18b9cc;
            case 0x18B9D0u: goto label_18b9d0;
            case 0x18B9D4u: goto label_18b9d4;
            case 0x18B9D8u: goto label_18b9d8;
            case 0x18B9DCu: goto label_18b9dc;
            case 0x18B9E0u: goto label_18b9e0;
            case 0x18B9E4u: goto label_18b9e4;
            case 0x18B9E8u: goto label_18b9e8;
            case 0x18B9ECu: goto label_18b9ec;
            case 0x18B9F0u: goto label_18b9f0;
            case 0x18B9F4u: goto label_18b9f4;
            case 0x18B9F8u: goto label_18b9f8;
            case 0x18B9FCu: goto label_18b9fc;
            case 0x18BA00u: goto label_18ba00;
            case 0x18BA04u: goto label_18ba04;
            case 0x18BA08u: goto label_18ba08;
            case 0x18BA0Cu: goto label_18ba0c;
            case 0x18BA10u: goto label_18ba10;
            case 0x18BA14u: goto label_18ba14;
            case 0x18BA18u: goto label_18ba18;
            case 0x18BA1Cu: goto label_18ba1c;
            case 0x18BA20u: goto label_18ba20;
            case 0x18BA24u: goto label_18ba24;
            case 0x18BA28u: goto label_18ba28;
            case 0x18BA2Cu: goto label_18ba2c;
            case 0x18BA30u: goto label_18ba30;
            case 0x18BA34u: goto label_18ba34;
            case 0x18BA38u: goto label_18ba38;
            case 0x18BA3Cu: goto label_18ba3c;
            case 0x18BA40u: goto label_18ba40;
            case 0x18BA44u: goto label_18ba44;
            case 0x18BA48u: goto label_18ba48;
            case 0x18BA4Cu: goto label_18ba4c;
            case 0x18BA50u: goto label_18ba50;
            case 0x18BA54u: goto label_18ba54;
            case 0x18BA58u: goto label_18ba58;
            case 0x18BA5Cu: goto label_18ba5c;
            case 0x18BA60u: goto label_18ba60;
            case 0x18BA64u: goto label_18ba64;
            case 0x18BA68u: goto label_18ba68;
            case 0x18BA6Cu: goto label_18ba6c;
            case 0x18BA70u: goto label_18ba70;
            case 0x18BA74u: goto label_18ba74;
            case 0x18BA78u: goto label_18ba78;
            case 0x18BA7Cu: goto label_18ba7c;
            case 0x18BA80u: goto label_18ba80;
            case 0x18BA84u: goto label_18ba84;
            case 0x18BA88u: goto label_18ba88;
            case 0x18BA8Cu: goto label_18ba8c;
            case 0x18BA90u: goto label_18ba90;
            case 0x18BA94u: goto label_18ba94;
            case 0x18BA98u: goto label_18ba98;
            case 0x18BA9Cu: goto label_18ba9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18BA98u;
label_18ba98:
    // 0x18ba98: 0x0
    ctx->pc = 0x18ba98u;
    // NOP
label_18ba9c:
    // 0x18ba9c: 0x0
    ctx->pc = 0x18ba9cu;
    // NOP
}
