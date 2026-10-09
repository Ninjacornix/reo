#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F43C0
// Address: 0x1f43c0 - 0x1f44c0
void sub_001F43C0_0x1f43c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F43C0_0x1f43c0");
#endif

    switch (ctx->pc) {
        case 0x1f4418u: goto label_1f4418;
        case 0x1f4424u: goto label_1f4424;
        case 0x1f443cu: goto label_1f443c;
        case 0x1f4448u: goto label_1f4448;
        default: break;
    }

    ctx->pc = 0x1f43c0u;

    // 0x1f43c0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1f43c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1f43c4: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1f43c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1f43c8: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1f43c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1f43cc: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1f43ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1f43d0: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x1f43d0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f43d4: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1f43d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1f43d8: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1f43d8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f43dc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1f43dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1f43e0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1f43e0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f43e4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f43e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f43e8: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1f43e8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f43ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f43ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f43f0: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x1f43f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f43f4: 0x12800003  beqz        $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F43F4u;
    {
        const bool branch_taken_0x1f43f4 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F43F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F43F4u;
            // 0x1f43f8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f43f4) {
            ctx->pc = 0x1F4404u;
            goto label_1f4404;
        }
    }
    ctx->pc = 0x1F43FCu;
    // 0x1f43fc: 0x16600003  bnez        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F43FCu;
    {
        const bool branch_taken_0x1f43fc = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F43FCu;
            // 0x1f4400: 0x27a40070  addiu       $a0, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f43fc) {
            ctx->pc = 0x1F440Cu;
            goto label_1f440c;
        }
    }
    ctx->pc = 0x1F4404u;
label_1f4404:
    // 0x1f4404: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1F4404u;
    {
        const bool branch_taken_0x1f4404 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4404u;
            // 0x1f4408: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4404) {
            ctx->pc = 0x1F4494u;
            goto label_1f4494;
        }
    }
    ctx->pc = 0x1F440Cu;
label_1f440c:
    // 0x1f440c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f440cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4410: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F4410u;
    SET_GPR_U32(ctx, 31, 0x1F4418u);
    ctx->pc = 0x1F4414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4410u;
            // 0x1f4414: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4418u; }
        if (ctx->pc != 0x1F4418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4418u; }
        if (ctx->pc != 0x1F4418u) { return; }
    }
    ctx->pc = 0x1F4418u;
label_1f4418:
    // 0x1f4418: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f4418u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f441c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F441Cu;
    SET_GPR_U32(ctx, 31, 0x1F4424u);
    ctx->pc = 0x1F4420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F441Cu;
            // 0x1f4420: 0x8c247430  lw          $a0, 0x7430($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 29744)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4424u; }
        if (ctx->pc != 0x1F4424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4424u; }
        if (ctx->pc != 0x1F4424u) { return; }
    }
    ctx->pc = 0x1F4424u;
label_1f4424:
    // 0x1f4424: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f4424u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f4428: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f4428u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f442c: 0x8c247430  lw          $a0, 0x7430($at)
    ctx->pc = 0x1f442cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 29744)));
    // 0x1f4430: 0x27a50070  addiu       $a1, $sp, 0x70
    ctx->pc = 0x1f4430u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1f4434: 0xc07d0b0  jal         func_1F42C0
    ctx->pc = 0x1F4434u;
    SET_GPR_U32(ctx, 31, 0x1F443Cu);
    ctx->pc = 0x1F4438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4434u;
            // 0x1f4438: 0x24070010  addiu       $a3, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F42C0u;
    if (runtime->hasFunction(0x1F42C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F42C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F443Cu; }
        if (ctx->pc != 0x1F443Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F42C0_0x1f42c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F443Cu; }
        if (ctx->pc != 0x1F443Cu) { return; }
    }
    ctx->pc = 0x1F443Cu;
label_1f443c:
    // 0x1f443c: 0x32a500ff  andi        $a1, $s5, 0xFF
    ctx->pc = 0x1f443cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)255);
    // 0x1f4440: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1F4440u;
    {
        const bool branch_taken_0x1f4440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4440u;
            // 0x1f4444: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4440) {
            ctx->pc = 0x1F4478u;
            goto label_1f4478;
        }
    }
    ctx->pc = 0x1F4448u;
label_1f4448:
    // 0x1f4448: 0x92640000  lbu         $a0, 0x0($s3)
    ctx->pc = 0x1f4448u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1f444c: 0x5d1821  addu        $v1, $v0, $sp
    ctx->pc = 0x1f444cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1f4450: 0x90630070  lbu         $v1, 0x70($v1)
    ctx->pc = 0x1f4450u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 112)));
    // 0x1f4454: 0xa61021  addu        $v0, $a1, $a2
    ctx->pc = 0x1f4454u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1f4458: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x1f4458u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1f445c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1f445cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1f4460: 0x2048021  addu        $s0, $s0, $a0
    ctx->pc = 0x1f4460u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x1f4464: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1f4464u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1f4468: 0x831826  xor         $v1, $a0, $v1
    ctx->pc = 0x1f4468u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 3));
    // 0x1f446c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f446cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f4470: 0xa2820000  sb          $v0, 0x0($s4)
    ctx->pc = 0x1f4470u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4474: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1f4474u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_1f4478:
    // 0x1f4478: 0xd2102a  slt         $v0, $a2, $s2
    ctx->pc = 0x1f4478u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1f447c: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1F447Cu;
    {
        const bool branch_taken_0x1f447c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F447Cu;
            // 0x1f4480: 0x30c20007  andi        $v0, $a2, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)7);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f447c) {
            ctx->pc = 0x1F4448u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f4448;
        }
    }
    ctx->pc = 0x1F4484u;
    // 0x1f4484: 0x51200  sll         $v0, $a1, 8
    ctx->pc = 0x1f4484u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x1f4488: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1f4488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1f448c: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1f448cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1f4490: 0x32027fff  andi        $v0, $s0, 0x7FFF
    ctx->pc = 0x1f4490u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)32767);
label_1f4494:
    // 0x1f4494: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1f4494u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1f4498: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1f4498u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1f449c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1f449cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1f44a0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1f44a0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f44a4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1f44a4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f44a8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f44a8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f44ac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f44acu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f44b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F44B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F44B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F44B0u;
            // 0x1f44b4: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F4404u: goto label_1f4404;
            case 0x1F440Cu: goto label_1f440c;
            case 0x1F4418u: goto label_1f4418;
            case 0x1F4424u: goto label_1f4424;
            case 0x1F443Cu: goto label_1f443c;
            case 0x1F4448u: goto label_1f4448;
            case 0x1F4478u: goto label_1f4478;
            case 0x1F4494u: goto label_1f4494;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F44B8u;
    // 0x1f44b8: 0x0  nop
    ctx->pc = 0x1f44b8u;
    // NOP
    // 0x1f44bc: 0x0  nop
    ctx->pc = 0x1f44bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
