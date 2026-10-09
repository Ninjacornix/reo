#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C0C0
// Address: 0x12c0c0 - 0x12c120
void sub_0012C0C0_0x12c0c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C0C0_0x12c0c0");
#endif

    switch (ctx->pc) {
        case 0x12c114u: goto label_12c114;
        default: break;
    }

    ctx->pc = 0x12c0c0u;

    // 0x12c0c0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12c0c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12c0c4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x12c0c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c0c8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x12C0C8u;
    {
        const bool branch_taken_0x12c0c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12C0CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C0C8u;
            // 0x12c0cc: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12c0c8) {
            ctx->pc = 0x12C108u;
            goto label_12c108;
        }
    }
    ctx->pc = 0x12C0D0u;
    // 0x12c0d0: 0x8c460008  lw          $a2, 0x8($v0)
    ctx->pc = 0x12c0d0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x12c0d4: 0x24070019  addiu       $a3, $zero, 0x19
    ctx->pc = 0x12c0d4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x12c0d8: 0x8c44000c  lw          $a0, 0xC($v0)
    ctx->pc = 0x12c0d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x12c0dc: 0x3a0402d  daddu       $t0, $sp, $zero
    ctx->pc = 0x12c0dcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c0e0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x12c0e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12c0e4: 0x24c50001  addiu       $a1, $a2, 0x1
    ctx->pc = 0x12c0e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x12c0e8: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x12c0e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x12c0ec: 0xafa40010  sw          $a0, 0x10($sp)
    ctx->pc = 0x12c0ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 4));
    // 0x12c0f0: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x12c0f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x12c0f4: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x12c0f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x12c0f8: 0xafa5000c  sw          $a1, 0xC($sp)
    ctx->pc = 0x12c0f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 5));
    // 0x12c0fc: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x12c0fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x12c100: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x12C100u;
    {
        const bool branch_taken_0x12c100 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12C104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C100u;
            // 0x12c104: 0xafa60008  sw          $a2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12c100) {
            ctx->pc = 0x12C10Cu;
            goto label_12c10c;
        }
    }
    ctx->pc = 0x12C108u;
label_12c108:
    // 0x12c108: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x12c108u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12c10c:
    // 0x12c10c: 0xc04ad8e  jal         func_12B638
    ctx->pc = 0x12C10Cu;
    SET_GPR_U32(ctx, 31, 0x12C114u);
    ctx->pc = 0x12C110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C10Cu;
            // 0x12c110: 0x100202d  daddu       $a0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B638u;
    if (runtime->hasFunction(0x12B638u)) {
        auto targetFn = runtime->lookupFunction(0x12B638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C114u; }
        if (ctx->pc != 0x12C114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B638_0x12b638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C114u; }
        if (ctx->pc != 0x12C114u) { return; }
    }
    ctx->pc = 0x12C114u;
label_12c114:
    // 0x12c114: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x12c114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12c118: 0x3e00008  jr          $ra
    ctx->pc = 0x12C118u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C11Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C118u;
            // 0x12c11c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C108u: goto label_12c108;
            case 0x12C10Cu: goto label_12c10c;
            case 0x12C114u: goto label_12c114;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C120u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
