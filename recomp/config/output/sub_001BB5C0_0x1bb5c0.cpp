#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB5C0
// Address: 0x1bb5c0 - 0x1bb644
void sub_001BB5C0_0x1bb5c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB5C0_0x1bb5c0");
#endif

    ctx->pc = 0x1bb5c0u;

    // 0x1bb5c0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb5c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb5c4: 0x3c060031  lui         $a2, 0x31
    ctx->pc = 0x1bb5c4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49 << 16));
    // 0x1bb5c8: 0x90236650  lbu         $v1, 0x6650($at)
    ctx->pc = 0x1bb5c8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26192)));
    // 0x1bb5cc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1bb5ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bb5d0: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BB5D0u;
    {
        const bool branch_taken_0x1bb5d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BB5D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB5D0u;
            // 0x1bb5d4: 0x24c66650  addiu       $a2, $a2, 0x6650 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb5d0) {
            ctx->pc = 0x1BB5E8u;
            goto label_1bb5e8;
        }
    }
    ctx->pc = 0x1BB5D8u;
    // 0x1bb5d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb5d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb5dc: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BB5DCu;
    {
        const bool branch_taken_0x1bb5dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1bb5dc) {
            ctx->pc = 0x1BB5E8u;
            goto label_1bb5e8;
        }
    }
    ctx->pc = 0x1BB5E4u;
    // 0x1bb5e4: 0xacc0000c  sw          $zero, 0xC($a2)
    ctx->pc = 0x1bb5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 0));
label_1bb5e8:
    // 0x1bb5e8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bb5e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bb5ec: 0x41c3c  dsll32      $v1, $a0, 16
    ctx->pc = 0x1bb5ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1bb5f0: 0x902243cc  lbu         $v0, 0x43CC($at)
    ctx->pc = 0x1bb5f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17356)));
    // 0x1bb5f4: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1bb5f4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1bb5f8: 0x431007  srav        $v0, $v1, $v0
    ctx->pc = 0x1bb5f8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0x1bb5fc: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1bb5fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1bb600: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1bb600u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1bb604: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BB604u;
    {
        const bool branch_taken_0x1bb604 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bb604) {
            ctx->pc = 0x1BB610u;
            goto label_1bb610;
        }
    }
    ctx->pc = 0x1BB60Cu;
    // 0x1bb60c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bb60cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1bb610:
    // 0x1bb610: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1bb610u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bb614: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x1bb614u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x1bb618: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1bb618u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bb61c: 0xacc50008  sw          $a1, 0x8($a2)
    ctx->pc = 0x1bb61cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 5));
    // 0x1bb620: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1bb620u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1bb624: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb628: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb628u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb62c: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1bb62cu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1bb630: 0xe4c00010  swc1        $f0, 0x10($a2)
    ctx->pc = 0x1bb630u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 16), bits); }
    // 0x1bb634: 0xa0226650  sb          $v0, 0x6650($at)
    ctx->pc = 0x1bb634u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bb638: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb638u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb63c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB63Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB63Cu;
            // 0x1bb640: 0xac226654  sw          $v0, 0x6654($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26196), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB5E8u: goto label_1bb5e8;
            case 0x1BB610u: goto label_1bb610;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB644u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
