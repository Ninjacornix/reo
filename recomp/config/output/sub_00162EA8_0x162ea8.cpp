#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162EA8
// Address: 0x162ea8 - 0x162ef0
void sub_00162EA8_0x162ea8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162EA8_0x162ea8");
#endif

    switch (ctx->pc) {
        case 0x162ebcu: goto label_162ebc;
        case 0x162ee0u: goto label_162ee0;
        default: break;
    }

    ctx->pc = 0x162ea8u;

    // 0x162ea8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162ea8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162eac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162eb0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x162eb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x162eb4: 0xc058d08  jal         func_163420
    ctx->pc = 0x162EB4u;
    SET_GPR_U32(ctx, 31, 0x162EBCu);
    ctx->pc = 0x162EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162EB4u;
            // 0x162eb8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162EBCu; }
        if (ctx->pc != 0x162EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162EBCu; }
        if (ctx->pc != 0x162EBCu) { return; }
    }
    ctx->pc = 0x162EBCu;
label_162ebc:
    // 0x162ebc: 0x52000009  beql        $s0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x162EBCu;
    {
        const bool branch_taken_0x162ebc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x162ebc) {
            ctx->pc = 0x162EC0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162EBCu;
            // 0x162ec0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162EE4u;
            goto label_162ee4;
        }
    }
    ctx->pc = 0x162EC4u;
    // 0x162ec4: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x162EC4u;
    {
        const bool branch_taken_0x162ec4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x162ec4) {
            ctx->pc = 0x162EC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162EC4u;
            // 0x162ec8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162EE4u;
            goto label_162ee4;
        }
    }
    ctx->pc = 0x162ECCu;
    // 0x162ecc: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x162eccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x162ed0: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x162ED0u;
    {
        const bool branch_taken_0x162ed0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x162ed0) {
            ctx->pc = 0x162ED4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162ED0u;
            // 0x162ed4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162EE4u;
            goto label_162ee4;
        }
    }
    ctx->pc = 0x162ED8u;
    // 0x162ed8: 0x40f809  jalr        $v0
    ctx->pc = 0x162ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x162EE0u);
        ctx->pc = 0x162EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162ED8u;
            // 0x162edc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x162EE0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162EBCu: goto label_162ebc;
            case 0x162EE0u: goto label_162ee0;
            case 0x162EE4u: goto label_162ee4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x162EE0u; }
            if (ctx->pc != 0x162EE0u) { return; }
        }
        }
    }
    ctx->pc = 0x162EE0u;
label_162ee0:
    // 0x162ee0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162ee0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_162ee4:
    // 0x162ee4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162ee4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162ee8: 0x3e00008  jr          $ra
    ctx->pc = 0x162EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162EE8u;
            // 0x162eec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162EBCu: goto label_162ebc;
            case 0x162EE0u: goto label_162ee0;
            case 0x162EE4u: goto label_162ee4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
