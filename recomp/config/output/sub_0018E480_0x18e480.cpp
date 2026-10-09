#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018E480
// Address: 0x18e480 - 0x18e500
void sub_0018E480_0x18e480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018E480_0x18e480");
#endif

    switch (ctx->pc) {
        case 0x18e4b0u: goto label_18e4b0;
        case 0x18e4e8u: goto label_18e4e8;
        default: break;
    }

    ctx->pc = 0x18e480u;

    // 0x18e480: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x18e480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x18e484: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x18e484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x18e488: 0x27a60038  addiu       $a2, $sp, 0x38
    ctx->pc = 0x18e488u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x18e48c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x18e48cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x18e490: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x18e490u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x18e494: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18e494u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e498: 0xafa0003c  sw          $zero, 0x3C($sp)
    ctx->pc = 0x18e498u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 0));
    // 0x18e49c: 0x46006506  mov.s       $f20, $f12
    ctx->pc = 0x18e49cu;
    ctx->f[20] = FPU_MOV_S(ctx->f[12]);
    // 0x18e4a0: 0xafa00038  sw          $zero, 0x38($sp)
    ctx->pc = 0x18e4a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
    // 0x18e4a4: 0x86070000  lh          $a3, 0x0($s0)
    ctx->pc = 0x18e4a4u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18e4a8: 0xc063a44  jal         func_18E910
    ctx->pc = 0x18E4A8u;
    SET_GPR_U32(ctx, 31, 0x18E4B0u);
    ctx->pc = 0x18E4ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E4A8u;
            // 0x18e4ac: 0x27a5003c  addiu       $a1, $sp, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18E910u;
    if (runtime->hasFunction(0x18E910u)) {
        auto targetFn = runtime->lookupFunction(0x18E910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E4B0u; }
        if (ctx->pc != 0x18E4B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E910_0x18e910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E4B0u; }
        if (ctx->pc != 0x18E4B0u) { return; }
    }
    ctx->pc = 0x18E4B0u;
label_18e4b0:
    // 0x18e4b0: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x18e4b0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x18e4b4: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x18e4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x18e4b8: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x18E4B8u;
    {
        const bool branch_taken_0x18e4b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e4b8) {
            ctx->pc = 0x18E4CCu;
            goto label_18e4cc;
        }
    }
    ctx->pc = 0x18E4C0u;
    // 0x18e4c0: 0x8fa2003c  lw          $v0, 0x3C($sp)
    ctx->pc = 0x18e4c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x18e4c4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x18E4C4u;
    {
        const bool branch_taken_0x18e4c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E4C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E4C4u;
            // 0x18e4c8: 0xc4400000  lwc1        $f0, 0x0($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e4c4) {
            ctx->pc = 0x18E4E8u;
            goto label_18e4e8;
        }
    }
    ctx->pc = 0x18E4CCu;
label_18e4cc:
    // 0x18e4cc: 0x8fa2003c  lw          $v0, 0x3C($sp)
    ctx->pc = 0x18e4ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x18e4d0: 0xc46f0000  lwc1        $f15, 0x0($v1)
    ctx->pc = 0x18e4d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[15] = f; }
    // 0x18e4d4: 0xc4700004  lwc1        $f16, 0x4($v1)
    ctx->pc = 0x18e4d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[16] = f; }
    // 0x18e4d8: 0xc44d0000  lwc1        $f13, 0x0($v0)
    ctx->pc = 0x18e4d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
    // 0x18e4dc: 0xc44e0004  lwc1        $f14, 0x4($v0)
    ctx->pc = 0x18e4dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[14] = f; }
    // 0x18e4e0: 0xc063c78  jal         func_18F1E0
    ctx->pc = 0x18E4E0u;
    SET_GPR_U32(ctx, 31, 0x18E4E8u);
    ctx->pc = 0x18E4E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E4E0u;
            // 0x18e4e4: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F1E0u;
    if (runtime->hasFunction(0x18F1E0u)) {
        auto targetFn = runtime->lookupFunction(0x18F1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E4E8u; }
        if (ctx->pc != 0x18E4E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F1E0_0x18f1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E4E8u; }
        if (ctx->pc != 0x18E4E8u) { return; }
    }
    ctx->pc = 0x18E4E8u;
label_18e4e8:
    // 0x18e4e8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x18e4e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18e4ec: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x18e4ecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x18e4f0: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x18e4f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18e4f4: 0x3e00008  jr          $ra
    ctx->pc = 0x18E4F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18E4F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E4F4u;
            // 0x18e4f8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18E4B0u: goto label_18e4b0;
            case 0x18E4CCu: goto label_18e4cc;
            case 0x18E4E8u: goto label_18e4e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18E4FCu;
    // 0x18e4fc: 0x0  nop
    ctx->pc = 0x18e4fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
