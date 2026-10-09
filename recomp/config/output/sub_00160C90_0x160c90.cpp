#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160C90
// Address: 0x160c90 - 0x160d48
void sub_00160C90_0x160c90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160C90_0x160c90");
#endif

    switch (ctx->pc) {
        case 0x160ce0u: goto label_160ce0;
        case 0x160cf4u: goto label_160cf4;
        case 0x160d08u: goto label_160d08;
        case 0x160d1cu: goto label_160d1c;
        case 0x160d30u: goto label_160d30;
        default: break;
    }

    ctx->pc = 0x160c90u;

    // 0x160c90: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x160c90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x160c94: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x160c94u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160c98: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x160c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x160c9c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x160c9cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160ca0: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x160ca0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x160ca4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x160ca4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x160ca8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x160ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x160cac: 0x26040004  addiu       $a0, $s0, 0x4
    ctx->pc = 0x160cacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x160cb0: 0x8d11000c  lw          $s1, 0xC($t0)
    ctx->pc = 0x160cb0u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
    // 0x160cb4: 0x8d090008  lw          $t1, 0x8($t0)
    ctx->pc = 0x160cb4u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x160cb8: 0x8d020004  lw          $v0, 0x4($t0)
    ctx->pc = 0x160cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x160cbc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x160cbcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160cc0: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x160cc0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160cc4: 0x120282d  daddu       $a1, $t1, $zero
    ctx->pc = 0x160cc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160cc8: 0xae090044  sw          $t1, 0x44($s0)
    ctx->pc = 0x160cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 9));
    // 0x160ccc: 0x10430006  beq         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x160CCCu;
    {
        const bool branch_taken_0x160ccc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x160CD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160CCCu;
            // 0x160cd0: 0xae110048  sw          $s1, 0x48($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160ccc) {
            ctx->pc = 0x160CE8u;
            goto label_160ce8;
        }
    }
    ctx->pc = 0x160CD4u;
    // 0x160cd4: 0x8d050000  lw          $a1, 0x0($t0)
    ctx->pc = 0x160cd4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x160cd8: 0xc058356  jal         func_160D58
    ctx->pc = 0x160CD8u;
    SET_GPR_U32(ctx, 31, 0x160CE0u);
    ctx->pc = 0x160CDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160CD8u;
            // 0x160cdc: 0x120302d  daddu       $a2, $t1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160D58u;
    if (runtime->hasFunction(0x160D58u)) {
        auto targetFn = runtime->lookupFunction(0x160D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160CE0u; }
        if (ctx->pc != 0x160CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160D58_0x160d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160CE0u; }
        if (ctx->pc != 0x160CE0u) { return; }
    }
    ctx->pc = 0x160CE0u;
label_160ce0:
    // 0x160ce0: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x160CE0u;
    {
        const bool branch_taken_0x160ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160CE0u;
            // 0x160ce4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160ce0) {
            ctx->pc = 0x160D34u;
            goto label_160d34;
        }
    }
    ctx->pc = 0x160CE8u;
label_160ce8:
    // 0x160ce8: 0x8d040000  lw          $a0, 0x0($t0)
    ctx->pc = 0x160ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x160cec: 0xc05785c  jal         func_15E170
    ctx->pc = 0x160CECu;
    SET_GPR_U32(ctx, 31, 0x160CF4u);
    ctx->pc = 0x160CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160CECu;
            // 0x160cf0: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E170u;
    if (runtime->hasFunction(0x15E170u)) {
        auto targetFn = runtime->lookupFunction(0x15E170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160CF4u; }
        if (ctx->pc != 0x160CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E170_0x15e170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160CF4u; }
        if (ctx->pc != 0x160CF4u) { return; }
    }
    ctx->pc = 0x160CF4u;
label_160cf4:
    // 0x160cf4: 0x26040004  addiu       $a0, $s0, 0x4
    ctx->pc = 0x160cf4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x160cf8: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x160cf8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160cfc: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x160cfcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160d00: 0xc058356  jal         func_160D58
    ctx->pc = 0x160D00u;
    SET_GPR_U32(ctx, 31, 0x160D08u);
    ctx->pc = 0x160D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160D00u;
            // 0x160d04: 0x8fa6000c  lw          $a2, 0xC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160D58u;
    if (runtime->hasFunction(0x160D58u)) {
        auto targetFn = runtime->lookupFunction(0x160D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160D08u; }
        if (ctx->pc != 0x160D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160D58_0x160d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160D08u; }
        if (ctx->pc != 0x160D08u) { return; }
    }
    ctx->pc = 0x160D08u;
label_160d08:
    // 0x160d08: 0x26040014  addiu       $a0, $s0, 0x14
    ctx->pc = 0x160d08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x160d0c: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x160d0cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x160d10: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x160d10u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160d14: 0xc058356  jal         func_160D58
    ctx->pc = 0x160D14u;
    SET_GPR_U32(ctx, 31, 0x160D1Cu);
    ctx->pc = 0x160D18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160D14u;
            // 0x160d18: 0x8fa60010  lw          $a2, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160D58u;
    if (runtime->hasFunction(0x160D58u)) {
        auto targetFn = runtime->lookupFunction(0x160D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160D1Cu; }
        if (ctx->pc != 0x160D1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160D58_0x160d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160D1Cu; }
        if (ctx->pc != 0x160D1Cu) { return; }
    }
    ctx->pc = 0x160D1Cu;
label_160d1c:
    // 0x160d1c: 0x26040024  addiu       $a0, $s0, 0x24
    ctx->pc = 0x160d1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    // 0x160d20: 0x8fa50008  lw          $a1, 0x8($sp)
    ctx->pc = 0x160d20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160d24: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x160d24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160d28: 0xc058356  jal         func_160D58
    ctx->pc = 0x160D28u;
    SET_GPR_U32(ctx, 31, 0x160D30u);
    ctx->pc = 0x160D2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160D28u;
            // 0x160d2c: 0x8fa60014  lw          $a2, 0x14($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160D58u;
    if (runtime->hasFunction(0x160D58u)) {
        auto targetFn = runtime->lookupFunction(0x160D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160D30u; }
        if (ctx->pc != 0x160D30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160D58_0x160d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160D30u; }
        if (ctx->pc != 0x160D30u) { return; }
    }
    ctx->pc = 0x160D30u;
label_160d30:
    // 0x160d30: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x160d30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_160d34:
    // 0x160d34: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x160d34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x160d38: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x160d38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x160d3c: 0x3e00008  jr          $ra
    ctx->pc = 0x160D3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160D40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160D3Cu;
            // 0x160d40: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160CE0u: goto label_160ce0;
            case 0x160CE8u: goto label_160ce8;
            case 0x160CF4u: goto label_160cf4;
            case 0x160D08u: goto label_160d08;
            case 0x160D1Cu: goto label_160d1c;
            case 0x160D30u: goto label_160d30;
            case 0x160D34u: goto label_160d34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160D44u;
    // 0x160d44: 0x0  nop
    ctx->pc = 0x160d44u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
