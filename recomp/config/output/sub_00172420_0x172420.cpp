#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172420
// Address: 0x172420 - 0x172480
void sub_00172420_0x172420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172420_0x172420");
#endif

    ctx->pc = 0x172420u;

    // 0x172420: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172420u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x172424: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x172424u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x172428: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x172428u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17242c: 0x805c90e  j           func_172438
    ctx->pc = 0x17242Cu;
    ctx->pc = 0x172430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17242Cu;
            // 0x172430: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172438u;
    goto label_172438;
    ctx->pc = 0x172434u;
    // 0x172434: 0x0  nop
    ctx->pc = 0x172434u;
    // NOP
label_172438:
    // 0x172438: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x172438u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x17243c: 0x3c035a5a  lui         $v1, 0x5A5A
    ctx->pc = 0x17243cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)23130 << 16));
    // 0x172440: 0x8c440a54  lw          $a0, 0xA54($v0)
    ctx->pc = 0x172440u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 2644)));
    // 0x172444: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172444u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x172448: 0x34635a5a  ori         $v1, $v1, 0x5A5A
    ctx->pc = 0x172448u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)23130);
    // 0x17244c: 0x10830008  beq         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x17244Cu;
    {
        const bool branch_taken_0x17244c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x172450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17244Cu;
            // 0x172450: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17244c) {
            ctx->pc = 0x172470u;
            goto label_172470;
        }
    }
    ctx->pc = 0x172454u;
    // 0x172454: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x172454u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x172458: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x172458u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17245c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17245cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172460: 0x34a50201  ori         $a1, $a1, 0x201
    ctx->pc = 0x172460u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)513);
    // 0x172464: 0x805a704  j           func_169C10
    ctx->pc = 0x172464u;
    ctx->pc = 0x172468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172464u;
            // 0x172468: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17246Cu;
    // 0x17246c: 0x0  nop
    ctx->pc = 0x17246cu;
    // NOP
label_172470:
    // 0x172470: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x172470u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172474: 0x3e00008  jr          $ra
    ctx->pc = 0x172474u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172474u;
            // 0x172478: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172438u: goto label_172438;
            case 0x172470u: goto label_172470;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17247Cu;
    // 0x17247c: 0x0  nop
    ctx->pc = 0x17247cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
