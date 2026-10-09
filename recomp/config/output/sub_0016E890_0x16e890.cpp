#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E890
// Address: 0x16e890 - 0x16e8e0
void sub_0016E890_0x16e890(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E890_0x16e890");
#endif

    switch (ctx->pc) {
        case 0x16e8d0u: goto label_16e8d0;
        default: break;
    }

    ctx->pc = 0x16e890u;

    // 0x16e890: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16e890u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16e894: 0x24852ab4  addiu       $a1, $a0, 0x2AB4
    ctx->pc = 0x16e894u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 10932));
    // 0x16e898: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16e898u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16e89c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16e89cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e8a0: 0x24830da4  addiu       $v1, $a0, 0xDA4
    ctx->pc = 0x16e8a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 3492));
    // 0x16e8a4: 0x8ca60004  lw          $a2, 0x4($a1)
    ctx->pc = 0x16e8a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x16e8a8: 0x4c0000a  bltz        $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x16E8A8u;
    {
        const bool branch_taken_0x16e8a8 = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x16E8ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E8A8u;
            // 0x16e8ac: 0x24880d54  addiu       $t0, $a0, 0xD54 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 3412));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e8a8) {
            ctx->pc = 0x16E8D4u;
            goto label_16e8d4;
        }
    }
    ctx->pc = 0x16E8B0u;
    // 0x16e8b0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x16e8b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x16e8b4: 0x54600008  bnel        $v1, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x16E8B4u;
    {
        const bool branch_taken_0x16e8b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x16e8b4) {
            ctx->pc = 0x16E8B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E8B4u;
            // 0x16e8b8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E8D8u;
            goto label_16e8d8;
        }
    }
    ctx->pc = 0x16E8BCu;
    // 0x16e8bc: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x16e8bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e8c0: 0x8d060020  lw          $a2, 0x20($t0)
    ctx->pc = 0x16e8c0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 32)));
    // 0x16e8c4: 0x8ca50008  lw          $a1, 0x8($a1)
    ctx->pc = 0x16e8c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x16e8c8: 0xc05407a  jal         func_1501E8
    ctx->pc = 0x16E8C8u;
    SET_GPR_U32(ctx, 31, 0x16E8D0u);
    ctx->pc = 0x16E8CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E8C8u;
            // 0x16e8cc: 0x8d070024  lw          $a3, 0x24($t0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1501E8u;
    if (runtime->hasFunction(0x1501E8u)) {
        auto targetFn = runtime->lookupFunction(0x1501E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E8D0u; }
        if (ctx->pc != 0x16E8D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001501E8_0x1501e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E8D0u; }
        if (ctx->pc != 0x16E8D0u) { return; }
    }
    ctx->pc = 0x16E8D0u;
label_16e8d0:
    // 0x16e8d0: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x16e8d0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_16e8d4:
    // 0x16e8d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16e8d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16e8d8:
    // 0x16e8d8: 0x3e00008  jr          $ra
    ctx->pc = 0x16E8D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E8DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E8D8u;
            // 0x16e8dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E8D0u: goto label_16e8d0;
            case 0x16E8D4u: goto label_16e8d4;
            case 0x16E8D8u: goto label_16e8d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E8E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
