#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180E28
// Address: 0x180e28 - 0x180f60
void sub_00180E28_0x180e28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180E28_0x180e28");
#endif

    switch (ctx->pc) {
        case 0x180e60u: goto label_180e60;
        case 0x180ec4u: goto label_180ec4;
        case 0x180ee0u: goto label_180ee0;
        case 0x180f14u: goto label_180f14;
        case 0x180f4cu: goto label_180f4c;
        default: break;
    }

    ctx->pc = 0x180e28u;

    // 0x180e28: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x180e28u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x180e2c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x180e2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x180e30: 0x8c65fa10  lw          $a1, -0x5F0($v1)
    ctx->pc = 0x180e30u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x180e34: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180e34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180e38: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x180e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x180e3c: 0x10a0000c  beqz        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x180E3Cu;
    {
        const bool branch_taken_0x180e3c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x180E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180E3Cu;
            // 0x180e40: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180e3c) {
            ctx->pc = 0x180E70u;
            goto label_180e70;
        }
    }
    ctx->pc = 0x180E44u;
    // 0x180e44: 0x3c050028  lui         $a1, 0x28
    ctx->pc = 0x180e44u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)40 << 16));
    // 0x180e48: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180e48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180e4c: 0x8ca39504  lw          $v1, -0x6AFC($a1)
    ctx->pc = 0x180e4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4294939908)));
    // 0x180e50: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x180E50u;
    {
        const bool branch_taken_0x180e50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x180E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180E50u;
            // 0x180e54: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180e50) {
            ctx->pc = 0x180E70u;
            goto label_180e70;
        }
    }
    ctx->pc = 0x180E58u;
    // 0x180e58: 0xc061e9c  jal         func_187A70
    ctx->pc = 0x180E58u;
    SET_GPR_U32(ctx, 31, 0x180E60u);
    ctx->pc = 0x187A70u;
    if (runtime->hasFunction(0x187A70u)) {
        auto targetFn = runtime->lookupFunction(0x187A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180E60u; }
        if (ctx->pc != 0x180E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A70_0x187a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180E60u; }
        if (ctx->pc != 0x180E60u) { return; }
    }
    ctx->pc = 0x180E60u;
label_180e60:
    // 0x180e60: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x180e60u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x180e64: 0x34638002  ori         $v1, $v1, 0x8002
    ctx->pc = 0x180e64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)32770);
    // 0x180e68: 0x2180b  movn        $v1, $zero, $v0
    ctx->pc = 0x180e68u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x180e6c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x180e6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_180e70:
    // 0x180e70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x180e70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180e74: 0x3e00008  jr          $ra
    ctx->pc = 0x180E74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180E74u;
            // 0x180e78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180E60u: goto label_180e60;
            case 0x180E70u: goto label_180e70;
            case 0x180EC4u: goto label_180ec4;
            case 0x180EE0u: goto label_180ee0;
            case 0x180F14u: goto label_180f14;
            case 0x180F18u: goto label_180f18;
            case 0x180F4Cu: goto label_180f4c;
            case 0x180F50u: goto label_180f50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180E7Cu;
    // 0x180e7c: 0x0  nop
    ctx->pc = 0x180e7cu;
    // NOP
    // 0x180e80: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x180e80u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x180e84: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x180e84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x180e88: 0x8c66fa10  lw          $a2, -0x5F0($v1)
    ctx->pc = 0x180e88u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x180e8c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180e90: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x180e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x180e94: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x180e94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180e98: 0x10c00011  beqz        $a2, . + 4 + (0x11 << 2)
    ctx->pc = 0x180E98u;
    {
        const bool branch_taken_0x180e98 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x180E9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180E98u;
            // 0x180e9c: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180e98) {
            ctx->pc = 0x180EE0u;
            goto label_180ee0;
        }
    }
    ctx->pc = 0x180EA0u;
    // 0x180ea0: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x180ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x180ea4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180ea8: 0x8c839504  lw          $v1, -0x6AFC($a0)
    ctx->pc = 0x180ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294939908)));
    // 0x180eac: 0x1460000c  bnez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x180EACu;
    {
        const bool branch_taken_0x180eac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x180EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180EACu;
            // 0x180eb0: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180eac) {
            ctx->pc = 0x180EE0u;
            goto label_180ee0;
        }
    }
    ctx->pc = 0x180EB4u;
    // 0x180eb4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x180eb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180eb8: 0xafa70008  sw          $a3, 0x8($sp)
    ctx->pc = 0x180eb8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
    // 0x180ebc: 0xc062448  jal         func_189120
    ctx->pc = 0x180EBCu;
    SET_GPR_U32(ctx, 31, 0x180EC4u);
    ctx->pc = 0x180EC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180EBCu;
            // 0x180ec0: 0xafa5000c  sw          $a1, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189120u;
    if (runtime->hasFunction(0x189120u)) {
        auto targetFn = runtime->lookupFunction(0x189120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180EC4u; }
        if (ctx->pc != 0x180EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189120_0x189120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180EC4u; }
        if (ctx->pc != 0x180EC4u) { return; }
    }
    ctx->pc = 0x180EC4u;
label_180ec4:
    // 0x180ec4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x180ec4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180ec8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180ecc: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x180eccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180ed0: 0x4600003  bltz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x180ED0u;
    {
        const bool branch_taken_0x180ed0 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x180ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180ED0u;
            // 0x180ed4: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180ed0) {
            ctx->pc = 0x180EE0u;
            goto label_180ee0;
        }
    }
    ctx->pc = 0x180ED8u;
    // 0x180ed8: 0xc061eb4  jal         func_187AD0
    ctx->pc = 0x180ED8u;
    SET_GPR_U32(ctx, 31, 0x180EE0u);
    ctx->pc = 0x187AD0u;
    if (runtime->hasFunction(0x187AD0u)) {
        auto targetFn = runtime->lookupFunction(0x187AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180EE0u; }
        if (ctx->pc != 0x180EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187AD0_0x187ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180EE0u; }
        if (ctx->pc != 0x180EE0u) { return; }
    }
    ctx->pc = 0x180EE0u;
label_180ee0:
    // 0x180ee0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x180ee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x180ee4: 0x3e00008  jr          $ra
    ctx->pc = 0x180EE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180EE4u;
            // 0x180ee8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180E60u: goto label_180e60;
            case 0x180E70u: goto label_180e70;
            case 0x180EC4u: goto label_180ec4;
            case 0x180EE0u: goto label_180ee0;
            case 0x180F14u: goto label_180f14;
            case 0x180F18u: goto label_180f18;
            case 0x180F4Cu: goto label_180f4c;
            case 0x180F50u: goto label_180f50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180EECu;
    // 0x180eec: 0x0  nop
    ctx->pc = 0x180eecu;
    // NOP
    // 0x180ef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x180ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x180ef4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180ef8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x180ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x180efc: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x180efcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180f00: 0x18800005  blez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x180F00u;
    {
        const bool branch_taken_0x180f00 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x180F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F00u;
            // 0x180f04: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180f00) {
            ctx->pc = 0x180F18u;
            goto label_180f18;
        }
    }
    ctx->pc = 0x180F08u;
    // 0x180f08: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x180f08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x180f0c: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x180F0Cu;
    SET_GPR_U32(ctx, 31, 0x180F14u);
    ctx->pc = 0x180F10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180F0Cu;
            // 0x180f10: 0x8c449a20  lw          $a0, -0x65E0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294941216)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F14u; }
        if (ctx->pc != 0x180F14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F14u; }
        if (ctx->pc != 0x180F14u) { return; }
    }
    ctx->pc = 0x180F14u;
label_180f14:
    // 0x180f14: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x180f14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_180f18:
    // 0x180f18: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x180f18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180f1c: 0x3e00008  jr          $ra
    ctx->pc = 0x180F1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F1Cu;
            // 0x180f20: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180E60u: goto label_180e60;
            case 0x180E70u: goto label_180e70;
            case 0x180EC4u: goto label_180ec4;
            case 0x180EE0u: goto label_180ee0;
            case 0x180F14u: goto label_180f14;
            case 0x180F18u: goto label_180f18;
            case 0x180F4Cu: goto label_180f4c;
            case 0x180F50u: goto label_180f50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180F24u;
    // 0x180f24: 0x0  nop
    ctx->pc = 0x180f24u;
    // NOP
    // 0x180f28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x180f28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x180f2c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180f30: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x180f30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x180f34: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x180f34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180f38: 0x18800005  blez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x180F38u;
    {
        const bool branch_taken_0x180f38 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x180F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F38u;
            // 0x180f3c: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180f38) {
            ctx->pc = 0x180F50u;
            goto label_180f50;
        }
    }
    ctx->pc = 0x180F40u;
    // 0x180f40: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x180f40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x180f44: 0xc045130  jal         func_1144C0
    ctx->pc = 0x180F44u;
    SET_GPR_U32(ctx, 31, 0x180F4Cu);
    ctx->pc = 0x180F48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180F44u;
            // 0x180f48: 0x8c449a20  lw          $a0, -0x65E0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294941216)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144C0u;
    if (runtime->hasFunction(0x1144C0u)) {
        auto targetFn = runtime->lookupFunction(0x1144C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F4Cu; }
        if (ctx->pc != 0x180F4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144C0_0x1144c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180F4Cu; }
        if (ctx->pc != 0x180F4Cu) { return; }
    }
    ctx->pc = 0x180F4Cu;
label_180f4c:
    // 0x180f4c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x180f4cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_180f50:
    // 0x180f50: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x180f50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180f54: 0x3e00008  jr          $ra
    ctx->pc = 0x180F54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180F54u;
            // 0x180f58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180E60u: goto label_180e60;
            case 0x180E70u: goto label_180e70;
            case 0x180EC4u: goto label_180ec4;
            case 0x180EE0u: goto label_180ee0;
            case 0x180F14u: goto label_180f14;
            case 0x180F18u: goto label_180f18;
            case 0x180F4Cu: goto label_180f4c;
            case 0x180F50u: goto label_180f50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180F5Cu;
    // 0x180f5c: 0x0  nop
    ctx->pc = 0x180f5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
