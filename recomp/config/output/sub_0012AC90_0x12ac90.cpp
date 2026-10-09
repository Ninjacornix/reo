#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012AC90
// Address: 0x12ac90 - 0x12ad70
void sub_0012AC90_0x12ac90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012AC90_0x12ac90");
#endif

    switch (ctx->pc) {
        case 0x12acf0u: goto label_12acf0;
        case 0x12ad04u: goto label_12ad04;
        case 0x12ad0cu: goto label_12ad0c;
        case 0x12ad1cu: goto label_12ad1c;
        case 0x12ad24u: goto label_12ad24;
        case 0x12ad2cu: goto label_12ad2c;
        case 0x12ad34u: goto label_12ad34;
        default: break;
    }

    ctx->pc = 0x12ac90u;

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
    ctx->pc = GPR_U32(ctx, 31); return;
}
