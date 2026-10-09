#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001772B8
// Address: 0x1772b8 - 0x1773a8
void sub_001772B8_0x1772b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001772B8_0x1772b8");
#endif

    ctx->pc = 0x1772b8u;

    // 0x1772b8: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1772b8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1772bc: 0xc4e10a58  lwc1        $f1, 0xA58($a3)
    ctx->pc = 0x1772bcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 2648)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1772c0: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1772c0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1772c4: 0x46016800  add.s       $f0, $f13, $f1
    ctx->pc = 0x1772c4u;
    ctx->f[0] = FPU_ADD_S(ctx->f[13], ctx->f[1]);
    // 0x1772c8: 0x460c0034  c.lt.s      $f0, $f12
    ctx->pc = 0x1772c8u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1772cc: 0x45000004  bc1f        . + 4 + (0x4 << 2)
    ctx->pc = 0x1772CCu;
    {
        const bool branch_taken_0x1772cc = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1772D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1772CCu;
            // 0x1772d0: 0x24e60cc0  addiu       $a2, $a3, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 3264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1772cc) {
            ctx->pc = 0x1772E0u;
            goto label_1772e0;
        }
    }
    ctx->pc = 0x1772D4u;
    // 0x1772d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1772D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1772D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1772D4u;
            // 0x1772d8: 0xaca00000  sw          $zero, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1772E0u: goto label_1772e0;
            case 0x177328u: goto label_177328;
            case 0x177354u: goto label_177354;
            case 0x177358u: goto label_177358;
            case 0x177370u: goto label_177370;
            case 0x177388u: goto label_177388;
            case 0x17738Cu: goto label_17738c;
            case 0x17739Cu: goto label_17739c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1772DCu;
    // 0x1772dc: 0x0  nop
    ctx->pc = 0x1772dcu;
    // NOP
label_1772e0:
    // 0x1772e0: 0x46016801  sub.s       $f0, $f13, $f1
    ctx->pc = 0x1772e0u;
    ctx->f[0] = FPU_SUB_S(ctx->f[13], ctx->f[1]);
    // 0x1772e4: 0x46006036  c.le.s      $f12, $f0
    ctx->pc = 0x1772e4u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1772e8: 0x4500000f  bc1f        . + 4 + (0xF << 2)
    ctx->pc = 0x1772E8u;
    {
        const bool branch_taken_0x1772e8 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1772ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1772E8u;
            // 0x1772ec: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1772e8) {
            ctx->pc = 0x177328u;
            goto label_177328;
        }
    }
    ctx->pc = 0x1772F0u;
    // 0x1772f0: 0xc4c00284  lwc1        $f0, 0x284($a2)
    ctx->pc = 0x1772f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 644)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1772f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1772f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1772f8: 0x460c0032  c.eq.s      $f0, $f12
    ctx->pc = 0x1772f8u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1772fc: 0x45010027  bc1t        . + 4 + (0x27 << 2)
    ctx->pc = 0x1772FCu;
    {
        const bool branch_taken_0x1772fc = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x177300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1772FCu;
            // 0x177300: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1772fc) {
            ctx->pc = 0x17739Cu;
            goto label_17739c;
        }
    }
    ctx->pc = 0x177304u;
    // 0x177304: 0xc4c0027c  lwc1        $f0, 0x27C($a2)
    ctx->pc = 0x177304u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 636)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x177308: 0x460c0032  c.eq.s      $f0, $f12
    ctx->pc = 0x177308u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17730c: 0x45010023  bc1t        . + 4 + (0x23 << 2)
    ctx->pc = 0x17730Cu;
    {
        const bool branch_taken_0x17730c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x17730c) {
            ctx->pc = 0x17739Cu;
            goto label_17739c;
        }
    }
    ctx->pc = 0x177314u;
    // 0x177314: 0x8cc20278  lw          $v0, 0x278($a2)
    ctx->pc = 0x177314u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 632)));
    // 0x177318: 0xe4cc027c  swc1        $f12, 0x27C($a2)
    ctx->pc = 0x177318u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 636), bits); }
    // 0x17731c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x17731cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x177320: 0x3e00008  jr          $ra
    ctx->pc = 0x177320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177320u;
            // 0x177324: 0xacc20278  sw          $v0, 0x278($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 632), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1772E0u: goto label_1772e0;
            case 0x177328u: goto label_177328;
            case 0x177354u: goto label_177354;
            case 0x177358u: goto label_177358;
            case 0x177370u: goto label_177370;
            case 0x177388u: goto label_177388;
            case 0x17738Cu: goto label_17738c;
            case 0x17739Cu: goto label_17739c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177328u;
label_177328:
    // 0x177328: 0x3404ea24  ori         $a0, $zero, 0xEA24
    ctx->pc = 0x177328u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)59940);
    // 0x17732c: 0x8c43f140  lw          $v1, -0xEC0($v0)
    ctx->pc = 0x17732cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294963520)));
    // 0x177330: 0x14640008  bne         $v1, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x177330u;
    {
        const bool branch_taken_0x177330 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x177334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177330u;
            // 0x177334: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177330) {
            ctx->pc = 0x177354u;
            goto label_177354;
        }
    }
    ctx->pc = 0x177338u;
    // 0x177338: 0x8ce20920  lw          $v0, 0x920($a3)
    ctx->pc = 0x177338u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 2336)));
    // 0x17733c: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x17733cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x177340: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x177340u;
    {
        const bool branch_taken_0x177340 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x177340) {
            ctx->pc = 0x177344u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x177340u;
            // 0x177344: 0x8cc20278  lw          $v0, 0x278($a2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 632)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x177358u;
            goto label_177358;
        }
    }
    ctx->pc = 0x177348u;
    // 0x177348: 0x8cc20268  lw          $v0, 0x268($a2)
    ctx->pc = 0x177348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 616)));
    // 0x17734c: 0x384203e8  xori        $v0, $v0, 0x3E8
    ctx->pc = 0x17734cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1000);
    // 0x177350: 0x2c480001  sltiu       $t0, $v0, 0x1
    ctx->pc = 0x177350u;
    SET_GPR_U64(ctx, 8, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_177354:
    // 0x177354: 0x8cc20278  lw          $v0, 0x278($a2)
    ctx->pc = 0x177354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 632)));
label_177358:
    // 0x177358: 0x102102a  slt         $v0, $t0, $v0
    ctx->pc = 0x177358u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x17735c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x17735Cu;
    {
        const bool branch_taken_0x17735c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17735c) {
            ctx->pc = 0x177370u;
            goto label_177370;
        }
    }
    ctx->pc = 0x177364u;
    // 0x177364: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x177364u;
    {
        const bool branch_taken_0x177364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177364u;
            // 0x177368: 0x8cc20280  lw          $v0, 0x280($a2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 640)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177364) {
            ctx->pc = 0x177388u;
            goto label_177388;
        }
    }
    ctx->pc = 0x17736Cu;
    // 0x17736c: 0x0  nop
    ctx->pc = 0x17736cu;
    // NOP
label_177370:
    // 0x177370: 0x460c6834  c.lt.s      $f13, $f12
    ctx->pc = 0x177370u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[13], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x177374: 0x45000004  bc1f        . + 4 + (0x4 << 2)
    ctx->pc = 0x177374u;
    {
        const bool branch_taken_0x177374 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x177378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177374u;
            // 0x177378: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177374) {
            ctx->pc = 0x177388u;
            goto label_177388;
        }
    }
    ctx->pc = 0x17737Cu;
    // 0x17737c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x17737Cu;
    {
        const bool branch_taken_0x17737c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17737Cu;
            // 0x177380: 0xaca00000  sw          $zero, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17737c) {
            ctx->pc = 0x17738Cu;
            goto label_17738c;
        }
    }
    ctx->pc = 0x177384u;
    // 0x177384: 0x0  nop
    ctx->pc = 0x177384u;
    // NOP
label_177388:
    // 0x177388: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x177388u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_17738c:
    // 0x17738c: 0xacc00278  sw          $zero, 0x278($a2)
    ctx->pc = 0x17738cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 632), GPR_U32(ctx, 0));
    // 0x177390: 0xe4cc0284  swc1        $f12, 0x284($a2)
    ctx->pc = 0x177390u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 644), bits); }
    // 0x177394: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x177394u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x177398: 0xacc20280  sw          $v0, 0x280($a2)
    ctx->pc = 0x177398u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 640), GPR_U32(ctx, 2));
label_17739c:
    // 0x17739c: 0x3e00008  jr          $ra
    ctx->pc = 0x17739Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1772E0u: goto label_1772e0;
            case 0x177328u: goto label_177328;
            case 0x177354u: goto label_177354;
            case 0x177358u: goto label_177358;
            case 0x177370u: goto label_177370;
            case 0x177388u: goto label_177388;
            case 0x17738Cu: goto label_17738c;
            case 0x17739Cu: goto label_17739c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1773A4u;
    // 0x1773a4: 0x0  nop
    ctx->pc = 0x1773a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
