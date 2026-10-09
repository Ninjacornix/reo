#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB110
// Address: 0x1bb110 - 0x1bb160
void sub_001BB110_0x1bb110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB110_0x1bb110");
#endif

    switch (ctx->pc) {
        case 0x1bb148u: goto label_1bb148;
        default: break;
    }

    ctx->pc = 0x1bb110u;

    // 0x1bb110: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bb110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb114: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bb114u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bb118: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bb118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb11c: 0x8c234e20  lw          $v1, 0x4E20($at)
    ctx->pc = 0x1bb11cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20000)));
    // 0x1bb120: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1bb120u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1bb124: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bb124u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bb128: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BB128u;
    {
        const bool branch_taken_0x1bb128 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BB12Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB128u;
            // 0x1bb12c: 0xac234e20  sw          $v1, 0x4E20($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20000), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb128) {
            ctx->pc = 0x1BB148u;
            goto label_1bb148;
        }
    }
    ctx->pc = 0x1BB130u;
    // 0x1bb130: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1bb130u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1bb134: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1bb134u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1bb138: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bb138u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bb13c: 0x24844198  addiu       $a0, $a0, 0x4198
    ctx->pc = 0x1bb13cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16792));
    // 0x1bb140: 0xc040742  jal         func_101D08
    ctx->pc = 0x1BB140u;
    SET_GPR_U32(ctx, 31, 0x1BB148u);
    ctx->pc = 0x1BB144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB140u;
            // 0x1bb144: 0xac224e20  sw          $v0, 0x4E20($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20000), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101D08u;
    if (runtime->hasFunction(0x101D08u)) {
        auto targetFn = runtime->lookupFunction(0x101D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB148u; }
        if (ctx->pc != 0x1BB148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101D08_0x101d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB148u; }
        if (ctx->pc != 0x1BB148u) { return; }
    }
    ctx->pc = 0x1BB148u;
label_1bb148:
    // 0x1bb148: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bb148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb14c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB14Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB14Cu;
            // 0x1bb150: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB148u: goto label_1bb148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB154u;
    // 0x1bb154: 0x0  nop
    ctx->pc = 0x1bb154u;
    // NOP
    // 0x1bb158: 0x0  nop
    ctx->pc = 0x1bb158u;
    // NOP
    // 0x1bb15c: 0x0  nop
    ctx->pc = 0x1bb15cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
