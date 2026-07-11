#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013F8A8
// Address: 0x13f8a8 - 0x13f9f0
void sub_0013F8A8_0x13f8a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13f8a8u;

    // 0x13f8a8: 0x27bdffd0
    ctx->pc = 0x13f8a8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13f8ac: 0xffb10008
    ctx->pc = 0x13f8acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f8b0: 0x80882d
    ctx->pc = 0x13f8b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f8b4: 0xffb20010
    ctx->pc = 0x13f8b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f8b8: 0xa0902d
    ctx->pc = 0x13f8b8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f8bc: 0xffb30018
    ctx->pc = 0x13f8bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13f8c0: 0xffb00000
    ctx->pc = 0x13f8c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f8c4: 0xffbf0020
    ctx->pc = 0x13f8c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13f8c8: 0xc04fc96
    ctx->pc = 0x13F8C8u;
    SET_GPR_U32(ctx, 31, 0x13F8D0u);
    ctx->pc = 0x13F8CCu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x13F258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F8D0u; }
    }
    if (ctx->pc != 0x13F8D0u) { return; }
    ctx->pc = 0x13F8D0u;
    // 0x13f8d0: 0x3c050022
    ctx->pc = 0x13f8d0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)34 << 16));
    // 0x13f8d4: 0x24a24c60
    ctx->pc = 0x13f8d4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 5), 19552));
    // 0x13f8d8: 0x24420004
    ctx->pc = 0x13f8d8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4));
    // 0x13f8dc: 0x8c430000
    ctx->pc = 0x13f8dcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13f8e0: 0x1060000c
    ctx->pc = 0x13F8E0u;
    {
        const bool branch_taken_0x13f8e0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x13F8E4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13f8e0) {
            ctx->pc = 0x13F914u;
            goto label_13f914;
        }
    }
    ctx->pc = 0x13F8E8u;
    // 0x13f8e8: 0x40182d
    ctx->pc = 0x13f8e8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f8ec: 0x24840001
    ctx->pc = 0x13f8ecu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1));
label_13f8f0:
    // 0x13f8f0: 0x28820100
    ctx->pc = 0x13f8f0u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 4), 256));
    // 0x13f8f4: 0x10400007
    ctx->pc = 0x13F8F4u;
    {
        const bool branch_taken_0x13f8f4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x13F8F8u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 64));
        if (branch_taken_0x13f8f4) {
            ctx->pc = 0x13F914u;
            goto label_13f914;
        }
    }
    ctx->pc = 0x13F8FCu;
    // 0x13f8fc: 0x8c620000
    ctx->pc = 0x13f8fcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13f900: 0x0
    ctx->pc = 0x13f900u;
    // NOP
    // 0x13f904: 0x0
    ctx->pc = 0x13f904u;
    // NOP
    // 0x13f908: 0x0
    ctx->pc = 0x13f908u;
    // NOP
    // 0x13f90c: 0x5440fff8
    ctx->pc = 0x13F90Cu;
    {
        const bool branch_taken_0x13f90c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x13f90c) {
            ctx->pc = 0x13F910u;
            SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1));
            ctx->pc = 0x13F8F0u;
            goto label_13f8f0;
        }
    }
    ctx->pc = 0x13F914u;
label_13f914:
    // 0x13f914: 0x24020100
    ctx->pc = 0x13f914u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 256));
    // 0x13f918: 0x10820015
    ctx->pc = 0x13F918u;
    {
        const bool branch_taken_0x13f918 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x13F91Cu;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13f918) {
            ctx->pc = 0x13F970u;
            goto label_13f970;
        }
    }
    ctx->pc = 0x13F920u;
    // 0x13f920: 0x24a24c60
    ctx->pc = 0x13f920u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 5), 19552));
    // 0x13f924: 0x3c050024
    ctx->pc = 0x13f924u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x13f928: 0x42180
    ctx->pc = 0x13f928u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 6));
    // 0x13f92c: 0x3c030022
    ctx->pc = 0x13f92cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13f930: 0x3c060014
    ctx->pc = 0x13f930u;
    SET_GPR_U32(ctx, 6, ((uint32_t)20 << 16));
    // 0x13f934: 0x828021
    ctx->pc = 0x13f934u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13f938: 0x24634c28
    ctx->pc = 0x13f938u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 19496));
    // 0x13f93c: 0x24a5da58
    ctx->pc = 0x13f93cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294957656));
    // 0x13f940: 0x24c6f7d8
    ctx->pc = 0x13f940u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 4294965208));
    // 0x13f944: 0x24020001
    ctx->pc = 0x13f944u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x13f948: 0xae020004
    ctx->pc = 0x13f948u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x13f94c: 0x200202d
    ctx->pc = 0x13f94cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f950: 0xae030000
    ctx->pc = 0x13f950u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x13f954: 0xae11001c
    ctx->pc = 0x13f954u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 17));
    // 0x13f958: 0xae120020
    ctx->pc = 0x13f958u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 18));
    // 0x13f95c: 0xae130024
    ctx->pc = 0x13f95cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 19));
    // 0x13f960: 0xae050008
    ctx->pc = 0x13f960u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 5));
    // 0x13f964: 0xae060038
    ctx->pc = 0x13f964u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 6));
    // 0x13f968: 0xc04fe7c
    ctx->pc = 0x13F968u;
    SET_GPR_U32(ctx, 31, 0x13F970u);
    ctx->pc = 0x13F96Cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 16));
    ctx->pc = 0x13F9F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F9F0_0x13f9f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F970u; }
    }
    if (ctx->pc != 0x13F970u) { return; }
    ctx->pc = 0x13F970u;
label_13f970:
    // 0x13f970: 0xc04fc9c
    ctx->pc = 0x13F970u;
    SET_GPR_U32(ctx, 31, 0x13F978u);
    ctx->pc = 0x13F270u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F978u; }
    }
    if (ctx->pc != 0x13F978u) { return; }
    ctx->pc = 0x13F978u;
    // 0x13f978: 0x200102d
    ctx->pc = 0x13f978u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f97c: 0xdfb10008
    ctx->pc = 0x13f97cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f980: 0xdfb00000
    ctx->pc = 0x13f980u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f984: 0xdfb20010
    ctx->pc = 0x13f984u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f988: 0xdfb30018
    ctx->pc = 0x13f988u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f98c: 0xdfbf0020
    ctx->pc = 0x13f98cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13f990: 0x3e00008
    ctx->pc = 0x13F990u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F994u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F8F0u: goto label_13f8f0;
            case 0x13F914u: goto label_13f914;
            case 0x13F970u: goto label_13f970;
            case 0x13F9C8u: goto label_13f9c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F998u;
    // 0x13f998: 0x27bdfff0
    ctx->pc = 0x13f998u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f99c: 0xffb00000
    ctx->pc = 0x13f99cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f9a0: 0xffbf0008
    ctx->pc = 0x13f9a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13f9a4: 0xc04fc96
    ctx->pc = 0x13F9A4u;
    SET_GPR_U32(ctx, 31, 0x13F9ACu);
    ctx->pc = 0x13F9A8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x13F258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9ACu; }
    }
    if (ctx->pc != 0x13F9ACu) { return; }
    ctx->pc = 0x13F9ACu;
    // 0x13f9ac: 0x200202d
    ctx->pc = 0x13f9acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f9b0: 0x282d
    ctx->pc = 0x13f9b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f9b4: 0x12000004
    ctx->pc = 0x13F9B4u;
    {
        const bool branch_taken_0x13f9b4 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x13F9B8u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 64));
        if (branch_taken_0x13f9b4) {
            ctx->pc = 0x13F9C8u;
            goto label_13f9c8;
        }
    }
    ctx->pc = 0x13F9BCu;
    // 0x13f9bc: 0xc041f1a
    ctx->pc = 0x13F9BCu;
    SET_GPR_U32(ctx, 31, 0x13F9C4u);
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9C4u; }
    }
    if (ctx->pc != 0x13F9C4u) { return; }
    ctx->pc = 0x13F9C4u;
    // 0x13f9c4: 0xae000004
    ctx->pc = 0x13f9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_13f9c8:
    // 0x13f9c8: 0xdfb00000
    ctx->pc = 0x13f9c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f9cc: 0xdfbf0008
    ctx->pc = 0x13f9ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f9d0: 0x804fc9c
    ctx->pc = 0x13F9D0u;
    ctx->pc = 0x13F9D4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x13F270u;
    sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    ctx->pc = 0x13F9D8u;
    // 0x13f9d8: 0x3e00008
    ctx->pc = 0x13F9D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F9DCu;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F8F0u: goto label_13f8f0;
            case 0x13F914u: goto label_13f914;
            case 0x13F970u: goto label_13f970;
            case 0x13F9C8u: goto label_13f9c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F9E0u;
    // 0x13f9e0: 0xac86003c
    ctx->pc = 0x13f9e0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 6));
    // 0x13f9e4: 0x3e00008
    ctx->pc = 0x13F9E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F9E8u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F8F0u: goto label_13f8f0;
            case 0x13F914u: goto label_13f914;
            case 0x13F970u: goto label_13f970;
            case 0x13F9C8u: goto label_13f9c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F9ECu;
    // 0x13f9ec: 0x0
    ctx->pc = 0x13f9ecu;
    // NOP
}
