#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C4CA0
// Address: 0x1c4ca0 - 0x1c4de0
void sub_001C4CA0_0x1c4ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C4CA0_0x1c4ca0");
#endif

    switch (ctx->pc) {
        case 0x1c4d20u: goto label_1c4d20;
        case 0x1c4d3cu: goto label_1c4d3c;
        case 0x1c4da0u: goto label_1c4da0;
        case 0x1c4dc0u: goto label_1c4dc0;
        case 0x1c4dc8u: goto label_1c4dc8;
        default: break;
    }

    ctx->pc = 0x1c4ca0u;

    // 0x1c4ca0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c4ca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c4ca4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c4ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4ca8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c4ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c4cac: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c4cacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c4cb0: 0x80830002  lb          $v1, 0x2($a0)
    ctx->pc = 0x1c4cb0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1c4cb4: 0x10620014  beq         $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1C4CB4u;
    {
        const bool branch_taken_0x1c4cb4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C4CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4CB4u;
            // 0x1c4cb8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4cb4) {
            ctx->pc = 0x1C4D08u;
            goto label_1c4d08;
        }
    }
    ctx->pc = 0x1C4CBCu;
    // 0x1c4cbc: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C4CBCu;
    {
        const bool branch_taken_0x1c4cbc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4CC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4CBCu;
            // 0x1c4cc0: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4cbc) {
            ctx->pc = 0x1C4CCCu;
            goto label_1c4ccc;
        }
    }
    ctx->pc = 0x1C4CC4u;
    // 0x1c4cc4: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1C4CC4u;
    {
        const bool branch_taken_0x1c4cc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4CC4u;
            // 0x1c4cc8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4cc4) {
            ctx->pc = 0x1C4DB8u;
            goto label_1c4db8;
        }
    }
    ctx->pc = 0x1C4CCCu;
label_1c4ccc:
    // 0x1c4ccc: 0x902243c0  lbu         $v0, 0x43C0($at)
    ctx->pc = 0x1c4cccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17344)));
    // 0x1c4cd0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C4CD0u;
    {
        const bool branch_taken_0x1c4cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C4CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4CD0u;
            // 0x1c4cd4: 0x24020035  addiu       $v0, $zero, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 53));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4cd0) {
            ctx->pc = 0x1C4CE4u;
            goto label_1c4ce4;
        }
    }
    ctx->pc = 0x1C4CD8u;
    // 0x1c4cd8: 0x24020037  addiu       $v0, $zero, 0x37
    ctx->pc = 0x1c4cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 55));
    // 0x1c4cdc: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C4CDCu;
    {
        const bool branch_taken_0x1c4cdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4CDCu;
            // 0x1c4ce0: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4cdc) {
            ctx->pc = 0x1C4CE8u;
            goto label_1c4ce8;
        }
    }
    ctx->pc = 0x1C4CE4u;
label_1c4ce4:
    // 0x1c4ce4: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c4ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
label_1c4ce8:
    // 0x1c4ce8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c4ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4cec: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c4cecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c4cf0: 0xae030030  sw          $v1, 0x30($s0)
    ctx->pc = 0x1c4cf0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 3));
    // 0x1c4cf4: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c4cf4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c4cf8: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c4cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x1c4cfc: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1c4cfcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c4d00: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c4d00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c4d04: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c4d04u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
label_1c4d08:
    // 0x1c4d08: 0x9603000a  lhu         $v1, 0xA($s0)
    ctx->pc = 0x1c4d08u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c4d0c: 0x30620010  andi        $v0, $v1, 0x10
    ctx->pc = 0x1c4d0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16);
    // 0x1c4d10: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1C4D10u;
    {
        const bool branch_taken_0x1c4d10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4d10) {
            ctx->pc = 0x1C4D4Cu;
            goto label_1c4d4c;
        }
    }
    ctx->pc = 0x1C4D18u;
    // 0x1c4d18: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C4D18u;
    SET_GPR_U32(ctx, 31, 0x1C4D20u);
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4D20u; }
        if (ctx->pc != 0x1C4D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4D20u; }
        if (ctx->pc != 0x1C4D20u) { return; }
    }
    ctx->pc = 0x1C4D20u;
label_1c4d20:
    // 0x1c4d20: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x1c4d20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x1c4d24: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c4d24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4d28: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x1c4d28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c4d2c: 0x14450005  bne         $v0, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C4D2Cu;
    {
        const bool branch_taken_0x1c4d2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        ctx->pc = 0x1C4D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4D2Cu;
            // 0x1c4d30: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4d2c) {
            ctx->pc = 0x1C4D44u;
            goto label_1c4d44;
        }
    }
    ctx->pc = 0x1C4D34u;
    // 0x1c4d34: 0xc070980  jal         func_1C2600
    ctx->pc = 0x1C4D34u;
    SET_GPR_U32(ctx, 31, 0x1C4D3Cu);
    ctx->pc = 0x1C4D38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4D34u;
            // 0x1c4d38: 0x8e040020  lw          $a0, 0x20($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2600u;
    if (runtime->hasFunction(0x1C2600u)) {
        auto targetFn = runtime->lookupFunction(0x1C2600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4D3Cu; }
        if (ctx->pc != 0x1C4D3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2600_0x1c2600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4D3Cu; }
        if (ctx->pc != 0x1C4D3Cu) { return; }
    }
    ctx->pc = 0x1C4D3Cu;
label_1c4d3c:
    // 0x1c4d3c: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1C4D3Cu;
    {
        const bool branch_taken_0x1c4d3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4D40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4D3Cu;
            // 0x1c4d40: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4d3c) {
            ctx->pc = 0x1C4DCCu;
            goto label_1c4dcc;
        }
    }
    ctx->pc = 0x1C4D44u;
label_1c4d44:
    // 0x1c4d44: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1C4D44u;
    {
        const bool branch_taken_0x1c4d44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4D48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4D44u;
            // 0x1c4d48: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4d44) {
            ctx->pc = 0x1C4DD0u;
            goto label_1c4dd0;
        }
    }
    ctx->pc = 0x1C4D4Cu;
label_1c4d4c:
    // 0x1c4d4c: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1c4d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c4d50: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C4D50u;
    {
        const bool branch_taken_0x1c4d50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4d50) {
            ctx->pc = 0x1C4D64u;
            goto label_1c4d64;
        }
    }
    ctx->pc = 0x1C4D58u;
    // 0x1c4d58: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1c4d58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1c4d5c: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1C4D5Cu;
    {
        const bool branch_taken_0x1c4d5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4D60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4D5Cu;
            // 0x1c4d60: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4d5c) {
            ctx->pc = 0x1C4DB4u;
            goto label_1c4db4;
        }
    }
    ctx->pc = 0x1C4D64u;
label_1c4d64:
    // 0x1c4d64: 0x30620008  andi        $v0, $v1, 0x8
    ctx->pc = 0x1c4d64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x1c4d68: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C4D68u;
    {
        const bool branch_taken_0x1c4d68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4D68u;
            // 0x1c4d6c: 0x30620004  andi        $v0, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4d68) {
            ctx->pc = 0x1C4D80u;
            goto label_1c4d80;
        }
    }
    ctx->pc = 0x1C4D70u;
    // 0x1c4d70: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x1c4d70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c4d74: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C4D74u;
    {
        const bool branch_taken_0x1c4d74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4d74) {
            ctx->pc = 0x1C4D98u;
            goto label_1c4d98;
        }
    }
    ctx->pc = 0x1C4D7Cu;
    // 0x1c4d7c: 0x30620004  andi        $v0, $v1, 0x4
    ctx->pc = 0x1c4d7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
label_1c4d80:
    // 0x1c4d80: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1C4D80u;
    {
        const bool branch_taken_0x1c4d80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4d80) {
            ctx->pc = 0x1C4DB4u;
            goto label_1c4db4;
        }
    }
    ctx->pc = 0x1C4D88u;
    // 0x1c4d88: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c4d88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c4d8c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c4d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4d90: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C4D90u;
    {
        const bool branch_taken_0x1c4d90 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c4d90) {
            ctx->pc = 0x1C4DB4u;
            goto label_1c4db4;
        }
    }
    ctx->pc = 0x1C4D98u;
label_1c4d98:
    // 0x1c4d98: 0xc071660  jal         func_1C5980
    ctx->pc = 0x1C4D98u;
    SET_GPR_U32(ctx, 31, 0x1C4DA0u);
    ctx->pc = 0x1C5980u;
    if (runtime->hasFunction(0x1C5980u)) {
        auto targetFn = runtime->lookupFunction(0x1C5980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4DA0u; }
        if (ctx->pc != 0x1C4DA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5980_0x1c5980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4DA0u; }
        if (ctx->pc != 0x1C4DA0u) { return; }
    }
    ctx->pc = 0x1C4DA0u;
label_1c4da0:
    // 0x1c4da0: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c4da0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c4da4: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c4da4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c4da8: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1c4da8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1c4dac: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c4dacu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c4db0: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c4db0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
label_1c4db4:
    // 0x1c4db4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c4db4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c4db8:
    // 0x1c4db8: 0xc0713c4  jal         func_1C4F10
    ctx->pc = 0x1C4DB8u;
    SET_GPR_U32(ctx, 31, 0x1C4DC0u);
    ctx->pc = 0x1C4F10u;
    if (runtime->hasFunction(0x1C4F10u)) {
        auto targetFn = runtime->lookupFunction(0x1C4F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4DC0u; }
        if (ctx->pc != 0x1C4DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4F10_0x1c4f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4DC0u; }
        if (ctx->pc != 0x1C4DC0u) { return; }
    }
    ctx->pc = 0x1C4DC0u;
label_1c4dc0:
    // 0x1c4dc0: 0xc07146c  jal         func_1C51B0
    ctx->pc = 0x1C4DC0u;
    SET_GPR_U32(ctx, 31, 0x1C4DC8u);
    ctx->pc = 0x1C4DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4DC0u;
            // 0x1c4dc4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C51B0u;
    if (runtime->hasFunction(0x1C51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4DC8u; }
        if (ctx->pc != 0x1C4DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C51B0_0x1c51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4DC8u; }
        if (ctx->pc != 0x1C4DC8u) { return; }
    }
    ctx->pc = 0x1C4DC8u;
label_1c4dc8:
    // 0x1c4dc8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c4dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c4dcc:
    // 0x1c4dcc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c4dccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1c4dd0:
    // 0x1c4dd0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c4dd0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c4dd4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C4DD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C4DD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4DD4u;
            // 0x1c4dd8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C4CCCu: goto label_1c4ccc;
            case 0x1C4CE4u: goto label_1c4ce4;
            case 0x1C4CE8u: goto label_1c4ce8;
            case 0x1C4D08u: goto label_1c4d08;
            case 0x1C4D20u: goto label_1c4d20;
            case 0x1C4D3Cu: goto label_1c4d3c;
            case 0x1C4D44u: goto label_1c4d44;
            case 0x1C4D4Cu: goto label_1c4d4c;
            case 0x1C4D64u: goto label_1c4d64;
            case 0x1C4D80u: goto label_1c4d80;
            case 0x1C4D98u: goto label_1c4d98;
            case 0x1C4DA0u: goto label_1c4da0;
            case 0x1C4DB4u: goto label_1c4db4;
            case 0x1C4DB8u: goto label_1c4db8;
            case 0x1C4DC0u: goto label_1c4dc0;
            case 0x1C4DC8u: goto label_1c4dc8;
            case 0x1C4DCCu: goto label_1c4dcc;
            case 0x1C4DD0u: goto label_1c4dd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C4DDCu;
    // 0x1c4ddc: 0x0  nop
    ctx->pc = 0x1c4ddcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
