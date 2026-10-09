#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010D168
// Address: 0x10d168 - 0x10d1e0
void sub_0010D168_0x10d168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010D168_0x10d168");
#endif

    switch (ctx->pc) {
        case 0x10d1b4u: goto label_10d1b4;
        default: break;
    }

    ctx->pc = 0x10d168u;

    // 0x10d168: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10d168u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10d16c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10d16cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10d170: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10d170u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d174: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10d174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10d178: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x10d178u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d17c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x10d17cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x10d180: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x10d180u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d184: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x10d184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x10d188: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10d188u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10d18c: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D18Cu;
    {
        const bool branch_taken_0x10d18c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D18Cu;
            // 0x10d190: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d18c) {
            ctx->pc = 0x10D1A0u;
            goto label_10d1a0;
        }
    }
    ctx->pc = 0x10D194u;
    // 0x10d194: 0x8c4297f0  lw          $v0, -0x6810($v0)
    ctx->pc = 0x10d194u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10d198: 0xae020054  sw          $v0, 0x54($s0)
    ctx->pc = 0x10d198u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 2));
    // 0x10d19c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10d19cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10d1a0:
    // 0x10d1a0: 0x8c820038  lw          $v0, 0x38($a0)
    ctx->pc = 0x10d1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x10d1a4: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10D1A4u;
    {
        const bool branch_taken_0x10d1a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D1A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D1A4u;
            // 0x10d1a8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d1a4) {
            ctx->pc = 0x10D1BCu;
            goto label_10d1bc;
        }
    }
    ctx->pc = 0x10D1ACu;
    // 0x10d1ac: 0xc041544  jal         func_105510
    ctx->pc = 0x10D1ACu;
    SET_GPR_U32(ctx, 31, 0x10D1B4u);
    ctx->pc = 0x105510u;
    if (runtime->hasFunction(0x105510u)) {
        auto targetFn = runtime->lookupFunction(0x105510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D1B4u; }
        if (ctx->pc != 0x10D1B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105510_0x105510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D1B4u; }
        if (ctx->pc != 0x10D1B4u) { return; }
    }
    ctx->pc = 0x10D1B4u;
label_10d1b4:
    // 0x10d1b4: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10d1b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10d1b8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x10d1b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_10d1bc:
    // 0x10d1bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10d1bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10d1c0: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x10d1c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d1c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10d1c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10d1c8: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x10d1c8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d1cc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x10d1ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10d1d0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x10d1d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10d1d4: 0x8043478  j           func_10D1E0
    ctx->pc = 0x10D1D4u;
    ctx->pc = 0x10D1D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D1D4u;
            // 0x10d1d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D1E0u;
    if (runtime->hasFunction(0x10D1E0u)) {
        auto targetFn = runtime->lookupFunction(0x10D1E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010D1E0_0x10d1e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10D1DCu;
    // 0x10d1dc: 0x0  nop
    ctx->pc = 0x10d1dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
