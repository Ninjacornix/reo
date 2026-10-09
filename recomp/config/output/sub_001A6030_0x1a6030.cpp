#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A6030
// Address: 0x1a6030 - 0x1a6090
void sub_001A6030_0x1a6030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A6030_0x1a6030");
#endif

    switch (ctx->pc) {
        case 0x1a6048u: goto label_1a6048;
        case 0x1a6058u: goto label_1a6058;
        case 0x1a6068u: goto label_1a6068;
        case 0x1a6078u: goto label_1a6078;
        default: break;
    }

    ctx->pc = 0x1a6030u;

    // 0x1a6030: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a6030u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a6034: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6034u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6038: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a6038u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a603c: 0x24840a30  addiu       $a0, $a0, 0xA30
    ctx->pc = 0x1a603cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2608));
    // 0x1a6040: 0xc068608  jal         func_1A1820
    ctx->pc = 0x1A6040u;
    SET_GPR_U32(ctx, 31, 0x1A6048u);
    ctx->pc = 0x1A6044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6040u;
            // 0x1a6044: 0x24050024  addiu       $a1, $zero, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1820u;
    if (runtime->hasFunction(0x1A1820u)) {
        auto targetFn = runtime->lookupFunction(0x1A1820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6048u; }
        if (ctx->pc != 0x1A6048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1820_0x1a1820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6048u; }
        if (ctx->pc != 0x1A6048u) { return; }
    }
    ctx->pc = 0x1A6048u;
label_1a6048:
    // 0x1a6048: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6048u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a604c: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1a604cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1a6050: 0xc068608  jal         func_1A1820
    ctx->pc = 0x1A6050u;
    SET_GPR_U32(ctx, 31, 0x1A6058u);
    ctx->pc = 0x1A6054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6050u;
            // 0x1a6054: 0x248409e0  addiu       $a0, $a0, 0x9E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1820u;
    if (runtime->hasFunction(0x1A1820u)) {
        auto targetFn = runtime->lookupFunction(0x1A1820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6058u; }
        if (ctx->pc != 0x1A6058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1820_0x1a1820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6058u; }
        if (ctx->pc != 0x1A6058u) { return; }
    }
    ctx->pc = 0x1A6058u;
label_1a6058:
    // 0x1a6058: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6058u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a605c: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1a605cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1a6060: 0xc068608  jal         func_1A1820
    ctx->pc = 0x1A6060u;
    SET_GPR_U32(ctx, 31, 0x1A6068u);
    ctx->pc = 0x1A6064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6060u;
            // 0x1a6064: 0x248409c0  addiu       $a0, $a0, 0x9C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2496));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1820u;
    if (runtime->hasFunction(0x1A1820u)) {
        auto targetFn = runtime->lookupFunction(0x1A1820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6068u; }
        if (ctx->pc != 0x1A6068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1820_0x1a1820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6068u; }
        if (ctx->pc != 0x1A6068u) { return; }
    }
    ctx->pc = 0x1A6068u;
label_1a6068:
    // 0x1a6068: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6068u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a606c: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1a606cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1a6070: 0xc068608  jal         func_1A1820
    ctx->pc = 0x1A6070u;
    SET_GPR_U32(ctx, 31, 0x1A6078u);
    ctx->pc = 0x1A6074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6070u;
            // 0x1a6074: 0x248409a0  addiu       $a0, $a0, 0x9A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2464));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1820u;
    if (runtime->hasFunction(0x1A1820u)) {
        auto targetFn = runtime->lookupFunction(0x1A1820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6078u; }
        if (ctx->pc != 0x1A6078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1820_0x1a1820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6078u; }
        if (ctx->pc != 0x1A6078u) { return; }
    }
    ctx->pc = 0x1A6078u;
label_1a6078:
    // 0x1a6078: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a6078u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a607c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A607Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A6080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A607Cu;
            // 0x1a6080: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A6048u: goto label_1a6048;
            case 0x1A6058u: goto label_1a6058;
            case 0x1A6068u: goto label_1a6068;
            case 0x1A6078u: goto label_1a6078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A6084u;
    // 0x1a6084: 0x0  nop
    ctx->pc = 0x1a6084u;
    // NOP
    // 0x1a6088: 0x0  nop
    ctx->pc = 0x1a6088u;
    // NOP
    // 0x1a608c: 0x0  nop
    ctx->pc = 0x1a608cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
