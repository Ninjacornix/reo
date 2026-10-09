#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150E08
// Address: 0x150e08 - 0x150ed0
void sub_00150E08_0x150e08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150E08_0x150e08");
#endif

    ctx->pc = 0x150e08u;

    // 0x150e08: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x150e08u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150e0c: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x150e0cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x150e10: 0x8d440050  lw          $a0, 0x50($t2)
    ctx->pc = 0x150e10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 80)));
    // 0x150e14: 0x8d430004  lw          $v1, 0x4($t2)
    ctx->pc = 0x150e14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 4)));
    // 0x150e18: 0x8d420054  lw          $v0, 0x54($t2)
    ctx->pc = 0x150e18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 84)));
    // 0x150e1c: 0x42300  sll         $a0, $a0, 12
    ctx->pc = 0x150e1cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 12));
    // 0x150e20: 0x8d460008  lw          $a2, 0x8($t2)
    ctx->pc = 0x150e20u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 8)));
    // 0x150e24: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x150e24u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x150e28: 0x21300  sll         $v0, $v0, 12
    ctx->pc = 0x150e28u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 12));
    // 0x150e2c: 0x2483000f  addiu       $v1, $a0, 0xF
    ctx->pc = 0x150e2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 15));
    // 0x150e30: 0x463025  or          $a2, $v0, $a2
    ctx->pc = 0x150e30u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x150e34: 0x8d470048  lw          $a3, 0x48($t2)
    ctx->pc = 0x150e34u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 72)));
    // 0x150e38: 0x24c5000f  addiu       $a1, $a2, 0xF
    ctx->pc = 0x150e38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 15));
    // 0x150e3c: 0x31902  srl         $v1, $v1, 4
    ctx->pc = 0x150e3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
    // 0x150e40: 0x52902  srl         $a1, $a1, 4
    ctx->pc = 0x150e40u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 4));
    // 0x150e44: 0xad4302cc  sw          $v1, 0x2CC($t2)
    ctx->pc = 0x150e44u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 716), GPR_U32(ctx, 3));
    // 0x150e48: 0xad4402c4  sw          $a0, 0x2C4($t2)
    ctx->pc = 0x150e48u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 708), GPR_U32(ctx, 4));
    // 0x150e4c: 0x14e80004  bne         $a3, $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x150E4Cu;
    {
        const bool branch_taken_0x150e4c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 8));
        ctx->pc = 0x150E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150E4Cu;
            // 0x150e50: 0xad4602c8  sw          $a2, 0x2C8($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 712), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150e4c) {
            ctx->pc = 0x150E60u;
            goto label_150e60;
        }
    }
    ctx->pc = 0x150E54u;
    // 0x150e54: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x150E54u;
    {
        const bool branch_taken_0x150e54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150E54u;
            // 0x150e58: 0xad4502d0  sw          $a1, 0x2D0($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 720), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150e54) {
            ctx->pc = 0x150E88u;
            goto label_150e88;
        }
    }
    ctx->pc = 0x150E5Cu;
    // 0x150e5c: 0x0  nop
    ctx->pc = 0x150e5cu;
    // NOP
label_150e60:
    // 0x150e60: 0x8d430118  lw          $v1, 0x118($t2)
    ctx->pc = 0x150e60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 280)));
    // 0x150e64: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x150e64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x150e68: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x150E68u;
    {
        const bool branch_taken_0x150e68 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x150E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150E68u;
            // 0x150e6c: 0x24c2001f  addiu       $v0, $a2, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150e68) {
            ctx->pc = 0x150E80u;
            goto label_150e80;
        }
    }
    ctx->pc = 0x150E70u;
    // 0x150e70: 0x21142  srl         $v0, $v0, 5
    ctx->pc = 0x150e70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 5));
    // 0x150e74: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x150E74u;
    {
        const bool branch_taken_0x150e74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150E74u;
            // 0x150e78: 0x21040  sll         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150e74) {
            ctx->pc = 0x150E84u;
            goto label_150e84;
        }
    }
    ctx->pc = 0x150E7Cu;
    // 0x150e7c: 0x0  nop
    ctx->pc = 0x150e7cu;
    // NOP
label_150e80:
    // 0x150e80: 0x21142  srl         $v0, $v0, 5
    ctx->pc = 0x150e80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 5));
label_150e84:
    // 0x150e84: 0xad4202d0  sw          $v0, 0x2D0($t2)
    ctx->pc = 0x150e84u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 720), GPR_U32(ctx, 2));
label_150e88:
    // 0x150e88: 0x8d4602cc  lw          $a2, 0x2CC($t2)
    ctx->pc = 0x150e88u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 716)));
    // 0x150e8c: 0x8d4702d0  lw          $a3, 0x2D0($t2)
    ctx->pc = 0x150e8cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 720)));
    // 0x150e90: 0x8d43004c  lw          $v1, 0x4C($t2)
    ctx->pc = 0x150e90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 76)));
    // 0x150e94: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x150e94u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x150e98: 0x73900  sll         $a3, $a3, 4
    ctx->pc = 0x150e98u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x150e9c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x150e9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150ea0: 0x38690001  xori        $t1, $v1, 0x1
    ctx->pc = 0x150ea0u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x150ea4: 0x38630003  xori        $v1, $v1, 0x3
    ctx->pc = 0x150ea4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)3);
    // 0x150ea8: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x150ea8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150eac: 0x64043  sra         $t0, $a2, 1
    ctx->pc = 0x150eacu;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 6), 1));
    // 0x150eb0: 0x72043  sra         $a0, $a3, 1
    ctx->pc = 0x150eb0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 7), 1));
    // 0x150eb4: 0x103280b  movn        $a1, $t0, $v1
    ctx->pc = 0x150eb4u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 8));
    // 0x150eb8: 0x89100a  movz        $v0, $a0, $t1
    ctx->pc = 0x150eb8u;
    if (GPR_U64(ctx, 9) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x150ebc: 0xad450418  sw          $a1, 0x418($t2)
    ctx->pc = 0x150ebcu;
    WRITE32(ADD32(GPR_U32(ctx, 10), 1048), GPR_U32(ctx, 5));
    // 0x150ec0: 0xad42041c  sw          $v0, 0x41C($t2)
    ctx->pc = 0x150ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 1052), GPR_U32(ctx, 2));
    // 0x150ec4: 0xad460410  sw          $a2, 0x410($t2)
    ctx->pc = 0x150ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 1040), GPR_U32(ctx, 6));
    // 0x150ec8: 0x3e00008  jr          $ra
    ctx->pc = 0x150EC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150EC8u;
            // 0x150ecc: 0xad470414  sw          $a3, 0x414($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 1044), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150E60u: goto label_150e60;
            case 0x150E80u: goto label_150e80;
            case 0x150E84u: goto label_150e84;
            case 0x150E88u: goto label_150e88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150ED0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
