#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017CEF0
// Address: 0x17cef0 - 0x17cf48
void sub_0017CEF0_0x17cef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017CEF0_0x17cef0");
#endif

    switch (ctx->pc) {
        case 0x17cf14u: goto label_17cf14;
        case 0x17cf1cu: goto label_17cf1c;
        case 0x17cf24u: goto label_17cf24;
        case 0x17cf2cu: goto label_17cf2c;
        default: break;
    }

    ctx->pc = 0x17cef0u;

    // 0x17cef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17cef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17cef4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17cef4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17cef8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17cef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17cefc: 0x2450f298  addiu       $s0, $v0, -0xD68
    ctx->pc = 0x17cefcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963864));
    // 0x17cf00: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x17cf00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17cf04: 0x1860000c  blez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x17CF04u;
    {
        const bool branch_taken_0x17cf04 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x17CF08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CF04u;
            // 0x17cf08: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cf04) {
            ctx->pc = 0x17CF38u;
            goto label_17cf38;
        }
    }
    ctx->pc = 0x17CF0Cu;
    // 0x17cf0c: 0xc05f5d0  jal         func_17D740
    ctx->pc = 0x17CF0Cu;
    SET_GPR_U32(ctx, 31, 0x17CF14u);
    ctx->pc = 0x17D740u;
    if (runtime->hasFunction(0x17D740u)) {
        auto targetFn = runtime->lookupFunction(0x17D740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF14u; }
        if (ctx->pc != 0x17CF14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D740_0x17d740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF14u; }
        if (ctx->pc != 0x17CF14u) { return; }
    }
    ctx->pc = 0x17CF14u;
label_17cf14:
    // 0x17cf14: 0xc05e99e  jal         func_17A678
    ctx->pc = 0x17CF14u;
    SET_GPR_U32(ctx, 31, 0x17CF1Cu);
    ctx->pc = 0x17A678u;
    if (runtime->hasFunction(0x17A678u)) {
        auto targetFn = runtime->lookupFunction(0x17A678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF1Cu; }
        if (ctx->pc != 0x17CF1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A678_0x17a678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF1Cu; }
        if (ctx->pc != 0x17CF1Cu) { return; }
    }
    ctx->pc = 0x17CF1Cu;
label_17cf1c:
    // 0x17cf1c: 0xc05f594  jal         func_17D650
    ctx->pc = 0x17CF1Cu;
    SET_GPR_U32(ctx, 31, 0x17CF24u);
    ctx->pc = 0x17D650u;
    if (runtime->hasFunction(0x17D650u)) {
        auto targetFn = runtime->lookupFunction(0x17D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF24u; }
        if (ctx->pc != 0x17CF24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D650_0x17d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF24u; }
        if (ctx->pc != 0x17CF24u) { return; }
    }
    ctx->pc = 0x17CF24u;
label_17cf24:
    // 0x17cf24: 0xc052480  jal         func_149200
    ctx->pc = 0x17CF24u;
    SET_GPR_U32(ctx, 31, 0x17CF2Cu);
    ctx->pc = 0x149200u;
    if (runtime->hasFunction(0x149200u)) {
        auto targetFn = runtime->lookupFunction(0x149200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF2Cu; }
        if (ctx->pc != 0x17CF2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149200_0x149200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF2Cu; }
        if (ctx->pc != 0x17CF2Cu) { return; }
    }
    ctx->pc = 0x17CF2Cu;
label_17cf2c:
    // 0x17cf2c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x17cf2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17cf30: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x17cf30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x17cf34: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x17cf34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_17cf38:
    // 0x17cf38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17cf38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cf3c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17cf3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cf40: 0x3e00008  jr          $ra
    ctx->pc = 0x17CF40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CF44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CF40u;
            // 0x17cf44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CF14u: goto label_17cf14;
            case 0x17CF1Cu: goto label_17cf1c;
            case 0x17CF24u: goto label_17cf24;
            case 0x17CF2Cu: goto label_17cf2c;
            case 0x17CF38u: goto label_17cf38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CF48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
