#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140B98
// Address: 0x140b98 - 0x140bf0
void sub_00140B98_0x140b98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140B98_0x140b98");
#endif

    switch (ctx->pc) {
        case 0x140bd8u: goto label_140bd8;
        default: break;
    }

    ctx->pc = 0x140b98u;

    // 0x140b98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140b98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140b9c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140ba0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140ba0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140ba4: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140ba4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140ba8: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140bac: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x140bacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140bb0: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140bb0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140bb4: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140bb4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140bb8: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140bb8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140bbc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140bbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140bc0: 0xac460008  sw          $a2, 0x8($v0)
    ctx->pc = 0x140bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 6));
    // 0x140bc4: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x140bc4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x140bc8: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140bc8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140bcc: 0x24040022  addiu       $a0, $zero, 0x22
    ctx->pc = 0x140bccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x140bd0: 0xc04e518  jal         func_139460
    ctx->pc = 0x140BD0u;
    SET_GPR_U32(ctx, 31, 0x140BD8u);
    ctx->pc = 0x140BD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140BD0u;
            // 0x140bd4: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140BD8u; }
        if (ctx->pc != 0x140BD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140BD8u; }
        if (ctx->pc != 0x140BD8u) { return; }
    }
    ctx->pc = 0x140BD8u;
label_140bd8:
    // 0x140bd8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x140bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140bdc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140bdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140be0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140be0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140be4: 0x3e00008  jr          $ra
    ctx->pc = 0x140BE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140BE4u;
            // 0x140be8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140BD8u: goto label_140bd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140BECu;
    // 0x140bec: 0x0  nop
    ctx->pc = 0x140becu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
