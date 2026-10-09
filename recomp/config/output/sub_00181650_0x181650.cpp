#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181650
// Address: 0x181650 - 0x181708
void sub_00181650_0x181650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181650_0x181650");
#endif

    switch (ctx->pc) {
        case 0x181688u: goto label_181688;
        case 0x1816b8u: goto label_1816b8;
        case 0x1816e0u: goto label_1816e0;
        case 0x1816ecu: goto label_1816ec;
        default: break;
    }

    ctx->pc = 0x181650u;

    // 0x181650: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x181650u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x181654: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181654u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181658: 0x8c66fa10  lw          $a2, -0x5F0($v1)
    ctx->pc = 0x181658u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x18165c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18165cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181660: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x181660u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x181664: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x181664u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181668: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x181668u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x18166c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x18166cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181670: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x181670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x181674: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x181674u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
    // 0x181678: 0x10c0001d  beqz        $a2, . + 4 + (0x1D << 2)
    ctx->pc = 0x181678u;
    {
        const bool branch_taken_0x181678 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x18167Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181678u;
            // 0x18167c: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181678) {
            ctx->pc = 0x1816F0u;
            goto label_1816f0;
        }
    }
    ctx->pc = 0x181680u;
    // 0x181680: 0xc061e90  jal         func_187A40
    ctx->pc = 0x181680u;
    SET_GPR_U32(ctx, 31, 0x181688u);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181688u; }
        if (ctx->pc != 0x181688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181688u; }
        if (ctx->pc != 0x181688u) { return; }
    }
    ctx->pc = 0x181688u;
label_181688:
    // 0x181688: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x181688u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x18168c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18168Cu;
    {
        const bool branch_taken_0x18168c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18168Cu;
            // 0x181690: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18168c) {
            ctx->pc = 0x1816A0u;
            goto label_1816a0;
        }
    }
    ctx->pc = 0x181694u;
    // 0x181694: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181694u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181698: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x181698u;
    {
        const bool branch_taken_0x181698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18169Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181698u;
            // 0x18169c: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181698) {
            ctx->pc = 0x1816F0u;
            goto label_1816f0;
        }
    }
    ctx->pc = 0x1816A0u;
label_1816a0:
    // 0x1816a0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1816a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1816a4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1816a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1816a8: 0x14600011  bnez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1816A8u;
    {
        const bool branch_taken_0x1816a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1816ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1816A8u;
            // 0x1816ac: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1816a8) {
            ctx->pc = 0x1816F0u;
            goto label_1816f0;
        }
    }
    ctx->pc = 0x1816B0u;
    // 0x1816b0: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1816B0u;
    SET_GPR_U32(ctx, 31, 0x1816B8u);
    ctx->pc = 0x1816B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1816B0u;
            // 0x1816b4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1816B8u; }
        if (ctx->pc != 0x1816B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1816B8u; }
        if (ctx->pc != 0x1816B8u) { return; }
    }
    ctx->pc = 0x1816B8u;
label_1816b8:
    // 0x1816b8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1816b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1816bc: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x1816bcu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1816c0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1816c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1816c4: 0x2604041c  addiu       $a0, $s0, 0x41C
    ctx->pc = 0x1816c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
    // 0x1816c8: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1816C8u;
    {
        const bool branch_taken_0x1816c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1816CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1816C8u;
            // 0x1816cc: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1816c8) {
            ctx->pc = 0x1816F0u;
            goto label_1816f0;
        }
    }
    ctx->pc = 0x1816D0u;
    // 0x1816d0: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x1816d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1816d4: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x1816d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x1816d8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1816D8u;
    SET_GPR_U32(ctx, 31, 0x1816E0u);
    ctx->pc = 0x1816DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1816D8u;
            // 0x1816dc: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1816E0u; }
        if (ctx->pc != 0x1816E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1816E0u; }
        if (ctx->pc != 0x1816E0u) { return; }
    }
    ctx->pc = 0x1816E0u;
label_1816e0:
    // 0x1816e0: 0x34038427  ori         $v1, $zero, 0x8427
    ctx->pc = 0x1816e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33831);
    // 0x1816e4: 0xc062228  jal         func_1888A0
    ctx->pc = 0x1816E4u;
    SET_GPR_U32(ctx, 31, 0x1816ECu);
    ctx->pc = 0x1816E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1816E4u;
            // 0x1816e8: 0xae03000c  sw          $v1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1816ECu; }
        if (ctx->pc != 0x1816ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1816ECu; }
        if (ctx->pc != 0x1816ECu) { return; }
    }
    ctx->pc = 0x1816ECu;
label_1816ec:
    // 0x1816ec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1816ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1816f0:
    // 0x1816f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1816f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1816f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1816f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1816f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1816f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1816fc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1816fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x181700: 0x3e00008  jr          $ra
    ctx->pc = 0x181700u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181700u;
            // 0x181704: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181688u: goto label_181688;
            case 0x1816A0u: goto label_1816a0;
            case 0x1816B8u: goto label_1816b8;
            case 0x1816E0u: goto label_1816e0;
            case 0x1816ECu: goto label_1816ec;
            case 0x1816F0u: goto label_1816f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181708u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
