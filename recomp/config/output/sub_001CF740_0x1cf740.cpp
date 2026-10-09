#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF740
// Address: 0x1cf740 - 0x1cf7e0
void sub_001CF740_0x1cf740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF740_0x1cf740");
#endif

    switch (ctx->pc) {
        case 0x1cf764u: goto label_1cf764;
        case 0x1cf794u: goto label_1cf794;
        case 0x1cf7a8u: goto label_1cf7a8;
        default: break;
    }

    ctx->pc = 0x1cf740u;

    // 0x1cf740: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cf740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cf744: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    ctx->pc = 0x1cf744u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1cf748: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cf748u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cf74c: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1cf74cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1cf750: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cf750u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cf754: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1cf754u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf758: 0x3c100034  lui         $s0, 0x34
    ctx->pc = 0x1cf758u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)52 << 16));
    // 0x1cf75c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1CF75Cu;
    {
        const bool branch_taken_0x1cf75c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF75Cu;
            // 0x1cf760: 0x261013f0  addiu       $s0, $s0, 0x13F0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf75c) {
            ctx->pc = 0x1CF7BCu;
            goto label_1cf7bc;
        }
    }
    ctx->pc = 0x1CF764u;
label_1cf764:
    // 0x1cf764: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1cf764u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cf768: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1CF768u;
    {
        const bool branch_taken_0x1cf768 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf768) {
            ctx->pc = 0x1CF7B4u;
            goto label_1cf7b4;
        }
    }
    ctx->pc = 0x1CF770u;
    // 0x1cf770: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x1cf770u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1cf774: 0x1465000f  bne         $v1, $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x1CF774u;
    {
        const bool branch_taken_0x1cf774 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1cf774) {
            ctx->pc = 0x1CF7B4u;
            goto label_1cf7b4;
        }
    }
    ctx->pc = 0x1CF77Cu;
    // 0x1cf77c: 0x96030008  lhu         $v1, 0x8($s0)
    ctx->pc = 0x1cf77cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1cf780: 0x1464000c  bne         $v1, $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x1CF780u;
    {
        const bool branch_taken_0x1cf780 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1cf780) {
            ctx->pc = 0x1CF7B4u;
            goto label_1cf7b4;
        }
    }
    ctx->pc = 0x1CF788u;
    // 0x1cf788: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1cf788u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cf78c: 0xc06c6ec  jal         func_1B1BB0
    ctx->pc = 0x1CF78Cu;
    SET_GPR_U32(ctx, 31, 0x1CF794u);
    ctx->pc = 0x1CF790u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF78Cu;
            // 0x1cf790: 0x24440004  addiu       $a0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1BB0u;
    if (runtime->hasFunction(0x1B1BB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF794u; }
        if (ctx->pc != 0x1CF794u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1BB0_0x1b1bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF794u; }
        if (ctx->pc != 0x1CF794u) { return; }
    }
    ctx->pc = 0x1CF794u;
label_1cf794:
    // 0x1cf794: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1cf794u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cf798: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cf798u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf79c: 0x24060c80  addiu       $a2, $zero, 0xC80
    ctx->pc = 0x1cf79cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3200));
    // 0x1cf7a0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CF7A0u;
    SET_GPR_U32(ctx, 31, 0x1CF7A8u);
    ctx->pc = 0x1CF7A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF7A0u;
            // 0x1cf7a4: 0x24440004  addiu       $a0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF7A8u; }
        if (ctx->pc != 0x1CF7A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF7A8u; }
        if (ctx->pc != 0x1CF7A8u) { return; }
    }
    ctx->pc = 0x1CF7A8u;
label_1cf7a8:
    // 0x1cf7a8: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1cf7a8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cf7ac: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1CF7ACu;
    {
        const bool branch_taken_0x1cf7ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF7ACu;
            // 0x1cf7b0: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf7ac) {
            ctx->pc = 0x1CF7C8u;
            goto label_1cf7c8;
        }
    }
    ctx->pc = 0x1CF7B4u;
label_1cf7b4:
    // 0x1cf7b4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1cf7b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1cf7b8: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x1cf7b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
label_1cf7bc:
    // 0x1cf7bc: 0x28c30004  slti        $v1, $a2, 0x4
    ctx->pc = 0x1cf7bcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1cf7c0: 0x1460ffe8  bnez        $v1, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1CF7C0u;
    {
        const bool branch_taken_0x1cf7c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf7c0) {
            ctx->pc = 0x1CF764u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cf764;
        }
    }
    ctx->pc = 0x1CF7C8u;
label_1cf7c8:
    // 0x1cf7c8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cf7c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cf7cc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cf7ccu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cf7d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF7D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CF7D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF7D0u;
            // 0x1cf7d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF764u: goto label_1cf764;
            case 0x1CF794u: goto label_1cf794;
            case 0x1CF7A8u: goto label_1cf7a8;
            case 0x1CF7B4u: goto label_1cf7b4;
            case 0x1CF7BCu: goto label_1cf7bc;
            case 0x1CF7C8u: goto label_1cf7c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF7D8u;
    // 0x1cf7d8: 0x0  nop
    ctx->pc = 0x1cf7d8u;
    // NOP
    // 0x1cf7dc: 0x0  nop
    ctx->pc = 0x1cf7dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
