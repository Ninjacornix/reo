#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017CE20
// Address: 0x17ce20 - 0x17ce90
void sub_0017CE20_0x17ce20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017CE20_0x17ce20");
#endif

    switch (ctx->pc) {
        case 0x17ce44u: goto label_17ce44;
        case 0x17ce54u: goto label_17ce54;
        case 0x17ce5cu: goto label_17ce5c;
        case 0x17ce64u: goto label_17ce64;
        case 0x17ce6cu: goto label_17ce6c;
        default: break;
    }

    ctx->pc = 0x17ce20u;

    // 0x17ce20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17ce20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17ce24: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17ce24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17ce28: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ce28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ce2c: 0x2450f298  addiu       $s0, $v0, -0xD68
    ctx->pc = 0x17ce2cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963864));
    // 0x17ce30: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x17ce30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ce34: 0x1c600012  bgtz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x17CE34u;
    {
        const bool branch_taken_0x17ce34 = (GPR_S64(ctx, 3) > 0);
        ctx->pc = 0x17CE38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CE34u;
            // 0x17ce38: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ce34) {
            ctx->pc = 0x17CE80u;
            goto label_17ce80;
        }
    }
    ctx->pc = 0x17CE3Cu;
    // 0x17ce3c: 0xc05f3a4  jal         func_17CE90
    ctx->pc = 0x17CE3Cu;
    SET_GPR_U32(ctx, 31, 0x17CE44u);
    ctx->pc = 0x17CE90u;
    if (runtime->hasFunction(0x17CE90u)) {
        auto targetFn = runtime->lookupFunction(0x17CE90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE44u; }
        if (ctx->pc != 0x17CE44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CE90_0x17ce90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE44u; }
        if (ctx->pc != 0x17CE44u) { return; }
    }
    ctx->pc = 0x17CE44u;
label_17ce44:
    // 0x17ce44: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x17ce44u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x17ce48: 0x24636148  addiu       $v1, $v1, 0x6148
    ctx->pc = 0x17ce48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 24904));
    // 0x17ce4c: 0xc05f3a8  jal         func_17CEA0
    ctx->pc = 0x17CE4Cu;
    SET_GPR_U32(ctx, 31, 0x17CE54u);
    ctx->pc = 0x17CE50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CE4Cu;
            // 0x17ce50: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CEA0u;
    if (runtime->hasFunction(0x17CEA0u)) {
        auto targetFn = runtime->lookupFunction(0x17CEA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE54u; }
        if (ctx->pc != 0x17CE54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CEA0_0x17cea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE54u; }
        if (ctx->pc != 0x17CE54u) { return; }
    }
    ctx->pc = 0x17CE54u;
label_17ce54:
    // 0x17ce54: 0xc05f58e  jal         func_17D638
    ctx->pc = 0x17CE54u;
    SET_GPR_U32(ctx, 31, 0x17CE5Cu);
    ctx->pc = 0x17D638u;
    if (runtime->hasFunction(0x17D638u)) {
        auto targetFn = runtime->lookupFunction(0x17D638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE5Cu; }
        if (ctx->pc != 0x17CE5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D638_0x17d638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE5Cu; }
        if (ctx->pc != 0x17CE5Cu) { return; }
    }
    ctx->pc = 0x17CE5Cu;
label_17ce5c:
    // 0x17ce5c: 0xc05f5ba  jal         func_17D6E8
    ctx->pc = 0x17CE5Cu;
    SET_GPR_U32(ctx, 31, 0x17CE64u);
    ctx->pc = 0x17D6E8u;
    if (runtime->hasFunction(0x17D6E8u)) {
        auto targetFn = runtime->lookupFunction(0x17D6E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE64u; }
        if (ctx->pc != 0x17CE64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D6E8_0x17d6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE64u; }
        if (ctx->pc != 0x17CE64u) { return; }
    }
    ctx->pc = 0x17CE64u;
label_17ce64:
    // 0x17ce64: 0xc05e988  jal         func_17A620
    ctx->pc = 0x17CE64u;
    SET_GPR_U32(ctx, 31, 0x17CE6Cu);
    ctx->pc = 0x17A620u;
    if (runtime->hasFunction(0x17A620u)) {
        auto targetFn = runtime->lookupFunction(0x17A620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE6Cu; }
        if (ctx->pc != 0x17CE6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A620_0x17a620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE6Cu; }
        if (ctx->pc != 0x17CE6Cu) { return; }
    }
    ctx->pc = 0x17CE6Cu;
label_17ce6c:
    // 0x17ce6c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x17ce6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ce70: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17ce70u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17ce74: 0xac60f29c  sw          $zero, -0xD64($v1)
    ctx->pc = 0x17ce74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963868), GPR_U32(ctx, 0));
    // 0x17ce78: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x17ce78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x17ce7c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x17ce7cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_17ce80:
    // 0x17ce80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ce80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ce84: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17ce84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ce88: 0x3e00008  jr          $ra
    ctx->pc = 0x17CE88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CE8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CE88u;
            // 0x17ce8c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CE44u: goto label_17ce44;
            case 0x17CE54u: goto label_17ce54;
            case 0x17CE5Cu: goto label_17ce5c;
            case 0x17CE64u: goto label_17ce64;
            case 0x17CE6Cu: goto label_17ce6c;
            case 0x17CE80u: goto label_17ce80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CE90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
