#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5820
// Address: 0x1c5820 - 0x1c58b8
void sub_001C5820_0x1c5820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5820_0x1c5820");
#endif

    switch (ctx->pc) {
        case 0x1c5840u: goto label_1c5840;
        case 0x1c584cu: goto label_1c584c;
        case 0x1c5864u: goto label_1c5864;
        case 0x1c5874u: goto label_1c5874;
        case 0x1c587cu: goto label_1c587c;
        case 0x1c5898u: goto label_1c5898;
        case 0x1c58a0u: goto label_1c58a0;
        default: break;
    }

    ctx->pc = 0x1c5820u;

    // 0x1c5820: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c5820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c5824: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1c5824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1c5828: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c5828u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c582c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c582cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c5830: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1c5830u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5834: 0x3c110025  lui         $s1, 0x25
    ctx->pc = 0x1c5834u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)37 << 16));
    // 0x1c5838: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5838u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c583c: 0x26312d60  addiu       $s1, $s1, 0x2D60
    ctx->pc = 0x1c583cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 11616));
label_1c5840:
    // 0x1c5840: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c5840u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5844: 0xc04a432  jal         func_1290C8
    ctx->pc = 0x1C5844u;
    SET_GPR_U32(ctx, 31, 0x1C584Cu);
    ctx->pc = 0x1C5848u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5844u;
            // 0x1c5848: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1290C8u;
    if (runtime->hasFunction(0x1290C8u)) {
        auto targetFn = runtime->lookupFunction(0x1290C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C584Cu; }
        if (ctx->pc != 0x1C584Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001290C8_0x1290c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C584Cu; }
        if (ctx->pc != 0x1C584Cu) { return; }
    }
    ctx->pc = 0x1C584Cu;
label_1c584c:
    // 0x1c584c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1c584cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5850: 0x0  nop
    ctx->pc = 0x1c5850u;
    // NOP
    // 0x1c5854: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1C5854u;
    {
        const bool branch_taken_0x1c5854 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c5854) {
            ctx->pc = 0x1C5840u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5840;
        }
    }
    ctx->pc = 0x1C585Cu;
    // 0x1c585c: 0xc04a702  jal         func_129C08
    ctx->pc = 0x1C585Cu;
    SET_GPR_U32(ctx, 31, 0x1C5864u);
    ctx->pc = 0x1C5860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C585Cu;
            // 0x1c5860: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129C08u;
    if (runtime->hasFunction(0x129C08u)) {
        auto targetFn = runtime->lookupFunction(0x129C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5864u; }
        if (ctx->pc != 0x1C5864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129C08_0x129c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5864u; }
        if (ctx->pc != 0x1C5864u) { return; }
    }
    ctx->pc = 0x1C5864u;
label_1c5864:
    // 0x1c5864: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1c5864u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5868: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c5868u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c586c: 0xc04a5e8  jal         func_1297A0
    ctx->pc = 0x1C586Cu;
    SET_GPR_U32(ctx, 31, 0x1C5874u);
    ctx->pc = 0x1C5870u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C586Cu;
            // 0x1c5870: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297A0u;
    if (runtime->hasFunction(0x1297A0u)) {
        auto targetFn = runtime->lookupFunction(0x1297A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5874u; }
        if (ctx->pc != 0x1C5874u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5874u; }
        if (ctx->pc != 0x1C5874u) { return; }
    }
    ctx->pc = 0x1C5874u;
label_1c5874:
    // 0x1c5874: 0xc04a752  jal         func_129D48
    ctx->pc = 0x1C5874u;
    SET_GPR_U32(ctx, 31, 0x1C587Cu);
    ctx->pc = 0x1C5878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5874u;
            // 0x1c5878: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129D48u;
    if (runtime->hasFunction(0x129D48u)) {
        auto targetFn = runtime->lookupFunction(0x129D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C587Cu; }
        if (ctx->pc != 0x1C587Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D48_0x129d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C587Cu; }
        if (ctx->pc != 0x1C587Cu) { return; }
    }
    ctx->pc = 0x1C587Cu;
label_1c587c:
    // 0x1c587c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c587cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c5880: 0x0  nop
    ctx->pc = 0x1c5880u;
    // NOP
    // 0x1c5884: 0x0  nop
    ctx->pc = 0x1c5884u;
    // NOP
    // 0x1c5888: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1C5888u;
    {
        const bool branch_taken_0x1c5888 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c5888) {
            ctx->pc = 0x1C5874u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5874;
        }
    }
    ctx->pc = 0x1C5890u;
    // 0x1c5890: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x1C5890u;
    SET_GPR_U32(ctx, 31, 0x1C5898u);
    ctx->pc = 0x1C5894u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5890u;
            // 0x1c5894: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5898u; }
        if (ctx->pc != 0x1C5898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5898u; }
        if (ctx->pc != 0x1C5898u) { return; }
    }
    ctx->pc = 0x1C5898u;
label_1c5898:
    // 0x1c5898: 0xc0704b0  jal         func_1C12C0
    ctx->pc = 0x1C5898u;
    SET_GPR_U32(ctx, 31, 0x1C58A0u);
    ctx->pc = 0x1C589Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5898u;
            // 0x1c589c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C12C0u;
    if (runtime->hasFunction(0x1C12C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C12C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C58A0u; }
        if (ctx->pc != 0x1C58A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C12C0_0x1c12c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C58A0u; }
        if (ctx->pc != 0x1C58A0u) { return; }
    }
    ctx->pc = 0x1C58A0u;
label_1c58a0:
    // 0x1c58a0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1c58a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c58a4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c58a4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c58a8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c58a8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c58ac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c58acu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c58b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C58B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C58B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C58B0u;
            // 0x1c58b4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5840u: goto label_1c5840;
            case 0x1C584Cu: goto label_1c584c;
            case 0x1C5864u: goto label_1c5864;
            case 0x1C5874u: goto label_1c5874;
            case 0x1C587Cu: goto label_1c587c;
            case 0x1C5898u: goto label_1c5898;
            case 0x1C58A0u: goto label_1c58a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C58B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
