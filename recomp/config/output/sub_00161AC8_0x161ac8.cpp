#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161AC8
// Address: 0x161ac8 - 0x161d20
void sub_00161AC8_0x161ac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161AC8_0x161ac8");
#endif

    switch (ctx->pc) {
        case 0x161b00u: goto label_161b00;
        case 0x161b30u: goto label_161b30;
        case 0x161b68u: goto label_161b68;
        case 0x161ba4u: goto label_161ba4;
        case 0x161bbcu: goto label_161bbc;
        case 0x161bccu: goto label_161bcc;
        case 0x161bf8u: goto label_161bf8;
        case 0x161c54u: goto label_161c54;
        case 0x161cacu: goto label_161cac;
        case 0x161cdcu: goto label_161cdc;
        case 0x161cf4u: goto label_161cf4;
        case 0x161d10u: goto label_161d10;
        default: break;
    }

    ctx->pc = 0x161ac8u;

    // 0x161ac8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x161ac8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x161acc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x161accu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x161ad0: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x161ad0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x161ad4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x161ad4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ad8: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x161ad8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x161adc: 0x26110100  addiu       $s1, $s0, 0x100
    ctx->pc = 0x161adcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
    // 0x161ae0: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x161ae0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x161ae4: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x161ae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x161ae8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x161ae8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x161aec: 0x8e1200e8  lw          $s2, 0xE8($s0)
    ctx->pc = 0x161aecu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x161af0: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x161af0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x161af4: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x161af4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x161af8: 0x40f809  jalr        $v0
    ctx->pc = 0x161AF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x161B00u);
        ctx->pc = 0x161AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161AF8u;
            // 0x161afc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x161B00u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161B00u: goto label_161b00;
            case 0x161B30u: goto label_161b30;
            case 0x161B38u: goto label_161b38;
            case 0x161B50u: goto label_161b50;
            case 0x161B68u: goto label_161b68;
            case 0x161BA4u: goto label_161ba4;
            case 0x161BBCu: goto label_161bbc;
            case 0x161BCCu: goto label_161bcc;
            case 0x161BD8u: goto label_161bd8;
            case 0x161BF8u: goto label_161bf8;
            case 0x161BFCu: goto label_161bfc;
            case 0x161C54u: goto label_161c54;
            case 0x161CACu: goto label_161cac;
            case 0x161CB8u: goto label_161cb8;
            case 0x161CDCu: goto label_161cdc;
            case 0x161CF4u: goto label_161cf4;
            case 0x161D00u: goto label_161d00;
            case 0x161D10u: goto label_161d10;
            case 0x161D14u: goto label_161d14;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x161B00u; }
            if (ctx->pc != 0x161B00u) { return; }
        }
        }
    }
    ctx->pc = 0x161B00u;
label_161b00:
    // 0x161b00: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x161b00u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x161b04: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x161b04u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x161b08: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x161b08u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161b0c: 0x24a5feb0  addiu       $a1, $a1, -0x150
    ctx->pc = 0x161b0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966960));
    // 0x161b10: 0x24c6feb8  addiu       $a2, $a2, -0x148
    ctx->pc = 0x161b10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294966968));
    // 0x161b14: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x161b14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161b18: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x161B18u;
    {
        const bool branch_taken_0x161b18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x161B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161B18u;
            // 0x161b1c: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161b18) {
            ctx->pc = 0x161B38u;
            goto label_161b38;
        }
    }
    ctx->pc = 0x161B20u;
    // 0x161b20: 0x8e0200ec  lw          $v0, 0xEC($s0)
    ctx->pc = 0x161b20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 236)));
    // 0x161b24: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x161b24u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x161b28: 0xc050288  jal         func_140A20
    ctx->pc = 0x161B28u;
    SET_GPR_U32(ctx, 31, 0x161B30u);
    ctx->pc = 0x161B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161B28u;
            // 0x161b2c: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140A20u;
    if (runtime->hasFunction(0x140A20u)) {
        auto targetFn = runtime->lookupFunction(0x140A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161B30u; }
        if (ctx->pc != 0x161B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140A20_0x140a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161B30u; }
        if (ctx->pc != 0x161B30u) { return; }
    }
    ctx->pc = 0x161B30u;
label_161b30:
    // 0x161b30: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x161B30u;
    {
        const bool branch_taken_0x161b30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161B30u;
            // 0x161b34: 0x261300f4  addiu       $s3, $s0, 0xF4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 244));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161b30) {
            ctx->pc = 0x161B50u;
            goto label_161b50;
        }
    }
    ctx->pc = 0x161B38u;
label_161b38:
    // 0x161b38: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x161b38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x161b3c: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x161b3cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x161b40: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x161b40u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x161b44: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x161B44u;
    {
        const bool branch_taken_0x161b44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161B44u;
            // 0x161b48: 0xae200008  sw          $zero, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161b44) {
            ctx->pc = 0x161BF8u;
            goto label_161bf8;
        }
    }
    ctx->pc = 0x161B4Cu;
    // 0x161b4c: 0x0  nop
    ctx->pc = 0x161b4cu;
    // NOP
label_161b50:
    // 0x161b50: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x161b50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x161b54: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x161B54u;
    {
        const bool branch_taken_0x161b54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x161B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161B54u;
            // 0x161b58: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161b54) {
            ctx->pc = 0x161BD8u;
            goto label_161bd8;
        }
    }
    ctx->pc = 0x161B5Cu;
    // 0x161b5c: 0x8fa50010  lw          $a1, 0x10($sp)
    ctx->pc = 0x161b5cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161b60: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x161B60u;
    SET_GPR_U32(ctx, 31, 0x161B68u);
    ctx->pc = 0x161B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161B60u;
            // 0x161b64: 0x8fa60014  lw          $a2, 0x14($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161B68u; }
        if (ctx->pc != 0x161B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161B68u; }
        if (ctx->pc != 0x161B68u) { return; }
    }
    ctx->pc = 0x161B68u;
label_161b68:
    // 0x161b68: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x161b68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x161b6c: 0x8fa50014  lw          $a1, 0x14($sp)
    ctx->pc = 0x161b6cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x161b70: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x161b70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x161b74: 0x8e470000  lw          $a3, 0x0($s2)
    ctx->pc = 0x161b74u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x161b78: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x161b78u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x161b7c: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x161b7cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x161b80: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x161b80u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x161b84: 0x8ce20018  lw          $v0, 0x18($a3)
    ctx->pc = 0x161b84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x161b88: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x161b88u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161b8c: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x161b8cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x161b90: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x161b90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161b94: 0xae250008  sw          $a1, 0x8($s1)
    ctx->pc = 0x161b94u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 5));
    // 0x161b98: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x161b98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x161b9c: 0x40f809  jalr        $v0
    ctx->pc = 0x161B9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x161BA4u);
        ctx->pc = 0x161BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161B9Cu;
            // 0x161ba0: 0x34c6ffff  ori         $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x161BA4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161B00u: goto label_161b00;
            case 0x161B30u: goto label_161b30;
            case 0x161B38u: goto label_161b38;
            case 0x161B50u: goto label_161b50;
            case 0x161B68u: goto label_161b68;
            case 0x161BA4u: goto label_161ba4;
            case 0x161BBCu: goto label_161bbc;
            case 0x161BCCu: goto label_161bcc;
            case 0x161BD8u: goto label_161bd8;
            case 0x161BF8u: goto label_161bf8;
            case 0x161BFCu: goto label_161bfc;
            case 0x161C54u: goto label_161c54;
            case 0x161CACu: goto label_161cac;
            case 0x161CB8u: goto label_161cb8;
            case 0x161CDCu: goto label_161cdc;
            case 0x161CF4u: goto label_161cf4;
            case 0x161D00u: goto label_161d00;
            case 0x161D10u: goto label_161d10;
            case 0x161D14u: goto label_161d14;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x161BA4u; }
            if (ctx->pc != 0x161BA4u) { return; }
        }
        }
    }
    ctx->pc = 0x161BA4u;
label_161ba4:
    // 0x161ba4: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x161ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x161ba8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x161ba8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161bac: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x161bacu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161bb0: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x161bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x161bb4: 0x40f809  jalr        $v0
    ctx->pc = 0x161BB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x161BBCu);
        ctx->pc = 0x161BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161BB4u;
            // 0x161bb8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x161BBCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161B00u: goto label_161b00;
            case 0x161B30u: goto label_161b30;
            case 0x161B38u: goto label_161b38;
            case 0x161B50u: goto label_161b50;
            case 0x161B68u: goto label_161b68;
            case 0x161BA4u: goto label_161ba4;
            case 0x161BBCu: goto label_161bbc;
            case 0x161BCCu: goto label_161bcc;
            case 0x161BD8u: goto label_161bd8;
            case 0x161BF8u: goto label_161bf8;
            case 0x161BFCu: goto label_161bfc;
            case 0x161C54u: goto label_161c54;
            case 0x161CACu: goto label_161cac;
            case 0x161CB8u: goto label_161cb8;
            case 0x161CDCu: goto label_161cdc;
            case 0x161CF4u: goto label_161cf4;
            case 0x161D00u: goto label_161d00;
            case 0x161D10u: goto label_161d10;
            case 0x161D14u: goto label_161d14;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x161BBCu; }
            if (ctx->pc != 0x161BBCu) { return; }
        }
        }
    }
    ctx->pc = 0x161BBCu;
label_161bbc:
    // 0x161bbc: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x161bbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x161bc0: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x161bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x161bc4: 0x40f809  jalr        $v0
    ctx->pc = 0x161BC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x161BCCu);
        ctx->pc = 0x161BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161BC4u;
            // 0x161bc8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x161BCCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161B00u: goto label_161b00;
            case 0x161B30u: goto label_161b30;
            case 0x161B38u: goto label_161b38;
            case 0x161B50u: goto label_161b50;
            case 0x161B68u: goto label_161b68;
            case 0x161BA4u: goto label_161ba4;
            case 0x161BBCu: goto label_161bbc;
            case 0x161BCCu: goto label_161bcc;
            case 0x161BD8u: goto label_161bd8;
            case 0x161BF8u: goto label_161bf8;
            case 0x161BFCu: goto label_161bfc;
            case 0x161C54u: goto label_161c54;
            case 0x161CACu: goto label_161cac;
            case 0x161CB8u: goto label_161cb8;
            case 0x161CDCu: goto label_161cdc;
            case 0x161CF4u: goto label_161cf4;
            case 0x161D00u: goto label_161d00;
            case 0x161D10u: goto label_161d10;
            case 0x161D14u: goto label_161d14;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x161BCCu; }
            if (ctx->pc != 0x161BCCu) { return; }
        }
        }
    }
    ctx->pc = 0x161BCCu;
label_161bcc:
    // 0x161bcc: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x161BCCu;
    {
        const bool branch_taken_0x161bcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161BCCu;
            // 0x161bd0: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161bcc) {
            ctx->pc = 0x161BFCu;
            goto label_161bfc;
        }
    }
    ctx->pc = 0x161BD4u;
    // 0x161bd4: 0x0  nop
    ctx->pc = 0x161bd4u;
    // NOP
label_161bd8:
    // 0x161bd8: 0x8fa50014  lw          $a1, 0x14($sp)
    ctx->pc = 0x161bd8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x161bdc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x161bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x161be0: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x161be0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161be4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161be4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161be8: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x161be8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x161bec: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x161becu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x161bf0: 0xc058748  jal         func_161D20
    ctx->pc = 0x161BF0u;
    SET_GPR_U32(ctx, 31, 0x161BF8u);
    ctx->pc = 0x161BF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161BF0u;
            // 0x161bf4: 0xae250008  sw          $a1, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161D20u;
    if (runtime->hasFunction(0x161D20u)) {
        auto targetFn = runtime->lookupFunction(0x161D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161BF8u; }
        if (ctx->pc != 0x161BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00161D20_0x161d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161BF8u; }
        if (ctx->pc != 0x161BF8u) { return; }
    }
    ctx->pc = 0x161BF8u;
label_161bf8:
    // 0x161bf8: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x161bf8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_161bfc:
    // 0x161bfc: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x161bfcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x161c00: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x161c00u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x161c04: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x161c04u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x161c08: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x161c08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x161c0c: 0x3e00008  jr          $ra
    ctx->pc = 0x161C0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161C0Cu;
            // 0x161c10: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161B00u: goto label_161b00;
            case 0x161B30u: goto label_161b30;
            case 0x161B38u: goto label_161b38;
            case 0x161B50u: goto label_161b50;
            case 0x161B68u: goto label_161b68;
            case 0x161BA4u: goto label_161ba4;
            case 0x161BBCu: goto label_161bbc;
            case 0x161BCCu: goto label_161bcc;
            case 0x161BD8u: goto label_161bd8;
            case 0x161BF8u: goto label_161bf8;
            case 0x161BFCu: goto label_161bfc;
            case 0x161C54u: goto label_161c54;
            case 0x161CACu: goto label_161cac;
            case 0x161CB8u: goto label_161cb8;
            case 0x161CDCu: goto label_161cdc;
            case 0x161CF4u: goto label_161cf4;
            case 0x161D00u: goto label_161d00;
            case 0x161D10u: goto label_161d10;
            case 0x161D14u: goto label_161d14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161C14u;
    // 0x161c14: 0x0  nop
    ctx->pc = 0x161c14u;
    // NOP
    // 0x161c18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x161c18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x161c1c: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x161c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x161c20: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x161c20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161c24: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x161c24u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161c28: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x161c28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x161c2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161c2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161c30: 0x51102a  slt         $v0, $v0, $s1
    ctx->pc = 0x161c30u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x161c34: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x161c34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x161c38: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x161c38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x161c3c: 0x249000f4  addiu       $s0, $a0, 0xF4
    ctx->pc = 0x161c3cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 244));
    // 0x161c40: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x161C40u;
    {
        const bool branch_taken_0x161c40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161C40u;
            // 0x161c44: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161c40) {
            ctx->pc = 0x161C54u;
            goto label_161c54;
        }
    }
    ctx->pc = 0x161C48u;
    // 0x161c48: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161c48u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161c4c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161C4Cu;
    SET_GPR_U32(ctx, 31, 0x161C54u);
    ctx->pc = 0x161C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161C4Cu;
            // 0x161c50: 0x2484fec0  addiu       $a0, $a0, -0x140 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161C54u; }
        if (ctx->pc != 0x161C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161C54u; }
        if (ctx->pc != 0x161C54u) { return; }
    }
    ctx->pc = 0x161C54u;
label_161c54:
    // 0x161c54: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x161c54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x161c58: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x161c58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x161c5c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161c5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161c60: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161c60u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161c64: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161c64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161c68: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x161c68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161c6c: 0x3e00008  jr          $ra
    ctx->pc = 0x161C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161C6Cu;
            // 0x161c70: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161B00u: goto label_161b00;
            case 0x161B30u: goto label_161b30;
            case 0x161B38u: goto label_161b38;
            case 0x161B50u: goto label_161b50;
            case 0x161B68u: goto label_161b68;
            case 0x161BA4u: goto label_161ba4;
            case 0x161BBCu: goto label_161bbc;
            case 0x161BCCu: goto label_161bcc;
            case 0x161BD8u: goto label_161bd8;
            case 0x161BF8u: goto label_161bf8;
            case 0x161BFCu: goto label_161bfc;
            case 0x161C54u: goto label_161c54;
            case 0x161CACu: goto label_161cac;
            case 0x161CB8u: goto label_161cb8;
            case 0x161CDCu: goto label_161cdc;
            case 0x161CF4u: goto label_161cf4;
            case 0x161D00u: goto label_161d00;
            case 0x161D10u: goto label_161d10;
            case 0x161D14u: goto label_161d14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161C74u;
    // 0x161c74: 0x0  nop
    ctx->pc = 0x161c74u;
    // NOP
    // 0x161c78: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x161c78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x161c7c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x161c7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161c80: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x161c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x161c84: 0x24430100  addiu       $v1, $v0, 0x100
    ctx->pc = 0x161c84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
    // 0x161c88: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x161c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x161c8c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x161c8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161c90: 0x8c680004  lw          $t0, 0x4($v1)
    ctx->pc = 0x161c90u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x161c94: 0x15000008  bnez        $t0, . + 4 + (0x8 << 2)
    ctx->pc = 0x161C94u;
    {
        const bool branch_taken_0x161c94 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x161C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161C94u;
            // 0x161c98: 0x8c5000a8  lw          $s0, 0xA8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 168)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161c94) {
            ctx->pc = 0x161CB8u;
            goto label_161cb8;
        }
    }
    ctx->pc = 0x161C9Cu;
    // 0x161c9c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161c9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ca0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x161ca0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ca4: 0xc05f4be  jal         func_17D2F8
    ctx->pc = 0x161CA4u;
    SET_GPR_U32(ctx, 31, 0x161CACu);
    ctx->pc = 0x161CA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161CA4u;
            // 0x161ca8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D2F8u;
    if (runtime->hasFunction(0x17D2F8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CACu; }
        if (ctx->pc != 0x161CACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D2F8_0x17d2f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CACu; }
        if (ctx->pc != 0x161CACu) { return; }
    }
    ctx->pc = 0x161CACu;
label_161cac:
    // 0x161cac: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x161CACu;
    {
        const bool branch_taken_0x161cac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161CB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161CACu;
            // 0x161cb0: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161cac) {
            ctx->pc = 0x161D14u;
            goto label_161d14;
        }
    }
    ctx->pc = 0x161CB4u;
    // 0x161cb4: 0x0  nop
    ctx->pc = 0x161cb4u;
    // NOP
label_161cb8:
    // 0x161cb8: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x161cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x161cbc: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x161cbcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x161cc0: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x161cc0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x161cc4: 0x24a5fef8  addiu       $a1, $a1, -0x108
    ctx->pc = 0x161cc4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967032));
    // 0x161cc8: 0x24c6ff00  addiu       $a2, $a2, -0x100
    ctx->pc = 0x161cc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967040));
    // 0x161ccc: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x161cccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x161cd0: 0xafa80000  sw          $t0, 0x0($sp)
    ctx->pc = 0x161cd0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 8));
    // 0x161cd4: 0xc050288  jal         func_140A20
    ctx->pc = 0x161CD4u;
    SET_GPR_U32(ctx, 31, 0x161CDCu);
    ctx->pc = 0x161CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161CD4u;
            // 0x161cd8: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140A20u;
    if (runtime->hasFunction(0x140A20u)) {
        auto targetFn = runtime->lookupFunction(0x140A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CDCu; }
        if (ctx->pc != 0x161CDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140A20_0x140a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CDCu; }
        if (ctx->pc != 0x161CDCu) { return; }
    }
    ctx->pc = 0x161CDCu;
label_161cdc:
    // 0x161cdc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161cdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ce0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x161ce0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ce4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x161CE4u;
    {
        const bool branch_taken_0x161ce4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161CE4u;
            // 0x161ce8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161ce4) {
            ctx->pc = 0x161D00u;
            goto label_161d00;
        }
    }
    ctx->pc = 0x161CECu;
    // 0x161cec: 0xc05f4be  jal         func_17D2F8
    ctx->pc = 0x161CECu;
    SET_GPR_U32(ctx, 31, 0x161CF4u);
    ctx->pc = 0x17D2F8u;
    if (runtime->hasFunction(0x17D2F8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CF4u; }
        if (ctx->pc != 0x161CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D2F8_0x17d2f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CF4u; }
        if (ctx->pc != 0x161CF4u) { return; }
    }
    ctx->pc = 0x161CF4u;
label_161cf4:
    // 0x161cf4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x161CF4u;
    {
        const bool branch_taken_0x161cf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161CF4u;
            // 0x161cf8: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161cf4) {
            ctx->pc = 0x161D14u;
            goto label_161d14;
        }
    }
    ctx->pc = 0x161CFCu;
    // 0x161cfc: 0x0  nop
    ctx->pc = 0x161cfcu;
    // NOP
label_161d00:
    // 0x161d00: 0x8fa50010  lw          $a1, 0x10($sp)
    ctx->pc = 0x161d00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161d04: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161d04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161d08: 0xc05f4be  jal         func_17D2F8
    ctx->pc = 0x161D08u;
    SET_GPR_U32(ctx, 31, 0x161D10u);
    ctx->pc = 0x161D0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161D08u;
            // 0x161d0c: 0x8fa60014  lw          $a2, 0x14($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D2F8u;
    if (runtime->hasFunction(0x17D2F8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161D10u; }
        if (ctx->pc != 0x161D10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D2F8_0x17d2f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161D10u; }
        if (ctx->pc != 0x161D10u) { return; }
    }
    ctx->pc = 0x161D10u;
label_161d10:
    // 0x161d10: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x161d10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_161d14:
    // 0x161d14: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x161d14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x161d18: 0x3e00008  jr          $ra
    ctx->pc = 0x161D18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161D18u;
            // 0x161d1c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161B00u: goto label_161b00;
            case 0x161B30u: goto label_161b30;
            case 0x161B38u: goto label_161b38;
            case 0x161B50u: goto label_161b50;
            case 0x161B68u: goto label_161b68;
            case 0x161BA4u: goto label_161ba4;
            case 0x161BBCu: goto label_161bbc;
            case 0x161BCCu: goto label_161bcc;
            case 0x161BD8u: goto label_161bd8;
            case 0x161BF8u: goto label_161bf8;
            case 0x161BFCu: goto label_161bfc;
            case 0x161C54u: goto label_161c54;
            case 0x161CACu: goto label_161cac;
            case 0x161CB8u: goto label_161cb8;
            case 0x161CDCu: goto label_161cdc;
            case 0x161CF4u: goto label_161cf4;
            case 0x161D00u: goto label_161d00;
            case 0x161D10u: goto label_161d10;
            case 0x161D14u: goto label_161d14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161D20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
