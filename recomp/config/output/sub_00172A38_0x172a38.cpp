#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172A38
// Address: 0x172a38 - 0x172ac8
void sub_00172A38_0x172a38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172A38_0x172a38");
#endif

    switch (ctx->pc) {
        case 0x172aa8u: goto label_172aa8;
        default: break;
    }

    ctx->pc = 0x172a38u;

    // 0x172a38: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172a38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x172a3c: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x172a3cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172a40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172a40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172a44: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x172a44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172a48: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x172a48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x172a4c: 0x260509a0  addiu       $a1, $s0, 0x9A0
    ctx->pc = 0x172a4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 2464));
    // 0x172a50: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x172a50u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x172a54: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x172a54u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x172a58: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x172a58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x172a5c: 0x8ca30014  lw          $v1, 0x14($a1)
    ctx->pc = 0x172a5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x172a60: 0x481026  xor         $v0, $v0, $t0
    ctx->pc = 0x172a60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 8));
    // 0x172a64: 0x2c450001  sltiu       $a1, $v0, 0x1
    ctx->pc = 0x172a64u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x172a68: 0x681826  xor         $v1, $v1, $t0
    ctx->pc = 0x172a68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 8));
    // 0x172a6c: 0x34a20002  ori         $v0, $a1, 0x2
    ctx->pc = 0x172a6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)2);
    // 0x172a70: 0x43280a  movz        $a1, $v0, $v1
    ctx->pc = 0x172a70u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
    // 0x172a74: 0x10a6000d  beq         $a1, $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x172A74u;
    {
        const bool branch_taken_0x172a74 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x172A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172A74u;
            // 0x172a78: 0x2ca20003  sltiu       $v0, $a1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x172a74) {
            ctx->pc = 0x172AACu;
            goto label_172aac;
        }
    }
    ctx->pc = 0x172A7Cu;
    // 0x172a7c: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x172A7Cu;
    {
        const bool branch_taken_0x172a7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x172a7c) {
            ctx->pc = 0x172A80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172A7Cu;
            // 0x172a80: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172A98u;
            goto label_172a98;
        }
    }
    ctx->pc = 0x172A84u;
    // 0x172a84: 0x10a80009  beq         $a1, $t0, . + 4 + (0x9 << 2)
    ctx->pc = 0x172A84u;
    {
        const bool branch_taken_0x172a84 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 8));
        ctx->pc = 0x172A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172A84u;
            // 0x172a88: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172a84) {
            ctx->pc = 0x172AACu;
            goto label_172aac;
        }
    }
    ctx->pc = 0x172A8Cu;
    // 0x172a8c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x172A8Cu;
    {
        const bool branch_taken_0x172a8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172A8Cu;
            // 0x172a90: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172a8c) {
            ctx->pc = 0x172AACu;
            goto label_172aac;
        }
    }
    ctx->pc = 0x172A94u;
    // 0x172a94: 0x0  nop
    ctx->pc = 0x172a94u;
    // NOP
label_172a98:
    // 0x172a98: 0x14a20004  bne         $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x172A98u;
    {
        const bool branch_taken_0x172a98 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x172A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172A98u;
            // 0x172a9c: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172a98) {
            ctx->pc = 0x172AACu;
            goto label_172aac;
        }
    }
    ctx->pc = 0x172AA0u;
    // 0x172aa0: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172AA0u;
    SET_GPR_U32(ctx, 31, 0x172AA8u);
    ctx->pc = 0x172AA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172AA0u;
            // 0x172aa4: 0x24050019  addiu       $a1, $zero, 0x19 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172AA8u; }
        if (ctx->pc != 0x172AA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172AA8u; }
        if (ctx->pc != 0x172AA8u) { return; }
    }
    ctx->pc = 0x172AA8u;
label_172aa8:
    // 0x172aa8: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x172aa8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_172aac:
    // 0x172aac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172aacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172ab0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172ab0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172ab4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x172ab4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172ab8: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x172ab8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172abc: 0x24050019  addiu       $a1, $zero, 0x19
    ctx->pc = 0x172abcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x172ac0: 0x805d518  j           func_175460
    ctx->pc = 0x172AC0u;
    ctx->pc = 0x172AC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172AC0u;
            // 0x172ac4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175460_0x175460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x172AC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
