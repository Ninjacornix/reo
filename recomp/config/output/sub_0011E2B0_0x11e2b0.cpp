#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011E2B0
// Address: 0x11e2b0 - 0x11e440
void sub_0011E2B0_0x11e2b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11e2b0u;

    // 0x11e2b0: 0x27bdffc0
    ctx->pc = 0x11e2b0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11e2b4: 0x3c020021
    ctx->pc = 0x11e2b4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x11e2b8: 0xffbf0030
    ctx->pc = 0x11e2b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11e2bc: 0x2442b3e8
    ctx->pc = 0x11e2bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294947816));
    // 0x11e2c0: 0xffb20020
    ctx->pc = 0x11e2c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11e2c4: 0x80382d
    ctx->pc = 0x11e2c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e2c8: 0xffb10010
    ctx->pc = 0x11e2c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11e2cc: 0xffb00000
    ctx->pc = 0x11e2ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11e2d0: 0x8c43001c
    ctx->pc = 0x11e2d0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x11e2d4: 0x4610054
    ctx->pc = 0x11E2D4u;
    {
        const bool branch_taken_0x11e2d4 = (GPR_S32(ctx, 3) >= 0);
        ctx->pc = 0x11E2D8u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 24)));
        if (branch_taken_0x11e2d4) {
            ctx->pc = 0x11E428u;
            goto label_11e428;
        }
    }
    ctx->pc = 0x11E2DCu;
    // 0x11e2dc: 0x3c021000
    ctx->pc = 0x11e2dcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x11e2e0: 0x34421010
    ctx->pc = 0x11e2e0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 4112));
    // 0x11e2e4: 0x8c520000
    ctx->pc = 0x11e2e4u;
    SET_GPR_U32(ctx, 18, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x11e2e8: 0x54c0000c
    ctx->pc = 0x11E2E8u;
    {
        const bool branch_taken_0x11e2e8 = (GPR_U32(ctx, 6) != GPR_U32(ctx, 0));
        if (branch_taken_0x11e2e8) {
            ctx->pc = 0x11E2ECu;
            SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 32)));
            ctx->pc = 0x11E31Cu;
            goto label_11e31c;
        }
    }
    ctx->pc = 0x11E2F0u;
    // 0x11e2f0: 0xc0477d4
    ctx->pc = 0x11E2F0u;
    SET_GPR_U32(ctx, 31, 0x11E2F8u);
    ctx->pc = 0x11E2F4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11DF50u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF50_0x11df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E2F8u; }
    }
    if (ctx->pc != 0x11E2F8u) { return; }
    ctx->pc = 0x11E2F8u;
    // 0x11e2f8: 0x3c04ffff
    ctx->pc = 0x11e2f8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)65535 << 16));
    // 0x11e2fc: 0xdfbf0030
    ctx->pc = 0x11e2fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e300: 0x3484f7ff
    ctx->pc = 0x11e300u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 63487));
    // 0x11e304: 0xdfb10010
    ctx->pc = 0x11e304u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e308: 0x2442024
    ctx->pc = 0x11e308u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
    // 0x11e30c: 0xdfb00000
    ctx->pc = 0x11e30cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e310: 0xdfb20020
    ctx->pc = 0x11e310u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e314: 0x80477d0
    ctx->pc = 0x11E314u;
    ctx->pc = 0x11E318u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x11DF40u;
    sub_0011DF40_0x11df40(rdram, ctx, runtime); return;
    ctx->pc = 0x11E31Cu;
label_11e31c:
    // 0x11e31c: 0xdcc30010
    ctx->pc = 0x11e31cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x11e320: 0xdcc40018
    ctx->pc = 0x11e320u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x11e324: 0x43102d
    ctx->pc = 0x11e324u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 3));
    // 0x11e328: 0x8cc60000
    ctx->pc = 0x11e328u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x11e32c: 0x10c00019
    ctx->pc = 0x11E32Cu;
    {
        const bool branch_taken_0x11e32c = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E330u;
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) - GPR_U64(ctx, 4));
        if (branch_taken_0x11e32c) {
            ctx->pc = 0x11E394u;
            goto label_11e394;
        }
    }
    ctx->pc = 0x11E334u;
    // 0x11e334: 0xdcc20020
    ctx->pc = 0x11e334u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x11e338: 0x66037333
    ctx->pc = 0x11e338u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 16) + (int64_t)29491);
    // 0x11e33c: 0xdcc40010
    ctx->pc = 0x11e33cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x11e340: 0xdcc50018
    ctx->pc = 0x11e340u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x11e344: 0x44102d
    ctx->pc = 0x11e344u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 4));
    // 0x11e348: 0x45102f
    ctx->pc = 0x11e348u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 5));
    // 0x11e34c: 0x43182b
    ctx->pc = 0x11e34cu;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x11e350: 0x10600010
    ctx->pc = 0x11E350u;
    {
        const bool branch_taken_0x11e350 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E354u;
        SET_GPR_U32(ctx, 17, AND32(GPR_U32(ctx, 18), 3));
        if (branch_taken_0x11e350) {
            ctx->pc = 0x11E394u;
            goto label_11e394;
        }
    }
    ctx->pc = 0x11E358u;
    // 0x11e358: 0x40802d
    ctx->pc = 0x11e358u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e35c: 0x0
    ctx->pc = 0x11e35cu;
    // NOP
label_11e360:
    // 0x11e360: 0x8cc60000
    ctx->pc = 0x11e360u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x11e364: 0x10c0000c
    ctx->pc = 0x11E364u;
    {
        const bool branch_taken_0x11e364 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E368u;
        SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 16) + (int64_t)29491);
        if (branch_taken_0x11e364) {
            ctx->pc = 0x11E398u;
            goto label_11e398;
        }
    }
    ctx->pc = 0x11E36Cu;
    // 0x11e36c: 0xdcc20020
    ctx->pc = 0x11e36cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x11e370: 0xdcc40010
    ctx->pc = 0x11e370u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x11e374: 0xdcc50018
    ctx->pc = 0x11e374u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x11e378: 0x44102d
    ctx->pc = 0x11e378u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 4));
    // 0x11e37c: 0x45102f
    ctx->pc = 0x11e37cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 5));
    // 0x11e380: 0x43182b
    ctx->pc = 0x11e380u;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x11e384: 0x50600005
    ctx->pc = 0x11E384u;
    {
        const bool branch_taken_0x11e384 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x11e384) {
            ctx->pc = 0x11E388u;
            SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) - GPR_U64(ctx, 7));
            ctx->pc = 0x11E39Cu;
            goto label_11e39c;
        }
    }
    ctx->pc = 0x11E38Cu;
    // 0x11e38c: 0x1000fff4
    ctx->pc = 0x11E38Cu;
    {
        const bool branch_taken_0x11e38c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E390u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x11e38c) {
            ctx->pc = 0x11E360u;
            goto label_11e360;
        }
    }
    ctx->pc = 0x11E394u;
label_11e394:
    // 0x11e394: 0x32510003
    ctx->pc = 0x11e394u;
    SET_GPR_U32(ctx, 17, AND32(GPR_U32(ctx, 18), 3));
label_11e398:
    // 0x11e398: 0x207102f
    ctx->pc = 0x11e398u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) - GPR_U64(ctx, 7));
label_11e39c:
    // 0x11e39c: 0x28427333
    ctx->pc = 0x11e39cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 29491));
    // 0x11e3a0: 0x10400013
    ctx->pc = 0x11E3A0u;
    {
        const bool branch_taken_0x11e3a0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x11E3A4u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x11e3a0) {
            ctx->pc = 0x11E3F0u;
            goto label_11e3f0;
        }
    }
    ctx->pc = 0x11E3A8u;
    // 0x11e3a8: 0x112880
    ctx->pc = 0x11e3a8u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 17), 2));
    // 0x11e3ac: 0x34421000
    ctx->pc = 0x11e3acu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 4096));
    // 0x11e3b0: 0x24047333
    ctx->pc = 0x11e3b0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 29491));
    // 0x11e3b4: 0xa42016
    ctx->pc = 0x11e3b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (GPR_U32(ctx, 5) & 0x3F));
    // 0x11e3b8: 0x8c430000
    ctx->pc = 0x11e3b8u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x11e3bc: 0x4203c
    ctx->pc = 0x11e3bcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x11e3c0: 0x4203f
    ctx->pc = 0x11e3c0u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x11e3c4: 0xc0477d4
    ctx->pc = 0x11E3C4u;
    SET_GPR_U32(ctx, 31, 0x11E3CCu);
    ctx->pc = 0x11E3C8u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    ctx->pc = 0x11DF50u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF50_0x11df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E3CCu; }
    }
    if (ctx->pc != 0x11E3CCu) { return; }
    ctx->pc = 0x11E3CCu;
    // 0x11e3cc: 0x3c04ffff
    ctx->pc = 0x11e3ccu;
    SET_GPR_U32(ctx, 4, ((uint32_t)65535 << 16));
    // 0x11e3d0: 0xdfbf0030
    ctx->pc = 0x11e3d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e3d4: 0x3484f7ff
    ctx->pc = 0x11e3d4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 63487));
    // 0x11e3d8: 0xdfb10010
    ctx->pc = 0x11e3d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e3dc: 0x2442024
    ctx->pc = 0x11e3dcu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
    // 0x11e3e0: 0xdfb00000
    ctx->pc = 0x11e3e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e3e4: 0xdfb20020
    ctx->pc = 0x11e3e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e3e8: 0x80477d0
    ctx->pc = 0x11E3E8u;
    ctx->pc = 0x11E3ECu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x11DF40u;
    sub_0011DF40_0x11df40(rdram, ctx, runtime); return;
    ctx->pc = 0x11E3F0u;
label_11e3f0:
    // 0x11e3f0: 0x3c04ffff
    ctx->pc = 0x11e3f0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)65535 << 16));
    // 0x11e3f4: 0x3484f7ff
    ctx->pc = 0x11e3f4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 63487));
    // 0x11e3f8: 0xc0477d0
    ctx->pc = 0x11E3F8u;
    SET_GPR_U32(ctx, 31, 0x11E400u);
    ctx->pc = 0x11E3FCu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
    ctx->pc = 0x11DF40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E400u; }
    }
    if (ctx->pc != 0x11E400u) { return; }
    ctx->pc = 0x11E400u;
    // 0x11e400: 0x112080
    ctx->pc = 0x11e400u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 17), 2));
    // 0x11e404: 0xdfbf0030
    ctx->pc = 0x11e404u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e408: 0x902016
    ctx->pc = 0x11e408u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) >> (GPR_U32(ctx, 4) & 0x3F));
    // 0x11e40c: 0xdfb20020
    ctx->pc = 0x11e40cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e410: 0xdfb10010
    ctx->pc = 0x11e410u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e414: 0x4203c
    ctx->pc = 0x11e414u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x11e418: 0x4203f
    ctx->pc = 0x11e418u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x11e41c: 0xdfb00000
    ctx->pc = 0x11e41cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e420: 0x80477d4
    ctx->pc = 0x11E420u;
    ctx->pc = 0x11E424u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x11DF50u;
    sub_0011DF50_0x11df50(rdram, ctx, runtime); return;
    ctx->pc = 0x11E428u;
label_11e428:
    // 0x11e428: 0xdfbf0030
    ctx->pc = 0x11e428u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e42c: 0xdfb20020
    ctx->pc = 0x11e42cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e430: 0xdfb10010
    ctx->pc = 0x11e430u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e434: 0xdfb00000
    ctx->pc = 0x11e434u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e438: 0x3e00008
    ctx->pc = 0x11E438u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E43Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E31Cu: goto label_11e31c;
            case 0x11E360u: goto label_11e360;
            case 0x11E394u: goto label_11e394;
            case 0x11E398u: goto label_11e398;
            case 0x11E39Cu: goto label_11e39c;
            case 0x11E3F0u: goto label_11e3f0;
            case 0x11E428u: goto label_11e428;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E440u;
}
