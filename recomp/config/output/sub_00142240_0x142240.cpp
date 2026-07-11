#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00142240
// Address: 0x142240 - 0x142490
void sub_00142240_0x142240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x142240u;

    // 0x142240: 0x27bdff50
    ctx->pc = 0x142240u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x142244: 0xffbe0090
    ctx->pc = 0x142244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x142248: 0xffb70080
    ctx->pc = 0x142248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 23));
    // 0x14224c: 0xc0f02d
    ctx->pc = 0x14224cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142250: 0xffb60070
    ctx->pc = 0x142250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x142254: 0xffb50060
    ctx->pc = 0x142254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x142258: 0xffb00010
    ctx->pc = 0x142258u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x14225c: 0xe0a82d
    ctx->pc = 0x14225cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142260: 0xffbf00a0
    ctx->pc = 0x142260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x142264: 0x80802d
    ctx->pc = 0x142264u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142268: 0xffb40050
    ctx->pc = 0x142268u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x14226c: 0x32a30001
    ctx->pc = 0x14226cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 21), 1));
    // 0x142270: 0xffb30040
    ctx->pc = 0x142270u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x142274: 0xffb20030
    ctx->pc = 0x142274u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x142278: 0xffb10020
    ctx->pc = 0x142278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x14227c: 0x8e020144
    ctx->pc = 0x14227cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 324)));
    // 0x142280: 0xafa30000
    ctx->pc = 0x142280u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x142284: 0xa2001a
    ctx->pc = 0x142284u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x142288: 0x50400001
    ctx->pc = 0x142288u;
    {
        const bool branch_taken_0x142288 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x142288) {
            ctx->pc = 0x14228Cu;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x142290u;
            goto label_142290;
        }
    }
    ctx->pc = 0x142290u;
label_142290:
    // 0x142290: 0x8fa20000
    ctx->pc = 0x142290u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142294: 0x1810
    ctx->pc = 0x142294u;
    SET_GPR_U32(ctx, 3, ctx->hi);
    // 0x142298: 0xb812
    ctx->pc = 0x142298u;
    SET_GPR_U32(ctx, 23, ctx->lo);
    // 0x14229c: 0x60b02d
    ctx->pc = 0x14229cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1422a0: 0x173100
    ctx->pc = 0x1422a0u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 23), 4));
    // 0x1422a4: 0x10400012
    ctx->pc = 0x1422A4u;
    {
        const bool branch_taken_0x1422a4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1422A8u;
        SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 22), 4));
        if (branch_taken_0x1422a4) {
            ctx->pc = 0x1422F0u;
            goto label_1422f0;
        }
    }
    ctx->pc = 0x1422ACu;
    // 0x1422ac: 0x8e040828
    ctx->pc = 0x1422acu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x1422b0: 0x261106e0
    ctx->pc = 0x1422b0u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 1760));
    // 0x1422b4: 0x261206dc
    ctx->pc = 0x1422b4u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 16), 1756));
    // 0x1422b8: 0x261306d8
    ctx->pc = 0x1422b8u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 16), 1752));
    // 0x1422bc: 0x261406d0
    ctx->pc = 0x1422bcu;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 16), 1744));
label_1422c0:
    // 0x1422c0: 0x3c021000
    ctx->pc = 0x1422c0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1422c4: 0x3442d400
    ctx->pc = 0x1422c4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 54272));
    // 0x1422c8: 0x8c430000
    ctx->pc = 0x1422c8u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1422cc: 0x31a02
    ctx->pc = 0x1422ccu;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), 8));
    // 0x1422d0: 0x30630001
    ctx->pc = 0x1422d0u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 1));
    // 0x1422d4: 0x1460fffa
    ctx->pc = 0x1422D4u;
    {
        const bool branch_taken_0x1422d4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x1422d4) {
            ctx->pc = 0x1422C0u;
            goto label_1422c0;
        }
    }
    ctx->pc = 0x1422DCu;
    // 0x1422dc: 0x24020140
    ctx->pc = 0x1422dcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 320));
    // 0x1422e0: 0x821818
    ctx->pc = 0x1422e0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
    // 0x1422e4: 0x711021
    ctx->pc = 0x1422e4u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1422e8: 0x10000026
    ctx->pc = 0x1422E8u;
    {
        const bool branch_taken_0x1422e8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1422ECu;
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        if (branch_taken_0x1422e8) {
            ctx->pc = 0x142384u;
            goto label_142384;
        }
    }
    ctx->pc = 0x1422F0u;
label_1422f0:
    // 0x1422f0: 0x2502ffff
    ctx->pc = 0x1422f0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x1422f4: 0x2c420003
    ctx->pc = 0x1422f4u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 3));
    // 0x1422f8: 0x1440000a
    ctx->pc = 0x1422F8u;
    {
        const bool branch_taken_0x1422f8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1422FCu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1422f8) {
            ctx->pc = 0x142324u;
            goto label_142324;
        }
    }
    ctx->pc = 0x142300u;
    // 0x142300: 0x3c050024
    ctx->pc = 0x142300u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x142304: 0x100302d
    ctx->pc = 0x142304u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142308: 0x24a5dd28
    ctx->pc = 0x142308u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294958376));
    // 0x14230c: 0xc05220e
    ctx->pc = 0x14230Cu;
    SET_GPR_U32(ctx, 31, 0x142314u);
    ctx->pc = 0x142310u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x148838u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00148838_0x148838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142314u; }
    }
    if (ctx->pc != 0x142314u) { return; }
    ctx->pc = 0x142314u;
    // 0x142314: 0x24030001
    ctx->pc = 0x142314u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x142318: 0x102d
    ctx->pc = 0x142318u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14231c: 0x10000050
    ctx->pc = 0x14231Cu;
    {
        const bool branch_taken_0x14231c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x142320u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 308), GPR_U32(ctx, 3));
        if (branch_taken_0x14231c) {
            ctx->pc = 0x142460u;
            goto label_142460;
        }
    }
    ctx->pc = 0x142324u;
label_142324:
    // 0x142324: 0xc050924
    ctx->pc = 0x142324u;
    SET_GPR_U32(ctx, 31, 0x14232Cu);
    ctx->pc = 0x142328u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x142490u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00142490_0x142490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14232Cu; }
    }
    if (ctx->pc != 0x14232Cu) { return; }
    ctx->pc = 0x14232Cu;
    // 0x14232c: 0x3c031000
    ctx->pc = 0x14232cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x142330: 0x261106e0
    ctx->pc = 0x142330u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 1760));
    // 0x142334: 0x261206dc
    ctx->pc = 0x142334u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 16), 1756));
    // 0x142338: 0x261306d8
    ctx->pc = 0x142338u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 16), 1752));
    // 0x14233c: 0x261406d0
    ctx->pc = 0x14233cu;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 16), 1744));
    // 0x142340: 0x3463d400
    ctx->pc = 0x142340u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 54272));
    // 0x142344: 0x0
    ctx->pc = 0x142344u;
    // NOP
label_142348:
    // 0x142348: 0x8c620000
    ctx->pc = 0x142348u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14234c: 0x21202
    ctx->pc = 0x14234cu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x142350: 0x30420001
    ctx->pc = 0x142350u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x142354: 0x0
    ctx->pc = 0x142354u;
    // NOP
    // 0x142358: 0x0
    ctx->pc = 0x142358u;
    // NOP
    // 0x14235c: 0x1440fffa
    ctx->pc = 0x14235Cu;
    {
        const bool branch_taken_0x14235c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x14235c) {
            ctx->pc = 0x142348u;
            goto label_142348;
        }
    }
    ctx->pc = 0x142364u;
    // 0x142364: 0xc051c28
    ctx->pc = 0x142364u;
    SET_GPR_U32(ctx, 31, 0x14236Cu);
    ctx->pc = 0x142368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1470A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001470A0_0x1470a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14236Cu; }
    }
    if (ctx->pc != 0x14236Cu) { return; }
    ctx->pc = 0x14236Cu;
    // 0x14236c: 0x8e020828
    ctx->pc = 0x14236cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x142370: 0x24030140
    ctx->pc = 0x142370u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 320));
    // 0x142374: 0x24040001
    ctx->pc = 0x142374u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x142378: 0x432818
    ctx->pc = 0x142378u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)(uint32_t)result); }
    // 0x14237c: 0xb11021
    ctx->pc = 0x14237cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 17)));
    // 0x142380: 0xac440000
    ctx->pc = 0x142380u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
label_142384:
    // 0x142384: 0x24020001
    ctx->pc = 0x142384u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x142388: 0x57c2000a
    ctx->pc = 0x142388u;
    {
        const bool branch_taken_0x142388 = (GPR_U32(ctx, 30) != GPR_U32(ctx, 2));
        if (branch_taken_0x142388) {
            ctx->pc = 0x14238Cu;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
            ctx->pc = 0x1423B4u;
            goto label_1423b4;
        }
    }
    ctx->pc = 0x142390u;
    // 0x142390: 0x32a20002
    ctx->pc = 0x142390u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 21), 2));
    // 0x142394: 0x10400006
    ctx->pc = 0x142394u;
    {
        const bool branch_taken_0x142394 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x142398u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 320));
        if (branch_taken_0x142394) {
            ctx->pc = 0x1423B0u;
            goto label_1423b0;
        }
    }
    ctx->pc = 0x14239Cu;
    // 0x14239c: 0x8e020828
    ctx->pc = 0x14239cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x1423a0: 0x432018
    ctx->pc = 0x1423a0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)(uint32_t)result); }
    // 0x1423a4: 0x921021
    ctx->pc = 0x1423a4u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x1423a8: 0x10000006
    ctx->pc = 0x1423A8u;
    {
        const bool branch_taken_0x1423a8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1423ACu;
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 30));
        if (branch_taken_0x1423a8) {
            ctx->pc = 0x1423C4u;
            goto label_1423c4;
        }
    }
    ctx->pc = 0x1423B0u;
label_1423b0:
    // 0x1423b0: 0x8e020828
    ctx->pc = 0x1423b0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
label_1423b4:
    // 0x1423b4: 0x24030140
    ctx->pc = 0x1423b4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 320));
    // 0x1423b8: 0x432018
    ctx->pc = 0x1423b8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)(uint32_t)result); }
    // 0x1423bc: 0x921021
    ctx->pc = 0x1423bcu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x1423c0: 0xac400000
    ctx->pc = 0x1423c0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_1423c4:
    // 0x1423c4: 0x8e020828
    ctx->pc = 0x1423c4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x1423c8: 0x24070140
    ctx->pc = 0x1423c8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 320));
    // 0x1423cc: 0x8fa50000
    ctx->pc = 0x1423ccu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1423d0: 0x24030003
    ctx->pc = 0x1423d0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1423d4: 0x472018
    ctx->pc = 0x1423d4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)(uint32_t)result); }
    // 0x1423d8: 0x931021
    ctx->pc = 0x1423d8u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
    // 0x1423dc: 0xac450000
    ctx->pc = 0x1423dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
    // 0x1423e0: 0x8e04018c
    ctx->pc = 0x1423e0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x1423e4: 0x1483000e
    ctx->pc = 0x1423E4u;
    {
        const bool branch_taken_0x1423e4 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 3));
        ctx->pc = 0x1423E8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1423e4) {
            ctx->pc = 0x142420u;
            goto label_142420;
        }
    }
    ctx->pc = 0x1423ECu;
    // 0x1423ec: 0x8e040828
    ctx->pc = 0x1423ecu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x1423f0: 0x24060180
    ctx->pc = 0x1423f0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 384));
    // 0x1423f4: 0x8e0501d8
    ctx->pc = 0x1423f4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 472)));
    // 0x1423f8: 0x871818
    ctx->pc = 0x1423f8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
    // 0x1423fc: 0x8ca20010
    ctx->pc = 0x1423fcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x142400: 0x742021
    ctx->pc = 0x142400u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x142404: 0x8ca30000
    ctx->pc = 0x142404u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x142408: 0x2c22818
    ctx->pc = 0x142408u;
    { int64_t result = (int64_t)GPR_S32(ctx, 22) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)(uint32_t)result); }
    // 0x14240c: 0xb71021
    ctx->pc = 0x14240cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 23)));
    // 0x142410: 0x461018
    ctx->pc = 0x142410u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x142414: 0x621821
    ctx->pc = 0x142414u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x142418: 0x10000010
    ctx->pc = 0x142418u;
    {
        const bool branch_taken_0x142418 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x14241Cu;
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        if (branch_taken_0x142418) {
            ctx->pc = 0x14245Cu;
            goto label_14245c;
        }
    }
    ctx->pc = 0x142420u;
label_142420:
    // 0x142420: 0x54820002
    ctx->pc = 0x142420u;
    {
        const bool branch_taken_0x142420 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        if (branch_taken_0x142420) {
            ctx->pc = 0x142424u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 488)));
            ctx->pc = 0x14242Cu;
            goto label_14242c;
        }
    }
    ctx->pc = 0x142428u;
    // 0x142428: 0x8e0201f8
    ctx->pc = 0x142428u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 504)));
label_14242c:
    // 0x14242c: 0x8c430010
    ctx->pc = 0x14242cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x142430: 0x24060180
    ctx->pc = 0x142430u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 384));
    // 0x142434: 0x8e040828
    ctx->pc = 0x142434u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x142438: 0x24050140
    ctx->pc = 0x142438u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 320));
    // 0x14243c: 0x2c33818
    ctx->pc = 0x14243cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 22) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)(uint32_t)result); }
    // 0x142440: 0x8c420000
    ctx->pc = 0x142440u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x142444: 0xf71821
    ctx->pc = 0x142444u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 23)));
    // 0x142448: 0x853818
    ctx->pc = 0x142448u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)(uint32_t)result); }
    // 0x14244c: 0x661818
    ctx->pc = 0x14244cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
    // 0x142450: 0xf42021
    ctx->pc = 0x142450u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 20)));
    // 0x142454: 0x431021
    ctx->pc = 0x142454u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x142458: 0xac820000
    ctx->pc = 0x142458u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_14245c:
    // 0x14245c: 0x24020001
    ctx->pc = 0x14245cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_142460:
    // 0x142460: 0xdfbf00a0
    ctx->pc = 0x142460u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x142464: 0xdfbe0090
    ctx->pc = 0x142464u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x142468: 0xdfb70080
    ctx->pc = 0x142468u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x14246c: 0xdfb60070
    ctx->pc = 0x14246cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x142470: 0xdfb50060
    ctx->pc = 0x142470u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x142474: 0xdfb40050
    ctx->pc = 0x142474u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x142478: 0xdfb30040
    ctx->pc = 0x142478u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14247c: 0xdfb20030
    ctx->pc = 0x14247cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x142480: 0xdfb10020
    ctx->pc = 0x142480u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x142484: 0xdfb00010
    ctx->pc = 0x142484u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x142488: 0x3e00008
    ctx->pc = 0x142488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14248Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 176));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x142290u: goto label_142290;
            case 0x1422C0u: goto label_1422c0;
            case 0x1422F0u: goto label_1422f0;
            case 0x142324u: goto label_142324;
            case 0x142348u: goto label_142348;
            case 0x142384u: goto label_142384;
            case 0x1423B0u: goto label_1423b0;
            case 0x1423B4u: goto label_1423b4;
            case 0x1423C4u: goto label_1423c4;
            case 0x142420u: goto label_142420;
            case 0x14242Cu: goto label_14242c;
            case 0x14245Cu: goto label_14245c;
            case 0x142460u: goto label_142460;
            default: break;
        }
        return;
    }
    ctx->pc = 0x142490u;
}
