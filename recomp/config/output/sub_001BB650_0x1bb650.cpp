#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB650
// Address: 0x1bb650 - 0x1bb6d8
void sub_001BB650_0x1bb650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB650_0x1bb650");
#endif

    ctx->pc = 0x1bb650u;

    // 0x1bb650: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb650u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb654: 0x3c060031  lui         $a2, 0x31
    ctx->pc = 0x1bb654u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49 << 16));
    // 0x1bb658: 0x90236650  lbu         $v1, 0x6650($at)
    ctx->pc = 0x1bb658u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26192)));
    // 0x1bb65c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1bb65cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bb660: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BB660u;
    {
        const bool branch_taken_0x1bb660 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BB664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB660u;
            // 0x1bb664: 0x24c66650  addiu       $a2, $a2, 0x6650 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb660) {
            ctx->pc = 0x1BB678u;
            goto label_1bb678;
        }
    }
    ctx->pc = 0x1BB668u;
    // 0x1bb668: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb668u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb66c: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BB66Cu;
    {
        const bool branch_taken_0x1bb66c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BB670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB66Cu;
            // 0x1bb670: 0x3c023f80  lui         $v0, 0x3F80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb66c) {
            ctx->pc = 0x1BB678u;
            goto label_1bb678;
        }
    }
    ctx->pc = 0x1BB674u;
    // 0x1bb674: 0xacc2000c  sw          $v0, 0xC($a2)
    ctx->pc = 0x1bb674u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 2));
label_1bb678:
    // 0x1bb678: 0xacc50008  sw          $a1, 0x8($a2)
    ctx->pc = 0x1bb678u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 5));
    // 0x1bb67c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bb67cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bb680: 0x902243cc  lbu         $v0, 0x43CC($at)
    ctx->pc = 0x1bb680u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17356)));
    // 0x1bb684: 0x41c3c  dsll32      $v1, $a0, 16
    ctx->pc = 0x1bb684u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1bb688: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1bb688u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1bb68c: 0x431007  srav        $v0, $v1, $v0
    ctx->pc = 0x1bb68cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0x1bb690: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1bb690u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1bb694: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1bb694u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1bb698: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BB698u;
    {
        const bool branch_taken_0x1bb698 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bb698) {
            ctx->pc = 0x1BB6A4u;
            goto label_1bb6a4;
        }
    }
    ctx->pc = 0x1BB6A0u;
    // 0x1bb6a0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bb6a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1bb6a4:
    // 0x1bb6a4: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1bb6a4u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bb6a8: 0x3c02bf80  lui         $v0, 0xBF80
    ctx->pc = 0x1bb6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x1bb6ac: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1bb6acu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bb6b0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bb6b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bb6b4: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1bb6b4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1bb6b8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb6b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb6bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb6bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb6c0: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1bb6c0u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1bb6c4: 0xe4c00010  swc1        $f0, 0x10($a2)
    ctx->pc = 0x1bb6c4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 16), bits); }
    // 0x1bb6c8: 0xa0236650  sb          $v1, 0x6650($at)
    ctx->pc = 0x1bb6c8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bb6cc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb6ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb6d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB6D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB6D0u;
            // 0x1bb6d4: 0xac236654  sw          $v1, 0x6654($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26196), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB678u: goto label_1bb678;
            case 0x1BB6A4u: goto label_1bb6a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB6D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
