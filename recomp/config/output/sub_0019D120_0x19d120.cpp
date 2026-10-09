#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019D120
// Address: 0x19d120 - 0x19d170
void sub_0019D120_0x19d120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019D120_0x19d120");
#endif

    switch (ctx->pc) {
        case 0x19d130u: goto label_19d130;
        default: break;
    }

    ctx->pc = 0x19d120u;

    // 0x19d120: 0x3c03002a  lui         $v1, 0x2A
    ctx->pc = 0x19d120u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)42 << 16));
    // 0x19d124: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x19d124u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d128: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19D128u;
    {
        const bool branch_taken_0x19d128 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D12Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D128u;
            // 0x19d12c: 0x24638680  addiu       $v1, $v1, -0x7980 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294936192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d128) {
            ctx->pc = 0x19D14Cu;
            goto label_19d14c;
        }
    }
    ctx->pc = 0x19D130u;
label_19d130:
    // 0x19d130: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x19d130u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19d134: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x19d134u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x19d138: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x19d138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x19d13c: 0x80420034  lb          $v0, 0x34($v0)
    ctx->pc = 0x19d13cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x19d140: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x19D140u;
    {
        const bool branch_taken_0x19d140 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D140u;
            // 0x19d144: 0x24820001  addiu       $v0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d140) {
            ctx->pc = 0x19D15Cu;
            goto label_19d15c;
        }
    }
    ctx->pc = 0x19D148u;
    // 0x19d148: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x19d148u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_19d14c:
    // 0x19d14c: 0x28820100  slti        $v0, $a0, 0x100
    ctx->pc = 0x19d14cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x19d150: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x19D150u;
    {
        const bool branch_taken_0x19d150 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D150u;
            // 0x19d154: 0x410c0  sll         $v0, $a0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d150) {
            ctx->pc = 0x19D130u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19d130;
        }
    }
    ctx->pc = 0x19D158u;
    // 0x19d158: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x19d158u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_19d15c:
    // 0x19d15c: 0x3e00008  jr          $ra
    ctx->pc = 0x19D15Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19D130u: goto label_19d130;
            case 0x19D14Cu: goto label_19d14c;
            case 0x19D15Cu: goto label_19d15c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19D164u;
    // 0x19d164: 0x0  nop
    ctx->pc = 0x19d164u;
    // NOP
    // 0x19d168: 0x0  nop
    ctx->pc = 0x19d168u;
    // NOP
    // 0x19d16c: 0x0  nop
    ctx->pc = 0x19d16cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
