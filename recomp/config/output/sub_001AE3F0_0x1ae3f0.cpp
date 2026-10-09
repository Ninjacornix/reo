#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE3F0
// Address: 0x1ae3f0 - 0x1ae470
void sub_001AE3F0_0x1ae3f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE3F0_0x1ae3f0");
#endif

    ctx->pc = 0x1ae3f0u;

    // 0x1ae3f0: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1ae3f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ae3f4: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1ae3f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae3f8: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae3f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae3fc: 0x438c0  sll         $a3, $a0, 3
    ctx->pc = 0x1ae3fcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1ae400: 0x24638d78  addiu       $v1, $v1, -0x7288
    ctx->pc = 0x1ae400u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937976));
    // 0x1ae404: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x1ae404u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1ae408: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1ae408u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ae40c: 0x65082a  slt         $at, $v1, $a1
    ctx->pc = 0x1ae40cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1ae410: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AE410u;
    {
        const bool branch_taken_0x1ae410 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae410) {
            ctx->pc = 0x1AE41Cu;
            goto label_1ae41c;
        }
    }
    ctx->pc = 0x1AE418u;
    // 0x1ae418: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1ae418u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_1ae41c:
    // 0x1ae41c: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae41cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae420: 0x24638d80  addiu       $v1, $v1, -0x7280
    ctx->pc = 0x1ae420u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937984));
    // 0x1ae424: 0x672021  addu        $a0, $v1, $a3
    ctx->pc = 0x1ae424u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1ae428: 0x44851000  mtc1        $a1, $f2
    ctx->pc = 0x1ae428u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1ae42c: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae42cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae430: 0xc4810000  lwc1        $f1, 0x0($a0)
    ctx->pc = 0x1ae430u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ae434: 0x24638d7c  addiu       $v1, $v1, -0x7284
    ctx->pc = 0x1ae434u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937980));
    // 0x1ae438: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x1ae438u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1ae43c: 0x672021  addu        $a0, $v1, $a3
    ctx->pc = 0x1ae43cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1ae440: 0x44860000  mtc1        $a2, $f0
    ctx->pc = 0x1ae440u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ae444: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae444u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae448: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x1ae448u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x1ae44c: 0x24638d84  addiu       $v1, $v1, -0x727C
    ctx->pc = 0x1ae44cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937988));
    // 0x1ae450: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x1ae450u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1ae454: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1ae454u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1ae458: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1ae458u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1ae45c: 0x0  nop
    ctx->pc = 0x1ae45cu;
    // NOP
    // 0x1ae460: 0xe4800000  swc1        $f0, 0x0($a0)
    ctx->pc = 0x1ae460u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x1ae464: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE464u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE464u;
            // 0x1ae468: 0xac650000  sw          $a1, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE41Cu: goto label_1ae41c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE46Cu;
    // 0x1ae46c: 0x0  nop
    ctx->pc = 0x1ae46cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
