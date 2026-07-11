#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0012A8F0
// Address: 0x12a8f0 - 0x12ab88
void sub_0012A8F0_0x12a8f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12a8f0u;

    // 0x12a8f0: 0x27bdfff0
    ctx->pc = 0x12a8f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a8f4: 0x14800008
    ctx->pc = 0x12A8F4u;
    {
        const bool branch_taken_0x12a8f4 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x12A8F8u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x12a8f4) {
            ctx->pc = 0x12A918u;
            goto label_12a918;
        }
    }
    ctx->pc = 0x12A8FCu;
    // 0x12a8fc: 0x3c040024
    ctx->pc = 0x12a8fcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x12a900: 0xc04a034
    ctx->pc = 0x12A900u;
    SET_GPR_U32(ctx, 31, 0x12A908u);
    ctx->pc = 0x12A904u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294943784));
    ctx->pc = 0x1280D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A908u; }
    }
    if (ctx->pc != 0x12A908u) { return; }
    ctx->pc = 0x12A908u;
    // 0x12a908: 0x2402ffff
    ctx->pc = 0x12a908u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x12a90c: 0xdfbf0000
    ctx->pc = 0x12a90cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a910: 0x3e00008
    ctx->pc = 0x12A910u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A914u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A918u: goto label_12a918;
            case 0x12A948u: goto label_12a948;
            case 0x12A960u: goto label_12a960;
            case 0x12A9CCu: goto label_12a9cc;
            case 0x12AA40u: goto label_12aa40;
            case 0x12AA4Cu: goto label_12aa4c;
            case 0x12AA60u: goto label_12aa60;
            case 0x12AAC0u: goto label_12aac0;
            case 0x12AAC4u: goto label_12aac4;
            case 0x12AAECu: goto label_12aaec;
            case 0x12AB08u: goto label_12ab08;
            case 0x12AB18u: goto label_12ab18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A918u;
label_12a918:
    // 0x12a918: 0x8c840094
    ctx->pc = 0x12a918u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 148)));
    // 0x12a91c: 0xdfbf0000
    ctx->pc = 0x12a91cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a920: 0x804f434
    ctx->pc = 0x12A920u;
    ctx->pc = 0x12A924u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x13D0D0u;
    sub_0013D0D0_0x13d0d0(rdram, ctx, runtime); return;
    ctx->pc = 0x12A928u;
    // 0x12a928: 0x27bdfff0
    ctx->pc = 0x12a928u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a92c: 0x14800006
    ctx->pc = 0x12A92Cu;
    {
        const bool branch_taken_0x12a92c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x12A930u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x12a92c) {
            ctx->pc = 0x12A948u;
            goto label_12a948;
        }
    }
    ctx->pc = 0x12A934u;
    // 0x12a934: 0x3c040024
    ctx->pc = 0x12a934u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x12a938: 0xdfbf0000
    ctx->pc = 0x12a938u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a93c: 0x2484a458
    ctx->pc = 0x12a93cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294943832));
    // 0x12a940: 0x804a034
    ctx->pc = 0x12A940u;
    ctx->pc = 0x12A944u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1280D0u;
    sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    ctx->pc = 0x12A948u;
label_12a948:
    // 0x12a948: 0x80820001
    ctx->pc = 0x12a948u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x12a94c: 0x14400004
    ctx->pc = 0x12A94Cu;
    {
        const bool branch_taken_0x12a94c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x12A950u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x12a94c) {
            ctx->pc = 0x12A960u;
            goto label_12a960;
        }
    }
    ctx->pc = 0x12A954u;
    // 0x12a954: 0x8c840094
    ctx->pc = 0x12a954u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 148)));
    // 0x12a958: 0x804f3b4
    ctx->pc = 0x12A958u;
    ctx->pc = 0x12A95Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x13CED0u;
    sub_0013CED0_0x13ced0(rdram, ctx, runtime); return;
    ctx->pc = 0x12A960u;
label_12a960:
    // 0x12a960: 0x3e00008
    ctx->pc = 0x12A960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A964u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A918u: goto label_12a918;
            case 0x12A948u: goto label_12a948;
            case 0x12A960u: goto label_12a960;
            case 0x12A9CCu: goto label_12a9cc;
            case 0x12AA40u: goto label_12aa40;
            case 0x12AA4Cu: goto label_12aa4c;
            case 0x12AA60u: goto label_12aa60;
            case 0x12AAC0u: goto label_12aac0;
            case 0x12AAC4u: goto label_12aac4;
            case 0x12AAECu: goto label_12aaec;
            case 0x12AB08u: goto label_12ab08;
            case 0x12AB18u: goto label_12ab18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A968u;
    // 0x12a968: 0x27bdffe0
    ctx->pc = 0x12a968u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12a96c: 0x3c020021
    ctx->pc = 0x12a96cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a970: 0xffb20010
    ctx->pc = 0x12a970u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12a974: 0x24520480
    ctx->pc = 0x12a974u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 2), 1152));
    // 0x12a978: 0x8e420000
    ctx->pc = 0x12a978u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12a97c: 0xffb00000
    ctx->pc = 0x12a97cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a980: 0xffb10008
    ctx->pc = 0x12a980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12a984: 0x14400011
    ctx->pc = 0x12A984u;
    {
        const bool branch_taken_0x12a984 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x12A988u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        if (branch_taken_0x12a984) {
            ctx->pc = 0x12A9CCu;
            goto label_12a9cc;
        }
    }
    ctx->pc = 0x12A98Cu;
    // 0x12a98c: 0xc045144
    ctx->pc = 0x12A98Cu;
    SET_GPR_U32(ctx, 31, 0x12A994u);
    ctx->pc = 0x12A990u;
    SET_GPR_U32(ctx, 16, ((uint32_t)33 << 16));
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A994u; }
    }
    if (ctx->pc != 0x12A994u) { return; }
    ctx->pc = 0x12A994u;
    // 0x12a994: 0x40882d
    ctx->pc = 0x12a994u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a998: 0x3c020021
    ctx->pc = 0x12a998u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a99c: 0x8c450460
    ctx->pc = 0x12a99cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 1120)));
    // 0x12a9a0: 0x220202d
    ctx->pc = 0x12a9a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a9a4: 0xc04512c
    ctx->pc = 0x12A9A4u;
    SET_GPR_U32(ctx, 31, 0x12A9ACu);
    ctx->pc = 0x12A9A8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1240));
    ctx->pc = 0x1144B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A9ACu; }
    }
    if (ctx->pc != 0x12A9ACu) { return; }
    ctx->pc = 0x12A9ACu;
    // 0x12a9ac: 0x3c030021
    ctx->pc = 0x12a9acu;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12a9b0: 0xac627d70
    ctx->pc = 0x12a9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 32112), GPR_U32(ctx, 2));
    // 0x12a9b4: 0x3c050021
    ctx->pc = 0x12a9b4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x12a9b8: 0x8e040000
    ctx->pc = 0x12a9b8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12a9bc: 0xc04ac3c
    ctx->pc = 0x12A9BCu;
    SET_GPR_U32(ctx, 31, 0x12A9C4u);
    ctx->pc = 0x12A9C0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 32116), GPR_U32(ctx, 17));
    ctx->pc = 0x12B0F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0F0_0x12b0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A9C4u; }
    }
    if (ctx->pc != 0x12A9C4u) { return; }
    ctx->pc = 0x12A9C4u;
    // 0x12a9c4: 0x8e030000
    ctx->pc = 0x12a9c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12a9c8: 0x8e420000
    ctx->pc = 0x12a9c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_12a9cc:
    // 0x12a9cc: 0x24420001
    ctx->pc = 0x12a9ccu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x12a9d0: 0xdfb00000
    ctx->pc = 0x12a9d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a9d4: 0xae420000
    ctx->pc = 0x12a9d4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x12a9d8: 0xdfb10008
    ctx->pc = 0x12a9d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a9dc: 0xdfb20010
    ctx->pc = 0x12a9dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12a9e0: 0xdfbf0018
    ctx->pc = 0x12a9e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12a9e4: 0x3e00008
    ctx->pc = 0x12A9E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A9E8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A918u: goto label_12a918;
            case 0x12A948u: goto label_12a948;
            case 0x12A960u: goto label_12a960;
            case 0x12A9CCu: goto label_12a9cc;
            case 0x12AA40u: goto label_12aa40;
            case 0x12AA4Cu: goto label_12aa4c;
            case 0x12AA60u: goto label_12aa60;
            case 0x12AAC0u: goto label_12aac0;
            case 0x12AAC4u: goto label_12aac4;
            case 0x12AAECu: goto label_12aaec;
            case 0x12AB08u: goto label_12ab08;
            case 0x12AB18u: goto label_12ab18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A9ECu;
    // 0x12a9ec: 0x0
    ctx->pc = 0x12a9ecu;
    // NOP
    // 0x12a9f0: 0x27bdffe0
    ctx->pc = 0x12a9f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12a9f4: 0x3c030021
    ctx->pc = 0x12a9f4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12a9f8: 0xffb10008
    ctx->pc = 0x12a9f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12a9fc: 0x24710480
    ctx->pc = 0x12a9fcu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 3), 1152));
    // 0x12aa00: 0x8e220000
    ctx->pc = 0x12aa00u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12aa04: 0xffb00000
    ctx->pc = 0x12aa04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12aa08: 0x2442ffff
    ctx->pc = 0x12aa08u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x12aa0c: 0xffbf0010
    ctx->pc = 0x12aa0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12aa10: 0x1440000b
    ctx->pc = 0x12AA10u;
    {
        const bool branch_taken_0x12aa10 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x12AA14u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x12aa10) {
            ctx->pc = 0x12AA40u;
            goto label_12aa40;
        }
    }
    ctx->pc = 0x12AA18u;
    // 0x12aa18: 0x3c100021
    ctx->pc = 0x12aa18u;
    SET_GPR_U32(ctx, 16, ((uint32_t)33 << 16));
    // 0x12aa1c: 0x261004d8
    ctx->pc = 0x12aa1cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1240));
    // 0x12aa20: 0xc04ac56
    ctx->pc = 0x12AA20u;
    SET_GPR_U32(ctx, 31, 0x12AA28u);
    ctx->pc = 0x12AA24u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    ctx->pc = 0x12B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B158_0x12b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AA28u; }
    }
    if (ctx->pc != 0x12AA28u) { return; }
    ctx->pc = 0x12AA28u;
    // 0x12aa28: 0xc045144
    ctx->pc = 0x12AA28u;
    SET_GPR_U32(ctx, 31, 0x12AA30u);
    ctx->pc = 0x12AA2Cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AA30u; }
    }
    if (ctx->pc != 0x12AA30u) { return; }
    ctx->pc = 0x12AA30u;
    // 0x12aa30: 0x3c030021
    ctx->pc = 0x12aa30u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12aa34: 0x8c657d70
    ctx->pc = 0x12aa34u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 3), 32112)));
    // 0x12aa38: 0xc04512c
    ctx->pc = 0x12AA38u;
    SET_GPR_U32(ctx, 31, 0x12AA40u);
    ctx->pc = 0x12AA3Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1144B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AA40u; }
    }
    if (ctx->pc != 0x12AA40u) { return; }
    ctx->pc = 0x12AA40u;
label_12aa40:
    // 0x12aa40: 0x8e220000
    ctx->pc = 0x12aa40u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12aa44: 0x4420001
    ctx->pc = 0x12AA44u;
    {
        const bool branch_taken_0x12aa44 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x12aa44) {
            ctx->pc = 0x12AA48u;
            WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
            ctx->pc = 0x12AA4Cu;
            goto label_12aa4c;
        }
    }
    ctx->pc = 0x12AA4Cu;
label_12aa4c:
    // 0x12aa4c: 0xdfb00000
    ctx->pc = 0x12aa4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12aa50: 0xdfb10008
    ctx->pc = 0x12aa50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12aa54: 0xdfbf0010
    ctx->pc = 0x12aa54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12aa58: 0x3e00008
    ctx->pc = 0x12AA58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12AA5Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A918u: goto label_12a918;
            case 0x12A948u: goto label_12a948;
            case 0x12A960u: goto label_12a960;
            case 0x12A9CCu: goto label_12a9cc;
            case 0x12AA40u: goto label_12aa40;
            case 0x12AA4Cu: goto label_12aa4c;
            case 0x12AA60u: goto label_12aa60;
            case 0x12AAC0u: goto label_12aac0;
            case 0x12AAC4u: goto label_12aac4;
            case 0x12AAECu: goto label_12aaec;
            case 0x12AB08u: goto label_12ab08;
            case 0x12AB18u: goto label_12ab18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12AA60u;
label_12aa60:
    // 0x12aa60: 0x27bdffd0
    ctx->pc = 0x12aa60u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12aa64: 0xffb10008
    ctx->pc = 0x12aa64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12aa68: 0x80882d
    ctx->pc = 0x12aa68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aa6c: 0xffb40020
    ctx->pc = 0x12aa6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12aa70: 0xa0a02d
    ctx->pc = 0x12aa70u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aa74: 0xffb00000
    ctx->pc = 0x12aa74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12aa78: 0xffb20010
    ctx->pc = 0x12aa78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12aa7c: 0xffb30018
    ctx->pc = 0x12aa7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12aa80: 0x12200025
    ctx->pc = 0x12AA80u;
    {
        const bool branch_taken_0x12aa80 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        ctx->pc = 0x12AA84u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        if (branch_taken_0x12aa80) {
            ctx->pc = 0x12AB18u;
            goto label_12ab18;
        }
    }
    ctx->pc = 0x12AA88u;
    // 0x12aa88: 0x3c020021
    ctx->pc = 0x12aa88u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12aa8c: 0x3c100021
    ctx->pc = 0x12aa8cu;
    SET_GPR_U32(ctx, 16, ((uint32_t)33 << 16));
    // 0x12aa90: 0x8c450460
    ctx->pc = 0x12aa90u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 1120)));
    // 0x12aa94: 0x24020001
    ctx->pc = 0x12aa94u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12aa98: 0x26100484
    ctx->pc = 0x12aa98u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1156));
    // 0x12aa9c: 0x3c120beb
    ctx->pc = 0x12aa9cu;
    SET_GPR_U32(ctx, 18, ((uint32_t)3051 << 16));
    // 0x12aaa0: 0xae020000
    ctx->pc = 0x12aaa0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x12aaa4: 0x200982d
    ctx->pc = 0x12aaa4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aaa8: 0x3652c1ff
    ctx->pc = 0x12aaa8u;
    SET_GPR_U32(ctx, 18, OR32(GPR_U32(ctx, 18), 49663));
    // 0x12aaac: 0xc04512c
    ctx->pc = 0x12AAACu;
    SET_GPR_U32(ctx, 31, 0x12AAB4u);
    ctx->pc = 0x12AAB0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1144B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AAB4u; }
    }
    if (ctx->pc != 0x12AAB4u) { return; }
    ctx->pc = 0x12AAB4u;
    // 0x12aab4: 0x10000003
    ctx->pc = 0x12AAB4u;
    {
        const bool branch_taken_0x12aab4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x12AAB8u;
        SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 18), GPR_S32(ctx, 16)));
        if (branch_taken_0x12aab4) {
            ctx->pc = 0x12AAC4u;
            goto label_12aac4;
        }
    }
    ctx->pc = 0x12AABCu;
    // 0x12aabc: 0x0
    ctx->pc = 0x12aabcu;
    // NOP
label_12aac0:
    // 0x12aac0: 0x250102a
    ctx->pc = 0x12aac0u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 18), GPR_S32(ctx, 16)));
label_12aac4:
    // 0x12aac4: 0x54400009
    ctx->pc = 0x12AAC4u;
    {
        const bool branch_taken_0x12aac4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x12aac4) {
            ctx->pc = 0x12AAC8u;
            SET_GPR_U32(ctx, 2, ((uint32_t)3051 << 16));
            ctx->pc = 0x12AAECu;
            goto label_12aaec;
        }
    }
    ctx->pc = 0x12AACCu;
    // 0x12aacc: 0xc04ac22
    ctx->pc = 0x12AACCu;
    SET_GPR_U32(ctx, 31, 0x12AAD4u);
    ctx->pc = 0x12AAD0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x12B088u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B088_0x12b088(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AAD4u; }
    }
    if (ctx->pc != 0x12AAD4u) { return; }
    ctx->pc = 0x12AAD4u;
    // 0x12aad4: 0xc04ac3c
    ctx->pc = 0x12AAD4u;
    SET_GPR_U32(ctx, 31, 0x12AADCu);
    ctx->pc = 0x12AAD8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x12B0F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0F0_0x12b0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AADCu; }
    }
    if (ctx->pc != 0x12AADCu) { return; }
    ctx->pc = 0x12AADCu;
    // 0x12aadc: 0x8e630000
    ctx->pc = 0x12aadcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12aae0: 0x5460fff7
    ctx->pc = 0x12AAE0u;
    {
        const bool branch_taken_0x12aae0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x12aae0) {
            ctx->pc = 0x12AAE4u;
            SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1));
            ctx->pc = 0x12AAC0u;
            goto label_12aac0;
        }
    }
    ctx->pc = 0x12AAE8u;
    // 0x12aae8: 0x3c020beb
    ctx->pc = 0x12aae8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)3051 << 16));
label_12aaec:
    // 0x12aaec: 0x3442c200
    ctx->pc = 0x12aaecu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 49664));
    // 0x12aaf0: 0x56020005
    ctx->pc = 0x12AAF0u;
    {
        const bool branch_taken_0x12aaf0 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 2));
        if (branch_taken_0x12aaf0) {
            ctx->pc = 0x12AAF4u;
            SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x12AB08u;
            goto label_12ab08;
        }
    }
    ctx->pc = 0x12AAF8u;
    // 0x12aaf8: 0x3c040024
    ctx->pc = 0x12aaf8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x12aafc: 0xc05062a
    ctx->pc = 0x12AAFCu;
    SET_GPR_U32(ctx, 31, 0x12AB04u);
    ctx->pc = 0x12AB00u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294943928));
    ctx->pc = 0x1418A8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001418A8_0x1418a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AB04u; }
    }
    if (ctx->pc != 0x12AB04u) { return; }
    ctx->pc = 0x12AB04u;
    // 0x12ab04: 0x220202d
    ctx->pc = 0x12ab04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12ab08:
    // 0x12ab08: 0xc04512c
    ctx->pc = 0x12AB08u;
    SET_GPR_U32(ctx, 31, 0x12AB10u);
    ctx->pc = 0x12AB0Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1144B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AB10u; }
    }
    if (ctx->pc != 0x12AB10u) { return; }
    ctx->pc = 0x12AB10u;
    // 0x12ab10: 0xc04ac56
    ctx->pc = 0x12AB10u;
    SET_GPR_U32(ctx, 31, 0x12AB18u);
    ctx->pc = 0x12AB14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x12B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B158_0x12b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AB18u; }
    }
    if (ctx->pc != 0x12AB18u) { return; }
    ctx->pc = 0x12AB18u;
label_12ab18:
    // 0x12ab18: 0xdfb00000
    ctx->pc = 0x12ab18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ab1c: 0xdfb10008
    ctx->pc = 0x12ab1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ab20: 0xdfb20010
    ctx->pc = 0x12ab20u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ab24: 0xdfb30018
    ctx->pc = 0x12ab24u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ab28: 0xdfb40020
    ctx->pc = 0x12ab28u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ab2c: 0xdfbf0028
    ctx->pc = 0x12ab2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ab30: 0x3e00008
    ctx->pc = 0x12AB30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12AB34u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A918u: goto label_12a918;
            case 0x12A948u: goto label_12a948;
            case 0x12A960u: goto label_12a960;
            case 0x12A9CCu: goto label_12a9cc;
            case 0x12AA40u: goto label_12aa40;
            case 0x12AA4Cu: goto label_12aa4c;
            case 0x12AA60u: goto label_12aa60;
            case 0x12AAC0u: goto label_12aac0;
            case 0x12AAC4u: goto label_12aac4;
            case 0x12AAECu: goto label_12aaec;
            case 0x12AB08u: goto label_12ab08;
            case 0x12AB18u: goto label_12ab18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12AB38u;
    // 0x12ab38: 0x27bdfff0
    ctx->pc = 0x12ab38u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12ab3c: 0x3c020021
    ctx->pc = 0x12ab3cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12ab40: 0xffbf0000
    ctx->pc = 0x12ab40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12ab44: 0x3c030021
    ctx->pc = 0x12ab44u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12ab48: 0x244204ec
    ctx->pc = 0x12ab48u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1260));
    // 0x12ab4c: 0x8c650478
    ctx->pc = 0x12ab4cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 3), 1144)));
    // 0x12ab50: 0x8c440000
    ctx->pc = 0x12ab50u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12ab54: 0xdfbf0000
    ctx->pc = 0x12ab54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ab58: 0x804aa98
    ctx->pc = 0x12AB58u;
    ctx->pc = 0x12AB5Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12AA60u;
    goto label_12aa60;
    ctx->pc = 0x12AB60u;
    // 0x12ab60: 0x27bdfff0
    ctx->pc = 0x12ab60u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12ab64: 0x3c020021
    ctx->pc = 0x12ab64u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12ab68: 0xffbf0000
    ctx->pc = 0x12ab68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12ab6c: 0x3c030021
    ctx->pc = 0x12ab6cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12ab70: 0x244204f0
    ctx->pc = 0x12ab70u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1264));
    // 0x12ab74: 0x8c65047c
    ctx->pc = 0x12ab74u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 3), 1148)));
    // 0x12ab78: 0x8c440000
    ctx->pc = 0x12ab78u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12ab7c: 0xdfbf0000
    ctx->pc = 0x12ab7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ab80: 0x804aa98
    ctx->pc = 0x12AB80u;
    ctx->pc = 0x12AB84u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12AA60u;
    goto label_12aa60;
    ctx->pc = 0x12AB88u;
}
