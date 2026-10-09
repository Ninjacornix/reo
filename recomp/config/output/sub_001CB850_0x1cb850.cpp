#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CB850
// Address: 0x1cb850 - 0x1cb8c0
void sub_001CB850_0x1cb850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CB850_0x1cb850");
#endif

    switch (ctx->pc) {
        case 0x1cb880u: goto label_1cb880;
        case 0x1cb88cu: goto label_1cb88c;
        case 0x1cb8a0u: goto label_1cb8a0;
        case 0x1cb8acu: goto label_1cb8ac;
        default: break;
    }

    ctx->pc = 0x1cb850u;

    // 0x1cb850: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cb850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cb854: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x1cb854u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb858: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cb858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cb85c: 0x11400003  beqz        $t2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB85Cu;
    {
        const bool branch_taken_0x1cb85c = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB85Cu;
            // 0x1cb860: 0xa0482d  daddu       $t1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb85c) {
            ctx->pc = 0x1CB86Cu;
            goto label_1cb86c;
        }
    }
    ctx->pc = 0x1CB864u;
    // 0x1cb864: 0x15200003  bnez        $t1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB864u;
    {
        const bool branch_taken_0x1cb864 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CB868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB864u;
            // 0x1cb868: 0x30c8ffff  andi        $t0, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb864) {
            ctx->pc = 0x1CB874u;
            goto label_1cb874;
        }
    }
    ctx->pc = 0x1CB86Cu;
label_1cb86c:
    // 0x1cb86c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1CB86Cu;
    {
        const bool branch_taken_0x1cb86c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB86Cu;
            // 0x1cb870: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb86c) {
            ctx->pc = 0x1CB8B4u;
            goto label_1cb8b4;
        }
    }
    ctx->pc = 0x1CB874u;
label_1cb874:
    // 0x1cb874: 0x120202d  daddu       $a0, $t1, $zero
    ctx->pc = 0x1cb874u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb878: 0xc072e00  jal         func_1CB800
    ctx->pc = 0x1CB878u;
    SET_GPR_U32(ctx, 31, 0x1CB880u);
    ctx->pc = 0x1CB87Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB878u;
            // 0x1cb87c: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB800u;
    if (runtime->hasFunction(0x1CB800u)) {
        auto targetFn = runtime->lookupFunction(0x1CB800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB880u; }
        if (ctx->pc != 0x1CB880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB800_0x1cb800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB880u; }
        if (ctx->pc != 0x1CB880u) { return; }
    }
    ctx->pc = 0x1CB880u;
label_1cb880:
    // 0x1cb880: 0x25240004  addiu       $a0, $t1, 0x4
    ctx->pc = 0x1cb880u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
    // 0x1cb884: 0xc072e00  jal         func_1CB800
    ctx->pc = 0x1CB884u;
    SET_GPR_U32(ctx, 31, 0x1CB88Cu);
    ctx->pc = 0x1CB888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB884u;
            // 0x1cb888: 0x1024821  addu        $t1, $t0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB800u;
    if (runtime->hasFunction(0x1CB800u)) {
        auto targetFn = runtime->lookupFunction(0x1CB800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB88Cu; }
        if (ctx->pc != 0x1CB88Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB800_0x1cb800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB88Cu; }
        if (ctx->pc != 0x1CB88Cu) { return; }
    }
    ctx->pc = 0x1CB88Cu;
label_1cb88c:
    // 0x1cb88c: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x1cb88cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x1cb890: 0x120282d  daddu       $a1, $t1, $zero
    ctx->pc = 0x1cb890u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb894: 0x140202d  daddu       $a0, $t2, $zero
    ctx->pc = 0x1cb894u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb898: 0xc072dec  jal         func_1CB7B0
    ctx->pc = 0x1CB898u;
    SET_GPR_U32(ctx, 31, 0x1CB8A0u);
    ctx->pc = 0x1CB89Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB898u;
            // 0x1cb89c: 0x24060005  addiu       $a2, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB7B0u;
    if (runtime->hasFunction(0x1CB7B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CB7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB8A0u; }
        if (ctx->pc != 0x1CB8A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB7B0_0x1cb7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB8A0u; }
        if (ctx->pc != 0x1CB8A0u) { return; }
    }
    ctx->pc = 0x1CB8A0u;
label_1cb8a0:
    // 0x1cb8a0: 0x100282d  daddu       $a1, $t0, $zero
    ctx->pc = 0x1cb8a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb8a4: 0xc072dec  jal         func_1CB7B0
    ctx->pc = 0x1CB8A4u;
    SET_GPR_U32(ctx, 31, 0x1CB8ACu);
    ctx->pc = 0x1CB8A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB8A4u;
            // 0x1cb8a8: 0x25440005  addiu       $a0, $t2, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 10), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB7B0u;
    if (runtime->hasFunction(0x1CB7B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CB7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB8ACu; }
        if (ctx->pc != 0x1CB8ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB7B0_0x1cb7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB8ACu; }
        if (ctx->pc != 0x1CB8ACu) { return; }
    }
    ctx->pc = 0x1CB8ACu;
label_1cb8ac:
    // 0x1cb8ac: 0xa140000a  sb          $zero, 0xA($t2)
    ctx->pc = 0x1cb8acu;
    WRITE8(ADD32(GPR_U32(ctx, 10), 10), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb8b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb8b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb8b4:
    // 0x1cb8b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cb8b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb8b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB8B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB8BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB8B8u;
            // 0x1cb8bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB86Cu: goto label_1cb86c;
            case 0x1CB874u: goto label_1cb874;
            case 0x1CB880u: goto label_1cb880;
            case 0x1CB88Cu: goto label_1cb88c;
            case 0x1CB8A0u: goto label_1cb8a0;
            case 0x1CB8ACu: goto label_1cb8ac;
            case 0x1CB8B4u: goto label_1cb8b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB8C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
