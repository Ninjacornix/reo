#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179BA0
// Address: 0x179ba0 - 0x179be8
void sub_00179BA0_0x179ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179BA0_0x179ba0");
#endif

    switch (ctx->pc) {
        case 0x179bc0u: goto label_179bc0;
        default: break;
    }

    ctx->pc = 0x179ba0u;

    // 0x179ba0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179ba4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179ba8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179bac: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x179bacu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179bb0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179bb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179bb4: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x179bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179bb8: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179BB8u;
    SET_GPR_U32(ctx, 31, 0x179BC0u);
    ctx->pc = 0x179BBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179BB8u;
            // 0x179bbc: 0x245000b0  addiu       $s0, $v0, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179BC0u; }
        if (ctx->pc != 0x179BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179BC0u; }
        if (ctx->pc != 0x179BC0u) { return; }
    }
    ctx->pc = 0x179BC0u;
label_179bc0:
    // 0x179bc0: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179BC0u;
    {
        const bool branch_taken_0x179bc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179bc0) {
            ctx->pc = 0x179BC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179BC0u;
            // 0x179bc4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179BD8u;
            goto label_179bd8;
        }
    }
    ctx->pc = 0x179BC8u;
    // 0x179bc8: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x179bc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x179bcc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179bccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179bd0: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179bd0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x179bd4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179bd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179bd8:
    // 0x179bd8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179bd8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179bdc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179bdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179be0: 0x3e00008  jr          $ra
    ctx->pc = 0x179BE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179BE0u;
            // 0x179be4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179BC0u: goto label_179bc0;
            case 0x179BD8u: goto label_179bd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179BE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
