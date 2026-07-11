#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00144500
// Address: 0x144500 - 0x144618
void sub_00144500_0x144500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x144500u;

    // 0x144500: 0x27bdffa0
    ctx->pc = 0x144500u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x144504: 0xffb40040
    ctx->pc = 0x144504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x144508: 0xffb30030
    ctx->pc = 0x144508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x14450c: 0x24140001
    ctx->pc = 0x14450cu;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 0), 1));
    // 0x144510: 0xffb20020
    ctx->pc = 0x144510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x144514: 0x24130003
    ctx->pc = 0x144514u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 0), 3));
    // 0x144518: 0xffb10010
    ctx->pc = 0x144518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x14451c: 0x80902d
    ctx->pc = 0x14451cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144520: 0xffbf0050
    ctx->pc = 0x144520u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x144524: 0xffb00000
    ctx->pc = 0x144524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x144528: 0xae400828
    ctx->pc = 0x144528u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2088), GPR_U32(ctx, 0));
    // 0x14452c: 0x8e420148
    ctx->pc = 0x14452cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 328)));
    // 0x144530: 0x8e440144
    ctx->pc = 0x144530u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 324)));
    // 0x144534: 0x8e43018c
    ctx->pc = 0x144534u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 396)));
    // 0x144538: 0x828818
    ctx->pc = 0x144538u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 17, (int32_t)(uint32_t)result); }
    // 0x14453c: 0xae40082c
    ctx->pc = 0x14453cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2092), GPR_U32(ctx, 0));
    // 0x144540: 0x38630003
    ctx->pc = 0x144540u;
    SET_GPR_U32(ctx, 3, XOR32(GPR_U32(ctx, 3), 3));
    // 0x144544: 0x111043
    ctx->pc = 0x144544u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 17), 1));
    // 0x144548: 0x43880b
    ctx->pc = 0x144548u;
    if (GPR_U32(ctx, 3) != 0) SET_GPR_U32(ctx, 17, GPR_U32(ctx, 2));
    // 0x14454c: 0x0
    ctx->pc = 0x14454cu;
    // NOP
label_144550:
    // 0x144550: 0x240202d
    ctx->pc = 0x144550u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_144554:
    // 0x144554: 0xc0511d2
    ctx->pc = 0x144554u;
    SET_GPR_U32(ctx, 31, 0x14455Cu);
    ctx->pc = 0x144558u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x144748u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00144748_0x144748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14455Cu; }
    }
    if (ctx->pc != 0x14455Cu) { return; }
    ctx->pc = 0x14455Cu;
    // 0x14455c: 0x40802d
    ctx->pc = 0x14455cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144560: 0x1214fffc
    ctx->pc = 0x144560u;
    {
        const bool branch_taken_0x144560 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 20));
        ctx->pc = 0x144564u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144560) {
            ctx->pc = 0x144554u;
            goto label_144554;
        }
    }
    ctx->pc = 0x144568u;
    // 0x144568: 0x1213fff9
    ctx->pc = 0x144568u;
    {
        const bool branch_taken_0x144568 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 19));
        if (branch_taken_0x144568) {
            ctx->pc = 0x144550u;
            goto label_144550;
        }
    }
    ctx->pc = 0x144570u;
    // 0x144570: 0xc051496
    ctx->pc = 0x144570u;
    SET_GPR_U32(ctx, 31, 0x144578u);
    ctx->pc = 0x144574u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x145258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144578u; }
    }
    if (ctx->pc != 0x144578u) { return; }
    ctx->pc = 0x144578u;
    // 0x144578: 0xc050fec
    ctx->pc = 0x144578u;
    SET_GPR_U32(ctx, 31, 0x144580u);
    ctx->pc = 0x14457Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x143FB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00143FB0_0x143fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144580u; }
    }
    if (ctx->pc != 0x144580u) { return; }
    ctx->pc = 0x144580u;
    // 0x144580: 0x14400006
    ctx->pc = 0x144580u;
    {
        const bool branch_taken_0x144580 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x144584u;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x144580) {
            ctx->pc = 0x14459Cu;
            goto label_14459c;
        }
    }
    ctx->pc = 0x144588u;
    // 0x144588: 0x8e4210a0
    ctx->pc = 0x144588u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 4256)));
    // 0x14458c: 0x1440001a
    ctx->pc = 0x14458Cu;
    {
        const bool branch_taken_0x14458c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x144590u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
        if (branch_taken_0x14458c) {
            ctx->pc = 0x1445F8u;
            goto label_1445f8;
        }
    }
    ctx->pc = 0x144594u;
    // 0x144594: 0x24100002
    ctx->pc = 0x144594u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 2));
    // 0x144598: 0x3c031000
    ctx->pc = 0x144598u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_14459c:
    // 0x14459c: 0x2611ffff
    ctx->pc = 0x14459cu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x1445a0: 0x2e130001
    ctx->pc = 0x1445a0u;
    SET_GPR_U32(ctx, 19, SLTU32(GPR_U32(ctx, 16), 1));
    // 0x1445a4: 0x3463d400
    ctx->pc = 0x1445a4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 54272));
label_1445a8:
    // 0x1445a8: 0x8c620000
    ctx->pc = 0x1445a8u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1445ac: 0x21202
    ctx->pc = 0x1445acu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x1445b0: 0x30420001
    ctx->pc = 0x1445b0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x1445b4: 0x0
    ctx->pc = 0x1445b4u;
    // NOP
    // 0x1445b8: 0x0
    ctx->pc = 0x1445b8u;
    // NOP
    // 0x1445bc: 0x1440fffa
    ctx->pc = 0x1445BCu;
    {
        const bool branch_taken_0x1445bc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1445bc) {
            ctx->pc = 0x1445A8u;
            goto label_1445a8;
        }
    }
    ctx->pc = 0x1445C4u;
    // 0x1445c4: 0x16000006
    ctx->pc = 0x1445C4u;
    {
        const bool branch_taken_0x1445c4 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x1445C8u;
        SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 17), 2));
        if (branch_taken_0x1445c4) {
            ctx->pc = 0x1445E0u;
            goto label_1445e0;
        }
    }
    ctx->pc = 0x1445CCu;
    // 0x1445cc: 0x8e450828
    ctx->pc = 0x1445ccu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 2088)));
    // 0x1445d0: 0x240202d
    ctx->pc = 0x1445d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1445d4: 0xc050bee
    ctx->pc = 0x1445D4u;
    SET_GPR_U32(ctx, 31, 0x1445DCu);
    ctx->pc = 0x1445D8u;
    SET_GPR_U32(ctx, 5, SLTU32(GPR_U32(ctx, 5), 1));
    ctx->pc = 0x142FB8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00142FB8_0x142fb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1445DCu; }
    }
    if (ctx->pc != 0x1445DCu) { return; }
    ctx->pc = 0x1445DCu;
    // 0x1445dc: 0x2e220002
    ctx->pc = 0x1445dcu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 17), 2));
label_1445e0:
    // 0x1445e0: 0x10400004
    ctx->pc = 0x1445E0u;
    {
        const bool branch_taken_0x1445e0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1445E4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1445e0) {
            ctx->pc = 0x1445F4u;
            goto label_1445f4;
        }
    }
    ctx->pc = 0x1445E8u;
    // 0x1445e8: 0x3c050024
    ctx->pc = 0x1445e8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x1445ec: 0xc05221c
    ctx->pc = 0x1445ECu;
    SET_GPR_U32(ctx, 31, 0x1445F4u);
    ctx->pc = 0x1445F0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294958624));
    ctx->pc = 0x148870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1445F4u; }
    }
    if (ctx->pc != 0x1445F4u) { return; }
    ctx->pc = 0x1445F4u;
label_1445f4:
    // 0x1445f4: 0x260102d
    ctx->pc = 0x1445f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1445f8:
    // 0x1445f8: 0xdfbf0050
    ctx->pc = 0x1445f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1445fc: 0xdfb40040
    ctx->pc = 0x1445fcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x144600: 0xdfb30030
    ctx->pc = 0x144600u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x144604: 0xdfb20020
    ctx->pc = 0x144604u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x144608: 0xdfb10010
    ctx->pc = 0x144608u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14460c: 0xdfb00000
    ctx->pc = 0x14460cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x144610: 0x3e00008
    ctx->pc = 0x144610u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x144614u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144550u: goto label_144550;
            case 0x144554u: goto label_144554;
            case 0x14459Cu: goto label_14459c;
            case 0x1445A8u: goto label_1445a8;
            case 0x1445E0u: goto label_1445e0;
            case 0x1445F4u: goto label_1445f4;
            case 0x1445F8u: goto label_1445f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x144618u;
}
