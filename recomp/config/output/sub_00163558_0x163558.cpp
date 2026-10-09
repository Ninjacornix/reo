#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163558
// Address: 0x163558 - 0x163598
void sub_00163558_0x163558(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163558_0x163558");
#endif

    switch (ctx->pc) {
        case 0x163580u: goto label_163580;
        default: break;
    }

    ctx->pc = 0x163558u;

    // 0x163558: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163558u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16355c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x16355cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163560: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163560u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163564: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163564u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163568: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x163568u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16356c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x16356cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163570: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x163570u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x163574: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x163574u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x163578: 0xc050716  jal         func_141C58
    ctx->pc = 0x163578u;
    SET_GPR_U32(ctx, 31, 0x163580u);
    ctx->pc = 0x16357Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163578u;
            // 0x16357c: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141C58u;
    if (runtime->hasFunction(0x141C58u)) {
        auto targetFn = runtime->lookupFunction(0x141C58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163580u; }
        if (ctx->pc != 0x163580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141C58_0x141c58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163580u; }
        if (ctx->pc != 0x163580u) { return; }
    }
    ctx->pc = 0x163580u;
label_163580:
    // 0x163580: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x163580u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x163584: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163584u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163588: 0xac500744  sw          $s0, 0x744($v0)
    ctx->pc = 0x163588u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1860), GPR_U32(ctx, 16));
    // 0x16358c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16358cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163590: 0x3e00008  jr          $ra
    ctx->pc = 0x163590u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163590u;
            // 0x163594: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163580u: goto label_163580;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163598u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
