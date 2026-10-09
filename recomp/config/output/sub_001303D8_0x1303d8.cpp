#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001303D8
// Address: 0x1303d8 - 0x130420
void sub_001303D8_0x1303d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001303D8_0x1303d8");
#endif

    switch (ctx->pc) {
        case 0x130400u: goto label_130400;
        case 0x130410u: goto label_130410;
        default: break;
    }

    ctx->pc = 0x1303d8u;

    // 0x1303d8: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1303d8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1303dc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1303dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1303e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1303e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1303e4: 0x28a20100  slti        $v0, $a1, 0x100
    ctx->pc = 0x1303e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1303e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1303e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1303ec: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1303ecu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1303f0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1303F0u;
    {
        const bool branch_taken_0x1303f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1303F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1303F0u;
            // 0x1303f4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1303f0) {
            ctx->pc = 0x130408u;
            goto label_130408;
        }
    }
    ctx->pc = 0x1303F8u;
    // 0x1303f8: 0xc04c086  jal         func_130218
    ctx->pc = 0x1303F8u;
    SET_GPR_U32(ctx, 31, 0x130400u);
    ctx->pc = 0x1303FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1303F8u;
            // 0x1303fc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130218u;
    if (runtime->hasFunction(0x130218u)) {
        auto targetFn = runtime->lookupFunction(0x130218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130400u; }
        if (ctx->pc != 0x130400u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130218_0x130218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130400u; }
        if (ctx->pc != 0x130400u) { return; }
    }
    ctx->pc = 0x130400u;
label_130400:
    // 0x130400: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x130400u;
    {
        const bool branch_taken_0x130400 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x130404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130400u;
            // 0x130404: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130400) {
            ctx->pc = 0x130414u;
            goto label_130414;
        }
    }
    ctx->pc = 0x130408u;
label_130408:
    // 0x130408: 0xc04c0be  jal         func_1302F8
    ctx->pc = 0x130408u;
    SET_GPR_U32(ctx, 31, 0x130410u);
    ctx->pc = 0x13040Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130408u;
            // 0x13040c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1302F8u;
    if (runtime->hasFunction(0x1302F8u)) {
        auto targetFn = runtime->lookupFunction(0x1302F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130410u; }
        if (ctx->pc != 0x130410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001302F8_0x1302f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130410u; }
        if (ctx->pc != 0x130410u) { return; }
    }
    ctx->pc = 0x130410u;
label_130410:
    // 0x130410: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x130410u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_130414:
    // 0x130414: 0x3e00008  jr          $ra
    ctx->pc = 0x130414u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130414u;
            // 0x130418: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130400u: goto label_130400;
            case 0x130408u: goto label_130408;
            case 0x130410u: goto label_130410;
            case 0x130414u: goto label_130414;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13041Cu;
    // 0x13041c: 0x0  nop
    ctx->pc = 0x13041cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
