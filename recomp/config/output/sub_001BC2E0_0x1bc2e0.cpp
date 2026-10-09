#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC2E0
// Address: 0x1bc2e0 - 0x1bc37c
void sub_001BC2E0_0x1bc2e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC2E0_0x1bc2e0");
#endif

    ctx->pc = 0x1bc2e0u;

    // 0x1bc2e0: 0x3c080031  lui         $t0, 0x31
    ctx->pc = 0x1bc2e0u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)49 << 16));
    // 0x1bc2e4: 0x14800014  bnez        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1BC2E4u;
    {
        const bool branch_taken_0x1bc2e4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BC2E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC2E4u;
            // 0x1bc2e8: 0x250865c0  addiu       $t0, $t0, 0x65C0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 26048));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc2e4) {
            ctx->pc = 0x1BC338u;
            goto label_1bc338;
        }
    }
    ctx->pc = 0x1BC2ECu;
    // 0x1bc2ec: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1bc2ecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bc2f0: 0x24c30001  addiu       $v1, $a2, 0x1
    ctx->pc = 0x1bc2f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1bc2f4: 0x44860000  mtc1        $a2, $f0
    ctx->pc = 0x1bc2f4u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bc2f8: 0xa1070000  sb          $a3, 0x0($t0)
    ctx->pc = 0x1bc2f8u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0x1bc2fc: 0xad040004  sw          $a0, 0x4($t0)
    ctx->pc = 0x1bc2fcu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 4), GPR_U32(ctx, 4));
    // 0x1bc300: 0xad05000c  sw          $a1, 0xC($t0)
    ctx->pc = 0x1bc300u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 5));
    // 0x1bc304: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1bc304u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1bc308: 0xad030008  sw          $v1, 0x8($t0)
    ctx->pc = 0x1bc308u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 8), GPR_U32(ctx, 3));
    // 0x1bc30c: 0x240400ff  addiu       $a0, $zero, 0xFF
    ctx->pc = 0x1bc30cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1bc310: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x1bc310u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x1bc314: 0xa1040010  sb          $a0, 0x10($t0)
    ctx->pc = 0x1bc314u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 16), (uint8_t)GPR_U32(ctx, 4));
    // 0x1bc318: 0xad030014  sw          $v1, 0x14($t0)
    ctx->pc = 0x1bc318u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 20), GPR_U32(ctx, 3));
    // 0x1bc31c: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1bc31cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bc320: 0x0  nop
    ctx->pc = 0x1bc320u;
    // NOP
    // 0x1bc324: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1bc324u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1bc328: 0x0  nop
    ctx->pc = 0x1bc328u;
    // NOP
    // 0x1bc32c: 0x0  nop
    ctx->pc = 0x1bc32cu;
    // NOP
    // 0x1bc330: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1BC330u;
    {
        const bool branch_taken_0x1bc330 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC330u;
            // 0x1bc334: 0xe5000018  swc1        $f0, 0x18($t0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 8), 24), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc330) {
            ctx->pc = 0x1BC374u;
            goto label_1bc374;
        }
    }
    ctx->pc = 0x1BC338u;
label_1bc338:
    // 0x1bc338: 0x44860000  mtc1        $a2, $f0
    ctx->pc = 0x1bc338u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bc33c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1bc33cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bc340: 0xa1030000  sb          $v1, 0x0($t0)
    ctx->pc = 0x1bc340u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bc344: 0x24c70001  addiu       $a3, $a2, 0x1
    ctx->pc = 0x1bc344u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1bc348: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1bc348u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1bc34c: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x1bc34cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x1bc350: 0xad040004  sw          $a0, 0x4($t0)
    ctx->pc = 0x1bc350u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 4), GPR_U32(ctx, 4));
    // 0x1bc354: 0xad05000c  sw          $a1, 0xC($t0)
    ctx->pc = 0x1bc354u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 5));
    // 0x1bc358: 0xad070008  sw          $a3, 0x8($t0)
    ctx->pc = 0x1bc358u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 8), GPR_U32(ctx, 7));
    // 0x1bc35c: 0xa1000010  sb          $zero, 0x10($t0)
    ctx->pc = 0x1bc35cu;
    WRITE8(ADD32(GPR_U32(ctx, 8), 16), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bc360: 0xad000014  sw          $zero, 0x14($t0)
    ctx->pc = 0x1bc360u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 20), GPR_U32(ctx, 0));
    // 0x1bc364: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1bc364u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bc368: 0x0  nop
    ctx->pc = 0x1bc368u;
    // NOP
    // 0x1bc36c: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1bc36cu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1bc370: 0xe5000018  swc1        $f0, 0x18($t0)
    ctx->pc = 0x1bc370u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 8), 24), bits); }
label_1bc374:
    // 0x1bc374: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC374u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC338u: goto label_1bc338;
            case 0x1BC374u: goto label_1bc374;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC37Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
