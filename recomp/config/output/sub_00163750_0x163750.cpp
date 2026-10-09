#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163750
// Address: 0x163750 - 0x1637e8
void sub_00163750_0x163750(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163750_0x163750");
#endif

    switch (ctx->pc) {
        case 0x1637b8u: goto label_1637b8;
        case 0x1637c8u: goto label_1637c8;
        case 0x1637d0u: goto label_1637d0;
        default: break;
    }

    ctx->pc = 0x163750u;

    // 0x163750: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x163750u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x163754: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163754u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163758: 0x3c100027  lui         $s0, 0x27
    ctx->pc = 0x163758u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)39 << 16));
    // 0x16375c: 0x26100640  addiu       $s0, $s0, 0x640
    ctx->pc = 0x16375cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1600));
    // 0x163760: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163760u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163764: 0xffa50048  sd          $a1, 0x48($sp)
    ctx->pc = 0x163764u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 5));
    // 0x163768: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x163768u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16376c: 0xffa60050  sd          $a2, 0x50($sp)
    ctx->pc = 0x16376cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 6));
    // 0x163770: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x163770u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x163774: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x163774u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163778: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x163778u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16377c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x16377cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x163780: 0xffa70058  sd          $a3, 0x58($sp)
    ctx->pc = 0x163780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 7));
    // 0x163784: 0xffa80060  sd          $t0, 0x60($sp)
    ctx->pc = 0x163784u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 8));
    // 0x163788: 0xffa90068  sd          $t1, 0x68($sp)
    ctx->pc = 0x163788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 9));
    // 0x16378c: 0xffaa0070  sd          $t2, 0x70($sp)
    ctx->pc = 0x16378cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 10));
    // 0x163790: 0xffab0078  sd          $t3, 0x78($sp)
    ctx->pc = 0x163790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 11));
    // 0x163794: 0xe7ac0028  swc1        $f12, 0x28($sp)
    ctx->pc = 0x163794u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x163798: 0xe7ad002c  swc1        $f13, 0x2C($sp)
    ctx->pc = 0x163798u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
    // 0x16379c: 0xe7ae0030  swc1        $f14, 0x30($sp)
    ctx->pc = 0x16379cu;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x1637a0: 0xe7af0034  swc1        $f15, 0x34($sp)
    ctx->pc = 0x1637a0u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 52), bits); }
    // 0x1637a4: 0xe7b00038  swc1        $f16, 0x38($sp)
    ctx->pc = 0x1637a4u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 56), bits); }
    // 0x1637a8: 0xe7b1003c  swc1        $f17, 0x3C($sp)
    ctx->pc = 0x1637a8u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 60), bits); }
    // 0x1637ac: 0xe7b20040  swc1        $f18, 0x40($sp)
    ctx->pc = 0x1637acu;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x1637b0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1637B0u;
    SET_GPR_U32(ctx, 31, 0x1637B8u);
    ctx->pc = 0x1637B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1637B0u;
            // 0x1637b4: 0xe7b30044  swc1        $f19, 0x44($sp) (Delay Slot)
        { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1637B8u; }
        if (ctx->pc != 0x1637B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1637B8u; }
        if (ctx->pc != 0x1637B8u) { return; }
    }
    ctx->pc = 0x1637B8u;
label_1637b8:
    // 0x1637b8: 0x27a60048  addiu       $a2, $sp, 0x48
    ctx->pc = 0x1637b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
    // 0x1637bc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1637bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1637c0: 0xc043e20  jal         func_10F880
    ctx->pc = 0x1637C0u;
    SET_GPR_U32(ctx, 31, 0x1637C8u);
    ctx->pc = 0x1637C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1637C0u;
            // 0x1637c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F880u;
    if (runtime->hasFunction(0x10F880u)) {
        auto targetFn = runtime->lookupFunction(0x10F880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1637C8u; }
        if (ctx->pc != 0x1637C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F880_0x10f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1637C8u; }
        if (ctx->pc != 0x1637C8u) { return; }
    }
    ctx->pc = 0x1637C8u;
label_1637c8:
    // 0x1637c8: 0xc058e06  jal         func_163818
    ctx->pc = 0x1637C8u;
    SET_GPR_U32(ctx, 31, 0x1637D0u);
    ctx->pc = 0x1637CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1637C8u;
            // 0x1637cc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163818u;
    if (runtime->hasFunction(0x163818u)) {
        auto targetFn = runtime->lookupFunction(0x163818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1637D0u; }
        if (ctx->pc != 0x1637D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163818_0x163818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1637D0u; }
        if (ctx->pc != 0x1637D0u) { return; }
    }
    ctx->pc = 0x1637D0u;
label_1637d0:
    // 0x1637d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1637d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1637d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1637d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1637d8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1637d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1637dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1637DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1637E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1637DCu;
            // 0x1637e0: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1637B8u: goto label_1637b8;
            case 0x1637C8u: goto label_1637c8;
            case 0x1637D0u: goto label_1637d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1637E4u;
    // 0x1637e4: 0x0  nop
    ctx->pc = 0x1637e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
