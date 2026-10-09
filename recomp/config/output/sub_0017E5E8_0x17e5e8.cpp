#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E5E8
// Address: 0x17e5e8 - 0x17e628
void sub_0017E5E8_0x17e5e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E5E8_0x17e5e8");
#endif

    switch (ctx->pc) {
        case 0x17e618u: goto label_17e618;
        default: break;
    }

    ctx->pc = 0x17e5e8u;

    // 0x17e5e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17e5e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17e5ec: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E5ECu;
    {
        const bool branch_taken_0x17e5ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E5F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5ECu;
            // 0x17e5f0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5ec) {
            ctx->pc = 0x17E5FCu;
            goto label_17e5fc;
        }
    }
    ctx->pc = 0x17E5F4u;
    // 0x17e5f4: 0x4a10004  bgez        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17E5F4u;
    {
        const bool branch_taken_0x17e5f4 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x17E5F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5F4u;
            // 0x17e5f8: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5f4) {
            ctx->pc = 0x17E608u;
            goto label_17e608;
        }
    }
    ctx->pc = 0x17E5FCu;
label_17e5fc:
    // 0x17e5fc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x17E5FCu;
    {
        const bool branch_taken_0x17e5fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5FCu;
            // 0x17e600: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5fc) {
            ctx->pc = 0x17E61Cu;
            goto label_17e61c;
        }
    }
    ctx->pc = 0x17E604u;
    // 0x17e604: 0x0  nop
    ctx->pc = 0x17e604u;
    // NOP
label_17e608:
    // 0x17e608: 0x24840013  addiu       $a0, $a0, 0x13
    ctx->pc = 0x17e608u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19));
    // 0x17e60c: 0x24a51548  addiu       $a1, $a1, 0x1548
    ctx->pc = 0x17e60cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5448));
    // 0x17e610: 0xc042d10  jal         func_10B440
    ctx->pc = 0x17E610u;
    SET_GPR_U32(ctx, 31, 0x17E618u);
    ctx->pc = 0x17E614u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E610u;
            // 0x17e614: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E618u; }
        if (ctx->pc != 0x17E618u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E618u; }
        if (ctx->pc != 0x17E618u) { return; }
    }
    ctx->pc = 0x17E618u;
label_17e618:
    // 0x17e618: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x17e618u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_17e61c:
    // 0x17e61c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17e61cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e620: 0x3e00008  jr          $ra
    ctx->pc = 0x17E620u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E620u;
            // 0x17e624: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E5FCu: goto label_17e5fc;
            case 0x17E608u: goto label_17e608;
            case 0x17E618u: goto label_17e618;
            case 0x17E61Cu: goto label_17e61c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E628u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
