#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A4C70
// Address: 0x1a4c70 - 0x1a4d50
void sub_001A4C70_0x1a4c70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A4C70_0x1a4c70");
#endif

    switch (ctx->pc) {
        case 0x1a4c94u: goto label_1a4c94;
        case 0x1a4ce0u: goto label_1a4ce0;
        default: break;
    }

    ctx->pc = 0x1a4c70u;

    // 0x1a4c70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a4c70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a4c74: 0x24024d42  addiu       $v0, $zero, 0x4D42
    ctx->pc = 0x1a4c74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19778));
    // 0x1a4c78: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a4c78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a4c7c: 0x94a30000  lhu         $v1, 0x0($a1)
    ctx->pc = 0x1a4c7cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a4c80: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A4C80u;
    {
        const bool branch_taken_0x1a4c80 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a4c80) {
            ctx->pc = 0x1A4C9Cu;
            goto label_1a4c9c;
        }
    }
    ctx->pc = 0x1A4C88u;
    // 0x1a4c88: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a4c88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a4c8c: 0xc0696a8  jal         func_1A5AA0
    ctx->pc = 0x1A4C8Cu;
    SET_GPR_U32(ctx, 31, 0x1A4C94u);
    ctx->pc = 0x1A4C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4C8Cu;
            // 0x1a4c90: 0x24841ea0  addiu       $a0, $a0, 0x1EA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7840));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5AA0u;
    if (runtime->hasFunction(0x1A5AA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A5AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4C94u; }
        if (ctx->pc != 0x1A4C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5AA0_0x1a5aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4C94u; }
        if (ctx->pc != 0x1A4C94u) { return; }
    }
    ctx->pc = 0x1A4C94u;
label_1a4c94:
    // 0x1a4c94: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1A4C94u;
    {
        const bool branch_taken_0x1a4c94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4C94u;
            // 0x1a4c98: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4c94) {
            ctx->pc = 0x1A4D40u;
            goto label_1a4d40;
        }
    }
    ctx->pc = 0x1A4C9Cu;
label_1a4c9c:
    // 0x1a4c9c: 0x94a30014  lhu         $v1, 0x14($a1)
    ctx->pc = 0x1a4c9cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x1a4ca0: 0x24020018  addiu       $v0, $zero, 0x18
    ctx->pc = 0x1a4ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1a4ca4: 0x94a60012  lhu         $a2, 0x12($a1)
    ctx->pc = 0x1a4ca4u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 18)));
    // 0x1a4ca8: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1a4ca8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1a4cac: 0xc31825  or          $v1, $a2, $v1
    ctx->pc = 0x1a4cacu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x1a4cb0: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x1a4cb0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x1a4cb4: 0x94a30018  lhu         $v1, 0x18($a1)
    ctx->pc = 0x1a4cb4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x1a4cb8: 0x94a60016  lhu         $a2, 0x16($a1)
    ctx->pc = 0x1a4cb8u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 22)));
    // 0x1a4cbc: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1a4cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1a4cc0: 0xc31825  or          $v1, $a2, $v1
    ctx->pc = 0x1a4cc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x1a4cc4: 0xac830008  sw          $v1, 0x8($a0)
    ctx->pc = 0x1a4cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x1a4cc8: 0x94a3001c  lhu         $v1, 0x1C($a1)
    ctx->pc = 0x1a4cc8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x1a4ccc: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A4CCCu;
    {
        const bool branch_taken_0x1a4ccc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A4CD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4CCCu;
            // 0x1a4cd0: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4ccc) {
            ctx->pc = 0x1A4CE8u;
            goto label_1a4ce8;
        }
    }
    ctx->pc = 0x1A4CD4u;
    // 0x1a4cd4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a4cd4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a4cd8: 0xc0696a8  jal         func_1A5AA0
    ctx->pc = 0x1A4CD8u;
    SET_GPR_U32(ctx, 31, 0x1A4CE0u);
    ctx->pc = 0x1A4CDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4CD8u;
            // 0x1a4cdc: 0x24841ee0  addiu       $a0, $a0, 0x1EE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5AA0u;
    if (runtime->hasFunction(0x1A5AA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A5AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4CE0u; }
        if (ctx->pc != 0x1A4CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5AA0_0x1a5aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4CE0u; }
        if (ctx->pc != 0x1A4CE0u) { return; }
    }
    ctx->pc = 0x1A4CE0u;
label_1a4ce0:
    // 0x1a4ce0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1A4CE0u;
    {
        const bool branch_taken_0x1a4ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4CE0u;
            // 0x1a4ce4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4ce0) {
            ctx->pc = 0x1A4D40u;
            goto label_1a4d40;
        }
    }
    ctx->pc = 0x1A4CE8u;
label_1a4ce8:
    // 0x1a4ce8: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x1a4ce8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a4cec: 0xac820014  sw          $v0, 0x14($a0)
    ctx->pc = 0x1a4cecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    // 0x1a4cf0: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1a4cf0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a4cf4: 0x8c880004  lw          $t0, 0x4($a0)
    ctx->pc = 0x1a4cf4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a4cf8: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1a4cf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a4cfc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a4cfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a4d00: 0x83840  sll         $a3, $t0, 1
    ctx->pc = 0x1a4d00u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1a4d04: 0xe83821  addu        $a3, $a3, $t0
    ctx->pc = 0x1a4d04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x1a4d08: 0xac87000c  sw          $a3, 0xC($a0)
    ctx->pc = 0x1a4d08u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 7));
    // 0x1a4d0c: 0xac860018  sw          $a2, 0x18($a0)
    ctx->pc = 0x1a4d0cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 6));
    // 0x1a4d10: 0xac85001c  sw          $a1, 0x1C($a0)
    ctx->pc = 0x1a4d10u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 5));
    // 0x1a4d14: 0xac830020  sw          $v1, 0x20($a0)
    ctx->pc = 0x1a4d14u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 3));
    // 0x1a4d18: 0xac860024  sw          $a2, 0x24($a0)
    ctx->pc = 0x1a4d18u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 6));
    // 0x1a4d1c: 0xac860028  sw          $a2, 0x28($a0)
    ctx->pc = 0x1a4d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 6));
    // 0x1a4d20: 0xac83002c  sw          $v1, 0x2C($a0)
    ctx->pc = 0x1a4d20u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 3));
    // 0x1a4d24: 0xac860030  sw          $a2, 0x30($a0)
    ctx->pc = 0x1a4d24u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 6));
    // 0x1a4d28: 0xac800034  sw          $zero, 0x34($a0)
    ctx->pc = 0x1a4d28u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x1a4d2c: 0xac830038  sw          $v1, 0x38($a0)
    ctx->pc = 0x1a4d2cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 3));
    // 0x1a4d30: 0xac80003c  sw          $zero, 0x3C($a0)
    ctx->pc = 0x1a4d30u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 0));
    // 0x1a4d34: 0xac800040  sw          $zero, 0x40($a0)
    ctx->pc = 0x1a4d34u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 0));
    // 0x1a4d38: 0xac800044  sw          $zero, 0x44($a0)
    ctx->pc = 0x1a4d38u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 0));
    // 0x1a4d3c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1a4d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
label_1a4d40:
    // 0x1a4d40: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a4d40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a4d44: 0x3e00008  jr          $ra
    ctx->pc = 0x1A4D44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A4D48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4D44u;
            // 0x1a4d48: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A4C94u: goto label_1a4c94;
            case 0x1A4C9Cu: goto label_1a4c9c;
            case 0x1A4CE0u: goto label_1a4ce0;
            case 0x1A4CE8u: goto label_1a4ce8;
            case 0x1A4D40u: goto label_1a4d40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A4D4Cu;
    // 0x1a4d4c: 0x0  nop
    ctx->pc = 0x1a4d4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
