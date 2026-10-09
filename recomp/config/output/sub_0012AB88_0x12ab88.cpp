#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012AB88
// Address: 0x12ab88 - 0x12b038
void sub_0012AB88_0x12ab88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012AB88_0x12ab88");
#endif

    switch (ctx->pc) {
        case 0x12abc8u: goto label_12abc8;
        case 0x12abd0u: goto label_12abd0;
        case 0x12ac40u: goto label_12ac40;
        case 0x12ac54u: goto label_12ac54;
        case 0x12ac5cu: goto label_12ac5c;
        case 0x12acf0u: goto label_12acf0;
        case 0x12ad04u: goto label_12ad04;
        case 0x12ad0cu: goto label_12ad0c;
        case 0x12ad1cu: goto label_12ad1c;
        case 0x12ad24u: goto label_12ad24;
        case 0x12ad2cu: goto label_12ad2c;
        case 0x12ad34u: goto label_12ad34;
        case 0x12add0u: goto label_12add0;
        case 0x12adf8u: goto label_12adf8;
        case 0x12ae10u: goto label_12ae10;
        case 0x12aeb0u: goto label_12aeb0;
        case 0x12aec4u: goto label_12aec4;
        case 0x12aee0u: goto label_12aee0;
        case 0x12aef0u: goto label_12aef0;
        case 0x12af04u: goto label_12af04;
        case 0x12af18u: goto label_12af18;
        case 0x12af20u: goto label_12af20;
        case 0x12afb8u: goto label_12afb8;
        case 0x12afccu: goto label_12afcc;
        case 0x12afe8u: goto label_12afe8;
        case 0x12aff8u: goto label_12aff8;
        default: break;
    }

    ctx->pc = 0x12ab88u;

label_12ab88:
    // 0x12ab88: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12ab88u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12ab8c: 0x246304a0  addiu       $v1, $v1, 0x4A0
    ctx->pc = 0x12ab8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1184));
    // 0x12ab90: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x12ab90u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12ab94: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12ab94u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12ab98: 0x3e00008  jr          $ra
    ctx->pc = 0x12AB98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12AB9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AB98u;
            // 0x12ab9c: 0xfc620000  sd          $v0, 0x0($v1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12AB88u: goto label_12ab88;
            case 0x12ABC8u: goto label_12abc8;
            case 0x12ABD0u: goto label_12abd0;
            case 0x12ABDCu: goto label_12abdc;
            case 0x12AC40u: goto label_12ac40;
            case 0x12AC54u: goto label_12ac54;
            case 0x12AC5Cu: goto label_12ac5c;
            case 0x12AC68u: goto label_12ac68;
            case 0x12ACF0u: goto label_12acf0;
            case 0x12AD04u: goto label_12ad04;
            case 0x12AD0Cu: goto label_12ad0c;
            case 0x12AD1Cu: goto label_12ad1c;
            case 0x12AD24u: goto label_12ad24;
            case 0x12AD2Cu: goto label_12ad2c;
            case 0x12AD34u: goto label_12ad34;
            case 0x12AD40u: goto label_12ad40;
            case 0x12ADD0u: goto label_12add0;
            case 0x12ADF0u: goto label_12adf0;
            case 0x12ADF8u: goto label_12adf8;
            case 0x12AE04u: goto label_12ae04;
            case 0x12AE10u: goto label_12ae10;
            case 0x12AE1Cu: goto label_12ae1c;
            case 0x12AEB0u: goto label_12aeb0;
            case 0x12AEC4u: goto label_12aec4;
            case 0x12AEE0u: goto label_12aee0;
            case 0x12AEF0u: goto label_12aef0;
            case 0x12AF04u: goto label_12af04;
            case 0x12AF18u: goto label_12af18;
            case 0x12AF20u: goto label_12af20;
            case 0x12AF2Cu: goto label_12af2c;
            case 0x12AFB8u: goto label_12afb8;
            case 0x12AFCCu: goto label_12afcc;
            case 0x12AFE8u: goto label_12afe8;
            case 0x12AFF8u: goto label_12aff8;
            case 0x12B004u: goto label_12b004;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12ABA0u;
    // 0x12aba0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12aba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12aba4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12aba4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12aba8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12aba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12abac: 0x244204f8  addiu       $v0, $v0, 0x4F8
    ctx->pc = 0x12abacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1272));
    // 0x12abb0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12abb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12abb4: 0xdc430000  ld          $v1, 0x0($v0)
    ctx->pc = 0x12abb4u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12abb8: 0x54600008  bnel        $v1, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x12ABB8u;
    {
        const bool branch_taken_0x12abb8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12abb8) {
            ctx->pc = 0x12ABBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12ABB8u;
            // 0x12abbc: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12ABDCu;
            goto label_12abdc;
        }
    }
    ctx->pc = 0x12ABC0u;
    // 0x12abc0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12abc0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12abc4: 0x0  nop
    ctx->pc = 0x12abc4u;
    // NOP
label_12abc8:
    // 0x12abc8: 0xc04aae2  jal         func_12AB88
    ctx->pc = 0x12ABC8u;
    SET_GPR_U32(ctx, 31, 0x12ABD0u);
    ctx->pc = 0x12AB88u;
    goto label_12ab88;
    ctx->pc = 0x12ABD0u;
label_12abd0:
    // 0x12abd0: 0xde020000  ld          $v0, 0x0($s0)
    ctx->pc = 0x12abd0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12abd4: 0x1040fffc  beqz        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x12ABD4u;
    {
        const bool branch_taken_0x12abd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12ABD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12ABD4u;
            // 0x12abd8: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12abd4) {
            ctx->pc = 0x12ABC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12abc8;
        }
    }
    ctx->pc = 0x12ABDCu;
label_12abdc:
    // 0x12abdc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12abdcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12abe0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12abe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12abe4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12abe4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12abe8: 0x24420500  addiu       $v0, $v0, 0x500
    ctx->pc = 0x12abe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1280));
    // 0x12abec: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12abecu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12abf0: 0x8045118  j           func_114460
    ctx->pc = 0x12ABF0u;
    ctx->pc = 0x12ABF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12ABF0u;
            // 0x12abf4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12ABF8u;
    // 0x12abf8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12abf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12abfc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12abfcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ac00: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ac00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ac04: 0x24440508  addiu       $a0, $v0, 0x508
    ctx->pc = 0x12ac04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 1288));
    // 0x12ac08: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ac08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ac0c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12ac0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12ac10: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12ac10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12ac14: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x12ac14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x12ac18: 0xdc830000  ld          $v1, 0x0($a0)
    ctx->pc = 0x12ac18u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12ac1c: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x12AC1Cu;
    {
        const bool branch_taken_0x12ac1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12AC20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC1Cu;
            // 0x12ac20: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ac1c) {
            ctx->pc = 0x12AC68u;
            goto label_12ac68;
        }
    }
    ctx->pc = 0x12AC24u;
    // 0x12ac24: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ac24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ac28: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12ac28u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12ac2c: 0x245104a8  addiu       $s1, $v0, 0x4A8
    ctx->pc = 0x12ac2cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 1192));
    // 0x12ac30: 0x2470048c  addiu       $s0, $v1, 0x48C
    ctx->pc = 0x12ac30u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 1164));
    // 0x12ac34: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x12ac34u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ac38: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x12ac38u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ac3c: 0x0  nop
    ctx->pc = 0x12ac3cu;
    // NOP
label_12ac40:
    // 0x12ac40: 0xde220000  ld          $v0, 0x0($s1)
    ctx->pc = 0x12ac40u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12ac44: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12ac44u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12ac48: 0xfe220000  sd          $v0, 0x0($s1)
    ctx->pc = 0x12ac48u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 2));
    // 0x12ac4c: 0xc0507ea  jal         func_141FA8
    ctx->pc = 0x12AC4Cu;
    SET_GPR_U32(ctx, 31, 0x12AC54u);
    ctx->pc = 0x12AC50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC4Cu;
            // 0x12ac50: 0xae120000  sw          $s2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141FA8u;
    if (runtime->hasFunction(0x141FA8u)) {
        auto targetFn = runtime->lookupFunction(0x141FA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AC54u; }
        if (ctx->pc != 0x12AC54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141FA8_0x141fa8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AC54u; }
        if (ctx->pc != 0x12AC54u) { return; }
    }
    ctx->pc = 0x12AC54u;
label_12ac54:
    // 0x12ac54: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AC54u;
    SET_GPR_U32(ctx, 31, 0x12AC5Cu);
    ctx->pc = 0x12AC58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC54u;
            // 0x12ac58: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AC5Cu; }
        if (ctx->pc != 0x12AC5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AC5Cu; }
        if (ctx->pc != 0x12AC5Cu) { return; }
    }
    ctx->pc = 0x12AC5Cu;
label_12ac5c:
    // 0x12ac5c: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x12ac5cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12ac60: 0x1040fff7  beqz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x12AC60u;
    {
        const bool branch_taken_0x12ac60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12AC64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC60u;
            // 0x12ac64: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ac60) {
            ctx->pc = 0x12AC40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ac40;
        }
    }
    ctx->pc = 0x12AC68u;
label_12ac68:
    // 0x12ac68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12ac68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ac6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12ac6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ac70: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12ac70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ac74: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12ac74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ac78: 0x24420510  addiu       $v0, $v0, 0x510
    ctx->pc = 0x12ac78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1296));
    // 0x12ac7c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12ac7cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ac80: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x12ac80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ac84: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12ac84u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12ac88: 0x8045118  j           func_114460
    ctx->pc = 0x12AC88u;
    ctx->pc = 0x12AC8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AC88u;
            // 0x12ac8c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12AC90u;
    // 0x12ac90: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12ac90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12ac94: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ac94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ac98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ac98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ac9c: 0x24460518  addiu       $a2, $v0, 0x518
    ctx->pc = 0x12ac9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 1304));
    // 0x12aca0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12aca0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12aca4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12aca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12aca8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12aca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12acac: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12acacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12acb0: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12acb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12acb4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x12acb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x12acb8: 0xdcc30000  ld          $v1, 0x0($a2)
    ctx->pc = 0x12acb8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12acbc: 0x14600020  bnez        $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x12ACBCu;
    {
        const bool branch_taken_0x12acbc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12ACC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12ACBCu;
            // 0x12acc0: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12acbc) {
            ctx->pc = 0x12AD40u;
            goto label_12ad40;
        }
    }
    ctx->pc = 0x12ACC4u;
    // 0x12acc4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12acc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12acc8: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12acc8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12accc: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12acccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12acd0: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x12acd0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x12acd4: 0x245204b0  addiu       $s2, $v0, 0x4B0
    ctx->pc = 0x12acd4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 1200));
    // 0x12acd8: 0x247504ec  addiu       $s5, $v1, 0x4EC
    ctx->pc = 0x12acd8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 3), 1260));
    // 0x12acdc: 0x249404f0  addiu       $s4, $a0, 0x4F0
    ctx->pc = 0x12acdcu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), 1264));
    // 0x12ace0: 0x24b10488  addiu       $s1, $a1, 0x488
    ctx->pc = 0x12ace0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), 1160));
    // 0x12ace4: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x12ace4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ace8: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x12ace8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12acec: 0x0  nop
    ctx->pc = 0x12acecu;
    // NOP
label_12acf0:
    // 0x12acf0: 0xde420000  ld          $v0, 0x0($s2)
    ctx->pc = 0x12acf0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12acf4: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12acf4u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12acf8: 0xfe420000  sd          $v0, 0x0($s2)
    ctx->pc = 0x12acf8u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 2));
    // 0x12acfc: 0xc04ac56  jal         func_12B158
    ctx->pc = 0x12ACFCu;
    SET_GPR_U32(ctx, 31, 0x12AD04u);
    ctx->pc = 0x12AD00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12ACFCu;
            // 0x12ad00: 0x8ea40000  lw          $a0, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B158u;
    if (runtime->hasFunction(0x12B158u)) {
        auto targetFn = runtime->lookupFunction(0x12B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD04u; }
        if (ctx->pc != 0x12AD04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B158_0x12b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD04u; }
        if (ctx->pc != 0x12AD04u) { return; }
    }
    ctx->pc = 0x12AD04u;
label_12ad04:
    // 0x12ad04: 0xc04ad4c  jal         func_12B530
    ctx->pc = 0x12AD04u;
    SET_GPR_U32(ctx, 31, 0x12AD0Cu);
    ctx->pc = 0x12B530u;
    if (runtime->hasFunction(0x12B530u)) {
        auto targetFn = runtime->lookupFunction(0x12B530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD0Cu; }
        if (ctx->pc != 0x12AD0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B530_0x12b530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD0Cu; }
        if (ctx->pc != 0x12AD0Cu) { return; }
    }
    ctx->pc = 0x12AD0Cu;
label_12ad0c:
    // 0x12ad0c: 0x14500003  bne         $v0, $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12AD0Cu;
    {
        const bool branch_taken_0x12ad0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        if (branch_taken_0x12ad0c) {
            ctx->pc = 0x12AD1Cu;
            goto label_12ad1c;
        }
    }
    ctx->pc = 0x12AD14u;
    // 0x12ad14: 0xc04ac56  jal         func_12B158
    ctx->pc = 0x12AD14u;
    SET_GPR_U32(ctx, 31, 0x12AD1Cu);
    ctx->pc = 0x12AD18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AD14u;
            // 0x12ad18: 0x8e840000  lw          $a0, 0x0($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B158u;
    if (runtime->hasFunction(0x12B158u)) {
        auto targetFn = runtime->lookupFunction(0x12B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD1Cu; }
        if (ctx->pc != 0x12AD1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B158_0x12b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD1Cu; }
        if (ctx->pc != 0x12AD1Cu) { return; }
    }
    ctx->pc = 0x12AD1Cu;
label_12ad1c:
    // 0x12ad1c: 0xc04afe6  jal         func_12BF98
    ctx->pc = 0x12AD1Cu;
    SET_GPR_U32(ctx, 31, 0x12AD24u);
    ctx->pc = 0x12BF98u;
    if (runtime->hasFunction(0x12BF98u)) {
        auto targetFn = runtime->lookupFunction(0x12BF98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD24u; }
        if (ctx->pc != 0x12AD24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BF98_0x12bf98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD24u; }
        if (ctx->pc != 0x12AD24u) { return; }
    }
    ctx->pc = 0x12AD24u;
label_12ad24:
    // 0x12ad24: 0xc0507f0  jal         func_141FC0
    ctx->pc = 0x12AD24u;
    SET_GPR_U32(ctx, 31, 0x12AD2Cu);
    ctx->pc = 0x12AD28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AD24u;
            // 0x12ad28: 0xae300000  sw          $s0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141FC0u;
    if (runtime->hasFunction(0x141FC0u)) {
        auto targetFn = runtime->lookupFunction(0x141FC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD2Cu; }
        if (ctx->pc != 0x12AD2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141FC0_0x141fc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD2Cu; }
        if (ctx->pc != 0x12AD2Cu) { return; }
    }
    ctx->pc = 0x12AD2Cu;
label_12ad2c:
    // 0x12ad2c: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AD2Cu;
    SET_GPR_U32(ctx, 31, 0x12AD34u);
    ctx->pc = 0x12AD30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AD2Cu;
            // 0x12ad30: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD34u; }
        if (ctx->pc != 0x12AD34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AD34u; }
        if (ctx->pc != 0x12AD34u) { return; }
    }
    ctx->pc = 0x12AD34u;
label_12ad34:
    // 0x12ad34: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x12ad34u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12ad38: 0x1040ffed  beqz        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x12AD38u;
    {
        const bool branch_taken_0x12ad38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12AD3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AD38u;
            // 0x12ad3c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ad38) {
            ctx->pc = 0x12ACF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12acf0;
        }
    }
    ctx->pc = 0x12AD40u;
label_12ad40:
    // 0x12ad40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12ad40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ad44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12ad44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ad48: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12ad48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ad4c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12ad4cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ad50: 0x24420520  addiu       $v0, $v0, 0x520
    ctx->pc = 0x12ad50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1312));
    // 0x12ad54: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12ad54u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ad58: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12ad58u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ad5c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12ad5cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ad60: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x12ad60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12ad64: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12ad64u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12ad68: 0x8045118  j           func_114460
    ctx->pc = 0x12AD68u;
    ctx->pc = 0x12AD6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AD68u;
            // 0x12ad6c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12AD70u;
    // 0x12ad70: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12ad70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12ad74: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ad74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ad78: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ad78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ad7c: 0x24450528  addiu       $a1, $v0, 0x528
    ctx->pc = 0x12ad7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1320));
    // 0x12ad80: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ad80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ad84: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12ad84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12ad88: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12ad88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12ad8c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12ad8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12ad90: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12ad90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12ad94: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x12ad94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x12ad98: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x12ad98u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12ad9c: 0x1460001f  bnez        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x12AD9Cu;
    {
        const bool branch_taken_0x12ad9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12ADA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AD9Cu;
            // 0x12ada0: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ad9c) {
            ctx->pc = 0x12AE1Cu;
            goto label_12ae1c;
        }
    }
    ctx->pc = 0x12ADA4u;
    // 0x12ada4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ada4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ada8: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12ada8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12adac: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12adacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12adb0: 0x3c111200  lui         $s1, 0x1200
    ctx->pc = 0x12adb0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)4608 << 16));
    // 0x12adb4: 0x245304b8  addiu       $s3, $v0, 0x4B8
    ctx->pc = 0x12adb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 1208));
    // 0x12adb8: 0x24720490  addiu       $s2, $v1, 0x490
    ctx->pc = 0x12adb8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 1168));
    // 0x12adbc: 0x24900564  addiu       $s0, $a0, 0x564
    ctx->pc = 0x12adbcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 1380));
    // 0x12adc0: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x12adc0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12adc4: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x12adc4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12adc8: 0x363100e0  ori         $s1, $s1, 0xE0
    ctx->pc = 0x12adc8u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)224);
    // 0x12adcc: 0x0  nop
    ctx->pc = 0x12adccu;
    // NOP
label_12add0:
    // 0x12add0: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x12add0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12add4: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x12add4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12add8: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12add8u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12addc: 0xfe620000  sd          $v0, 0x0($s3)
    ctx->pc = 0x12addcu;
    WRITE64(ADD32(GPR_U32(ctx, 19), 0), GPR_U64(ctx, 2));
    // 0x12ade0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12ADE0u;
    {
        const bool branch_taken_0x12ade0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12ADE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12ADE0u;
            // 0x12ade4: 0xae540000  sw          $s4, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ade0) {
            ctx->pc = 0x12ADF0u;
            goto label_12adf0;
        }
    }
    ctx->pc = 0x12ADE8u;
    // 0x12ade8: 0x96020000  lhu         $v0, 0x0($s0)
    ctx->pc = 0x12ade8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12adec: 0xfe220000  sd          $v0, 0x0($s1)
    ctx->pc = 0x12adecu;
    WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 2));
label_12adf0:
    // 0x12adf0: 0xc0507fc  jal         func_141FF0
    ctx->pc = 0x12ADF0u;
    SET_GPR_U32(ctx, 31, 0x12ADF8u);
    ctx->pc = 0x141FF0u;
    if (runtime->hasFunction(0x141FF0u)) {
        auto targetFn = runtime->lookupFunction(0x141FF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ADF8u; }
        if (ctx->pc != 0x12ADF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141FF0_0x141ff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ADF8u; }
        if (ctx->pc != 0x12ADF8u) { return; }
    }
    ctx->pc = 0x12ADF8u;
label_12adf8:
    // 0x12adf8: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x12adf8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12adfc: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12ADFCu;
    {
        const bool branch_taken_0x12adfc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12adfc) {
            ctx->pc = 0x12AE00u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12ADFCu;
            // 0x12ae00: 0xfe200000  sd          $zero, 0x0($s1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12AE04u;
            goto label_12ae04;
        }
    }
    ctx->pc = 0x12AE04u;
label_12ae04:
    // 0x12ae04: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x12ae04u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x12ae08: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AE08u;
    SET_GPR_U32(ctx, 31, 0x12AE10u);
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AE10u; }
        if (ctx->pc != 0x12AE10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AE10u; }
        if (ctx->pc != 0x12AE10u) { return; }
    }
    ctx->pc = 0x12AE10u;
label_12ae10:
    // 0x12ae10: 0xdea20000  ld          $v0, 0x0($s5)
    ctx->pc = 0x12ae10u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x12ae14: 0x1040ffee  beqz        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x12AE14u;
    {
        const bool branch_taken_0x12ae14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12AE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AE14u;
            // 0x12ae18: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ae14) {
            ctx->pc = 0x12ADD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12add0;
        }
    }
    ctx->pc = 0x12AE1Cu;
label_12ae1c:
    // 0x12ae1c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12ae1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ae20: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12ae20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ae24: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12ae24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ae28: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12ae28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ae2c: 0x24420530  addiu       $v0, $v0, 0x530
    ctx->pc = 0x12ae2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1328));
    // 0x12ae30: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12ae30u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ae34: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12ae34u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ae38: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12ae38u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ae3c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x12ae3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12ae40: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12ae40u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12ae44: 0x8045118  j           func_114460
    ctx->pc = 0x12AE44u;
    ctx->pc = 0x12AE48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AE44u;
            // 0x12ae48: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12AE4Cu;
    // 0x12ae4c: 0x0  nop
    ctx->pc = 0x12ae4cu;
    // NOP
    // 0x12ae50: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12ae50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12ae54: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ae54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ae58: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ae58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ae5c: 0x24450538  addiu       $a1, $v0, 0x538
    ctx->pc = 0x12ae5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1336));
    // 0x12ae60: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ae60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ae64: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12ae64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12ae68: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12ae68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12ae6c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12ae6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12ae70: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12ae70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12ae74: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x12ae74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x12ae78: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12ae78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12ae7c: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x12ae7cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12ae80: 0x1460002a  bnez        $v1, . + 4 + (0x2A << 2)
    ctx->pc = 0x12AE80u;
    {
        const bool branch_taken_0x12ae80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12AE84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AE80u;
            // 0x12ae84: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ae80) {
            ctx->pc = 0x12AF2Cu;
            goto label_12af2c;
        }
    }
    ctx->pc = 0x12AE88u;
    // 0x12ae88: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ae88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ae8c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12ae8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12ae90: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12ae90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12ae94: 0x245404c0  addiu       $s4, $v0, 0x4C0
    ctx->pc = 0x12ae94u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 1216));
    // 0x12ae98: 0x24730494  addiu       $s3, $v1, 0x494
    ctx->pc = 0x12ae98u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), 1172));
    // 0x12ae9c: 0x24920484  addiu       $s2, $a0, 0x484
    ctx->pc = 0x12ae9cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), 1156));
    // 0x12aea0: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x12aea0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aea4: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12aea4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12aea8: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x12aea8u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x12aeac: 0x0  nop
    ctx->pc = 0x12aeacu;
    // NOP
label_12aeb0:
    // 0x12aeb0: 0xde820000  ld          $v0, 0x0($s4)
    ctx->pc = 0x12aeb0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12aeb4: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12aeb4u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12aeb8: 0xfe820000  sd          $v0, 0x0($s4)
    ctx->pc = 0x12aeb8u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 2));
    // 0x12aebc: 0xc050808  jal         func_142020
    ctx->pc = 0x12AEBCu;
    SET_GPR_U32(ctx, 31, 0x12AEC4u);
    ctx->pc = 0x12AEC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AEBCu;
            // 0x12aec0: 0xae710000  sw          $s1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142020u;
    if (runtime->hasFunction(0x142020u)) {
        auto targetFn = runtime->lookupFunction(0x142020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEC4u; }
        if (ctx->pc != 0x12AEC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142020_0x142020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEC4u; }
        if (ctx->pc != 0x12AEC4u) { return; }
    }
    ctx->pc = 0x12AEC4u;
label_12aec4:
    // 0x12aec4: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x12aec4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x12aec8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12aec8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aecc: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x12aeccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12aed0: 0x14510003  bne         $v0, $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12AED0u;
    {
        const bool branch_taken_0x12aed0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x12aed0) {
            ctx->pc = 0x12AEE0u;
            goto label_12aee0;
        }
    }
    ctx->pc = 0x12AED8u;
    // 0x12aed8: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AED8u;
    SET_GPR_U32(ctx, 31, 0x12AEE0u);
    ctx->pc = 0x12AEDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AED8u;
            // 0x12aedc: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEE0u; }
        if (ctx->pc != 0x12AEE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEE0u; }
        if (ctx->pc != 0x12AEE0u) { return; }
    }
    ctx->pc = 0x12AEE0u;
label_12aee0:
    // 0x12aee0: 0x1600000f  bnez        $s0, . + 4 + (0xF << 2)
    ctx->pc = 0x12AEE0u;
    {
        const bool branch_taken_0x12aee0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x12aee0) {
            ctx->pc = 0x12AF20u;
            goto label_12af20;
        }
    }
    ctx->pc = 0x12AEE8u;
    // 0x12aee8: 0xc04ad4c  jal         func_12B530
    ctx->pc = 0x12AEE8u;
    SET_GPR_U32(ctx, 31, 0x12AEF0u);
    ctx->pc = 0x12B530u;
    if (runtime->hasFunction(0x12B530u)) {
        auto targetFn = runtime->lookupFunction(0x12B530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEF0u; }
        if (ctx->pc != 0x12AEF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B530_0x12b530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEF0u; }
        if (ctx->pc != 0x12AEF0u) { return; }
    }
    ctx->pc = 0x12AEF0u;
label_12aef0:
    // 0x12aef0: 0x14510009  bne         $v0, $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x12AEF0u;
    {
        const bool branch_taken_0x12aef0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x12AEF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AEF0u;
            // 0x12aef4: 0x26b004f0  addiu       $s0, $s5, 0x4F0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 1264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12aef0) {
            ctx->pc = 0x12AF18u;
            goto label_12af18;
        }
    }
    ctx->pc = 0x12AEF8u;
    // 0x12aef8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12aef8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12aefc: 0xc04ac3c  jal         func_12B0F0
    ctx->pc = 0x12AEFCu;
    SET_GPR_U32(ctx, 31, 0x12AF04u);
    ctx->pc = 0x12B0F0u;
    if (runtime->hasFunction(0x12B0F0u)) {
        auto targetFn = runtime->lookupFunction(0x12B0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF04u; }
        if (ctx->pc != 0x12AF04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0F0_0x12b0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF04u; }
        if (ctx->pc != 0x12AF04u) { return; }
    }
    ctx->pc = 0x12AF04u;
label_12af04:
    // 0x12af04: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12af04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12af08: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12AF08u;
    {
        const bool branch_taken_0x12af08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x12af08) {
            ctx->pc = 0x12AF18u;
            goto label_12af18;
        }
    }
    ctx->pc = 0x12AF10u;
    // 0x12af10: 0xc04ac22  jal         func_12B088
    ctx->pc = 0x12AF10u;
    SET_GPR_U32(ctx, 31, 0x12AF18u);
    ctx->pc = 0x12AF14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AF10u;
            // 0x12af14: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B088u;
    if (runtime->hasFunction(0x12B088u)) {
        auto targetFn = runtime->lookupFunction(0x12B088u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF18u; }
        if (ctx->pc != 0x12AF18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B088_0x12b088(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF18u; }
        if (ctx->pc != 0x12AF18u) { return; }
    }
    ctx->pc = 0x12AF18u;
label_12af18:
    // 0x12af18: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AF18u;
    SET_GPR_U32(ctx, 31, 0x12AF20u);
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF20u; }
        if (ctx->pc != 0x12AF20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF20u; }
        if (ctx->pc != 0x12AF20u) { return; }
    }
    ctx->pc = 0x12AF20u;
label_12af20:
    // 0x12af20: 0xdec20000  ld          $v0, 0x0($s6)
    ctx->pc = 0x12af20u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x12af24: 0x1040ffe2  beqz        $v0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x12AF24u;
    {
        const bool branch_taken_0x12af24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12AF28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AF24u;
            // 0x12af28: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12af24) {
            ctx->pc = 0x12AEB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12aeb0;
        }
    }
    ctx->pc = 0x12AF2Cu;
label_12af2c:
    // 0x12af2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12af2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12af30: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12af30u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12af34: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12af34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12af38: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12af38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12af3c: 0x24420540  addiu       $v0, $v0, 0x540
    ctx->pc = 0x12af3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1344));
    // 0x12af40: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12af40u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12af44: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12af44u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12af48: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12af48u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12af4c: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x12af4cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12af50: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12af50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12af54: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12af54u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12af58: 0x8045118  j           func_114460
    ctx->pc = 0x12AF58u;
    ctx->pc = 0x12AF5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AF58u;
            // 0x12af5c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12AF60u;
    // 0x12af60: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12af60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12af64: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12af64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12af68: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12af68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12af6c: 0x24450548  addiu       $a1, $v0, 0x548
    ctx->pc = 0x12af6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1352));
    // 0x12af70: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12af70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12af74: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12af74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12af78: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12af78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12af7c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12af7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12af80: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12af80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12af84: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x12af84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x12af88: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x12af88u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12af8c: 0x1460001d  bnez        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x12AF8Cu;
    {
        const bool branch_taken_0x12af8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12AF90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AF8Cu;
            // 0x12af90: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12af8c) {
            ctx->pc = 0x12B004u;
            goto label_12b004;
        }
    }
    ctx->pc = 0x12AF94u;
    // 0x12af94: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12af94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12af98: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12af98u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12af9c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12af9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12afa0: 0x245404c8  addiu       $s4, $v0, 0x4C8
    ctx->pc = 0x12afa0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 1224));
    // 0x12afa4: 0x24730498  addiu       $s3, $v1, 0x498
    ctx->pc = 0x12afa4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), 1176));
    // 0x12afa8: 0x24920484  addiu       $s2, $a0, 0x484
    ctx->pc = 0x12afa8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), 1156));
    // 0x12afac: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x12afacu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12afb0: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12afb0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12afb4: 0x0  nop
    ctx->pc = 0x12afb4u;
    // NOP
label_12afb8:
    // 0x12afb8: 0xde820000  ld          $v0, 0x0($s4)
    ctx->pc = 0x12afb8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12afbc: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12afbcu;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12afc0: 0xfe820000  sd          $v0, 0x0($s4)
    ctx->pc = 0x12afc0u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 2));
    // 0x12afc4: 0xc05080e  jal         func_142038
    ctx->pc = 0x12AFC4u;
    SET_GPR_U32(ctx, 31, 0x12AFCCu);
    ctx->pc = 0x12AFC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AFC4u;
            // 0x12afc8: 0xae710000  sw          $s1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142038u;
    if (runtime->hasFunction(0x142038u)) {
        auto targetFn = runtime->lookupFunction(0x142038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFCCu; }
        if (ctx->pc != 0x12AFCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142038_0x142038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFCCu; }
        if (ctx->pc != 0x12AFCCu) { return; }
    }
    ctx->pc = 0x12AFCCu;
label_12afcc:
    // 0x12afcc: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x12afccu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x12afd0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12afd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12afd4: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x12afd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12afd8: 0x14510003  bne         $v0, $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12AFD8u;
    {
        const bool branch_taken_0x12afd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x12afd8) {
            ctx->pc = 0x12AFE8u;
            goto label_12afe8;
        }
    }
    ctx->pc = 0x12AFE0u;
    // 0x12afe0: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AFE0u;
    SET_GPR_U32(ctx, 31, 0x12AFE8u);
    ctx->pc = 0x12AFE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AFE0u;
            // 0x12afe4: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFE8u; }
        if (ctx->pc != 0x12AFE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFE8u; }
        if (ctx->pc != 0x12AFE8u) { return; }
    }
    ctx->pc = 0x12AFE8u;
label_12afe8:
    // 0x12afe8: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12AFE8u;
    {
        const bool branch_taken_0x12afe8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x12afe8) {
            ctx->pc = 0x12AFF8u;
            goto label_12aff8;
        }
    }
    ctx->pc = 0x12AFF0u;
    // 0x12aff0: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AFF0u;
    SET_GPR_U32(ctx, 31, 0x12AFF8u);
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFF8u; }
        if (ctx->pc != 0x12AFF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFF8u; }
        if (ctx->pc != 0x12AFF8u) { return; }
    }
    ctx->pc = 0x12AFF8u;
label_12aff8:
    // 0x12aff8: 0xdea20000  ld          $v0, 0x0($s5)
    ctx->pc = 0x12aff8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x12affc: 0x1040ffee  beqz        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x12AFFCu;
    {
        const bool branch_taken_0x12affc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12B000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AFFCu;
            // 0x12b000: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12affc) {
            ctx->pc = 0x12AFB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12afb8;
        }
    }
    ctx->pc = 0x12B004u;
label_12b004:
    // 0x12b004: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12b004u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b008: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12b008u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12b00c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12b00cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12b010: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12b010u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12b014: 0x24420550  addiu       $v0, $v0, 0x550
    ctx->pc = 0x12b014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1360));
    // 0x12b018: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12b018u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12b01c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12b01cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12b020: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12b020u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12b024: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x12b024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b028: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12b028u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12b02c: 0x8045118  j           func_114460
    ctx->pc = 0x12B02Cu;
    ctx->pc = 0x12B030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B02Cu;
            // 0x12b030: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12B034u;
    // 0x12b034: 0x0  nop
    ctx->pc = 0x12b034u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
