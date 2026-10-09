#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F7160
// Address: 0x1f7160 - 0x1f71e0
void sub_001F7160_0x1f7160(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F7160_0x1f7160");
#endif

    switch (ctx->pc) {
        case 0x1f7188u: goto label_1f7188;
        case 0x1f719cu: goto label_1f719c;
        case 0x1f71b0u: goto label_1f71b0;
        case 0x1f71c4u: goto label_1f71c4;
        default: break;
    }

    ctx->pc = 0x1f7160u;

    // 0x1f7160: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f7160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f7164: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f7164u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f7168: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f7168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f716c: 0x2484f080  addiu       $a0, $a0, -0xF80
    ctx->pc = 0x1f716cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963328));
    // 0x1f7170: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f7170u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f7174: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f7174u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f7178: 0x3c100037  lui         $s0, 0x37
    ctx->pc = 0x1f7178u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)55 << 16));
    // 0x1f717c: 0x34068000  ori         $a2, $zero, 0x8000
    ctx->pc = 0x1f717cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1f7180: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F7180u;
    SET_GPR_U32(ctx, 31, 0x1F7188u);
    ctx->pc = 0x1F7184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7180u;
            // 0x1f7184: 0x2610f080  addiu       $s0, $s0, -0xF80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294963328));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7188u; }
        if (ctx->pc != 0x1F7188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7188u; }
        if (ctx->pc != 0x1F7188u) { return; }
    }
    ctx->pc = 0x1F7188u;
label_1f7188:
    // 0x1f7188: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f7188u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f718c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f718cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f7190: 0x24847080  addiu       $a0, $a0, 0x7080
    ctx->pc = 0x1f7190u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28800));
    // 0x1f7194: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F7194u;
    SET_GPR_U32(ctx, 31, 0x1F719Cu);
    ctx->pc = 0x1F7198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7194u;
            // 0x1f7198: 0x34068000  ori         $a2, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F719Cu; }
        if (ctx->pc != 0x1F719Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F719Cu; }
        if (ctx->pc != 0x1F719Cu) { return; }
    }
    ctx->pc = 0x1F719Cu;
label_1f719c:
    // 0x1f719c: 0x3c050031  lui         $a1, 0x31
    ctx->pc = 0x1f719cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49 << 16));
    // 0x1f71a0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f71a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f71a4: 0x24a565a8  addiu       $a1, $a1, 0x65A8
    ctx->pc = 0x1f71a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26024));
    // 0x1f71a8: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1F71A8u;
    SET_GPR_U32(ctx, 31, 0x1F71B0u);
    ctx->pc = 0x1F71ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F71A8u;
            // 0x1f71ac: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F71B0u; }
        if (ctx->pc != 0x1F71B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F71B0u; }
        if (ctx->pc != 0x1F71B0u) { return; }
    }
    ctx->pc = 0x1F71B0u;
label_1f71b0:
    // 0x1f71b0: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f71b0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f71b4: 0x2604000a  addiu       $a0, $s0, 0xA
    ctx->pc = 0x1f71b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 10));
    // 0x1f71b8: 0x24a59bf8  addiu       $a1, $a1, -0x6408
    ctx->pc = 0x1f71b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941688));
    // 0x1f71bc: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1F71BCu;
    SET_GPR_U32(ctx, 31, 0x1F71C4u);
    ctx->pc = 0x1F71C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F71BCu;
            // 0x1f71c0: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F71C4u; }
        if (ctx->pc != 0x1F71C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F71C4u; }
        if (ctx->pc != 0x1F71C4u) { return; }
    }
    ctx->pc = 0x1F71C4u;
label_1f71c4:
    // 0x1f71c4: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x1f71c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x1f71c8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f71c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f71cc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f71ccu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f71d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F71D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F71D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F71D0u;
            // 0x1f71d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F7188u: goto label_1f7188;
            case 0x1F719Cu: goto label_1f719c;
            case 0x1F71B0u: goto label_1f71b0;
            case 0x1F71C4u: goto label_1f71c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F71D8u;
    // 0x1f71d8: 0x0  nop
    ctx->pc = 0x1f71d8u;
    // NOP
    // 0x1f71dc: 0x0  nop
    ctx->pc = 0x1f71dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
