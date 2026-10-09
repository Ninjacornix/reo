#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AC730
// Address: 0x1ac730 - 0x1ac7f0
void sub_001AC730_0x1ac730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AC730_0x1ac730");
#endif

    switch (ctx->pc) {
        case 0x1ac758u: goto label_1ac758;
        case 0x1ac764u: goto label_1ac764;
        case 0x1ac77cu: goto label_1ac77c;
        case 0x1ac784u: goto label_1ac784;
        case 0x1ac78cu: goto label_1ac78c;
        case 0x1ac798u: goto label_1ac798;
        case 0x1ac7a8u: goto label_1ac7a8;
        case 0x1ac7b0u: goto label_1ac7b0;
        case 0x1ac7c0u: goto label_1ac7c0;
        case 0x1ac7d0u: goto label_1ac7d0;
        default: break;
    }

    ctx->pc = 0x1ac730u;

    // 0x1ac730: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1ac730u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ac734: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ac734u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1ac738: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ac738u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ac73c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ac73cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ac740: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ac740u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ac744: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1ac744u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac748: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1ac748u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac74c: 0x3444000c  ori         $a0, $v0, 0xC
    ctx->pc = 0x1ac74cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12);
    // 0x1ac750: 0xc06a030  jal         func_1A80C0
    ctx->pc = 0x1AC750u;
    SET_GPR_U32(ctx, 31, 0x1AC758u);
    ctx->pc = 0x1AC754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC750u;
            // 0x1ac754: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A80C0u;
    if (runtime->hasFunction(0x1A80C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A80C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC758u; }
        if (ctx->pc != 0x1AC758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A80C0_0x1a80c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC758u; }
        if (ctx->pc != 0x1AC758u) { return; }
    }
    ctx->pc = 0x1AC758u;
label_1ac758:
    // 0x1ac758: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1ac758u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac75c: 0xc06b3ec  jal         func_1ACFB0
    ctx->pc = 0x1AC75Cu;
    SET_GPR_U32(ctx, 31, 0x1AC764u);
    ctx->pc = 0x1AC760u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC75Cu;
            // 0x1ac760: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACFB0u;
    if (runtime->hasFunction(0x1ACFB0u)) {
        auto targetFn = runtime->lookupFunction(0x1ACFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC764u; }
        if (ctx->pc != 0x1AC764u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACFB0_0x1acfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC764u; }
        if (ctx->pc != 0x1AC764u) { return; }
    }
    ctx->pc = 0x1AC764u;
label_1ac764:
    // 0x1ac764: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AC764u;
    {
        const bool branch_taken_0x1ac764 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1AC768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC764u;
            // 0x1ac768: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac764) {
            ctx->pc = 0x1AC774u;
            goto label_1ac774;
        }
    }
    ctx->pc = 0x1AC76Cu;
    // 0x1ac76c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1AC76Cu;
    {
        const bool branch_taken_0x1ac76c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC76Cu;
            // 0x1ac770: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac76c) {
            ctx->pc = 0x1AC7D8u;
            goto label_1ac7d8;
        }
    }
    ctx->pc = 0x1AC774u;
label_1ac774:
    // 0x1ac774: 0xc06ade4  jal         func_1AB790
    ctx->pc = 0x1AC774u;
    SET_GPR_U32(ctx, 31, 0x1AC77Cu);
    ctx->pc = 0x1AB790u;
    if (runtime->hasFunction(0x1AB790u)) {
        auto targetFn = runtime->lookupFunction(0x1AB790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC77Cu; }
        if (ctx->pc != 0x1AC77Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB790_0x1ab790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC77Cu; }
        if (ctx->pc != 0x1AC77Cu) { return; }
    }
    ctx->pc = 0x1AC77Cu;
label_1ac77c:
    // 0x1ac77c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AC77Cu;
    {
        const bool branch_taken_0x1ac77c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC77Cu;
            // 0x1ac780: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac77c) {
            ctx->pc = 0x1AC790u;
            goto label_1ac790;
        }
    }
    ctx->pc = 0x1AC784u;
label_1ac784:
    // 0x1ac784: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x1AC784u;
    SET_GPR_U32(ctx, 31, 0x1AC78Cu);
    ctx->pc = 0x1AC788u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC784u;
            // 0x1ac788: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC78Cu; }
        if (ctx->pc != 0x1AC78Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC78Cu; }
        if (ctx->pc != 0x1AC78Cu) { return; }
    }
    ctx->pc = 0x1AC78Cu;
label_1ac78c:
    // 0x1ac78c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1ac78cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1ac790:
    // 0x1ac790: 0xc069fd4  jal         func_1A7F50
    ctx->pc = 0x1AC790u;
    SET_GPR_U32(ctx, 31, 0x1AC798u);
    ctx->pc = 0x1A7F50u;
    if (runtime->hasFunction(0x1A7F50u)) {
        auto targetFn = runtime->lookupFunction(0x1A7F50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC798u; }
        if (ctx->pc != 0x1AC798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7F50_0x1a7f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC798u; }
        if (ctx->pc != 0x1AC798u) { return; }
    }
    ctx->pc = 0x1AC798u;
label_1ac798:
    // 0x1ac798: 0x1c40fffa  bgtz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AC798u;
    {
        const bool branch_taken_0x1ac798 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1ac798) {
            ctx->pc = 0x1AC784u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ac784;
        }
    }
    ctx->pc = 0x1AC7A0u;
    // 0x1ac7a0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AC7A0u;
    {
        const bool branch_taken_0x1ac7a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC7A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC7A0u;
            // 0x1ac7a4: 0x3c028000  lui         $v0, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac7a0) {
            ctx->pc = 0x1AC7B4u;
            goto label_1ac7b4;
        }
    }
    ctx->pc = 0x1AC7A8u;
label_1ac7a8:
    // 0x1ac7a8: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x1AC7A8u;
    SET_GPR_U32(ctx, 31, 0x1AC7B0u);
    ctx->pc = 0x1AC7ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC7A8u;
            // 0x1ac7ac: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC7B0u; }
        if (ctx->pc != 0x1AC7B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC7B0u; }
        if (ctx->pc != 0x1AC7B0u) { return; }
    }
    ctx->pc = 0x1AC7B0u;
label_1ac7b0:
    // 0x1ac7b0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ac7b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
label_1ac7b4:
    // 0x1ac7b4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1ac7b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac7b8: 0xc06a030  jal         func_1A80C0
    ctx->pc = 0x1AC7B8u;
    SET_GPR_U32(ctx, 31, 0x1AC7C0u);
    ctx->pc = 0x1AC7BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC7B8u;
            // 0x1ac7bc: 0x3444000c  ori         $a0, $v0, 0xC (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A80C0u;
    if (runtime->hasFunction(0x1A80C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A80C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC7C0u; }
        if (ctx->pc != 0x1AC7C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A80C0_0x1a80c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC7C0u; }
        if (ctx->pc != 0x1AC7C0u) { return; }
    }
    ctx->pc = 0x1AC7C0u;
label_1ac7c0:
    // 0x1ac7c0: 0x1c40fff9  bgtz        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1AC7C0u;
    {
        const bool branch_taken_0x1ac7c0 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1ac7c0) {
            ctx->pc = 0x1AC7A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ac7a8;
        }
    }
    ctx->pc = 0x1AC7C8u;
    // 0x1ac7c8: 0xc06adfc  jal         func_1AB7F0
    ctx->pc = 0x1AC7C8u;
    SET_GPR_U32(ctx, 31, 0x1AC7D0u);
    ctx->pc = 0x1AB7F0u;
    if (runtime->hasFunction(0x1AB7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC7D0u; }
        if (ctx->pc != 0x1AC7D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB7F0_0x1ab7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC7D0u; }
        if (ctx->pc != 0x1AC7D0u) { return; }
    }
    ctx->pc = 0x1AC7D0u;
label_1ac7d0:
    // 0x1ac7d0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1ac7d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac7d4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ac7d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1ac7d8:
    // 0x1ac7d8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ac7d8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ac7dc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ac7dcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ac7e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC7E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AC7E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC7E0u;
            // 0x1ac7e4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AC758u: goto label_1ac758;
            case 0x1AC764u: goto label_1ac764;
            case 0x1AC774u: goto label_1ac774;
            case 0x1AC77Cu: goto label_1ac77c;
            case 0x1AC784u: goto label_1ac784;
            case 0x1AC78Cu: goto label_1ac78c;
            case 0x1AC790u: goto label_1ac790;
            case 0x1AC798u: goto label_1ac798;
            case 0x1AC7A8u: goto label_1ac7a8;
            case 0x1AC7B0u: goto label_1ac7b0;
            case 0x1AC7B4u: goto label_1ac7b4;
            case 0x1AC7C0u: goto label_1ac7c0;
            case 0x1AC7D0u: goto label_1ac7d0;
            case 0x1AC7D8u: goto label_1ac7d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AC7E8u;
    // 0x1ac7e8: 0x0  nop
    ctx->pc = 0x1ac7e8u;
    // NOP
    // 0x1ac7ec: 0x0  nop
    ctx->pc = 0x1ac7ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
