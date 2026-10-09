#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115770
// Address: 0x115770 - 0x1157e0
void sub_00115770_0x115770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115770_0x115770");
#endif

    switch (ctx->pc) {
        case 0x1157a8u: goto label_1157a8;
        case 0x1157d0u: goto label_1157d0;
        default: break;
    }

    ctx->pc = 0x115770u;

    // 0x115770: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x115770u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x115774: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115774u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x115778: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x115778u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x11577c: 0x2442aa40  addiu       $v0, $v0, -0x55C0
    ctx->pc = 0x11577cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294945344));
    // 0x115780: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x115780u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x115784: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x115784u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x115788: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x115788u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x11578c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x11578cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x115790: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x115790u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115794: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x115794u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x115798: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x115798u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11579c: 0xafa60008  sw          $a2, 0x8($sp)
    ctx->pc = 0x11579cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x1157a0: 0xc045294  jal         func_114A50
    ctx->pc = 0x1157A0u;
    SET_GPR_U32(ctx, 31, 0x1157A8u);
    ctx->pc = 0x1157A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1157A0u;
            // 0x1157a4: 0xafa2000c  sw          $v0, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1157A8u; }
        if (ctx->pc != 0x1157A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1157A8u; }
        if (ctx->pc != 0x1157A8u) { return; }
    }
    ctx->pc = 0x1157A8u;
label_1157a8:
    // 0x1157a8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1157a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1157ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1157ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1157B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1157ACu;
            // 0x1157b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1157A8u: goto label_1157a8;
            case 0x1157D0u: goto label_1157d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1157B4u;
    // 0x1157b4: 0x0  nop
    ctx->pc = 0x1157b4u;
    // NOP
    // 0x1157b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1157b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1157bc: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x1157bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x1157c0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1157c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1157c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1157c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1157c8: 0xc045294  jal         func_114A50
    ctx->pc = 0x1157C8u;
    SET_GPR_U32(ctx, 31, 0x1157D0u);
    ctx->pc = 0x1157CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1157C8u;
            // 0x1157cc: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1157D0u; }
        if (ctx->pc != 0x1157D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1157D0u; }
        if (ctx->pc != 0x1157D0u) { return; }
    }
    ctx->pc = 0x1157D0u;
label_1157d0:
    // 0x1157d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1157d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1157d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1157D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1157D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1157D4u;
            // 0x1157d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1157A8u: goto label_1157a8;
            case 0x1157D0u: goto label_1157d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1157DCu;
    // 0x1157dc: 0x0  nop
    ctx->pc = 0x1157dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
