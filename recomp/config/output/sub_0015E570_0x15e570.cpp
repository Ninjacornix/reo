#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E570
// Address: 0x15e570 - 0x15e5a0
void sub_0015E570_0x15e570(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E570_0x15e570");
#endif

    switch (ctx->pc) {
        case 0x15e580u: goto label_15e580;
        default: break;
    }

    ctx->pc = 0x15e570u;

    // 0x15e570: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15e570u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15e574: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15e574u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15e578: 0xc05e70c  jal         func_179C30
    ctx->pc = 0x15E578u;
    SET_GPR_U32(ctx, 31, 0x15E580u);
    ctx->pc = 0x15E57Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E578u;
            // 0x15e57c: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179C30u;
    if (runtime->hasFunction(0x179C30u)) {
        auto targetFn = runtime->lookupFunction(0x179C30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E580u; }
        if (ctx->pc != 0x15E580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179C30_0x179c30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E580u; }
        if (ctx->pc != 0x15E580u) { return; }
    }
    ctx->pc = 0x15E580u;
label_15e580:
    // 0x15e580: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x15e580u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15e584: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x15e584u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e588: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x15e588u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x15e58c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15e58cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e590: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x15e590u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
    // 0x15e594: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x15e594u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e598: 0x3e00008  jr          $ra
    ctx->pc = 0x15E598u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E59Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E598u;
            // 0x15e59c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E580u: goto label_15e580;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E5A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
