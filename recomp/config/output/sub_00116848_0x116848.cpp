#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116848
// Address: 0x116848 - 0x1168d8
void sub_00116848_0x116848(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116848_0x116848");
#endif

    switch (ctx->pc) {
        case 0x116890u: goto label_116890;
        default: break;
    }

    ctx->pc = 0x116848u;

    // 0x116848: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x116848u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x11684c: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x11684cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x116850: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x116850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x116854: 0x24425f30  addiu       $v0, $v0, 0x5F30
    ctx->pc = 0x116854u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24368));
    // 0x116858: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x116858u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x11685c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11685cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x116860: 0x8e119d44  lw          $s1, -0x62BC($s0)
    ctx->pc = 0x116860u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942020)));
    // 0x116864: 0xffa50078  sd          $a1, 0x78($sp)
    ctx->pc = 0x116864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 5));
    // 0x116868: 0xae029d44  sw          $v0, -0x62BC($s0)
    ctx->pc = 0x116868u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294942020), GPR_U32(ctx, 2));
    // 0x11686c: 0x27a50078  addiu       $a1, $sp, 0x78
    ctx->pc = 0x11686cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 120));
    // 0x116870: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x116870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x116874: 0xffa60080  sd          $a2, 0x80($sp)
    ctx->pc = 0x116874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 6));
    // 0x116878: 0xffa70088  sd          $a3, 0x88($sp)
    ctx->pc = 0x116878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 7));
    // 0x11687c: 0xffa80090  sd          $t0, 0x90($sp)
    ctx->pc = 0x11687cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 8));
    // 0x116880: 0xffa90098  sd          $t1, 0x98($sp)
    ctx->pc = 0x116880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 9));
    // 0x116884: 0xffaa00a0  sd          $t2, 0xA0($sp)
    ctx->pc = 0x116884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 10));
    // 0x116888: 0xc045886  jal         func_116218
    ctx->pc = 0x116888u;
    SET_GPR_U32(ctx, 31, 0x116890u);
    ctx->pc = 0x11688Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116888u;
            // 0x11688c: 0xffab00a8  sd          $t3, 0xA8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116218u;
    if (runtime->hasFunction(0x116218u)) {
        auto targetFn = runtime->lookupFunction(0x116218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116890u; }
        if (ctx->pc != 0x116890u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116218_0x116218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116890u; }
        if (ctx->pc != 0x116890u) { return; }
    }
    ctx->pc = 0x116890u;
label_116890:
    // 0x116890: 0xae119d44  sw          $s1, -0x62BC($s0)
    ctx->pc = 0x116890u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294942020), GPR_U32(ctx, 17));
    // 0x116894: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x116894u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x116898: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x116898u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11689c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11689cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1168a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1168A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1168A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1168A0u;
            // 0x1168a4: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116890u: goto label_116890;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1168A8u;
    // 0x1168a8: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x1168a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1168ac: 0x8ca6001c  lw          $a2, 0x1C($a1)
    ctx->pc = 0x1168acu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x1168b0: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1168b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1168b4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1168b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1168b8: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1168b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1168bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1168BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1168C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1168BCu;
            // 0x1168c0: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116890u: goto label_116890;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1168C4u;
    // 0x1168c4: 0x0  nop
    ctx->pc = 0x1168c4u;
    // NOP
    // 0x1168c8: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x1168c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1168cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1168CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1168D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1168CCu;
            // 0x1168d0: 0xaca20008  sw          $v0, 0x8($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116890u: goto label_116890;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1168D4u;
    // 0x1168d4: 0x0  nop
    ctx->pc = 0x1168d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
