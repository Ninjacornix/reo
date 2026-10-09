#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019D3F0
// Address: 0x19d3f0 - 0x19d440
void sub_0019D3F0_0x19d3f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019D3F0_0x19d3f0");
#endif

    switch (ctx->pc) {
        case 0x19d400u: goto label_19d400;
        default: break;
    }

    ctx->pc = 0x19d3f0u;

    // 0x19d3f0: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x19d3f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x19d3f4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x19d3f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d3f8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19D3F8u;
    {
        const bool branch_taken_0x19d3f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D3FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D3F8u;
            // 0x19d3fc: 0x24634e80  addiu       $v1, $v1, 0x4E80 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 20096));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d3f8) {
            ctx->pc = 0x19D41Cu;
            goto label_19d41c;
        }
    }
    ctx->pc = 0x19D400u;
label_19d400:
    // 0x19d400: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x19d400u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19d404: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x19d404u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x19d408: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x19d408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x19d40c: 0x80420034  lb          $v0, 0x34($v0)
    ctx->pc = 0x19d40cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x19d410: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x19D410u;
    {
        const bool branch_taken_0x19d410 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D410u;
            // 0x19d414: 0x24820001  addiu       $v0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d410) {
            ctx->pc = 0x19D42Cu;
            goto label_19d42c;
        }
    }
    ctx->pc = 0x19D418u;
    // 0x19d418: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x19d418u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_19d41c:
    // 0x19d41c: 0x28820100  slti        $v0, $a0, 0x100
    ctx->pc = 0x19d41cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x19d420: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x19D420u;
    {
        const bool branch_taken_0x19d420 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D420u;
            // 0x19d424: 0x410c0  sll         $v0, $a0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d420) {
            ctx->pc = 0x19D400u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19d400;
        }
    }
    ctx->pc = 0x19D428u;
    // 0x19d428: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x19d428u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_19d42c:
    // 0x19d42c: 0x3e00008  jr          $ra
    ctx->pc = 0x19D42Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19D430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D42Cu;
            // 0x19d430: 0x21400  sll         $v0, $v0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19D400u: goto label_19d400;
            case 0x19D41Cu: goto label_19d41c;
            case 0x19D42Cu: goto label_19d42c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19D434u;
    // 0x19d434: 0x0  nop
    ctx->pc = 0x19d434u;
    // NOP
    // 0x19d438: 0x0  nop
    ctx->pc = 0x19d438u;
    // NOP
    // 0x19d43c: 0x0  nop
    ctx->pc = 0x19d43cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
