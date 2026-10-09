#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173F90
// Address: 0x173f90 - 0x173fb0
void sub_00173F90_0x173f90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173F90_0x173f90");
#endif

    switch (ctx->pc) {
        case 0x173fa0u: goto label_173fa0;
        default: break;
    }

    ctx->pc = 0x173f90u;

    // 0x173f90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173f90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173f94: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x173f94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x173f98: 0xc059f40  jal         func_167D00
    ctx->pc = 0x173F98u;
    SET_GPR_U32(ctx, 31, 0x173FA0u);
    ctx->pc = 0x173F9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173F98u;
            // 0x173f9c: 0x8c851ab4  lw          $a1, 0x1AB4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6836)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173FA0u; }
        if (ctx->pc != 0x173FA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D00_0x167d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173FA0u; }
        if (ctx->pc != 0x173FA0u) { return; }
    }
    ctx->pc = 0x173FA0u;
label_173fa0:
    // 0x173fa0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x173fa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173fa4: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x173fa4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x173fa8: 0x3e00008  jr          $ra
    ctx->pc = 0x173FA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173FA8u;
            // 0x173fac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173FA0u: goto label_173fa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173FB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
