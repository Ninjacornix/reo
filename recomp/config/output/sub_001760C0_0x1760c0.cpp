#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001760C0
// Address: 0x1760c0 - 0x176110
void sub_001760C0_0x1760c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001760C0_0x1760c0");
#endif

    switch (ctx->pc) {
        case 0x1760e8u: goto label_1760e8;
        default: break;
    }

    ctx->pc = 0x1760c0u;

    // 0x1760c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1760c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1760c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1760c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1760c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1760c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1760cc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1760ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1760d0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1760d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1760d4: 0x8e030118  lw          $v1, 0x118($s0)
    ctx->pc = 0x1760d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 280)));
    // 0x1760d8: 0x4600008  bltz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1760D8u;
    {
        const bool branch_taken_0x1760d8 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1760DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1760D8u;
            // 0x1760dc: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1760d8) {
            ctx->pc = 0x1760FCu;
            goto label_1760fc;
        }
    }
    ctx->pc = 0x1760E0u;
    // 0x1760e0: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x1760E0u;
    SET_GPR_U32(ctx, 31, 0x1760E8u);
    ctx->pc = 0x1760E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1760E0u;
            // 0x1760e4: 0x240657e4  addiu       $a2, $zero, 0x57E4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 22500));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1760E8u; }
        if (ctx->pc != 0x1760E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1760E8u; }
        if (ctx->pc != 0x1760E8u) { return; }
    }
    ctx->pc = 0x1760E8u;
label_1760e8:
    // 0x1760e8: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1760e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1760ec: 0x8e040118  lw          $a0, 0x118($s0)
    ctx->pc = 0x1760ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 280)));
    // 0x1760f0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1760f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1760f4: 0xac62f1cc  sw          $v0, -0xE34($v1)
    ctx->pc = 0x1760f4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963660), GPR_U32(ctx, 2));
    // 0x1760f8: 0xaca4f1c8  sw          $a0, -0xE38($a1)
    ctx->pc = 0x1760f8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294963656), GPR_U32(ctx, 4));
label_1760fc:
    // 0x1760fc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1760fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176100: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x176100u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176104: 0x3e00008  jr          $ra
    ctx->pc = 0x176104u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176104u;
            // 0x176108: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1760E8u: goto label_1760e8;
            case 0x1760FCu: goto label_1760fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17610Cu;
    // 0x17610c: 0x0  nop
    ctx->pc = 0x17610cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
