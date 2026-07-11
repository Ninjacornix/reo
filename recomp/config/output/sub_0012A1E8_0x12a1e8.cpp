#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0012A1E8
// Address: 0x12a1e8 - 0x12a388
void sub_0012A1E8_0x12a1e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12a1e8u;

label_12a1e8:
    // 0x12a1e8: 0x27bdfff0
    ctx->pc = 0x12a1e8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a1ec: 0x3c020021
    ctx->pc = 0x12a1ecu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a1f0: 0xffb00000
    ctx->pc = 0x12a1f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a1f4: 0x3c100021
    ctx->pc = 0x12a1f4u;
    SET_GPR_U32(ctx, 16, ((uint32_t)33 << 16));
    // 0x12a1f8: 0xffbf0008
    ctx->pc = 0x12a1f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12a1fc: 0x2442f398
    ctx->pc = 0x12a1fcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294964120));
    // 0x12a200: 0x8e03f3b0
    ctx->pc = 0x12a200u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4294964144)));
    // 0x12a204: 0x8c440000
    ctx->pc = 0x12a204u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12a208: 0x5460004f
    ctx->pc = 0x12A208u;
    {
        const bool branch_taken_0x12a208 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x12a208) {
            ctx->pc = 0x12A20Cu;
            SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 16), 4294964144));
            ctx->pc = 0x12A348u;
            goto label_12a348;
        }
    }
    ctx->pc = 0x12A210u;
    // 0x12a210: 0xc049934
    ctx->pc = 0x12A210u;
    SET_GPR_U32(ctx, 31, 0x12A218u);
    ctx->pc = 0x1264D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264D0_0x1264d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A218u; }
    }
    if (ctx->pc != 0x12A218u) { return; }
    ctx->pc = 0x12A218u;
    // 0x12a218: 0xc049938
    ctx->pc = 0x12A218u;
    SET_GPR_U32(ctx, 31, 0x12A220u);
    ctx->pc = 0x1264E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A220u; }
    }
    if (ctx->pc != 0x12A220u) { return; }
    ctx->pc = 0x12A220u;
    // 0x12a220: 0xc050008
    ctx->pc = 0x12A220u;
    SET_GPR_U32(ctx, 31, 0x12A228u);
    ctx->pc = 0x140020u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00140020_0x140020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A228u; }
    }
    if (ctx->pc != 0x12A228u) { return; }
    ctx->pc = 0x12A228u;
    // 0x12a228: 0xc04fdfe
    ctx->pc = 0x12A228u;
    SET_GPR_U32(ctx, 31, 0x12A230u);
    ctx->pc = 0x13F7F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F7F8_0x13f7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A230u; }
    }
    if (ctx->pc != 0x12A230u) { return; }
    ctx->pc = 0x12A230u;
    // 0x12a230: 0xc04fcb0
    ctx->pc = 0x12A230u;
    SET_GPR_U32(ctx, 31, 0x12A238u);
    ctx->pc = 0x13F2C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F2C0_0x13f2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A238u; }
    }
    if (ctx->pc != 0x12A238u) { return; }
    ctx->pc = 0x12A238u;
    // 0x12a238: 0xc04a00e
    ctx->pc = 0x12A238u;
    SET_GPR_U32(ctx, 31, 0x12A240u);
    ctx->pc = 0x128038u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00128038_0x128038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A240u; }
    }
    if (ctx->pc != 0x12A240u) { return; }
    ctx->pc = 0x12A240u;
    // 0x12a240: 0xc04c032
    ctx->pc = 0x12A240u;
    SET_GPR_U32(ctx, 31, 0x12A248u);
    ctx->pc = 0x1300C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001300C8_0x1300c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A248u; }
    }
    if (ctx->pc != 0x12A248u) { return; }
    ctx->pc = 0x12A248u;
    // 0x12a248: 0xc04b252
    ctx->pc = 0x12A248u;
    SET_GPR_U32(ctx, 31, 0x12A250u);
    ctx->pc = 0x12C948u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C948_0x12c948(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A250u; }
    }
    if (ctx->pc != 0x12A250u) { return; }
    ctx->pc = 0x12A250u;
    // 0x12a250: 0xc04a0d2
    ctx->pc = 0x12A250u;
    SET_GPR_U32(ctx, 31, 0x12A258u);
    ctx->pc = 0x128348u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00128348_0x128348(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A258u; }
    }
    if (ctx->pc != 0x12A258u) { return; }
    ctx->pc = 0x12A258u;
    // 0x12a258: 0xc04b18c
    ctx->pc = 0x12A258u;
    SET_GPR_U32(ctx, 31, 0x12A260u);
    ctx->pc = 0x12C630u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C630_0x12c630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A260u; }
    }
    if (ctx->pc != 0x12A260u) { return; }
    ctx->pc = 0x12A260u;
    // 0x12a260: 0xc04f566
    ctx->pc = 0x12A260u;
    SET_GPR_U32(ctx, 31, 0x12A268u);
    ctx->pc = 0x13D598u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D598_0x13d598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A268u; }
    }
    if (ctx->pc != 0x12A268u) { return; }
    ctx->pc = 0x12A268u;
    // 0x12a268: 0xc05083e
    ctx->pc = 0x12A268u;
    SET_GPR_U32(ctx, 31, 0x12A270u);
    ctx->pc = 0x1420F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001420F8_0x1420f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A270u; }
    }
    if (ctx->pc != 0x12A270u) { return; }
    ctx->pc = 0x12A270u;
    // 0x12a270: 0x3c040013
    ctx->pc = 0x12a270u;
    SET_GPR_U32(ctx, 4, ((uint32_t)19 << 16));
    // 0x12a274: 0x282d
    ctx->pc = 0x12a274u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a278: 0xc04b198
    ctx->pc = 0x12A278u;
    SET_GPR_U32(ctx, 31, 0x12A280u);
    ctx->pc = 0x12A27Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294942976));
    ctx->pc = 0x12C660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C660_0x12c660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A280u; }
    }
    if (ctx->pc != 0x12A280u) { return; }
    ctx->pc = 0x12A280u;
    // 0x12a280: 0x3c040013
    ctx->pc = 0x12a280u;
    SET_GPR_U32(ctx, 4, ((uint32_t)19 << 16));
    // 0x12a284: 0x2484a118
    ctx->pc = 0x12a284u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294943000));
    // 0x12a288: 0xc04f534
    ctx->pc = 0x12A288u;
    SET_GPR_U32(ctx, 31, 0x12A290u);
    ctx->pc = 0x12A28Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x13D4D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4D0_0x13d4d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A290u; }
    }
    if (ctx->pc != 0x12A290u) { return; }
    ctx->pc = 0x12A290u;
    // 0x12a290: 0x3c040021
    ctx->pc = 0x12a290u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x12a294: 0x2484f3c8
    ctx->pc = 0x12a294u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294964168));
    // 0x12a298: 0x282d
    ctx->pc = 0x12a298u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a29c: 0xc041f1a
    ctx->pc = 0x12A29Cu;
    SET_GPR_U32(ctx, 31, 0x12A2A4u);
    ctx->pc = 0x12A2A0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 3136));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A2A4u; }
    }
    if (ctx->pc != 0x12A2A4u) { return; }
    ctx->pc = 0x12A2A4u;
    // 0x12a2a4: 0xc04ad84
    ctx->pc = 0x12A2A4u;
    SET_GPR_U32(ctx, 31, 0x12A2ACu);
    ctx->pc = 0x12B610u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B610_0x12b610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A2ACu; }
    }
    if (ctx->pc != 0x12A2ACu) { return; }
    ctx->pc = 0x12A2ACu;
    // 0x12a2ac: 0x40382d
    ctx->pc = 0x12a2acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a2b0: 0x24020001
    ctx->pc = 0x12a2b0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a2b4: 0x3c050013
    ctx->pc = 0x12a2b4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)19 << 16));
    // 0x12a2b8: 0x24040005
    ctx->pc = 0x12a2b8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    // 0x12a2bc: 0x24a5a178
    ctx->pc = 0x12a2bcu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294943096));
    // 0x12a2c0: 0x14e20015
    ctx->pc = 0x12A2C0u;
    {
        const bool branch_taken_0x12a2c0 = (GPR_U32(ctx, 7) != GPR_U32(ctx, 2));
        ctx->pc = 0x12A2C4u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x12a2c0) {
            ctx->pc = 0x12A318u;
            goto label_12a318;
        }
    }
    ctx->pc = 0x12A2C8u;
    // 0x12a2c8: 0x3c020021
    ctx->pc = 0x12a2c8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a2cc: 0x8c43f3bc
    ctx->pc = 0x12a2ccu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4294964156)));
    // 0x12a2d0: 0x14670011
    ctx->pc = 0x12A2D0u;
    {
        const bool branch_taken_0x12a2d0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 7));
        ctx->pc = 0x12A2D4u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x12a2d0) {
            ctx->pc = 0x12A318u;
            goto label_12a318;
        }
    }
    ctx->pc = 0x12A2D8u;
    // 0x12a2d8: 0x3c060013
    ctx->pc = 0x12a2d8u;
    SET_GPR_U32(ctx, 6, ((uint32_t)19 << 16));
    // 0x12a2dc: 0x24040002
    ctx->pc = 0x12a2dcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
    // 0x12a2e0: 0x24050001
    ctx->pc = 0x12a2e0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a2e4: 0xc050716
    ctx->pc = 0x12A2E4u;
    SET_GPR_U32(ctx, 31, 0x12A2ECu);
    ctx->pc = 0x12A2E8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 4294943144));
    ctx->pc = 0x141C58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141C58_0x141c58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A2ECu; }
    }
    if (ctx->pc != 0x12A2ECu) { return; }
    ctx->pc = 0x12A2ECu;
    // 0x12a2ec: 0x3c050013
    ctx->pc = 0x12a2ecu;
    SET_GPR_U32(ctx, 5, ((uint32_t)19 << 16));
    // 0x12a2f0: 0x24a5a1c8
    ctx->pc = 0x12a2f0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294943176));
    // 0x12a2f4: 0x24040004
    ctx->pc = 0x12a2f4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    // 0x12a2f8: 0xc0506c4
    ctx->pc = 0x12A2F8u;
    SET_GPR_U32(ctx, 31, 0x12A300u);
    ctx->pc = 0x12A2FCu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x141B10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141B10_0x141b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A300u; }
    }
    if (ctx->pc != 0x12A300u) { return; }
    ctx->pc = 0x12A300u;
    // 0x12a300: 0x3c030021
    ctx->pc = 0x12a300u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12a304: 0x3c050013
    ctx->pc = 0x12a304u;
    SET_GPR_U32(ctx, 5, ((uint32_t)19 << 16));
    // 0x12a308: 0x24040005
    ctx->pc = 0x12a308u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    // 0x12a30c: 0x24a5a158
    ctx->pc = 0x12a30cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294943064));
    // 0x12a310: 0x302d
    ctx->pc = 0x12a310u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a314: 0x0
    ctx->pc = 0x12a314u;
    // NOP
label_12a318:
    // 0x12a318: 0xc0506c4
    ctx->pc = 0x12A318u;
    SET_GPR_U32(ctx, 31, 0x12A320u);
    ctx->pc = 0x141B10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141B10_0x141b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A320u; }
    }
    if (ctx->pc != 0x12A320u) { return; }
    ctx->pc = 0x12A320u;
    // 0x12a320: 0x3c030021
    ctx->pc = 0x12a320u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12a324: 0xac62f3b8
    ctx->pc = 0x12a324u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294964152), GPR_U32(ctx, 2));
    // 0x12a328: 0x3c020021
    ctx->pc = 0x12a328u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a32c: 0x2404003c
    ctx->pc = 0x12a32cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 60));
    // 0x12a330: 0x2442f3c4
    ctx->pc = 0x12a330u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294964164));
    // 0x12a334: 0xc04ca2a
    ctx->pc = 0x12A334u;
    SET_GPR_U32(ctx, 31, 0x12A33Cu);
    ctx->pc = 0x1328A8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001328A8_0x1328a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A33Cu; }
    }
    if (ctx->pc != 0x12A33Cu) { return; }
    ctx->pc = 0x12A33Cu;
    // 0x12a33c: 0xc04993e
    ctx->pc = 0x12A33Cu;
    SET_GPR_U32(ctx, 31, 0x12A344u);
    ctx->pc = 0x1264F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A344u; }
    }
    if (ctx->pc != 0x12A344u) { return; }
    ctx->pc = 0x12A344u;
    // 0x12a344: 0x2603f3b0
    ctx->pc = 0x12a344u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 16), 4294964144));
label_12a348:
    // 0x12a348: 0xdfb00000
    ctx->pc = 0x12a348u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a34c: 0x8c620000
    ctx->pc = 0x12a34cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a350: 0xdfbf0008
    ctx->pc = 0x12a350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a354: 0x24420001
    ctx->pc = 0x12a354u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x12a358: 0xac620000
    ctx->pc = 0x12a358u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x12a35c: 0x3e00008
    ctx->pc = 0x12A35Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A360u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A1E8u: goto label_12a1e8;
            case 0x12A318u: goto label_12a318;
            case 0x12A348u: goto label_12a348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A364u;
    // 0x12a364: 0x0
    ctx->pc = 0x12a364u;
    // NOP
    // 0x12a368: 0x27bdfff0
    ctx->pc = 0x12a368u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a36c: 0x3c020021
    ctx->pc = 0x12a36cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a370: 0xffbf0000
    ctx->pc = 0x12a370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a374: 0xac40f3b0
    ctx->pc = 0x12a374u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294964144), GPR_U32(ctx, 0));
    // 0x12a378: 0xdfbf0000
    ctx->pc = 0x12a378u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a37c: 0x804a87a
    ctx->pc = 0x12A37Cu;
    ctx->pc = 0x12A380u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12A1E8u;
    goto label_12a1e8;
    ctx->pc = 0x12A384u;
    // 0x12a384: 0x0
    ctx->pc = 0x12a384u;
    // NOP
}
