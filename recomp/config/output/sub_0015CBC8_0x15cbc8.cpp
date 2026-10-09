#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015CBC8
// Address: 0x15cbc8 - 0x15cc58
void sub_0015CBC8_0x15cbc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015CBC8_0x15cbc8");
#endif

    switch (ctx->pc) {
        case 0x15cbe8u: goto label_15cbe8;
        case 0x15cc10u: goto label_15cc10;
        case 0x15cc20u: goto label_15cc20;
        case 0x15cc30u: goto label_15cc30;
        case 0x15cc40u: goto label_15cc40;
        default: break;
    }

    ctx->pc = 0x15cbc8u;

    // 0x15cbc8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15cbc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15cbcc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15cbccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15cbd0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15cbd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cbd4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15cbd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15cbd8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15cbd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15cbdc: 0x8e300040  lw          $s0, 0x40($s1)
    ctx->pc = 0x15cbdcu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x15cbe0: 0xc05ceca  jal         func_173B28
    ctx->pc = 0x15CBE0u;
    SET_GPR_U32(ctx, 31, 0x15CBE8u);
    ctx->pc = 0x15CBE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CBE0u;
            // 0x15cbe4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173B28u;
    if (runtime->hasFunction(0x173B28u)) {
        auto targetFn = runtime->lookupFunction(0x173B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CBE8u; }
        if (ctx->pc != 0x15CBE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173B28_0x173b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CBE8u; }
        if (ctx->pc != 0x15CBE8u) { return; }
    }
    ctx->pc = 0x15CBE8u;
label_15cbe8:
    // 0x15cbe8: 0x3c050016  lui         $a1, 0x16
    ctx->pc = 0x15cbe8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22 << 16));
    // 0x15cbec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15cbecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cbf0: 0x24a5ec08  addiu       $a1, $a1, -0x13F8
    ctx->pc = 0x15cbf0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962184));
    // 0x15cbf4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15CBF4u;
    {
        const bool branch_taken_0x15cbf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CBF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CBF4u;
            // 0x15cbf8: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cbf4) {
            ctx->pc = 0x15CC08u;
            goto label_15cc08;
        }
    }
    ctx->pc = 0x15CBFCu;
    // 0x15cbfc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15cbfcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15cc00: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x15CC00u;
    {
        const bool branch_taken_0x15cc00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CC04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CC00u;
            // 0x15cc04: 0x2484e8e0  addiu       $a0, $a0, -0x1720 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961376));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cc00) {
            ctx->pc = 0x15CC28u;
            goto label_15cc28;
        }
    }
    ctx->pc = 0x15CC08u;
label_15cc08:
    // 0x15cc08: 0xc05a730  jal         func_169CC0
    ctx->pc = 0x15CC08u;
    SET_GPR_U32(ctx, 31, 0x15CC10u);
    ctx->pc = 0x169CC0u;
    if (runtime->hasFunction(0x169CC0u)) {
        auto targetFn = runtime->lookupFunction(0x169CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CC10u; }
        if (ctx->pc != 0x15CC10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169CC0_0x169cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CC10u; }
        if (ctx->pc != 0x15CC10u) { return; }
    }
    ctx->pc = 0x15CC10u;
label_15cc10:
    // 0x15cc10: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15CC10u;
    {
        const bool branch_taken_0x15cc10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15cc10) {
            ctx->pc = 0x15CC38u;
            goto label_15cc38;
        }
    }
    ctx->pc = 0x15CC18u;
    // 0x15cc18: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15CC18u;
    SET_GPR_U32(ctx, 31, 0x15CC20u);
    ctx->pc = 0x15CC1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CC18u;
            // 0x15cc1c: 0x2404fed1  addiu       $a0, $zero, -0x12F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966993));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CC20u; }
        if (ctx->pc != 0x15CC20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CC20u; }
        if (ctx->pc != 0x15CC20u) { return; }
    }
    ctx->pc = 0x15CC20u;
label_15cc20:
    // 0x15cc20: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15cc20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15cc24: 0x2484e918  addiu       $a0, $a0, -0x16E8
    ctx->pc = 0x15cc24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961432));
label_15cc28:
    // 0x15cc28: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15CC28u;
    SET_GPR_U32(ctx, 31, 0x15CC30u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CC30u; }
        if (ctx->pc != 0x15CC30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CC30u; }
        if (ctx->pc != 0x15CC30u) { return; }
    }
    ctx->pc = 0x15CC30u;
label_15cc30:
    // 0x15cc30: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15CC30u;
    {
        const bool branch_taken_0x15cc30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CC34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CC30u;
            // 0x15cc34: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cc30) {
            ctx->pc = 0x15CC44u;
            goto label_15cc44;
        }
    }
    ctx->pc = 0x15CC38u;
label_15cc38:
    // 0x15cc38: 0xc057230  jal         func_15C8C0
    ctx->pc = 0x15CC38u;
    SET_GPR_U32(ctx, 31, 0x15CC40u);
    ctx->pc = 0x15CC3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CC38u;
            // 0x15cc3c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15C8C0u;
    if (runtime->hasFunction(0x15C8C0u)) {
        auto targetFn = runtime->lookupFunction(0x15C8C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CC40u; }
        if (ctx->pc != 0x15CC40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015C8C0_0x15c8c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CC40u; }
        if (ctx->pc != 0x15CC40u) { return; }
    }
    ctx->pc = 0x15CC40u;
label_15cc40:
    // 0x15cc40: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15cc40u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15cc44:
    // 0x15cc44: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15cc44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15cc48: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15cc48u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15cc4c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15cc4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15cc50: 0x3e00008  jr          $ra
    ctx->pc = 0x15CC50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15CC54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CC50u;
            // 0x15cc54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15CBE8u: goto label_15cbe8;
            case 0x15CC08u: goto label_15cc08;
            case 0x15CC10u: goto label_15cc10;
            case 0x15CC20u: goto label_15cc20;
            case 0x15CC28u: goto label_15cc28;
            case 0x15CC30u: goto label_15cc30;
            case 0x15CC38u: goto label_15cc38;
            case 0x15CC40u: goto label_15cc40;
            case 0x15CC44u: goto label_15cc44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15CC58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
