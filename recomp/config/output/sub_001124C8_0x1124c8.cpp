#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001124C8
// Address: 0x1124c8 - 0x112568
void sub_001124C8_0x1124c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001124C8_0x1124c8");
#endif

    switch (ctx->pc) {
        case 0x1124e0u: goto label_1124e0;
        default: break;
    }

    ctx->pc = 0x1124c8u;

    // 0x1124c8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1124c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1124cc: 0xffa40020  sd          $a0, 0x20($sp)
    ctx->pc = 0x1124ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 4));
    // 0x1124d0: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1124d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1124d4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1124d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1124d8: 0xc044674  jal         func_1119D0
    ctx->pc = 0x1124D8u;
    SET_GPR_U32(ctx, 31, 0x1124E0u);
    ctx->pc = 0x1124DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1124D8u;
            // 0x1124dc: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1124E0u; }
        if (ctx->pc != 0x1124E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1124E0u; }
        if (ctx->pc != 0x1124E0u) { return; }
    }
    ctx->pc = 0x1124E0u;
label_1124e0:
    // 0x1124e0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1124e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1124e4: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1124e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1124e8: 0x38830002  xori        $v1, $a0, 0x2
    ctx->pc = 0x1124e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)2);
    // 0x1124ec: 0x1060001b  beqz        $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1124ECu;
    {
        const bool branch_taken_0x1124ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1124F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1124ECu;
            // 0x1124f0: 0x2c850002  sltiu       $a1, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1124ec) {
            ctx->pc = 0x11255Cu;
            goto label_11255c;
        }
    }
    ctx->pc = 0x1124F4u;
    // 0x1124f4: 0x14a0001a  bnez        $a1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1124F4u;
    {
        const bool branch_taken_0x1124f4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1124F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1124F4u;
            // 0x1124f8: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1124f4) {
            ctx->pc = 0x112560u;
            goto label_112560;
        }
    }
    ctx->pc = 0x1124FCu;
    // 0x1124fc: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x1124fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x112500: 0x14600017  bnez        $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x112500u;
    {
        const bool branch_taken_0x112500 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x112504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112500u;
            // 0x112504: 0x38830004  xori        $v1, $a0, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x112500) {
            ctx->pc = 0x112560u;
            goto label_112560;
        }
    }
    ctx->pc = 0x112508u;
    // 0x112508: 0x10600015  beqz        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x112508u;
    {
        const bool branch_taken_0x112508 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11250Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112508u;
            // 0x11250c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112508) {
            ctx->pc = 0x112560u;
            goto label_112560;
        }
    }
    ctx->pc = 0x112510u;
    // 0x112510: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x112510u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x112514: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x112514u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112518: 0x4800011  bltz        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x112518u;
    {
        const bool branch_taken_0x112518 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x11251Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112518u;
            // 0x11251c: 0x28830020  slti        $v1, $a0, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x112518) {
            ctx->pc = 0x112560u;
            goto label_112560;
        }
    }
    ctx->pc = 0x112520u;
    // 0x112520: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x112520u;
    {
        const bool branch_taken_0x112520 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x112524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112520u;
            // 0x112524: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112520) {
            ctx->pc = 0x112560u;
            goto label_112560;
        }
    }
    ctx->pc = 0x112528u;
    // 0x112528: 0x2882003d  slti        $v0, $a0, 0x3D
    ctx->pc = 0x112528u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)61) ? 1 : 0);
    // 0x11252c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11252Cu;
    {
        const bool branch_taken_0x11252c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x112530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11252Cu;
            // 0x112530: 0x2403003c  addiu       $v1, $zero, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11252c) {
            ctx->pc = 0x112548u;
            goto label_112548;
        }
    }
    ctx->pc = 0x112534u;
    // 0x112534: 0xdfa20010  ld          $v0, 0x10($sp)
    ctx->pc = 0x112534u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x112538: 0x2483ffc4  addiu       $v1, $a0, -0x3C
    ctx->pc = 0x112538u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967236));
    // 0x11253c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11253Cu;
    {
        const bool branch_taken_0x11253c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11253Cu;
            // 0x112540: 0x621014  dsllv       $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (GPR_U32(ctx, 3) & 0x3F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11253c) {
            ctx->pc = 0x112554u;
            goto label_112554;
        }
    }
    ctx->pc = 0x112544u;
    // 0x112544: 0x0  nop
    ctx->pc = 0x112544u;
    // NOP
label_112548:
    // 0x112548: 0xdfa20010  ld          $v0, 0x10($sp)
    ctx->pc = 0x112548u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11254c: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x11254cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x112550: 0x621016  dsrlv       $v0, $v0, $v1
    ctx->pc = 0x112550u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (GPR_U32(ctx, 3) & 0x3F));
label_112554:
    // 0x112554: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x112554u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x112558: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x112558u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
label_11255c:
    // 0x11255c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11255cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_112560:
    // 0x112560: 0x3e00008  jr          $ra
    ctx->pc = 0x112560u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112560u;
            // 0x112564: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1124E0u: goto label_1124e0;
            case 0x112548u: goto label_112548;
            case 0x112554u: goto label_112554;
            case 0x11255Cu: goto label_11255c;
            case 0x112560u: goto label_112560;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112568u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
