#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001724C8
// Address: 0x1724c8 - 0x172530
void sub_001724C8_0x1724c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001724C8_0x1724c8");
#endif

    switch (ctx->pc) {
        case 0x1724e8u: goto label_1724e8;
        case 0x1724fcu: goto label_1724fc;
        default: break;
    }

    ctx->pc = 0x1724c8u;

    // 0x1724c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1724c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1724cc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1724ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1724d0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1724d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1724d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1724d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1724d8: 0x2450f18c  addiu       $s0, $v0, -0xE74
    ctx->pc = 0x1724d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963596));
    // 0x1724dc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1724dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1724e0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1724e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1724e4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1724e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_1724e8:
    // 0x1724e8: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x1724e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1724ec: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1724ECu;
    {
        const bool branch_taken_0x1724ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1724F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1724ECu;
            // 0x1724f0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1724ec) {
            ctx->pc = 0x172504u;
            goto label_172504;
        }
    }
    ctx->pc = 0x1724F4u;
    // 0x1724f4: 0xc05c928  jal         func_1724A0
    ctx->pc = 0x1724F4u;
    SET_GPR_U32(ctx, 31, 0x1724FCu);
    ctx->pc = 0x1724A0u;
    if (runtime->hasFunction(0x1724A0u)) {
        auto targetFn = runtime->lookupFunction(0x1724A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1724FCu; }
        if (ctx->pc != 0x1724FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001724A0_0x1724a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1724FCu; }
        if (ctx->pc != 0x1724FCu) { return; }
    }
    ctx->pc = 0x1724FCu;
label_1724fc:
    // 0x1724fc: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1724FCu;
    {
        const bool branch_taken_0x1724fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1724fc) {
            ctx->pc = 0x172500u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1724FCu;
            // 0x172500: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17251Cu;
            goto label_17251c;
        }
    }
    ctx->pc = 0x172504u;
label_172504:
    // 0x172504: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x172504u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x172508: 0x2a220008  slti        $v0, $s1, 0x8
    ctx->pc = 0x172508u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x17250c: 0x5440fff6  bnel        $v0, $zero, . + 4 + (-0xA << 2)
    ctx->pc = 0x17250Cu;
    {
        const bool branch_taken_0x17250c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17250c) {
            ctx->pc = 0x172510u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17250Cu;
            // 0x172510: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1724E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1724e8;
        }
    }
    ctx->pc = 0x172514u;
    // 0x172514: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x172514u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172518: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172518u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17251c:
    // 0x17251c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17251cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172520: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172520u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172524: 0x3e00008  jr          $ra
    ctx->pc = 0x172524u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172524u;
            // 0x172528: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1724E8u: goto label_1724e8;
            case 0x1724FCu: goto label_1724fc;
            case 0x172504u: goto label_172504;
            case 0x17251Cu: goto label_17251c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17252Cu;
    // 0x17252c: 0x0  nop
    ctx->pc = 0x17252cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
