#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001235E8
// Address: 0x1235e8 - 0x123700
void sub_001235E8_0x1235e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001235E8_0x1235e8");
#endif

    switch (ctx->pc) {
        case 0x123654u: goto label_123654;
        default: break;
    }

    ctx->pc = 0x1235e8u;

    // 0x1235e8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1235e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1235ec: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1235ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1235f0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1235f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1235f4: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x1235f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x1235f8: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x1235f8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1235fc: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x1235fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x123600: 0x2611000e  addiu       $s1, $s0, 0xE
    ctx->pc = 0x123600u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 14));
    // 0x123604: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x123604u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x123608: 0x2612000f  addiu       $s2, $s0, 0xF
    ctx->pc = 0x123608u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x12360c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x12360cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x123610: 0x26130010  addiu       $s3, $s0, 0x10
    ctx->pc = 0x123610u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x123614: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x123614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x123618: 0x2614000d  addiu       $s4, $s0, 0xD
    ctx->pc = 0x123618u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), 13));
    // 0x12361c: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x12361cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x123620: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x123620u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123624: 0xa6150002  sh          $s5, 0x2($s0)
    ctx->pc = 0x123624u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 21));
    // 0x123628: 0x26020018  addiu       $v0, $s0, 0x18
    ctx->pc = 0x123628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x12362c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x12362cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123630: 0x27a60010  addiu       $a2, $sp, 0x10
    ctx->pc = 0x123630u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x123634: 0x2607000c  addiu       $a3, $s0, 0xC
    ctx->pc = 0x123634u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x123638: 0x280402d  daddu       $t0, $s4, $zero
    ctx->pc = 0x123638u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12363c: 0x240482d  daddu       $t1, $s2, $zero
    ctx->pc = 0x12363cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123640: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x123640u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123644: 0x260b0014  addiu       $t3, $s0, 0x14
    ctx->pc = 0x123644u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x123648: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x123648u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x12364c: 0xc048d36  jal         func_1234D8
    ctx->pc = 0x12364Cu;
    SET_GPR_U32(ctx, 31, 0x123654u);
    ctx->pc = 0x123650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12364Cu;
            // 0x123650: 0xafb30008  sw          $s3, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1234D8u;
    if (runtime->hasFunction(0x1234D8u)) {
        auto targetFn = runtime->lookupFunction(0x1234D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123654u; }
        if (ctx->pc != 0x123654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001234D8_0x1234d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123654u; }
        if (ctx->pc != 0x123654u) { return; }
    }
    ctx->pc = 0x123654u;
label_123654:
    // 0x123654: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x123654u;
    {
        const bool branch_taken_0x123654 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x123658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123654u;
            // 0x123658: 0x24070008  addiu       $a3, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123654) {
            ctx->pc = 0x123668u;
            goto label_123668;
        }
    }
    ctx->pc = 0x12365Cu;
    // 0x12365c: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x12365Cu;
    {
        const bool branch_taken_0x12365c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12365Cu;
            // 0x123660: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12365c) {
            ctx->pc = 0x1236DCu;
            goto label_1236dc;
        }
    }
    ctx->pc = 0x123664u;
    // 0x123664: 0x0  nop
    ctx->pc = 0x123664u;
    // NOP
label_123668:
    // 0x123668: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x123668u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x12366c: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x12366cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x123670: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x123670u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x123674: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x123674u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x123678: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x123678u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x12367c: 0xa600001c  sh          $zero, 0x1C($s0)
    ctx->pc = 0x12367cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x123680: 0xa6000026  sh          $zero, 0x26($s0)
    ctx->pc = 0x123680u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x123684: 0xa6000024  sh          $zero, 0x24($s0)
    ctx->pc = 0x123684u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x123688: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x123688u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x12368c: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x12368cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x123690: 0x8e050040  lw          $a1, 0x40($s0)
    ctx->pc = 0x123690u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x123694: 0xae020050  sw          $v0, 0x50($s0)
    ctx->pc = 0x123694u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 2));
    // 0x123698: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x123698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12369c: 0x8e060044  lw          $a2, 0x44($s0)
    ctx->pc = 0x12369cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x1236a0: 0x82430000  lb          $v1, 0x0($s2)
    ctx->pc = 0x1236a0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1236a4: 0xae04005c  sw          $a0, 0x5C($s0)
    ctx->pc = 0x1236a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 4));
    // 0x1236a8: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x1236a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x1236ac: 0xa6020098  sh          $v0, 0x98($s0)
    ctx->pc = 0x1236acu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 2));
    // 0x1236b0: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x1236b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1236b4: 0xae050060  sw          $a1, 0x60($s0)
    ctx->pc = 0x1236b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 5));
    // 0x1236b8: 0xae030058  sw          $v1, 0x58($s0)
    ctx->pc = 0x1236b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 3));
    // 0x1236bc: 0xae060064  sw          $a2, 0x64($s0)
    ctx->pc = 0x1236bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 6));
    // 0x1236c0: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x1236c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
    // 0x1236c4: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x1236c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
    // 0x1236c8: 0x82820000  lb          $v0, 0x0($s4)
    ctx->pc = 0x1236c8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1236cc: 0x54470002  bnel        $v0, $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x1236CCu;
    {
        const bool branch_taken_0x1236cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        if (branch_taken_0x1236cc) {
            ctx->pc = 0x1236D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1236CCu;
            // 0x1236d0: 0xa600009a  sh          $zero, 0x9A($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 154), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1236D8u;
            goto label_1236d8;
        }
    }
    ctx->pc = 0x1236D4u;
    // 0x1236d4: 0xa615009a  sh          $s5, 0x9A($s0)
    ctx->pc = 0x1236d4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 154), (uint16_t)GPR_U32(ctx, 21));
label_1236d8:
    // 0x1236d8: 0x87a20010  lh          $v0, 0x10($sp)
    ctx->pc = 0x1236d8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 16)));
label_1236dc:
    // 0x1236dc: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1236dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1236e0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x1236e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1236e4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1236e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1236e8: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x1236e8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1236ec: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x1236ecu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1236f0: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x1236f0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1236f4: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1236f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1236f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1236F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1236FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1236F8u;
            // 0x1236fc: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123654u: goto label_123654;
            case 0x123668u: goto label_123668;
            case 0x1236D8u: goto label_1236d8;
            case 0x1236DCu: goto label_1236dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123700u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
