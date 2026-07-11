#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00155800
// Address: 0x155800 - 0x155a88
void sub_00155800_0x155800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x155800u;

label_155800:
    // 0x155800: 0x27bdffb0
    ctx->pc = 0x155800u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
label_155804:
    // 0x155804: 0x3c020015
    ctx->pc = 0x155804u;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155808:
    // 0x155808: 0xffb60030
    ctx->pc = 0x155808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
label_15580c:
    // 0x15580c: 0x3c160023
    ctx->pc = 0x15580cu;
    SET_GPR_U32(ctx, 22, ((uint32_t)35 << 16));
label_155810:
    // 0x155810: 0x244259a0
    ctx->pc = 0x155810u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 22944));
label_155814:
    // 0x155814: 0xffb70038
    ctx->pc = 0x155814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
label_155818:
    // 0x155818: 0xaec2d80c
    ctx->pc = 0x155818u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 4294957068), GPR_U32(ctx, 2));
label_15581c:
    // 0x15581c: 0x3c020015
    ctx->pc = 0x15581cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155820:
    // 0x155820: 0x3c170023
    ctx->pc = 0x155820u;
    SET_GPR_U32(ctx, 23, ((uint32_t)35 << 16));
label_155824:
    // 0x155824: 0x244259b0
    ctx->pc = 0x155824u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 22960));
label_155828:
    // 0x155828: 0xaee2d810
    ctx->pc = 0x155828u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 4294957072), GPR_U32(ctx, 2));
label_15582c:
    // 0x15582c: 0x3c020015
    ctx->pc = 0x15582cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155830:
    // 0x155830: 0x3c180023
    ctx->pc = 0x155830u;
    SET_GPR_U32(ctx, 24, ((uint32_t)35 << 16));
label_155834:
    // 0x155834: 0x24425b88
    ctx->pc = 0x155834u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 23432));
label_155838:
    // 0x155838: 0xaf02d814
    ctx->pc = 0x155838u;
    WRITE32(ADD32(GPR_U32(ctx, 24), 4294957076), GPR_U32(ctx, 2));
label_15583c:
    // 0x15583c: 0x3c020015
    ctx->pc = 0x15583cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155840:
    // 0x155840: 0x3c190023
    ctx->pc = 0x155840u;
    SET_GPR_U32(ctx, 25, ((uint32_t)35 << 16));
label_155844:
    // 0x155844: 0x24425b90
    ctx->pc = 0x155844u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 23440));
label_155848:
    // 0x155848: 0xaf22d818
    ctx->pc = 0x155848u;
    WRITE32(ADD32(GPR_U32(ctx, 25), 4294957080), GPR_U32(ctx, 2));
label_15584c:
    // 0x15584c: 0x3c020015
    ctx->pc = 0x15584cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155850:
    // 0x155850: 0xffbe0040
    ctx->pc = 0x155850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
label_155854:
    // 0x155854: 0x3c1e0023
    ctx->pc = 0x155854u;
    SET_GPR_U32(ctx, 30, ((uint32_t)35 << 16));
label_155858:
    // 0x155858: 0x24425cd8
    ctx->pc = 0x155858u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 23768));
label_15585c:
    // 0x15585c: 0xffb00000
    ctx->pc = 0x15585cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_155860:
    // 0x155860: 0xffb10008
    ctx->pc = 0x155860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_155864:
    // 0x155864: 0x3c110023
    ctx->pc = 0x155864u;
    SET_GPR_U32(ctx, 17, ((uint32_t)35 << 16));
label_155868:
    // 0x155868: 0xffb20010
    ctx->pc = 0x155868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_15586c:
    // 0x15586c: 0x3c120023
    ctx->pc = 0x15586cu;
    SET_GPR_U32(ctx, 18, ((uint32_t)35 << 16));
label_155870:
    // 0x155870: 0xffb30018
    ctx->pc = 0x155870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
label_155874:
    // 0x155874: 0x3c130023
    ctx->pc = 0x155874u;
    SET_GPR_U32(ctx, 19, ((uint32_t)35 << 16));
label_155878:
    // 0x155878: 0xffb40020
    ctx->pc = 0x155878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
label_15587c:
    // 0x15587c: 0x3c140023
    ctx->pc = 0x15587cu;
    SET_GPR_U32(ctx, 20, ((uint32_t)35 << 16));
label_155880:
    // 0x155880: 0xffb50028
    ctx->pc = 0x155880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
label_155884:
    // 0x155884: 0x24150001
    ctx->pc = 0x155884u;
    SET_GPR_S32(ctx, 21, ADD32(GPR_U32(ctx, 0), 1));
label_155888:
    // 0x155888: 0xafc2d81c
    ctx->pc = 0x155888u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4294957084), GPR_U32(ctx, 2));
label_15588c:
    // 0x15588c: 0x3c020015
    ctx->pc = 0x15588cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155890:
    // 0x155890: 0x24425d30
    ctx->pc = 0x155890u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 23856));
label_155894:
    // 0x155894: 0x3c050015
    ctx->pc = 0x155894u;
    SET_GPR_U32(ctx, 5, ((uint32_t)21 << 16));
label_155898:
    // 0x155898: 0xae82d820
    ctx->pc = 0x155898u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 4294957088), GPR_U32(ctx, 2));
label_15589c:
    // 0x15589c: 0x3c020015
    ctx->pc = 0x15589cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_1558a0:
    // 0x1558a0: 0x24425d28
    ctx->pc = 0x1558a0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 23848));
label_1558a4:
    // 0x1558a4: 0x3c100023
    ctx->pc = 0x1558a4u;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
label_1558a8:
    // 0x1558a8: 0xae62d824
    ctx->pc = 0x1558a8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294957092), GPR_U32(ctx, 2));
label_1558ac:
    // 0x1558ac: 0x3c020015
    ctx->pc = 0x1558acu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_1558b0:
    // 0x1558b0: 0x24420580
    ctx->pc = 0x1558b0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1408));
label_1558b4:
    // 0x1558b4: 0x3c040015
    ctx->pc = 0x1558b4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)21 << 16));
label_1558b8:
    // 0x1558b8: 0xae42d828
    ctx->pc = 0x1558b8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294957096), GPR_U32(ctx, 2));
label_1558bc:
    // 0x1558bc: 0x3c020015
    ctx->pc = 0x1558bcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_1558c0:
    // 0x1558c0: 0x244205f0
    ctx->pc = 0x1558c0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1520));
label_1558c4:
    // 0x1558c4: 0x3c0f0023
    ctx->pc = 0x1558c4u;
    SET_GPR_U32(ctx, 15, ((uint32_t)35 << 16));
label_1558c8:
    // 0x1558c8: 0xae22d82c
    ctx->pc = 0x1558c8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294957100), GPR_U32(ctx, 2));
label_1558cc:
    // 0x1558cc: 0x3c020015
    ctx->pc = 0x1558ccu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_1558d0:
    // 0x1558d0: 0x244207b0
    ctx->pc = 0x1558d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1968));
label_1558d4:
    // 0x1558d4: 0x3c030015
    ctx->pc = 0x1558d4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)21 << 16));
label_1558d8:
    // 0x1558d8: 0xae02d830
    ctx->pc = 0x1558d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294957104), GPR_U32(ctx, 2));
label_1558dc:
    // 0x1558dc: 0xa0102d
    ctx->pc = 0x1558dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1558e0:
    // 0x1558e0: 0x244206f8
    ctx->pc = 0x1558e0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1784));
label_1558e4:
    // 0x1558e4: 0x3c0e0023
    ctx->pc = 0x1558e4u;
    SET_GPR_U32(ctx, 14, ((uint32_t)35 << 16));
label_1558e8:
    // 0x1558e8: 0xade2d834
    ctx->pc = 0x1558e8u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 4294957108), GPR_U32(ctx, 2));
label_1558ec:
    // 0x1558ec: 0x80102d
    ctx->pc = 0x1558ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1558f0:
    // 0x1558f0: 0x24420ac8
    ctx->pc = 0x1558f0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 2760));
label_1558f4:
    // 0x1558f4: 0x3c0d0023
    ctx->pc = 0x1558f4u;
    SET_GPR_U32(ctx, 13, ((uint32_t)35 << 16));
label_1558f8:
    // 0x1558f8: 0xadc2d838
    ctx->pc = 0x1558f8u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 4294957112), GPR_U32(ctx, 2));
label_1558fc:
    // 0x1558fc: 0x60102d
    ctx->pc = 0x1558fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_155900:
    // 0x155900: 0x24420af0
    ctx->pc = 0x155900u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 2800));
label_155904:
    // 0x155904: 0x3c0c0023
    ctx->pc = 0x155904u;
    SET_GPR_U32(ctx, 12, ((uint32_t)35 << 16));
label_155908:
    // 0x155908: 0xada2d83c
    ctx->pc = 0x155908u;
    WRITE32(ADD32(GPR_U32(ctx, 13), 4294957116), GPR_U32(ctx, 2));
label_15590c:
    // 0x15590c: 0x3c020015
    ctx->pc = 0x15590cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155910:
    // 0x155910: 0x24420b08
    ctx->pc = 0x155910u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 2824));
label_155914:
    // 0x155914: 0x3c0b0023
    ctx->pc = 0x155914u;
    SET_GPR_U32(ctx, 11, ((uint32_t)35 << 16));
label_155918:
    // 0x155918: 0xad82d840
    ctx->pc = 0x155918u;
    WRITE32(ADD32(GPR_U32(ctx, 12), 4294957120), GPR_U32(ctx, 2));
label_15591c:
    // 0x15591c: 0x3c020015
    ctx->pc = 0x15591cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155920:
    // 0x155920: 0x24420b30
    ctx->pc = 0x155920u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 2864));
label_155924:
    // 0x155924: 0x3c0a0023
    ctx->pc = 0x155924u;
    SET_GPR_U32(ctx, 10, ((uint32_t)35 << 16));
label_155928:
    // 0x155928: 0xad62d844
    ctx->pc = 0x155928u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 4294957124), GPR_U32(ctx, 2));
label_15592c:
    // 0x15592c: 0x3c020015
    ctx->pc = 0x15592cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155930:
    // 0x155930: 0x244207b8
    ctx->pc = 0x155930u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1976));
label_155934:
    // 0x155934: 0x3c090023
    ctx->pc = 0x155934u;
    SET_GPR_U32(ctx, 9, ((uint32_t)35 << 16));
label_155938:
    // 0x155938: 0xad42d848
    ctx->pc = 0x155938u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 4294957128), GPR_U32(ctx, 2));
label_15593c:
    // 0x15593c: 0x3c020015
    ctx->pc = 0x15593cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155940:
    // 0x155940: 0x244208e0
    ctx->pc = 0x155940u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 2272));
label_155944:
    // 0x155944: 0x3c080023
    ctx->pc = 0x155944u;
    SET_GPR_U32(ctx, 8, ((uint32_t)35 << 16));
label_155948:
    // 0x155948: 0xad22d84c
    ctx->pc = 0x155948u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 4294957132), GPR_U32(ctx, 2));
label_15594c:
    // 0x15594c: 0x3c020015
    ctx->pc = 0x15594cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155950:
    // 0x155950: 0x3c060023
    ctx->pc = 0x155950u;
    SET_GPR_U32(ctx, 6, ((uint32_t)35 << 16));
label_155954:
    // 0x155954: 0x24420940
    ctx->pc = 0x155954u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 2368));
label_155958:
    // 0x155958: 0xad02d850
    ctx->pc = 0x155958u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 4294957136), GPR_U32(ctx, 2));
label_15595c:
    // 0x15595c: 0x3c020015
    ctx->pc = 0x15595cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)21 << 16));
label_155960:
    // 0x155960: 0xacd5d808
    ctx->pc = 0x155960u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4294957064), GPR_U32(ctx, 21));
label_155964:
    // 0x155964: 0x3c070023
    ctx->pc = 0x155964u;
    SET_GPR_U32(ctx, 7, ((uint32_t)35 << 16));
label_155968:
    // 0x155968: 0xdfb00000
    ctx->pc = 0x155968u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_15596c:
    // 0x15596c: 0x244209d0
    ctx->pc = 0x15596cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 2512));
label_155970:
    // 0x155970: 0xdfb10008
    ctx->pc = 0x155970u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_155974:
    // 0x155974: 0xdfb20010
    ctx->pc = 0x155974u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_155978:
    // 0x155978: 0xdfb30018
    ctx->pc = 0x155978u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_15597c:
    // 0x15597c: 0xdfb40020
    ctx->pc = 0x15597cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_155980:
    // 0x155980: 0xdfb50028
    ctx->pc = 0x155980u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_155984:
    // 0x155984: 0xdfb60030
    ctx->pc = 0x155984u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_155988:
    // 0x155988: 0xdfb70038
    ctx->pc = 0x155988u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
label_15598c:
    // 0x15598c: 0xdfbe0040
    ctx->pc = 0x15598cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_155990:
    // 0x155990: 0xace2d854
    ctx->pc = 0x155990u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294957140), GPR_U32(ctx, 2));
label_155994:
    // 0x155994: 0x3e00008
label_155998:
    if (ctx->pc == 0x155998u) {
        ctx->pc = 0x155998u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = 0x15599Cu;
        goto label_15599c;
    }
    ctx->pc = 0x155994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155998u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155800u: goto label_155800;
            case 0x155804u: goto label_155804;
            case 0x155808u: goto label_155808;
            case 0x15580Cu: goto label_15580c;
            case 0x155810u: goto label_155810;
            case 0x155814u: goto label_155814;
            case 0x155818u: goto label_155818;
            case 0x15581Cu: goto label_15581c;
            case 0x155820u: goto label_155820;
            case 0x155824u: goto label_155824;
            case 0x155828u: goto label_155828;
            case 0x15582Cu: goto label_15582c;
            case 0x155830u: goto label_155830;
            case 0x155834u: goto label_155834;
            case 0x155838u: goto label_155838;
            case 0x15583Cu: goto label_15583c;
            case 0x155840u: goto label_155840;
            case 0x155844u: goto label_155844;
            case 0x155848u: goto label_155848;
            case 0x15584Cu: goto label_15584c;
            case 0x155850u: goto label_155850;
            case 0x155854u: goto label_155854;
            case 0x155858u: goto label_155858;
            case 0x15585Cu: goto label_15585c;
            case 0x155860u: goto label_155860;
            case 0x155864u: goto label_155864;
            case 0x155868u: goto label_155868;
            case 0x15586Cu: goto label_15586c;
            case 0x155870u: goto label_155870;
            case 0x155874u: goto label_155874;
            case 0x155878u: goto label_155878;
            case 0x15587Cu: goto label_15587c;
            case 0x155880u: goto label_155880;
            case 0x155884u: goto label_155884;
            case 0x155888u: goto label_155888;
            case 0x15588Cu: goto label_15588c;
            case 0x155890u: goto label_155890;
            case 0x155894u: goto label_155894;
            case 0x155898u: goto label_155898;
            case 0x15589Cu: goto label_15589c;
            case 0x1558A0u: goto label_1558a0;
            case 0x1558A4u: goto label_1558a4;
            case 0x1558A8u: goto label_1558a8;
            case 0x1558ACu: goto label_1558ac;
            case 0x1558B0u: goto label_1558b0;
            case 0x1558B4u: goto label_1558b4;
            case 0x1558B8u: goto label_1558b8;
            case 0x1558BCu: goto label_1558bc;
            case 0x1558C0u: goto label_1558c0;
            case 0x1558C4u: goto label_1558c4;
            case 0x1558C8u: goto label_1558c8;
            case 0x1558CCu: goto label_1558cc;
            case 0x1558D0u: goto label_1558d0;
            case 0x1558D4u: goto label_1558d4;
            case 0x1558D8u: goto label_1558d8;
            case 0x1558DCu: goto label_1558dc;
            case 0x1558E0u: goto label_1558e0;
            case 0x1558E4u: goto label_1558e4;
            case 0x1558E8u: goto label_1558e8;
            case 0x1558ECu: goto label_1558ec;
            case 0x1558F0u: goto label_1558f0;
            case 0x1558F4u: goto label_1558f4;
            case 0x1558F8u: goto label_1558f8;
            case 0x1558FCu: goto label_1558fc;
            case 0x155900u: goto label_155900;
            case 0x155904u: goto label_155904;
            case 0x155908u: goto label_155908;
            case 0x15590Cu: goto label_15590c;
            case 0x155910u: goto label_155910;
            case 0x155914u: goto label_155914;
            case 0x155918u: goto label_155918;
            case 0x15591Cu: goto label_15591c;
            case 0x155920u: goto label_155920;
            case 0x155924u: goto label_155924;
            case 0x155928u: goto label_155928;
            case 0x15592Cu: goto label_15592c;
            case 0x155930u: goto label_155930;
            case 0x155934u: goto label_155934;
            case 0x155938u: goto label_155938;
            case 0x15593Cu: goto label_15593c;
            case 0x155940u: goto label_155940;
            case 0x155944u: goto label_155944;
            case 0x155948u: goto label_155948;
            case 0x15594Cu: goto label_15594c;
            case 0x155950u: goto label_155950;
            case 0x155954u: goto label_155954;
            case 0x155958u: goto label_155958;
            case 0x15595Cu: goto label_15595c;
            case 0x155960u: goto label_155960;
            case 0x155964u: goto label_155964;
            case 0x155968u: goto label_155968;
            case 0x15596Cu: goto label_15596c;
            case 0x155970u: goto label_155970;
            case 0x155974u: goto label_155974;
            case 0x155978u: goto label_155978;
            case 0x15597Cu: goto label_15597c;
            case 0x155980u: goto label_155980;
            case 0x155984u: goto label_155984;
            case 0x155988u: goto label_155988;
            case 0x15598Cu: goto label_15598c;
            case 0x155990u: goto label_155990;
            case 0x155994u: goto label_155994;
            case 0x155998u: goto label_155998;
            case 0x15599Cu: goto label_15599c;
            case 0x1559A0u: goto label_1559a0;
            case 0x1559A4u: goto label_1559a4;
            case 0x1559A8u: goto label_1559a8;
            case 0x1559ACu: goto label_1559ac;
            case 0x1559B0u: goto label_1559b0;
            case 0x1559B4u: goto label_1559b4;
            case 0x1559B8u: goto label_1559b8;
            case 0x1559BCu: goto label_1559bc;
            case 0x1559C0u: goto label_1559c0;
            case 0x1559C4u: goto label_1559c4;
            case 0x1559C8u: goto label_1559c8;
            case 0x1559CCu: goto label_1559cc;
            case 0x1559D0u: goto label_1559d0;
            case 0x1559D4u: goto label_1559d4;
            case 0x1559D8u: goto label_1559d8;
            case 0x1559DCu: goto label_1559dc;
            case 0x1559E0u: goto label_1559e0;
            case 0x1559E4u: goto label_1559e4;
            case 0x1559E8u: goto label_1559e8;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F0u: goto label_1559f0;
            case 0x1559F4u: goto label_1559f4;
            case 0x1559F8u: goto label_1559f8;
            case 0x1559FCu: goto label_1559fc;
            case 0x155A00u: goto label_155a00;
            case 0x155A04u: goto label_155a04;
            case 0x155A08u: goto label_155a08;
            case 0x155A0Cu: goto label_155a0c;
            case 0x155A10u: goto label_155a10;
            case 0x155A14u: goto label_155a14;
            case 0x155A18u: goto label_155a18;
            case 0x155A1Cu: goto label_155a1c;
            case 0x155A20u: goto label_155a20;
            case 0x155A24u: goto label_155a24;
            case 0x155A28u: goto label_155a28;
            case 0x155A2Cu: goto label_155a2c;
            case 0x155A30u: goto label_155a30;
            case 0x155A34u: goto label_155a34;
            case 0x155A38u: goto label_155a38;
            case 0x155A3Cu: goto label_155a3c;
            case 0x155A40u: goto label_155a40;
            case 0x155A44u: goto label_155a44;
            case 0x155A48u: goto label_155a48;
            case 0x155A4Cu: goto label_155a4c;
            case 0x155A50u: goto label_155a50;
            case 0x155A54u: goto label_155a54;
            case 0x155A58u: goto label_155a58;
            case 0x155A5Cu: goto label_155a5c;
            case 0x155A60u: goto label_155a60;
            case 0x155A64u: goto label_155a64;
            case 0x155A68u: goto label_155a68;
            case 0x155A6Cu: goto label_155a6c;
            case 0x155A70u: goto label_155a70;
            case 0x155A74u: goto label_155a74;
            case 0x155A78u: goto label_155a78;
            case 0x155A7Cu: goto label_155a7c;
            case 0x155A80u: goto label_155a80;
            case 0x155A84u: goto label_155a84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15599Cu;
label_15599c:
    // 0x15599c: 0x0
    ctx->pc = 0x15599cu;
    // NOP
label_1559a0:
    // 0x1559a0: 0x3c020024
    ctx->pc = 0x1559a0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
label_1559a4:
    // 0x1559a4: 0x3e00008
label_1559a8:
    if (ctx->pc == 0x1559A8u) {
        ctx->pc = 0x1559A8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294960296));
        ctx->pc = 0x1559ACu;
        goto label_1559ac;
    }
    ctx->pc = 0x1559A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1559A8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294960296));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155800u: goto label_155800;
            case 0x155804u: goto label_155804;
            case 0x155808u: goto label_155808;
            case 0x15580Cu: goto label_15580c;
            case 0x155810u: goto label_155810;
            case 0x155814u: goto label_155814;
            case 0x155818u: goto label_155818;
            case 0x15581Cu: goto label_15581c;
            case 0x155820u: goto label_155820;
            case 0x155824u: goto label_155824;
            case 0x155828u: goto label_155828;
            case 0x15582Cu: goto label_15582c;
            case 0x155830u: goto label_155830;
            case 0x155834u: goto label_155834;
            case 0x155838u: goto label_155838;
            case 0x15583Cu: goto label_15583c;
            case 0x155840u: goto label_155840;
            case 0x155844u: goto label_155844;
            case 0x155848u: goto label_155848;
            case 0x15584Cu: goto label_15584c;
            case 0x155850u: goto label_155850;
            case 0x155854u: goto label_155854;
            case 0x155858u: goto label_155858;
            case 0x15585Cu: goto label_15585c;
            case 0x155860u: goto label_155860;
            case 0x155864u: goto label_155864;
            case 0x155868u: goto label_155868;
            case 0x15586Cu: goto label_15586c;
            case 0x155870u: goto label_155870;
            case 0x155874u: goto label_155874;
            case 0x155878u: goto label_155878;
            case 0x15587Cu: goto label_15587c;
            case 0x155880u: goto label_155880;
            case 0x155884u: goto label_155884;
            case 0x155888u: goto label_155888;
            case 0x15588Cu: goto label_15588c;
            case 0x155890u: goto label_155890;
            case 0x155894u: goto label_155894;
            case 0x155898u: goto label_155898;
            case 0x15589Cu: goto label_15589c;
            case 0x1558A0u: goto label_1558a0;
            case 0x1558A4u: goto label_1558a4;
            case 0x1558A8u: goto label_1558a8;
            case 0x1558ACu: goto label_1558ac;
            case 0x1558B0u: goto label_1558b0;
            case 0x1558B4u: goto label_1558b4;
            case 0x1558B8u: goto label_1558b8;
            case 0x1558BCu: goto label_1558bc;
            case 0x1558C0u: goto label_1558c0;
            case 0x1558C4u: goto label_1558c4;
            case 0x1558C8u: goto label_1558c8;
            case 0x1558CCu: goto label_1558cc;
            case 0x1558D0u: goto label_1558d0;
            case 0x1558D4u: goto label_1558d4;
            case 0x1558D8u: goto label_1558d8;
            case 0x1558DCu: goto label_1558dc;
            case 0x1558E0u: goto label_1558e0;
            case 0x1558E4u: goto label_1558e4;
            case 0x1558E8u: goto label_1558e8;
            case 0x1558ECu: goto label_1558ec;
            case 0x1558F0u: goto label_1558f0;
            case 0x1558F4u: goto label_1558f4;
            case 0x1558F8u: goto label_1558f8;
            case 0x1558FCu: goto label_1558fc;
            case 0x155900u: goto label_155900;
            case 0x155904u: goto label_155904;
            case 0x155908u: goto label_155908;
            case 0x15590Cu: goto label_15590c;
            case 0x155910u: goto label_155910;
            case 0x155914u: goto label_155914;
            case 0x155918u: goto label_155918;
            case 0x15591Cu: goto label_15591c;
            case 0x155920u: goto label_155920;
            case 0x155924u: goto label_155924;
            case 0x155928u: goto label_155928;
            case 0x15592Cu: goto label_15592c;
            case 0x155930u: goto label_155930;
            case 0x155934u: goto label_155934;
            case 0x155938u: goto label_155938;
            case 0x15593Cu: goto label_15593c;
            case 0x155940u: goto label_155940;
            case 0x155944u: goto label_155944;
            case 0x155948u: goto label_155948;
            case 0x15594Cu: goto label_15594c;
            case 0x155950u: goto label_155950;
            case 0x155954u: goto label_155954;
            case 0x155958u: goto label_155958;
            case 0x15595Cu: goto label_15595c;
            case 0x155960u: goto label_155960;
            case 0x155964u: goto label_155964;
            case 0x155968u: goto label_155968;
            case 0x15596Cu: goto label_15596c;
            case 0x155970u: goto label_155970;
            case 0x155974u: goto label_155974;
            case 0x155978u: goto label_155978;
            case 0x15597Cu: goto label_15597c;
            case 0x155980u: goto label_155980;
            case 0x155984u: goto label_155984;
            case 0x155988u: goto label_155988;
            case 0x15598Cu: goto label_15598c;
            case 0x155990u: goto label_155990;
            case 0x155994u: goto label_155994;
            case 0x155998u: goto label_155998;
            case 0x15599Cu: goto label_15599c;
            case 0x1559A0u: goto label_1559a0;
            case 0x1559A4u: goto label_1559a4;
            case 0x1559A8u: goto label_1559a8;
            case 0x1559ACu: goto label_1559ac;
            case 0x1559B0u: goto label_1559b0;
            case 0x1559B4u: goto label_1559b4;
            case 0x1559B8u: goto label_1559b8;
            case 0x1559BCu: goto label_1559bc;
            case 0x1559C0u: goto label_1559c0;
            case 0x1559C4u: goto label_1559c4;
            case 0x1559C8u: goto label_1559c8;
            case 0x1559CCu: goto label_1559cc;
            case 0x1559D0u: goto label_1559d0;
            case 0x1559D4u: goto label_1559d4;
            case 0x1559D8u: goto label_1559d8;
            case 0x1559DCu: goto label_1559dc;
            case 0x1559E0u: goto label_1559e0;
            case 0x1559E4u: goto label_1559e4;
            case 0x1559E8u: goto label_1559e8;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F0u: goto label_1559f0;
            case 0x1559F4u: goto label_1559f4;
            case 0x1559F8u: goto label_1559f8;
            case 0x1559FCu: goto label_1559fc;
            case 0x155A00u: goto label_155a00;
            case 0x155A04u: goto label_155a04;
            case 0x155A08u: goto label_155a08;
            case 0x155A0Cu: goto label_155a0c;
            case 0x155A10u: goto label_155a10;
            case 0x155A14u: goto label_155a14;
            case 0x155A18u: goto label_155a18;
            case 0x155A1Cu: goto label_155a1c;
            case 0x155A20u: goto label_155a20;
            case 0x155A24u: goto label_155a24;
            case 0x155A28u: goto label_155a28;
            case 0x155A2Cu: goto label_155a2c;
            case 0x155A30u: goto label_155a30;
            case 0x155A34u: goto label_155a34;
            case 0x155A38u: goto label_155a38;
            case 0x155A3Cu: goto label_155a3c;
            case 0x155A40u: goto label_155a40;
            case 0x155A44u: goto label_155a44;
            case 0x155A48u: goto label_155a48;
            case 0x155A4Cu: goto label_155a4c;
            case 0x155A50u: goto label_155a50;
            case 0x155A54u: goto label_155a54;
            case 0x155A58u: goto label_155a58;
            case 0x155A5Cu: goto label_155a5c;
            case 0x155A60u: goto label_155a60;
            case 0x155A64u: goto label_155a64;
            case 0x155A68u: goto label_155a68;
            case 0x155A6Cu: goto label_155a6c;
            case 0x155A70u: goto label_155a70;
            case 0x155A74u: goto label_155a74;
            case 0x155A78u: goto label_155a78;
            case 0x155A7Cu: goto label_155a7c;
            case 0x155A80u: goto label_155a80;
            case 0x155A84u: goto label_155a84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1559ACu;
label_1559ac:
    // 0x1559ac: 0x0
    ctx->pc = 0x1559acu;
    // NOP
label_1559b0:
    // 0x1559b0: 0x27bdffe0
    ctx->pc = 0x1559b0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_1559b4:
    // 0x1559b4: 0xffb00000
    ctx->pc = 0x1559b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_1559b8:
    // 0x1559b8: 0x80802d
    ctx->pc = 0x1559b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1559bc:
    // 0x1559bc: 0xffb10008
    ctx->pc = 0x1559bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_1559c0:
    // 0x1559c0: 0xa0882d
    ctx->pc = 0x1559c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1559c4:
    // 0x1559c4: 0xffb20010
    ctx->pc = 0x1559c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_1559c8:
    // 0x1559c8: 0xffbf0018
    ctx->pc = 0x1559c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_1559cc:
    // 0x1559cc: 0x3c020024
    ctx->pc = 0x1559ccu;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
label_1559d0:
    // 0x1559d0: 0x9043e544
    ctx->pc = 0x1559d0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294960452)));
label_1559d4:
    // 0x1559d4: 0x24040004
    ctx->pc = 0x1559d4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
label_1559d8:
    // 0x1559d8: 0x10640007
label_1559dc:
    if (ctx->pc == 0x1559DCu) {
        ctx->pc = 0x1559DCu;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1559E0u;
        goto label_1559e0;
    }
    ctx->pc = 0x1559D8u;
    {
        const bool branch_taken_0x1559d8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 4));
        ctx->pc = 0x1559DCu;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1559d8) {
            ctx->pc = 0x1559F8u;
            goto label_1559f8;
        }
    }
    ctx->pc = 0x1559E0u;
label_1559e0:
    // 0x1559e0: 0x2401ffff
    ctx->pc = 0x1559e0u;
    SET_GPR_S32(ctx, 1, ADD32(GPR_U32(ctx, 0), 4294967295));
label_1559e4:
    // 0x1559e4: 0x20f809
label_1559e8:
    if (ctx->pc == 0x1559E8u) {
        ctx->pc = 0x1559ECu;
        goto label_1559ec;
    }
    ctx->pc = 0x1559E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 1);
        SET_GPR_U32(ctx, 31, 0x1559ECu);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155800u: goto label_155800;
            case 0x155804u: goto label_155804;
            case 0x155808u: goto label_155808;
            case 0x15580Cu: goto label_15580c;
            case 0x155810u: goto label_155810;
            case 0x155814u: goto label_155814;
            case 0x155818u: goto label_155818;
            case 0x15581Cu: goto label_15581c;
            case 0x155820u: goto label_155820;
            case 0x155824u: goto label_155824;
            case 0x155828u: goto label_155828;
            case 0x15582Cu: goto label_15582c;
            case 0x155830u: goto label_155830;
            case 0x155834u: goto label_155834;
            case 0x155838u: goto label_155838;
            case 0x15583Cu: goto label_15583c;
            case 0x155840u: goto label_155840;
            case 0x155844u: goto label_155844;
            case 0x155848u: goto label_155848;
            case 0x15584Cu: goto label_15584c;
            case 0x155850u: goto label_155850;
            case 0x155854u: goto label_155854;
            case 0x155858u: goto label_155858;
            case 0x15585Cu: goto label_15585c;
            case 0x155860u: goto label_155860;
            case 0x155864u: goto label_155864;
            case 0x155868u: goto label_155868;
            case 0x15586Cu: goto label_15586c;
            case 0x155870u: goto label_155870;
            case 0x155874u: goto label_155874;
            case 0x155878u: goto label_155878;
            case 0x15587Cu: goto label_15587c;
            case 0x155880u: goto label_155880;
            case 0x155884u: goto label_155884;
            case 0x155888u: goto label_155888;
            case 0x15588Cu: goto label_15588c;
            case 0x155890u: goto label_155890;
            case 0x155894u: goto label_155894;
            case 0x155898u: goto label_155898;
            case 0x15589Cu: goto label_15589c;
            case 0x1558A0u: goto label_1558a0;
            case 0x1558A4u: goto label_1558a4;
            case 0x1558A8u: goto label_1558a8;
            case 0x1558ACu: goto label_1558ac;
            case 0x1558B0u: goto label_1558b0;
            case 0x1558B4u: goto label_1558b4;
            case 0x1558B8u: goto label_1558b8;
            case 0x1558BCu: goto label_1558bc;
            case 0x1558C0u: goto label_1558c0;
            case 0x1558C4u: goto label_1558c4;
            case 0x1558C8u: goto label_1558c8;
            case 0x1558CCu: goto label_1558cc;
            case 0x1558D0u: goto label_1558d0;
            case 0x1558D4u: goto label_1558d4;
            case 0x1558D8u: goto label_1558d8;
            case 0x1558DCu: goto label_1558dc;
            case 0x1558E0u: goto label_1558e0;
            case 0x1558E4u: goto label_1558e4;
            case 0x1558E8u: goto label_1558e8;
            case 0x1558ECu: goto label_1558ec;
            case 0x1558F0u: goto label_1558f0;
            case 0x1558F4u: goto label_1558f4;
            case 0x1558F8u: goto label_1558f8;
            case 0x1558FCu: goto label_1558fc;
            case 0x155900u: goto label_155900;
            case 0x155904u: goto label_155904;
            case 0x155908u: goto label_155908;
            case 0x15590Cu: goto label_15590c;
            case 0x155910u: goto label_155910;
            case 0x155914u: goto label_155914;
            case 0x155918u: goto label_155918;
            case 0x15591Cu: goto label_15591c;
            case 0x155920u: goto label_155920;
            case 0x155924u: goto label_155924;
            case 0x155928u: goto label_155928;
            case 0x15592Cu: goto label_15592c;
            case 0x155930u: goto label_155930;
            case 0x155934u: goto label_155934;
            case 0x155938u: goto label_155938;
            case 0x15593Cu: goto label_15593c;
            case 0x155940u: goto label_155940;
            case 0x155944u: goto label_155944;
            case 0x155948u: goto label_155948;
            case 0x15594Cu: goto label_15594c;
            case 0x155950u: goto label_155950;
            case 0x155954u: goto label_155954;
            case 0x155958u: goto label_155958;
            case 0x15595Cu: goto label_15595c;
            case 0x155960u: goto label_155960;
            case 0x155964u: goto label_155964;
            case 0x155968u: goto label_155968;
            case 0x15596Cu: goto label_15596c;
            case 0x155970u: goto label_155970;
            case 0x155974u: goto label_155974;
            case 0x155978u: goto label_155978;
            case 0x15597Cu: goto label_15597c;
            case 0x155980u: goto label_155980;
            case 0x155984u: goto label_155984;
            case 0x155988u: goto label_155988;
            case 0x15598Cu: goto label_15598c;
            case 0x155990u: goto label_155990;
            case 0x155994u: goto label_155994;
            case 0x155998u: goto label_155998;
            case 0x15599Cu: goto label_15599c;
            case 0x1559A0u: goto label_1559a0;
            case 0x1559A4u: goto label_1559a4;
            case 0x1559A8u: goto label_1559a8;
            case 0x1559ACu: goto label_1559ac;
            case 0x1559B0u: goto label_1559b0;
            case 0x1559B4u: goto label_1559b4;
            case 0x1559B8u: goto label_1559b8;
            case 0x1559BCu: goto label_1559bc;
            case 0x1559C0u: goto label_1559c0;
            case 0x1559C4u: goto label_1559c4;
            case 0x1559C8u: goto label_1559c8;
            case 0x1559CCu: goto label_1559cc;
            case 0x1559D0u: goto label_1559d0;
            case 0x1559D4u: goto label_1559d4;
            case 0x1559D8u: goto label_1559d8;
            case 0x1559DCu: goto label_1559dc;
            case 0x1559E0u: goto label_1559e0;
            case 0x1559E4u: goto label_1559e4;
            case 0x1559E8u: goto label_1559e8;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F0u: goto label_1559f0;
            case 0x1559F4u: goto label_1559f4;
            case 0x1559F8u: goto label_1559f8;
            case 0x1559FCu: goto label_1559fc;
            case 0x155A00u: goto label_155a00;
            case 0x155A04u: goto label_155a04;
            case 0x155A08u: goto label_155a08;
            case 0x155A0Cu: goto label_155a0c;
            case 0x155A10u: goto label_155a10;
            case 0x155A14u: goto label_155a14;
            case 0x155A18u: goto label_155a18;
            case 0x155A1Cu: goto label_155a1c;
            case 0x155A20u: goto label_155a20;
            case 0x155A24u: goto label_155a24;
            case 0x155A28u: goto label_155a28;
            case 0x155A2Cu: goto label_155a2c;
            case 0x155A30u: goto label_155a30;
            case 0x155A34u: goto label_155a34;
            case 0x155A38u: goto label_155a38;
            case 0x155A3Cu: goto label_155a3c;
            case 0x155A40u: goto label_155a40;
            case 0x155A44u: goto label_155a44;
            case 0x155A48u: goto label_155a48;
            case 0x155A4Cu: goto label_155a4c;
            case 0x155A50u: goto label_155a50;
            case 0x155A54u: goto label_155a54;
            case 0x155A58u: goto label_155a58;
            case 0x155A5Cu: goto label_155a5c;
            case 0x155A60u: goto label_155a60;
            case 0x155A64u: goto label_155a64;
            case 0x155A68u: goto label_155a68;
            case 0x155A6Cu: goto label_155a6c;
            case 0x155A70u: goto label_155a70;
            case 0x155A74u: goto label_155a74;
            case 0x155A78u: goto label_155a78;
            case 0x155A7Cu: goto label_155a7c;
            case 0x155A80u: goto label_155a80;
            case 0x155A84u: goto label_155a84;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1559ECu; }
            if (ctx->pc != 0x1559ECu) { return; }
        }
    }
    ctx->pc = 0x1559ECu;
label_1559ec:
    // 0x1559ec: 0x1000fffc
label_1559f0:
    if (ctx->pc == 0x1559F0u) {
        ctx->pc = 0x1559F4u;
        goto label_1559f4;
    }
    ctx->pc = 0x1559ECu;
    {
        const bool branch_taken_0x1559ec = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1559ec) {
            ctx->pc = 0x1559E0u;
            goto label_1559e0;
        }
    }
    ctx->pc = 0x1559F4u;
label_1559f4:
    // 0x1559f4: 0x0
    ctx->pc = 0x1559f4u;
    // NOP
label_1559f8:
    // 0x1559f8: 0x3c030026
    ctx->pc = 0x1559f8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
label_1559fc:
    // 0x1559fc: 0x3c020024
    ctx->pc = 0x1559fcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
label_155a00:
    // 0x155a00: 0x24634c08
    ctx->pc = 0x155a00u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 19464));
label_155a04:
    // 0x155a04: 0x2442e4a8
    ctx->pc = 0x155a04u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294960296));
label_155a08:
    // 0x155a08: 0xc054152
label_155a0c:
    if (ctx->pc == 0x155A0Cu) {
        ctx->pc = 0x155A0Cu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x155A10u;
        goto label_155a10;
    }
    ctx->pc = 0x155A08u;
    SET_GPR_U32(ctx, 31, 0x155A10u);
    ctx->pc = 0x155A0Cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x150548u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00150548_0x150548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A10u; }
    }
    if (ctx->pc != 0x155A10u) { return; }
    ctx->pc = 0x155A10u;
label_155a10:
    // 0x155a10: 0xc054292
label_155a14:
    if (ctx->pc == 0x155A14u) {
        ctx->pc = 0x155A18u;
        goto label_155a18;
    }
    ctx->pc = 0x155A10u;
    SET_GPR_U32(ctx, 31, 0x155A18u);
    ctx->pc = 0x150A48u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00150A48_0x150a48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A18u; }
    }
    if (ctx->pc != 0x155A18u) { return; }
    ctx->pc = 0x155A18u;
label_155a18:
    // 0x155a18: 0x200202d
    ctx->pc = 0x155a18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_155a1c:
    // 0x155a1c: 0x220282d
    ctx->pc = 0x155a1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_155a20:
    // 0x155a20: 0xc0556a2
label_155a24:
    if (ctx->pc == 0x155A24u) {
        ctx->pc = 0x155A24u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x155A28u;
        goto label_155a28;
    }
    ctx->pc = 0x155A20u;
    SET_GPR_U32(ctx, 31, 0x155A28u);
    ctx->pc = 0x155A24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x155A88u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00155A88_0x155a88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A28u; }
    }
    if (ctx->pc != 0x155A28u) { return; }
    ctx->pc = 0x155A28u;
label_155a28:
    // 0x155a28: 0xdfb00000
    ctx->pc = 0x155a28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_155a2c:
    // 0x155a2c: 0xdfb10008
    ctx->pc = 0x155a2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_155a30:
    // 0x155a30: 0xdfb20010
    ctx->pc = 0x155a30u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_155a34:
    // 0x155a34: 0xdfbf0018
    ctx->pc = 0x155a34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_155a38:
    // 0x155a38: 0x8055690
label_155a3c:
    if (ctx->pc == 0x155A3Cu) {
        ctx->pc = 0x155A3Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x155A40u;
        goto label_155a40;
    }
    ctx->pc = 0x155A38u;
    ctx->pc = 0x155A3Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x155A40u;
    goto label_155a40;
    ctx->pc = 0x155A40u;
label_155a40:
    // 0x155a40: 0x3c020026
    ctx->pc = 0x155a40u;
    SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
label_155a44:
    // 0x155a44: 0x24424c10
    ctx->pc = 0x155a44u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 19472));
label_155a48:
    // 0x155a48: 0x8c440040
    ctx->pc = 0x155a48u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 64)));
label_155a4c:
    // 0x155a4c: 0x1880000b
label_155a50:
    if (ctx->pc == 0x155A50u) {
        ctx->pc = 0x155A50u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 68)));
        ctx->pc = 0x155A54u;
        goto label_155a54;
    }
    ctx->pc = 0x155A4Cu;
    {
        const bool branch_taken_0x155a4c = (GPR_S32(ctx, 4) <= 0);
        ctx->pc = 0x155A50u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 68)));
        if (branch_taken_0x155a4c) {
            ctx->pc = 0x155A7Cu;
            goto label_155a7c;
        }
    }
    ctx->pc = 0x155A54u;
label_155a54:
    // 0x155a54: 0x80102d
    ctx->pc = 0x155a54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_155a58:
    // 0x155a58: 0x24040001
    ctx->pc = 0x155a58u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
label_155a5c:
    // 0x155a5c: 0x0
    ctx->pc = 0x155a5cu;
    // NOP
label_155a60:
    // 0x155a60: 0x2442ffff
    ctx->pc = 0x155a60u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
label_155a64:
    // 0x155a64: 0xac640000
    ctx->pc = 0x155a64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
label_155a68:
    // 0x155a68: 0x0
    ctx->pc = 0x155a68u;
    // NOP
label_155a6c:
    // 0x155a6c: 0x0
    ctx->pc = 0x155a6cu;
    // NOP
label_155a70:
    // 0x155a70: 0x0
    ctx->pc = 0x155a70u;
    // NOP
label_155a74:
    // 0x155a74: 0x1440fffa
label_155a78:
    if (ctx->pc == 0x155A78u) {
        ctx->pc = 0x155A78u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1696));
        ctx->pc = 0x155A7Cu;
        goto label_155a7c;
    }
    ctx->pc = 0x155A74u;
    {
        const bool branch_taken_0x155a74 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x155A78u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1696));
        if (branch_taken_0x155a74) {
            ctx->pc = 0x155A60u;
            goto label_155a60;
        }
    }
    ctx->pc = 0x155A7Cu;
label_155a7c:
    // 0x155a7c: 0x3e00008
label_155a80:
    if (ctx->pc == 0x155A80u) {
        ctx->pc = 0x155A84u;
        goto label_155a84;
    }
    ctx->pc = 0x155A7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155800u: goto label_155800;
            case 0x155804u: goto label_155804;
            case 0x155808u: goto label_155808;
            case 0x15580Cu: goto label_15580c;
            case 0x155810u: goto label_155810;
            case 0x155814u: goto label_155814;
            case 0x155818u: goto label_155818;
            case 0x15581Cu: goto label_15581c;
            case 0x155820u: goto label_155820;
            case 0x155824u: goto label_155824;
            case 0x155828u: goto label_155828;
            case 0x15582Cu: goto label_15582c;
            case 0x155830u: goto label_155830;
            case 0x155834u: goto label_155834;
            case 0x155838u: goto label_155838;
            case 0x15583Cu: goto label_15583c;
            case 0x155840u: goto label_155840;
            case 0x155844u: goto label_155844;
            case 0x155848u: goto label_155848;
            case 0x15584Cu: goto label_15584c;
            case 0x155850u: goto label_155850;
            case 0x155854u: goto label_155854;
            case 0x155858u: goto label_155858;
            case 0x15585Cu: goto label_15585c;
            case 0x155860u: goto label_155860;
            case 0x155864u: goto label_155864;
            case 0x155868u: goto label_155868;
            case 0x15586Cu: goto label_15586c;
            case 0x155870u: goto label_155870;
            case 0x155874u: goto label_155874;
            case 0x155878u: goto label_155878;
            case 0x15587Cu: goto label_15587c;
            case 0x155880u: goto label_155880;
            case 0x155884u: goto label_155884;
            case 0x155888u: goto label_155888;
            case 0x15588Cu: goto label_15588c;
            case 0x155890u: goto label_155890;
            case 0x155894u: goto label_155894;
            case 0x155898u: goto label_155898;
            case 0x15589Cu: goto label_15589c;
            case 0x1558A0u: goto label_1558a0;
            case 0x1558A4u: goto label_1558a4;
            case 0x1558A8u: goto label_1558a8;
            case 0x1558ACu: goto label_1558ac;
            case 0x1558B0u: goto label_1558b0;
            case 0x1558B4u: goto label_1558b4;
            case 0x1558B8u: goto label_1558b8;
            case 0x1558BCu: goto label_1558bc;
            case 0x1558C0u: goto label_1558c0;
            case 0x1558C4u: goto label_1558c4;
            case 0x1558C8u: goto label_1558c8;
            case 0x1558CCu: goto label_1558cc;
            case 0x1558D0u: goto label_1558d0;
            case 0x1558D4u: goto label_1558d4;
            case 0x1558D8u: goto label_1558d8;
            case 0x1558DCu: goto label_1558dc;
            case 0x1558E0u: goto label_1558e0;
            case 0x1558E4u: goto label_1558e4;
            case 0x1558E8u: goto label_1558e8;
            case 0x1558ECu: goto label_1558ec;
            case 0x1558F0u: goto label_1558f0;
            case 0x1558F4u: goto label_1558f4;
            case 0x1558F8u: goto label_1558f8;
            case 0x1558FCu: goto label_1558fc;
            case 0x155900u: goto label_155900;
            case 0x155904u: goto label_155904;
            case 0x155908u: goto label_155908;
            case 0x15590Cu: goto label_15590c;
            case 0x155910u: goto label_155910;
            case 0x155914u: goto label_155914;
            case 0x155918u: goto label_155918;
            case 0x15591Cu: goto label_15591c;
            case 0x155920u: goto label_155920;
            case 0x155924u: goto label_155924;
            case 0x155928u: goto label_155928;
            case 0x15592Cu: goto label_15592c;
            case 0x155930u: goto label_155930;
            case 0x155934u: goto label_155934;
            case 0x155938u: goto label_155938;
            case 0x15593Cu: goto label_15593c;
            case 0x155940u: goto label_155940;
            case 0x155944u: goto label_155944;
            case 0x155948u: goto label_155948;
            case 0x15594Cu: goto label_15594c;
            case 0x155950u: goto label_155950;
            case 0x155954u: goto label_155954;
            case 0x155958u: goto label_155958;
            case 0x15595Cu: goto label_15595c;
            case 0x155960u: goto label_155960;
            case 0x155964u: goto label_155964;
            case 0x155968u: goto label_155968;
            case 0x15596Cu: goto label_15596c;
            case 0x155970u: goto label_155970;
            case 0x155974u: goto label_155974;
            case 0x155978u: goto label_155978;
            case 0x15597Cu: goto label_15597c;
            case 0x155980u: goto label_155980;
            case 0x155984u: goto label_155984;
            case 0x155988u: goto label_155988;
            case 0x15598Cu: goto label_15598c;
            case 0x155990u: goto label_155990;
            case 0x155994u: goto label_155994;
            case 0x155998u: goto label_155998;
            case 0x15599Cu: goto label_15599c;
            case 0x1559A0u: goto label_1559a0;
            case 0x1559A4u: goto label_1559a4;
            case 0x1559A8u: goto label_1559a8;
            case 0x1559ACu: goto label_1559ac;
            case 0x1559B0u: goto label_1559b0;
            case 0x1559B4u: goto label_1559b4;
            case 0x1559B8u: goto label_1559b8;
            case 0x1559BCu: goto label_1559bc;
            case 0x1559C0u: goto label_1559c0;
            case 0x1559C4u: goto label_1559c4;
            case 0x1559C8u: goto label_1559c8;
            case 0x1559CCu: goto label_1559cc;
            case 0x1559D0u: goto label_1559d0;
            case 0x1559D4u: goto label_1559d4;
            case 0x1559D8u: goto label_1559d8;
            case 0x1559DCu: goto label_1559dc;
            case 0x1559E0u: goto label_1559e0;
            case 0x1559E4u: goto label_1559e4;
            case 0x1559E8u: goto label_1559e8;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F0u: goto label_1559f0;
            case 0x1559F4u: goto label_1559f4;
            case 0x1559F8u: goto label_1559f8;
            case 0x1559FCu: goto label_1559fc;
            case 0x155A00u: goto label_155a00;
            case 0x155A04u: goto label_155a04;
            case 0x155A08u: goto label_155a08;
            case 0x155A0Cu: goto label_155a0c;
            case 0x155A10u: goto label_155a10;
            case 0x155A14u: goto label_155a14;
            case 0x155A18u: goto label_155a18;
            case 0x155A1Cu: goto label_155a1c;
            case 0x155A20u: goto label_155a20;
            case 0x155A24u: goto label_155a24;
            case 0x155A28u: goto label_155a28;
            case 0x155A2Cu: goto label_155a2c;
            case 0x155A30u: goto label_155a30;
            case 0x155A34u: goto label_155a34;
            case 0x155A38u: goto label_155a38;
            case 0x155A3Cu: goto label_155a3c;
            case 0x155A40u: goto label_155a40;
            case 0x155A44u: goto label_155a44;
            case 0x155A48u: goto label_155a48;
            case 0x155A4Cu: goto label_155a4c;
            case 0x155A50u: goto label_155a50;
            case 0x155A54u: goto label_155a54;
            case 0x155A58u: goto label_155a58;
            case 0x155A5Cu: goto label_155a5c;
            case 0x155A60u: goto label_155a60;
            case 0x155A64u: goto label_155a64;
            case 0x155A68u: goto label_155a68;
            case 0x155A6Cu: goto label_155a6c;
            case 0x155A70u: goto label_155a70;
            case 0x155A74u: goto label_155a74;
            case 0x155A78u: goto label_155a78;
            case 0x155A7Cu: goto label_155a7c;
            case 0x155A80u: goto label_155a80;
            case 0x155A84u: goto label_155a84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155A84u;
label_155a84:
    // 0x155a84: 0x0
    ctx->pc = 0x155a84u;
    // NOP
}
