#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3210
// Address: 0x1a3210 - 0x1a32b0
void sub_001A3210_0x1a3210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3210_0x1a3210");
#endif

    switch (ctx->pc) {
        case 0x1a3228u: goto label_1a3228;
        case 0x1a3238u: goto label_1a3238;
        case 0x1a3254u: goto label_1a3254;
        case 0x1a3288u: goto label_1a3288;
        default: break;
    }

    ctx->pc = 0x1a3210u;

    // 0x1a3210: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a3210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a3214: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a3214u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a3218: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a3218u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a321c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1a321cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3220: 0xc068d64  jal         func_1A3590
    ctx->pc = 0x1A3220u;
    SET_GPR_U32(ctx, 31, 0x1A3228u);
    ctx->pc = 0x1A3224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3220u;
            // 0x1a3224: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3590u;
    if (runtime->hasFunction(0x1A3590u)) {
        auto targetFn = runtime->lookupFunction(0x1A3590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3228u; }
        if (ctx->pc != 0x1A3228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3590_0x1a3590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3228u; }
        if (ctx->pc != 0x1A3228u) { return; }
    }
    ctx->pc = 0x1A3228u;
label_1a3228:
    // 0x1a3228: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1a3228u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a322c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1a322cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a3230: 0xc068d68  jal         func_1A35A0
    ctx->pc = 0x1A3230u;
    SET_GPR_U32(ctx, 31, 0x1A3238u);
    ctx->pc = 0x1A3234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3230u;
            // 0x1a3234: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35A0u;
    if (runtime->hasFunction(0x1A35A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3238u; }
        if (ctx->pc != 0x1A3238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35A0_0x1a35a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3238u; }
        if (ctx->pc != 0x1A3238u) { return; }
    }
    ctx->pc = 0x1A3238u;
label_1a3238:
    // 0x1a3238: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3238u;
    {
        const bool branch_taken_0x1a3238 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A323Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3238u;
            // 0x1a323c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3238) {
            ctx->pc = 0x1A3248u;
            goto label_1a3248;
        }
    }
    ctx->pc = 0x1A3240u;
    // 0x1a3240: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1A3240u;
    {
        const bool branch_taken_0x1a3240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3240u;
            // 0x1a3244: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3240) {
            ctx->pc = 0x1A3298u;
            goto label_1a3298;
        }
    }
    ctx->pc = 0x1A3248u;
label_1a3248:
    // 0x1a3248: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1a3248u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a324c: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A324Cu;
    SET_GPR_U32(ctx, 31, 0x1A3254u);
    ctx->pc = 0x1A3250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A324Cu;
            // 0x1a3250: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3254u; }
        if (ctx->pc != 0x1A3254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3254u; }
        if (ctx->pc != 0x1A3254u) { return; }
    }
    ctx->pc = 0x1A3254u;
label_1a3254:
    // 0x1a3254: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3254u;
    {
        const bool branch_taken_0x1a3254 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3254) {
            ctx->pc = 0x1A3264u;
            goto label_1a3264;
        }
    }
    ctx->pc = 0x1A325Cu;
    // 0x1a325c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1A325Cu;
    {
        const bool branch_taken_0x1a325c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A325Cu;
            // 0x1a3260: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a325c) {
            ctx->pc = 0x1A3298u;
            goto label_1a3298;
        }
    }
    ctx->pc = 0x1A3264u;
label_1a3264:
    // 0x1a3264: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1a3264u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a3268: 0x71082b  sltu        $at, $v1, $s1
    ctx->pc = 0x1a3268u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x1a326c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A326Cu;
    {
        const bool branch_taken_0x1a326c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A326Cu;
            // 0x1a3270: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a326c) {
            ctx->pc = 0x1A327Cu;
            goto label_1a327c;
        }
    }
    ctx->pc = 0x1A3274u;
    // 0x1a3274: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A3274u;
    {
        const bool branch_taken_0x1a3274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3274u;
            // 0x1a3278: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3274) {
            ctx->pc = 0x1A3298u;
            goto label_1a3298;
        }
    }
    ctx->pc = 0x1A327Cu;
label_1a327c:
    // 0x1a327c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a327cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3280: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3280u;
    SET_GPR_U32(ctx, 31, 0x1A3288u);
    ctx->pc = 0x1A3284u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3280u;
            // 0x1a3284: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3288u; }
        if (ctx->pc != 0x1A3288u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3288u; }
        if (ctx->pc != 0x1A3288u) { return; }
    }
    ctx->pc = 0x1A3288u;
label_1a3288:
    // 0x1a3288: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3288u;
    {
        const bool branch_taken_0x1a3288 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3288) {
            ctx->pc = 0x1A3298u;
            goto label_1a3298;
        }
    }
    ctx->pc = 0x1A3290u;
    // 0x1a3290: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1A3290u;
    {
        const bool branch_taken_0x1a3290 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3290u;
            // 0x1a3294: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3290) {
            ctx->pc = 0x1A3298u;
            goto label_1a3298;
        }
    }
    ctx->pc = 0x1A3298u;
label_1a3298:
    // 0x1a3298: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a3298u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a329c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a329cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a32a0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a32a0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a32a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A32A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A32A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A32A4u;
            // 0x1a32a8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3228u: goto label_1a3228;
            case 0x1A3238u: goto label_1a3238;
            case 0x1A3248u: goto label_1a3248;
            case 0x1A3254u: goto label_1a3254;
            case 0x1A3264u: goto label_1a3264;
            case 0x1A327Cu: goto label_1a327c;
            case 0x1A3288u: goto label_1a3288;
            case 0x1A3298u: goto label_1a3298;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A32ACu;
    // 0x1a32ac: 0x0  nop
    ctx->pc = 0x1a32acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
