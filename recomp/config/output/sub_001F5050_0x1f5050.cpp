#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F5050
// Address: 0x1f5050 - 0x1f50e4
void sub_001F5050_0x1f5050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F5050_0x1f5050");
#endif

    switch (ctx->pc) {
        case 0x1f5084u: goto label_1f5084;
        case 0x1f5098u: goto label_1f5098;
        default: break;
    }

    ctx->pc = 0x1f5050u;

    // 0x1f5050: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f5050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f5054: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1f5054u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1f5058: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f5058u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f505c: 0x244257d0  addiu       $v0, $v0, 0x57D0
    ctx->pc = 0x1f505cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22480));
    // 0x1f5060: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f5060u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f5064: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5064u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5068: 0xac22ec70  sw          $v0, -0x1390($at)
    ctx->pc = 0x1f5068u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962288), GPR_U32(ctx, 2));
    // 0x1f506c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f506cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5070: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5070u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5074: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f5074u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5078: 0x8c24ec70  lw          $a0, -0x1390($at)
    ctx->pc = 0x1f5078u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962288)));
    // 0x1f507c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F507Cu;
    SET_GPR_U32(ctx, 31, 0x1F5084u);
    ctx->pc = 0x1F5080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F507Cu;
            // 0x1f5080: 0x24060300  addiu       $a2, $zero, 0x300 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5084u; }
        if (ctx->pc != 0x1F5084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5084u; }
        if (ctx->pc != 0x1F5084u) { return; }
    }
    ctx->pc = 0x1F5084u;
label_1f5084:
    // 0x1f5084: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5084u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5088: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f5088u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f508c: 0x8c25ec70  lw          $a1, -0x1390($at)
    ctx->pc = 0x1f508cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962288)));
    // 0x1f5090: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F5090u;
    SET_GPR_U32(ctx, 31, 0x1F5098u);
    ctx->pc = 0x1F5094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5090u;
            // 0x1f5094: 0x240602ff  addiu       $a2, $zero, 0x2FF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 767));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5098u; }
        if (ctx->pc != 0x1F5098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5098u; }
        if (ctx->pc != 0x1F5098u) { return; }
    }
    ctx->pc = 0x1F5098u;
label_1f5098:
    // 0x1f5098: 0x441000c  bgez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1F5098u;
    {
        const bool branch_taken_0x1f5098 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F509Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5098u;
            // 0x1f509c: 0x3c010035  lui         $at, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5098) {
            ctx->pc = 0x1F50CCu;
            goto label_1f50cc;
        }
    }
    ctx->pc = 0x1F50A0u;
    // 0x1f50a0: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f50a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f50a4: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f50a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f50a8: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f50a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f50ac: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f50acu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f50b0: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f50b0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f50b4: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f50b4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f50b8: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f50b8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f50bc: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f50bcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f50c0: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f50c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f50c4: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f50c4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f50c8: 0xa600000a  sh          $zero, 0xA($s0)
    ctx->pc = 0x1f50c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f50cc:
    // 0x1f50cc: 0x2402ffc6  addiu       $v0, $zero, -0x3A
    ctx->pc = 0x1f50ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967238));
    // 0x1f50d0: 0xa0205acf  sb          $zero, 0x5ACF($at)
    ctx->pc = 0x1f50d0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 23247), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f50d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f50d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f50d8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f50d8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f50dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1F50DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F50E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F50DCu;
            // 0x1f50e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F5084u: goto label_1f5084;
            case 0x1F5098u: goto label_1f5098;
            case 0x1F50CCu: goto label_1f50cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F50E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
