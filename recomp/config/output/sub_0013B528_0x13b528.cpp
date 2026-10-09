#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B528
// Address: 0x13b528 - 0x13b5b0
void sub_0013B528_0x13b528(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B528_0x13b528");
#endif

    switch (ctx->pc) {
        case 0x13b544u: goto label_13b544;
        case 0x13b554u: goto label_13b554;
        case 0x13b560u: goto label_13b560;
        case 0x13b574u: goto label_13b574;
        case 0x13b584u: goto label_13b584;
        case 0x13b590u: goto label_13b590;
        default: break;
    }

    ctx->pc = 0x13b528u;

    // 0x13b528: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13b528u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13b52c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13b52cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13b530: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13b530u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b534: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13b534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13b538: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13b538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13b53c: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B53Cu;
    SET_GPR_U32(ctx, 31, 0x13B544u);
    ctx->pc = 0x13B540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B53Cu;
            // 0x13b540: 0x24044700  addiu       $a0, $zero, 0x4700 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B544u; }
        if (ctx->pc != 0x13B544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B544u; }
        if (ctx->pc != 0x13B544u) { return; }
    }
    ctx->pc = 0x13B544u;
label_13b544:
    // 0x13b544: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13b544u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b548: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13b548u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b54c: 0xc04e0fa  jal         func_1383E8
    ctx->pc = 0x13B54Cu;
    SET_GPR_U32(ctx, 31, 0x13B554u);
    ctx->pc = 0x13B550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B54Cu;
            // 0x13b550: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1383E8u;
    if (runtime->hasFunction(0x1383E8u)) {
        auto targetFn = runtime->lookupFunction(0x1383E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B554u; }
        if (ctx->pc != 0x13B554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001383E8_0x1383e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B554u; }
        if (ctx->pc != 0x13B554u) { return; }
    }
    ctx->pc = 0x13B554u;
label_13b554:
    // 0x13b554: 0x24044701  addiu       $a0, $zero, 0x4701
    ctx->pc = 0x13b554u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18177));
    // 0x13b558: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B558u;
    SET_GPR_U32(ctx, 31, 0x13B560u);
    ctx->pc = 0x13B55Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B558u;
            // 0x13b55c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B560u; }
        if (ctx->pc != 0x13B560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B560u; }
        if (ctx->pc != 0x13B560u) { return; }
    }
    ctx->pc = 0x13B560u;
label_13b560:
    // 0x13b560: 0x24044800  addiu       $a0, $zero, 0x4800
    ctx->pc = 0x13b560u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18432));
    // 0x13b564: 0x600000d  bltz        $s0, . + 4 + (0xD << 2)
    ctx->pc = 0x13B564u;
    {
        const bool branch_taken_0x13b564 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x13B568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B564u;
            // 0x13b568: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b564) {
            ctx->pc = 0x13B59Cu;
            goto label_13b59c;
        }
    }
    ctx->pc = 0x13B56Cu;
    // 0x13b56c: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B56Cu;
    SET_GPR_U32(ctx, 31, 0x13B574u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B574u; }
        if (ctx->pc != 0x13B574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B574u; }
        if (ctx->pc != 0x13B574u) { return; }
    }
    ctx->pc = 0x13B574u;
label_13b574:
    // 0x13b574: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13b574u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b578: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13b578u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b57c: 0xc04e0fa  jal         func_1383E8
    ctx->pc = 0x13B57Cu;
    SET_GPR_U32(ctx, 31, 0x13B584u);
    ctx->pc = 0x13B580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B57Cu;
            // 0x13b580: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1383E8u;
    if (runtime->hasFunction(0x1383E8u)) {
        auto targetFn = runtime->lookupFunction(0x1383E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B584u; }
        if (ctx->pc != 0x13B584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001383E8_0x1383e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B584u; }
        if (ctx->pc != 0x13B584u) { return; }
    }
    ctx->pc = 0x13B584u;
label_13b584:
    // 0x13b584: 0x24044801  addiu       $a0, $zero, 0x4801
    ctx->pc = 0x13b584u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18433));
    // 0x13b588: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B588u;
    SET_GPR_U32(ctx, 31, 0x13B590u);
    ctx->pc = 0x13B58Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B588u;
            // 0x13b58c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B590u; }
        if (ctx->pc != 0x13B590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B590u; }
        if (ctx->pc != 0x13B590u) { return; }
    }
    ctx->pc = 0x13B590u;
label_13b590:
    // 0x13b590: 0x2a030000  slti        $v1, $s0, 0x0
    ctx->pc = 0x13b590u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x13b594: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13b594u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b598: 0x203100a  movz        $v0, $s0, $v1
    ctx->pc = 0x13b598u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 16));
label_13b59c:
    // 0x13b59c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13b59cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b5a0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13b5a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13b5a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13b5a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b5a8: 0x3e00008  jr          $ra
    ctx->pc = 0x13B5A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B5ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B5A8u;
            // 0x13b5ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B544u: goto label_13b544;
            case 0x13B554u: goto label_13b554;
            case 0x13B560u: goto label_13b560;
            case 0x13B574u: goto label_13b574;
            case 0x13B584u: goto label_13b584;
            case 0x13B590u: goto label_13b590;
            case 0x13B59Cu: goto label_13b59c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B5B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
