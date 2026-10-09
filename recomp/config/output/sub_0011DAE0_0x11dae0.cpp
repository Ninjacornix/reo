#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DAE0
// Address: 0x11dae0 - 0x11db20
void sub_0011DAE0_0x11dae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DAE0_0x11dae0");
#endif

    switch (ctx->pc) {
        case 0x11daf8u: goto label_11daf8;
        default: break;
    }

    ctx->pc = 0x11dae0u;

    // 0x11dae0: 0x2403005a  addiu       $v1, $zero, 0x5A
    ctx->pc = 0x11dae0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x11dae4: 0xc  syscall     0
    ctx->pc = 0x11dae4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11dae8: 0x3e00008  jr          $ra
    ctx->pc = 0x11DAE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DAF8u: goto label_11daf8;
            case 0x11DB18u: goto label_11db18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DAF0u;
    // 0x11daf0: 0x10c00009  beqz        $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x11DAF0u;
    {
        const bool branch_taken_0x11daf0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11DAF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DAF0u;
            // 0x11daf4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11daf0) {
            ctx->pc = 0x11DB18u;
            goto label_11db18;
        }
    }
    ctx->pc = 0x11DAF8u;
label_11daf8:
    // 0x11daf8: 0x90a30000  lbu         $v1, 0x0($a1)
    ctx->pc = 0x11daf8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11dafc: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x11dafcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x11db00: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11db00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x11db04: 0xe6102b  sltu        $v0, $a3, $a2
    ctx->pc = 0x11db04u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x11db08: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x11db08u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x11db0c: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x11db0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x11db10: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11DB10u;
    {
        const bool branch_taken_0x11db10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11db10) {
            ctx->pc = 0x11DAF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11daf8;
        }
    }
    ctx->pc = 0x11DB18u;
label_11db18:
    // 0x11db18: 0x3e00008  jr          $ra
    ctx->pc = 0x11DB18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DB1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DB18u;
            // 0x11db1c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DAF8u: goto label_11daf8;
            case 0x11DB18u: goto label_11db18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DB20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
