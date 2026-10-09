#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135E98
// Address: 0x135e98 - 0x135ef0
void sub_00135E98_0x135e98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135E98_0x135e98");
#endif

    switch (ctx->pc) {
        case 0x135ed0u: goto label_135ed0;
        default: break;
    }

    ctx->pc = 0x135e98u;

    // 0x135e98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x135e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x135e9c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x135E9Cu;
    {
        const bool branch_taken_0x135e9c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x135EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E9Cu;
            // 0x135ea0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135e9c) {
            ctx->pc = 0x135EB8u;
            goto label_135eb8;
        }
    }
    ctx->pc = 0x135EA4u;
    // 0x135ea4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135ea4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135ea8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x135ea8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135eac: 0x2484ba70  addiu       $a0, $a0, -0x4590
    ctx->pc = 0x135eacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949488));
    // 0x135eb0: 0x804d480  j           func_135200
    ctx->pc = 0x135EB0u;
    ctx->pc = 0x135EB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135EB0u;
            // 0x135eb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135EB8u;
label_135eb8:
    // 0x135eb8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x135eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x135ebc: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x135ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x135ec0: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x135EC0u;
    {
        const bool branch_taken_0x135ec0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x135ec0) {
            ctx->pc = 0x135EC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135EC0u;
            // 0x135ec4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135EE0u;
            goto label_135ee0;
        }
    }
    ctx->pc = 0x135EC8u;
    // 0x135ec8: 0x40f809  jalr        $v0
    ctx->pc = 0x135EC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135ED0u);
        ctx->pc = 0x135ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135EC8u;
            // 0x135ecc: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x135ED0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135EB8u: goto label_135eb8;
            case 0x135ED0u: goto label_135ed0;
            case 0x135EE0u: goto label_135ee0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135ED0u; }
            if (ctx->pc != 0x135ED0u) { return; }
        }
        }
    }
    ctx->pc = 0x135ED0u;
label_135ed0:
    // 0x135ed0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x135ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135ed4: 0x3e00008  jr          $ra
    ctx->pc = 0x135ED4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135ED4u;
            // 0x135ed8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135EB8u: goto label_135eb8;
            case 0x135ED0u: goto label_135ed0;
            case 0x135EE0u: goto label_135ee0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135EDCu;
    // 0x135edc: 0x0  nop
    ctx->pc = 0x135edcu;
    // NOP
label_135ee0:
    // 0x135ee0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x135ee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135ee4: 0x2484ba90  addiu       $a0, $a0, -0x4570
    ctx->pc = 0x135ee4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949520));
    // 0x135ee8: 0x804d480  j           func_135200
    ctx->pc = 0x135EE8u;
    ctx->pc = 0x135EECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135EE8u;
            // 0x135eec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
