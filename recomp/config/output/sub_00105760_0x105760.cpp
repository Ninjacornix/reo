#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00105760
// Address: 0x105760 - 0x1057b4
void sub_00105760_0x105760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00105760_0x105760");
#endif

    switch (ctx->pc) {
        case 0x1057a8u: goto label_1057a8;
        default: break;
    }

    ctx->pc = 0x105760u;

    // 0x105760: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x105760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x105764: 0xffa60030  sd          $a2, 0x30($sp)
    ctx->pc = 0x105764u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 6));
    // 0x105768: 0x27a60030  addiu       $a2, $sp, 0x30
    ctx->pc = 0x105768u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x10576c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10576cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x105770: 0xffa70038  sd          $a3, 0x38($sp)
    ctx->pc = 0x105770u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 7));
    // 0x105774: 0xffa80040  sd          $t0, 0x40($sp)
    ctx->pc = 0x105774u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 8));
    // 0x105778: 0xffa90048  sd          $t1, 0x48($sp)
    ctx->pc = 0x105778u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 9));
    // 0x10577c: 0xffaa0050  sd          $t2, 0x50($sp)
    ctx->pc = 0x10577cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 10));
    // 0x105780: 0xffab0058  sd          $t3, 0x58($sp)
    ctx->pc = 0x105780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 11));
    // 0x105784: 0xe7ac0010  swc1        $f12, 0x10($sp)
    ctx->pc = 0x105784u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x105788: 0xe7ad0014  swc1        $f13, 0x14($sp)
    ctx->pc = 0x105788u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 20), bits); }
    // 0x10578c: 0xe7ae0018  swc1        $f14, 0x18($sp)
    ctx->pc = 0x10578cu;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 24), bits); }
    // 0x105790: 0xe7af001c  swc1        $f15, 0x1C($sp)
    ctx->pc = 0x105790u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 28), bits); }
    // 0x105794: 0xe7b00020  swc1        $f16, 0x20($sp)
    ctx->pc = 0x105794u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x105798: 0xe7b10024  swc1        $f17, 0x24($sp)
    ctx->pc = 0x105798u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 36), bits); }
    // 0x10579c: 0xe7b20028  swc1        $f18, 0x28($sp)
    ctx->pc = 0x10579cu;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x1057a0: 0xc04345a  jal         func_10D168
    ctx->pc = 0x1057A0u;
    SET_GPR_U32(ctx, 31, 0x1057A8u);
    ctx->pc = 0x1057A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1057A0u;
            // 0x1057a4: 0xe7b3002c  swc1        $f19, 0x2C($sp) (Delay Slot)
        { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D168u;
    if (runtime->hasFunction(0x10D168u)) {
        auto targetFn = runtime->lookupFunction(0x10D168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1057A8u; }
        if (ctx->pc != 0x1057A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D168_0x10d168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1057A8u; }
        if (ctx->pc != 0x1057A8u) { return; }
    }
    ctx->pc = 0x1057A8u;
label_1057a8:
    // 0x1057a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1057a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1057ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1057ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1057B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1057ACu;
            // 0x1057b0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1057A8u: goto label_1057a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1057B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
