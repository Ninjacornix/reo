#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E320
// Address: 0x17e320 - 0x17e368
void sub_0017E320_0x17e320(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E320_0x17e320");
#endif

    ctx->pc = 0x17e320u;

    // 0x17e320: 0x460c6836  c.le.s      $f13, $f12
    ctx->pc = 0x17e320u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[13], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17e324: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17e324u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e328: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x17E328u;
    {
        const bool branch_taken_0x17e328 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x17E32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E328u;
            // 0x17e32c: 0x460c6841  sub.s       $f1, $f13, $f12 (Delay Slot)
        ctx->f[1] = FPU_SUB_S(ctx->f[13], ctx->f[12]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e328) {
            ctx->pc = 0x17E334u;
            goto label_17e334;
        }
    }
    ctx->pc = 0x17E330u;
    // 0x17e330: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17e330u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17e334:
    // 0x17e334: 0x3c01c160  lui         $at, 0xC160
    ctx->pc = 0x17e334u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49504 << 16));
    // 0x17e338: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x17e338u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17e33c: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x17e33cu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17e340: 0x45030001  bc1tl       . + 4 + (0x1 << 2)
    ctx->pc = 0x17E340u;
    {
        const bool branch_taken_0x17e340 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x17e340) {
            ctx->pc = 0x17E344u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17E340u;
            // 0x17e344: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17E348u;
            goto label_17e348;
        }
    }
    ctx->pc = 0x17E348u;
label_17e348:
    // 0x17e348: 0x3e00008  jr          $ra
    ctx->pc = 0x17E348u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E334u: goto label_17e334;
            case 0x17E348u: goto label_17e348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E350u;
    // 0x17e350: 0xc480003c  lwc1        $f0, 0x3C($a0)
    ctx->pc = 0x17e350u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x17e354: 0xe4a00000  swc1        $f0, 0x0($a1)
    ctx->pc = 0x17e354u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
    // 0x17e358: 0xc4810040  lwc1        $f1, 0x40($a0)
    ctx->pc = 0x17e358u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x17e35c: 0x3e00008  jr          $ra
    ctx->pc = 0x17E35Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E35Cu;
            // 0x17e360: 0xe4c10000  swc1        $f1, 0x0($a2) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 0), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E334u: goto label_17e334;
            case 0x17E348u: goto label_17e348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E364u;
    // 0x17e364: 0x0  nop
    ctx->pc = 0x17e364u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
