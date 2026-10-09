#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108ED0
// Address: 0x108ed0 - 0x108f40
void sub_00108ED0_0x108ed0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108ED0_0x108ed0");
#endif

    switch (ctx->pc) {
        case 0x108f34u: goto label_108f34;
        default: break;
    }

    ctx->pc = 0x108ed0u;

    // 0x108ed0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x108ed0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x108ed4: 0x3c0c0021  lui         $t4, 0x21
    ctx->pc = 0x108ed4u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)33 << 16));
    // 0x108ed8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x108ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x108edc: 0xffa50038  sd          $a1, 0x38($sp)
    ctx->pc = 0x108edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 5));
    // 0x108ee0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x108ee0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108ee4: 0xffa60040  sd          $a2, 0x40($sp)
    ctx->pc = 0x108ee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 6));
    // 0x108ee8: 0x27a60038  addiu       $a2, $sp, 0x38
    ctx->pc = 0x108ee8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x108eec: 0xffa70048  sd          $a3, 0x48($sp)
    ctx->pc = 0x108eecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 7));
    // 0x108ef0: 0xffa80050  sd          $t0, 0x50($sp)
    ctx->pc = 0x108ef0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 8));
    // 0x108ef4: 0xffa90058  sd          $t1, 0x58($sp)
    ctx->pc = 0x108ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 9));
    // 0x108ef8: 0xffaa0060  sd          $t2, 0x60($sp)
    ctx->pc = 0x108ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 10));
    // 0x108efc: 0xffab0068  sd          $t3, 0x68($sp)
    ctx->pc = 0x108efcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 11));
    // 0x108f00: 0xe7ac0018  swc1        $f12, 0x18($sp)
    ctx->pc = 0x108f00u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 24), bits); }
    // 0x108f04: 0xe7ad001c  swc1        $f13, 0x1C($sp)
    ctx->pc = 0x108f04u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 28), bits); }
    // 0x108f08: 0xe7ae0020  swc1        $f14, 0x20($sp)
    ctx->pc = 0x108f08u;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x108f0c: 0xe7af0024  swc1        $f15, 0x24($sp)
    ctx->pc = 0x108f0cu;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 36), bits); }
    // 0x108f10: 0xe7b00028  swc1        $f16, 0x28($sp)
    ctx->pc = 0x108f10u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x108f14: 0xe7b1002c  swc1        $f17, 0x2C($sp)
    ctx->pc = 0x108f14u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
    // 0x108f18: 0xe7b20030  swc1        $f18, 0x30($sp)
    ctx->pc = 0x108f18u;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x108f1c: 0xe7b30034  swc1        $f19, 0x34($sp)
    ctx->pc = 0x108f1cu;
    { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 52), bits); }
    // 0x108f20: 0x8d8297f0  lw          $v0, -0x6810($t4)
    ctx->pc = 0x108f20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 4294940656)));
    // 0x108f24: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x108f24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x108f28: 0xac620054  sw          $v0, 0x54($v1)
    ctx->pc = 0x108f28u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 84), GPR_U32(ctx, 2));
    // 0x108f2c: 0xc04345a  jal         func_10D168
    ctx->pc = 0x108F2Cu;
    SET_GPR_U32(ctx, 31, 0x108F34u);
    ctx->pc = 0x108F30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108F2Cu;
            // 0x108f30: 0x8c440008  lw          $a0, 0x8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D168u;
    if (runtime->hasFunction(0x10D168u)) {
        auto targetFn = runtime->lookupFunction(0x10D168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108F34u; }
        if (ctx->pc != 0x108F34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D168_0x10d168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108F34u; }
        if (ctx->pc != 0x108F34u) { return; }
    }
    ctx->pc = 0x108F34u;
label_108f34:
    // 0x108f34: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x108f34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108f38: 0x3e00008  jr          $ra
    ctx->pc = 0x108F38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108F38u;
            // 0x108f3c: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F34u: goto label_108f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108F40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
