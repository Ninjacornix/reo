#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00145258
// Address: 0x145258 - 0x1453c0
void sub_00145258_0x145258(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x145258u;

    // 0x145258: 0x27bdff50
    ctx->pc = 0x145258u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x14525c: 0x3c021000
    ctx->pc = 0x14525cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x145260: 0xffb70080
    ctx->pc = 0x145260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 23));
    // 0x145264: 0x34422010
    ctx->pc = 0x145264u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x145268: 0xffbf00a0
    ctx->pc = 0x145268u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x14526c: 0x3c058000
    ctx->pc = 0x14526cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x145270: 0xffbe0090
    ctx->pc = 0x145270u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x145274: 0x34a54000
    ctx->pc = 0x145274u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 16384));
    // 0x145278: 0xffb60070
    ctx->pc = 0x145278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x14527c: 0x80b82d
    ctx->pc = 0x14527cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145280: 0xffb50060
    ctx->pc = 0x145280u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x145284: 0x202d
    ctx->pc = 0x145284u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145288: 0xffb40050
    ctx->pc = 0x145288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x14528c: 0xffb30040
    ctx->pc = 0x14528cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x145290: 0xffb20030
    ctx->pc = 0x145290u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x145294: 0xffb10020
    ctx->pc = 0x145294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x145298: 0xffb00010
    ctx->pc = 0x145298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x14529c: 0x8c430000
    ctx->pc = 0x14529cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1452a0: 0x3c028000
    ctx->pc = 0x1452a0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32768 << 16));
    // 0x1452a4: 0x651824
    ctx->pc = 0x1452a4u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1452a8: 0x1462003a
    ctx->pc = 0x1452A8u;
    {
        const bool branch_taken_0x1452a8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x1452ACu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
        if (branch_taken_0x1452a8) {
            ctx->pc = 0x145394u;
            goto label_145394;
        }
    }
    ctx->pc = 0x1452B0u;
    // 0x1452b0: 0x3c021000
    ctx->pc = 0x1452b0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1452b4: 0x3c131000
    ctx->pc = 0x1452b4u;
    SET_GPR_U32(ctx, 19, ((uint32_t)4096 << 16));
    // 0x1452b8: 0xafa20000
    ctx->pc = 0x1452b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1452bc: 0x3c111000
    ctx->pc = 0x1452bcu;
    SET_GPR_U32(ctx, 17, ((uint32_t)4096 << 16));
    // 0x1452c0: 0x3442b420
    ctx->pc = 0x1452c0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46112));
    // 0x1452c4: 0x3c141000
    ctx->pc = 0x1452c4u;
    SET_GPR_U32(ctx, 20, ((uint32_t)4096 << 16));
    // 0x1452c8: 0x3c151000
    ctx->pc = 0x1452c8u;
    SET_GPR_U32(ctx, 21, ((uint32_t)4096 << 16));
    // 0x1452cc: 0x3c16fffe
    ctx->pc = 0x1452ccu;
    SET_GPR_U32(ctx, 22, ((uint32_t)65534 << 16));
    // 0x1452d0: 0x3c1e1000
    ctx->pc = 0x1452d0u;
    SET_GPR_U32(ctx, 30, ((uint32_t)4096 << 16));
    // 0x1452d4: 0x3c121000
    ctx->pc = 0x1452d4u;
    SET_GPR_U32(ctx, 18, ((uint32_t)4096 << 16));
    // 0x1452d8: 0x3c108000
    ctx->pc = 0x1452d8u;
    SET_GPR_U32(ctx, 16, ((uint32_t)32768 << 16));
    // 0x1452dc: 0xafa20000
    ctx->pc = 0x1452dcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1452e0: 0x3673f590
    ctx->pc = 0x1452e0u;
    SET_GPR_U32(ctx, 19, OR32(GPR_U32(ctx, 19), 62864));
    // 0x1452e4: 0x3631f520
    ctx->pc = 0x1452e4u;
    SET_GPR_U32(ctx, 17, OR32(GPR_U32(ctx, 17), 62752));
    // 0x1452e8: 0x3694b400
    ctx->pc = 0x1452e8u;
    SET_GPR_U32(ctx, 20, OR32(GPR_U32(ctx, 20), 46080));
    // 0x1452ec: 0x36b5b000
    ctx->pc = 0x1452ecu;
    SET_GPR_U32(ctx, 21, OR32(GPR_U32(ctx, 21), 45056));
    // 0x1452f0: 0x36d6ffff
    ctx->pc = 0x1452f0u;
    SET_GPR_U32(ctx, 22, OR32(GPR_U32(ctx, 22), 65535));
    // 0x1452f4: 0x37deb020
    ctx->pc = 0x1452f4u;
    SET_GPR_U32(ctx, 30, OR32(GPR_U32(ctx, 30), 45088));
    // 0x1452f8: 0x36522010
    ctx->pc = 0x1452f8u;
    SET_GPR_U32(ctx, 18, OR32(GPR_U32(ctx, 18), 8208));
    // 0x1452fc: 0x36104000
    ctx->pc = 0x1452fcu;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 16), 16384));
    // 0x145300: 0x8ee210a0
    ctx->pc = 0x145300u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 23), 4256)));
    // 0x145304: 0x0
    ctx->pc = 0x145304u;
    // NOP
label_145308:
    // 0x145308: 0x10400016
    ctx->pc = 0x145308u;
    {
        const bool branch_taken_0x145308 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x14530Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145308) {
            ctx->pc = 0x145364u;
            goto label_145364;
        }
    }
    ctx->pc = 0x145310u;
    // 0x145310: 0xc047598
    ctx->pc = 0x145310u;
    SET_GPR_U32(ctx, 31, 0x145318u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145318u; }
    }
    if (ctx->pc != 0x145318u) { return; }
    ctx->pc = 0x145318u;
    // 0x145318: 0x8e230000
    ctx->pc = 0x145318u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14531c: 0x3c040001
    ctx->pc = 0x14531cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x145320: 0x641825
    ctx->pc = 0x145320u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x145324: 0xae630000
    ctx->pc = 0x145324u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x145328: 0xae800000
    ctx->pc = 0x145328u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
    // 0x14532c: 0xaea00000
    ctx->pc = 0x14532cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x145330: 0x8e230000
    ctx->pc = 0x145330u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x145334: 0x761824
    ctx->pc = 0x145334u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 22)));
    // 0x145338: 0x10400003
    ctx->pc = 0x145338u;
    {
        const bool branch_taken_0x145338 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x14533Cu;
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        if (branch_taken_0x145338) {
            ctx->pc = 0x145348u;
            goto label_145348;
        }
    }
    ctx->pc = 0x145340u;
    // 0x145340: 0xc0475ae
    ctx->pc = 0x145340u;
    SET_GPR_U32(ctx, 31, 0x145348u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145348u; }
    }
    if (ctx->pc != 0x145348u) { return; }
    ctx->pc = 0x145348u;
label_145348:
    // 0x145348: 0xafc00000
    ctx->pc = 0x145348u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
    // 0x14534c: 0x3c034000
    ctx->pc = 0x14534cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16384 << 16));
    // 0x145350: 0x8fa20000
    ctx->pc = 0x145350u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x145354: 0xac400000
    ctx->pc = 0x145354u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x145358: 0xae430000
    ctx->pc = 0x145358u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x14535c: 0x1000000d
    ctx->pc = 0x14535Cu;
    {
        const bool branch_taken_0x14535c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x145360u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
        if (branch_taken_0x14535c) {
            ctx->pc = 0x145394u;
            goto label_145394;
        }
    }
    ctx->pc = 0x145364u;
label_145364:
    // 0x145364: 0x28421389
    ctx->pc = 0x145364u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 5001));
    // 0x145368: 0x14400004
    ctx->pc = 0x145368u;
    {
        const bool branch_taken_0x145368 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x14536Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x145368) {
            ctx->pc = 0x14537Cu;
            goto label_14537c;
        }
    }
    ctx->pc = 0x145370u;
    // 0x145370: 0xc051ff8
    ctx->pc = 0x145370u;
    SET_GPR_U32(ctx, 31, 0x145378u);
    ctx->pc = 0x145374u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 23), 2160)));
    ctx->pc = 0x147FE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145378u; }
    }
    if (ctx->pc != 0x145378u) { return; }
    ctx->pc = 0x145378u;
    // 0x145378: 0x202d
    ctx->pc = 0x145378u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_14537c:
    // 0x14537c: 0x8e420000
    ctx->pc = 0x14537cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x145380: 0x3c038000
    ctx->pc = 0x145380u;
    SET_GPR_U32(ctx, 3, ((uint32_t)32768 << 16));
    // 0x145384: 0x501024
    ctx->pc = 0x145384u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x145388: 0x5043ffdf
    ctx->pc = 0x145388u;
    {
        const bool branch_taken_0x145388 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        if (branch_taken_0x145388) {
            ctx->pc = 0x14538Cu;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 23), 4256)));
            ctx->pc = 0x145308u;
            goto label_145308;
        }
    }
    ctx->pc = 0x145390u;
    // 0x145390: 0xdfbf00a0
    ctx->pc = 0x145390u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
label_145394:
    // 0x145394: 0xdfbe0090
    ctx->pc = 0x145394u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x145398: 0xdfb70080
    ctx->pc = 0x145398u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x14539c: 0xdfb60070
    ctx->pc = 0x14539cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1453a0: 0xdfb50060
    ctx->pc = 0x1453a0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1453a4: 0xdfb40050
    ctx->pc = 0x1453a4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1453a8: 0xdfb30040
    ctx->pc = 0x1453a8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1453ac: 0xdfb20030
    ctx->pc = 0x1453acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1453b0: 0xdfb10020
    ctx->pc = 0x1453b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1453b4: 0xdfb00010
    ctx->pc = 0x1453b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1453b8: 0x3e00008
    ctx->pc = 0x1453B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1453BCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 176));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145308u: goto label_145308;
            case 0x145348u: goto label_145348;
            case 0x145364u: goto label_145364;
            case 0x14537Cu: goto label_14537c;
            case 0x145394u: goto label_145394;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1453C0u;
}
