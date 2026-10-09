#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174D20
// Address: 0x174d20 - 0x174dc8
void sub_00174D20_0x174d20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174D20_0x174d20");
#endif

    switch (ctx->pc) {
        case 0x174d5cu: goto label_174d5c;
        case 0x174d74u: goto label_174d74;
        case 0x174d88u: goto label_174d88;
        case 0x174da8u: goto label_174da8;
        default: break;
    }

    ctx->pc = 0x174d20u;

    // 0x174d20: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x174d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x174d24: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x174d24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x174d28: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x174d28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x174d2c: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x174d2cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174d30: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x174d30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x174d34: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x174d34u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174d38: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x174d38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x174d3c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x174d3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x174d40: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x174d40u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174d44: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x174d44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x174d48: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x174d48u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x174d4c: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x174d4cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x174d50: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x174d50u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174d54: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x174D54u;
    SET_GPR_U32(ctx, 31, 0x174D5Cu);
    ctx->pc = 0x174D58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174D54u;
            // 0x174d58: 0x24502ab0  addiu       $s0, $v0, 0x2AB0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 10928));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174D5Cu; }
        if (ctx->pc != 0x174D5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174D5Cu; }
        if (ctx->pc != 0x174D5Cu) { return; }
    }
    ctx->pc = 0x174D5Cu;
label_174d5c:
    // 0x174d5c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x174d5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174d60: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x174D60u;
    {
        const bool branch_taken_0x174d60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174D60u;
            // 0x174d64: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174d60) {
            ctx->pc = 0x174D80u;
            goto label_174d80;
        }
    }
    ctx->pc = 0x174D68u;
    // 0x174d68: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x174d68u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174d6c: 0xc05a704  jal         func_169C10
    ctx->pc = 0x174D6Cu;
    SET_GPR_U32(ctx, 31, 0x174D74u);
    ctx->pc = 0x174D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174D6Cu;
            // 0x174d70: 0x34a50157  ori         $a1, $a1, 0x157 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)343);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174D74u; }
        if (ctx->pc != 0x174D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174D74u; }
        if (ctx->pc != 0x174D74u) { return; }
    }
    ctx->pc = 0x174D74u;
label_174d74:
    // 0x174d74: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x174D74u;
    {
        const bool branch_taken_0x174d74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x174D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174D74u;
            // 0x174d78: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174d74) {
            ctx->pc = 0x174DB0u;
            goto label_174db0;
        }
    }
    ctx->pc = 0x174D7Cu;
    // 0x174d7c: 0x0  nop
    ctx->pc = 0x174d7cu;
    // NOP
label_174d80:
    // 0x174d80: 0xc05d2ee  jal         func_174BB8
    ctx->pc = 0x174D80u;
    SET_GPR_U32(ctx, 31, 0x174D88u);
    ctx->pc = 0x174D84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174D80u;
            // 0x174d84: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174BB8u;
    if (runtime->hasFunction(0x174BB8u)) {
        auto targetFn = runtime->lookupFunction(0x174BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174D88u; }
        if (ctx->pc != 0x174D88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174BB8_0x174bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174D88u; }
        if (ctx->pc != 0x174D88u) { return; }
    }
    ctx->pc = 0x174D88u;
label_174d88:
    // 0x174d88: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x174d88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174d8c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x174d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174d90: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x174d90u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174d94: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x174d94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174d98: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x174D98u;
    {
        const bool branch_taken_0x174d98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x174D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174D98u;
            // 0x174d9c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174d98) {
            ctx->pc = 0x174DACu;
            goto label_174dac;
        }
    }
    ctx->pc = 0x174DA0u;
    // 0x174da0: 0xc05d372  jal         func_174DC8
    ctx->pc = 0x174DA0u;
    SET_GPR_U32(ctx, 31, 0x174DA8u);
    ctx->pc = 0x174DA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174DA0u;
            // 0x174da4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174DC8u;
    if (runtime->hasFunction(0x174DC8u)) {
        auto targetFn = runtime->lookupFunction(0x174DC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174DA8u; }
        if (ctx->pc != 0x174DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174DC8_0x174dc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174DA8u; }
        if (ctx->pc != 0x174DA8u) { return; }
    }
    ctx->pc = 0x174DA8u;
label_174da8:
    // 0x174da8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174da8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_174dac:
    // 0x174dac: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x174dacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_174db0:
    // 0x174db0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x174db0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x174db4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x174db4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x174db8: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x174db8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x174dbc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x174dbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x174dc0: 0x3e00008  jr          $ra
    ctx->pc = 0x174DC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174DC0u;
            // 0x174dc4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174D5Cu: goto label_174d5c;
            case 0x174D74u: goto label_174d74;
            case 0x174D80u: goto label_174d80;
            case 0x174D88u: goto label_174d88;
            case 0x174DA8u: goto label_174da8;
            case 0x174DACu: goto label_174dac;
            case 0x174DB0u: goto label_174db0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174DC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
