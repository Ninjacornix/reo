#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179D58
// Address: 0x179d58 - 0x17a040
void sub_00179D58_0x179d58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179D58_0x179d58");
#endif

    switch (ctx->pc) {
        case 0x179d74u: goto label_179d74;
        case 0x179dd4u: goto label_179dd4;
        case 0x179de8u: goto label_179de8;
        case 0x179e3cu: goto label_179e3c;
        case 0x179e50u: goto label_179e50;
        case 0x179ebcu: goto label_179ebc;
        case 0x179ed0u: goto label_179ed0;
        case 0x179f24u: goto label_179f24;
        case 0x179f38u: goto label_179f38;
        case 0x179f8cu: goto label_179f8c;
        case 0x179fa0u: goto label_179fa0;
        case 0x179ff4u: goto label_179ff4;
        case 0x17a008u: goto label_17a008;
        default: break;
    }

    ctx->pc = 0x179d58u;

label_179d58:
    // 0x179d58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179d58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179d5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179d5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179d60: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x179d60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179d64: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179d64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179d68: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179d68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179d6c: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179D6Cu;
    SET_GPR_U32(ctx, 31, 0x179D74u);
    ctx->pc = 0x179D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179D6Cu;
            // 0x179d70: 0x8c910004  lw          $s1, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179D74u; }
        if (ctx->pc != 0x179D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179D74u; }
        if (ctx->pc != 0x179D74u) { return; }
    }
    ctx->pc = 0x179D74u;
label_179d74:
    // 0x179d74: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179d74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179d78: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x179D78u;
    {
        const bool branch_taken_0x179d78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x179D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179D78u;
            // 0x179d7c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179d78) {
            ctx->pc = 0x179D98u;
            goto label_179d98;
        }
    }
    ctx->pc = 0x179D80u;
    // 0x179d80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179d80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179d84: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179d84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179d88: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179d88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179d8c: 0x805e54e  j           func_179538
    ctx->pc = 0x179D8Cu;
    ctx->pc = 0x179D90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179D8Cu;
            // 0x179d90: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179538u;
    if (runtime->hasFunction(0x179538u)) {
        auto targetFn = runtime->lookupFunction(0x179538u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00179538_0x179538(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x179D94u;
    // 0x179d94: 0x0  nop
    ctx->pc = 0x179d94u;
    // NOP
label_179d98:
    // 0x179d98: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179d98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179d9c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179d9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179da0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179da0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179da4: 0x3e00008  jr          $ra
    ctx->pc = 0x179DA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179DA4u;
            // 0x179da8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179D58u: goto label_179d58;
            case 0x179D74u: goto label_179d74;
            case 0x179D98u: goto label_179d98;
            case 0x179DD4u: goto label_179dd4;
            case 0x179DE8u: goto label_179de8;
            case 0x179E00u: goto label_179e00;
            case 0x179E3Cu: goto label_179e3c;
            case 0x179E50u: goto label_179e50;
            case 0x179E68u: goto label_179e68;
            case 0x179E80u: goto label_179e80;
            case 0x179EBCu: goto label_179ebc;
            case 0x179ED0u: goto label_179ed0;
            case 0x179EE8u: goto label_179ee8;
            case 0x179F24u: goto label_179f24;
            case 0x179F38u: goto label_179f38;
            case 0x179F50u: goto label_179f50;
            case 0x179F8Cu: goto label_179f8c;
            case 0x179FA0u: goto label_179fa0;
            case 0x179FB8u: goto label_179fb8;
            case 0x179FF4u: goto label_179ff4;
            case 0x17A008u: goto label_17a008;
            case 0x17A028u: goto label_17a028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179DACu;
    // 0x179dac: 0x0  nop
    ctx->pc = 0x179dacu;
    // NOP
    // 0x179db0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179db4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179db8: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179db8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179dbc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179dbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179dc0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179dc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179dc4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179dc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179dc8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179dc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179dcc: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179DCCu;
    SET_GPR_U32(ctx, 31, 0x179DD4u);
    ctx->pc = 0x179DD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179DCCu;
            // 0x179dd0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    goto label_179d58;
    ctx->pc = 0x179DD4u;
label_179dd4:
    // 0x179dd4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179dd4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179dd8: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x179DD8u;
    {
        const bool branch_taken_0x179dd8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179DD8u;
            // 0x179ddc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179dd8) {
            ctx->pc = 0x179E00u;
            goto label_179e00;
        }
    }
    ctx->pc = 0x179DE0u;
    // 0x179de0: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179DE0u;
    SET_GPR_U32(ctx, 31, 0x179DE8u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179DE8u; }
        if (ctx->pc != 0x179DE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179DE8u; }
        if (ctx->pc != 0x179DE8u) { return; }
    }
    ctx->pc = 0x179DE8u;
label_179de8:
    // 0x179de8: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x179de8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x179dec: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179DECu;
    {
        const bool branch_taken_0x179dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x179DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179DECu;
            // 0x179df0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179dec) {
            ctx->pc = 0x179E00u;
            goto label_179e00;
        }
    }
    ctx->pc = 0x179DF4u;
    // 0x179df4: 0x92230019  lbu         $v1, 0x19($s1)
    ctx->pc = 0x179df4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 25)));
    // 0x179df8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179df8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179dfc: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179dfcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179e00:
    // 0x179e00: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179e00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179e04: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179e04u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179e08: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179e08u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179e0c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179e0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179e10: 0x3e00008  jr          $ra
    ctx->pc = 0x179E10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E10u;
            // 0x179e14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179D58u: goto label_179d58;
            case 0x179D74u: goto label_179d74;
            case 0x179D98u: goto label_179d98;
            case 0x179DD4u: goto label_179dd4;
            case 0x179DE8u: goto label_179de8;
            case 0x179E00u: goto label_179e00;
            case 0x179E3Cu: goto label_179e3c;
            case 0x179E50u: goto label_179e50;
            case 0x179E68u: goto label_179e68;
            case 0x179E80u: goto label_179e80;
            case 0x179EBCu: goto label_179ebc;
            case 0x179ED0u: goto label_179ed0;
            case 0x179EE8u: goto label_179ee8;
            case 0x179F24u: goto label_179f24;
            case 0x179F38u: goto label_179f38;
            case 0x179F50u: goto label_179f50;
            case 0x179F8Cu: goto label_179f8c;
            case 0x179FA0u: goto label_179fa0;
            case 0x179FB8u: goto label_179fb8;
            case 0x179FF4u: goto label_179ff4;
            case 0x17A008u: goto label_17a008;
            case 0x17A028u: goto label_17a028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179E18u;
    // 0x179e18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179e18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179e1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179e20: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179e20u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179e24: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179e24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179e28: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179e2c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179e2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179e30: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179e34: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179E34u;
    SET_GPR_U32(ctx, 31, 0x179E3Cu);
    ctx->pc = 0x179E38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179E34u;
            // 0x179e38: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    goto label_179d58;
    ctx->pc = 0x179E3Cu;
label_179e3c:
    // 0x179e3c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179e3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179e40: 0x1220000f  beqz        $s1, . + 4 + (0xF << 2)
    ctx->pc = 0x179E40u;
    {
        const bool branch_taken_0x179e40 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E40u;
            // 0x179e44: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179e40) {
            ctx->pc = 0x179E80u;
            goto label_179e80;
        }
    }
    ctx->pc = 0x179E48u;
    // 0x179e48: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179E48u;
    SET_GPR_U32(ctx, 31, 0x179E50u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179E50u; }
        if (ctx->pc != 0x179E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179E50u; }
        if (ctx->pc != 0x179E50u) { return; }
    }
    ctx->pc = 0x179E50u;
label_179e50:
    // 0x179e50: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x179e50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x179e54: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179E54u;
    {
        const bool branch_taken_0x179e54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x179E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E54u;
            // 0x179e58: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179e54) {
            ctx->pc = 0x179E68u;
            goto label_179e68;
        }
    }
    ctx->pc = 0x179E5Cu;
    // 0x179e5c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x179E5Cu;
    {
        const bool branch_taken_0x179e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x179E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E5Cu;
            // 0x179e60: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179e5c) {
            ctx->pc = 0x179E80u;
            goto label_179e80;
        }
    }
    ctx->pc = 0x179E64u;
    // 0x179e64: 0x0  nop
    ctx->pc = 0x179e64u;
    // NOP
label_179e68:
    // 0x179e68: 0x92230019  lbu         $v1, 0x19($s1)
    ctx->pc = 0x179e68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 25)));
    // 0x179e6c: 0x14640004  bne         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x179E6Cu;
    {
        const bool branch_taken_0x179e6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x179E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E6Cu;
            // 0x179e70: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179e6c) {
            ctx->pc = 0x179E80u;
            goto label_179e80;
        }
    }
    ctx->pc = 0x179E74u;
    // 0x179e74: 0x9223001a  lbu         $v1, 0x1A($s1)
    ctx->pc = 0x179e74u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x179e78: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179e7c: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179e80:
    // 0x179e80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179e80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179e84: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179e84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179e88: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179e88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179e8c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179e8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179e90: 0x3e00008  jr          $ra
    ctx->pc = 0x179E90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E90u;
            // 0x179e94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179D58u: goto label_179d58;
            case 0x179D74u: goto label_179d74;
            case 0x179D98u: goto label_179d98;
            case 0x179DD4u: goto label_179dd4;
            case 0x179DE8u: goto label_179de8;
            case 0x179E00u: goto label_179e00;
            case 0x179E3Cu: goto label_179e3c;
            case 0x179E50u: goto label_179e50;
            case 0x179E68u: goto label_179e68;
            case 0x179E80u: goto label_179e80;
            case 0x179EBCu: goto label_179ebc;
            case 0x179ED0u: goto label_179ed0;
            case 0x179EE8u: goto label_179ee8;
            case 0x179F24u: goto label_179f24;
            case 0x179F38u: goto label_179f38;
            case 0x179F50u: goto label_179f50;
            case 0x179F8Cu: goto label_179f8c;
            case 0x179FA0u: goto label_179fa0;
            case 0x179FB8u: goto label_179fb8;
            case 0x179FF4u: goto label_179ff4;
            case 0x17A008u: goto label_17a008;
            case 0x17A028u: goto label_17a028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179E98u;
    // 0x179e98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179e9c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179ea0: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179ea0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179ea4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179ea4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179ea8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179ea8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179eac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179eb0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179eb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179eb4: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179EB4u;
    SET_GPR_U32(ctx, 31, 0x179EBCu);
    ctx->pc = 0x179EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179EB4u;
            // 0x179eb8: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    goto label_179d58;
    ctx->pc = 0x179EBCu;
label_179ebc:
    // 0x179ebc: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179ebcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179ec0: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x179EC0u;
    {
        const bool branch_taken_0x179ec0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179EC0u;
            // 0x179ec4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179ec0) {
            ctx->pc = 0x179EE8u;
            goto label_179ee8;
        }
    }
    ctx->pc = 0x179EC8u;
    // 0x179ec8: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179EC8u;
    SET_GPR_U32(ctx, 31, 0x179ED0u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179ED0u; }
        if (ctx->pc != 0x179ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179ED0u; }
        if (ctx->pc != 0x179ED0u) { return; }
    }
    ctx->pc = 0x179ED0u;
label_179ed0:
    // 0x179ed0: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x179ed0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x179ed4: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179ED4u;
    {
        const bool branch_taken_0x179ed4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x179ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179ED4u;
            // 0x179ed8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179ed4) {
            ctx->pc = 0x179EE8u;
            goto label_179ee8;
        }
    }
    ctx->pc = 0x179EDCu;
    // 0x179edc: 0x9223001b  lbu         $v1, 0x1B($s1)
    ctx->pc = 0x179edcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 27)));
    // 0x179ee0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179ee4: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179ee4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179ee8:
    // 0x179ee8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179ee8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179eec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179eecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179ef0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179ef0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179ef4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179ef4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179ef8: 0x3e00008  jr          $ra
    ctx->pc = 0x179EF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179EF8u;
            // 0x179efc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179D58u: goto label_179d58;
            case 0x179D74u: goto label_179d74;
            case 0x179D98u: goto label_179d98;
            case 0x179DD4u: goto label_179dd4;
            case 0x179DE8u: goto label_179de8;
            case 0x179E00u: goto label_179e00;
            case 0x179E3Cu: goto label_179e3c;
            case 0x179E50u: goto label_179e50;
            case 0x179E68u: goto label_179e68;
            case 0x179E80u: goto label_179e80;
            case 0x179EBCu: goto label_179ebc;
            case 0x179ED0u: goto label_179ed0;
            case 0x179EE8u: goto label_179ee8;
            case 0x179F24u: goto label_179f24;
            case 0x179F38u: goto label_179f38;
            case 0x179F50u: goto label_179f50;
            case 0x179F8Cu: goto label_179f8c;
            case 0x179FA0u: goto label_179fa0;
            case 0x179FB8u: goto label_179fb8;
            case 0x179FF4u: goto label_179ff4;
            case 0x17A008u: goto label_17a008;
            case 0x17A028u: goto label_17a028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179F00u;
    // 0x179f00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179f00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179f04: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179f04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179f08: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179f08u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179f0c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179f0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179f10: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179f10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179f14: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179f14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179f18: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179f18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179f1c: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179F1Cu;
    SET_GPR_U32(ctx, 31, 0x179F24u);
    ctx->pc = 0x179F20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179F1Cu;
            // 0x179f20: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    goto label_179d58;
    ctx->pc = 0x179F24u;
label_179f24:
    // 0x179f24: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179f24u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179f28: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x179F28u;
    {
        const bool branch_taken_0x179f28 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179F28u;
            // 0x179f2c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179f28) {
            ctx->pc = 0x179F50u;
            goto label_179f50;
        }
    }
    ctx->pc = 0x179F30u;
    // 0x179f30: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179F30u;
    SET_GPR_U32(ctx, 31, 0x179F38u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179F38u; }
        if (ctx->pc != 0x179F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179F38u; }
        if (ctx->pc != 0x179F38u) { return; }
    }
    ctx->pc = 0x179F38u;
label_179f38:
    // 0x179f38: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x179f38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x179f3c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179F3Cu;
    {
        const bool branch_taken_0x179f3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x179F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179F3Cu;
            // 0x179f40: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179f3c) {
            ctx->pc = 0x179F50u;
            goto label_179f50;
        }
    }
    ctx->pc = 0x179F44u;
    // 0x179f44: 0x8e23001c  lw          $v1, 0x1C($s1)
    ctx->pc = 0x179f44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x179f48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179f48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179f4c: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179f50:
    // 0x179f50: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179f50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179f54: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179f54u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179f58: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179f58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179f5c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179f5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179f60: 0x3e00008  jr          $ra
    ctx->pc = 0x179F60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179F60u;
            // 0x179f64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179D58u: goto label_179d58;
            case 0x179D74u: goto label_179d74;
            case 0x179D98u: goto label_179d98;
            case 0x179DD4u: goto label_179dd4;
            case 0x179DE8u: goto label_179de8;
            case 0x179E00u: goto label_179e00;
            case 0x179E3Cu: goto label_179e3c;
            case 0x179E50u: goto label_179e50;
            case 0x179E68u: goto label_179e68;
            case 0x179E80u: goto label_179e80;
            case 0x179EBCu: goto label_179ebc;
            case 0x179ED0u: goto label_179ed0;
            case 0x179EE8u: goto label_179ee8;
            case 0x179F24u: goto label_179f24;
            case 0x179F38u: goto label_179f38;
            case 0x179F50u: goto label_179f50;
            case 0x179F8Cu: goto label_179f8c;
            case 0x179FA0u: goto label_179fa0;
            case 0x179FB8u: goto label_179fb8;
            case 0x179FF4u: goto label_179ff4;
            case 0x17A008u: goto label_17a008;
            case 0x17A028u: goto label_17a028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179F68u;
    // 0x179f68: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179f68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179f6c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179f6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179f70: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179f70u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179f74: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179f74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179f78: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179f78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179f7c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179f80: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179f80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179f84: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179F84u;
    SET_GPR_U32(ctx, 31, 0x179F8Cu);
    ctx->pc = 0x179F88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179F84u;
            // 0x179f88: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    goto label_179d58;
    ctx->pc = 0x179F8Cu;
label_179f8c:
    // 0x179f8c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179f8cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179f90: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x179F90u;
    {
        const bool branch_taken_0x179f90 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179F90u;
            // 0x179f94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179f90) {
            ctx->pc = 0x179FB8u;
            goto label_179fb8;
        }
    }
    ctx->pc = 0x179F98u;
    // 0x179f98: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179F98u;
    SET_GPR_U32(ctx, 31, 0x179FA0u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179FA0u; }
        if (ctx->pc != 0x179FA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179FA0u; }
        if (ctx->pc != 0x179FA0u) { return; }
    }
    ctx->pc = 0x179FA0u;
label_179fa0:
    // 0x179fa0: 0x240300e0  addiu       $v1, $zero, 0xE0
    ctx->pc = 0x179fa0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x179fa4: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179FA4u;
    {
        const bool branch_taken_0x179fa4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x179FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179FA4u;
            // 0x179fa8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179fa4) {
            ctx->pc = 0x179FB8u;
            goto label_179fb8;
        }
    }
    ctx->pc = 0x179FACu;
    // 0x179fac: 0x92230019  lbu         $v1, 0x19($s1)
    ctx->pc = 0x179facu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 25)));
    // 0x179fb0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179fb4: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179fb8:
    // 0x179fb8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179fb8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179fbc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179fbcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179fc0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179fc0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179fc4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179fc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179fc8: 0x3e00008  jr          $ra
    ctx->pc = 0x179FC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179FC8u;
            // 0x179fcc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179D58u: goto label_179d58;
            case 0x179D74u: goto label_179d74;
            case 0x179D98u: goto label_179d98;
            case 0x179DD4u: goto label_179dd4;
            case 0x179DE8u: goto label_179de8;
            case 0x179E00u: goto label_179e00;
            case 0x179E3Cu: goto label_179e3c;
            case 0x179E50u: goto label_179e50;
            case 0x179E68u: goto label_179e68;
            case 0x179E80u: goto label_179e80;
            case 0x179EBCu: goto label_179ebc;
            case 0x179ED0u: goto label_179ed0;
            case 0x179EE8u: goto label_179ee8;
            case 0x179F24u: goto label_179f24;
            case 0x179F38u: goto label_179f38;
            case 0x179F50u: goto label_179f50;
            case 0x179F8Cu: goto label_179f8c;
            case 0x179FA0u: goto label_179fa0;
            case 0x179FB8u: goto label_179fb8;
            case 0x179FF4u: goto label_179ff4;
            case 0x17A008u: goto label_17a008;
            case 0x17A028u: goto label_17a028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179FD0u;
    // 0x179fd0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179fd4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179fd8: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179fd8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179fdc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179fdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179fe0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179fe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179fe4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179fe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179fe8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179fec: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179FECu;
    SET_GPR_U32(ctx, 31, 0x179FF4u);
    ctx->pc = 0x179FF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179FECu;
            // 0x179ff0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    goto label_179d58;
    ctx->pc = 0x179FF4u;
label_179ff4:
    // 0x179ff4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179ff4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179ff8: 0x1220000b  beqz        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x179FF8u;
    {
        const bool branch_taken_0x179ff8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179FF8u;
            // 0x179ffc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179ff8) {
            ctx->pc = 0x17A028u;
            goto label_17a028;
        }
    }
    ctx->pc = 0x17A000u;
    // 0x17a000: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x17A000u;
    SET_GPR_U32(ctx, 31, 0x17A008u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A008u; }
        if (ctx->pc != 0x17A008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A008u; }
        if (ctx->pc != 0x17A008u) { return; }
    }
    ctx->pc = 0x17A008u;
label_17a008:
    // 0x17a008: 0x240300e0  addiu       $v1, $zero, 0xE0
    ctx->pc = 0x17a008u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x17a00c: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x17A00Cu;
    {
        const bool branch_taken_0x17a00c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17A010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A00Cu;
            // 0x17a010: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a00c) {
            ctx->pc = 0x17A028u;
            goto label_17a028;
        }
    }
    ctx->pc = 0x17A014u;
    // 0x17a014: 0x9623001a  lhu         $v1, 0x1A($s1)
    ctx->pc = 0x17a014u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x17a018: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a018u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a01c: 0x3864ffff  xori        $a0, $v1, 0xFFFF
    ctx->pc = 0x17a01cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)65535);
    // 0x17a020: 0x4180a  movz        $v1, $zero, $a0
    ctx->pc = 0x17a020u;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x17a024: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a024u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a028:
    // 0x17a028: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a028u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a02c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a02cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a030: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a030u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a034: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a034u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a038: 0x3e00008  jr          $ra
    ctx->pc = 0x17A038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A03Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A038u;
            // 0x17a03c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179D58u: goto label_179d58;
            case 0x179D74u: goto label_179d74;
            case 0x179D98u: goto label_179d98;
            case 0x179DD4u: goto label_179dd4;
            case 0x179DE8u: goto label_179de8;
            case 0x179E00u: goto label_179e00;
            case 0x179E3Cu: goto label_179e3c;
            case 0x179E50u: goto label_179e50;
            case 0x179E68u: goto label_179e68;
            case 0x179E80u: goto label_179e80;
            case 0x179EBCu: goto label_179ebc;
            case 0x179ED0u: goto label_179ed0;
            case 0x179EE8u: goto label_179ee8;
            case 0x179F24u: goto label_179f24;
            case 0x179F38u: goto label_179f38;
            case 0x179F50u: goto label_179f50;
            case 0x179F8Cu: goto label_179f8c;
            case 0x179FA0u: goto label_179fa0;
            case 0x179FB8u: goto label_179fb8;
            case 0x179FF4u: goto label_179ff4;
            case 0x17A008u: goto label_17a008;
            case 0x17A028u: goto label_17a028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A040u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
