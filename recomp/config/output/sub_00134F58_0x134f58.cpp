#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134F58
// Address: 0x134f58 - 0x134f98
void sub_00134F58_0x134f58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134F58_0x134f58");
#endif

    ctx->pc = 0x134f58u;

    // 0x134f58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x134f58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x134f5c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x134f5cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134f60: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x134F60u;
    {
        const bool branch_taken_0x134f60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x134F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134F60u;
            // 0x134f64: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134f60) {
            ctx->pc = 0x134F80u;
            goto label_134f80;
        }
    }
    ctx->pc = 0x134F68u;
    // 0x134f68: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134f68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134f6c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x134f6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134f70: 0x2406003c  addiu       $a2, $zero, 0x3C
    ctx->pc = 0x134f70u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x134f74: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x134f74u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x134f78: 0x8041f1a  j           func_107C68
    ctx->pc = 0x134F78u;
    ctx->pc = 0x134F7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134F78u;
            // 0x134f7c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x134F80u;
label_134f80:
    // 0x134f80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134f80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134f84: 0x3e00008  jr          $ra
    ctx->pc = 0x134F84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134F84u;
            // 0x134f88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134F80u: goto label_134f80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134F8Cu;
    // 0x134f8c: 0x0  nop
    ctx->pc = 0x134f8cu;
    // NOP
    // 0x134f90: 0x3e00008  jr          $ra
    ctx->pc = 0x134F90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134F90u;
            // 0x134f94: 0xac850008  sw          $a1, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134F80u: goto label_134f80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134F98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
