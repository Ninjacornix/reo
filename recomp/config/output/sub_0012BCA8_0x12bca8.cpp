#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BCA8
// Address: 0x12bca8 - 0x12bd78
void sub_0012BCA8_0x12bca8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BCA8_0x12bca8");
#endif

    switch (ctx->pc) {
        case 0x12bcf8u: goto label_12bcf8;
        case 0x12bd08u: goto label_12bd08;
        case 0x12bd10u: goto label_12bd10;
        case 0x12bd18u: goto label_12bd18;
        default: break;
    }

    ctx->pc = 0x12bca8u;

    // 0x12bca8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12bca8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12bcac: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x12bcacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x12bcb0: 0x3c160021  lui         $s6, 0x21
    ctx->pc = 0x12bcb0u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)33 << 16));
    // 0x12bcb4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12bcb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12bcb8: 0x26c30500  addiu       $v1, $s6, 0x500
    ctx->pc = 0x12bcb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), 1280));
    // 0x12bcbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12bcbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12bcc0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12bcc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12bcc4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12bcc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12bcc8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12bcc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12bccc: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12bcccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12bcd0: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12bcd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12bcd4: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x12bcd4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12bcd8: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x12BCD8u;
    {
        const bool branch_taken_0x12bcd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12BCDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BCD8u;
            // 0x12bcdc: 0x3c150021  lui         $s5, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bcd8) {
            ctx->pc = 0x12BD30u;
            goto label_12bd30;
        }
    }
    ctx->pc = 0x12BCE0u;
    // 0x12bce0: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12bce0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12bce4: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x12bce4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12bce8: 0x26b204f8  addiu       $s2, $s5, 0x4F8
    ctx->pc = 0x12bce8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), 1272));
    // 0x12bcec: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12bcecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12bcf0: 0x269004d8  addiu       $s0, $s4, 0x4D8
    ctx->pc = 0x12bcf0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 1240));
    // 0x12bcf4: 0x0  nop
    ctx->pc = 0x12bcf4u;
    // NOP
label_12bcf8:
    // 0x12bcf8: 0xfe510000  sd          $s1, 0x0($s2)
    ctx->pc = 0x12bcf8u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 17));
    // 0x12bcfc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12bcfcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12bd00: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12BD00u;
    SET_GPR_U32(ctx, 31, 0x12BD08u);
    ctx->pc = 0x12BD04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BD00u;
            // 0x12bd04: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BD08u; }
        if (ctx->pc != 0x12BD08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BD08u; }
        if (ctx->pc != 0x12BD08u) { return; }
    }
    ctx->pc = 0x12BD08u;
label_12bd08:
    // 0x12bd08: 0xc045154  jal         func_114550
    ctx->pc = 0x12BD08u;
    SET_GPR_U32(ctx, 31, 0x12BD10u);
    ctx->pc = 0x12BD0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BD08u;
            // 0x12bd0c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114550u;
    if (runtime->hasFunction(0x114550u)) {
        auto targetFn = runtime->lookupFunction(0x114550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BD10u; }
        if (ctx->pc != 0x12BD10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114550_0x114550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BD10u; }
        if (ctx->pc != 0x12BD10u) { return; }
    }
    ctx->pc = 0x12BD10u;
label_12bd10:
    // 0x12bd10: 0xc04516c  jal         func_1145B0
    ctx->pc = 0x12BD10u;
    SET_GPR_U32(ctx, 31, 0x12BD18u);
    ctx->pc = 0x12BD14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BD10u;
            // 0x12bd14: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1145B0u;
    if (runtime->hasFunction(0x1145B0u)) {
        auto targetFn = runtime->lookupFunction(0x1145B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BD18u; }
        if (ctx->pc != 0x12BD18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001145B0_0x1145b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BD18u; }
        if (ctx->pc != 0x12BD18u) { return; }
    }
    ctx->pc = 0x12BD18u;
label_12bd18:
    // 0x12bd18: 0xde630000  ld          $v1, 0x0($s3)
    ctx->pc = 0x12bd18u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12bd1c: 0x1060fff6  beqz        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x12BD1Cu;
    {
        const bool branch_taken_0x12bd1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12BD20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BD1Cu;
            // 0x12bd20: 0x26c20500  addiu       $v0, $s6, 0x500 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bd1c) {
            ctx->pc = 0x12BCF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12bcf8;
        }
    }
    ctx->pc = 0x12BD24u;
    // 0x12bd24: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x12BD24u;
    {
        const bool branch_taken_0x12bd24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12BD28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BD24u;
            // 0x12bd28: 0xdfb60030  ld          $s6, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bd24) {
            ctx->pc = 0x12BD3Cu;
            goto label_12bd3c;
        }
    }
    ctx->pc = 0x12BD2Cu;
    // 0x12bd2c: 0x0  nop
    ctx->pc = 0x12bd2cu;
    // NOP
label_12bd30:
    // 0x12bd30: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x12bd30u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x12bd34: 0x26c20500  addiu       $v0, $s6, 0x500
    ctx->pc = 0x12bd34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1280));
    // 0x12bd38: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x12bd38u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_12bd3c:
    // 0x12bd3c: 0x26a304f8  addiu       $v1, $s5, 0x4F8
    ctx->pc = 0x12bd3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 1272));
    // 0x12bd40: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12bd40u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12bd44: 0x268404d8  addiu       $a0, $s4, 0x4D8
    ctx->pc = 0x12bd44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 1240));
    // 0x12bd48: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12bd48u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12bd4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12bd4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12bd50: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12bd50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12bd54: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12bd54u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12bd58: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12bd58u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12bd5c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12bd5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12bd60: 0xfc400000  sd          $zero, 0x0($v0)
    ctx->pc = 0x12bd60u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 0));
    // 0x12bd64: 0xfc600000  sd          $zero, 0x0($v1)
    ctx->pc = 0x12bd64u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 0));
    // 0x12bd68: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x12bd68u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x12bd6c: 0x3e00008  jr          $ra
    ctx->pc = 0x12BD6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12BD70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BD6Cu;
            // 0x12bd70: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12BCF8u: goto label_12bcf8;
            case 0x12BD08u: goto label_12bd08;
            case 0x12BD10u: goto label_12bd10;
            case 0x12BD18u: goto label_12bd18;
            case 0x12BD30u: goto label_12bd30;
            case 0x12BD3Cu: goto label_12bd3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12BD74u;
    // 0x12bd74: 0x0  nop
    ctx->pc = 0x12bd74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
