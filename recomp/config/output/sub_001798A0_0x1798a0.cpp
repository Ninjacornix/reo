#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001798A0
// Address: 0x1798a0 - 0x1798e8
void sub_001798A0_0x1798a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001798A0_0x1798a0");
#endif

    switch (ctx->pc) {
        case 0x1798c0u: goto label_1798c0;
        default: break;
    }

    ctx->pc = 0x1798a0u;

    // 0x1798a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1798a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1798a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1798a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1798a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1798a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1798ac: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1798acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1798b0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1798b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1798b4: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1798b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1798b8: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x1798B8u;
    SET_GPR_U32(ctx, 31, 0x1798C0u);
    ctx->pc = 0x1798BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1798B8u;
            // 0x1798bc: 0x24500080  addiu       $s0, $v0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1798C0u; }
        if (ctx->pc != 0x1798C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1798C0u; }
        if (ctx->pc != 0x1798C0u) { return; }
    }
    ctx->pc = 0x1798C0u;
label_1798c0:
    // 0x1798c0: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1798C0u;
    {
        const bool branch_taken_0x1798c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1798c0) {
            ctx->pc = 0x1798C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1798C0u;
            // 0x1798c4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1798D8u;
            goto label_1798d8;
        }
    }
    ctx->pc = 0x1798C8u;
    // 0x1798c8: 0x86030008  lh          $v1, 0x8($s0)
    ctx->pc = 0x1798c8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1798cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1798ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1798d0: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1798d0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1798d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1798d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1798d8:
    // 0x1798d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1798d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1798dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1798dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1798e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1798E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1798E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1798E0u;
            // 0x1798e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1798C0u: goto label_1798c0;
            case 0x1798D8u: goto label_1798d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1798E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
