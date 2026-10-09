#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E320
// Address: 0x12e320 - 0x12e358
void sub_0012E320_0x12e320(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E320_0x12e320");
#endif

    ctx->pc = 0x12e320u;

    // 0x12e320: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12e320u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12e324: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x12e324u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e328: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12E328u;
    {
        const bool branch_taken_0x12e328 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E328u;
            // 0x12e32c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e328) {
            ctx->pc = 0x12E348u;
            goto label_12e348;
        }
    }
    ctx->pc = 0x12E330u;
    // 0x12e330: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12e330u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e334: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12e334u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e338: 0x24060090  addiu       $a2, $zero, 0x90
    ctx->pc = 0x12e338u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
    // 0x12e33c: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x12e33cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x12e340: 0x8041f1a  j           func_107C68
    ctx->pc = 0x12E340u;
    ctx->pc = 0x12E344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E340u;
            // 0x12e344: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12E348u;
label_12e348:
    // 0x12e348: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12e348u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e34c: 0x3e00008  jr          $ra
    ctx->pc = 0x12E34Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E34Cu;
            // 0x12e350: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E348u: goto label_12e348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E354u;
    // 0x12e354: 0x0  nop
    ctx->pc = 0x12e354u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
