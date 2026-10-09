#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169918
// Address: 0x169918 - 0x169950
void sub_00169918_0x169918(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169918_0x169918");
#endif

    switch (ctx->pc) {
        case 0x169930u: goto label_169930;
        default: break;
    }

    ctx->pc = 0x169918u;

    // 0x169918: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x169918u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16991c: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x16991cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169920: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x169920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x169924: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x169924u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x169928: 0x40f809  jalr        $v0
    ctx->pc = 0x169928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x169930u);
        ctx->pc = 0x16992Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169928u;
            // 0x16992c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x169930u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169930u: goto label_169930;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x169930u; }
            if (ctx->pc != 0x169930u) { return; }
        }
        }
    }
    ctx->pc = 0x169930u;
label_169930:
    // 0x169930: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x169930u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x169934: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x169934u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169938: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x169938u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x16993c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16993cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x169940: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x169940u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
    // 0x169944: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x169944u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169948: 0x3e00008  jr          $ra
    ctx->pc = 0x169948u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16994Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169948u;
            // 0x16994c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169930u: goto label_169930;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169950u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
