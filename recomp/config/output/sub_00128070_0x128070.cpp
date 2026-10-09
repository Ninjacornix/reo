#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128070
// Address: 0x128070 - 0x1280d0
void sub_00128070_0x128070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128070_0x128070");
#endif

    switch (ctx->pc) {
        case 0x12808cu: goto label_12808c;
        default: break;
    }

    ctx->pc = 0x128070u;

    // 0x128070: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x128070u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x128074: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128074u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128078: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128078u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12807c: 0x2484c7b8  addiu       $a0, $a0, -0x3848
    ctx->pc = 0x12807cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952888));
    // 0x128080: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x128080u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x128084: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x128084u;
    SET_GPR_U32(ctx, 31, 0x12808Cu);
    ctx->pc = 0x128088u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128084u;
            // 0x128088: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12808Cu; }
        if (ctx->pc != 0x12808Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12808Cu; }
        if (ctx->pc != 0x12808Cu) { return; }
    }
    ctx->pc = 0x12808Cu;
label_12808c:
    // 0x12808c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12808cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128090: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x128090u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128094: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x128094u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128098: 0xac60c7b0  sw          $zero, -0x3850($v1)
    ctx->pc = 0x128098u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294952880), GPR_U32(ctx, 0));
    // 0x12809c: 0xac40c7b4  sw          $zero, -0x384C($v0)
    ctx->pc = 0x12809cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294952884), GPR_U32(ctx, 0));
    // 0x1280a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1280A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1280A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1280A0u;
            // 0x1280a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12808Cu: goto label_12808c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1280A8u;
    // 0x1280a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1280a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1280ac: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1280acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1280b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1280b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1280b4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x1280b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x1280b8: 0xac44c7b0  sw          $a0, -0x3850($v0)
    ctx->pc = 0x1280b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294952880), GPR_U32(ctx, 4));
    // 0x1280bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1280bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1280c0: 0x0  nop
    ctx->pc = 0x1280c0u;
    // NOP
    // 0x1280c4: 0x805076c  j           func_141DB0
    ctx->pc = 0x1280C4u;
    ctx->pc = 0x1280C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1280C4u;
            // 0x1280c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141DB0u;
    if (runtime->hasFunction(0x141DB0u)) {
        auto targetFn = runtime->lookupFunction(0x141DB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141DB0_0x141db0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1280CCu;
    // 0x1280cc: 0x0  nop
    ctx->pc = 0x1280ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
