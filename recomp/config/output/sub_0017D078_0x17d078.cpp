#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D078
// Address: 0x17d078 - 0x17d0c8
void sub_0017D078_0x17d078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D078_0x17d078");
#endif

    switch (ctx->pc) {
        case 0x17d098u: goto label_17d098;
        default: break;
    }

    ctx->pc = 0x17d078u;

    // 0x17d078: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17d078u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17d07c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x17d07cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d080: 0x2442f2a0  addiu       $v0, $v0, -0xD60
    ctx->pc = 0x17d080u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963872));
    // 0x17d084: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x17d084u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x17d088: 0x18a0000c  blez        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x17D088u;
    {
        const bool branch_taken_0x17d088 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x17D08Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D088u;
            // 0x17d08c: 0x24420018  addiu       $v0, $v0, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d088) {
            ctx->pc = 0x17D0BCu;
            goto label_17d0bc;
        }
    }
    ctx->pc = 0x17D090u;
    // 0x17d090: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x17d090u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d094: 0x0  nop
    ctx->pc = 0x17d094u;
    // NOP
label_17d098:
    // 0x17d098: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x17d098u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d09c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x17d09cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d0a0: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17D0A0u;
    {
        const bool branch_taken_0x17d0a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x17D0A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D0A0u;
            // 0x17d0a4: 0x24840090  addiu       $a0, $a0, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d0a0) {
            ctx->pc = 0x17D0C0u;
            goto label_17d0c0;
        }
    }
    ctx->pc = 0x17D0A8u;
    // 0x17d0a8: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x17d0a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x17d0ac: 0xc5102a  slt         $v0, $a2, $a1
    ctx->pc = 0x17d0acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x17d0b0: 0x0  nop
    ctx->pc = 0x17d0b0u;
    // NOP
    // 0x17d0b4: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x17D0B4u;
    {
        const bool branch_taken_0x17d0b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17d0b4) {
            ctx->pc = 0x17D098u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17d098;
        }
    }
    ctx->pc = 0x17D0BCu;
label_17d0bc:
    // 0x17d0bc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17d0bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17d0c0:
    // 0x17d0c0: 0x3e00008  jr          $ra
    ctx->pc = 0x17D0C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D098u: goto label_17d098;
            case 0x17D0BCu: goto label_17d0bc;
            case 0x17D0C0u: goto label_17d0c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D0C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
