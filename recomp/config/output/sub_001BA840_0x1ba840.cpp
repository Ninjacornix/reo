#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA840
// Address: 0x1ba840 - 0x1ba890
void sub_001BA840_0x1ba840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA840_0x1ba840");
#endif

    switch (ctx->pc) {
        case 0x1ba858u: goto label_1ba858;
        default: break;
    }

    ctx->pc = 0x1ba840u;

    // 0x1ba840: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ba840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ba844: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ba844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ba848: 0x27a5001c  addiu       $a1, $sp, 0x1C
    ctx->pc = 0x1ba848u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
    // 0x1ba84c: 0xa3a0001c  sb          $zero, 0x1C($sp)
    ctx->pc = 0x1ba84cu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 28), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba850: 0xc06ea28  jal         func_1BA8A0
    ctx->pc = 0x1BA850u;
    SET_GPR_U32(ctx, 31, 0x1BA858u);
    ctx->pc = 0x1BA854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA850u;
            // 0x1ba854: 0xa3a0001d  sb          $zero, 0x1D($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 29), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA8A0u;
    if (runtime->hasFunction(0x1BA8A0u)) {
        auto targetFn = runtime->lookupFunction(0x1BA8A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA858u; }
        if (ctx->pc != 0x1BA858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA8A0_0x1ba8a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA858u; }
        if (ctx->pc != 0x1BA858u) { return; }
    }
    ctx->pc = 0x1BA858u;
label_1ba858:
    // 0x1ba858: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba858u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba85c: 0xa420657c  sh          $zero, 0x657C($at)
    ctx->pc = 0x1ba85cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 25980), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ba860: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba860u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba864: 0xa420657e  sh          $zero, 0x657E($at)
    ctx->pc = 0x1ba864u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 25982), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ba868: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba868u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba86c: 0xac206580  sw          $zero, 0x6580($at)
    ctx->pc = 0x1ba86cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 25984), GPR_U32(ctx, 0));
    // 0x1ba870: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba870u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba874: 0xa0206571  sb          $zero, 0x6571($at)
    ctx->pc = 0x1ba874u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 25969), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba878: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ba878u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba87c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA87Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA87Cu;
            // 0x1ba880: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA858u: goto label_1ba858;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA884u;
    // 0x1ba884: 0x0  nop
    ctx->pc = 0x1ba884u;
    // NOP
    // 0x1ba888: 0x0  nop
    ctx->pc = 0x1ba888u;
    // NOP
    // 0x1ba88c: 0x0  nop
    ctx->pc = 0x1ba88cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
