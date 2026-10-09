#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001415E0
// Address: 0x1415e0 - 0x141640
void sub_001415E0_0x1415e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001415E0_0x1415e0");
#endif

    switch (ctx->pc) {
        case 0x141608u: goto label_141608;
        default: break;
    }

    ctx->pc = 0x1415e0u;

    // 0x1415e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1415e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1415e4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1415e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1415e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1415e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1415ec: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1415ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1415f0: 0x244249e0  addiu       $v0, $v0, 0x49E0
    ctx->pc = 0x1415f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18912));
    // 0x1415f4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1415f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1415f8: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1415F8u;
    {
        const bool branch_taken_0x1415f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1415FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1415F8u;
            // 0x1415fc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1415f8) {
            ctx->pc = 0x141630u;
            goto label_141630;
        }
    }
    ctx->pc = 0x141600u;
    // 0x141600: 0x60f809  jalr        $v1
    ctx->pc = 0x141600u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x141608u);
        ctx->pc = 0x141604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141600u;
            // 0x141604: 0x8c440004  lw          $a0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141608u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141608u: goto label_141608;
            case 0x141624u: goto label_141624;
            case 0x141630u: goto label_141630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141608u; }
            if (ctx->pc != 0x141608u) { return; }
        }
        }
    }
    ctx->pc = 0x141608u;
label_141608:
    // 0x141608: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141608u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x14160c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x14160cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x141610: 0x2444a5f4  addiu       $a0, $v0, -0x5A0C
    ctx->pc = 0x141610u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944244));
    // 0x141614: 0x2463a5f0  addiu       $v1, $v1, -0x5A10
    ctx->pc = 0x141614u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944240));
    // 0x141618: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x141618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14161c: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x14161Cu;
    {
        const bool branch_taken_0x14161c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x14161c) {
            ctx->pc = 0x141620u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14161Cu;
            // 0x141620: 0xac900000  sw          $s0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141624u;
            goto label_141624;
        }
    }
    ctx->pc = 0x141624u;
label_141624:
    // 0x141624: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x141624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x141628: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x141628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x14162c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x14162cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_141630:
    // 0x141630: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141630u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141634: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x141634u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141638: 0x3e00008  jr          $ra
    ctx->pc = 0x141638u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14163Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141638u;
            // 0x14163c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141608u: goto label_141608;
            case 0x141624u: goto label_141624;
            case 0x141630u: goto label_141630;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141640u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
