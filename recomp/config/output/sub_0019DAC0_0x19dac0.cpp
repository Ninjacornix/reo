#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019DAC0
// Address: 0x19dac0 - 0x19db10
void sub_0019DAC0_0x19dac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019DAC0_0x19dac0");
#endif

    switch (ctx->pc) {
        case 0x19dad4u: goto label_19dad4;
        default: break;
    }

    ctx->pc = 0x19dac0u;

    // 0x19dac0: 0x4243c  dsll32      $a0, $a0, 16
    ctx->pc = 0x19dac0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 16));
    // 0x19dac4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x19dac4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19dac8: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x19dac8u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x19dacc: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x19daccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19dad0: 0xa21804  sllv        $v1, $v0, $a1
    ctx->pc = 0x19dad0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
label_19dad4:
    // 0x19dad4: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x19dad4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x19dad8: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x19DAD8u;
    {
        const bool branch_taken_0x19dad8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19dad8) {
            ctx->pc = 0x19DAECu;
            goto label_19daec;
        }
    }
    ctx->pc = 0x19DAE0u;
    // 0x19dae0: 0x5143c  dsll32      $v0, $a1, 16
    ctx->pc = 0x19dae0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 16));
    // 0x19dae4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x19DAE4u;
    {
        const bool branch_taken_0x19dae4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DAE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DAE4u;
            // 0x19dae8: 0x2143f  dsra32      $v0, $v0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19dae4) {
            ctx->pc = 0x19DAFCu;
            goto label_19dafc;
        }
    }
    ctx->pc = 0x19DAECu;
label_19daec:
    // 0x19daec: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x19daecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x19daf0: 0x28a1000b  slti        $at, $a1, 0xB
    ctx->pc = 0x19daf0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)11) ? 1 : 0);
    // 0x19daf4: 0x1420fff7  bnez        $at, . + 4 + (-0x9 << 2)
    ctx->pc = 0x19DAF4u;
    {
        const bool branch_taken_0x19daf4 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x19DAF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DAF4u;
            // 0x19daf8: 0xa21804  sllv        $v1, $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19daf4) {
            ctx->pc = 0x19DAD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19dad4;
        }
    }
    ctx->pc = 0x19DAFCu;
label_19dafc:
    // 0x19dafc: 0x3e00008  jr          $ra
    ctx->pc = 0x19DAFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19DAD4u: goto label_19dad4;
            case 0x19DAECu: goto label_19daec;
            case 0x19DAFCu: goto label_19dafc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19DB04u;
    // 0x19db04: 0x0  nop
    ctx->pc = 0x19db04u;
    // NOP
    // 0x19db08: 0x0  nop
    ctx->pc = 0x19db08u;
    // NOP
    // 0x19db0c: 0x0  nop
    ctx->pc = 0x19db0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
