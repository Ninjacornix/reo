#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016F658
// Address: 0x16f658 - 0x16f6a0
void sub_0016F658_0x16f658(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016F658_0x16f658");
#endif

    switch (ctx->pc) {
        case 0x16f680u: goto label_16f680;
        default: break;
    }

    ctx->pc = 0x16f658u;

    // 0x16f658: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16f658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16f65c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16f65cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16f660: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x16f660u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f664: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16f664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16f668: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16f668u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f66c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x16f66cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16f670: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x16f670u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x16f674: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x16f674u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16f678: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x16F678u;
    SET_GPR_U32(ctx, 31, 0x16F680u);
    ctx->pc = 0x16F67Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F678u;
            // 0x16f67c: 0x8e060004  lw          $a2, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F680u; }
        if (ctx->pc != 0x16F680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F680u; }
        if (ctx->pc != 0x16F680u) { return; }
    }
    ctx->pc = 0x16F680u;
label_16f680:
    // 0x16f680: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x16f680u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x16f684: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16f684u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16f688: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x16f688u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x16f68c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16f68cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16f690: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16f690u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16f694: 0x3e00008  jr          $ra
    ctx->pc = 0x16F694u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16F698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F694u;
            // 0x16f698: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F680u: goto label_16f680;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16F69Cu;
    // 0x16f69c: 0x0  nop
    ctx->pc = 0x16f69cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
