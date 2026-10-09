#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C4DE0
// Address: 0x1c4de0 - 0x1c4f10
void sub_001C4DE0_0x1c4de0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C4DE0_0x1c4de0");
#endif

    switch (ctx->pc) {
        case 0x1c4e48u: goto label_1c4e48;
        case 0x1c4e68u: goto label_1c4e68;
        case 0x1c4eccu: goto label_1c4ecc;
        case 0x1c4eecu: goto label_1c4eec;
        case 0x1c4ef4u: goto label_1c4ef4;
        default: break;
    }

    ctx->pc = 0x1c4de0u;

    // 0x1c4de0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c4de0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c4de4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c4de4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c4de8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c4de8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c4dec: 0x80820002  lb          $v0, 0x2($a0)
    ctx->pc = 0x1c4decu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1c4df0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c4df0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c4df4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c4df4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4df8: 0x1044000d  beq         $v0, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C4DF8u;
    {
        const bool branch_taken_0x1c4df8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x1c4df8) {
            ctx->pc = 0x1C4E30u;
            goto label_1c4e30;
        }
    }
    ctx->pc = 0x1C4E00u;
    // 0x1c4e00: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C4E00u;
    {
        const bool branch_taken_0x1c4e00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4E00u;
            // 0x1c4e04: 0x24030038  addiu       $v1, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4e00) {
            ctx->pc = 0x1C4E10u;
            goto label_1c4e10;
        }
    }
    ctx->pc = 0x1C4E08u;
    // 0x1c4e08: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1C4E08u;
    {
        const bool branch_taken_0x1c4e08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4E08u;
            // 0x1c4e0c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4e08) {
            ctx->pc = 0x1C4EE4u;
            goto label_1c4ee4;
        }
    }
    ctx->pc = 0x1C4E10u;
label_1c4e10:
    // 0x1c4e10: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c4e10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c4e14: 0xae03002c  sw          $v1, 0x2C($s0)
    ctx->pc = 0x1c4e14u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
    // 0x1c4e18: 0xae040030  sw          $a0, 0x30($s0)
    ctx->pc = 0x1c4e18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 4));
    // 0x1c4e1c: 0xae040038  sw          $a0, 0x38($s0)
    ctx->pc = 0x1c4e1cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 4));
    // 0x1c4e20: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c4e20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x1c4e24: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1c4e24u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c4e28: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c4e28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c4e2c: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c4e2cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
label_1c4e30:
    // 0x1c4e30: 0x9603000a  lhu         $v1, 0xA($s0)
    ctx->pc = 0x1c4e30u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c4e34: 0x30620010  andi        $v0, $v1, 0x10
    ctx->pc = 0x1c4e34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16);
    // 0x1c4e38: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1C4E38u;
    {
        const bool branch_taken_0x1c4e38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4e38) {
            ctx->pc = 0x1C4E78u;
            goto label_1c4e78;
        }
    }
    ctx->pc = 0x1C4E40u;
    // 0x1c4e40: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C4E40u;
    SET_GPR_U32(ctx, 31, 0x1C4E48u);
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4E48u; }
        if (ctx->pc != 0x1C4E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4E48u; }
        if (ctx->pc != 0x1C4E48u) { return; }
    }
    ctx->pc = 0x1C4E48u;
label_1c4e48:
    // 0x1c4e48: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x1c4e48u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x1c4e4c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c4e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4e50: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c4e50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c4e54: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C4E54u;
    {
        const bool branch_taken_0x1c4e54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C4E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4E54u;
            // 0x1c4e58: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4e54) {
            ctx->pc = 0x1C4E70u;
            goto label_1c4e70;
        }
    }
    ctx->pc = 0x1C4E5Cu;
    // 0x1c4e5c: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x1c4e5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1c4e60: 0xc070980  jal         func_1C2600
    ctx->pc = 0x1C4E60u;
    SET_GPR_U32(ctx, 31, 0x1C4E68u);
    ctx->pc = 0x1C4E64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4E60u;
            // 0x1c4e64: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2600u;
    if (runtime->hasFunction(0x1C2600u)) {
        auto targetFn = runtime->lookupFunction(0x1C2600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4E68u; }
        if (ctx->pc != 0x1C4E68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2600_0x1c2600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4E68u; }
        if (ctx->pc != 0x1C4E68u) { return; }
    }
    ctx->pc = 0x1C4E68u;
label_1c4e68:
    // 0x1c4e68: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1C4E68u;
    {
        const bool branch_taken_0x1c4e68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4E68u;
            // 0x1c4e6c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4e68) {
            ctx->pc = 0x1C4EF8u;
            goto label_1c4ef8;
        }
    }
    ctx->pc = 0x1C4E70u;
label_1c4e70:
    // 0x1c4e70: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1C4E70u;
    {
        const bool branch_taken_0x1c4e70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4E70u;
            // 0x1c4e74: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4e70) {
            ctx->pc = 0x1C4EFCu;
            goto label_1c4efc;
        }
    }
    ctx->pc = 0x1C4E78u;
label_1c4e78:
    // 0x1c4e78: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1c4e78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c4e7c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C4E7Cu;
    {
        const bool branch_taken_0x1c4e7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4e7c) {
            ctx->pc = 0x1C4E90u;
            goto label_1c4e90;
        }
    }
    ctx->pc = 0x1C4E84u;
    // 0x1c4e84: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1c4e84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1c4e88: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1C4E88u;
    {
        const bool branch_taken_0x1c4e88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4E88u;
            // 0x1c4e8c: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4e88) {
            ctx->pc = 0x1C4EE0u;
            goto label_1c4ee0;
        }
    }
    ctx->pc = 0x1C4E90u;
label_1c4e90:
    // 0x1c4e90: 0x30620008  andi        $v0, $v1, 0x8
    ctx->pc = 0x1c4e90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x1c4e94: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C4E94u;
    {
        const bool branch_taken_0x1c4e94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4E94u;
            // 0x1c4e98: 0x30620004  andi        $v0, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4e94) {
            ctx->pc = 0x1C4EACu;
            goto label_1c4eac;
        }
    }
    ctx->pc = 0x1C4E9Cu;
    // 0x1c4e9c: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x1c4e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c4ea0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C4EA0u;
    {
        const bool branch_taken_0x1c4ea0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4ea0) {
            ctx->pc = 0x1C4EC4u;
            goto label_1c4ec4;
        }
    }
    ctx->pc = 0x1C4EA8u;
    // 0x1c4ea8: 0x30620004  andi        $v0, $v1, 0x4
    ctx->pc = 0x1c4ea8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
label_1c4eac:
    // 0x1c4eac: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1C4EACu;
    {
        const bool branch_taken_0x1c4eac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4eac) {
            ctx->pc = 0x1C4EE0u;
            goto label_1c4ee0;
        }
    }
    ctx->pc = 0x1C4EB4u;
    // 0x1c4eb4: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c4eb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c4eb8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c4eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4ebc: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C4EBCu;
    {
        const bool branch_taken_0x1c4ebc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c4ebc) {
            ctx->pc = 0x1C4EE0u;
            goto label_1c4ee0;
        }
    }
    ctx->pc = 0x1C4EC4u;
label_1c4ec4:
    // 0x1c4ec4: 0xc071660  jal         func_1C5980
    ctx->pc = 0x1C4EC4u;
    SET_GPR_U32(ctx, 31, 0x1C4ECCu);
    ctx->pc = 0x1C5980u;
    if (runtime->hasFunction(0x1C5980u)) {
        auto targetFn = runtime->lookupFunction(0x1C5980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4ECCu; }
        if (ctx->pc != 0x1C4ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5980_0x1c5980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4ECCu; }
        if (ctx->pc != 0x1C4ECCu) { return; }
    }
    ctx->pc = 0x1C4ECCu;
label_1c4ecc:
    // 0x1c4ecc: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c4eccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c4ed0: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c4ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c4ed4: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1c4ed4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1c4ed8: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c4ed8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c4edc: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c4edcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
label_1c4ee0:
    // 0x1c4ee0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c4ee0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c4ee4:
    // 0x1c4ee4: 0xc0713c4  jal         func_1C4F10
    ctx->pc = 0x1C4EE4u;
    SET_GPR_U32(ctx, 31, 0x1C4EECu);
    ctx->pc = 0x1C4F10u;
    if (runtime->hasFunction(0x1C4F10u)) {
        auto targetFn = runtime->lookupFunction(0x1C4F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4EECu; }
        if (ctx->pc != 0x1C4EECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4F10_0x1c4f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4EECu; }
        if (ctx->pc != 0x1C4EECu) { return; }
    }
    ctx->pc = 0x1C4EECu;
label_1c4eec:
    // 0x1c4eec: 0xc07146c  jal         func_1C51B0
    ctx->pc = 0x1C4EECu;
    SET_GPR_U32(ctx, 31, 0x1C4EF4u);
    ctx->pc = 0x1C4EF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4EECu;
            // 0x1c4ef0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C51B0u;
    if (runtime->hasFunction(0x1C51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4EF4u; }
        if (ctx->pc != 0x1C4EF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C51B0_0x1c51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4EF4u; }
        if (ctx->pc != 0x1C4EF4u) { return; }
    }
    ctx->pc = 0x1C4EF4u;
label_1c4ef4:
    // 0x1c4ef4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c4ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c4ef8:
    // 0x1c4ef8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c4ef8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1c4efc:
    // 0x1c4efc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c4efcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c4f00: 0x3e00008  jr          $ra
    ctx->pc = 0x1C4F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C4F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4F00u;
            // 0x1c4f04: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C4E10u: goto label_1c4e10;
            case 0x1C4E30u: goto label_1c4e30;
            case 0x1C4E48u: goto label_1c4e48;
            case 0x1C4E68u: goto label_1c4e68;
            case 0x1C4E70u: goto label_1c4e70;
            case 0x1C4E78u: goto label_1c4e78;
            case 0x1C4E90u: goto label_1c4e90;
            case 0x1C4EACu: goto label_1c4eac;
            case 0x1C4EC4u: goto label_1c4ec4;
            case 0x1C4ECCu: goto label_1c4ecc;
            case 0x1C4EE0u: goto label_1c4ee0;
            case 0x1C4EE4u: goto label_1c4ee4;
            case 0x1C4EECu: goto label_1c4eec;
            case 0x1C4EF4u: goto label_1c4ef4;
            case 0x1C4EF8u: goto label_1c4ef8;
            case 0x1C4EFCu: goto label_1c4efc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C4F08u;
    // 0x1c4f08: 0x0  nop
    ctx->pc = 0x1c4f08u;
    // NOP
    // 0x1c4f0c: 0x0  nop
    ctx->pc = 0x1c4f0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
