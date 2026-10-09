#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A1E8
// Address: 0x12a1e8 - 0x12a388
void sub_0012A1E8_0x12a1e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A1E8_0x12a1e8");
#endif

    switch (ctx->pc) {
        case 0x12a218u: goto label_12a218;
        case 0x12a220u: goto label_12a220;
        case 0x12a228u: goto label_12a228;
        case 0x12a230u: goto label_12a230;
        case 0x12a238u: goto label_12a238;
        case 0x12a240u: goto label_12a240;
        case 0x12a248u: goto label_12a248;
        case 0x12a250u: goto label_12a250;
        case 0x12a258u: goto label_12a258;
        case 0x12a260u: goto label_12a260;
        case 0x12a268u: goto label_12a268;
        case 0x12a270u: goto label_12a270;
        case 0x12a280u: goto label_12a280;
        case 0x12a290u: goto label_12a290;
        case 0x12a2a4u: goto label_12a2a4;
        case 0x12a2acu: goto label_12a2ac;
        case 0x12a2ecu: goto label_12a2ec;
        case 0x12a300u: goto label_12a300;
        case 0x12a320u: goto label_12a320;
        case 0x12a33cu: goto label_12a33c;
        case 0x12a344u: goto label_12a344;
        default: break;
    }

    ctx->pc = 0x12a1e8u;

label_12a1e8:
    // 0x12a1e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a1e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a1ec: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a1ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a1f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12a1f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a1f4: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x12a1f4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x12a1f8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12a1f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12a1fc: 0x2442f398  addiu       $v0, $v0, -0xC68
    ctx->pc = 0x12a1fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294964120));
    // 0x12a200: 0x8e03f3b0  lw          $v1, -0xC50($s0)
    ctx->pc = 0x12a200u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294964144)));
    // 0x12a204: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x12a204u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12a208: 0x5460004f  bnel        $v1, $zero, . + 4 + (0x4F << 2)
    ctx->pc = 0x12A208u;
    {
        const bool branch_taken_0x12a208 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12a208) {
            ctx->pc = 0x12A20Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12A208u;
            // 0x12a20c: 0x2603f3b0  addiu       $v1, $s0, -0xC50 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294964144));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12A348u;
            goto label_12a348;
        }
    }
    ctx->pc = 0x12A210u;
    // 0x12a210: 0xc049934  jal         func_1264D0
    ctx->pc = 0x12A210u;
    SET_GPR_U32(ctx, 31, 0x12A218u);
    ctx->pc = 0x1264D0u;
    if (runtime->hasFunction(0x1264D0u)) {
        auto targetFn = runtime->lookupFunction(0x1264D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A218u; }
        if (ctx->pc != 0x12A218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264D0_0x1264d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A218u; }
        if (ctx->pc != 0x12A218u) { return; }
    }
    ctx->pc = 0x12A218u;
label_12a218:
    // 0x12a218: 0xc049938  jal         func_1264E0
    ctx->pc = 0x12A218u;
    SET_GPR_U32(ctx, 31, 0x12A220u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A220u; }
        if (ctx->pc != 0x12A220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A220u; }
        if (ctx->pc != 0x12A220u) { return; }
    }
    ctx->pc = 0x12A220u;
label_12a220:
    // 0x12a220: 0xc050008  jal         func_140020
    ctx->pc = 0x12A220u;
    SET_GPR_U32(ctx, 31, 0x12A228u);
    ctx->pc = 0x140020u;
    if (runtime->hasFunction(0x140020u)) {
        auto targetFn = runtime->lookupFunction(0x140020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A228u; }
        if (ctx->pc != 0x12A228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140020_0x140020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A228u; }
        if (ctx->pc != 0x12A228u) { return; }
    }
    ctx->pc = 0x12A228u;
label_12a228:
    // 0x12a228: 0xc04fdfe  jal         func_13F7F8
    ctx->pc = 0x12A228u;
    SET_GPR_U32(ctx, 31, 0x12A230u);
    ctx->pc = 0x13F7F8u;
    if (runtime->hasFunction(0x13F7F8u)) {
        auto targetFn = runtime->lookupFunction(0x13F7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A230u; }
        if (ctx->pc != 0x12A230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F7F8_0x13f7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A230u; }
        if (ctx->pc != 0x12A230u) { return; }
    }
    ctx->pc = 0x12A230u;
label_12a230:
    // 0x12a230: 0xc04fcb0  jal         func_13F2C0
    ctx->pc = 0x12A230u;
    SET_GPR_U32(ctx, 31, 0x12A238u);
    ctx->pc = 0x13F2C0u;
    if (runtime->hasFunction(0x13F2C0u)) {
        auto targetFn = runtime->lookupFunction(0x13F2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A238u; }
        if (ctx->pc != 0x12A238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F2C0_0x13f2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A238u; }
        if (ctx->pc != 0x12A238u) { return; }
    }
    ctx->pc = 0x12A238u;
label_12a238:
    // 0x12a238: 0xc04a00e  jal         func_128038
    ctx->pc = 0x12A238u;
    SET_GPR_U32(ctx, 31, 0x12A240u);
    ctx->pc = 0x128038u;
    if (runtime->hasFunction(0x128038u)) {
        auto targetFn = runtime->lookupFunction(0x128038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A240u; }
        if (ctx->pc != 0x12A240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128038_0x128038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A240u; }
        if (ctx->pc != 0x12A240u) { return; }
    }
    ctx->pc = 0x12A240u;
label_12a240:
    // 0x12a240: 0xc04c032  jal         func_1300C8
    ctx->pc = 0x12A240u;
    SET_GPR_U32(ctx, 31, 0x12A248u);
    ctx->pc = 0x1300C8u;
    if (runtime->hasFunction(0x1300C8u)) {
        auto targetFn = runtime->lookupFunction(0x1300C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A248u; }
        if (ctx->pc != 0x12A248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001300C8_0x1300c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A248u; }
        if (ctx->pc != 0x12A248u) { return; }
    }
    ctx->pc = 0x12A248u;
label_12a248:
    // 0x12a248: 0xc04b252  jal         func_12C948
    ctx->pc = 0x12A248u;
    SET_GPR_U32(ctx, 31, 0x12A250u);
    ctx->pc = 0x12C948u;
    if (runtime->hasFunction(0x12C948u)) {
        auto targetFn = runtime->lookupFunction(0x12C948u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A250u; }
        if (ctx->pc != 0x12A250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C948_0x12c948(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A250u; }
        if (ctx->pc != 0x12A250u) { return; }
    }
    ctx->pc = 0x12A250u;
label_12a250:
    // 0x12a250: 0xc04a0d2  jal         func_128348
    ctx->pc = 0x12A250u;
    SET_GPR_U32(ctx, 31, 0x12A258u);
    ctx->pc = 0x128348u;
    if (runtime->hasFunction(0x128348u)) {
        auto targetFn = runtime->lookupFunction(0x128348u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A258u; }
        if (ctx->pc != 0x12A258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128348_0x128348(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A258u; }
        if (ctx->pc != 0x12A258u) { return; }
    }
    ctx->pc = 0x12A258u;
label_12a258:
    // 0x12a258: 0xc04b18c  jal         func_12C630
    ctx->pc = 0x12A258u;
    SET_GPR_U32(ctx, 31, 0x12A260u);
    ctx->pc = 0x12C630u;
    if (runtime->hasFunction(0x12C630u)) {
        auto targetFn = runtime->lookupFunction(0x12C630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A260u; }
        if (ctx->pc != 0x12A260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C630_0x12c630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A260u; }
        if (ctx->pc != 0x12A260u) { return; }
    }
    ctx->pc = 0x12A260u;
label_12a260:
    // 0x12a260: 0xc04f566  jal         func_13D598
    ctx->pc = 0x12A260u;
    SET_GPR_U32(ctx, 31, 0x12A268u);
    ctx->pc = 0x13D598u;
    if (runtime->hasFunction(0x13D598u)) {
        auto targetFn = runtime->lookupFunction(0x13D598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A268u; }
        if (ctx->pc != 0x12A268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D598_0x13d598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A268u; }
        if (ctx->pc != 0x12A268u) { return; }
    }
    ctx->pc = 0x12A268u;
label_12a268:
    // 0x12a268: 0xc05083e  jal         func_1420F8
    ctx->pc = 0x12A268u;
    SET_GPR_U32(ctx, 31, 0x12A270u);
    ctx->pc = 0x1420F8u;
    if (runtime->hasFunction(0x1420F8u)) {
        auto targetFn = runtime->lookupFunction(0x1420F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A270u; }
        if (ctx->pc != 0x12A270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001420F8_0x1420f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A270u; }
        if (ctx->pc != 0x12A270u) { return; }
    }
    ctx->pc = 0x12A270u;
label_12a270:
    // 0x12a270: 0x3c040013  lui         $a0, 0x13
    ctx->pc = 0x12a270u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)19 << 16));
    // 0x12a274: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12a274u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a278: 0xc04b198  jal         func_12C660
    ctx->pc = 0x12A278u;
    SET_GPR_U32(ctx, 31, 0x12A280u);
    ctx->pc = 0x12A27Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A278u;
            // 0x12a27c: 0x2484a100  addiu       $a0, $a0, -0x5F00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C660u;
    if (runtime->hasFunction(0x12C660u)) {
        auto targetFn = runtime->lookupFunction(0x12C660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A280u; }
        if (ctx->pc != 0x12A280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C660_0x12c660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A280u; }
        if (ctx->pc != 0x12A280u) { return; }
    }
    ctx->pc = 0x12A280u;
label_12a280:
    // 0x12a280: 0x3c040013  lui         $a0, 0x13
    ctx->pc = 0x12a280u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)19 << 16));
    // 0x12a284: 0x2484a118  addiu       $a0, $a0, -0x5EE8
    ctx->pc = 0x12a284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943000));
    // 0x12a288: 0xc04f534  jal         func_13D4D0
    ctx->pc = 0x12A288u;
    SET_GPR_U32(ctx, 31, 0x12A290u);
    ctx->pc = 0x12A28Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A288u;
            // 0x12a28c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4D0u;
    if (runtime->hasFunction(0x13D4D0u)) {
        auto targetFn = runtime->lookupFunction(0x13D4D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A290u; }
        if (ctx->pc != 0x12A290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4D0_0x13d4d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A290u; }
        if (ctx->pc != 0x12A290u) { return; }
    }
    ctx->pc = 0x12A290u;
label_12a290:
    // 0x12a290: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12a290u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12a294: 0x2484f3c8  addiu       $a0, $a0, -0xC38
    ctx->pc = 0x12a294u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964168));
    // 0x12a298: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12a298u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a29c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x12A29Cu;
    SET_GPR_U32(ctx, 31, 0x12A2A4u);
    ctx->pc = 0x12A2A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A29Cu;
            // 0x12a2a0: 0x24060c40  addiu       $a2, $zero, 0xC40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A2A4u; }
        if (ctx->pc != 0x12A2A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A2A4u; }
        if (ctx->pc != 0x12A2A4u) { return; }
    }
    ctx->pc = 0x12A2A4u;
label_12a2a4:
    // 0x12a2a4: 0xc04ad84  jal         func_12B610
    ctx->pc = 0x12A2A4u;
    SET_GPR_U32(ctx, 31, 0x12A2ACu);
    ctx->pc = 0x12B610u;
    if (runtime->hasFunction(0x12B610u)) {
        auto targetFn = runtime->lookupFunction(0x12B610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A2ACu; }
        if (ctx->pc != 0x12A2ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B610_0x12b610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A2ACu; }
        if (ctx->pc != 0x12A2ACu) { return; }
    }
    ctx->pc = 0x12A2ACu;
label_12a2ac:
    // 0x12a2ac: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x12a2acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a2b0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12a2b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a2b4: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12a2b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12a2b8: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x12a2b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x12a2bc: 0x24a5a178  addiu       $a1, $a1, -0x5E88
    ctx->pc = 0x12a2bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294943096));
    // 0x12a2c0: 0x14e20015  bne         $a3, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x12A2C0u;
    {
        const bool branch_taken_0x12a2c0 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x12A2C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A2C0u;
            // 0x12a2c4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a2c0) {
            ctx->pc = 0x12A318u;
            goto label_12a318;
        }
    }
    ctx->pc = 0x12A2C8u;
    // 0x12a2c8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a2c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a2cc: 0x8c43f3bc  lw          $v1, -0xC44($v0)
    ctx->pc = 0x12a2ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294964156)));
    // 0x12a2d0: 0x14670011  bne         $v1, $a3, . + 4 + (0x11 << 2)
    ctx->pc = 0x12A2D0u;
    {
        const bool branch_taken_0x12a2d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 7));
        ctx->pc = 0x12A2D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A2D0u;
            // 0x12a2d4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a2d0) {
            ctx->pc = 0x12A318u;
            goto label_12a318;
        }
    }
    ctx->pc = 0x12A2D8u;
    // 0x12a2d8: 0x3c060013  lui         $a2, 0x13
    ctx->pc = 0x12a2d8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)19 << 16));
    // 0x12a2dc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x12a2dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12a2e0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12a2e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a2e4: 0xc050716  jal         func_141C58
    ctx->pc = 0x12A2E4u;
    SET_GPR_U32(ctx, 31, 0x12A2ECu);
    ctx->pc = 0x12A2E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A2E4u;
            // 0x12a2e8: 0x24c6a1a8  addiu       $a2, $a2, -0x5E58 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141C58u;
    if (runtime->hasFunction(0x141C58u)) {
        auto targetFn = runtime->lookupFunction(0x141C58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A2ECu; }
        if (ctx->pc != 0x12A2ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141C58_0x141c58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A2ECu; }
        if (ctx->pc != 0x12A2ECu) { return; }
    }
    ctx->pc = 0x12A2ECu;
label_12a2ec:
    // 0x12a2ec: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12a2ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12a2f0: 0x24a5a1c8  addiu       $a1, $a1, -0x5E38
    ctx->pc = 0x12a2f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294943176));
    // 0x12a2f4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x12a2f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12a2f8: 0xc0506c4  jal         func_141B10
    ctx->pc = 0x12A2F8u;
    SET_GPR_U32(ctx, 31, 0x12A300u);
    ctx->pc = 0x12A2FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A2F8u;
            // 0x12a2fc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141B10u;
    if (runtime->hasFunction(0x141B10u)) {
        auto targetFn = runtime->lookupFunction(0x141B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A300u; }
        if (ctx->pc != 0x12A300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141B10_0x141b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A300u; }
        if (ctx->pc != 0x12A300u) { return; }
    }
    ctx->pc = 0x12A300u;
label_12a300:
    // 0x12a300: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12a300u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12a304: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12a304u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12a308: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x12a308u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x12a30c: 0x24a5a158  addiu       $a1, $a1, -0x5EA8
    ctx->pc = 0x12a30cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294943064));
    // 0x12a310: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x12a310u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a314: 0xac62f3c0  sw          $v0, -0xC40($v1)
    ctx->pc = 0x12a314u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294964160), GPR_U32(ctx, 2));
label_12a318:
    // 0x12a318: 0xc0506c4  jal         func_141B10
    ctx->pc = 0x12A318u;
    SET_GPR_U32(ctx, 31, 0x12A320u);
    ctx->pc = 0x141B10u;
    if (runtime->hasFunction(0x141B10u)) {
        auto targetFn = runtime->lookupFunction(0x141B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A320u; }
        if (ctx->pc != 0x12A320u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141B10_0x141b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A320u; }
        if (ctx->pc != 0x12A320u) { return; }
    }
    ctx->pc = 0x12A320u;
label_12a320:
    // 0x12a320: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12a320u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12a324: 0xac62f3b8  sw          $v0, -0xC48($v1)
    ctx->pc = 0x12a324u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294964152), GPR_U32(ctx, 2));
    // 0x12a328: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a328u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a32c: 0x2404003c  addiu       $a0, $zero, 0x3C
    ctx->pc = 0x12a32cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x12a330: 0x2442f3c4  addiu       $v0, $v0, -0xC3C
    ctx->pc = 0x12a330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294964164));
    // 0x12a334: 0xc04ca2a  jal         func_1328A8
    ctx->pc = 0x12A334u;
    SET_GPR_U32(ctx, 31, 0x12A33Cu);
    ctx->pc = 0x12A338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A334u;
            // 0x12a338: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1328A8u;
    if (runtime->hasFunction(0x1328A8u)) {
        auto targetFn = runtime->lookupFunction(0x1328A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A33Cu; }
        if (ctx->pc != 0x12A33Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001328A8_0x1328a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A33Cu; }
        if (ctx->pc != 0x12A33Cu) { return; }
    }
    ctx->pc = 0x12A33Cu;
label_12a33c:
    // 0x12a33c: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x12A33Cu;
    SET_GPR_U32(ctx, 31, 0x12A344u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A344u; }
        if (ctx->pc != 0x12A344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A344u; }
        if (ctx->pc != 0x12A344u) { return; }
    }
    ctx->pc = 0x12A344u;
label_12a344:
    // 0x12a344: 0x2603f3b0  addiu       $v1, $s0, -0xC50
    ctx->pc = 0x12a344u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294964144));
label_12a348:
    // 0x12a348: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a348u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a34c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12a34cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a350: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12a350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a354: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12a354u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12a358: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x12a358u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x12a35c: 0x3e00008  jr          $ra
    ctx->pc = 0x12A35Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A35Cu;
            // 0x12a360: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A1E8u: goto label_12a1e8;
            case 0x12A218u: goto label_12a218;
            case 0x12A220u: goto label_12a220;
            case 0x12A228u: goto label_12a228;
            case 0x12A230u: goto label_12a230;
            case 0x12A238u: goto label_12a238;
            case 0x12A240u: goto label_12a240;
            case 0x12A248u: goto label_12a248;
            case 0x12A250u: goto label_12a250;
            case 0x12A258u: goto label_12a258;
            case 0x12A260u: goto label_12a260;
            case 0x12A268u: goto label_12a268;
            case 0x12A270u: goto label_12a270;
            case 0x12A280u: goto label_12a280;
            case 0x12A290u: goto label_12a290;
            case 0x12A2A4u: goto label_12a2a4;
            case 0x12A2ACu: goto label_12a2ac;
            case 0x12A2ECu: goto label_12a2ec;
            case 0x12A300u: goto label_12a300;
            case 0x12A318u: goto label_12a318;
            case 0x12A320u: goto label_12a320;
            case 0x12A33Cu: goto label_12a33c;
            case 0x12A344u: goto label_12a344;
            case 0x12A348u: goto label_12a348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A364u;
    // 0x12a364: 0x0  nop
    ctx->pc = 0x12a364u;
    // NOP
    // 0x12a368: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a368u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a36c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a36cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a370: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a374: 0xac40f3b0  sw          $zero, -0xC50($v0)
    ctx->pc = 0x12a374u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294964144), GPR_U32(ctx, 0));
    // 0x12a378: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a378u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a37c: 0x804a87a  j           func_12A1E8
    ctx->pc = 0x12A37Cu;
    ctx->pc = 0x12A380u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A37Cu;
            // 0x12a380: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A1E8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_12a1e8;
    ctx->pc = 0x12A384u;
    // 0x12a384: 0x0  nop
    ctx->pc = 0x12a384u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
