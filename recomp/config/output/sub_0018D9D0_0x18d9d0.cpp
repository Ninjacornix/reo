#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018D9D0
// Address: 0x18d9d0 - 0x18dab0
void sub_0018D9D0_0x18d9d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018D9D0_0x18d9d0");
#endif

    switch (ctx->pc) {
        case 0x18da00u: goto label_18da00;
        case 0x18da08u: goto label_18da08;
        case 0x18da1cu: goto label_18da1c;
        case 0x18da24u: goto label_18da24;
        case 0x18da34u: goto label_18da34;
        case 0x18da3cu: goto label_18da3c;
        case 0x18da48u: goto label_18da48;
        case 0x18da58u: goto label_18da58;
        case 0x18da70u: goto label_18da70;
        case 0x18da80u: goto label_18da80;
        case 0x18da88u: goto label_18da88;
        case 0x18da90u: goto label_18da90;
        default: break;
    }

    ctx->pc = 0x18d9d0u;

    // 0x18d9d0: 0x27bdf7c0  addiu       $sp, $sp, -0x840
    ctx->pc = 0x18d9d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294965184));
    // 0x18d9d4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x18d9d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x18d9d8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18d9d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18d9dc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18d9dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18d9e0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x18d9e0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d9e4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18d9e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18d9e8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18d9e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18d9ec: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x18d9ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d9f0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x18d9f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d9f4: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x18d9f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x18d9f8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x18D9F8u;
    SET_GPR_U32(ctx, 31, 0x18DA00u);
    ctx->pc = 0x18D9FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D9F8u;
            // 0x18d9fc: 0x24a51c68  addiu       $a1, $a1, 0x1C68 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA00u; }
        if (ctx->pc != 0x18DA00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA00u; }
        if (ctx->pc != 0x18DA00u) { return; }
    }
    ctx->pc = 0x18DA00u;
label_18da00:
    // 0x18da00: 0xc042c56  jal         func_10B158
    ctx->pc = 0x18DA00u;
    SET_GPR_U32(ctx, 31, 0x18DA08u);
    ctx->pc = 0x18DA04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA00u;
            // 0x18da04: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA08u; }
        if (ctx->pc != 0x18DA08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA08u; }
        if (ctx->pc != 0x18DA08u) { return; }
    }
    ctx->pc = 0x18DA08u;
label_18da08:
    // 0x18da08: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x18da08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x18da0c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x18da0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18da10: 0x24500040  addiu       $s0, $v0, 0x40
    ctx->pc = 0x18da10u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x18da14: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x18DA14u;
    SET_GPR_U32(ctx, 31, 0x18DA1Cu);
    ctx->pc = 0x18DA18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA14u;
            // 0x18da18: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA1Cu; }
        if (ctx->pc != 0x18DA1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA1Cu; }
        if (ctx->pc != 0x18DA1Cu) { return; }
    }
    ctx->pc = 0x18DA1Cu;
label_18da1c:
    // 0x18da1c: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x18DA1Cu;
    SET_GPR_U32(ctx, 31, 0x18DA24u);
    ctx->pc = 0x18DA20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA1Cu;
            // 0x18da20: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA24u; }
        if (ctx->pc != 0x18DA24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA24u; }
        if (ctx->pc != 0x18DA24u) { return; }
    }
    ctx->pc = 0x18DA24u;
label_18da24:
    // 0x18da24: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18da24u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18da28: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x18da28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x18da2c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x18DA2Cu;
    SET_GPR_U32(ctx, 31, 0x18DA34u);
    ctx->pc = 0x18DA30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA2Cu;
            // 0x18da30: 0x24a51c70  addiu       $a1, $a1, 0x1C70 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA34u; }
        if (ctx->pc != 0x18DA34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA34u; }
        if (ctx->pc != 0x18DA34u) { return; }
    }
    ctx->pc = 0x18DA34u;
label_18da34:
    // 0x18da34: 0xc04af5e  jal         func_12BD78
    ctx->pc = 0x18DA34u;
    SET_GPR_U32(ctx, 31, 0x18DA3Cu);
    ctx->pc = 0x12BD78u;
    if (runtime->hasFunction(0x12BD78u)) {
        auto targetFn = runtime->lookupFunction(0x12BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA3Cu; }
        if (ctx->pc != 0x18DA3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD78_0x12bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA3Cu; }
        if (ctx->pc != 0x18DA3Cu) { return; }
    }
    ctx->pc = 0x18DA3Cu;
label_18da3c:
    // 0x18da3c: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x18da3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x18da40: 0xc04629c  jal         func_118A70
    ctx->pc = 0x18DA40u;
    SET_GPR_U32(ctx, 31, 0x18DA48u);
    ctx->pc = 0x18DA44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA40u;
            // 0x18da44: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA48u; }
        if (ctx->pc != 0x18DA48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA48u; }
        if (ctx->pc != 0x18DA48u) { return; }
    }
    ctx->pc = 0x18DA48u;
label_18da48:
    // 0x18da48: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18DA48u;
    {
        const bool branch_taken_0x18da48 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x18DA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA48u;
            // 0x18da4c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18da48) {
            ctx->pc = 0x18DA60u;
            goto label_18da60;
        }
    }
    ctx->pc = 0x18DA50u;
    // 0x18da50: 0xc04af64  jal         func_12BD90
    ctx->pc = 0x18DA50u;
    SET_GPR_U32(ctx, 31, 0x18DA58u);
    ctx->pc = 0x12BD90u;
    if (runtime->hasFunction(0x12BD90u)) {
        auto targetFn = runtime->lookupFunction(0x12BD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA58u; }
        if (ctx->pc != 0x18DA58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD90_0x12bd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA58u; }
        if (ctx->pc != 0x18DA58u) { return; }
    }
    ctx->pc = 0x18DA58u;
label_18da58:
    // 0x18da58: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x18DA58u;
    {
        const bool branch_taken_0x18da58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18DA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA58u;
            // 0x18da5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18da58) {
            ctx->pc = 0x18DA94u;
            goto label_18da94;
        }
    }
    ctx->pc = 0x18DA60u;
label_18da60:
    // 0x18da60: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18da60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18da64: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18da64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18da68: 0xc04639e  jal         func_118E78
    ctx->pc = 0x18DA68u;
    SET_GPR_U32(ctx, 31, 0x18DA70u);
    ctx->pc = 0x18DA6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA68u;
            // 0x18da6c: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA70u; }
        if (ctx->pc != 0x18DA70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA70u; }
        if (ctx->pc != 0x18DA70u) { return; }
    }
    ctx->pc = 0x18DA70u;
label_18da70:
    // 0x18da70: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x18da70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18da74: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x18da74u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18da78: 0xc0464c4  jal         func_119310
    ctx->pc = 0x18DA78u;
    SET_GPR_U32(ctx, 31, 0x18DA80u);
    ctx->pc = 0x18DA7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA78u;
            // 0x18da7c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119310u;
    if (runtime->hasFunction(0x119310u)) {
        auto targetFn = runtime->lookupFunction(0x119310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA80u; }
        if (ctx->pc != 0x18DA80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119310_0x119310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA80u; }
        if (ctx->pc != 0x18DA80u) { return; }
    }
    ctx->pc = 0x18DA80u;
label_18da80:
    // 0x18da80: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x18DA80u;
    SET_GPR_U32(ctx, 31, 0x18DA88u);
    ctx->pc = 0x18DA84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DA80u;
            // 0x18da84: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA88u; }
        if (ctx->pc != 0x18DA88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA88u; }
        if (ctx->pc != 0x18DA88u) { return; }
    }
    ctx->pc = 0x18DA88u;
label_18da88:
    // 0x18da88: 0xc04af64  jal         func_12BD90
    ctx->pc = 0x18DA88u;
    SET_GPR_U32(ctx, 31, 0x18DA90u);
    ctx->pc = 0x12BD90u;
    if (runtime->hasFunction(0x12BD90u)) {
        auto targetFn = runtime->lookupFunction(0x12BD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA90u; }
        if (ctx->pc != 0x18DA90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD90_0x12bd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DA90u; }
        if (ctx->pc != 0x18DA90u) { return; }
    }
    ctx->pc = 0x18DA90u;
label_18da90:
    // 0x18da90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18da90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_18da94:
    // 0x18da94: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x18da94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18da98: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18da98u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18da9c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18da9cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18daa0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18daa0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18daa4: 0x3e00008  jr          $ra
    ctx->pc = 0x18DAA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18DAA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DAA4u;
            // 0x18daa8: 0x27bd0840  addiu       $sp, $sp, 0x840 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 2112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DA00u: goto label_18da00;
            case 0x18DA08u: goto label_18da08;
            case 0x18DA1Cu: goto label_18da1c;
            case 0x18DA24u: goto label_18da24;
            case 0x18DA34u: goto label_18da34;
            case 0x18DA3Cu: goto label_18da3c;
            case 0x18DA48u: goto label_18da48;
            case 0x18DA58u: goto label_18da58;
            case 0x18DA60u: goto label_18da60;
            case 0x18DA70u: goto label_18da70;
            case 0x18DA80u: goto label_18da80;
            case 0x18DA88u: goto label_18da88;
            case 0x18DA90u: goto label_18da90;
            case 0x18DA94u: goto label_18da94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18DAACu;
    // 0x18daac: 0x0  nop
    ctx->pc = 0x18daacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
