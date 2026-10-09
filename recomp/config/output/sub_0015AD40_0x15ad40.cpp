#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015AD40
// Address: 0x15ad40 - 0x15ade4
void sub_0015AD40_0x15ad40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015AD40_0x15ad40");
#endif

    switch (ctx->pc) {
        case 0x15ad74u: goto label_15ad74;
        case 0x15ada0u: goto label_15ada0;
        default: break;
    }

    ctx->pc = 0x15ad40u;

    // 0x15ad40: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15ad40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15ad44: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15ad44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ad48: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15ad48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15ad4c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15ad4cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ad50: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15ad50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15ad54: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x15ad54u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ad58: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15ad58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15ad5c: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x15ad5cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ad60: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15ad60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15ad64: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x15ad64u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15ad68: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x15ad68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15ad6c: 0xc0561d4  jal         func_158750
    ctx->pc = 0x15AD6Cu;
    SET_GPR_U32(ctx, 31, 0x15AD74u);
    ctx->pc = 0x15AD70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AD6Cu;
            // 0x15ad70: 0x8e250000  lw          $a1, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AD74u; }
        if (ctx->pc != 0x15AD74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AD74u; }
        if (ctx->pc != 0x15AD74u) { return; }
    }
    ctx->pc = 0x15AD74u;
label_15ad74:
    // 0x15ad74: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15ad74u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ad78: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15ad78u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ad7c: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15AD7Cu;
    {
        const bool branch_taken_0x15ad7c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x15AD80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AD7Cu;
            // 0x15ad80: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ad7c) {
            ctx->pc = 0x15AD98u;
            goto label_15ad98;
        }
    }
    ctx->pc = 0x15AD84u;
    // 0x15ad84: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x15ad84u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15ad88: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x15ad88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15ad8c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x15AD8Cu;
    {
        const bool branch_taken_0x15ad8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AD90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AD8Cu;
            // 0x15ad90: 0xa0182d  daddu       $v1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ad8c) {
            ctx->pc = 0x15ADACu;
            goto label_15adac;
        }
    }
    ctx->pc = 0x15AD94u;
    // 0x15ad94: 0x0  nop
    ctx->pc = 0x15ad94u;
    // NOP
label_15ad98:
    // 0x15ad98: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x15AD98u;
    SET_GPR_U32(ctx, 31, 0x15ADA0u);
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ADA0u; }
        if (ctx->pc != 0x15ADA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ADA0u; }
        if (ctx->pc != 0x15ADA0u) { return; }
    }
    ctx->pc = 0x15ADA0u;
label_15ada0:
    // 0x15ada0: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x15ada0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15ada4: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x15ada4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15ada8: 0x2042823  subu        $a1, $s0, $a0
    ctx->pc = 0x15ada8u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_15adac:
    // 0x15adac: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x15adacu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x15adb0: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x15adb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x15adb4: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x15adb4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x15adb8: 0xae440000  sw          $a0, 0x0($s2)
    ctx->pc = 0x15adb8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x15adbc: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x15adbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x15adc0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15adc0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15adc4: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x15adc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x15adc8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15adc8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15adcc: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x15adccu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x15add0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15add0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15add4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15add4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15add8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15add8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15addc: 0x3e00008  jr          $ra
    ctx->pc = 0x15ADDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15ADE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ADDCu;
            // 0x15ade0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AD74u: goto label_15ad74;
            case 0x15AD98u: goto label_15ad98;
            case 0x15ADA0u: goto label_15ada0;
            case 0x15ADACu: goto label_15adac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15ADE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
