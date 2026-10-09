#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165630
// Address: 0x165630 - 0x1656e8
void sub_00165630_0x165630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165630_0x165630");
#endif

    switch (ctx->pc) {
        case 0x165648u: goto label_165648;
        case 0x165670u: goto label_165670;
        case 0x165680u: goto label_165680;
        case 0x16568cu: goto label_16568c;
        case 0x165698u: goto label_165698;
        default: break;
    }

    ctx->pc = 0x165630u;

    // 0x165630: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x165630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x165634: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x165634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x165638: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x165638u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16563c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x16563cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x165640: 0xc05984a  jal         func_166128
    ctx->pc = 0x165640u;
    SET_GPR_U32(ctx, 31, 0x165648u);
    ctx->pc = 0x165644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165640u;
            // 0x165644: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166128u;
    if (runtime->hasFunction(0x166128u)) {
        auto targetFn = runtime->lookupFunction(0x166128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165648u; }
        if (ctx->pc != 0x165648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166128_0x166128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165648u; }
        if (ctx->pc != 0x165648u) { return; }
    }
    ctx->pc = 0x165648u;
label_165648:
    // 0x165648: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x165648u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16564c: 0x52200021  beql        $s1, $zero, . + 4 + (0x21 << 2)
    ctx->pc = 0x16564Cu;
    {
        const bool branch_taken_0x16564c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x16564c) {
            ctx->pc = 0x165650u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16564Cu;
            // 0x165650: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1656D4u;
            goto label_1656d4;
        }
    }
    ctx->pc = 0x165654u;
    // 0x165654: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x165654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x165658: 0x5440001e  bnel        $v0, $zero, . + 4 + (0x1E << 2)
    ctx->pc = 0x165658u;
    {
        const bool branch_taken_0x165658 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x165658) {
            ctx->pc = 0x16565Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x165658u;
            // 0x16565c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1656D4u;
            goto label_1656d4;
        }
    }
    ctx->pc = 0x165660u;
    // 0x165660: 0x8e021b74  lw          $v0, 0x1B74($s0)
    ctx->pc = 0x165660u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7028)));
    // 0x165664: 0x8c500000  lw          $s0, 0x0($v0)
    ctx->pc = 0x165664u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x165668: 0xc0595ba  jal         func_1656E8
    ctx->pc = 0x165668u;
    SET_GPR_U32(ctx, 31, 0x165670u);
    ctx->pc = 0x16566Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165668u;
            // 0x16566c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1656E8u;
    if (runtime->hasFunction(0x1656E8u)) {
        auto targetFn = runtime->lookupFunction(0x1656E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165670u; }
        if (ctx->pc != 0x165670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001656E8_0x1656e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165670u; }
        if (ctx->pc != 0x165670u) { return; }
    }
    ctx->pc = 0x165670u;
label_165670:
    // 0x165670: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x165670u;
    {
        const bool branch_taken_0x165670 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x165674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165670u;
            // 0x165674: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165670) {
            ctx->pc = 0x1656D0u;
            goto label_1656d0;
        }
    }
    ctx->pc = 0x165678u;
    // 0x165678: 0xc04c93e  jal         func_1324F8
    ctx->pc = 0x165678u;
    SET_GPR_U32(ctx, 31, 0x165680u);
    ctx->pc = 0x1324F8u;
    if (runtime->hasFunction(0x1324F8u)) {
        auto targetFn = runtime->lookupFunction(0x1324F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165680u; }
        if (ctx->pc != 0x165680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001324F8_0x1324f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165680u; }
        if (ctx->pc != 0x165680u) { return; }
    }
    ctx->pc = 0x165680u;
label_165680:
    // 0x165680: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165680u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165684: 0xc04c92a  jal         func_1324A8
    ctx->pc = 0x165684u;
    SET_GPR_U32(ctx, 31, 0x16568Cu);
    ctx->pc = 0x165688u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165684u;
            // 0x165688: 0xae220010  sw          $v0, 0x10($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1324A8u;
    if (runtime->hasFunction(0x1324A8u)) {
        auto targetFn = runtime->lookupFunction(0x1324A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16568Cu; }
        if (ctx->pc != 0x16568Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001324A8_0x1324a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16568Cu; }
        if (ctx->pc != 0x16568Cu) { return; }
    }
    ctx->pc = 0x16568Cu;
label_16568c:
    // 0x16568c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16568cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165690: 0xc04c952  jal         func_132548
    ctx->pc = 0x165690u;
    SET_GPR_U32(ctx, 31, 0x165698u);
    ctx->pc = 0x165694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165690u;
            // 0x165694: 0xae220014  sw          $v0, 0x14($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132548u;
    if (runtime->hasFunction(0x132548u)) {
        auto targetFn = runtime->lookupFunction(0x132548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165698u; }
        if (ctx->pc != 0x165698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132548_0x132548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165698u; }
        if (ctx->pc != 0x165698u) { return; }
    }
    ctx->pc = 0x165698u;
label_165698:
    // 0x165698: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x165698u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x16569c: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x16569cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x1656a0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1656a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1656a4: 0x822018  mult        $a0, $a0, $v0
    ctx->pc = 0x1656a4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1656a8: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1656a8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1656ac: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x1656acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x1656b0: 0x410c0  sll         $v0, $a0, 3
    ctx->pc = 0x1656b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1656b4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1656b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1656b8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1656b8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1656bc: 0x2444000f  addiu       $a0, $v0, 0xF
    ctx->pc = 0x1656bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 15));
    // 0x1656c0: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x1656c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1656c4: 0x82180b  movn        $v1, $a0, $v0
    ctx->pc = 0x1656c4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x1656c8: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x1656c8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
    // 0x1656cc: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1656ccu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
label_1656d0:
    // 0x1656d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1656d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1656d4:
    // 0x1656d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1656d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1656d8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1656d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1656dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1656DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1656E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1656DCu;
            // 0x1656e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165648u: goto label_165648;
            case 0x165670u: goto label_165670;
            case 0x165680u: goto label_165680;
            case 0x16568Cu: goto label_16568c;
            case 0x165698u: goto label_165698;
            case 0x1656D0u: goto label_1656d0;
            case 0x1656D4u: goto label_1656d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1656E4u;
    // 0x1656e4: 0x0  nop
    ctx->pc = 0x1656e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
