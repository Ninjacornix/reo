#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0580
// Address: 0x1c0580 - 0x1c0708
void sub_001C0580_0x1c0580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0580_0x1c0580");
#endif

    switch (ctx->pc) {
        case 0x1c05c0u: goto label_1c05c0;
        case 0x1c0620u: goto label_1c0620;
        case 0x1c06b8u: goto label_1c06b8;
        case 0x1c06f8u: goto label_1c06f8;
        default: break;
    }

    ctx->pc = 0x1c0580u;

    // 0x1c0580: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0584: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c0584u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c0588: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c058c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c058cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0590: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c0590u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c0594: 0x10620046  beq         $v1, $v0, . + 4 + (0x46 << 2)
    ctx->pc = 0x1C0594u;
    {
        const bool branch_taken_0x1c0594 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C0598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0594u;
            // 0x1c0598: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0594) {
            ctx->pc = 0x1C06B0u;
            goto label_1c06b0;
        }
    }
    ctx->pc = 0x1C059Cu;
    // 0x1c059c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c059cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c05a0: 0x1062001d  beq         $v1, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C05A0u;
    {
        const bool branch_taken_0x1c05a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c05a0) {
            ctx->pc = 0x1C0618u;
            goto label_1c0618;
        }
    }
    ctx->pc = 0x1C05A8u;
    // 0x1c05a8: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C05A8u;
    {
        const bool branch_taken_0x1c05a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c05a8) {
            ctx->pc = 0x1C05B8u;
            goto label_1c05b8;
        }
    }
    ctx->pc = 0x1C05B0u;
    // 0x1c05b0: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1C05B0u;
    {
        const bool branch_taken_0x1c05b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C05B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C05B0u;
            // 0x1c05b4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c05b0) {
            ctx->pc = 0x1C06F0u;
            goto label_1c06f0;
        }
    }
    ctx->pc = 0x1C05B8u;
label_1c05b8:
    // 0x1c05b8: 0xc06fe10  jal         func_1BF840
    ctx->pc = 0x1C05B8u;
    SET_GPR_U32(ctx, 31, 0x1C05C0u);
    ctx->pc = 0x1BF840u;
    if (runtime->hasFunction(0x1BF840u)) {
        auto targetFn = runtime->lookupFunction(0x1BF840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C05C0u; }
        if (ctx->pc != 0x1C05C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF840_0x1bf840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C05C0u; }
        if (ctx->pc != 0x1C05C0u) { return; }
    }
    ctx->pc = 0x1C05C0u;
label_1c05c0:
    // 0x1c05c0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c05c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c05c4: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C05C4u;
    {
        const bool branch_taken_0x1c05c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C05C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C05C4u;
            // 0x1c05c8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c05c4) {
            ctx->pc = 0x1C0608u;
            goto label_1c0608;
        }
    }
    ctx->pc = 0x1C05CCu;
    // 0x1c05cc: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C05CCu;
    {
        const bool branch_taken_0x1c05cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c05cc) {
            ctx->pc = 0x1C0608u;
            goto label_1c0608;
        }
    }
    ctx->pc = 0x1C05D4u;
    // 0x1c05d4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c05d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c05d8: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C05D8u;
    {
        const bool branch_taken_0x1c05d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c05d8) {
            ctx->pc = 0x1C05FCu;
            goto label_1c05fc;
        }
    }
    ctx->pc = 0x1C05E0u;
    // 0x1c05e0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C05E0u;
    {
        const bool branch_taken_0x1c05e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c05e0) {
            ctx->pc = 0x1C05F0u;
            goto label_1c05f0;
        }
    }
    ctx->pc = 0x1C05E8u;
    // 0x1c05e8: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1C05E8u;
    {
        const bool branch_taken_0x1c05e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c05e8) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C05F0u;
label_1c05f0:
    // 0x1c05f0: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c05f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c05f4: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1C05F4u;
    {
        const bool branch_taken_0x1c05f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C05F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C05F4u;
            // 0x1c05f8: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c05f4) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C05FCu;
label_1c05fc:
    // 0x1c05fc: 0x2402ff02  addiu       $v0, $zero, -0xFE
    ctx->pc = 0x1c05fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c0600: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1C0600u;
    {
        const bool branch_taken_0x1c0600 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0600u;
            // 0x1c0604: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0600) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C0608u;
label_1c0608:
    // 0x1c0608: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1c0608u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c060c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c060cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0610: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1C0610u;
    {
        const bool branch_taken_0x1c0610 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0610u;
            // 0x1c0614: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0610) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C0618u;
label_1c0618:
    // 0x1c0618: 0xc06fe94  jal         func_1BFA50
    ctx->pc = 0x1C0618u;
    SET_GPR_U32(ctx, 31, 0x1C0620u);
    ctx->pc = 0x1BFA50u;
    if (runtime->hasFunction(0x1BFA50u)) {
        auto targetFn = runtime->lookupFunction(0x1BFA50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0620u; }
        if (ctx->pc != 0x1C0620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFA50_0x1bfa50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0620u; }
        if (ctx->pc != 0x1C0620u) { return; }
    }
    ctx->pc = 0x1C0620u;
label_1c0620:
    // 0x1c0620: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c0620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0624: 0x1043001e  beq         $v0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1C0624u;
    {
        const bool branch_taken_0x1c0624 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0624u;
            // 0x1c0628: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0624) {
            ctx->pc = 0x1C06A0u;
            goto label_1c06a0;
        }
    }
    ctx->pc = 0x1C062Cu;
    // 0x1c062c: 0x10430018  beq         $v0, $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1C062Cu;
    {
        const bool branch_taken_0x1c062c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c062c) {
            ctx->pc = 0x1C0690u;
            goto label_1c0690;
        }
    }
    ctx->pc = 0x1C0634u;
    // 0x1c0634: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0634u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0638: 0x10430011  beq         $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C0638u;
    {
        const bool branch_taken_0x1c0638 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0638) {
            ctx->pc = 0x1C0680u;
            goto label_1c0680;
        }
    }
    ctx->pc = 0x1C0640u;
    // 0x1c0640: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0640u;
    {
        const bool branch_taken_0x1c0640 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0640u;
            // 0x1c0644: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0640) {
            ctx->pc = 0x1C0650u;
            goto label_1c0650;
        }
    }
    ctx->pc = 0x1C0648u;
    // 0x1c0648: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1C0648u;
    {
        const bool branch_taken_0x1c0648 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0648) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C0650u;
label_1c0650:
    // 0x1c0650: 0x8e020088  lw          $v0, 0x88($s0)
    ctx->pc = 0x1c0650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 136)));
    // 0x1c0654: 0x8c236ac0  lw          $v1, 0x6AC0($at)
    ctx->pc = 0x1c0654u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27328)));
    // 0x1c0658: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C0658u;
    {
        const bool branch_taken_0x1c0658 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c0658) {
            ctx->pc = 0x1C0670u;
            goto label_1c0670;
        }
    }
    ctx->pc = 0x1C0660u;
    // 0x1c0660: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c0660u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c0664: 0x2402ff05  addiu       $v0, $zero, -0xFB
    ctx->pc = 0x1c0664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967045));
    // 0x1c0668: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1C0668u;
    {
        const bool branch_taken_0x1c0668 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C066Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0668u;
            // 0x1c066c: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0668) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C0670u;
label_1c0670:
    // 0x1c0670: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1c0670u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c0674: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0674u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0678: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1C0678u;
    {
        const bool branch_taken_0x1c0678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C067Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0678u;
            // 0x1c067c: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0678) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C0680u;
label_1c0680:
    // 0x1c0680: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c0680u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c0684: 0x2402ff03  addiu       $v0, $zero, -0xFD
    ctx->pc = 0x1c0684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
    // 0x1c0688: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1C0688u;
    {
        const bool branch_taken_0x1c0688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C068Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0688u;
            // 0x1c068c: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0688) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C0690u;
label_1c0690:
    // 0x1c0690: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c0690u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c0694: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c0694u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c0698: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1C0698u;
    {
        const bool branch_taken_0x1c0698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C069Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0698u;
            // 0x1c069c: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0698) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C06A0u;
label_1c06a0:
    // 0x1c06a0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c06a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c06a4: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c06a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c06a8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1C06A8u;
    {
        const bool branch_taken_0x1c06a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C06ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C06A8u;
            // 0x1c06ac: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c06a8) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C06B0u;
label_1c06b0:
    // 0x1c06b0: 0xc06fed0  jal         func_1BFB40
    ctx->pc = 0x1C06B0u;
    SET_GPR_U32(ctx, 31, 0x1C06B8u);
    ctx->pc = 0x1BFB40u;
    if (runtime->hasFunction(0x1BFB40u)) {
        auto targetFn = runtime->lookupFunction(0x1BFB40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C06B8u; }
        if (ctx->pc != 0x1C06B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFB40_0x1bfb40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C06B8u; }
        if (ctx->pc != 0x1C06B8u) { return; }
    }
    ctx->pc = 0x1C06B8u;
label_1c06b8:
    // 0x1c06b8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c06b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c06bc: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C06BCu;
    {
        const bool branch_taken_0x1c06bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c06bc) {
            ctx->pc = 0x1C06E0u;
            goto label_1c06e0;
        }
    }
    ctx->pc = 0x1C06C4u;
    // 0x1c06c4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C06C4u;
    {
        const bool branch_taken_0x1c06c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c06c4) {
            ctx->pc = 0x1C06D4u;
            goto label_1c06d4;
        }
    }
    ctx->pc = 0x1C06CCu;
    // 0x1c06cc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C06CCu;
    {
        const bool branch_taken_0x1c06cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c06cc) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C06D4u;
label_1c06d4:
    // 0x1c06d4: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c06d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c06d8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C06D8u;
    {
        const bool branch_taken_0x1c06d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C06DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C06D8u;
            // 0x1c06dc: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c06d8) {
            ctx->pc = 0x1C06ECu;
            goto label_1c06ec;
        }
    }
    ctx->pc = 0x1C06E0u;
label_1c06e0:
    // 0x1c06e0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c06e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c06e4: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c06e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c06e8: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c06e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c06ec:
    // 0x1c06ec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c06ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c06f0:
    // 0x1c06f0: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C06F0u;
    SET_GPR_U32(ctx, 31, 0x1C06F8u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C06F8u; }
        if (ctx->pc != 0x1C06F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C06F8u; }
        if (ctx->pc != 0x1C06F8u) { return; }
    }
    ctx->pc = 0x1C06F8u;
label_1c06f8:
    // 0x1c06f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c06f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c06fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c06fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0700: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0700u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0700u;
            // 0x1c0704: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C05B8u: goto label_1c05b8;
            case 0x1C05C0u: goto label_1c05c0;
            case 0x1C05F0u: goto label_1c05f0;
            case 0x1C05FCu: goto label_1c05fc;
            case 0x1C0608u: goto label_1c0608;
            case 0x1C0618u: goto label_1c0618;
            case 0x1C0620u: goto label_1c0620;
            case 0x1C0650u: goto label_1c0650;
            case 0x1C0670u: goto label_1c0670;
            case 0x1C0680u: goto label_1c0680;
            case 0x1C0690u: goto label_1c0690;
            case 0x1C06A0u: goto label_1c06a0;
            case 0x1C06B0u: goto label_1c06b0;
            case 0x1C06B8u: goto label_1c06b8;
            case 0x1C06D4u: goto label_1c06d4;
            case 0x1C06E0u: goto label_1c06e0;
            case 0x1C06ECu: goto label_1c06ec;
            case 0x1C06F0u: goto label_1c06f0;
            case 0x1C06F8u: goto label_1c06f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0708u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
