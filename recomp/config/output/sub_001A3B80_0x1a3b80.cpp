#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3B80
// Address: 0x1a3b80 - 0x1a3bd0
void sub_001A3B80_0x1a3b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3B80_0x1a3b80");
#endif

    switch (ctx->pc) {
        case 0x1a3b98u: goto label_1a3b98;
        default: break;
    }

    ctx->pc = 0x1a3b80u;

    // 0x1a3b80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3b80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3b84: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1a3b84u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3b88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3b88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a3b8c: 0x3c050007  lui         $a1, 0x7
    ctx->pc = 0x1a3b8cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)7 << 16));
    // 0x1a3b90: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3B90u;
    SET_GPR_U32(ctx, 31, 0x1A3B98u);
    ctx->pc = 0x1A3B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3B90u;
            // 0x1a3b94: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3B98u; }
        if (ctx->pc != 0x1A3B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3B98u; }
        if (ctx->pc != 0x1A3B98u) { return; }
    }
    ctx->pc = 0x1A3B98u;
label_1a3b98:
    // 0x1a3b98: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3B98u;
    {
        const bool branch_taken_0x1a3b98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3B98u;
            // 0x1a3b9c: 0x81840  sll         $v1, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3b98) {
            ctx->pc = 0x1A3BA8u;
            goto label_1a3ba8;
        }
    }
    ctx->pc = 0x1A3BA0u;
    // 0x1a3ba0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A3BA0u;
    {
        const bool branch_taken_0x1a3ba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3BA0u;
            // 0x1a3ba4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3ba0) {
            ctx->pc = 0x1A3BB8u;
            goto label_1a3bb8;
        }
    }
    ctx->pc = 0x1A3BA8u;
label_1a3ba8:
    // 0x1a3ba8: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x1a3ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1a3bac: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a3bacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a3bb0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a3bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a3bb4: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1a3bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
label_1a3bb8:
    // 0x1a3bb8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3bb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3bbc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3BBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3BC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3BBCu;
            // 0x1a3bc0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3B98u: goto label_1a3b98;
            case 0x1A3BA8u: goto label_1a3ba8;
            case 0x1A3BB8u: goto label_1a3bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3BC4u;
    // 0x1a3bc4: 0x0  nop
    ctx->pc = 0x1a3bc4u;
    // NOP
    // 0x1a3bc8: 0x0  nop
    ctx->pc = 0x1a3bc8u;
    // NOP
    // 0x1a3bcc: 0x0  nop
    ctx->pc = 0x1a3bccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
