#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169168
// Address: 0x169168 - 0x1691a8
void sub_00169168_0x169168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169168_0x169168");
#endif

    switch (ctx->pc) {
        case 0x16917cu: goto label_16917c;
        default: break;
    }

    ctx->pc = 0x169168u;

    // 0x169168: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169168u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16916c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16916cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x169170: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x169170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x169174: 0xc05a4b8  jal         func_1692E0
    ctx->pc = 0x169174u;
    SET_GPR_U32(ctx, 31, 0x16917Cu);
    ctx->pc = 0x169178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169174u;
            // 0x169178: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1692E0u;
    if (runtime->hasFunction(0x1692E0u)) {
        auto targetFn = runtime->lookupFunction(0x1692E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16917Cu; }
        if (ctx->pc != 0x16917Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001692E0_0x1692e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16917Cu; }
        if (ctx->pc != 0x16917Cu) { return; }
    }
    ctx->pc = 0x16917Cu;
label_16917c:
    // 0x16917c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x16917cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169180: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x169180u;
    {
        const bool branch_taken_0x169180 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x169184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169180u;
            // 0x169184: 0x26050078  addiu       $a1, $s0, 0x78 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 120));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169180) {
            ctx->pc = 0x169198u;
            goto label_169198;
        }
    }
    ctx->pc = 0x169188u;
    // 0x169188: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169188u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16918c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16918cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169190: 0x805a46a  j           func_1691A8
    ctx->pc = 0x169190u;
    ctx->pc = 0x169194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169190u;
            // 0x169194: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1691A8u;
    if (runtime->hasFunction(0x1691A8u)) {
        auto targetFn = runtime->lookupFunction(0x1691A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001691A8_0x1691a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x169198u;
label_169198:
    // 0x169198: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169198u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16919c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16919cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1691a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1691A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1691A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1691A0u;
            // 0x1691a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16917Cu: goto label_16917c;
            case 0x169198u: goto label_169198;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1691A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
