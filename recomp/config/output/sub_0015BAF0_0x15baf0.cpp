#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BAF0
// Address: 0x15baf0 - 0x15bba0
void sub_0015BAF0_0x15baf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BAF0_0x15baf0");
#endif

    switch (ctx->pc) {
        case 0x15bb38u: goto label_15bb38;
        case 0x15bb44u: goto label_15bb44;
        case 0x15bb50u: goto label_15bb50;
        case 0x15bb5cu: goto label_15bb5c;
        case 0x15bb68u: goto label_15bb68;
        case 0x15bb78u: goto label_15bb78;
        case 0x15bb80u: goto label_15bb80;
        case 0x15bb88u: goto label_15bb88;
        default: break;
    }

    ctx->pc = 0x15baf0u;

    // 0x15baf0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15baf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15baf4: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x15baf4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15baf8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15baf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15bafc: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x15bafcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bb00: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15bb00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15bb04: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15bb04u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bb08: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15bb08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15bb0c: 0x16400008  bnez        $s2, . + 4 + (0x8 << 2)
    ctx->pc = 0x15BB0Cu;
    {
        const bool branch_taken_0x15bb0c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x15BB10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB0Cu;
            // 0x15bb10: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bb0c) {
            ctx->pc = 0x15BB30u;
            goto label_15bb30;
        }
    }
    ctx->pc = 0x15BB14u;
    // 0x15bb14: 0x711826  xor         $v1, $v1, $s1
    ctx->pc = 0x15bb14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 17));
    // 0x15bb18: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x15bb18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x15bb1c: 0x28630000  slti        $v1, $v1, 0x0
    ctx->pc = 0x15bb1cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15bb20: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x15bb20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x15bb24: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x15bb24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x15bb28: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x15BB28u;
    {
        const bool branch_taken_0x15bb28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15BB2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB28u;
            // 0x15bb2c: 0x83100b  movn        $v0, $a0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bb28) {
            ctx->pc = 0x15BB88u;
            goto label_15bb88;
        }
    }
    ctx->pc = 0x15BB30u;
label_15bb30:
    // 0x15bb30: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x15BB30u;
    SET_GPR_U32(ctx, 31, 0x15BB38u);
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB38u; }
        if (ctx->pc != 0x15BB38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB38u; }
        if (ctx->pc != 0x15BB38u) { return; }
    }
    ctx->pc = 0x15BB38u;
label_15bb38:
    // 0x15bb38: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15bb38u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bb3c: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x15BB3Cu;
    SET_GPR_U32(ctx, 31, 0x15BB44u);
    ctx->pc = 0x15BB40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB3Cu;
            // 0x15bb40: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB44u; }
        if (ctx->pc != 0x15BB44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB44u; }
        if (ctx->pc != 0x15BB44u) { return; }
    }
    ctx->pc = 0x15BB44u;
label_15bb44:
    // 0x15bb44: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15bb44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bb48: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x15BB48u;
    SET_GPR_U32(ctx, 31, 0x15BB50u);
    ctx->pc = 0x15BB4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB48u;
            // 0x15bb4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB50u; }
        if (ctx->pc != 0x15BB50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB50u; }
        if (ctx->pc != 0x15BB50u) { return; }
    }
    ctx->pc = 0x15BB50u;
label_15bb50:
    // 0x15bb50: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15bb50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bb54: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x15BB54u;
    SET_GPR_U32(ctx, 31, 0x15BB5Cu);
    ctx->pc = 0x15BB58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB54u;
            // 0x15bb58: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB5Cu; }
        if (ctx->pc != 0x15BB5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB5Cu; }
        if (ctx->pc != 0x15BB5Cu) { return; }
    }
    ctx->pc = 0x15BB5Cu;
label_15bb5c:
    // 0x15bb5c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15bb5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bb60: 0xc04480e  jal         func_112038
    ctx->pc = 0x15BB60u;
    SET_GPR_U32(ctx, 31, 0x15BB68u);
    ctx->pc = 0x15BB64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB60u;
            // 0x15bb64: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB68u; }
        if (ctx->pc != 0x15BB68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB68u; }
        if (ctx->pc != 0x15BB68u) { return; }
    }
    ctx->pc = 0x15BB68u;
label_15bb68:
    // 0x15bb68: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x15bb68u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x15bb6c: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x15bb6cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x15bb70: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x15BB70u;
    SET_GPR_U32(ctx, 31, 0x15BB78u);
    ctx->pc = 0x15BB74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB70u;
            // 0x15bb74: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB78u; }
        if (ctx->pc != 0x15BB78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB78u; }
        if (ctx->pc != 0x15BB78u) { return; }
    }
    ctx->pc = 0x15BB78u;
label_15bb78:
    // 0x15bb78: 0xc0487ca  jal         func_121F28
    ctx->pc = 0x15BB78u;
    SET_GPR_U32(ctx, 31, 0x15BB80u);
    ctx->pc = 0x15BB7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB78u;
            // 0x15bb7c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x121F28u;
    if (runtime->hasFunction(0x121F28u)) {
        auto targetFn = runtime->lookupFunction(0x121F28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB80u; }
        if (ctx->pc != 0x15BB80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121F28_0x121f28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB80u; }
        if (ctx->pc != 0x15BB80u) { return; }
    }
    ctx->pc = 0x15BB80u;
label_15bb80:
    // 0x15bb80: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x15BB80u;
    SET_GPR_U32(ctx, 31, 0x15BB88u);
    ctx->pc = 0x15BB84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB80u;
            // 0x15bb84: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB88u; }
        if (ctx->pc != 0x15BB88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BB88u; }
        if (ctx->pc != 0x15BB88u) { return; }
    }
    ctx->pc = 0x15BB88u;
label_15bb88:
    // 0x15bb88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15bb88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15bb8c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15bb8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15bb90: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15bb90u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15bb94: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15bb94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15bb98: 0x3e00008  jr          $ra
    ctx->pc = 0x15BB98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BB9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BB98u;
            // 0x15bb9c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15BB30u: goto label_15bb30;
            case 0x15BB38u: goto label_15bb38;
            case 0x15BB44u: goto label_15bb44;
            case 0x15BB50u: goto label_15bb50;
            case 0x15BB5Cu: goto label_15bb5c;
            case 0x15BB68u: goto label_15bb68;
            case 0x15BB78u: goto label_15bb78;
            case 0x15BB80u: goto label_15bb80;
            case 0x15BB88u: goto label_15bb88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15BBA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
