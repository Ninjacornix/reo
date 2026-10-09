#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136F98
// Address: 0x136f98 - 0x136fe8
void sub_00136F98_0x136f98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136F98_0x136f98");
#endif

    switch (ctx->pc) {
        case 0x136fa8u: goto label_136fa8;
        case 0x136fd0u: goto label_136fd0;
        default: break;
    }

    ctx->pc = 0x136f98u;

    // 0x136f98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136f98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x136f9c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x136f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x136fa0: 0xc04d558  jal         func_135560
    ctx->pc = 0x136FA0u;
    SET_GPR_U32(ctx, 31, 0x136FA8u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136FA8u; }
        if (ctx->pc != 0x136FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136FA8u; }
        if (ctx->pc != 0x136FA8u) { return; }
    }
    ctx->pc = 0x136FA8u;
label_136fa8:
    // 0x136fa8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x136fa8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136fac: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x136FACu;
    {
        const bool branch_taken_0x136fac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x136FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136FACu;
            // 0x136fb0: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136fac) {
            ctx->pc = 0x136FE0u;
            goto label_136fe0;
        }
    }
    ctx->pc = 0x136FB4u;
    // 0x136fb4: 0x8c620060  lw          $v0, 0x60($v1)
    ctx->pc = 0x136fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 96)));
    // 0x136fb8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136FB8u;
    {
        const bool branch_taken_0x136fb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136FB8u;
            // 0x136fbc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136fb8) {
            ctx->pc = 0x136FD8u;
            goto label_136fd8;
        }
    }
    ctx->pc = 0x136FC0u;
    // 0x136fc0: 0x24050064  addiu       $a1, $zero, 0x64
    ctx->pc = 0x136fc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x136fc4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136fc4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136fc8: 0x40f809  jalr        $v0
    ctx->pc = 0x136FC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136FD0u);
        ctx->pc = 0x136FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136FC8u;
            // 0x136fcc: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136FD0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136FA8u: goto label_136fa8;
            case 0x136FD0u: goto label_136fd0;
            case 0x136FD8u: goto label_136fd8;
            case 0x136FE0u: goto label_136fe0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136FD0u; }
            if (ctx->pc != 0x136FD0u) { return; }
        }
        }
    }
    ctx->pc = 0x136FD0u;
label_136fd0:
    // 0x136fd0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x136FD0u;
    {
        const bool branch_taken_0x136fd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136FD0u;
            // 0x136fd4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136fd0) {
            ctx->pc = 0x136FE0u;
            goto label_136fe0;
        }
    }
    ctx->pc = 0x136FD8u;
label_136fd8:
    // 0x136fd8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x136fd8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136fdc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136fdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_136fe0:
    // 0x136fe0: 0x3e00008  jr          $ra
    ctx->pc = 0x136FE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136FE0u;
            // 0x136fe4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136FA8u: goto label_136fa8;
            case 0x136FD0u: goto label_136fd0;
            case 0x136FD8u: goto label_136fd8;
            case 0x136FE0u: goto label_136fe0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136FE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
