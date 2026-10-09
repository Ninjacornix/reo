#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163FD8
// Address: 0x163fd8 - 0x164008
void sub_00163FD8_0x163fd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163FD8_0x163fd8");
#endif

    switch (ctx->pc) {
        case 0x163fe8u: goto label_163fe8;
        case 0x163ffcu: goto label_163ffc;
        default: break;
    }

    ctx->pc = 0x163fd8u;

    // 0x163fd8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163fd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163fdc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163fe0: 0xc05799e  jal         func_15E678
    ctx->pc = 0x163FE0u;
    SET_GPR_U32(ctx, 31, 0x163FE8u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163FE8u; }
        if (ctx->pc != 0x163FE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163FE8u; }
        if (ctx->pc != 0x163FE8u) { return; }
    }
    ctx->pc = 0x163FE8u;
label_163fe8:
    // 0x163fe8: 0x8c430040  lw          $v1, 0x40($v0)
    ctx->pc = 0x163fe8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x163fec: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x163FECu;
    {
        const bool branch_taken_0x163fec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x163FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163FECu;
            // 0x163ff0: 0x8c440044  lw          $a0, 0x44($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163fec) {
            ctx->pc = 0x163FFCu;
            goto label_163ffc;
        }
    }
    ctx->pc = 0x163FF4u;
    // 0x163ff4: 0x60f809  jalr        $v1
    ctx->pc = 0x163FF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x163FFCu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x163FFCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163FE8u: goto label_163fe8;
            case 0x163FFCu: goto label_163ffc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x163FFCu; }
            if (ctx->pc != 0x163FFCu) { return; }
        }
        }
    }
    ctx->pc = 0x163FFCu;
label_163ffc:
    // 0x163ffc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x163ffcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164000: 0x3e00008  jr          $ra
    ctx->pc = 0x164000u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164000u;
            // 0x164004: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163FE8u: goto label_163fe8;
            case 0x163FFCu: goto label_163ffc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164008u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
