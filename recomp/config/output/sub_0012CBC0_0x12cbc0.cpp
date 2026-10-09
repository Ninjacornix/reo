#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012CBC0
// Address: 0x12cbc0 - 0x12cc10
void sub_0012CBC0_0x12cbc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012CBC0_0x12cbc0");
#endif

    switch (ctx->pc) {
        case 0x12cbe4u: goto label_12cbe4;
        default: break;
    }

    ctx->pc = 0x12cbc0u;

    // 0x12cbc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12cbc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12cbc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12cbc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12cbc8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12cbc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cbcc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12cbccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12cbd0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12cbd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cbd4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12cbd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12cbd8: 0xae110008  sw          $s1, 0x8($s0)
    ctx->pc = 0x12cbd8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 17));
    // 0x12cbdc: 0xc048bfc  jal         func_122FF0
    ctx->pc = 0x12CBDCu;
    SET_GPR_U32(ctx, 31, 0x12CBE4u);
    ctx->pc = 0x12CBE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CBDCu;
            // 0x12cbe0: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122FF0u;
    if (runtime->hasFunction(0x122FF0u)) {
        auto targetFn = runtime->lookupFunction(0x122FF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CBE4u; }
        if (ctx->pc != 0x12CBE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00122FF0_0x122ff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CBE4u; }
        if (ctx->pc != 0x12CBE4u) { return; }
    }
    ctx->pc = 0x12CBE4u;
label_12cbe4:
    // 0x12cbe4: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x12cbe4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12cbe8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x12cbe8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cbec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12cbecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12cbf0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12cbf0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12cbf4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12cbf4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12cbf8: 0x8048b90  j           func_122E40
    ctx->pc = 0x12CBF8u;
    ctx->pc = 0x12CBFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CBF8u;
            // 0x12cbfc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122E40u;
    if (runtime->hasFunction(0x122E40u)) {
        auto targetFn = runtime->lookupFunction(0x122E40u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00122E40_0x122e40(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12CC00u;
    // 0x12cc00: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x12cc00u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12cc04: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x12cc04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x12cc08: 0x3e00008  jr          $ra
    ctx->pc = 0x12CC08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12CC0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CC08u;
            // 0x12cc0c: 0xac86000c  sw          $a2, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CBE4u: goto label_12cbe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12CC10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
