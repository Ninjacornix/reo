#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_1d2280
// Address: 0x1d2280 - 0x1d25b0
void entry_1d2280_0x1d25b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1d2280u;

    // 0x1d2280: 0x27bdfff0
    ctx->pc = 0x1d2280u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2284: 0x24040001
    ctx->pc = 0x1d2284u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d2288: 0xffbf0000
    ctx->pc = 0x1d2288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d228c: 0xc073420
    ctx->pc = 0x1D228Cu;
    SET_GPR_U32(ctx, 31, 0x1D2294u);
    ctx->pc = 0x1D2290u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x1CD080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2294u; }
    }
    if (ctx->pc != 0x1D2294u) { return; }
    ctx->pc = 0x1D2294u;
    // 0x1d2294: 0xc06372c
    ctx->pc = 0x1D2294u;
    SET_GPR_U32(ctx, 31, 0x1D229Cu);
    ctx->pc = 0x18DCB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D229Cu; }
    }
    if (ctx->pc != 0x1D229Cu) { return; }
    ctx->pc = 0x1D229Cu;
    // 0x1d229c: 0xdfbf0000
    ctx->pc = 0x1d229cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d22a0: 0x3e00008
    ctx->pc = 0x1D22A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D22A4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2314u: goto label_1d2314;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D22A8u;
    // 0x1d22a8: 0x0
    ctx->pc = 0x1d22a8u;
    // NOP
    // 0x1d22ac: 0x0
    ctx->pc = 0x1d22acu;
    // NOP
    // 0x1d22b0: 0x27bdfeb0
    ctx->pc = 0x1d22b0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x1d22b4: 0x3c050025
    ctx->pc = 0x1d22b4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d22b8: 0xffbf0040
    ctx->pc = 0x1d22b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d22bc: 0x3c010032
    ctx->pc = 0x1d22bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d22c0: 0x7fb30030
    ctx->pc = 0x1d22c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d22c4: 0x3c020010
    ctx->pc = 0x1d22c4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
    // 0x1d22c8: 0x7fb20020
    ctx->pc = 0x1d22c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d22cc: 0x24a564f0
    ctx->pc = 0x1d22ccu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 25840));
    // 0x1d22d0: 0x7fb10010
    ctx->pc = 0x1d22d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d22d4: 0x80902d
    ctx->pc = 0x1d22d4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d22d8: 0x7fb00000
    ctx->pc = 0x1d22d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d22dc: 0x27a40050
    ctx->pc = 0x1d22dcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d22e0: 0x8c30440c
    ctx->pc = 0x1d22e0u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d22e4: 0xc042bf0
    ctx->pc = 0x1D22E4u;
    SET_GPR_U32(ctx, 31, 0x1D22ECu);
    ctx->pc = 0x1D22E8u;
    SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    ctx->pc = 0x10AFC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D22ECu; }
    }
    if (ctx->pc != 0x1D22ECu) { return; }
    ctx->pc = 0x1D22ECu;
    // 0x1d22ec: 0x27a40050
    ctx->pc = 0x1d22ecu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d22f0: 0x200282d
    ctx->pc = 0x1d22f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d22f4: 0x24060001
    ctx->pc = 0x1d22f4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d22f8: 0xc07323c
    ctx->pc = 0x1D22F8u;
    SET_GPR_U32(ctx, 31, 0x1D2300u);
    ctx->pc = 0x1D22FCu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2300u; }
    }
    if (ctx->pc != 0x1D2300u) { return; }
    ctx->pc = 0x1D2300u;
    // 0x1d2300: 0x10400016
    ctx->pc = 0x1D2300u;
    {
        const bool branch_taken_0x1d2300 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D2304u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d2300) {
            ctx->pc = 0x1D235Cu;
            goto label_1d235c;
        }
    }
    ctx->pc = 0x1D2308u;
    // 0x1d2308: 0xc06bd74
    ctx->pc = 0x1D2308u;
    SET_GPR_U32(ctx, 31, 0x1D2310u);
    ctx->pc = 0x1D230Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AF5D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2310u; }
    }
    if (ctx->pc != 0x1D2310u) { return; }
    ctx->pc = 0x1D2310u;
    // 0x1d2310: 0x802d
    ctx->pc = 0x1d2310u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d2314:
    // 0x1d2314: 0x3c020023
    ctx->pc = 0x1d2314u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x1d2318: 0x101880
    ctx->pc = 0x1d2318u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d231c: 0x24426750
    ctx->pc = 0x1d231cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 26448));
    // 0x1d2320: 0x439821
    ctx->pc = 0x1d2320u;
    SET_GPR_U32(ctx, 19, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2324: 0x3c020023
    ctx->pc = 0x1d2324u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x1d2328: 0x8e640000
    ctx->pc = 0x1d2328u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d232c: 0x24426730
    ctx->pc = 0x1d232cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 26416));
    // 0x1d2330: 0x431021
    ctx->pc = 0x1d2330u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d2334: 0x8c420000
    ctx->pc = 0x1d2334u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d2338: 0xc0732e4
    ctx->pc = 0x1D2338u;
    SET_GPR_U32(ctx, 31, 0x1D2340u);
    ctx->pc = 0x1D233Cu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    ctx->pc = 0x1CCB90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2340u; }
    }
    if (ctx->pc != 0x1D2340u) { return; }
    ctx->pc = 0x1D2340u;
    // 0x1d2340: 0xc073494
    ctx->pc = 0x1D2340u;
    SET_GPR_U32(ctx, 31, 0x1D2348u);
    ctx->pc = 0x1D2344u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 19), 0)));
    ctx->pc = 0x1CD250u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2348u; }
    }
    if (ctx->pc != 0x1D2348u) { return; }
    ctx->pc = 0x1D2348u;
    // 0x1d2348: 0x26100001
    ctx->pc = 0x1d2348u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d234c: 0xae420000
    ctx->pc = 0x1d234cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1d2350: 0x2a030006
    ctx->pc = 0x1d2350u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 16), 6));
    // 0x1d2354: 0x1460ffef
    ctx->pc = 0x1D2354u;
    {
        const bool branch_taken_0x1d2354 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D2358u;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 4));
        if (branch_taken_0x1d2354) {
            ctx->pc = 0x1D2314u;
            goto label_1d2314;
        }
    }
    ctx->pc = 0x1D235Cu;
label_1d235c:
    // 0x1d235c: 0xdfbf0040
    ctx->pc = 0x1d235cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d2360: 0x7bb30030
    ctx->pc = 0x1d2360u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d2364: 0x7bb20020
    ctx->pc = 0x1d2364u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2368: 0x7bb10010
    ctx->pc = 0x1d2368u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d236c: 0x7bb00000
    ctx->pc = 0x1d236cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2370: 0x3e00008
    ctx->pc = 0x1D2370u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2374u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 336));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2314u: goto label_1d2314;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2378u;
    // 0x1d2378: 0x0
    ctx->pc = 0x1d2378u;
    // NOP
    // 0x1d237c: 0x0
    ctx->pc = 0x1d237cu;
    // NOP
    // 0x1d2380: 0x27bdfff0
    ctx->pc = 0x1d2380u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2384: 0x24040001
    ctx->pc = 0x1d2384u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d2388: 0xffbf0000
    ctx->pc = 0x1d2388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d238c: 0xc073420
    ctx->pc = 0x1D238Cu;
    SET_GPR_U32(ctx, 31, 0x1D2394u);
    ctx->pc = 0x1D2390u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 6));
    ctx->pc = 0x1CD080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2394u; }
    }
    if (ctx->pc != 0x1D2394u) { return; }
    ctx->pc = 0x1D2394u;
    // 0x1d2394: 0xc06372c
    ctx->pc = 0x1D2394u;
    SET_GPR_U32(ctx, 31, 0x1D239Cu);
    ctx->pc = 0x18DCB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D239Cu; }
    }
    if (ctx->pc != 0x1D239Cu) { return; }
    ctx->pc = 0x1D239Cu;
    // 0x1d239c: 0xdfbf0000
    ctx->pc = 0x1d239cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d23a0: 0x3e00008
    ctx->pc = 0x1D23A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D23A4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2314u: goto label_1d2314;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D23A8u;
    // 0x1d23a8: 0x0
    ctx->pc = 0x1d23a8u;
    // NOP
    // 0x1d23ac: 0x0
    ctx->pc = 0x1d23acu;
    // NOP
    // 0x1d23b0: 0x27bdffa0
    ctx->pc = 0x1d23b0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1d23b4: 0xffbf0050
    ctx->pc = 0x1d23b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d23b8: 0x7fb40040
    ctx->pc = 0x1d23b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d23bc: 0x7fb30030
    ctx->pc = 0x1d23bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d23c0: 0x7fb20020
    ctx->pc = 0x1d23c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d23c4: 0x80982d
    ctx->pc = 0x1d23c4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23c8: 0x7fb10010
    ctx->pc = 0x1d23c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d23cc: 0xa0902d
    ctx->pc = 0x1d23ccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23d0: 0xc0882d
    ctx->pc = 0x1d23d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23d4: 0x24044200
    ctx->pc = 0x1d23d4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 16896));
    // 0x1d23d8: 0xc073470
    ctx->pc = 0x1D23D8u;
    SET_GPR_U32(ctx, 31, 0x1D23E0u);
    ctx->pc = 0x1D23DCu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x1CD1C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D23E0u; }
    }
    if (ctx->pc != 0x1D23E0u) { return; }
    ctx->pc = 0x1D23E0u;
    // 0x1d23e0: 0x3c010032
    ctx->pc = 0x1d23e0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d23e4: 0x3c040025
    ctx->pc = 0x1d23e4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1d23e8: 0x8c34440c
    ctx->pc = 0x1d23e8u;
    SET_GPR_U32(ctx, 20, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d23ec: 0x3c020010
    ctx->pc = 0x1d23ecu;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
    // 0x1d23f0: 0x248465d0
    ctx->pc = 0x1d23f0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 26064));
    // 0x1d23f4: 0x24060001
    ctx->pc = 0x1d23f4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d23f8: 0x382d
    ctx->pc = 0x1d23f8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23fc: 0x2828021
    ctx->pc = 0x1d23fcu;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x1d2400: 0xc07323c
    ctx->pc = 0x1D2400u;
    SET_GPR_U32(ctx, 31, 0x1D2408u);
    ctx->pc = 0x1D2404u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2408u; }
    }
    if (ctx->pc != 0x1D2408u) { return; }
    ctx->pc = 0x1D2408u;
    // 0x1d2408: 0x10400012
    ctx->pc = 0x1D2408u;
    {
        const bool branch_taken_0x1d2408 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D240Cu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d2408) {
            ctx->pc = 0x1D2454u;
            goto label_1d2454;
        }
    }
    ctx->pc = 0x1D2410u;
    // 0x1d2410: 0xc06bd74
    ctx->pc = 0x1D2410u;
    SET_GPR_U32(ctx, 31, 0x1D2418u);
    ctx->pc = 0x1D2414u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AF5D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2418u; }
    }
    if (ctx->pc != 0x1D2418u) { return; }
    ctx->pc = 0x1D2418u;
    // 0x1d2418: 0x1000000b
    ctx->pc = 0x1D2418u;
    {
        const bool branch_taken_0x1d2418 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D241Cu;
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d2418) {
            ctx->pc = 0x1D2448u;
            goto label_1d2448;
        }
    }
    ctx->pc = 0x1D2420u;
label_1d2420:
    // 0x1d2420: 0x8e620000
    ctx->pc = 0x1d2420u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d2424: 0x26844200
    ctx->pc = 0x1d2424u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 16896));
    // 0x1d2428: 0xc0732e4
    ctx->pc = 0x1D2428u;
    SET_GPR_U32(ctx, 31, 0x1D2430u);
    ctx->pc = 0x1D242Cu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    ctx->pc = 0x1CCB90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2430u; }
    }
    if (ctx->pc != 0x1D2430u) { return; }
    ctx->pc = 0x1D2430u;
    // 0x1d2430: 0xc073494
    ctx->pc = 0x1D2430u;
    SET_GPR_U32(ctx, 31, 0x1D2438u);
    ctx->pc = 0x1D2434u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 16896));
    ctx->pc = 0x1CD250u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2438u; }
    }
    if (ctx->pc != 0x1D2438u) { return; }
    ctx->pc = 0x1D2438u;
    // 0x1d2438: 0xae420000
    ctx->pc = 0x1d2438u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1d243c: 0x26730004
    ctx->pc = 0x1d243cu;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 4));
    // 0x1d2440: 0x26520004
    ctx->pc = 0x1d2440u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 4));
    // 0x1d2444: 0x26940001
    ctx->pc = 0x1d2444u;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 20), 1));
label_1d2448:
    // 0x1d2448: 0x291182a
    ctx->pc = 0x1d2448u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 20), GPR_S32(ctx, 17)));
    // 0x1d244c: 0x1460fff4
    ctx->pc = 0x1D244Cu;
    {
        const bool branch_taken_0x1d244c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x1d244c) {
            ctx->pc = 0x1D2420u;
            goto label_1d2420;
        }
    }
    ctx->pc = 0x1D2454u;
label_1d2454:
    // 0x1d2454: 0xdfbf0050
    ctx->pc = 0x1d2454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d2458: 0x7bb40040
    ctx->pc = 0x1d2458u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d245c: 0x7bb30030
    ctx->pc = 0x1d245cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d2460: 0x7bb20020
    ctx->pc = 0x1d2460u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2464: 0x7bb10010
    ctx->pc = 0x1d2464u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d2468: 0x7bb00000
    ctx->pc = 0x1d2468u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d246c: 0x3e00008
    ctx->pc = 0x1D246Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2470u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2314u: goto label_1d2314;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2474u;
    // 0x1d2474: 0x0
    ctx->pc = 0x1d2474u;
    // NOP
    // 0x1d2478: 0x0
    ctx->pc = 0x1d2478u;
    // NOP
    // 0x1d247c: 0x0
    ctx->pc = 0x1d247cu;
    // NOP
    // 0x1d2480: 0x27bdfff0
    ctx->pc = 0x1d2480u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2484: 0x80282d
    ctx->pc = 0x1d2484u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2488: 0xffbf0000
    ctx->pc = 0x1d2488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d248c: 0xc073420
    ctx->pc = 0x1D248Cu;
    SET_GPR_U32(ctx, 31, 0x1D2494u);
    ctx->pc = 0x1D2490u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 16896));
    ctx->pc = 0x1CD080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2494u; }
    }
    if (ctx->pc != 0x1D2494u) { return; }
    ctx->pc = 0x1D2494u;
    // 0x1d2494: 0xc06372c
    ctx->pc = 0x1D2494u;
    SET_GPR_U32(ctx, 31, 0x1D249Cu);
    ctx->pc = 0x18DCB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D249Cu; }
    }
    if (ctx->pc != 0x1D249Cu) { return; }
    ctx->pc = 0x1D249Cu;
    // 0x1d249c: 0xdfbf0000
    ctx->pc = 0x1d249cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d24a0: 0x3e00008
    ctx->pc = 0x1D24A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D24A4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2314u: goto label_1d2314;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D24A8u;
    // 0x1d24a8: 0x0
    ctx->pc = 0x1d24a8u;
    // NOP
    // 0x1d24ac: 0x0
    ctx->pc = 0x1d24acu;
    // NOP
    // 0x1d24b0: 0x27bdfff0
    ctx->pc = 0x1d24b0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d24b4: 0x3c010032
    ctx->pc = 0x1d24b4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d24b8: 0xffbf0000
    ctx->pc = 0x1d24b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d24bc: 0x802343d7
    ctx->pc = 0x1d24bcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d24c0: 0x14600005
    ctx->pc = 0x1D24C0u;
    {
        const bool branch_taken_0x1d24c0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x1d24c0) {
            ctx->pc = 0x1D24D8u;
            goto label_1d24d8;
        }
    }
    ctx->pc = 0x1D24C8u;
    // 0x1d24c8: 0x3082ffff
    ctx->pc = 0x1d24c8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 65535));
    // 0x1d24cc: 0x24052a00
    ctx->pc = 0x1d24ccu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 10752));
    // 0x1d24d0: 0xc073784
    ctx->pc = 0x1D24D0u;
    SET_GPR_U32(ctx, 31, 0x1D24D8u);
    ctx->pc = 0x1D24D4u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 2), 16));
    ctx->pc = 0x1CDE10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D24D8u; }
    }
    if (ctx->pc != 0x1D24D8u) { return; }
    ctx->pc = 0x1D24D8u;
label_1d24d8:
    // 0x1d24d8: 0xdfbf0000
    ctx->pc = 0x1d24d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d24dc: 0x3e00008
    ctx->pc = 0x1D24DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D24E0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2314u: goto label_1d2314;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D24E4u;
    // 0x1d24e4: 0x0
    ctx->pc = 0x1d24e4u;
    // NOP
    // 0x1d24e8: 0x0
    ctx->pc = 0x1d24e8u;
    // NOP
    // 0x1d24ec: 0x0
    ctx->pc = 0x1d24ecu;
    // NOP
    // 0x1d24f0: 0x27bdfff0
    ctx->pc = 0x1d24f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d24f4: 0x3c010032
    ctx->pc = 0x1d24f4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d24f8: 0xffbf0000
    ctx->pc = 0x1d24f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d24fc: 0x802343d7
    ctx->pc = 0x1d24fcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d2500: 0x14600004
    ctx->pc = 0x1D2500u;
    {
        const bool branch_taken_0x1d2500 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D2504u;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d2500) {
            ctx->pc = 0x1D2514u;
            goto label_1d2514;
        }
    }
    ctx->pc = 0x1D2508u;
    // 0x1d2508: 0x942443da
    ctx->pc = 0x1d2508u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d250c: 0xc073784
    ctx->pc = 0x1D250Cu;
    SET_GPR_U32(ctx, 31, 0x1D2514u);
    ctx->pc = 0x1D2510u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8192));
    ctx->pc = 0x1CDE10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2514u; }
    }
    if (ctx->pc != 0x1D2514u) { return; }
    ctx->pc = 0x1D2514u;
label_1d2514:
    // 0x1d2514: 0xdfbf0000
    ctx->pc = 0x1d2514u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2518: 0x3e00008
    ctx->pc = 0x1D2518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D251Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2314u: goto label_1d2314;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2520u;
    // 0x1d2520: 0x27bdfff0
    ctx->pc = 0x1d2520u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2524: 0x3c010032
    ctx->pc = 0x1d2524u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d2528: 0xffbf0000
    ctx->pc = 0x1d2528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d252c: 0x802343d7
    ctx->pc = 0x1d252cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d2530: 0x14600004
    ctx->pc = 0x1D2530u;
    {
        const bool branch_taken_0x1d2530 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D2534u;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d2530) {
            ctx->pc = 0x1D2544u;
            goto label_1d2544;
        }
    }
    ctx->pc = 0x1D2538u;
    // 0x1d2538: 0x942443da
    ctx->pc = 0x1d2538u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d253c: 0xc073784
    ctx->pc = 0x1D253Cu;
    SET_GPR_U32(ctx, 31, 0x1D2544u);
    ctx->pc = 0x1D2540u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 9216));
    ctx->pc = 0x1CDE10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2544u; }
    }
    if (ctx->pc != 0x1D2544u) { return; }
    ctx->pc = 0x1D2544u;
label_1d2544:
    // 0x1d2544: 0xdfbf0000
    ctx->pc = 0x1d2544u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2548: 0x3e00008
    ctx->pc = 0x1D2548u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D254Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2314u: goto label_1d2314;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2550u;
    // 0x1d2550: 0x202d
    ctx->pc = 0x1d2550u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2554: 0x8073784
    ctx->pc = 0x1D2554u;
    ctx->pc = 0x1D2558u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 9472));
    ctx->pc = 0x1CDE10u;
    sub_001CDE10_0x1cde10(rdram, ctx, runtime); return;
    ctx->pc = 0x1D255Cu;
    // 0x1d255c: 0x0
    ctx->pc = 0x1d255cu;
    // NOP
    // 0x1d2560: 0x27bdfff0
    ctx->pc = 0x1d2560u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2564: 0x3c010032
    ctx->pc = 0x1d2564u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d2568: 0xffbf0000
    ctx->pc = 0x1d2568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d256c: 0x802343d7
    ctx->pc = 0x1d256cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d2570: 0x14600005
    ctx->pc = 0x1D2570u;
    {
        const bool branch_taken_0x1d2570 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x1d2570) {
            ctx->pc = 0x1D2588u;
            goto label_1d2588;
        }
    }
    ctx->pc = 0x1D2578u;
    // 0x1d2578: 0x308400ff
    ctx->pc = 0x1d2578u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), 255));
    // 0x1d257c: 0x410c0
    ctx->pc = 0x1d257cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 3));
    // 0x1d2580: 0xc073784
    ctx->pc = 0x1D2580u;
    SET_GPR_U32(ctx, 31, 0x1D2588u);
    ctx->pc = 0x1D2584u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 2), 12288));
    ctx->pc = 0x1CDE10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2588u; }
    }
    if (ctx->pc != 0x1D2588u) { return; }
    ctx->pc = 0x1D2588u;
label_1d2588:
    // 0x1d2588: 0xdfbf0000
    ctx->pc = 0x1d2588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d258c: 0x3e00008
    ctx->pc = 0x1D258Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2590u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2314u: goto label_1d2314;
            case 0x1D235Cu: goto label_1d235c;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            case 0x1D24D8u: goto label_1d24d8;
            case 0x1D2514u: goto label_1d2514;
            case 0x1D2544u: goto label_1d2544;
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2594u;
    // 0x1d2594: 0x0
    ctx->pc = 0x1d2594u;
    // NOP
    // 0x1d2598: 0x0
    ctx->pc = 0x1d2598u;
    // NOP
    // 0x1d259c: 0x0
    ctx->pc = 0x1d259cu;
    // NOP
    // 0x1d25a0: 0x80738fc
    ctx->pc = 0x1D25A0u;
    ctx->pc = 0x1CE3F0u;
    entry_1ce3f0_0x1ce570(rdram, ctx, runtime); return;
    ctx->pc = 0x1D25A8u;
    // 0x1d25a8: 0x0
    ctx->pc = 0x1d25a8u;
    // NOP
    // 0x1d25ac: 0x0
    ctx->pc = 0x1d25acu;
    // NOP
}
