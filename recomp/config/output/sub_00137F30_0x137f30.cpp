#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137F30
// Address: 0x137f30 - 0x137f68
void sub_00137F30_0x137f30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137F30_0x137f30");
#endif

    switch (ctx->pc) {
        case 0x137f44u: goto label_137f44;
        default: break;
    }

    ctx->pc = 0x137f30u;

    // 0x137f30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137f30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x137f34: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x137f34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137f38: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x137f38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x137f3c: 0xc04dfa4  jal         func_137E90
    ctx->pc = 0x137F3Cu;
    SET_GPR_U32(ctx, 31, 0x137F44u);
    ctx->pc = 0x137F40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137F3Cu;
            // 0x137f40: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137E90u;
    if (runtime->hasFunction(0x137E90u)) {
        auto targetFn = runtime->lookupFunction(0x137E90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137F44u; }
        if (ctx->pc != 0x137F44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137E90_0x137e90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137F44u; }
        if (ctx->pc != 0x137F44u) { return; }
    }
    ctx->pc = 0x137F44u;
label_137f44:
    // 0x137f44: 0x108600  sll         $s0, $s0, 24
    ctx->pc = 0x137f44u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 24));
    // 0x137f48: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137f48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x137f4c: 0x2442bbcc  addiu       $v0, $v0, -0x4434
    ctx->pc = 0x137f4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949836));
    // 0x137f50: 0x108603  sra         $s0, $s0, 24
    ctx->pc = 0x137f50u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 24));
    // 0x137f54: 0xac500000  sw          $s0, 0x0($v0)
    ctx->pc = 0x137f54u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 16));
    // 0x137f58: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x137f58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137f5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137f5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137f60: 0x3e00008  jr          $ra
    ctx->pc = 0x137F60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137F60u;
            // 0x137f64: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137F44u: goto label_137f44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137F68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
