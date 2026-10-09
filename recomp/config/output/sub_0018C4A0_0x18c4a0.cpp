#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C4A0
// Address: 0x18c4a0 - 0x18c5f0
void sub_0018C4A0_0x18c4a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C4A0_0x18c4a0");
#endif

    switch (ctx->pc) {
        case 0x18c504u: goto label_18c504;
        case 0x18c51cu: goto label_18c51c;
        case 0x18c530u: goto label_18c530;
        case 0x18c540u: goto label_18c540;
        case 0x18c570u: goto label_18c570;
        default: break;
    }

    ctx->pc = 0x18c4a0u;

    // 0x18c4a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x18c4a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18c4a4: 0x2485ffff  addiu       $a1, $a0, -0x1
    ctx->pc = 0x18c4a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x18c4a8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18c4a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18c4ac: 0x51840  sll         $v1, $a1, 1
    ctx->pc = 0x18c4acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x18c4b0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18c4b0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18c4b4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18c4b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18c4b8: 0x8c2241a0  lw          $v0, 0x41A0($at)
    ctx->pc = 0x18c4b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16800)));
    // 0x18c4bc: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x18c4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x18c4c0: 0x319c0  sll         $v1, $v1, 7
    ctx->pc = 0x18c4c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
    // 0x18c4c4: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C4C4u;
    {
        const bool branch_taken_0x18c4c4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x18C4C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C4C4u;
            // 0x18c4c8: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c4c4) {
            ctx->pc = 0x18C4D4u;
            goto label_18c4d4;
        }
    }
    ctx->pc = 0x18C4CCu;
    // 0x18c4cc: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x18C4CCu;
    {
        const bool branch_taken_0x18c4cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C4D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C4CCu;
            // 0x18c4d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c4cc) {
            ctx->pc = 0x18C558u;
            goto label_18c558;
        }
    }
    ctx->pc = 0x18C4D4u;
label_18c4d4:
    // 0x18c4d4: 0x2c810281  sltiu       $at, $a0, 0x281
    ctx->pc = 0x18c4d4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)641) ? 1 : 0);
    // 0x18c4d8: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C4D8u;
    {
        const bool branch_taken_0x18c4d8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x18C4DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C4D8u;
            // 0x18c4dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c4d8) {
            ctx->pc = 0x18C4E8u;
            goto label_18c4e8;
        }
    }
    ctx->pc = 0x18C4E0u;
    // 0x18c4e0: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x18C4E0u;
    {
        const bool branch_taken_0x18c4e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C4E0u;
            // 0x18c4e4: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c4e0) {
            ctx->pc = 0x18C55Cu;
            goto label_18c55c;
        }
    }
    ctx->pc = 0x18C4E8u;
label_18c4e8:
    // 0x18c4e8: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x18c4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x18c4ec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C4ECu;
    {
        const bool branch_taken_0x18c4ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18C4F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C4ECu;
            // 0x18c4f0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c4ec) {
            ctx->pc = 0x18C4FCu;
            goto label_18c4fc;
        }
    }
    ctx->pc = 0x18C4F4u;
    // 0x18c4f4: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x18C4F4u;
    {
        const bool branch_taken_0x18c4f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c4f4) {
            ctx->pc = 0x18C558u;
            goto label_18c558;
        }
    }
    ctx->pc = 0x18C4FCu;
label_18c4fc:
    // 0x18c4fc: 0xc0635b0  jal         func_18D6C0
    ctx->pc = 0x18C4FCu;
    SET_GPR_U32(ctx, 31, 0x18C504u);
    ctx->pc = 0x18D6C0u;
    if (runtime->hasFunction(0x18D6C0u)) {
        auto targetFn = runtime->lookupFunction(0x18D6C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C504u; }
        if (ctx->pc != 0x18C504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D6C0_0x18d6c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C504u; }
        if (ctx->pc != 0x18C504u) { return; }
    }
    ctx->pc = 0x18C504u;
label_18c504:
    // 0x18c504: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x18c504u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x18c508: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x18c508u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x18c50c: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C50Cu;
    {
        const bool branch_taken_0x18c50c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c50c) {
            ctx->pc = 0x18C51Cu;
            goto label_18c51c;
        }
    }
    ctx->pc = 0x18C514u;
    // 0x18c514: 0xc063724  jal         func_18DC90
    ctx->pc = 0x18C514u;
    SET_GPR_U32(ctx, 31, 0x18C51Cu);
    ctx->pc = 0x18DC90u;
    if (runtime->hasFunction(0x18DC90u)) {
        auto targetFn = runtime->lookupFunction(0x18DC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C51Cu; }
        if (ctx->pc != 0x18C51Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC90_0x18dc90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C51Cu; }
        if (ctx->pc != 0x18C51Cu) { return; }
    }
    ctx->pc = 0x18C51Cu;
label_18c51c:
    // 0x18c51c: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x18c51cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x18c520: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C520u;
    {
        const bool branch_taken_0x18c520 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c520) {
            ctx->pc = 0x18C530u;
            goto label_18c530;
        }
    }
    ctx->pc = 0x18C528u;
    // 0x18c528: 0xc063724  jal         func_18DC90
    ctx->pc = 0x18C528u;
    SET_GPR_U32(ctx, 31, 0x18C530u);
    ctx->pc = 0x18DC90u;
    if (runtime->hasFunction(0x18DC90u)) {
        auto targetFn = runtime->lookupFunction(0x18DC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C530u; }
        if (ctx->pc != 0x18C530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC90_0x18dc90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C530u; }
        if (ctx->pc != 0x18C530u) { return; }
    }
    ctx->pc = 0x18C530u;
label_18c530:
    // 0x18c530: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18c530u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c534: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18c534u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c538: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x18C538u;
    SET_GPR_U32(ctx, 31, 0x18C540u);
    ctx->pc = 0x18C53Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C538u;
            // 0x18c53c: 0x24060180  addiu       $a2, $zero, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C540u; }
        if (ctx->pc != 0x18C540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C540u; }
        if (ctx->pc != 0x18C540u) { return; }
    }
    ctx->pc = 0x18C540u;
label_18c540:
    // 0x18c540: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18c540u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18c544: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18c544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18c548: 0x8c234198  lw          $v1, 0x4198($at)
    ctx->pc = 0x18c548u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16792)));
    // 0x18c54c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x18c54cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18c550: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18c550u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18c554: 0xac234198  sw          $v1, 0x4198($at)
    ctx->pc = 0x18c554u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16792), GPR_U32(ctx, 3));
label_18c558:
    // 0x18c558: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x18c558u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_18c55c:
    // 0x18c55c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18c55cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18c560: 0x3e00008  jr          $ra
    ctx->pc = 0x18C560u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C560u;
            // 0x18c564: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C4D4u: goto label_18c4d4;
            case 0x18C4E8u: goto label_18c4e8;
            case 0x18C4FCu: goto label_18c4fc;
            case 0x18C504u: goto label_18c504;
            case 0x18C51Cu: goto label_18c51c;
            case 0x18C530u: goto label_18c530;
            case 0x18C540u: goto label_18c540;
            case 0x18C558u: goto label_18c558;
            case 0x18C55Cu: goto label_18c55c;
            case 0x18C570u: goto label_18c570;
            case 0x18C58Cu: goto label_18c58c;
            case 0x18C5A8u: goto label_18c5a8;
            case 0x18C5E8u: goto label_18c5e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C568u;
    // 0x18c568: 0x0  nop
    ctx->pc = 0x18c568u;
    // NOP
    // 0x18c56c: 0x0  nop
    ctx->pc = 0x18c56cu;
    // NOP
label_18c570:
    // 0x18c570: 0x1080001d  beqz        $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x18C570u;
    {
        const bool branch_taken_0x18c570 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c570) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C578u;
    // 0x18c578: 0x2c810281  sltiu       $at, $a0, 0x281
    ctx->pc = 0x18c578u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)641) ? 1 : 0);
    // 0x18c57c: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C57Cu;
    {
        const bool branch_taken_0x18c57c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x18c57c) {
            ctx->pc = 0x18C58Cu;
            goto label_18c58c;
        }
    }
    ctx->pc = 0x18C584u;
    // 0x18c584: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x18C584u;
    {
        const bool branch_taken_0x18c584 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c584) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C58Cu;
label_18c58c:
    // 0x18c58c: 0x4a00016  bltz        $a1, . + 4 + (0x16 << 2)
    ctx->pc = 0x18C58Cu;
    {
        const bool branch_taken_0x18c58c = (GPR_S64(ctx, 5) < 0);
        if (branch_taken_0x18c58c) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C594u;
    // 0x18c594: 0x28a30020  slti        $v1, $a1, 0x20
    ctx->pc = 0x18c594u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x18c598: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C598u;
    {
        const bool branch_taken_0x18c598 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18c598) {
            ctx->pc = 0x18C5A8u;
            goto label_18c5a8;
        }
    }
    ctx->pc = 0x18C5A0u;
    // 0x18c5a0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x18C5A0u;
    {
        const bool branch_taken_0x18c5a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c5a0) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C5A8u;
label_18c5a8:
    // 0x18c5a8: 0x10c0000f  beqz        $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x18C5A8u;
    {
        const bool branch_taken_0x18c5a8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c5a8) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C5B0u;
    // 0x18c5b0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18c5b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18c5b4: 0x2487ffff  addiu       $a3, $a0, -0x1
    ctx->pc = 0x18c5b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x18c5b8: 0x8c2341a0  lw          $v1, 0x41A0($at)
    ctx->pc = 0x18c5b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16800)));
    // 0x18c5bc: 0x72040  sll         $a0, $a3, 1
    ctx->pc = 0x18c5bcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x18c5c0: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x18c5c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x18c5c4: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x18c5c4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x18c5c8: 0x421c0  sll         $a0, $a0, 7
    ctx->pc = 0x18c5c8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x18c5cc: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18c5ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18c5d0: 0xa32021  addu        $a0, $a1, $v1
    ctx->pc = 0x18c5d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x18c5d4: 0x8c830080  lw          $v1, 0x80($a0)
    ctx->pc = 0x18c5d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 128)));
    // 0x18c5d8: 0x10660003  beq         $v1, $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C5D8u;
    {
        const bool branch_taken_0x18c5d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        ctx->pc = 0x18C5DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C5D8u;
            // 0x18c5dc: 0x24850080  addiu       $a1, $a0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c5d8) {
            ctx->pc = 0x18C5E8u;
            goto label_18c5e8;
        }
    }
    ctx->pc = 0x18C5E0u;
    // 0x18c5e0: 0xaca60000  sw          $a2, 0x0($a1)
    ctx->pc = 0x18c5e0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 6));
    // 0x18c5e4: 0xac860100  sw          $a2, 0x100($a0)
    ctx->pc = 0x18c5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 256), GPR_U32(ctx, 6));
label_18c5e8:
    // 0x18c5e8: 0x3e00008  jr          $ra
    ctx->pc = 0x18C5E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C4D4u: goto label_18c4d4;
            case 0x18C4E8u: goto label_18c4e8;
            case 0x18C4FCu: goto label_18c4fc;
            case 0x18C504u: goto label_18c504;
            case 0x18C51Cu: goto label_18c51c;
            case 0x18C530u: goto label_18c530;
            case 0x18C540u: goto label_18c540;
            case 0x18C558u: goto label_18c558;
            case 0x18C55Cu: goto label_18c55c;
            case 0x18C570u: goto label_18c570;
            case 0x18C58Cu: goto label_18c58c;
            case 0x18C5A8u: goto label_18c5a8;
            case 0x18C5E8u: goto label_18c5e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C5F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
