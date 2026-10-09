#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CB50
// Address: 0x13cb50 - 0x13cbb0
void sub_0013CB50_0x13cb50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CB50_0x13cb50");
#endif

    switch (ctx->pc) {
        case 0x13cb74u: goto label_13cb74;
        default: break;
    }

    ctx->pc = 0x13cb50u;

    // 0x13cb50: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x13cb50u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x13cb54: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13cb54u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cb58: 0x24c3e110  addiu       $v1, $a2, -0x1EF0
    ctx->pc = 0x13cb58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294959376));
    // 0x13cb5c: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x13cb5cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13cb60: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13CB60u;
    {
        const bool branch_taken_0x13cb60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CB60u;
            // 0x13cb64: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cb60) {
            ctx->pc = 0x13CB70u;
            goto label_13cb70;
        }
    }
    ctx->pc = 0x13CB68u;
    // 0x13cb68: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x13CB68u;
    {
        const bool branch_taken_0x13cb68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CB6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CB68u;
            // 0x13cb6c: 0x60382d  daddu       $a3, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cb68) {
            ctx->pc = 0x13CBA8u;
            goto label_13cba8;
        }
    }
    ctx->pc = 0x13CB70u;
label_13cb70:
    // 0x13cb70: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x13cb70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_13cb74:
    // 0x13cb74: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x13cb74u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x13cb78: 0x28a30010  slti        $v1, $a1, 0x10
    ctx->pc = 0x13cb78u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13cb7c: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x13CB7Cu;
    {
        const bool branch_taken_0x13cb7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CB80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CB7Cu;
            // 0x13cb80: 0x451021  addu        $v0, $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cb7c) {
            ctx->pc = 0x13CBA8u;
            goto label_13cba8;
        }
    }
    ctx->pc = 0x13CB84u;
    // 0x13cb84: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x13cb84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x13cb88: 0x24c4e110  addiu       $a0, $a2, -0x1EF0
    ctx->pc = 0x13cb88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 4294959376));
    // 0x13cb8c: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x13cb8cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x13cb90: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x13cb90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x13cb94: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x13cb94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13cb98: 0x80430000  lb          $v1, 0x0($v0)
    ctx->pc = 0x13cb98u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13cb9c: 0x5460fff5  bnel        $v1, $zero, . + 4 + (-0xB << 2)
    ctx->pc = 0x13CB9Cu;
    {
        const bool branch_taken_0x13cb9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x13cb9c) {
            ctx->pc = 0x13CBA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13CB9Cu;
            // 0x13cba0: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13CB74u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13cb74;
        }
    }
    ctx->pc = 0x13CBA4u;
    // 0x13cba4: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x13cba4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_13cba8:
    // 0x13cba8: 0x3e00008  jr          $ra
    ctx->pc = 0x13CBA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CBACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CBA8u;
            // 0x13cbac: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CB70u: goto label_13cb70;
            case 0x13CB74u: goto label_13cb74;
            case 0x13CBA8u: goto label_13cba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CBB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
