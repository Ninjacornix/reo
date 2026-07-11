#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001D1FC0
// Address: 0x1d1fc0 - 0x1d2170
void sub_001D1FC0_0x1d1fc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1d1fc0u;

    // 0x1d1fc0: 0x27bdfed0
    ctx->pc = 0x1d1fc0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x1d1fc4: 0x202d
    ctx->pc = 0x1d1fc4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1fc8: 0xffbf0020
    ctx->pc = 0x1d1fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d1fcc: 0x7fb10010
    ctx->pc = 0x1d1fccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1fd0: 0xc073494
    ctx->pc = 0x1D1FD0u;
    SET_GPR_U32(ctx, 31, 0x1D1FD8u);
    ctx->pc = 0x1D1FD4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x1CD250u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1FD8u; }
    }
    if (ctx->pc != 0x1D1FD8u) { return; }
    ctx->pc = 0x1D1FD8u;
    // 0x1d1fd8: 0x14400017
    ctx->pc = 0x1D1FD8u;
    {
        const bool branch_taken_0x1d1fd8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D1FDCu;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d1fd8) {
            ctx->pc = 0x1D2038u;
            goto label_1d2038;
        }
    }
    ctx->pc = 0x1D1FE0u;
    // 0x1d1fe0: 0x3c050025
    ctx->pc = 0x1d1fe0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d1fe4: 0x8c30440c
    ctx->pc = 0x1d1fe4u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1fe8: 0x3c020010
    ctx->pc = 0x1d1fe8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
    // 0x1d1fec: 0x27a40030
    ctx->pc = 0x1d1fecu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d1ff0: 0x24a564f0
    ctx->pc = 0x1d1ff0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 25840));
    // 0x1d1ff4: 0xc042bf0
    ctx->pc = 0x1D1FF4u;
    SET_GPR_U32(ctx, 31, 0x1D1FFCu);
    ctx->pc = 0x1D1FF8u;
    SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    ctx->pc = 0x10AFC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1FFCu; }
    }
    if (ctx->pc != 0x1D1FFCu) { return; }
    ctx->pc = 0x1D1FFCu;
    // 0x1d1ffc: 0x3c010032
    ctx->pc = 0x1d1ffcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d2000: 0x27a40030
    ctx->pc = 0x1d2000u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d2004: 0x8c25440c
    ctx->pc = 0x1d2004u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d2008: 0x24060001
    ctx->pc = 0x1d2008u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d200c: 0xc07323c
    ctx->pc = 0x1D200Cu;
    SET_GPR_U32(ctx, 31, 0x1D2014u);
    ctx->pc = 0x1D2010u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2014u; }
    }
    if (ctx->pc != 0x1D2014u) { return; }
    ctx->pc = 0x1D2014u;
    // 0x1d2014: 0x10400008
    ctx->pc = 0x1D2014u;
    {
        const bool branch_taken_0x1d2014 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D2018u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d2014) {
            ctx->pc = 0x1D2038u;
            goto label_1d2038;
        }
    }
    ctx->pc = 0x1D201Cu;
    // 0x1d201c: 0xc06bd74
    ctx->pc = 0x1D201Cu;
    SET_GPR_U32(ctx, 31, 0x1D2024u);
    ctx->pc = 0x1D2020u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AF5D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2024u; }
    }
    if (ctx->pc != 0x1D2024u) { return; }
    ctx->pc = 0x1D2024u;
    // 0x1d2024: 0x3c02001e
    ctx->pc = 0x1d2024u;
    SET_GPR_U32(ctx, 2, ((uint32_t)30 << 16));
    // 0x1d2028: 0x202d
    ctx->pc = 0x1d2028u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d202c: 0x34422740
    ctx->pc = 0x1d202cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 10048));
    // 0x1d2030: 0xc0732e4
    ctx->pc = 0x1D2030u;
    SET_GPR_U32(ctx, 31, 0x1D2038u);
    ctx->pc = 0x1D2034u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    ctx->pc = 0x1CCB90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2038u; }
    }
    if (ctx->pc != 0x1D2038u) { return; }
    ctx->pc = 0x1D2038u;
label_1d2038:
    // 0x1d2038: 0xdfbf0020
    ctx->pc = 0x1d2038u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d203c: 0x7bb10010
    ctx->pc = 0x1d203cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d2040: 0x7bb00000
    ctx->pc = 0x1d2040u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2044: 0x3e00008
    ctx->pc = 0x1D2044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2048u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 304));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2038u: goto label_1d2038;
            case 0x1D20B0u: goto label_1d20b0;
            case 0x1D2128u: goto label_1d2128;
            case 0x1D2150u: goto label_1d2150;
            case 0x1D2154u: goto label_1d2154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D204Cu;
    // 0x1d204c: 0x0
    ctx->pc = 0x1d204cu;
    // NOP
    // 0x1d2050: 0x27bdfec0
    ctx->pc = 0x1d2050u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294966976));
    // 0x1d2054: 0x3c050025
    ctx->pc = 0x1d2054u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d2058: 0xffbf0030
    ctx->pc = 0x1d2058u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d205c: 0x3c010032
    ctx->pc = 0x1d205cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d2060: 0x7fb20020
    ctx->pc = 0x1d2060u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d2064: 0x3c020010
    ctx->pc = 0x1d2064u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
    // 0x1d2068: 0x7fb10010
    ctx->pc = 0x1d2068u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d206c: 0x27a40040
    ctx->pc = 0x1d206cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2070: 0x7fb00000
    ctx->pc = 0x1d2070u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d2074: 0x24a56520
    ctx->pc = 0x1d2074u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 25888));
    // 0x1d2078: 0x8c30440c
    ctx->pc = 0x1d2078u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d207c: 0x24122600
    ctx->pc = 0x1d207cu;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 9728));
    // 0x1d2080: 0xc042bf0
    ctx->pc = 0x1D2080u;
    SET_GPR_U32(ctx, 31, 0x1D2088u);
    ctx->pc = 0x1D2084u;
    SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    ctx->pc = 0x10AFC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2088u; }
    }
    if (ctx->pc != 0x1D2088u) { return; }
    ctx->pc = 0x1D2088u;
    // 0x1d2088: 0x27a40040
    ctx->pc = 0x1d2088u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d208c: 0x200282d
    ctx->pc = 0x1d208cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2090: 0x24060001
    ctx->pc = 0x1d2090u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d2094: 0xc07323c
    ctx->pc = 0x1D2094u;
    SET_GPR_U32(ctx, 31, 0x1D209Cu);
    ctx->pc = 0x1D2098u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D209Cu; }
    }
    if (ctx->pc != 0x1D209Cu) { return; }
    ctx->pc = 0x1D209Cu;
    // 0x1d209c: 0x1040002c
    ctx->pc = 0x1D209Cu;
    {
        const bool branch_taken_0x1d209c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D20A0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d209c) {
            ctx->pc = 0x1D2150u;
            goto label_1d2150;
        }
    }
    ctx->pc = 0x1D20A4u;
    // 0x1d20a4: 0xc06bd74
    ctx->pc = 0x1D20A4u;
    SET_GPR_U32(ctx, 31, 0x1D20ACu);
    ctx->pc = 0x1D20A8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AF5D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D20ACu; }
    }
    if (ctx->pc != 0x1D20ACu) { return; }
    ctx->pc = 0x1D20ACu;
    // 0x1d20ac: 0x802d
    ctx->pc = 0x1d20acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d20b0:
    // 0x1d20b0: 0x3c020023
    ctx->pc = 0x1d20b0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x1d20b4: 0x101880
    ctx->pc = 0x1d20b4u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d20b8: 0x24426700
    ctx->pc = 0x1d20b8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 26368));
    // 0x1d20bc: 0x240202d
    ctx->pc = 0x1d20bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d20c0: 0x431021
    ctx->pc = 0x1d20c0u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d20c4: 0x8c420000
    ctx->pc = 0x1d20c4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d20c8: 0xc0732e4
    ctx->pc = 0x1D20C8u;
    SET_GPR_U32(ctx, 31, 0x1D20D0u);
    ctx->pc = 0x1D20CCu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    ctx->pc = 0x1CCB90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D20D0u; }
    }
    if (ctx->pc != 0x1D20D0u) { return; }
    ctx->pc = 0x1D20D0u;
    // 0x1d20d0: 0x26100001
    ctx->pc = 0x1d20d0u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d20d4: 0x2a020004
    ctx->pc = 0x1d20d4u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 16), 4));
    // 0x1d20d8: 0x1440fff5
    ctx->pc = 0x1D20D8u;
    {
        const bool branch_taken_0x1d20d8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D20DCu;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
        if (branch_taken_0x1d20d8) {
            ctx->pc = 0x1D20B0u;
            goto label_1d20b0;
        }
    }
    ctx->pc = 0x1D20E0u;
    // 0x1d20e0: 0x3c010032
    ctx->pc = 0x1d20e0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d20e4: 0x802243d7
    ctx->pc = 0x1d20e4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d20e8: 0x1440000f
    ctx->pc = 0x1D20E8u;
    {
        const bool branch_taken_0x1d20e8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D20ECu;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d20e8) {
            ctx->pc = 0x1D2128u;
            goto label_1d2128;
        }
    }
    ctx->pc = 0x1D20F0u;
    // 0x1d20f0: 0x3c010032
    ctx->pc = 0x1d20f0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d20f4: 0x3c050025
    ctx->pc = 0x1d20f4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d20f8: 0x942743da
    ctx->pc = 0x1d20f8u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d20fc: 0x3c060025
    ctx->pc = 0x1d20fcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d2100: 0x27a40040
    ctx->pc = 0x1d2100u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2104: 0x24a56548
    ctx->pc = 0x1d2104u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 25928));
    // 0x1d2108: 0xc042a0c
    ctx->pc = 0x1D2108u;
    SET_GPR_U32(ctx, 31, 0x1D2110u);
    ctx->pc = 0x1D210Cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 25952));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2110u; }
    }
    if (ctx->pc != 0x1D2110u) { return; }
    ctx->pc = 0x1D2110u;
    // 0x1d2110: 0x240282d
    ctx->pc = 0x1d2110u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2114: 0x27a40040
    ctx->pc = 0x1d2114u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2118: 0xc073364
    ctx->pc = 0x1D2118u;
    SET_GPR_U32(ctx, 31, 0x1D2120u);
    ctx->pc = 0x1D211Cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1CCD90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCD90_0x1ccd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2120u; }
    }
    if (ctx->pc != 0x1D2120u) { return; }
    ctx->pc = 0x1D2120u;
    // 0x1d2120: 0x1000000c
    ctx->pc = 0x1D2120u;
    {
        const bool branch_taken_0x1d2120 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D2124u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x1d2120) {
            ctx->pc = 0x1D2154u;
            goto label_1d2154;
        }
    }
    ctx->pc = 0x1D2128u;
label_1d2128:
    // 0x1d2128: 0x3c050025
    ctx->pc = 0x1d2128u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d212c: 0x942643da
    ctx->pc = 0x1d212cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d2130: 0x27a40040
    ctx->pc = 0x1d2130u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2134: 0xc042a0c
    ctx->pc = 0x1D2134u;
    SET_GPR_U32(ctx, 31, 0x1D213Cu);
    ctx->pc = 0x1D2138u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 25984));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D213Cu; }
    }
    if (ctx->pc != 0x1D213Cu) { return; }
    ctx->pc = 0x1D213Cu;
    // 0x1d213c: 0x3c020001
    ctx->pc = 0x1d213cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d2140: 0x240282d
    ctx->pc = 0x1d2140u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2144: 0x27a40040
    ctx->pc = 0x1d2144u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d2148: 0xc073364
    ctx->pc = 0x1D2148u;
    SET_GPR_U32(ctx, 31, 0x1D2150u);
    ctx->pc = 0x1D214Cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1CCD90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCD90_0x1ccd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2150u; }
    }
    if (ctx->pc != 0x1D2150u) { return; }
    ctx->pc = 0x1D2150u;
label_1d2150:
    // 0x1d2150: 0xdfbf0030
    ctx->pc = 0x1d2150u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1d2154:
    // 0x1d2154: 0x7bb20020
    ctx->pc = 0x1d2154u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2158: 0x7bb10010
    ctx->pc = 0x1d2158u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d215c: 0x7bb00000
    ctx->pc = 0x1d215cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2160: 0x3e00008
    ctx->pc = 0x1D2160u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2164u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 320));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2038u: goto label_1d2038;
            case 0x1D20B0u: goto label_1d20b0;
            case 0x1D2128u: goto label_1d2128;
            case 0x1D2150u: goto label_1d2150;
            case 0x1D2154u: goto label_1d2154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2168u;
    // 0x1d2168: 0x0
    ctx->pc = 0x1d2168u;
    // NOP
    // 0x1d216c: 0x0
    ctx->pc = 0x1d216cu;
    // NOP
}
