#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001363A8
// Address: 0x1363a8 - 0x13640c
void sub_001363A8_0x1363a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001363A8_0x1363a8");
#endif

    switch (ctx->pc) {
        case 0x1363c8u: goto label_1363c8;
        case 0x1363e8u: goto label_1363e8;
        case 0x1363f8u: goto label_1363f8;
        default: break;
    }

    ctx->pc = 0x1363a8u;

    // 0x1363a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1363a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1363ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1363acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1363b0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1363b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1363b4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1363B4u;
    {
        const bool branch_taken_0x1363b4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1363B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1363B4u;
            // 0x1363b8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1363b4) {
            ctx->pc = 0x1363D0u;
            goto label_1363d0;
        }
    }
    ctx->pc = 0x1363BCu;
    // 0x1363bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1363bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1363c0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1363C0u;
    SET_GPR_U32(ctx, 31, 0x1363C8u);
    ctx->pc = 0x1363C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1363C0u;
            // 0x1363c4: 0x2484bd20  addiu       $a0, $a0, -0x42E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1363C8u; }
        if (ctx->pc != 0x1363C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1363C8u; }
        if (ctx->pc != 0x1363C8u) { return; }
    }
    ctx->pc = 0x1363C8u;
label_1363c8:
    // 0x1363c8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1363C8u;
    {
        const bool branch_taken_0x1363c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1363CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1363C8u;
            // 0x1363cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1363c8) {
            ctx->pc = 0x1363FCu;
            goto label_1363fc;
        }
    }
    ctx->pc = 0x1363D0u;
label_1363d0:
    // 0x1363d0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1363d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1363d4: 0x8c420038  lw          $v0, 0x38($v0)
    ctx->pc = 0x1363d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1363d8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1363D8u;
    {
        const bool branch_taken_0x1363d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1363d8) {
            ctx->pc = 0x1363DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1363D8u;
            // 0x1363dc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1363F0u;
            goto label_1363f0;
        }
    }
    ctx->pc = 0x1363E0u;
    // 0x1363e0: 0x40f809  jalr        $v0
    ctx->pc = 0x1363E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1363E8u);
        ctx->pc = 0x1363E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1363E0u;
            // 0x1363e4: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1363E8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1363E8u; }
            if (ctx->pc != 0x1363E8u) { return; }
        }
        }
    }
    ctx->pc = 0x1363E8u;
label_1363e8:
    // 0x1363e8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1363E8u;
    {
        const bool branch_taken_0x1363e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1363ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1363E8u;
            // 0x1363ec: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1363e8) {
            ctx->pc = 0x1363F8u;
            goto label_1363f8;
        }
    }
    ctx->pc = 0x1363F0u;
label_1363f0:
    // 0x1363f0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1363F0u;
    SET_GPR_U32(ctx, 31, 0x1363F8u);
    ctx->pc = 0x1363F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1363F0u;
            // 0x1363f4: 0x2484bd40  addiu       $a0, $a0, -0x42C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1363F8u; }
        if (ctx->pc != 0x1363F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1363F8u; }
        if (ctx->pc != 0x1363F8u) { return; }
    }
    ctx->pc = 0x1363F8u;
label_1363f8:
    // 0x1363f8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1363f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1363fc:
    // 0x1363fc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1363fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136400: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x136400u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x136404: 0x3e00008  jr          $ra
    ctx->pc = 0x136404u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136404u;
            // 0x136408: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13640Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
