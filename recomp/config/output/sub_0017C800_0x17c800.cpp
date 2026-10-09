#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C800
// Address: 0x17c800 - 0x17c8cc
void sub_0017C800_0x17c800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C800_0x17c800");
#endif

    switch (ctx->pc) {
        case 0x17c820u: goto label_17c820;
        case 0x17c858u: goto label_17c858;
        case 0x17c8a8u: goto label_17c8a8;
        default: break;
    }

    ctx->pc = 0x17c800u;

    // 0x17c800: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c804: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c808: 0x8c84003c  lw          $a0, 0x3C($a0)
    ctx->pc = 0x17c808u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c80c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c80cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c810: 0x805f206  j           func_17C818
    ctx->pc = 0x17C810u;
    ctx->pc = 0x17C814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C810u;
            // 0x17c814: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C818u;
    goto label_17c818;
    ctx->pc = 0x17C818u;
label_17c818:
    // 0x17c818: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x17c818u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x17c81c: 0x2482000f  addiu       $v0, $a0, 0xF
    ctx->pc = 0x17c81cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 15));
label_17c820:
    // 0x17c820: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x17c820u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x17c824: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x17c824u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x17c828: 0x0  nop
    ctx->pc = 0x17c828u;
    // NOP
    // 0x17c82c: 0x0  nop
    ctx->pc = 0x17c82cu;
    // NOP
    // 0x17c830: 0x0  nop
    ctx->pc = 0x17c830u;
    // NOP
    // 0x17c834: 0x4a1fffa  bgez        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17C834u;
    {
        const bool branch_taken_0x17c834 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x17C838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C834u;
            // 0x17c838: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c834) {
            ctx->pc = 0x17C820u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17c820;
        }
    }
    ctx->pc = 0x17C83Cu;
    // 0x17c83c: 0x3c013f14  lui         $at, 0x3F14
    ctx->pc = 0x17c83cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16148 << 16));
    // 0x17c840: 0x3421fdf3  ori         $at, $at, 0xFDF3
    ctx->pc = 0x17c840u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65011);
    // 0x17c844: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x17c844u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x17c848: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x17c848u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x17c84c: 0x3c014f00  lui         $at, 0x4F00
    ctx->pc = 0x17c84cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)20224 << 16));
    // 0x17c850: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x17c850u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x17c854: 0x3c078000  lui         $a3, 0x8000
    ctx->pc = 0x17c854u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)32768 << 16));
label_17c858:
    // 0x17c858: 0x24a2fff0  addiu       $v0, $a1, -0x10
    ctx->pc = 0x17c858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967280));
    // 0x17c85c: 0x853021  addu        $a2, $a0, $a1
    ctx->pc = 0x17c85cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x17c860: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x17c860u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17c864: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x17c864u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x17c868: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x17c868u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x17c86c: 0x46020002  mul.s       $f0, $f0, $f2
    ctx->pc = 0x17c86cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x17c870: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x17c870u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17c874: 0x460000e4  .word       0x460000E4                   # cvt.w.s     $f3, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x17c874u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x17c878: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x17c878u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x17c87c: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x17C87Cu;
    {
        const bool branch_taken_0x17c87c = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x17C880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C87Cu;
            // 0x17c880: 0x28a300ec  slti        $v1, $a1, 0xEC (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)236) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c87c) {
            ctx->pc = 0x17C894u;
            goto label_17c894;
        }
    }
    ctx->pc = 0x17C884u;
    // 0x17c884: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x17c884u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x17c888: 0x460000e4  .word       0x460000E4                   # cvt.w.s     $f3, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x17c888u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x17c88c: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x17c88cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x17c890: 0x471025  or          $v0, $v0, $a3
    ctx->pc = 0x17c890u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
label_17c894:
    // 0x17c894: 0x1460fff0  bnez        $v1, . + 4 + (-0x10 << 2)
    ctx->pc = 0x17C894u;
    {
        const bool branch_taken_0x17c894 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17C898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C894u;
            // 0x17c898: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c894) {
            ctx->pc = 0x17C858u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17c858;
        }
    }
    ctx->pc = 0x17C89Cu;
    // 0x17c89c: 0x240500ec  addiu       $a1, $zero, 0xEC
    ctx->pc = 0x17c89cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 236));
    // 0x17c8a0: 0x2406ff80  addiu       $a2, $zero, -0x80
    ctx->pc = 0x17c8a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
    // 0x17c8a4: 0x0  nop
    ctx->pc = 0x17c8a4u;
    // NOP
label_17c8a8:
    // 0x17c8a8: 0x851821  addu        $v1, $a0, $a1
    ctx->pc = 0x17c8a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x17c8ac: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x17c8acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x17c8b0: 0x28a20100  slti        $v0, $a1, 0x100
    ctx->pc = 0x17c8b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x17c8b4: 0x0  nop
    ctx->pc = 0x17c8b4u;
    // NOP
    // 0x17c8b8: 0x0  nop
    ctx->pc = 0x17c8b8u;
    // NOP
    // 0x17c8bc: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17C8BCu;
    {
        const bool branch_taken_0x17c8bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17C8C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C8BCu;
            // 0x17c8c0: 0xa0660000  sb          $a2, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c8bc) {
            ctx->pc = 0x17C8A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17c8a8;
        }
    }
    ctx->pc = 0x17C8C4u;
    // 0x17c8c4: 0x3e00008  jr          $ra
    ctx->pc = 0x17C8C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17C818u: goto label_17c818;
            case 0x17C820u: goto label_17c820;
            case 0x17C858u: goto label_17c858;
            case 0x17C894u: goto label_17c894;
            case 0x17C8A8u: goto label_17c8a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17C8CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
