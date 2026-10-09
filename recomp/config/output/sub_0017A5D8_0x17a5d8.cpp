#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A5D8
// Address: 0x17a5d8 - 0x17a620
void sub_0017A5D8_0x17a5d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A5D8_0x17a5d8");
#endif

    ctx->pc = 0x17a5d8u;

    // 0x17a5d8: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x17a5d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a5dc: 0x240200c0  addiu       $v0, $zero, 0xC0
    ctx->pc = 0x17a5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x17a5e0: 0x24a3ff40  addiu       $v1, $a1, -0xC0
    ctx->pc = 0x17a5e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967104));
    // 0x17a5e4: 0x24a4ff20  addiu       $a0, $a1, -0xE0
    ctx->pc = 0x17a5e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967072));
    // 0x17a5e8: 0x2c630020  sltiu       $v1, $v1, 0x20
    ctx->pc = 0x17a5e8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x17a5ec: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x17A5ECu;
    {
        const bool branch_taken_0x17a5ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17A5F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A5ECu;
            // 0x17a5f0: 0x2c840010  sltiu       $a0, $a0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a5ec) {
            ctx->pc = 0x17A614u;
            goto label_17a614;
        }
    }
    ctx->pc = 0x17A5F4u;
    // 0x17a5f4: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17A5F4u;
    {
        const bool branch_taken_0x17a5f4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x17A5F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A5F4u;
            // 0x17a5f8: 0x240200e0  addiu       $v0, $zero, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a5f4) {
            ctx->pc = 0x17A614u;
            goto label_17a614;
        }
    }
    ctx->pc = 0x17A5FCu;
    // 0x17a5fc: 0x240200bd  addiu       $v0, $zero, 0xBD
    ctx->pc = 0x17a5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 189));
    // 0x17a600: 0x10a20004  beq         $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x17A600u;
    {
        const bool branch_taken_0x17a600 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x17A604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A600u;
            // 0x17a604: 0x240300bf  addiu       $v1, $zero, 0xBF (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 191));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a600) {
            ctx->pc = 0x17A614u;
            goto label_17a614;
        }
    }
    ctx->pc = 0x17A608u;
    // 0x17a608: 0x14a30002  bne         $a1, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x17A608u;
    {
        const bool branch_taken_0x17a608 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x17A60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A608u;
            // 0x17a60c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a608) {
            ctx->pc = 0x17A614u;
            goto label_17a614;
        }
    }
    ctx->pc = 0x17A610u;
    // 0x17a610: 0x240200bd  addiu       $v0, $zero, 0xBD
    ctx->pc = 0x17a610u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 189));
label_17a614:
    // 0x17a614: 0x3e00008  jr          $ra
    ctx->pc = 0x17A614u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A614u: goto label_17a614;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A61Cu;
    // 0x17a61c: 0x0  nop
    ctx->pc = 0x17a61cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
