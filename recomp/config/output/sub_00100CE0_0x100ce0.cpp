#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100CE0
// Address: 0x100ce0 - 0x100d78
void sub_00100CE0_0x100ce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100CE0_0x100ce0");
#endif

    switch (ctx->pc) {
        case 0x100cf4u: goto label_100cf4;
        case 0x100d34u: goto label_100d34;
        case 0x100d48u: goto label_100d48;
        case 0x100d64u: goto label_100d64;
        default: break;
    }

    ctx->pc = 0x100ce0u;

    // 0x100ce0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x100ce0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x100ce4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x100ce4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x100ce8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x100ce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x100cec: 0xc0402dc  jal         func_100B70
    ctx->pc = 0x100CECu;
    SET_GPR_U32(ctx, 31, 0x100CF4u);
    ctx->pc = 0x100CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100CECu;
            // 0x100cf0: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100B70u;
    if (runtime->hasFunction(0x100B70u)) {
        auto targetFn = runtime->lookupFunction(0x100B70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100CF4u; }
        if (ctx->pc != 0x100CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100B70_0x100b70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100CF4u; }
        if (ctx->pc != 0x100CF4u) { return; }
    }
    ctx->pc = 0x100CF4u;
label_100cf4:
    // 0x100cf4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x100CF4u;
    {
        const bool branch_taken_0x100cf4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x100CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100CF4u;
            // 0x100cf8: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100cf4) {
            ctx->pc = 0x100D04u;
            goto label_100d04;
        }
    }
    ctx->pc = 0x100CFCu;
    // 0x100cfc: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x100CFCu;
    {
        const bool branch_taken_0x100cfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100CFCu;
            // 0x100d00: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100cfc) {
            ctx->pc = 0x100D68u;
            goto label_100d68;
        }
    }
    ctx->pc = 0x100D04u;
label_100d04:
    // 0x100d04: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x100d04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x100d08: 0x24507980  addiu       $s0, $v0, 0x7980
    ctx->pc = 0x100d08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 31104));
    // 0x100d0c: 0x24848ad0  addiu       $a0, $a0, -0x7530
    ctx->pc = 0x100d0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937296));
    // 0x100d10: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x100d10u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x100d14: 0x2405000e  addiu       $a1, $zero, 0xE
    ctx->pc = 0x100d14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x100d18: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x100d18u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100d1c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x100d1cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100d20: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x100d20u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100d24: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x100d24u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100d28: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x100d28u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x100d2c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x100D2Cu;
    SET_GPR_U32(ctx, 31, 0x100D34u);
    ctx->pc = 0x100D30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100D2Cu;
            // 0x100d30: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100D34u; }
        if (ctx->pc != 0x100D34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100D34u; }
        if (ctx->pc != 0x100D34u) { return; }
    }
    ctx->pc = 0x100D34u;
label_100d34:
    // 0x100d34: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x100D34u;
    {
        const bool branch_taken_0x100d34 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x100D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100D34u;
            // 0x100d38: 0x3c030020  lui         $v1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100d34) {
            ctx->pc = 0x100D50u;
            goto label_100d50;
        }
    }
    ctx->pc = 0x100D3Cu;
    // 0x100d3c: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100d40: 0xc045190  jal         func_114640
    ctx->pc = 0x100D40u;
    SET_GPR_U32(ctx, 31, 0x100D48u);
    ctx->pc = 0x100D44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100D40u;
            // 0x100d44: 0x8c447928  lw          $a0, 0x7928($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31016)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100D48u; }
        if (ctx->pc != 0x100D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100D48u; }
        if (ctx->pc != 0x100D48u) { return; }
    }
    ctx->pc = 0x100D48u;
label_100d48:
    // 0x100d48: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x100D48u;
    {
        const bool branch_taken_0x100d48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100D4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100D48u;
            // 0x100d4c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100d48) {
            ctx->pc = 0x100D68u;
            goto label_100d68;
        }
    }
    ctx->pc = 0x100D50u;
label_100d50:
    // 0x100d50: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x100d50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x100d54: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x100d54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x100d58: 0x8c647928  lw          $a0, 0x7928($v1)
    ctx->pc = 0x100d58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 31016)));
    // 0x100d5c: 0xc045190  jal         func_114640
    ctx->pc = 0x100D5Cu;
    SET_GPR_U32(ctx, 31, 0x100D64u);
    ctx->pc = 0x100D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100D5Cu;
            // 0x100d60: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100D64u; }
        if (ctx->pc != 0x100D64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100D64u; }
        if (ctx->pc != 0x100D64u) { return; }
    }
    ctx->pc = 0x100D64u;
label_100d64:
    // 0x100d64: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x100d64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_100d68:
    // 0x100d68: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x100d68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100d6c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x100d6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x100d70: 0x3e00008  jr          $ra
    ctx->pc = 0x100D70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100D70u;
            // 0x100d74: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100CF4u: goto label_100cf4;
            case 0x100D04u: goto label_100d04;
            case 0x100D34u: goto label_100d34;
            case 0x100D48u: goto label_100d48;
            case 0x100D50u: goto label_100d50;
            case 0x100D64u: goto label_100d64;
            case 0x100D68u: goto label_100d68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100D78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
