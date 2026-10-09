#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD080
// Address: 0x1cd080 - 0x1cd1c0
void sub_001CD080_0x1cd080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD080_0x1cd080");
#endif

    switch (ctx->pc) {
        case 0x1cd0a4u: goto label_1cd0a4;
        case 0x1cd0b4u: goto label_1cd0b4;
        case 0x1cd0d4u: goto label_1cd0d4;
        case 0x1cd170u: goto label_1cd170;
        case 0x1cd184u: goto label_1cd184;
        case 0x1cd194u: goto label_1cd194;
        default: break;
    }

    ctx->pc = 0x1cd080u;

label_1cd080:
    // 0x1cd080: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1cd080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1cd084: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1cd084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1cd088: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cd088u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cd08c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cd08cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cd090: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1cd090u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd094: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cd094u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cd098: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1cd098u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd09c: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1CD09Cu;
    {
        const bool branch_taken_0x1cd09c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD0A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD09Cu;
            // 0x1cd0a0: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd09c) {
            ctx->pc = 0x1CD0F4u;
            goto label_1cd0f4;
        }
    }
    ctx->pc = 0x1CD0A4u;
label_1cd0a4:
    // 0x1cd0a4: 0x2502821  addu        $a1, $s2, $s0
    ctx->pc = 0x1cd0a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x1cd0a8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1cd0a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd0ac: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1CD0ACu;
    {
        const bool branch_taken_0x1cd0ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD0B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD0ACu;
            // 0x1cd0b0: 0x24841640  addiu       $a0, $a0, 0x1640 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd0ac) {
            ctx->pc = 0x1CD0E4u;
            goto label_1cd0e4;
        }
    }
    ctx->pc = 0x1CD0B4u;
label_1cd0b4:
    // 0x1cd0b4: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1cd0b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1cd0b8: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CD0B8u;
    {
        const bool branch_taken_0x1cd0b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cd0b8) {
            ctx->pc = 0x1CD0DCu;
            goto label_1cd0dc;
        }
    }
    ctx->pc = 0x1CD0C0u;
    // 0x1cd0c0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1cd0c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1cd0c4: 0x14650005  bne         $v1, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CD0C4u;
    {
        const bool branch_taken_0x1cd0c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1cd0c4) {
            ctx->pc = 0x1CD0DCu;
            goto label_1cd0dc;
        }
    }
    ctx->pc = 0x1CD0CCu;
    // 0x1cd0cc: 0xc0732b4  jal         func_1CCAD0
    ctx->pc = 0x1CD0CCu;
    SET_GPR_U32(ctx, 31, 0x1CD0D4u);
    ctx->pc = 0x1CCAD0u;
    if (runtime->hasFunction(0x1CCAD0u)) {
        auto targetFn = runtime->lookupFunction(0x1CCAD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD0D4u; }
        if (ctx->pc != 0x1CD0D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCAD0_0x1ccad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD0D4u; }
        if (ctx->pc != 0x1CD0D4u) { return; }
    }
    ctx->pc = 0x1CD0D4u;
label_1cd0d4:
    // 0x1cd0d4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CD0D4u;
    {
        const bool branch_taken_0x1cd0d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD0D4u;
            // 0x1cd0d8: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd0d4) {
            ctx->pc = 0x1CD0F4u;
            goto label_1cd0f4;
        }
    }
    ctx->pc = 0x1CD0DCu;
label_1cd0dc:
    // 0x1cd0dc: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1cd0dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1cd0e0: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x1cd0e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
label_1cd0e4:
    // 0x1cd0e4: 0x28c30100  slti        $v1, $a2, 0x100
    ctx->pc = 0x1cd0e4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1cd0e8: 0x1460fff2  bnez        $v1, . + 4 + (-0xE << 2)
    ctx->pc = 0x1CD0E8u;
    {
        const bool branch_taken_0x1cd0e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cd0e8) {
            ctx->pc = 0x1CD0B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cd0b4;
        }
    }
    ctx->pc = 0x1CD0F0u;
    // 0x1cd0f0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cd0f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1cd0f4:
    // 0x1cd0f4: 0x211182a  slt         $v1, $s0, $s1
    ctx->pc = 0x1cd0f4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1cd0f8: 0x1460ffea  bnez        $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x1CD0F8u;
    {
        const bool branch_taken_0x1cd0f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD0FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD0F8u;
            // 0x1cd0fc: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd0f8) {
            ctx->pc = 0x1CD0A4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cd0a4;
        }
    }
    ctx->pc = 0x1CD100u;
    // 0x1cd100: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1cd100u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cd104: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cd104u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cd108: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cd108u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cd10c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cd10cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd110: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD110u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD110u;
            // 0x1cd114: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD080u: goto label_1cd080;
            case 0x1CD0A4u: goto label_1cd0a4;
            case 0x1CD0B4u: goto label_1cd0b4;
            case 0x1CD0D4u: goto label_1cd0d4;
            case 0x1CD0DCu: goto label_1cd0dc;
            case 0x1CD0E4u: goto label_1cd0e4;
            case 0x1CD0F4u: goto label_1cd0f4;
            case 0x1CD170u: goto label_1cd170;
            case 0x1CD184u: goto label_1cd184;
            case 0x1CD194u: goto label_1cd194;
            case 0x1CD19Cu: goto label_1cd19c;
            case 0x1CD1A4u: goto label_1cd1a4;
            case 0x1CD1B4u: goto label_1cd1b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD118u;
    // 0x1cd118: 0x0  nop
    ctx->pc = 0x1cd118u;
    // NOP
    // 0x1cd11c: 0x0  nop
    ctx->pc = 0x1cd11cu;
    // NOP
    // 0x1cd120: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1cd120u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1cd124: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1cd124u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1cd128: 0x420c0  sll         $a0, $a0, 3
    ctx->pc = 0x1cd128u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1cd12c: 0x24636640  addiu       $v1, $v1, 0x6640
    ctx->pc = 0x1cd12cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 26176));
    // 0x1cd130: 0x24426644  addiu       $v0, $v0, 0x6644
    ctx->pc = 0x1cd130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26180));
    // 0x1cd134: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1cd134u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1cd138: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1cd138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1cd13c: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1cd13cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd140: 0x8073420  j           func_1CD080
    ctx->pc = 0x1CD140u;
    ctx->pc = 0x1CD144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD140u;
            // 0x1cd144: 0x8c640000  lw          $a0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1cd080;
    ctx->pc = 0x1CD148u;
    // 0x1cd148: 0x0  nop
    ctx->pc = 0x1cd148u;
    // NOP
    // 0x1cd14c: 0x0  nop
    ctx->pc = 0x1cd14cu;
    // NOP
    // 0x1cd150: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cd150u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cd154: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1cd154u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cd158: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cd158u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cd15c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cd15cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cd160: 0x3c100034  lui         $s0, 0x34
    ctx->pc = 0x1cd160u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)52 << 16));
    // 0x1cd164: 0x26101640  addiu       $s0, $s0, 0x1640
    ctx->pc = 0x1cd164u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5696));
    // 0x1cd168: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1CD168u;
    {
        const bool branch_taken_0x1cd168 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD16Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD168u;
            // 0x1cd16c: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd168) {
            ctx->pc = 0x1CD1A4u;
            goto label_1cd1a4;
        }
    }
    ctx->pc = 0x1CD170u;
label_1cd170:
    // 0x1cd170: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1cd170u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cd174: 0x14640009  bne         $v1, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CD174u;
    {
        const bool branch_taken_0x1cd174 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1cd174) {
            ctx->pc = 0x1CD19Cu;
            goto label_1cd19c;
        }
    }
    ctx->pc = 0x1CD17Cu;
    // 0x1cd17c: 0xc07328c  jal         func_1CCA30
    ctx->pc = 0x1CD17Cu;
    SET_GPR_U32(ctx, 31, 0x1CD184u);
    ctx->pc = 0x1CD180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD17Cu;
            // 0x1cd180: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCA30u;
    if (runtime->hasFunction(0x1CCA30u)) {
        auto targetFn = runtime->lookupFunction(0x1CCA30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD184u; }
        if (ctx->pc != 0x1CD184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCA30_0x1cca30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD184u; }
        if (ctx->pc != 0x1CD184u) { return; }
    }
    ctx->pc = 0x1CD184u;
label_1cd184:
    // 0x1cd184: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1cd184u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd188: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cd188u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd18c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CD18Cu;
    SET_GPR_U32(ctx, 31, 0x1CD194u);
    ctx->pc = 0x1CD190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD18Cu;
            // 0x1cd190: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD194u; }
        if (ctx->pc != 0x1CD194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD194u; }
        if (ctx->pc != 0x1CD194u) { return; }
    }
    ctx->pc = 0x1CD194u;
label_1cd194:
    // 0x1cd194: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CD194u;
    {
        const bool branch_taken_0x1cd194 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD194u;
            // 0x1cd198: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd194) {
            ctx->pc = 0x1CD1B4u;
            goto label_1cd1b4;
        }
    }
    ctx->pc = 0x1CD19Cu;
label_1cd19c:
    // 0x1cd19c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1cd19cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1cd1a0: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x1cd1a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
label_1cd1a4:
    // 0x1cd1a4: 0x28a30100  slti        $v1, $a1, 0x100
    ctx->pc = 0x1cd1a4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1cd1a8: 0x1460fff1  bnez        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x1CD1A8u;
    {
        const bool branch_taken_0x1cd1a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cd1a8) {
            ctx->pc = 0x1CD170u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cd170;
        }
    }
    ctx->pc = 0x1CD1B0u;
    // 0x1cd1b0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cd1b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1cd1b4:
    // 0x1cd1b4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cd1b4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd1b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD1B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD1B8u;
            // 0x1cd1bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD080u: goto label_1cd080;
            case 0x1CD0A4u: goto label_1cd0a4;
            case 0x1CD0B4u: goto label_1cd0b4;
            case 0x1CD0D4u: goto label_1cd0d4;
            case 0x1CD0DCu: goto label_1cd0dc;
            case 0x1CD0E4u: goto label_1cd0e4;
            case 0x1CD0F4u: goto label_1cd0f4;
            case 0x1CD170u: goto label_1cd170;
            case 0x1CD184u: goto label_1cd184;
            case 0x1CD194u: goto label_1cd194;
            case 0x1CD19Cu: goto label_1cd19c;
            case 0x1CD1A4u: goto label_1cd1a4;
            case 0x1CD1B4u: goto label_1cd1b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD1C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
