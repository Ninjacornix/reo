#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E020
// Address: 0x15e020 - 0x15e048
void sub_0015E020_0x15e020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E020_0x15e020");
#endif

    ctx->pc = 0x15e020u;

    // 0x15e020: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e024: 0x248200b4  addiu       $v0, $a0, 0xB4
    ctx->pc = 0x15e024u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 180));
    // 0x15e028: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15e028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15e02c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15e02cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e030: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x15e030u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x15e034: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15e034u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e038: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x15e038u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x15e03c: 0x805855e  j           func_161578
    ctx->pc = 0x15E03Cu;
    ctx->pc = 0x15E040u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E03Cu;
            // 0x15e040: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161578u;
    if (runtime->hasFunction(0x161578u)) {
        auto targetFn = runtime->lookupFunction(0x161578u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00161578_0x161578(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15E044u;
    // 0x15e044: 0x0  nop
    ctx->pc = 0x15e044u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
