#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A928
// Address: 0x12a928 - 0x12a968
void sub_0012A928_0x12a928(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A928_0x12a928");
#endif

    ctx->pc = 0x12a928u;

    // 0x12a928: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a928u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a92c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x12A92Cu;
    {
        const bool branch_taken_0x12a92c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x12A930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A92Cu;
            // 0x12a930: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a92c) {
            ctx->pc = 0x12A948u;
            goto label_12a948;
        }
    }
    ctx->pc = 0x12A934u;
    // 0x12a934: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12a934u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12a938: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a938u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a93c: 0x2484a458  addiu       $a0, $a0, -0x5BA8
    ctx->pc = 0x12a93cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943832));
    // 0x12a940: 0x804a034  j           func_1280D0
    ctx->pc = 0x12A940u;
    ctx->pc = 0x12A944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A940u;
            // 0x12a944: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A948u;
label_12a948:
    // 0x12a948: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x12a948u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x12a94c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12A94Cu;
    {
        const bool branch_taken_0x12a94c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12A950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A94Cu;
            // 0x12a950: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a94c) {
            ctx->pc = 0x12A960u;
            goto label_12a960;
        }
    }
    ctx->pc = 0x12A954u;
    // 0x12a954: 0x8c840094  lw          $a0, 0x94($a0)
    ctx->pc = 0x12a954u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 148)));
    // 0x12a958: 0x804f3b4  j           func_13CED0
    ctx->pc = 0x12A958u;
    ctx->pc = 0x12A95Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A958u;
            // 0x12a95c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CED0u;
    if (runtime->hasFunction(0x13CED0u)) {
        auto targetFn = runtime->lookupFunction(0x13CED0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013CED0_0x13ced0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A960u;
label_12a960:
    // 0x12a960: 0x3e00008  jr          $ra
    ctx->pc = 0x12A960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A960u;
            // 0x12a964: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A948u: goto label_12a948;
            case 0x12A960u: goto label_12a960;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A968u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
