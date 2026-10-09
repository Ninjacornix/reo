#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182158
// Address: 0x182158 - 0x182194
void sub_00182158_0x182158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182158_0x182158");
#endif

    switch (ctx->pc) {
        case 0x182168u: goto label_182168;
        case 0x182184u: goto label_182184;
        default: break;
    }

    ctx->pc = 0x182158u;

    // 0x182158: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18215c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18215cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x182160: 0xc06065c  jal         func_181970
    ctx->pc = 0x182160u;
    SET_GPR_U32(ctx, 31, 0x182168u);
    ctx->pc = 0x181970u;
    if (runtime->hasFunction(0x181970u)) {
        auto targetFn = runtime->lookupFunction(0x181970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182168u; }
        if (ctx->pc != 0x182168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181970_0x181970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182168u; }
        if (ctx->pc != 0x182168u) { return; }
    }
    ctx->pc = 0x182168u;
label_182168:
    // 0x182168: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x182168u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18216c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x18216cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x182170: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182170u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182174: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182174u;
    {
        const bool branch_taken_0x182174 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182174u;
            // 0x182178: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182174) {
            ctx->pc = 0x182188u;
            goto label_182188;
        }
    }
    ctx->pc = 0x18217Cu;
    // 0x18217c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x18217Cu;
    SET_GPR_U32(ctx, 31, 0x182184u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182184u; }
        if (ctx->pc != 0x182184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182184u; }
        if (ctx->pc != 0x182184u) { return; }
    }
    ctx->pc = 0x182184u;
label_182184:
    // 0x182184: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182184u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182188:
    // 0x182188: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182188u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18218c: 0x3e00008  jr          $ra
    ctx->pc = 0x18218Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18218Cu;
            // 0x182190: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182168u: goto label_182168;
            case 0x182184u: goto label_182184;
            case 0x182188u: goto label_182188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182194u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
