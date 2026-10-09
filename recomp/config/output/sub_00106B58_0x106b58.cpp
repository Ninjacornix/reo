#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106B58
// Address: 0x106b58 - 0x106d18
void sub_00106B58_0x106b58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106B58_0x106b58");
#endif

    switch (ctx->pc) {
        case 0x106bb0u: goto label_106bb0;
        case 0x106c20u: goto label_106c20;
        case 0x106c80u: goto label_106c80;
        case 0x106cdcu: goto label_106cdc;
        case 0x106cecu: goto label_106cec;
        case 0x106cf8u: goto label_106cf8;
        default: break;
    }

    ctx->pc = 0x106b58u;

    // 0x106b58: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x106b58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x106b5c: 0xffb00070  sd          $s0, 0x70($sp)
    ctx->pc = 0x106b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 16));
    // 0x106b60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x106b60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106b64: 0xffb10078  sd          $s1, 0x78($sp)
    ctx->pc = 0x106b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 17));
    // 0x106b68: 0xffb20080  sd          $s2, 0x80($sp)
    ctx->pc = 0x106b68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 18));
    // 0x106b6c: 0xffbf0088  sd          $ra, 0x88($sp)
    ctx->pc = 0x106b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 31));
    // 0x106b70: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x106b70u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x106b74: 0x30620002  andi        $v0, $v1, 0x2
    ctx->pc = 0x106b74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2);
    // 0x106b78: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x106B78u;
    {
        const bool branch_taken_0x106b78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x106B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106B78u;
            // 0x106b7c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106b78) {
            ctx->pc = 0x106B98u;
            goto label_106b98;
        }
    }
    ctx->pc = 0x106B80u;
    // 0x106b80: 0x26030043  addiu       $v1, $s0, 0x43
    ctx->pc = 0x106b80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 67));
    // 0x106b84: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x106b84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x106b88: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x106b88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x106b8c: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x106B8Cu;
    {
        const bool branch_taken_0x106b8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106B90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106B8Cu;
            // 0x106b90: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106b8c) {
            ctx->pc = 0x106C94u;
            goto label_106c94;
        }
    }
    ctx->pc = 0x106B94u;
    // 0x106b94: 0x0  nop
    ctx->pc = 0x106b94u;
    // NOP
label_106b98:
    // 0x106b98: 0x8605000e  lh          $a1, 0xE($s0)
    ctx->pc = 0x106b98u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x106b9c: 0x4a00008  bltz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x106B9Cu;
    {
        const bool branch_taken_0x106b9c = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x106BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106B9Cu;
            // 0x106ba0: 0x34620800  ori         $v0, $v1, 0x800 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2048);
        ctx->in_delay_slot = false;
        if (branch_taken_0x106b9c) {
            ctx->pc = 0x106BC0u;
            goto label_106bc0;
        }
    }
    ctx->pc = 0x106BA4u;
    // 0x106ba4: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x106ba4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x106ba8: 0xc04187c  jal         func_1061F0
    ctx->pc = 0x106BA8u;
    SET_GPR_U32(ctx, 31, 0x106BB0u);
    ctx->pc = 0x106BACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106BA8u;
            // 0x106bac: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1061F0u;
    if (runtime->hasFunction(0x1061F0u)) {
        auto targetFn = runtime->lookupFunction(0x1061F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106BB0u; }
        if (ctx->pc != 0x106BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001061F0_0x1061f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106BB0u; }
        if (ctx->pc != 0x106BB0u) { return; }
    }
    ctx->pc = 0x106BB0u;
label_106bb0:
    // 0x106bb0: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x106BB0u;
    {
        const bool branch_taken_0x106bb0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x106BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106BB0u;
            // 0x106bb4: 0x8fa20004  lw          $v0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106bb0) {
            ctx->pc = 0x106BD0u;
            goto label_106bd0;
        }
    }
    ctx->pc = 0x106BB8u;
    // 0x106bb8: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x106bb8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x106bbc: 0x34620800  ori         $v0, $v1, 0x800
    ctx->pc = 0x106bbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2048);
label_106bc0:
    // 0x106bc0: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x106bc0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106bc4: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x106bc4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x106bc8: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x106BC8u;
    {
        const bool branch_taken_0x106bc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106BC8u;
            // 0x106bcc: 0x24110400  addiu       $s1, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106bc8) {
            ctx->pc = 0x106C14u;
            goto label_106c14;
        }
    }
    ctx->pc = 0x106BD0u;
label_106bd0:
    // 0x106bd0: 0x34048000  ori         $a0, $zero, 0x8000
    ctx->pc = 0x106bd0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x106bd4: 0x24110400  addiu       $s1, $zero, 0x400
    ctx->pc = 0x106bd4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x106bd8: 0x3042f000  andi        $v0, $v0, 0xF000
    ctx->pc = 0x106bd8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)61440);
    // 0x106bdc: 0x38432000  xori        $v1, $v0, 0x2000
    ctx->pc = 0x106bdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)8192);
    // 0x106be0: 0x14440009  bne         $v0, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x106BE0u;
    {
        const bool branch_taken_0x106be0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x106BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106BE0u;
            // 0x106be4: 0x2c720001  sltiu       $s2, $v1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 18, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x106be0) {
            ctx->pc = 0x106C08u;
            goto label_106c08;
        }
    }
    ctx->pc = 0x106BE8u;
    // 0x106be8: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x106be8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x106bec: 0x8e030028  lw          $v1, 0x28($s0)
    ctx->pc = 0x106becu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x106bf0: 0x2442aa58  addiu       $v0, $v0, -0x55A8
    ctx->pc = 0x106bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294945368));
    // 0x106bf4: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x106BF4u;
    {
        const bool branch_taken_0x106bf4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x106BF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106BF4u;
            // 0x106bf8: 0x9602000c  lhu         $v0, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106bf4) {
            ctx->pc = 0x106C0Cu;
            goto label_106c0c;
        }
    }
    ctx->pc = 0x106BFCu;
    // 0x106bfc: 0xae11004c  sw          $s1, 0x4C($s0)
    ctx->pc = 0x106bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 17));
    // 0x106c00: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x106C00u;
    {
        const bool branch_taken_0x106c00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106C00u;
            // 0x106c04: 0x34420400  ori         $v0, $v0, 0x400 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1024);
        ctx->in_delay_slot = false;
        if (branch_taken_0x106c00) {
            ctx->pc = 0x106C10u;
            goto label_106c10;
        }
    }
    ctx->pc = 0x106C08u;
label_106c08:
    // 0x106c08: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x106c08u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_106c0c:
    // 0x106c0c: 0x34420800  ori         $v0, $v0, 0x800
    ctx->pc = 0x106c0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2048);
label_106c10:
    // 0x106c10: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x106c10u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
label_106c14:
    // 0x106c14: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x106c14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x106c18: 0xc041c76  jal         func_1071D8
    ctx->pc = 0x106C18u;
    SET_GPR_U32(ctx, 31, 0x106C20u);
    ctx->pc = 0x106C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106C18u;
            // 0x106c1c: 0x24050400  addiu       $a1, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1071D8u;
    if (runtime->hasFunction(0x1071D8u)) {
        auto targetFn = runtime->lookupFunction(0x1071D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106C20u; }
        if (ctx->pc != 0x106C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001071D8_0x1071d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106C20u; }
        if (ctx->pc != 0x106C20u) { return; }
    }
    ctx->pc = 0x106C20u;
label_106c20:
    // 0x106c20: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x106c20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106c24: 0x14a0000a  bnez        $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x106C24u;
    {
        const bool branch_taken_0x106c24 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x106C28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106C24u;
            // 0x106c28: 0x9602000c  lhu         $v0, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106c24) {
            ctx->pc = 0x106C50u;
            goto label_106c50;
        }
    }
    ctx->pc = 0x106C2Cu;
    // 0x106c2c: 0x26040043  addiu       $a0, $s0, 0x43
    ctx->pc = 0x106c2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 67));
    // 0x106c30: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x106c30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x106c34: 0xae040010  sw          $a0, 0x10($s0)
    ctx->pc = 0x106c34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 4));
    // 0x106c38: 0x34420002  ori         $v0, $v0, 0x2
    ctx->pc = 0x106c38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
    // 0x106c3c: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x106c3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x106c40: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x106c40u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x106c44: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x106C44u;
    {
        const bool branch_taken_0x106c44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106C44u;
            // 0x106c48: 0xae040000  sw          $a0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106c44) {
            ctx->pc = 0x106C94u;
            goto label_106c94;
        }
    }
    ctx->pc = 0x106C4Cu;
    // 0x106c4c: 0x0  nop
    ctx->pc = 0x106c4cu;
    // NOP
label_106c50:
    // 0x106c50: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x106c50u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
    // 0x106c54: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x106c54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x106c58: 0x246354d0  addiu       $v1, $v1, 0x54D0
    ctx->pc = 0x106c58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 21712));
    // 0x106c5c: 0x34420080  ori         $v0, $v0, 0x80
    ctx->pc = 0x106c5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
    // 0x106c60: 0xae050010  sw          $a1, 0x10($s0)
    ctx->pc = 0x106c60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 5));
    // 0x106c64: 0xac83003c  sw          $v1, 0x3C($a0)
    ctx->pc = 0x106c64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 3));
    // 0x106c68: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x106c68u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x106c6c: 0xae110014  sw          $s1, 0x14($s0)
    ctx->pc = 0x106c6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 17));
    // 0x106c70: 0x12400008  beqz        $s2, . + 4 + (0x8 << 2)
    ctx->pc = 0x106C70u;
    {
        const bool branch_taken_0x106c70 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x106C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106C70u;
            // 0x106c74: 0xae050000  sw          $a1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106c70) {
            ctx->pc = 0x106C94u;
            goto label_106c94;
        }
    }
    ctx->pc = 0x106C78u;
    // 0x106c78: 0xc045374  jal         func_114DD0
    ctx->pc = 0x106C78u;
    SET_GPR_U32(ctx, 31, 0x106C80u);
    ctx->pc = 0x106C7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106C78u;
            // 0x106c7c: 0x8604000e  lh          $a0, 0xE($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114DD0u;
    if (runtime->hasFunction(0x114DD0u)) {
        auto targetFn = runtime->lookupFunction(0x114DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106C80u; }
        if (ctx->pc != 0x106C80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114DD0_0x114dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106C80u; }
        if (ctx->pc != 0x106C80u) { return; }
    }
    ctx->pc = 0x106C80u;
label_106c80:
    // 0x106c80: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x106C80u;
    {
        const bool branch_taken_0x106c80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x106c80) {
            ctx->pc = 0x106C84u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106C80u;
            // 0x106c84: 0xdfb00070  ld          $s0, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106C98u;
            goto label_106c98;
        }
    }
    ctx->pc = 0x106C88u;
    // 0x106c88: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x106c88u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x106c8c: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x106c8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x106c90: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x106c90u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
label_106c94:
    // 0x106c94: 0xdfb00070  ld          $s0, 0x70($sp)
    ctx->pc = 0x106c94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_106c98:
    // 0x106c98: 0xdfb10078  ld          $s1, 0x78($sp)
    ctx->pc = 0x106c98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x106c9c: 0xdfb20080  ld          $s2, 0x80($sp)
    ctx->pc = 0x106c9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x106ca0: 0xdfbf0088  ld          $ra, 0x88($sp)
    ctx->pc = 0x106ca0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x106ca4: 0x3e00008  jr          $ra
    ctx->pc = 0x106CA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106CA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106CA4u;
            // 0x106ca8: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106B98u: goto label_106b98;
            case 0x106BB0u: goto label_106bb0;
            case 0x106BC0u: goto label_106bc0;
            case 0x106BD0u: goto label_106bd0;
            case 0x106C08u: goto label_106c08;
            case 0x106C0Cu: goto label_106c0c;
            case 0x106C10u: goto label_106c10;
            case 0x106C14u: goto label_106c14;
            case 0x106C20u: goto label_106c20;
            case 0x106C50u: goto label_106c50;
            case 0x106C80u: goto label_106c80;
            case 0x106C94u: goto label_106c94;
            case 0x106C98u: goto label_106c98;
            case 0x106CDCu: goto label_106cdc;
            case 0x106CECu: goto label_106cec;
            case 0x106CF8u: goto label_106cf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106CACu;
    // 0x106cac: 0x0  nop
    ctx->pc = 0x106cacu;
    // NOP
    // 0x106cb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x106cb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x106cb4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x106cb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106cb8: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x106cb8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x106cbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106cbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106cc0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x106cc0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106cc4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x106cc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x106cc8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x106cc8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ccc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x106cccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x106cd0: 0x261097f0  addiu       $s0, $s0, -0x6810
    ctx->pc = 0x106cd0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294940656));
    // 0x106cd4: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x106CD4u;
    SET_GPR_U32(ctx, 31, 0x106CDCu);
    ctx->pc = 0x106CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106CD4u;
            // 0x106cd8: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CDCu; }
        if (ctx->pc != 0x106CDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CDCu; }
        if (ctx->pc != 0x106CDCu) { return; }
    }
    ctx->pc = 0x106CDCu;
label_106cdc:
    // 0x106cdc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x106cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106ce0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x106ce0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ce4: 0xc041b46  jal         func_106D18
    ctx->pc = 0x106CE4u;
    SET_GPR_U32(ctx, 31, 0x106CECu);
    ctx->pc = 0x106CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106CE4u;
            // 0x106ce8: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106D18u;
    if (runtime->hasFunction(0x106D18u)) {
        auto targetFn = runtime->lookupFunction(0x106D18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CECu; }
        if (ctx->pc != 0x106CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106D18_0x106d18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CECu; }
        if (ctx->pc != 0x106CECu) { return; }
    }
    ctx->pc = 0x106CECu;
label_106cec:
    // 0x106cec: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x106cecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106cf0: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x106CF0u;
    SET_GPR_U32(ctx, 31, 0x106CF8u);
    ctx->pc = 0x106CF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106CF0u;
            // 0x106cf4: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CF8u; }
        if (ctx->pc != 0x106CF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106CF8u; }
        if (ctx->pc != 0x106CF8u) { return; }
    }
    ctx->pc = 0x106CF8u;
label_106cf8:
    // 0x106cf8: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x106cf8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106cfc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106cfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106d00: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x106d00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106d04: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x106d04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106d08: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x106d08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x106d0c: 0x3e00008  jr          $ra
    ctx->pc = 0x106D0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106D0Cu;
            // 0x106d10: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106B98u: goto label_106b98;
            case 0x106BB0u: goto label_106bb0;
            case 0x106BC0u: goto label_106bc0;
            case 0x106BD0u: goto label_106bd0;
            case 0x106C08u: goto label_106c08;
            case 0x106C0Cu: goto label_106c0c;
            case 0x106C10u: goto label_106c10;
            case 0x106C14u: goto label_106c14;
            case 0x106C20u: goto label_106c20;
            case 0x106C50u: goto label_106c50;
            case 0x106C80u: goto label_106c80;
            case 0x106C94u: goto label_106c94;
            case 0x106C98u: goto label_106c98;
            case 0x106CDCu: goto label_106cdc;
            case 0x106CECu: goto label_106cec;
            case 0x106CF8u: goto label_106cf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106D14u;
    // 0x106d14: 0x0  nop
    ctx->pc = 0x106d14u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
