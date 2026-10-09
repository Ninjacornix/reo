#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140A20
// Address: 0x140a20 - 0x140b98
void sub_00140A20_0x140a20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140A20_0x140a20");
#endif

    switch (ctx->pc) {
        case 0x140a68u: goto label_140a68;
        case 0x140a78u: goto label_140a78;
        case 0x140a88u: goto label_140a88;
        case 0x140aacu: goto label_140aac;
        case 0x140ac4u: goto label_140ac4;
        case 0x140b30u: goto label_140b30;
        case 0x140b84u: goto label_140b84;
        default: break;
    }

    ctx->pc = 0x140a20u;

    // 0x140a20: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x140a20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x140a24: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x140a24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x140a28: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x140a28u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140a2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140a30: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x140a30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x140a34: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x140a34u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140a38: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x140a38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x140a3c: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x140a3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x140a40: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x140a40u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140a44: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x140a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140a48: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x140a48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x140a4c: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x140a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x140a50: 0xae600004  sw          $zero, 0x4($s3)
    ctx->pc = 0x140a50u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 0));
    // 0x140a54: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x140a54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x140a58: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x140a58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x140a5c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x140a5cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140a60: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x140A60u;
    {
        const bool branch_taken_0x140a60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140A60u;
            // 0x140a64: 0x43a021  addu        $s4, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140a60) {
            ctx->pc = 0x140A90u;
            goto label_140a90;
        }
    }
    ctx->pc = 0x140A68u;
label_140a68:
    // 0x140a68: 0x12400005  beqz        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x140A68u;
    {
        const bool branch_taken_0x140a68 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x140a68) {
            ctx->pc = 0x140A80u;
            goto label_140a80;
        }
    }
    ctx->pc = 0x140A70u;
    // 0x140a70: 0xc042d10  jal         func_10B440
    ctx->pc = 0x140A70u;
    SET_GPR_U32(ctx, 31, 0x140A78u);
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140A78u; }
        if (ctx->pc != 0x140A78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140A78u; }
        if (ctx->pc != 0x140A78u) { return; }
    }
    ctx->pc = 0x140A78u;
label_140a78:
    // 0x140a78: 0x50400015  beql        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x140A78u;
    {
        const bool branch_taken_0x140a78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140a78) {
            ctx->pc = 0x140A7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140A78u;
            // 0x140a7c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140AD0u;
            goto label_140ad0;
        }
    }
    ctx->pc = 0x140A80u;
label_140a80:
    // 0x140a80: 0xc050236  jal         func_1408D8
    ctx->pc = 0x140A80u;
    SET_GPR_U32(ctx, 31, 0x140A88u);
    ctx->pc = 0x140A84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140A80u;
            // 0x140a84: 0x26040008  addiu       $a0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1408D8u;
    if (runtime->hasFunction(0x1408D8u)) {
        auto targetFn = runtime->lookupFunction(0x1408D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140A88u; }
        if (ctx->pc != 0x140A88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001408D8_0x1408d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140A88u; }
        if (ctx->pc != 0x140A88u) { return; }
    }
    ctx->pc = 0x140A88u;
label_140a88:
    // 0x140a88: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x140a88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x140a8c: 0x24500010  addiu       $s0, $v0, 0x10
    ctx->pc = 0x140a8cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
label_140a90:
    // 0x140a90: 0x214882b  sltu        $s1, $s0, $s4
    ctx->pc = 0x140a90u;
    SET_GPR_U64(ctx, 17, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 20)) ? 1 : 0);
    // 0x140a94: 0x1220000c  beqz        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x140A94u;
    {
        const bool branch_taken_0x140a94 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x140A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140A94u;
            // 0x140a98: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140a94) {
            ctx->pc = 0x140AC8u;
            goto label_140ac8;
        }
    }
    ctx->pc = 0x140A9Cu;
    // 0x140a9c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x140a9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140aa0: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x140aa0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140aa4: 0xc042d10  jal         func_10B440
    ctx->pc = 0x140AA4u;
    SET_GPR_U32(ctx, 31, 0x140AACu);
    ctx->pc = 0x140AA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140AA4u;
            // 0x140aa8: 0x24060007  addiu       $a2, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140AACu; }
        if (ctx->pc != 0x140AACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140AACu; }
        if (ctx->pc != 0x140AACu) { return; }
    }
    ctx->pc = 0x140AACu;
label_140aac:
    // 0x140aac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x140aacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140ab0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x140ab0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140ab4: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x140AB4u;
    {
        const bool branch_taken_0x140ab4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x140AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140AB4u;
            // 0x140ab8: 0x24060007  addiu       $a2, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140ab4) {
            ctx->pc = 0x140A68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_140a68;
        }
    }
    ctx->pc = 0x140ABCu;
    // 0x140abc: 0xc05027a  jal         func_1409E8
    ctx->pc = 0x140ABCu;
    SET_GPR_U32(ctx, 31, 0x140AC4u);
    ctx->pc = 0x140AC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140ABCu;
            // 0x140ac0: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1409E8u;
    if (runtime->hasFunction(0x1409E8u)) {
        auto targetFn = runtime->lookupFunction(0x1409E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140AC4u; }
        if (ctx->pc != 0x140AC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001409E8_0x1409e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140AC4u; }
        if (ctx->pc != 0x140AC4u) { return; }
    }
    ctx->pc = 0x140AC4u;
label_140ac4:
    // 0x140ac4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x140ac4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_140ac8:
    // 0x140ac8: 0x211100b  movn        $v0, $s0, $s1
    ctx->pc = 0x140ac8u;
    if (GPR_U64(ctx, 17) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 16));
    // 0x140acc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140accu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_140ad0:
    // 0x140ad0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140ad0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140ad4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x140ad4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140ad8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x140ad8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x140adc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x140adcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x140ae0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x140ae0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x140ae4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x140ae4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x140ae8: 0x3e00008  jr          $ra
    ctx->pc = 0x140AE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140AE8u;
            // 0x140aec: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140A68u: goto label_140a68;
            case 0x140A78u: goto label_140a78;
            case 0x140A80u: goto label_140a80;
            case 0x140A88u: goto label_140a88;
            case 0x140A90u: goto label_140a90;
            case 0x140AACu: goto label_140aac;
            case 0x140AC4u: goto label_140ac4;
            case 0x140AC8u: goto label_140ac8;
            case 0x140AD0u: goto label_140ad0;
            case 0x140B30u: goto label_140b30;
            case 0x140B84u: goto label_140b84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140AF0u;
    // 0x140af0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140af0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140af4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140af4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140af8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140af8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140afc: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140afcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140b00: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140b00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140b04: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x140b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140b08: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140b08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140b0c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140b0cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140b10: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140b10u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140b14: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140b14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140b18: 0xac460008  sw          $a2, 0x8($v0)
    ctx->pc = 0x140b18u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 6));
    // 0x140b1c: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x140b1cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x140b20: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140b20u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140b24: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x140b24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x140b28: 0xc04e518  jal         func_139460
    ctx->pc = 0x140B28u;
    SET_GPR_U32(ctx, 31, 0x140B30u);
    ctx->pc = 0x140B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140B28u;
            // 0x140b2c: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140B30u; }
        if (ctx->pc != 0x140B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140B30u; }
        if (ctx->pc != 0x140B30u) { return; }
    }
    ctx->pc = 0x140B30u;
label_140b30:
    // 0x140b30: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x140b30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140b34: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140b34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140b38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140b38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140b3c: 0x3e00008  jr          $ra
    ctx->pc = 0x140B3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140B3Cu;
            // 0x140b40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140A68u: goto label_140a68;
            case 0x140A78u: goto label_140a78;
            case 0x140A80u: goto label_140a80;
            case 0x140A88u: goto label_140a88;
            case 0x140A90u: goto label_140a90;
            case 0x140AACu: goto label_140aac;
            case 0x140AC4u: goto label_140ac4;
            case 0x140AC8u: goto label_140ac8;
            case 0x140AD0u: goto label_140ad0;
            case 0x140B30u: goto label_140b30;
            case 0x140B84u: goto label_140b84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140B44u;
    // 0x140b44: 0x0  nop
    ctx->pc = 0x140b44u;
    // NOP
    // 0x140b48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140b4c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140b50: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140b50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140b54: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140b54u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140b58: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140b5c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x140b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140b60: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140b60u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140b64: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140b64u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140b68: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140b68u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140b6c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140b6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140b70: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140b70u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140b74: 0x24040021  addiu       $a0, $zero, 0x21
    ctx->pc = 0x140b74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x140b78: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x140b78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x140b7c: 0xc04e518  jal         func_139460
    ctx->pc = 0x140B7Cu;
    SET_GPR_U32(ctx, 31, 0x140B84u);
    ctx->pc = 0x140B80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140B7Cu;
            // 0x140b80: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140B84u; }
        if (ctx->pc != 0x140B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140B84u; }
        if (ctx->pc != 0x140B84u) { return; }
    }
    ctx->pc = 0x140B84u;
label_140b84:
    // 0x140b84: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x140b84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140b88: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140b88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140b8c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140b8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140b90: 0x3e00008  jr          $ra
    ctx->pc = 0x140B90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140B94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140B90u;
            // 0x140b94: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140A68u: goto label_140a68;
            case 0x140A78u: goto label_140a78;
            case 0x140A80u: goto label_140a80;
            case 0x140A88u: goto label_140a88;
            case 0x140A90u: goto label_140a90;
            case 0x140AACu: goto label_140aac;
            case 0x140AC4u: goto label_140ac4;
            case 0x140AC8u: goto label_140ac8;
            case 0x140AD0u: goto label_140ad0;
            case 0x140B30u: goto label_140b30;
            case 0x140B84u: goto label_140b84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140B98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
