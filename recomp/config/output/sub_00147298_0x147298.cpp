#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00147298
// Address: 0x147298 - 0x147508
void sub_00147298_0x147298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x147298u;

    // 0x147298: 0x27bdff90
    ctx->pc = 0x147298u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x14729c: 0x3c031000
    ctx->pc = 0x14729cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1472a0: 0xffb30050
    ctx->pc = 0x1472a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x1472a4: 0x34632010
    ctx->pc = 0x1472a4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x1472a8: 0xffb20040
    ctx->pc = 0x1472a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x1472ac: 0xc0982d
    ctx->pc = 0x1472acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1472b0: 0xffb10030
    ctx->pc = 0x1472b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x1472b4: 0x80902d
    ctx->pc = 0x1472b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1472b8: 0xffb00020
    ctx->pc = 0x1472b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1472bc: 0x138980
    ctx->pc = 0x1472bcu;
    SET_GPR_U32(ctx, 17, SLL32(GPR_U32(ctx, 19), 6));
    // 0x1472c0: 0xffbf0060
    ctx->pc = 0x1472c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1472c4: 0xa0802d
    ctx->pc = 0x1472c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1472c8:
    // 0x1472c8: 0x8c620000
    ctx->pc = 0x1472c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1472cc: 0x0
    ctx->pc = 0x1472ccu;
    // NOP
    // 0x1472d0: 0x0
    ctx->pc = 0x1472d0u;
    // NOP
    // 0x1472d4: 0x0
    ctx->pc = 0x1472d4u;
    // NOP
    // 0x1472d8: 0x0
    ctx->pc = 0x1472d8u;
    // NOP
    // 0x1472dc: 0x440fffa
    ctx->pc = 0x1472DCu;
    {
        const bool branch_taken_0x1472dc = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1472dc) {
            ctx->pc = 0x1472C8u;
            goto label_1472c8;
        }
    }
    ctx->pc = 0x1472E4u;
    // 0x1472e4: 0xc047598
    ctx->pc = 0x1472E4u;
    SET_GPR_U32(ctx, 31, 0x1472ECu);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1472ECu; }
    }
    if (ctx->pc != 0x1472ECu) { return; }
    ctx->pc = 0x1472ECu;
    // 0x1472ec: 0x3c030fff
    ctx->pc = 0x1472ecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4095 << 16));
    // 0x1472f0: 0x3c051000
    ctx->pc = 0x1472f0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x1472f4: 0x3463ffff
    ctx->pc = 0x1472f4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
    // 0x1472f8: 0x34a5b010
    ctx->pc = 0x1472f8u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 45072));
    // 0x1472fc: 0x2031824
    ctx->pc = 0x1472fcu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x147300: 0x3c041000
    ctx->pc = 0x147300u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x147304: 0xaca30000
    ctx->pc = 0x147304u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x147308: 0x3484b020
    ctx->pc = 0x147308u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45088));
    // 0x14730c: 0xac910000
    ctx->pc = 0x14730cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 17)); // MMIO: 0x10000000
    // 0x147310: 0x3c031000
    ctx->pc = 0x147310u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x147314: 0x3463b000
    ctx->pc = 0x147314u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 45056));
    // 0x147318: 0x24040100
    ctx->pc = 0x147318u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 256));
    // 0x14731c: 0xac640000
    ctx->pc = 0x14731cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x147320: 0x50400004
    ctx->pc = 0x147320u;
    {
        const bool branch_taken_0x147320 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x147320) {
            ctx->pc = 0x147324u;
            SET_GPR_U32(ctx, 5, ((uint32_t)28672 << 16));
            ctx->pc = 0x147334u;
            goto label_147334;
        }
    }
    ctx->pc = 0x147328u;
    // 0x147328: 0xc0475ae
    ctx->pc = 0x147328u;
    SET_GPR_U32(ctx, 31, 0x147330u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147330u; }
    }
    if (ctx->pc != 0x147330u) { return; }
    ctx->pc = 0x147330u;
    // 0x147330: 0x3c057000
    ctx->pc = 0x147330u;
    SET_GPR_U32(ctx, 5, ((uint32_t)28672 << 16));
label_147334:
    // 0x147334: 0x240202d
    ctx->pc = 0x147334u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147338: 0xc05148a
    ctx->pc = 0x147338u;
    SET_GPR_U32(ctx, 31, 0x147340u);
    ctx->pc = 0x14733Cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
    ctx->pc = 0x145228u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147340u; }
    }
    if (ctx->pc != 0x147340u) { return; }
    ctx->pc = 0x147340u;
    // 0x147340: 0x8e440870
    ctx->pc = 0x147340u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 2160)));
    // 0x147344: 0x24020004
    ctx->pc = 0x147344u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x147348: 0xafa20000
    ctx->pc = 0x147348u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x14734c: 0xc051fda
    ctx->pc = 0x14734Cu;
    SET_GPR_U32(ctx, 31, 0x147354u);
    ctx->pc = 0x147350u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x147F68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147354u; }
    }
    if (ctx->pc != 0x147354u) { return; }
    ctx->pc = 0x147354u;
    // 0x147354: 0x3c031000
    ctx->pc = 0x147354u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x147358: 0x3463b000
    ctx->pc = 0x147358u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 45056));
    // 0x14735c: 0x0
    ctx->pc = 0x14735cu;
    // NOP
label_147360:
    // 0x147360: 0x8c620000
    ctx->pc = 0x147360u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x147364: 0x21202
    ctx->pc = 0x147364u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x147368: 0x30420001
    ctx->pc = 0x147368u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x14736c: 0x0
    ctx->pc = 0x14736cu;
    // NOP
    // 0x147370: 0x0
    ctx->pc = 0x147370u;
    // NOP
    // 0x147374: 0x1440fffa
    ctx->pc = 0x147374u;
    {
        const bool branch_taken_0x147374 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x147374) {
            ctx->pc = 0x147360u;
            goto label_147360;
        }
    }
    ctx->pc = 0x14737Cu;
    // 0x14737c: 0x3c031000
    ctx->pc = 0x14737cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x147380: 0x34632010
    ctx->pc = 0x147380u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x147384: 0x0
    ctx->pc = 0x147384u;
    // NOP
label_147388:
    // 0x147388: 0x8c620000
    ctx->pc = 0x147388u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x14738c: 0x0
    ctx->pc = 0x14738cu;
    // NOP
    // 0x147390: 0x0
    ctx->pc = 0x147390u;
    // NOP
    // 0x147394: 0x0
    ctx->pc = 0x147394u;
    // NOP
    // 0x147398: 0x0
    ctx->pc = 0x147398u;
    // NOP
    // 0x14739c: 0x440fffa
    ctx->pc = 0x14739Cu;
    {
        const bool branch_taken_0x14739c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x14739c) {
            ctx->pc = 0x147388u;
            goto label_147388;
        }
    }
    ctx->pc = 0x1473A4u;
    // 0x1473a4: 0xdfbf0060
    ctx->pc = 0x1473a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1473a8: 0xdfb30050
    ctx->pc = 0x1473a8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1473ac: 0xdfb20040
    ctx->pc = 0x1473acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1473b0: 0xdfb10030
    ctx->pc = 0x1473b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1473b4: 0xdfb00020
    ctx->pc = 0x1473b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1473b8: 0x3e00008
    ctx->pc = 0x1473B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1473BCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1472C8u: goto label_1472c8;
            case 0x147334u: goto label_147334;
            case 0x147360u: goto label_147360;
            case 0x147388u: goto label_147388;
            case 0x14740Cu: goto label_14740c;
            case 0x147420u: goto label_147420;
            case 0x147494u: goto label_147494;
            case 0x1474F8u: goto label_1474f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1473C0u;
    // 0x1473c0: 0x3c021000
    ctx->pc = 0x1473c0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1473c4: 0x24030008
    ctx->pc = 0x1473c4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
    // 0x1473c8: 0x3442e010
    ctx->pc = 0x1473c8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57360));
    // 0x1473cc: 0xa0482d
    ctx->pc = 0x1473ccu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1473d0: 0xac430000
    ctx->pc = 0x1473d0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1473d4: 0x3c041000
    ctx->pc = 0x1473d4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1473d8: 0x3484b020
    ctx->pc = 0x1473d8u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45088));
    // 0x1473dc: 0x8d220000
    ctx->pc = 0x1473dcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1473e0: 0x24420001
    ctx->pc = 0x1473e0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1473e4: 0xad220000
    ctx->pc = 0x1473e4u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 2));
    // 0x1473e8: 0x8c830000
    ctx->pc = 0x1473e8u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x1473ec: 0x14600007
    ctx->pc = 0x1473ECu;
    {
        const bool branch_taken_0x1473ec = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1473F0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1473ec) {
            ctx->pc = 0x14740Cu;
            goto label_14740c;
        }
    }
    ctx->pc = 0x1473F4u;
    // 0x1473f4: 0x3c021000
    ctx->pc = 0x1473f4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1473f8: 0x3442b000
    ctx->pc = 0x1473f8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 45056));
    // 0x1473fc: 0x8c430000
    ctx->pc = 0x1473fcu;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x147400: 0x30630100
    ctx->pc = 0x147400u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 256));
    // 0x147404: 0x10600006
    ctx->pc = 0x147404u;
    {
        const bool branch_taken_0x147404 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x147408u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x147404) {
            ctx->pc = 0x147420u;
            goto label_147420;
        }
    }
    ctx->pc = 0x14740Cu;
label_14740c:
    // 0x14740c: 0xad220004
    ctx->pc = 0x14740cu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 4), GPR_U32(ctx, 2));
    // 0x147410: 0xf
    ctx->pc = 0x147410u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x147414: 0x42000038
    ctx->pc = 0x147414u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x147418: 0x3e00008
    ctx->pc = 0x147418u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14741Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1472C8u: goto label_1472c8;
            case 0x147334u: goto label_147334;
            case 0x147360u: goto label_147360;
            case 0x147388u: goto label_147388;
            case 0x14740Cu: goto label_14740c;
            case 0x147420u: goto label_147420;
            case 0x147494u: goto label_147494;
            case 0x1474F8u: goto label_1474f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147420u;
label_147420:
    // 0x147420: 0x8d230010
    ctx->pc = 0x147420u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x147424: 0x8d220000
    ctx->pc = 0x147424u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x147428: 0x2463ffff
    ctx->pc = 0x147428u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x14742c: 0x43102a
    ctx->pc = 0x14742cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 3)));
    // 0x147430: 0x10400018
    ctx->pc = 0x147430u;
    {
        const bool branch_taken_0x147430 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x147434u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x147430) {
            ctx->pc = 0x147494u;
            goto label_147494;
        }
    }
    ctx->pc = 0x147438u;
    // 0x147438: 0x8d23000c
    ctx->pc = 0x147438u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x14743c: 0x3442b010
    ctx->pc = 0x14743cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 45072));
    // 0x147440: 0x3404ffc0
    ctx->pc = 0x147440u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 0), 65472));
    // 0x147444: 0xac430000
    ctx->pc = 0x147444u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x147448: 0x24050100
    ctx->pc = 0x147448u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 256));
    // 0x14744c: 0x3c011001
    ctx->pc = 0x14744cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x147450: 0xac24b020
    ctx->pc = 0x147450u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946848), GPR_U32(ctx, 4)); // MMIO: 0x1000b020
    // 0x147454: 0x3c031000
    ctx->pc = 0x147454u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x147458: 0x3c027000
    ctx->pc = 0x147458u;
    SET_GPR_U32(ctx, 2, ((uint32_t)28672 << 16));
    // 0x14745c: 0x3c011001
    ctx->pc = 0x14745cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x147460: 0xac25b000
    ctx->pc = 0x147460u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946816), GPR_U32(ctx, 5)); // MMIO: 0x1000b000
    // 0x147464: 0x34632000
    ctx->pc = 0x147464u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8192));
    // 0x147468: 0x344203ff
    ctx->pc = 0x147468u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 1023));
    // 0x14746c: 0xac620000
    ctx->pc = 0x14746cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x147470: 0x3c04000f
    ctx->pc = 0x147470u;
    SET_GPR_U32(ctx, 4, ((uint32_t)15 << 16));
    // 0x147474: 0x3484fc00
    ctx->pc = 0x147474u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 64512));
    // 0x147478: 0x3c030fff
    ctx->pc = 0x147478u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4095 << 16));
    // 0x14747c: 0x8d22000c
    ctx->pc = 0x14747cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x147480: 0x3463ffff
    ctx->pc = 0x147480u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
    // 0x147484: 0x441021
    ctx->pc = 0x147484u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x147488: 0x431024
    ctx->pc = 0x147488u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x14748c: 0x1000001a
    ctx->pc = 0x14748Cu;
    {
        const bool branch_taken_0x14748c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x147490u;
        WRITE32(ADD32(GPR_U32(ctx, 9), 12), GPR_U32(ctx, 2));
        if (branch_taken_0x14748c) {
            ctx->pc = 0x1474F8u;
            goto label_1474f8;
        }
    }
    ctx->pc = 0x147494u;
label_147494:
    // 0x147494: 0x8d220000
    ctx->pc = 0x147494u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x147498: 0x14430017
    ctx->pc = 0x147498u;
    {
        const bool branch_taken_0x147498 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x14749Cu;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 256));
        if (branch_taken_0x147498) {
            ctx->pc = 0x1474F8u;
            goto label_1474f8;
        }
    }
    ctx->pc = 0x1474A0u;
    // 0x1474a0: 0x8d250000
    ctx->pc = 0x1474a0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1474a4: 0x3c041000
    ctx->pc = 0x1474a4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1474a8: 0x8d230008
    ctx->pc = 0x1474a8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1474ac: 0x3484b010
    ctx->pc = 0x1474acu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45072));
    // 0x1474b0: 0x51280
    ctx->pc = 0x1474b0u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 10));
    // 0x1474b4: 0x8d26000c
    ctx->pc = 0x1474b4u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x1474b8: 0x451023
    ctx->pc = 0x1474b8u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1474bc: 0x621823
    ctx->pc = 0x1474bcu;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1474c0: 0x3c051000
    ctx->pc = 0x1474c0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x1474c4: 0xad230008
    ctx->pc = 0x1474c4u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 8), GPR_U32(ctx, 3));
    // 0x1474c8: 0x3c077000
    ctx->pc = 0x1474c8u;
    SET_GPR_U32(ctx, 7, ((uint32_t)28672 << 16));
    // 0x1474cc: 0xac860000
    ctx->pc = 0x1474ccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
    // 0x1474d0: 0x34a52000
    ctx->pc = 0x1474d0u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 8192));
    // 0x1474d4: 0x8d220008
    ctx->pc = 0x1474d4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1474d8: 0x21180
    ctx->pc = 0x1474d8u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 6));
    // 0x1474dc: 0x3c011001
    ctx->pc = 0x1474dcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x1474e0: 0xac22b020
    ctx->pc = 0x1474e0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946848), GPR_U32(ctx, 2)); // MMIO: 0x1000b020
    // 0x1474e4: 0x3c011001
    ctx->pc = 0x1474e4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x1474e8: 0xac28b000
    ctx->pc = 0x1474e8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294946816), GPR_U32(ctx, 8)); // MMIO: 0x1000b000
    // 0x1474ec: 0x8d220008
    ctx->pc = 0x1474ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1474f0: 0x471025
    ctx->pc = 0x1474f0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1474f4: 0xaca20000
    ctx->pc = 0x1474f4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_1474f8:
    // 0x1474f8: 0xf
    ctx->pc = 0x1474f8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1474fc: 0x42000038
    ctx->pc = 0x1474fcu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x147500: 0x3e00008
    ctx->pc = 0x147500u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147504u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1472C8u: goto label_1472c8;
            case 0x147334u: goto label_147334;
            case 0x147360u: goto label_147360;
            case 0x147388u: goto label_147388;
            case 0x14740Cu: goto label_14740c;
            case 0x147420u: goto label_147420;
            case 0x147494u: goto label_147494;
            case 0x1474F8u: goto label_1474f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147508u;
}
