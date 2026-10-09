#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135228
// Address: 0x135228 - 0x1352ec
void sub_00135228_0x135228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135228_0x135228");
#endif

    switch (ctx->pc) {
        case 0x135260u: goto label_135260;
        case 0x135290u: goto label_135290;
        case 0x1352c4u: goto label_1352c4;
        default: break;
    }

    ctx->pc = 0x135228u;

    // 0x135228: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x135228u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13522c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13522cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x135230: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135230u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135234: 0x3c110022  lui         $s1, 0x22
    ctx->pc = 0x135234u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)34 << 16));
    // 0x135238: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13523c: 0x2442bb78  addiu       $v0, $v0, -0x4488
    ctx->pc = 0x13523cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949752));
    // 0x135240: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x135240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x135244: 0x8e23bb84  lw          $v1, -0x447C($s1)
    ctx->pc = 0x135244u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294949764)));
    // 0x135248: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x135248u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13524c: 0x1460001f  bnez        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x13524Cu;
    {
        const bool branch_taken_0x13524c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x135250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13524Cu;
            // 0x135250: 0x2623bb84  addiu       $v1, $s1, -0x447C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294949764));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13524c) {
            ctx->pc = 0x1352CCu;
            goto label_1352cc;
        }
    }
    ctx->pc = 0x135254u;
    // 0x135254: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x135254u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x135258: 0x24030027  addiu       $v1, $zero, 0x27
    ctx->pc = 0x135258u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x13525c: 0x24421f28  addiu       $v0, $v0, 0x1F28
    ctx->pc = 0x13525cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7976));
label_135260:
    // 0x135260: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x135260u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x135264: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x135264u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x135268: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x135268u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x13526c: 0x0  nop
    ctx->pc = 0x13526cu;
    // NOP
    // 0x135270: 0x0  nop
    ctx->pc = 0x135270u;
    // NOP
    // 0x135274: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x135274u;
    {
        const bool branch_taken_0x135274 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x135278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135274u;
            // 0x135278: 0x24420008  addiu       $v0, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135274) {
            ctx->pc = 0x135260u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135260;
        }
    }
    ctx->pc = 0x13527Cu;
    // 0x13527c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x13527cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x135280: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x135280u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x135284: 0x24422068  addiu       $v0, $v0, 0x2068
    ctx->pc = 0x135284u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8296));
    // 0x135288: 0x244201f4  addiu       $v0, $v0, 0x1F4
    ctx->pc = 0x135288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 500));
    // 0x13528c: 0x0  nop
    ctx->pc = 0x13528cu;
    // NOP
label_135290:
    // 0x135290: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x135290u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x135294: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x135294u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x135298: 0x0  nop
    ctx->pc = 0x135298u;
    // NOP
    // 0x13529c: 0x0  nop
    ctx->pc = 0x13529cu;
    // NOP
    // 0x1352a0: 0x0  nop
    ctx->pc = 0x1352a0u;
    // NOP
    // 0x1352a4: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1352A4u;
    {
        const bool branch_taken_0x1352a4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1352A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1352A4u;
            // 0x1352a8: 0x2442fff0  addiu       $v0, $v0, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1352a4) {
            ctx->pc = 0x135290u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135290;
        }
    }
    ctx->pc = 0x1352ACu;
    // 0x1352ac: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x1352acu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x1352b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1352b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1352b4: 0x26102268  addiu       $s0, $s0, 0x2268
    ctx->pc = 0x1352b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8808));
    // 0x1352b8: 0x24060009  addiu       $a2, $zero, 0x9
    ctx->pc = 0x1352b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1352bc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1352BCu;
    SET_GPR_U32(ctx, 31, 0x1352C4u);
    ctx->pc = 0x1352C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1352BCu;
            // 0x1352c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1352C4u; }
        if (ctx->pc != 0x1352C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1352C4u; }
        if (ctx->pc != 0x1352C4u) { return; }
    }
    ctx->pc = 0x1352C4u;
label_1352c4:
    // 0x1352c4: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1352c4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1352c8: 0x2623bb84  addiu       $v1, $s1, -0x447C
    ctx->pc = 0x1352c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294949764));
label_1352cc:
    // 0x1352cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1352ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1352d0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1352d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1352d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1352d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1352d8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1352d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1352dc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1352dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1352e0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1352e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1352e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1352E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1352E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1352E4u;
            // 0x1352e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135260u: goto label_135260;
            case 0x135290u: goto label_135290;
            case 0x1352C4u: goto label_1352c4;
            case 0x1352CCu: goto label_1352cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1352ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
