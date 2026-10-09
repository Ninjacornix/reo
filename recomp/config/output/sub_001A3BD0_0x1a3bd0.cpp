#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3BD0
// Address: 0x1a3bd0 - 0x1a3c20
void sub_001A3BD0_0x1a3bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3BD0_0x1a3bd0");
#endif

    switch (ctx->pc) {
        case 0x1a3be8u: goto label_1a3be8;
        default: break;
    }

    ctx->pc = 0x1a3bd0u;

    // 0x1a3bd0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3bd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3bd4: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1a3bd4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3bd8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3bd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a3bdc: 0x3c050008  lui         $a1, 0x8
    ctx->pc = 0x1a3bdcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)8 << 16));
    // 0x1a3be0: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3BE0u;
    SET_GPR_U32(ctx, 31, 0x1A3BE8u);
    ctx->pc = 0x1A3BE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3BE0u;
            // 0x1a3be4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3BE8u; }
        if (ctx->pc != 0x1A3BE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3BE8u; }
        if (ctx->pc != 0x1A3BE8u) { return; }
    }
    ctx->pc = 0x1A3BE8u;
label_1a3be8:
    // 0x1a3be8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3BE8u;
    {
        const bool branch_taken_0x1a3be8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3BE8u;
            // 0x1a3bec: 0x81840  sll         $v1, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3be8) {
            ctx->pc = 0x1A3BF8u;
            goto label_1a3bf8;
        }
    }
    ctx->pc = 0x1A3BF0u;
    // 0x1a3bf0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A3BF0u;
    {
        const bool branch_taken_0x1a3bf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3BF0u;
            // 0x1a3bf4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3bf0) {
            ctx->pc = 0x1A3C08u;
            goto label_1a3c08;
        }
    }
    ctx->pc = 0x1A3BF8u;
label_1a3bf8:
    // 0x1a3bf8: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x1a3bf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1a3bfc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a3bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a3c00: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a3c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a3c04: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1a3c04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
label_1a3c08:
    // 0x1a3c08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3c08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3c0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3C0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3C0Cu;
            // 0x1a3c10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3BE8u: goto label_1a3be8;
            case 0x1A3BF8u: goto label_1a3bf8;
            case 0x1A3C08u: goto label_1a3c08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3C14u;
    // 0x1a3c14: 0x0  nop
    ctx->pc = 0x1a3c14u;
    // NOP
    // 0x1a3c18: 0x0  nop
    ctx->pc = 0x1a3c18u;
    // NOP
    // 0x1a3c1c: 0x0  nop
    ctx->pc = 0x1a3c1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
