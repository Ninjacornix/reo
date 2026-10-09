#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179BE8
// Address: 0x179be8 - 0x179c30
void sub_00179BE8_0x179be8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179BE8_0x179be8");
#endif

    switch (ctx->pc) {
        case 0x179c08u: goto label_179c08;
        default: break;
    }

    ctx->pc = 0x179be8u;

    // 0x179be8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179be8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179bec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179becu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179bf0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179bf4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x179bf4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179bf8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179bf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179bfc: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x179bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179c00: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179C00u;
    SET_GPR_U32(ctx, 31, 0x179C08u);
    ctx->pc = 0x179C04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179C00u;
            // 0x179c04: 0x245000b0  addiu       $s0, $v0, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179C08u; }
        if (ctx->pc != 0x179C08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179C08u; }
        if (ctx->pc != 0x179C08u) { return; }
    }
    ctx->pc = 0x179C08u;
label_179c08:
    // 0x179c08: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179C08u;
    {
        const bool branch_taken_0x179c08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179c08) {
            ctx->pc = 0x179C0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179C08u;
            // 0x179c0c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179C20u;
            goto label_179c20;
        }
    }
    ctx->pc = 0x179C10u;
    // 0x179c10: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x179c10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x179c14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179c14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179c18: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179c18u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x179c1c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179c1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179c20:
    // 0x179c20: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179c20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179c24: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179c24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179c28: 0x3e00008  jr          $ra
    ctx->pc = 0x179C28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179C28u;
            // 0x179c2c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179C08u: goto label_179c08;
            case 0x179C20u: goto label_179c20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179C30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
