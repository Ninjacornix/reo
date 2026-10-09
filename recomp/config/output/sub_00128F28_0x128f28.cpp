#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128F28
// Address: 0x128f28 - 0x128f80
void sub_00128F28_0x128f28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128F28_0x128f28");
#endif

    switch (ctx->pc) {
        case 0x128f4cu: goto label_128f4c;
        default: break;
    }

    ctx->pc = 0x128f28u;

    // 0x128f28: 0x3c060021  lui         $a2, 0x21
    ctx->pc = 0x128f28u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)33 << 16));
    // 0x128f2c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x128f2cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128f30: 0x24c3c8c0  addiu       $v1, $a2, -0x3740
    ctx->pc = 0x128f30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294953152));
    // 0x128f34: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x128f34u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x128f38: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x128F38u;
    {
        const bool branch_taken_0x128f38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x128F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128F38u;
            // 0x128f3c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128f38) {
            ctx->pc = 0x128F48u;
            goto label_128f48;
        }
    }
    ctx->pc = 0x128F40u;
    // 0x128f40: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x128F40u;
    {
        const bool branch_taken_0x128f40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128F44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128F40u;
            // 0x128f44: 0x60382d  daddu       $a3, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128f40) {
            ctx->pc = 0x128F78u;
            goto label_128f78;
        }
    }
    ctx->pc = 0x128F48u;
label_128f48:
    // 0x128f48: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x128f48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_128f4c:
    // 0x128f4c: 0x51100  sll         $v0, $a1, 4
    ctx->pc = 0x128f4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x128f50: 0x28a30010  slti        $v1, $a1, 0x10
    ctx->pc = 0x128f50u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x128f54: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x128F54u;
    {
        const bool branch_taken_0x128f54 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x128F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128F54u;
            // 0x128f58: 0x451021  addu        $v0, $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128f54) {
            ctx->pc = 0x128F78u;
            goto label_128f78;
        }
    }
    ctx->pc = 0x128F5Cu;
    // 0x128f5c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x128f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x128f60: 0x24c3c8c0  addiu       $v1, $a2, -0x3740
    ctx->pc = 0x128f60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294953152));
    // 0x128f64: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x128f64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x128f68: 0x80440000  lb          $a0, 0x0($v0)
    ctx->pc = 0x128f68u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x128f6c: 0x5480fff7  bnel        $a0, $zero, . + 4 + (-0x9 << 2)
    ctx->pc = 0x128F6Cu;
    {
        const bool branch_taken_0x128f6c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x128f6c) {
            ctx->pc = 0x128F70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128F6Cu;
            // 0x128f70: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x128F4Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_128f4c;
        }
    }
    ctx->pc = 0x128F74u;
    // 0x128f74: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x128f74u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_128f78:
    // 0x128f78: 0x3e00008  jr          $ra
    ctx->pc = 0x128F78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128F78u;
            // 0x128f7c: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128F48u: goto label_128f48;
            case 0x128F4Cu: goto label_128f4c;
            case 0x128F78u: goto label_128f78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128F80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
