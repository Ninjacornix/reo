#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130E98
// Address: 0x130e98 - 0x130ef0
void sub_00130E98_0x130e98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130E98_0x130e98");
#endif

    switch (ctx->pc) {
        case 0x130eacu: goto label_130eac;
        default: break;
    }

    ctx->pc = 0x130e98u;

    // 0x130e98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130e9c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130ea0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130ea0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130ea4: 0xc04d7ee  jal         func_135FB8
    ctx->pc = 0x130EA4u;
    SET_GPR_U32(ctx, 31, 0x130EACu);
    ctx->pc = 0x130EA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130EA4u;
            // 0x130ea8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135FB8u;
    if (runtime->hasFunction(0x135FB8u)) {
        auto targetFn = runtime->lookupFunction(0x135FB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130EACu; }
        if (ctx->pc != 0x130EACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135FB8_0x135fb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130EACu; }
        if (ctx->pc != 0x130EACu) { return; }
    }
    ctx->pc = 0x130EACu;
label_130eac:
    // 0x130eac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x130eacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130eb0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130eb4: 0x24a607ff  addiu       $a2, $a1, 0x7FF
    ctx->pc = 0x130eb4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 2047));
    // 0x130eb8: 0x28a40000  slti        $a0, $a1, 0x0
    ctx->pc = 0x130eb8u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x130ebc: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x130ebcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130ec0: 0xc4180b  movn        $v1, $a2, $a0
    ctx->pc = 0x130ec0u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 6));
    // 0x130ec4: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x130ec4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x130ec8: 0x322c0  sll         $a0, $v1, 11
    ctx->pc = 0x130ec8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x130ecc: 0x24660001  addiu       $a2, $v1, 0x1
    ctx->pc = 0x130eccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x130ed0: 0xa42823  subu        $a1, $a1, $a0
    ctx->pc = 0x130ed0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x130ed4: 0x18a00002  blez        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x130ED4u;
    {
        const bool branch_taken_0x130ed4 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x130ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130ED4u;
            // 0x130ed8: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130ed4) {
            ctx->pc = 0x130EE0u;
            goto label_130ee0;
        }
    }
    ctx->pc = 0x130EDCu;
    // 0x130edc: 0xae060000  sw          $a2, 0x0($s0)
    ctx->pc = 0x130edcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 6));
label_130ee0:
    // 0x130ee0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130ee0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130ee4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130ee4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130ee8: 0x3e00008  jr          $ra
    ctx->pc = 0x130EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130EE8u;
            // 0x130eec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130EACu: goto label_130eac;
            case 0x130EE0u: goto label_130ee0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
