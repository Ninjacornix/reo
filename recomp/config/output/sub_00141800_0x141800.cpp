#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141800
// Address: 0x141800 - 0x1418a8
void sub_00141800_0x141800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141800_0x141800");
#endif

    switch (ctx->pc) {
        case 0x141868u: goto label_141868;
        case 0x141878u: goto label_141878;
        case 0x141894u: goto label_141894;
        default: break;
    }

    ctx->pc = 0x141800u;

    // 0x141800: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x141800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x141804: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141808: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x141808u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x14180c: 0x2610a638  addiu       $s0, $s0, -0x59C8
    ctx->pc = 0x14180cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294944312));
    // 0x141810: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141810u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141814: 0xffa50048  sd          $a1, 0x48($sp)
    ctx->pc = 0x141814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 5));
    // 0x141818: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x141818u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14181c: 0xffa60050  sd          $a2, 0x50($sp)
    ctx->pc = 0x14181cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 6));
    // 0x141820: 0x24060080  addiu       $a2, $zero, 0x80
    ctx->pc = 0x141820u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x141824: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x141824u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141828: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x141828u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14182c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x14182cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x141830: 0xffa70058  sd          $a3, 0x58($sp)
    ctx->pc = 0x141830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 7));
    // 0x141834: 0xffa80060  sd          $t0, 0x60($sp)
    ctx->pc = 0x141834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 8));
    // 0x141838: 0xffa90068  sd          $t1, 0x68($sp)
    ctx->pc = 0x141838u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 9));
    // 0x14183c: 0xffaa0070  sd          $t2, 0x70($sp)
    ctx->pc = 0x14183cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 10));
    // 0x141840: 0xffab0078  sd          $t3, 0x78($sp)
    ctx->pc = 0x141840u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 11));
    // 0x141844: 0xe7ac0028  swc1        $f12, 0x28($sp)
    ctx->pc = 0x141844u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x141848: 0xe7ad002c  swc1        $f13, 0x2C($sp)
    ctx->pc = 0x141848u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
    // 0x14184c: 0xe7ae0030  swc1        $f14, 0x30($sp)
    ctx->pc = 0x14184cu;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x141850: 0xe7af0034  swc1        $f15, 0x34($sp)
    ctx->pc = 0x141850u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 52), bits); }
    // 0x141854: 0xe7b00038  swc1        $f16, 0x38($sp)
    ctx->pc = 0x141854u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 56), bits); }
    // 0x141858: 0xe7b1003c  swc1        $f17, 0x3C($sp)
    ctx->pc = 0x141858u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 60), bits); }
    // 0x14185c: 0xe7b20040  swc1        $f18, 0x40($sp)
    ctx->pc = 0x14185cu;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x141860: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x141860u;
    SET_GPR_U32(ctx, 31, 0x141868u);
    ctx->pc = 0x141864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141860u;
            // 0x141864: 0xe7b30044  swc1        $f19, 0x44($sp) (Delay Slot)
        { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141868u; }
        if (ctx->pc != 0x141868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141868u; }
        if (ctx->pc != 0x141868u) { return; }
    }
    ctx->pc = 0x141868u;
label_141868:
    // 0x141868: 0x27a60048  addiu       $a2, $sp, 0x48
    ctx->pc = 0x141868u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
    // 0x14186c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x14186cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141870: 0xc043e20  jal         func_10F880
    ctx->pc = 0x141870u;
    SET_GPR_U32(ctx, 31, 0x141878u);
    ctx->pc = 0x141874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141870u;
            // 0x141874: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F880u;
    if (runtime->hasFunction(0x10F880u)) {
        auto targetFn = runtime->lookupFunction(0x10F880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141878u; }
        if (ctx->pc != 0x141878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F880_0x10f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141878u; }
        if (ctx->pc != 0x141878u) { return; }
    }
    ctx->pc = 0x141878u;
label_141878:
    // 0x141878: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x141878u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x14187c: 0x244249f0  addiu       $v0, $v0, 0x49F0
    ctx->pc = 0x14187cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18928));
    // 0x141880: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x141880u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x141884: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x141884u;
    {
        const bool branch_taken_0x141884 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x141888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141884u;
            // 0x141888: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141884) {
            ctx->pc = 0x141894u;
            goto label_141894;
        }
    }
    ctx->pc = 0x14188Cu;
    // 0x14188c: 0x60f809  jalr        $v1
    ctx->pc = 0x14188Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x141894u);
        ctx->pc = 0x141890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14188Cu;
            // 0x141890: 0x8c440004  lw          $a0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141894u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141868u: goto label_141868;
            case 0x141878u: goto label_141878;
            case 0x141894u: goto label_141894;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141894u; }
            if (ctx->pc != 0x141894u) { return; }
        }
        }
    }
    ctx->pc = 0x141894u;
label_141894:
    // 0x141894: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141894u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141898: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141898u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14189c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x14189cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1418a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1418A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1418A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1418A0u;
            // 0x1418a4: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141868u: goto label_141868;
            case 0x141878u: goto label_141878;
            case 0x141894u: goto label_141894;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1418A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
