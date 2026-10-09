#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B64F0
// Address: 0x1b64f0 - 0x1b6580
void sub_001B64F0_0x1b64f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B64F0_0x1b64f0");
#endif

    switch (ctx->pc) {
        case 0x1b6504u: goto label_1b6504;
        case 0x1b653cu: goto label_1b653c;
        default: break;
    }

    ctx->pc = 0x1b64f0u;

    // 0x1b64f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b64f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b64f4: 0x14a0000f  bnez        $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x1B64F4u;
    {
        const bool branch_taken_0x1b64f4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B64F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B64F4u;
            // 0x1b64f8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b64f4) {
            ctx->pc = 0x1B6534u;
            goto label_1b6534;
        }
    }
    ctx->pc = 0x1B64FCu;
    // 0x1b64fc: 0xc06d8e0  jal         func_1B6380
    ctx->pc = 0x1B64FCu;
    SET_GPR_U32(ctx, 31, 0x1B6504u);
    ctx->pc = 0x1B6380u;
    if (runtime->hasFunction(0x1B6380u)) {
        auto targetFn = runtime->lookupFunction(0x1B6380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6504u; }
        if (ctx->pc != 0x1B6504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6380_0x1b6380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6504u; }
        if (ctx->pc != 0x1B6504u) { return; }
    }
    ctx->pc = 0x1B6504u;
label_1b6504:
    // 0x1b6504: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1b6504u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6508: 0x41a02  srl         $v1, $a0, 8
    ctx->pc = 0x1b6508u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x1b650c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1b650cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1b6510: 0x2464ffdf  addiu       $a0, $v1, -0x21
    ctx->pc = 0x1b6510u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967263));
    // 0x1b6514: 0x2442ffdf  addiu       $v0, $v0, -0x21
    ctx->pc = 0x1b6514u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967263));
    // 0x1b6518: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1b6518u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b651c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b651cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b6520: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1b6520u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1b6524: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1b6524u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b6528: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b6528u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b652c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1B652Cu;
    {
        const bool branch_taken_0x1b652c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B652Cu;
            // 0x1b6530: 0x621021  addu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b652c) {
            ctx->pc = 0x1B6568u;
            goto label_1b6568;
        }
    }
    ctx->pc = 0x1B6534u;
label_1b6534:
    // 0x1b6534: 0xc06d918  jal         func_1B6460
    ctx->pc = 0x1B6534u;
    SET_GPR_U32(ctx, 31, 0x1B653Cu);
    ctx->pc = 0x1B6460u;
    if (runtime->hasFunction(0x1B6460u)) {
        auto targetFn = runtime->lookupFunction(0x1B6460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B653Cu; }
        if (ctx->pc != 0x1B653Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6460_0x1b6460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B653Cu; }
        if (ctx->pc != 0x1B653Cu) { return; }
    }
    ctx->pc = 0x1B653Cu;
label_1b653c:
    // 0x1b653c: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1b653cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1b6540: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1b6540u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1b6544: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1b6544u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1b6548: 0x2464ffdf  addiu       $a0, $v1, -0x21
    ctx->pc = 0x1b6548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967263));
    // 0x1b654c: 0x2442ffdf  addiu       $v0, $v0, -0x21
    ctx->pc = 0x1b654cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967263));
    // 0x1b6550: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1b6550u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b6554: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b6554u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b6558: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1b6558u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1b655c: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1b655cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b6560: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b6560u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b6564: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b6564u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1b6568:
    // 0x1b6568: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b6568u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b656c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B656Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B656Cu;
            // 0x1b6570: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B6504u: goto label_1b6504;
            case 0x1B6534u: goto label_1b6534;
            case 0x1B653Cu: goto label_1b653c;
            case 0x1B6568u: goto label_1b6568;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B6574u;
    // 0x1b6574: 0x0  nop
    ctx->pc = 0x1b6574u;
    // NOP
    // 0x1b6578: 0x0  nop
    ctx->pc = 0x1b6578u;
    // NOP
    // 0x1b657c: 0x0  nop
    ctx->pc = 0x1b657cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
