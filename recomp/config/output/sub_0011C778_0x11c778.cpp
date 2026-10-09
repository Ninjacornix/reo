#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C778
// Address: 0x11c778 - 0x11c798
void sub_0011C778_0x11c778(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C778_0x11c778");
#endif

    switch (ctx->pc) {
        case 0x11c78cu: goto label_11c78c;
        default: break;
    }

    ctx->pc = 0x11c778u;

    // 0x11c778: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11c778u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11c77c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11c77cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c780: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11c780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11c784: 0xc047154  jal         func_11C550
    ctx->pc = 0x11C784u;
    SET_GPR_U32(ctx, 31, 0x11C78Cu);
    ctx->pc = 0x11C788u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C784u;
            // 0x11c788: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C550u;
    if (runtime->hasFunction(0x11C550u)) {
        auto targetFn = runtime->lookupFunction(0x11C550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C78Cu; }
        if (ctx->pc != 0x11C78Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C550_0x11c550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C78Cu; }
        if (ctx->pc != 0x11C78Cu) { return; }
    }
    ctx->pc = 0x11C78Cu;
label_11c78c:
    // 0x11c78c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11c78cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c790: 0x3e00008  jr          $ra
    ctx->pc = 0x11C790u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C790u;
            // 0x11c794: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C78Cu: goto label_11c78c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C798u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
