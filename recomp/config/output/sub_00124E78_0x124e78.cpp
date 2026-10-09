#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124E78
// Address: 0x124e78 - 0x124ef8
void sub_00124E78_0x124e78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124E78_0x124e78");
#endif

    switch (ctx->pc) {
        case 0x124e80u: goto label_124e80;
        case 0x124ee8u: goto label_124ee8;
        case 0x124ef0u: goto label_124ef0;
        default: break;
    }

    ctx->pc = 0x124e78u;

    // 0x124e78: 0x3e00008  jr          $ra
    ctx->pc = 0x124E78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124E78u;
            // 0x124e7c: 0x8082000e  lb          $v0, 0xE($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 14)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124E80u: goto label_124e80;
            case 0x124EC0u: goto label_124ec0;
            case 0x124EE0u: goto label_124ee0;
            case 0x124EE8u: goto label_124ee8;
            case 0x124EF0u: goto label_124ef0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124E80u;
label_124e80:
    // 0x124e80: 0x3e00008  jr          $ra
    ctx->pc = 0x124E80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124E80u;
            // 0x124e84: 0x8082000d  lb          $v0, 0xD($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 13)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124E80u: goto label_124e80;
            case 0x124EC0u: goto label_124ec0;
            case 0x124EE0u: goto label_124ee0;
            case 0x124EE8u: goto label_124ee8;
            case 0x124EF0u: goto label_124ef0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124E88u;
    // 0x124e88: 0x84850098  lh          $a1, 0x98($a0)
    ctx->pc = 0x124e88u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 152)));
    // 0x124e8c: 0x10a00014  beqz        $a1, . + 4 + (0x14 << 2)
    ctx->pc = 0x124E8Cu;
    {
        const bool branch_taken_0x124e8c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x124E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124E8Cu;
            // 0x124e90: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124e8c) {
            ctx->pc = 0x124EE0u;
            goto label_124ee0;
        }
    }
    ctx->pc = 0x124E94u;
    // 0x124e94: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x124e94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124e98: 0x14a20009  bne         $a1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x124E98u;
    {
        const bool branch_taken_0x124e98 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x124E9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124E98u;
            // 0x124e9c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124e98) {
            ctx->pc = 0x124EC0u;
            goto label_124ec0;
        }
    }
    ctx->pc = 0x124EA0u;
    // 0x124ea0: 0x8483009a  lh          $v1, 0x9A($a0)
    ctx->pc = 0x124ea0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 154)));
    // 0x124ea4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x124ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x124ea8: 0x1065000d  beq         $v1, $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x124EA8u;
    {
        const bool branch_taken_0x124ea8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x124EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124EA8u;
            // 0x124eac: 0x38640001  xori        $a0, $v1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x124ea8) {
            ctx->pc = 0x124EE0u;
            goto label_124ee0;
        }
    }
    ctx->pc = 0x124EB0u;
    // 0x124eb0: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x124eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x124eb4: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x124eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x124eb8: 0x3e00008  jr          $ra
    ctx->pc = 0x124EB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124EB8u;
            // 0x124ebc: 0x64100b  movn        $v0, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124E80u: goto label_124e80;
            case 0x124EC0u: goto label_124ec0;
            case 0x124EE0u: goto label_124ee0;
            case 0x124EE8u: goto label_124ee8;
            case 0x124EF0u: goto label_124ef0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124EC0u;
label_124ec0:
    // 0x124ec0: 0x54a20007  bnel        $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x124EC0u;
    {
        const bool branch_taken_0x124ec0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x124ec0) {
            ctx->pc = 0x124EC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x124EC0u;
            // 0x124ec4: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124EE0u;
            goto label_124ee0;
        }
    }
    ctx->pc = 0x124EC8u;
    // 0x124ec8: 0x8483009a  lh          $v1, 0x9A($a0)
    ctx->pc = 0x124ec8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 154)));
    // 0x124ecc: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x124eccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x124ed0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x124ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x124ed4: 0x38630002  xori        $v1, $v1, 0x2
    ctx->pc = 0x124ed4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
    // 0x124ed8: 0x3e00008  jr          $ra
    ctx->pc = 0x124ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124ED8u;
            // 0x124edc: 0x83100b  movn        $v0, $a0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124E80u: goto label_124e80;
            case 0x124EC0u: goto label_124ec0;
            case 0x124EE0u: goto label_124ee0;
            case 0x124EE8u: goto label_124ee8;
            case 0x124EF0u: goto label_124ef0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124EE0u;
label_124ee0:
    // 0x124ee0: 0x3e00008  jr          $ra
    ctx->pc = 0x124EE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124E80u: goto label_124e80;
            case 0x124EC0u: goto label_124ec0;
            case 0x124EE0u: goto label_124ee0;
            case 0x124EE8u: goto label_124ee8;
            case 0x124EF0u: goto label_124ef0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124EE8u;
label_124ee8:
    // 0x124ee8: 0x3e00008  jr          $ra
    ctx->pc = 0x124EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124EE8u;
            // 0x124eec: 0x8c820010  lw          $v0, 0x10($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124E80u: goto label_124e80;
            case 0x124EC0u: goto label_124ec0;
            case 0x124EE0u: goto label_124ee0;
            case 0x124EE8u: goto label_124ee8;
            case 0x124EF0u: goto label_124ef0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124EF0u;
label_124ef0:
    // 0x124ef0: 0x3e00008  jr          $ra
    ctx->pc = 0x124EF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124EF0u;
            // 0x124ef4: 0x8082000f  lb          $v0, 0xF($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124E80u: goto label_124e80;
            case 0x124EC0u: goto label_124ec0;
            case 0x124EE0u: goto label_124ee0;
            case 0x124EE8u: goto label_124ee8;
            case 0x124EF0u: goto label_124ef0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124EF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
