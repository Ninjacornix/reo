#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BFB40
// Address: 0x1bfb40 - 0x1bfc00
void sub_001BFB40_0x1bfb40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BFB40_0x1bfb40");
#endif

    switch (ctx->pc) {
        case 0x1bfb74u: goto label_1bfb74;
        case 0x1bfba8u: goto label_1bfba8;
        case 0x1bfbd0u: goto label_1bfbd0;
        default: break;
    }

    ctx->pc = 0x1bfb40u;

    // 0x1bfb40: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bfb40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bfb44: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bfb44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bfb48: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bfb48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bfb4c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bfb4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bfb50: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1bfb50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bfb54: 0x1062001c  beq         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1BFB54u;
    {
        const bool branch_taken_0x1bfb54 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BFB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFB54u;
            // 0x1bfb58: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfb54) {
            ctx->pc = 0x1BFBC8u;
            goto label_1bfbc8;
        }
    }
    ctx->pc = 0x1BFB5Cu;
    // 0x1bfb5c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFB5Cu;
    {
        const bool branch_taken_0x1bfb5c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bfb5c) {
            ctx->pc = 0x1BFB6Cu;
            goto label_1bfb6c;
        }
    }
    ctx->pc = 0x1BFB64u;
    // 0x1bfb64: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1BFB64u;
    {
        const bool branch_taken_0x1bfb64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFB68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFB64u;
            // 0x1bfb68: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfb64) {
            ctx->pc = 0x1BFBECu;
            goto label_1bfbec;
        }
    }
    ctx->pc = 0x1BFB6Cu;
label_1bfb6c:
    // 0x1bfb6c: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFB6Cu;
    SET_GPR_U32(ctx, 31, 0x1BFB74u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFB74u; }
        if (ctx->pc != 0x1BFB74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFB74u; }
        if (ctx->pc != 0x1BFB74u) { return; }
    }
    ctx->pc = 0x1BFB74u;
label_1bfb74:
    // 0x1bfb74: 0x440001c  bltz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1BFB74u;
    {
        const bool branch_taken_0x1bfb74 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfb74) {
            ctx->pc = 0x1BFBE8u;
            goto label_1bfbe8;
        }
    }
    ctx->pc = 0x1BFB7Cu;
    // 0x1bfb7c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bfb7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bfb80: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bfb80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bfb84: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1bfb84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1bfb88: 0x8e080088  lw          $t0, 0x88($s0)
    ctx->pc = 0x1bfb88u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 136)));
    // 0x1bfb8c: 0x8e06009c  lw          $a2, 0x9C($s0)
    ctx->pc = 0x1bfb8cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 156)));
    // 0x1bfb90: 0x26050044  addiu       $a1, $s0, 0x44
    ctx->pc = 0x1bfb90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
    // 0x1bfb94: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bfb94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bfb98: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bfb98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bfb9c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1bfb9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bfba0: 0xc06048c  jal         func_181230
    ctx->pc = 0x1BFBA0u;
    SET_GPR_U32(ctx, 31, 0x1BFBA8u);
    ctx->pc = 0x1BFBA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFBA0u;
            // 0x1bfba4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181230u;
    if (runtime->hasFunction(0x181230u)) {
        auto targetFn = runtime->lookupFunction(0x181230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFBA8u; }
        if (ctx->pc != 0x1BFBA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181230_0x181230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFBA8u; }
        if (ctx->pc != 0x1BFBA8u) { return; }
    }
    ctx->pc = 0x1BFBA8u;
label_1bfba8:
    // 0x1bfba8: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFBA8u;
    {
        const bool branch_taken_0x1bfba8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1bfba8) {
            ctx->pc = 0x1BFBB8u;
            goto label_1bfbb8;
        }
    }
    ctx->pc = 0x1BFBB0u;
    // 0x1bfbb0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1BFBB0u;
    {
        const bool branch_taken_0x1bfbb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFBB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFBB0u;
            // 0x1bfbb4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfbb0) {
            ctx->pc = 0x1BFBECu;
            goto label_1bfbec;
        }
    }
    ctx->pc = 0x1BFBB8u;
label_1bfbb8:
    // 0x1bfbb8: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1bfbb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bfbbc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bfbbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bfbc0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1BFBC0u;
    {
        const bool branch_taken_0x1bfbc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFBC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFBC0u;
            // 0x1bfbc4: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfbc0) {
            ctx->pc = 0x1BFBE8u;
            goto label_1bfbe8;
        }
    }
    ctx->pc = 0x1BFBC8u;
label_1bfbc8:
    // 0x1bfbc8: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFBC8u;
    SET_GPR_U32(ctx, 31, 0x1BFBD0u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFBD0u; }
        if (ctx->pc != 0x1BFBD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFBD0u; }
        if (ctx->pc != 0x1BFBD0u) { return; }
    }
    ctx->pc = 0x1BFBD0u;
label_1bfbd0:
    // 0x1bfbd0: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BFBD0u;
    {
        const bool branch_taken_0x1bfbd0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfbd0) {
            ctx->pc = 0x1BFBE8u;
            goto label_1bfbe8;
        }
    }
    ctx->pc = 0x1BFBD8u;
    // 0x1bfbd8: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bfbd8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bfbdc: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1bfbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1bfbe0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1BFBE0u;
    {
        const bool branch_taken_0x1bfbe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFBE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFBE0u;
            // 0x1bfbe4: 0x40102a  slt         $v0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfbe0) {
            ctx->pc = 0x1BFBECu;
            goto label_1bfbec;
        }
    }
    ctx->pc = 0x1BFBE8u;
label_1bfbe8:
    // 0x1bfbe8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1bfbe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1bfbec:
    // 0x1bfbec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bfbecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bfbf0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bfbf0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bfbf4: 0x3e00008  jr          $ra
    ctx->pc = 0x1BFBF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BFBF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFBF4u;
            // 0x1bfbf8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BFB6Cu: goto label_1bfb6c;
            case 0x1BFB74u: goto label_1bfb74;
            case 0x1BFBA8u: goto label_1bfba8;
            case 0x1BFBB8u: goto label_1bfbb8;
            case 0x1BFBC8u: goto label_1bfbc8;
            case 0x1BFBD0u: goto label_1bfbd0;
            case 0x1BFBE8u: goto label_1bfbe8;
            case 0x1BFBECu: goto label_1bfbec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BFBFCu;
    // 0x1bfbfc: 0x0  nop
    ctx->pc = 0x1bfbfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
