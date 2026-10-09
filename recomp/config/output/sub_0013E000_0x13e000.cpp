#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013E000
// Address: 0x13e000 - 0x13e2b8
void sub_0013E000_0x13e000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013E000_0x13e000");
#endif

    switch (ctx->pc) {
        case 0x13e040u: goto label_13e040;
        case 0x13e1f0u: goto label_13e1f0;
        default: break;
    }

    ctx->pc = 0x13e000u;

    // 0x13e000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13e000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13e004: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13e004u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13e008: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13e008u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13e00c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x13e00cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e010: 0x24423880  addiu       $v0, $v0, 0x3880
    ctx->pc = 0x13e010u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14464));
    // 0x13e014: 0x260d0010  addiu       $t5, $s0, 0x10
    ctx->pc = 0x13e014u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x13e018: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13e018u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13e01c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13e01cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13e020: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x13e020u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e024: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x13e024u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e028: 0x24710498  addiu       $s1, $v1, 0x498
    ctx->pc = 0x13e028u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 1176));
    // 0x13e02c: 0x782d  daddu       $t7, $zero, $zero
    ctx->pc = 0x13e02cu;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e030: 0x24190001  addiu       $t9, $zero, 0x1
    ctx->pc = 0x13e030u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e034: 0x24180002  addiu       $t8, $zero, 0x2
    ctx->pc = 0x13e034u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13e038: 0x244e0008  addiu       $t6, $v0, 0x8
    ctx->pc = 0x13e038u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x13e03c: 0x1a0302d  daddu       $a2, $t5, $zero
    ctx->pc = 0x13e03cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
label_13e040:
    // 0x13e040: 0x80e20000  lb          $v0, 0x0($a3)
    ctx->pc = 0x13e040u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x13e044: 0x54590093  bnel        $v0, $t9, . + 4 + (0x93 << 2)
    ctx->pc = 0x13E044u;
    {
        const bool branch_taken_0x13e044 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 25));
        if (branch_taken_0x13e044) {
            ctx->pc = 0x13E048u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E044u;
            // 0x13e048: 0x25ef0001  addiu       $t7, $t7, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E294u;
            goto label_13e294;
        }
    }
    ctx->pc = 0x13E04Cu;
    // 0x13e04c: 0x24080080  addiu       $t0, $zero, 0x80
    ctx->pc = 0x13e04cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x13e050: 0x51480095  beql        $t2, $t0, . + 4 + (0x95 << 2)
    ctx->pc = 0x13E050u;
    {
        const bool branch_taken_0x13e050 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e050) {
            ctx->pc = 0x13E054u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E050u;
            // 0x13e054: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E058u;
    // 0x13e058: 0x80e30053  lb          $v1, 0x53($a3)
    ctx->pc = 0x13e058u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 83)));
    // 0x13e05c: 0x80e20052  lb          $v0, 0x52($a3)
    ctx->pc = 0x13e05cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 82)));
    // 0x13e060: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x13E060u;
    {
        const bool branch_taken_0x13e060 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E060u;
            // 0x13e064: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e060) {
            ctx->pc = 0x13E08Cu;
            goto label_13e08c;
        }
    }
    ctx->pc = 0x13E068u;
    // 0x13e068: 0x8ce30020  lw          $v1, 0x20($a3)
    ctx->pc = 0x13e068u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e06c: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x13e06cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x13e070: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e070u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e074: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x13e074u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x13e078: 0x80e20053  lb          $v0, 0x53($a3)
    ctx->pc = 0x13e078u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 83)));
    // 0x13e07c: 0xacc20008  sw          $v0, 0x8($a2)
    ctx->pc = 0x13e07cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 2));
    // 0x13e080: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e080u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e084: 0x90e20053  lbu         $v0, 0x53($a3)
    ctx->pc = 0x13e084u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 83)));
    // 0x13e088: 0xa0e20052  sb          $v0, 0x52($a3)
    ctx->pc = 0x13e088u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 82), (uint8_t)GPR_U32(ctx, 2));
label_13e08c:
    // 0x13e08c: 0x11480085  beq         $t2, $t0, . + 4 + (0x85 << 2)
    ctx->pc = 0x13E08Cu;
    {
        const bool branch_taken_0x13e08c = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        ctx->pc = 0x13E090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E08Cu;
            // 0x13e090: 0x24020100  addiu       $v0, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e08c) {
            ctx->pc = 0x13E2A4u;
            goto label_13e2a4;
        }
    }
    ctx->pc = 0x13E094u;
    // 0x13e094: 0x94e30024  lhu         $v1, 0x24($a3)
    ctx->pc = 0x13e094u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e098: 0x1462000a  bne         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x13E098u;
    {
        const bool branch_taken_0x13e098 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13e098) {
            ctx->pc = 0x13E0C4u;
            goto label_13e0c4;
        }
    }
    ctx->pc = 0x13E0A0u;
    // 0x13e0a0: 0x8ce20020  lw          $v0, 0x20($a3)
    ctx->pc = 0x13e0a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e0a4: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e0a4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e0a8: 0xa4d80000  sh          $t8, 0x0($a2)
    ctx->pc = 0x13e0a8u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 24));
    // 0x13e0ac: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x13e0acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x13e0b0: 0x80e30024  lb          $v1, 0x24($a3)
    ctx->pc = 0x13e0b0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e0b4: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x13e0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x13e0b8: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e0b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e0bc: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x13e0bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e0c0: 0xa0e20025  sb          $v0, 0x25($a3)
    ctx->pc = 0x13e0c0u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 37), (uint8_t)GPR_U32(ctx, 2));
label_13e0c4:
    // 0x13e0c4: 0x51480078  beql        $t2, $t0, . + 4 + (0x78 << 2)
    ctx->pc = 0x13E0C4u;
    {
        const bool branch_taken_0x13e0c4 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e0c4) {
            ctx->pc = 0x13E0C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E0C4u;
            // 0x13e0c8: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E0CCu;
    // 0x13e0cc: 0x8ce30048  lw          $v1, 0x48($a3)
    ctx->pc = 0x13e0ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 72)));
    // 0x13e0d0: 0x8ce2004c  lw          $v0, 0x4C($a3)
    ctx->pc = 0x13e0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 76)));
    // 0x13e0d4: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13E0D4u;
    {
        const bool branch_taken_0x13e0d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E0D4u;
            // 0x13e0d8: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e0d4) {
            ctx->pc = 0x13E0FCu;
            goto label_13e0fc;
        }
    }
    ctx->pc = 0x13E0DCu;
    // 0x13e0dc: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x13e0dcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x13e0e0: 0x8ce40020  lw          $a0, 0x20($a3)
    ctx->pc = 0x13e0e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e0e4: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e0e4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e0e8: 0x8ce30048  lw          $v1, 0x48($a3)
    ctx->pc = 0x13e0e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 72)));
    // 0x13e0ec: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x13e0ecu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x13e0f0: 0xace3004c  sw          $v1, 0x4C($a3)
    ctx->pc = 0x13e0f0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 76), GPR_U32(ctx, 3));
    // 0x13e0f4: 0xacc40004  sw          $a0, 0x4($a2)
    ctx->pc = 0x13e0f4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 4));
    // 0x13e0f8: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e0f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
label_13e0fc:
    // 0x13e0fc: 0x5148006a  beql        $t2, $t0, . + 4 + (0x6A << 2)
    ctx->pc = 0x13E0FCu;
    {
        const bool branch_taken_0x13e0fc = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e0fc) {
            ctx->pc = 0x13E100u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E0FCu;
            // 0x13e100: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E104u;
    // 0x13e104: 0x80e30026  lb          $v1, 0x26($a3)
    ctx->pc = 0x13e104u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e108: 0x80e20027  lb          $v0, 0x27($a3)
    ctx->pc = 0x13e108u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 39)));
    // 0x13e10c: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x13E10Cu;
    {
        const bool branch_taken_0x13e10c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E10Cu;
            // 0x13e110: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e10c) {
            ctx->pc = 0x13E138u;
            goto label_13e138;
        }
    }
    ctx->pc = 0x13E114u;
    // 0x13e114: 0x8ce30020  lw          $v1, 0x20($a3)
    ctx->pc = 0x13e114u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e118: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x13e118u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x13e11c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e11cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e120: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x13e120u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x13e124: 0x80e20026  lb          $v0, 0x26($a3)
    ctx->pc = 0x13e124u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e128: 0xacc20008  sw          $v0, 0x8($a2)
    ctx->pc = 0x13e128u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 2));
    // 0x13e12c: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e12cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e130: 0x90e20026  lbu         $v0, 0x26($a3)
    ctx->pc = 0x13e130u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e134: 0xa0e20027  sb          $v0, 0x27($a3)
    ctx->pc = 0x13e134u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 39), (uint8_t)GPR_U32(ctx, 2));
label_13e138:
    // 0x13e138: 0x5148005b  beql        $t2, $t0, . + 4 + (0x5B << 2)
    ctx->pc = 0x13E138u;
    {
        const bool branch_taken_0x13e138 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e138) {
            ctx->pc = 0x13E13Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E138u;
            // 0x13e13c: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E140u;
    // 0x13e140: 0x8ce30028  lw          $v1, 0x28($a3)
    ctx->pc = 0x13e140u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x13e144: 0x8ce2002c  lw          $v0, 0x2C($a3)
    ctx->pc = 0x13e144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x13e148: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13E148u;
    {
        const bool branch_taken_0x13e148 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E14Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E148u;
            // 0x13e14c: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e148) {
            ctx->pc = 0x13E170u;
            goto label_13e170;
        }
    }
    ctx->pc = 0x13E150u;
    // 0x13e150: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x13e150u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x13e154: 0x8ce40020  lw          $a0, 0x20($a3)
    ctx->pc = 0x13e154u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e158: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e158u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e15c: 0x8ce30028  lw          $v1, 0x28($a3)
    ctx->pc = 0x13e15cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x13e160: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x13e160u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x13e164: 0xace3002c  sw          $v1, 0x2C($a3)
    ctx->pc = 0x13e164u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 44), GPR_U32(ctx, 3));
    // 0x13e168: 0xacc40004  sw          $a0, 0x4($a2)
    ctx->pc = 0x13e168u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 4));
    // 0x13e16c: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e16cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
label_13e170:
    // 0x13e170: 0x5148004d  beql        $t2, $t0, . + 4 + (0x4D << 2)
    ctx->pc = 0x13E170u;
    {
        const bool branch_taken_0x13e170 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e170) {
            ctx->pc = 0x13E174u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E170u;
            // 0x13e174: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E178u;
    // 0x13e178: 0x8ce30030  lw          $v1, 0x30($a3)
    ctx->pc = 0x13e178u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x13e17c: 0x8ce20034  lw          $v0, 0x34($a3)
    ctx->pc = 0x13e17cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x13e180: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13E180u;
    {
        const bool branch_taken_0x13e180 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E180u;
            // 0x13e184: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e180) {
            ctx->pc = 0x13E1B8u;
            goto label_13e1b8;
        }
    }
    ctx->pc = 0x13E188u;
    // 0x13e188: 0x8ce50020  lw          $a1, 0x20($a3)
    ctx->pc = 0x13e188u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e18c: 0x2221023  subu        $v0, $s1, $v0
    ctx->pc = 0x13e18cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x13e190: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x13e190u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x13e194: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x13e194u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13e198: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e198u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e19c: 0xacc00008  sw          $zero, 0x8($a2)
    ctx->pc = 0x13e19cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 0));
    // 0x13e1a0: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x13e1a0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x13e1a4: 0xa4c40000  sh          $a0, 0x0($a2)
    ctx->pc = 0x13e1a4u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x13e1a8: 0x8ce20030  lw          $v0, 0x30($a3)
    ctx->pc = 0x13e1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x13e1ac: 0xacc50004  sw          $a1, 0x4($a2)
    ctx->pc = 0x13e1acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 5));
    // 0x13e1b0: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e1b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e1b4: 0xace20034  sw          $v0, 0x34($a3)
    ctx->pc = 0x13e1b4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 52), GPR_U32(ctx, 2));
label_13e1b8:
    // 0x13e1b8: 0x1148003a  beq         $t2, $t0, . + 4 + (0x3A << 2)
    ctx->pc = 0x13E1B8u;
    {
        const bool branch_taken_0x13e1b8 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        ctx->pc = 0x13E1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E1B8u;
            // 0x13e1bc: 0x2402007f  addiu       $v0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e1b8) {
            ctx->pc = 0x13E2A4u;
            goto label_13e2a4;
        }
    }
    ctx->pc = 0x13E1C0u;
    // 0x13e1c0: 0x51420039  beql        $t2, $v0, . + 4 + (0x39 << 2)
    ctx->pc = 0x13E1C0u;
    {
        const bool branch_taken_0x13e1c0 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 2));
        if (branch_taken_0x13e1c0) {
            ctx->pc = 0x13E1C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E1C0u;
            // 0x13e1c4: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E1C8u;
    // 0x13e1c8: 0x80e20026  lb          $v0, 0x26($a3)
    ctx->pc = 0x13e1c8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e1cc: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x13e1ccu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e1d0: 0x1840001e  blez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x13E1D0u;
    {
        const bool branch_taken_0x13e1d0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13E1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E1D0u;
            // 0x13e1d4: 0x90e90026  lbu         $t1, 0x26($a3) (Delay Slot)
        SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e1d0) {
            ctx->pc = 0x13E24Cu;
            goto label_13e24c;
        }
    }
    ctx->pc = 0x13E1D8u;
    // 0x13e1d8: 0xa1100  sll         $v0, $t2, 4
    ctx->pc = 0x13e1d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 4));
    // 0x13e1dc: 0x240c0009  addiu       $t4, $zero, 0x9
    ctx->pc = 0x13e1dcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x13e1e0: 0x4d2021  addu        $a0, $v0, $t5
    ctx->pc = 0x13e1e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 13)));
    // 0x13e1e4: 0x24e80040  addiu       $t0, $a3, 0x40
    ctx->pc = 0x13e1e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x13e1e8: 0x25c50030  addiu       $a1, $t6, 0x30
    ctx->pc = 0x13e1e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 14), 48));
    // 0x13e1ec: 0x0  nop
    ctx->pc = 0x13e1ecu;
    // NOP
label_13e1f0:
    // 0x13e1f0: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x13e1f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x13e1f4: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x13e1f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x13e1f8: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x13E1F8u;
    {
        const bool branch_taken_0x13e1f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E1FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E1F8u;
            // 0x13e1fc: 0x91600  sll         $v0, $t1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e1f8) {
            ctx->pc = 0x13E234u;
            goto label_13e234;
        }
    }
    ctx->pc = 0x13E200u;
    // 0x13e200: 0xac8b0008  sw          $t3, 0x8($a0)
    ctx->pc = 0x13e200u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 11));
    // 0x13e204: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e204u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e208: 0x8ce30020  lw          $v1, 0x20($a3)
    ctx->pc = 0x13e208u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e20c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e20cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e210: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x13e210u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x13e214: 0xa48c0000  sh          $t4, 0x0($a0)
    ctx->pc = 0x13e214u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 12));
    // 0x13e218: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x13e218u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x13e21c: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x13e21cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x13e220: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x13e220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x13e224: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x13e224u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x13e228: 0xad020000  sw          $v0, 0x0($t0)
    ctx->pc = 0x13e228u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 2));
    // 0x13e22c: 0x90e90026  lbu         $t1, 0x26($a3)
    ctx->pc = 0x13e22cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e230: 0x91600  sll         $v0, $t1, 24
    ctx->pc = 0x13e230u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 24));
label_13e234:
    // 0x13e234: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x13e234u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x13e238: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x13e238u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x13e23c: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x13e23cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x13e240: 0x162102a  slt         $v0, $t3, $v0
    ctx->pc = 0x13e240u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 11) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13e244: 0x1440ffea  bnez        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x13E244u;
    {
        const bool branch_taken_0x13e244 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E244u;
            // 0x13e248: 0x24a50004  addiu       $a1, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e244) {
            ctx->pc = 0x13E1F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e1f0;
        }
    }
    ctx->pc = 0x13E24Cu;
label_13e24c:
    // 0x13e24c: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x13e24cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x13e250: 0x51440015  beql        $t2, $a0, . + 4 + (0x15 << 2)
    ctx->pc = 0x13E250u;
    {
        const bool branch_taken_0x13e250 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 4));
        if (branch_taken_0x13e250) {
            ctx->pc = 0x13E254u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E250u;
            // 0x13e254: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E258u;
    // 0x13e258: 0x94e20024  lhu         $v0, 0x24($a3)
    ctx->pc = 0x13e258u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e25c: 0x1459000a  bne         $v0, $t9, . + 4 + (0xA << 2)
    ctx->pc = 0x13E25Cu;
    {
        const bool branch_taken_0x13e25c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 25));
        if (branch_taken_0x13e25c) {
            ctx->pc = 0x13E288u;
            goto label_13e288;
        }
    }
    ctx->pc = 0x13E264u;
    // 0x13e264: 0x8ce20020  lw          $v0, 0x20($a3)
    ctx->pc = 0x13e264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e268: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e268u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e26c: 0xa4d80000  sh          $t8, 0x0($a2)
    ctx->pc = 0x13e26cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 24));
    // 0x13e270: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x13e270u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x13e274: 0x80e30024  lb          $v1, 0x24($a3)
    ctx->pc = 0x13e274u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e278: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x13e278u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x13e27c: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e27cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e280: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x13e280u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e284: 0xa0e20025  sb          $v0, 0x25($a3)
    ctx->pc = 0x13e284u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 37), (uint8_t)GPR_U32(ctx, 2));
label_13e288:
    // 0x13e288: 0x51440007  beql        $t2, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13E288u;
    {
        const bool branch_taken_0x13e288 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 4));
        if (branch_taken_0x13e288) {
            ctx->pc = 0x13E28Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E288u;
            // 0x13e28c: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E290u;
    // 0x13e290: 0x25ef0001  addiu       $t7, $t7, 0x1
    ctx->pc = 0x13e290u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
label_13e294:
    // 0x13e294: 0x25ce0060  addiu       $t6, $t6, 0x60
    ctx->pc = 0x13e294u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 96));
    // 0x13e298: 0x29e20010  slti        $v0, $t7, 0x10
    ctx->pc = 0x13e298u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 15) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13e29c: 0x1440ff68  bnez        $v0, . + 4 + (-0x98 << 2)
    ctx->pc = 0x13E29Cu;
    {
        const bool branch_taken_0x13e29c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E29Cu;
            // 0x13e2a0: 0x24e70060  addiu       $a3, $a3, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e29c) {
            ctx->pc = 0x13E040u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e040;
        }
    }
    ctx->pc = 0x13E2A4u;
label_13e2a4:
    // 0x13e2a4: 0xae0a0000  sw          $t2, 0x0($s0)
    ctx->pc = 0x13e2a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
label_13e2a8:
    // 0x13e2a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13e2a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e2ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e2acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e2b0: 0x3e00008  jr          $ra
    ctx->pc = 0x13E2B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E2B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E2B0u;
            // 0x13e2b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E040u: goto label_13e040;
            case 0x13E08Cu: goto label_13e08c;
            case 0x13E0C4u: goto label_13e0c4;
            case 0x13E0FCu: goto label_13e0fc;
            case 0x13E138u: goto label_13e138;
            case 0x13E170u: goto label_13e170;
            case 0x13E1B8u: goto label_13e1b8;
            case 0x13E1F0u: goto label_13e1f0;
            case 0x13E234u: goto label_13e234;
            case 0x13E24Cu: goto label_13e24c;
            case 0x13E288u: goto label_13e288;
            case 0x13E294u: goto label_13e294;
            case 0x13E2A4u: goto label_13e2a4;
            case 0x13E2A8u: goto label_13e2a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E2B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
