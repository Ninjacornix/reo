#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128038
// Address: 0x128038 - 0x128070
void sub_00128038_0x128038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128038_0x128038");
#endif

    switch (ctx->pc) {
        case 0x128054u: goto label_128054;
        default: break;
    }

    ctx->pc = 0x128038u;

    // 0x128038: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x128038u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12803c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12803cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128040: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128040u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128044: 0x2484c7b8  addiu       $a0, $a0, -0x3848
    ctx->pc = 0x128044u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952888));
    // 0x128048: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x128048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12804c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x12804Cu;
    SET_GPR_U32(ctx, 31, 0x128054u);
    ctx->pc = 0x128050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12804Cu;
            // 0x128050: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128054u; }
        if (ctx->pc != 0x128054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128054u; }
        if (ctx->pc != 0x128054u) { return; }
    }
    ctx->pc = 0x128054u;
label_128054:
    // 0x128054: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x128054u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128058: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x128058u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12805c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12805cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128060: 0xac60c7b0  sw          $zero, -0x3850($v1)
    ctx->pc = 0x128060u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294952880), GPR_U32(ctx, 0));
    // 0x128064: 0xac40c7b4  sw          $zero, -0x384C($v0)
    ctx->pc = 0x128064u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294952884), GPR_U32(ctx, 0));
    // 0x128068: 0x3e00008  jr          $ra
    ctx->pc = 0x128068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12806Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128068u;
            // 0x12806c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128054u: goto label_128054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128070u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
