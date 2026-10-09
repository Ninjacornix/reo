#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5C30
// Address: 0x1a5c30 - 0x1a5c80
void sub_001A5C30_0x1a5c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5C30_0x1a5c30");
#endif

    ctx->pc = 0x1a5c30u;

label_1a5c30:
    // 0x1a5c30: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a5c30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a5c34: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A5C34u;
    {
        const bool branch_taken_0x1a5c34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a5c34) {
            ctx->pc = 0x1A5C44u;
            goto label_1a5c44;
        }
    }
    ctx->pc = 0x1A5C3Cu;
    // 0x1a5c3c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A5C3Cu;
    {
        const bool branch_taken_0x1a5c3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5C3Cu;
            // 0x1a5c40: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5c3c) {
            ctx->pc = 0x1A5C6Cu;
            goto label_1a5c6c;
        }
    }
    ctx->pc = 0x1A5C44u;
label_1a5c44:
    // 0x1a5c44: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1a5c44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a5c48: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x1a5c48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1a5c4c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A5C4Cu;
    {
        const bool branch_taken_0x1a5c4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a5c4c) {
            ctx->pc = 0x1A5C64u;
            goto label_1a5c64;
        }
    }
    ctx->pc = 0x1A5C54u;
    // 0x1a5c54: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1a5c54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1a5c58: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1a5c58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1a5c5c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A5C5Cu;
    {
        const bool branch_taken_0x1a5c5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5C5Cu;
            // 0x1a5c60: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5c5c) {
            ctx->pc = 0x1A5C6Cu;
            goto label_1a5c6c;
        }
    }
    ctx->pc = 0x1A5C64u;
label_1a5c64:
    // 0x1a5c64: 0x1000fff2  b           . + 4 + (-0xE << 2)
    ctx->pc = 0x1A5C64u;
    {
        const bool branch_taken_0x1a5c64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5C64u;
            // 0x1a5c68: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5c64) {
            ctx->pc = 0x1A5C30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a5c30;
        }
    }
    ctx->pc = 0x1A5C6Cu;
label_1a5c6c:
    // 0x1a5c6c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5C30u: goto label_1a5c30;
            case 0x1A5C44u: goto label_1a5c44;
            case 0x1A5C64u: goto label_1a5c64;
            case 0x1A5C6Cu: goto label_1a5c6c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5C74u;
    // 0x1a5c74: 0x0  nop
    ctx->pc = 0x1a5c74u;
    // NOP
    // 0x1a5c78: 0x0  nop
    ctx->pc = 0x1a5c78u;
    // NOP
    // 0x1a5c7c: 0x0  nop
    ctx->pc = 0x1a5c7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
