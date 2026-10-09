#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115100
// Address: 0x115100 - 0x115168
void sub_00115100_0x115100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115100_0x115100");
#endif

    switch (ctx->pc) {
        case 0x115130u: goto label_115130;
        case 0x115138u: goto label_115138;
        case 0x115150u: goto label_115150;
        default: break;
    }

    ctx->pc = 0x115100u;

    // 0x115100: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x115100u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x115104: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x115104u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115108: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x115108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11510c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11510cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115110: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x115110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x115114: 0x40106000  mfc0        $s0, Status
    ctx->pc = 0x115114u;
    SET_GPR_S32(ctx, 16, (int32_t)ctx->cop0_status);
    // 0x115118: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x115118u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x11511c: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x11511cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x115120: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x115120u;
    {
        const bool branch_taken_0x115120 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x115120) {
            ctx->pc = 0x115130u;
            goto label_115130;
        }
    }
    ctx->pc = 0x115128u;
    // 0x115128: 0xc047598  jal         func_11D660
    ctx->pc = 0x115128u;
    SET_GPR_U32(ctx, 31, 0x115130u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115130u; }
        if (ctx->pc != 0x115130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115130u; }
        if (ctx->pc != 0x115130u) { return; }
    }
    ctx->pc = 0x115130u;
label_115130:
    // 0x115130: 0xc0450dc  jal         func_114370
    ctx->pc = 0x115130u;
    SET_GPR_U32(ctx, 31, 0x115138u);
    ctx->pc = 0x115134u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115130u;
            // 0x115134: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114370u;
    if (runtime->hasFunction(0x114370u)) {
        auto targetFn = runtime->lookupFunction(0x114370u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115138u; }
        if (ctx->pc != 0x115138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114370_0x114370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115138u; }
        if (ctx->pc != 0x115138u) { return; }
    }
    ctx->pc = 0x115138u;
label_115138:
    // 0x115138: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x115138u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11513c: 0xf  sync
    ctx->pc = 0x11513cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x115140: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x115140u;
    {
        const bool branch_taken_0x115140 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x115144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115140u;
            // 0x115144: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115140) {
            ctx->pc = 0x115154u;
            goto label_115154;
        }
    }
    ctx->pc = 0x115148u;
    // 0x115148: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x115148u;
    SET_GPR_U32(ctx, 31, 0x115150u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115150u; }
        if (ctx->pc != 0x115150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115150u; }
        if (ctx->pc != 0x115150u) { return; }
    }
    ctx->pc = 0x115150u;
label_115150:
    // 0x115150: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x115150u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_115154:
    // 0x115154: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x115154u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115158: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x115158u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11515c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11515cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115160: 0x3e00008  jr          $ra
    ctx->pc = 0x115160u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115160u;
            // 0x115164: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115130u: goto label_115130;
            case 0x115138u: goto label_115138;
            case 0x115150u: goto label_115150;
            case 0x115154u: goto label_115154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115168u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
