#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4D80
// Address: 0x1d4d80 - 0x1d4e20
void sub_001D4D80_0x1d4d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4D80_0x1d4d80");
#endif

    switch (ctx->pc) {
        case 0x1d4d9cu: goto label_1d4d9c;
        case 0x1d4dc0u: goto label_1d4dc0;
        default: break;
    }

    ctx->pc = 0x1d4d80u;

    // 0x1d4d80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d4d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d4d84: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d4d84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d4d88: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4d88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4d8c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d4d8cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4d90: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d4d90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d4d94: 0xc0754fc  jal         func_1D53F0
    ctx->pc = 0x1D4D94u;
    SET_GPR_U32(ctx, 31, 0x1D4D9Cu);
    ctx->pc = 0x1D4D98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D94u;
            // 0x1d4d98: 0x24842720  addiu       $a0, $a0, 0x2720 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10016));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D53F0u;
    if (runtime->hasFunction(0x1D53F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D53F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4D9Cu; }
        if (ctx->pc != 0x1D4D9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D53F0_0x1d53f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4D9Cu; }
        if (ctx->pc != 0x1D4D9Cu) { return; }
    }
    ctx->pc = 0x1D4D9Cu;
label_1d4d9c:
    // 0x1d4d9c: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4d9cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1d4da0: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4da0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1d4da4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D4DA4u;
    {
        const bool branch_taken_0x1d4da4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DA4u;
            // 0x1d4da8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4da4) {
            ctx->pc = 0x1D4DB8u;
            goto label_1d4db8;
        }
    }
    ctx->pc = 0x1D4DACu;
    // 0x1d4dac: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4dacu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d4db0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1D4DB0u;
    {
        const bool branch_taken_0x1d4db0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DB0u;
            // 0x1d4db4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4db0) {
            ctx->pc = 0x1D4E10u;
            goto label_1d4e10;
        }
    }
    ctx->pc = 0x1D4DB8u;
label_1d4db8:
    // 0x1d4db8: 0xc075646  jal         func_1D5918
    ctx->pc = 0x1D4DB8u;
    SET_GPR_U32(ctx, 31, 0x1D4DC0u);
    ctx->pc = 0x1D4DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DB8u;
            // 0x1d4dbc: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5918u;
    if (runtime->hasFunction(0x1D5918u)) {
        auto targetFn = runtime->lookupFunction(0x1D5918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4DC0u; }
        if (ctx->pc != 0x1D4DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5918_0x1d5918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4DC0u; }
        if (ctx->pc != 0x1D4DC0u) { return; }
    }
    ctx->pc = 0x1D4DC0u;
label_1d4dc0:
    // 0x1d4dc0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4dc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4dc4: 0xac222678  sw          $v0, 0x2678($at)
    ctx->pc = 0x1d4dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9848), GPR_U32(ctx, 2));
    // 0x1d4dc8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4dc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4dcc: 0x8c222678  lw          $v0, 0x2678($at)
    ctx->pc = 0x1d4dccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9848)));
    // 0x1d4dd0: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1D4DD0u;
    {
        const bool branch_taken_0x1d4dd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4dd0) {
            ctx->pc = 0x1D4E0Cu;
            goto label_1d4e0c;
        }
    }
    ctx->pc = 0x1D4DD8u;
    // 0x1d4dd8: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1d4ddc: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D4DDCu;
    {
        const bool branch_taken_0x1d4ddc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DDCu;
            // 0x1d4de0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4ddc) {
            ctx->pc = 0x1D4E10u;
            goto label_1d4e10;
        }
    }
    ctx->pc = 0x1D4DE4u;
    // 0x1d4de4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4de4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4de8: 0x8c222724  lw          $v0, 0x2724($at)
    ctx->pc = 0x1d4de8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 10020)));
    // 0x1d4dec: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D4DECu;
    {
        const bool branch_taken_0x1d4dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4dec) {
            ctx->pc = 0x1D4E00u;
            goto label_1d4e00;
        }
    }
    ctx->pc = 0x1D4DF4u;
    // 0x1d4df4: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4df4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d4df8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D4DF8u;
    {
        const bool branch_taken_0x1d4df8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DF8u;
            // 0x1d4dfc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4df8) {
            ctx->pc = 0x1D4E10u;
            goto label_1d4e10;
        }
    }
    ctx->pc = 0x1D4E00u;
label_1d4e00:
    // 0x1d4e00: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1d4e00u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d4e04: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d4e04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d4e08: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1d4e08u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
label_1d4e0c:
    // 0x1d4e0c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d4e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d4e10:
    // 0x1d4e10: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d4e10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4e14: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4e14u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4e18: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4E18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E18u;
            // 0x1d4e1c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4E20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
