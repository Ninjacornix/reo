#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001805B0
// Address: 0x1805b0 - 0x180680
void sub_001805B0_0x1805b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001805B0_0x1805b0");
#endif

    switch (ctx->pc) {
        case 0x1805d0u: goto label_1805d0;
        case 0x1805f8u: goto label_1805f8;
        case 0x180608u: goto label_180608;
        case 0x180634u: goto label_180634;
        case 0x180658u: goto label_180658;
        default: break;
    }

    ctx->pc = 0x1805b0u;

    // 0x1805b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1805b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1805b4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1805b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1805b8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1805b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1805bc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1805bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1805c0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1805c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1805c4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1805c4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1805c8: 0xc0601a0  jal         func_180680
    ctx->pc = 0x1805C8u;
    SET_GPR_U32(ctx, 31, 0x1805D0u);
    ctx->pc = 0x1805CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1805C8u;
            // 0x1805cc: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180680u;
    if (runtime->hasFunction(0x180680u)) {
        auto targetFn = runtime->lookupFunction(0x180680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1805D0u; }
        if (ctx->pc != 0x1805D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180680_0x180680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1805D0u; }
        if (ctx->pc != 0x1805D0u) { return; }
    }
    ctx->pc = 0x1805D0u;
label_1805d0:
    // 0x1805d0: 0x24030334  addiu       $v1, $zero, 0x334
    ctx->pc = 0x1805d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x1805d4: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x1805d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x1805d8: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x1805d8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1805dc: 0x24426188  addiu       $v0, $v0, 0x6188
    ctx->pc = 0x1805dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24968));
    // 0x1805e0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1805e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1805e4: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x1805e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1805e8: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1805E8u;
    {
        const bool branch_taken_0x1805e8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1805e8) {
            ctx->pc = 0x180600u;
            goto label_180600;
        }
    }
    ctx->pc = 0x1805F0u;
    // 0x1805f0: 0xc060246  jal         func_180918
    ctx->pc = 0x1805F0u;
    SET_GPR_U32(ctx, 31, 0x1805F8u);
    ctx->pc = 0x1805F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1805F0u;
            // 0x1805f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180918u;
    if (runtime->hasFunction(0x180918u)) {
        auto targetFn = runtime->lookupFunction(0x180918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1805F8u; }
        if (ctx->pc != 0x1805F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180918_0x180918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1805F8u; }
        if (ctx->pc != 0x1805F8u) { return; }
    }
    ctx->pc = 0x1805F8u;
label_1805f8:
    // 0x1805f8: 0x440001b  bltz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1805F8u;
    {
        const bool branch_taken_0x1805f8 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1805FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1805F8u;
            // 0x1805fc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1805f8) {
            ctx->pc = 0x180668u;
            goto label_180668;
        }
    }
    ctx->pc = 0x180600u;
label_180600:
    // 0x180600: 0xc060276  jal         func_1809D8
    ctx->pc = 0x180600u;
    SET_GPR_U32(ctx, 31, 0x180608u);
    ctx->pc = 0x180604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180600u;
            // 0x180604: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1809D8u;
    if (runtime->hasFunction(0x1809D8u)) {
        auto targetFn = runtime->lookupFunction(0x1809D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180608u; }
        if (ctx->pc != 0x180608u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001809D8_0x1809d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180608u; }
        if (ctx->pc != 0x180608u) { return; }
    }
    ctx->pc = 0x180608u;
label_180608:
    // 0x180608: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x180608u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18060c: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x18060cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x180610: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x180610u;
    {
        const bool branch_taken_0x180610 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x180614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180610u;
            // 0x180614: 0x2602001c  addiu       $v0, $s0, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180610) {
            ctx->pc = 0x180658u;
            goto label_180658;
        }
    }
    ctx->pc = 0x180618u;
    // 0x180618: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x180618u;
    {
        const bool branch_taken_0x180618 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18061Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180618u;
            // 0x18061c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180618) {
            ctx->pc = 0x180658u;
            goto label_180658;
        }
    }
    ctx->pc = 0x180620u;
    // 0x180620: 0x92050002  lbu         $a1, 0x2($s0)
    ctx->pc = 0x180620u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x180624: 0x92060003  lbu         $a2, 0x3($s0)
    ctx->pc = 0x180624u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x180628: 0xb02821  addu        $a1, $a1, $s0
    ctx->pc = 0x180628u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x18062c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x18062Cu;
    SET_GPR_U32(ctx, 31, 0x180634u);
    ctx->pc = 0x180630u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18062Cu;
            // 0x180630: 0x24a5001c  addiu       $a1, $a1, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180634u; }
        if (ctx->pc != 0x180634u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180634u; }
        if (ctx->pc != 0x180634u) { return; }
    }
    ctx->pc = 0x180634u;
label_180634:
    // 0x180634: 0x24030334  addiu       $v1, $zero, 0x334
    ctx->pc = 0x180634u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x180638: 0x92040002  lbu         $a0, 0x2($s0)
    ctx->pc = 0x180638u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x18063c: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x18063cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x180640: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x180640u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x180644: 0x2484001c  addiu       $a0, $a0, 0x1C
    ctx->pc = 0x180644u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28));
    // 0x180648: 0x24a5619c  addiu       $a1, $a1, 0x619C
    ctx->pc = 0x180648u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24988));
    // 0x18064c: 0x2042021  addu        $a0, $s0, $a0
    ctx->pc = 0x18064cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x180650: 0xc0602a8  jal         func_180AA0
    ctx->pc = 0x180650u;
    SET_GPR_U32(ctx, 31, 0x180658u);
    ctx->pc = 0x180654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180650u;
            // 0x180654: 0x652821  addu        $a1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180AA0u;
    if (runtime->hasFunction(0x180AA0u)) {
        auto targetFn = runtime->lookupFunction(0x180AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180658u; }
        if (ctx->pc != 0x180658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180AA0_0x180aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180658u; }
        if (ctx->pc != 0x180658u) { return; }
    }
    ctx->pc = 0x180658u;
label_180658:
    // 0x180658: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x180658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x18065c: 0x54400002  bnel        $v0, $zero, . + 4 + (0x2 << 2)
    ctx->pc = 0x18065Cu;
    {
        const bool branch_taken_0x18065c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18065c) {
            ctx->pc = 0x180660u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18065Cu;
            // 0x180660: 0x92020003  lbu         $v0, 0x3($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x180668u;
            goto label_180668;
        }
    }
    ctx->pc = 0x180664u;
    // 0x180664: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x180664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_180668:
    // 0x180668: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x180668u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18066c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x18066cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x180670: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x180670u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x180674: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x180674u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180678: 0x3e00008  jr          $ra
    ctx->pc = 0x180678u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18067Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180678u;
            // 0x18067c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1805D0u: goto label_1805d0;
            case 0x1805F8u: goto label_1805f8;
            case 0x180600u: goto label_180600;
            case 0x180608u: goto label_180608;
            case 0x180634u: goto label_180634;
            case 0x180658u: goto label_180658;
            case 0x180668u: goto label_180668;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180680u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
