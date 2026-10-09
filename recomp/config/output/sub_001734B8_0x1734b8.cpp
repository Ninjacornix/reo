#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001734B8
// Address: 0x1734b8 - 0x173550
void sub_001734B8_0x1734b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001734B8_0x1734b8");
#endif

    switch (ctx->pc) {
        case 0x1734e4u: goto label_1734e4;
        case 0x1734f8u: goto label_1734f8;
        case 0x173508u: goto label_173508;
        case 0x173524u: goto label_173524;
        default: break;
    }

    ctx->pc = 0x1734b8u;

    // 0x1734b8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1734b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1734bc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1734bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1734c0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1734c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1734c4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1734c4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1734c8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1734c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1734cc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1734ccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1734d0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1734d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1734d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1734d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1734d8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1734d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1734dc: 0xc05cd54  jal         func_173550
    ctx->pc = 0x1734DCu;
    SET_GPR_U32(ctx, 31, 0x1734E4u);
    ctx->pc = 0x1734E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1734DCu;
            // 0x1734e0: 0x2453f18c  addiu       $s3, $v0, -0xE74 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963596));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173550u;
    if (runtime->hasFunction(0x173550u)) {
        auto targetFn = runtime->lookupFunction(0x173550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1734E4u; }
        if (ctx->pc != 0x1734E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173550_0x173550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1734E4u; }
        if (ctx->pc != 0x1734E4u) { return; }
    }
    ctx->pc = 0x1734E4u;
label_1734e4:
    // 0x1734e4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1734e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1734e8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1734E8u;
    {
        const bool branch_taken_0x1734e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1734ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1734E8u;
            // 0x1734ec: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1734e8) {
            ctx->pc = 0x173500u;
            goto label_173500;
        }
    }
    ctx->pc = 0x1734F0u;
    // 0x1734f0: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1734F0u;
    SET_GPR_U32(ctx, 31, 0x1734F8u);
    ctx->pc = 0x1734F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1734F0u;
            // 0x1734f4: 0x34a50203  ori         $a1, $a1, 0x203 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)515);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1734F8u; }
        if (ctx->pc != 0x1734F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1734F8u; }
        if (ctx->pc != 0x1734F8u) { return; }
    }
    ctx->pc = 0x1734F8u;
label_1734f8:
    // 0x1734f8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1734F8u;
    {
        const bool branch_taken_0x1734f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1734FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1734F8u;
            // 0x1734fc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1734f8) {
            ctx->pc = 0x173530u;
            goto label_173530;
        }
    }
    ctx->pc = 0x173500u;
label_173500:
    // 0x173500: 0xc05cd5c  jal         func_173570
    ctx->pc = 0x173500u;
    SET_GPR_U32(ctx, 31, 0x173508u);
    ctx->pc = 0x173570u;
    if (runtime->hasFunction(0x173570u)) {
        auto targetFn = runtime->lookupFunction(0x173570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173508u; }
        if (ctx->pc != 0x173508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173570_0x173570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173508u; }
        if (ctx->pc != 0x173508u) { return; }
    }
    ctx->pc = 0x173508u;
label_173508:
    // 0x173508: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x173508u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17350c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x17350cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173510: 0x12030007  beq         $s0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x173510u;
    {
        const bool branch_taken_0x173510 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x173514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173510u;
            // 0x173514: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173510) {
            ctx->pc = 0x173530u;
            goto label_173530;
        }
    }
    ctx->pc = 0x173518u;
    // 0x173518: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x173518u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17351c: 0xc05cd6c  jal         func_1735B0
    ctx->pc = 0x17351Cu;
    SET_GPR_U32(ctx, 31, 0x173524u);
    ctx->pc = 0x173520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17351Cu;
            // 0x173520: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1735B0u;
    if (runtime->hasFunction(0x1735B0u)) {
        auto targetFn = runtime->lookupFunction(0x1735B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173524u; }
        if (ctx->pc != 0x173524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001735B0_0x1735b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173524u; }
        if (ctx->pc != 0x173524u) { return; }
    }
    ctx->pc = 0x173524u;
label_173524:
    // 0x173524: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x173524u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x173528: 0x731821  addu        $v1, $v1, $s3
    ctx->pc = 0x173528u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x17352c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x17352cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_173530:
    // 0x173530: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173530u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173534: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x173534u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173538: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x173538u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17353c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17353cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x173540: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x173540u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x173544: 0x3e00008  jr          $ra
    ctx->pc = 0x173544u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173544u;
            // 0x173548: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1734E4u: goto label_1734e4;
            case 0x1734F8u: goto label_1734f8;
            case 0x173500u: goto label_173500;
            case 0x173508u: goto label_173508;
            case 0x173524u: goto label_173524;
            case 0x173530u: goto label_173530;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17354Cu;
    // 0x17354c: 0x0  nop
    ctx->pc = 0x17354cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
