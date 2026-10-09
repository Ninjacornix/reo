#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD6A0
// Address: 0x1cd6a0 - 0x1cd710
void sub_001CD6A0_0x1cd6a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD6A0_0x1cd6a0");
#endif

    switch (ctx->pc) {
        case 0x1cd6dcu: goto label_1cd6dc;
        case 0x1cd6f4u: goto label_1cd6f4;
        default: break;
    }

    ctx->pc = 0x1cd6a0u;

    // 0x1cd6a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cd6a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cd6a4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1cd6a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1cd6a8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cd6a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cd6ac: 0x51880  sll         $v1, $a1, 2
    ctx->pc = 0x1cd6acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1cd6b0: 0x244266d0  addiu       $v0, $v0, 0x66D0
    ctx->pc = 0x1cd6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26320));
    // 0x1cd6b4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cd6b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cd6b8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cd6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cd6bc: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1cd6bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd6c0: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1cd6c0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd6c4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1cd6c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd6c8: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd6c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd6cc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd6ccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd6d0: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd6d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd6d4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD6D4u;
    SET_GPR_U32(ctx, 31, 0x1CD6DCu);
    ctx->pc = 0x1CD6D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD6D4u;
            // 0x1cd6d8: 0x24a56020  addiu       $a1, $a1, 0x6020 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24608));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD6DCu; }
        if (ctx->pc != 0x1CD6DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD6DCu; }
        if (ctx->pc != 0x1CD6DCu) { return; }
    }
    ctx->pc = 0x1CD6DCu;
label_1cd6dc:
    // 0x1cd6dc: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CD6DCu;
    {
        const bool branch_taken_0x1cd6dc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD6E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD6DCu;
            // 0x1cd6e0: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd6dc) {
            ctx->pc = 0x1CD6F4u;
            goto label_1cd6f4;
        }
    }
    ctx->pc = 0x1CD6E4u;
    // 0x1cd6e4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd6e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd6e8: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd6e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd6ec: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CD6ECu;
    SET_GPR_U32(ctx, 31, 0x1CD6F4u);
    ctx->pc = 0x1CD6F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD6ECu;
            // 0x1cd6f0: 0x24a55fa0  addiu       $a1, $a1, 0x5FA0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD6F4u; }
        if (ctx->pc != 0x1CD6F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD6F4u; }
        if (ctx->pc != 0x1CD6F4u) { return; }
    }
    ctx->pc = 0x1CD6F4u;
label_1cd6f4:
    // 0x1cd6f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cd6f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cd6f8: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cd6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cd6fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cd6fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd700: 0x24420af0  addiu       $v0, $v0, 0xAF0
    ctx->pc = 0x1cd700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2800));
    // 0x1cd704: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD704u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD704u;
            // 0x1cd708: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD6DCu: goto label_1cd6dc;
            case 0x1CD6F4u: goto label_1cd6f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD70Cu;
    // 0x1cd70c: 0x0  nop
    ctx->pc = 0x1cd70cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
