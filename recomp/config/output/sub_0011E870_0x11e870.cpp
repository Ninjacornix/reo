#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011E870
// Address: 0x11e870 - 0x11e8e0
void sub_0011E870_0x11e870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011E870_0x11e870");
#endif

    ctx->pc = 0x11e870u;

    // 0x11e870: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11e870u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11e874: 0x2447b3e8  addiu       $a3, $v0, -0x4C18
    ctx->pc = 0x11e874u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947816));
    // 0x11e878: 0x8ce60014  lw          $a2, 0x14($a3)
    ctx->pc = 0x11e878u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x11e87c: 0x14c00004  bnez        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E87Cu;
    {
        const bool branch_taken_0x11e87c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x11e87c) {
            ctx->pc = 0x11E890u;
            goto label_11e890;
        }
    }
    ctx->pc = 0x11E884u;
    // 0x11e884: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e884u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e888: 0x3e00008  jr          $ra
    ctx->pc = 0x11E888u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E88Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E888u;
            // 0x11e88c: 0x34428005  ori         $v0, $v0, 0x8005 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32773);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E890u: goto label_11e890;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E890u;
label_11e890:
    // 0x11e890: 0x8ce20010  lw          $v0, 0x10($a3)
    ctx->pc = 0x11e890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x11e894: 0x62900  sll         $a1, $a2, 4
    ctx->pc = 0x11e894u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x11e898: 0x8cc40000  lw          $a0, 0x0($a2)
    ctx->pc = 0x11e898u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x11e89c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x11e89cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11e8a0: 0xacc00028  sw          $zero, 0x28($a2)
    ctx->pc = 0x11e8a0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 0));
    // 0x11e8a4: 0xace20010  sw          $v0, 0x10($a3)
    ctx->pc = 0x11e8a4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 16), GPR_U32(ctx, 2));
    // 0x11e8a8: 0xacc0000c  sw          $zero, 0xC($a2)
    ctx->pc = 0x11e8a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 0));
    // 0x11e8ac: 0xace40014  sw          $a0, 0x14($a3)
    ctx->pc = 0x11e8acu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 20), GPR_U32(ctx, 4));
    // 0x11e8b0: 0x8ce3000c  lw          $v1, 0xC($a3)
    ctx->pc = 0x11e8b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x11e8b4: 0xfcc00018  sd          $zero, 0x18($a2)
    ctx->pc = 0x11e8b4u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 24), GPR_U64(ctx, 0));
    // 0x11e8b8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x11e8b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x11e8bc: 0xace3000c  sw          $v1, 0xC($a3)
    ctx->pc = 0x11e8bcu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 12), GPR_U32(ctx, 3));
    // 0x11e8c0: 0x8ce2000c  lw          $v0, 0xC($a3)
    ctx->pc = 0x11e8c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x11e8c4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x11e8c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x11e8c8: 0x304203fe  andi        $v0, $v0, 0x3FE
    ctx->pc = 0x11e8c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1022);
    // 0x11e8cc: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x11e8ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x11e8d0: 0xacc20008  sw          $v0, 0x8($a2)
    ctx->pc = 0x11e8d0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 2));
    // 0x11e8d4: 0x8cc20008  lw          $v0, 0x8($a2)
    ctx->pc = 0x11e8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x11e8d8: 0x3e00008  jr          $ra
    ctx->pc = 0x11E8D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E8DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E8D8u;
            // 0x11e8dc: 0xa21025  or          $v0, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E890u: goto label_11e890;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E8E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
