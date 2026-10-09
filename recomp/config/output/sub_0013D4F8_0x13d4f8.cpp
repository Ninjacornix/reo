#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D4F8
// Address: 0x13d4f8 - 0x13d588
void sub_0013D4F8_0x13d4f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D4F8_0x13d4f8");
#endif

    switch (ctx->pc) {
        case 0x13d558u: goto label_13d558;
        case 0x13d574u: goto label_13d574;
        default: break;
    }

    ctx->pc = 0x13d4f8u;

    // 0x13d4f8: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x13d4f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x13d4fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13d4fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13d500: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13d500u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13d504: 0x2610dff0  addiu       $s0, $s0, -0x2010
    ctx->pc = 0x13d504u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959088));
    // 0x13d508: 0xffa50038  sd          $a1, 0x38($sp)
    ctx->pc = 0x13d508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 5));
    // 0x13d50c: 0xffa60040  sd          $a2, 0x40($sp)
    ctx->pc = 0x13d50cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 6));
    // 0x13d510: 0x27a60038  addiu       $a2, $sp, 0x38
    ctx->pc = 0x13d510u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x13d514: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x13d514u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d518: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13d518u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d51c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x13d51cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13d520: 0xffa70048  sd          $a3, 0x48($sp)
    ctx->pc = 0x13d520u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 7));
    // 0x13d524: 0xffa80050  sd          $t0, 0x50($sp)
    ctx->pc = 0x13d524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 8));
    // 0x13d528: 0xffa90058  sd          $t1, 0x58($sp)
    ctx->pc = 0x13d528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 9));
    // 0x13d52c: 0xffaa0060  sd          $t2, 0x60($sp)
    ctx->pc = 0x13d52cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 10));
    // 0x13d530: 0xffab0068  sd          $t3, 0x68($sp)
    ctx->pc = 0x13d530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 11));
    // 0x13d534: 0xe7ac0018  swc1        $f12, 0x18($sp)
    ctx->pc = 0x13d534u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 24), bits); }
    // 0x13d538: 0xe7ad001c  swc1        $f13, 0x1C($sp)
    ctx->pc = 0x13d538u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 28), bits); }
    // 0x13d53c: 0xe7ae0020  swc1        $f14, 0x20($sp)
    ctx->pc = 0x13d53cu;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x13d540: 0xe7af0024  swc1        $f15, 0x24($sp)
    ctx->pc = 0x13d540u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 36), bits); }
    // 0x13d544: 0xe7b00028  swc1        $f16, 0x28($sp)
    ctx->pc = 0x13d544u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x13d548: 0xe7b1002c  swc1        $f17, 0x2C($sp)
    ctx->pc = 0x13d548u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
    // 0x13d54c: 0xe7b20030  swc1        $f18, 0x30($sp)
    ctx->pc = 0x13d54cu;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x13d550: 0xc043e20  jal         func_10F880
    ctx->pc = 0x13D550u;
    SET_GPR_U32(ctx, 31, 0x13D558u);
    ctx->pc = 0x13D554u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D550u;
            // 0x13d554: 0xe7b30034  swc1        $f19, 0x34($sp) (Delay Slot)
        { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 52), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F880u;
    if (runtime->hasFunction(0x10F880u)) {
        auto targetFn = runtime->lookupFunction(0x10F880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D558u; }
        if (ctx->pc != 0x13D558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F880_0x10f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D558u; }
        if (ctx->pc != 0x13D558u) { return; }
    }
    ctx->pc = 0x13D558u;
label_13d558:
    // 0x13d558: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13d558u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13d55c: 0x8c63dfe8  lw          $v1, -0x2018($v1)
    ctx->pc = 0x13d55cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294959080)));
    // 0x13d560: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x13D560u;
    {
        const bool branch_taken_0x13d560 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D560u;
            // 0x13d564: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d560) {
            ctx->pc = 0x13D574u;
            goto label_13d574;
        }
    }
    ctx->pc = 0x13D568u;
    // 0x13d568: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13d568u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13d56c: 0x60f809  jalr        $v1
    ctx->pc = 0x13D56Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x13D574u);
        ctx->pc = 0x13D570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D56Cu;
            // 0x13d570: 0x8c44dfec  lw          $a0, -0x2014($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294959084)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13D574u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D558u: goto label_13d558;
            case 0x13D574u: goto label_13d574;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13D574u; }
            if (ctx->pc != 0x13D574u) { return; }
        }
        }
    }
    ctx->pc = 0x13D574u;
label_13d574:
    // 0x13d574: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13d574u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d578: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13d578u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d57c: 0x3e00008  jr          $ra
    ctx->pc = 0x13D57Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D57Cu;
            // 0x13d580: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D558u: goto label_13d558;
            case 0x13D574u: goto label_13d574;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D584u;
    // 0x13d584: 0x0  nop
    ctx->pc = 0x13d584u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
