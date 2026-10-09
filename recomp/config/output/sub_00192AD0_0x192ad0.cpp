#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192AD0
// Address: 0x192ad0 - 0x192b2c
void sub_00192AD0_0x192ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192AD0_0x192ad0");
#endif

    switch (ctx->pc) {
        case 0x192ad4u: goto label_192ad4;
        case 0x192b04u: goto label_192b04;
        default: break;
    }

    ctx->pc = 0x192ad0u;

    // 0x192ad0: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x192ad0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_192ad4:
    // 0x192ad4: 0xac8000d4  sw          $zero, 0xD4($a0)
    ctx->pc = 0x192ad4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 212), GPR_U32(ctx, 0));
    // 0x192ad8: 0xac8000d8  sw          $zero, 0xD8($a0)
    ctx->pc = 0x192ad8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 216), GPR_U32(ctx, 0));
    // 0x192adc: 0x8c8200d0  lw          $v0, 0xD0($a0)
    ctx->pc = 0x192adcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 208)));
    // 0x192ae0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192AE0u;
    {
        const bool branch_taken_0x192ae0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x192ae0) {
            ctx->pc = 0x192AF0u;
            goto label_192af0;
        }
    }
    ctx->pc = 0x192AE8u;
    // 0x192ae8: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x192AE8u;
    {
        const bool branch_taken_0x192ae8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192AE8u;
            // 0x192aec: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192ae8) {
            ctx->pc = 0x192AD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192ad4;
        }
    }
    ctx->pc = 0x192AF0u;
label_192af0:
    // 0x192af0: 0x8c8200cc  lw          $v0, 0xCC($a0)
    ctx->pc = 0x192af0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192af4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x192AF4u;
    {
        const bool branch_taken_0x192af4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x192af4) {
            ctx->pc = 0x192B1Cu;
            goto label_192b1c;
        }
    }
    ctx->pc = 0x192AFCu;
    // 0x192afc: 0x1000fff5  b           . + 4 + (-0xB << 2)
    ctx->pc = 0x192AFCu;
    {
        const bool branch_taken_0x192afc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192AFCu;
            // 0x192b00: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192afc) {
            ctx->pc = 0x192AD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192ad4;
        }
    }
    ctx->pc = 0x192B04u;
label_192b04:
    // 0x192b04: 0x8c8200cc  lw          $v0, 0xCC($a0)
    ctx->pc = 0x192b04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192b08: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192B08u;
    {
        const bool branch_taken_0x192b08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x192b08) {
            ctx->pc = 0x192B18u;
            goto label_192b18;
        }
    }
    ctx->pc = 0x192B10u;
    // 0x192b10: 0x1000fff0  b           . + 4 + (-0x10 << 2)
    ctx->pc = 0x192B10u;
    {
        const bool branch_taken_0x192b10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192B10u;
            // 0x192b14: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192b10) {
            ctx->pc = 0x192AD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192ad4;
        }
    }
    ctx->pc = 0x192B18u;
label_192b18:
    // 0x192b18: 0x8c8400c8  lw          $a0, 0xC8($a0)
    ctx->pc = 0x192b18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 200)));
label_192b1c:
    // 0x192b1c: 0x1483fff9  bne         $a0, $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x192B1Cu;
    {
        const bool branch_taken_0x192b1c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x192B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192B1Cu;
            // 0x192b20: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192b1c) {
            ctx->pc = 0x192B04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192b04;
        }
    }
    ctx->pc = 0x192B24u;
    // 0x192b24: 0x3e00008  jr          $ra
    ctx->pc = 0x192B24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192AD4u: goto label_192ad4;
            case 0x192AF0u: goto label_192af0;
            case 0x192B04u: goto label_192b04;
            case 0x192B18u: goto label_192b18;
            case 0x192B1Cu: goto label_192b1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192B2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
