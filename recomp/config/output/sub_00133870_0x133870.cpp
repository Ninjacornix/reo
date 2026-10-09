#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133870
// Address: 0x133870 - 0x133928
void sub_00133870_0x133870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133870_0x133870");
#endif

    switch (ctx->pc) {
        case 0x13389cu: goto label_13389c;
        case 0x1338a8u: goto label_1338a8;
        case 0x1338b4u: goto label_1338b4;
        case 0x1338c0u: goto label_1338c0;
        case 0x1338d0u: goto label_1338d0;
        case 0x1338e0u: goto label_1338e0;
        case 0x1338ecu: goto label_1338ec;
        case 0x1338f8u: goto label_1338f8;
        default: break;
    }

    ctx->pc = 0x133870u;

    // 0x133870: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x133870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x133874: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133878: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x133878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13387c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x13387cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133880: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x133880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x133884: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x133884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x133888: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x133888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x13388c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13388cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133890: 0x8e510004  lw          $s1, 0x4($s2)
    ctx->pc = 0x133890u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x133894: 0xc04b61a  jal         func_12D868
    ctx->pc = 0x133894u;
    SET_GPR_U32(ctx, 31, 0x13389Cu);
    ctx->pc = 0x133898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133894u;
            // 0x133898: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D868u;
    if (runtime->hasFunction(0x12D868u)) {
        auto targetFn = runtime->lookupFunction(0x12D868u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13389Cu; }
        if (ctx->pc != 0x13389Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D868_0x12d868(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13389Cu; }
        if (ctx->pc != 0x13389Cu) { return; }
    }
    ctx->pc = 0x13389Cu;
label_13389c:
    // 0x13389c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13389cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338a0: 0xc04b620  jal         func_12D880
    ctx->pc = 0x1338A0u;
    SET_GPR_U32(ctx, 31, 0x1338A8u);
    ctx->pc = 0x1338A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338A0u;
            // 0x1338a4: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D880u;
    if (runtime->hasFunction(0x12D880u)) {
        auto targetFn = runtime->lookupFunction(0x12D880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338A8u; }
        if (ctx->pc != 0x1338A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D880_0x12d880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338A8u; }
        if (ctx->pc != 0x1338A8u) { return; }
    }
    ctx->pc = 0x1338A8u;
label_1338a8:
    // 0x1338a8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338ac: 0xc04b62c  jal         func_12D8B0
    ctx->pc = 0x1338ACu;
    SET_GPR_U32(ctx, 31, 0x1338B4u);
    ctx->pc = 0x1338B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338ACu;
            // 0x1338b0: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8B0u;
    if (runtime->hasFunction(0x12D8B0u)) {
        auto targetFn = runtime->lookupFunction(0x12D8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338B4u; }
        if (ctx->pc != 0x1338B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8B0_0x12d8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338B4u; }
        if (ctx->pc != 0x1338B4u) { return; }
    }
    ctx->pc = 0x1338B4u;
label_1338b4:
    // 0x1338b4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338b8: 0xc04b68e  jal         func_12DA38
    ctx->pc = 0x1338B8u;
    SET_GPR_U32(ctx, 31, 0x1338C0u);
    ctx->pc = 0x1338BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338B8u;
            // 0x1338bc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DA38u;
    if (runtime->hasFunction(0x12DA38u)) {
        auto targetFn = runtime->lookupFunction(0x12DA38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338C0u; }
        if (ctx->pc != 0x1338C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DA38_0x12da38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338C0u; }
        if (ctx->pc != 0x1338C0u) { return; }
    }
    ctx->pc = 0x1338C0u;
label_1338c0:
    // 0x1338c0: 0x2138023  subu        $s0, $s0, $s3
    ctx->pc = 0x1338c0u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x1338c4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338c8: 0xc04b5d6  jal         func_12D758
    ctx->pc = 0x1338C8u;
    SET_GPR_U32(ctx, 31, 0x1338D0u);
    ctx->pc = 0x1338CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338C8u;
            // 0x1338cc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D758u;
    if (runtime->hasFunction(0x12D758u)) {
        auto targetFn = runtime->lookupFunction(0x12D758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338D0u; }
        if (ctx->pc != 0x1338D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D758_0x12d758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338D0u; }
        if (ctx->pc != 0x1338D0u) { return; }
    }
    ctx->pc = 0x1338D0u;
label_1338d0:
    // 0x1338d0: 0xae500090  sw          $s0, 0x90($s2)
    ctx->pc = 0x1338d0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 144), GPR_U32(ctx, 16));
    // 0x1338d4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1338d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338d8: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x1338D8u;
    SET_GPR_U32(ctx, 31, 0x1338E0u);
    ctx->pc = 0x1338DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338D8u;
            // 0x1338dc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338E0u; }
        if (ctx->pc != 0x1338E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338E0u; }
        if (ctx->pc != 0x1338E0u) { return; }
    }
    ctx->pc = 0x1338E0u;
label_1338e0:
    // 0x1338e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338e4: 0xc04b5da  jal         func_12D768
    ctx->pc = 0x1338E4u;
    SET_GPR_U32(ctx, 31, 0x1338ECu);
    ctx->pc = 0x1338E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338E4u;
            // 0x1338e8: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D768u;
    if (runtime->hasFunction(0x12D768u)) {
        auto targetFn = runtime->lookupFunction(0x12D768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338ECu; }
        if (ctx->pc != 0x1338ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D768_0x12d768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338ECu; }
        if (ctx->pc != 0x1338ECu) { return; }
    }
    ctx->pc = 0x1338ECu;
label_1338ec:
    // 0x1338ec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1338f0: 0xc04b5ba  jal         func_12D6E8
    ctx->pc = 0x1338F0u;
    SET_GPR_U32(ctx, 31, 0x1338F8u);
    ctx->pc = 0x1338F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1338F0u;
            // 0x1338f4: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D6E8u;
    if (runtime->hasFunction(0x12D6E8u)) {
        auto targetFn = runtime->lookupFunction(0x12D6E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338F8u; }
        if (ctx->pc != 0x1338F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D6E8_0x12d6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1338F8u; }
        if (ctx->pc != 0x1338F8u) { return; }
    }
    ctx->pc = 0x1338F8u;
label_1338f8:
    // 0x1338f8: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x1338f8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x1338fc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1338fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133900: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133900u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133904: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x133904u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133908: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133908u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13390c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13390cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133910: 0x24a53928  addiu       $a1, $a1, 0x3928
    ctx->pc = 0x133910u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 14632));
    // 0x133914: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133914u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133918: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x133918u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13391c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13391cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x133920: 0x804b5ce  j           func_12D738
    ctx->pc = 0x133920u;
    ctx->pc = 0x133924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133920u;
            // 0x133924: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D738u;
    if (runtime->hasFunction(0x12D738u)) {
        auto targetFn = runtime->lookupFunction(0x12D738u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D738_0x12d738(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133928u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
