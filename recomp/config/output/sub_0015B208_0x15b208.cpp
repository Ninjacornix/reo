#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B208
// Address: 0x15b208 - 0x15b258
void sub_0015B208_0x15b208(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B208_0x15b208");
#endif

    switch (ctx->pc) {
        case 0x15b21cu: goto label_15b21c;
        case 0x15b238u: goto label_15b238;
        default: break;
    }

    ctx->pc = 0x15b208u;

    // 0x15b208: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15b208u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15b20c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15b20cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15b210: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15b210u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15b214: 0xc056c96  jal         func_15B258
    ctx->pc = 0x15B214u;
    SET_GPR_U32(ctx, 31, 0x15B21Cu);
    ctx->pc = 0x15B218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B214u;
            // 0x15b218: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B258u;
    if (runtime->hasFunction(0x15B258u)) {
        auto targetFn = runtime->lookupFunction(0x15B258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B21Cu; }
        if (ctx->pc != 0x15B21Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B258_0x15b258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B21Cu; }
        if (ctx->pc != 0x15B21Cu) { return; }
    }
    ctx->pc = 0x15B21Cu;
label_15b21c:
    // 0x15b21c: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x15b21cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x15b220: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15b220u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b224: 0x24a5d8e8  addiu       $a1, $a1, -0x2718
    ctx->pc = 0x15b224u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294957288));
    // 0x15b228: 0x12000006  beqz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15B228u;
    {
        const bool branch_taken_0x15b228 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x15B22Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B228u;
            // 0x15b22c: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b228) {
            ctx->pc = 0x15B244u;
            goto label_15b244;
        }
    }
    ctx->pc = 0x15B230u;
    // 0x15b230: 0xc05583c  jal         func_1560F0
    ctx->pc = 0x15B230u;
    SET_GPR_U32(ctx, 31, 0x15B238u);
    ctx->pc = 0x1560F0u;
    if (runtime->hasFunction(0x1560F0u)) {
        auto targetFn = runtime->lookupFunction(0x1560F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B238u; }
        if (ctx->pc != 0x15B238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001560F0_0x1560f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B238u; }
        if (ctx->pc != 0x15B238u) { return; }
    }
    ctx->pc = 0x15B238u;
label_15b238:
    // 0x15b238: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15b238u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15b23c: 0x26020180  addiu       $v0, $s0, 0x180
    ctx->pc = 0x15b23cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 384));
    // 0x15b240: 0xac62d8dc  sw          $v0, -0x2724($v1)
    ctx->pc = 0x15b240u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294957276), GPR_U32(ctx, 2));
label_15b244:
    // 0x15b244: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15b244u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b248: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15b248u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b24c: 0x3e00008  jr          $ra
    ctx->pc = 0x15B24Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B24Cu;
            // 0x15b250: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B21Cu: goto label_15b21c;
            case 0x15B238u: goto label_15b238;
            case 0x15B244u: goto label_15b244;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B254u;
    // 0x15b254: 0x0  nop
    ctx->pc = 0x15b254u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
