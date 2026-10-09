#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171BE0
// Address: 0x171be0 - 0x171d10
void sub_00171BE0_0x171be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171BE0_0x171be0");
#endif

    switch (ctx->pc) {
        case 0x171c54u: goto label_171c54;
        case 0x171c64u: goto label_171c64;
        case 0x171c78u: goto label_171c78;
        case 0x171c94u: goto label_171c94;
        case 0x171ca4u: goto label_171ca4;
        case 0x171cb8u: goto label_171cb8;
        case 0x171cc8u: goto label_171cc8;
        case 0x171cd8u: goto label_171cd8;
        default: break;
    }

    ctx->pc = 0x171be0u;

    // 0x171be0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x171be0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x171be4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x171be4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171be8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x171be8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171bec: 0x120802d  daddu       $s0, $t1, $zero
    ctx->pc = 0x171becu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171bf0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x171bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x171bf4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x171bf4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171bf8: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x171bf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x171bfc: 0x160a82d  daddu       $s5, $t3, $zero
    ctx->pc = 0x171bfcu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171c00: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x171c00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x171c04: 0x215f021  addu        $fp, $s0, $s5
    ctx->pc = 0x171c04u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 21)));
    // 0x171c08: 0x2273821  addu        $a3, $s1, $a3
    ctx->pc = 0x171c08u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 7)));
    // 0x171c0c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x171c0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x171c10: 0xfe382a  slt         $a3, $a3, $fp
    ctx->pc = 0x171c10u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 30)) ? 1 : 0);
    // 0x171c14: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x171c14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x171c18: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x171c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x171c1c: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x171c1cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171c20: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x171c20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x171c24: 0x80b82d  daddu       $s7, $a0, $zero
    ctx->pc = 0x171c24u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171c28: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x171c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x171c2c: 0x211182a  slt         $v1, $s0, $s1
    ctx->pc = 0x171c2cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x171c30: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x171c30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x171c34: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x171c34u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171c38: 0x14e00028  bnez        $a3, . + 4 + (0x28 << 2)
    ctx->pc = 0x171C38u;
    {
        const bool branch_taken_0x171c38 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x171C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171C38u;
            // 0x171c3c: 0x140a02d  daddu       $s4, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171c38) {
            ctx->pc = 0x171CDCu;
            goto label_171cdc;
        }
    }
    ctx->pc = 0x171C40u;
    // 0x171c40: 0x5460000f  bnel        $v1, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x171C40u;
    {
        const bool branch_taken_0x171c40 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x171c40) {
            ctx->pc = 0x171C44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171C40u;
            // 0x171c44: 0x2309823  subu        $s3, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x171C80u;
            goto label_171c80;
        }
    }
    ctx->pc = 0x171C48u;
    // 0x171c48: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x171c48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171c4c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x171C4Cu;
    SET_GPR_U32(ctx, 31, 0x171C54u);
    ctx->pc = 0x171C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171C4Cu;
            // 0x171c50: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171C54u; }
        if (ctx->pc != 0x171C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171C54u; }
        if (ctx->pc != 0x171C54u) { return; }
    }
    ctx->pc = 0x171C54u;
label_171c54:
    // 0x171c54: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x171c54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171c58: 0x2512821  addu        $a1, $s2, $s1
    ctx->pc = 0x171c58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x171c5c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x171C5Cu;
    SET_GPR_U32(ctx, 31, 0x171C64u);
    ctx->pc = 0x171C60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171C5Cu;
            // 0x171c60: 0x2113023  subu        $a2, $s0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171C64u; }
        if (ctx->pc != 0x171C64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171C64u; }
        if (ctx->pc != 0x171C64u) { return; }
    }
    ctx->pc = 0x171C64u;
label_171c64:
    // 0x171c64: 0x2d02021  addu        $a0, $s6, $s0
    ctx->pc = 0x171c64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 16)));
    // 0x171c68: 0x912023  subu        $a0, $a0, $s1
    ctx->pc = 0x171c68u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x171c6c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x171c6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171c70: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x171C70u;
    SET_GPR_U32(ctx, 31, 0x171C78u);
    ctx->pc = 0x171C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171C70u;
            // 0x171c74: 0x2a0302d  daddu       $a2, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171C78u; }
        if (ctx->pc != 0x171C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171C78u; }
        if (ctx->pc != 0x171C78u) { return; }
    }
    ctx->pc = 0x171C78u;
label_171c78:
    // 0x171c78: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x171C78u;
    {
        const bool branch_taken_0x171c78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171C78u;
            // 0x171c7c: 0x3c0102d  daddu       $v0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171c78) {
            ctx->pc = 0x171CDCu;
            goto label_171cdc;
        }
    }
    ctx->pc = 0x171C80u;
label_171c80:
    // 0x171c80: 0x2b3102a  slt         $v0, $s5, $s3
    ctx->pc = 0x171c80u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x171c84: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x171C84u;
    {
        const bool branch_taken_0x171c84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x171C88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171C84u;
            // 0x171c88: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171c84) {
            ctx->pc = 0x171CC0u;
            goto label_171cc0;
        }
    }
    ctx->pc = 0x171C8Cu;
    // 0x171c8c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x171C8Cu;
    SET_GPR_U32(ctx, 31, 0x171C94u);
    ctx->pc = 0x171C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171C8Cu;
            // 0x171c90: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171C94u; }
        if (ctx->pc != 0x171C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171C94u; }
        if (ctx->pc != 0x171C94u) { return; }
    }
    ctx->pc = 0x171C94u;
label_171c94:
    // 0x171c94: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x171c94u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171c98: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x171c98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171c9c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x171C9Cu;
    SET_GPR_U32(ctx, 31, 0x171CA4u);
    ctx->pc = 0x171CA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171C9Cu;
            // 0x171ca0: 0x2f02021  addu        $a0, $s7, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171CA4u; }
        if (ctx->pc != 0x171CA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171CA4u; }
        if (ctx->pc != 0x171CA4u) { return; }
    }
    ctx->pc = 0x171CA4u;
label_171ca4:
    // 0x171ca4: 0x2912821  addu        $a1, $s4, $s1
    ctx->pc = 0x171ca4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 17)));
    // 0x171ca8: 0xb02823  subu        $a1, $a1, $s0
    ctx->pc = 0x171ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x171cac: 0x2b33023  subu        $a2, $s5, $s3
    ctx->pc = 0x171cacu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 19)));
    // 0x171cb0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x171CB0u;
    SET_GPR_U32(ctx, 31, 0x171CB8u);
    ctx->pc = 0x171CB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171CB0u;
            // 0x171cb4: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171CB8u; }
        if (ctx->pc != 0x171CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171CB8u; }
        if (ctx->pc != 0x171CB8u) { return; }
    }
    ctx->pc = 0x171CB8u;
label_171cb8:
    // 0x171cb8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x171CB8u;
    {
        const bool branch_taken_0x171cb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171CB8u;
            // 0x171cbc: 0x3c0102d  daddu       $v0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171cb8) {
            ctx->pc = 0x171CDCu;
            goto label_171cdc;
        }
    }
    ctx->pc = 0x171CC0u;
label_171cc0:
    // 0x171cc0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x171CC0u;
    SET_GPR_U32(ctx, 31, 0x171CC8u);
    ctx->pc = 0x171CC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171CC0u;
            // 0x171cc4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171CC8u; }
        if (ctx->pc != 0x171CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171CC8u; }
        if (ctx->pc != 0x171CC8u) { return; }
    }
    ctx->pc = 0x171CC8u;
label_171cc8:
    // 0x171cc8: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x171cc8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171ccc: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x171cccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171cd0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x171CD0u;
    SET_GPR_U32(ctx, 31, 0x171CD8u);
    ctx->pc = 0x171CD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171CD0u;
            // 0x171cd4: 0x2f02021  addu        $a0, $s7, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171CD8u; }
        if (ctx->pc != 0x171CD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171CD8u; }
        if (ctx->pc != 0x171CD8u) { return; }
    }
    ctx->pc = 0x171CD8u;
label_171cd8:
    // 0x171cd8: 0x3c0102d  daddu       $v0, $fp, $zero
    ctx->pc = 0x171cd8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
label_171cdc:
    // 0x171cdc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x171cdcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171ce0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x171ce0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171ce4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x171ce4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171ce8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x171ce8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x171cec: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x171cecu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x171cf0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x171cf0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x171cf4: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x171cf4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x171cf8: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x171cf8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x171cfc: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x171cfcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x171d00: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x171d00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x171d04: 0x3e00008  jr          $ra
    ctx->pc = 0x171D04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171D04u;
            // 0x171d08: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171C54u: goto label_171c54;
            case 0x171C64u: goto label_171c64;
            case 0x171C78u: goto label_171c78;
            case 0x171C80u: goto label_171c80;
            case 0x171C94u: goto label_171c94;
            case 0x171CA4u: goto label_171ca4;
            case 0x171CB8u: goto label_171cb8;
            case 0x171CC0u: goto label_171cc0;
            case 0x171CC8u: goto label_171cc8;
            case 0x171CD8u: goto label_171cd8;
            case 0x171CDCu: goto label_171cdc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171D0Cu;
    // 0x171d0c: 0x0  nop
    ctx->pc = 0x171d0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
