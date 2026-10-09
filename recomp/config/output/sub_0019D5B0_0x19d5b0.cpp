#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019D5B0
// Address: 0x19d5b0 - 0x19d720
void sub_0019D5B0_0x19d5b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019D5B0_0x19d5b0");
#endif

    switch (ctx->pc) {
        case 0x19d614u: goto label_19d614;
        case 0x19d61cu: goto label_19d61c;
        case 0x19d630u: goto label_19d630;
        case 0x19d640u: goto label_19d640;
        case 0x19d6d4u: goto label_19d6d4;
        case 0x19d6e8u: goto label_19d6e8;
        case 0x19d6f8u: goto label_19d6f8;
        default: break;
    }

    ctx->pc = 0x19d5b0u;

    // 0x19d5b0: 0x2485ffff  addiu       $a1, $a0, -0x1
    ctx->pc = 0x19d5b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19d5b4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x19d5b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x19d5b8: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x19d5b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x19d5bc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x19d5bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x19d5c0: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x19d5c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x19d5c4: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x19d5c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x19d5c8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19d5c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19d5cc: 0x24424e80  addiu       $v0, $v0, 0x4E80
    ctx->pc = 0x19d5ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20096));
    // 0x19d5d0: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x19d5d0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x19d5d4: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D5D4u;
    {
        const bool branch_taken_0x19d5d4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D5D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D5D4u;
            // 0x19d5d8: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d5d4) {
            ctx->pc = 0x19D5E4u;
            goto label_19d5e4;
        }
    }
    ctx->pc = 0x19D5DCu;
    // 0x19d5dc: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x19D5DCu;
    {
        const bool branch_taken_0x19d5dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D5E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D5DCu;
            // 0x19d5e0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d5dc) {
            ctx->pc = 0x19D658u;
            goto label_19d658;
        }
    }
    ctx->pc = 0x19D5E4u;
label_19d5e4:
    // 0x19d5e4: 0x2c810101  sltiu       $at, $a0, 0x101
    ctx->pc = 0x19d5e4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)257) ? 1 : 0);
    // 0x19d5e8: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D5E8u;
    {
        const bool branch_taken_0x19d5e8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D5ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D5E8u;
            // 0x19d5ec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d5e8) {
            ctx->pc = 0x19D5F8u;
            goto label_19d5f8;
        }
    }
    ctx->pc = 0x19D5F0u;
    // 0x19d5f0: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x19D5F0u;
    {
        const bool branch_taken_0x19d5f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D5F0u;
            // 0x19d5f4: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d5f0) {
            ctx->pc = 0x19D65Cu;
            goto label_19d65c;
        }
    }
    ctx->pc = 0x19D5F8u;
label_19d5f8:
    // 0x19d5f8: 0x82020034  lb          $v0, 0x34($s0)
    ctx->pc = 0x19d5f8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x19d5fc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D5FCu;
    {
        const bool branch_taken_0x19d5fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D5FCu;
            // 0x19d600: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d5fc) {
            ctx->pc = 0x19D60Cu;
            goto label_19d60c;
        }
    }
    ctx->pc = 0x19D604u;
    // 0x19d604: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x19D604u;
    {
        const bool branch_taken_0x19d604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19d604) {
            ctx->pc = 0x19D658u;
            goto label_19d658;
        }
    }
    ctx->pc = 0x19D60Cu;
label_19d60c:
    // 0x19d60c: 0xc0635b0  jal         func_18D6C0
    ctx->pc = 0x19D60Cu;
    SET_GPR_U32(ctx, 31, 0x19D614u);
    ctx->pc = 0x18D6C0u;
    if (runtime->hasFunction(0x18D6C0u)) {
        auto targetFn = runtime->lookupFunction(0x18D6C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D614u; }
        if (ctx->pc != 0x19D614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D6C0_0x18d6c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D614u; }
        if (ctx->pc != 0x19D614u) { return; }
    }
    ctx->pc = 0x19D614u;
label_19d614:
    // 0x19d614: 0xc067bb4  jal         func_19EED0
    ctx->pc = 0x19D614u;
    SET_GPR_U32(ctx, 31, 0x19D61Cu);
    ctx->pc = 0x19D618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D614u;
            // 0x19d618: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EED0u;
    if (runtime->hasFunction(0x19EED0u)) {
        auto targetFn = runtime->lookupFunction(0x19EED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D61Cu; }
        if (ctx->pc != 0x19D61Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EED0_0x19eed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D61Cu; }
        if (ctx->pc != 0x19D61Cu) { return; }
    }
    ctx->pc = 0x19D61Cu;
label_19d61c:
    // 0x19d61c: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x19d61cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x19d620: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D620u;
    {
        const bool branch_taken_0x19d620 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x19d620) {
            ctx->pc = 0x19D630u;
            goto label_19d630;
        }
    }
    ctx->pc = 0x19D628u;
    // 0x19d628: 0xc063724  jal         func_18DC90
    ctx->pc = 0x19D628u;
    SET_GPR_U32(ctx, 31, 0x19D630u);
    ctx->pc = 0x18DC90u;
    if (runtime->hasFunction(0x18DC90u)) {
        auto targetFn = runtime->lookupFunction(0x18DC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D630u; }
        if (ctx->pc != 0x19D630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC90_0x18dc90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D630u; }
        if (ctx->pc != 0x19D630u) { return; }
    }
    ctx->pc = 0x19D630u;
label_19d630:
    // 0x19d630: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x19d630u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d634: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x19d634u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d638: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x19D638u;
    SET_GPR_U32(ctx, 31, 0x19D640u);
    ctx->pc = 0x19D63Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D638u;
            // 0x19d63c: 0x24060038  addiu       $a2, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D640u; }
        if (ctx->pc != 0x19D640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D640u; }
        if (ctx->pc != 0x19D640u) { return; }
    }
    ctx->pc = 0x19D640u;
label_19d640:
    // 0x19d640: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19d640u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19d644: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19d644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19d648: 0x8c23bec0  lw          $v1, -0x4140($at)
    ctx->pc = 0x19d648u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950592)));
    // 0x19d64c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x19d64cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x19d650: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19d650u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19d654: 0xac23bec0  sw          $v1, -0x4140($at)
    ctx->pc = 0x19d654u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950592), GPR_U32(ctx, 3));
label_19d658:
    // 0x19d658: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x19d658u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_19d65c:
    // 0x19d65c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19d65cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19d660: 0x3e00008  jr          $ra
    ctx->pc = 0x19D660u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19D664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D660u;
            // 0x19d664: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19D5E4u: goto label_19d5e4;
            case 0x19D5F8u: goto label_19d5f8;
            case 0x19D60Cu: goto label_19d60c;
            case 0x19D614u: goto label_19d614;
            case 0x19D61Cu: goto label_19d61c;
            case 0x19D630u: goto label_19d630;
            case 0x19D640u: goto label_19d640;
            case 0x19D658u: goto label_19d658;
            case 0x19D65Cu: goto label_19d65c;
            case 0x19D6A4u: goto label_19d6a4;
            case 0x19D6B8u: goto label_19d6b8;
            case 0x19D6CCu: goto label_19d6cc;
            case 0x19D6D4u: goto label_19d6d4;
            case 0x19D6E8u: goto label_19d6e8;
            case 0x19D6F8u: goto label_19d6f8;
            case 0x19D710u: goto label_19d710;
            case 0x19D714u: goto label_19d714;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19D668u;
    // 0x19d668: 0x0  nop
    ctx->pc = 0x19d668u;
    // NOP
    // 0x19d66c: 0x0  nop
    ctx->pc = 0x19d66cu;
    // NOP
    // 0x19d670: 0x2485ffff  addiu       $a1, $a0, -0x1
    ctx->pc = 0x19d670u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19d674: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x19d674u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x19d678: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x19d678u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x19d67c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x19d67cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x19d680: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x19d680u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x19d684: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x19d684u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x19d688: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19d688u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19d68c: 0x24424e80  addiu       $v0, $v0, 0x4E80
    ctx->pc = 0x19d68cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20096));
    // 0x19d690: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x19d690u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x19d694: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D694u;
    {
        const bool branch_taken_0x19d694 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D694u;
            // 0x19d698: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d694) {
            ctx->pc = 0x19D6A4u;
            goto label_19d6a4;
        }
    }
    ctx->pc = 0x19D69Cu;
    // 0x19d69c: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x19D69Cu;
    {
        const bool branch_taken_0x19d69c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D6A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D69Cu;
            // 0x19d6a0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d69c) {
            ctx->pc = 0x19D710u;
            goto label_19d710;
        }
    }
    ctx->pc = 0x19D6A4u;
label_19d6a4:
    // 0x19d6a4: 0x2c810101  sltiu       $at, $a0, 0x101
    ctx->pc = 0x19d6a4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)257) ? 1 : 0);
    // 0x19d6a8: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D6A8u;
    {
        const bool branch_taken_0x19d6a8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D6ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D6A8u;
            // 0x19d6ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d6a8) {
            ctx->pc = 0x19D6B8u;
            goto label_19d6b8;
        }
    }
    ctx->pc = 0x19D6B0u;
    // 0x19d6b0: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x19D6B0u;
    {
        const bool branch_taken_0x19d6b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D6B0u;
            // 0x19d6b4: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d6b0) {
            ctx->pc = 0x19D714u;
            goto label_19d714;
        }
    }
    ctx->pc = 0x19D6B8u;
label_19d6b8:
    // 0x19d6b8: 0x82020034  lb          $v0, 0x34($s0)
    ctx->pc = 0x19d6b8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x19d6bc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D6BCu;
    {
        const bool branch_taken_0x19d6bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D6C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D6BCu;
            // 0x19d6c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d6bc) {
            ctx->pc = 0x19D6CCu;
            goto label_19d6cc;
        }
    }
    ctx->pc = 0x19D6C4u;
    // 0x19d6c4: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x19D6C4u;
    {
        const bool branch_taken_0x19d6c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D6C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D6C4u;
            // 0x19d6c8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d6c4) {
            ctx->pc = 0x19D710u;
            goto label_19d710;
        }
    }
    ctx->pc = 0x19D6CCu;
label_19d6cc:
    // 0x19d6cc: 0xc067bb4  jal         func_19EED0
    ctx->pc = 0x19D6CCu;
    SET_GPR_U32(ctx, 31, 0x19D6D4u);
    ctx->pc = 0x19EED0u;
    if (runtime->hasFunction(0x19EED0u)) {
        auto targetFn = runtime->lookupFunction(0x19EED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D6D4u; }
        if (ctx->pc != 0x19D6D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EED0_0x19eed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D6D4u; }
        if (ctx->pc != 0x19D6D4u) { return; }
    }
    ctx->pc = 0x19D6D4u;
label_19d6d4:
    // 0x19d6d4: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x19d6d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x19d6d8: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D6D8u;
    {
        const bool branch_taken_0x19d6d8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x19d6d8) {
            ctx->pc = 0x19D6E8u;
            goto label_19d6e8;
        }
    }
    ctx->pc = 0x19D6E0u;
    // 0x19d6e0: 0xc063724  jal         func_18DC90
    ctx->pc = 0x19D6E0u;
    SET_GPR_U32(ctx, 31, 0x19D6E8u);
    ctx->pc = 0x18DC90u;
    if (runtime->hasFunction(0x18DC90u)) {
        auto targetFn = runtime->lookupFunction(0x18DC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D6E8u; }
        if (ctx->pc != 0x19D6E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC90_0x18dc90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D6E8u; }
        if (ctx->pc != 0x19D6E8u) { return; }
    }
    ctx->pc = 0x19D6E8u;
label_19d6e8:
    // 0x19d6e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x19d6e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d6ec: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x19d6ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d6f0: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x19D6F0u;
    SET_GPR_U32(ctx, 31, 0x19D6F8u);
    ctx->pc = 0x19D6F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D6F0u;
            // 0x19d6f4: 0x24060038  addiu       $a2, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D6F8u; }
        if (ctx->pc != 0x19D6F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D6F8u; }
        if (ctx->pc != 0x19D6F8u) { return; }
    }
    ctx->pc = 0x19D6F8u;
label_19d6f8:
    // 0x19d6f8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19d6f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19d6fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19d6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19d700: 0x8c23bec0  lw          $v1, -0x4140($at)
    ctx->pc = 0x19d700u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950592)));
    // 0x19d704: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x19d704u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x19d708: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19d708u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19d70c: 0xac23bec0  sw          $v1, -0x4140($at)
    ctx->pc = 0x19d70cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950592), GPR_U32(ctx, 3));
label_19d710:
    // 0x19d710: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x19d710u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_19d714:
    // 0x19d714: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19d714u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19d718: 0x3e00008  jr          $ra
    ctx->pc = 0x19D718u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19D71Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D718u;
            // 0x19d71c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19D5E4u: goto label_19d5e4;
            case 0x19D5F8u: goto label_19d5f8;
            case 0x19D60Cu: goto label_19d60c;
            case 0x19D614u: goto label_19d614;
            case 0x19D61Cu: goto label_19d61c;
            case 0x19D630u: goto label_19d630;
            case 0x19D640u: goto label_19d640;
            case 0x19D658u: goto label_19d658;
            case 0x19D65Cu: goto label_19d65c;
            case 0x19D6A4u: goto label_19d6a4;
            case 0x19D6B8u: goto label_19d6b8;
            case 0x19D6CCu: goto label_19d6cc;
            case 0x19D6D4u: goto label_19d6d4;
            case 0x19D6E8u: goto label_19d6e8;
            case 0x19D6F8u: goto label_19d6f8;
            case 0x19D710u: goto label_19d710;
            case 0x19D714u: goto label_19d714;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19D720u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
