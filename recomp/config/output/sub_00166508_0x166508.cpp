#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166508
// Address: 0x166508 - 0x166548
void sub_00166508_0x166508(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166508_0x166508");
#endif

    switch (ctx->pc) {
        case 0x166520u: goto label_166520;
        case 0x166534u: goto label_166534;
        default: break;
    }

    ctx->pc = 0x166508u;

    // 0x166508: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166508u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16650c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16650cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x166510: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166514: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x166514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x166518: 0xc05d58a  jal         func_175628
    ctx->pc = 0x166518u;
    SET_GPR_U32(ctx, 31, 0x166520u);
    ctx->pc = 0x16651Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166518u;
            // 0x16651c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166520u; }
        if (ctx->pc != 0x166520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166520u; }
        if (ctx->pc != 0x166520u) { return; }
    }
    ctx->pc = 0x166520u;
label_166520:
    // 0x166520: 0x26032a5c  addiu       $v1, $s0, 0x2A5C
    ctx->pc = 0x166520u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 10844));
    // 0x166524: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x166524u;
    {
        const bool branch_taken_0x166524 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166524u;
            // 0x166528: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166524) {
            ctx->pc = 0x166538u;
            goto label_166538;
        }
    }
    ctx->pc = 0x16652Cu;
    // 0x16652c: 0xc059952  jal         func_166548
    ctx->pc = 0x16652Cu;
    SET_GPR_U32(ctx, 31, 0x166534u);
    ctx->pc = 0x166530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16652Cu;
            // 0x166530: 0xae031c84  sw          $v1, 0x1C84($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 7300), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166548u;
    if (runtime->hasFunction(0x166548u)) {
        auto targetFn = runtime->lookupFunction(0x166548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166534u; }
        if (ctx->pc != 0x166534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166548_0x166548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166534u; }
        if (ctx->pc != 0x166534u) { return; }
    }
    ctx->pc = 0x166534u;
label_166534:
    // 0x166534: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166534u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_166538:
    // 0x166538: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166538u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16653c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16653cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166540: 0x3e00008  jr          $ra
    ctx->pc = 0x166540u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166540u;
            // 0x166544: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166520u: goto label_166520;
            case 0x166534u: goto label_166534;
            case 0x166538u: goto label_166538;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166548u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
