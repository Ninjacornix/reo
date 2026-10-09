#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129408
// Address: 0x129408 - 0x129468
void sub_00129408_0x129408(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129408_0x129408");
#endif

    switch (ctx->pc) {
        case 0x129430u: goto label_129430;
        case 0x129444u: goto label_129444;
        default: break;
    }

    ctx->pc = 0x129408u;

    // 0x129408: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x129408u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12940c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12940cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x129410: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x129410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x129414: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129414u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129418: 0x2450c8c0  addiu       $s0, $v0, -0x3740
    ctx->pc = 0x129418u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953152));
    // 0x12941c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12941cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x129420: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x129420u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x129424: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x129424u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x129428: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x129428u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12942c: 0x0  nop
    ctx->pc = 0x12942cu;
    // NOP
label_129430:
    // 0x129430: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x129430u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x129434: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x129434u;
    {
        const bool branch_taken_0x129434 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x129434) {
            ctx->pc = 0x129438u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129434u;
            // 0x129438: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129448u;
            goto label_129448;
        }
    }
    ctx->pc = 0x12943Cu;
    // 0x12943c: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x12943Cu;
    SET_GPR_U32(ctx, 31, 0x129444u);
    ctx->pc = 0x129440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12943Cu;
            // 0x129440: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129444u; }
        if (ctx->pc != 0x129444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129444u; }
        if (ctx->pc != 0x129444u) { return; }
    }
    ctx->pc = 0x129444u;
label_129444:
    // 0x129444: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x129444u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_129448:
    // 0x129448: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x129448u;
    {
        const bool branch_taken_0x129448 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x12944Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129448u;
            // 0x12944c: 0x26100044  addiu       $s0, $s0, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129448) {
            ctx->pc = 0x129430u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_129430;
        }
    }
    ctx->pc = 0x129450u;
    // 0x129450: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129450u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129454: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x129454u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129458: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x129458u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12945c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12945cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x129460: 0x3e00008  jr          $ra
    ctx->pc = 0x129460u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129460u;
            // 0x129464: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129430u: goto label_129430;
            case 0x129444u: goto label_129444;
            case 0x129448u: goto label_129448;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129468u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
