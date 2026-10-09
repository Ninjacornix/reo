#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4910
// Address: 0x1f4910 - 0x1f4a10
void sub_001F4910_0x1f4910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4910_0x1f4910");
#endif

    switch (ctx->pc) {
        case 0x1f493cu: goto label_1f493c;
        case 0x1f494cu: goto label_1f494c;
        case 0x1f4994u: goto label_1f4994;
        case 0x1f49b0u: goto label_1f49b0;
        case 0x1f49ccu: goto label_1f49cc;
        default: break;
    }

    ctx->pc = 0x1f4910u;

    // 0x1f4910: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1f4910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1f4914: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1f4914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1f4918: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1f4918u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1f491c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1f491cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1f4920: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1f4920u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4924: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1f4924u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1f4928: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1f4928u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f492c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f492cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f4930: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1f4930u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4934: 0xc07d20c  jal         func_1F4830
    ctx->pc = 0x1F4934u;
    SET_GPR_U32(ctx, 31, 0x1F493Cu);
    ctx->pc = 0x1F4938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4934u;
            // 0x1f4938: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4830u;
    if (runtime->hasFunction(0x1F4830u)) {
        auto targetFn = runtime->lookupFunction(0x1F4830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F493Cu; }
        if (ctx->pc != 0x1F493Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4830_0x1f4830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F493Cu; }
        if (ctx->pc != 0x1F493Cu) { return; }
    }
    ctx->pc = 0x1F493Cu;
label_1f493c:
    // 0x1f493c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f493cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f4940: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1f4940u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4944: 0xc07d20c  jal         func_1F4830
    ctx->pc = 0x1F4944u;
    SET_GPR_U32(ctx, 31, 0x1F494Cu);
    ctx->pc = 0x1F4948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4944u;
            // 0x1f4948: 0x2451fffe  addiu       $s1, $v0, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967294));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4830u;
    if (runtime->hasFunction(0x1F4830u)) {
        auto targetFn = runtime->lookupFunction(0x1F4830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F494Cu; }
        if (ctx->pc != 0x1F494Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4830_0x1f4830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F494Cu; }
        if (ctx->pc != 0x1F494Cu) { return; }
    }
    ctx->pc = 0x1F494Cu;
label_1f494c:
    // 0x1f494c: 0x3050ffff  andi        $s0, $v0, 0xFFFF
    ctx->pc = 0x1f494cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f4950: 0x96830034  lhu         $v1, 0x34($s4)
    ctx->pc = 0x1f4950u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 52)));
    // 0x1f4954: 0x8e820028  lw          $v0, 0x28($s4)
    ctx->pc = 0x1f4954u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 40)));
    // 0x1f4958: 0x6210003  bgez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4958u;
    {
        const bool branch_taken_0x1f4958 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1F495Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4958u;
            // 0x1f495c: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4958) {
            ctx->pc = 0x1F4968u;
            goto label_1f4968;
        }
    }
    ctx->pc = 0x1F4960u;
    // 0x1f4960: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1F4960u;
    {
        const bool branch_taken_0x1f4960 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4960u;
            // 0x1f4964: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4960) {
            ctx->pc = 0x1F49ECu;
            goto label_1f49ec;
        }
    }
    ctx->pc = 0x1F4968u;
label_1f4968:
    // 0x1f4968: 0x3231ffff  andi        $s1, $s1, 0xFFFF
    ctx->pc = 0x1f4968u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
    // 0x1f496c: 0x251082b  sltu        $at, $s2, $s1
    ctx->pc = 0x1f496cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x1f4970: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4970u;
    {
        const bool branch_taken_0x1f4970 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4970u;
            // 0x1f4974: 0x11082a  slt         $at, $zero, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4970) {
            ctx->pc = 0x1F4980u;
            goto label_1f4980;
        }
    }
    ctx->pc = 0x1F4978u;
    // 0x1f4978: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1F4978u;
    {
        const bool branch_taken_0x1f4978 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F497Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4978u;
            // 0x1f497c: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4978) {
            ctx->pc = 0x1F49ECu;
            goto label_1f49ec;
        }
    }
    ctx->pc = 0x1F4980u;
label_1f4980:
    // 0x1f4980: 0x10200005  beqz        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F4980u;
    {
        const bool branch_taken_0x1f4980 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4980u;
            // 0x1f4984: 0x2513023  subu        $a2, $s2, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4980) {
            ctx->pc = 0x1F4998u;
            goto label_1f4998;
        }
    }
    ctx->pc = 0x1F4988u;
    // 0x1f4988: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1f4988u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f498c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F498Cu;
    SET_GPR_U32(ctx, 31, 0x1F4994u);
    ctx->pc = 0x1F4990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F498Cu;
            // 0x1f4990: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4994u; }
        if (ctx->pc != 0x1F4994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4994u; }
        if (ctx->pc != 0x1F4994u) { return; }
    }
    ctx->pc = 0x1F4994u;
label_1f4994:
    // 0x1f4994: 0x2513023  subu        $a2, $s2, $s1
    ctx->pc = 0x1f4994u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
label_1f4998:
    // 0x1f4998: 0x6082a  slt         $at, $zero, $a2
    ctx->pc = 0x1f4998u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1f499c: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F499Cu;
    {
        const bool branch_taken_0x1f499c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F49A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F499Cu;
            // 0x1f49a0: 0x3222ffff  andi        $v0, $s1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f499c) {
            ctx->pc = 0x1F49B0u;
            goto label_1f49b0;
        }
    }
    ctx->pc = 0x1F49A4u;
    // 0x1f49a4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f49a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f49a8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F49A8u;
    SET_GPR_U32(ctx, 31, 0x1F49B0u);
    ctx->pc = 0x1F49ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F49A8u;
            // 0x1f49ac: 0x2622021  addu        $a0, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F49B0u; }
        if (ctx->pc != 0x1F49B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F49B0u; }
        if (ctx->pc != 0x1F49B0u) { return; }
    }
    ctx->pc = 0x1F49B0u;
label_1f49b0:
    // 0x1f49b0: 0x8e820024  lw          $v0, 0x24($s4)
    ctx->pc = 0x1f49b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 36)));
    // 0x1f49b4: 0x3232ffff  andi        $s2, $s1, 0xFFFF
    ctx->pc = 0x1f49b4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
    // 0x1f49b8: 0x96870040  lhu         $a3, 0x40($s4)
    ctx->pc = 0x1f49b8u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 64)));
    // 0x1f49bc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1f49bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f49c0: 0x90450005  lbu         $a1, 0x5($v0)
    ctx->pc = 0x1f49c0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 5)));
    // 0x1f49c4: 0xc07d130  jal         func_1F44C0
    ctx->pc = 0x1F49C4u;
    SET_GPR_U32(ctx, 31, 0x1F49CCu);
    ctx->pc = 0x1F49C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F49C4u;
            // 0x1f49c8: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F44C0u;
    if (runtime->hasFunction(0x1F44C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F44C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F49CCu; }
        if (ctx->pc != 0x1F49CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F44C0_0x1f44c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F49CCu; }
        if (ctx->pc != 0x1F49CCu) { return; }
    }
    ctx->pc = 0x1F49CCu;
label_1f49cc:
    // 0x1f49cc: 0x12020003  beq         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F49CCu;
    {
        const bool branch_taken_0x1f49cc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x1f49cc) {
            ctx->pc = 0x1F49DCu;
            goto label_1f49dc;
        }
    }
    ctx->pc = 0x1F49D4u;
    // 0x1f49d4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F49D4u;
    {
        const bool branch_taken_0x1f49d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F49D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F49D4u;
            // 0x1f49d8: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f49d4) {
            ctx->pc = 0x1F49ECu;
            goto label_1f49ec;
        }
    }
    ctx->pc = 0x1F49DCu;
label_1f49dc:
    // 0x1f49dc: 0x96830034  lhu         $v1, 0x34($s4)
    ctx->pc = 0x1f49dcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 52)));
    // 0x1f49e0: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x1f49e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f49e4: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1f49e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1f49e8: 0xa6830034  sh          $v1, 0x34($s4)
    ctx->pc = 0x1f49e8u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 52), (uint16_t)GPR_U32(ctx, 3));
label_1f49ec:
    // 0x1f49ec: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1f49ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1f49f0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1f49f0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1f49f4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1f49f4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f49f8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1f49f8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f49fc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f49fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f4a00: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f4a00u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4a04: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4A04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4A04u;
            // 0x1f4a08: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F493Cu: goto label_1f493c;
            case 0x1F494Cu: goto label_1f494c;
            case 0x1F4968u: goto label_1f4968;
            case 0x1F4980u: goto label_1f4980;
            case 0x1F4994u: goto label_1f4994;
            case 0x1F4998u: goto label_1f4998;
            case 0x1F49B0u: goto label_1f49b0;
            case 0x1F49CCu: goto label_1f49cc;
            case 0x1F49DCu: goto label_1f49dc;
            case 0x1F49ECu: goto label_1f49ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4A0Cu;
    // 0x1f4a0c: 0x0  nop
    ctx->pc = 0x1f4a0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
