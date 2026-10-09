#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011CE18
// Address: 0x11ce18 - 0x11ce9c
void sub_0011CE18_0x11ce18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011CE18_0x11ce18");
#endif

    switch (ctx->pc) {
        case 0x11ce70u: goto label_11ce70;
        case 0x11ce88u: goto label_11ce88;
        default: break;
    }

    ctx->pc = 0x11ce18u;

    // 0x11ce18: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x11ce18u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ce1c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11ce1cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11ce20: 0x24c4ffff  addiu       $a0, $a2, -0x1
    ctx->pc = 0x11ce20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x11ce24: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11ce24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11ce28: 0x2c82000d  sltiu       $v0, $a0, 0xD
    ctx->pc = 0x11ce28u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)13) ? 1 : 0);
    // 0x11ce2c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11CE2Cu;
    {
        const bool branch_taken_0x11ce2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11CE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE2Cu;
            // 0x11ce30: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ce2c) {
            ctx->pc = 0x11CE40u;
            goto label_11ce40;
        }
    }
    ctx->pc = 0x11CE34u;
    // 0x11ce34: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11ce34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11ce38: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x11CE38u;
    {
        const bool branch_taken_0x11ce38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CE3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE38u;
            // 0x11ce3c: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ce38) {
            ctx->pc = 0x11CE8Cu;
            goto label_11ce8c;
        }
    }
    ctx->pc = 0x11CE40u;
label_11ce40:
    // 0x11ce40: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11ce40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11ce44: 0x61880  sll         $v1, $a2, 2
    ctx->pc = 0x11ce44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x11ce48: 0x2442a140  addiu       $v0, $v0, -0x5EC0
    ctx->pc = 0x11ce48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294943040));
    // 0x11ce4c: 0x2c840003  sltiu       $a0, $a0, 0x3
    ctx->pc = 0x11ce4cu;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x11ce50: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x11ce50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x11ce54: 0x8c700000  lw          $s0, 0x0($v1)
    ctx->pc = 0x11ce54u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11ce58: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11CE58u;
    {
        const bool branch_taken_0x11ce58 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CE5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE58u;
            // 0x11ce5c: 0xac650000  sw          $a1, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ce58) {
            ctx->pc = 0x11CE78u;
            goto label_11ce78;
        }
    }
    ctx->pc = 0x11CE60u;
    // 0x11ce60: 0x3c050012  lui         $a1, 0x12
    ctx->pc = 0x11ce60u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)18 << 16));
    // 0x11ce64: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x11ce64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ce68: 0xc0450b4  jal         func_1142D0
    ctx->pc = 0x11CE68u;
    SET_GPR_U32(ctx, 31, 0x11CE70u);
    ctx->pc = 0x11CE6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE68u;
            // 0x11ce6c: 0x24a5d540  addiu       $a1, $a1, -0x2AC0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294956352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142D0u;
    if (runtime->hasFunction(0x1142D0u)) {
        auto targetFn = runtime->lookupFunction(0x1142D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE70u; }
        if (ctx->pc != 0x11CE70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142D0_0x1142d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE70u; }
        if (ctx->pc != 0x11CE70u) { return; }
    }
    ctx->pc = 0x11CE70u;
label_11ce70:
    // 0x11ce70: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11CE70u;
    {
        const bool branch_taken_0x11ce70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CE74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE70u;
            // 0x11ce74: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ce70) {
            ctx->pc = 0x11CE8Cu;
            goto label_11ce8c;
        }
    }
    ctx->pc = 0x11CE78u;
label_11ce78:
    // 0x11ce78: 0x3c050012  lui         $a1, 0x12
    ctx->pc = 0x11ce78u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)18 << 16));
    // 0x11ce7c: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x11ce7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ce80: 0xc0450b8  jal         func_1142E0
    ctx->pc = 0x11CE80u;
    SET_GPR_U32(ctx, 31, 0x11CE88u);
    ctx->pc = 0x11CE84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE80u;
            // 0x11ce84: 0x24a5d540  addiu       $a1, $a1, -0x2AC0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294956352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142E0u;
    if (runtime->hasFunction(0x1142E0u)) {
        auto targetFn = runtime->lookupFunction(0x1142E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE88u; }
        if (ctx->pc != 0x11CE88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142E0_0x1142e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE88u; }
        if (ctx->pc != 0x11CE88u) { return; }
    }
    ctx->pc = 0x11CE88u;
label_11ce88:
    // 0x11ce88: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11ce88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_11ce8c:
    // 0x11ce8c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11ce8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ce90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ce90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ce94: 0x3e00008  jr          $ra
    ctx->pc = 0x11CE94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CE98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE94u;
            // 0x11ce98: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CE40u: goto label_11ce40;
            case 0x11CE70u: goto label_11ce70;
            case 0x11CE78u: goto label_11ce78;
            case 0x11CE88u: goto label_11ce88;
            case 0x11CE8Cu: goto label_11ce8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CE9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
