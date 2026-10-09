#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001409E8
// Address: 0x1409e8 - 0x140a20
void sub_001409E8_0x1409e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001409E8_0x1409e8");
#endif

    switch (ctx->pc) {
        case 0x140a08u: goto label_140a08;
        default: break;
    }

    ctx->pc = 0x1409e8u;

    // 0x1409e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1409e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1409ec: 0x24820010  addiu       $v0, $a0, 0x10
    ctx->pc = 0x1409ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x1409f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1409f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1409f4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1409f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1409f8: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1409f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1409fc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1409fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140a00: 0xc050236  jal         func_1408D8
    ctx->pc = 0x140A00u;
    SET_GPR_U32(ctx, 31, 0x140A08u);
    ctx->pc = 0x140A04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140A00u;
            // 0x140a04: 0x24840008  addiu       $a0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1408D8u;
    if (runtime->hasFunction(0x1408D8u)) {
        auto targetFn = runtime->lookupFunction(0x1408D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140A08u; }
        if (ctx->pc != 0x140A08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001408D8_0x1408d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140A08u; }
        if (ctx->pc != 0x140A08u) { return; }
    }
    ctx->pc = 0x140A08u;
label_140a08:
    // 0x140a08: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x140a08u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x140a0c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140a0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140a10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140a10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140a14: 0x3e00008  jr          $ra
    ctx->pc = 0x140A14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140A14u;
            // 0x140a18: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140A08u: goto label_140a08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140A1Cu;
    // 0x140a1c: 0x0  nop
    ctx->pc = 0x140a1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
