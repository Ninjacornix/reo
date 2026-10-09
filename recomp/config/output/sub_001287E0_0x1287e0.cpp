#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001287E0
// Address: 0x1287e0 - 0x128828
void sub_001287E0_0x1287e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001287E0_0x1287e0");
#endif

    switch (ctx->pc) {
        case 0x12881cu: goto label_12881c;
        default: break;
    }

    ctx->pc = 0x1287e0u;

    // 0x1287e0: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x1287e0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287e4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1287e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287e8: 0xe0602d  daddu       $t4, $a3, $zero
    ctx->pc = 0x1287e8u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287ec: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1287ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1287f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1287f4: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1287f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287f8: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1287f8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287fc: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x1287fcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128800: 0x120582d  daddu       $t3, $t1, $zero
    ctx->pc = 0x128800u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128804: 0x180482d  daddu       $t1, $t4, $zero
    ctx->pc = 0x128804u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128808: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128808u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12880c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12880cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128810: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x128810u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x128814: 0xc04a218  jal         func_128860
    ctx->pc = 0x128814u;
    SET_GPR_U32(ctx, 31, 0x12881Cu);
    ctx->pc = 0x128818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128814u;
            // 0x128818: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128860u;
    if (runtime->hasFunction(0x128860u)) {
        auto targetFn = runtime->lookupFunction(0x128860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12881Cu; }
        if (ctx->pc != 0x12881Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128860_0x128860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12881Cu; }
        if (ctx->pc != 0x12881Cu) { return; }
    }
    ctx->pc = 0x12881Cu;
label_12881c:
    // 0x12881c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12881cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x128820: 0x3e00008  jr          $ra
    ctx->pc = 0x128820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128820u;
            // 0x128824: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12881Cu: goto label_12881c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128828u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
