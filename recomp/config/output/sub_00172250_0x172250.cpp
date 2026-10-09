#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172250
// Address: 0x172250 - 0x172278
void sub_00172250_0x172250(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172250_0x172250");
#endif

    switch (ctx->pc) {
        case 0x17226cu: goto label_17226c;
        default: break;
    }

    ctx->pc = 0x172250u;

    // 0x172250: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x172254: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x172254u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172258: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x172258u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x17225c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x17225cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172260: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x172260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x172264: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x172264u;
    SET_GPR_U32(ctx, 31, 0x17226Cu);
    ctx->pc = 0x172268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172264u;
            // 0x172268: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17226Cu; }
        if (ctx->pc != 0x17226Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17226Cu; }
        if (ctx->pc != 0x17226Cu) { return; }
    }
    ctx->pc = 0x17226Cu;
label_17226c:
    // 0x17226c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17226cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172270: 0x3e00008  jr          $ra
    ctx->pc = 0x172270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172270u;
            // 0x172274: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17226Cu: goto label_17226c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172278u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
