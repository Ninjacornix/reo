#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160388
// Address: 0x160388 - 0x1603b4
void sub_00160388_0x160388(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160388_0x160388");
#endif

    switch (ctx->pc) {
        case 0x16039cu: goto label_16039c;
        default: break;
    }

    ctx->pc = 0x160388u;

    // 0x160388: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x160388u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16038c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16038cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x160390: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x160390u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160394: 0xc05cf8e  jal         func_173E38
    ctx->pc = 0x160394u;
    SET_GPR_U32(ctx, 31, 0x16039Cu);
    ctx->pc = 0x160398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160394u;
            // 0x160398: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173E38u;
    if (runtime->hasFunction(0x173E38u)) {
        auto targetFn = runtime->lookupFunction(0x173E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16039Cu; }
        if (ctx->pc != 0x16039Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173E38_0x173e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16039Cu; }
        if (ctx->pc != 0x16039Cu) { return; }
    }
    ctx->pc = 0x16039Cu;
label_16039c:
    // 0x16039c: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x16039cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1603a0: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x1603a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1603a4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1603a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1603a8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1603a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1603ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1603ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1603B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1603ACu;
            // 0x1603b0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16039Cu: goto label_16039c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1603B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
