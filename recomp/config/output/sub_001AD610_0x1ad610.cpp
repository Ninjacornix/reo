#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD610
// Address: 0x1ad610 - 0x1ad790
void sub_001AD610_0x1ad610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD610_0x1ad610");
#endif

    switch (ctx->pc) {
        case 0x1ad6b4u: goto label_1ad6b4;
        case 0x1ad774u: goto label_1ad774;
        case 0x1ad77cu: goto label_1ad77c;
        default: break;
    }

    ctx->pc = 0x1ad610u;

    // 0x1ad610: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1ad610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ad614: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ad614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ad618: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ad618u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ad61c: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD61Cu;
    {
        const bool branch_taken_0x1ad61c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AD620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD61Cu;
            // 0x1ad620: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad61c) {
            ctx->pc = 0x1AD62Cu;
            goto label_1ad62c;
        }
    }
    ctx->pc = 0x1AD624u;
    // 0x1ad624: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1AD624u;
    {
        const bool branch_taken_0x1ad624 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD624u;
            // 0x1ad628: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad624) {
            ctx->pc = 0x1AD6ECu;
            goto label_1ad6ec;
        }
    }
    ctx->pc = 0x1AD62Cu;
label_1ad62c:
    // 0x1ad62c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ad62cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ad630: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ad630u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ad634: 0x90234405  lbu         $v1, 0x4405($at)
    ctx->pc = 0x1ad634u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17413)));
    // 0x1ad638: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD638u;
    {
        const bool branch_taken_0x1ad638 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1AD63Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD638u;
            // 0x1ad63c: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad638) {
            ctx->pc = 0x1AD648u;
            goto label_1ad648;
        }
    }
    ctx->pc = 0x1AD640u;
    // 0x1ad640: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1AD640u;
    {
        const bool branch_taken_0x1ad640 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD640u;
            // 0x1ad644: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad640) {
            ctx->pc = 0x1AD6ECu;
            goto label_1ad6ec;
        }
    }
    ctx->pc = 0x1AD648u;
label_1ad648:
    // 0x1ad648: 0x3c11002b  lui         $s1, 0x2B
    ctx->pc = 0x1ad648u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)43 << 16));
    // 0x1ad64c: 0x90223841  lbu         $v0, 0x3841($at)
    ctx->pc = 0x1ad64cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 14401)));
    // 0x1ad650: 0x28420008  slti        $v0, $v0, 0x8
    ctx->pc = 0x1ad650u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1ad654: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD654u;
    {
        const bool branch_taken_0x1ad654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AD658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD654u;
            // 0x1ad658: 0x26313840  addiu       $s1, $s1, 0x3840 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 14400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad654) {
            ctx->pc = 0x1AD664u;
            goto label_1ad664;
        }
    }
    ctx->pc = 0x1AD65Cu;
    // 0x1ad65c: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1AD65Cu;
    {
        const bool branch_taken_0x1ad65c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD65Cu;
            // 0x1ad660: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad65c) {
            ctx->pc = 0x1AD6ECu;
            goto label_1ad6ec;
        }
    }
    ctx->pc = 0x1AD664u;
label_1ad664:
    // 0x1ad664: 0x92230003  lbu         $v1, 0x3($s1)
    ctx->pc = 0x1ad664u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1ad668: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1ad668u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ad66c: 0x305000ff  andi        $s0, $v0, 0xFF
    ctx->pc = 0x1ad66cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ad670: 0x2a020008  slti        $v0, $s0, 0x8
    ctx->pc = 0x1ad670u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1ad674: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AD674u;
    {
        const bool branch_taken_0x1ad674 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AD678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD674u;
            // 0x1ad678: 0x306200ff  andi        $v0, $v1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad674) {
            ctx->pc = 0x1AD680u;
            goto label_1ad680;
        }
    }
    ctx->pc = 0x1AD67Cu;
    // 0x1ad67c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1ad67cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ad680:
    // 0x1ad680: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1ad680u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1ad684: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1ad684u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ad688: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1ad688u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1ad68c: 0xa4400014  sh          $zero, 0x14($v0)
    ctx->pc = 0x1ad68cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 20), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ad690: 0x92220003  lbu         $v0, 0x3($s1)
    ctx->pc = 0x1ad690u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1ad694: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1ad694u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1ad698: 0xa045000c  sb          $a1, 0xC($v0)
    ctx->pc = 0x1ad698u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 12), (uint8_t)GPR_U32(ctx, 5));
    // 0x1ad69c: 0x92220003  lbu         $v0, 0x3($s1)
    ctx->pc = 0x1ad69cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1ad6a0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1ad6a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad6a4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1ad6a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ad6a8: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x1ad6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1ad6ac: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AD6ACu;
    SET_GPR_U32(ctx, 31, 0x1AD6B4u);
    ctx->pc = 0x1AD6B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD6ACu;
            // 0x1ad6b0: 0x24440024  addiu       $a0, $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD6B4u; }
        if (ctx->pc != 0x1AD6B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD6B4u; }
        if (ctx->pc != 0x1AD6B4u) { return; }
    }
    ctx->pc = 0x1AD6B4u;
label_1ad6b4:
    // 0x1ad6b4: 0x92220003  lbu         $v0, 0x3($s1)
    ctx->pc = 0x1ad6b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1ad6b8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1ad6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ad6bc: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1ad6bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1ad6c0: 0xa0400033  sb          $zero, 0x33($v0)
    ctx->pc = 0x1ad6c0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 51), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ad6c4: 0xa2300003  sb          $s0, 0x3($s1)
    ctx->pc = 0x1ad6c4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 16));
    // 0x1ad6c8: 0x92220001  lbu         $v0, 0x1($s1)
    ctx->pc = 0x1ad6c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1ad6cc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ad6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ad6d0: 0xa2220001  sb          $v0, 0x1($s1)
    ctx->pc = 0x1ad6d0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad6d4: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1ad6d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ad6d8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AD6D8u;
    {
        const bool branch_taken_0x1ad6d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AD6DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD6D8u;
            // 0x1ad6dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad6d8) {
            ctx->pc = 0x1AD6ECu;
            goto label_1ad6ec;
        }
    }
    ctx->pc = 0x1AD6E0u;
    // 0x1ad6e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ad6e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ad6e4: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1ad6e4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ad6e8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ad6e8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ad6ec:
    // 0x1ad6ec: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ad6ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ad6f0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ad6f0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ad6f4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ad6f4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ad6f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD6F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD6FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD6F8u;
            // 0x1ad6fc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD62Cu: goto label_1ad62c;
            case 0x1AD648u: goto label_1ad648;
            case 0x1AD664u: goto label_1ad664;
            case 0x1AD680u: goto label_1ad680;
            case 0x1AD6B4u: goto label_1ad6b4;
            case 0x1AD6ECu: goto label_1ad6ec;
            case 0x1AD724u: goto label_1ad724;
            case 0x1AD740u: goto label_1ad740;
            case 0x1AD774u: goto label_1ad774;
            case 0x1AD77Cu: goto label_1ad77c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD700u;
    // 0x1ad700: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1ad700u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1ad704: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1ad704u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1ad708: 0x24423934  addiu       $v0, $v0, 0x3934
    ctx->pc = 0x1ad708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14644));
    // 0x1ad70c: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1ad70cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ad710: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1ad710u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ad714: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD714u;
    {
        const bool branch_taken_0x1ad714 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AD718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD714u;
            // 0x1ad718: 0x24633840  addiu       $v1, $v1, 0x3840 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 14400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad714) {
            ctx->pc = 0x1AD724u;
            goto label_1ad724;
        }
    }
    ctx->pc = 0x1AD71Cu;
    // 0x1ad71c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AD71Cu;
    {
        const bool branch_taken_0x1ad71c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD71Cu;
            // 0x1ad720: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad71c) {
            ctx->pc = 0x1AD740u;
            goto label_1ad740;
        }
    }
    ctx->pc = 0x1AD724u;
label_1ad724:
    // 0x1ad724: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1ad724u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1ad728: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ad728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ad72c: 0x906300e4  lbu         $v1, 0xE4($v1)
    ctx->pc = 0x1ad72cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 228)));
    // 0x1ad730: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD730u;
    {
        const bool branch_taken_0x1ad730 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1AD734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD730u;
            // 0x1ad734: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad730) {
            ctx->pc = 0x1AD740u;
            goto label_1ad740;
        }
    }
    ctx->pc = 0x1AD738u;
    // 0x1ad738: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1AD738u;
    {
        const bool branch_taken_0x1ad738 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD73Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD738u;
            // 0x1ad73c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad738) {
            ctx->pc = 0x1AD740u;
            goto label_1ad740;
        }
    }
    ctx->pc = 0x1AD740u;
label_1ad740:
    // 0x1ad740: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD740u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD62Cu: goto label_1ad62c;
            case 0x1AD648u: goto label_1ad648;
            case 0x1AD664u: goto label_1ad664;
            case 0x1AD680u: goto label_1ad680;
            case 0x1AD6B4u: goto label_1ad6b4;
            case 0x1AD6ECu: goto label_1ad6ec;
            case 0x1AD724u: goto label_1ad724;
            case 0x1AD740u: goto label_1ad740;
            case 0x1AD774u: goto label_1ad774;
            case 0x1AD77Cu: goto label_1ad77c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD748u;
    // 0x1ad748: 0x0  nop
    ctx->pc = 0x1ad748u;
    // NOP
    // 0x1ad74c: 0x0  nop
    ctx->pc = 0x1ad74cu;
    // NOP
    // 0x1ad750: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ad750u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ad754: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1ad754u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1ad758: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ad758u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ad75c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad75cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad760: 0x8c223944  lw          $v0, 0x3944($at)
    ctx->pc = 0x1ad760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14660)));
    // 0x1ad764: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AD764u;
    {
        const bool branch_taken_0x1ad764 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD764u;
            // 0x1ad768: 0x24633840  addiu       $v1, $v1, 0x3840 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 14400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad764) {
            ctx->pc = 0x1AD774u;
            goto label_1ad774;
        }
    }
    ctx->pc = 0x1AD76Cu;
    // 0x1ad76c: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x1AD76Cu;
    SET_GPR_U32(ctx, 31, 0x1AD774u);
    ctx->pc = 0x1AD770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD76Cu;
            // 0x1ad770: 0x8c640104  lw          $a0, 0x104($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 260)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD774u; }
        if (ctx->pc != 0x1AD774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD774u; }
        if (ctx->pc != 0x1AD774u) { return; }
    }
    ctx->pc = 0x1AD774u;
label_1ad774:
    // 0x1ad774: 0xc06b570  jal         func_1AD5C0
    ctx->pc = 0x1AD774u;
    SET_GPR_U32(ctx, 31, 0x1AD77Cu);
    ctx->pc = 0x1AD5C0u;
    if (runtime->hasFunction(0x1AD5C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AD5C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD77Cu; }
        if (ctx->pc != 0x1AD77Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD5C0_0x1ad5c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD77Cu; }
        if (ctx->pc != 0x1AD77Cu) { return; }
    }
    ctx->pc = 0x1AD77Cu;
label_1ad77c:
    // 0x1ad77c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ad77cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ad780: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD780u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD780u;
            // 0x1ad784: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD62Cu: goto label_1ad62c;
            case 0x1AD648u: goto label_1ad648;
            case 0x1AD664u: goto label_1ad664;
            case 0x1AD680u: goto label_1ad680;
            case 0x1AD6B4u: goto label_1ad6b4;
            case 0x1AD6ECu: goto label_1ad6ec;
            case 0x1AD724u: goto label_1ad724;
            case 0x1AD740u: goto label_1ad740;
            case 0x1AD774u: goto label_1ad774;
            case 0x1AD77Cu: goto label_1ad77c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD788u;
    // 0x1ad788: 0x0  nop
    ctx->pc = 0x1ad788u;
    // NOP
    // 0x1ad78c: 0x0  nop
    ctx->pc = 0x1ad78cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
