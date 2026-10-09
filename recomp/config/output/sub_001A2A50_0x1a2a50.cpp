#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2A50
// Address: 0x1a2a50 - 0x1a2ad0
void sub_001A2A50_0x1a2a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2A50_0x1a2a50");
#endif

    switch (ctx->pc) {
        case 0x1a2a78u: goto label_1a2a78;
        case 0x1a2a90u: goto label_1a2a90;
        default: break;
    }

    ctx->pc = 0x1a2a50u;

    // 0x1a2a50: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1a2a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1a2a54: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x1a2a54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x1a2a58: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1a2a58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1a2a5c: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1a2a5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1a2a60: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1a2a60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1a2a64: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a2a64u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2a68: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1a2a68u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1a2a6c: 0xc4341e90  lwc1        $f20, 0x1E90($at)
    ctx->pc = 0x1a2a6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7824)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1a2a70: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A2A70u;
    {
        const bool branch_taken_0x1a2a70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2A70u;
            // 0x1a2a74: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2a70) {
            ctx->pc = 0x1A2AA4u;
            goto label_1a2aa4;
        }
    }
    ctx->pc = 0x1A2A78u;
label_1a2a78:
    // 0x1a2a78: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1a2a78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1a2a7c: 0x8c23ffb0  lw          $v1, -0x50($at)
    ctx->pc = 0x1a2a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967216)));
    // 0x1a2a80: 0x1010c0  sll         $v0, $s0, 3
    ctx->pc = 0x1a2a80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1a2a84: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1a2a84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a2a88: 0xc06938c  jal         func_1A4E30
    ctx->pc = 0x1A2A88u;
    SET_GPR_U32(ctx, 31, 0x1A2A90u);
    ctx->pc = 0x1A2A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2A88u;
            // 0x1a2a8c: 0x622021  addu        $a0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A4E30u;
    if (runtime->hasFunction(0x1A4E30u)) {
        auto targetFn = runtime->lookupFunction(0x1A4E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2A90u; }
        if (ctx->pc != 0x1A2A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A4E30_0x1a4e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2A90u; }
        if (ctx->pc != 0x1A2A90u) { return; }
    }
    ctx->pc = 0x1A2A90u;
label_1a2a90:
    // 0x1a2a90: 0x46140034  c.lt.s      $f0, $f20
    ctx->pc = 0x1a2a90u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[20])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a2a94: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1A2A94u;
    {
        const bool branch_taken_0x1a2a94 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a2a94) {
            ctx->pc = 0x1A2AA0u;
            goto label_1a2aa0;
        }
    }
    ctx->pc = 0x1A2A9Cu;
    // 0x1a2a9c: 0x46000506  mov.s       $f20, $f0
    ctx->pc = 0x1a2a9cu;
    ctx->f[20] = FPU_MOV_S(ctx->f[0]);
label_1a2aa0:
    // 0x1a2aa0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a2aa0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1a2aa4:
    // 0x1a2aa4: 0x86220002  lh          $v0, 0x2($s1)
    ctx->pc = 0x1a2aa4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1a2aa8: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x1a2aa8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a2aac: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1A2AACu;
    {
        const bool branch_taken_0x1a2aac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2AACu;
            // 0x1a2ab0: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2aac) {
            ctx->pc = 0x1A2A78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2a78;
        }
    }
    ctx->pc = 0x1A2AB4u;
    // 0x1a2ab4: 0x4600a006  mov.s       $f0, $f20
    ctx->pc = 0x1a2ab4u;
    ctx->f[0] = FPU_MOV_S(ctx->f[20]);
    // 0x1a2ab8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1a2ab8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a2abc: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1a2abcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a2ac0: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1a2ac0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1a2ac4: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1a2ac4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a2ac8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2AC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2AC8u;
            // 0x1a2acc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2A78u: goto label_1a2a78;
            case 0x1A2A90u: goto label_1a2a90;
            case 0x1A2AA0u: goto label_1a2aa0;
            case 0x1A2AA4u: goto label_1a2aa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2AD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
