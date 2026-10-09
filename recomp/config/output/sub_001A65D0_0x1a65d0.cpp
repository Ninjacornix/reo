#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A65D0
// Address: 0x1a65d0 - 0x1a6660
void sub_001A65D0_0x1a65d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A65D0_0x1a65d0");
#endif

    ctx->pc = 0x1a65d0u;

    // 0x1a65d0: 0x84820004  lh          $v0, 0x4($a0)
    ctx->pc = 0x1a65d0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a65d4: 0x28410025  slti        $at, $v0, 0x25
    ctx->pc = 0x1a65d4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)37) ? 1 : 0);
    // 0x1a65d8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A65D8u;
    {
        const bool branch_taken_0x1a65d8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A65DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A65D8u;
            // 0x1a65dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a65d8) {
            ctx->pc = 0x1A65E8u;
            goto label_1a65e8;
        }
    }
    ctx->pc = 0x1A65E0u;
    // 0x1a65e0: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1A65E0u;
    {
        const bool branch_taken_0x1a65e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a65e0) {
            ctx->pc = 0x1A6658u;
            goto label_1a6658;
        }
    }
    ctx->pc = 0x1A65E8u;
label_1a65e8:
    // 0x1a65e8: 0x84830006  lh          $v1, 0x6($a0)
    ctx->pc = 0x1a65e8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x1a65ec: 0x3c0241b4  lui         $v0, 0x41B4
    ctx->pc = 0x1a65ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16820 << 16));
    // 0x1a65f0: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1a65f0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1a65f4: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1a65f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1a65f8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a65f8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a65fc: 0x44831000  mtc1        $v1, $f2
    ctx->pc = 0x1a65fcu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1a6600: 0x0  nop
    ctx->pc = 0x1a6600u;
    // NOP
    // 0x1a6604: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x1a6604u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1a6608: 0x46011043  div.s       $f1, $f2, $f1
    ctx->pc = 0x1a6608u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[2] / ctx->f[1];
    // 0x1a660c: 0x0  nop
    ctx->pc = 0x1a660cu;
    // NOP
    // 0x1a6610: 0x0  nop
    ctx->pc = 0x1a6610u;
    // NOP
    // 0x1a6614: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a6614u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a6618: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A6618u;
    {
        const bool branch_taken_0x1a6618 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a6618) {
            ctx->pc = 0x1A6630u;
            goto label_1a6630;
        }
    }
    ctx->pc = 0x1A6620u;
    // 0x1a6620: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a6620u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a6624: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a6624u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a6628: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1A6628u;
    {
        const bool branch_taken_0x1a6628 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a6628) {
            ctx->pc = 0x1A6648u;
            goto label_1a6648;
        }
    }
    ctx->pc = 0x1A6630u;
label_1a6630:
    // 0x1a6630: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a6630u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a6634: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1a6634u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1a6638: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a6638u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a663c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a663cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a6640: 0x0  nop
    ctx->pc = 0x1a6640u;
    // NOP
    // 0x1a6644: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1a6644u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
label_1a6648:
    // 0x1a6648: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1a6648u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1a664c: 0x24421170  addiu       $v0, $v0, 0x1170
    ctx->pc = 0x1a664cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4464));
    // 0x1a6650: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a6650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a6654: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1a6654u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
label_1a6658:
    // 0x1a6658: 0x3e00008  jr          $ra
    ctx->pc = 0x1A6658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A65E8u: goto label_1a65e8;
            case 0x1A6630u: goto label_1a6630;
            case 0x1A6648u: goto label_1a6648;
            case 0x1A6658u: goto label_1a6658;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A6660u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
