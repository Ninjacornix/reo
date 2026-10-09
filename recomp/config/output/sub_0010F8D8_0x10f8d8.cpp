#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010F8D8
// Address: 0x10f8d8 - 0x10f92c
void sub_0010F8D8_0x10f8d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010F8D8_0x10f8d8");
#endif

    switch (ctx->pc) {
        case 0x10f918u: goto label_10f918;
        default: break;
    }

    ctx->pc = 0x10f8d8u;

    // 0x10f8d8: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x10f8d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x10f8dc: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x10f8dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x10f8e0: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x10f8e0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f8e4: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x10f8e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f8e8: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x10f8e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x10f8ec: 0xafa40054  sw          $a0, 0x54($sp)
    ctx->pc = 0x10f8ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 4));
    // 0x10f8f0: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x10f8f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f8f4: 0x24020208  addiu       $v0, $zero, 0x208
    ctx->pc = 0x10f8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 520));
    // 0x10f8f8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x10f8f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f8fc: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x10f8fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x10f900: 0xafa30014  sw          $v1, 0x14($sp)
    ctx->pc = 0x10f900u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x10f904: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x10f904u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x10f908: 0xa7a2000c  sh          $v0, 0xC($sp)
    ctx->pc = 0x10f908u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x10f90c: 0xafa80010  sw          $t0, 0x10($sp)
    ctx->pc = 0x10f90cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x10f910: 0xc04345a  jal         func_10D168
    ctx->pc = 0x10F910u;
    SET_GPR_U32(ctx, 31, 0x10F918u);
    ctx->pc = 0x10F914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F910u;
            // 0x10f914: 0xafa80000  sw          $t0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D168u;
    if (runtime->hasFunction(0x10D168u)) {
        auto targetFn = runtime->lookupFunction(0x10D168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F918u; }
        if (ctx->pc != 0x10F918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D168_0x10d168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F918u; }
        if (ctx->pc != 0x10F918u) { return; }
    }
    ctx->pc = 0x10F918u;
label_10f918:
    // 0x10f918: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x10f918u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10f91c: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x10f91cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x10f920: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x10f920u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x10f924: 0x3e00008  jr          $ra
    ctx->pc = 0x10F924u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10F928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F924u;
            // 0x10f928: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10F918u: goto label_10f918;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10F92Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
