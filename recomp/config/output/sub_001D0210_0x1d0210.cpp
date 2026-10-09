#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D0210
// Address: 0x1d0210 - 0x1d02b0
void sub_001D0210_0x1d0210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D0210_0x1d0210");
#endif

    switch (ctx->pc) {
        case 0x1d0228u: goto label_1d0228;
        case 0x1d0230u: goto label_1d0230;
        case 0x1d024cu: goto label_1d024c;
        case 0x1d028cu: goto label_1d028c;
        default: break;
    }

    ctx->pc = 0x1d0210u;

    // 0x1d0210: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d0210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d0214: 0x24041400  addiu       $a0, $zero, 0x1400
    ctx->pc = 0x1d0214u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5120));
    // 0x1d0218: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d0218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d021c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d021cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0220: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0220u;
    SET_GPR_U32(ctx, 31, 0x1D0228u);
    ctx->pc = 0x1D0224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0220u;
            // 0x1d0224: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0228u; }
        if (ctx->pc != 0x1D0228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0228u; }
        if (ctx->pc != 0x1D0228u) { return; }
    }
    ctx->pc = 0x1D0228u;
label_1d0228:
    // 0x1d0228: 0xc0740e8  jal         func_1D03A0
    ctx->pc = 0x1D0228u;
    SET_GPR_U32(ctx, 31, 0x1D0230u);
    ctx->pc = 0x1D03A0u;
    if (runtime->hasFunction(0x1D03A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D03A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0230u; }
        if (ctx->pc != 0x1D0230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D03A0_0x1d03a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0230u; }
        if (ctx->pc != 0x1D0230u) { return; }
    }
    ctx->pc = 0x1D0230u;
label_1d0230:
    // 0x1d0230: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0230u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0234: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1d0234u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1d0238: 0x942443dc  lhu         $a0, 0x43DC($at)
    ctx->pc = 0x1d0238u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1d023c: 0x24638e80  addiu       $v1, $v1, -0x7180
    ctx->pc = 0x1d023cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938240));
    // 0x1d0240: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d0240u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0244: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1d0244u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1d0248: 0x648821  addu        $s1, $v1, $a0
    ctx->pc = 0x1d0248u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_1d024c:
    // 0x1d024c: 0x96250000  lhu         $a1, 0x0($s1)
    ctx->pc = 0x1d024cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d0250: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x1d0250u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1d0254: 0x96240002  lhu         $a0, 0x2($s1)
    ctx->pc = 0x1d0254u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1d0258: 0x14a30004  bne         $a1, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D0258u;
    {
        const bool branch_taken_0x1d0258 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D025Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0258u;
            // 0x1d025c: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0258) {
            ctx->pc = 0x1D026Cu;
            goto label_1d026c;
        }
    }
    ctx->pc = 0x1D0260u;
    // 0x1d0260: 0x3083ffff  andi        $v1, $a0, 0xFFFF
    ctx->pc = 0x1d0260u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1d0264: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D0264u;
    {
        const bool branch_taken_0x1d0264 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0264) {
            ctx->pc = 0x1D028Cu;
            goto label_1d028c;
        }
    }
    ctx->pc = 0x1D026Cu;
label_1d026c:
    // 0x1d026c: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x1d026cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1d0270: 0x10a30006  beq         $a1, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D0270u;
    {
        const bool branch_taken_0x1d0270 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D0274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0270u;
            // 0x1d0274: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0270) {
            ctx->pc = 0x1D028Cu;
            goto label_1d028c;
        }
    }
    ctx->pc = 0x1D0278u;
    // 0x1d0278: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1d0278u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d027c: 0x24070003  addiu       $a3, $zero, 0x3
    ctx->pc = 0x1d027cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d0280: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1d0280u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0284: 0xc073cc0  jal         func_1CF300
    ctx->pc = 0x1D0284u;
    SET_GPR_U32(ctx, 31, 0x1D028Cu);
    ctx->pc = 0x1D0288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0284u;
            // 0x1d0288: 0x2409ffff  addiu       $t1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF300u;
    if (runtime->hasFunction(0x1CF300u)) {
        auto targetFn = runtime->lookupFunction(0x1CF300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D028Cu; }
        if (ctx->pc != 0x1D028Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF300_0x1cf300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D028Cu; }
        if (ctx->pc != 0x1D028Cu) { return; }
    }
    ctx->pc = 0x1D028Cu;
label_1d028c:
    // 0x1d028c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d028cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d0290: 0x2a030004  slti        $v1, $s0, 0x4
    ctx->pc = 0x1d0290u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1d0294: 0x1460ffed  bnez        $v1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1D0294u;
    {
        const bool branch_taken_0x1d0294 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d0294) {
            ctx->pc = 0x1D024Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d024c;
        }
    }
    ctx->pc = 0x1D029Cu;
    // 0x1d029c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d029cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d02a0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d02a0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d02a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d02a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d02a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D02A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D02ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D02A8u;
            // 0x1d02ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D0228u: goto label_1d0228;
            case 0x1D0230u: goto label_1d0230;
            case 0x1D024Cu: goto label_1d024c;
            case 0x1D026Cu: goto label_1d026c;
            case 0x1D028Cu: goto label_1d028c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D02B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
