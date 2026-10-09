#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178D90
// Address: 0x178d90 - 0x178e10
void sub_00178D90_0x178d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178D90_0x178d90");
#endif

    switch (ctx->pc) {
        case 0x178db0u: goto label_178db0;
        case 0x178dc0u: goto label_178dc0;
        case 0x178dd0u: goto label_178dd0;
        default: break;
    }

    ctx->pc = 0x178d90u;

    // 0x178d90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x178d90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x178d94: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x178d94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x178d98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x178d98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178d9c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x178d9cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178da0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x178da0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x178da4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x178da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x178da8: 0xc05df1e  jal         func_177C78
    ctx->pc = 0x178DA8u;
    SET_GPR_U32(ctx, 31, 0x178DB0u);
    ctx->pc = 0x178DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178DA8u;
            // 0x178dac: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C78u;
    if (runtime->hasFunction(0x177C78u)) {
        auto targetFn = runtime->lookupFunction(0x177C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178DB0u; }
        if (ctx->pc != 0x178DB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C78_0x177c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178DB0u; }
        if (ctx->pc != 0x178DB0u) { return; }
    }
    ctx->pc = 0x178DB0u;
label_178db0:
    // 0x178db0: 0x10510011  beq         $v0, $s1, . + 4 + (0x11 << 2)
    ctx->pc = 0x178DB0u;
    {
        const bool branch_taken_0x178db0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x178DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178DB0u;
            // 0x178db4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178db0) {
            ctx->pc = 0x178DF8u;
            goto label_178df8;
        }
    }
    ctx->pc = 0x178DB8u;
    // 0x178db8: 0xc059f40  jal         func_167D00
    ctx->pc = 0x178DB8u;
    SET_GPR_U32(ctx, 31, 0x178DC0u);
    ctx->pc = 0x178DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178DB8u;
            // 0x178dbc: 0x8e051c48  lw          $a1, 0x1C48($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178DC0u; }
        if (ctx->pc != 0x178DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D00_0x167d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178DC0u; }
        if (ctx->pc != 0x178DC0u) { return; }
    }
    ctx->pc = 0x178DC0u;
label_178dc0:
    // 0x178dc0: 0x1451000d  bne         $v0, $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x178DC0u;
    {
        const bool branch_taken_0x178dc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x178DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178DC0u;
            // 0x178dc4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178dc0) {
            ctx->pc = 0x178DF8u;
            goto label_178df8;
        }
    }
    ctx->pc = 0x178DC8u;
    // 0x178dc8: 0xc05e384  jal         func_178E10
    ctx->pc = 0x178DC8u;
    SET_GPR_U32(ctx, 31, 0x178DD0u);
    ctx->pc = 0x178E10u;
    if (runtime->hasFunction(0x178E10u)) {
        auto targetFn = runtime->lookupFunction(0x178E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178DD0u; }
        if (ctx->pc != 0x178DD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178E10_0x178e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178DD0u; }
        if (ctx->pc != 0x178DD0u) { return; }
    }
    ctx->pc = 0x178DD0u;
label_178dd0:
    // 0x178dd0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x178DD0u;
    {
        const bool branch_taken_0x178dd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178DD0u;
            // 0x178dd4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178dd0) {
            ctx->pc = 0x178DF8u;
            goto label_178df8;
        }
    }
    ctx->pc = 0x178DD8u;
    // 0x178dd8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178dd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178ddc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178ddcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178de0: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x178de0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x178de4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x178de4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178de8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x178de8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x178dec: 0x805df18  j           func_177C60
    ctx->pc = 0x178DECu;
    ctx->pc = 0x178DF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178DECu;
            // 0x178df0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C60u;
    if (runtime->hasFunction(0x177C60u)) {
        auto targetFn = runtime->lookupFunction(0x177C60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177C60_0x177c60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178DF4u;
    // 0x178df4: 0x0  nop
    ctx->pc = 0x178df4u;
    // NOP
label_178df8:
    // 0x178df8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178df8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178dfc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178dfcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178e00: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x178e00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178e04: 0x3e00008  jr          $ra
    ctx->pc = 0x178E04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178E08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178E04u;
            // 0x178e08: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178DB0u: goto label_178db0;
            case 0x178DC0u: goto label_178dc0;
            case 0x178DD0u: goto label_178dd0;
            case 0x178DF8u: goto label_178df8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178E0Cu;
    // 0x178e0c: 0x0  nop
    ctx->pc = 0x178e0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
