#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141A78
// Address: 0x141a78 - 0x141b10
void sub_00141A78_0x141a78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141A78_0x141a78");
#endif

    switch (ctx->pc) {
        case 0x141aacu: goto label_141aac;
        case 0x141ab4u: goto label_141ab4;
        case 0x141accu: goto label_141acc;
        case 0x141ad4u: goto label_141ad4;
        case 0x141ae0u: goto label_141ae0;
        default: break;
    }

    ctx->pc = 0x141a78u;

    // 0x141a78: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x141a78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x141a7c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141a7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141a80: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x141a80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141a84: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141a84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141a88: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x141a88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141a8c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x141a8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x141a90: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x141a90u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141a94: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x141a94u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141a98: 0x10803c  dsll32      $s0, $s0, 0
    ctx->pc = 0x141a98u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
    // 0x141a9c: 0x10803f  dsra32      $s0, $s0, 0
    ctx->pc = 0x141a9cu;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 0));
    // 0x141aa0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x141aa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x141aa4: 0xc05065a  jal         func_141968
    ctx->pc = 0x141AA4u;
    SET_GPR_U32(ctx, 31, 0x141AACu);
    ctx->pc = 0x141AA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141AA4u;
            // 0x141aa8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141968u;
    if (runtime->hasFunction(0x141968u)) {
        auto targetFn = runtime->lookupFunction(0x141968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141AACu; }
        if (ctx->pc != 0x141AACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141968_0x141968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141AACu; }
        if (ctx->pc != 0x141AACu) { return; }
    }
    ctx->pc = 0x141AACu;
label_141aac:
    // 0x141aac: 0xc042c56  jal         func_10B158
    ctx->pc = 0x141AACu;
    SET_GPR_U32(ctx, 31, 0x141AB4u);
    ctx->pc = 0x141AB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141AACu;
            // 0x141ab0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141AB4u; }
        if (ctx->pc != 0x141AB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141AB4u; }
        if (ctx->pc != 0x141AB4u) { return; }
    }
    ctx->pc = 0x141AB4u;
label_141ab4:
    // 0x141ab4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x141ab4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x141ab8: 0x2028023  subu        $s0, $s0, $v0
    ctx->pc = 0x141ab8u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x141abc: 0x24a5dbf0  addiu       $a1, $a1, -0x2410
    ctx->pc = 0x141abcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958064));
    // 0x141ac0: 0x2606ffff  addiu       $a2, $s0, -0x1
    ctx->pc = 0x141ac0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x141ac4: 0xc042ca4  jal         func_10B290
    ctx->pc = 0x141AC4u;
    SET_GPR_U32(ctx, 31, 0x141ACCu);
    ctx->pc = 0x141AC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141AC4u;
            // 0x141ac8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B290u;
    if (runtime->hasFunction(0x10B290u)) {
        auto targetFn = runtime->lookupFunction(0x10B290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141ACCu; }
        if (ctx->pc != 0x141ACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B290_0x10b290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141ACCu; }
        if (ctx->pc != 0x141ACCu) { return; }
    }
    ctx->pc = 0x141ACCu;
label_141acc:
    // 0x141acc: 0xc042c56  jal         func_10B158
    ctx->pc = 0x141ACCu;
    SET_GPR_U32(ctx, 31, 0x141AD4u);
    ctx->pc = 0x141AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141ACCu;
            // 0x141ad0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141AD4u; }
        if (ctx->pc != 0x141AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141AD4u; }
        if (ctx->pc != 0x141AD4u) { return; }
    }
    ctx->pc = 0x141AD4u;
label_141ad4:
    // 0x141ad4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x141ad4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141ad8: 0xc042c56  jal         func_10B158
    ctx->pc = 0x141AD8u;
    SET_GPR_U32(ctx, 31, 0x141AE0u);
    ctx->pc = 0x141ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141AD8u;
            // 0x141adc: 0x2228821  addu        $s1, $s1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141AE0u; }
        if (ctx->pc != 0x141AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141AE0u; }
        if (ctx->pc != 0x141AE0u) { return; }
    }
    ctx->pc = 0x141AE0u;
label_141ae0:
    // 0x141ae0: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x141ae0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x141ae4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141ae4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141ae8: 0xc23023  subu        $a2, $a2, $v0
    ctx->pc = 0x141ae8u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x141aec: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x141aecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141af0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x141af0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141af4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141af4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141af8: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x141af8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x141afc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x141afcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141b00: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x141b00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x141b04: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x141b04u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x141b08: 0x805065a  j           func_141968
    ctx->pc = 0x141B08u;
    ctx->pc = 0x141B0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141B08u;
            // 0x141b0c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141968u;
    if (runtime->hasFunction(0x141968u)) {
        auto targetFn = runtime->lookupFunction(0x141968u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141968_0x141968(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141B10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
