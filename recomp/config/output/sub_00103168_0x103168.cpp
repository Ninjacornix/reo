#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103168
// Address: 0x103168 - 0x103390
void sub_00103168_0x103168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103168_0x103168");
#endif

    ctx->pc = 0x103168u;

    // 0x103168: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x103168u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x10316c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x10316cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x103170: 0x3442e000  ori         $v0, $v0, 0xE000
    ctx->pc = 0x103170u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57344);
    // 0x103174: 0x3463e020  ori         $v1, $v1, 0xE020
    ctx->pc = 0x103174u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)57376);
    // 0x103178: 0x8c4a0000  lw          $t2, 0x0($v0)
    ctx->pc = 0x103178u;
    SET_GPR_S32(ctx, 10, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x10317c: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x10317cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x103180: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x103180u;
    SET_GPR_S32(ctx, 6, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x103184: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x103184u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103188: 0x34a5e030  ori         $a1, $a1, 0xE030
    ctx->pc = 0x103188u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)57392);
    // 0x10318c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x10318cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x103190: 0x8ca50000  lw          $a1, 0x0($a1)
    ctx->pc = 0x103190u;
    SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0))); // MMIO: 0x10000000
    // 0x103194: 0x3463e050  ori         $v1, $v1, 0xE050
    ctx->pc = 0x103194u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)57424);
    // 0x103198: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x103198u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x10319c: 0x91240000  lbu         $a0, 0x0($t1)
    ctx->pc = 0x10319cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1031a0: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x1031a0u;
    SET_GPR_S32(ctx, 6, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1031a4: 0x3442e040  ori         $v0, $v0, 0xE040
    ctx->pc = 0x1031a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57408);
    // 0x1031a8: 0x8c480000  lw          $t0, 0x0($v0)
    ctx->pc = 0x1031a8u;
    SET_GPR_S32(ctx, 8, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1031ac: 0x2c84000a  sltiu       $a0, $a0, 0xA
    ctx->pc = 0x1031acu;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1031b0: 0x54800003  bnel        $a0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x1031B0u;
    {
        const bool branch_taken_0x1031b0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1031b0) {
            ctx->pc = 0x1031B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1031B0u;
            // 0x1031b4: 0x91220001  lbu         $v0, 0x1($t1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 1)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1031C0u;
            goto label_1031c0;
        }
    }
    ctx->pc = 0x1031B8u;
    // 0x1031b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1031B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1031BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1031B8u;
            // 0x1031bc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1031C0u;
label_1031c0:
    // 0x1031c0: 0x2c42000a  sltiu       $v0, $v0, 0xA
    ctx->pc = 0x1031c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1031c4: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x1031C4u;
    {
        const bool branch_taken_0x1031c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1031c4) {
            ctx->pc = 0x1031C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1031C4u;
            // 0x1031c8: 0x91220002  lbu         $v0, 0x2($t1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1031D4u;
            goto label_1031d4;
        }
    }
    ctx->pc = 0x1031CCu;
    // 0x1031cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1031CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1031D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1031CCu;
            // 0x1031d0: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1031D4u;
label_1031d4:
    // 0x1031d4: 0x2c42000a  sltiu       $v0, $v0, 0xA
    ctx->pc = 0x1031d4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1031d8: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x1031D8u;
    {
        const bool branch_taken_0x1031d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1031d8) {
            ctx->pc = 0x1031DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1031D8u;
            // 0x1031dc: 0x912b0003  lbu         $t3, 0x3($t1) (Delay Slot)
        SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 3)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1031E8u;
            goto label_1031e8;
        }
    }
    ctx->pc = 0x1031E0u;
    // 0x1031e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1031E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1031E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1031E0u;
            // 0x1031e4: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1031E8u;
label_1031e8:
    // 0x1031e8: 0x2d620007  sltiu       $v0, $t3, 0x7
    ctx->pc = 0x1031e8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)(int64_t)(int32_t)7) ? 1 : 0);
    // 0x1031ec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1031ECu;
    {
        const bool branch_taken_0x1031ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1031F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1031ECu;
            // 0x1031f0: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1031ec) {
            ctx->pc = 0x1031FCu;
            goto label_1031fc;
        }
    }
    ctx->pc = 0x1031F4u;
    // 0x1031f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1031F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1031F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1031F4u;
            // 0x1031f8: 0x2402fffc  addiu       $v0, $zero, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1031FCu;
label_1031fc:
    // 0x1031fc: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1031fcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x103200: 0x24427738  addiu       $v0, $v0, 0x7738
    ctx->pc = 0x103200u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 30520));
    // 0x103204: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x103204u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x103208: 0x91250001  lbu         $a1, 0x1($t1)
    ctx->pc = 0x103208u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 1)));
    // 0x10320c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10320cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x103210: 0x24847748  addiu       $a0, $a0, 0x7748
    ctx->pc = 0x103210u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30536));
    // 0x103214: 0x90680000  lbu         $t0, 0x0($v1)
    ctx->pc = 0x103214u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x103218: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x103218u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x10321c: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x10321cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x103220: 0x3442ffcf  ori         $v0, $v0, 0xFFCF
    ctx->pc = 0x103220u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65487);
    // 0x103224: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x103224u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x103228: 0x91270002  lbu         $a3, 0x2($t1)
    ctx->pc = 0x103228u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 2)));
    // 0x10322c: 0x1421024  and         $v0, $t2, $v0
    ctx->pc = 0x10322cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) & GPR_U64(ctx, 2));
    // 0x103230: 0x24847758  addiu       $a0, $a0, 0x7758
    ctx->pc = 0x103230u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30552));
    // 0x103234: 0x84100  sll         $t0, $t0, 4
    ctx->pc = 0x103234u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x103238: 0x90a60000  lbu         $a2, 0x0($a1)
    ctx->pc = 0x103238u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10323c: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x10323cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x103240: 0x485025  or          $t2, $v0, $t0
    ctx->pc = 0x103240u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 2) | GPR_U64(ctx, 8));
    // 0x103244: 0xe43821  addu        $a3, $a3, $a0
    ctx->pc = 0x103244u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x103248: 0x3463ff3f  ori         $v1, $v1, 0xFF3F
    ctx->pc = 0x103248u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65343);
    // 0x10324c: 0x63180  sll         $a2, $a2, 6
    ctx->pc = 0x10324cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 6));
    // 0x103250: 0x1431824  and         $v1, $t2, $v1
    ctx->pc = 0x103250u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 10) & GPR_U64(ctx, 3));
    // 0x103254: 0x90e40000  lbu         $a0, 0x0($a3)
    ctx->pc = 0x103254u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x103258: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x103258u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x10325c: 0x665025  or          $t2, $v1, $a2
    ctx->pc = 0x10325cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
    // 0x103260: 0x3442fff3  ori         $v0, $v0, 0xFFF3
    ctx->pc = 0x103260u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65523);
    // 0x103264: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x103264u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x103268: 0x1421024  and         $v0, $t2, $v0
    ctx->pc = 0x103268u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) & GPR_U64(ctx, 2));
    // 0x10326c: 0x1160000a  beqz        $t3, . + 4 + (0xA << 2)
    ctx->pc = 0x10326Cu;
    {
        const bool branch_taken_0x10326c = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        ctx->pc = 0x103270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10326Cu;
            // 0x103270: 0x445025  or          $t2, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10326c) {
            ctx->pc = 0x103298u;
            goto label_103298;
        }
    }
    ctx->pc = 0x103274u;
    // 0x103274: 0x91230003  lbu         $v1, 0x3($t1)
    ctx->pc = 0x103274u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 3)));
    // 0x103278: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x103278u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x10327c: 0x354a0002  ori         $t2, $t2, 0x2
    ctx->pc = 0x10327cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)2);
    // 0x103280: 0x3442fcff  ori         $v0, $v0, 0xFCFF
    ctx->pc = 0x103280u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64767);
    // 0x103284: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x103284u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x103288: 0x1421024  and         $v0, $t2, $v0
    ctx->pc = 0x103288u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) & GPR_U64(ctx, 2));
    // 0x10328c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x10328cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x103290: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x103290u;
    {
        const bool branch_taken_0x103290 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103290u;
            // 0x103294: 0x435025  or          $t2, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103290) {
            ctx->pc = 0x1032A4u;
            goto label_1032a4;
        }
    }
    ctx->pc = 0x103298u;
label_103298:
    // 0x103298: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x103298u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x10329c: 0x3442fffd  ori         $v0, $v0, 0xFFFD
    ctx->pc = 0x10329cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65533);
    // 0x1032a0: 0x1425024  and         $t2, $t2, $v0
    ctx->pc = 0x1032a0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) & GPR_U64(ctx, 2));
label_1032a4:
    // 0x1032a4: 0x95220004  lhu         $v0, 0x4($t1)
    ctx->pc = 0x1032a4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 4)));
    // 0x1032a8: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x1032a8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1032ac: 0x95260006  lhu         $a2, 0x6($t1)
    ctx->pc = 0x1032acu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 6)));
    // 0x1032b0: 0x3484e000  ori         $a0, $a0, 0xE000
    ctx->pc = 0x1032b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)57344);
    // 0x1032b4: 0x9525000a  lhu         $a1, 0xA($t1)
    ctx->pc = 0x1032b4u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 10)));
    // 0x1032b8: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1032b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1032bc: 0x8d280010  lw          $t0, 0x10($t1)
    ctx->pc = 0x1032bcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x1032c0: 0x463025  or          $a2, $v0, $a2
    ctx->pc = 0x1032c0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x1032c4: 0x95270008  lhu         $a3, 0x8($t1)
    ctx->pc = 0x1032c4u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1032c8: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1032c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1032cc: 0xac8a0000  sw          $t2, 0x0($a0)
    ctx->pc = 0x1032ccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 10));
    // 0x1032d0: 0x3463e020  ori         $v1, $v1, 0xE020
    ctx->pc = 0x1032d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)57376);
    // 0x1032d4: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x1032d4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1032d8: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1032d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1032dc: 0xac660000  sw          $a2, 0x0($v1)
    ctx->pc = 0x1032dcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6)); // MMIO: 0x10000000
    // 0x1032e0: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x1032e0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1032e4: 0x3442e030  ori         $v0, $v0, 0xE030
    ctx->pc = 0x1032e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57392);
    // 0x1032e8: 0x8d26000c  lw          $a2, 0xC($t1)
    ctx->pc = 0x1032e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x1032ec: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x1032ecu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x1032f0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1032f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1032f4: 0x3463e050  ori         $v1, $v1, 0xE050
    ctx->pc = 0x1032f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)57424);
    // 0x1032f8: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1032f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1032fc: 0xac660000  sw          $a2, 0x0($v1)
    ctx->pc = 0x1032fcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6)); // MMIO: 0x10000000
    // 0x103300: 0x3442e040  ori         $v0, $v0, 0xE040
    ctx->pc = 0x103300u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57408);
    // 0x103304: 0xac480000  sw          $t0, 0x0($v0)
    ctx->pc = 0x103304u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 8)); // MMIO: 0x10000000
    // 0x103308: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x103308u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x10330c: 0x2466a218  addiu       $a2, $v1, -0x5DE8
    ctx->pc = 0x10330cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 4294943256));
    // 0x103310: 0x69220007  ldl         $v0, 0x7($t1)
    ctx->pc = 0x103310u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x103314: 0x6d220000  ldr         $v0, 0x0($t1)
    ctx->pc = 0x103314u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x103318: 0x6924000f  ldl         $a0, 0xF($t1)
    ctx->pc = 0x103318u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x10331c: 0x6d240008  ldr         $a0, 0x8($t1)
    ctx->pc = 0x10331cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x103320: 0x8d250010  lw          $a1, 0x10($t1)
    ctx->pc = 0x103320u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x103324: 0xb0c20007  sdl         $v0, 0x7($a2)
    ctx->pc = 0x103324u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103328: 0xb4c20000  sdr         $v0, 0x0($a2)
    ctx->pc = 0x103328u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x10332c: 0xb0c4000f  sdl         $a0, 0xF($a2)
    ctx->pc = 0x10332cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103330: 0xb4c40008  sdr         $a0, 0x8($a2)
    ctx->pc = 0x103330u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103334: 0xacc50010  sw          $a1, 0x10($a2)
    ctx->pc = 0x103334u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 5));
    // 0x103338: 0x3e00008  jr          $ra
    ctx->pc = 0x103338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10333Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103338u;
            // 0x10333c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103340u;
    // 0x103340: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x103340u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x103344: 0x2468a218  addiu       $t0, $v1, -0x5DE8
    ctx->pc = 0x103344u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), 4294943256));
    // 0x103348: 0x69050007  ldl         $a1, 0x7($t0)
    ctx->pc = 0x103348u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x10334c: 0x6d050000  ldr         $a1, 0x0($t0)
    ctx->pc = 0x10334cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x103350: 0x6906000f  ldl         $a2, 0xF($t0)
    ctx->pc = 0x103350u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x103354: 0x6d060008  ldr         $a2, 0x8($t0)
    ctx->pc = 0x103354u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x103358: 0x8d070010  lw          $a3, 0x10($t0)
    ctx->pc = 0x103358u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 16)));
    // 0x10335c: 0xb0850007  sdl         $a1, 0x7($a0)
    ctx->pc = 0x10335cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103360: 0xb4850000  sdr         $a1, 0x0($a0)
    ctx->pc = 0x103360u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103364: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x103364u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x103368: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x103368u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x10336c: 0xac870010  sw          $a3, 0x10($a0)
    ctx->pc = 0x10336cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 7));
    // 0x103370: 0x3e00008  jr          $ra
    ctx->pc = 0x103370u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103370u;
            // 0x103374: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103378u;
    // 0x103378: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x103378u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x10337c: 0x3463e060  ori         $v1, $v1, 0xE060
    ctx->pc = 0x10337cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)57440);
    // 0x103380: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x103380u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x103384: 0x3e00008  jr          $ra
    ctx->pc = 0x103384u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103384u;
            // 0x103388: 0xac640000  sw          $a0, 0x0($v1) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1031C0u: goto label_1031c0;
            case 0x1031D4u: goto label_1031d4;
            case 0x1031E8u: goto label_1031e8;
            case 0x1031FCu: goto label_1031fc;
            case 0x103298u: goto label_103298;
            case 0x1032A4u: goto label_1032a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10338Cu;
    // 0x10338c: 0x0  nop
    ctx->pc = 0x10338cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
