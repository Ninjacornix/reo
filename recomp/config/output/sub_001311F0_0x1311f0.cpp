#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001311F0
// Address: 0x1311f0 - 0x131254
void sub_001311F0_0x1311f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001311F0_0x1311f0");
#endif

    switch (ctx->pc) {
        case 0x131230u: goto label_131230;
        case 0x131240u: goto label_131240;
        default: break;
    }

    ctx->pc = 0x1311f0u;

    // 0x1311f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1311f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1311f4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1311f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1311f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1311f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1311fc: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1311fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131200: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x131200u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131204: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x131204u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131208: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x131208u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13120c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13120cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131210: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x131210u;
    {
        const bool branch_taken_0x131210 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x131214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131210u;
            // 0x131214: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131210) {
            ctx->pc = 0x131238u;
            goto label_131238;
        }
    }
    ctx->pc = 0x131218u;
    // 0x131218: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x131218u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13121c: 0x8c47000c  lw          $a3, 0xC($v0)
    ctx->pc = 0x13121cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x131220: 0x8c480004  lw          $t0, 0x4($v0)
    ctx->pc = 0x131220u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x131224: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x131224u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131228: 0xc04eb18  jal         func_13AC60
    ctx->pc = 0x131228u;
    SET_GPR_U32(ctx, 31, 0x131230u);
    ctx->pc = 0x13122Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131228u;
            // 0x13122c: 0x8c460008  lw          $a2, 0x8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AC60u;
    if (runtime->hasFunction(0x13AC60u)) {
        auto targetFn = runtime->lookupFunction(0x13AC60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131230u; }
        if (ctx->pc != 0x131230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AC60_0x13ac60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131230u; }
        if (ctx->pc != 0x131230u) { return; }
    }
    ctx->pc = 0x131230u;
label_131230:
    // 0x131230: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x131230u;
    {
        const bool branch_taken_0x131230 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x131234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131230u;
            // 0x131234: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131230) {
            ctx->pc = 0x131240u;
            goto label_131240;
        }
    }
    ctx->pc = 0x131238u;
label_131238:
    // 0x131238: 0xc04eaac  jal         func_13AAB0
    ctx->pc = 0x131238u;
    SET_GPR_U32(ctx, 31, 0x131240u);
    ctx->pc = 0x13123Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131238u;
            // 0x13123c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AAB0u;
    if (runtime->hasFunction(0x13AAB0u)) {
        auto targetFn = runtime->lookupFunction(0x13AAB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131240u; }
        if (ctx->pc != 0x131240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AAB0_0x13aab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131240u; }
        if (ctx->pc != 0x131240u) { return; }
    }
    ctx->pc = 0x131240u;
label_131240:
    // 0x131240: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x131240u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131244: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131244u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131248: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x131248u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13124c: 0x3e00008  jr          $ra
    ctx->pc = 0x13124Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13124Cu;
            // 0x131250: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131230u: goto label_131230;
            case 0x131238u: goto label_131238;
            case 0x131240u: goto label_131240;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131254u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
