#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132F80
// Address: 0x132f80 - 0x132fb0
void sub_00132F80_0x132f80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132F80_0x132f80");
#endif

    switch (ctx->pc) {
        case 0x132f98u: goto label_132f98;
        default: break;
    }

    ctx->pc = 0x132f80u;

    // 0x132f80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132f80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132f84: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132F84u;
    {
        const bool branch_taken_0x132f84 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132F84u;
            // 0x132f88: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132f84) {
            ctx->pc = 0x132FA0u;
            goto label_132fa0;
        }
    }
    ctx->pc = 0x132F8Cu;
    // 0x132f8c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132f8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132f90: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132F90u;
    SET_GPR_U32(ctx, 31, 0x132F98u);
    ctx->pc = 0x132F94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132F90u;
            // 0x132f94: 0x2484b4e8  addiu       $a0, $a0, -0x4B18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132F98u; }
        if (ctx->pc != 0x132F98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132F98u; }
        if (ctx->pc != 0x132F98u) { return; }
    }
    ctx->pc = 0x132F98u;
label_132f98:
    // 0x132f98: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132F98u;
    {
        const bool branch_taken_0x132f98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132F98u;
            // 0x132f9c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132f98) {
            ctx->pc = 0x132FA4u;
            goto label_132fa4;
        }
    }
    ctx->pc = 0x132FA0u;
label_132fa0:
    // 0x132fa0: 0x80820072  lb          $v0, 0x72($a0)
    ctx->pc = 0x132fa0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 114)));
label_132fa4:
    // 0x132fa4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132fa4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132fa8: 0x3e00008  jr          $ra
    ctx->pc = 0x132FA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132FA8u;
            // 0x132fac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132F98u: goto label_132f98;
            case 0x132FA0u: goto label_132fa0;
            case 0x132FA4u: goto label_132fa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132FB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
