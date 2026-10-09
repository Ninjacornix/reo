#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191EF0
// Address: 0x191ef0 - 0x192000
void sub_00191EF0_0x191ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191EF0_0x191ef0");
#endif

    ctx->pc = 0x191ef0u;

    // 0x191ef0: 0x3c024334  lui         $v0, 0x4334
    ctx->pc = 0x191ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17204 << 16));
    // 0x191ef4: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x191ef4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x191ef8: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x191ef8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x191efc: 0xc4211c88  lwc1        $f1, 0x1C88($at)
    ctx->pc = 0x191efcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7304)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191f00: 0x460c1082  mul.s       $f2, $f2, $f12
    ctx->pc = 0x191f00u;
    ctx->f[2] = FPU_MUL_S(ctx->f[2], ctx->f[12]);
    // 0x191f04: 0x46011083  div.s       $f2, $f2, $f1
    ctx->pc = 0x191f04u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[2] / ctx->f[1];
    // 0x191f08: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x191f08u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x191f0c: 0x0  nop
    ctx->pc = 0x191f0cu;
    // NOP
    // 0x191f10: 0x0  nop
    ctx->pc = 0x191f10u;
    // NOP
    // 0x191f14: 0x46001034  c.lt.s      $f2, $f0
    ctx->pc = 0x191f14u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[2], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x191f18: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x191F18u;
    {
        const bool branch_taken_0x191f18 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x191F1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191F18u;
            // 0x191f1c: 0x3c010024  lui         $at, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x191f18) {
            ctx->pc = 0x191F30u;
            goto label_191f30;
        }
    }
    ctx->pc = 0x191F20u;
    // 0x191f20: 0x3c0243b4  lui         $v0, 0x43B4
    ctx->pc = 0x191f20u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17332 << 16));
    // 0x191f24: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x191f24u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x191f28: 0x0  nop
    ctx->pc = 0x191f28u;
    // NOP
    // 0x191f2c: 0x46001080  add.s       $f2, $f2, $f0
    ctx->pc = 0x191f2cu;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
label_191f30:
    // 0x191f30: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x191f30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x191f34: 0xc4211c80  lwc1        $f1, 0x1C80($at)
    ctx->pc = 0x191f34u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7296)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191f38: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x191f38u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x191f3c: 0x0  nop
    ctx->pc = 0x191f3cu;
    // NOP
    // 0x191f40: 0x46020842  mul.s       $f1, $f1, $f2
    ctx->pc = 0x191f40u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x191f44: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x191f44u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x191f48: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x191F48u;
    {
        const bool branch_taken_0x191f48 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x191f48) {
            ctx->pc = 0x191F60u;
            goto label_191f60;
        }
    }
    ctx->pc = 0x191F50u;
    // 0x191f50: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x191f50u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x191f54: 0x44020800  mfc1        $v0, $f1
    ctx->pc = 0x191f54u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x191f58: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x191F58u;
    {
        const bool branch_taken_0x191f58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x191f58) {
            ctx->pc = 0x191F78u;
            goto label_191f78;
        }
    }
    ctx->pc = 0x191F60u;
label_191f60:
    // 0x191f60: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x191f60u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x191f64: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x191f64u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x191f68: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x191f68u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x191f6c: 0x44020800  mfc1        $v0, $f1
    ctx->pc = 0x191f6cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x191f70: 0x0  nop
    ctx->pc = 0x191f70u;
    // NOP
    // 0x191f74: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x191f74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
label_191f78:
    // 0x191f78: 0x3e00008  jr          $ra
    ctx->pc = 0x191F78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191F30u: goto label_191f30;
            case 0x191F60u: goto label_191f60;
            case 0x191F78u: goto label_191f78;
            case 0x191F9Cu: goto label_191f9c;
            case 0x191FB4u: goto label_191fb4;
            case 0x191FF0u: goto label_191ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191F80u;
    // 0x191f80: 0x3c023bb4  lui         $v0, 0x3BB4
    ctx->pc = 0x191f80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15284 << 16));
    // 0x191f84: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x191f84u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x191f88: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x191F88u;
    {
        const bool branch_taken_0x191f88 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x191F8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191F88u;
            // 0x191f8c: 0x41842  srl         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x191f88) {
            ctx->pc = 0x191F9Cu;
            goto label_191f9c;
        }
    }
    ctx->pc = 0x191F90u;
    // 0x191f90: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x191f90u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x191f94: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x191F94u;
    {
        const bool branch_taken_0x191f94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x191F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191F94u;
            // 0x191f98: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x191f94) {
            ctx->pc = 0x191FB4u;
            goto label_191fb4;
        }
    }
    ctx->pc = 0x191F9Cu;
label_191f9c:
    // 0x191f9c: 0x30820001  andi        $v0, $a0, 0x1
    ctx->pc = 0x191f9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x191fa0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x191fa0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x191fa4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x191fa4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x191fa8: 0x0  nop
    ctx->pc = 0x191fa8u;
    // NOP
    // 0x191fac: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x191facu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x191fb0: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x191fb0u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_191fb4:
    // 0x191fb4: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x191fb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x191fb8: 0x3c024334  lui         $v0, 0x4334
    ctx->pc = 0x191fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17204 << 16));
    // 0x191fbc: 0xc4221c88  lwc1        $f2, 0x1C88($at)
    ctx->pc = 0x191fbcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7304)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191fc0: 0x46000842  mul.s       $f1, $f1, $f0
    ctx->pc = 0x191fc0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x191fc4: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x191fc4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x191fc8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x191fc8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x191fcc: 0x0  nop
    ctx->pc = 0x191fccu;
    // NOP
    // 0x191fd0: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x191fd0u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x191fd4: 0x0  nop
    ctx->pc = 0x191fd4u;
    // NOP
    // 0x191fd8: 0x0  nop
    ctx->pc = 0x191fd8u;
    // NOP
    // 0x191fdc: 0x46020036  c.le.s      $f0, $f2
    ctx->pc = 0x191fdcu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[2])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x191fe0: 0x45010003  bc1t        . + 4 + (0x3 << 2)
    ctx->pc = 0x191FE0u;
    {
        const bool branch_taken_0x191fe0 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x191FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191FE0u;
            // 0x191fe4: 0x3c010024  lui         $at, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x191fe0) {
            ctx->pc = 0x191FF0u;
            goto label_191ff0;
        }
    }
    ctx->pc = 0x191FE8u;
    // 0x191fe8: 0xc4211c78  lwc1        $f1, 0x1C78($at)
    ctx->pc = 0x191fe8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7288)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191fec: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x191fecu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
label_191ff0:
    // 0x191ff0: 0x3e00008  jr          $ra
    ctx->pc = 0x191FF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191F30u: goto label_191f30;
            case 0x191F60u: goto label_191f60;
            case 0x191F78u: goto label_191f78;
            case 0x191F9Cu: goto label_191f9c;
            case 0x191FB4u: goto label_191fb4;
            case 0x191FF0u: goto label_191ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191FF8u;
    // 0x191ff8: 0x0  nop
    ctx->pc = 0x191ff8u;
    // NOP
    // 0x191ffc: 0x0  nop
    ctx->pc = 0x191ffcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
