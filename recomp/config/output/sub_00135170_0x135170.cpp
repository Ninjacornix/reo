#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135170
// Address: 0x135170 - 0x1351d0
void sub_00135170_0x135170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135170_0x135170");
#endif

    switch (ctx->pc) {
        case 0x135198u: goto label_135198;
        case 0x1351acu: goto label_1351ac;
        default: break;
    }

    ctx->pc = 0x135170u;

    // 0x135170: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x135170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x135174: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x135174u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x135178: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x135178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13517c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13517cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135180: 0x2450b7b8  addiu       $s0, $v0, -0x4848
    ctx->pc = 0x135180u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294948792));
    // 0x135184: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135188: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x135188u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13518c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13518cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x135190: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x135190u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x135194: 0x0  nop
    ctx->pc = 0x135194u;
    // NOP
label_135198:
    // 0x135198: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x135198u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13519c: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13519Cu;
    {
        const bool branch_taken_0x13519c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x13519c) {
            ctx->pc = 0x1351A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13519Cu;
            // 0x1351a0: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1351B0u;
            goto label_1351b0;
        }
    }
    ctx->pc = 0x1351A4u;
    // 0x1351a4: 0xc04d41e  jal         func_135078
    ctx->pc = 0x1351A4u;
    SET_GPR_U32(ctx, 31, 0x1351ACu);
    ctx->pc = 0x1351A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1351A4u;
            // 0x1351a8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135078u;
    if (runtime->hasFunction(0x135078u)) {
        auto targetFn = runtime->lookupFunction(0x135078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1351ACu; }
        if (ctx->pc != 0x1351ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135078_0x135078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1351ACu; }
        if (ctx->pc != 0x1351ACu) { return; }
    }
    ctx->pc = 0x1351ACu;
label_1351ac:
    // 0x1351ac: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x1351acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_1351b0:
    // 0x1351b0: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1351B0u;
    {
        const bool branch_taken_0x1351b0 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1351B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351B0u;
            // 0x1351b4: 0x2610003c  addiu       $s0, $s0, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1351b0) {
            ctx->pc = 0x135198u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135198;
        }
    }
    ctx->pc = 0x1351B8u;
    // 0x1351b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1351b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1351bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1351bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1351c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1351c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1351c4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1351c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1351c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1351C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1351CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351C8u;
            // 0x1351cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135198u: goto label_135198;
            case 0x1351ACu: goto label_1351ac;
            case 0x1351B0u: goto label_1351b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1351D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
