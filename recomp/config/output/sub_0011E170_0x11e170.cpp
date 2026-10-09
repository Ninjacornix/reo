#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011E170
// Address: 0x11e170 - 0x11e19c
void sub_0011E170_0x11e170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011E170_0x11e170");
#endif

    ctx->pc = 0x11e170u;

    // 0x11e170: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11e170u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11e174: 0x8c43b3f0  lw          $v1, -0x4C10($v0)
    ctx->pc = 0x11e174u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294947824)));
    // 0x11e178: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E178u;
    {
        const bool branch_taken_0x11e178 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11E17Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E178u;
            // 0x11e17c: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e178) {
            ctx->pc = 0x11E18Cu;
            goto label_11e18c;
        }
    }
    ctx->pc = 0x11E180u;
    // 0x11e180: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e180u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e184: 0x3e00008  jr          $ra
    ctx->pc = 0x11E184u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E184u;
            // 0x11e188: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E18Cu: goto label_11e18c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E18Cu;
label_11e18c:
    // 0x11e18c: 0x34631010  ori         $v1, $v1, 0x1010
    ctx->pc = 0x11e18cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4112);
    // 0x11e190: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x11e190u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x11e194: 0x3e00008  jr          $ra
    ctx->pc = 0x11E194u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E194u;
            // 0x11e198: 0x30420003  andi        $v0, $v0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E18Cu: goto label_11e18c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E19Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
