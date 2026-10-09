#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00145B58
// Address: 0x145b58 - 0x145bd8
void sub_00145B58_0x145b58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00145B58_0x145b58");
#endif

    switch (ctx->pc) {
        case 0x145b70u: goto label_145b70;
        case 0x145b98u: goto label_145b98;
        case 0x145ba0u: goto label_145ba0;
        case 0x145ba8u: goto label_145ba8;
        case 0x145bb4u: goto label_145bb4;
        default: break;
    }

    ctx->pc = 0x145b58u;

    // 0x145b58: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x145b58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x145b5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x145b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x145b60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x145b60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145b64: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x145b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x145b68: 0xc051496  jal         func_145258
    ctx->pc = 0x145B68u;
    SET_GPR_U32(ctx, 31, 0x145B70u);
    ctx->pc = 0x145B6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145B68u;
            // 0x145b6c: 0xffb10010  sd          $s1, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145258u;
    if (runtime->hasFunction(0x145258u)) {
        auto targetFn = runtime->lookupFunction(0x145258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145B70u; }
        if (ctx->pc != 0x145B70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145B70u; }
        if (ctx->pc != 0x145B70u) { return; }
    }
    ctx->pc = 0x145B70u;
label_145b70:
    // 0x145b70: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x145b70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x145b74: 0x34422020  ori         $v0, $v0, 0x2020
    ctx->pc = 0x145b74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8224);
    // 0x145b78: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x145b78u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x145b7c: 0x30630007  andi        $v1, $v1, 0x7
    ctx->pc = 0x145b7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
    // 0x145b80: 0x31823  negu        $v1, $v1
    ctx->pc = 0x145b80u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 3)));
    // 0x145b84: 0x30650007  andi        $a1, $v1, 0x7
    ctx->pc = 0x145b84u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
    // 0x145b88: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x145B88u;
    {
        const bool branch_taken_0x145b88 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x145B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145B88u;
            // 0x145b8c: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145b88) {
            ctx->pc = 0x145BA8u;
            goto label_145ba8;
        }
    }
    ctx->pc = 0x145B90u;
    // 0x145b90: 0xc051636  jal         func_1458D8
    ctx->pc = 0x145B90u;
    SET_GPR_U32(ctx, 31, 0x145B98u);
    ctx->pc = 0x145B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145B90u;
            // 0x145b94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1458D8u;
    if (runtime->hasFunction(0x1458D8u)) {
        auto targetFn = runtime->lookupFunction(0x1458D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145B98u; }
        if (ctx->pc != 0x145B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145B98u; }
        if (ctx->pc != 0x145B98u) { return; }
    }
    ctx->pc = 0x145B98u;
label_145b98:
    // 0x145b98: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x145B98u;
    {
        const bool branch_taken_0x145b98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x145B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145B98u;
            // 0x145b9c: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145b98) {
            ctx->pc = 0x145BA8u;
            goto label_145ba8;
        }
    }
    ctx->pc = 0x145BA0u;
label_145ba0:
    // 0x145ba0: 0xc051636  jal         func_1458D8
    ctx->pc = 0x145BA0u;
    SET_GPR_U32(ctx, 31, 0x145BA8u);
    ctx->pc = 0x145BA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145BA0u;
            // 0x145ba4: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1458D8u;
    if (runtime->hasFunction(0x1458D8u)) {
        auto targetFn = runtime->lookupFunction(0x1458D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145BA8u; }
        if (ctx->pc != 0x145BA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145BA8u; }
        if (ctx->pc != 0x145BA8u) { return; }
    }
    ctx->pc = 0x145BA8u;
label_145ba8:
    // 0x145ba8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145ba8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145bac: 0xc0515ee  jal         func_1457B8
    ctx->pc = 0x145BACu;
    SET_GPR_U32(ctx, 31, 0x145BB4u);
    ctx->pc = 0x145BB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145BACu;
            // 0x145bb0: 0x24050018  addiu       $a1, $zero, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1457B8u;
    if (runtime->hasFunction(0x1457B8u)) {
        auto targetFn = runtime->lookupFunction(0x1457B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145BB4u; }
        if (ctx->pc != 0x145BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001457B8_0x1457b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145BB4u; }
        if (ctx->pc != 0x145BB4u) { return; }
    }
    ctx->pc = 0x145BB4u;
label_145bb4:
    // 0x145bb4: 0x10510004  beq         $v0, $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x145BB4u;
    {
        const bool branch_taken_0x145bb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x145BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145BB4u;
            // 0x145bb8: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145bb4) {
            ctx->pc = 0x145BC8u;
            goto label_145bc8;
        }
    }
    ctx->pc = 0x145BBCu;
    // 0x145bbc: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x145bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x145bc0: 0x1040fff7  beqz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x145BC0u;
    {
        const bool branch_taken_0x145bc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x145BC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145BC0u;
            // 0x145bc4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145bc0) {
            ctx->pc = 0x145BA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_145ba0;
        }
    }
    ctx->pc = 0x145BC8u;
label_145bc8:
    // 0x145bc8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x145bc8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x145bcc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x145bccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x145bd0: 0x3e00008  jr          $ra
    ctx->pc = 0x145BD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145BD0u;
            // 0x145bd4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145B70u: goto label_145b70;
            case 0x145B98u: goto label_145b98;
            case 0x145BA0u: goto label_145ba0;
            case 0x145BA8u: goto label_145ba8;
            case 0x145BB4u: goto label_145bb4;
            case 0x145BC8u: goto label_145bc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145BD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
