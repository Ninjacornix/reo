#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BA38
// Address: 0x12ba38 - 0x12bb08
void sub_0012BA38_0x12ba38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BA38_0x12ba38");
#endif

    switch (ctx->pc) {
        case 0x12ba88u: goto label_12ba88;
        case 0x12ba98u: goto label_12ba98;
        case 0x12baa0u: goto label_12baa0;
        case 0x12baa8u: goto label_12baa8;
        default: break;
    }

    ctx->pc = 0x12ba38u;

    // 0x12ba38: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12ba38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12ba3c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x12ba3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x12ba40: 0x3c160021  lui         $s6, 0x21
    ctx->pc = 0x12ba40u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)33 << 16));
    // 0x12ba44: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ba44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ba48: 0x26c30520  addiu       $v1, $s6, 0x520
    ctx->pc = 0x12ba48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), 1312));
    // 0x12ba4c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ba4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ba50: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12ba50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12ba54: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12ba54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12ba58: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12ba58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12ba5c: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12ba5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12ba60: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12ba60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12ba64: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x12ba64u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12ba68: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x12BA68u;
    {
        const bool branch_taken_0x12ba68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12BA6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BA68u;
            // 0x12ba6c: 0x3c150021  lui         $s5, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ba68) {
            ctx->pc = 0x12BAC0u;
            goto label_12bac0;
        }
    }
    ctx->pc = 0x12BA70u;
    // 0x12ba70: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12ba70u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12ba74: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x12ba74u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ba78: 0x26b20518  addiu       $s2, $s5, 0x518
    ctx->pc = 0x12ba78u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), 1304));
    // 0x12ba7c: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12ba7cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ba80: 0x269004e0  addiu       $s0, $s4, 0x4E0
    ctx->pc = 0x12ba80u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 1248));
    // 0x12ba84: 0x0  nop
    ctx->pc = 0x12ba84u;
    // NOP
label_12ba88:
    // 0x12ba88: 0xfe510000  sd          $s1, 0x0($s2)
    ctx->pc = 0x12ba88u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 17));
    // 0x12ba8c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12ba8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ba90: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12BA90u;
    SET_GPR_U32(ctx, 31, 0x12BA98u);
    ctx->pc = 0x12BA94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BA90u;
            // 0x12ba94: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BA98u; }
        if (ctx->pc != 0x12BA98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BA98u; }
        if (ctx->pc != 0x12BA98u) { return; }
    }
    ctx->pc = 0x12BA98u;
label_12ba98:
    // 0x12ba98: 0xc045154  jal         func_114550
    ctx->pc = 0x12BA98u;
    SET_GPR_U32(ctx, 31, 0x12BAA0u);
    ctx->pc = 0x12BA9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BA98u;
            // 0x12ba9c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114550u;
    if (runtime->hasFunction(0x114550u)) {
        auto targetFn = runtime->lookupFunction(0x114550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BAA0u; }
        if (ctx->pc != 0x12BAA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114550_0x114550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BAA0u; }
        if (ctx->pc != 0x12BAA0u) { return; }
    }
    ctx->pc = 0x12BAA0u;
label_12baa0:
    // 0x12baa0: 0xc04516c  jal         func_1145B0
    ctx->pc = 0x12BAA0u;
    SET_GPR_U32(ctx, 31, 0x12BAA8u);
    ctx->pc = 0x12BAA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BAA0u;
            // 0x12baa4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1145B0u;
    if (runtime->hasFunction(0x1145B0u)) {
        auto targetFn = runtime->lookupFunction(0x1145B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BAA8u; }
        if (ctx->pc != 0x12BAA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001145B0_0x1145b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BAA8u; }
        if (ctx->pc != 0x12BAA8u) { return; }
    }
    ctx->pc = 0x12BAA8u;
label_12baa8:
    // 0x12baa8: 0xde630000  ld          $v1, 0x0($s3)
    ctx->pc = 0x12baa8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12baac: 0x1060fff6  beqz        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x12BAACu;
    {
        const bool branch_taken_0x12baac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12BAB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BAACu;
            // 0x12bab0: 0x26c20520  addiu       $v0, $s6, 0x520 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1312));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12baac) {
            ctx->pc = 0x12BA88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ba88;
        }
    }
    ctx->pc = 0x12BAB4u;
    // 0x12bab4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x12BAB4u;
    {
        const bool branch_taken_0x12bab4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12BAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BAB4u;
            // 0x12bab8: 0xdfb60030  ld          $s6, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bab4) {
            ctx->pc = 0x12BACCu;
            goto label_12bacc;
        }
    }
    ctx->pc = 0x12BABCu;
    // 0x12babc: 0x0  nop
    ctx->pc = 0x12babcu;
    // NOP
label_12bac0:
    // 0x12bac0: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12bac0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12bac4: 0x26c20520  addiu       $v0, $s6, 0x520
    ctx->pc = 0x12bac4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1312));
    // 0x12bac8: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x12bac8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_12bacc:
    // 0x12bacc: 0x26a30518  addiu       $v1, $s5, 0x518
    ctx->pc = 0x12baccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 1304));
    // 0x12bad0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12bad0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12bad4: 0x268404e0  addiu       $a0, $s4, 0x4E0
    ctx->pc = 0x12bad4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 1248));
    // 0x12bad8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12bad8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12badc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12badcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12bae0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12bae0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12bae4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12bae4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12bae8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12bae8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12baec: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12baecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12baf0: 0xfc400000  sd          $zero, 0x0($v0)
    ctx->pc = 0x12baf0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 0));
    // 0x12baf4: 0xfc600000  sd          $zero, 0x0($v1)
    ctx->pc = 0x12baf4u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 0));
    // 0x12baf8: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x12baf8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x12bafc: 0x3e00008  jr          $ra
    ctx->pc = 0x12BAFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12BB00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BAFCu;
            // 0x12bb00: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12BA88u: goto label_12ba88;
            case 0x12BA98u: goto label_12ba98;
            case 0x12BAA0u: goto label_12baa0;
            case 0x12BAA8u: goto label_12baa8;
            case 0x12BAC0u: goto label_12bac0;
            case 0x12BACCu: goto label_12bacc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12BB04u;
    // 0x12bb04: 0x0  nop
    ctx->pc = 0x12bb04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
