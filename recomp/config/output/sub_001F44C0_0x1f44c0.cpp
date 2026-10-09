#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F44C0
// Address: 0x1f44c0 - 0x1f45b0
void sub_001F44C0_0x1f44c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F44C0_0x1f44c0");
#endif

    switch (ctx->pc) {
        case 0x1f450cu: goto label_1f450c;
        case 0x1f4518u: goto label_1f4518;
        case 0x1f4530u: goto label_1f4530;
        case 0x1f453cu: goto label_1f453c;
        default: break;
    }

    ctx->pc = 0x1f44c0u;

    // 0x1f44c0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1f44c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1f44c4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1f44c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1f44c8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1f44c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1f44cc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1f44ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1f44d0: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1f44d0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f44d4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1f44d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1f44d8: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1f44d8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f44dc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f44dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f44e0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1f44e0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f44e4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f44e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f44e8: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1f44e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f44ec: 0x16600003  bnez        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F44ECu;
    {
        const bool branch_taken_0x1f44ec = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F44F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F44ECu;
            // 0x1f44f0: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f44ec) {
            ctx->pc = 0x1F44FCu;
            goto label_1f44fc;
        }
    }
    ctx->pc = 0x1F44F4u;
    // 0x1f44f4: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1F44F4u;
    {
        const bool branch_taken_0x1f44f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F44F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F44F4u;
            // 0x1f44f8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f44f4) {
            ctx->pc = 0x1F4588u;
            goto label_1f4588;
        }
    }
    ctx->pc = 0x1F44FCu;
label_1f44fc:
    // 0x1f44fc: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1f44fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1f4500: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f4500u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4504: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F4504u;
    SET_GPR_U32(ctx, 31, 0x1F450Cu);
    ctx->pc = 0x1F4508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4504u;
            // 0x1f4508: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F450Cu; }
        if (ctx->pc != 0x1F450Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F450Cu; }
        if (ctx->pc != 0x1F450Cu) { return; }
    }
    ctx->pc = 0x1F450Cu;
label_1f450c:
    // 0x1f450c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f450cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f4510: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F4510u;
    SET_GPR_U32(ctx, 31, 0x1F4518u);
    ctx->pc = 0x1F4514u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4510u;
            // 0x1f4514: 0x8c247430  lw          $a0, 0x7430($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 29744)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4518u; }
        if (ctx->pc != 0x1F4518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4518u; }
        if (ctx->pc != 0x1F4518u) { return; }
    }
    ctx->pc = 0x1F4518u;
label_1f4518:
    // 0x1f4518: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f4518u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f451c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f451cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4520: 0x8c247430  lw          $a0, 0x7430($at)
    ctx->pc = 0x1f4520u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 29744)));
    // 0x1f4524: 0x27a50060  addiu       $a1, $sp, 0x60
    ctx->pc = 0x1f4524u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1f4528: 0xc07d0b0  jal         func_1F42C0
    ctx->pc = 0x1F4528u;
    SET_GPR_U32(ctx, 31, 0x1F4530u);
    ctx->pc = 0x1F452Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4528u;
            // 0x1f452c: 0x24070010  addiu       $a3, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F42C0u;
    if (runtime->hasFunction(0x1F42C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F42C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4530u; }
        if (ctx->pc != 0x1F4530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F42C0_0x1f42c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4530u; }
        if (ctx->pc != 0x1F4530u) { return; }
    }
    ctx->pc = 0x1F4530u;
label_1f4530:
    // 0x1f4530: 0x328500ff  andi        $a1, $s4, 0xFF
    ctx->pc = 0x1f4530u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
    // 0x1f4534: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1F4534u;
    {
        const bool branch_taken_0x1f4534 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4534u;
            // 0x1f4538: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4534) {
            ctx->pc = 0x1F456Cu;
            goto label_1f456c;
        }
    }
    ctx->pc = 0x1F453Cu;
label_1f453c:
    // 0x1f453c: 0x92640000  lbu         $a0, 0x0($s3)
    ctx->pc = 0x1f453cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1f4540: 0x2221821  addu        $v1, $s1, $v0
    ctx->pc = 0x1f4540u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1f4544: 0x30c20007  andi        $v0, $a2, 0x7
    ctx->pc = 0x1f4544u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)7);
    // 0x1f4548: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1f4548u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1f454c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1f454cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1f4550: 0x90420060  lbu         $v0, 0x60($v0)
    ctx->pc = 0x1f4550u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1f4554: 0x831826  xor         $v1, $a0, $v1
    ctx->pc = 0x1f4554u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 3));
    // 0x1f4558: 0x431026  xor         $v0, $v0, $v1
    ctx->pc = 0x1f4558u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x1f455c: 0xa2620000  sb          $v0, 0x0($s3)
    ctx->pc = 0x1f455cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4560: 0x92620000  lbu         $v0, 0x0($s3)
    ctx->pc = 0x1f4560u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1f4564: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1f4564u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1f4568: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1f4568u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1f456c:
    // 0x1f456c: 0xd2102a  slt         $v0, $a2, $s2
    ctx->pc = 0x1f456cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1f4570: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1F4570u;
    {
        const bool branch_taken_0x1f4570 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4570u;
            // 0x1f4574: 0xa61021  addu        $v0, $a1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4570) {
            ctx->pc = 0x1F453Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f453c;
        }
    }
    ctx->pc = 0x1F4578u;
    // 0x1f4578: 0x51200  sll         $v0, $a1, 8
    ctx->pc = 0x1f4578u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x1f457c: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1f457cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1f4580: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1f4580u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1f4584: 0x32027fff  andi        $v0, $s0, 0x7FFF
    ctx->pc = 0x1f4584u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)32767);
label_1f4588:
    // 0x1f4588: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1f4588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1f458c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1f458cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1f4590: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1f4590u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f4594: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1f4594u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f4598: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f4598u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f459c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f459cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f45a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F45A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F45A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F45A0u;
            // 0x1f45a4: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F44FCu: goto label_1f44fc;
            case 0x1F450Cu: goto label_1f450c;
            case 0x1F4518u: goto label_1f4518;
            case 0x1F4530u: goto label_1f4530;
            case 0x1F453Cu: goto label_1f453c;
            case 0x1F456Cu: goto label_1f456c;
            case 0x1F4588u: goto label_1f4588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F45A8u;
    // 0x1f45a8: 0x0  nop
    ctx->pc = 0x1f45a8u;
    // NOP
    // 0x1f45ac: 0x0  nop
    ctx->pc = 0x1f45acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
