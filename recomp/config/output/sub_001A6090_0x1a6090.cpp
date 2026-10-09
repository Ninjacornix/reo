#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A6090
// Address: 0x1a6090 - 0x1a6140
void sub_001A6090_0x1a6090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A6090_0x1a6090");
#endif

    ctx->pc = 0x1a6090u;

    // 0x1a6090: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A6090u;
    {
        const bool branch_taken_0x1a6090 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1A6094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6090u;
            // 0x1a6094: 0x41842  srl         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6090) {
            ctx->pc = 0x1A60A4u;
            goto label_1a60a4;
        }
    }
    ctx->pc = 0x1A6098u;
    // 0x1a6098: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1a6098u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a609c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1A609Cu;
    {
        const bool branch_taken_0x1a609c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A60A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A609Cu;
            // 0x1a60a0: 0x468000a0  cvt.s.w     $f2, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a609c) {
            ctx->pc = 0x1A60BCu;
            goto label_1a60bc;
        }
    }
    ctx->pc = 0x1A60A4u;
label_1a60a4:
    // 0x1a60a4: 0x30820001  andi        $v0, $a0, 0x1
    ctx->pc = 0x1a60a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1a60a8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1a60a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a60ac: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a60acu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a60b0: 0x0  nop
    ctx->pc = 0x1a60b0u;
    // NOP
    // 0x1a60b4: 0x468000a0  cvt.s.w     $f2, $f0
    ctx->pc = 0x1a60b4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1a60b8: 0x46021080  add.s       $f2, $f2, $f2
    ctx->pc = 0x1a60b8u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[2]);
label_1a60bc:
    // 0x1a60bc: 0x3c024300  lui         $v0, 0x4300
    ctx->pc = 0x1a60bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17152 << 16));
    // 0x1a60c0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a60c0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a60c4: 0x0  nop
    ctx->pc = 0x1a60c4u;
    // NOP
    // 0x1a60c8: 0x46001034  c.lt.s      $f2, $f0
    ctx->pc = 0x1a60c8u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[2], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a60cc: 0x4501000b  bc1t        . + 4 + (0xB << 2)
    ctx->pc = 0x1A60CCu;
    {
        const bool branch_taken_0x1a60cc = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1A60D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A60CCu;
            // 0x1a60d0: 0x3c0242ae  lui         $v0, 0x42AE (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17070 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a60cc) {
            ctx->pc = 0x1A60FCu;
            goto label_1a60fc;
        }
    }
    ctx->pc = 0x1A60D4u;
    // 0x1a60d4: 0x3c024328  lui         $v0, 0x4328
    ctx->pc = 0x1a60d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17192 << 16));
    // 0x1a60d8: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1a60d8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1a60dc: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1a60dcu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a60e0: 0x0  nop
    ctx->pc = 0x1a60e0u;
    // NOP
    // 0x1a60e4: 0x46011081  sub.s       $f2, $f2, $f1
    ctx->pc = 0x1a60e4u;
    ctx->f[2] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x1a60e8: 0x46001034  c.lt.s      $f2, $f0
    ctx->pc = 0x1a60e8u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[2], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a60ec: 0x4500000d  bc1f        . + 4 + (0xD << 2)
    ctx->pc = 0x1A60ECu;
    {
        const bool branch_taken_0x1a60ec = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a60ec) {
            ctx->pc = 0x1A6124u;
            goto label_1a6124;
        }
    }
    ctx->pc = 0x1A60F4u;
    // 0x1a60f4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A60F4u;
    {
        const bool branch_taken_0x1a60f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A60F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A60F4u;
            // 0x1a60f8: 0x46000086  mov.s       $f2, $f0 (Delay Slot)
        ctx->f[2] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a60f4) {
            ctx->pc = 0x1A6124u;
            goto label_1a6124;
        }
    }
    ctx->pc = 0x1A60FCu;
label_1a60fc:
    // 0x1a60fc: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a60fcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a6100: 0x0  nop
    ctx->pc = 0x1a6100u;
    // NOP
    // 0x1a6104: 0x46001036  c.le.s      $f2, $f0
    ctx->pc = 0x1a6104u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[2], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a6108: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x1A6108u;
    {
        const bool branch_taken_0x1a6108 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a6108) {
            ctx->pc = 0x1A6114u;
            goto label_1a6114;
        }
    }
    ctx->pc = 0x1A6110u;
    // 0x1a6110: 0x46000086  mov.s       $f2, $f0
    ctx->pc = 0x1a6110u;
    ctx->f[2] = FPU_MOV_S(ctx->f[0]);
label_1a6114:
    // 0x1a6114: 0x3c0242ae  lui         $v0, 0x42AE
    ctx->pc = 0x1a6114u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17070 << 16));
    // 0x1a6118: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a6118u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a611c: 0x0  nop
    ctx->pc = 0x1a611cu;
    // NOP
    // 0x1a6120: 0x46001081  sub.s       $f2, $f2, $f0
    ctx->pc = 0x1a6120u;
    ctx->f[2] = FPU_SUB_S(ctx->f[2], ctx->f[0]);
label_1a6124:
    // 0x1a6124: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x1a6124u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x1a6128: 0xc4201f60  lwc1        $f0, 0x1F60($at)
    ctx->pc = 0x1a6128u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 8032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a612c: 0x46001082  mul.s       $f2, $f2, $f0
    ctx->pc = 0x1a612cu;
    ctx->f[2] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
    // 0x1a6130: 0x46001024  .word       0x46001024                   # cvt.w.s     $f0, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a6130u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1a6134: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x1a6134u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1a6138: 0x3e00008  jr          $ra
    ctx->pc = 0x1A6138u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A60A4u: goto label_1a60a4;
            case 0x1A60BCu: goto label_1a60bc;
            case 0x1A60FCu: goto label_1a60fc;
            case 0x1A6114u: goto label_1a6114;
            case 0x1A6124u: goto label_1a6124;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A6140u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
