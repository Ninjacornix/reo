#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00141280
// Address: 0x141280 - 0x141418
void sub_00141280_0x141280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x141280u;

    // 0x141280: 0x27bdffc0
    ctx->pc = 0x141280u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x141284: 0xffb50028
    ctx->pc = 0x141284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x141288: 0x3c150023
    ctx->pc = 0x141288u;
    SET_GPR_U32(ctx, 21, ((uint32_t)35 << 16));
    // 0x14128c: 0x8ea29a7c
    ctx->pc = 0x14128cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 21), 4294941308)));
    // 0x141290: 0xffb00000
    ctx->pc = 0x141290u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141294: 0xffb10008
    ctx->pc = 0x141294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141298: 0xffb20010
    ctx->pc = 0x141298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x14129c: 0xffb30018
    ctx->pc = 0x14129cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1412a0: 0xffb40020
    ctx->pc = 0x1412a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1412a4: 0x1440004f
    ctx->pc = 0x1412A4u;
    {
        const bool branch_taken_0x1412a4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1412A8u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        if (branch_taken_0x1412a4) {
            ctx->pc = 0x1413E4u;
            goto label_1413e4;
        }
    }
    ctx->pc = 0x1412ACu;
    // 0x1412ac: 0x3c100023
    ctx->pc = 0x1412acu;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
    // 0x1412b0: 0x3c140023
    ctx->pc = 0x1412b0u;
    SET_GPR_U32(ctx, 20, ((uint32_t)35 << 16));
    // 0x1412b4: 0x26109d18
    ctx->pc = 0x1412b4u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294941976));
    // 0x1412b8: 0x282d
    ctx->pc = 0x1412b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1412bc: 0x200202d
    ctx->pc = 0x1412bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1412c0: 0x26100040
    ctx->pc = 0x1412c0u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 64));
    // 0x1412c4: 0x240608d0
    ctx->pc = 0x1412c4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2256));
    // 0x1412c8: 0xc041f1a
    ctx->pc = 0x1412C8u;
    SET_GPR_U32(ctx, 31, 0x1412D0u);
    ctx->pc = 0x1412CCu;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 20), 4294941316));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1412D0u; }
    }
    if (ctx->pc != 0x1412D0u) { return; }
    ctx->pc = 0x1412D0u;
    // 0x1412d0: 0xc04e4be
    ctx->pc = 0x1412D0u;
    SET_GPR_U32(ctx, 31, 0x1412D8u);
    ctx->pc = 0x1412D4u;
    SET_GPR_U32(ctx, 18, ((uint32_t)35 << 16));
    ctx->pc = 0x1392F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001392F8_0x1392f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1412D8u; }
    }
    if (ctx->pc != 0x1412D8u) { return; }
    ctx->pc = 0x1412D8u;
    // 0x1412d8: 0x2402ffc0
    ctx->pc = 0x1412d8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1412dc: 0x8e630000
    ctx->pc = 0x1412dcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1412e0: 0x24040880
    ctx->pc = 0x1412e0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2176));
    // 0x1412e4: 0x2028024
    ctx->pc = 0x1412e4u;
    SET_GPR_U32(ctx, 16, AND32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1412e8: 0x3c110023
    ctx->pc = 0x1412e8u;
    SET_GPR_U32(ctx, 17, ((uint32_t)35 << 16));
    // 0x1412ec: 0xae449d14
    ctx->pc = 0x1412ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294941972), GPR_U32(ctx, 4));
    // 0x1412f0: 0x14600011
    ctx->pc = 0x1412F0u;
    {
        const bool branch_taken_0x1412f0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x1412f0) {
            ctx->pc = 0x141338u;
            goto label_141338;
        }
    }
    ctx->pc = 0x1412F8u;
    // 0x1412f8: 0xc046e2c
    ctx->pc = 0x1412F8u;
    SET_GPR_U32(ctx, 31, 0x141300u);
    ctx->pc = 0x1412FCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2256));
    ctx->pc = 0x11B8B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B8B0_0x11b8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141300u; }
    }
    if (ctx->pc != 0x141300u) { return; }
    ctx->pc = 0x141300u;
    // 0x141300: 0x1440000d
    ctx->pc = 0x141300u;
    {
        const bool branch_taken_0x141300 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x141304u;
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x141300) {
            ctx->pc = 0x141338u;
            goto label_141338;
        }
    }
    ctx->pc = 0x141308u;
    // 0x141308: 0x3c040024
    ctx->pc = 0x141308u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x14130c: 0xc045a12
    ctx->pc = 0x14130Cu;
    SET_GPR_U32(ctx, 31, 0x141314u);
    ctx->pc = 0x141310u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294957816));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141314u; }
    }
    if (ctx->pc != 0x141314u) { return; }
    ctx->pc = 0x141314u;
    // 0x141314: 0x0
    ctx->pc = 0x141314u;
    // NOP
label_141318:
    // 0x141318: 0x0
    ctx->pc = 0x141318u;
    // NOP
    // 0x14131c: 0x0
    ctx->pc = 0x14131cu;
    // NOP
    // 0x141320: 0x0
    ctx->pc = 0x141320u;
    // NOP
    // 0x141324: 0x0
    ctx->pc = 0x141324u;
    // NOP
    // 0x141328: 0x0
    ctx->pc = 0x141328u;
    // NOP
    // 0x14132c: 0x1000fffa
    ctx->pc = 0x14132Cu;
    {
        const bool branch_taken_0x14132c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x14132c) {
            ctx->pc = 0x141318u;
            goto label_141318;
        }
    }
    ctx->pc = 0x141334u;
    // 0x141334: 0x0
    ctx->pc = 0x141334u;
    // NOP
label_141338:
    // 0x141338: 0x8e829a84
    ctx->pc = 0x141338u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 4294941316)));
    // 0x14133c: 0x2403ffc0
    ctx->pc = 0x14133cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x141340: 0x8e259a80
    ctx->pc = 0x141340u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4294941312)));
    // 0x141344: 0x3c080023
    ctx->pc = 0x141344u;
    SET_GPR_U32(ctx, 8, ((uint32_t)35 << 16));
    // 0x141348: 0x24420040
    ctx->pc = 0x141348u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 64));
    // 0x14134c: 0x8e479d14
    ctx->pc = 0x14134cu;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 18), 4294941972)));
    // 0x141350: 0x431024
    ctx->pc = 0x141350u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x141354: 0x202d
    ctx->pc = 0x141354u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141358: 0x40302d
    ctx->pc = 0x141358u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14135c: 0x0
    ctx->pc = 0x14135cu;
    // NOP
    // 0x141360: 0xc04e3de
    ctx->pc = 0x141360u;
    SET_GPR_U32(ctx, 31, 0x141368u);
    ctx->pc = 0x141364u;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
    ctx->pc = 0x138F78u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138F78_0x138f78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141368u; }
    }
    if (ctx->pc != 0x141368u) { return; }
    ctx->pc = 0x141368u;
    // 0x141368: 0x1440000d
    ctx->pc = 0x141368u;
    {
        const bool branch_taken_0x141368 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x14136Cu;
        WRITE32(ADD32(GPR_U32(ctx, 16), 4294941968), GPR_U32(ctx, 2));
        if (branch_taken_0x141368) {
            ctx->pc = 0x1413A0u;
            goto label_1413a0;
        }
    }
    ctx->pc = 0x141370u;
    // 0x141370: 0x3c040024
    ctx->pc = 0x141370u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x141374: 0xc045a12
    ctx->pc = 0x141374u;
    SET_GPR_U32(ctx, 31, 0x14137Cu);
    ctx->pc = 0x141378u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294957864));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14137Cu; }
    }
    if (ctx->pc != 0x14137Cu) { return; }
    ctx->pc = 0x14137Cu;
    // 0x14137c: 0x0
    ctx->pc = 0x14137cu;
    // NOP
label_141380:
    // 0x141380: 0x0
    ctx->pc = 0x141380u;
    // NOP
    // 0x141384: 0x0
    ctx->pc = 0x141384u;
    // NOP
    // 0x141388: 0x0
    ctx->pc = 0x141388u;
    // NOP
    // 0x14138c: 0x0
    ctx->pc = 0x14138cu;
    // NOP
    // 0x141390: 0x0
    ctx->pc = 0x141390u;
    // NOP
    // 0x141394: 0x1000fffa
    ctx->pc = 0x141394u;
    {
        const bool branch_taken_0x141394 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x141394) {
            ctx->pc = 0x141380u;
            goto label_141380;
        }
    }
    ctx->pc = 0x14139Cu;
    // 0x14139c: 0x0
    ctx->pc = 0x14139cu;
    // NOP
label_1413a0:
    // 0x1413a0: 0x26109d10
    ctx->pc = 0x1413a0u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294941968));
    // 0x1413a4: 0x3c050014
    ctx->pc = 0x1413a4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)20 << 16));
    // 0x1413a8: 0x8e040000
    ctx->pc = 0x1413a8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1413ac: 0x24a50f18
    ctx->pc = 0x1413acu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 3864));
    // 0x1413b0: 0xc04e45e
    ctx->pc = 0x1413B0u;
    SET_GPR_U32(ctx, 31, 0x1413B8u);
    ctx->pc = 0x1413B4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x139178u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00139178_0x139178(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1413B8u; }
    }
    if (ctx->pc != 0x1413B8u) { return; }
    ctx->pc = 0x1413B8u;
    // 0x1413b8: 0x3c050014
    ctx->pc = 0x1413b8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)20 << 16));
    // 0x1413bc: 0x8e040000
    ctx->pc = 0x1413bcu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1413c0: 0x24a50fb8
    ctx->pc = 0x1413c0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4024));
    // 0x1413c4: 0xc04e462
    ctx->pc = 0x1413C4u;
    SET_GPR_U32(ctx, 31, 0x1413CCu);
    ctx->pc = 0x1413C8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x139188u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00139188_0x139188(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1413CCu; }
    }
    if (ctx->pc != 0x1413CCu) { return; }
    ctx->pc = 0x1413CCu;
    // 0x1413cc: 0x24040003
    ctx->pc = 0x1413ccu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1413d0: 0x282d
    ctx->pc = 0x1413d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1413d4: 0x302d
    ctx->pc = 0x1413d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1413d8: 0x382d
    ctx->pc = 0x1413d8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1413dc: 0xc04e518
    ctx->pc = 0x1413DCu;
    SET_GPR_U32(ctx, 31, 0x1413E4u);
    ctx->pc = 0x1413E0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x139460u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1413E4u; }
    }
    if (ctx->pc != 0x1413E4u) { return; }
    ctx->pc = 0x1413E4u;
label_1413e4:
    // 0x1413e4: 0x26a39a7c
    ctx->pc = 0x1413e4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 21), 4294941308));
    // 0x1413e8: 0xdfb50028
    ctx->pc = 0x1413e8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1413ec: 0x8c620000
    ctx->pc = 0x1413ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1413f0: 0xdfb00000
    ctx->pc = 0x1413f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1413f4: 0xdfb10008
    ctx->pc = 0x1413f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1413f8: 0x24420001
    ctx->pc = 0x1413f8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1413fc: 0xdfb20010
    ctx->pc = 0x1413fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141400: 0xdfb30018
    ctx->pc = 0x141400u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x141404: 0xdfb40020
    ctx->pc = 0x141404u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x141408: 0xdfbf0030
    ctx->pc = 0x141408u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x14140c: 0xac620000
    ctx->pc = 0x14140cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x141410: 0x3e00008
    ctx->pc = 0x141410u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141414u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141318u: goto label_141318;
            case 0x141338u: goto label_141338;
            case 0x141380u: goto label_141380;
            case 0x1413A0u: goto label_1413a0;
            case 0x1413E4u: goto label_1413e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141418u;
}
