#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176B40
// Address: 0x176b40 - 0x176b78
void sub_00176B40_0x176b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176B40_0x176b40");
#endif

    switch (ctx->pc) {
        case 0x176b60u: goto label_176b60;
        default: break;
    }

    ctx->pc = 0x176b40u;

    // 0x176b40: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176b40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176b44: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176b48: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x176b48u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176b4c: 0x3404ea60  ori         $a0, $zero, 0xEA60
    ctx->pc = 0x176b4cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)60000);
    // 0x176b50: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176b50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176b54: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x176b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x176b58: 0xc05da98  jal         func_176A60
    ctx->pc = 0x176B58u;
    SET_GPR_U32(ctx, 31, 0x176B60u);
    ctx->pc = 0x176B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176B58u;
            // 0x176b5c: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176A60u;
    if (runtime->hasFunction(0x176A60u)) {
        auto targetFn = runtime->lookupFunction(0x176A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176B60u; }
        if (ctx->pc != 0x176B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176A60_0x176a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176B60u; }
        if (ctx->pc != 0x176B60u) { return; }
    }
    ctx->pc = 0x176B60u;
label_176b60:
    // 0x176b60: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x176b60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x176b64: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x176b64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176b68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176b68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176b6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176b6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176b70: 0x3e00008  jr          $ra
    ctx->pc = 0x176B70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176B70u;
            // 0x176b74: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176B60u: goto label_176b60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176B78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
