#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC740
// Address: 0x1cc740 - 0x1cc7e0
void sub_001CC740_0x1cc740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC740_0x1cc740");
#endif

    switch (ctx->pc) {
        case 0x1cc750u: goto label_1cc750;
        default: break;
    }

    ctx->pc = 0x1cc740u;

    // 0x1cc740: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x1cc740u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x1cc744: 0x3c08000f  lui         $t0, 0xF
    ctx->pc = 0x1cc744u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)15 << 16));
    // 0x1cc748: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1CC748u;
    {
        const bool branch_taken_0x1cc748 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC74Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC748u;
            // 0x1cc74c: 0x835025  or          $t2, $a0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc748) {
            ctx->pc = 0x1CC7D0u;
            goto label_1cc7d0;
        }
    }
    ctx->pc = 0x1CC750u;
label_1cc750:
    // 0x1cc750: 0x3421fff0  ori         $at, $at, 0xFFF0
    ctx->pc = 0x1cc750u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65520);
    // 0x1cc754: 0xc1082a  slt         $at, $a2, $at
    ctx->pc = 0x1cc754u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1cc758: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CC758u;
    {
        const bool branch_taken_0x1cc758 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC75Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC758u;
            // 0x1cc75c: 0x3509fff0  ori         $t1, $t0, 0xFFF0 (Delay Slot)
        SET_GPR_U64(ctx, 9, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)65520);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc758) {
            ctx->pc = 0x1CC764u;
            goto label_1cc764;
        }
    }
    ctx->pc = 0x1CC760u;
    // 0x1cc760: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x1cc760u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_1cc764:
    // 0x1cc764: 0xc93023  subu        $a2, $a2, $t1
    ctx->pc = 0x1cc764u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
    // 0x1cc768: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1cc768u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1cc76c: 0x6200a  movz        $a0, $zero, $a2
    ctx->pc = 0x1cc76cu;
    if (GPR_U64(ctx, 6) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
    // 0x1cc770: 0x5183c  dsll32      $v1, $a1, 0
    ctx->pc = 0x1cc770u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1cc774: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x1cc774u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1cc778: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1cc778u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1cc77c: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x1cc77cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x1cc780: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1cc780u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1cc784: 0x43f38  dsll        $a3, $a0, 28
    ctx->pc = 0x1cc784u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) << 28);
    // 0x1cc788: 0x2524000f  addiu       $a0, $t1, 0xF
    ctx->pc = 0x1cc788u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), 15));
    // 0x1cc78c: 0x673825  or          $a3, $v1, $a3
    ctx->pc = 0x1cc78cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x1cc790: 0x4810003  bgez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CC790u;
    {
        const bool branch_taken_0x1cc790 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1CC794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC790u;
            // 0x1cc794: 0x41903  sra         $v1, $a0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc790) {
            ctx->pc = 0x1CC7A0u;
            goto label_1cc7a0;
        }
    }
    ctx->pc = 0x1CC798u;
    // 0x1cc798: 0x2483000f  addiu       $v1, $a0, 0xF
    ctx->pc = 0x1cc798u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 15));
    // 0x1cc79c: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x1cc79cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
label_1cc7a0:
    // 0x1cc7a0: 0x32100  sll         $a0, $v1, 4
    ctx->pc = 0x1cc7a0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1cc7a4: 0x3193c  dsll32      $v1, $v1, 4
    ctx->pc = 0x1cc7a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 4));
    // 0x1cc7a8: 0x4810003  bgez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CC7A8u;
    {
        const bool branch_taken_0x1cc7a8 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1CC7ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC7A8u;
            // 0x1cc7ac: 0x3193f  dsra32      $v1, $v1, 4 (Delay Slot)
        SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc7a8) {
            ctx->pc = 0x1CC7B8u;
            goto label_1cc7b8;
        }
    }
    ctx->pc = 0x1CC7B0u;
    // 0x1cc7b0: 0x2483000f  addiu       $v1, $a0, 0xF
    ctx->pc = 0x1cc7b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 15));
    // 0x1cc7b4: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x1cc7b4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
label_1cc7b8:
    // 0x1cc7b8: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1cc7b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1cc7bc: 0xa92821  addu        $a1, $a1, $t1
    ctx->pc = 0x1cc7bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x1cc7c0: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1cc7c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1cc7c4: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x1cc7c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x1cc7c8: 0xfd430000  sd          $v1, 0x0($t2)
    ctx->pc = 0x1cc7c8u;
    WRITE64(ADD32(GPR_U32(ctx, 10), 0), GPR_U64(ctx, 3));
    // 0x1cc7cc: 0x254a0010  addiu       $t2, $t2, 0x10
    ctx->pc = 0x1cc7ccu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 16));
label_1cc7d0:
    // 0x1cc7d0: 0x1cc0ffdf  bgtz        $a2, . + 4 + (-0x21 << 2)
    ctx->pc = 0x1CC7D0u;
    {
        const bool branch_taken_0x1cc7d0 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x1CC7D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC7D0u;
            // 0x1cc7d4: 0x3c01000f  lui         $at, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc7d0) {
            ctx->pc = 0x1CC750u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cc750;
        }
    }
    ctx->pc = 0x1CC7D8u;
    // 0x1cc7d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC7D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC750u: goto label_1cc750;
            case 0x1CC764u: goto label_1cc764;
            case 0x1CC7A0u: goto label_1cc7a0;
            case 0x1CC7B8u: goto label_1cc7b8;
            case 0x1CC7D0u: goto label_1cc7d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC7E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
