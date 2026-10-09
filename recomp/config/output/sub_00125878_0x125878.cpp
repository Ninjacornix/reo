#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125878
// Address: 0x125878 - 0x125c08
void sub_00125878_0x125878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125878_0x125878");
#endif

    switch (ctx->pc) {
        case 0x125a00u: goto label_125a00;
        case 0x125ac4u: goto label_125ac4;
        case 0x125ae4u: goto label_125ae4;
        case 0x125b40u: goto label_125b40;
        case 0x125b80u: goto label_125b80;
        case 0x125be4u: goto label_125be4;
        default: break;
    }

    ctx->pc = 0x125878u;

label_125878:
    // 0x125878: 0x80602d  daddu       $t4, $a0, $zero
    ctx->pc = 0x125878u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12587c: 0x240f0001  addiu       $t7, $zero, 0x1
    ctx->pc = 0x12587cu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x125880: 0x91820007  lbu         $v0, 0x7($t4)
    ctx->pc = 0x125880u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 12), 7)));
    // 0x125884: 0x8fa50010  lw          $a1, 0x10($sp)
    ctx->pc = 0x125884u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x125888: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x125888u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x12588c: 0x8fad0008  lw          $t5, 0x8($sp)
    ctx->pc = 0x12588cu;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125890: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x125890u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x125894: 0x8fae0000  lw          $t6, 0x0($sp)
    ctx->pc = 0x125894u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125898: 0x91820009  lbu         $v0, 0x9($t4)
    ctx->pc = 0x125898u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 12), 9)));
    // 0x12589c: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x12589cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x1258a0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1258a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1258a4: 0xa1420000  sb          $v0, 0x0($t2)
    ctx->pc = 0x1258a4u;
    WRITE8(ADD32(GPR_U32(ctx, 10), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1258a8: 0x9583002a  lhu         $v1, 0x2A($t4)
    ctx->pc = 0x1258a8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 42)));
    // 0x1258ac: 0xad630000  sw          $v1, 0x0($t3)
    ctx->pc = 0x1258acu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 0), GPR_U32(ctx, 3));
    // 0x1258b0: 0x91840008  lbu         $a0, 0x8($t4)
    ctx->pc = 0x1258b0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 12), 8)));
    // 0x1258b4: 0x108f0018  beq         $a0, $t7, . + 4 + (0x18 << 2)
    ctx->pc = 0x1258B4u;
    {
        const bool branch_taken_0x1258b4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 15));
        ctx->pc = 0x1258B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1258B4u;
            // 0x1258b8: 0x28820002  slti        $v0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1258b4) {
            ctx->pc = 0x125918u;
            goto label_125918;
        }
    }
    ctx->pc = 0x1258BCu;
    // 0x1258bc: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x1258BCu;
    {
        const bool branch_taken_0x1258bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1258bc) {
            ctx->pc = 0x1258C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1258BCu;
            // 0x1258c0: 0x28820004  slti        $v0, $a0, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1258D8u;
            goto label_1258d8;
        }
    }
    ctx->pc = 0x1258C4u;
    // 0x1258c4: 0x50800008  beql        $a0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x1258C4u;
    {
        const bool branch_taken_0x1258c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1258c4) {
            ctx->pc = 0x1258C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1258C4u;
            // 0x1258c8: 0x24030010  addiu       $v1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1258E8u;
            goto label_1258e8;
        }
    }
    ctx->pc = 0x1258CCu;
    // 0x1258cc: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1258CCu;
    {
        const bool branch_taken_0x1258cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1258D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1258CCu;
            // 0x1258d0: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1258cc) {
            ctx->pc = 0x125960u;
            goto label_125960;
        }
    }
    ctx->pc = 0x1258D4u;
    // 0x1258d4: 0x0  nop
    ctx->pc = 0x1258d4u;
    // NOP
label_1258d8:
    // 0x1258d8: 0x50400021  beql        $v0, $zero, . + 4 + (0x21 << 2)
    ctx->pc = 0x1258D8u;
    {
        const bool branch_taken_0x1258d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1258d8) {
            ctx->pc = 0x1258DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1258D8u;
            // 0x1258dc: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125960u;
            goto label_125960;
        }
    }
    ctx->pc = 0x1258E0u;
    // 0x1258e0: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1258E0u;
    {
        const bool branch_taken_0x1258e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1258E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1258E0u;
            // 0x1258e4: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1258e0) {
            ctx->pc = 0x125938u;
            goto label_125938;
        }
    }
    ctx->pc = 0x1258E8u;
label_1258e8:
    // 0x1258e8: 0xa1030000  sb          $v1, 0x0($t0)
    ctx->pc = 0x1258e8u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1258ec: 0x81420000  lb          $v0, 0x0($t2)
    ctx->pc = 0x1258ecu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1258f0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1258f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1258f4: 0xa1220000  sb          $v0, 0x0($t1)
    ctx->pc = 0x1258f4u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1258f8: 0xadaf0000  sw          $t7, 0x0($t5)
    ctx->pc = 0x1258f8u;
    WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 15));
    // 0x1258fc: 0xa4a00000  sh          $zero, 0x0($a1)
    ctx->pc = 0x1258fcu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x125900: 0x8d82000c  lw          $v0, 0xC($t4)
    ctx->pc = 0x125900u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 12)));
    // 0x125904: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x125904u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x125908: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x125908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x12590c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x12590Cu;
    {
        const bool branch_taken_0x12590c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12590Cu;
            // 0x125910: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12590c) {
            ctx->pc = 0x125958u;
            goto label_125958;
        }
    }
    ctx->pc = 0x125914u;
    // 0x125914: 0x0  nop
    ctx->pc = 0x125914u;
    // NOP
label_125918:
    // 0x125918: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x125918u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x12591c: 0xa1020000  sb          $v0, 0x0($t0)
    ctx->pc = 0x12591cu;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x125920: 0x81430000  lb          $v1, 0x0($t2)
    ctx->pc = 0x125920u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x125924: 0xa1230000  sb          $v1, 0x0($t1)
    ctx->pc = 0x125924u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x125928: 0xada40000  sw          $a0, 0x0($t5)
    ctx->pc = 0x125928u;
    WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 4));
    // 0x12592c: 0xa4a40000  sh          $a0, 0x0($a1)
    ctx->pc = 0x12592cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x125930: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x125930u;
    {
        const bool branch_taken_0x125930 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125930u;
            // 0x125934: 0x8d82000c  lw          $v0, 0xC($t4) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125930) {
            ctx->pc = 0x125958u;
            goto label_125958;
        }
    }
    ctx->pc = 0x125938u;
label_125938:
    // 0x125938: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x125938u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12593c: 0xa1030000  sb          $v1, 0x0($t0)
    ctx->pc = 0x12593cu;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x125940: 0x81420000  lb          $v0, 0x0($t2)
    ctx->pc = 0x125940u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x125944: 0xa1220000  sb          $v0, 0x0($t1)
    ctx->pc = 0x125944u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x125948: 0xada40000  sw          $a0, 0x0($t5)
    ctx->pc = 0x125948u;
    WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 4));
    // 0x12594c: 0xa4a40000  sh          $a0, 0x0($a1)
    ctx->pc = 0x12594cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x125950: 0x8d82000c  lw          $v0, 0xC($t4)
    ctx->pc = 0x125950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 12)));
    // 0x125954: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x125954u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_125958:
    // 0x125958: 0xadc20000  sw          $v0, 0x0($t6)
    ctx->pc = 0x125958u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 0), GPR_U32(ctx, 2));
    // 0x12595c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x12595cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_125960:
    // 0x125960: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x125960u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x125964: 0xa1230000  sb          $v1, 0x0($t1)
    ctx->pc = 0x125964u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x125968: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x125968u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12596c: 0xada40000  sw          $a0, 0x0($t5)
    ctx->pc = 0x12596cu;
    WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 4));
    // 0x125970: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x125970u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x125974: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x125974u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125978: 0x8d83000c  lw          $v1, 0xC($t4)
    ctx->pc = 0x125978u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 12)));
    // 0x12597c: 0x327c2  srl         $a0, $v1, 31
    ctx->pc = 0x12597cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x125980: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x125980u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x125984: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x125984u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x125988: 0xadc30000  sw          $v1, 0x0($t6)
    ctx->pc = 0x125988u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 0), GPR_U32(ctx, 3));
    // 0x12598c: 0xa1050000  sb          $a1, 0x0($t0)
    ctx->pc = 0x12598cu;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x125990: 0x3e00008  jr          $ra
    ctx->pc = 0x125990u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125990u;
            // 0x125994: 0xa0e60000  sb          $a2, 0x0($a3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125878u: goto label_125878;
            case 0x1258D8u: goto label_1258d8;
            case 0x1258E8u: goto label_1258e8;
            case 0x125918u: goto label_125918;
            case 0x125938u: goto label_125938;
            case 0x125958u: goto label_125958;
            case 0x125960u: goto label_125960;
            case 0x125A00u: goto label_125a00;
            case 0x125A10u: goto label_125a10;
            case 0x125A70u: goto label_125a70;
            case 0x125AC4u: goto label_125ac4;
            case 0x125AE4u: goto label_125ae4;
            case 0x125B40u: goto label_125b40;
            case 0x125B78u: goto label_125b78;
            case 0x125B80u: goto label_125b80;
            case 0x125BA4u: goto label_125ba4;
            case 0x125BC4u: goto label_125bc4;
            case 0x125BE4u: goto label_125be4;
            case 0x125BF0u: goto label_125bf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125998u;
    // 0x125998: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x125998u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x12599c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12599cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1259a0: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x1259a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x1259a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1259a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259a8: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x1259a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x1259ac: 0x2611000e  addiu       $s1, $s0, 0xE
    ctx->pc = 0x1259acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 14));
    // 0x1259b0: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x1259b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x1259b4: 0x26120010  addiu       $s2, $s0, 0x10
    ctx->pc = 0x1259b4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x1259b8: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x1259b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x1259bc: 0x2613000f  addiu       $s3, $s0, 0xF
    ctx->pc = 0x1259bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x1259c0: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1259c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1259c4: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1259c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259c8: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x1259c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1259cc: 0x26020018  addiu       $v0, $s0, 0x18
    ctx->pc = 0x1259ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x1259d0: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1259d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259d4: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x1259d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1259d8: 0x2603009a  addiu       $v1, $s0, 0x9A
    ctx->pc = 0x1259d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 154));
    // 0x1259dc: 0x2607000c  addiu       $a3, $s0, 0xC
    ctx->pc = 0x1259dcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x1259e0: 0x2608000d  addiu       $t0, $s0, 0xD
    ctx->pc = 0x1259e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 13));
    // 0x1259e4: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x1259e4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259e8: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x1259e8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259ec: 0x260b0014  addiu       $t3, $s0, 0x14
    ctx->pc = 0x1259ecu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x1259f0: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1259f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1259f4: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x1259f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x1259f8: 0xc04961e  jal         func_125878
    ctx->pc = 0x1259F8u;
    SET_GPR_U32(ctx, 31, 0x125A00u);
    ctx->pc = 0x1259FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1259F8u;
            // 0x1259fc: 0xafb20008  sw          $s2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125878u;
    goto label_125878;
    ctx->pc = 0x125A00u;
label_125a00:
    // 0x125a00: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x125A00u;
    {
        const bool branch_taken_0x125a00 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x125a00) {
            ctx->pc = 0x125A04u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125A00u;
            // 0x125a04: 0xae000034  sw          $zero, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125A10u;
            goto label_125a10;
        }
    }
    ctx->pc = 0x125A08u;
    // 0x125a08: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x125A08u;
    {
        const bool branch_taken_0x125a08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125A0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125A08u;
            // 0x125a0c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125a08) {
            ctx->pc = 0x125A70u;
            goto label_125a70;
        }
    }
    ctx->pc = 0x125A10u;
label_125a10:
    // 0x125a10: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x125a10u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x125a14: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x125a14u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x125a18: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x125a18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x125a1c: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x125a1cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x125a20: 0xa600001c  sh          $zero, 0x1C($s0)
    ctx->pc = 0x125a20u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x125a24: 0xa6000026  sh          $zero, 0x26($s0)
    ctx->pc = 0x125a24u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x125a28: 0xa6000024  sh          $zero, 0x24($s0)
    ctx->pc = 0x125a28u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x125a2c: 0x8e05003c  lw          $a1, 0x3C($s0)
    ctx->pc = 0x125a2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x125a30: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x125a30u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x125a34: 0x8e060040  lw          $a2, 0x40($s0)
    ctx->pc = 0x125a34u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x125a38: 0xae030050  sw          $v1, 0x50($s0)
    ctx->pc = 0x125a38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 3));
    // 0x125a3c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x125a3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125a40: 0x8e070044  lw          $a3, 0x44($s0)
    ctx->pc = 0x125a40u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x125a44: 0x82640000  lb          $a0, 0x0($s3)
    ctx->pc = 0x125a44u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x125a48: 0x87a20020  lh          $v0, 0x20($sp)
    ctx->pc = 0x125a48u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125a4c: 0xae040054  sw          $a0, 0x54($s0)
    ctx->pc = 0x125a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 4));
    // 0x125a50: 0xa6030098  sh          $v1, 0x98($s0)
    ctx->pc = 0x125a50u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 3));
    // 0x125a54: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x125a54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x125a58: 0xae05005c  sw          $a1, 0x5C($s0)
    ctx->pc = 0x125a58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 5));
    // 0x125a5c: 0xae060060  sw          $a2, 0x60($s0)
    ctx->pc = 0x125a5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 6));
    // 0x125a60: 0xae030058  sw          $v1, 0x58($s0)
    ctx->pc = 0x125a60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 3));
    // 0x125a64: 0xae070064  sw          $a3, 0x64($s0)
    ctx->pc = 0x125a64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 7));
    // 0x125a68: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x125a68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
    // 0x125a6c: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x125a6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
label_125a70:
    // 0x125a70: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x125a70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x125a74: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x125a74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x125a78: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x125a78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x125a7c: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x125a7cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x125a80: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x125a80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x125a84: 0x3e00008  jr          $ra
    ctx->pc = 0x125A84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125A84u;
            // 0x125a88: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125878u: goto label_125878;
            case 0x1258D8u: goto label_1258d8;
            case 0x1258E8u: goto label_1258e8;
            case 0x125918u: goto label_125918;
            case 0x125938u: goto label_125938;
            case 0x125958u: goto label_125958;
            case 0x125960u: goto label_125960;
            case 0x125A00u: goto label_125a00;
            case 0x125A10u: goto label_125a10;
            case 0x125A70u: goto label_125a70;
            case 0x125AC4u: goto label_125ac4;
            case 0x125AE4u: goto label_125ae4;
            case 0x125B40u: goto label_125b40;
            case 0x125B78u: goto label_125b78;
            case 0x125B80u: goto label_125b80;
            case 0x125BA4u: goto label_125ba4;
            case 0x125BC4u: goto label_125bc4;
            case 0x125BE4u: goto label_125be4;
            case 0x125BF0u: goto label_125bf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125A8Cu;
    // 0x125a8c: 0x0  nop
    ctx->pc = 0x125a8cu;
    // NOP
    // 0x125a90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x125a90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x125a94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x125a94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x125a98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x125a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x125a9c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x125a9cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125aa0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x125aa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x125aa4: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x125aa4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x125aa8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x125aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x125aac: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x125aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x125ab0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x125ab0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x125ab4: 0x14620043  bne         $v1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x125AB4u;
    {
        const bool branch_taken_0x125ab4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x125AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125AB4u;
            // 0x125ab8: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125ab4) {
            ctx->pc = 0x125BC4u;
            goto label_125bc4;
        }
    }
    ctx->pc = 0x125ABCu;
    // 0x125abc: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x125ABCu;
    SET_GPR_U32(ctx, 31, 0x125AC4u);
    ctx->pc = 0x125AC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125ABCu;
            // 0x125ac0: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125AC4u; }
        if (ctx->pc != 0x125AC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125AC4u; }
        if (ctx->pc != 0x125AC4u) { return; }
    }
    ctx->pc = 0x125AC4u;
label_125ac4:
    // 0x125ac4: 0x5440003f  bnel        $v0, $zero, . + 4 + (0x3F << 2)
    ctx->pc = 0x125AC4u;
    {
        const bool branch_taken_0x125ac4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x125ac4) {
            ctx->pc = 0x125AC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125AC4u;
            // 0x125ac8: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125BC4u;
            goto label_125bc4;
        }
    }
    ctx->pc = 0x125ACCu;
    // 0x125acc: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x125accu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x125ad0: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x125ad0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x125ad4: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x125ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x125ad8: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x125ad8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x125adc: 0x40f809  jalr        $v0
    ctx->pc = 0x125ADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x125AE4u);
        ctx->pc = 0x125AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125ADCu;
            // 0x125ae0: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x125AE4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125878u: goto label_125878;
            case 0x1258D8u: goto label_1258d8;
            case 0x1258E8u: goto label_1258e8;
            case 0x125918u: goto label_125918;
            case 0x125938u: goto label_125938;
            case 0x125958u: goto label_125958;
            case 0x125960u: goto label_125960;
            case 0x125A00u: goto label_125a00;
            case 0x125A10u: goto label_125a10;
            case 0x125A70u: goto label_125a70;
            case 0x125AC4u: goto label_125ac4;
            case 0x125AE4u: goto label_125ae4;
            case 0x125B40u: goto label_125b40;
            case 0x125B78u: goto label_125b78;
            case 0x125B80u: goto label_125b80;
            case 0x125BA4u: goto label_125ba4;
            case 0x125BC4u: goto label_125bc4;
            case 0x125BE4u: goto label_125be4;
            case 0x125BF0u: goto label_125bf0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x125AE4u; }
            if (ctx->pc != 0x125AE4u) { return; }
        }
        }
    }
    ctx->pc = 0x125AE4u;
label_125ae4:
    // 0x125ae4: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x125ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x125ae8: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x125ae8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x125aec: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x125aecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125af0: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x125af0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x125af4: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x125af4u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x125af8: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x125af8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x125afc: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x125afcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125b00: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x125b00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x125b04: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x125b04u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x125b08: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x125b08u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x125b0c: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x125b0cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x125b10: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x125b10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125b14: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x125b14u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x125b18: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x125b18u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x125b1c: 0x14860016  bne         $a0, $a2, . + 4 + (0x16 << 2)
    ctx->pc = 0x125B1Cu;
    {
        const bool branch_taken_0x125b1c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x125B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B1Cu;
            // 0x125b20: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b1c) {
            ctx->pc = 0x125B78u;
            goto label_125b78;
        }
    }
    ctx->pc = 0x125B24u;
    // 0x125b24: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x125b24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x125b28: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x125b28u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125b2c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x125b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x125b30: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x125b30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x125b34: 0x1920001b  blez        $t1, . + 4 + (0x1B << 2)
    ctx->pc = 0x125B34u;
    {
        const bool branch_taken_0x125b34 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x125B38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B34u;
            // 0x125b38: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b34) {
            ctx->pc = 0x125BA4u;
            goto label_125ba4;
        }
    }
    ctx->pc = 0x125B3Cu;
    // 0x125b3c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x125b3cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_125b40:
    // 0x125b40: 0x81840  sll         $v1, $t0, 1
    ctx->pc = 0x125b40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x125b44: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x125b44u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x125b48: 0x94e50000  lhu         $a1, 0x0($a3)
    ctx->pc = 0x125b48u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x125b4c: 0x6a2021  addu        $a0, $v1, $t2
    ctx->pc = 0x125b4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x125b50: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x125b50u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125b54: 0x6b1821  addu        $v1, $v1, $t3
    ctx->pc = 0x125b54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x125b58: 0xa4850000  sh          $a1, 0x0($a0)
    ctx->pc = 0x125b58u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x125b5c: 0x94e20002  lhu         $v0, 0x2($a3)
    ctx->pc = 0x125b5cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x125b60: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x125b60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x125b64: 0x14c0fff6  bnez        $a2, . + 4 + (-0xA << 2)
    ctx->pc = 0x125B64u;
    {
        const bool branch_taken_0x125b64 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x125B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B64u;
            // 0x125b68: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b64) {
            ctx->pc = 0x125B40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_125b40;
        }
    }
    ctx->pc = 0x125B6Cu;
    // 0x125b6c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x125B6Cu;
    {
        const bool branch_taken_0x125b6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B6Cu;
            // 0x125b70: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b6c) {
            ctx->pc = 0x125BA4u;
            goto label_125ba4;
        }
    }
    ctx->pc = 0x125B74u;
    // 0x125b74: 0x0  nop
    ctx->pc = 0x125b74u;
    // NOP
label_125b78:
    // 0x125b78: 0x1920000a  blez        $t1, . + 4 + (0xA << 2)
    ctx->pc = 0x125B78u;
    {
        const bool branch_taken_0x125b78 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x125B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B78u;
            // 0x125b7c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b78) {
            ctx->pc = 0x125BA4u;
            goto label_125ba4;
        }
    }
    ctx->pc = 0x125B80u;
label_125b80:
    // 0x125b80: 0x81040  sll         $v0, $t0, 1
    ctx->pc = 0x125b80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x125b84: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x125b84u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x125b88: 0x521821  addu        $v1, $v0, $s2
    ctx->pc = 0x125b88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x125b8c: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x125b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x125b90: 0x94640000  lhu         $a0, 0x0($v1)
    ctx->pc = 0x125b90u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x125b94: 0x109282a  slt         $a1, $t0, $t1
    ctx->pc = 0x125b94u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125b98: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x125B98u;
    {
        const bool branch_taken_0x125b98 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x125B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B98u;
            // 0x125b9c: 0xa4440000  sh          $a0, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b98) {
            ctx->pc = 0x125B80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_125b80;
        }
    }
    ctx->pc = 0x125BA0u;
    // 0x125ba0: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x125ba0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_125ba4:
    // 0x125ba4: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x125ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x125ba8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x125ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125bac: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x125bacu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x125bb0: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x125bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x125bb4: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x125bb4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x125bb8: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x125bb8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x125bbc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x125bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x125bc0: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x125bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_125bc4:
    // 0x125bc4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x125bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125bc8: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x125BC8u;
    {
        const bool branch_taken_0x125bc8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x125bc8) {
            ctx->pc = 0x125BCCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125BC8u;
            // 0x125bcc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125BF0u;
            goto label_125bf0;
        }
    }
    ctx->pc = 0x125BD0u;
    // 0x125bd0: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x125bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x125bd4: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x125bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x125bd8: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x125bd8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x125bdc: 0x60f809  jalr        $v1
    ctx->pc = 0x125BDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x125BE4u);
        ctx->pc = 0x125BE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125BDCu;
            // 0x125be0: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x125BE4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125878u: goto label_125878;
            case 0x1258D8u: goto label_1258d8;
            case 0x1258E8u: goto label_1258e8;
            case 0x125918u: goto label_125918;
            case 0x125938u: goto label_125938;
            case 0x125958u: goto label_125958;
            case 0x125960u: goto label_125960;
            case 0x125A00u: goto label_125a00;
            case 0x125A10u: goto label_125a10;
            case 0x125A70u: goto label_125a70;
            case 0x125AC4u: goto label_125ac4;
            case 0x125AE4u: goto label_125ae4;
            case 0x125B40u: goto label_125b40;
            case 0x125B78u: goto label_125b78;
            case 0x125B80u: goto label_125b80;
            case 0x125BA4u: goto label_125ba4;
            case 0x125BC4u: goto label_125bc4;
            case 0x125BE4u: goto label_125be4;
            case 0x125BF0u: goto label_125bf0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x125BE4u; }
            if (ctx->pc != 0x125BE4u) { return; }
        }
        }
    }
    ctx->pc = 0x125BE4u;
label_125be4:
    // 0x125be4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x125be4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x125be8: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x125be8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x125bec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125becu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_125bf0:
    // 0x125bf0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x125bf0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125bf4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x125bf4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x125bf8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x125bf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x125bfc: 0x3e00008  jr          $ra
    ctx->pc = 0x125BFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125BFCu;
            // 0x125c00: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125878u: goto label_125878;
            case 0x1258D8u: goto label_1258d8;
            case 0x1258E8u: goto label_1258e8;
            case 0x125918u: goto label_125918;
            case 0x125938u: goto label_125938;
            case 0x125958u: goto label_125958;
            case 0x125960u: goto label_125960;
            case 0x125A00u: goto label_125a00;
            case 0x125A10u: goto label_125a10;
            case 0x125A70u: goto label_125a70;
            case 0x125AC4u: goto label_125ac4;
            case 0x125AE4u: goto label_125ae4;
            case 0x125B40u: goto label_125b40;
            case 0x125B78u: goto label_125b78;
            case 0x125B80u: goto label_125b80;
            case 0x125BA4u: goto label_125ba4;
            case 0x125BC4u: goto label_125bc4;
            case 0x125BE4u: goto label_125be4;
            case 0x125BF0u: goto label_125bf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125C04u;
    // 0x125c04: 0x0  nop
    ctx->pc = 0x125c04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
