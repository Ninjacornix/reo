#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A4E8
// Address: 0x17a4e8 - 0x17a558
void sub_0017A4E8_0x17a4e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A4E8_0x17a4e8");
#endif

    ctx->pc = 0x17a4e8u;

    // 0x17a4e8: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x17a4e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x17a4ec: 0x2c820008  sltiu       $v0, $a0, 0x8
    ctx->pc = 0x17a4ecu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x17a4f0: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x17A4F0u;
    {
        const bool branch_taken_0x17a4f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17a4f0) {
            ctx->pc = 0x17A550u;
            goto label_17a550;
        }
    }
    ctx->pc = 0x17A4F8u;
    // 0x17a4f8: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x17a4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x17a4fc: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x17a4fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x17a500: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x17a500u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17a504: 0x8c630e10  lw          $v1, 0xE10($v1)
    ctx->pc = 0x17a504u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 3600)));
    // 0x17a508: 0x600008  jr          $v1
    ctx->pc = 0x17A508u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A510u;
label_17a510:
    // 0x17a510: 0x3e00008  jr          $ra
    ctx->pc = 0x17A510u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A510u;
            // 0x17a514: 0x24025da8  addiu       $v0, $zero, 0x5DA8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 23976));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            case 0x17A550u: goto label_17a550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A518u;
label_17a518:
    // 0x17a518: 0x3e00008  jr          $ra
    ctx->pc = 0x17A518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A51Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A518u;
            // 0x17a51c: 0x24025dc0  addiu       $v0, $zero, 0x5DC0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24000));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            case 0x17A550u: goto label_17a550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A520u;
label_17a520:
    // 0x17a520: 0x3e00008  jr          $ra
    ctx->pc = 0x17A520u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A520u;
            // 0x17a524: 0x240261a8  addiu       $v0, $zero, 0x61A8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 25000));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            case 0x17A550u: goto label_17a550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A528u;
label_17a528:
    // 0x17a528: 0x3e00008  jr          $ra
    ctx->pc = 0x17A528u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A528u;
            // 0x17a52c: 0x24027512  addiu       $v0, $zero, 0x7512 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29970));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            case 0x17A550u: goto label_17a550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A530u;
label_17a530:
    // 0x17a530: 0x3e00008  jr          $ra
    ctx->pc = 0x17A530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A530u;
            // 0x17a534: 0x24027530  addiu       $v0, $zero, 0x7530 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 30000));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            case 0x17A550u: goto label_17a550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A538u;
label_17a538:
    // 0x17a538: 0x3e00008  jr          $ra
    ctx->pc = 0x17A538u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A53Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A538u;
            // 0x17a53c: 0x3402c350  ori         $v0, $zero, 0xC350 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)50000);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            case 0x17A550u: goto label_17a550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A540u;
label_17a540:
    // 0x17a540: 0x3e00008  jr          $ra
    ctx->pc = 0x17A540u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A540u;
            // 0x17a544: 0x3402ea24  ori         $v0, $zero, 0xEA24 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)59940);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            case 0x17A550u: goto label_17a550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A548u;
label_17a548:
    // 0x17a548: 0x3e00008  jr          $ra
    ctx->pc = 0x17A548u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A54Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A548u;
            // 0x17a54c: 0x3402ea60  ori         $v0, $zero, 0xEA60 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)60000);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            case 0x17A550u: goto label_17a550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A550u;
label_17a550:
    // 0x17a550: 0x3e00008  jr          $ra
    ctx->pc = 0x17A550u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A550u;
            // 0x17a554: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A510u: goto label_17a510;
            case 0x17A518u: goto label_17a518;
            case 0x17A520u: goto label_17a520;
            case 0x17A528u: goto label_17a528;
            case 0x17A530u: goto label_17a530;
            case 0x17A538u: goto label_17a538;
            case 0x17A540u: goto label_17a540;
            case 0x17A548u: goto label_17a548;
            case 0x17A550u: goto label_17a550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A558u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
