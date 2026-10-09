#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F9D0
// Address: 0x15f9d0 - 0x15fa50
void sub_0015F9D0_0x15f9d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F9D0_0x15f9d0");
#endif

    switch (ctx->pc) {
        case 0x15f9e4u: goto label_15f9e4;
        case 0x15f9f0u: goto label_15f9f0;
        case 0x15f9fcu: goto label_15f9fc;
        case 0x15fa2cu: goto label_15fa2c;
        case 0x15fa3cu: goto label_15fa3c;
        default: break;
    }

    ctx->pc = 0x15f9d0u;

    // 0x15f9d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f9d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f9d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f9d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f9d8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15f9d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15f9dc: 0xc040c18  jal         func_103060
    ctx->pc = 0x15F9DCu;
    SET_GPR_U32(ctx, 31, 0x15F9E4u);
    ctx->pc = 0x103060u;
    if (runtime->hasFunction(0x103060u)) {
        auto targetFn = runtime->lookupFunction(0x103060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F9E4u; }
        if (ctx->pc != 0x15F9E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103060_0x103060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F9E4u; }
        if (ctx->pc != 0x15F9E4u) { return; }
    }
    ctx->pc = 0x15F9E4u;
label_15f9e4:
    // 0x15f9e4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15f9e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f9e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f9e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f9ec: 0x0  nop
    ctx->pc = 0x15f9ecu;
    // NOP
label_15f9f0:
    // 0x15f9f0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15f9f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15f9f4: 0xc040d8c  jal         func_103630
    ctx->pc = 0x15F9F4u;
    SET_GPR_U32(ctx, 31, 0x15F9FCu);
    ctx->pc = 0x15F9F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F9F4u;
            // 0x15f9f8: 0x2406001e  addiu       $a2, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103630u;
    if (runtime->hasFunction(0x103630u)) {
        auto targetFn = runtime->lookupFunction(0x103630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F9FCu; }
        if (ctx->pc != 0x15F9FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103630_0x103630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F9FCu; }
        if (ctx->pc != 0x15F9FCu) { return; }
    }
    ctx->pc = 0x15F9FCu;
label_15f9fc:
    // 0x15f9fc: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x15F9FCu;
    {
        const bool branch_taken_0x15f9fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F9FCu;
            // 0x15fa00: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f9fc) {
            ctx->pc = 0x15F9F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15f9f0;
        }
    }
    ctx->pc = 0x15FA04u;
    // 0x15fa04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fa04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fa08: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15fa08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fa0c: 0x3e00008  jr          $ra
    ctx->pc = 0x15FA0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FA10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FA0Cu;
            // 0x15fa10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F9E4u: goto label_15f9e4;
            case 0x15F9F0u: goto label_15f9f0;
            case 0x15F9FCu: goto label_15f9fc;
            case 0x15FA2Cu: goto label_15fa2c;
            case 0x15FA3Cu: goto label_15fa3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FA14u;
    // 0x15fa14: 0x0  nop
    ctx->pc = 0x15fa14u;
    // NOP
    // 0x15fa18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15fa18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15fa1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fa1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fa20: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15fa20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15fa24: 0xc040c18  jal         func_103060
    ctx->pc = 0x15FA24u;
    SET_GPR_U32(ctx, 31, 0x15FA2Cu);
    ctx->pc = 0x15FA28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FA24u;
            // 0x15fa28: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103060u;
    if (runtime->hasFunction(0x103060u)) {
        auto targetFn = runtime->lookupFunction(0x103060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FA2Cu; }
        if (ctx->pc != 0x15FA2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103060_0x103060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FA2Cu; }
        if (ctx->pc != 0x15FA2Cu) { return; }
    }
    ctx->pc = 0x15FA2Cu;
label_15fa2c:
    // 0x15fa2c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15fa2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fa30: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15fa30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15fa34: 0xc040d8c  jal         func_103630
    ctx->pc = 0x15FA34u;
    SET_GPR_U32(ctx, 31, 0x15FA3Cu);
    ctx->pc = 0x15FA38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FA34u;
            // 0x15fa38: 0x2406001e  addiu       $a2, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103630u;
    if (runtime->hasFunction(0x103630u)) {
        auto targetFn = runtime->lookupFunction(0x103630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FA3Cu; }
        if (ctx->pc != 0x15FA3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103630_0x103630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FA3Cu; }
        if (ctx->pc != 0x15FA3Cu) { return; }
    }
    ctx->pc = 0x15FA3Cu;
label_15fa3c:
    // 0x15fa3c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x15fa3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x15fa40: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15fa40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fa44: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fa44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fa48: 0x3e00008  jr          $ra
    ctx->pc = 0x15FA48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FA48u;
            // 0x15fa4c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F9E4u: goto label_15f9e4;
            case 0x15F9F0u: goto label_15f9f0;
            case 0x15F9FCu: goto label_15f9fc;
            case 0x15FA2Cu: goto label_15fa2c;
            case 0x15FA3Cu: goto label_15fa3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FA50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
