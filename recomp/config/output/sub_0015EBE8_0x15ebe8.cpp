#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EBE8
// Address: 0x15ebe8 - 0x15ee48
void sub_0015EBE8_0x15ebe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EBE8_0x15ebe8");
#endif

    switch (ctx->pc) {
        case 0x15ebf8u: goto label_15ebf8;
        case 0x15ec3cu: goto label_15ec3c;
        case 0x15ed38u: goto label_15ed38;
        case 0x15ed60u: goto label_15ed60;
        case 0x15ed70u: goto label_15ed70;
        case 0x15ed88u: goto label_15ed88;
        case 0x15edacu: goto label_15edac;
        case 0x15edccu: goto label_15edcc;
        case 0x15ee14u: goto label_15ee14;
        case 0x15ee38u: goto label_15ee38;
        default: break;
    }

    ctx->pc = 0x15ebe8u;

    // 0x15ebe8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ebe8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ebec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ebecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ebf0: 0xc05a6ce  jal         func_169B38
    ctx->pc = 0x15EBF0u;
    SET_GPR_U32(ctx, 31, 0x15EBF8u);
    ctx->pc = 0x169B38u;
    if (runtime->hasFunction(0x169B38u)) {
        auto targetFn = runtime->lookupFunction(0x169B38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBF8u; }
        if (ctx->pc != 0x15EBF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169B38_0x169b38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBF8u; }
        if (ctx->pc != 0x15EBF8u) { return; }
    }
    ctx->pc = 0x15EBF8u;
label_15ebf8:
    // 0x15ebf8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ebf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ebfc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15ebfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec00: 0x3e00008  jr          $ra
    ctx->pc = 0x15EC00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EC04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EC00u;
            // 0x15ec04: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EBF8u: goto label_15ebf8;
            case 0x15EC3Cu: goto label_15ec3c;
            case 0x15EC58u: goto label_15ec58;
            case 0x15EC6Cu: goto label_15ec6c;
            case 0x15EC9Cu: goto label_15ec9c;
            case 0x15ECF0u: goto label_15ecf0;
            case 0x15ED2Cu: goto label_15ed2c;
            case 0x15ED38u: goto label_15ed38;
            case 0x15ED40u: goto label_15ed40;
            case 0x15ED60u: goto label_15ed60;
            case 0x15ED70u: goto label_15ed70;
            case 0x15ED74u: goto label_15ed74;
            case 0x15ED88u: goto label_15ed88;
            case 0x15ED90u: goto label_15ed90;
            case 0x15EDACu: goto label_15edac;
            case 0x15EDB8u: goto label_15edb8;
            case 0x15EDBCu: goto label_15edbc;
            case 0x15EDC0u: goto label_15edc0;
            case 0x15EDCCu: goto label_15edcc;
            case 0x15EDD0u: goto label_15edd0;
            case 0x15EE14u: goto label_15ee14;
            case 0x15EE38u: goto label_15ee38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EC08u;
    // 0x15ec08: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15ec08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15ec0c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15ec0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ec10: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15ec10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec14: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15ec14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15ec18: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15ec18u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec1c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15ec1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15ec20: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x15ec20u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec24: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15ec24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15ec28: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x15ec28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x15ec2c: 0x1200000a  beqz        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x15EC2Cu;
    {
        const bool branch_taken_0x15ec2c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EC30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EC2Cu;
            // 0x15ec30: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ec2c) {
            ctx->pc = 0x15EC58u;
            goto label_15ec58;
        }
    }
    ctx->pc = 0x15EC34u;
    // 0x15ec34: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x15EC34u;
    SET_GPR_U32(ctx, 31, 0x15EC3Cu);
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EC3Cu; }
        if (ctx->pc != 0x15EC3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EC3Cu; }
        if (ctx->pc != 0x15EC3Cu) { return; }
    }
    ctx->pc = 0x15EC3Cu;
label_15ec3c:
    // 0x15ec3c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15ec3cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15ec40: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x15ec40u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec44: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15ec44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15ec48: 0xac50ef40  sw          $s0, -0x10C0($v0)
    ctx->pc = 0x15ec48u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963008), GPR_U32(ctx, 16));
    // 0x15ec4c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x15EC4Cu;
    {
        const bool branch_taken_0x15ec4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EC50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EC4Cu;
            // 0x15ec50: 0xac72ef44  sw          $s2, -0x10BC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294963012), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ec4c) {
            ctx->pc = 0x15EC6Cu;
            goto label_15ec6c;
        }
    }
    ctx->pc = 0x15EC54u;
    // 0x15ec54: 0x0  nop
    ctx->pc = 0x15ec54u;
    // NOP
label_15ec58:
    // 0x15ec58: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15ec58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15ec5c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15ec5cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15ec60: 0xac40ef40  sw          $zero, -0x10C0($v0)
    ctx->pc = 0x15ec60u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963008), GPR_U32(ctx, 0));
    // 0x15ec64: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x15ec64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ec68: 0xac60ef44  sw          $zero, -0x10BC($v1)
    ctx->pc = 0x15ec68u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963012), GPR_U32(ctx, 0));
label_15ec6c:
    // 0x15ec6c: 0x1220000b  beqz        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x15EC6Cu;
    {
        const bool branch_taken_0x15ec6c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EC70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EC6Cu;
            // 0x15ec70: 0x3c020027  lui         $v0, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ec6c) {
            ctx->pc = 0x15EC9Cu;
            goto label_15ec9c;
        }
    }
    ctx->pc = 0x15EC74u;
    // 0x15ec74: 0x24458580  addiu       $a1, $v0, -0x7A80
    ctx->pc = 0x15ec74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294935936));
    // 0x15ec78: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x15ec78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15ec7c: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x15ec7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x15ec80: 0x2883000f  slti        $v1, $a0, 0xF
    ctx->pc = 0x15ec80u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)15) ? 1 : 0);
    // 0x15ec84: 0x3c010027  lui         $at, 0x27
    ctx->pc = 0x15ec84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)39 << 16));
    // 0x15ec88: 0x220821  addu        $at, $at, $v0
    ctx->pc = 0x15ec88u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x15ec8c: 0xac318540  sw          $s1, -0x7AC0($at)
    ctx->pc = 0x15ec8cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294935872), GPR_U32(ctx, 17));
    // 0x15ec90: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x15EC90u;
    {
        const bool branch_taken_0x15ec90 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EC94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EC90u;
            // 0x15ec94: 0x24820001  addiu       $v0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ec90) {
            ctx->pc = 0x15EC9Cu;
            goto label_15ec9c;
        }
    }
    ctx->pc = 0x15EC98u;
    // 0x15ec98: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x15ec98u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_15ec9c:
    // 0x15ec9c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x15ec9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x15eca0: 0x34420f1c  ori         $v0, $v0, 0xF1C
    ctx->pc = 0x15eca0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3868);
    // 0x15eca4: 0x1222003a  beq         $s1, $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x15ECA4u;
    {
        const bool branch_taken_0x15eca4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x15ECA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ECA4u;
            // 0x15eca8: 0x51102b  sltu        $v0, $v0, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15eca4) {
            ctx->pc = 0x15ED90u;
            goto label_15ed90;
        }
    }
    ctx->pc = 0x15ECACu;
    // 0x15ecac: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x15ECACu;
    {
        const bool branch_taken_0x15ecac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15ecac) {
            ctx->pc = 0x15ECF0u;
            goto label_15ecf0;
        }
    }
    ctx->pc = 0x15ECB4u;
    // 0x15ecb4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x15ecb4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x15ecb8: 0x34420f18  ori         $v0, $v0, 0xF18
    ctx->pc = 0x15ecb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3864);
    // 0x15ecbc: 0x51102b  sltu        $v0, $v0, $s1
    ctx->pc = 0x15ecbcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x15ecc0: 0x1440003d  bnez        $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x15ECC0u;
    {
        const bool branch_taken_0x15ecc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15ECC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ECC0u;
            // 0x15ecc4: 0x3c140027  lui         $s4, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ecc0) {
            ctx->pc = 0x15EDB8u;
            goto label_15edb8;
        }
    }
    ctx->pc = 0x15ECC8u;
    // 0x15ecc8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x15ecc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x15eccc: 0x34420f17  ori         $v0, $v0, 0xF17
    ctx->pc = 0x15ecccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3863);
    // 0x15ecd0: 0x222102b  sltu        $v0, $s1, $v0
    ctx->pc = 0x15ecd0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x15ecd4: 0x54400039  bnel        $v0, $zero, . + 4 + (0x39 << 2)
    ctx->pc = 0x15ECD4u;
    {
        const bool branch_taken_0x15ecd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15ecd4) {
            ctx->pc = 0x15ECD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15ECD4u;
            // 0x15ecd8: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15EDBCu;
            goto label_15edbc;
        }
    }
    ctx->pc = 0x15ECDCu;
    // 0x15ecdc: 0x3c140027  lui         $s4, 0x27
    ctx->pc = 0x15ecdcu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)39 << 16));
    // 0x15ece0: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x15ece0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x15ece4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x15ECE4u;
    {
        const bool branch_taken_0x15ece4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15ECE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ECE4u;
            // 0x15ece8: 0x24a5ef48  addiu       $a1, $a1, -0x10B8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294963016));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ece4) {
            ctx->pc = 0x15ED2Cu;
            goto label_15ed2c;
        }
    }
    ctx->pc = 0x15ECECu;
    // 0x15ecec: 0x0  nop
    ctx->pc = 0x15ececu;
    // NOP
label_15ecf0:
    // 0x15ecf0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x15ecf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x15ecf4: 0x34420f40  ori         $v0, $v0, 0xF40
    ctx->pc = 0x15ecf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3904);
    // 0x15ecf8: 0x12220011  beq         $s1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x15ECF8u;
    {
        const bool branch_taken_0x15ecf8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x15ECFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ECF8u;
            // 0x15ecfc: 0x222102b  sltu        $v0, $s1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ecf8) {
            ctx->pc = 0x15ED40u;
            goto label_15ed40;
        }
    }
    ctx->pc = 0x15ED00u;
    // 0x15ed00: 0x1440002d  bnez        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x15ED00u;
    {
        const bool branch_taken_0x15ed00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15ED04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED00u;
            // 0x15ed04: 0x3c140027  lui         $s4, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ed00) {
            ctx->pc = 0x15EDB8u;
            goto label_15edb8;
        }
    }
    ctx->pc = 0x15ED08u;
    // 0x15ed08: 0x2e22ffff  sltiu       $v0, $s1, -0x1
    ctx->pc = 0x15ed08u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x15ed0c: 0x1040002b  beqz        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x15ED0Cu;
    {
        const bool branch_taken_0x15ed0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15ED10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED0Cu;
            // 0x15ed10: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ed0c) {
            ctx->pc = 0x15EDBCu;
            goto label_15edbc;
        }
    }
    ctx->pc = 0x15ED14u;
    // 0x15ed14: 0x2e22fffd  sltiu       $v0, $s1, -0x3
    ctx->pc = 0x15ed14u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)4294967293) ? 1 : 0);
    // 0x15ed18: 0x14400029  bnez        $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x15ED18u;
    {
        const bool branch_taken_0x15ed18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15ED1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED18u;
            // 0x15ed1c: 0x24a5efe0  addiu       $a1, $a1, -0x1020 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294963168));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ed18) {
            ctx->pc = 0x15EDC0u;
            goto label_15edc0;
        }
    }
    ctx->pc = 0x15ED20u;
    // 0x15ed20: 0x3c140027  lui         $s4, 0x27
    ctx->pc = 0x15ed20u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)39 << 16));
    // 0x15ed24: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x15ed24u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x15ed28: 0x24a5ef18  addiu       $a1, $a1, -0x10E8
    ctx->pc = 0x15ed28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962968));
label_15ed2c:
    // 0x15ed2c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x15ed2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ed30: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x15ED30u;
    SET_GPR_U32(ctx, 31, 0x15ED38u);
    ctx->pc = 0x15ED34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED30u;
            // 0x15ed34: 0x26848588  addiu       $a0, $s4, -0x7A78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294935944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED38u; }
        if (ctx->pc != 0x15ED38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED38u; }
        if (ctx->pc != 0x15ED38u) { return; }
    }
    ctx->pc = 0x15ED38u;
label_15ed38:
    // 0x15ed38: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x15ED38u;
    {
        const bool branch_taken_0x15ed38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15ED3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED38u;
            // 0x15ed3c: 0x26848588  addiu       $a0, $s4, -0x7A78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294935944));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ed38) {
            ctx->pc = 0x15EDD0u;
            goto label_15edd0;
        }
    }
    ctx->pc = 0x15ED40u;
label_15ed40:
    // 0x15ed40: 0x3c140027  lui         $s4, 0x27
    ctx->pc = 0x15ed40u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)39 << 16));
    // 0x15ed44: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x15ed44u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x15ed48: 0x26908588  addiu       $s0, $s4, -0x7A78
    ctx->pc = 0x15ed48u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 4294935944));
    // 0x15ed4c: 0x3c06ff00  lui         $a2, 0xFF00
    ctx->pc = 0x15ed4cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)65280 << 16));
    // 0x15ed50: 0x24a5ef30  addiu       $a1, $a1, -0x10D0
    ctx->pc = 0x15ed50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962992));
    // 0x15ed54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15ed54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ed58: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x15ED58u;
    SET_GPR_U32(ctx, 31, 0x15ED60u);
    ctx->pc = 0x15ED5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED58u;
            // 0x15ed5c: 0x34c60f40  ori         $a2, $a2, 0xF40 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)3904);
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED60u; }
        if (ctx->pc != 0x15ED60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED60u; }
        if (ctx->pc != 0x15ED60u) { return; }
    }
    ctx->pc = 0x15ED60u;
label_15ed60:
    // 0x15ed60: 0x12400004  beqz        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x15ED60u;
    {
        const bool branch_taken_0x15ed60 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x15ed60) {
            ctx->pc = 0x15ED74u;
            goto label_15ed74;
        }
    }
    ctx->pc = 0x15ED68u;
    // 0x15ed68: 0xc05c602  jal         func_171808
    ctx->pc = 0x15ED68u;
    SET_GPR_U32(ctx, 31, 0x15ED70u);
    ctx->pc = 0x15ED6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED68u;
            // 0x15ed6c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171808u;
    if (runtime->hasFunction(0x171808u)) {
        auto targetFn = runtime->lookupFunction(0x171808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED70u; }
        if (ctx->pc != 0x15ED70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171808_0x171808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED70u; }
        if (ctx->pc != 0x15ED70u) { return; }
    }
    ctx->pc = 0x15ED70u;
label_15ed70:
    // 0x15ed70: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x15ed70u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_15ed74:
    // 0x15ed74: 0x12600015  beqz        $s3, . + 4 + (0x15 << 2)
    ctx->pc = 0x15ED74u;
    {
        const bool branch_taken_0x15ed74 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x15ED78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED74u;
            // 0x15ed78: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ed74) {
            ctx->pc = 0x15EDCCu;
            goto label_15edcc;
        }
    }
    ctx->pc = 0x15ED7Cu;
    // 0x15ed7c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x15ed7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ed80: 0xc042ca4  jal         func_10B290
    ctx->pc = 0x15ED80u;
    SET_GPR_U32(ctx, 31, 0x15ED88u);
    ctx->pc = 0x15ED84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED80u;
            // 0x15ed84: 0x24060069  addiu       $a2, $zero, 0x69 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 105));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B290u;
    if (runtime->hasFunction(0x10B290u)) {
        auto targetFn = runtime->lookupFunction(0x10B290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED88u; }
        if (ctx->pc != 0x15ED88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B290_0x10b290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ED88u; }
        if (ctx->pc != 0x15ED88u) { return; }
    }
    ctx->pc = 0x15ED88u;
label_15ed88:
    // 0x15ed88: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x15ED88u;
    {
        const bool branch_taken_0x15ed88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15ED8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ED88u;
            // 0x15ed8c: 0x26848588  addiu       $a0, $s4, -0x7A78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294935944));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ed88) {
            ctx->pc = 0x15EDD0u;
            goto label_15edd0;
        }
    }
    ctx->pc = 0x15ED90u;
label_15ed90:
    // 0x15ed90: 0x3c140027  lui         $s4, 0x27
    ctx->pc = 0x15ed90u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)39 << 16));
    // 0x15ed94: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x15ed94u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x15ed98: 0x3c06ff00  lui         $a2, 0xFF00
    ctx->pc = 0x15ed98u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)65280 << 16));
    // 0x15ed9c: 0x24a5ef80  addiu       $a1, $a1, -0x1080
    ctx->pc = 0x15ed9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294963072));
    // 0x15eda0: 0x26848588  addiu       $a0, $s4, -0x7A78
    ctx->pc = 0x15eda0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294935944));
    // 0x15eda4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x15EDA4u;
    SET_GPR_U32(ctx, 31, 0x15EDACu);
    ctx->pc = 0x15EDA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EDA4u;
            // 0x15eda8: 0x34c60f1c  ori         $a2, $a2, 0xF1C (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)3868);
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EDACu; }
        if (ctx->pc != 0x15EDACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EDACu; }
        if (ctx->pc != 0x15EDACu) { return; }
    }
    ctx->pc = 0x15EDACu;
label_15edac:
    // 0x15edac: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x15EDACu;
    {
        const bool branch_taken_0x15edac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EDB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EDACu;
            // 0x15edb0: 0x26848588  addiu       $a0, $s4, -0x7A78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294935944));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15edac) {
            ctx->pc = 0x15EDD0u;
            goto label_15edd0;
        }
    }
    ctx->pc = 0x15EDB4u;
    // 0x15edb4: 0x0  nop
    ctx->pc = 0x15edb4u;
    // NOP
label_15edb8:
    // 0x15edb8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x15edb8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
label_15edbc:
    // 0x15edbc: 0x24a5efe0  addiu       $a1, $a1, -0x1020
    ctx->pc = 0x15edbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294963168));
label_15edc0:
    // 0x15edc0: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x15edc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15edc4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x15EDC4u;
    SET_GPR_U32(ctx, 31, 0x15EDCCu);
    ctx->pc = 0x15EDC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EDC4u;
            // 0x15edc8: 0x26848588  addiu       $a0, $s4, -0x7A78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294935944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EDCCu; }
        if (ctx->pc != 0x15EDCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EDCCu; }
        if (ctx->pc != 0x15EDCCu) { return; }
    }
    ctx->pc = 0x15EDCCu;
label_15edcc:
    // 0x15edcc: 0x26848588  addiu       $a0, $s4, -0x7A78
    ctx->pc = 0x15edccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294935944));
label_15edd0:
    // 0x15edd0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x15edd0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15edd4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15edd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15edd8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15edd8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15eddc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15eddcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15ede0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15ede0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15ede4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x15ede4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15ede8: 0x8058dd4  j           func_163750
    ctx->pc = 0x15EDE8u;
    ctx->pc = 0x15EDECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EDE8u;
            // 0x15edec: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15EDF0u;
    // 0x15edf0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15edf0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15edf4: 0x3e00008  jr          $ra
    ctx->pc = 0x15EDF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EDF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EDF4u;
            // 0x15edf8: 0x8c62ef40  lw          $v0, -0x10C0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294963008)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EBF8u: goto label_15ebf8;
            case 0x15EC3Cu: goto label_15ec3c;
            case 0x15EC58u: goto label_15ec58;
            case 0x15EC6Cu: goto label_15ec6c;
            case 0x15EC9Cu: goto label_15ec9c;
            case 0x15ECF0u: goto label_15ecf0;
            case 0x15ED2Cu: goto label_15ed2c;
            case 0x15ED38u: goto label_15ed38;
            case 0x15ED40u: goto label_15ed40;
            case 0x15ED60u: goto label_15ed60;
            case 0x15ED70u: goto label_15ed70;
            case 0x15ED74u: goto label_15ed74;
            case 0x15ED88u: goto label_15ed88;
            case 0x15ED90u: goto label_15ed90;
            case 0x15EDACu: goto label_15edac;
            case 0x15EDB8u: goto label_15edb8;
            case 0x15EDBCu: goto label_15edbc;
            case 0x15EDC0u: goto label_15edc0;
            case 0x15EDCCu: goto label_15edcc;
            case 0x15EDD0u: goto label_15edd0;
            case 0x15EE14u: goto label_15ee14;
            case 0x15EE38u: goto label_15ee38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EDFCu;
    // 0x15edfc: 0x0  nop
    ctx->pc = 0x15edfcu;
    // NOP
    // 0x15ee00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ee00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ee04: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15ee04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ee08: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15ee08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15ee0c: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15EE0Cu;
    SET_GPR_U32(ctx, 31, 0x15EE14u);
    ctx->pc = 0x15EE10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE0Cu;
            // 0x15ee10: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE14u; }
        if (ctx->pc != 0x15EE14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE14u; }
        if (ctx->pc != 0x15EE14u) { return; }
    }
    ctx->pc = 0x15EE14u;
label_15ee14:
    // 0x15ee14: 0xac500034  sw          $s0, 0x34($v0)
    ctx->pc = 0x15ee14u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 52), GPR_U32(ctx, 16));
    // 0x15ee18: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15ee18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15ee1c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15ee1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ee20: 0x3e00008  jr          $ra
    ctx->pc = 0x15EE20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EE24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE20u;
            // 0x15ee24: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EBF8u: goto label_15ebf8;
            case 0x15EC3Cu: goto label_15ec3c;
            case 0x15EC58u: goto label_15ec58;
            case 0x15EC6Cu: goto label_15ec6c;
            case 0x15EC9Cu: goto label_15ec9c;
            case 0x15ECF0u: goto label_15ecf0;
            case 0x15ED2Cu: goto label_15ed2c;
            case 0x15ED38u: goto label_15ed38;
            case 0x15ED40u: goto label_15ed40;
            case 0x15ED60u: goto label_15ed60;
            case 0x15ED70u: goto label_15ed70;
            case 0x15ED74u: goto label_15ed74;
            case 0x15ED88u: goto label_15ed88;
            case 0x15ED90u: goto label_15ed90;
            case 0x15EDACu: goto label_15edac;
            case 0x15EDB8u: goto label_15edb8;
            case 0x15EDBCu: goto label_15edbc;
            case 0x15EDC0u: goto label_15edc0;
            case 0x15EDCCu: goto label_15edcc;
            case 0x15EDD0u: goto label_15edd0;
            case 0x15EE14u: goto label_15ee14;
            case 0x15EE38u: goto label_15ee38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EE28u;
    // 0x15ee28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ee28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ee2c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ee2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ee30: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15EE30u;
    SET_GPR_U32(ctx, 31, 0x15EE38u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE38u; }
        if (ctx->pc != 0x15EE38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE38u; }
        if (ctx->pc != 0x15EE38u) { return; }
    }
    ctx->pc = 0x15EE38u;
label_15ee38:
    // 0x15ee38: 0x8c420034  lw          $v0, 0x34($v0)
    ctx->pc = 0x15ee38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x15ee3c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ee3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ee40: 0x3e00008  jr          $ra
    ctx->pc = 0x15EE40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EE44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE40u;
            // 0x15ee44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EBF8u: goto label_15ebf8;
            case 0x15EC3Cu: goto label_15ec3c;
            case 0x15EC58u: goto label_15ec58;
            case 0x15EC6Cu: goto label_15ec6c;
            case 0x15EC9Cu: goto label_15ec9c;
            case 0x15ECF0u: goto label_15ecf0;
            case 0x15ED2Cu: goto label_15ed2c;
            case 0x15ED38u: goto label_15ed38;
            case 0x15ED40u: goto label_15ed40;
            case 0x15ED60u: goto label_15ed60;
            case 0x15ED70u: goto label_15ed70;
            case 0x15ED74u: goto label_15ed74;
            case 0x15ED88u: goto label_15ed88;
            case 0x15ED90u: goto label_15ed90;
            case 0x15EDACu: goto label_15edac;
            case 0x15EDB8u: goto label_15edb8;
            case 0x15EDBCu: goto label_15edbc;
            case 0x15EDC0u: goto label_15edc0;
            case 0x15EDCCu: goto label_15edcc;
            case 0x15EDD0u: goto label_15edd0;
            case 0x15EE14u: goto label_15ee14;
            case 0x15EE38u: goto label_15ee38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EE48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
