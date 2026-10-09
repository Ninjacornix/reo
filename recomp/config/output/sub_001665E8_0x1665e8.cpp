#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001665E8
// Address: 0x1665e8 - 0x166630
void sub_001665E8_0x1665e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001665E8_0x1665e8");
#endif

    switch (ctx->pc) {
        case 0x166600u: goto label_166600;
        case 0x166620u: goto label_166620;
        default: break;
    }

    ctx->pc = 0x1665e8u;

    // 0x1665e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1665e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1665ec: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1665ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1665f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1665f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1665f4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1665f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1665f8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1665F8u;
    SET_GPR_U32(ctx, 31, 0x166600u);
    ctx->pc = 0x1665FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1665F8u;
            // 0x1665fc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166600u; }
        if (ctx->pc != 0x166600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166600u; }
        if (ctx->pc != 0x166600u) { return; }
    }
    ctx->pc = 0x166600u;
label_166600:
    // 0x166600: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166600u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166604: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x166604u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x166608: 0x24060007  addiu       $a2, $zero, 0x7
    ctx->pc = 0x166608u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x16660c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x16660cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166610: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x166610u;
    {
        const bool branch_taken_0x166610 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166610u;
            // 0x166614: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166610) {
            ctx->pc = 0x166620u;
            goto label_166620;
        }
    }
    ctx->pc = 0x166618u;
    // 0x166618: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x166618u;
    SET_GPR_U32(ctx, 31, 0x166620u);
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166620u; }
        if (ctx->pc != 0x166620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166620u; }
        if (ctx->pc != 0x166620u) { return; }
    }
    ctx->pc = 0x166620u;
label_166620:
    // 0x166620: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166620u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166624: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x166624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166628: 0x3e00008  jr          $ra
    ctx->pc = 0x166628u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16662Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166628u;
            // 0x16662c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166600u: goto label_166600;
            case 0x166620u: goto label_166620;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166630u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
