#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00144248
// Address: 0x144248 - 0x144268
void sub_00144248_0x144248(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00144248_0x144248");
#endif

    switch (ctx->pc) {
        case 0x144258u: goto label_144258;
        default: break;
    }

    ctx->pc = 0x144248u;

    // 0x144248: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x144248u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14424c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x14424cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x144250: 0xc051552  jal         func_145548
    ctx->pc = 0x144250u;
    SET_GPR_U32(ctx, 31, 0x144258u);
    ctx->pc = 0x144254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144250u;
            // 0x144254: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145548u;
    if (runtime->hasFunction(0x145548u)) {
        auto targetFn = runtime->lookupFunction(0x145548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144258u; }
        if (ctx->pc != 0x144258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145548_0x145548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144258u; }
        if (ctx->pc != 0x144258u) { return; }
    }
    ctx->pc = 0x144258u;
label_144258:
    // 0x144258: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x144258u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14425c: 0x3e00008  jr          $ra
    ctx->pc = 0x14425Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x144260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14425Cu;
            // 0x144260: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144258u: goto label_144258;
            default: break;
        }
        return;
    }
    ctx->pc = 0x144264u;
    // 0x144264: 0x0  nop
    ctx->pc = 0x144264u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
