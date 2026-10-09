#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019CA50
// Address: 0x19ca50 - 0x19cb28
void sub_0019CA50_0x19ca50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019CA50_0x19ca50");
#endif

    switch (ctx->pc) {
        case 0x19ca70u: goto label_19ca70;
        case 0x19cab4u: goto label_19cab4;
        case 0x19caccu: goto label_19cacc;
        case 0x19cad8u: goto label_19cad8;
        case 0x19cb00u: goto label_19cb00;
        case 0x19cb0cu: goto label_19cb0c;
        default: break;
    }

    ctx->pc = 0x19ca50u;

    // 0x19ca50: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x19ca50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x19ca54: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19ca54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19ca58: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19ca58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19ca5c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19ca5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19ca60: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19ca60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19ca64: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x19ca64u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ca68: 0xc067448  jal         func_19D120
    ctx->pc = 0x19CA68u;
    SET_GPR_U32(ctx, 31, 0x19CA70u);
    ctx->pc = 0x19CA6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19CA68u;
            // 0x19ca6c: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19D120u;
    if (runtime->hasFunction(0x19D120u)) {
        auto targetFn = runtime->lookupFunction(0x19D120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CA70u; }
        if (ctx->pc != 0x19CA70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D120_0x19d120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CA70u; }
        if (ctx->pc != 0x19CA70u) { return; }
    }
    ctx->pc = 0x19CA70u;
label_19ca70:
    // 0x19ca70: 0xafa2004c  sw          $v0, 0x4C($sp)
    ctx->pc = 0x19ca70u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
    // 0x19ca74: 0x8fa6004c  lw          $a2, 0x4C($sp)
    ctx->pc = 0x19ca74u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x19ca78: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x19CA78u;
    {
        const bool branch_taken_0x19ca78 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x19CA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19CA78u;
            // 0x19ca7c: 0x30c3ffff  andi        $v1, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ca78) {
            ctx->pc = 0x19CA88u;
            goto label_19ca88;
        }
    }
    ctx->pc = 0x19CA80u;
    // 0x19ca80: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x19CA80u;
    {
        const bool branch_taken_0x19ca80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19CA84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19CA80u;
            // 0x19ca84: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ca80) {
            ctx->pc = 0x19CB10u;
            goto label_19cb10;
        }
    }
    ctx->pc = 0x19CA88u;
label_19ca88:
    // 0x19ca88: 0x3c02002a  lui         $v0, 0x2A
    ctx->pc = 0x19ca88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)42 << 16));
    // 0x19ca8c: 0x2467ffff  addiu       $a3, $v1, -0x1
    ctx->pc = 0x19ca8cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x19ca90: 0x24428680  addiu       $v0, $v0, -0x7980
    ctx->pc = 0x19ca90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936192));
    // 0x19ca94: 0x718c0  sll         $v1, $a3, 3
    ctx->pc = 0x19ca94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x19ca98: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x19ca98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ca9c: 0x671823  subu        $v1, $v1, $a3
    ctx->pc = 0x19ca9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x19caa0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x19caa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19caa4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x19caa4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x19caa8: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x19caa8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19caac: 0xc0672cc  jal         func_19CB30
    ctx->pc = 0x19CAACu;
    SET_GPR_U32(ctx, 31, 0x19CAB4u);
    ctx->pc = 0x19CAB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19CAACu;
            // 0x19cab0: 0x439021  addu        $s2, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19CB30u;
    if (runtime->hasFunction(0x19CB30u)) {
        auto targetFn = runtime->lookupFunction(0x19CB30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CAB4u; }
        if (ctx->pc != 0x19CAB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019CB30_0x19cb30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CAB4u; }
        if (ctx->pc != 0x19CAB4u) { return; }
    }
    ctx->pc = 0x19CAB4u;
label_19cab4:
    // 0x19cab4: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x19cab4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x19cab8: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x19CAB8u;
    {
        const bool branch_taken_0x19cab8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19CABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19CAB8u;
            // 0x19cabc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19cab8) {
            ctx->pc = 0x19CAF4u;
            goto label_19caf4;
        }
    }
    ctx->pc = 0x19CAC0u;
    // 0x19cac0: 0x27a4004c  addiu       $a0, $sp, 0x4C
    ctx->pc = 0x19cac0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
    // 0x19cac4: 0xc067bc0  jal         func_19EF00
    ctx->pc = 0x19CAC4u;
    SET_GPR_U32(ctx, 31, 0x19CACCu);
    ctx->pc = 0x19CAC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19CAC4u;
            // 0x19cac8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EF00u;
    if (runtime->hasFunction(0x19EF00u)) {
        auto targetFn = runtime->lookupFunction(0x19EF00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CACCu; }
        if (ctx->pc != 0x19CACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EF00_0x19ef00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CACCu; }
        if (ctx->pc != 0x19CACCu) { return; }
    }
    ctx->pc = 0x19CACCu;
label_19cacc:
    // 0x19cacc: 0x8e440008  lw          $a0, 0x8($s2)
    ctx->pc = 0x19caccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x19cad0: 0xc063714  jal         func_18DC50
    ctx->pc = 0x19CAD0u;
    SET_GPR_U32(ctx, 31, 0x19CAD8u);
    ctx->pc = 0x19CAD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19CAD0u;
            // 0x19cad4: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC50u;
    if (runtime->hasFunction(0x18DC50u)) {
        auto targetFn = runtime->lookupFunction(0x18DC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CAD8u; }
        if (ctx->pc != 0x19CAD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CAD8u; }
        if (ctx->pc != 0x19CAD8u) { return; }
    }
    ctx->pc = 0x19CAD8u;
label_19cad8:
    // 0x19cad8: 0xae420024  sw          $v0, 0x24($s2)
    ctx->pc = 0x19cad8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 2));
    // 0x19cadc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19cadcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19cae0: 0x8c22fee0  lw          $v0, -0x120($at)
    ctx->pc = 0x19cae0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967008)));
    // 0x19cae4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x19cae4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x19cae8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19cae8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19caec: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x19CAECu;
    {
        const bool branch_taken_0x19caec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19CAF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19CAECu;
            // 0x19caf0: 0xac22fee0  sw          $v0, -0x120($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294967008), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19caec) {
            ctx->pc = 0x19CB0Cu;
            goto label_19cb0c;
        }
    }
    ctx->pc = 0x19CAF4u;
label_19caf4:
    // 0x19caf4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x19caf4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19caf8: 0xc06774c  jal         func_19DD30
    ctx->pc = 0x19CAF8u;
    SET_GPR_U32(ctx, 31, 0x19CB00u);
    ctx->pc = 0x19CAFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19CAF8u;
            // 0x19cafc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19DD30u;
    if (runtime->hasFunction(0x19DD30u)) {
        auto targetFn = runtime->lookupFunction(0x19DD30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CB00u; }
        if (ctx->pc != 0x19CB00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019DD30_0x19dd30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CB00u; }
        if (ctx->pc != 0x19CB00u) { return; }
    }
    ctx->pc = 0x19CB00u;
label_19cb00:
    // 0x19cb00: 0x8fa4004c  lw          $a0, 0x4C($sp)
    ctx->pc = 0x19cb00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x19cb04: 0xc067350  jal         func_19CD40
    ctx->pc = 0x19CB04u;
    SET_GPR_U32(ctx, 31, 0x19CB0Cu);
    ctx->pc = 0x19CB08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19CB04u;
            // 0x19cb08: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19CD40u;
    if (runtime->hasFunction(0x19CD40u)) {
        auto targetFn = runtime->lookupFunction(0x19CD40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CB0Cu; }
        if (ctx->pc != 0x19CB0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019CD40_0x19cd40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CB0Cu; }
        if (ctx->pc != 0x19CB0Cu) { return; }
    }
    ctx->pc = 0x19CB0Cu;
label_19cb0c:
    // 0x19cb0c: 0x8fa2004c  lw          $v0, 0x4C($sp)
    ctx->pc = 0x19cb0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
label_19cb10:
    // 0x19cb10: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19cb10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19cb14: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19cb14u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19cb18: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19cb18u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19cb1c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19cb1cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19cb20: 0x3e00008  jr          $ra
    ctx->pc = 0x19CB20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19CB24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19CB20u;
            // 0x19cb24: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19CA70u: goto label_19ca70;
            case 0x19CA88u: goto label_19ca88;
            case 0x19CAB4u: goto label_19cab4;
            case 0x19CACCu: goto label_19cacc;
            case 0x19CAD8u: goto label_19cad8;
            case 0x19CAF4u: goto label_19caf4;
            case 0x19CB00u: goto label_19cb00;
            case 0x19CB0Cu: goto label_19cb0c;
            case 0x19CB10u: goto label_19cb10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19CB28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
