#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108DA0
// Address: 0x108da0 - 0x108e10
void sub_00108DA0_0x108da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108DA0_0x108da0");
#endif

    switch (ctx->pc) {
        case 0x108de0u: goto label_108de0;
        case 0x108df0u: goto label_108df0;
        default: break;
    }

    ctx->pc = 0x108da0u;

    // 0x108da0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x108da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x108da4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x108da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x108da8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x108da8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108dac: 0x2a020018  slti        $v0, $s0, 0x18
    ctx->pc = 0x108dacu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x108db0: 0x3404ffc0  ori         $a0, $zero, 0xFFC0
    ctx->pc = 0x108db0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x108db4: 0x423bc  dsll32      $a0, $a0, 14
    ctx->pc = 0x108db4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 14));
    // 0x108db8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x108DB8u;
    {
        const bool branch_taken_0x108db8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x108DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108DB8u;
            // 0x108dbc: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108db8) {
            ctx->pc = 0x108DD8u;
            goto label_108dd8;
        }
    }
    ctx->pc = 0x108DC0u;
    // 0x108dc0: 0x1018c0  sll         $v1, $s0, 3
    ctx->pc = 0x108dc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x108dc4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x108dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x108dc8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x108dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x108dcc: 0xdc427928  ld          $v0, 0x7928($v0)
    ctx->pc = 0x108dccu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 31016)));
    // 0x108dd0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x108DD0u;
    {
        const bool branch_taken_0x108dd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108DD0u;
            // 0x108dd4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108dd0) {
            ctx->pc = 0x108E04u;
            goto label_108e04;
        }
    }
    ctx->pc = 0x108DD8u;
label_108dd8:
    // 0x108dd8: 0x1a000008  blez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x108DD8u;
    {
        const bool branch_taken_0x108dd8 = (GPR_S64(ctx, 16) <= 0);
        if (branch_taken_0x108dd8) {
            ctx->pc = 0x108DFCu;
            goto label_108dfc;
        }
    }
    ctx->pc = 0x108DE0u;
label_108de0:
    // 0x108de0: 0x34058048  ori         $a1, $zero, 0x8048
    ctx->pc = 0x108de0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32840);
    // 0x108de4: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x108de4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x108de8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x108DE8u;
    SET_GPR_U32(ctx, 31, 0x108DF0u);
    ctx->pc = 0x108DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108DE8u;
            // 0x108dec: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108DF0u; }
        if (ctx->pc != 0x108DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108DF0u; }
        if (ctx->pc != 0x108DF0u) { return; }
    }
    ctx->pc = 0x108DF0u;
label_108df0:
    // 0x108df0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x108df0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108df4: 0x1e00fffa  bgtz        $s0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x108DF4u;
    {
        const bool branch_taken_0x108df4 = (GPR_S64(ctx, 16) > 0);
        if (branch_taken_0x108df4) {
            ctx->pc = 0x108DE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108de0;
        }
    }
    ctx->pc = 0x108DFCu;
label_108dfc:
    // 0x108dfc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x108dfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108e00: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x108e00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_108e04:
    // 0x108e04: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x108e04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x108e08: 0x3e00008  jr          $ra
    ctx->pc = 0x108E08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108E08u;
            // 0x108e0c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108DD8u: goto label_108dd8;
            case 0x108DE0u: goto label_108de0;
            case 0x108DF0u: goto label_108df0;
            case 0x108DFCu: goto label_108dfc;
            case 0x108E04u: goto label_108e04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108E10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
