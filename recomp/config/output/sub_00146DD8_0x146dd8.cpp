#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00146DD8
// Address: 0x146dd8 - 0x146ee8
void sub_00146DD8_0x146dd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00146DD8_0x146dd8");
#endif

    switch (ctx->pc) {
        case 0x146e04u: goto label_146e04;
        case 0x146e84u: goto label_146e84;
        case 0x146eacu: goto label_146eac;
        case 0x146ebcu: goto label_146ebc;
        default: break;
    }

    ctx->pc = 0x146dd8u;

    // 0x146dd8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x146dd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x146ddc: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x146ddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x146de0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x146de0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x146de4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x146de4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146de8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x146de8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x146dec: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x146decu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146df0: 0x8e070870  lw          $a3, 0x870($s0)
    ctx->pc = 0x146df0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x146df4: 0x24e80020  addiu       $t0, $a3, 0x20
    ctx->pc = 0x146df4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 32));
    // 0x146df8: 0x24e60010  addiu       $a2, $a3, 0x10
    ctx->pc = 0x146df8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x146dfc: 0xc051b18  jal         func_146C60
    ctx->pc = 0x146DFCu;
    SET_GPR_U32(ctx, 31, 0x146E04u);
    ctx->pc = 0x146E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146DFCu;
            // 0x146e00: 0x24e70018  addiu       $a3, $a3, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146C60u;
    if (runtime->hasFunction(0x146C60u)) {
        auto targetFn = runtime->lookupFunction(0x146C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146E04u; }
        if (ctx->pc != 0x146E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146C60_0x146c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146E04u; }
        if (ctx->pc != 0x146E04u) { return; }
    }
    ctx->pc = 0x146E04u;
label_146e04:
    // 0x146e04: 0x8e070870  lw          $a3, 0x870($s0)
    ctx->pc = 0x146e04u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x146e08: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x146e08u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x146e0c: 0x24c6a720  addiu       $a2, $a2, -0x58E0
    ctx->pc = 0x146e0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294944544));
    // 0x146e10: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146e10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146e14: 0xdce20020  ld          $v0, 0x20($a3)
    ctx->pc = 0x146e14u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x146e18: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x146e18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146e1c: 0x8ce30010  lw          $v1, 0x10($a3)
    ctx->pc = 0x146e1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x146e20: 0x216f8  dsll        $v0, $v0, 27
    ctx->pc = 0x146e20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 27);
    // 0x146e24: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x146e24u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x146e28: 0xae030098  sw          $v1, 0x98($s0)
    ctx->pc = 0x146e28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 152), GPR_U32(ctx, 3));
    // 0x146e2c: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x146e2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x146e30: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x146e30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x146e34: 0x8e23005c  lw          $v1, 0x5C($s1)
    ctx->pc = 0x146e34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 92)));
    // 0x146e38: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x146e38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x146e3c: 0x9c460000  lwu         $a2, 0x0($v0)
    ctx->pc = 0x146e3cu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x146e40: 0xae0300e4  sw          $v1, 0xE4($s0)
    ctx->pc = 0x146e40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 228), GPR_U32(ctx, 3));
    // 0x146e44: 0xfe0600a0  sd          $a2, 0xA0($s0)
    ctx->pc = 0x146e44u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 160), GPR_U64(ctx, 6));
    // 0x146e48: 0x8e220060  lw          $v0, 0x60($s1)
    ctx->pc = 0x146e48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x146e4c: 0xae0200e8  sw          $v0, 0xE8($s0)
    ctx->pc = 0x146e4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 232), GPR_U32(ctx, 2));
    // 0x146e50: 0x8e230044  lw          $v1, 0x44($s1)
    ctx->pc = 0x146e50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x146e54: 0xae0300cc  sw          $v1, 0xCC($s0)
    ctx->pc = 0x146e54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 204), GPR_U32(ctx, 3));
    // 0x146e58: 0x8e220048  lw          $v0, 0x48($s1)
    ctx->pc = 0x146e58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x146e5c: 0xae0200d0  sw          $v0, 0xD0($s0)
    ctx->pc = 0x146e5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 208), GPR_U32(ctx, 2));
    // 0x146e60: 0x8e23004c  lw          $v1, 0x4C($s1)
    ctx->pc = 0x146e60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 76)));
    // 0x146e64: 0xae0300d4  sw          $v1, 0xD4($s0)
    ctx->pc = 0x146e64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 212), GPR_U32(ctx, 3));
    // 0x146e68: 0x8e220050  lw          $v0, 0x50($s1)
    ctx->pc = 0x146e68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 80)));
    // 0x146e6c: 0xae0200d8  sw          $v0, 0xD8($s0)
    ctx->pc = 0x146e6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 216), GPR_U32(ctx, 2));
    // 0x146e70: 0x8e230054  lw          $v1, 0x54($s1)
    ctx->pc = 0x146e70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x146e74: 0xae0300dc  sw          $v1, 0xDC($s0)
    ctx->pc = 0x146e74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 220), GPR_U32(ctx, 3));
    // 0x146e78: 0x8e220058  lw          $v0, 0x58($s1)
    ctx->pc = 0x146e78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x146e7c: 0xc051a42  jal         func_146908
    ctx->pc = 0x146E7Cu;
    SET_GPR_U32(ctx, 31, 0x146E84u);
    ctx->pc = 0x146E80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146E7Cu;
            // 0x146e80: 0xae0200e0  sw          $v0, 0xE0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146908u;
    if (runtime->hasFunction(0x146908u)) {
        auto targetFn = runtime->lookupFunction(0x146908u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146E84u; }
        if (ctx->pc != 0x146E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146908_0x146908(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146E84u; }
        if (ctx->pc != 0x146E84u) { return; }
    }
    ctx->pc = 0x146E84u;
label_146e84:
    // 0x146e84: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x146E84u;
    {
        const bool branch_taken_0x146e84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x146E88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146E84u;
            // 0x146e88: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146e84) {
            ctx->pc = 0x146ED4u;
            goto label_146ed4;
        }
    }
    ctx->pc = 0x146E8Cu;
    // 0x146e8c: 0x8e230028  lw          $v1, 0x28($s1)
    ctx->pc = 0x146e8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x146e90: 0x14620011  bne         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x146E90u;
    {
        const bool branch_taken_0x146e90 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x146E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146E90u;
            // 0x146e94: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146e90) {
            ctx->pc = 0x146ED8u;
            goto label_146ed8;
        }
    }
    ctx->pc = 0x146E98u;
    // 0x146e98: 0x8e0200c8  lw          $v0, 0xC8($s0)
    ctx->pc = 0x146e98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 200)));
    // 0x146e9c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x146E9Cu;
    {
        const bool branch_taken_0x146e9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x146EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146E9Cu;
            // 0x146ea0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146e9c) {
            ctx->pc = 0x146EB4u;
            goto label_146eb4;
        }
    }
    ctx->pc = 0x146EA4u;
    // 0x146ea4: 0xc051de8  jal         func_1477A0
    ctx->pc = 0x146EA4u;
    SET_GPR_U32(ctx, 31, 0x146EACu);
    ctx->pc = 0x146EA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146EA4u;
            // 0x146ea8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1477A0u;
    if (runtime->hasFunction(0x1477A0u)) {
        auto targetFn = runtime->lookupFunction(0x1477A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146EACu; }
        if (ctx->pc != 0x146EACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001477A0_0x1477a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146EACu; }
        if (ctx->pc != 0x146EACu) { return; }
    }
    ctx->pc = 0x146EACu;
label_146eac:
    // 0x146eac: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x146EACu;
    {
        const bool branch_taken_0x146eac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146EACu;
            // 0x146eb0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146eac) {
            ctx->pc = 0x146EC0u;
            goto label_146ec0;
        }
    }
    ctx->pc = 0x146EB4u;
label_146eb4:
    // 0x146eb4: 0xc051a6a  jal         func_1469A8
    ctx->pc = 0x146EB4u;
    SET_GPR_U32(ctx, 31, 0x146EBCu);
    ctx->pc = 0x146EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146EB4u;
            // 0x146eb8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1469A8u;
    if (runtime->hasFunction(0x1469A8u)) {
        auto targetFn = runtime->lookupFunction(0x1469A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146EBCu; }
        if (ctx->pc != 0x146EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001469A8_0x1469a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146EBCu; }
        if (ctx->pc != 0x146EBCu) { return; }
    }
    ctx->pc = 0x146EBCu;
label_146ebc:
    // 0x146ebc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146ebcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_146ec0:
    // 0x146ec0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x146ec0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x146ec4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x146ec4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x146ec8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146ec8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146ecc: 0x8051b0e  j           func_146C38
    ctx->pc = 0x146ECCu;
    ctx->pc = 0x146ED0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146ECCu;
            // 0x146ed0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146C38u;
    {
        auto targetFn = runtime->lookupFunction(0x146C38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x146ED4u;
label_146ed4:
    // 0x146ed4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x146ed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_146ed8:
    // 0x146ed8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x146ed8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x146edc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146edcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146ee0: 0x3e00008  jr          $ra
    ctx->pc = 0x146EE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146EE0u;
            // 0x146ee4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146E04u: goto label_146e04;
            case 0x146E84u: goto label_146e84;
            case 0x146EACu: goto label_146eac;
            case 0x146EB4u: goto label_146eb4;
            case 0x146EBCu: goto label_146ebc;
            case 0x146EC0u: goto label_146ec0;
            case 0x146ED4u: goto label_146ed4;
            case 0x146ED8u: goto label_146ed8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146EE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
