#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179A60
// Address: 0x179a60 - 0x179aa8
void sub_00179A60_0x179a60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179A60_0x179a60");
#endif

    switch (ctx->pc) {
        case 0x179a80u: goto label_179a80;
        default: break;
    }

    ctx->pc = 0x179a60u;

    // 0x179a60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179a60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179a64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179a64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179a68: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179a68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179a6c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x179a6cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179a70: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179a70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179a74: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x179a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179a78: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179A78u;
    SET_GPR_U32(ctx, 31, 0x179A80u);
    ctx->pc = 0x179A7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179A78u;
            // 0x179a7c: 0x245000b0  addiu       $s0, $v0, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179A80u; }
        if (ctx->pc != 0x179A80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179A80u; }
        if (ctx->pc != 0x179A80u) { return; }
    }
    ctx->pc = 0x179A80u;
label_179a80:
    // 0x179a80: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179A80u;
    {
        const bool branch_taken_0x179a80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179a80) {
            ctx->pc = 0x179A84u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179A80u;
            // 0x179a84: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179A98u;
            goto label_179a98;
        }
    }
    ctx->pc = 0x179A88u;
    // 0x179a88: 0x92030001  lbu         $v1, 0x1($s0)
    ctx->pc = 0x179a88u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x179a8c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179a90: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179a90u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x179a94: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179a94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179a98:
    // 0x179a98: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179a98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179a9c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179a9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179aa0: 0x3e00008  jr          $ra
    ctx->pc = 0x179AA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179AA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179AA0u;
            // 0x179aa4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179A80u: goto label_179a80;
            case 0x179A98u: goto label_179a98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179AA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
