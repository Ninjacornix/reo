#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001395F8
// Address: 0x1395f8 - 0x139628
void sub_001395F8_0x1395f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001395F8_0x1395f8");
#endif

    switch (ctx->pc) {
        case 0x13961cu: goto label_13961c;
        default: break;
    }

    ctx->pc = 0x1395f8u;

    // 0x1395f8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1395f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1395fc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1395fcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x139600: 0x8c43cbe4  lw          $v1, -0x341C($v0)
    ctx->pc = 0x139600u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294953956)));
    // 0x139604: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x139604u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139608: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x139608u;
    {
        const bool branch_taken_0x139608 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13960Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139608u;
            // 0x13960c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139608) {
            ctx->pc = 0x13961Cu;
            goto label_13961c;
        }
    }
    ctx->pc = 0x139610u;
    // 0x139610: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x139610u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x139614: 0x60f809  jalr        $v1
    ctx->pc = 0x139614u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x13961Cu);
        ctx->pc = 0x139618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139614u;
            // 0x139618: 0x8c44cbe8  lw          $a0, -0x3418($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294953960)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13961Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13961Cu: goto label_13961c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13961Cu; }
            if (ctx->pc != 0x13961Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13961Cu;
label_13961c:
    // 0x13961c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13961cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x139620: 0x3e00008  jr          $ra
    ctx->pc = 0x139620u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139620u;
            // 0x139624: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13961Cu: goto label_13961c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139628u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
