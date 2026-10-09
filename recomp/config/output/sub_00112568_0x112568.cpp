#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112568
// Address: 0x112568 - 0x1126f8
void sub_00112568_0x112568(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112568_0x112568");
#endif

    switch (ctx->pc) {
        case 0x1125dcu: goto label_1125dc;
        case 0x112614u: goto label_112614;
        case 0x11262cu: goto label_11262c;
        case 0x112638u: goto label_112638;
        case 0x112688u: goto label_112688;
        default: break;
    }

    ctx->pc = 0x112568u;

    // 0x112568: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x112568u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11256c: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x11256cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x112570: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x112570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x112574: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x112574u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x112578: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x112578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11257c: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x11257cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x112580: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x112580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x112584: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x112584u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x112588: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x112588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11258c: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x11258cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x112590: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x112590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x112594: 0x58c03  sra         $s1, $a1, 16
    ctx->pc = 0x112594u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 5), 16));
    // 0x112598: 0x69403  sra         $s2, $a2, 16
    ctx->pc = 0x112598u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 6), 16));
    // 0x11259c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11259cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1125a0: 0x10820031  beq         $a0, $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x1125A0u;
    {
        const bool branch_taken_0x1125a0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1125A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1125A0u;
            // 0x1125a4: 0x79c03  sra         $s3, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1125a0) {
            ctx->pc = 0x112668u;
            goto label_112668;
        }
    }
    ctx->pc = 0x1125A8u;
    // 0x1125a8: 0x28820002  slti        $v0, $a0, 0x2
    ctx->pc = 0x1125a8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1125ac: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1125ACu;
    {
        const bool branch_taken_0x1125ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1125ac) {
            ctx->pc = 0x1125B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1125ACu;
            // 0x1125b0: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1125C4u;
            goto label_1125c4;
        }
    }
    ctx->pc = 0x1125B4u;
    // 0x1125b4: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1125B4u;
    {
        const bool branch_taken_0x1125b4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1125B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1125B4u;
            // 0x1125b8: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1125b4) {
            ctx->pc = 0x1125D4u;
            goto label_1125d4;
        }
    }
    ctx->pc = 0x1125BCu;
    // 0x1125bc: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x1125BCu;
    {
        const bool branch_taken_0x1125bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1125C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1125BCu;
            // 0x1125c0: 0xdfb30030  ld          $s3, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1125bc) {
            ctx->pc = 0x1126E4u;
            goto label_1126e4;
        }
    }
    ctx->pc = 0x1125C4u;
label_1125c4:
    // 0x1125c4: 0x1082002e  beq         $a0, $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0x1125C4u;
    {
        const bool branch_taken_0x1125c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1125C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1125C4u;
            // 0x1125c8: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1125c4) {
            ctx->pc = 0x112680u;
            goto label_112680;
        }
    }
    ctx->pc = 0x1125CCu;
    // 0x1125cc: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x1125CCu;
    {
        const bool branch_taken_0x1125cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1125D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1125CCu;
            // 0x1125d0: 0xdfb30030  ld          $s3, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1125cc) {
            ctx->pc = 0x1126E4u;
            goto label_1126e4;
        }
    }
    ctx->pc = 0x1125D4u;
label_1125d4:
    // 0x1125d4: 0xc0449be  jal         func_1126F8
    ctx->pc = 0x1125D4u;
    SET_GPR_U32(ctx, 31, 0x1125DCu);
    ctx->pc = 0x1126F8u;
    if (runtime->hasFunction(0x1126F8u)) {
        auto targetFn = runtime->lookupFunction(0x1126F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1125DCu; }
        if (ctx->pc != 0x1125DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1125DCu; }
        if (ctx->pc != 0x1125DCu) { return; }
    }
    ctx->pc = 0x1125DCu;
label_1125dc:
    // 0x1125dc: 0x3c031200  lui         $v1, 0x1200
    ctx->pc = 0x1125dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4608 << 16));
    // 0x1125e0: 0x24040200  addiu       $a0, $zero, 0x200
    ctx->pc = 0x1125e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1125e4: 0x34631000  ori         $v1, $v1, 0x1000
    ctx->pc = 0x1125e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4096);
    // 0x1125e8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1125e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1125ec: 0xfc640000  sd          $a0, 0x0($v1)
    ctx->pc = 0x1125ecu;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 4));
    // 0x1125f0: 0xa6110000  sh          $s1, 0x0($s0)
    ctx->pc = 0x1125f0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 17));
    // 0x1125f4: 0x3404ff00  ori         $a0, $zero, 0xFF00
    ctx->pc = 0x1125f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65280);
    // 0x1125f8: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x1125f8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1125fc: 0xa6120002  sh          $s2, 0x2($s0)
    ctx->pc = 0x1125fcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 18));
    // 0x112600: 0x2143a  dsrl        $v0, $v0, 16
    ctx->pc = 0x112600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 16);
    // 0x112604: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x112604u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x112608: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x112608u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x11260c: 0xc045258  jal         func_114960
    ctx->pc = 0x11260Cu;
    SET_GPR_U32(ctx, 31, 0x112614u);
    ctx->pc = 0x112610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11260Cu;
            // 0x112610: 0xa6020006  sh          $v0, 0x6($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114960u;
    if (runtime->hasFunction(0x114960u)) {
        auto targetFn = runtime->lookupFunction(0x114960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112614u; }
        if (ctx->pc != 0x112614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114960_0x114960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112614u; }
        if (ctx->pc != 0x112614u) { return; }
    }
    ctx->pc = 0x112614u;
label_112614:
    // 0x112614: 0x13182b  sltu        $v1, $zero, $s3
    ctx->pc = 0x112614u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 19)) ? 1 : 0);
    // 0x112618: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x112618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11261c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11261Cu;
    {
        const bool branch_taken_0x11261c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x112620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11261Cu;
            // 0x112620: 0xa6030004  sh          $v1, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11261c) {
            ctx->pc = 0x112640u;
            goto label_112640;
        }
    }
    ctx->pc = 0x112624u;
    // 0x112624: 0xc045440  jal         func_115100
    ctx->pc = 0x112624u;
    SET_GPR_U32(ctx, 31, 0x11262Cu);
    ctx->pc = 0x112628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112624u;
            // 0x112628: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115100u;
    if (runtime->hasFunction(0x115100u)) {
        auto targetFn = runtime->lookupFunction(0x115100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11262Cu; }
        if (ctx->pc != 0x11262Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115100_0x115100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11262Cu; }
        if (ctx->pc != 0x11262Cu) { return; }
    }
    ctx->pc = 0x11262Cu;
label_11262c:
    // 0x11262c: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x11262cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x112630: 0xc0450c8  jal         func_114320
    ctx->pc = 0x112630u;
    SET_GPR_U32(ctx, 31, 0x112638u);
    ctx->pc = 0x112634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112630u;
            // 0x112634: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114320u;
    if (runtime->hasFunction(0x114320u)) {
        auto targetFn = runtime->lookupFunction(0x114320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112638u; }
        if (ctx->pc != 0x112638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114320_0x114320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112638u; }
        if (ctx->pc != 0x112638u) { return; }
    }
    ctx->pc = 0x112638u;
label_112638:
    // 0x112638: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x112638u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x11263c: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x11263cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
label_112640:
    // 0x112640: 0x32240001  andi        $a0, $s1, 0x1
    ctx->pc = 0x112640u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
    // 0x112644: 0x324500ff  andi        $a1, $s2, 0xFF
    ctx->pc = 0x112644u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x112648: 0x32660001  andi        $a2, $s3, 0x1
    ctx->pc = 0x112648u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)1);
    // 0x11264c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11264cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x112650: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x112650u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x112654: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x112654u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x112658: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x112658u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11265c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11265cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112660: 0x8045088  j           func_114220
    ctx->pc = 0x112660u;
    ctx->pc = 0x112664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112660u;
            // 0x112664: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114220u;
    if (runtime->hasFunction(0x114220u)) {
        auto targetFn = runtime->lookupFunction(0x114220u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114220_0x114220(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x112668u;
label_112668:
    // 0x112668: 0x3c021200  lui         $v0, 0x1200
    ctx->pc = 0x112668u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4608 << 16));
    // 0x11266c: 0x24030100  addiu       $v1, $zero, 0x100
    ctx->pc = 0x11266cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x112670: 0x34421000  ori         $v0, $v0, 0x1000
    ctx->pc = 0x112670u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4096);
    // 0x112674: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x112674u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x112678: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x112678u;
    {
        const bool branch_taken_0x112678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11267Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112678u;
            // 0x11267c: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112678) {
            ctx->pc = 0x1126E0u;
            goto label_1126e0;
        }
    }
    ctx->pc = 0x112680u;
label_112680:
    // 0x112680: 0xc0449be  jal         func_1126F8
    ctx->pc = 0x112680u;
    SET_GPR_U32(ctx, 31, 0x112688u);
    ctx->pc = 0x1126F8u;
    if (runtime->hasFunction(0x1126F8u)) {
        auto targetFn = runtime->lookupFunction(0x1126F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112688u; }
        if (ctx->pc != 0x112688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112688u; }
        if (ctx->pc != 0x112688u) { return; }
    }
    ctx->pc = 0x112688u;
label_112688:
    // 0x112688: 0x3c031200  lui         $v1, 0x1200
    ctx->pc = 0x112688u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4608 << 16));
    // 0x11268c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11268cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112690: 0x34631000  ori         $v1, $v1, 0x1000
    ctx->pc = 0x112690u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4096);
    // 0x112694: 0x13302b  sltu        $a2, $zero, $s3
    ctx->pc = 0x112694u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 19)) ? 1 : 0);
    // 0x112698: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x112698u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11269c: 0x32240001  andi        $a0, $s1, 0x1
    ctx->pc = 0x11269cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
    // 0x1126a0: 0xa6060004  sh          $a2, 0x4($s0)
    ctx->pc = 0x1126a0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 6));
    // 0x1126a4: 0x324500ff  andi        $a1, $s2, 0xFF
    ctx->pc = 0x1126a4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1126a8: 0x2143a  dsrl        $v0, $v0, 16
    ctx->pc = 0x1126a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 16);
    // 0x1126ac: 0xa6110000  sh          $s1, 0x0($s0)
    ctx->pc = 0x1126acu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 17));
    // 0x1126b0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1126b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1126b4: 0xa6120002  sh          $s2, 0x2($s0)
    ctx->pc = 0x1126b4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 18));
    // 0x1126b8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1126b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1126bc: 0x32660001  andi        $a2, $s3, 0x1
    ctx->pc = 0x1126bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)1);
    // 0x1126c0: 0xa6020006  sh          $v0, 0x6($s0)
    ctx->pc = 0x1126c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 2));
    // 0x1126c4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1126c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1126c8: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x1126c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1126cc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1126ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1126d0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1126d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1126d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1126d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1126d8: 0x8045088  j           func_114220
    ctx->pc = 0x1126D8u;
    ctx->pc = 0x1126DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1126D8u;
            // 0x1126dc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114220u;
    if (runtime->hasFunction(0x114220u)) {
        auto targetFn = runtime->lookupFunction(0x114220u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114220_0x114220(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1126E0u;
label_1126e0:
    // 0x1126e0: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x1126e0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1126e4:
    // 0x1126e4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1126e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1126e8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1126e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1126ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1126ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1126f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1126F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1126F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1126F0u;
            // 0x1126f4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1125C4u: goto label_1125c4;
            case 0x1125D4u: goto label_1125d4;
            case 0x1125DCu: goto label_1125dc;
            case 0x112614u: goto label_112614;
            case 0x11262Cu: goto label_11262c;
            case 0x112638u: goto label_112638;
            case 0x112640u: goto label_112640;
            case 0x112668u: goto label_112668;
            case 0x112680u: goto label_112680;
            case 0x112688u: goto label_112688;
            case 0x1126E0u: goto label_1126e0;
            case 0x1126E4u: goto label_1126e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1126F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
