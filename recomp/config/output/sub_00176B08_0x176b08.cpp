#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176B08
// Address: 0x176b08 - 0x176b40
void sub_00176B08_0x176b08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176B08_0x176b08");
#endif

    switch (ctx->pc) {
        case 0x176b28u: goto label_176b28;
        default: break;
    }

    ctx->pc = 0x176b08u;

    // 0x176b08: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176b08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176b0c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176b0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176b10: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x176b10u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176b14: 0x24047530  addiu       $a0, $zero, 0x7530
    ctx->pc = 0x176b14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 30000));
    // 0x176b18: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176b18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176b1c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x176b1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x176b20: 0xc05da98  jal         func_176A60
    ctx->pc = 0x176B20u;
    SET_GPR_U32(ctx, 31, 0x176B28u);
    ctx->pc = 0x176B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176B20u;
            // 0x176b24: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176A60u;
    if (runtime->hasFunction(0x176A60u)) {
        auto targetFn = runtime->lookupFunction(0x176A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176B28u; }
        if (ctx->pc != 0x176B28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176A60_0x176a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176B28u; }
        if (ctx->pc != 0x176B28u) { return; }
    }
    ctx->pc = 0x176B28u;
label_176b28:
    // 0x176b28: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x176b28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x176b2c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x176b2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176b30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176b30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176b34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176b34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176b38: 0x3e00008  jr          $ra
    ctx->pc = 0x176B38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176B38u;
            // 0x176b3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176B28u: goto label_176b28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176B40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
