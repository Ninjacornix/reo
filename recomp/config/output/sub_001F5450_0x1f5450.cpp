#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F5450
// Address: 0x1f5450 - 0x1f5600
void sub_001F5450_0x1f5450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F5450_0x1f5450");
#endif

    switch (ctx->pc) {
        case 0x1f547cu: goto label_1f547c;
        case 0x1f54b8u: goto label_1f54b8;
        case 0x1f54c0u: goto label_1f54c0;
        case 0x1f5564u: goto label_1f5564;
        case 0x1f557cu: goto label_1f557c;
        case 0x1f5584u: goto label_1f5584;
        default: break;
    }

    ctx->pc = 0x1f5450u;

    // 0x1f5450: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f5450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f5454: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5454u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5458: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f5458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f545c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f545cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f5460: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f5460u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f5464: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1F5464u;
    {
        const bool branch_taken_0x1f5464 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5464u;
            // 0x1f5468: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5464) {
            ctx->pc = 0x1F54DCu;
            goto label_1f54dc;
        }
    }
    ctx->pc = 0x1F546Cu;
    // 0x1f546c: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1f546cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1f5470: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1f5470u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f5474: 0xc07d284  jal         func_1F4A10
    ctx->pc = 0x1F5474u;
    SET_GPR_U32(ctx, 31, 0x1F547Cu);
    ctx->pc = 0x1F5478u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5474u;
            // 0x1f5478: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4A10u;
    if (runtime->hasFunction(0x1F4A10u)) {
        auto targetFn = runtime->lookupFunction(0x1F4A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F547Cu; }
        if (ctx->pc != 0x1F547Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4A10_0x1f4a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F547Cu; }
        if (ctx->pc != 0x1F547Cu) { return; }
    }
    ctx->pc = 0x1F547Cu;
label_1f547c:
    // 0x1f547c: 0x9603002c  lhu         $v1, 0x2C($s0)
    ctx->pc = 0x1f547cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f5480: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1f5480u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f5484: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1f5484u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1f5488: 0x31a03  sra         $v1, $v1, 8
    ctx->pc = 0x1f5488u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1f548c: 0x3084ff00  andi        $a0, $a0, 0xFF00
    ctx->pc = 0x1f548cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1f5490: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1f5490u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1f5494: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1f5494u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1f5498: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1f5498u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f549c: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x1f549cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f54a0: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f54a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f54a4: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x1f54a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f54a8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f54a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f54ac: 0x2343c  dsll32      $a2, $v0, 16
    ctx->pc = 0x1f54acu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f54b0: 0xc075aa4  jal         func_1D6A90
    ctx->pc = 0x1F54B0u;
    SET_GPR_U32(ctx, 31, 0x1F54B8u);
    ctx->pc = 0x1F54B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F54B0u;
            // 0x1f54b4: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6A90u;
    if (runtime->hasFunction(0x1D6A90u)) {
        auto targetFn = runtime->lookupFunction(0x1D6A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F54B8u; }
        if (ctx->pc != 0x1F54B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6A90_0x1d6a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F54B8u; }
        if (ctx->pc != 0x1F54B8u) { return; }
    }
    ctx->pc = 0x1F54B8u;
label_1f54b8:
    // 0x1f54b8: 0xc07d16c  jal         func_1F45B0
    ctx->pc = 0x1F54B8u;
    SET_GPR_U32(ctx, 31, 0x1F54C0u);
    ctx->pc = 0x1F54BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F54B8u;
            // 0x1f54bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45B0u;
    if (runtime->hasFunction(0x1F45B0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F54C0u; }
        if (ctx->pc != 0x1F54C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45B0_0x1f45b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F54C0u; }
        if (ctx->pc != 0x1F54C0u) { return; }
    }
    ctx->pc = 0x1F54C0u;
label_1f54c0:
    // 0x1f54c0: 0x2841ffff  slti        $at, $v0, -0x1
    ctx->pc = 0x1f54c0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x1f54c4: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F54C4u;
    {
        const bool branch_taken_0x1f54c4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f54c4) {
            ctx->pc = 0x1F54D4u;
            goto label_1f54d4;
        }
    }
    ctx->pc = 0x1F54CCu;
    // 0x1f54cc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F54CCu;
    {
        const bool branch_taken_0x1f54cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F54D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F54CCu;
            // 0x1f54d0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f54cc) {
            ctx->pc = 0x1F54E4u;
            goto label_1f54e4;
        }
    }
    ctx->pc = 0x1F54D4u;
label_1f54d4:
    // 0x1f54d4: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1f54d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1f54d8: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f54d8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f54dc:
    // 0x1f54dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f54dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f54e0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f54e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f54e4:
    // 0x1f54e4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f54e4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f54e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F54E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F54ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F54E8u;
            // 0x1f54ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F547Cu: goto label_1f547c;
            case 0x1F54B8u: goto label_1f54b8;
            case 0x1F54C0u: goto label_1f54c0;
            case 0x1F54D4u: goto label_1f54d4;
            case 0x1F54DCu: goto label_1f54dc;
            case 0x1F54E4u: goto label_1f54e4;
            case 0x1F555Cu: goto label_1f555c;
            case 0x1F5564u: goto label_1f5564;
            case 0x1F557Cu: goto label_1f557c;
            case 0x1F5584u: goto label_1f5584;
            case 0x1F55B8u: goto label_1f55b8;
            case 0x1F55D0u: goto label_1f55d0;
            case 0x1F55D8u: goto label_1f55d8;
            case 0x1F55DCu: goto label_1f55dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F54F0u;
    // 0x1f54f0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1f54f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1f54f4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f54f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f54f8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1f54f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1f54fc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1f54fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1f5500: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1f5500u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1f5504: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f5504u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f5508: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f5508u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f550c: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f550cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f5510: 0x8c830024  lw          $v1, 0x24($a0)
    ctx->pc = 0x1f5510u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f5514: 0x10400030  beqz        $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1F5514u;
    {
        const bool branch_taken_0x1f5514 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5514u;
            // 0x1f5518: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5514) {
            ctx->pc = 0x1F55D8u;
            goto label_1f55d8;
        }
    }
    ctx->pc = 0x1F551Cu;
    // 0x1f551c: 0x80630006  lb          $v1, 0x6($v1)
    ctx->pc = 0x1f551cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 6)));
    // 0x1f5520: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1f5520u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f5524: 0x1462000d  bne         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F5524u;
    {
        const bool branch_taken_0x1f5524 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F5528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5524u;
            // 0x1f5528: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5524) {
            ctx->pc = 0x1F555Cu;
            goto label_1f555c;
        }
    }
    ctx->pc = 0x1F552Cu;
    // 0x1f552c: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f552cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f5530: 0xae62008c  sw          $v0, 0x8C($s3)
    ctx->pc = 0x1f5530u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 140), GPR_U32(ctx, 2));
    // 0x1f5534: 0xa2630000  sb          $v1, 0x0($s3)
    ctx->pc = 0x1f5534u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f5538: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f5538u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f553c: 0xa2600001  sb          $zero, 0x1($s3)
    ctx->pc = 0x1f553cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5540: 0xa2600002  sb          $zero, 0x2($s3)
    ctx->pc = 0x1f5540u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5544: 0xa2600003  sb          $zero, 0x3($s3)
    ctx->pc = 0x1f5544u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5548: 0xa6600004  sh          $zero, 0x4($s3)
    ctx->pc = 0x1f5548u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f554c: 0xa6600006  sh          $zero, 0x6($s3)
    ctx->pc = 0x1f554cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5550: 0xa6600008  sh          $zero, 0x8($s3)
    ctx->pc = 0x1f5550u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5554: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1F5554u;
    {
        const bool branch_taken_0x1f5554 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5554u;
            // 0x1f5558: 0xa660000a  sh          $zero, 0xA($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5554) {
            ctx->pc = 0x1F55DCu;
            goto label_1f55dc;
        }
    }
    ctx->pc = 0x1F555Cu;
label_1f555c:
    // 0x1f555c: 0xc07d20c  jal         func_1F4830
    ctx->pc = 0x1F555Cu;
    SET_GPR_U32(ctx, 31, 0x1F5564u);
    ctx->pc = 0x1F4830u;
    if (runtime->hasFunction(0x1F4830u)) {
        auto targetFn = runtime->lookupFunction(0x1F4830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5564u; }
        if (ctx->pc != 0x1F5564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4830_0x1f4830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5564u; }
        if (ctx->pc != 0x1F5564u) { return; }
    }
    ctx->pc = 0x1F5564u;
label_1f5564:
    // 0x1f5564: 0x3052ffff  andi        $s2, $v0, 0xFFFF
    ctx->pc = 0x1f5564u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f5568: 0x12400019  beqz        $s2, . + 4 + (0x19 << 2)
    ctx->pc = 0x1F5568u;
    {
        const bool branch_taken_0x1f5568 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F556Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5568u;
            // 0x1f556c: 0x3c010036  lui         $at, 0x36 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5568) {
            ctx->pc = 0x1F55D0u;
            goto label_1f55d0;
        }
    }
    ctx->pc = 0x1F5570u;
    // 0x1f5570: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1f5570u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5574: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1F5574u;
    {
        const bool branch_taken_0x1f5574 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5574u;
            // 0x1f5578: 0xa432ebb0  sh          $s2, -0x1450($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294962096), (uint16_t)GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5574) {
            ctx->pc = 0x1F55B8u;
            goto label_1f55b8;
        }
    }
    ctx->pc = 0x1F557Cu;
label_1f557c:
    // 0x1f557c: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F557Cu;
    SET_GPR_U32(ctx, 31, 0x1F5584u);
    ctx->pc = 0x1F5580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F557Cu;
            // 0x1f5580: 0x118080  sll         $s0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5584u; }
        if (ctx->pc != 0x1F5584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5584u; }
        if (ctx->pc != 0x1F5584u) { return; }
    }
    ctx->pc = 0x1F5584u;
label_1f5584:
    // 0x1f5584: 0x3c030036  lui         $v1, 0x36
    ctx->pc = 0x1f5584u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)54 << 16));
    // 0x1f5588: 0x112280  sll         $a0, $s1, 10
    ctx->pc = 0x1f5588u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 17), 10));
    // 0x1f558c: 0x2463ebb0  addiu       $v1, $v1, -0x1450
    ctx->pc = 0x1f558cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294962096));
    // 0x1f5590: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1f5590u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1f5594: 0x702821  addu        $a1, $v1, $s0
    ctx->pc = 0x1f5594u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1f5598: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1f5598u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1f559c: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1f559cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1f55a0: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f55a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f55a4: 0x24635ad0  addiu       $v1, $v1, 0x5AD0
    ctx->pc = 0x1f55a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 23248));
    // 0x1f55a8: 0x2442ec50  addiu       $v0, $v0, -0x13B0
    ctx->pc = 0x1f55a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962256));
    // 0x1f55ac: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1f55acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1f55b0: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1f55b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1f55b4: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1f55b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_1f55b8:
    // 0x1f55b8: 0x232102a  slt         $v0, $s1, $s2
    ctx->pc = 0x1f55b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1f55bc: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1F55BCu;
    {
        const bool branch_taken_0x1f55bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F55C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F55BCu;
            // 0x1f55c0: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f55bc) {
            ctx->pc = 0x1F557Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f557c;
        }
    }
    ctx->pc = 0x1F55C4u;
    // 0x1f55c4: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1f55c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f55c8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1F55C8u;
    {
        const bool branch_taken_0x1f55c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F55CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F55C8u;
            // 0x1f55cc: 0xa2620001  sb          $v0, 0x1($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f55c8) {
            ctx->pc = 0x1F55D8u;
            goto label_1f55d8;
        }
    }
    ctx->pc = 0x1F55D0u;
label_1f55d0:
    // 0x1f55d0: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1f55d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1f55d4: 0xa2620001  sb          $v0, 0x1($s3)
    ctx->pc = 0x1f55d4u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f55d8:
    // 0x1f55d8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f55d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f55dc:
    // 0x1f55dc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1f55dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1f55e0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1f55e0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f55e4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1f55e4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f55e8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f55e8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f55ec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f55ecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f55f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F55F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F55F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F55F0u;
            // 0x1f55f4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F547Cu: goto label_1f547c;
            case 0x1F54B8u: goto label_1f54b8;
            case 0x1F54C0u: goto label_1f54c0;
            case 0x1F54D4u: goto label_1f54d4;
            case 0x1F54DCu: goto label_1f54dc;
            case 0x1F54E4u: goto label_1f54e4;
            case 0x1F555Cu: goto label_1f555c;
            case 0x1F5564u: goto label_1f5564;
            case 0x1F557Cu: goto label_1f557c;
            case 0x1F5584u: goto label_1f5584;
            case 0x1F55B8u: goto label_1f55b8;
            case 0x1F55D0u: goto label_1f55d0;
            case 0x1F55D8u: goto label_1f55d8;
            case 0x1F55DCu: goto label_1f55dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F55F8u;
    // 0x1f55f8: 0x0  nop
    ctx->pc = 0x1f55f8u;
    // NOP
    // 0x1f55fc: 0x0  nop
    ctx->pc = 0x1f55fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
