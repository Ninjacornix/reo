#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001700D0
// Address: 0x1700d0 - 0x170120
void sub_001700D0_0x1700d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001700D0_0x1700d0");
#endif

    switch (ctx->pc) {
        case 0x1700f0u: goto label_1700f0;
        case 0x1700fcu: goto label_1700fc;
        case 0x170108u: goto label_170108;
        default: break;
    }

    ctx->pc = 0x1700d0u;

    // 0x1700d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1700d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1700d4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1700d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1700d8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1700d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1700dc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1700dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1700e0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1700e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1700e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1700e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1700e8: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x1700E8u;
    SET_GPR_U32(ctx, 31, 0x1700F0u);
    ctx->pc = 0x1700ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1700E8u;
            // 0x1700ec: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1700F0u; }
        if (ctx->pc != 0x1700F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1700F0u; }
        if (ctx->pc != 0x1700F0u) { return; }
    }
    ctx->pc = 0x1700F0u;
label_1700f0:
    // 0x1700f0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1700f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1700f4: 0xc05c048  jal         func_170120
    ctx->pc = 0x1700F4u;
    SET_GPR_U32(ctx, 31, 0x1700FCu);
    ctx->pc = 0x1700F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1700F4u;
            // 0x1700f8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170120u;
    if (runtime->hasFunction(0x170120u)) {
        auto targetFn = runtime->lookupFunction(0x170120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1700FCu; }
        if (ctx->pc != 0x1700FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170120_0x170120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1700FCu; }
        if (ctx->pc != 0x1700FCu) { return; }
    }
    ctx->pc = 0x1700FCu;
label_1700fc:
    // 0x1700fc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1700fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170100: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x170100u;
    SET_GPR_U32(ctx, 31, 0x170108u);
    ctx->pc = 0x170104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170100u;
            // 0x170104: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170108u; }
        if (ctx->pc != 0x170108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170108u; }
        if (ctx->pc != 0x170108u) { return; }
    }
    ctx->pc = 0x170108u;
label_170108:
    // 0x170108: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x170108u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17010c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17010cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x170110: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x170110u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170114: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x170114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x170118: 0x3e00008  jr          $ra
    ctx->pc = 0x170118u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17011Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170118u;
            // 0x17011c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1700F0u: goto label_1700f0;
            case 0x1700FCu: goto label_1700fc;
            case 0x170108u: goto label_170108;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170120u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
