#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001888E0
// Address: 0x1888e0 - 0x188938
void sub_001888E0_0x1888e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001888E0_0x1888e0");
#endif

    switch (ctx->pc) {
        case 0x188920u: goto label_188920;
        default: break;
    }

    ctx->pc = 0x1888e0u;

    // 0x1888e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1888e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1888e4: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x1888e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x1888e8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1888e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1888ec: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x1888ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x1888f0: 0x3c100029  lui         $s0, 0x29
    ctx->pc = 0x1888f0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)41 << 16));
    // 0x1888f4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1888f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1888f8: 0x26070c00  addiu       $a3, $s0, 0xC00
    ctx->pc = 0x1888f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 3072));
    // 0x1888fc: 0x24840b88  addiu       $a0, $a0, 0xB88
    ctx->pc = 0x1888fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2952));
    // 0x188900: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x188900u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x188904: 0x34a51363  ori         $a1, $a1, 0x1363
    ctx->pc = 0x188904u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4963);
    // 0x188908: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x188908u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18890c: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x18890cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188910: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x188910u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188914: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x188914u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188918: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x188918u;
    SET_GPR_U32(ctx, 31, 0x188920u);
    ctx->pc = 0x18891Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188918u;
            // 0x18891c: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188920u; }
        if (ctx->pc != 0x188920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188920u; }
        if (ctx->pc != 0x188920u) { return; }
    }
    ctx->pc = 0x188920u;
label_188920:
    // 0x188920: 0x8e020c00  lw          $v0, 0xC00($s0)
    ctx->pc = 0x188920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3072)));
    // 0x188924: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x188924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188928: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x188928u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18892c: 0x3e00008  jr          $ra
    ctx->pc = 0x18892Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18892Cu;
            // 0x188930: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188920u: goto label_188920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188934u;
    // 0x188934: 0x0  nop
    ctx->pc = 0x188934u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
