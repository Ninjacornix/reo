#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167E38
// Address: 0x167e38 - 0x167e80
void sub_00167E38_0x167e38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167E38_0x167e38");
#endif

    switch (ctx->pc) {
        case 0x167e50u: goto label_167e50;
        case 0x167e64u: goto label_167e64;
        default: break;
    }

    ctx->pc = 0x167e38u;

    // 0x167e38: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x167e38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x167e3c: 0x24050031  addiu       $a1, $zero, 0x31
    ctx->pc = 0x167e3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
    // 0x167e40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x167e40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x167e44: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x167e44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x167e48: 0xc05d58a  jal         func_175628
    ctx->pc = 0x167E48u;
    SET_GPR_U32(ctx, 31, 0x167E50u);
    ctx->pc = 0x167E4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167E48u;
            // 0x167e4c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167E50u; }
        if (ctx->pc != 0x167E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167E50u; }
        if (ctx->pc != 0x167E50u) { return; }
    }
    ctx->pc = 0x167E50u;
label_167e50:
    // 0x167e50: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x167e50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167e54: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x167E54u;
    {
        const bool branch_taken_0x167e54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x167E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167E54u;
            // 0x167e58: 0x24050039  addiu       $a1, $zero, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167e54) {
            ctx->pc = 0x167E6Cu;
            goto label_167e6c;
        }
    }
    ctx->pc = 0x167E5Cu;
    // 0x167e5c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x167E5Cu;
    SET_GPR_U32(ctx, 31, 0x167E64u);
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167E64u; }
        if (ctx->pc != 0x167E64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167E64u; }
        if (ctx->pc != 0x167E64u) { return; }
    }
    ctx->pc = 0x167E64u;
label_167e64:
    // 0x167e64: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x167E64u;
    {
        const bool branch_taken_0x167e64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x167E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167E64u;
            // 0x167e68: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167e64) {
            ctx->pc = 0x167E74u;
            goto label_167e74;
        }
    }
    ctx->pc = 0x167E6Cu;
label_167e6c:
    // 0x167e6c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x167e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x167e70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x167e70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_167e74:
    // 0x167e74: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x167e74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x167e78: 0x3e00008  jr          $ra
    ctx->pc = 0x167E78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167E78u;
            // 0x167e7c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167E50u: goto label_167e50;
            case 0x167E64u: goto label_167e64;
            case 0x167E6Cu: goto label_167e6c;
            case 0x167E74u: goto label_167e74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167E80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
