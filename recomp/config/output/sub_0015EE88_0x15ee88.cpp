#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EE88
// Address: 0x15ee88 - 0x15efb8
void sub_0015EE88_0x15ee88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EE88_0x15ee88");
#endif

    switch (ctx->pc) {
        case 0x15ee98u: goto label_15ee98;
        case 0x15eea8u: goto label_15eea8;
        case 0x15eeb4u: goto label_15eeb4;
        case 0x15eef4u: goto label_15eef4;
        case 0x15ef68u: goto label_15ef68;
        case 0x15ef8cu: goto label_15ef8c;
        default: break;
    }

    ctx->pc = 0x15ee88u;

    // 0x15ee88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ee88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ee8c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ee8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ee90: 0xc05ce9c  jal         func_173A70
    ctx->pc = 0x15EE90u;
    SET_GPR_U32(ctx, 31, 0x15EE98u);
    ctx->pc = 0x15EE94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE90u;
            // 0x15ee94: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173A70u;
    if (runtime->hasFunction(0x173A70u)) {
        auto targetFn = runtime->lookupFunction(0x173A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE98u; }
        if (ctx->pc != 0x15EE98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173A70_0x173a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE98u; }
        if (ctx->pc != 0x15EE98u) { return; }
    }
    ctx->pc = 0x15EE98u;
label_15ee98:
    // 0x15ee98: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15EE98u;
    {
        const bool branch_taken_0x15ee98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EE9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE98u;
            // 0x15ee9c: 0x2404fecd  addiu       $a0, $zero, -0x133 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966989));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ee98) {
            ctx->pc = 0x15EEB8u;
            goto label_15eeb8;
        }
    }
    ctx->pc = 0x15EEA0u;
    // 0x15eea0: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15EEA0u;
    SET_GPR_U32(ctx, 31, 0x15EEA8u);
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EEA8u; }
        if (ctx->pc != 0x15EEA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EEA8u; }
        if (ctx->pc != 0x15EEA8u) { return; }
    }
    ctx->pc = 0x15EEA8u;
label_15eea8:
    // 0x15eea8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15eea8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15eeac: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15EEACu;
    SET_GPR_U32(ctx, 31, 0x15EEB4u);
    ctx->pc = 0x15EEB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EEACu;
            // 0x15eeb0: 0x2484f010  addiu       $a0, $a0, -0xFF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EEB4u; }
        if (ctx->pc != 0x15EEB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EEB4u; }
        if (ctx->pc != 0x15EEB4u) { return; }
    }
    ctx->pc = 0x15EEB4u;
label_15eeb4:
    // 0x15eeb4: 0x2402fecd  addiu       $v0, $zero, -0x133
    ctx->pc = 0x15eeb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966989));
label_15eeb8:
    // 0x15eeb8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15eeb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15eebc: 0x3e00008  jr          $ra
    ctx->pc = 0x15EEBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EEC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EEBCu;
            // 0x15eec0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EE98u: goto label_15ee98;
            case 0x15EEA8u: goto label_15eea8;
            case 0x15EEB4u: goto label_15eeb4;
            case 0x15EEB8u: goto label_15eeb8;
            case 0x15EEF4u: goto label_15eef4;
            case 0x15EF48u: goto label_15ef48;
            case 0x15EF68u: goto label_15ef68;
            case 0x15EF8Cu: goto label_15ef8c;
            case 0x15EF90u: goto label_15ef90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EEC4u;
    // 0x15eec4: 0x0  nop
    ctx->pc = 0x15eec4u;
    // NOP
    // 0x15eec8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x15eec8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x15eecc: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x15eeccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x15eed0: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x15eed0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15eed4: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x15eed4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x15eed8: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x15eed8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15eedc: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x15eedcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x15eee0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x15eee0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15eee4: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x15eee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x15eee8: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15eee8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15eeec: 0xc05cf8e  jal         func_173E38
    ctx->pc = 0x15EEECu;
    SET_GPR_U32(ctx, 31, 0x15EEF4u);
    ctx->pc = 0x15EEF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EEECu;
            // 0x15eef0: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173E38u;
    if (runtime->hasFunction(0x173E38u)) {
        auto targetFn = runtime->lookupFunction(0x173E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EEF4u; }
        if (ctx->pc != 0x15EEF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173E38_0x173e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EEF4u; }
        if (ctx->pc != 0x15EEF4u) { return; }
    }
    ctx->pc = 0x15EEF4u;
label_15eef4:
    // 0x15eef4: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x15eef4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15eef8: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x15eef8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15eefc: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x15eefcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x15ef00: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x15ef00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x15ef04: 0xae440000  sw          $a0, 0x0($s2)
    ctx->pc = 0x15ef04u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x15ef08: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x15ef08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x15ef0c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x15ef0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15ef10: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x15ef10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15ef14: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x15ef14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15ef18: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x15ef18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15ef1c: 0x3e00008  jr          $ra
    ctx->pc = 0x15EF1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EF20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF1Cu;
            // 0x15ef20: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EE98u: goto label_15ee98;
            case 0x15EEA8u: goto label_15eea8;
            case 0x15EEB4u: goto label_15eeb4;
            case 0x15EEB8u: goto label_15eeb8;
            case 0x15EEF4u: goto label_15eef4;
            case 0x15EF48u: goto label_15ef48;
            case 0x15EF68u: goto label_15ef68;
            case 0x15EF8Cu: goto label_15ef8c;
            case 0x15EF90u: goto label_15ef90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EF24u;
    // 0x15ef24: 0x0  nop
    ctx->pc = 0x15ef24u;
    // NOP
    // 0x15ef28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ef28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ef2c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ef2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ef30: 0x4a00005  bltz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x15EF30u;
    {
        const bool branch_taken_0x15ef30 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x15EF34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF30u;
            // 0x15ef34: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ef30) {
            ctx->pc = 0x15EF48u;
            goto label_15ef48;
        }
    }
    ctx->pc = 0x15EF38u;
    // 0x15ef38: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ef38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ef3c: 0x805cfaa  j           func_173EA8
    ctx->pc = 0x15EF3Cu;
    ctx->pc = 0x15EF40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF3Cu;
            // 0x15ef40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173EA8u;
    if (runtime->hasFunction(0x173EA8u)) {
        auto targetFn = runtime->lookupFunction(0x173EA8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00173EA8_0x173ea8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15EF44u;
    // 0x15ef44: 0x0  nop
    ctx->pc = 0x15ef44u;
    // NOP
label_15ef48:
    // 0x15ef48: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ef48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ef4c: 0x3e00008  jr          $ra
    ctx->pc = 0x15EF4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EF50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF4Cu;
            // 0x15ef50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EE98u: goto label_15ee98;
            case 0x15EEA8u: goto label_15eea8;
            case 0x15EEB4u: goto label_15eeb4;
            case 0x15EEB8u: goto label_15eeb8;
            case 0x15EEF4u: goto label_15eef4;
            case 0x15EF48u: goto label_15ef48;
            case 0x15EF68u: goto label_15ef68;
            case 0x15EF8Cu: goto label_15ef8c;
            case 0x15EF90u: goto label_15ef90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EF54u;
    // 0x15ef54: 0x0  nop
    ctx->pc = 0x15ef54u;
    // NOP
    // 0x15ef58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ef58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ef5c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ef5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ef60: 0xc05c81e  jal         func_172078
    ctx->pc = 0x15EF60u;
    SET_GPR_U32(ctx, 31, 0x15EF68u);
    ctx->pc = 0x15EF64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF60u;
            // 0x15ef64: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172078u;
    if (runtime->hasFunction(0x172078u)) {
        auto targetFn = runtime->lookupFunction(0x172078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EF68u; }
        if (ctx->pc != 0x15EF68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172078_0x172078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EF68u; }
        if (ctx->pc != 0x15EF68u) { return; }
    }
    ctx->pc = 0x15EF68u;
label_15ef68:
    // 0x15ef68: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x15ef68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15ef6c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15EF6Cu;
    {
        const bool branch_taken_0x15ef6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EF70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF6Cu;
            // 0x15ef70: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ef6c) {
            ctx->pc = 0x15EF90u;
            goto label_15ef90;
        }
    }
    ctx->pc = 0x15EF74u;
    // 0x15ef74: 0x10440006  beq         $v0, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15EF74u;
    {
        const bool branch_taken_0x15ef74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x15EF78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF74u;
            // 0x15ef78: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ef74) {
            ctx->pc = 0x15EF90u;
            goto label_15ef90;
        }
    }
    ctx->pc = 0x15EF7Cu;
    // 0x15ef7c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15ef7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15ef80: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15ef80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ef84: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15EF84u;
    SET_GPR_U32(ctx, 31, 0x15EF8Cu);
    ctx->pc = 0x15EF88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF84u;
            // 0x15ef88: 0x2484f030  addiu       $a0, $a0, -0xFD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963248));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EF8Cu; }
        if (ctx->pc != 0x15EF8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EF8Cu; }
        if (ctx->pc != 0x15EF8Cu) { return; }
    }
    ctx->pc = 0x15EF8Cu;
label_15ef8c:
    // 0x15ef8c: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x15ef8cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15ef90:
    // 0x15ef90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ef90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ef94: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x15ef94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ef98: 0x3e00008  jr          $ra
    ctx->pc = 0x15EF98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EF9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EF98u;
            // 0x15ef9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EE98u: goto label_15ee98;
            case 0x15EEA8u: goto label_15eea8;
            case 0x15EEB4u: goto label_15eeb4;
            case 0x15EEB8u: goto label_15eeb8;
            case 0x15EEF4u: goto label_15eef4;
            case 0x15EF48u: goto label_15ef48;
            case 0x15EF68u: goto label_15ef68;
            case 0x15EF8Cu: goto label_15ef8c;
            case 0x15EF90u: goto label_15ef90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EFA0u;
    // 0x15efa0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15efa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15efa4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15efa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15efa8: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15efa8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15efac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15efacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15efb0: 0x805cfca  j           func_173F28
    ctx->pc = 0x15EFB0u;
    ctx->pc = 0x15EFB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EFB0u;
            // 0x15efb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173F28u;
    if (runtime->hasFunction(0x173F28u)) {
        auto targetFn = runtime->lookupFunction(0x173F28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00173F28_0x173f28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15EFB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
