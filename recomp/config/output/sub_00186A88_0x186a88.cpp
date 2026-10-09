#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186A88
// Address: 0x186a88 - 0x186ba8
void sub_00186A88_0x186a88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186A88_0x186a88");
#endif

    switch (ctx->pc) {
        case 0x186aa8u: goto label_186aa8;
        case 0x186af0u: goto label_186af0;
        case 0x186b00u: goto label_186b00;
        case 0x186b20u: goto label_186b20;
        case 0x186b4cu: goto label_186b4c;
        case 0x186b84u: goto label_186b84;
        default: break;
    }

    ctx->pc = 0x186a88u;

    // 0x186a88: 0x27bdfd50  addiu       $sp, $sp, -0x2B0
    ctx->pc = 0x186a88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966608));
    // 0x186a8c: 0xffb10298  sd          $s1, 0x298($sp)
    ctx->pc = 0x186a8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 664), GPR_U64(ctx, 17));
    // 0x186a90: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x186a90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186a94: 0xffb202a0  sd          $s2, 0x2A0($sp)
    ctx->pc = 0x186a94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 672), GPR_U64(ctx, 18));
    // 0x186a98: 0xffb00290  sd          $s0, 0x290($sp)
    ctx->pc = 0x186a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 656), GPR_U64(ctx, 16));
    // 0x186a9c: 0xffbf02a8  sd          $ra, 0x2A8($sp)
    ctx->pc = 0x186a9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 680), GPR_U64(ctx, 31));
    // 0x186aa0: 0xc062210  jal         func_188840
    ctx->pc = 0x186AA0u;
    SET_GPR_U32(ctx, 31, 0x186AA8u);
    ctx->pc = 0x186AA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186AA0u;
            // 0x186aa4: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186AA8u; }
        if (ctx->pc != 0x186AA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186AA8u; }
        if (ctx->pc != 0x186AA8u) { return; }
    }
    ctx->pc = 0x186AA8u;
label_186aa8:
    // 0x186aa8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x186AA8u;
    {
        const bool branch_taken_0x186aa8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186AA8u;
            // 0x186aac: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186aa8) {
            ctx->pc = 0x186AC0u;
            goto label_186ac0;
        }
    }
    ctx->pc = 0x186AB0u;
    // 0x186ab0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186ab4: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x186AB4u;
    {
        const bool branch_taken_0x186ab4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186AB4u;
            // 0x186ab8: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186ab4) {
            ctx->pc = 0x186B8Cu;
            goto label_186b8c;
        }
    }
    ctx->pc = 0x186ABCu;
    // 0x186abc: 0x0  nop
    ctx->pc = 0x186abcu;
    // NOP
label_186ac0:
    // 0x186ac0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186ac4: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x186ac4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x186ac8: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x186ac8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x186acc: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x186accu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x186ad0: 0x8c8463d4  lw          $a0, 0x63D4($a0)
    ctx->pc = 0x186ad0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 25556)));
    // 0x186ad4: 0x1080002d  beqz        $a0, . + 4 + (0x2D << 2)
    ctx->pc = 0x186AD4u;
    {
        const bool branch_taken_0x186ad4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x186AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186AD4u;
            // 0x186ad8: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186ad4) {
            ctx->pc = 0x186B8Cu;
            goto label_186b8c;
        }
    }
    ctx->pc = 0x186ADCu;
    // 0x186adc: 0x27b00200  addiu       $s0, $sp, 0x200
    ctx->pc = 0x186adcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
    // 0x186ae0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x186ae0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186ae4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x186ae4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186ae8: 0xc0609a2  jal         func_182688
    ctx->pc = 0x186AE8u;
    SET_GPR_U32(ctx, 31, 0x186AF0u);
    ctx->pc = 0x186AECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186AE8u;
            // 0x186aec: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182688u;
    if (runtime->hasFunction(0x182688u)) {
        auto targetFn = runtime->lookupFunction(0x182688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186AF0u; }
        if (ctx->pc != 0x186AF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182688_0x182688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186AF0u; }
        if (ctx->pc != 0x186AF0u) { return; }
    }
    ctx->pc = 0x186AF0u;
label_186af0:
    // 0x186af0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x186AF0u;
    {
        const bool branch_taken_0x186af0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x186af0) {
            ctx->pc = 0x186B08u;
            goto label_186b08;
        }
    }
    ctx->pc = 0x186AF8u;
    // 0x186af8: 0xc06089c  jal         func_182270
    ctx->pc = 0x186AF8u;
    SET_GPR_U32(ctx, 31, 0x186B00u);
    ctx->pc = 0x186AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186AF8u;
            // 0x186afc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182270u;
    if (runtime->hasFunction(0x182270u)) {
        auto targetFn = runtime->lookupFunction(0x182270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186B00u; }
        if (ctx->pc != 0x186B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182270_0x182270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186B00u; }
        if (ctx->pc != 0x186B00u) { return; }
    }
    ctx->pc = 0x186B00u;
label_186b00:
    // 0x186b00: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x186B00u;
    {
        const bool branch_taken_0x186b00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x186b00) {
            ctx->pc = 0x186B18u;
            goto label_186b18;
        }
    }
    ctx->pc = 0x186B08u;
label_186b08:
    // 0x186b08: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186b08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186b0c: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x186B0Cu;
    {
        const bool branch_taken_0x186b0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186B0Cu;
            // 0x186b10: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186b0c) {
            ctx->pc = 0x186B8Cu;
            goto label_186b8c;
        }
    }
    ctx->pc = 0x186B14u;
    // 0x186b14: 0x0  nop
    ctx->pc = 0x186b14u;
    // NOP
label_186b18:
    // 0x186b18: 0xc060880  jal         func_182200
    ctx->pc = 0x186B18u;
    SET_GPR_U32(ctx, 31, 0x186B20u);
    ctx->pc = 0x186B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186B18u;
            // 0x186b1c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182200u;
    if (runtime->hasFunction(0x182200u)) {
        auto targetFn = runtime->lookupFunction(0x182200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186B20u; }
        if (ctx->pc != 0x186B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182200_0x182200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186B20u; }
        if (ctx->pc != 0x186B20u) { return; }
    }
    ctx->pc = 0x186B20u;
label_186b20:
    // 0x186b20: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x186B20u;
    {
        const bool branch_taken_0x186b20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186B20u;
            // 0x186b24: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186b20) {
            ctx->pc = 0x186B38u;
            goto label_186b38;
        }
    }
    ctx->pc = 0x186B28u;
    // 0x186b28: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186b28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186b2c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x186B2Cu;
    {
        const bool branch_taken_0x186b2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186B2Cu;
            // 0x186b30: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186b2c) {
            ctx->pc = 0x186B8Cu;
            goto label_186b8c;
        }
    }
    ctx->pc = 0x186B34u;
    // 0x186b34: 0x0  nop
    ctx->pc = 0x186b34u;
    // NOP
label_186b38:
    // 0x186b38: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x186b38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186b3c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x186b3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186b40: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x186b40u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186b44: 0xc0610d8  jal         func_184360
    ctx->pc = 0x186B44u;
    SET_GPR_U32(ctx, 31, 0x186B4Cu);
    ctx->pc = 0x186B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186B44u;
            // 0x186b48: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186B4Cu; }
        if (ctx->pc != 0x186B4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186B4Cu; }
        if (ctx->pc != 0x186B4Cu) { return; }
    }
    ctx->pc = 0x186B4Cu;
label_186b4c:
    // 0x186b4c: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x186b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x186b50: 0x34630011  ori         $v1, $v1, 0x11
    ctx->pc = 0x186b50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17);
    // 0x186b54: 0x1443000d  bne         $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x186B54u;
    {
        const bool branch_taken_0x186b54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x186B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186B54u;
            // 0x186b58: 0xafa20280  sw          $v0, 0x280($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 640), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186b54) {
            ctx->pc = 0x186B8Cu;
            goto label_186b8c;
        }
    }
    ctx->pc = 0x186B5Cu;
    // 0x186b5c: 0x97a30000  lhu         $v1, 0x0($sp)
    ctx->pc = 0x186b5cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x186b60: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186b60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186b64: 0x30630020  andi        $v1, $v1, 0x20
    ctx->pc = 0x186b64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32);
    // 0x186b68: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x186B68u;
    {
        const bool branch_taken_0x186b68 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x186B6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186B68u;
            // 0x186b6c: 0x34420014  ori         $v0, $v0, 0x14 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)20);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186b68) {
            ctx->pc = 0x186B8Cu;
            goto label_186b8c;
        }
    }
    ctx->pc = 0x186B70u;
    // 0x186b70: 0x8fa50010  lw          $a1, 0x10($sp)
    ctx->pc = 0x186b70u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x186b74: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x186b74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186b78: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x186b78u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x186b7c: 0xc061318  jal         func_184C60
    ctx->pc = 0x186B7Cu;
    SET_GPR_U32(ctx, 31, 0x186B84u);
    ctx->pc = 0x186B80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186B7Cu;
            // 0x186b80: 0x27a70280  addiu       $a3, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184C60u;
    if (runtime->hasFunction(0x184C60u)) {
        auto targetFn = runtime->lookupFunction(0x184C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186B84u; }
        if (ctx->pc != 0x186B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184C60_0x184c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186B84u; }
        if (ctx->pc != 0x186B84u) { return; }
    }
    ctx->pc = 0x186B84u;
label_186b84:
    // 0x186b84: 0x8fa30280  lw          $v1, 0x280($sp)
    ctx->pc = 0x186b84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x186b88: 0x63100b  movn        $v0, $v1, $v1
    ctx->pc = 0x186b88u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
label_186b8c:
    // 0x186b8c: 0xdfb00290  ld          $s0, 0x290($sp)
    ctx->pc = 0x186b8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 656)));
    // 0x186b90: 0xdfb10298  ld          $s1, 0x298($sp)
    ctx->pc = 0x186b90u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 664)));
    // 0x186b94: 0xdfb202a0  ld          $s2, 0x2A0($sp)
    ctx->pc = 0x186b94u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 672)));
    // 0x186b98: 0xdfbf02a8  ld          $ra, 0x2A8($sp)
    ctx->pc = 0x186b98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 680)));
    // 0x186b9c: 0x3e00008  jr          $ra
    ctx->pc = 0x186B9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x186BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186B9Cu;
            // 0x186ba0: 0x27bd02b0  addiu       $sp, $sp, 0x2B0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 688));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x186AA8u: goto label_186aa8;
            case 0x186AC0u: goto label_186ac0;
            case 0x186AF0u: goto label_186af0;
            case 0x186B00u: goto label_186b00;
            case 0x186B08u: goto label_186b08;
            case 0x186B18u: goto label_186b18;
            case 0x186B20u: goto label_186b20;
            case 0x186B38u: goto label_186b38;
            case 0x186B4Cu: goto label_186b4c;
            case 0x186B84u: goto label_186b84;
            case 0x186B8Cu: goto label_186b8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x186BA4u;
    // 0x186ba4: 0x0  nop
    ctx->pc = 0x186ba4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
