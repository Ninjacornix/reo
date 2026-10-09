#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5A20
// Address: 0x1a5a20 - 0x1a5a9c
void sub_001A5A20_0x1a5a20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5A20_0x1a5a20");
#endif

    switch (ctx->pc) {
        case 0x1a5a34u: goto label_1a5a34;
        case 0x1a5a70u: goto label_1a5a70;
        default: break;
    }

    ctx->pc = 0x1a5a20u;

    // 0x1a5a20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a5a20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a5a24: 0x80582d  daddu       $t3, $a0, $zero
    ctx->pc = 0x1a5a24u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5a28: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a5a28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a5a2c: 0xc069630  jal         func_1A58C0
    ctx->pc = 0x1A5A2Cu;
    SET_GPR_U32(ctx, 31, 0x1A5A34u);
    ctx->pc = 0x1A5A30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5A2Cu;
            // 0x1a5a30: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A58C0u;
    if (runtime->hasFunction(0x1A58C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A58C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5A34u; }
        if (ctx->pc != 0x1A5A34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A58C0_0x1a58c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5A34u; }
        if (ctx->pc != 0x1A5A34u) { return; }
    }
    ctx->pc = 0x1A5A34u;
label_1a5a34:
    // 0x1a5a34: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1a5a34u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5a38: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x1a5a38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1a5a3c: 0x90420011  lbu         $v0, 0x11($v0)
    ctx->pc = 0x1a5a3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 17)));
    // 0x1a5a40: 0x28410002  slti        $at, $v0, 0x2
    ctx->pc = 0x1a5a40u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1a5a44: 0x14200008  bnez        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A5A44u;
    {
        const bool branch_taken_0x1a5a44 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A5A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5A44u;
            // 0x1a5a48: 0xe0302d  daddu       $a2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5a44) {
            ctx->pc = 0x1A5A68u;
            goto label_1a5a68;
        }
    }
    ctx->pc = 0x1A5A4Cu;
    // 0x1a5a4c: 0x28410005  slti        $at, $v0, 0x5
    ctx->pc = 0x1a5a4cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1a5a50: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A5A50u;
    {
        const bool branch_taken_0x1a5a50 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a5a50) {
            ctx->pc = 0x1A5A60u;
            goto label_1a5a60;
        }
    }
    ctx->pc = 0x1A5A58u;
    // 0x1a5a58: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A5A58u;
    {
        const bool branch_taken_0x1a5a58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5A58u;
            // 0x1a5a5c: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5a58) {
            ctx->pc = 0x1A5A64u;
            goto label_1a5a64;
        }
    }
    ctx->pc = 0x1A5A60u;
label_1a5a60:
    // 0x1a5a60: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1a5a60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1a5a64:
    // 0x1a5a64: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1a5a64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_1a5a68:
    // 0x1a5a68: 0xc069614  jal         func_1A5850
    ctx->pc = 0x1A5A68u;
    SET_GPR_U32(ctx, 31, 0x1A5A70u);
    ctx->pc = 0x1A5A6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5A68u;
            // 0x1a5a6c: 0x160202d  daddu       $a0, $t3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5850u;
    if (runtime->hasFunction(0x1A5850u)) {
        auto targetFn = runtime->lookupFunction(0x1A5850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5A70u; }
        if (ctx->pc != 0x1A5A70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5850_0x1a5850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5A70u; }
        if (ctx->pc != 0x1A5A70u) { return; }
    }
    ctx->pc = 0x1A5A70u;
label_1a5a70:
    // 0x1a5a70: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x1a5a70u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a5a74: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x1a5a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1a5a78: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A5A78u;
    {
        const bool branch_taken_0x1a5a78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a5a78) {
            ctx->pc = 0x1A5A8Cu;
            goto label_1a5a8c;
        }
    }
    ctx->pc = 0x1A5A80u;
    // 0x1a5a80: 0x8cc20008  lw          $v0, 0x8($a2)
    ctx->pc = 0x1a5a80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x1a5a84: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A5A84u;
    {
        const bool branch_taken_0x1a5a84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5A84u;
            // 0x1a5a88: 0xe21021  addu        $v0, $a3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5a84) {
            ctx->pc = 0x1A5A90u;
            goto label_1a5a90;
        }
    }
    ctx->pc = 0x1A5A8Cu;
label_1a5a8c:
    // 0x1a5a8c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a5a8cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a5a90:
    // 0x1a5a90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a5a90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5a94: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5A94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5A94u;
            // 0x1a5a98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5A34u: goto label_1a5a34;
            case 0x1A5A60u: goto label_1a5a60;
            case 0x1A5A64u: goto label_1a5a64;
            case 0x1A5A68u: goto label_1a5a68;
            case 0x1A5A70u: goto label_1a5a70;
            case 0x1A5A8Cu: goto label_1a5a8c;
            case 0x1A5A90u: goto label_1a5a90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5A9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
