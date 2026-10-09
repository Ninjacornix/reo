#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018CEF0
// Address: 0x18cef0 - 0x18cfb0
void sub_0018CEF0_0x18cef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018CEF0_0x18cef0");
#endif

    switch (ctx->pc) {
        case 0x18cf40u: goto label_18cf40;
        default: break;
    }

    ctx->pc = 0x18cef0u;

    // 0x18cef0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x18cef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x18cef4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18cef4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18cef8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x18cef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x18cefc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x18cefcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18cf00: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18cf00u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18cf04: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x18cf04u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cf08: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18cf08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18cf0c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x18cf0cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cf10: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18cf10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18cf14: 0x8c23fdb4  lw          $v1, -0x24C($at)
    ctx->pc = 0x18cf14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
    // 0x18cf18: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x18cf18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x18cf1c: 0x38080  sll         $s0, $v1, 2
    ctx->pc = 0x18cf1cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18cf20: 0x2052021  addu        $a0, $s0, $a1
    ctx->pc = 0x18cf20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x18cf24: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18cf24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18cf28: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x18cf28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x18cf2c: 0x43082b  sltu        $at, $v0, $v1
    ctx->pc = 0x18cf2cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x18cf30: 0x14200016  bnez        $at, . + 4 + (0x16 << 2)
    ctx->pc = 0x18CF30u;
    {
        const bool branch_taken_0x18cf30 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x18CF34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CF30u;
            // 0x18cf34: 0x24910014  addiu       $s1, $a0, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18cf30) {
            ctx->pc = 0x18CF8Cu;
            goto label_18cf8c;
        }
    }
    ctx->pc = 0x18CF38u;
    // 0x18cf38: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x18CF38u;
    SET_GPR_U32(ctx, 31, 0x18CF40u);
    ctx->pc = 0x18CF3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18CF38u;
            // 0x18cf3c: 0x8c84000c  lw          $a0, 0xC($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CF40u; }
        if (ctx->pc != 0x18CF40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CF40u; }
        if (ctx->pc != 0x18CF40u) { return; }
    }
    ctx->pc = 0x18CF40u;
label_18cf40:
    // 0x18cf40: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x18cf40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18cf44: 0x2122821  addu        $a1, $s0, $s2
    ctx->pc = 0x18cf44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x18cf48: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x18cf48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18cf4c: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x18cf4cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x18cf50: 0x8ca3001c  lw          $v1, 0x1C($a1)
    ctx->pc = 0x18cf50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x18cf54: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x18cf54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18cf58: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18cf58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18cf5c: 0xaca4001c  sw          $a0, 0x1C($a1)
    ctx->pc = 0x18cf5cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 4));
    // 0x18cf60: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18cf60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18cf64: 0xac530000  sw          $s3, 0x0($v0)
    ctx->pc = 0x18cf64u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 19));
    // 0x18cf68: 0x8ca3001c  lw          $v1, 0x1C($a1)
    ctx->pc = 0x18cf68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x18cf6c: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x18cf6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x18cf70: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x18CF70u;
    {
        const bool branch_taken_0x18cf70 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18CF74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CF70u;
            // 0x18cf74: 0x24a6001c  addiu       $a2, $a1, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18cf70) {
            ctx->pc = 0x18CF7Cu;
            goto label_18cf7c;
        }
    }
    ctx->pc = 0x18CF78u;
    // 0x18cf78: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18cf78u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
label_18cf7c:
    // 0x18cf7c: 0xae400034  sw          $zero, 0x34($s2)
    ctx->pc = 0x18cf7cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 0));
    // 0x18cf80: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18cf80u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cf84: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18CF84u;
    {
        const bool branch_taken_0x18cf84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18CF88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CF84u;
            // 0x18cf88: 0xae400038  sw          $zero, 0x38($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18cf84) {
            ctx->pc = 0x18CF90u;
            goto label_18cf90;
        }
    }
    ctx->pc = 0x18CF8Cu;
label_18cf8c:
    // 0x18cf8c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x18cf8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_18cf90:
    // 0x18cf90: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x18cf90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18cf94: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x18cf94u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18cf98: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18cf98u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18cf9c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18cf9cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18cfa0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18cfa0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18cfa4: 0x3e00008  jr          $ra
    ctx->pc = 0x18CFA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18CFA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CFA4u;
            // 0x18cfa8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CF40u: goto label_18cf40;
            case 0x18CF7Cu: goto label_18cf7c;
            case 0x18CF8Cu: goto label_18cf8c;
            case 0x18CF90u: goto label_18cf90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18CFACu;
    // 0x18cfac: 0x0  nop
    ctx->pc = 0x18cfacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
