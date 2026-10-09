#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011EAC8
// Address: 0x11eac8 - 0x11eb78
void sub_0011EAC8_0x11eac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011EAC8_0x11eac8");
#endif

    switch (ctx->pc) {
        case 0x11eb30u: goto label_11eb30;
        case 0x11eb54u: goto label_11eb54;
        case 0x11eb5cu: goto label_11eb5c;
        default: break;
    }

    ctx->pc = 0x11eac8u;

    // 0x11eac8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11eac8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11eacc: 0x41282  srl         $v0, $a0, 10
    ctx->pc = 0x11eaccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 10));
    // 0x11ead0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11ead0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11ead4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11ead4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11ead8: 0x28180  sll         $s0, $v0, 6
    ctx->pc = 0x11ead8u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x11eadc: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11EADCu;
    {
        const bool branch_taken_0x11eadc = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x11EAE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EADCu;
            // 0x11eae0: 0xffb10010  sd          $s1, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11eadc) {
            ctx->pc = 0x11EAF4u;
            goto label_11eaf4;
        }
    }
    ctx->pc = 0x11EAE4u;
    // 0x11eae4: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x11eae4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11eae8: 0x308203ff  andi        $v0, $a0, 0x3FF
    ctx->pc = 0x11eae8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1023);
    // 0x11eaec: 0x50430004  beql        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x11EAECu;
    {
        const bool branch_taken_0x11eaec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x11eaec) {
            ctx->pc = 0x11EAF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11EAECu;
            // 0x11eaf0: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11EB00u;
            goto label_11eb00;
        }
    }
    ctx->pc = 0x11EAF4u;
label_11eaf4:
    // 0x11eaf4: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11eaf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11eaf8: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x11EAF8u;
    {
        const bool branch_taken_0x11eaf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EAFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EAF8u;
            // 0x11eafc: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11eaf8) {
            ctx->pc = 0x11EB60u;
            goto label_11eb60;
        }
    }
    ctx->pc = 0x11EB00u;
label_11eb00:
    // 0x11eb00: 0x2442b3e8  addiu       $v0, $v0, -0x4C18
    ctx->pc = 0x11eb00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947816));
    // 0x11eb04: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x11eb04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x11eb08: 0x54640004  bnel        $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11EB08u;
    {
        const bool branch_taken_0x11eb08 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x11eb08) {
            ctx->pc = 0x11EB0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB08u;
            // 0x11eb0c: 0x8e02000c  lw          $v0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11EB1Cu;
            goto label_11eb1c;
        }
    }
    ctx->pc = 0x11EB10u;
    // 0x11eb10: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11eb10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11eb14: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x11EB14u;
    {
        const bool branch_taken_0x11eb14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EB18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB14u;
            // 0x11eb18: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11eb14) {
            ctx->pc = 0x11EB60u;
            goto label_11eb60;
        }
    }
    ctx->pc = 0x11EB1Cu;
label_11eb1c:
    // 0x11eb1c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x11eb1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x11eb20: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x11EB20u;
    {
        const bool branch_taken_0x11eb20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11EB24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB20u;
            // 0x11eb24: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11eb20) {
            ctx->pc = 0x11EB60u;
            goto label_11eb60;
        }
    }
    ctx->pc = 0x11EB28u;
    // 0x11eb28: 0xc0479e8  jal         func_11E7A0
    ctx->pc = 0x11EB28u;
    SET_GPR_U32(ctx, 31, 0x11EB30u);
    ctx->pc = 0x11E7A0u;
    if (runtime->hasFunction(0x11E7A0u)) {
        auto targetFn = runtime->lookupFunction(0x11E7A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB30u; }
        if (ctx->pc != 0x11EB30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E7A0_0x11e7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB30u; }
        if (ctx->pc != 0x11EB30u) { return; }
    }
    ctx->pc = 0x11EB30u;
label_11eb30:
    // 0x11eb30: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11eb30u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11eb34: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x11eb34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x11eb38: 0xfe110010  sd          $s1, 0x10($s0)
    ctx->pc = 0x11eb38u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 16), GPR_U64(ctx, 17));
    // 0x11eb3c: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x11eb3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x11eb40: 0x30430002  andi        $v1, $v0, 0x2
    ctx->pc = 0x11eb40u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x11eb44: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x11EB44u;
    {
        const bool branch_taken_0x11eb44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EB48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB44u;
            // 0x11eb48: 0xae02000c  sw          $v0, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11eb44) {
            ctx->pc = 0x11EB5Cu;
            goto label_11eb5c;
        }
    }
    ctx->pc = 0x11EB4Cu;
    // 0x11eb4c: 0xc047910  jal         func_11E440
    ctx->pc = 0x11EB4Cu;
    SET_GPR_U32(ctx, 31, 0x11EB54u);
    ctx->pc = 0x11EB50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB4Cu;
            // 0x11eb50: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11E440u;
    if (runtime->hasFunction(0x11E440u)) {
        auto targetFn = runtime->lookupFunction(0x11E440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB54u; }
        if (ctx->pc != 0x11EB54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E440_0x11e440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB54u; }
        if (ctx->pc != 0x11EB54u) { return; }
    }
    ctx->pc = 0x11EB54u;
label_11eb54:
    // 0x11eb54: 0xc0478ac  jal         func_11E2B0
    ctx->pc = 0x11EB54u;
    SET_GPR_U32(ctx, 31, 0x11EB5Cu);
    ctx->pc = 0x11EB58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB54u;
            // 0x11eb58: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11E2B0u;
    if (runtime->hasFunction(0x11E2B0u)) {
        auto targetFn = runtime->lookupFunction(0x11E2B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB5Cu; }
        if (ctx->pc != 0x11EB5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E2B0_0x11e2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB5Cu; }
        if (ctx->pc != 0x11EB5Cu) { return; }
    }
    ctx->pc = 0x11EB5Cu;
label_11eb5c:
    // 0x11eb5c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11eb5cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11eb60:
    // 0x11eb60: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11eb60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11eb64: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11eb64u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11eb68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11eb68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11eb6c: 0x3e00008  jr          $ra
    ctx->pc = 0x11EB6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EB70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB6Cu;
            // 0x11eb70: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EAF4u: goto label_11eaf4;
            case 0x11EB00u: goto label_11eb00;
            case 0x11EB1Cu: goto label_11eb1c;
            case 0x11EB30u: goto label_11eb30;
            case 0x11EB54u: goto label_11eb54;
            case 0x11EB5Cu: goto label_11eb5c;
            case 0x11EB60u: goto label_11eb60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EB74u;
    // 0x11eb74: 0x0  nop
    ctx->pc = 0x11eb74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
