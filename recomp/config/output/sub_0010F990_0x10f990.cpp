#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010F990
// Address: 0x10f990 - 0x10faa0
void sub_0010F990_0x10f990(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010F990_0x10f990");
#endif

    switch (ctx->pc) {
        case 0x10f9d0u: goto label_10f9d0;
        case 0x10fa14u: goto label_10fa14;
        case 0x10fa50u: goto label_10fa50;
        default: break;
    }

    ctx->pc = 0x10f990u;

    // 0x10f990: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10f990u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10f994: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10f994u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10f998: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10f998u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f99c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x10f99cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x10f9a0: 0x8e030054  lw          $v1, 0x54($s0)
    ctx->pc = 0x10f9a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10f9a4: 0x54600006  bnel        $v1, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x10F9A4u;
    {
        const bool branch_taken_0x10f9a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f9a4) {
            ctx->pc = 0x10F9A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F9A4u;
            // 0x10f9a8: 0x8c620038  lw          $v0, 0x38($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F9C0u;
            goto label_10f9c0;
        }
    }
    ctx->pc = 0x10F9ACu;
    // 0x10f9ac: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10f9acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x10f9b0: 0x8c4397f0  lw          $v1, -0x6810($v0)
    ctx->pc = 0x10f9b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10f9b4: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x10f9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x10f9b8: 0x8c620038  lw          $v0, 0x38($v1)
    ctx->pc = 0x10f9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
    // 0x10f9bc: 0x0  nop
    ctx->pc = 0x10f9bcu;
    // NOP
label_10f9c0:
    // 0x10f9c0: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x10F9C0u;
    {
        const bool branch_taken_0x10f9c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f9c0) {
            ctx->pc = 0x10F9C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F9C0u;
            // 0x10f9c4: 0x9604000c  lhu         $a0, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F9D4u;
            goto label_10f9d4;
        }
    }
    ctx->pc = 0x10F9C8u;
    // 0x10f9c8: 0xc041544  jal         func_105510
    ctx->pc = 0x10F9C8u;
    SET_GPR_U32(ctx, 31, 0x10F9D0u);
    ctx->pc = 0x10F9CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F9C8u;
            // 0x10f9cc: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105510u;
    if (runtime->hasFunction(0x105510u)) {
        auto targetFn = runtime->lookupFunction(0x105510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F9D0u; }
        if (ctx->pc != 0x10F9D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105510_0x105510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F9D0u; }
        if (ctx->pc != 0x10F9D0u) { return; }
    }
    ctx->pc = 0x10F9D0u;
label_10f9d0:
    // 0x10f9d0: 0x9604000c  lhu         $a0, 0xC($s0)
    ctx->pc = 0x10f9d0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_10f9d4:
    // 0x10f9d4: 0x30820008  andi        $v0, $a0, 0x8
    ctx->pc = 0x10f9d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8);
    // 0x10f9d8: 0x54400019  bnel        $v0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x10F9D8u;
    {
        const bool branch_taken_0x10f9d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f9d8) {
            ctx->pc = 0x10F9DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F9D8u;
            // 0x10f9dc: 0x8e050010  lw          $a1, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FA40u;
            goto label_10fa40;
        }
    }
    ctx->pc = 0x10F9E0u;
    // 0x10f9e0: 0x30830010  andi        $v1, $a0, 0x10
    ctx->pc = 0x10f9e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)16);
    // 0x10f9e4: 0x10600029  beqz        $v1, . + 4 + (0x29 << 2)
    ctx->pc = 0x10F9E4u;
    {
        const bool branch_taken_0x10f9e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F9E4u;
            // 0x10f9e8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f9e4) {
            ctx->pc = 0x10FA8Cu;
            goto label_10fa8c;
        }
    }
    ctx->pc = 0x10F9ECu;
    // 0x10f9ec: 0x30820004  andi        $v0, $a0, 0x4
    ctx->pc = 0x10f9ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)4);
    // 0x10f9f0: 0x50400011  beql        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x10F9F0u;
    {
        const bool branch_taken_0x10f9f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f9f0) {
            ctx->pc = 0x10F9F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F9F0u;
            // 0x10f9f4: 0x8e050010  lw          $a1, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FA38u;
            goto label_10fa38;
        }
    }
    ctx->pc = 0x10F9F8u;
    // 0x10f9f8: 0x8e050030  lw          $a1, 0x30($s0)
    ctx->pc = 0x10f9f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x10f9fc: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x10F9FCu;
    {
        const bool branch_taken_0x10f9fc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F9FCu;
            // 0x10fa00: 0x26020040  addiu       $v0, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f9fc) {
            ctx->pc = 0x10FA1Cu;
            goto label_10fa1c;
        }
    }
    ctx->pc = 0x10FA04u;
    // 0x10fa04: 0x50a20005  beql        $a1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10FA04u;
    {
        const bool branch_taken_0x10fa04 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x10fa04) {
            ctx->pc = 0x10FA08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FA04u;
            // 0x10fa08: 0xae000030  sw          $zero, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FA1Cu;
            goto label_10fa1c;
        }
    }
    ctx->pc = 0x10FA0Cu;
    // 0x10fa0c: 0xc041636  jal         func_1058D8
    ctx->pc = 0x10FA0Cu;
    SET_GPR_U32(ctx, 31, 0x10FA14u);
    ctx->pc = 0x10FA10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10FA0Cu;
            // 0x10fa10: 0x8e040054  lw          $a0, 0x54($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10FA14u; }
        if (ctx->pc != 0x10FA14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10FA14u; }
        if (ctx->pc != 0x10FA14u) { return; }
    }
    ctx->pc = 0x10FA14u;
label_10fa14:
    // 0x10fa14: 0x9604000c  lhu         $a0, 0xC($s0)
    ctx->pc = 0x10fa14u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10fa18: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x10fa18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
label_10fa1c:
    // 0x10fa1c: 0x2402ffdb  addiu       $v0, $zero, -0x25
    ctx->pc = 0x10fa1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967259));
    // 0x10fa20: 0x8e050010  lw          $a1, 0x10($s0)
    ctx->pc = 0x10fa20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x10fa24: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x10fa24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x10fa28: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x10fa28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x10fa2c: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x10fa2cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x10fa30: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10fa30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10fa34: 0xae050000  sw          $a1, 0x0($s0)
    ctx->pc = 0x10fa34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 5));
label_10fa38:
    // 0x10fa38: 0x34820008  ori         $v0, $a0, 0x8
    ctx->pc = 0x10fa38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8);
    // 0x10fa3c: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x10fa3cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
label_10fa40:
    // 0x10fa40: 0x54a00004  bnel        $a1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x10FA40u;
    {
        const bool branch_taken_0x10fa40 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x10fa40) {
            ctx->pc = 0x10FA44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10FA40u;
            // 0x10fa44: 0x9603000c  lhu         $v1, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10FA54u;
            goto label_10fa54;
        }
    }
    ctx->pc = 0x10FA48u;
    // 0x10fa48: 0xc041ad6  jal         func_106B58
    ctx->pc = 0x10FA48u;
    SET_GPR_U32(ctx, 31, 0x10FA50u);
    ctx->pc = 0x10FA4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10FA48u;
            // 0x10fa4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106B58u;
    if (runtime->hasFunction(0x106B58u)) {
        auto targetFn = runtime->lookupFunction(0x106B58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10FA50u; }
        if (ctx->pc != 0x10FA50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106B58_0x106b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10FA50u; }
        if (ctx->pc != 0x10FA50u) { return; }
    }
    ctx->pc = 0x10FA50u;
label_10fa50:
    // 0x10fa50: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x10fa50u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_10fa54:
    // 0x10fa54: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x10fa54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x10fa58: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10FA58u;
    {
        const bool branch_taken_0x10fa58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FA58u;
            // 0x10fa5c: 0x30620002  andi        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fa58) {
            ctx->pc = 0x10FA78u;
            goto label_10fa78;
        }
    }
    ctx->pc = 0x10FA60u;
    // 0x10fa60: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x10fa60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x10fa64: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x10fa64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x10fa68: 0x21023  negu        $v0, $v0
    ctx->pc = 0x10fa68u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x10fa6c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x10FA6Cu;
    {
        const bool branch_taken_0x10fa6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10FA70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FA6Cu;
            // 0x10fa70: 0xae020018  sw          $v0, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fa6c) {
            ctx->pc = 0x10FA88u;
            goto label_10fa88;
        }
    }
    ctx->pc = 0x10FA74u;
    // 0x10fa74: 0x0  nop
    ctx->pc = 0x10fa74u;
    // NOP
label_10fa78:
    // 0x10fa78: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x10FA78u;
    {
        const bool branch_taken_0x10fa78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10FA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FA78u;
            // 0x10fa7c: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10fa78) {
            ctx->pc = 0x10FA84u;
            goto label_10fa84;
        }
    }
    ctx->pc = 0x10FA80u;
    // 0x10fa80: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x10fa80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_10fa84:
    // 0x10fa84: 0xae030008  sw          $v1, 0x8($s0)
    ctx->pc = 0x10fa84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 3));
label_10fa88:
    // 0x10fa88: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10fa88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10fa8c:
    // 0x10fa8c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10fa8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10fa90: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x10fa90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10fa94: 0x3e00008  jr          $ra
    ctx->pc = 0x10FA94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10FA98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10FA94u;
            // 0x10fa98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10F9C0u: goto label_10f9c0;
            case 0x10F9D0u: goto label_10f9d0;
            case 0x10F9D4u: goto label_10f9d4;
            case 0x10FA14u: goto label_10fa14;
            case 0x10FA1Cu: goto label_10fa1c;
            case 0x10FA38u: goto label_10fa38;
            case 0x10FA40u: goto label_10fa40;
            case 0x10FA50u: goto label_10fa50;
            case 0x10FA54u: goto label_10fa54;
            case 0x10FA78u: goto label_10fa78;
            case 0x10FA84u: goto label_10fa84;
            case 0x10FA88u: goto label_10fa88;
            case 0x10FA8Cu: goto label_10fa8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10FA9Cu;
    // 0x10fa9c: 0x0  nop
    ctx->pc = 0x10fa9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
