#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8170
// Address: 0x1b8170 - 0x1b8280
void sub_001B8170_0x1b8170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8170_0x1b8170");
#endif

    switch (ctx->pc) {
        case 0x1b8188u: goto label_1b8188;
        case 0x1b8194u: goto label_1b8194;
        case 0x1b81b0u: goto label_1b81b0;
        case 0x1b81c4u: goto label_1b81c4;
        case 0x1b81d8u: goto label_1b81d8;
        case 0x1b81f0u: goto label_1b81f0;
        case 0x1b8210u: goto label_1b8210;
        case 0x1b8220u: goto label_1b8220;
        case 0x1b822cu: goto label_1b822c;
        case 0x1b8250u: goto label_1b8250;
        case 0x1b8260u: goto label_1b8260;
        case 0x1b826cu: goto label_1b826c;
        default: break;
    }

    ctx->pc = 0x1b8170u;

    // 0x1b8170: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8174: 0x3c040058  lui         $a0, 0x58
    ctx->pc = 0x1b8174u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)88 << 16));
    // 0x1b8178: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b8178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b817c: 0x2484f1f0  addiu       $a0, $a0, -0xE10
    ctx->pc = 0x1b817cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963696));
    // 0x1b8180: 0xc06dfb8  jal         func_1B7EE0
    ctx->pc = 0x1B8180u;
    SET_GPR_U32(ctx, 31, 0x1B8188u);
    ctx->pc = 0x1B8184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8180u;
            // 0x1b8184: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7EE0u;
    if (runtime->hasFunction(0x1B7EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1B7EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8188u; }
        if (ctx->pc != 0x1B8188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7EE0_0x1b7ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8188u; }
        if (ctx->pc != 0x1B8188u) { return; }
    }
    ctx->pc = 0x1B8188u;
label_1b8188:
    // 0x1b8188: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b8188u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b818c: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B818Cu;
    SET_GPR_U32(ctx, 31, 0x1B8194u);
    ctx->pc = 0x1B8190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B818Cu;
            // 0x1b8190: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8194u; }
        if (ctx->pc != 0x1B8194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8194u; }
        if (ctx->pc != 0x1B8194u) { return; }
    }
    ctx->pc = 0x1B8194u;
label_1b8194:
    // 0x1b8194: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b8194u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8198: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8198u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B819Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8198u;
            // 0x1b819c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8188u: goto label_1b8188;
            case 0x1B8194u: goto label_1b8194;
            case 0x1B81B0u: goto label_1b81b0;
            case 0x1B81C4u: goto label_1b81c4;
            case 0x1B81D8u: goto label_1b81d8;
            case 0x1B81E0u: goto label_1b81e0;
            case 0x1B81F0u: goto label_1b81f0;
            case 0x1B81F4u: goto label_1b81f4;
            case 0x1B8210u: goto label_1b8210;
            case 0x1B8220u: goto label_1b8220;
            case 0x1B822Cu: goto label_1b822c;
            case 0x1B8250u: goto label_1b8250;
            case 0x1B8260u: goto label_1b8260;
            case 0x1B826Cu: goto label_1b826c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B81A0u;
    // 0x1b81a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b81a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b81a4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b81a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b81a8: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B81A8u;
    SET_GPR_U32(ctx, 31, 0x1B81B0u);
    ctx->pc = 0x1B81ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81A8u;
            // 0x1b81ac: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81B0u; }
        if (ctx->pc != 0x1B81B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81B0u; }
        if (ctx->pc != 0x1B81B0u) { return; }
    }
    ctx->pc = 0x1B81B0u;
label_1b81b0:
    // 0x1b81b0: 0x3c040060  lui         $a0, 0x60
    ctx->pc = 0x1b81b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)96 << 16));
    // 0x1b81b4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1b81b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b81b8: 0x2484e360  addiu       $a0, $a0, -0x1CA0
    ctx->pc = 0x1b81b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959968));
    // 0x1b81bc: 0xc06dfd0  jal         func_1B7F40
    ctx->pc = 0x1B81BCu;
    SET_GPR_U32(ctx, 31, 0x1B81C4u);
    ctx->pc = 0x1B81C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81BCu;
            // 0x1b81c0: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7F40u;
    if (runtime->hasFunction(0x1B7F40u)) {
        auto targetFn = runtime->lookupFunction(0x1B7F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81C4u; }
        if (ctx->pc != 0x1B81C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7F40_0x1b7f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81C4u; }
        if (ctx->pc != 0x1B81C4u) { return; }
    }
    ctx->pc = 0x1B81C4u;
label_1b81c4:
    // 0x1b81c4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b81c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b81c8: 0x16030005  bne         $s0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B81C8u;
    {
        const bool branch_taken_0x1b81c8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B81CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81C8u;
            // 0x1b81cc: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b81c8) {
            ctx->pc = 0x1B81E0u;
            goto label_1b81e0;
        }
    }
    ctx->pc = 0x1B81D0u;
    // 0x1b81d0: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B81D0u;
    SET_GPR_U32(ctx, 31, 0x1B81D8u);
    ctx->pc = 0x1B81D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81D0u;
            // 0x1b81d4: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81D8u; }
        if (ctx->pc != 0x1B81D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81D8u; }
        if (ctx->pc != 0x1B81D8u) { return; }
    }
    ctx->pc = 0x1B81D8u;
label_1b81d8:
    // 0x1b81d8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B81D8u;
    {
        const bool branch_taken_0x1b81d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B81DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81D8u;
            // 0x1b81dc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b81d8) {
            ctx->pc = 0x1B81F4u;
            goto label_1b81f4;
        }
    }
    ctx->pc = 0x1B81E0u;
label_1b81e0:
    // 0x1b81e0: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B81E0u;
    {
        const bool branch_taken_0x1b81e0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B81E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81E0u;
            // 0x1b81e4: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b81e0) {
            ctx->pc = 0x1B81F0u;
            goto label_1b81f0;
        }
    }
    ctx->pc = 0x1B81E8u;
    // 0x1b81e8: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B81E8u;
    SET_GPR_U32(ctx, 31, 0x1B81F0u);
    ctx->pc = 0x1B81ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81E8u;
            // 0x1b81ec: 0x24050009  addiu       $a1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81F0u; }
        if (ctx->pc != 0x1B81F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81F0u; }
        if (ctx->pc != 0x1B81F0u) { return; }
    }
    ctx->pc = 0x1B81F0u;
label_1b81f0:
    // 0x1b81f0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b81f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b81f4:
    // 0x1b81f4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b81f4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b81f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B81F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B81FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81F8u;
            // 0x1b81fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8188u: goto label_1b8188;
            case 0x1B8194u: goto label_1b8194;
            case 0x1B81B0u: goto label_1b81b0;
            case 0x1B81C4u: goto label_1b81c4;
            case 0x1B81D8u: goto label_1b81d8;
            case 0x1B81E0u: goto label_1b81e0;
            case 0x1B81F0u: goto label_1b81f0;
            case 0x1B81F4u: goto label_1b81f4;
            case 0x1B8210u: goto label_1b8210;
            case 0x1B8220u: goto label_1b8220;
            case 0x1B822Cu: goto label_1b822c;
            case 0x1B8250u: goto label_1b8250;
            case 0x1B8260u: goto label_1b8260;
            case 0x1B826Cu: goto label_1b826c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8200u;
    // 0x1b8200: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8204: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b8204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b8208: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B8208u;
    SET_GPR_U32(ctx, 31, 0x1B8210u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8210u; }
        if (ctx->pc != 0x1B8210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8210u; }
        if (ctx->pc != 0x1B8210u) { return; }
    }
    ctx->pc = 0x1B8210u;
label_1b8210:
    // 0x1b8210: 0x3c04005c  lui         $a0, 0x5C
    ctx->pc = 0x1b8210u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)92 << 16));
    // 0x1b8214: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1b8214u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b8218: 0xc06dfd0  jal         func_1B7F40
    ctx->pc = 0x1B8218u;
    SET_GPR_U32(ctx, 31, 0x1B8220u);
    ctx->pc = 0x1B821Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8218u;
            // 0x1b821c: 0x2484a010  addiu       $a0, $a0, -0x5FF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942736));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7F40u;
    if (runtime->hasFunction(0x1B7F40u)) {
        auto targetFn = runtime->lookupFunction(0x1B7F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8220u; }
        if (ctx->pc != 0x1B8220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7F40_0x1b7f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8220u; }
        if (ctx->pc != 0x1B8220u) { return; }
    }
    ctx->pc = 0x1B8220u;
label_1b8220:
    // 0x1b8220: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1b8220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b8224: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B8224u;
    SET_GPR_U32(ctx, 31, 0x1B822Cu);
    ctx->pc = 0x1B8228u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8224u;
            // 0x1b8228: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B822Cu; }
        if (ctx->pc != 0x1B822Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B822Cu; }
        if (ctx->pc != 0x1B822Cu) { return; }
    }
    ctx->pc = 0x1B822Cu;
label_1b822c:
    // 0x1b822c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b822cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8230: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8230u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8230u;
            // 0x1b8234: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8188u: goto label_1b8188;
            case 0x1B8194u: goto label_1b8194;
            case 0x1B81B0u: goto label_1b81b0;
            case 0x1B81C4u: goto label_1b81c4;
            case 0x1B81D8u: goto label_1b81d8;
            case 0x1B81E0u: goto label_1b81e0;
            case 0x1B81F0u: goto label_1b81f0;
            case 0x1B81F4u: goto label_1b81f4;
            case 0x1B8210u: goto label_1b8210;
            case 0x1B8220u: goto label_1b8220;
            case 0x1B822Cu: goto label_1b822c;
            case 0x1B8250u: goto label_1b8250;
            case 0x1B8260u: goto label_1b8260;
            case 0x1B826Cu: goto label_1b826c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8238u;
    // 0x1b8238: 0x0  nop
    ctx->pc = 0x1b8238u;
    // NOP
    // 0x1b823c: 0x0  nop
    ctx->pc = 0x1b823cu;
    // NOP
    // 0x1b8240: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8244: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b8244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b8248: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B8248u;
    SET_GPR_U32(ctx, 31, 0x1B8250u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8250u; }
        if (ctx->pc != 0x1B8250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8250u; }
        if (ctx->pc != 0x1B8250u) { return; }
    }
    ctx->pc = 0x1B8250u;
label_1b8250:
    // 0x1b8250: 0x3c04005c  lui         $a0, 0x5C
    ctx->pc = 0x1b8250u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)92 << 16));
    // 0x1b8254: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1b8254u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b8258: 0xc06dfd0  jal         func_1B7F40
    ctx->pc = 0x1B8258u;
    SET_GPR_U32(ctx, 31, 0x1B8260u);
    ctx->pc = 0x1B825Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8258u;
            // 0x1b825c: 0x2484a1f0  addiu       $a0, $a0, -0x5E10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7F40u;
    if (runtime->hasFunction(0x1B7F40u)) {
        auto targetFn = runtime->lookupFunction(0x1B7F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8260u; }
        if (ctx->pc != 0x1B8260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7F40_0x1b7f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8260u; }
        if (ctx->pc != 0x1B8260u) { return; }
    }
    ctx->pc = 0x1B8260u;
label_1b8260:
    // 0x1b8260: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1b8260u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b8264: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B8264u;
    SET_GPR_U32(ctx, 31, 0x1B826Cu);
    ctx->pc = 0x1B8268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8264u;
            // 0x1b8268: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B826Cu; }
        if (ctx->pc != 0x1B826Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B826Cu; }
        if (ctx->pc != 0x1B826Cu) { return; }
    }
    ctx->pc = 0x1B826Cu;
label_1b826c:
    // 0x1b826c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b826cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8270: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8270u;
            // 0x1b8274: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8188u: goto label_1b8188;
            case 0x1B8194u: goto label_1b8194;
            case 0x1B81B0u: goto label_1b81b0;
            case 0x1B81C4u: goto label_1b81c4;
            case 0x1B81D8u: goto label_1b81d8;
            case 0x1B81E0u: goto label_1b81e0;
            case 0x1B81F0u: goto label_1b81f0;
            case 0x1B81F4u: goto label_1b81f4;
            case 0x1B8210u: goto label_1b8210;
            case 0x1B8220u: goto label_1b8220;
            case 0x1B822Cu: goto label_1b822c;
            case 0x1B8250u: goto label_1b8250;
            case 0x1B8260u: goto label_1b8260;
            case 0x1B826Cu: goto label_1b826c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8278u;
    // 0x1b8278: 0x0  nop
    ctx->pc = 0x1b8278u;
    // NOP
    // 0x1b827c: 0x0  nop
    ctx->pc = 0x1b827cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
