#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C2600
// Address: 0x1c2600 - 0x1c2940
void sub_001C2600_0x1c2600(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C2600_0x1c2600");
#endif

    switch (ctx->pc) {
        case 0x1c2670u: goto label_1c2670;
        case 0x1c26dcu: goto label_1c26dc;
        default: break;
    }

    ctx->pc = 0x1c2600u;

    // 0x1c2600: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c2600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c2604: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2604u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2608: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c2608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c260c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c260cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c2610: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c2610u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c2614: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c2614u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2618: 0x902243c0  lbu         $v0, 0x43C0($at)
    ctx->pc = 0x1c2618u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17344)));
    // 0x1c261c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C261Cu;
    {
        const bool branch_taken_0x1c261c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C261Cu;
            // 0x1c2620: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c261c) {
            ctx->pc = 0x1C2640u;
            goto label_1c2640;
        }
    }
    ctx->pc = 0x1C2624u;
    // 0x1c2624: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2624u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2628: 0x3c02000a  lui         $v0, 0xA
    ctx->pc = 0x1c2628u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)10 << 16));
    // 0x1c262c: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1c262cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1c2630: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1c2630u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c2634: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2634u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2638: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C2638u;
    {
        const bool branch_taken_0x1c2638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C263Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2638u;
            // 0x1c263c: 0xac226f10  sw          $v0, 0x6F10($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 28432), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2638) {
            ctx->pc = 0x1C265Cu;
            goto label_1c265c;
        }
    }
    ctx->pc = 0x1C2640u;
label_1c2640:
    // 0x1c2640: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2640u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2644: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1c2644u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1c2648: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1c2648u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1c264c: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x1c264cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x1c2650: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1c2650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c2654: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2654u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2658: 0xac226f10  sw          $v0, 0x6F10($at)
    ctx->pc = 0x1c2658u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 28432), GPR_U32(ctx, 2));
label_1c265c:
    // 0x1c265c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c265cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2660: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c2660u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2664: 0x8c246f10  lw          $a0, 0x6F10($at)
    ctx->pc = 0x1c2664u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c2668: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C2668u;
    SET_GPR_U32(ctx, 31, 0x1C2670u);
    ctx->pc = 0x1C266Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2668u;
            // 0x1c266c: 0x240600f4  addiu       $a2, $zero, 0xF4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 244));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2670u; }
        if (ctx->pc != 0x1C2670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2670u; }
        if (ctx->pc != 0x1C2670u) { return; }
    }
    ctx->pc = 0x1C2670u;
label_1c2670:
    // 0x1c2670: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2670u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2674: 0x3c030004  lui         $v1, 0x4
    ctx->pc = 0x1c2674u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4 << 16));
    // 0x1c2678: 0x8c226f10  lw          $v0, 0x6F10($at)
    ctx->pc = 0x1c2678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c267c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1c267cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2680: 0xac4200e4  sw          $v0, 0xE4($v0)
    ctx->pc = 0x1c2680u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 228), GPR_U32(ctx, 2));
    // 0x1c2684: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2684u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2688: 0x8c256f10  lw          $a1, 0x6F10($at)
    ctx->pc = 0x1c2688u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c268c: 0x8ca200e4  lw          $v0, 0xE4($a1)
    ctx->pc = 0x1c268cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 228)));
    // 0x1c2690: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2690u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2694: 0x24420100  addiu       $v0, $v0, 0x100
    ctx->pc = 0x1c2694u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
    // 0x1c2698: 0xaca200e8  sw          $v0, 0xE8($a1)
    ctx->pc = 0x1c2698u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 232), GPR_U32(ctx, 2));
    // 0x1c269c: 0x8c256f10  lw          $a1, 0x6F10($at)
    ctx->pc = 0x1c269cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c26a0: 0x8ca200e8  lw          $v0, 0xE8($a1)
    ctx->pc = 0x1c26a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 232)));
    // 0x1c26a4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c26a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c26a8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c26a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c26ac: 0xaca200ec  sw          $v0, 0xEC($a1)
    ctx->pc = 0x1c26acu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 236), GPR_U32(ctx, 2));
    // 0x1c26b0: 0x8c256f10  lw          $a1, 0x6F10($at)
    ctx->pc = 0x1c26b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c26b4: 0x8ca200ec  lw          $v0, 0xEC($a1)
    ctx->pc = 0x1c26b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 236)));
    // 0x1c26b8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c26b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c26bc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c26bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c26c0: 0xaca200f0  sw          $v0, 0xF0($a1)
    ctx->pc = 0x1c26c0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 240), GPR_U32(ctx, 2));
    // 0x1c26c4: 0x8c226f10  lw          $v0, 0x6F10($at)
    ctx->pc = 0x1c26c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c26c8: 0xac510020  sw          $s1, 0x20($v0)
    ctx->pc = 0x1c26c8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 17));
    // 0x1c26cc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c26ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c26d0: 0x8c226f10  lw          $v0, 0x6F10($at)
    ctx->pc = 0x1c26d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c26d4: 0xc0700dc  jal         func_1C0370
    ctx->pc = 0x1C26D4u;
    SET_GPR_U32(ctx, 31, 0x1C26DCu);
    ctx->pc = 0x1C26D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C26D4u;
            // 0x1c26d8: 0xac50001c  sw          $s0, 0x1C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C0370u;
    if (runtime->hasFunction(0x1C0370u)) {
        auto targetFn = runtime->lookupFunction(0x1C0370u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C26DCu; }
        if (ctx->pc != 0x1C26DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0370_0x1c0370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C26DCu; }
        if (ctx->pc != 0x1C26DCu) { return; }
    }
    ctx->pc = 0x1C26DCu;
label_1c26dc:
    // 0x1c26dc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c26dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c26e0: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x1c26e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c26e4: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c26e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c26e8: 0x8c640020  lw          $a0, 0x20($v1)
    ctx->pc = 0x1c26e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1c26ec: 0x10880076  beq         $a0, $t0, . + 4 + (0x76 << 2)
    ctx->pc = 0x1C26ECu;
    {
        const bool branch_taken_0x1c26ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 8));
        ctx->pc = 0x1C26F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C26ECu;
            // 0x1c26f0: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c26ec) {
            ctx->pc = 0x1C28C8u;
            goto label_1c28c8;
        }
    }
    ctx->pc = 0x1C26F4u;
    // 0x1c26f4: 0x10870058  beq         $a0, $a3, . + 4 + (0x58 << 2)
    ctx->pc = 0x1C26F4u;
    {
        const bool branch_taken_0x1c26f4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 7));
        ctx->pc = 0x1C26F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C26F4u;
            // 0x1c26f8: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c26f4) {
            ctx->pc = 0x1C2858u;
            goto label_1c2858;
        }
    }
    ctx->pc = 0x1C26FCu;
    // 0x1c26fc: 0x1086003d  beq         $a0, $a2, . + 4 + (0x3D << 2)
    ctx->pc = 0x1C26FCu;
    {
        const bool branch_taken_0x1c26fc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 6));
        ctx->pc = 0x1C2700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C26FCu;
            // 0x1c2700: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c26fc) {
            ctx->pc = 0x1C27F4u;
            goto label_1c27f4;
        }
    }
    ctx->pc = 0x1C2704u;
    // 0x1c2704: 0x10850023  beq         $a0, $a1, . + 4 + (0x23 << 2)
    ctx->pc = 0x1C2704u;
    {
        const bool branch_taken_0x1c2704 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 5));
        if (branch_taken_0x1c2704) {
            ctx->pc = 0x1C2794u;
            goto label_1c2794;
        }
    }
    ctx->pc = 0x1C270Cu;
    // 0x1c270c: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C270Cu;
    {
        const bool branch_taken_0x1c270c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c270c) {
            ctx->pc = 0x1C271Cu;
            goto label_1c271c;
        }
    }
    ctx->pc = 0x1C2714u;
    // 0x1c2714: 0x10000086  b           . + 4 + (0x86 << 2)
    ctx->pc = 0x1C2714u;
    {
        const bool branch_taken_0x1c2714 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2714u;
            // 0x1c2718: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2714) {
            ctx->pc = 0x1C2930u;
            goto label_1c2930;
        }
    }
    ctx->pc = 0x1C271Cu;
label_1c271c:
    // 0x1c271c: 0x8c64001c  lw          $a0, 0x1C($v1)
    ctx->pc = 0x1c271cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1c2720: 0x10880082  beq         $a0, $t0, . + 4 + (0x82 << 2)
    ctx->pc = 0x1C2720u;
    {
        const bool branch_taken_0x1c2720 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 8));
        if (branch_taken_0x1c2720) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2728u;
    // 0x1c2728: 0x10870080  beq         $a0, $a3, . + 4 + (0x80 << 2)
    ctx->pc = 0x1C2728u;
    {
        const bool branch_taken_0x1c2728 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 7));
        if (branch_taken_0x1c2728) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2730u;
    // 0x1c2730: 0x1086000d  beq         $a0, $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x1C2730u;
    {
        const bool branch_taken_0x1c2730 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 6));
        if (branch_taken_0x1c2730) {
            ctx->pc = 0x1C2768u;
            goto label_1c2768;
        }
    }
    ctx->pc = 0x1C2738u;
    // 0x1c2738: 0x1085000b  beq         $a0, $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x1C2738u;
    {
        const bool branch_taken_0x1c2738 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 5));
        if (branch_taken_0x1c2738) {
            ctx->pc = 0x1C2768u;
            goto label_1c2768;
        }
    }
    ctx->pc = 0x1C2740u;
    // 0x1c2740: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2740u;
    {
        const bool branch_taken_0x1c2740 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2740u;
            // 0x1c2744: 0x24050030  addiu       $a1, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2740) {
            ctx->pc = 0x1C2750u;
            goto label_1c2750;
        }
    }
    ctx->pc = 0x1C2748u;
    // 0x1c2748: 0x10000078  b           . + 4 + (0x78 << 2)
    ctx->pc = 0x1C2748u;
    {
        const bool branch_taken_0x1c2748 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2748) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2750u;
label_1c2750:
    // 0x1c2750: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2750u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2754: 0xac6500d4  sw          $a1, 0xD4($v1)
    ctx->pc = 0x1c2754u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 212), GPR_U32(ctx, 5));
    // 0x1c2758: 0x24040108  addiu       $a0, $zero, 0x108
    ctx->pc = 0x1c2758u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 264));
    // 0x1c275c: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c275cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c2760: 0x10000072  b           . + 4 + (0x72 << 2)
    ctx->pc = 0x1C2760u;
    {
        const bool branch_taken_0x1c2760 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2760u;
            // 0x1c2764: 0xac6400d8  sw          $a0, 0xD8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 216), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2760) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2768u;
label_1c2768:
    // 0x1c2768: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c2768u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c276c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c276cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2770: 0xac6400dc  sw          $a0, 0xDC($v1)
    ctx->pc = 0x1c2770u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 220), GPR_U32(ctx, 4));
    // 0x1c2774: 0x24050050  addiu       $a1, $zero, 0x50
    ctx->pc = 0x1c2774u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1c2778: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c2778u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c277c: 0x2404008c  addiu       $a0, $zero, 0x8C
    ctx->pc = 0x1c277cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 140));
    // 0x1c2780: 0xac6500d4  sw          $a1, 0xD4($v1)
    ctx->pc = 0x1c2780u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 212), GPR_U32(ctx, 5));
    // 0x1c2784: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2784u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2788: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c2788u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c278c: 0x10000067  b           . + 4 + (0x67 << 2)
    ctx->pc = 0x1C278Cu;
    {
        const bool branch_taken_0x1c278c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C278Cu;
            // 0x1c2790: 0xac6400d8  sw          $a0, 0xD8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 216), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c278c) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2794u;
label_1c2794:
    // 0x1c2794: 0x8c64001c  lw          $a0, 0x1C($v1)
    ctx->pc = 0x1c2794u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1c2798: 0x1086000b  beq         $a0, $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x1C2798u;
    {
        const bool branch_taken_0x1c2798 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 6));
        if (branch_taken_0x1c2798) {
            ctx->pc = 0x1C27C8u;
            goto label_1c27c8;
        }
    }
    ctx->pc = 0x1C27A0u;
    // 0x1c27a0: 0x10850009  beq         $a0, $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C27A0u;
    {
        const bool branch_taken_0x1c27a0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 5));
        if (branch_taken_0x1c27a0) {
            ctx->pc = 0x1C27C8u;
            goto label_1c27c8;
        }
    }
    ctx->pc = 0x1C27A8u;
    // 0x1c27a8: 0x10870007  beq         $a0, $a3, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C27A8u;
    {
        const bool branch_taken_0x1c27a8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 7));
        if (branch_taken_0x1c27a8) {
            ctx->pc = 0x1C27C8u;
            goto label_1c27c8;
        }
    }
    ctx->pc = 0x1C27B0u;
    // 0x1c27b0: 0x1088005e  beq         $a0, $t0, . + 4 + (0x5E << 2)
    ctx->pc = 0x1C27B0u;
    {
        const bool branch_taken_0x1c27b0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 8));
        if (branch_taken_0x1c27b0) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C27B8u;
    // 0x1c27b8: 0x1080005c  beqz        $a0, . + 4 + (0x5C << 2)
    ctx->pc = 0x1C27B8u;
    {
        const bool branch_taken_0x1c27b8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c27b8) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C27C0u;
    // 0x1c27c0: 0x1000005a  b           . + 4 + (0x5A << 2)
    ctx->pc = 0x1C27C0u;
    {
        const bool branch_taken_0x1c27c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c27c0) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C27C8u;
label_1c27c8:
    // 0x1c27c8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c27c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c27cc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c27ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c27d0: 0xac6400dc  sw          $a0, 0xDC($v1)
    ctx->pc = 0x1c27d0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 220), GPR_U32(ctx, 4));
    // 0x1c27d4: 0x24050050  addiu       $a1, $zero, 0x50
    ctx->pc = 0x1c27d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1c27d8: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c27d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c27dc: 0x2404008c  addiu       $a0, $zero, 0x8C
    ctx->pc = 0x1c27dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 140));
    // 0x1c27e0: 0xac6500d4  sw          $a1, 0xD4($v1)
    ctx->pc = 0x1c27e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 212), GPR_U32(ctx, 5));
    // 0x1c27e4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c27e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c27e8: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c27e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c27ec: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1C27ECu;
    {
        const bool branch_taken_0x1c27ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C27F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C27ECu;
            // 0x1c27f0: 0xac6400d8  sw          $a0, 0xD8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 216), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c27ec) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C27F4u;
label_1c27f4:
    // 0x1c27f4: 0x8c65001c  lw          $a1, 0x1C($v1)
    ctx->pc = 0x1c27f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1c27f8: 0x10a6000d  beq         $a1, $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x1C27F8u;
    {
        const bool branch_taken_0x1c27f8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x1C27FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C27F8u;
            // 0x1c27fc: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c27f8) {
            ctx->pc = 0x1C2830u;
            goto label_1c2830;
        }
    }
    ctx->pc = 0x1C2800u;
    // 0x1c2800: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c2800u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2804: 0x10a40009  beq         $a1, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C2804u;
    {
        const bool branch_taken_0x1c2804 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        if (branch_taken_0x1c2804) {
            ctx->pc = 0x1C282Cu;
            goto label_1c282c;
        }
    }
    ctx->pc = 0x1C280Cu;
    // 0x1c280c: 0x10a80047  beq         $a1, $t0, . + 4 + (0x47 << 2)
    ctx->pc = 0x1C280Cu;
    {
        const bool branch_taken_0x1c280c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 8));
        if (branch_taken_0x1c280c) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2814u;
    // 0x1c2814: 0x10a70045  beq         $a1, $a3, . + 4 + (0x45 << 2)
    ctx->pc = 0x1C2814u;
    {
        const bool branch_taken_0x1c2814 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 7));
        if (branch_taken_0x1c2814) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C281Cu;
    // 0x1c281c: 0x10a00043  beqz        $a1, . + 4 + (0x43 << 2)
    ctx->pc = 0x1C281Cu;
    {
        const bool branch_taken_0x1c281c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c281c) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2824u;
    // 0x1c2824: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1C2824u;
    {
        const bool branch_taken_0x1c2824 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2824) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C282Cu;
label_1c282c:
    // 0x1c282c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c282cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c2830:
    // 0x1c2830: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2830u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2834: 0xac6400dc  sw          $a0, 0xDC($v1)
    ctx->pc = 0x1c2834u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 220), GPR_U32(ctx, 4));
    // 0x1c2838: 0x24050050  addiu       $a1, $zero, 0x50
    ctx->pc = 0x1c2838u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1c283c: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c283cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c2840: 0x2404008c  addiu       $a0, $zero, 0x8C
    ctx->pc = 0x1c2840u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 140));
    // 0x1c2844: 0xac6500d4  sw          $a1, 0xD4($v1)
    ctx->pc = 0x1c2844u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 212), GPR_U32(ctx, 5));
    // 0x1c2848: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2848u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c284c: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c284cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c2850: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1C2850u;
    {
        const bool branch_taken_0x1c2850 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2850u;
            // 0x1c2854: 0xac6400d8  sw          $a0, 0xD8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 216), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2850) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2858u;
label_1c2858:
    // 0x1c2858: 0x8c65001c  lw          $a1, 0x1C($v1)
    ctx->pc = 0x1c2858u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1c285c: 0x10a80013  beq         $a1, $t0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1C285Cu;
    {
        const bool branch_taken_0x1c285c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 8));
        ctx->pc = 0x1C2860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C285Cu;
            // 0x1c2860: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c285c) {
            ctx->pc = 0x1C28ACu;
            goto label_1c28ac;
        }
    }
    ctx->pc = 0x1C2864u;
    // 0x1c2864: 0x10a40011  beq         $a1, $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C2864u;
    {
        const bool branch_taken_0x1c2864 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        if (branch_taken_0x1c2864) {
            ctx->pc = 0x1C28ACu;
            goto label_1c28ac;
        }
    }
    ctx->pc = 0x1C286Cu;
    // 0x1c286c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c286cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2870: 0x10a40007  beq         $a1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C2870u;
    {
        const bool branch_taken_0x1c2870 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        if (branch_taken_0x1c2870) {
            ctx->pc = 0x1C2890u;
            goto label_1c2890;
        }
    }
    ctx->pc = 0x1C2878u;
    // 0x1c2878: 0x10a7002c  beq         $a1, $a3, . + 4 + (0x2C << 2)
    ctx->pc = 0x1C2878u;
    {
        const bool branch_taken_0x1c2878 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 7));
        if (branch_taken_0x1c2878) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2880u;
    // 0x1c2880: 0x10a0002a  beqz        $a1, . + 4 + (0x2A << 2)
    ctx->pc = 0x1C2880u;
    {
        const bool branch_taken_0x1c2880 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2880) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2888u;
    // 0x1c2888: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1C2888u;
    {
        const bool branch_taken_0x1c2888 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2888) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2890u;
label_1c2890:
    // 0x1c2890: 0x24050050  addiu       $a1, $zero, 0x50
    ctx->pc = 0x1c2890u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1c2894: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2894u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2898: 0xac6500d4  sw          $a1, 0xD4($v1)
    ctx->pc = 0x1c2898u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 212), GPR_U32(ctx, 5));
    // 0x1c289c: 0x24040074  addiu       $a0, $zero, 0x74
    ctx->pc = 0x1c289cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 116));
    // 0x1c28a0: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c28a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c28a4: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1C28A4u;
    {
        const bool branch_taken_0x1c28a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C28A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C28A4u;
            // 0x1c28a8: 0xac6400d8  sw          $a0, 0xD8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 216), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c28a4) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C28ACu;
label_1c28ac:
    // 0x1c28ac: 0x24050050  addiu       $a1, $zero, 0x50
    ctx->pc = 0x1c28acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1c28b0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c28b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c28b4: 0xac6500d4  sw          $a1, 0xD4($v1)
    ctx->pc = 0x1c28b4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 212), GPR_U32(ctx, 5));
    // 0x1c28b8: 0x2404008c  addiu       $a0, $zero, 0x8C
    ctx->pc = 0x1c28b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 140));
    // 0x1c28bc: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c28bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c28c0: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1C28C0u;
    {
        const bool branch_taken_0x1c28c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C28C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C28C0u;
            // 0x1c28c4: 0xac6400d8  sw          $a0, 0xD8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 216), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c28c0) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C28C8u;
label_1c28c8:
    // 0x1c28c8: 0x8c65001c  lw          $a1, 0x1C($v1)
    ctx->pc = 0x1c28c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1c28cc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1c28ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c28d0: 0x10a4000d  beq         $a1, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C28D0u;
    {
        const bool branch_taken_0x1c28d0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C28D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C28D0u;
            // 0x1c28d4: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c28d0) {
            ctx->pc = 0x1C2908u;
            goto label_1c2908;
        }
    }
    ctx->pc = 0x1C28D8u;
    // 0x1c28d8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c28d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c28dc: 0x10a40009  beq         $a1, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C28DCu;
    {
        const bool branch_taken_0x1c28dc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        if (branch_taken_0x1c28dc) {
            ctx->pc = 0x1C2904u;
            goto label_1c2904;
        }
    }
    ctx->pc = 0x1C28E4u;
    // 0x1c28e4: 0x10a80011  beq         $a1, $t0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C28E4u;
    {
        const bool branch_taken_0x1c28e4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 8));
        ctx->pc = 0x1C28E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C28E4u;
            // 0x1c28e8: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c28e4) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C28ECu;
    // 0x1c28ec: 0x10a3000f  beq         $a1, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1C28ECu;
    {
        const bool branch_taken_0x1c28ec = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c28ec) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C28F4u;
    // 0x1c28f4: 0x10a0000d  beqz        $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x1C28F4u;
    {
        const bool branch_taken_0x1c28f4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c28f4) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C28FCu;
    // 0x1c28fc: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1C28FCu;
    {
        const bool branch_taken_0x1c28fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c28fc) {
            ctx->pc = 0x1C292Cu;
            goto label_1c292c;
        }
    }
    ctx->pc = 0x1C2904u;
label_1c2904:
    // 0x1c2904: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c2904u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c2908:
    // 0x1c2908: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2908u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c290c: 0xac6400dc  sw          $a0, 0xDC($v1)
    ctx->pc = 0x1c290cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 220), GPR_U32(ctx, 4));
    // 0x1c2910: 0x24050050  addiu       $a1, $zero, 0x50
    ctx->pc = 0x1c2910u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1c2914: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c2914u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c2918: 0x2404008c  addiu       $a0, $zero, 0x8C
    ctx->pc = 0x1c2918u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 140));
    // 0x1c291c: 0xac6500d4  sw          $a1, 0xD4($v1)
    ctx->pc = 0x1c291cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 212), GPR_U32(ctx, 5));
    // 0x1c2920: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2920u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2924: 0x8c236f10  lw          $v1, 0x6F10($at)
    ctx->pc = 0x1c2924u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c2928: 0xac6400d8  sw          $a0, 0xD8($v1)
    ctx->pc = 0x1c2928u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 216), GPR_U32(ctx, 4));
label_1c292c:
    // 0x1c292c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c292cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1c2930:
    // 0x1c2930: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c2930u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c2934: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c2934u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c2938: 0x3e00008  jr          $ra
    ctx->pc = 0x1C2938u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C293Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2938u;
            // 0x1c293c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C2640u: goto label_1c2640;
            case 0x1C265Cu: goto label_1c265c;
            case 0x1C2670u: goto label_1c2670;
            case 0x1C26DCu: goto label_1c26dc;
            case 0x1C271Cu: goto label_1c271c;
            case 0x1C2750u: goto label_1c2750;
            case 0x1C2768u: goto label_1c2768;
            case 0x1C2794u: goto label_1c2794;
            case 0x1C27C8u: goto label_1c27c8;
            case 0x1C27F4u: goto label_1c27f4;
            case 0x1C282Cu: goto label_1c282c;
            case 0x1C2830u: goto label_1c2830;
            case 0x1C2858u: goto label_1c2858;
            case 0x1C2890u: goto label_1c2890;
            case 0x1C28ACu: goto label_1c28ac;
            case 0x1C28C8u: goto label_1c28c8;
            case 0x1C2904u: goto label_1c2904;
            case 0x1C2908u: goto label_1c2908;
            case 0x1C292Cu: goto label_1c292c;
            case 0x1C2930u: goto label_1c2930;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C2940u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
