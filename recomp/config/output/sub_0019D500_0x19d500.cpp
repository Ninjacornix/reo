#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019D500
// Address: 0x19d500 - 0x19d5b0
void sub_0019D500_0x19d500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019D500_0x19d500");
#endif

    switch (ctx->pc) {
        case 0x19d564u: goto label_19d564;
        case 0x19d578u: goto label_19d578;
        case 0x19d588u: goto label_19d588;
        default: break;
    }

    ctx->pc = 0x19d500u;

    // 0x19d500: 0x2485ffff  addiu       $a1, $a0, -0x1
    ctx->pc = 0x19d500u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19d504: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x19d504u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x19d508: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x19d508u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x19d50c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x19d50cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x19d510: 0x3c02002a  lui         $v0, 0x2A
    ctx->pc = 0x19d510u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)42 << 16));
    // 0x19d514: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x19d514u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x19d518: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19d518u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19d51c: 0x24428680  addiu       $v0, $v0, -0x7980
    ctx->pc = 0x19d51cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936192));
    // 0x19d520: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x19d520u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x19d524: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D524u;
    {
        const bool branch_taken_0x19d524 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D524u;
            // 0x19d528: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d524) {
            ctx->pc = 0x19D534u;
            goto label_19d534;
        }
    }
    ctx->pc = 0x19D52Cu;
    // 0x19d52c: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x19D52Cu;
    {
        const bool branch_taken_0x19d52c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D52Cu;
            // 0x19d530: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d52c) {
            ctx->pc = 0x19D5A0u;
            goto label_19d5a0;
        }
    }
    ctx->pc = 0x19D534u;
label_19d534:
    // 0x19d534: 0x2c810101  sltiu       $at, $a0, 0x101
    ctx->pc = 0x19d534u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)257) ? 1 : 0);
    // 0x19d538: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D538u;
    {
        const bool branch_taken_0x19d538 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D53Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D538u;
            // 0x19d53c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d538) {
            ctx->pc = 0x19D548u;
            goto label_19d548;
        }
    }
    ctx->pc = 0x19D540u;
    // 0x19d540: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x19D540u;
    {
        const bool branch_taken_0x19d540 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D540u;
            // 0x19d544: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d540) {
            ctx->pc = 0x19D5A4u;
            goto label_19d5a4;
        }
    }
    ctx->pc = 0x19D548u;
label_19d548:
    // 0x19d548: 0x82020034  lb          $v0, 0x34($s0)
    ctx->pc = 0x19d548u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x19d54c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D54Cu;
    {
        const bool branch_taken_0x19d54c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D54Cu;
            // 0x19d550: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d54c) {
            ctx->pc = 0x19D55Cu;
            goto label_19d55c;
        }
    }
    ctx->pc = 0x19D554u;
    // 0x19d554: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x19D554u;
    {
        const bool branch_taken_0x19d554 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D554u;
            // 0x19d558: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d554) {
            ctx->pc = 0x19D5A0u;
            goto label_19d5a0;
        }
    }
    ctx->pc = 0x19D55Cu;
label_19d55c:
    // 0x19d55c: 0xc067bb4  jal         func_19EED0
    ctx->pc = 0x19D55Cu;
    SET_GPR_U32(ctx, 31, 0x19D564u);
    ctx->pc = 0x19EED0u;
    if (runtime->hasFunction(0x19EED0u)) {
        auto targetFn = runtime->lookupFunction(0x19EED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D564u; }
        if (ctx->pc != 0x19D564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EED0_0x19eed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D564u; }
        if (ctx->pc != 0x19D564u) { return; }
    }
    ctx->pc = 0x19D564u;
label_19d564:
    // 0x19d564: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x19d564u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x19d568: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D568u;
    {
        const bool branch_taken_0x19d568 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x19d568) {
            ctx->pc = 0x19D578u;
            goto label_19d578;
        }
    }
    ctx->pc = 0x19D570u;
    // 0x19d570: 0xc063724  jal         func_18DC90
    ctx->pc = 0x19D570u;
    SET_GPR_U32(ctx, 31, 0x19D578u);
    ctx->pc = 0x18DC90u;
    if (runtime->hasFunction(0x18DC90u)) {
        auto targetFn = runtime->lookupFunction(0x18DC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D578u; }
        if (ctx->pc != 0x19D578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC90_0x18dc90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D578u; }
        if (ctx->pc != 0x19D578u) { return; }
    }
    ctx->pc = 0x19D578u;
label_19d578:
    // 0x19d578: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x19d578u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d57c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x19d57cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d580: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x19D580u;
    SET_GPR_U32(ctx, 31, 0x19D588u);
    ctx->pc = 0x19D584u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D580u;
            // 0x19d584: 0x24060038  addiu       $a2, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D588u; }
        if (ctx->pc != 0x19D588u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D588u; }
        if (ctx->pc != 0x19D588u) { return; }
    }
    ctx->pc = 0x19D588u;
label_19d588:
    // 0x19d588: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19d588u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19d58c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19d58cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19d590: 0x8c23fee0  lw          $v1, -0x120($at)
    ctx->pc = 0x19d590u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967008)));
    // 0x19d594: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x19d594u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x19d598: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19d598u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19d59c: 0xac23fee0  sw          $v1, -0x120($at)
    ctx->pc = 0x19d59cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967008), GPR_U32(ctx, 3));
label_19d5a0:
    // 0x19d5a0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x19d5a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_19d5a4:
    // 0x19d5a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19d5a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19d5a8: 0x3e00008  jr          $ra
    ctx->pc = 0x19D5A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19D5ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D5A8u;
            // 0x19d5ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19D534u: goto label_19d534;
            case 0x19D548u: goto label_19d548;
            case 0x19D55Cu: goto label_19d55c;
            case 0x19D564u: goto label_19d564;
            case 0x19D578u: goto label_19d578;
            case 0x19D588u: goto label_19d588;
            case 0x19D5A0u: goto label_19d5a0;
            case 0x19D5A4u: goto label_19d5a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19D5B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
