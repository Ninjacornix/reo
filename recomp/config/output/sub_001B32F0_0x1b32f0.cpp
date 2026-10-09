#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B32F0
// Address: 0x1b32f0 - 0x1b3398
void sub_001B32F0_0x1b32f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B32F0_0x1b32f0");
#endif

    ctx->pc = 0x1b32f0u;

    // 0x1b32f0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b32f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b32f4: 0x90860002  lbu         $a2, 0x2($a0)
    ctx->pc = 0x1b32f4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1b32f8: 0x9422a820  lhu         $v0, -0x57E0($at)
    ctx->pc = 0x1b32f8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944800)));
    // 0x1b32fc: 0x14c20010  bne         $a2, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B32FCu;
    {
        const bool branch_taken_0x1b32fc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b32fc) {
            ctx->pc = 0x1B3340u;
            goto label_1b3340;
        }
    }
    ctx->pc = 0x1B3304u;
    // 0x1b3304: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b3304u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b3308: 0x90820022  lbu         $v0, 0x22($a0)
    ctx->pc = 0x1b3308u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 34)));
    // 0x1b330c: 0x942343dc  lhu         $v1, 0x43DC($at)
    ctx->pc = 0x1b330cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b3310: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1b3310u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1b3314: 0x24a5a620  addiu       $a1, $a1, -0x59E0
    ctx->pc = 0x1b3314u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294944288));
    // 0x1b3318: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1b3318u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1b331c: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b331cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b3320: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1b3320u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1b3324: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1b3324u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1b3328: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1b3328u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b332c: 0x94630000  lhu         $v1, 0x0($v1)
    ctx->pc = 0x1b332cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b3330: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B3330u;
    {
        const bool branch_taken_0x1b3330 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b3330) {
            ctx->pc = 0x1B3340u;
            goto label_1b3340;
        }
    }
    ctx->pc = 0x1B3338u;
    // 0x1b3338: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1B3338u;
    {
        const bool branch_taken_0x1b3338 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B333Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3338u;
            // 0x1b333c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3338) {
            ctx->pc = 0x1B3390u;
            goto label_1b3390;
        }
    }
    ctx->pc = 0x1B3340u;
label_1b3340:
    // 0x1b3340: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3344: 0x9422a822  lhu         $v0, -0x57DE($at)
    ctx->pc = 0x1b3344u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944802)));
    // 0x1b3348: 0x14c20011  bne         $a2, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B3348u;
    {
        const bool branch_taken_0x1b3348 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B334Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3348u;
            // 0x1b334c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3348) {
            ctx->pc = 0x1B3390u;
            goto label_1b3390;
        }
    }
    ctx->pc = 0x1B3350u;
    // 0x1b3350: 0x90820022  lbu         $v0, 0x22($a0)
    ctx->pc = 0x1b3350u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 34)));
    // 0x1b3354: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b3354u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b3358: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1b3358u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1b335c: 0x2463a720  addiu       $v1, $v1, -0x58E0
    ctx->pc = 0x1b335cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944544));
    // 0x1b3360: 0x942443dc  lhu         $a0, 0x43DC($at)
    ctx->pc = 0x1b3360u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b3364: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1b3364u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1b3368: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1b3368u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b336c: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1b336cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b3370: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x1b3370u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b3374: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b3374u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b3378: 0x94630000  lhu         $v1, 0x0($v1)
    ctx->pc = 0x1b3378u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b337c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B337Cu;
    {
        const bool branch_taken_0x1b337c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B3380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B337Cu;
            // 0x1b3380: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b337c) {
            ctx->pc = 0x1B338Cu;
            goto label_1b338c;
        }
    }
    ctx->pc = 0x1B3384u;
    // 0x1b3384: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B3384u;
    {
        const bool branch_taken_0x1b3384 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3384) {
            ctx->pc = 0x1B3390u;
            goto label_1b3390;
        }
    }
    ctx->pc = 0x1B338Cu;
label_1b338c:
    // 0x1b338c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b338cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b3390:
    // 0x1b3390: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3390u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3340u: goto label_1b3340;
            case 0x1B338Cu: goto label_1b338c;
            case 0x1B3390u: goto label_1b3390;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B3398u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
