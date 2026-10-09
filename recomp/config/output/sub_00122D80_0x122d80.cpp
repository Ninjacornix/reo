#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122D80
// Address: 0x122d80 - 0x122e10
void sub_00122D80_0x122d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122D80_0x122d80");
#endif

    switch (ctx->pc) {
        case 0x122dd0u: goto label_122dd0;
        case 0x122de4u: goto label_122de4;
        default: break;
    }

    ctx->pc = 0x122d80u;

label_122d80:
    // 0x122d80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122d84: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x122d84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x122d88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x122d88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x122d8c: 0x80830001  lb          $v1, 0x1($a0)
    ctx->pc = 0x122d8cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x122d90: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x122D90u;
    {
        const bool branch_taken_0x122d90 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x122D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122D90u;
            // 0x122d94: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122d90) {
            ctx->pc = 0x122DA0u;
            goto label_122da0;
        }
    }
    ctx->pc = 0x122D98u;
    // 0x122d98: 0x8048abc  j           func_122AF0
    ctx->pc = 0x122D98u;
    ctx->pc = 0x122D9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122D98u;
            // 0x122d9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122AF0u;
    if (runtime->hasFunction(0x122AF0u)) {
        auto targetFn = runtime->lookupFunction(0x122AF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00122AF0_0x122af0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x122DA0u;
label_122da0:
    // 0x122da0: 0x3e00008  jr          $ra
    ctx->pc = 0x122DA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122DA0u;
            // 0x122da4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122D80u: goto label_122d80;
            case 0x122DA0u: goto label_122da0;
            case 0x122DD0u: goto label_122dd0;
            case 0x122DE4u: goto label_122de4;
            case 0x122DE8u: goto label_122de8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122DA8u;
    // 0x122da8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x122da8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x122dac: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x122dacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x122db0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x122db0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x122db4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x122db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x122db8: 0x2450b418  addiu       $s0, $v0, -0x4BE8
    ctx->pc = 0x122db8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947864));
    // 0x122dbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x122dbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x122dc0: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x122dc0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x122dc4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x122dc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x122dc8: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x122dc8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122dcc: 0x0  nop
    ctx->pc = 0x122dccu;
    // NOP
label_122dd0:
    // 0x122dd0: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x122dd0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x122dd4: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x122DD4u;
    {
        const bool branch_taken_0x122dd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x122dd4) {
            ctx->pc = 0x122DD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122DD4u;
            // 0x122dd8: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122DE8u;
            goto label_122de8;
        }
    }
    ctx->pc = 0x122DDCu;
    // 0x122ddc: 0xc048b60  jal         func_122D80
    ctx->pc = 0x122DDCu;
    SET_GPR_U32(ctx, 31, 0x122DE4u);
    ctx->pc = 0x122DE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122DDCu;
            // 0x122de0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122D80u;
    goto label_122d80;
    ctx->pc = 0x122DE4u;
label_122de4:
    // 0x122de4: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x122de4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_122de8:
    // 0x122de8: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x122DE8u;
    {
        const bool branch_taken_0x122de8 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x122DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122DE8u;
            // 0x122dec: 0x26100030  addiu       $s0, $s0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122de8) {
            ctx->pc = 0x122DD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122dd0;
        }
    }
    ctx->pc = 0x122DF0u;
    // 0x122df0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x122df0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x122df4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x122df4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x122df8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x122df8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x122dfc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x122dfcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x122e00: 0x3e00008  jr          $ra
    ctx->pc = 0x122E00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E00u;
            // 0x122e04: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122D80u: goto label_122d80;
            case 0x122DA0u: goto label_122da0;
            case 0x122DD0u: goto label_122dd0;
            case 0x122DE4u: goto label_122de4;
            case 0x122DE8u: goto label_122de8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E08u;
    // 0x122e08: 0x3e00008  jr          $ra
    ctx->pc = 0x122E08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E08u;
            // 0x122e0c: 0x8c820014  lw          $v0, 0x14($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122D80u: goto label_122d80;
            case 0x122DA0u: goto label_122da0;
            case 0x122DD0u: goto label_122dd0;
            case 0x122DE4u: goto label_122de4;
            case 0x122DE8u: goto label_122de8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
