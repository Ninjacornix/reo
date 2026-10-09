#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015C078
// Address: 0x15c078 - 0x15c120
void sub_0015C078_0x15c078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015C078_0x15c078");
#endif

    switch (ctx->pc) {
        case 0x15c0d4u: goto label_15c0d4;
        case 0x15c0e4u: goto label_15c0e4;
        default: break;
    }

    ctx->pc = 0x15c078u;

    // 0x15c078: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15c078u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15c07c: 0x3c020008  lui         $v0, 0x8
    ctx->pc = 0x15c07cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
    // 0x15c080: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15c080u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15c084: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x15c084u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c088: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15c088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15c08c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15c08cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c090: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x15c090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x15c094: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x15c094u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c098: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x15c098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x15c09c: 0x344240d0  ori         $v0, $v0, 0x40D0
    ctx->pc = 0x15c09cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16592);
    // 0x15c0a0: 0x8ca3000c  lw          $v1, 0xC($a1)
    ctx->pc = 0x15c0a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x15c0a4: 0x8ca70008  lw          $a3, 0x8($a1)
    ctx->pc = 0x15c0a4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x15c0a8: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x15c0a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x15c0ac: 0xe33818  mult        $a3, $a3, $v1
    ctx->pc = 0x15c0acu;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x15c0b0: 0x710c0  sll         $v0, $a3, 3
    ctx->pc = 0x15c0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x15c0b4: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x15c0b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x15c0b8: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x15c0b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x15c0bc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x15c0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x15c0c0: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x15c0c0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x15c0c4: 0x24422840  addiu       $v0, $v0, 0x2840
    ctx->pc = 0x15c0c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 10304));
    // 0x15c0c8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15c0c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c0cc: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C0CCu;
    SET_GPR_U32(ctx, 31, 0x15C0D4u);
    ctx->pc = 0x15C0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C0CCu;
            // 0x15c0d0: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C0D4u; }
        if (ctx->pc != 0x15C0D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C0D4u; }
        if (ctx->pc != 0x15C0D4u) { return; }
    }
    ctx->pc = 0x15C0D4u;
label_15c0d4:
    // 0x15c0d4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15c0d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c0d8: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x15c0d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x15c0dc: 0xc057568  jal         func_15D5A0
    ctx->pc = 0x15C0DCu;
    SET_GPR_U32(ctx, 31, 0x15C0E4u);
    ctx->pc = 0x15C0E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C0DCu;
            // 0x15c0e0: 0x8fa50004  lw          $a1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D5A0u;
    if (runtime->hasFunction(0x15D5A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D5A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C0E4u; }
        if (ctx->pc != 0x15C0E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D5A0_0x15d5a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C0E4u; }
        if (ctx->pc != 0x15C0E4u) { return; }
    }
    ctx->pc = 0x15C0E4u;
label_15c0e4:
    // 0x15c0e4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x15c0e4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c0e8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x15c0e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15c0ec: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15C0ECu;
    {
        const bool branch_taken_0x15c0ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C0F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C0ECu;
            // 0x15c0f0: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c0ec) {
            ctx->pc = 0x15C0FCu;
            goto label_15c0fc;
        }
    }
    ctx->pc = 0x15C0F4u;
    // 0x15c0f4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x15C0F4u;
    {
        const bool branch_taken_0x15c0f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x15C0F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C0F4u;
            // 0x15c0f8: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c0f4) {
            ctx->pc = 0x15C104u;
            goto label_15c104;
        }
    }
    ctx->pc = 0x15C0FCu;
label_15c0fc:
    // 0x15c0fc: 0x2412ffff  addiu       $s2, $zero, -0x1
    ctx->pc = 0x15c0fcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15c100: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x15c100u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_15c104:
    // 0x15c104: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15c104u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15c108: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15c108u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15c10c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15c10cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15c110: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x15c110u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15c114: 0x3e00008  jr          $ra
    ctx->pc = 0x15C114u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15C118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C114u;
            // 0x15c118: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15C0D4u: goto label_15c0d4;
            case 0x15C0E4u: goto label_15c0e4;
            case 0x15C0FCu: goto label_15c0fc;
            case 0x15C104u: goto label_15c104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15C11Cu;
    // 0x15c11c: 0x0  nop
    ctx->pc = 0x15c11cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
