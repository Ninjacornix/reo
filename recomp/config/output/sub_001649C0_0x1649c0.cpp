#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001649C0
// Address: 0x1649c0 - 0x164af8
void sub_001649C0_0x1649c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001649C0_0x1649c0");
#endif

    switch (ctx->pc) {
        case 0x1649f8u: goto label_1649f8;
        case 0x164a04u: goto label_164a04;
        case 0x164a84u: goto label_164a84;
        case 0x164a94u: goto label_164a94;
        case 0x164ab0u: goto label_164ab0;
        case 0x164abcu: goto label_164abc;
        case 0x164ac8u: goto label_164ac8;
        case 0x164ad0u: goto label_164ad0;
        case 0x164ad8u: goto label_164ad8;
        case 0x164ae0u: goto label_164ae0;
        default: break;
    }

    ctx->pc = 0x1649c0u;

label_1649c0:
    // 0x1649c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1649c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1649c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1649c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1649c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1649c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1649cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1649ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1649d0: 0x26020cc0  addiu       $v0, $s0, 0xCC0
    ctx->pc = 0x1649d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
    // 0x1649d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1649d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1649d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1649d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1649dc: 0x8e041b74  lw          $a0, 0x1B74($s0)
    ctx->pc = 0x1649dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7028)));
    // 0x1649e0: 0x8c4501b4  lw          $a1, 0x1B4($v0)
    ctx->pc = 0x1649e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 436)));
    // 0x1649e4: 0x8c4301b0  lw          $v1, 0x1B0($v0)
    ctx->pc = 0x1649e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 432)));
    // 0x1649e8: 0x14650013  bne         $v1, $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1649E8u;
    {
        const bool branch_taken_0x1649e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1649ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1649E8u;
            // 0x1649ec: 0x8c910000  lw          $s1, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1649e8) {
            ctx->pc = 0x164A38u;
            goto label_164a38;
        }
    }
    ctx->pc = 0x1649F0u;
    // 0x1649f0: 0xc04c92a  jal         func_1324A8
    ctx->pc = 0x1649F0u;
    SET_GPR_U32(ctx, 31, 0x1649F8u);
    ctx->pc = 0x1649F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1649F0u;
            // 0x1649f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1324A8u;
    if (runtime->hasFunction(0x1324A8u)) {
        auto targetFn = runtime->lookupFunction(0x1324A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649F8u; }
        if (ctx->pc != 0x1649F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001324A8_0x1324a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649F8u; }
        if (ctx->pc != 0x1649F8u) { return; }
    }
    ctx->pc = 0x1649F8u;
label_1649f8:
    // 0x1649f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1649f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1649fc: 0xc04c93e  jal         func_1324F8
    ctx->pc = 0x1649FCu;
    SET_GPR_U32(ctx, 31, 0x164A04u);
    ctx->pc = 0x164A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1649FCu;
            // 0x164a00: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1324F8u;
    if (runtime->hasFunction(0x1324F8u)) {
        auto targetFn = runtime->lookupFunction(0x1324F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164A04u; }
        if (ctx->pc != 0x164A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001324F8_0x1324f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164A04u; }
        if (ctx->pc != 0x164A04u) { return; }
    }
    ctx->pc = 0x164A04u;
label_164a04:
    // 0x164a04: 0x5a40000d  blezl       $s2, . + 4 + (0xD << 2)
    ctx->pc = 0x164A04u;
    {
        const bool branch_taken_0x164a04 = (GPR_S64(ctx, 18) <= 0);
        if (branch_taken_0x164a04) {
            ctx->pc = 0x164A08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164A04u;
            // 0x164a08: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x164A3Cu;
            goto label_164a3c;
        }
    }
    ctx->pc = 0x164A0Cu;
    // 0x164a0c: 0x5840000b  blezl       $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x164A0Cu;
    {
        const bool branch_taken_0x164a0c = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x164a0c) {
            ctx->pc = 0x164A10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164A0Cu;
            // 0x164a10: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x164A3Cu;
            goto label_164a3c;
        }
    }
    ctx->pc = 0x164A14u;
    // 0x164a14: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x164a14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164a18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x164a18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164a1c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x164a1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164a20: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x164a20u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164a24: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x164a24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164a28: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x164a28u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164a2c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x164a2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x164a30: 0x8059fc2  j           func_167F08
    ctx->pc = 0x164A30u;
    ctx->pc = 0x164A34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164A30u;
            // 0x164a34: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167F08u;
    if (runtime->hasFunction(0x167F08u)) {
        auto targetFn = runtime->lookupFunction(0x167F08u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00167F08_0x167f08(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x164A38u;
label_164a38:
    // 0x164a38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x164a38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_164a3c:
    // 0x164a3c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x164a3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164a40: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x164a40u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164a44: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x164a44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x164a48: 0x3e00008  jr          $ra
    ctx->pc = 0x164A48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164A48u;
            // 0x164a4c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1649C0u: goto label_1649c0;
            case 0x1649F8u: goto label_1649f8;
            case 0x164A04u: goto label_164a04;
            case 0x164A38u: goto label_164a38;
            case 0x164A3Cu: goto label_164a3c;
            case 0x164A68u: goto label_164a68;
            case 0x164A84u: goto label_164a84;
            case 0x164A94u: goto label_164a94;
            case 0x164AA8u: goto label_164aa8;
            case 0x164AB0u: goto label_164ab0;
            case 0x164ABCu: goto label_164abc;
            case 0x164AC8u: goto label_164ac8;
            case 0x164AD0u: goto label_164ad0;
            case 0x164AD8u: goto label_164ad8;
            case 0x164AE0u: goto label_164ae0;
            case 0x164AE4u: goto label_164ae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164A50u;
    // 0x164a50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164a54: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164a54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164a58: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164a58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164a5c: 0x805929a  j           func_164A68
    ctx->pc = 0x164A5Cu;
    ctx->pc = 0x164A60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164A5Cu;
            // 0x164a60: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164A68u;
    goto label_164a68;
    ctx->pc = 0x164A64u;
    // 0x164a64: 0x0  nop
    ctx->pc = 0x164a64u;
    // NOP
label_164a68:
    // 0x164a68: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x164a68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x164a6c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x164a6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x164a70: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x164a70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x164a74: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x164a74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x164a78: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x164a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x164a7c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x164A7Cu;
    SET_GPR_U32(ctx, 31, 0x164A84u);
    ctx->pc = 0x164A80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164A7Cu;
            // 0x164a80: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164A84u; }
        if (ctx->pc != 0x164A84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164A84u; }
        if (ctx->pc != 0x164A84u) { return; }
    }
    ctx->pc = 0x164A84u;
label_164a84:
    // 0x164a84: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x164A84u;
    {
        const bool branch_taken_0x164a84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x164A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164A84u;
            // 0x164a88: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164a84) {
            ctx->pc = 0x164AE4u;
            goto label_164ae4;
        }
    }
    ctx->pc = 0x164A8Cu;
    // 0x164a8c: 0xc05957e  jal         func_1655F8
    ctx->pc = 0x164A8Cu;
    SET_GPR_U32(ctx, 31, 0x164A94u);
    ctx->pc = 0x1655F8u;
    if (runtime->hasFunction(0x1655F8u)) {
        auto targetFn = runtime->lookupFunction(0x1655F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164A94u; }
        if (ctx->pc != 0x164A94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001655F8_0x1655f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164A94u; }
        if (ctx->pc != 0x164A94u) { return; }
    }
    ctx->pc = 0x164A94u;
label_164a94:
    // 0x164a94: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x164a94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x164a98: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x164A98u;
    {
        const bool branch_taken_0x164a98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x164A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164A98u;
            // 0x164a9c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164a98) {
            ctx->pc = 0x164AA8u;
            goto label_164aa8;
        }
    }
    ctx->pc = 0x164AA0u;
    // 0x164aa0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x164AA0u;
    {
        const bool branch_taken_0x164aa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x164AA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164AA0u;
            // 0x164aa4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164aa0) {
            ctx->pc = 0x164AE4u;
            goto label_164ae4;
        }
    }
    ctx->pc = 0x164AA8u;
label_164aa8:
    // 0x164aa8: 0xc0592be  jal         func_164AF8
    ctx->pc = 0x164AA8u;
    SET_GPR_U32(ctx, 31, 0x164AB0u);
    ctx->pc = 0x164AACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164AA8u;
            // 0x164aac: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164AF8u;
    if (runtime->hasFunction(0x164AF8u)) {
        auto targetFn = runtime->lookupFunction(0x164AF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164AB0u; }
        if (ctx->pc != 0x164AB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164AF8_0x164af8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164AB0u; }
        if (ctx->pc != 0x164AB0u) { return; }
    }
    ctx->pc = 0x164AB0u;
label_164ab0:
    // 0x164ab0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x164ab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164ab4: 0xc0594c6  jal         func_165318
    ctx->pc = 0x164AB4u;
    SET_GPR_U32(ctx, 31, 0x164ABCu);
    ctx->pc = 0x164AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164AB4u;
            // 0x164ab8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165318u;
    if (runtime->hasFunction(0x165318u)) {
        auto targetFn = runtime->lookupFunction(0x165318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164ABCu; }
        if (ctx->pc != 0x164ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165318_0x165318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164ABCu; }
        if (ctx->pc != 0x164ABCu) { return; }
    }
    ctx->pc = 0x164ABCu;
label_164abc:
    // 0x164abc: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x164abcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164ac0: 0xc0594fa  jal         func_1653E8
    ctx->pc = 0x164AC0u;
    SET_GPR_U32(ctx, 31, 0x164AC8u);
    ctx->pc = 0x164AC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164AC0u;
            // 0x164ac4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1653E8u;
    if (runtime->hasFunction(0x1653E8u)) {
        auto targetFn = runtime->lookupFunction(0x1653E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164AC8u; }
        if (ctx->pc != 0x164AC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001653E8_0x1653e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164AC8u; }
        if (ctx->pc != 0x164AC8u) { return; }
    }
    ctx->pc = 0x164AC8u;
label_164ac8:
    // 0x164ac8: 0xc05958c  jal         func_165630
    ctx->pc = 0x164AC8u;
    SET_GPR_U32(ctx, 31, 0x164AD0u);
    ctx->pc = 0x164ACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164AC8u;
            // 0x164acc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165630u;
    if (runtime->hasFunction(0x165630u)) {
        auto targetFn = runtime->lookupFunction(0x165630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164AD0u; }
        if (ctx->pc != 0x164AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165630_0x165630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164AD0u; }
        if (ctx->pc != 0x164AD0u) { return; }
    }
    ctx->pc = 0x164AD0u;
label_164ad0:
    // 0x164ad0: 0xc0595c4  jal         func_165710
    ctx->pc = 0x164AD0u;
    SET_GPR_U32(ctx, 31, 0x164AD8u);
    ctx->pc = 0x164AD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164AD0u;
            // 0x164ad4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165710u;
    if (runtime->hasFunction(0x165710u)) {
        auto targetFn = runtime->lookupFunction(0x165710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164AD8u; }
        if (ctx->pc != 0x164AD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165710_0x165710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164AD8u; }
        if (ctx->pc != 0x164AD8u) { return; }
    }
    ctx->pc = 0x164AD8u;
label_164ad8:
    // 0x164ad8: 0xc059270  jal         func_1649C0
    ctx->pc = 0x164AD8u;
    SET_GPR_U32(ctx, 31, 0x164AE0u);
    ctx->pc = 0x164ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164AD8u;
            // 0x164adc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1649C0u;
    goto label_1649c0;
    ctx->pc = 0x164AE0u;
label_164ae0:
    // 0x164ae0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x164ae0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_164ae4:
    // 0x164ae4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x164ae4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164ae8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x164ae8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x164aec: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x164aecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x164af0: 0x3e00008  jr          $ra
    ctx->pc = 0x164AF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164AF0u;
            // 0x164af4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1649C0u: goto label_1649c0;
            case 0x1649F8u: goto label_1649f8;
            case 0x164A04u: goto label_164a04;
            case 0x164A38u: goto label_164a38;
            case 0x164A3Cu: goto label_164a3c;
            case 0x164A68u: goto label_164a68;
            case 0x164A84u: goto label_164a84;
            case 0x164A94u: goto label_164a94;
            case 0x164AA8u: goto label_164aa8;
            case 0x164AB0u: goto label_164ab0;
            case 0x164ABCu: goto label_164abc;
            case 0x164AC8u: goto label_164ac8;
            case 0x164AD0u: goto label_164ad0;
            case 0x164AD8u: goto label_164ad8;
            case 0x164AE0u: goto label_164ae0;
            case 0x164AE4u: goto label_164ae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164AF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
