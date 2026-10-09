#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172CF8
// Address: 0x172cf8 - 0x172e78
void sub_00172CF8_0x172cf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172CF8_0x172cf8");
#endif

    switch (ctx->pc) {
        case 0x172d18u: goto label_172d18;
        case 0x172d28u: goto label_172d28;
        case 0x172d54u: goto label_172d54;
        case 0x172d68u: goto label_172d68;
        case 0x172d8cu: goto label_172d8c;
        case 0x172da0u: goto label_172da0;
        case 0x172db4u: goto label_172db4;
        case 0x172dc4u: goto label_172dc4;
        case 0x172dd8u: goto label_172dd8;
        case 0x172decu: goto label_172dec;
        case 0x172e04u: goto label_172e04;
        case 0x172e1cu: goto label_172e1c;
        case 0x172e30u: goto label_172e30;
        case 0x172e5cu: goto label_172e5c;
        default: break;
    }

    ctx->pc = 0x172cf8u;

    // 0x172cf8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x172cf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x172cfc: 0x24050043  addiu       $a1, $zero, 0x43
    ctx->pc = 0x172cfcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x172d00: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x172d00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x172d04: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x172d04u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172d08: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x172d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x172d0c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x172d0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x172d10: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172D10u;
    SET_GPR_U32(ctx, 31, 0x172D18u);
    ctx->pc = 0x172D14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172D10u;
            // 0x172d14: 0x2611094c  addiu       $s1, $s0, 0x94C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 2380));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D18u; }
        if (ctx->pc != 0x172D18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D18u; }
        if (ctx->pc != 0x172D18u) { return; }
    }
    ctx->pc = 0x172D18u;
label_172d18:
    // 0x172d18: 0x10400051  beqz        $v0, . + 4 + (0x51 << 2)
    ctx->pc = 0x172D18u;
    {
        const bool branch_taken_0x172d18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172D18u;
            // 0x172d1c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172d18) {
            ctx->pc = 0x172E60u;
            goto label_172e60;
        }
    }
    ctx->pc = 0x172D20u;
    // 0x172d20: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172D20u;
    SET_GPR_U32(ctx, 31, 0x172D28u);
    ctx->pc = 0x172D24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172D20u;
            // 0x172d24: 0x2405000f  addiu       $a1, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D28u; }
        if (ctx->pc != 0x172D28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D28u; }
        if (ctx->pc != 0x172D28u) { return; }
    }
    ctx->pc = 0x172D28u;
label_172d28:
    // 0x172d28: 0x5040004e  beql        $v0, $zero, . + 4 + (0x4E << 2)
    ctx->pc = 0x172D28u;
    {
        const bool branch_taken_0x172d28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x172d28) {
            ctx->pc = 0x172D2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172D28u;
            // 0x172d2c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172E64u;
            goto label_172e64;
        }
    }
    ctx->pc = 0x172D30u;
    // 0x172d30: 0x8e030050  lw          $v1, 0x50($s0)
    ctx->pc = 0x172d30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x172d34: 0x1460004a  bnez        $v1, . + 4 + (0x4A << 2)
    ctx->pc = 0x172D34u;
    {
        const bool branch_taken_0x172d34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x172D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172D34u;
            // 0x172d38: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172d34) {
            ctx->pc = 0x172E60u;
            goto label_172e60;
        }
    }
    ctx->pc = 0x172D3Cu;
    // 0x172d3c: 0x8e040048  lw          $a0, 0x48($s0)
    ctx->pc = 0x172d3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x172d40: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x172d40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x172d44: 0x54830047  bnel        $a0, $v1, . + 4 + (0x47 << 2)
    ctx->pc = 0x172D44u;
    {
        const bool branch_taken_0x172d44 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x172d44) {
            ctx->pc = 0x172D48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172D44u;
            // 0x172d48: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172E64u;
            goto label_172e64;
        }
    }
    ctx->pc = 0x172D4Cu;
    // 0x172d4c: 0xc05cbd6  jal         func_172F58
    ctx->pc = 0x172D4Cu;
    SET_GPR_U32(ctx, 31, 0x172D54u);
    ctx->pc = 0x172D50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172D4Cu;
            // 0x172d50: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172F58u;
    if (runtime->hasFunction(0x172F58u)) {
        auto targetFn = runtime->lookupFunction(0x172F58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D54u; }
        if (ctx->pc != 0x172D54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172F58_0x172f58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D54u; }
        if (ctx->pc != 0x172D54u) { return; }
    }
    ctx->pc = 0x172D54u;
label_172d54:
    // 0x172d54: 0x54400042  bnel        $v0, $zero, . + 4 + (0x42 << 2)
    ctx->pc = 0x172D54u;
    {
        const bool branch_taken_0x172d54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x172d54) {
            ctx->pc = 0x172D58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172D54u;
            // 0x172d58: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172E60u;
            goto label_172e60;
        }
    }
    ctx->pc = 0x172D5Cu;
    // 0x172d5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172d5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172d60: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172D60u;
    SET_GPR_U32(ctx, 31, 0x172D68u);
    ctx->pc = 0x172D64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172D60u;
            // 0x172d64: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D68u; }
        if (ctx->pc != 0x172D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D68u; }
        if (ctx->pc != 0x172D68u) { return; }
    }
    ctx->pc = 0x172D68u;
label_172d68:
    // 0x172d68: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x172d68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172d6c: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x172D6Cu;
    {
        const bool branch_taken_0x172d6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x172D70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172D6Cu;
            // 0x172d70: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172d6c) {
            ctx->pc = 0x172D84u;
            goto label_172d84;
        }
    }
    ctx->pc = 0x172D74u;
    // 0x172d74: 0x8e230020  lw          $v1, 0x20($s1)
    ctx->pc = 0x172d74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x172d78: 0x10600039  beqz        $v1, . + 4 + (0x39 << 2)
    ctx->pc = 0x172D78u;
    {
        const bool branch_taken_0x172d78 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x172D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172D78u;
            // 0x172d7c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172d78) {
            ctx->pc = 0x172E60u;
            goto label_172e60;
        }
    }
    ctx->pc = 0x172D80u;
    // 0x172d80: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172d80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_172d84:
    // 0x172d84: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172D84u;
    SET_GPR_U32(ctx, 31, 0x172D8Cu);
    ctx->pc = 0x172D88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172D84u;
            // 0x172d88: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D8Cu; }
        if (ctx->pc != 0x172D8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172D8Cu; }
        if (ctx->pc != 0x172D8Cu) { return; }
    }
    ctx->pc = 0x172D8Cu;
label_172d8c:
    // 0x172d8c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x172d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172d90: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x172D90u;
    {
        const bool branch_taken_0x172d90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x172D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172D90u;
            // 0x172d94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172d90) {
            ctx->pc = 0x172DACu;
            goto label_172dac;
        }
    }
    ctx->pc = 0x172D98u;
    // 0x172d98: 0xc059f48  jal         func_167D20
    ctx->pc = 0x172D98u;
    SET_GPR_U32(ctx, 31, 0x172DA0u);
    ctx->pc = 0x172D9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172D98u;
            // 0x172d9c: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D20u;
    if (runtime->hasFunction(0x167D20u)) {
        auto targetFn = runtime->lookupFunction(0x167D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DA0u; }
        if (ctx->pc != 0x172DA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D20_0x167d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DA0u; }
        if (ctx->pc != 0x172DA0u) { return; }
    }
    ctx->pc = 0x172DA0u;
label_172da0:
    // 0x172da0: 0x1c40002f  bgtz        $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x172DA0u;
    {
        const bool branch_taken_0x172da0 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x172DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172DA0u;
            // 0x172da4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172da0) {
            ctx->pc = 0x172E60u;
            goto label_172e60;
        }
    }
    ctx->pc = 0x172DA8u;
    // 0x172da8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172da8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_172dac:
    // 0x172dac: 0xc05df24  jal         func_177C90
    ctx->pc = 0x172DACu;
    SET_GPR_U32(ctx, 31, 0x172DB4u);
    ctx->pc = 0x172DB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172DACu;
            // 0x172db0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C90u;
    if (runtime->hasFunction(0x177C90u)) {
        auto targetFn = runtime->lookupFunction(0x177C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DB4u; }
        if (ctx->pc != 0x172DB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C90_0x177c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DB4u; }
        if (ctx->pc != 0x172DB4u) { return; }
    }
    ctx->pc = 0x172DB4u;
label_172db4:
    // 0x172db4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x172DB4u;
    {
        const bool branch_taken_0x172db4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172DB4u;
            // 0x172db8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172db4) {
            ctx->pc = 0x172DCCu;
            goto label_172dcc;
        }
    }
    ctx->pc = 0x172DBCu;
    // 0x172dbc: 0xc059f48  jal         func_167D20
    ctx->pc = 0x172DBCu;
    SET_GPR_U32(ctx, 31, 0x172DC4u);
    ctx->pc = 0x172DC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172DBCu;
            // 0x172dc0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D20u;
    if (runtime->hasFunction(0x167D20u)) {
        auto targetFn = runtime->lookupFunction(0x167D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DC4u; }
        if (ctx->pc != 0x172DC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D20_0x167d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DC4u; }
        if (ctx->pc != 0x172DC4u) { return; }
    }
    ctx->pc = 0x172DC4u;
label_172dc4:
    // 0x172dc4: 0x1c400026  bgtz        $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x172DC4u;
    {
        const bool branch_taken_0x172dc4 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x172DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172DC4u;
            // 0x172dc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172dc4) {
            ctx->pc = 0x172E60u;
            goto label_172e60;
        }
    }
    ctx->pc = 0x172DCCu;
label_172dcc:
    // 0x172dcc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172dccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172dd0: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172DD0u;
    SET_GPR_U32(ctx, 31, 0x172DD8u);
    ctx->pc = 0x172DD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172DD0u;
            // 0x172dd4: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DD8u; }
        if (ctx->pc != 0x172DD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DD8u; }
        if (ctx->pc != 0x172DD8u) { return; }
    }
    ctx->pc = 0x172DD8u;
label_172dd8:
    // 0x172dd8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x172dd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172ddc: 0x54430006  bnel        $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x172DDCu;
    {
        const bool branch_taken_0x172ddc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x172ddc) {
            ctx->pc = 0x172DE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172DDCu;
            // 0x172de0: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172DF8u;
            goto label_172df8;
        }
    }
    ctx->pc = 0x172DE4u;
    // 0x172de4: 0xc05cbfe  jal         func_172FF8
    ctx->pc = 0x172DE4u;
    SET_GPR_U32(ctx, 31, 0x172DECu);
    ctx->pc = 0x172DE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172DE4u;
            // 0x172de8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172FF8u;
    if (runtime->hasFunction(0x172FF8u)) {
        auto targetFn = runtime->lookupFunction(0x172FF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DECu; }
        if (ctx->pc != 0x172DECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172FF8_0x172ff8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172DECu; }
        if (ctx->pc != 0x172DECu) { return; }
    }
    ctx->pc = 0x172DECu;
label_172dec:
    // 0x172dec: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x172DECu;
    {
        const bool branch_taken_0x172dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x172DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172DECu;
            // 0x172df0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172dec) {
            ctx->pc = 0x172E60u;
            goto label_172e60;
        }
    }
    ctx->pc = 0x172DF4u;
    // 0x172df4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x172df4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_172df8:
    // 0x172df8: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x172df8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x172dfc: 0xc05d8d4  jal         func_176350
    ctx->pc = 0x172DFCu;
    SET_GPR_U32(ctx, 31, 0x172E04u);
    ctx->pc = 0x172E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172DFCu;
            // 0x172e00: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176350u;
    if (runtime->hasFunction(0x176350u)) {
        auto targetFn = runtime->lookupFunction(0x176350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E04u; }
        if (ctx->pc != 0x172E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176350_0x176350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E04u; }
        if (ctx->pc != 0x172E04u) { return; }
    }
    ctx->pc = 0x172E04u;
label_172e04:
    // 0x172e04: 0x26030cc0  addiu       $v1, $s0, 0xCC0
    ctx->pc = 0x172e04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
    // 0x172e08: 0x8c710244  lw          $s1, 0x244($v1)
    ctx->pc = 0x172e08u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 580)));
    // 0x172e0c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172e0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172e10: 0x24050044  addiu       $a1, $zero, 0x44
    ctx->pc = 0x172e10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
    // 0x172e14: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172E14u;
    SET_GPR_U32(ctx, 31, 0x172E1Cu);
    ctx->pc = 0x172E18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172E14u;
            // 0x172e18: 0x8c700240  lw          $s0, 0x240($v1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 576)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E1Cu; }
        if (ctx->pc != 0x172E1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E1Cu; }
        if (ctx->pc != 0x172E1Cu) { return; }
    }
    ctx->pc = 0x172E1Cu;
label_172e1c:
    // 0x172e1c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x172e1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172e20: 0x3c06000f  lui         $a2, 0xF
    ctx->pc = 0x172e20u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)15 << 16));
    // 0x172e24: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x172e24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172e28: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x172E28u;
    SET_GPR_U32(ctx, 31, 0x172E30u);
    ctx->pc = 0x172E2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172E28u;
            // 0x172e2c: 0x34c64240  ori         $a2, $a2, 0x4240 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)16960);
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E30u; }
        if (ctx->pc != 0x172E30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E30u; }
        if (ctx->pc != 0x172E30u) { return; }
    }
    ctx->pc = 0x172E30u;
label_172e30:
    // 0x172e30: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x172e30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172e34: 0x18800003  blez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x172E34u;
    {
        const bool branch_taken_0x172e34 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x172E38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172E34u;
            // 0x172e38: 0x2028023  subu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172e34) {
            ctx->pc = 0x172E44u;
            goto label_172e44;
        }
    }
    ctx->pc = 0x172E3Cu;
    // 0x172e3c: 0x1e000004  bgtz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x172E3Cu;
    {
        const bool branch_taken_0x172e3c = (GPR_S64(ctx, 16) > 0);
        ctx->pc = 0x172E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172E3Cu;
            // 0x172e40: 0x8fa50004  lw          $a1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172e3c) {
            ctx->pc = 0x172E50u;
            goto label_172e50;
        }
    }
    ctx->pc = 0x172E44u;
label_172e44:
    // 0x172e44: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x172E44u;
    {
        const bool branch_taken_0x172e44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172E44u;
            // 0x172e48: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172e44) {
            ctx->pc = 0x172E60u;
            goto label_172e60;
        }
    }
    ctx->pc = 0x172E4Cu;
    // 0x172e4c: 0x0  nop
    ctx->pc = 0x172e4cu;
    // NOP
label_172e50:
    // 0x172e50: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x172e50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172e54: 0xc05d9de  jal         func_176778
    ctx->pc = 0x172E54u;
    SET_GPR_U32(ctx, 31, 0x172E5Cu);
    ctx->pc = 0x172E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172E54u;
            // 0x172e58: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176778u;
    if (runtime->hasFunction(0x176778u)) {
        auto targetFn = runtime->lookupFunction(0x176778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E5Cu; }
        if (ctx->pc != 0x172E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176778_0x176778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E5Cu; }
        if (ctx->pc != 0x172E5Cu) { return; }
    }
    ctx->pc = 0x172E5Cu;
label_172e5c:
    // 0x172e5c: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x172e5cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_172e60:
    // 0x172e60: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x172e60u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_172e64:
    // 0x172e64: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x172e64u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x172e68: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x172e68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x172e6c: 0x3e00008  jr          $ra
    ctx->pc = 0x172E6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172E6Cu;
            // 0x172e70: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172D18u: goto label_172d18;
            case 0x172D28u: goto label_172d28;
            case 0x172D54u: goto label_172d54;
            case 0x172D68u: goto label_172d68;
            case 0x172D84u: goto label_172d84;
            case 0x172D8Cu: goto label_172d8c;
            case 0x172DA0u: goto label_172da0;
            case 0x172DACu: goto label_172dac;
            case 0x172DB4u: goto label_172db4;
            case 0x172DC4u: goto label_172dc4;
            case 0x172DCCu: goto label_172dcc;
            case 0x172DD8u: goto label_172dd8;
            case 0x172DECu: goto label_172dec;
            case 0x172DF8u: goto label_172df8;
            case 0x172E04u: goto label_172e04;
            case 0x172E1Cu: goto label_172e1c;
            case 0x172E30u: goto label_172e30;
            case 0x172E44u: goto label_172e44;
            case 0x172E50u: goto label_172e50;
            case 0x172E5Cu: goto label_172e5c;
            case 0x172E60u: goto label_172e60;
            case 0x172E64u: goto label_172e64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172E74u;
    // 0x172e74: 0x0  nop
    ctx->pc = 0x172e74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
