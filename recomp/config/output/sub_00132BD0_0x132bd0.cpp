#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132BD0
// Address: 0x132bd0 - 0x132c08
void sub_00132BD0_0x132bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132BD0_0x132bd0");
#endif

    switch (ctx->pc) {
        case 0x132be8u: goto label_132be8;
        default: break;
    }

    ctx->pc = 0x132bd0u;

    // 0x132bd0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132bd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132bd4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132BD4u;
    {
        const bool branch_taken_0x132bd4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132BD4u;
            // 0x132bd8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132bd4) {
            ctx->pc = 0x132BF0u;
            goto label_132bf0;
        }
    }
    ctx->pc = 0x132BDCu;
    // 0x132bdc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132bdcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132be0: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132BE0u;
    SET_GPR_U32(ctx, 31, 0x132BE8u);
    ctx->pc = 0x132BE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132BE0u;
            // 0x132be4: 0x2484b330  addiu       $a0, $a0, -0x4CD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132BE8u; }
        if (ctx->pc != 0x132BE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132BE8u; }
        if (ctx->pc != 0x132BE8u) { return; }
    }
    ctx->pc = 0x132BE8u;
label_132be8:
    // 0x132be8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x132BE8u;
    {
        const bool branch_taken_0x132be8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132BE8u;
            // 0x132bec: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132be8) {
            ctx->pc = 0x132BFCu;
            goto label_132bfc;
        }
    }
    ctx->pc = 0x132BF0u;
label_132bf0:
    // 0x132bf0: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x132bf0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x132bf4: 0x38420005  xori        $v0, $v0, 0x5
    ctx->pc = 0x132bf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)5);
    // 0x132bf8: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x132bf8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_132bfc:
    // 0x132bfc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132bfcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132c00: 0x3e00008  jr          $ra
    ctx->pc = 0x132C00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132C00u;
            // 0x132c04: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132BE8u: goto label_132be8;
            case 0x132BF0u: goto label_132bf0;
            case 0x132BFCu: goto label_132bfc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132C08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
