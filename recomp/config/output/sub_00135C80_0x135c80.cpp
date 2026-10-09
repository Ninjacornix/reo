#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135C80
// Address: 0x135c80 - 0x135cf8
void sub_00135C80_0x135c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135C80_0x135c80");
#endif

    switch (ctx->pc) {
        case 0x135cc8u: goto label_135cc8;
        default: break;
    }

    ctx->pc = 0x135c80u;

    // 0x135c80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x135c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x135c84: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135c88: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x135c88u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135c8c: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x135C8Cu;
    {
        const bool branch_taken_0x135c8c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x135C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135C8Cu;
            // 0x135c90: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135c8c) {
            ctx->pc = 0x135CB0u;
            goto label_135cb0;
        }
    }
    ctx->pc = 0x135C94u;
    // 0x135c94: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135c94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135c98: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135c98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135c9c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x135c9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135ca0: 0x2484b958  addiu       $a0, $a0, -0x46A8
    ctx->pc = 0x135ca0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949208));
    // 0x135ca4: 0x804d480  j           func_135200
    ctx->pc = 0x135CA4u;
    ctx->pc = 0x135CA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135CA4u;
            // 0x135ca8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135CACu;
    // 0x135cac: 0x0  nop
    ctx->pc = 0x135cacu;
    // NOP
label_135cb0:
    // 0x135cb0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x135cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x135cb4: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x135cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x135cb8: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x135CB8u;
    {
        const bool branch_taken_0x135cb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x135cb8) {
            ctx->pc = 0x135CBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135CB8u;
            // 0x135cbc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135CE0u;
            goto label_135ce0;
        }
    }
    ctx->pc = 0x135CC0u;
    // 0x135cc0: 0x40f809  jalr        $v0
    ctx->pc = 0x135CC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135CC8u);
        ctx->pc = 0x135CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135CC0u;
            // 0x135cc4: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x135CC8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135CB0u: goto label_135cb0;
            case 0x135CC8u: goto label_135cc8;
            case 0x135CE0u: goto label_135ce0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135CC8u; }
            if (ctx->pc != 0x135CC8u) { return; }
        }
        }
    }
    ctx->pc = 0x135CC8u;
label_135cc8:
    // 0x135cc8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x135cc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135ccc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x135cccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135cd0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135cd0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135cd4: 0x804d6b0  j           func_135AC0
    ctx->pc = 0x135CD4u;
    ctx->pc = 0x135CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135CD4u;
            // 0x135cd8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AC0u;
    if (runtime->hasFunction(0x135AC0u)) {
        auto targetFn = runtime->lookupFunction(0x135AC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135AC0_0x135ac0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135CDCu;
    // 0x135cdc: 0x0  nop
    ctx->pc = 0x135cdcu;
    // NOP
label_135ce0:
    // 0x135ce0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135ce0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135ce4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x135ce4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135ce8: 0x2484b978  addiu       $a0, $a0, -0x4688
    ctx->pc = 0x135ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949240));
    // 0x135cec: 0x804d480  j           func_135200
    ctx->pc = 0x135CECu;
    ctx->pc = 0x135CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135CECu;
            // 0x135cf0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135CF4u;
    // 0x135cf4: 0x0  nop
    ctx->pc = 0x135cf4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
