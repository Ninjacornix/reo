#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138518
// Address: 0x138518 - 0x138580
void sub_00138518_0x138518(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138518_0x138518");
#endif

    switch (ctx->pc) {
        case 0x138534u: goto label_138534;
        case 0x138540u: goto label_138540;
        case 0x13855cu: goto label_13855c;
        case 0x138564u: goto label_138564;
        default: break;
    }

    ctx->pc = 0x138518u;

    // 0x138518: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x138518u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13851c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13851cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138520: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x138520u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138524: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x138524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x138528: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x138528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13852c: 0xc04e0bc  jal         func_1382F0
    ctx->pc = 0x13852Cu;
    SET_GPR_U32(ctx, 31, 0x138534u);
    ctx->pc = 0x138530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13852Cu;
            // 0x138530: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1382F0u;
    if (runtime->hasFunction(0x1382F0u)) {
        auto targetFn = runtime->lookupFunction(0x1382F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138534u; }
        if (ctx->pc != 0x138534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001382F0_0x1382f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138534u; }
        if (ctx->pc != 0x138534u) { return; }
    }
    ctx->pc = 0x138534u;
label_138534:
    // 0x138534: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x138534u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138538: 0xc04629c  jal         func_118A70
    ctx->pc = 0x138538u;
    SET_GPR_U32(ctx, 31, 0x138540u);
    ctx->pc = 0x13853Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138538u;
            // 0x13853c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138540u; }
        if (ctx->pc != 0x138540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138540u; }
        if (ctx->pc != 0x138540u) { return; }
    }
    ctx->pc = 0x138540u;
label_138540:
    // 0x138540: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138540u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138544: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x138544u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138548: 0x2484c760  addiu       $a0, $a0, -0x38A0
    ctx->pc = 0x138548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952800));
    // 0x13854c: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13854Cu;
    {
        const bool branch_taken_0x13854c = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x138550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13854Cu;
            // 0x138550: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13854c) {
            ctx->pc = 0x13855Cu;
            goto label_13855c;
        }
    }
    ctx->pc = 0x138554u;
    // 0x138554: 0xc045a12  jal         func_116848
    ctx->pc = 0x138554u;
    SET_GPR_U32(ctx, 31, 0x13855Cu);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13855Cu; }
        if (ctx->pc != 0x13855Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13855Cu; }
        if (ctx->pc != 0x13855Cu) { return; }
    }
    ctx->pc = 0x13855Cu;
label_13855c:
    // 0x13855c: 0xc04e0ca  jal         func_138328
    ctx->pc = 0x13855Cu;
    SET_GPR_U32(ctx, 31, 0x138564u);
    ctx->pc = 0x138328u;
    if (runtime->hasFunction(0x138328u)) {
        auto targetFn = runtime->lookupFunction(0x138328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138564u; }
        if (ctx->pc != 0x138564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138328_0x138328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138564u; }
        if (ctx->pc != 0x138564u) { return; }
    }
    ctx->pc = 0x138564u;
label_138564:
    // 0x138564: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x138564u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138568: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x138568u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13856c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13856cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138570: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x138570u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138574: 0x3e00008  jr          $ra
    ctx->pc = 0x138574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138574u;
            // 0x138578: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138534u: goto label_138534;
            case 0x138540u: goto label_138540;
            case 0x13855Cu: goto label_13855c;
            case 0x138564u: goto label_138564;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13857Cu;
    // 0x13857c: 0x0  nop
    ctx->pc = 0x13857cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
