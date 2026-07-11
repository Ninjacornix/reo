#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017E778
// Address: 0x17e778 - 0x17e870
void sub_0017E778_0x17e778(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17e778u;

    // 0x17e778: 0x3c030023
    ctx->pc = 0x17e778u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17e77c: 0x2466f988
    ctx->pc = 0x17e77cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 3), 4294965640));
    // 0x17e780: 0x8cc20000
    ctx->pc = 0x17e780u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x17e784: 0x10400006
    ctx->pc = 0x17E784u;
    {
        const bool branch_taken_0x17e784 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x17E788u;
        SET_GPR_U32(ctx, 5, ((uint32_t)39 << 16));
        if (branch_taken_0x17e784) {
            ctx->pc = 0x17E7A0u;
            goto label_17e7a0;
        }
    }
    ctx->pc = 0x17E78Cu;
    // 0x17e78c: 0x8ca26158
    ctx->pc = 0x17e78cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 24920)));
    // 0x17e790: 0x10440035
    ctx->pc = 0x17E790u;
    {
        const bool branch_taken_0x17e790 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 4));
        ctx->pc = 0x17E794u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x17e790) {
            ctx->pc = 0x17E868u;
            goto label_17e868;
        }
    }
    ctx->pc = 0x17E798u;
    // 0x17e798: 0x10000003
    ctx->pc = 0x17E798u;
    {
        const bool branch_taken_0x17e798 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x17E79Cu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x17e798) {
            ctx->pc = 0x17E7A8u;
            goto label_17e7a8;
        }
    }
    ctx->pc = 0x17E7A0u;
label_17e7a0:
    // 0x17e7a0: 0x24020001
    ctx->pc = 0x17e7a0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e7a4: 0x2403ffff
    ctx->pc = 0x17e7a4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_17e7a8:
    // 0x17e7a8: 0xacc20000
    ctx->pc = 0x17e7a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x17e7ac: 0x14830006
    ctx->pc = 0x17E7ACu;
    {
        const bool branch_taken_0x17e7ac = (GPR_U32(ctx, 4) != GPR_U32(ctx, 3));
        ctx->pc = 0x17E7B0u;
        WRITE32(ADD32(GPR_U32(ctx, 5), 24920), GPR_U32(ctx, 4));
        if (branch_taken_0x17e7ac) {
            ctx->pc = 0x17E7C8u;
            goto label_17e7c8;
        }
    }
    ctx->pc = 0x17E7B4u;
    // 0x17e7b4: 0x3c030023
    ctx->pc = 0x17e7b4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17e7b8: 0x24020001
    ctx->pc = 0x17e7b8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e7bc: 0x3e00008
    ctx->pc = 0x17E7BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E7C0u;
        WRITE64(ADD32(GPR_U32(ctx, 3), 4294965632), GPR_U64(ctx, 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E7A0u: goto label_17e7a0;
            case 0x17E7A8u: goto label_17e7a8;
            case 0x17E7C8u: goto label_17e7c8;
            case 0x17E818u: goto label_17e818;
            case 0x17E81Cu: goto label_17e81c;
            case 0x17E868u: goto label_17e868;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E7C4u;
    // 0x17e7c4: 0x0
    ctx->pc = 0x17e7c4u;
    // NOP
label_17e7c8:
    // 0x17e7c8: 0x3c030023
    ctx->pc = 0x17e7c8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17e7cc: 0x3c020008
    ctx->pc = 0x17e7ccu;
    SET_GPR_U32(ctx, 2, ((uint32_t)8 << 16));
    // 0x17e7d0: 0x3442ca00
    ctx->pc = 0x17e7d0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 51712));
    // 0x17e7d4: 0x42880
    ctx->pc = 0x17e7d4u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 4), 2));
    // 0x17e7d8: 0xfc62f980
    ctx->pc = 0x17e7d8u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 4294965632), GPR_U64(ctx, 2));
    // 0x17e7dc: 0x3c040024
    ctx->pc = 0x17e7dcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x17e7e0: 0x852021
    ctx->pc = 0x17e7e0u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x17e7e4: 0x8c841580
    ctx->pc = 0x17e7e4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 5504)));
    // 0x17e7e8: 0x24030082
    ctx->pc = 0x17e7e8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 130));
    // 0x17e7ec: 0x8c820000
    ctx->pc = 0x17e7ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17e7f0: 0x304200c7
    ctx->pc = 0x17e7f0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 199));
    // 0x17e7f4: 0x10430008
    ctx->pc = 0x17E7F4u;
    {
        const bool branch_taken_0x17e7f4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x17E7F8u;
        SET_GPR_U32(ctx, 6, ((uint32_t)36 << 16));
        if (branch_taken_0x17e7f4) {
            ctx->pc = 0x17E818u;
            goto label_17e818;
        }
    }
    ctx->pc = 0x17E7FCu;
    // 0x17e7fc: 0x3c020024
    ctx->pc = 0x17e7fcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
    // 0x17e800: 0x451021
    ctx->pc = 0x17e800u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17e804: 0x8c421590
    ctx->pc = 0x17e804u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 5520)));
    // 0x17e808: 0xac400000
    ctx->pc = 0x17e808u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x17e80c: 0xac830000
    ctx->pc = 0x17e80cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x17e810: 0x10000002
    ctx->pc = 0x17E810u;
    {
        const bool branch_taken_0x17e810 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x17E814u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 6), 5520));
        if (branch_taken_0x17e810) {
            ctx->pc = 0x17E81Cu;
            goto label_17e81c;
        }
    }
    ctx->pc = 0x17E818u;
label_17e818:
    // 0x17e818: 0x24c21590
    ctx->pc = 0x17e818u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 6), 5520));
label_17e81c:
    // 0x17e81c: 0x3c060027
    ctx->pc = 0x17e81cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)39 << 16));
    // 0x17e820: 0xa21021
    ctx->pc = 0x17e820u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x17e824: 0x3c050027
    ctx->pc = 0x17e824u;
    SET_GPR_U32(ctx, 5, ((uint32_t)39 << 16));
    // 0x17e828: 0x8c430000
    ctx->pc = 0x17e828u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17e82c: 0x3c040027
    ctx->pc = 0x17e82cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)39 << 16));
    // 0x17e830: 0x24846160
    ctx->pc = 0x17e830u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 24928));
    // 0x17e834: 0x24a56170
    ctx->pc = 0x17e834u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 24944));
    // 0x17e838: 0x8c620000
    ctx->pc = 0x17e838u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17e83c: 0x3c070027
    ctx->pc = 0x17e83cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)39 << 16));
    // 0x17e840: 0x24e76180
    ctx->pc = 0x17e840u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 24960));
    // 0x17e844: 0x24c66184
    ctx->pc = 0x17e844u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 24964));
    // 0x17e848: 0xa4820008
    ctx->pc = 0x17e848u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x17e84c: 0xfc800000
    ctx->pc = 0x17e84cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 0));
    // 0x17e850: 0xdc820000
    ctx->pc = 0x17e850u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17e854: 0xfca20000
    ctx->pc = 0x17e854u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x17e858: 0xdc830008
    ctx->pc = 0x17e858u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17e85c: 0xfca30008
    ctx->pc = 0x17e85cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 3));
    // 0x17e860: 0xace40000
    ctx->pc = 0x17e860u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x17e864: 0xacc00000
    ctx->pc = 0x17e864u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
label_17e868:
    // 0x17e868: 0x3e00008
    ctx->pc = 0x17E868u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E7A0u: goto label_17e7a0;
            case 0x17E7A8u: goto label_17e7a8;
            case 0x17E7C8u: goto label_17e7c8;
            case 0x17E818u: goto label_17e818;
            case 0x17E81Cu: goto label_17e81c;
            case 0x17E868u: goto label_17e868;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E870u;
}
