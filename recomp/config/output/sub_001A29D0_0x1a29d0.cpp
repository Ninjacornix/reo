#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A29D0
// Address: 0x1a29d0 - 0x1a2a50
void sub_001A29D0_0x1a29d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A29D0_0x1a29d0");
#endif

    switch (ctx->pc) {
        case 0x1a29f4u: goto label_1a29f4;
        case 0x1a2a0cu: goto label_1a2a0c;
        default: break;
    }

    ctx->pc = 0x1a29d0u;

    // 0x1a29d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1a29d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1a29d4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1a29d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1a29d8: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1a29d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1a29dc: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1a29dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1a29e0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a29e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a29e4: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1a29e4u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1a29e8: 0x4480a000  mtc1        $zero, $f20
    ctx->pc = 0x1a29e8u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
    // 0x1a29ec: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A29ECu;
    {
        const bool branch_taken_0x1a29ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A29F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A29ECu;
            // 0x1a29f0: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a29ec) {
            ctx->pc = 0x1A2A20u;
            goto label_1a2a20;
        }
    }
    ctx->pc = 0x1A29F4u;
label_1a29f4:
    // 0x1a29f4: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1a29f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1a29f8: 0x8c23ffb0  lw          $v1, -0x50($at)
    ctx->pc = 0x1a29f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967216)));
    // 0x1a29fc: 0x1010c0  sll         $v0, $s0, 3
    ctx->pc = 0x1a29fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1a2a00: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1a2a00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a2a04: 0xc0693c4  jal         func_1A4F10
    ctx->pc = 0x1A2A04u;
    SET_GPR_U32(ctx, 31, 0x1A2A0Cu);
    ctx->pc = 0x1A2A08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2A04u;
            // 0x1a2a08: 0x622021  addu        $a0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A4F10u;
    if (runtime->hasFunction(0x1A4F10u)) {
        auto targetFn = runtime->lookupFunction(0x1A4F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2A0Cu; }
        if (ctx->pc != 0x1A2A0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A4F10_0x1a4f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2A0Cu; }
        if (ctx->pc != 0x1A2A0Cu) { return; }
    }
    ctx->pc = 0x1A2A0Cu;
label_1a2a0c:
    // 0x1a2a0c: 0x46140036  c.le.s      $f0, $f20
    ctx->pc = 0x1a2a0cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[20])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a2a10: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x1A2A10u;
    {
        const bool branch_taken_0x1a2a10 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a2a10) {
            ctx->pc = 0x1A2A1Cu;
            goto label_1a2a1c;
        }
    }
    ctx->pc = 0x1A2A18u;
    // 0x1a2a18: 0x46000506  mov.s       $f20, $f0
    ctx->pc = 0x1a2a18u;
    ctx->f[20] = FPU_MOV_S(ctx->f[0]);
label_1a2a1c:
    // 0x1a2a1c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a2a1cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1a2a20:
    // 0x1a2a20: 0x86220002  lh          $v0, 0x2($s1)
    ctx->pc = 0x1a2a20u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1a2a24: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x1a2a24u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a2a28: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1A2A28u;
    {
        const bool branch_taken_0x1a2a28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2A2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2A28u;
            // 0x1a2a2c: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2a28) {
            ctx->pc = 0x1A29F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a29f4;
        }
    }
    ctx->pc = 0x1A2A30u;
    // 0x1a2a30: 0x4600a006  mov.s       $f0, $f20
    ctx->pc = 0x1a2a30u;
    ctx->f[0] = FPU_MOV_S(ctx->f[20]);
    // 0x1a2a34: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1a2a34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a2a38: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1a2a38u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a2a3c: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1a2a3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1a2a40: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1a2a40u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a2a44: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2A44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2A44u;
            // 0x1a2a48: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A29F4u: goto label_1a29f4;
            case 0x1A2A0Cu: goto label_1a2a0c;
            case 0x1A2A1Cu: goto label_1a2a1c;
            case 0x1A2A20u: goto label_1a2a20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2A4Cu;
    // 0x1a2a4c: 0x0  nop
    ctx->pc = 0x1a2a4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
