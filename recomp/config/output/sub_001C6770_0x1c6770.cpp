#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6770
// Address: 0x1c6770 - 0x1c679c
void sub_001C6770_0x1c6770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6770_0x1c6770");
#endif

    switch (ctx->pc) {
        case 0x1c6780u: goto label_1c6780;
        default: break;
    }

    ctx->pc = 0x1c6770u;

    // 0x1c6770: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6770u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6774: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6774u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6778: 0xc072210  jal         func_1C8840
    ctx->pc = 0x1C6778u;
    SET_GPR_U32(ctx, 31, 0x1C6780u);
    ctx->pc = 0x1C677Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6778u;
            // 0x1c677c: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8840u;
    if (runtime->hasFunction(0x1C8840u)) {
        auto targetFn = runtime->lookupFunction(0x1C8840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6780u; }
        if (ctx->pc != 0x1C6780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8840_0x1c8840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6780u; }
        if (ctx->pc != 0x1C6780u) { return; }
    }
    ctx->pc = 0x1C6780u;
label_1c6780:
    // 0x1c6780: 0x3c02447a  lui         $v0, 0x447A
    ctx->pc = 0x1c6780u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17530 << 16));
    // 0x1c6784: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6784u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6788: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1c6788u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1c678c: 0x0  nop
    ctx->pc = 0x1c678cu;
    // NOP
    // 0x1c6790: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1c6790u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1c6794: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6794u;
            // 0x1c6798: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6780u: goto label_1c6780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C679Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
