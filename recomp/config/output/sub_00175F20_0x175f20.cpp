#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175F20
// Address: 0x175f20 - 0x175f68
void sub_00175F20_0x175f20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175F20_0x175f20");
#endif

    switch (ctx->pc) {
        case 0x175f38u: goto label_175f38;
        default: break;
    }

    ctx->pc = 0x175f20u;

    // 0x175f20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x175f20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x175f24: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175f24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175f28: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x175f28u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175f2c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x175f2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x175f30: 0xc05d58a  jal         func_175628
    ctx->pc = 0x175F30u;
    SET_GPR_U32(ctx, 31, 0x175F38u);
    ctx->pc = 0x175F34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175F30u;
            // 0x175f34: 0x24050047  addiu       $a1, $zero, 0x47 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175F38u; }
        if (ctx->pc != 0x175F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175F38u; }
        if (ctx->pc != 0x175F38u) { return; }
    }
    ctx->pc = 0x175F38u;
label_175f38:
    // 0x175f38: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x175f38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x175f3c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x175F3Cu;
    {
        const bool branch_taken_0x175f3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x175f3c) {
            ctx->pc = 0x175F50u;
            goto label_175f50;
        }
    }
    ctx->pc = 0x175F44u;
    // 0x175f44: 0x8e020264  lw          $v0, 0x264($s0)
    ctx->pc = 0x175f44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 612)));
    // 0x175f48: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x175F48u;
    {
        const bool branch_taken_0x175f48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x175F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175F48u;
            // 0x175f4c: 0xae02028c  sw          $v0, 0x28C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 652), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175f48) {
            ctx->pc = 0x175F58u;
            goto label_175f58;
        }
    }
    ctx->pc = 0x175F50u;
label_175f50:
    // 0x175f50: 0x8e020298  lw          $v0, 0x298($s0)
    ctx->pc = 0x175f50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 664)));
    // 0x175f54: 0xae02028c  sw          $v0, 0x28C($s0)
    ctx->pc = 0x175f54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 652), GPR_U32(ctx, 2));
label_175f58:
    // 0x175f58: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175f58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175f5c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x175f5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175f60: 0x3e00008  jr          $ra
    ctx->pc = 0x175F60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175F60u;
            // 0x175f64: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175F38u: goto label_175f38;
            case 0x175F50u: goto label_175f50;
            case 0x175F58u: goto label_175f58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175F68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
