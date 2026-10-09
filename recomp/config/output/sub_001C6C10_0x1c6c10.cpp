#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6C10
// Address: 0x1c6c10 - 0x1c6c54
void sub_001C6C10_0x1c6c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6C10_0x1c6c10");
#endif

    switch (ctx->pc) {
        case 0x1c6c3cu: goto label_1c6c3c;
        default: break;
    }

    ctx->pc = 0x1c6c10u;

    // 0x1c6c10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6c10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6c14: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6c14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6c18: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6c1c: 0xc4215074  lwc1        $f1, 0x5074($at)
    ctx->pc = 0x1c6c1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20596)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c6c20: 0x3c010025  lui         $at, 0x25
    ctx->pc = 0x1c6c20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)37 << 16));
    // 0x1c6c24: 0xc4202d70  lwc1        $f0, 0x2D70($at)
    ctx->pc = 0x1c6c24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 11632)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c6c28: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1c6c28u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1c6c2c: 0x45010006  bc1t        . + 4 + (0x6 << 2)
    ctx->pc = 0x1C6C2Cu;
    {
        const bool branch_taken_0x1c6c2c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1c6c2c) {
            ctx->pc = 0x1C6C48u;
            goto label_1c6c48;
        }
    }
    ctx->pc = 0x1C6C34u;
    // 0x1c6c34: 0xc071b9c  jal         func_1C6E70
    ctx->pc = 0x1C6C34u;
    SET_GPR_U32(ctx, 31, 0x1C6C3Cu);
    ctx->pc = 0x1C6E70u;
    if (runtime->hasFunction(0x1C6E70u)) {
        auto targetFn = runtime->lookupFunction(0x1C6E70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6C3Cu; }
        if (ctx->pc != 0x1C6C3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C6E70_0x1c6e70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6C3Cu; }
        if (ctx->pc != 0x1C6C3Cu) { return; }
    }
    ctx->pc = 0x1C6C3Cu;
label_1c6c3c:
    // 0x1c6c3c: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C6C3Cu;
    {
        const bool branch_taken_0x1c6c3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6C3Cu;
            // 0x1c6c40: 0x3c010033  lui         $at, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6c3c) {
            ctx->pc = 0x1C6C48u;
            goto label_1c6c48;
        }
    }
    ctx->pc = 0x1C6C44u;
    // 0x1c6c44: 0xac205074  sw          $zero, 0x5074($at)
    ctx->pc = 0x1c6c44u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20596), GPR_U32(ctx, 0));
label_1c6c48:
    // 0x1c6c48: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6c48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6c4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6C4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6C50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6C4Cu;
            // 0x1c6c50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6C3Cu: goto label_1c6c3c;
            case 0x1C6C48u: goto label_1c6c48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6C54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
