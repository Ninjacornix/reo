#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7550
// Address: 0x1a7550 - 0x1a7690
void sub_001A7550_0x1a7550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7550_0x1a7550");
#endif

    switch (ctx->pc) {
        case 0x1a7590u: goto label_1a7590;
        default: break;
    }

    ctx->pc = 0x1a7550u;

    // 0x1a7550: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7550u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7554: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a7554u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a7558: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7558u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a755c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a755cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7560: 0x8c280a68  lw          $t0, 0xA68($at)
    ctx->pc = 0x1a7560u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7564: 0x24630a80  addiu       $v1, $v1, 0xA80
    ctx->pc = 0x1a7564u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2688));
    // 0x1a7568: 0x81040  sll         $v0, $t0, 1
    ctx->pc = 0x1a7568u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1a756c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1a756cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1a7570: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1a7570u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1a7574: 0x625021  addu        $t2, $v1, $v0
    ctx->pc = 0x1a7574u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a7578: 0x8d430000  lw          $v1, 0x0($t2)
    ctx->pc = 0x1a7578u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1a757c: 0x4600006  bltz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A757Cu;
    {
        const bool branch_taken_0x1a757c = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1A7580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A757Cu;
            // 0x1a7580: 0x51e3c  dsll32      $v1, $a1, 24 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a757c) {
            ctx->pc = 0x1A7598u;
            goto label_1a7598;
        }
    }
    ctx->pc = 0x1A7584u;
    // 0x1a7584: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7584u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7588: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7588u;
    SET_GPR_U32(ctx, 31, 0x1A7590u);
    ctx->pc = 0x1A758Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7588u;
            // 0x1a758c: 0x24842120  addiu       $a0, $a0, 0x2120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7590u; }
        if (ctx->pc != 0x1A7590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7590u; }
        if (ctx->pc != 0x1A7590u) { return; }
    }
    ctx->pc = 0x1A7590u;
label_1a7590:
    // 0x1a7590: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1A7590u;
    {
        const bool branch_taken_0x1a7590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7590u;
            // 0x1a7594: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7590) {
            ctx->pc = 0x1A767Cu;
            goto label_1a767c;
        }
    }
    ctx->pc = 0x1A7598u;
label_1a7598:
    // 0x1a7598: 0x6463c  dsll32      $t0, $a2, 24
    ctx->pc = 0x1a7598u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) << (32 + 24));
    // 0x1a759c: 0x31e3f  dsra32      $v1, $v1, 24
    ctx->pc = 0x1a759cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 24));
    // 0x1a75a0: 0x8463f  dsra32      $t0, $t0, 24
    ctx->pc = 0x1a75a0u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 8) >> (32 + 24));
    // 0x1a75a4: 0x60182a  slt         $v1, $v1, $zero
    ctx->pc = 0x1a75a4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
    // 0x1a75a8: 0x100482a  slt         $t1, $t0, $zero
    ctx->pc = 0x1a75a8u;
    SET_GPR_U64(ctx, 9, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
    // 0x1a75ac: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1a75acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1a75b0: 0x39290001  xori        $t1, $t1, 0x1
    ctx->pc = 0x1a75b0u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) ^ (uint64_t)(uint16_t)1);
    // 0x1a75b4: 0x30680001  andi        $t0, $v1, 0x1
    ctx->pc = 0x1a75b4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1a75b8: 0x31230001  andi        $v1, $t1, 0x1
    ctx->pc = 0x1a75b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)1);
    // 0x1a75bc: 0x35080008  ori         $t0, $t0, 0x8
    ctx->pc = 0x1a75bcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)8);
    // 0x1a75c0: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1a75c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1a75c4: 0x1034825  or          $t1, $t0, $v1
    ctx->pc = 0x1a75c4u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1a75c8: 0x71c3c  dsll32      $v1, $a3, 16
    ctx->pc = 0x1a75c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 16));
    // 0x1a75cc: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1a75ccu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1a75d0: 0x60402a  slt         $t0, $v1, $zero
    ctx->pc = 0x1a75d0u;
    SET_GPR_U64(ctx, 8, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
    // 0x1a75d4: 0x39080001  xori        $t0, $t0, 0x1
    ctx->pc = 0x1a75d4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) ^ (uint64_t)(uint16_t)1);
    // 0x1a75d8: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1a75d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a75dc: 0x84080  sll         $t0, $t0, 2
    ctx->pc = 0x1a75dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1a75e0: 0x1094025  or          $t0, $t0, $t1
    ctx->pc = 0x1a75e0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 9));
    // 0x1a75e4: 0x8463c  dsll32      $t0, $t0, 24
    ctx->pc = 0x1a75e4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << (32 + 24));
    // 0x1a75e8: 0x8463f  dsra32      $t0, $t0, 24
    ctx->pc = 0x1a75e8u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 8) >> (32 + 24));
    // 0x1a75ec: 0x15030003  bne         $t0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A75ECu;
    {
        const bool branch_taken_0x1a75ec = (GPR_U64(ctx, 8) != GPR_U64(ctx, 3));
        if (branch_taken_0x1a75ec) {
            ctx->pc = 0x1A75FCu;
            goto label_1a75fc;
        }
    }
    ctx->pc = 0x1A75F4u;
    // 0x1a75f4: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1A75F4u;
    {
        const bool branch_taken_0x1a75f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A75F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A75F4u;
            // 0x1a75f8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a75f4) {
            ctx->pc = 0x1A767Cu;
            goto label_1a767c;
        }
    }
    ctx->pc = 0x1A75FCu;
label_1a75fc:
    // 0x1a75fc: 0x41a3c  dsll32      $v1, $a0, 8
    ctx->pc = 0x1a75fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 8));
    // 0x1a7600: 0x84600  sll         $t0, $t0, 24
    ctx->pc = 0x1a7600u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 24));
    // 0x1a7604: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a7604u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a7608: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7608u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a760c: 0x1032025  or          $a0, $t0, $v1
    ctx->pc = 0x1a760cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1a7610: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a7610u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a7614: 0xad440000  sw          $a0, 0x0($t2)
    ctx->pc = 0x1a7614u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 4));
    // 0x1a7618: 0x24630a84  addiu       $v1, $v1, 0xA84
    ctx->pc = 0x1a7618u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2692));
    // 0x1a761c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1a761cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a7620: 0xa0650000  sb          $a1, 0x0($v1)
    ctx->pc = 0x1a7620u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1a7624: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a7624u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a7628: 0x24630a85  addiu       $v1, $v1, 0xA85
    ctx->pc = 0x1a7628u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2693));
    // 0x1a762c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1a762cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a7630: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a7630u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a7634: 0xa0860000  sb          $a2, 0x0($a0)
    ctx->pc = 0x1a7634u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1a7638: 0x24630a86  addiu       $v1, $v1, 0xA86
    ctx->pc = 0x1a7638u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2694));
    // 0x1a763c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1a763cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a7640: 0xa4670000  sh          $a3, 0x0($v1)
    ctx->pc = 0x1a7640u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 7));
    // 0x1a7644: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a7644u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a7648: 0x24630a88  addiu       $v1, $v1, 0xA88
    ctx->pc = 0x1a7648u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2696));
    // 0x1a764c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a764cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a7650: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1a7650u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a7654: 0x8c220a68  lw          $v0, 0xA68($at)
    ctx->pc = 0x1a7654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7658: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1a7658u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a765c: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A765Cu;
    {
        const bool branch_taken_0x1a765c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A765Cu;
            // 0x1a7660: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a765c) {
            ctx->pc = 0x1A7670u;
            goto label_1a7670;
        }
    }
    ctx->pc = 0x1A7664u;
    // 0x1a7664: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7664u;
    {
        const bool branch_taken_0x1a7664 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7664) {
            ctx->pc = 0x1A7670u;
            goto label_1a7670;
        }
    }
    ctx->pc = 0x1A766Cu;
    // 0x1a766c: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a766cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a7670:
    // 0x1a7670: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7670u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7674: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7674u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7678: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7678u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a767c:
    // 0x1a767c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a767cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7680: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7680u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7680u;
            // 0x1a7684: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7590u: goto label_1a7590;
            case 0x1A7598u: goto label_1a7598;
            case 0x1A75FCu: goto label_1a75fc;
            case 0x1A7670u: goto label_1a7670;
            case 0x1A767Cu: goto label_1a767c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7688u;
    // 0x1a7688: 0x0  nop
    ctx->pc = 0x1a7688u;
    // NOP
    // 0x1a768c: 0x0  nop
    ctx->pc = 0x1a768cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
