#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016FB28
// Address: 0x16fb28 - 0x16fbf0
void sub_0016FB28_0x16fb28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016FB28_0x16fb28");
#endif

    switch (ctx->pc) {
        case 0x16fb44u: goto label_16fb44;
        case 0x16fb78u: goto label_16fb78;
        case 0x16fbc0u: goto label_16fbc0;
        default: break;
    }

    ctx->pc = 0x16fb28u;

    // 0x16fb28: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x16fb28u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x16fb2c: 0x24a36068  addiu       $v1, $a1, 0x6068
    ctx->pc = 0x16fb2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 24680));
    // 0x16fb30: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x16fb30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x16fb34: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x16fb34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x16fb38: 0x2c420010  sltiu       $v0, $v0, 0x10
    ctx->pc = 0x16fb38u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x16fb3c: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x16FB3Cu;
    {
        const bool branch_taken_0x16fb3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16fb3c) {
            ctx->pc = 0x16FB40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16FB3Cu;
            // 0x16fb40: 0x8c620010  lw          $v0, 0x10($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16FB50u;
            goto label_16fb50;
        }
    }
    ctx->pc = 0x16FB44u;
label_16fb44:
    // 0x16fb44: 0x3e00008  jr          $ra
    ctx->pc = 0x16FB44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16FB48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FB44u;
            // 0x16fb48: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16FB44u: goto label_16fb44;
            case 0x16FB50u: goto label_16fb50;
            case 0x16FB68u: goto label_16fb68;
            case 0x16FB78u: goto label_16fb78;
            case 0x16FBC0u: goto label_16fbc0;
            case 0x16FBE4u: goto label_16fbe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16FB4Cu;
    // 0x16fb4c: 0x0  nop
    ctx->pc = 0x16fb4cu;
    // NOP
label_16fb50:
    // 0x16fb50: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16FB50u;
    {
        const bool branch_taken_0x16fb50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16FB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FB50u;
            // 0x16fb54: 0x3c020027  lui         $v0, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16fb50) {
            ctx->pc = 0x16FB68u;
            goto label_16fb68;
        }
    }
    ctx->pc = 0x16FB58u;
    // 0x16fb58: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x16fb58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x16fb5c: 0x14400021  bnez        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x16FB5Cu;
    {
        const bool branch_taken_0x16fb5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16fb5c) {
            ctx->pc = 0x16FBE4u;
            goto label_16fbe4;
        }
    }
    ctx->pc = 0x16FB64u;
    // 0x16fb64: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x16fb64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
label_16fb68:
    // 0x16fb68: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x16fb68u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16fb6c: 0x24446090  addiu       $a0, $v0, 0x6090
    ctx->pc = 0x16fb6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 24720));
    // 0x16fb70: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x16fb70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x16fb74: 0x0  nop
    ctx->pc = 0x16fb74u;
    // NOP
label_16fb78:
    // 0x16fb78: 0x1040fff2  beqz        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x16FB78u;
    {
        const bool branch_taken_0x16fb78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16FB7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FB78u;
            // 0x16fb7c: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16fb78) {
            ctx->pc = 0x16FB44u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16fb44;
        }
    }
    ctx->pc = 0x16FB80u;
    // 0x16fb80: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x16fb80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x16fb84: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x16fb84u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x16fb88: 0x0  nop
    ctx->pc = 0x16fb88u;
    // NOP
    // 0x16fb8c: 0x0  nop
    ctx->pc = 0x16fb8cu;
    // NOP
    // 0x16fb90: 0x0  nop
    ctx->pc = 0x16fb90u;
    // NOP
    // 0x16fb94: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x16FB94u;
    {
        const bool branch_taken_0x16fb94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16fb94) {
            ctx->pc = 0x16FB98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16FB94u;
            // 0x16fb98: 0x8c820000  lw          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16FB78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16fb78;
        }
    }
    ctx->pc = 0x16FB9Cu;
    // 0x16fb9c: 0x24a26068  addiu       $v0, $a1, 0x6068
    ctx->pc = 0x16fb9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 24680));
    // 0x16fba0: 0x8c44001c  lw          $a0, 0x1C($v0)
    ctx->pc = 0x16fba0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x16fba4: 0x1880000f  blez        $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x16FBA4u;
    {
        const bool branch_taken_0x16fba4 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x16FBA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FBA4u;
            // 0x16fba8: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16fba4) {
            ctx->pc = 0x16FBE4u;
            goto label_16fbe4;
        }
    }
    ctx->pc = 0x16FBACu;
    // 0x16fbac: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x16fbacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x16fbb0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x16fbb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16fbb4: 0x24446098  addiu       $a0, $v0, 0x6098
    ctx->pc = 0x16fbb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 24728));
    // 0x16fbb8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x16fbb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x16fbbc: 0x0  nop
    ctx->pc = 0x16fbbcu;
    // NOP
label_16fbc0:
    // 0x16fbc0: 0x1040ffe0  beqz        $v0, . + 4 + (-0x20 << 2)
    ctx->pc = 0x16FBC0u;
    {
        const bool branch_taken_0x16fbc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16FBC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FBC0u;
            // 0x16fbc4: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16fbc0) {
            ctx->pc = 0x16FB44u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16fb44;
        }
    }
    ctx->pc = 0x16FBC8u;
    // 0x16fbc8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x16fbc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x16fbcc: 0x65102a  slt         $v0, $v1, $a1
    ctx->pc = 0x16fbccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x16fbd0: 0x0  nop
    ctx->pc = 0x16fbd0u;
    // NOP
    // 0x16fbd4: 0x0  nop
    ctx->pc = 0x16fbd4u;
    // NOP
    // 0x16fbd8: 0x0  nop
    ctx->pc = 0x16fbd8u;
    // NOP
    // 0x16fbdc: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x16FBDCu;
    {
        const bool branch_taken_0x16fbdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16fbdc) {
            ctx->pc = 0x16FBE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16FBDCu;
            // 0x16fbe0: 0x8c820000  lw          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16FBC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16fbc0;
        }
    }
    ctx->pc = 0x16FBE4u;
label_16fbe4:
    // 0x16fbe4: 0x3e00008  jr          $ra
    ctx->pc = 0x16FBE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16FBE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FBE4u;
            // 0x16fbe8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16FB44u: goto label_16fb44;
            case 0x16FB50u: goto label_16fb50;
            case 0x16FB68u: goto label_16fb68;
            case 0x16FB78u: goto label_16fb78;
            case 0x16FBC0u: goto label_16fbc0;
            case 0x16FBE4u: goto label_16fbe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16FBECu;
    // 0x16fbec: 0x0  nop
    ctx->pc = 0x16fbecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
