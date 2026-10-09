#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180CD0
// Address: 0x180cd0 - 0x180d90
void sub_00180CD0_0x180cd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180CD0_0x180cd0");
#endif

    switch (ctx->pc) {
        case 0x180d24u: goto label_180d24;
        case 0x180d38u: goto label_180d38;
        case 0x180d4cu: goto label_180d4c;
        case 0x180d60u: goto label_180d60;
        case 0x180d68u: goto label_180d68;
        case 0x180d70u: goto label_180d70;
        default: break;
    }

    ctx->pc = 0x180cd0u;

    // 0x180cd0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x180cd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x180cd4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180cd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180cd8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x180cd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x180cdc: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x180cdcu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x180ce0: 0x8e23fa10  lw          $v1, -0x5F0($s1)
    ctx->pc = 0x180ce0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294965776)));
    // 0x180ce4: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x180ce4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
    // 0x180ce8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x180ce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x180cec: 0x10600022  beqz        $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x180CECu;
    {
        const bool branch_taken_0x180cec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x180CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180CECu;
            // 0x180cf0: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180cec) {
            ctx->pc = 0x180D78u;
            goto label_180d78;
        }
    }
    ctx->pc = 0x180CF4u;
    // 0x180cf4: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x180cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x180cf8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180cfc: 0x8c649504  lw          $a0, -0x6AFC($v1)
    ctx->pc = 0x180cfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294939908)));
    // 0x180d00: 0x1480001d  bnez        $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x180D00u;
    {
        const bool branch_taken_0x180d00 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x180D04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180D00u;
            // 0x180d04: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180d00) {
            ctx->pc = 0x180D78u;
            goto label_180d78;
        }
    }
    ctx->pc = 0x180D08u;
    // 0x180d08: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x180d08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x180d0c: 0x24509a20  addiu       $s0, $v0, -0x65E0
    ctx->pc = 0x180d0cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941216));
    // 0x180d10: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x180d10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x180d14: 0x4820004  bltzl       $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x180D14u;
    {
        const bool branch_taken_0x180d14 = (GPR_S64(ctx, 4) < 0);
        if (branch_taken_0x180d14) {
            ctx->pc = 0x180D18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x180D14u;
            // 0x180d18: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x180D28u;
            goto label_180d28;
        }
    }
    ctx->pc = 0x180D1Cu;
    // 0x180d1c: 0xc04518c  jal         func_114630
    ctx->pc = 0x180D1Cu;
    SET_GPR_U32(ctx, 31, 0x180D24u);
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D24u; }
        if (ctx->pc != 0x180D24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D24u; }
        if (ctx->pc != 0x180D24u) { return; }
    }
    ctx->pc = 0x180D24u;
label_180d24:
    // 0x180d24: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x180d24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_180d28:
    // 0x180d28: 0x4820004  bltzl       $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x180D28u;
    {
        const bool branch_taken_0x180d28 = (GPR_S64(ctx, 4) < 0);
        if (branch_taken_0x180d28) {
            ctx->pc = 0x180D2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x180D28u;
            // 0x180d2c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x180D3Cu;
            goto label_180d3c;
        }
    }
    ctx->pc = 0x180D30u;
    // 0x180d30: 0xc04518c  jal         func_114630
    ctx->pc = 0x180D30u;
    SET_GPR_U32(ctx, 31, 0x180D38u);
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D38u; }
        if (ctx->pc != 0x180D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D38u; }
        if (ctx->pc != 0x180D38u) { return; }
    }
    ctx->pc = 0x180D38u;
label_180d38:
    // 0x180d38: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x180d38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_180d3c:
    // 0x180d3c: 0x480000a  bltz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x180D3Cu;
    {
        const bool branch_taken_0x180d3c = (GPR_S64(ctx, 4) < 0);
        if (branch_taken_0x180d3c) {
            ctx->pc = 0x180D68u;
            goto label_180d68;
        }
    }
    ctx->pc = 0x180D44u;
    // 0x180d44: 0xc04511c  jal         func_114470
    ctx->pc = 0x180D44u;
    SET_GPR_U32(ctx, 31, 0x180D4Cu);
    ctx->pc = 0x114470u;
    if (runtime->hasFunction(0x114470u)) {
        auto targetFn = runtime->lookupFunction(0x114470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D4Cu; }
        if (ctx->pc != 0x180D4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114470_0x114470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D4Cu; }
        if (ctx->pc != 0x180D4Cu) { return; }
    }
    ctx->pc = 0x180D4Cu;
label_180d4c:
    // 0x180d4c: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x180D4Cu;
    {
        const bool branch_taken_0x180d4c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x180d4c) {
            ctx->pc = 0x180D60u;
            goto label_180d60;
        }
    }
    ctx->pc = 0x180D54u;
    // 0x180d54: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x180d54u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x180d58: 0xc045a12  jal         func_116848
    ctx->pc = 0x180D58u;
    SET_GPR_U32(ctx, 31, 0x180D60u);
    ctx->pc = 0x180D5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180D58u;
            // 0x180d5c: 0x24841600  addiu       $a0, $a0, 0x1600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D60u; }
        if (ctx->pc != 0x180D60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D60u; }
        if (ctx->pc != 0x180D60u) { return; }
    }
    ctx->pc = 0x180D60u;
label_180d60:
    // 0x180d60: 0xc04510c  jal         func_114430
    ctx->pc = 0x180D60u;
    SET_GPR_U32(ctx, 31, 0x180D68u);
    ctx->pc = 0x180D64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180D60u;
            // 0x180d64: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114430u;
    if (runtime->hasFunction(0x114430u)) {
        auto targetFn = runtime->lookupFunction(0x114430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D68u; }
        if (ctx->pc != 0x180D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114430_0x114430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D68u; }
        if (ctx->pc != 0x180D68u) { return; }
    }
    ctx->pc = 0x180D68u;
label_180d68:
    // 0x180d68: 0xc061e38  jal         func_1878E0
    ctx->pc = 0x180D68u;
    SET_GPR_U32(ctx, 31, 0x180D70u);
    ctx->pc = 0x1878E0u;
    if (runtime->hasFunction(0x1878E0u)) {
        auto targetFn = runtime->lookupFunction(0x1878E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D70u; }
        if (ctx->pc != 0x180D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001878E0_0x1878e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180D70u; }
        if (ctx->pc != 0x180D70u) { return; }
    }
    ctx->pc = 0x180D70u;
label_180d70:
    // 0x180d70: 0xae20fa10  sw          $zero, -0x5F0($s1)
    ctx->pc = 0x180d70u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294965776), GPR_U32(ctx, 0));
    // 0x180d74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x180d74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_180d78:
    // 0x180d78: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x180d78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180d7c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x180d7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x180d80: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x180d80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x180d84: 0x3e00008  jr          $ra
    ctx->pc = 0x180D84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180D84u;
            // 0x180d88: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180D24u: goto label_180d24;
            case 0x180D28u: goto label_180d28;
            case 0x180D38u: goto label_180d38;
            case 0x180D3Cu: goto label_180d3c;
            case 0x180D4Cu: goto label_180d4c;
            case 0x180D60u: goto label_180d60;
            case 0x180D68u: goto label_180d68;
            case 0x180D70u: goto label_180d70;
            case 0x180D78u: goto label_180d78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180D8Cu;
    // 0x180d8c: 0x0  nop
    ctx->pc = 0x180d8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
