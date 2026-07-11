#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001BD0B0
// Address: 0x1bd0b0 - 0x1bd2f0
void sub_001BD0B0_0x1bd0b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1bd0b0u;

    // 0x1bd0b0: 0x27bdffa0
    ctx->pc = 0x1bd0b0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1bd0b4: 0x24020001
    ctx->pc = 0x1bd0b4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd0b8: 0xffbf0000
    ctx->pc = 0x1bd0b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bd0bc: 0x27a40040
    ctx->pc = 0x1bd0bcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1bd0c0: 0xafa20044
    ctx->pc = 0x1bd0c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
    // 0x1bd0c4: 0xafa00048
    ctx->pc = 0x1bd0c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 0));
    // 0x1bd0c8: 0xc045188
    ctx->pc = 0x1BD0C8u;
    SET_GPR_U32(ctx, 31, 0x1BD0D0u);
    ctx->pc = 0x1BD0CCu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 0));
    ctx->pc = 0x114620u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD0D0u; }
    }
    if (ctx->pc != 0x1BD0D0u) { return; }
    ctx->pc = 0x1BD0D0u;
    // 0x1bd0d0: 0x3c010023
    ctx->pc = 0x1bd0d0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bd0d4: 0xc045144
    ctx->pc = 0x1BD0D4u;
    SET_GPR_U32(ctx, 31, 0x1BD0DCu);
    ctx->pc = 0x1BD0D8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20496), GPR_U32(ctx, 2));
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD0DCu; }
    }
    if (ctx->pc != 0x1BD0DCu) { return; }
    ctx->pc = 0x1BD0DCu;
    // 0x1bd0dc: 0x40202d
    ctx->pc = 0x1bd0dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd0e0: 0xc04512c
    ctx->pc = 0x1BD0E0u;
    SET_GPR_U32(ctx, 31, 0x1BD0E8u);
    ctx->pc = 0x1BD0E4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x1144B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD0E8u; }
    }
    if (ctx->pc != 0x1BD0E8u) { return; }
    ctx->pc = 0x1BD0E8u;
    // 0x1bd0e8: 0x24022000
    ctx->pc = 0x1bd0e8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1bd0ec: 0x3c030026
    ctx->pc = 0x1bd0ecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
    // 0x1bd0f0: 0xafa2001c
    ctx->pc = 0x1bd0f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x1bd0f4: 0x24631cf0
    ctx->pc = 0x1bd0f4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 7408));
    // 0x1bd0f8: 0x3c02001c
    ctx->pc = 0x1bd0f8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)28 << 16));
    // 0x1bd0fc: 0xafa30020
    ctx->pc = 0x1bd0fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    // 0x1bd100: 0x2442d160
    ctx->pc = 0x1bd100u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294955360));
    // 0x1bd104: 0x3c030032
    ctx->pc = 0x1bd104u;
    SET_GPR_U32(ctx, 3, ((uint32_t)50 << 16));
    // 0x1bd108: 0xafa20014
    ctx->pc = 0x1bd108u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x1bd10c: 0x24634880
    ctx->pc = 0x1bd10cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 18560));
    // 0x1bd110: 0x24020001
    ctx->pc = 0x1bd110u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd114: 0xafa30018
    ctx->pc = 0x1bd114u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x1bd118: 0x27a40010
    ctx->pc = 0x1bd118u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    // 0x1bd11c: 0xc045108
    ctx->pc = 0x1BD11Cu;
    SET_GPR_U32(ctx, 31, 0x1BD124u);
    ctx->pc = 0x1BD120u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
    ctx->pc = 0x114420u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD124u; }
    }
    if (ctx->pc != 0x1BD124u) { return; }
    ctx->pc = 0x1BD124u;
    // 0x1bd124: 0x3c010023
    ctx->pc = 0x1bd124u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bd128: 0xac225018
    ctx->pc = 0x1bd128u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20504), GPR_U32(ctx, 2));
    // 0x1bd12c: 0x3c010023
    ctx->pc = 0x1bd12cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bd130: 0x8c245018
    ctx->pc = 0x1bd130u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 20504)));
    // 0x1bd134: 0x3c010023
    ctx->pc = 0x1bd134u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bd138: 0xc045110
    ctx->pc = 0x1BD138u;
    SET_GPR_U32(ctx, 31, 0x1BD140u);
    ctx->pc = 0x1BD13Cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 20496)));
    ctx->pc = 0x114440u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD140u; }
    }
    if (ctx->pc != 0x1BD140u) { return; }
    ctx->pc = 0x1BD140u;
    // 0x1bd140: 0x3c010023
    ctx->pc = 0x1bd140u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bd144: 0x3c04001c
    ctx->pc = 0x1bd144u;
    SET_GPR_U32(ctx, 4, ((uint32_t)28 << 16));
    // 0x1bd148: 0x8c255010
    ctx->pc = 0x1bd148u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 20496)));
    // 0x1bd14c: 0xc0461ac
    ctx->pc = 0x1BD14Cu;
    SET_GPR_U32(ctx, 31, 0x1BD154u);
    ctx->pc = 0x1BD150u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294955744));
    ctx->pc = 0x1186B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001186B0_0x1186b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD154u; }
    }
    if (ctx->pc != 0x1BD154u) { return; }
    ctx->pc = 0x1BD154u;
    // 0x1bd154: 0xdfbf0000
    ctx->pc = 0x1bd154u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd158: 0x3e00008
    ctx->pc = 0x1BD158u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD15Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD1D0u: goto label_1bd1d0;
            case 0x1BD200u: goto label_1bd200;
            case 0x1BD21Cu: goto label_1bd21c;
            case 0x1BD24Cu: goto label_1bd24c;
            case 0x1BD274u: goto label_1bd274;
            case 0x1BD29Cu: goto label_1bd29c;
            case 0x1BD2C4u: goto label_1bd2c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD160u;
    // 0x1bd160: 0x27bdfff0
    ctx->pc = 0x1bd160u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bd164: 0xffbf0000
    ctx->pc = 0x1bd164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bd168: 0xc045198
    ctx->pc = 0x1BD168u;
    SET_GPR_U32(ctx, 31, 0x1BD170u);
    ctx->pc = 0x114660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD170u; }
    }
    if (ctx->pc != 0x1BD170u) { return; }
    ctx->pc = 0x1BD170u;
    // 0x1bd170: 0xc0dea90
    ctx->pc = 0x1BD170u;
    SET_GPR_U32(ctx, 31, 0x1BD178u);
    ctx->pc = 0x37AA40u;
    {
        auto targetFn = runtime->lookupFunction(0x37AA40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD178u; }
        if (ctx->pc != 0x1BD178u) { return; }
    }
    ctx->pc = 0x1BD178u;
    // 0x1bd178: 0x3c040025
    ctx->pc = 0x1bd178u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bd17c: 0xc0470f8
    ctx->pc = 0x1BD17Cu;
    SET_GPR_U32(ctx, 31, 0x1BD184u);
    ctx->pc = 0x1BD180u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1032));
    ctx->pc = 0x11C3E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C3E0_0x11c3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD184u; }
    }
    if (ctx->pc != 0x1BD184u) { return; }
    ctx->pc = 0x1BD184u;
    // 0x1bd184: 0x4400031
    ctx->pc = 0x1BD184u;
    {
        const bool branch_taken_0x1bd184 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1bd184) {
            ctx->pc = 0x1BD24Cu;
            goto label_1bd24c;
        }
    }
    ctx->pc = 0x1BD18Cu;
    // 0x1bd18c: 0x3c040025
    ctx->pc = 0x1bd18cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bd190: 0x24054807
    ctx->pc = 0x1bd190u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 18439));
    // 0x1bd194: 0x24840410
    ctx->pc = 0x1bd194u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1040));
    // 0x1bd198: 0x302d
    ctx->pc = 0x1bd198u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd19c: 0x382d
    ctx->pc = 0x1bd19cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1a0: 0x402d
    ctx->pc = 0x1bd1a0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1a4: 0xc046c92
    ctx->pc = 0x1BD1A4u;
    SET_GPR_U32(ctx, 31, 0x1BD1ACu);
    ctx->pc = 0x1BD1A8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11B248u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD1ACu; }
    }
    if (ctx->pc != 0x1BD1ACu) { return; }
    ctx->pc = 0x1BD1ACu;
    // 0x1bd1ac: 0x3c010032
    ctx->pc = 0x1bd1acu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bd1b0: 0xac2244f8
    ctx->pc = 0x1bd1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17656), GPR_U32(ctx, 2));
    // 0x1bd1b4: 0x3c010032
    ctx->pc = 0x1bd1b4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bd1b8: 0x24020003
    ctx->pc = 0x1bd1b8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1bd1bc: 0x8c2344f8
    ctx->pc = 0x1bd1bcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 17656)));
    // 0x1bd1c0: 0x10620003
    ctx->pc = 0x1BD1C0u;
    {
        const bool branch_taken_0x1bd1c0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x1bd1c0) {
            ctx->pc = 0x1BD1D0u;
            goto label_1bd1d0;
        }
    }
    ctx->pc = 0x1BD1C8u;
    // 0x1bd1c8: 0x1000000d
    ctx->pc = 0x1BD1C8u;
    {
        const bool branch_taken_0x1bd1c8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1BD1CCu;
        SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
        if (branch_taken_0x1bd1c8) {
            ctx->pc = 0x1BD200u;
            goto label_1bd200;
        }
    }
    ctx->pc = 0x1BD1D0u;
label_1bd1d0:
    // 0x1bd1d0: 0x3c040025
    ctx->pc = 0x1bd1d0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bd1d4: 0x24054402
    ctx->pc = 0x1bd1d4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 17410));
    // 0x1bd1d8: 0x24840418
    ctx->pc = 0x1bd1d8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1048));
    // 0x1bd1dc: 0x302d
    ctx->pc = 0x1bd1dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1e0: 0x382d
    ctx->pc = 0x1bd1e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1e4: 0x402d
    ctx->pc = 0x1bd1e4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd1e8: 0xc046c92
    ctx->pc = 0x1BD1E8u;
    SET_GPR_U32(ctx, 31, 0x1BD1F0u);
    ctx->pc = 0x1BD1ECu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11B248u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD1F0u; }
    }
    if (ctx->pc != 0x1BD1F0u) { return; }
    ctx->pc = 0x1BD1F0u;
    // 0x1bd1f0: 0x440fff7
    ctx->pc = 0x1BD1F0u;
    {
        const bool branch_taken_0x1bd1f0 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1bd1f0) {
            ctx->pc = 0x1BD1D0u;
            goto label_1bd1d0;
        }
    }
    ctx->pc = 0x1BD1F8u;
    // 0x1bd1f8: 0x1000001e
    ctx->pc = 0x1BD1F8u;
    {
        const bool branch_taken_0x1bd1f8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1bd1f8) {
            ctx->pc = 0x1BD274u;
            goto label_1bd274;
        }
    }
    ctx->pc = 0x1BD200u;
label_1bd200:
    // 0x1bd200: 0x24055003
    ctx->pc = 0x1bd200u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 20483));
    // 0x1bd204: 0x24840420
    ctx->pc = 0x1bd204u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1056));
    // 0x1bd208: 0x302d
    ctx->pc = 0x1bd208u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd20c: 0x382d
    ctx->pc = 0x1bd20cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd210: 0x402d
    ctx->pc = 0x1bd210u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd214: 0xc046c92
    ctx->pc = 0x1BD214u;
    SET_GPR_U32(ctx, 31, 0x1BD21Cu);
    ctx->pc = 0x1BD218u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11B248u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD21Cu; }
    }
    if (ctx->pc != 0x1BD21Cu) { return; }
    ctx->pc = 0x1BD21Cu;
label_1bd21c:
    // 0x1bd21c: 0x3c040025
    ctx->pc = 0x1bd21cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bd220: 0x24054806
    ctx->pc = 0x1bd220u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 18438));
    // 0x1bd224: 0x24840410
    ctx->pc = 0x1bd224u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1040));
    // 0x1bd228: 0x302d
    ctx->pc = 0x1bd228u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd22c: 0x382d
    ctx->pc = 0x1bd22cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd230: 0x402d
    ctx->pc = 0x1bd230u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd234: 0xc046c92
    ctx->pc = 0x1BD234u;
    SET_GPR_U32(ctx, 31, 0x1BD23Cu);
    ctx->pc = 0x1BD238u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11B248u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD23Cu; }
    }
    if (ctx->pc != 0x1BD23Cu) { return; }
    ctx->pc = 0x1BD23Cu;
    // 0x1bd23c: 0x440fff7
    ctx->pc = 0x1BD23Cu;
    {
        const bool branch_taken_0x1bd23c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1bd23c) {
            ctx->pc = 0x1BD21Cu;
            goto label_1bd21c;
        }
    }
    ctx->pc = 0x1BD244u;
    // 0x1bd244: 0x1000000b
    ctx->pc = 0x1BD244u;
    {
        const bool branch_taken_0x1bd244 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1bd244) {
            ctx->pc = 0x1BD274u;
            goto label_1bd274;
        }
    }
    ctx->pc = 0x1BD24Cu;
label_1bd24c:
    // 0x1bd24c: 0x3c040025
    ctx->pc = 0x1bd24cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bd250: 0x24054402
    ctx->pc = 0x1bd250u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 17410));
    // 0x1bd254: 0x24840418
    ctx->pc = 0x1bd254u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1048));
    // 0x1bd258: 0x302d
    ctx->pc = 0x1bd258u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd25c: 0x382d
    ctx->pc = 0x1bd25cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd260: 0x402d
    ctx->pc = 0x1bd260u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd264: 0xc046c92
    ctx->pc = 0x1BD264u;
    SET_GPR_U32(ctx, 31, 0x1BD26Cu);
    ctx->pc = 0x1BD268u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11B248u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD26Cu; }
    }
    if (ctx->pc != 0x1BD26Cu) { return; }
    ctx->pc = 0x1BD26Cu;
    // 0x1bd26c: 0x440fff7
    ctx->pc = 0x1BD26Cu;
    {
        const bool branch_taken_0x1bd26c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1bd26c) {
            ctx->pc = 0x1BD24Cu;
            goto label_1bd24c;
        }
    }
    ctx->pc = 0x1BD274u;
label_1bd274:
    // 0x1bd274: 0x3c040025
    ctx->pc = 0x1bd274u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bd278: 0x24054328
    ctx->pc = 0x1bd278u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 17192));
    // 0x1bd27c: 0x24840428
    ctx->pc = 0x1bd27cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1064));
    // 0x1bd280: 0x302d
    ctx->pc = 0x1bd280u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd284: 0x382d
    ctx->pc = 0x1bd284u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd288: 0x402d
    ctx->pc = 0x1bd288u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd28c: 0xc046c92
    ctx->pc = 0x1BD28Cu;
    SET_GPR_U32(ctx, 31, 0x1BD294u);
    ctx->pc = 0x1BD290u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11B248u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD294u; }
    }
    if (ctx->pc != 0x1BD294u) { return; }
    ctx->pc = 0x1BD294u;
    // 0x1bd294: 0x440fff7
    ctx->pc = 0x1BD294u;
    {
        const bool branch_taken_0x1bd294 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1bd294) {
            ctx->pc = 0x1BD274u;
            goto label_1bd274;
        }
    }
    ctx->pc = 0x1BD29Cu;
label_1bd29c:
    // 0x1bd29c: 0x3c040025
    ctx->pc = 0x1bd29cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bd2a0: 0x24054323
    ctx->pc = 0x1bd2a0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 17187));
    // 0x1bd2a4: 0x24840428
    ctx->pc = 0x1bd2a4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1064));
    // 0x1bd2a8: 0x302d
    ctx->pc = 0x1bd2a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd2ac: 0x382d
    ctx->pc = 0x1bd2acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd2b0: 0x402d
    ctx->pc = 0x1bd2b0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd2b4: 0xc046c92
    ctx->pc = 0x1BD2B4u;
    SET_GPR_U32(ctx, 31, 0x1BD2BCu);
    ctx->pc = 0x1BD2B8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11B248u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD2BCu; }
    }
    if (ctx->pc != 0x1BD2BCu) { return; }
    ctx->pc = 0x1BD2BCu;
    // 0x1bd2bc: 0x440fff7
    ctx->pc = 0x1BD2BCu;
    {
        const bool branch_taken_0x1bd2bc = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1bd2bc) {
            ctx->pc = 0x1BD29Cu;
            goto label_1bd29c;
        }
    }
    ctx->pc = 0x1BD2C4u;
label_1bd2c4:
    // 0x1bd2c4: 0x0
    ctx->pc = 0x1bd2c4u;
    // NOP
    // 0x1bd2c8: 0x0
    ctx->pc = 0x1bd2c8u;
    // NOP
    // 0x1bd2cc: 0x0
    ctx->pc = 0x1bd2ccu;
    // NOP
    // 0x1bd2d0: 0x0
    ctx->pc = 0x1bd2d0u;
    // NOP
    // 0x1bd2d4: 0x0
    ctx->pc = 0x1bd2d4u;
    // NOP
    // 0x1bd2d8: 0x1000fffa
    ctx->pc = 0x1BD2D8u;
    {
        const bool branch_taken_0x1bd2d8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1bd2d8) {
            ctx->pc = 0x1BD2C4u;
            goto label_1bd2c4;
        }
    }
    ctx->pc = 0x1BD2E0u;
    // 0x1bd2e0: 0x8045194
    ctx->pc = 0x1BD2E0u;
    ctx->pc = 0x114650u;
    sub_00114650_0x114650(rdram, ctx, runtime); return;
    ctx->pc = 0x1BD2E8u;
    // 0x1bd2e8: 0x0
    ctx->pc = 0x1bd2e8u;
    // NOP
    // 0x1bd2ec: 0x0
    ctx->pc = 0x1bd2ecu;
    // NOP
}
