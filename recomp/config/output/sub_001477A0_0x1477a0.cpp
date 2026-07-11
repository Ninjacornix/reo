#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001477A0
// Address: 0x1477a0 - 0x147a28
void sub_001477A0_0x1477a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1477a0u;

    // 0x1477a0: 0x27bdff60
    ctx->pc = 0x1477a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1477a4: 0x24060002
    ctx->pc = 0x1477a4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
    // 0x1477a8: 0xffb30060
    ctx->pc = 0x1477a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 19));
    // 0x1477ac: 0xffb20050
    ctx->pc = 0x1477acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x1477b0: 0xffb00030
    ctx->pc = 0x1477b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x1477b4: 0xa0902d
    ctx->pc = 0x1477b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1477b8: 0xffbf0090
    ctx->pc = 0x1477b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1477bc: 0x80802d
    ctx->pc = 0x1477bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1477c0: 0xffb50080
    ctx->pc = 0x1477c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 21));
    // 0x1477c4: 0x3a0282d
    ctx->pc = 0x1477c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1477c8: 0xffb40070
    ctx->pc = 0x1477c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 20));
    // 0x1477cc: 0xffb10040
    ctx->pc = 0x1477ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 17));
    // 0x1477d0: 0x8e43000c
    ctx->pc = 0x1477d0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1477d4: 0x8e420010
    ctx->pc = 0x1477d4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1477d8: 0x8e040870
    ctx->pc = 0x1477d8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x1477dc: 0x629818
    ctx->pc = 0x1477dcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 19, (int32_t)(uint32_t)result); }
    // 0x1477e0: 0xc051fda
    ctx->pc = 0x1477E0u;
    SET_GPR_U32(ctx, 31, 0x1477E8u);
    ctx->pc = 0x1477E4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    ctx->pc = 0x147F68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1477E8u; }
    }
    if (ctx->pc != 0x1477E8u) { return; }
    ctx->pc = 0x1477E8u;
    // 0x1477e8: 0x3c031000
    ctx->pc = 0x1477e8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1477ec: 0x34632010
    ctx->pc = 0x1477ecu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x1477f0: 0x8c620000
    ctx->pc = 0x1477f0u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1477f4: 0x30424000
    ctx->pc = 0x1477f4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 16384));
    // 0x1477f8: 0x10400003
    ctx->pc = 0x1477F8u;
    {
        const bool branch_taken_0x1477f8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1477FCu;
        SET_GPR_U32(ctx, 2, ((uint32_t)16384 << 16));
        if (branch_taken_0x1477f8) {
            ctx->pc = 0x147808u;
            goto label_147808;
        }
    }
    ctx->pc = 0x147800u;
    // 0x147800: 0x3c011000
    ctx->pc = 0x147800u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x147804: 0xac222010
    ctx->pc = 0x147804u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 2)); // MMIO: 0x10002010
label_147808:
    // 0x147808: 0x3c031000
    ctx->pc = 0x147808u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x14780c: 0x2a750400
    ctx->pc = 0x14780cu;
    SET_GPR_U32(ctx, 21, SLT32(GPR_S32(ctx, 19), 1024));
    // 0x147810: 0x34632010
    ctx->pc = 0x147810u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x147814: 0x0
    ctx->pc = 0x147814u;
    // NOP
label_147818:
    // 0x147818: 0x8c620000
    ctx->pc = 0x147818u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x14781c: 0x0
    ctx->pc = 0x14781cu;
    // NOP
    // 0x147820: 0x0
    ctx->pc = 0x147820u;
    // NOP
    // 0x147824: 0x0
    ctx->pc = 0x147824u;
    // NOP
    // 0x147828: 0x0
    ctx->pc = 0x147828u;
    // NOP
    // 0x14782c: 0x440fffa
    ctx->pc = 0x14782Cu;
    {
        const bool branch_taken_0x14782c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x14782c) {
            ctx->pc = 0x147818u;
            goto label_147818;
        }
    }
    ctx->pc = 0x147834u;
    // 0x147834: 0x200202d
    ctx->pc = 0x147834u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147838: 0xc05148a
    ctx->pc = 0x147838u;
    SET_GPR_U32(ctx, 31, 0x147840u);
    ctx->pc = 0x14783Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x145228u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147840u; }
    }
    if (ctx->pc != 0x147840u) { return; }
    ctx->pc = 0x147840u;
    // 0x147840: 0x3c041000
    ctx->pc = 0x147840u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x147844: 0x8e430000
    ctx->pc = 0x147844u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x147848: 0x34842010
    ctx->pc = 0x147848u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 8208));
    // 0x14784c: 0x0
    ctx->pc = 0x14784cu;
    // NOP
label_147850:
    // 0x147850: 0x8c820000
    ctx->pc = 0x147850u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x147854: 0x0
    ctx->pc = 0x147854u;
    // NOP
    // 0x147858: 0x0
    ctx->pc = 0x147858u;
    // NOP
    // 0x14785c: 0x0
    ctx->pc = 0x14785cu;
    // NOP
    // 0x147860: 0x0
    ctx->pc = 0x147860u;
    // NOP
    // 0x147864: 0x440fffa
    ctx->pc = 0x147864u;
    {
        const bool branch_taken_0x147864 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x147864) {
            ctx->pc = 0x147850u;
            goto label_147850;
        }
    }
    ctx->pc = 0x14786Cu;
    // 0x14786c: 0x24020018
    ctx->pc = 0x14786cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 24));
    // 0x147870: 0x3c110fff
    ctx->pc = 0x147870u;
    SET_GPR_U32(ctx, 17, ((uint32_t)4095 << 16));
    // 0x147874: 0x2621018
    ctx->pc = 0x147874u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x147878: 0x3631ffff
    ctx->pc = 0x147878u;
    SET_GPR_U32(ctx, 17, OR32(GPR_U32(ctx, 17), 65535));
    // 0x14787c: 0x711824
    ctx->pc = 0x14787cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x147880: 0x3414ffff
    ctx->pc = 0x147880u;
    SET_GPR_U32(ctx, 20, OR32(GPR_U32(ctx, 0), 65535));
    // 0x147884: 0xafa30024
    ctx->pc = 0x147884u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 3));
    // 0x147888: 0x282202b
    ctx->pc = 0x147888u;
    SET_GPR_U32(ctx, 4, SLTU32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x14788c: 0x1080003a
    ctx->pc = 0x14788Cu;
    {
        const bool branch_taken_0x14788c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x147890u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
        if (branch_taken_0x14788c) {
            ctx->pc = 0x147978u;
            goto label_147978;
        }
    }
    ctx->pc = 0x147894u;
    // 0x147894: 0x3c050014
    ctx->pc = 0x147894u;
    SET_GPR_U32(ctx, 5, ((uint32_t)20 << 16));
    // 0x147898: 0x24040004
    ctx->pc = 0x147898u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    // 0x14789c: 0x24a576c8
    ctx->pc = 0x14789cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 30408));
    // 0x1478a0: 0x302d
    ctx->pc = 0x1478a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1478a4: 0xc0450d0
    ctx->pc = 0x1478A4u;
    SET_GPR_U32(ctx, 31, 0x1478ACu);
    ctx->pc = 0x1478A8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x114340u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114340_0x114340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1478ACu; }
    }
    if (ctx->pc != 0x1478ACu) { return; }
    ctx->pc = 0x1478ACu;
    // 0x1478ac: 0x40902d
    ctx->pc = 0x1478acu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1478b0: 0x24030010
    ctx->pc = 0x1478b0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
    // 0x1478b4: 0x3c021000
    ctx->pc = 0x1478b4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1478b8: 0x24040004
    ctx->pc = 0x1478b8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    // 0x1478bc: 0x3442e010
    ctx->pc = 0x1478bcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57360));
    // 0x1478c0: 0xc04548e
    ctx->pc = 0x1478C0u;
    SET_GPR_U32(ctx, 31, 0x1478C8u);
    ctx->pc = 0x1478C4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x115238u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00115238_0x115238(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1478C8u; }
    }
    if (ctx->pc != 0x1478C8u) { return; }
    ctx->pc = 0x1478C8u;
    // 0x1478c8: 0xc047598
    ctx->pc = 0x1478C8u;
    SET_GPR_U32(ctx, 31, 0x1478D0u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1478D0u; }
    }
    if (ctx->pc != 0x1478D0u) { return; }
    ctx->pc = 0x1478D0u;
    // 0x1478d0: 0x8fa50024
    ctx->pc = 0x1478d0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1478d4: 0x3c031000
    ctx->pc = 0x1478d4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1478d8: 0x3463b410
    ctx->pc = 0x1478d8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46096));
    // 0x1478dc: 0x3c041000
    ctx->pc = 0x1478dcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1478e0: 0xac650000
    ctx->pc = 0x1478e0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x1478e4: 0x3484b420
    ctx->pc = 0x1478e4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46112));
    // 0x1478e8: 0xac940000
    ctx->pc = 0x1478e8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 20)); // MMIO: 0x10000000
    // 0x1478ec: 0x3c031000
    ctx->pc = 0x1478ecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1478f0: 0x3463b400
    ctx->pc = 0x1478f0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46080));
    // 0x1478f4: 0x24040101
    ctx->pc = 0x1478f4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 257));
    // 0x1478f8: 0xac640000
    ctx->pc = 0x1478f8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x1478fc: 0x10400004
    ctx->pc = 0x1478FCu;
    {
        const bool branch_taken_0x1478fc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x147900u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 36)));
        if (branch_taken_0x1478fc) {
            ctx->pc = 0x147910u;
            goto label_147910;
        }
    }
    ctx->pc = 0x147904u;
    // 0x147904: 0xc0475ae
    ctx->pc = 0x147904u;
    SET_GPR_U32(ctx, 31, 0x14790Cu);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14790Cu; }
    }
    if (ctx->pc != 0x14790Cu) { return; }
    ctx->pc = 0x14790Cu;
    // 0x14790c: 0x8fa20024
    ctx->pc = 0x14790cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_147910:
    // 0x147910: 0x3c03000f
    ctx->pc = 0x147910u;
    SET_GPR_U32(ctx, 3, ((uint32_t)15 << 16));
    // 0x147914: 0x8fa40020
    ctx->pc = 0x147914u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x147918: 0x3463fff0
    ctx->pc = 0x147918u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65520));
    // 0x14791c: 0x431021
    ctx->pc = 0x14791cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x147920: 0x511024
    ctx->pc = 0x147920u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x147924: 0x942023
    ctx->pc = 0x147924u;
    SET_GPR_U32(ctx, 4, SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 20)));
    // 0x147928: 0xafa20024
    ctx->pc = 0x147928u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
    // 0x14792c: 0x12a00007
    ctx->pc = 0x14792Cu;
    {
        const bool branch_taken_0x14792c = (GPR_U32(ctx, 21) == GPR_U32(ctx, 0));
        ctx->pc = 0x147930u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 4));
        if (branch_taken_0x14792c) {
            ctx->pc = 0x14794Cu;
            goto label_14794c;
        }
    }
    ctx->pc = 0x147934u;
    // 0x147934: 0x8e0500f0
    ctx->pc = 0x147934u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x147938: 0x260302d
    ctx->pc = 0x147938u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14793c: 0xc051ca6
    ctx->pc = 0x14793Cu;
    SET_GPR_U32(ctx, 31, 0x147944u);
    ctx->pc = 0x147940u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x147298u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147298_0x147298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147944u; }
    }
    if (ctx->pc != 0x147944u) { return; }
    ctx->pc = 0x147944u;
    // 0x147944: 0x10000005
    ctx->pc = 0x147944u;
    {
        const bool branch_taken_0x147944 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x147944) {
            ctx->pc = 0x14795Cu;
            goto label_14795c;
        }
    }
    ctx->pc = 0x14794Cu;
label_14794c:
    // 0x14794c: 0x8e0500f0
    ctx->pc = 0x14794cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x147950: 0x260302d
    ctx->pc = 0x147950u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147954: 0xc051d42
    ctx->pc = 0x147954u;
    SET_GPR_U32(ctx, 31, 0x14795Cu);
    ctx->pc = 0x147958u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x147508u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147508_0x147508(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14795Cu; }
    }
    if (ctx->pc != 0x14795Cu) { return; }
    ctx->pc = 0x14795Cu;
label_14795c:
    // 0x14795c: 0xc045474
    ctx->pc = 0x14795Cu;
    SET_GPR_U32(ctx, 31, 0x147964u);
    ctx->pc = 0x147960u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x1151D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001151D0_0x1151d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147964u; }
    }
    if (ctx->pc != 0x147964u) { return; }
    ctx->pc = 0x147964u;
    // 0x147964: 0x240282d
    ctx->pc = 0x147964u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147968: 0xc0450d4
    ctx->pc = 0x147968u;
    SET_GPR_U32(ctx, 31, 0x147970u);
    ctx->pc = 0x14796Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x114350u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114350_0x114350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147970u; }
    }
    if (ctx->pc != 0x147970u) { return; }
    ctx->pc = 0x147970u;
    // 0x147970: 0x10000020
    ctx->pc = 0x147970u;
    {
        const bool branch_taken_0x147970 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x147974u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2160)));
        if (branch_taken_0x147970) {
            ctx->pc = 0x1479F4u;
            goto label_1479f4;
        }
    }
    ctx->pc = 0x147978u;
label_147978:
    // 0x147978: 0xc047598
    ctx->pc = 0x147978u;
    SET_GPR_U32(ctx, 31, 0x147980u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147980u; }
    }
    if (ctx->pc != 0x147980u) { return; }
    ctx->pc = 0x147980u;
    // 0x147980: 0x8e450000
    ctx->pc = 0x147980u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x147984: 0x3c031000
    ctx->pc = 0x147984u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x147988: 0x3463b410
    ctx->pc = 0x147988u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46096));
    // 0x14798c: 0x3c061000
    ctx->pc = 0x14798cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x147990: 0xb12824
    ctx->pc = 0x147990u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 17)));
    // 0x147994: 0x34c6b420
    ctx->pc = 0x147994u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 46112));
    // 0x147998: 0xac650000
    ctx->pc = 0x147998u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x14799c: 0x3c041000
    ctx->pc = 0x14799cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1479a0: 0x3484b400
    ctx->pc = 0x1479a0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46080));
    // 0x1479a4: 0x24050101
    ctx->pc = 0x1479a4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 257));
    // 0x1479a8: 0x8fa30020
    ctx->pc = 0x1479a8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1479ac: 0xacc30000
    ctx->pc = 0x1479acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x1479b0: 0x10400003
    ctx->pc = 0x1479B0u;
    {
        const bool branch_taken_0x1479b0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1479B4u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        if (branch_taken_0x1479b0) {
            ctx->pc = 0x1479C0u;
            goto label_1479c0;
        }
    }
    ctx->pc = 0x1479B8u;
    // 0x1479b8: 0xc0475ae
    ctx->pc = 0x1479B8u;
    SET_GPR_U32(ctx, 31, 0x1479C0u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1479C0u; }
    }
    if (ctx->pc != 0x1479C0u) { return; }
    ctx->pc = 0x1479C0u;
label_1479c0:
    // 0x1479c0: 0x12a00007
    ctx->pc = 0x1479C0u;
    {
        const bool branch_taken_0x1479c0 = (GPR_U32(ctx, 21) == GPR_U32(ctx, 0));
        ctx->pc = 0x1479C4u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
        if (branch_taken_0x1479c0) {
            ctx->pc = 0x1479E0u;
            goto label_1479e0;
        }
    }
    ctx->pc = 0x1479C8u;
    // 0x1479c8: 0x8e0500f0
    ctx->pc = 0x1479c8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x1479cc: 0x260302d
    ctx->pc = 0x1479ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1479d0: 0xc051ca6
    ctx->pc = 0x1479D0u;
    SET_GPR_U32(ctx, 31, 0x1479D8u);
    ctx->pc = 0x1479D4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x147298u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147298_0x147298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1479D8u; }
    }
    if (ctx->pc != 0x1479D8u) { return; }
    ctx->pc = 0x1479D8u;
    // 0x1479d8: 0x10000006
    ctx->pc = 0x1479D8u;
    {
        const bool branch_taken_0x1479d8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1479DCu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2160)));
        if (branch_taken_0x1479d8) {
            ctx->pc = 0x1479F4u;
            goto label_1479f4;
        }
    }
    ctx->pc = 0x1479E0u;
label_1479e0:
    // 0x1479e0: 0x8e0500f0
    ctx->pc = 0x1479e0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x1479e4: 0x260302d
    ctx->pc = 0x1479e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1479e8: 0xc051d42
    ctx->pc = 0x1479E8u;
    SET_GPR_U32(ctx, 31, 0x1479F0u);
    ctx->pc = 0x1479ECu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x147508u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147508_0x147508(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1479F0u; }
    }
    if (ctx->pc != 0x1479F0u) { return; }
    ctx->pc = 0x1479F0u;
    // 0x1479f0: 0x8e040870
    ctx->pc = 0x1479f0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2160)));
label_1479f4:
    // 0x1479f4: 0x24020003
    ctx->pc = 0x1479f4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1479f8: 0xafa20000
    ctx->pc = 0x1479f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1479fc: 0xc051fda
    ctx->pc = 0x1479FCu;
    SET_GPR_U32(ctx, 31, 0x147A04u);
    ctx->pc = 0x147A00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x147F68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147A04u; }
    }
    if (ctx->pc != 0x147A04u) { return; }
    ctx->pc = 0x147A04u;
    // 0x147a04: 0xdfbf0090
    ctx->pc = 0x147a04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x147a08: 0xdfb50080
    ctx->pc = 0x147a08u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x147a0c: 0xdfb40070
    ctx->pc = 0x147a0cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x147a10: 0xdfb30060
    ctx->pc = 0x147a10u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x147a14: 0xdfb20050
    ctx->pc = 0x147a14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x147a18: 0xdfb10040
    ctx->pc = 0x147a18u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x147a1c: 0xdfb00030
    ctx->pc = 0x147a1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x147a20: 0x3e00008
    ctx->pc = 0x147A20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147A24u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 160));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147808u: goto label_147808;
            case 0x147818u: goto label_147818;
            case 0x147850u: goto label_147850;
            case 0x147910u: goto label_147910;
            case 0x14794Cu: goto label_14794c;
            case 0x14795Cu: goto label_14795c;
            case 0x147978u: goto label_147978;
            case 0x1479C0u: goto label_1479c0;
            case 0x1479E0u: goto label_1479e0;
            case 0x1479F4u: goto label_1479f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147A28u;
}
