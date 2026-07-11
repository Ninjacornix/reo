#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001453C0
// Address: 0x1453c0 - 0x145548
void sub_001453C0_0x1453c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1453c0u;

    // 0x1453c0: 0x27bdff40
    ctx->pc = 0x1453c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1453c4: 0x3c021000
    ctx->pc = 0x1453c4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1453c8: 0xffbf00b0
    ctx->pc = 0x1453c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x1453cc: 0x34422000
    ctx->pc = 0x1453ccu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x1453d0: 0xffbe00a0
    ctx->pc = 0x1453d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 30));
    // 0x1453d4: 0x80282d
    ctx->pc = 0x1453d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1453d8: 0xffb70090
    ctx->pc = 0x1453d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 23));
    // 0x1453dc: 0x202d
    ctx->pc = 0x1453dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1453e0: 0xffb60080
    ctx->pc = 0x1453e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x1453e4: 0xffb50070
    ctx->pc = 0x1453e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x1453e8: 0xffb30050
    ctx->pc = 0x1453e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x1453ec: 0xffb20040
    ctx->pc = 0x1453ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x1453f0: 0xffb10030
    ctx->pc = 0x1453f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x1453f4: 0xffb00020
    ctx->pc = 0x1453f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1453f8: 0xffb40060
    ctx->pc = 0x1453f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x1453fc: 0xdc540000
    ctx->pc = 0x1453fcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x145400: 0x6810044
    ctx->pc = 0x145400u;
    {
        const bool branch_taken_0x145400 = (GPR_S32(ctx, 20) >= 0);
        ctx->pc = 0x145404u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145400) {
            ctx->pc = 0x145514u;
            goto label_145514;
        }
    }
    ctx->pc = 0x145408u;
    // 0x145408: 0x3c021000
    ctx->pc = 0x145408u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x14540c: 0x34422010
    ctx->pc = 0x14540cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x145410: 0x8c430000
    ctx->pc = 0x145410u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x145414: 0x30634000
    ctx->pc = 0x145414u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 16384));
    // 0x145418: 0x1460003e
    ctx->pc = 0x145418u;
    {
        const bool branch_taken_0x145418 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x14541Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145418) {
            ctx->pc = 0x145514u;
            goto label_145514;
        }
    }
    ctx->pc = 0x145420u;
    // 0x145420: 0x3c021000
    ctx->pc = 0x145420u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x145424: 0x3c131000
    ctx->pc = 0x145424u;
    SET_GPR_U32(ctx, 19, ((uint32_t)4096 << 16));
    // 0x145428: 0xafa20000
    ctx->pc = 0x145428u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x14542c: 0x3c111000
    ctx->pc = 0x14542cu;
    SET_GPR_U32(ctx, 17, ((uint32_t)4096 << 16));
    // 0x145430: 0x3442b420
    ctx->pc = 0x145430u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46112));
    // 0x145434: 0x3c151000
    ctx->pc = 0x145434u;
    SET_GPR_U32(ctx, 21, ((uint32_t)4096 << 16));
    // 0x145438: 0x3c161000
    ctx->pc = 0x145438u;
    SET_GPR_U32(ctx, 22, ((uint32_t)4096 << 16));
    // 0x14543c: 0x3c17fffe
    ctx->pc = 0x14543cu;
    SET_GPR_U32(ctx, 23, ((uint32_t)65534 << 16));
    // 0x145440: 0x3c1e1000
    ctx->pc = 0x145440u;
    SET_GPR_U32(ctx, 30, ((uint32_t)4096 << 16));
    // 0x145444: 0x3c121000
    ctx->pc = 0x145444u;
    SET_GPR_U32(ctx, 18, ((uint32_t)4096 << 16));
    // 0x145448: 0x3c101000
    ctx->pc = 0x145448u;
    SET_GPR_U32(ctx, 16, ((uint32_t)4096 << 16));
    // 0x14544c: 0xafa20000
    ctx->pc = 0x14544cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x145450: 0x3673f590
    ctx->pc = 0x145450u;
    SET_GPR_U32(ctx, 19, OR32(GPR_U32(ctx, 19), 62864));
    // 0x145454: 0x3631f520
    ctx->pc = 0x145454u;
    SET_GPR_U32(ctx, 17, OR32(GPR_U32(ctx, 17), 62752));
    // 0x145458: 0x36b5b400
    ctx->pc = 0x145458u;
    SET_GPR_U32(ctx, 21, OR32(GPR_U32(ctx, 21), 46080));
    // 0x14545c: 0x36d6b000
    ctx->pc = 0x14545cu;
    SET_GPR_U32(ctx, 22, OR32(GPR_U32(ctx, 22), 45056));
    // 0x145460: 0x36f7ffff
    ctx->pc = 0x145460u;
    SET_GPR_U32(ctx, 23, OR32(GPR_U32(ctx, 23), 65535));
    // 0x145464: 0x37deb020
    ctx->pc = 0x145464u;
    SET_GPR_U32(ctx, 30, OR32(GPR_U32(ctx, 30), 45088));
    // 0x145468: 0x36522010
    ctx->pc = 0x145468u;
    SET_GPR_U32(ctx, 18, OR32(GPR_U32(ctx, 18), 8208));
    // 0x14546c: 0x36102000
    ctx->pc = 0x14546cu;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 16), 8192));
    // 0x145470: 0x8ca210a0
    ctx->pc = 0x145470u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 4256)));
    // 0x145474: 0x0
    ctx->pc = 0x145474u;
    // NOP
label_145478:
    // 0x145478: 0x10400016
    ctx->pc = 0x145478u;
    {
        const bool branch_taken_0x145478 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x14547Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145478) {
            ctx->pc = 0x1454D4u;
            goto label_1454d4;
        }
    }
    ctx->pc = 0x145480u;
    // 0x145480: 0xc047598
    ctx->pc = 0x145480u;
    SET_GPR_U32(ctx, 31, 0x145488u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145488u; }
    }
    if (ctx->pc != 0x145488u) { return; }
    ctx->pc = 0x145488u;
    // 0x145488: 0x8e230000
    ctx->pc = 0x145488u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14548c: 0x3c040001
    ctx->pc = 0x14548cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x145490: 0x641825
    ctx->pc = 0x145490u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x145494: 0xae630000
    ctx->pc = 0x145494u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x145498: 0xaea00000
    ctx->pc = 0x145498u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x14549c: 0xaec00000
    ctx->pc = 0x14549cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 0));
    // 0x1454a0: 0x8e230000
    ctx->pc = 0x1454a0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1454a4: 0x771824
    ctx->pc = 0x1454a4u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 23)));
    // 0x1454a8: 0x10400003
    ctx->pc = 0x1454A8u;
    {
        const bool branch_taken_0x1454a8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1454ACu;
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        if (branch_taken_0x1454a8) {
            ctx->pc = 0x1454B8u;
            goto label_1454b8;
        }
    }
    ctx->pc = 0x1454B0u;
    // 0x1454b0: 0xc0475ae
    ctx->pc = 0x1454B0u;
    SET_GPR_U32(ctx, 31, 0x1454B8u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1454B8u; }
    }
    if (ctx->pc != 0x1454B8u) { return; }
    ctx->pc = 0x1454B8u;
label_1454b8:
    // 0x1454b8: 0xafc00000
    ctx->pc = 0x1454b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
    // 0x1454bc: 0x3c044000
    ctx->pc = 0x1454bcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)16384 << 16));
    // 0x1454c0: 0x8fa20000
    ctx->pc = 0x1454c0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1454c4: 0xac400000
    ctx->pc = 0x1454c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1454c8: 0xae440000
    ctx->pc = 0x1454c8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x1454cc: 0x10000011
    ctx->pc = 0x1454CCu;
    {
        const bool branch_taken_0x1454cc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1454D0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1454cc) {
            ctx->pc = 0x145514u;
            goto label_145514;
        }
    }
    ctx->pc = 0x1454D4u;
label_1454d4:
    // 0x1454d4: 0x28421389
    ctx->pc = 0x1454d4u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 5001));
    // 0x1454d8: 0x14400006
    ctx->pc = 0x1454D8u;
    {
        const bool branch_taken_0x1454d8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1454DCu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x1454d8) {
            ctx->pc = 0x1454F4u;
            goto label_1454f4;
        }
    }
    ctx->pc = 0x1454E0u;
    // 0x1454e0: 0x8ca40870
    ctx->pc = 0x1454e0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 5), 2160)));
    // 0x1454e4: 0xc051ff8
    ctx->pc = 0x1454E4u;
    SET_GPR_U32(ctx, 31, 0x1454ECu);
    ctx->pc = 0x1454E8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 5));
    ctx->pc = 0x147FE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1454ECu; }
    }
    if (ctx->pc != 0x1454ECu) { return; }
    ctx->pc = 0x1454ECu;
    // 0x1454ec: 0x7ba50010
    ctx->pc = 0x1454ecu;
    SET_GPR_VEC(ctx, 5, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1454f0: 0x202d
    ctx->pc = 0x1454f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1454f4:
    // 0x1454f4: 0xde140000
    ctx->pc = 0x1454f4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1454f8: 0x6810006
    ctx->pc = 0x1454F8u;
    {
        const bool branch_taken_0x1454f8 = (GPR_S32(ctx, 20) >= 0);
        ctx->pc = 0x1454FCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1454f8) {
            ctx->pc = 0x145514u;
            goto label_145514;
        }
    }
    ctx->pc = 0x145500u;
    // 0x145500: 0x8e420000
    ctx->pc = 0x145500u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x145504: 0x30424000
    ctx->pc = 0x145504u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 16384));
    // 0x145508: 0x5040ffdb
    ctx->pc = 0x145508u;
    {
        const bool branch_taken_0x145508 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x145508) {
            ctx->pc = 0x14550Cu;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 4256)));
            ctx->pc = 0x145478u;
            goto label_145478;
        }
    }
    ctx->pc = 0x145510u;
    // 0x145510: 0x280102d
    ctx->pc = 0x145510u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_145514:
    // 0x145514: 0xdfbf00b0
    ctx->pc = 0x145514u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x145518: 0xdfbe00a0
    ctx->pc = 0x145518u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x14551c: 0xdfb70090
    ctx->pc = 0x14551cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x145520: 0xdfb60080
    ctx->pc = 0x145520u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x145524: 0xdfb50070
    ctx->pc = 0x145524u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x145528: 0xdfb40060
    ctx->pc = 0x145528u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x14552c: 0xdfb30050
    ctx->pc = 0x14552cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x145530: 0xdfb20040
    ctx->pc = 0x145530u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x145534: 0xdfb10030
    ctx->pc = 0x145534u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x145538: 0xdfb00020
    ctx->pc = 0x145538u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14553c: 0x3e00008
    ctx->pc = 0x14553Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145540u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 192));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145478u: goto label_145478;
            case 0x1454B8u: goto label_1454b8;
            case 0x1454D4u: goto label_1454d4;
            case 0x1454F4u: goto label_1454f4;
            case 0x145514u: goto label_145514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145544u;
    // 0x145544: 0x0
    ctx->pc = 0x145544u;
    // NOP
}
