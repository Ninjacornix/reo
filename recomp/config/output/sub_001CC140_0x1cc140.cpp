#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC140
// Address: 0x1cc140 - 0x1cc1f0
void sub_001CC140_0x1cc140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC140_0x1cc140");
#endif

    switch (ctx->pc) {
        case 0x1cc168u: goto label_1cc168;
        case 0x1cc17cu: goto label_1cc17c;
        case 0x1cc18cu: goto label_1cc18c;
        case 0x1cc198u: goto label_1cc198;
        case 0x1cc1a8u: goto label_1cc1a8;
        case 0x1cc1b8u: goto label_1cc1b8;
        case 0x1cc1c8u: goto label_1cc1c8;
        default: break;
    }

    ctx->pc = 0x1cc140u;

    // 0x1cc140: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1cc140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1cc144: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1cc144u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1cc148: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1cc148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1cc14c: 0x24a5b630  addiu       $a1, $a1, -0x49D0
    ctx->pc = 0x1cc14cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294948400));
    // 0x1cc150: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cc150u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cc154: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1cc154u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc158: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cc158u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cc15c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cc15cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc160: 0xc07302c  jal         func_1CC0B0
    ctx->pc = 0x1CC160u;
    SET_GPR_U32(ctx, 31, 0x1CC168u);
    ctx->pc = 0x1CC164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC160u;
            // 0x1cc164: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC0B0u;
    if (runtime->hasFunction(0x1CC0B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC0B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC168u; }
        if (ctx->pc != 0x1CC168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC0B0_0x1cc0b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC168u; }
        if (ctx->pc != 0x1CC168u) { return; }
    }
    ctx->pc = 0x1CC168u;
label_1cc168:
    // 0x1cc168: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1cc168u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc16c: 0x6200018  bltz        $s1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1CC16Cu;
    {
        const bool branch_taken_0x1cc16c = (GPR_S64(ctx, 17) < 0);
        ctx->pc = 0x1CC170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC16Cu;
            // 0x1cc170: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc16c) {
            ctx->pc = 0x1CC1D0u;
            goto label_1cc1d0;
        }
    }
    ctx->pc = 0x1CC174u;
    // 0x1cc174: 0xc071f24  jal         func_1C7C90
    ctx->pc = 0x1CC174u;
    SET_GPR_U32(ctx, 31, 0x1CC17Cu);
    ctx->pc = 0x1CC178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC174u;
            // 0x1cc178: 0x2484b630  addiu       $a0, $a0, -0x49D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C90u;
    if (runtime->hasFunction(0x1C7C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC17Cu; }
        if (ctx->pc != 0x1CC17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C90_0x1c7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC17Cu; }
        if (ctx->pc != 0x1CC17Cu) { return; }
    }
    ctx->pc = 0x1CC17Cu;
label_1cc17c:
    // 0x1cc17c: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1CC17Cu;
    {
        const bool branch_taken_0x1cc17c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc17c) {
            ctx->pc = 0x1CC1D0u;
            goto label_1cc1d0;
        }
    }
    ctx->pc = 0x1CC184u;
    // 0x1cc184: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1CC184u;
    {
        const bool branch_taken_0x1cc184 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC184u;
            // 0x1cc188: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc184) {
            ctx->pc = 0x1CC1BCu;
            goto label_1cc1bc;
        }
    }
    ctx->pc = 0x1CC18Cu;
label_1cc18c:
    // 0x1cc18c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cc18cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cc190: 0xc071f30  jal         func_1C7CC0
    ctx->pc = 0x1CC190u;
    SET_GPR_U32(ctx, 31, 0x1CC198u);
    ctx->pc = 0x1CC194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC190u;
            // 0x1cc194: 0x2484b630  addiu       $a0, $a0, -0x49D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CC0u;
    if (runtime->hasFunction(0x1C7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC198u; }
        if (ctx->pc != 0x1CC198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CC0_0x1c7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC198u; }
        if (ctx->pc != 0x1CC198u) { return; }
    }
    ctx->pc = 0x1CC198u;
label_1cc198:
    // 0x1cc198: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1cc198u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc19c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1cc19cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc1a0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1CC1A0u;
    SET_GPR_U32(ctx, 31, 0x1CC1A8u);
    ctx->pc = 0x1CC1A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC1A0u;
            // 0x1cc1a4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC1A8u; }
        if (ctx->pc != 0x1CC1A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC1A8u; }
        if (ctx->pc != 0x1CC1A8u) { return; }
    }
    ctx->pc = 0x1CC1A8u;
label_1cc1a8:
    // 0x1cc1a8: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cc1a8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cc1ac: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1cc1acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc1b0: 0xc071f60  jal         func_1C7D80
    ctx->pc = 0x1CC1B0u;
    SET_GPR_U32(ctx, 31, 0x1CC1B8u);
    ctx->pc = 0x1CC1B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC1B0u;
            // 0x1cc1b4: 0x2484b630  addiu       $a0, $a0, -0x49D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D80u;
    if (runtime->hasFunction(0x1C7D80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC1B8u; }
        if (ctx->pc != 0x1CC1B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D80_0x1c7d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC1B8u; }
        if (ctx->pc != 0x1CC1B8u) { return; }
    }
    ctx->pc = 0x1CC1B8u;
label_1cc1b8:
    // 0x1cc1b8: 0x2308821  addu        $s1, $s1, $s0
    ctx->pc = 0x1cc1b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
label_1cc1bc:
    // 0x1cc1bc: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cc1bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cc1c0: 0xc071f24  jal         func_1C7C90
    ctx->pc = 0x1CC1C0u;
    SET_GPR_U32(ctx, 31, 0x1CC1C8u);
    ctx->pc = 0x1CC1C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC1C0u;
            // 0x1cc1c4: 0x2484b630  addiu       $a0, $a0, -0x49D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C90u;
    if (runtime->hasFunction(0x1C7C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC1C8u; }
        if (ctx->pc != 0x1CC1C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C90_0x1c7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC1C8u; }
        if (ctx->pc != 0x1CC1C8u) { return; }
    }
    ctx->pc = 0x1CC1C8u;
label_1cc1c8:
    // 0x1cc1c8: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1CC1C8u;
    {
        const bool branch_taken_0x1cc1c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CC1CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC1C8u;
            // 0x1cc1cc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc1c8) {
            ctx->pc = 0x1CC18Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cc18c;
        }
    }
    ctx->pc = 0x1CC1D0u;
label_1cc1d0:
    // 0x1cc1d0: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1cc1d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc1d4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1cc1d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cc1d8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cc1d8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cc1dc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cc1dcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cc1e0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cc1e0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc1e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC1E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC1E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC1E4u;
            // 0x1cc1e8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC168u: goto label_1cc168;
            case 0x1CC17Cu: goto label_1cc17c;
            case 0x1CC18Cu: goto label_1cc18c;
            case 0x1CC198u: goto label_1cc198;
            case 0x1CC1A8u: goto label_1cc1a8;
            case 0x1CC1B8u: goto label_1cc1b8;
            case 0x1CC1BCu: goto label_1cc1bc;
            case 0x1CC1C8u: goto label_1cc1c8;
            case 0x1CC1D0u: goto label_1cc1d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC1ECu;
    // 0x1cc1ec: 0x0  nop
    ctx->pc = 0x1cc1ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
