#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018FCE0
// Address: 0x18fce0 - 0x18fdf0
void sub_0018FCE0_0x18fce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018FCE0_0x18fce0");
#endif

    switch (ctx->pc) {
        case 0x18fd14u: goto label_18fd14;
        default: break;
    }

    ctx->pc = 0x18fce0u;

    // 0x18fce0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x18fce0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x18fce4: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x18fce4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x18fce8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x18fce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x18fcec: 0x24844cc0  addiu       $a0, $a0, 0x4CC0
    ctx->pc = 0x18fcecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19648));
    // 0x18fcf0: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x18fcf0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x18fcf4: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x18fcf4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x18fcf8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x18fcf8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18fcfc: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x18fcfcu;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x18fd00: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x18fd00u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18fd04: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x18fd04u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x18fd08: 0x46006546  mov.s       $f21, $f12
    ctx->pc = 0x18fd08u;
    ctx->f[21] = FPU_MOV_S(ctx->f[12]);
    // 0x18fd0c: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x18FD0Cu;
    SET_GPR_U32(ctx, 31, 0x18FD14u);
    ctx->pc = 0x18FD10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18FD0Cu;
            // 0x18fd10: 0x46006d06  mov.s       $f20, $f13 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18FD14u; }
        if (ctx->pc != 0x18FD14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18FD14u; }
        if (ctx->pc != 0x18FD14u) { return; }
    }
    ctx->pc = 0x18FD14u;
label_18fd14:
    // 0x18fd14: 0x6210003  bgez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18FD14u;
    {
        const bool branch_taken_0x18fd14 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x18FD18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FD14u;
            // 0x18fd18: 0x111843  sra         $v1, $s1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18fd14) {
            ctx->pc = 0x18FD24u;
            goto label_18fd24;
        }
    }
    ctx->pc = 0x18FD1Cu;
    // 0x18fd1c: 0x26230001  addiu       $v1, $s1, 0x1
    ctx->pc = 0x18fd1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x18fd20: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x18fd20u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
label_18fd24:
    // 0x18fd24: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18fd24u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18fd28: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fd28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fd2c: 0x102043  sra         $a0, $s0, 1
    ctx->pc = 0x18fd2cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 16), 1));
    // 0x18fd30: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18fd30u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18fd34: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18FD34u;
    {
        const bool branch_taken_0x18fd34 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x18FD38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FD34u;
            // 0x18fd38: 0xe4204cc0  swc1        $f0, 0x4CC0($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19648), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18fd34) {
            ctx->pc = 0x18FD44u;
            goto label_18fd44;
        }
    }
    ctx->pc = 0x18FD3Cu;
    // 0x18fd3c: 0x26030001  addiu       $v1, $s0, 0x1
    ctx->pc = 0x18fd3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x18fd40: 0x32043  sra         $a0, $v1, 1
    ctx->pc = 0x18fd40u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 1));
label_18fd44:
    // 0x18fd44: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x18fd44u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x18fd48: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fd48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fd4c: 0xac234cfc  sw          $v1, 0x4CFC($at)
    ctx->pc = 0x18fd4cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 19708), GPR_U32(ctx, 3));
    // 0x18fd50: 0x4615a001  sub.s       $f0, $f20, $f21
    ctx->pc = 0x18fd50u;
    ctx->f[0] = FPU_SUB_S(ctx->f[20], ctx->f[21]);
    // 0x18fd54: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18fd54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18fd58: 0x3c033f00  lui         $v1, 0x3F00
    ctx->pc = 0x18fd58u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16128 << 16));
    // 0x18fd5c: 0xc425f9f4  lwc1        $f5, -0x60C($at)
    ctx->pc = 0x18fd5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x18fd60: 0x44831800  mtc1        $v1, $f3
    ctx->pc = 0x18fd60u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x18fd64: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fd64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fd68: 0xc42141c0  lwc1        $f1, 0x41C0($at)
    ctx->pc = 0x18fd68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16832)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18fd6c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fd6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fd70: 0xe4204ce8  swc1        $f0, 0x4CE8($at)
    ctx->pc = 0x18fd70u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19688), bits); }
    // 0x18fd74: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x18fd74u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18fd78: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fd78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fd7c: 0xc4224ce8  lwc1        $f2, 0x4CE8($at)
    ctx->pc = 0x18fd7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 19688)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x18fd80: 0x46800120  cvt.s.w     $f4, $f0
    ctx->pc = 0x18fd80u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[4] = FPU_CVT_S_W(tmp); }
    // 0x18fd84: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fd84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fd88: 0xc42041b8  lwc1        $f0, 0x41B8($at)
    ctx->pc = 0x18fd88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16824)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18fd8c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fd8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fd90: 0xe4214cf0  swc1        $f1, 0x4CF0($at)
    ctx->pc = 0x18fd90u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19696), bits); }
    // 0x18fd94: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fd94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fd98: 0xe4204cf4  swc1        $f0, 0x4CF4($at)
    ctx->pc = 0x18fd98u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19700), bits); }
    // 0x18fd9c: 0x46002007  neg.s       $f0, $f4
    ctx->pc = 0x18fd9cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[4]);
    // 0x18fda0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fda0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fda4: 0xe4204cd4  swc1        $f0, 0x4CD4($at)
    ctx->pc = 0x18fda4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19668), bits); }
    // 0x18fda8: 0x46002807  neg.s       $f0, $f5
    ctx->pc = 0x18fda8u;
    ctx->f[0] = FPU_NEG_S(ctx->f[5]);
    // 0x18fdac: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fdacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fdb0: 0x46001802  mul.s       $f0, $f3, $f0
    ctx->pc = 0x18fdb0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[3], ctx->f[0]);
    // 0x18fdb4: 0x46001042  mul.s       $f1, $f2, $f0
    ctx->pc = 0x18fdb4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
    // 0x18fdb8: 0x46051802  mul.s       $f0, $f3, $f5
    ctx->pc = 0x18fdb8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[3], ctx->f[5]);
    // 0x18fdbc: 0xe4214ce8  swc1        $f1, 0x4CE8($at)
    ctx->pc = 0x18fdbcu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19688), bits); }
    // 0x18fdc0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fdc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fdc4: 0xe4204cf8  swc1        $f0, 0x4CF8($at)
    ctx->pc = 0x18fdc4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19704), bits); }
    // 0x18fdc8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x18fdc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18fdcc: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x18fdccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x18fdd0: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x18fdd0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18fdd4: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x18fdd4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x18fdd8: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x18fdd8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18fddc: 0x3e00008  jr          $ra
    ctx->pc = 0x18FDDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18FDE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FDDCu;
            // 0x18fde0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18FD14u: goto label_18fd14;
            case 0x18FD24u: goto label_18fd24;
            case 0x18FD44u: goto label_18fd44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18FDE4u;
    // 0x18fde4: 0x0  nop
    ctx->pc = 0x18fde4u;
    // NOP
    // 0x18fde8: 0x0  nop
    ctx->pc = 0x18fde8u;
    // NOP
    // 0x18fdec: 0x0  nop
    ctx->pc = 0x18fdecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
