#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180AA0
// Address: 0x180aa0 - 0x180b88
void sub_00180AA0_0x180aa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180AA0_0x180aa0");
#endif

    switch (ctx->pc) {
        case 0x180ab8u: goto label_180ab8;
        default: break;
    }

    ctx->pc = 0x180aa0u;

    // 0x180aa0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x180aa0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180aa4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x180aa4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180aa8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x180aa8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180aac: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x180aacu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180ab0: 0x240a0008  addiu       $t2, $zero, 0x8
    ctx->pc = 0x180ab0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x180ab4: 0x0  nop
    ctx->pc = 0x180ab4u;
    // NOP
label_180ab8:
    // 0x180ab8: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x180ab8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x180abc: 0x1021007  srav        $v0, $v0, $t0
    ctx->pc = 0x180abcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 8) & 0x1F));
    // 0x180ac0: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x180ac0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x180ac4: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x180AC4u;
    {
        const bool branch_taken_0x180ac4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x180AC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180AC4u;
            // 0x180ac8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180ac4) {
            ctx->pc = 0x180B18u;
            goto label_180b18;
        }
    }
    ctx->pc = 0x180ACCu;
    // 0x180acc: 0x24c2fff0  addiu       $v0, $a2, -0x10
    ctx->pc = 0x180accu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967280));
    // 0x180ad0: 0x2c420010  sltiu       $v0, $v0, 0x10
    ctx->pc = 0x180ad0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x180ad4: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x180ad4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x180ad8: 0xaca90008  sw          $t1, 0x8($a1)
    ctx->pc = 0x180ad8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 9));
    // 0x180adc: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x180ADCu;
    {
        const bool branch_taken_0x180adc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x180AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180ADCu;
            // 0x180ae0: 0xaca7000c  sw          $a3, 0xC($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180adc) {
            ctx->pc = 0x180AF4u;
            goto label_180af4;
        }
    }
    ctx->pc = 0x180AE4u;
    // 0x180ae4: 0x24c2ffdd  addiu       $v0, $a2, -0x23
    ctx->pc = 0x180ae4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967261));
    // 0x180ae8: 0x2c420004  sltiu       $v0, $v0, 0x4
    ctx->pc = 0x180ae8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x180aec: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x180AECu;
    {
        const bool branch_taken_0x180aec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x180aec) {
            ctx->pc = 0x180AF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x180AECu;
            // 0x180af0: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x180B00u;
            goto label_180b00;
        }
    }
    ctx->pc = 0x180AF4u;
label_180af4:
    // 0x180af4: 0xacaa0004  sw          $t2, 0x4($a1)
    ctx->pc = 0x180af4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 10));
    // 0x180af8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x180AF8u;
    {
        const bool branch_taken_0x180af8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x180AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180AF8u;
            // 0x180afc: 0x25290001  addiu       $t1, $t1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180af8) {
            ctx->pc = 0x180B24u;
            goto label_180b24;
        }
    }
    ctx->pc = 0x180B00u;
label_180b00:
    // 0x180b00: 0x30e20007  andi        $v0, $a3, 0x7
    ctx->pc = 0x180b00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)7);
    // 0x180b04: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x180B04u;
    {
        const bool branch_taken_0x180b04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x180B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180B04u;
            // 0x180b08: 0xaca30004  sw          $v1, 0x4($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180b04) {
            ctx->pc = 0x180B24u;
            goto label_180b24;
        }
    }
    ctx->pc = 0x180B0Cu;
    // 0x180b0c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x180b0cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x180b10: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x180B10u;
    {
        const bool branch_taken_0x180b10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x180B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180B10u;
            // 0x180b14: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180b10) {
            ctx->pc = 0x180B24u;
            goto label_180b24;
        }
    }
    ctx->pc = 0x180B18u;
label_180b18:
    // 0x180b18: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x180b18u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x180b1c: 0xaca00008  sw          $zero, 0x8($a1)
    ctx->pc = 0x180b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 0));
    // 0x180b20: 0xaca0000c  sw          $zero, 0xC($a1)
    ctx->pc = 0x180b20u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 0));
label_180b24:
    // 0x180b24: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x180b24u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x180b28: 0x31020007  andi        $v0, $t0, 0x7
    ctx->pc = 0x180b28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)7);
    // 0x180b2c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x180B2Cu;
    {
        const bool branch_taken_0x180b2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x180B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180B2Cu;
            // 0x180b30: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180b2c) {
            ctx->pc = 0x180B3Cu;
            goto label_180b3c;
        }
    }
    ctx->pc = 0x180B34u;
    // 0x180b34: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x180b34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x180b38: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x180b38u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_180b3c:
    // 0x180b3c: 0x28c20028  slti        $v0, $a2, 0x28
    ctx->pc = 0x180b3cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)40) ? 1 : 0);
    // 0x180b40: 0x1440ffdd  bnez        $v0, . + 4 + (-0x23 << 2)
    ctx->pc = 0x180B40u;
    {
        const bool branch_taken_0x180b40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x180B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180B40u;
            // 0x180b44: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180b40) {
            ctx->pc = 0x180AB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_180ab8;
        }
    }
    ctx->pc = 0x180B48u;
    // 0x180b48: 0x3e00008  jr          $ra
    ctx->pc = 0x180B48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180B48u;
            // 0x180b4c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180AB8u: goto label_180ab8;
            case 0x180AF4u: goto label_180af4;
            case 0x180B00u: goto label_180b00;
            case 0x180B18u: goto label_180b18;
            case 0x180B24u: goto label_180b24;
            case 0x180B3Cu: goto label_180b3c;
            case 0x180B78u: goto label_180b78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180B50u;
    // 0x180b50: 0x2c820004  sltiu       $v0, $a0, 0x4
    ctx->pc = 0x180b50u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x180b54: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x180B54u;
    {
        const bool branch_taken_0x180b54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x180B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180B54u;
            // 0x180b58: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180b54) {
            ctx->pc = 0x180B78u;
            goto label_180b78;
        }
    }
    ctx->pc = 0x180B5Cu;
    // 0x180b5c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x180b5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x180b60: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x180b60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x180b64: 0x2442f9f0  addiu       $v0, $v0, -0x610
    ctx->pc = 0x180b64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965744));
    // 0x180b68: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x180b68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180b6c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x180b6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x180b70: 0x8042bf0  j           func_10AFC0
    ctx->pc = 0x180B70u;
    ctx->pc = 0x180B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180B70u;
            // 0x180b74: 0x8c650000  lw          $a1, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x180B78u;
label_180b78:
    // 0x180b78: 0x904315f8  lbu         $v1, 0x15F8($v0)
    ctx->pc = 0x180b78u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 5624)));
    // 0x180b7c: 0x3e00008  jr          $ra
    ctx->pc = 0x180B7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180B7Cu;
            // 0x180b80: 0xa0a30000  sb          $v1, 0x0($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180AB8u: goto label_180ab8;
            case 0x180AF4u: goto label_180af4;
            case 0x180B00u: goto label_180b00;
            case 0x180B18u: goto label_180b18;
            case 0x180B24u: goto label_180b24;
            case 0x180B3Cu: goto label_180b3c;
            case 0x180B78u: goto label_180b78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180B84u;
    // 0x180b84: 0x0  nop
    ctx->pc = 0x180b84u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
