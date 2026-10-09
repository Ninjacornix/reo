#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D000
// Address: 0x11d000 - 0x11d030
void sub_0011D000_0x11d000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D000_0x11d000");
#endif

    switch (ctx->pc) {
        case 0x11d024u: goto label_11d024;
        default: break;
    }

    ctx->pc = 0x11d000u;

    // 0x11d000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11d000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11d004: 0x2482fff3  addiu       $v0, $a0, -0xD
    ctx->pc = 0x11d004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967283));
    // 0x11d008: 0x2c420023  sltiu       $v0, $v0, 0x23
    ctx->pc = 0x11d008u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)35) ? 1 : 0);
    // 0x11d00c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11D00Cu;
    {
        const bool branch_taken_0x11d00c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11D010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D00Cu;
            // 0x11d010: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d00c) {
            ctx->pc = 0x11D01Cu;
            goto label_11d01c;
        }
    }
    ctx->pc = 0x11D014u;
    // 0x11d014: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11D014u;
    {
        const bool branch_taken_0x11d014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D014u;
            // 0x11d018: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d014) {
            ctx->pc = 0x11D024u;
            goto label_11d024;
        }
    }
    ctx->pc = 0x11D01Cu;
label_11d01c:
    // 0x11d01c: 0xc0473fc  jal         func_11CFF0
    ctx->pc = 0x11D01Cu;
    SET_GPR_U32(ctx, 31, 0x11D024u);
    ctx->pc = 0x11CFF0u;
    if (runtime->hasFunction(0x11CFF0u)) {
        auto targetFn = runtime->lookupFunction(0x11CFF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D024u; }
        if (ctx->pc != 0x11D024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CFF0_0x11cff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D024u; }
        if (ctx->pc != 0x11D024u) { return; }
    }
    ctx->pc = 0x11D024u;
label_11d024:
    // 0x11d024: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11d024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11d028: 0x3e00008  jr          $ra
    ctx->pc = 0x11D028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D028u;
            // 0x11d02c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D01Cu: goto label_11d01c;
            case 0x11D024u: goto label_11d024;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D030u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
