#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130658
// Address: 0x130658 - 0x130698
void sub_00130658_0x130658(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130658_0x130658");
#endif

    switch (ctx->pc) {
        case 0x13066cu: goto label_13066c;
        case 0x130674u: goto label_130674;
        case 0x130684u: goto label_130684;
        default: break;
    }

    ctx->pc = 0x130658u;

    // 0x130658: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13065c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13065cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130660: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130660u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130664: 0xc049938  jal         func_1264E0
    ctx->pc = 0x130664u;
    SET_GPR_U32(ctx, 31, 0x13066Cu);
    ctx->pc = 0x130668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130664u;
            // 0x130668: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13066Cu; }
        if (ctx->pc != 0x13066Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13066Cu; }
        if (ctx->pc != 0x13066Cu) { return; }
    }
    ctx->pc = 0x13066Cu;
label_13066c:
    // 0x13066c: 0xc04c188  jal         func_130620
    ctx->pc = 0x13066Cu;
    SET_GPR_U32(ctx, 31, 0x130674u);
    ctx->pc = 0x130670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13066Cu;
            // 0x130670: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130620u;
    if (runtime->hasFunction(0x130620u)) {
        auto targetFn = runtime->lookupFunction(0x130620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130674u; }
        if (ctx->pc != 0x130674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130620_0x130620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130674u; }
        if (ctx->pc != 0x130674u) { return; }
    }
    ctx->pc = 0x130674u;
label_130674:
    // 0x130674: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x130674u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
    // 0x130678: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x130678u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x13067c: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x13067Cu;
    SET_GPR_U32(ctx, 31, 0x130684u);
    ctx->pc = 0x130680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13067Cu;
            // 0x130680: 0xae020058  sw          $v0, 0x58($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130684u; }
        if (ctx->pc != 0x130684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130684u; }
        if (ctx->pc != 0x130684u) { return; }
    }
    ctx->pc = 0x130684u;
label_130684:
    // 0x130684: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130688: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130688u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13068c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13068cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130690: 0x3e00008  jr          $ra
    ctx->pc = 0x130690u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130690u;
            // 0x130694: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13066Cu: goto label_13066c;
            case 0x130674u: goto label_130674;
            case 0x130684u: goto label_130684;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130698u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
