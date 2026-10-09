#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D738
// Address: 0x11d738 - 0x11d770
void sub_0011D738_0x11d738(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D738_0x11d738");
#endif

    switch (ctx->pc) {
        case 0x11d748u: goto label_11d748;
        default: break;
    }

    ctx->pc = 0x11d738u;

    // 0x11d738: 0x63082  srl         $a2, $a2, 2
    ctx->pc = 0x11d738u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x11d73c: 0x10c0000a  beqz        $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x11D73Cu;
    {
        const bool branch_taken_0x11d73c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D73Cu;
            // 0x11d740: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d73c) {
            ctx->pc = 0x11D768u;
            goto label_11d768;
        }
    }
    ctx->pc = 0x11D744u;
    // 0x11d744: 0x0  nop
    ctx->pc = 0x11d744u;
    // NOP
label_11d748:
    // 0x11d748: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x11d748u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11d74c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x11d74cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x11d750: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x11d750u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x11d754: 0xe6102b  sltu        $v0, $a3, $a2
    ctx->pc = 0x11d754u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x11d758: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x11d758u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x11d75c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x11d75cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x11d760: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11D760u;
    {
        const bool branch_taken_0x11d760 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11d760) {
            ctx->pc = 0x11D748u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11d748;
        }
    }
    ctx->pc = 0x11D768u;
label_11d768:
    // 0x11d768: 0x3e00008  jr          $ra
    ctx->pc = 0x11D768u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D76Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D768u;
            // 0x11d76c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D748u: goto label_11d748;
            case 0x11D768u: goto label_11d768;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D770u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
