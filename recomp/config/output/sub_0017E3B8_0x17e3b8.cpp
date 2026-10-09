#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E3B8
// Address: 0x17e3b8 - 0x17e404
void sub_0017E3B8_0x17e3b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E3B8_0x17e3b8");
#endif

    switch (ctx->pc) {
        case 0x17e3dcu: goto label_17e3dc;
        default: break;
    }

    ctx->pc = 0x17e3b8u;

    // 0x17e3b8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17e3b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17e3bc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17e3bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17e3c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17e3c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17e3c4: 0x2450f978  addiu       $s0, $v0, -0x688
    ctx->pc = 0x17e3c4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965624));
    // 0x17e3c8: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x17e3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17e3cc: 0x1c600009  bgtz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x17E3CCu;
    {
        const bool branch_taken_0x17e3cc = (GPR_S64(ctx, 3) > 0);
        ctx->pc = 0x17E3D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E3CCu;
            // 0x17e3d0: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e3cc) {
            ctx->pc = 0x17E3F4u;
            goto label_17e3f4;
        }
    }
    ctx->pc = 0x17E3D4u;
    // 0x17e3d4: 0xc05f902  jal         func_17E408
    ctx->pc = 0x17E3D4u;
    SET_GPR_U32(ctx, 31, 0x17E3DCu);
    ctx->pc = 0x17E408u;
    if (runtime->hasFunction(0x17E408u)) {
        auto targetFn = runtime->lookupFunction(0x17E408u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E3DCu; }
        if (ctx->pc != 0x17E3DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E408_0x17e408(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E3DCu; }
        if (ctx->pc != 0x17E3DCu) { return; }
    }
    ctx->pc = 0x17E3DCu;
label_17e3dc:
    // 0x17e3dc: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x17e3dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x17e3e0: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x17e3e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17e3e4: 0x24636150  addiu       $v1, $v1, 0x6150
    ctx->pc = 0x17e3e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 24912));
    // 0x17e3e8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x17e3e8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x17e3ec: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x17e3ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x17e3f0: 0xae040000  sw          $a0, 0x0($s0)
    ctx->pc = 0x17e3f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
label_17e3f4:
    // 0x17e3f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17e3f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e3f8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17e3f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17e3fc: 0x3e00008  jr          $ra
    ctx->pc = 0x17E3FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E3FCu;
            // 0x17e400: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E3DCu: goto label_17e3dc;
            case 0x17E3F4u: goto label_17e3f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E404u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
