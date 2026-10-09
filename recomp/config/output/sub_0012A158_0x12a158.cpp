#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A158
// Address: 0x12a158 - 0x12a1a8
void sub_0012A158_0x12a158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A158_0x12a158");
#endif

    switch (ctx->pc) {
        case 0x12a168u: goto label_12a168;
        case 0x12a188u: goto label_12a188;
        case 0x12a190u: goto label_12a190;
        case 0x12a198u: goto label_12a198;
        default: break;
    }

    ctx->pc = 0x12a158u;

label_12a158:
    // 0x12a158: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a15c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a15cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a160: 0xc04f410  jal         func_13D040
    ctx->pc = 0x12A160u;
    SET_GPR_U32(ctx, 31, 0x12A168u);
    ctx->pc = 0x13D040u;
    if (runtime->hasFunction(0x13D040u)) {
        auto targetFn = runtime->lookupFunction(0x13D040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A168u; }
        if (ctx->pc != 0x12A168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D040_0x13d040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A168u; }
        if (ctx->pc != 0x12A168u) { return; }
    }
    ctx->pc = 0x12A168u;
label_12a168:
    // 0x12a168: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a168u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a16c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12a16cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a170: 0x3e00008  jr          $ra
    ctx->pc = 0x12A170u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A170u;
            // 0x12a174: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A158u: goto label_12a158;
            case 0x12A168u: goto label_12a168;
            case 0x12A188u: goto label_12a188;
            case 0x12A190u: goto label_12a190;
            case 0x12A198u: goto label_12a198;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A178u;
    // 0x12a178: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a178u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a17c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a17cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a180: 0xc04a86a  jal         func_12A1A8
    ctx->pc = 0x12A180u;
    SET_GPR_U32(ctx, 31, 0x12A188u);
    ctx->pc = 0x12A184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A180u;
            // 0x12a184: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A1A8u;
    if (runtime->hasFunction(0x12A1A8u)) {
        auto targetFn = runtime->lookupFunction(0x12A1A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A188u; }
        if (ctx->pc != 0x12A188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A1A8_0x12a1a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A188u; }
        if (ctx->pc != 0x12A188u) { return; }
    }
    ctx->pc = 0x12A188u;
label_12a188:
    // 0x12a188: 0xc04a872  jal         func_12A1C8
    ctx->pc = 0x12A188u;
    SET_GPR_U32(ctx, 31, 0x12A190u);
    ctx->pc = 0x12A18Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A188u;
            // 0x12a18c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A1C8u;
    if (runtime->hasFunction(0x12A1C8u)) {
        auto targetFn = runtime->lookupFunction(0x12A1C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A190u; }
        if (ctx->pc != 0x12A190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A1C8_0x12a1c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A190u; }
        if (ctx->pc != 0x12A190u) { return; }
    }
    ctx->pc = 0x12A190u;
label_12a190:
    // 0x12a190: 0xc04a856  jal         func_12A158
    ctx->pc = 0x12A190u;
    SET_GPR_U32(ctx, 31, 0x12A198u);
    ctx->pc = 0x12A194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A190u;
            // 0x12a194: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A158u;
    goto label_12a158;
    ctx->pc = 0x12A198u;
label_12a198:
    // 0x12a198: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12a198u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a19c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a19cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a1a0: 0x3e00008  jr          $ra
    ctx->pc = 0x12A1A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A1A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A1A0u;
            // 0x12a1a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A158u: goto label_12a158;
            case 0x12A168u: goto label_12a168;
            case 0x12A188u: goto label_12a188;
            case 0x12A190u: goto label_12a190;
            case 0x12A198u: goto label_12a198;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A1A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
