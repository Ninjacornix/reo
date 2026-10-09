#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124CD8
// Address: 0x124cd8 - 0x124e40
void sub_00124CD8_0x124cd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124CD8_0x124cd8");
#endif

    switch (ctx->pc) {
        case 0x124d38u: goto label_124d38;
        case 0x124d68u: goto label_124d68;
        case 0x124d98u: goto label_124d98;
        case 0x124dc8u: goto label_124dc8;
        case 0x124df8u: goto label_124df8;
        default: break;
    }

    ctx->pc = 0x124cd8u;

    // 0x124cd8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x124cd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x124cdc: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x124cdcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x124ce0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x124ce0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124ce4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x124ce4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124ce8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x124ce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x124cec: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x124cecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124cf0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x124cf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x124cf4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x124cf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x124cf8: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x124cf8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x124cfc: 0x33a00  sll         $a3, $v1, 8
    ctx->pc = 0x124cfcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x124d00: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x124d00u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x124d04: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x124d04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x124d08: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x124d08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x124d0c: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x124D0Cu;
    {
        const bool branch_taken_0x124d0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x124D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124D0Cu;
            // 0x124d10: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124d0c) {
            ctx->pc = 0x124D30u;
            goto label_124d30;
        }
    }
    ctx->pc = 0x124D14u;
    // 0x124d14: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124d14u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124d18: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124d18u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124d1c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124d1cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124d20: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124d20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124d24: 0x804927a  j           func_1249E8
    ctx->pc = 0x124D24u;
    ctx->pc = 0x124D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124D24u;
            // 0x124d28: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1249E8u;
    if (runtime->hasFunction(0x1249E8u)) {
        auto targetFn = runtime->lookupFunction(0x1249E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001249E8_0x1249e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124D2Cu;
    // 0x124d2c: 0x0  nop
    ctx->pc = 0x124d2cu;
    // NOP
label_124d30:
    // 0x124d30: 0xc049702  jal         func_125C08
    ctx->pc = 0x124D30u;
    SET_GPR_U32(ctx, 31, 0x124D38u);
    ctx->pc = 0x124D34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124D30u;
            // 0x124d34: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125C08u;
    if (runtime->hasFunction(0x125C08u)) {
        auto targetFn = runtime->lookupFunction(0x125C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124D38u; }
        if (ctx->pc != 0x124D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125C08_0x125c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124D38u; }
        if (ctx->pc != 0x124D38u) { return; }
    }
    ctx->pc = 0x124D38u;
label_124d38:
    // 0x124d38: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x124D38u;
    {
        const bool branch_taken_0x124d38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x124D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124D38u;
            // 0x124d3c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124d38) {
            ctx->pc = 0x124D60u;
            goto label_124d60;
        }
    }
    ctx->pc = 0x124D40u;
    // 0x124d40: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124d40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124d44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124d44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124d48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124d48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124d4c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x124d4cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124d50: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124d50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124d54: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124d54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124d58: 0x8049666  j           func_125998
    ctx->pc = 0x124D58u;
    ctx->pc = 0x124D5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124D58u;
            // 0x124d5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125998u;
    if (runtime->hasFunction(0x125998u)) {
        auto targetFn = runtime->lookupFunction(0x125998u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125998_0x125998(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124D60u;
label_124d60:
    // 0x124d60: 0xc049904  jal         func_126410
    ctx->pc = 0x124D60u;
    SET_GPR_U32(ctx, 31, 0x124D68u);
    ctx->pc = 0x124D64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124D60u;
            // 0x124d64: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126410u;
    if (runtime->hasFunction(0x126410u)) {
        auto targetFn = runtime->lookupFunction(0x126410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124D68u; }
        if (ctx->pc != 0x124D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126410_0x126410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124D68u; }
        if (ctx->pc != 0x124D68u) { return; }
    }
    ctx->pc = 0x124D68u;
label_124d68:
    // 0x124d68: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x124D68u;
    {
        const bool branch_taken_0x124d68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x124D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124D68u;
            // 0x124d6c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124d68) {
            ctx->pc = 0x124D90u;
            goto label_124d90;
        }
    }
    ctx->pc = 0x124D70u;
    // 0x124d70: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124d70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124d74: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124d74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124d78: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124d78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124d7c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x124d7cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124d80: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124d80u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124d84: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124d84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124d88: 0x8049798  j           func_125E60
    ctx->pc = 0x124D88u;
    ctx->pc = 0x124D8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124D88u;
            // 0x124d8c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125E60u;
    if (runtime->hasFunction(0x125E60u)) {
        auto targetFn = runtime->lookupFunction(0x125E60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125E60_0x125e60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124D90u;
label_124d90:
    // 0x124d90: 0xc048d1c  jal         func_123470
    ctx->pc = 0x124D90u;
    SET_GPR_U32(ctx, 31, 0x124D98u);
    ctx->pc = 0x124D94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124D90u;
            // 0x124d94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123470u;
    if (runtime->hasFunction(0x123470u)) {
        auto targetFn = runtime->lookupFunction(0x123470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124D98u; }
        if (ctx->pc != 0x124D98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00123470_0x123470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124D98u; }
        if (ctx->pc != 0x124D98u) { return; }
    }
    ctx->pc = 0x124D98u;
label_124d98:
    // 0x124d98: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x124D98u;
    {
        const bool branch_taken_0x124d98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x124D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124D98u;
            // 0x124d9c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124d98) {
            ctx->pc = 0x124DC0u;
            goto label_124dc0;
        }
    }
    ctx->pc = 0x124DA0u;
    // 0x124da0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124da0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124da4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124da4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124da8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124da8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124dac: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x124dacu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124db0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124db0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124db4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124db4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124db8: 0x8048d7a  j           func_1235E8
    ctx->pc = 0x124DB8u;
    ctx->pc = 0x124DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124DB8u;
            // 0x124dbc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1235E8u;
    if (runtime->hasFunction(0x1235E8u)) {
        auto targetFn = runtime->lookupFunction(0x1235E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001235E8_0x1235e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124DC0u;
label_124dc0:
    // 0x124dc0: 0xc048f56  jal         func_123D58
    ctx->pc = 0x124DC0u;
    SET_GPR_U32(ctx, 31, 0x124DC8u);
    ctx->pc = 0x124DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124DC0u;
            // 0x124dc4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123D58u;
    if (runtime->hasFunction(0x123D58u)) {
        auto targetFn = runtime->lookupFunction(0x123D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124DC8u; }
        if (ctx->pc != 0x124DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00123D58_0x123d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124DC8u; }
        if (ctx->pc != 0x124DC8u) { return; }
    }
    ctx->pc = 0x124DC8u;
label_124dc8:
    // 0x124dc8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x124DC8u;
    {
        const bool branch_taken_0x124dc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x124DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124DC8u;
            // 0x124dcc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124dc8) {
            ctx->pc = 0x124DF0u;
            goto label_124df0;
        }
    }
    ctx->pc = 0x124DD0u;
    // 0x124dd0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124dd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124dd4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124dd4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124dd8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124dd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124ddc: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x124ddcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124de0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124de0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124de4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124de4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124de8: 0x8048fb0  j           func_123EC0
    ctx->pc = 0x124DE8u;
    ctx->pc = 0x124DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124DE8u;
            // 0x124dec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123EC0u;
    if (runtime->hasFunction(0x123EC0u)) {
        auto targetFn = runtime->lookupFunction(0x123EC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00123EC0_0x123ec0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124DF0u;
label_124df0:
    // 0x124df0: 0xc048be8  jal         func_122FA0
    ctx->pc = 0x124DF0u;
    SET_GPR_U32(ctx, 31, 0x124DF8u);
    ctx->pc = 0x124DF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124DF0u;
            // 0x124df4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122FA0u;
    if (runtime->hasFunction(0x122FA0u)) {
        auto targetFn = runtime->lookupFunction(0x122FA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124DF8u; }
        if (ctx->pc != 0x124DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00122FA0_0x122fa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124DF8u; }
        if (ctx->pc != 0x124DF8u) { return; }
    }
    ctx->pc = 0x124DF8u;
label_124df8:
    // 0x124df8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x124DF8u;
    {
        const bool branch_taken_0x124df8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x124DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124DF8u;
            // 0x124dfc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124df8) {
            ctx->pc = 0x124E20u;
            goto label_124e20;
        }
    }
    ctx->pc = 0x124E00u;
    // 0x124e00: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124e00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124e04: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x124e04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124e08: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124e08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124e0c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x124e0cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124e10: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124e10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124e14: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124e14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124e18: 0x8048bbc  j           func_122EF0
    ctx->pc = 0x124E18u;
    ctx->pc = 0x124E1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124E18u;
            // 0x124e1c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122EF0u;
    if (runtime->hasFunction(0x122EF0u)) {
        auto targetFn = runtime->lookupFunction(0x122EF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00122EF0_0x122ef0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x124E20u;
label_124e20:
    // 0x124e20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124e20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124e24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x124e24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x124e28: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124e28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124e2c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124e2cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124e30: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124e30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124e34: 0x3e00008  jr          $ra
    ctx->pc = 0x124E34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124E38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124E34u;
            // 0x124e38: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124D30u: goto label_124d30;
            case 0x124D38u: goto label_124d38;
            case 0x124D60u: goto label_124d60;
            case 0x124D68u: goto label_124d68;
            case 0x124D90u: goto label_124d90;
            case 0x124D98u: goto label_124d98;
            case 0x124DC0u: goto label_124dc0;
            case 0x124DC8u: goto label_124dc8;
            case 0x124DF0u: goto label_124df0;
            case 0x124DF8u: goto label_124df8;
            case 0x124E20u: goto label_124e20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124E3Cu;
    // 0x124e3c: 0x0  nop
    ctx->pc = 0x124e3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
