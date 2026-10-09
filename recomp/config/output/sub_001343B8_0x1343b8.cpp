#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001343B8
// Address: 0x1343b8 - 0x134530
void sub_001343B8_0x1343b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001343B8_0x1343b8");
#endif

    switch (ctx->pc) {
        case 0x1343e8u: goto label_1343e8;
        case 0x1343f4u: goto label_1343f4;
        case 0x134414u: goto label_134414;
        case 0x134428u: goto label_134428;
        case 0x134458u: goto label_134458;
        case 0x134484u: goto label_134484;
        case 0x134498u: goto label_134498;
        case 0x1344b8u: goto label_1344b8;
        case 0x1344dcu: goto label_1344dc;
        case 0x1344ecu: goto label_1344ec;
        case 0x134504u: goto label_134504;
        default: break;
    }

    ctx->pc = 0x1343b8u;

    // 0x1343b8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1343b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1343bc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1343bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1343c0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1343c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1343c4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1343c4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1343c8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x1343c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1343cc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1343ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1343d0: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x1343d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x1343d4: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1343d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1343d8: 0x8e32000c  lw          $s2, 0xC($s1)
    ctx->pc = 0x1343d8u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1343dc: 0x8e340004  lw          $s4, 0x4($s1)
    ctx->pc = 0x1343dcu;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1343e0: 0xc04b1cc  jal         func_12C730
    ctx->pc = 0x1343E0u;
    SET_GPR_U32(ctx, 31, 0x1343E8u);
    ctx->pc = 0x1343E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1343E0u;
            // 0x1343e4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C730u;
    if (runtime->hasFunction(0x12C730u)) {
        auto targetFn = runtime->lookupFunction(0x12C730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1343E8u; }
        if (ctx->pc != 0x1343E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C730_0x12c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1343E8u; }
        if (ctx->pc != 0x1343E8u) { return; }
    }
    ctx->pc = 0x1343E8u;
label_1343e8:
    // 0x1343e8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1343e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1343ec: 0xc04b1d2  jal         func_12C748
    ctx->pc = 0x1343ECu;
    SET_GPR_U32(ctx, 31, 0x1343F4u);
    ctx->pc = 0x1343F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1343ECu;
            // 0x1343f0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C748u;
    if (runtime->hasFunction(0x12C748u)) {
        auto targetFn = runtime->lookupFunction(0x12C748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1343F4u; }
        if (ctx->pc != 0x1343F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C748_0x12c748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1343F4u; }
        if (ctx->pc != 0x1343F4u) { return; }
    }
    ctx->pc = 0x1343F4u;
label_1343f4:
    // 0x1343f4: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1343f4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1343f8: 0x8e220048  lw          $v0, 0x48($s1)
    ctx->pc = 0x1343f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x1343fc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1343fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x134400: 0x202802a  slt         $s0, $s0, $v0
    ctx->pc = 0x134400u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x134404: 0x5200000c  beql        $s0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x134404u;
    {
        const bool branch_taken_0x134404 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x134404) {
            ctx->pc = 0x134408u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134404u;
            // 0x134408: 0x82220070  lb          $v0, 0x70($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 112)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134438u;
            goto label_134438;
        }
    }
    ctx->pc = 0x13440Cu;
    // 0x13440c: 0xc04b5f6  jal         func_12D7D8
    ctx->pc = 0x13440Cu;
    SET_GPR_U32(ctx, 31, 0x134414u);
    ctx->pc = 0x134410u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13440Cu;
            // 0x134410: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7D8u;
    if (runtime->hasFunction(0x12D7D8u)) {
        auto targetFn = runtime->lookupFunction(0x12D7D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134414u; }
        if (ctx->pc != 0x134414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7D8_0x12d7d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134414u; }
        if (ctx->pc != 0x134414u) { return; }
    }
    ctx->pc = 0x134414u;
label_134414:
    // 0x134414: 0x53102a  slt         $v0, $v0, $s3
    ctx->pc = 0x134414u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x134418: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x134418u;
    {
        const bool branch_taken_0x134418 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134418) {
            ctx->pc = 0x13441Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134418u;
            // 0x13441c: 0x82220070  lb          $v0, 0x70($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 112)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134438u;
            goto label_134438;
        }
    }
    ctx->pc = 0x134420u;
    // 0x134420: 0xc04b2ee  jal         func_12CBB8
    ctx->pc = 0x134420u;
    SET_GPR_U32(ctx, 31, 0x134428u);
    ctx->pc = 0x134424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134420u;
            // 0x134424: 0x8e240004  lw          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CBB8u;
    if (runtime->hasFunction(0x12CBB8u)) {
        auto targetFn = runtime->lookupFunction(0x12CBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134428u; }
        if (ctx->pc != 0x134428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CBB8_0x12cbb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134428u; }
        if (ctx->pc != 0x134428u) { return; }
    }
    ctx->pc = 0x134428u;
label_134428:
    // 0x134428: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x134428u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x13442c: 0x14430013  bne         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x13442Cu;
    {
        const bool branch_taken_0x13442c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x13442c) {
            ctx->pc = 0x13447Cu;
            goto label_13447c;
        }
    }
    ctx->pc = 0x134434u;
    // 0x134434: 0x82220070  lb          $v0, 0x70($s1)
    ctx->pc = 0x134434u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 112)));
label_134438:
    // 0x134438: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x134438u;
    {
        const bool branch_taken_0x134438 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13443Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134438u;
            // 0x13443c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134438) {
            ctx->pc = 0x134478u;
            goto label_134478;
        }
    }
    ctx->pc = 0x134440u;
    // 0x134440: 0x82220072  lb          $v0, 0x72($s1)
    ctx->pc = 0x134440u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 114)));
    // 0x134444: 0x5440000a  bnel        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x134444u;
    {
        const bool branch_taken_0x134444 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x134444) {
            ctx->pc = 0x134448u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134444u;
            // 0x134448: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134470u;
            goto label_134470;
        }
    }
    ctx->pc = 0x13444Cu;
    // 0x13444c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13444cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134450: 0xc04b1c0  jal         func_12C700
    ctx->pc = 0x134450u;
    SET_GPR_U32(ctx, 31, 0x134458u);
    ctx->pc = 0x134454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134450u;
            // 0x134454: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C700u;
    if (runtime->hasFunction(0x12C700u)) {
        auto targetFn = runtime->lookupFunction(0x12C700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134458u; }
        if (ctx->pc != 0x134458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C700_0x12c700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134458u; }
        if (ctx->pc != 0x134458u) { return; }
    }
    ctx->pc = 0x134458u;
label_134458:
    // 0x134458: 0xae20009c  sw          $zero, 0x9C($s1)
    ctx->pc = 0x134458u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 156), GPR_U32(ctx, 0));
    // 0x13445c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x13445cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x134460: 0x2442f3c4  addiu       $v0, $v0, -0xC3C
    ctx->pc = 0x134460u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294964164));
    // 0x134464: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x134464u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x134468: 0xae2300a0  sw          $v1, 0xA0($s1)
    ctx->pc = 0x134468u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 160), GPR_U32(ctx, 3));
    // 0x13446c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x13446cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_134470:
    // 0x134470: 0xa2220001  sb          $v0, 0x1($s1)
    ctx->pc = 0x134470u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x134474: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x134474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_134478:
    // 0x134478: 0xa2220071  sb          $v0, 0x71($s1)
    ctx->pc = 0x134478u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 113), (uint8_t)GPR_U32(ctx, 2));
label_13447c:
    // 0x13447c: 0xc04b2ee  jal         func_12CBB8
    ctx->pc = 0x13447Cu;
    SET_GPR_U32(ctx, 31, 0x134484u);
    ctx->pc = 0x134480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13447Cu;
            // 0x134480: 0x8e240004  lw          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CBB8u;
    if (runtime->hasFunction(0x12CBB8u)) {
        auto targetFn = runtime->lookupFunction(0x12CBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134484u; }
        if (ctx->pc != 0x134484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CBB8_0x12cbb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134484u; }
        if (ctx->pc != 0x134484u) { return; }
    }
    ctx->pc = 0x134484u;
label_134484:
    // 0x134484: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x134484u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x134488: 0x14430021  bne         $v0, $v1, . + 4 + (0x21 << 2)
    ctx->pc = 0x134488u;
    {
        const bool branch_taken_0x134488 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x13448Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134488u;
            // 0x13448c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134488) {
            ctx->pc = 0x134510u;
            goto label_134510;
        }
    }
    ctx->pc = 0x134490u;
    // 0x134490: 0xc04c952  jal         func_132548
    ctx->pc = 0x134490u;
    SET_GPR_U32(ctx, 31, 0x134498u);
    ctx->pc = 0x134494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134490u;
            // 0x134494: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132548u;
    if (runtime->hasFunction(0x132548u)) {
        auto targetFn = runtime->lookupFunction(0x132548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134498u; }
        if (ctx->pc != 0x134498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132548_0x132548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134498u; }
        if (ctx->pc != 0x134498u) { return; }
    }
    ctx->pc = 0x134498u;
label_134498:
    // 0x134498: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x134498u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13449c: 0x8e220048  lw          $v0, 0x48($s1)
    ctx->pc = 0x13449cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x1344a0: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x1344a0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1344a4: 0x18600019  blez        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1344A4u;
    {
        const bool branch_taken_0x1344a4 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x1344A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1344A4u;
            // 0x1344a8: 0x29840  sll         $s3, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1344a4) {
            ctx->pc = 0x13450Cu;
            goto label_13450c;
        }
    }
    ctx->pc = 0x1344ACu;
    // 0x1344ac: 0x26320018  addiu       $s2, $s1, 0x18
    ctx->pc = 0x1344acu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 24));
    // 0x1344b0: 0x60882d  daddu       $s1, $v1, $zero
    ctx->pc = 0x1344b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1344b4: 0x8e500000  lw          $s0, 0x0($s2)
    ctx->pc = 0x1344b4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_1344b8:
    // 0x1344b8: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x1344b8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x1344bc: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x1344bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1344c0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1344c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1344c4: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1344c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1344c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1344c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1344cc: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1344ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1344d0: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x1344d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1344d4: 0x40f809  jalr        $v0
    ctx->pc = 0x1344D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1344DCu);
        ctx->pc = 0x1344D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1344D4u;
            // 0x1344d8: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1344DCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1343E8u: goto label_1343e8;
            case 0x1343F4u: goto label_1343f4;
            case 0x134414u: goto label_134414;
            case 0x134428u: goto label_134428;
            case 0x134438u: goto label_134438;
            case 0x134458u: goto label_134458;
            case 0x134470u: goto label_134470;
            case 0x134478u: goto label_134478;
            case 0x13447Cu: goto label_13447c;
            case 0x134484u: goto label_134484;
            case 0x134498u: goto label_134498;
            case 0x1344B8u: goto label_1344b8;
            case 0x1344DCu: goto label_1344dc;
            case 0x1344ECu: goto label_1344ec;
            case 0x134504u: goto label_134504;
            case 0x13450Cu: goto label_13450c;
            case 0x134510u: goto label_134510;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1344DCu; }
            if (ctx->pc != 0x1344DCu) { return; }
        }
        }
    }
    ctx->pc = 0x1344DCu;
label_1344dc:
    // 0x1344dc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1344dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1344e0: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1344e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1344e4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1344E4u;
    SET_GPR_U32(ctx, 31, 0x1344ECu);
    ctx->pc = 0x1344E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1344E4u;
            // 0x1344e8: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1344ECu; }
        if (ctx->pc != 0x1344ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1344ECu; }
        if (ctx->pc != 0x1344ECu) { return; }
    }
    ctx->pc = 0x1344ECu;
label_1344ec:
    // 0x1344ec: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1344ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1344f0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1344f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1344f4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1344f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1344f8: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x1344f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1344fc: 0x40f809  jalr        $v0
    ctx->pc = 0x1344FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x134504u);
        ctx->pc = 0x134500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1344FCu;
            // 0x134500: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x134504u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1343E8u: goto label_1343e8;
            case 0x1343F4u: goto label_1343f4;
            case 0x134414u: goto label_134414;
            case 0x134428u: goto label_134428;
            case 0x134438u: goto label_134438;
            case 0x134458u: goto label_134458;
            case 0x134470u: goto label_134470;
            case 0x134478u: goto label_134478;
            case 0x13447Cu: goto label_13447c;
            case 0x134484u: goto label_134484;
            case 0x134498u: goto label_134498;
            case 0x1344B8u: goto label_1344b8;
            case 0x1344DCu: goto label_1344dc;
            case 0x1344ECu: goto label_1344ec;
            case 0x134504u: goto label_134504;
            case 0x13450Cu: goto label_13450c;
            case 0x134510u: goto label_134510;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x134504u; }
            if (ctx->pc != 0x134504u) { return; }
        }
        }
    }
    ctx->pc = 0x134504u;
label_134504:
    // 0x134504: 0x5620ffec  bnel        $s1, $zero, . + 4 + (-0x14 << 2)
    ctx->pc = 0x134504u;
    {
        const bool branch_taken_0x134504 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x134504) {
            ctx->pc = 0x134508u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134504u;
            // 0x134508: 0x8e500000  lw          $s0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1344B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1344b8;
        }
    }
    ctx->pc = 0x13450Cu;
label_13450c:
    // 0x13450c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13450cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_134510:
    // 0x134510: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x134510u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x134514: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x134514u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x134518: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x134518u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13451c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x13451cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x134520: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x134520u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x134524: 0x3e00008  jr          $ra
    ctx->pc = 0x134524u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134524u;
            // 0x134528: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1343E8u: goto label_1343e8;
            case 0x1343F4u: goto label_1343f4;
            case 0x134414u: goto label_134414;
            case 0x134428u: goto label_134428;
            case 0x134438u: goto label_134438;
            case 0x134458u: goto label_134458;
            case 0x134470u: goto label_134470;
            case 0x134478u: goto label_134478;
            case 0x13447Cu: goto label_13447c;
            case 0x134484u: goto label_134484;
            case 0x134498u: goto label_134498;
            case 0x1344B8u: goto label_1344b8;
            case 0x1344DCu: goto label_1344dc;
            case 0x1344ECu: goto label_1344ec;
            case 0x134504u: goto label_134504;
            case 0x13450Cu: goto label_13450c;
            case 0x134510u: goto label_134510;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13452Cu;
    // 0x13452c: 0x0  nop
    ctx->pc = 0x13452cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
