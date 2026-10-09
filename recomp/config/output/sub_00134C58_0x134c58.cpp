#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134C58
// Address: 0x134c58 - 0x134d90
void sub_00134C58_0x134c58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134C58_0x134c58");
#endif

    switch (ctx->pc) {
        case 0x134ca0u: goto label_134ca0;
        case 0x134cb8u: goto label_134cb8;
        case 0x134cd0u: goto label_134cd0;
        case 0x134ce8u: goto label_134ce8;
        case 0x134d00u: goto label_134d00;
        case 0x134d08u: goto label_134d08;
        default: break;
    }

    ctx->pc = 0x134c58u;

    // 0x134c58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x134c58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x134c5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x134c5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x134c60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x134c60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134c64: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x134C64u;
    {
        const bool branch_taken_0x134c64 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x134C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134C64u;
            // 0x134c68: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134c64) {
            ctx->pc = 0x134C88u;
            goto label_134c88;
        }
    }
    ctx->pc = 0x134C6Cu;
    // 0x134c6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x134c6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x134c70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x134c70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134c74: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x134c74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x134c78: 0x2484b748  addiu       $a0, $a0, -0x48B8
    ctx->pc = 0x134c78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948680));
    // 0x134c7c: 0x804a034  j           func_1280D0
    ctx->pc = 0x134C7Cu;
    ctx->pc = 0x134C80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134C7Cu;
            // 0x134c80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x134C84u;
    // 0x134c84: 0x0  nop
    ctx->pc = 0x134c84u;
    // NOP
label_134c88:
    // 0x134c88: 0x82030001  lb          $v1, 0x1($s0)
    ctx->pc = 0x134c88u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x134c8c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x134c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x134c90: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x134C90u;
    {
        const bool branch_taken_0x134c90 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x134C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134C90u;
            // 0x134c94: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134c90) {
            ctx->pc = 0x134CA8u;
            goto label_134ca8;
        }
    }
    ctx->pc = 0x134C98u;
    // 0x134c98: 0xc04d14c  jal         func_134530
    ctx->pc = 0x134C98u;
    SET_GPR_U32(ctx, 31, 0x134CA0u);
    ctx->pc = 0x134530u;
    if (runtime->hasFunction(0x134530u)) {
        auto targetFn = runtime->lookupFunction(0x134530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134CA0u; }
        if (ctx->pc != 0x134CA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134530_0x134530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134CA0u; }
        if (ctx->pc != 0x134CA0u) { return; }
    }
    ctx->pc = 0x134CA0u;
label_134ca0:
    // 0x134ca0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x134CA0u;
    {
        const bool branch_taken_0x134ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x134ca0) {
            ctx->pc = 0x134D00u;
            goto label_134d00;
        }
    }
    ctx->pc = 0x134CA8u;
label_134ca8:
    // 0x134ca8: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x134CA8u;
    {
        const bool branch_taken_0x134ca8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x134CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134CA8u;
            // 0x134cac: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134ca8) {
            ctx->pc = 0x134CC0u;
            goto label_134cc0;
        }
    }
    ctx->pc = 0x134CB0u;
    // 0x134cb0: 0xc04cff8  jal         func_133FE0
    ctx->pc = 0x134CB0u;
    SET_GPR_U32(ctx, 31, 0x134CB8u);
    ctx->pc = 0x133FE0u;
    if (runtime->hasFunction(0x133FE0u)) {
        auto targetFn = runtime->lookupFunction(0x133FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134CB8u; }
        if (ctx->pc != 0x134CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133FE0_0x133fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134CB8u; }
        if (ctx->pc != 0x134CB8u) { return; }
    }
    ctx->pc = 0x134CB8u;
label_134cb8:
    // 0x134cb8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x134CB8u;
    {
        const bool branch_taken_0x134cb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x134cb8) {
            ctx->pc = 0x134D00u;
            goto label_134d00;
        }
    }
    ctx->pc = 0x134CC0u;
label_134cc0:
    // 0x134cc0: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x134CC0u;
    {
        const bool branch_taken_0x134cc0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x134CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134CC0u;
            // 0x134cc4: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134cc0) {
            ctx->pc = 0x134CD8u;
            goto label_134cd8;
        }
    }
    ctx->pc = 0x134CC8u;
    // 0x134cc8: 0xc04d0ee  jal         func_1343B8
    ctx->pc = 0x134CC8u;
    SET_GPR_U32(ctx, 31, 0x134CD0u);
    ctx->pc = 0x1343B8u;
    if (runtime->hasFunction(0x1343B8u)) {
        auto targetFn = runtime->lookupFunction(0x1343B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134CD0u; }
        if (ctx->pc != 0x134CD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001343B8_0x1343b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134CD0u; }
        if (ctx->pc != 0x134CD0u) { return; }
    }
    ctx->pc = 0x134CD0u;
label_134cd0:
    // 0x134cd0: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x134CD0u;
    {
        const bool branch_taken_0x134cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x134cd0) {
            ctx->pc = 0x134D00u;
            goto label_134d00;
        }
    }
    ctx->pc = 0x134CD8u;
label_134cd8:
    // 0x134cd8: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x134CD8u;
    {
        const bool branch_taken_0x134cd8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x134CDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134CD8u;
            // 0x134cdc: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134cd8) {
            ctx->pc = 0x134CF0u;
            goto label_134cf0;
        }
    }
    ctx->pc = 0x134CE0u;
    // 0x134ce0: 0xc04d17c  jal         func_1345F0
    ctx->pc = 0x134CE0u;
    SET_GPR_U32(ctx, 31, 0x134CE8u);
    ctx->pc = 0x1345F0u;
    if (runtime->hasFunction(0x1345F0u)) {
        auto targetFn = runtime->lookupFunction(0x1345F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134CE8u; }
        if (ctx->pc != 0x134CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001345F0_0x1345f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134CE8u; }
        if (ctx->pc != 0x134CE8u) { return; }
    }
    ctx->pc = 0x134CE8u;
label_134ce8:
    // 0x134ce8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x134CE8u;
    {
        const bool branch_taken_0x134ce8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x134ce8) {
            ctx->pc = 0x134D00u;
            goto label_134d00;
        }
    }
    ctx->pc = 0x134CF0u;
label_134cf0:
    // 0x134cf0: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x134CF0u;
    {
        const bool branch_taken_0x134cf0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x134cf0) {
            ctx->pc = 0x134D00u;
            goto label_134d00;
        }
    }
    ctx->pc = 0x134CF8u;
    // 0x134cf8: 0xc04d1fe  jal         func_1347F8
    ctx->pc = 0x134CF8u;
    SET_GPR_U32(ctx, 31, 0x134D00u);
    ctx->pc = 0x1347F8u;
    if (runtime->hasFunction(0x1347F8u)) {
        auto targetFn = runtime->lookupFunction(0x1347F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134D00u; }
        if (ctx->pc != 0x134D00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001347F8_0x1347f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134D00u; }
        if (ctx->pc != 0x134D00u) { return; }
    }
    ctx->pc = 0x134D00u;
label_134d00:
    // 0x134d00: 0xc04d2f0  jal         func_134BC0
    ctx->pc = 0x134D00u;
    SET_GPR_U32(ctx, 31, 0x134D08u);
    ctx->pc = 0x134D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134D00u;
            // 0x134d04: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134BC0u;
    if (runtime->hasFunction(0x134BC0u)) {
        auto targetFn = runtime->lookupFunction(0x134BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134D08u; }
        if (ctx->pc != 0x134D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134BC0_0x134bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134D08u; }
        if (ctx->pc != 0x134D08u) { return; }
    }
    ctx->pc = 0x134D08u;
label_134d08:
    // 0x134d08: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x134d08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134d0c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x134d0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x134d10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x134d10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134d14: 0x804d2d0  j           func_134B40
    ctx->pc = 0x134D14u;
    ctx->pc = 0x134D18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134D14u;
            // 0x134d18: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134B40u;
    if (runtime->hasFunction(0x134B40u)) {
        auto targetFn = runtime->lookupFunction(0x134B40u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00134B40_0x134b40(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x134D1Cu;
    // 0x134d1c: 0x0  nop
    ctx->pc = 0x134d1cu;
    // NOP
    // 0x134d20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x134d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x134d24: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x134d24u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134d28: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x134d28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x134d2c: 0x10600014  beqz        $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x134D2Cu;
    {
        const bool branch_taken_0x134d2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x134D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D2Cu;
            // 0x134d30: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d2c) {
            ctx->pc = 0x134D80u;
            goto label_134d80;
        }
    }
    ctx->pc = 0x134D34u;
    // 0x134d34: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x134d34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x134d38: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x134D38u;
    {
        const bool branch_taken_0x134d38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x134D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D38u;
            // 0x134d3c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d38) {
            ctx->pc = 0x134D70u;
            goto label_134d70;
        }
    }
    ctx->pc = 0x134D40u;
    // 0x134d40: 0x8c640094  lw          $a0, 0x94($v1)
    ctx->pc = 0x134d40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 148)));
    // 0x134d44: 0x1080000e  beqz        $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x134D44u;
    {
        const bool branch_taken_0x134d44 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x134D48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D44u;
            // 0x134d48: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d44) {
            ctx->pc = 0x134D80u;
            goto label_134d80;
        }
    }
    ctx->pc = 0x134D4Cu;
    // 0x134d4c: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x134d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x134d50: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x134D50u;
    {
        const bool branch_taken_0x134d50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x134D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D50u;
            // 0x134d54: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d50) {
            ctx->pc = 0x134D68u;
            goto label_134d68;
        }
    }
    ctx->pc = 0x134D58u;
    // 0x134d58: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134d58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134d5c: 0x804c3f8  j           func_130FE0
    ctx->pc = 0x134D5Cu;
    ctx->pc = 0x134D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134D5Cu;
            // 0x134d60: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130FE0u;
    if (runtime->hasFunction(0x130FE0u)) {
        auto targetFn = runtime->lookupFunction(0x130FE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130FE0_0x130fe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x134D64u;
    // 0x134d64: 0x0  nop
    ctx->pc = 0x134d64u;
    // NOP
label_134d68:
    // 0x134d68: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x134D68u;
    {
        const bool branch_taken_0x134d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D68u;
            // 0x134d6c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d68) {
            ctx->pc = 0x134D80u;
            goto label_134d80;
        }
    }
    ctx->pc = 0x134D70u;
label_134d70:
    // 0x134d70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134d70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134d74: 0x804c3f8  j           func_130FE0
    ctx->pc = 0x134D74u;
    ctx->pc = 0x134D78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134D74u;
            // 0x134d78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130FE0u;
    if (runtime->hasFunction(0x130FE0u)) {
        auto targetFn = runtime->lookupFunction(0x130FE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130FE0_0x130fe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x134D7Cu;
    // 0x134d7c: 0x0  nop
    ctx->pc = 0x134d7cu;
    // NOP
label_134d80:
    // 0x134d80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134d80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134d84: 0x3e00008  jr          $ra
    ctx->pc = 0x134D84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D84u;
            // 0x134d88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134C88u: goto label_134c88;
            case 0x134CA0u: goto label_134ca0;
            case 0x134CA8u: goto label_134ca8;
            case 0x134CB8u: goto label_134cb8;
            case 0x134CC0u: goto label_134cc0;
            case 0x134CD0u: goto label_134cd0;
            case 0x134CD8u: goto label_134cd8;
            case 0x134CE8u: goto label_134ce8;
            case 0x134CF0u: goto label_134cf0;
            case 0x134D00u: goto label_134d00;
            case 0x134D08u: goto label_134d08;
            case 0x134D68u: goto label_134d68;
            case 0x134D70u: goto label_134d70;
            case 0x134D80u: goto label_134d80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134D8Cu;
    // 0x134d8c: 0x0  nop
    ctx->pc = 0x134d8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
