#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011EBC8
// Address: 0x11ebc8 - 0x11edb0
void sub_0011EBC8_0x11ebc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011EBC8_0x11ebc8");
#endif

    switch (ctx->pc) {
        case 0x11ec30u: goto label_11ec30;
        case 0x11ec6cu: goto label_11ec6c;
        case 0x11ec74u: goto label_11ec74;
        case 0x11eca8u: goto label_11eca8;
        case 0x11ecb4u: goto label_11ecb4;
        case 0x11ecc4u: goto label_11ecc4;
        case 0x11ed0cu: goto label_11ed0c;
        case 0x11ed44u: goto label_11ed44;
        case 0x11ed60u: goto label_11ed60;
        case 0x11ed8cu: goto label_11ed8c;
        default: break;
    }

    ctx->pc = 0x11ebc8u;

label_11ebc8:
    // 0x11ebc8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11ebc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11ebcc: 0x41282  srl         $v0, $a0, 10
    ctx->pc = 0x11ebccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 10));
    // 0x11ebd0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11ebd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11ebd4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11ebd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11ebd8: 0x28180  sll         $s0, $v0, 6
    ctx->pc = 0x11ebd8u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x11ebdc: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11EBDCu;
    {
        const bool branch_taken_0x11ebdc = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x11EBE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EBDCu;
            // 0x11ebe0: 0xffb10010  sd          $s1, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ebdc) {
            ctx->pc = 0x11EBF4u;
            goto label_11ebf4;
        }
    }
    ctx->pc = 0x11EBE4u;
    // 0x11ebe4: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x11ebe4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11ebe8: 0x308203ff  andi        $v0, $a0, 0x3FF
    ctx->pc = 0x11ebe8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1023);
    // 0x11ebec: 0x50430004  beql        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x11EBECu;
    {
        const bool branch_taken_0x11ebec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x11ebec) {
            ctx->pc = 0x11EBF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11EBECu;
            // 0x11ebf0: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11EC00u;
            goto label_11ec00;
        }
    }
    ctx->pc = 0x11EBF4u;
label_11ebf4:
    // 0x11ebf4: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11ebf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11ebf8: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x11EBF8u;
    {
        const bool branch_taken_0x11ebf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EBFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EBF8u;
            // 0x11ebfc: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ebf8) {
            ctx->pc = 0x11EC78u;
            goto label_11ec78;
        }
    }
    ctx->pc = 0x11EC00u;
label_11ec00:
    // 0x11ec00: 0x2442b3e8  addiu       $v0, $v0, -0x4C18
    ctx->pc = 0x11ec00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947816));
    // 0x11ec04: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x11ec04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x11ec08: 0x54640004  bnel        $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11EC08u;
    {
        const bool branch_taken_0x11ec08 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x11ec08) {
            ctx->pc = 0x11EC0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11EC08u;
            // 0x11ec0c: 0x8e02000c  lw          $v0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11EC1Cu;
            goto label_11ec1c;
        }
    }
    ctx->pc = 0x11EC10u;
    // 0x11ec10: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11ec10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11ec14: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x11EC14u;
    {
        const bool branch_taken_0x11ec14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EC18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EC14u;
            // 0x11ec18: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ec14) {
            ctx->pc = 0x11EC78u;
            goto label_11ec78;
        }
    }
    ctx->pc = 0x11EC1Cu;
label_11ec1c:
    // 0x11ec1c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x11ec1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x11ec20: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x11EC20u;
    {
        const bool branch_taken_0x11ec20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EC24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EC20u;
            // 0x11ec24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ec20) {
            ctx->pc = 0x11EC78u;
            goto label_11ec78;
        }
    }
    ctx->pc = 0x11EC28u;
    // 0x11ec28: 0xc0479e8  jal         func_11E7A0
    ctx->pc = 0x11EC28u;
    SET_GPR_U32(ctx, 31, 0x11EC30u);
    ctx->pc = 0x11E7A0u;
    if (runtime->hasFunction(0x11E7A0u)) {
        auto targetFn = runtime->lookupFunction(0x11E7A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EC30u; }
        if (ctx->pc != 0x11EC30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E7A0_0x11e7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EC30u; }
        if (ctx->pc != 0x11EC30u) { return; }
    }
    ctx->pc = 0x11EC30u;
label_11ec30:
    // 0x11ec30: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x11ec30u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x11ec34: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11ec34u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ec38: 0xde040010  ld          $a0, 0x10($s0)
    ctx->pc = 0x11ec38u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x11ec3c: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11ec3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11ec40: 0xde030018  ld          $v1, 0x18($s0)
    ctx->pc = 0x11ec40u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x11ec44: 0x3442fffe  ori         $v0, $v0, 0xFFFE
    ctx->pc = 0x11ec44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65534);
    // 0x11ec48: 0x224202f  dsubu       $a0, $s1, $a0
    ctx->pc = 0x11ec48u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) - GPR_U64(ctx, 4));
    // 0x11ec4c: 0x30a60002  andi        $a2, $a1, 0x2
    ctx->pc = 0x11ec4cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)2);
    // 0x11ec50: 0x64182d  daddu       $v1, $v1, $a0
    ctx->pc = 0x11ec50u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 4));
    // 0x11ec54: 0xa22824  and         $a1, $a1, $v0
    ctx->pc = 0x11ec54u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x11ec58: 0xfe030018  sd          $v1, 0x18($s0)
    ctx->pc = 0x11ec58u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 24), GPR_U64(ctx, 3));
    // 0x11ec5c: 0x10c00005  beqz        $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x11EC5Cu;
    {
        const bool branch_taken_0x11ec5c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EC60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EC5Cu;
            // 0x11ec60: 0xae05000c  sw          $a1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ec5c) {
            ctx->pc = 0x11EC74u;
            goto label_11ec74;
        }
    }
    ctx->pc = 0x11EC64u;
    // 0x11ec64: 0xc047932  jal         func_11E4C8
    ctx->pc = 0x11EC64u;
    SET_GPR_U32(ctx, 31, 0x11EC6Cu);
    ctx->pc = 0x11EC68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EC64u;
            // 0x11ec68: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11E4C8u;
    if (runtime->hasFunction(0x11E4C8u)) {
        auto targetFn = runtime->lookupFunction(0x11E4C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EC6Cu; }
        if (ctx->pc != 0x11EC6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E4C8_0x11e4c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EC6Cu; }
        if (ctx->pc != 0x11EC6Cu) { return; }
    }
    ctx->pc = 0x11EC6Cu;
label_11ec6c:
    // 0x11ec6c: 0xc0478ac  jal         func_11E2B0
    ctx->pc = 0x11EC6Cu;
    SET_GPR_U32(ctx, 31, 0x11EC74u);
    ctx->pc = 0x11EC70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EC6Cu;
            // 0x11ec70: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11E2B0u;
    if (runtime->hasFunction(0x11E2B0u)) {
        auto targetFn = runtime->lookupFunction(0x11E2B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EC74u; }
        if (ctx->pc != 0x11EC74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E2B0_0x11e2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EC74u; }
        if (ctx->pc != 0x11EC74u) { return; }
    }
    ctx->pc = 0x11EC74u;
label_11ec74:
    // 0x11ec74: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11ec74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_11ec78:
    // 0x11ec78: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11ec78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11ec7c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ec7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ec80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ec80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ec84: 0x3e00008  jr          $ra
    ctx->pc = 0x11EC84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EC84u;
            // 0x11ec88: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EBC8u: goto label_11ebc8;
            case 0x11EBF4u: goto label_11ebf4;
            case 0x11EC00u: goto label_11ec00;
            case 0x11EC1Cu: goto label_11ec1c;
            case 0x11EC30u: goto label_11ec30;
            case 0x11EC6Cu: goto label_11ec6c;
            case 0x11EC74u: goto label_11ec74;
            case 0x11EC78u: goto label_11ec78;
            case 0x11ECA8u: goto label_11eca8;
            case 0x11ECB4u: goto label_11ecb4;
            case 0x11ECC4u: goto label_11ecc4;
            case 0x11ED0Cu: goto label_11ed0c;
            case 0x11ED34u: goto label_11ed34;
            case 0x11ED44u: goto label_11ed44;
            case 0x11ED4Cu: goto label_11ed4c;
            case 0x11ED60u: goto label_11ed60;
            case 0x11ED78u: goto label_11ed78;
            case 0x11ED7Cu: goto label_11ed7c;
            case 0x11ED8Cu: goto label_11ed8c;
            case 0x11ED90u: goto label_11ed90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EC8Cu;
    // 0x11ec8c: 0x0  nop
    ctx->pc = 0x11ec8cu;
    // NOP
    // 0x11ec90: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11ec90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11ec94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11ec94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11ec98: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11ec98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11ec9c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11ec9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11eca0: 0xc047598  jal         func_11D660
    ctx->pc = 0x11ECA0u;
    SET_GPR_U32(ctx, 31, 0x11ECA8u);
    ctx->pc = 0x11ECA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ECA0u;
            // 0x11eca4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECA8u; }
        if (ctx->pc != 0x11ECA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECA8u; }
        if (ctx->pc != 0x11ECA8u) { return; }
    }
    ctx->pc = 0x11ECA8u;
label_11eca8:
    // 0x11eca8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11eca8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ecac: 0xc047af2  jal         func_11EBC8
    ctx->pc = 0x11ECACu;
    SET_GPR_U32(ctx, 31, 0x11ECB4u);
    ctx->pc = 0x11ECB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ECACu;
            // 0x11ecb0: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EBC8u;
    goto label_11ebc8;
    ctx->pc = 0x11ECB4u;
label_11ecb4:
    // 0x11ecb4: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11ECB4u;
    {
        const bool branch_taken_0x11ecb4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ECB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ECB4u;
            // 0x11ecb8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ecb4) {
            ctx->pc = 0x11ECC4u;
            goto label_11ecc4;
        }
    }
    ctx->pc = 0x11ECBCu;
    // 0x11ecbc: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11ECBCu;
    SET_GPR_U32(ctx, 31, 0x11ECC4u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECC4u; }
        if (ctx->pc != 0x11ECC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECC4u; }
        if (ctx->pc != 0x11ECC4u) { return; }
    }
    ctx->pc = 0x11ECC4u;
label_11ecc4:
    // 0x11ecc4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11ecc4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ecc8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11ecc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11eccc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ecccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ecd0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ecd0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ecd4: 0x3e00008  jr          $ra
    ctx->pc = 0x11ECD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11ECD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ECD4u;
            // 0x11ecd8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EBC8u: goto label_11ebc8;
            case 0x11EBF4u: goto label_11ebf4;
            case 0x11EC00u: goto label_11ec00;
            case 0x11EC1Cu: goto label_11ec1c;
            case 0x11EC30u: goto label_11ec30;
            case 0x11EC6Cu: goto label_11ec6c;
            case 0x11EC74u: goto label_11ec74;
            case 0x11EC78u: goto label_11ec78;
            case 0x11ECA8u: goto label_11eca8;
            case 0x11ECB4u: goto label_11ecb4;
            case 0x11ECC4u: goto label_11ecc4;
            case 0x11ED0Cu: goto label_11ed0c;
            case 0x11ED34u: goto label_11ed34;
            case 0x11ED44u: goto label_11ed44;
            case 0x11ED4Cu: goto label_11ed4c;
            case 0x11ED60u: goto label_11ed60;
            case 0x11ED78u: goto label_11ed78;
            case 0x11ED7Cu: goto label_11ed7c;
            case 0x11ED8Cu: goto label_11ed8c;
            case 0x11ED90u: goto label_11ed90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11ECDCu;
    // 0x11ecdc: 0x0  nop
    ctx->pc = 0x11ecdcu;
    // NOP
    // 0x11ece0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11ece0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11ece4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11ece4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11ece8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11ece8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ecec: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11ececu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11ecf0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11ecf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11ecf4: 0x111282  srl         $v0, $s1, 10
    ctx->pc = 0x11ecf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 10));
    // 0x11ecf8: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11ecf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11ecfc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11ecfcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ed00: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11ed00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11ed04: 0xc047598  jal         func_11D660
    ctx->pc = 0x11ED04u;
    SET_GPR_U32(ctx, 31, 0x11ED0Cu);
    ctx->pc = 0x11ED08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED04u;
            // 0x11ed08: 0x28180  sll         $s0, $v0, 6 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED0Cu; }
        if (ctx->pc != 0x11ED0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED0Cu; }
        if (ctx->pc != 0x11ED0Cu) { return; }
    }
    ctx->pc = 0x11ED0Cu;
label_11ed0c:
    // 0x11ed0c: 0x6200009  bltz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x11ED0Cu;
    {
        const bool branch_taken_0x11ed0c = (GPR_S64(ctx, 17) < 0);
        ctx->pc = 0x11ED10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED0Cu;
            // 0x11ed10: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed0c) {
            ctx->pc = 0x11ED34u;
            goto label_11ed34;
        }
    }
    ctx->pc = 0x11ED14u;
    // 0x11ed14: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x11ed14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11ed18: 0x322203ff  andi        $v0, $s1, 0x3FF
    ctx->pc = 0x11ed18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1023);
    // 0x11ed1c: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x11ED1Cu;
    {
        const bool branch_taken_0x11ed1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x11ED20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED1Cu;
            // 0x11ed20: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed1c) {
            ctx->pc = 0x11ED34u;
            goto label_11ed34;
        }
    }
    ctx->pc = 0x11ED24u;
    // 0x11ed24: 0x2442b3e8  addiu       $v0, $v0, -0x4C18
    ctx->pc = 0x11ed24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947816));
    // 0x11ed28: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x11ed28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x11ed2c: 0x54710007  bnel        $v1, $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x11ED2Cu;
    {
        const bool branch_taken_0x11ed2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 17));
        if (branch_taken_0x11ed2c) {
            ctx->pc = 0x11ED30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED2Cu;
            // 0x11ed30: 0x8e02000c  lw          $v0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11ED4Cu;
            goto label_11ed4c;
        }
    }
    ctx->pc = 0x11ED34u;
label_11ed34:
    // 0x11ed34: 0x12600016  beqz        $s3, . + 4 + (0x16 << 2)
    ctx->pc = 0x11ED34u;
    {
        const bool branch_taken_0x11ed34 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED34u;
            // 0x11ed38: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed34) {
            ctx->pc = 0x11ED90u;
            goto label_11ed90;
        }
    }
    ctx->pc = 0x11ED3Cu;
    // 0x11ed3c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11ED3Cu;
    SET_GPR_U32(ctx, 31, 0x11ED44u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED44u; }
        if (ctx->pc != 0x11ED44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED44u; }
        if (ctx->pc != 0x11ED44u) { return; }
    }
    ctx->pc = 0x11ED44u;
label_11ed44:
    // 0x11ed44: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x11ED44u;
    {
        const bool branch_taken_0x11ed44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED44u;
            // 0x11ed48: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed44) {
            ctx->pc = 0x11ED90u;
            goto label_11ed90;
        }
    }
    ctx->pc = 0x11ED4Cu;
label_11ed4c:
    // 0x11ed4c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x11ed4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x11ed50: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x11ED50u;
    {
        const bool branch_taken_0x11ed50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED50u;
            // 0x11ed54: 0xde110018  ld          $s1, 0x18($s0) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed50) {
            ctx->pc = 0x11ED78u;
            goto label_11ed78;
        }
    }
    ctx->pc = 0x11ED58u;
    // 0x11ed58: 0xc0479e8  jal         func_11E7A0
    ctx->pc = 0x11ED58u;
    SET_GPR_U32(ctx, 31, 0x11ED60u);
    ctx->pc = 0x11E7A0u;
    if (runtime->hasFunction(0x11E7A0u)) {
        auto targetFn = runtime->lookupFunction(0x11E7A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED60u; }
        if (ctx->pc != 0x11ED60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E7A0_0x11e7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED60u; }
        if (ctx->pc != 0x11ED60u) { return; }
    }
    ctx->pc = 0x11ED60u;
label_11ed60:
    // 0x11ed60: 0xde030010  ld          $v1, 0x10($s0)
    ctx->pc = 0x11ed60u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x11ed64: 0xfe120018  sd          $s2, 0x18($s0)
    ctx->pc = 0x11ed64u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 24), GPR_U64(ctx, 18));
    // 0x11ed68: 0x43182f  dsubu       $v1, $v0, $v1
    ctx->pc = 0x11ed68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) - GPR_U64(ctx, 3));
    // 0x11ed6c: 0xfe020010  sd          $v0, 0x10($s0)
    ctx->pc = 0x11ed6cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 16), GPR_U64(ctx, 2));
    // 0x11ed70: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x11ED70u;
    {
        const bool branch_taken_0x11ed70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED70u;
            // 0x11ed74: 0x223882d  daddu       $s1, $s1, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed70) {
            ctx->pc = 0x11ED7Cu;
            goto label_11ed7c;
        }
    }
    ctx->pc = 0x11ED78u;
label_11ed78:
    // 0x11ed78: 0xfe120018  sd          $s2, 0x18($s0)
    ctx->pc = 0x11ed78u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 24), GPR_U64(ctx, 18));
label_11ed7c:
    // 0x11ed7c: 0x12600004  beqz        $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x11ED7Cu;
    {
        const bool branch_taken_0x11ed7c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED7Cu;
            // 0x11ed80: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed7c) {
            ctx->pc = 0x11ED90u;
            goto label_11ed90;
        }
    }
    ctx->pc = 0x11ED84u;
    // 0x11ed84: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11ED84u;
    SET_GPR_U32(ctx, 31, 0x11ED8Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED8Cu; }
        if (ctx->pc != 0x11ED8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED8Cu; }
        if (ctx->pc != 0x11ED8Cu) { return; }
    }
    ctx->pc = 0x11ED8Cu;
label_11ed8c:
    // 0x11ed8c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x11ed8cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_11ed90:
    // 0x11ed90: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11ed90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11ed94: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11ed94u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11ed98: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11ed98u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11ed9c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ed9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11eda0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11eda0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11eda4: 0x3e00008  jr          $ra
    ctx->pc = 0x11EDA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EDA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EDA4u;
            // 0x11eda8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EBC8u: goto label_11ebc8;
            case 0x11EBF4u: goto label_11ebf4;
            case 0x11EC00u: goto label_11ec00;
            case 0x11EC1Cu: goto label_11ec1c;
            case 0x11EC30u: goto label_11ec30;
            case 0x11EC6Cu: goto label_11ec6c;
            case 0x11EC74u: goto label_11ec74;
            case 0x11EC78u: goto label_11ec78;
            case 0x11ECA8u: goto label_11eca8;
            case 0x11ECB4u: goto label_11ecb4;
            case 0x11ECC4u: goto label_11ecc4;
            case 0x11ED0Cu: goto label_11ed0c;
            case 0x11ED34u: goto label_11ed34;
            case 0x11ED44u: goto label_11ed44;
            case 0x11ED4Cu: goto label_11ed4c;
            case 0x11ED60u: goto label_11ed60;
            case 0x11ED78u: goto label_11ed78;
            case 0x11ED7Cu: goto label_11ed7c;
            case 0x11ED8Cu: goto label_11ed8c;
            case 0x11ED90u: goto label_11ed90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EDACu;
    // 0x11edac: 0x0  nop
    ctx->pc = 0x11edacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
