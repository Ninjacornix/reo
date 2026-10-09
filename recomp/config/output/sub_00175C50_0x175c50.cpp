#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175C50
// Address: 0x175c50 - 0x175c98
void sub_00175C50_0x175c50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175C50_0x175c50");
#endif

    switch (ctx->pc) {
        case 0x175c74u: goto label_175c74;
        default: break;
    }

    ctx->pc = 0x175c50u;

    // 0x175c50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x175c50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x175c54: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175c54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175c58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x175c58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175c5c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x175c5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175c60: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x175c60u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175c64: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x175c64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x175c68: 0x26040004  addiu       $a0, $s0, 0x4
    ctx->pc = 0x175c68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x175c6c: 0xc05d726  jal         func_175C98
    ctx->pc = 0x175C6Cu;
    SET_GPR_U32(ctx, 31, 0x175C74u);
    ctx->pc = 0x175C70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175C6Cu;
            // 0x175c70: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175C98u;
    if (runtime->hasFunction(0x175C98u)) {
        auto targetFn = runtime->lookupFunction(0x175C98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175C74u; }
        if (ctx->pc != 0x175C74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175C98_0x175c98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175C74u; }
        if (ctx->pc != 0x175C74u) { return; }
    }
    ctx->pc = 0x175C74u;
label_175c74:
    // 0x175c74: 0xae110020  sw          $s1, 0x20($s0)
    ctx->pc = 0x175c74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 17));
    // 0x175c78: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x175c78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x175c7c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x175c7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175c80: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x175c80u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x175c84: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175c84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175c88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175c88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175c8c: 0x3e00008  jr          $ra
    ctx->pc = 0x175C8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175C8Cu;
            // 0x175c90: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175C74u: goto label_175c74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175C94u;
    // 0x175c94: 0x0  nop
    ctx->pc = 0x175c94u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
