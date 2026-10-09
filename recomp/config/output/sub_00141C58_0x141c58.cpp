#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141C58
// Address: 0x141c58 - 0x141d18
void sub_00141C58_0x141c58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141C58_0x141c58");
#endif

    switch (ctx->pc) {
        case 0x141c94u: goto label_141c94;
        case 0x141cb0u: goto label_141cb0;
        case 0x141cb8u: goto label_141cb8;
        case 0x141cf0u: goto label_141cf0;
        default: break;
    }

    ctx->pc = 0x141c58u;

    // 0x141c58: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x141c58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x141c5c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141c5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141c60: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x141c60u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141c64: 0x2e220006  sltiu       $v0, $s1, 0x6
    ctx->pc = 0x141c64u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x141c68: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141c68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141c6c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x141c6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x141c70: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x141c70u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141c74: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x141c74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x141c78: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x141c78u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141c7c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x141c7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x141c80: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x141C80u;
    {
        const bool branch_taken_0x141c80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x141C84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141C80u;
            // 0x141c84: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141c80) {
            ctx->pc = 0x141C94u;
            goto label_141c94;
        }
    }
    ctx->pc = 0x141C88u;
    // 0x141c88: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x141c88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x141c8c: 0xc05062a  jal         func_1418A8
    ctx->pc = 0x141C8Cu;
    SET_GPR_U32(ctx, 31, 0x141C94u);
    ctx->pc = 0x141C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141C8Cu;
            // 0x141c90: 0x2484dc48  addiu       $a0, $a0, -0x23B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294958152));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1418A8u;
    if (runtime->hasFunction(0x1418A8u)) {
        auto targetFn = runtime->lookupFunction(0x1418A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141C94u; }
        if (ctx->pc != 0x141C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001418A8_0x1418a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141C94u; }
        if (ctx->pc != 0x141C94u) { return; }
    }
    ctx->pc = 0x141C94u;
label_141c94:
    // 0x141c94: 0x6000003  bltz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x141C94u;
    {
        const bool branch_taken_0x141c94 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x141C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141C94u;
            // 0x141c98: 0x2a220008  slti        $v0, $s1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x141c94) {
            ctx->pc = 0x141CA4u;
            goto label_141ca4;
        }
    }
    ctx->pc = 0x141C9Cu;
    // 0x141c9c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x141C9Cu;
    {
        const bool branch_taken_0x141c9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x141c9c) {
            ctx->pc = 0x141CB0u;
            goto label_141cb0;
        }
    }
    ctx->pc = 0x141CA4u;
label_141ca4:
    // 0x141ca4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x141ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x141ca8: 0xc05062a  jal         func_1418A8
    ctx->pc = 0x141CA8u;
    SET_GPR_U32(ctx, 31, 0x141CB0u);
    ctx->pc = 0x141CACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141CA8u;
            // 0x141cac: 0x2484dc70  addiu       $a0, $a0, -0x2390 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294958192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1418A8u;
    if (runtime->hasFunction(0x1418A8u)) {
        auto targetFn = runtime->lookupFunction(0x1418A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141CB0u; }
        if (ctx->pc != 0x141CB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001418A8_0x1418a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141CB0u; }
        if (ctx->pc != 0x141CB0u) { return; }
    }
    ctx->pc = 0x141CB0u;
label_141cb0:
    // 0x141cb0: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x141CB0u;
    SET_GPR_U32(ctx, 31, 0x141CB8u);
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141CB8u; }
        if (ctx->pc != 0x141CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141CB8u; }
        if (ctx->pc != 0x141CB8u) { return; }
    }
    ctx->pc = 0x141CB8u;
label_141cb8:
    // 0x141cb8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x141cb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x141cbc: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x141cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x141cc0: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x141cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x141cc4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x141cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x141cc8: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x141cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x141ccc: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x141cccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x141cd0: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x141cd0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x141cd4: 0x26104820  addiu       $s0, $s0, 0x4820
    ctx->pc = 0x141cd4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18464));
    // 0x141cd8: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x141cd8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x141cdc: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x141cdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x141ce0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x141CE0u;
    {
        const bool branch_taken_0x141ce0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x141CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141CE0u;
            // 0x141ce4: 0x2484dc98  addiu       $a0, $a0, -0x2368 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294958232));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141ce0) {
            ctx->pc = 0x141CF0u;
            goto label_141cf0;
        }
    }
    ctx->pc = 0x141CE8u;
    // 0x141ce8: 0xc05062a  jal         func_1418A8
    ctx->pc = 0x141CE8u;
    SET_GPR_U32(ctx, 31, 0x141CF0u);
    ctx->pc = 0x1418A8u;
    if (runtime->hasFunction(0x1418A8u)) {
        auto targetFn = runtime->lookupFunction(0x1418A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141CF0u; }
        if (ctx->pc != 0x141CF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001418A8_0x1418a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141CF0u; }
        if (ctx->pc != 0x141CF0u) { return; }
    }
    ctx->pc = 0x141CF0u;
label_141cf0:
    // 0x141cf0: 0xae120004  sw          $s2, 0x4($s0)
    ctx->pc = 0x141cf0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 18));
    // 0x141cf4: 0xae130000  sw          $s3, 0x0($s0)
    ctx->pc = 0x141cf4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 19));
    // 0x141cf8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141cf8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141cfc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141cfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141d00: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x141d00u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141d04: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x141d04u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x141d08: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x141d08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x141d0c: 0x80505ba  j           func_1416E8
    ctx->pc = 0x141D0Cu;
    ctx->pc = 0x141D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141D0Cu;
            // 0x141d10: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141D14u;
    // 0x141d14: 0x0  nop
    ctx->pc = 0x141d14u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
