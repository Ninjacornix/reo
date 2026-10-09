#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001151D0
// Address: 0x1151d0 - 0x115238
void sub_001151D0_0x1151d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001151D0_0x1151d0");
#endif

    switch (ctx->pc) {
        case 0x115200u: goto label_115200;
        case 0x115208u: goto label_115208;
        case 0x115220u: goto label_115220;
        default: break;
    }

    ctx->pc = 0x1151d0u;

    // 0x1151d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1151d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1151d4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1151d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1151d8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1151d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1151dc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1151dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1151e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1151e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1151e4: 0x40106000  mfc0        $s0, Status
    ctx->pc = 0x1151e4u;
    SET_GPR_S32(ctx, 16, (int32_t)ctx->cop0_status);
    // 0x1151e8: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1151e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1151ec: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x1151ecu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x1151f0: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1151F0u;
    {
        const bool branch_taken_0x1151f0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1151f0) {
            ctx->pc = 0x115200u;
            goto label_115200;
        }
    }
    ctx->pc = 0x1151F8u;
    // 0x1151f8: 0xc047598  jal         func_11D660
    ctx->pc = 0x1151F8u;
    SET_GPR_U32(ctx, 31, 0x115200u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115200u; }
        if (ctx->pc != 0x115200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115200u; }
        if (ctx->pc != 0x115200u) { return; }
    }
    ctx->pc = 0x115200u;
label_115200:
    // 0x115200: 0xc0450e4  jal         func_114390
    ctx->pc = 0x115200u;
    SET_GPR_U32(ctx, 31, 0x115208u);
    ctx->pc = 0x115204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115200u;
            // 0x115204: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114390u;
    if (runtime->hasFunction(0x114390u)) {
        auto targetFn = runtime->lookupFunction(0x114390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115208u; }
        if (ctx->pc != 0x115208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114390_0x114390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115208u; }
        if (ctx->pc != 0x115208u) { return; }
    }
    ctx->pc = 0x115208u;
label_115208:
    // 0x115208: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x115208u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11520c: 0xf  sync
    ctx->pc = 0x11520cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x115210: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x115210u;
    {
        const bool branch_taken_0x115210 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x115214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115210u;
            // 0x115214: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115210) {
            ctx->pc = 0x115224u;
            goto label_115224;
        }
    }
    ctx->pc = 0x115218u;
    // 0x115218: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x115218u;
    SET_GPR_U32(ctx, 31, 0x115220u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115220u; }
        if (ctx->pc != 0x115220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115220u; }
        if (ctx->pc != 0x115220u) { return; }
    }
    ctx->pc = 0x115220u;
label_115220:
    // 0x115220: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x115220u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_115224:
    // 0x115224: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x115224u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115228: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x115228u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11522c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11522cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115230: 0x3e00008  jr          $ra
    ctx->pc = 0x115230u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115230u;
            // 0x115234: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115200u: goto label_115200;
            case 0x115208u: goto label_115208;
            case 0x115220u: goto label_115220;
            case 0x115224u: goto label_115224;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115238u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
