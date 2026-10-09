#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC7B0
// Address: 0x1bc7b0 - 0x1bc870
void sub_001BC7B0_0x1bc7b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC7B0_0x1bc7b0");
#endif

    switch (ctx->pc) {
        case 0x1bc7c8u: goto label_1bc7c8;
        case 0x1bc7e0u: goto label_1bc7e0;
        case 0x1bc7ecu: goto label_1bc7ec;
        case 0x1bc7f8u: goto label_1bc7f8;
        case 0x1bc804u: goto label_1bc804;
        case 0x1bc810u: goto label_1bc810;
        case 0x1bc81cu: goto label_1bc81c;
        case 0x1bc828u: goto label_1bc828;
        case 0x1bc834u: goto label_1bc834;
        case 0x1bc840u: goto label_1bc840;
        case 0x1bc85cu: goto label_1bc85c;
        default: break;
    }

    ctx->pc = 0x1bc7b0u;

    // 0x1bc7b0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1bc7b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1bc7b4: 0x28820002  slti        $v0, $a0, 0x2
    ctx->pc = 0x1bc7b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1bc7b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bc7b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bc7bc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bc7bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bc7c0: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1BC7C0u;
    SET_GPR_U32(ctx, 31, 0x1BC7C8u);
    ctx->pc = 0x1BC7C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC7C0u;
            // 0x1bc7c4: 0x38500001  xori        $s0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC7C8u; }
        if (ctx->pc != 0x1BC7C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC7C8u; }
        if (ctx->pc != 0x1BC7C8u) { return; }
    }
    ctx->pc = 0x1BC7C8u;
label_1bc7c8:
    // 0x1bc7c8: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1bc7c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1bc7cc: 0x8fa3002c  lw          $v1, 0x2C($sp)
    ctx->pc = 0x1bc7ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1bc7d0: 0x10600022  beqz        $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x1BC7D0u;
    {
        const bool branch_taken_0x1bc7d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bc7d0) {
            ctx->pc = 0x1BC85Cu;
            goto label_1bc85c;
        }
    }
    ctx->pc = 0x1BC7D8u;
    // 0x1bc7d8: 0xc06bc10  jal         func_1AF040
    ctx->pc = 0x1BC7D8u;
    SET_GPR_U32(ctx, 31, 0x1BC7E0u);
    ctx->pc = 0x1AF040u;
    if (runtime->hasFunction(0x1AF040u)) {
        auto targetFn = runtime->lookupFunction(0x1AF040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC7E0u; }
        if (ctx->pc != 0x1BC7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF040_0x1af040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC7E0u; }
        if (ctx->pc != 0x1BC7E0u) { return; }
    }
    ctx->pc = 0x1BC7E0u;
label_1bc7e0:
    // 0x1bc7e0: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1bc7e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1bc7e4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC7E4u;
    SET_GPR_U32(ctx, 31, 0x1BC7ECu);
    ctx->pc = 0x1BC7E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC7E4u;
            // 0x1bc7e8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC7ECu; }
        if (ctx->pc != 0x1BC7ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC7ECu; }
        if (ctx->pc != 0x1BC7ECu) { return; }
    }
    ctx->pc = 0x1BC7ECu;
label_1bc7ec:
    // 0x1bc7ec: 0x2404005f  addiu       $a0, $zero, 0x5F
    ctx->pc = 0x1bc7ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x1bc7f0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC7F0u;
    SET_GPR_U32(ctx, 31, 0x1BC7F8u);
    ctx->pc = 0x1BC7F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC7F0u;
            // 0x1bc7f4: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC7F8u; }
        if (ctx->pc != 0x1BC7F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC7F8u; }
        if (ctx->pc != 0x1BC7F8u) { return; }
    }
    ctx->pc = 0x1BC7F8u;
label_1bc7f8:
    // 0x1bc7f8: 0x24040060  addiu       $a0, $zero, 0x60
    ctx->pc = 0x1bc7f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x1bc7fc: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC7FCu;
    SET_GPR_U32(ctx, 31, 0x1BC804u);
    ctx->pc = 0x1BC800u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC7FCu;
            // 0x1bc800: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC804u; }
        if (ctx->pc != 0x1BC804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC804u; }
        if (ctx->pc != 0x1BC804u) { return; }
    }
    ctx->pc = 0x1BC804u;
label_1bc804:
    // 0x1bc804: 0x24040063  addiu       $a0, $zero, 0x63
    ctx->pc = 0x1bc804u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1bc808: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC808u;
    SET_GPR_U32(ctx, 31, 0x1BC810u);
    ctx->pc = 0x1BC80Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC808u;
            // 0x1bc80c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC810u; }
        if (ctx->pc != 0x1BC810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC810u; }
        if (ctx->pc != 0x1BC810u) { return; }
    }
    ctx->pc = 0x1BC810u;
label_1bc810:
    // 0x1bc810: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1bc810u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1bc814: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC814u;
    SET_GPR_U32(ctx, 31, 0x1BC81Cu);
    ctx->pc = 0x1BC818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC814u;
            // 0x1bc818: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC81Cu; }
        if (ctx->pc != 0x1BC81Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC81Cu; }
        if (ctx->pc != 0x1BC81Cu) { return; }
    }
    ctx->pc = 0x1BC81Cu;
label_1bc81c:
    // 0x1bc81c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bc81cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bc820: 0xc0675c8  jal         func_19D720
    ctx->pc = 0x1BC820u;
    SET_GPR_U32(ctx, 31, 0x1BC828u);
    ctx->pc = 0x1BC824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC820u;
            // 0x1bc824: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19D720u;
    if (runtime->hasFunction(0x19D720u)) {
        auto targetFn = runtime->lookupFunction(0x19D720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC828u; }
        if (ctx->pc != 0x1BC828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D720_0x19d720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC828u; }
        if (ctx->pc != 0x1BC828u) { return; }
    }
    ctx->pc = 0x1BC828u;
label_1bc828:
    // 0x1bc828: 0x8fa5002c  lw          $a1, 0x2C($sp)
    ctx->pc = 0x1bc828u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1bc82c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC82Cu;
    SET_GPR_U32(ctx, 31, 0x1BC834u);
    ctx->pc = 0x1BC830u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC82Cu;
            // 0x1bc830: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC834u; }
        if (ctx->pc != 0x1BC834u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC834u; }
        if (ctx->pc != 0x1BC834u) { return; }
    }
    ctx->pc = 0x1BC834u;
label_1bc834:
    // 0x1bc834: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1bc834u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1bc838: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1BC838u;
    SET_GPR_U32(ctx, 31, 0x1BC840u);
    ctx->pc = 0x1BC83Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC838u;
            // 0x1bc83c: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC840u; }
        if (ctx->pc != 0x1BC840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC840u; }
        if (ctx->pc != 0x1BC840u) { return; }
    }
    ctx->pc = 0x1BC840u;
label_1bc840:
    // 0x1bc840: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1bc840u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1bc844: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1bc844u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1bc848: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1bc848u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1bc84c: 0x24424ee0  addiu       $v0, $v0, 0x4EE0
    ctx->pc = 0x1bc84cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20192));
    // 0x1bc850: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bc850u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bc854: 0xc06ae18  jal         func_1AB860
    ctx->pc = 0x1BC854u;
    SET_GPR_U32(ctx, 31, 0x1BC85Cu);
    ctx->pc = 0x1BC858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC854u;
            // 0x1bc858: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB860u;
    if (runtime->hasFunction(0x1AB860u)) {
        auto targetFn = runtime->lookupFunction(0x1AB860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC85Cu; }
        if (ctx->pc != 0x1BC85Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB860_0x1ab860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC85Cu; }
        if (ctx->pc != 0x1BC85Cu) { return; }
    }
    ctx->pc = 0x1BC85Cu;
label_1bc85c:
    // 0x1bc85c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bc85cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bc860: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bc860u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bc864: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BC868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC864u;
            // 0x1bc868: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC7C8u: goto label_1bc7c8;
            case 0x1BC7E0u: goto label_1bc7e0;
            case 0x1BC7ECu: goto label_1bc7ec;
            case 0x1BC7F8u: goto label_1bc7f8;
            case 0x1BC804u: goto label_1bc804;
            case 0x1BC810u: goto label_1bc810;
            case 0x1BC81Cu: goto label_1bc81c;
            case 0x1BC828u: goto label_1bc828;
            case 0x1BC834u: goto label_1bc834;
            case 0x1BC840u: goto label_1bc840;
            case 0x1BC85Cu: goto label_1bc85c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC86Cu;
    // 0x1bc86c: 0x0  nop
    ctx->pc = 0x1bc86cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
