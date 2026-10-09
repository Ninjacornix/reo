#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016AD80
// Address: 0x16ad80 - 0x16ae28
void sub_0016AD80_0x16ad80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016AD80_0x16ad80");
#endif

    switch (ctx->pc) {
        case 0x16adb0u: goto label_16adb0;
        case 0x16add0u: goto label_16add0;
        case 0x16adf4u: goto label_16adf4;
        default: break;
    }

    ctx->pc = 0x16ad80u;

    // 0x16ad80: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16ad80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16ad84: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16ad84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16ad88: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x16ad88u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ad8c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16ad8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16ad90: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x16ad90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ad94: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16ad94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16ad98: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x16ad98u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ad9c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16ad9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16ada0: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x16ada0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x16ada4: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x16ada4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x16ada8: 0x40f809  jalr        $v0
    ctx->pc = 0x16ADA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16ADB0u);
        ctx->pc = 0x16ADACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16ADA8u;
            // 0x16adac: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16ADB0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16ADB0u: goto label_16adb0;
            case 0x16ADD0u: goto label_16add0;
            case 0x16ADF4u: goto label_16adf4;
            case 0x16AE0Cu: goto label_16ae0c;
            case 0x16AE10u: goto label_16ae10;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16ADB0u; }
            if (ctx->pc != 0x16ADB0u) { return; }
        }
        }
    }
    ctx->pc = 0x16ADB0u;
label_16adb0:
    // 0x16adb0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16adb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16adb4: 0x50182a  slt         $v1, $v0, $s0
    ctx->pc = 0x16adb4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x16adb8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16adb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16adbc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16adbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16adc0: 0x14600013  bnez        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x16ADC0u;
    {
        const bool branch_taken_0x16adc0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16ADC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16ADC0u;
            // 0x16adc4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16adc0) {
            ctx->pc = 0x16AE10u;
            goto label_16ae10;
        }
    }
    ctx->pc = 0x16ADC8u;
    // 0x16adc8: 0xc05ab8a  jal         func_16AE28
    ctx->pc = 0x16ADC8u;
    SET_GPR_U32(ctx, 31, 0x16ADD0u);
    ctx->pc = 0x16AE28u;
    if (runtime->hasFunction(0x16AE28u)) {
        auto targetFn = runtime->lookupFunction(0x16AE28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ADD0u; }
        if (ctx->pc != 0x16ADD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016AE28_0x16ae28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ADD0u; }
        if (ctx->pc != 0x16ADD0u) { return; }
    }
    ctx->pc = 0x16ADD0u;
label_16add0:
    // 0x16add0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16add0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16add4: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x16ADD4u;
    {
        const bool branch_taken_0x16add4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16ADD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16ADD4u;
            // 0x16add8: 0x2038023  subu        $s0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16add4) {
            ctx->pc = 0x16AE10u;
            goto label_16ae10;
        }
    }
    ctx->pc = 0x16ADDCu;
    // 0x16addc: 0x1a00000b  blez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x16ADDCu;
    {
        const bool branch_taken_0x16addc = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x16ADE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16ADDCu;
            // 0x16ade0: 0x2238821  addu        $s1, $s1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16addc) {
            ctx->pc = 0x16AE0Cu;
            goto label_16ae0c;
        }
    }
    ctx->pc = 0x16ADE4u;
    // 0x16ade4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16ade4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ade8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16ade8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16adec: 0xc05ab8a  jal         func_16AE28
    ctx->pc = 0x16ADECu;
    SET_GPR_U32(ctx, 31, 0x16ADF4u);
    ctx->pc = 0x16ADF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16ADECu;
            // 0x16adf0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16AE28u;
    if (runtime->hasFunction(0x16AE28u)) {
        auto targetFn = runtime->lookupFunction(0x16AE28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ADF4u; }
        if (ctx->pc != 0x16ADF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016AE28_0x16ae28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ADF4u; }
        if (ctx->pc != 0x16ADF4u) { return; }
    }
    ctx->pc = 0x16ADF4u;
label_16adf4:
    // 0x16adf4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x16adf4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x16adf8: 0x10500004  beq         $v0, $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16ADF8u;
    {
        const bool branch_taken_0x16adf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        ctx->pc = 0x16ADFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16ADF8u;
            // 0x16adfc: 0x2463f1b0  addiu       $v1, $v1, -0xE50 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963632));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16adf8) {
            ctx->pc = 0x16AE0Cu;
            goto label_16ae0c;
        }
    }
    ctx->pc = 0x16AE00u;
    // 0x16ae00: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x16ae00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x16ae04: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x16ae04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16ae08: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x16ae08u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_16ae0c:
    // 0x16ae0c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16ae0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_16ae10:
    // 0x16ae10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16ae10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16ae14: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16ae14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16ae18: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16ae18u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16ae1c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16ae1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16ae20: 0x3e00008  jr          $ra
    ctx->pc = 0x16AE20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16AE24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AE20u;
            // 0x16ae24: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16ADB0u: goto label_16adb0;
            case 0x16ADD0u: goto label_16add0;
            case 0x16ADF4u: goto label_16adf4;
            case 0x16AE0Cu: goto label_16ae0c;
            case 0x16AE10u: goto label_16ae10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16AE28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
