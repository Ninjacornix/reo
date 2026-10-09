#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020ADA0
// Address: 0x20ada0 - 0x20aedc
void sub_0020ADA0_0x20ada0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020ADA0_0x20ada0");
#endif

    switch (ctx->pc) {
        case 0x20adfcu: goto label_20adfc;
        case 0x20ae20u: goto label_20ae20;
        case 0x20ae58u: goto label_20ae58;
        case 0x20aeacu: goto label_20aeac;
        default: break;
    }

    ctx->pc = 0x20ada0u;

    // 0x20ada0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x20ada0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x20ada4: 0x3c02b000  lui         $v0, 0xB000
    ctx->pc = 0x20ada4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)45056 << 16));
    // 0x20ada8: 0xffb70070  sd          $s7, 0x70($sp)
    ctx->pc = 0x20ada8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x20adac: 0x34421800  ori         $v0, $v0, 0x1800
    ctx->pc = 0x20adacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6144);
    // 0x20adb0: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x20adb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x20adb4: 0xc0b82d  daddu       $s7, $a2, $zero
    ctx->pc = 0x20adb4u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20adb8: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x20adb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x20adbc: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x20adbcu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20adc0: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x20adc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x20adc4: 0x3c158007  lui         $s5, 0x8007
    ctx->pc = 0x20adc4u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)32775 << 16));
    // 0x20adc8: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x20adc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x20adcc: 0x3093ffff  andi        $s3, $a0, 0xFFFF
    ctx->pc = 0x20adccu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x20add0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x20add0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x20add4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x20add4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x20add8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x20add8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x20addc: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x20addcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x20ade0: 0x8ea36700  lw          $v1, 0x6700($s5)
    ctx->pc = 0x20ade0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 26368)));
    // 0x20ade4: 0x8c540000  lw          $s4, 0x0($v0)
    ctx->pc = 0x20ade4u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x20ade8: 0x28630040  slti        $v1, $v1, 0x40
    ctx->pc = 0x20ade8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x20adec: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x20ADECu;
    {
        const bool branch_taken_0x20adec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x20ADF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20ADECu;
            // 0x20adf0: 0x2749821  addu        $s3, $s3, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20adec) {
            ctx->pc = 0x20AE10u;
            goto label_20ae10;
        }
    }
    ctx->pc = 0x20ADF4u;
    // 0x20adf4: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x20ADF4u;
    {
        const bool branch_taken_0x20adf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20ADF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20ADF4u;
            // 0x20adf8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20adf4) {
            ctx->pc = 0x20AEB0u;
            goto label_20aeb0;
        }
    }
    ctx->pc = 0x20ADFCu;
label_20adfc:
    // 0x20adfc: 0x60902d  daddu       $s2, $v1, $zero
    ctx->pc = 0x20adfcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20ae00: 0x621014  dsllv       $v0, $v0, $v1
    ctx->pc = 0x20ae00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (GPR_U32(ctx, 3) & 0x3F));
    // 0x20ae04: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x20ae04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x20ae08: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x20AE08u;
    {
        const bool branch_taken_0x20ae08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20AE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AE08u;
            // 0x20ae0c: 0xfca26708  sd          $v0, 0x6708($a1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 5), 26376), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20ae08) {
            ctx->pc = 0x20AE40u;
            goto label_20ae40;
        }
    }
    ctx->pc = 0x20AE10u;
label_20ae10:
    // 0x20ae10: 0x3c058007  lui         $a1, 0x8007
    ctx->pc = 0x20ae10u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32775 << 16));
    // 0x20ae14: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x20ae14u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20ae18: 0xdca46708  ld          $a0, 0x6708($a1)
    ctx->pc = 0x20ae18u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 5), 26376)));
    // 0x20ae1c: 0x641016  dsrlv       $v0, $a0, $v1
    ctx->pc = 0x20ae1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) >> (GPR_U32(ctx, 3) & 0x3F));
label_20ae20:
    // 0x20ae20: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x20ae20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x20ae24: 0x1040fff5  beqz        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x20AE24u;
    {
        const bool branch_taken_0x20ae24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x20AE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AE24u;
            // 0x20ae28: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20ae24) {
            ctx->pc = 0x20ADFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20adfc;
        }
    }
    ctx->pc = 0x20AE2Cu;
    // 0x20ae2c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x20ae2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x20ae30: 0x28620040  slti        $v0, $v1, 0x40
    ctx->pc = 0x20ae30u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x20ae34: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x20AE34u;
    {
        const bool branch_taken_0x20ae34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20AE38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AE34u;
            // 0x20ae38: 0x641016  dsrlv       $v0, $a0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) >> (GPR_U32(ctx, 3) & 0x3F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20ae34) {
            ctx->pc = 0x20AE20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20ae20;
        }
    }
    ctx->pc = 0x20AE3Cu;
    // 0x20ae3c: 0x2412ffff  addiu       $s2, $zero, -0x1
    ctx->pc = 0x20ae3cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_20ae40:
    // 0x20ae40: 0x640001b  bltz        $s2, . + 4 + (0x1B << 2)
    ctx->pc = 0x20AE40u;
    {
        const bool branch_taken_0x20ae40 = (GPR_S64(ctx, 18) < 0);
        ctx->pc = 0x20AE44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AE40u;
            // 0x20ae44: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20ae40) {
            ctx->pc = 0x20AEB0u;
            goto label_20aeb0;
        }
    }
    ctx->pc = 0x20AE48u;
    // 0x20ae48: 0x380882d  daddu       $s1, $gp, $zero
    ctx->pc = 0x20ae48u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20ae4c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x20ae4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20ae50: 0xc01d816  jal         func_076058
    ctx->pc = 0x20AE50u;
    SET_GPR_U32(ctx, 31, 0x20AE58u);
    ctx->pc = 0x20AE54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20AE50u;
            // 0x20ae54: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x76058u;
    {
        auto targetFn = runtime->lookupFunction(0x76058u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20AE58u; }
        if (ctx->pc != 0x20AE58u) { return; }
    }
    ctx->pc = 0x20AE58u;
label_20ae58:
    // 0x20ae58: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x20ae58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x20ae5c: 0x3c088007  lui         $t0, 0x8007
    ctx->pc = 0x20ae5cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32775 << 16));
    // 0x20ae60: 0x441018  mult        $v0, $v0, $a0
    ctx->pc = 0x20ae60u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x20ae64: 0x25036740  addiu       $v1, $t0, 0x6740
    ctx->pc = 0x20ae64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 26432));
    // 0x20ae68: 0x8ea56700  lw          $a1, 0x6700($s5)
    ctx->pc = 0x20ae68u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 26368)));
    // 0x20ae6c: 0x24700004  addiu       $s0, $v1, 0x4
    ctx->pc = 0x20ae6cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x20ae70: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x20ae70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x20ae74: 0x432021  addu        $a0, $v0, $v1
    ctx->pc = 0x20ae74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x20ae78: 0x623821  addu        $a3, $v1, $v0
    ctx->pc = 0x20ae78u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x20ae7c: 0x508021  addu        $s0, $v0, $s0
    ctx->pc = 0x20ae7cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x20ae80: 0xa4940002  sh          $s4, 0x2($a0)
    ctx->pc = 0x20ae80u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 20));
    // 0x20ae84: 0xa4930000  sh          $s3, 0x0($a0)
    ctx->pc = 0x20ae84u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 19));
    // 0x20ae88: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x20ae88u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20ae8c: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x20ae8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x20ae90: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x20ae90u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20ae94: 0xacf10010  sw          $s1, 0x10($a3)
    ctx->pc = 0x20ae94u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 16), GPR_U32(ctx, 17));
    // 0x20ae98: 0x95046740  lhu         $a0, 0x6740($t0)
    ctx->pc = 0x20ae98u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 26432)));
    // 0x20ae9c: 0xacd60008  sw          $s6, 0x8($a2)
    ctx->pc = 0x20ae9cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 22));
    // 0x20aea0: 0xac77000c  sw          $s7, 0xC($v1)
    ctx->pc = 0x20aea0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 23));
    // 0x20aea4: 0xc01d918  jal         func_076460
    ctx->pc = 0x20AEA4u;
    SET_GPR_U32(ctx, 31, 0x20AEACu);
    ctx->pc = 0x20AEA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20AEA4u;
            // 0x20aea8: 0xaea56700  sw          $a1, 0x6700($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 26368), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x76460u;
    {
        auto targetFn = runtime->lookupFunction(0x76460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20AEACu; }
        if (ctx->pc != 0x20AEACu) { return; }
    }
    ctx->pc = 0x20AEACu;
label_20aeac:
    // 0x20aeac: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x20aeacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_20aeb0:
    // 0x20aeb0: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x20aeb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x20aeb4: 0xdfb70070  ld          $s7, 0x70($sp)
    ctx->pc = 0x20aeb4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x20aeb8: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x20aeb8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x20aebc: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x20aebcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x20aec0: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x20aec0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x20aec4: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x20aec4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x20aec8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x20aec8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x20aecc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x20aeccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x20aed0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x20aed0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x20aed4: 0x3e00008  jr          $ra
    ctx->pc = 0x20AED4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20AED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20AED4u;
            // 0x20aed8: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20ADFCu: goto label_20adfc;
            case 0x20AE10u: goto label_20ae10;
            case 0x20AE20u: goto label_20ae20;
            case 0x20AE40u: goto label_20ae40;
            case 0x20AE58u: goto label_20ae58;
            case 0x20AEACu: goto label_20aeac;
            case 0x20AEB0u: goto label_20aeb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20AEDCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
