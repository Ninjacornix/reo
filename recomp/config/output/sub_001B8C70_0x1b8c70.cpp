#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8C70
// Address: 0x1b8c70 - 0x1b8d40
void sub_001B8C70_0x1b8c70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8C70_0x1b8c70");
#endif

    switch (ctx->pc) {
        case 0x1b8ca8u: goto label_1b8ca8;
        case 0x1b8cc8u: goto label_1b8cc8;
        case 0x1b8ce8u: goto label_1b8ce8;
        case 0x1b8cf8u: goto label_1b8cf8;
        case 0x1b8d2cu: goto label_1b8d2c;
        default: break;
    }

    ctx->pc = 0x1b8c70u;

    // 0x1b8c70: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b8c70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b8c74: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b8c74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b8c78: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b8c78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b8c7c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b8c7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b8c80: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b8c80u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8c84: 0x92230002  lbu         $v1, 0x2($s1)
    ctx->pc = 0x1b8c84u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b8c88: 0x90840c7c  lbu         $a0, 0xC7C($a0)
    ctx->pc = 0x1b8c88u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3196)));
    // 0x1b8c8c: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B8C8Cu;
    {
        const bool branch_taken_0x1b8c8c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8C8Cu;
            // 0x1b8c90: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8c8c) {
            ctx->pc = 0x1B8CF0u;
            goto label_1b8cf0;
        }
    }
    ctx->pc = 0x1B8C94u;
    // 0x1b8c94: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B8C94u;
    {
        const bool branch_taken_0x1b8c94 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B8C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8C94u;
            // 0x1b8c98: 0x24030006  addiu       $v1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8c94) {
            ctx->pc = 0x1B8CB4u;
            goto label_1b8cb4;
        }
    }
    ctx->pc = 0x1B8C9Cu;
    // 0x1b8c9c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b8c9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8ca0: 0xc06e2c8  jal         func_1B8B20
    ctx->pc = 0x1B8CA0u;
    SET_GPR_U32(ctx, 31, 0x1B8CA8u);
    ctx->pc = 0x1B8CA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8CA0u;
            // 0x1b8ca4: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8B20u;
    if (runtime->hasFunction(0x1B8B20u)) {
        auto targetFn = runtime->lookupFunction(0x1B8B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8CA8u; }
        if (ctx->pc != 0x1B8CA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8B20_0x1b8b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8CA8u; }
        if (ctx->pc != 0x1B8CA8u) { return; }
    }
    ctx->pc = 0x1B8CA8u;
label_1b8ca8:
    // 0x1b8ca8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1B8CA8u;
    {
        const bool branch_taken_0x1b8ca8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b8ca8) {
            ctx->pc = 0x1B8CE8u;
            goto label_1b8ce8;
        }
    }
    ctx->pc = 0x1B8CB0u;
    // 0x1b8cb0: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1b8cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
label_1b8cb4:
    // 0x1b8cb4: 0x16030007  bne         $s0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B8CB4u;
    {
        const bool branch_taken_0x1b8cb4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B8CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8CB4u;
            // 0x1b8cb8: 0x24030019  addiu       $v1, $zero, 0x19 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8cb4) {
            ctx->pc = 0x1B8CD4u;
            goto label_1b8cd4;
        }
    }
    ctx->pc = 0x1B8CBCu;
    // 0x1b8cbc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b8cbcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8cc0: 0xc06e2c8  jal         func_1B8B20
    ctx->pc = 0x1B8CC0u;
    SET_GPR_U32(ctx, 31, 0x1B8CC8u);
    ctx->pc = 0x1B8CC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8CC0u;
            // 0x1b8cc4: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8B20u;
    if (runtime->hasFunction(0x1B8B20u)) {
        auto targetFn = runtime->lookupFunction(0x1B8B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8CC8u; }
        if (ctx->pc != 0x1B8CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8B20_0x1b8b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8CC8u; }
        if (ctx->pc != 0x1B8CC8u) { return; }
    }
    ctx->pc = 0x1B8CC8u;
label_1b8cc8:
    // 0x1b8cc8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B8CC8u;
    {
        const bool branch_taken_0x1b8cc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b8cc8) {
            ctx->pc = 0x1B8CE8u;
            goto label_1b8ce8;
        }
    }
    ctx->pc = 0x1B8CD0u;
    // 0x1b8cd0: 0x24030019  addiu       $v1, $zero, 0x19
    ctx->pc = 0x1b8cd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
label_1b8cd4:
    // 0x1b8cd4: 0x16030015  bne         $s0, $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B8CD4u;
    {
        const bool branch_taken_0x1b8cd4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b8cd4) {
            ctx->pc = 0x1B8D2Cu;
            goto label_1b8d2c;
        }
    }
    ctx->pc = 0x1B8CDCu;
    // 0x1b8cdc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b8cdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8ce0: 0xc06e2c8  jal         func_1B8B20
    ctx->pc = 0x1B8CE0u;
    SET_GPR_U32(ctx, 31, 0x1B8CE8u);
    ctx->pc = 0x1B8CE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8CE0u;
            // 0x1b8ce4: 0x24050009  addiu       $a1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8B20u;
    if (runtime->hasFunction(0x1B8B20u)) {
        auto targetFn = runtime->lookupFunction(0x1B8B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8CE8u; }
        if (ctx->pc != 0x1B8CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8B20_0x1b8b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8CE8u; }
        if (ctx->pc != 0x1B8CE8u) { return; }
    }
    ctx->pc = 0x1B8CE8u;
label_1b8ce8:
    // 0x1b8ce8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1B8CE8u;
    {
        const bool branch_taken_0x1b8ce8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8CECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8CE8u;
            // 0x1b8cec: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8ce8) {
            ctx->pc = 0x1B8D30u;
            goto label_1b8d30;
        }
    }
    ctx->pc = 0x1B8CF0u;
label_1b8cf0:
    // 0x1b8cf0: 0xc16d338  jal         func_5B4CE0
    ctx->pc = 0x1B8CF0u;
    SET_GPR_U32(ctx, 31, 0x1B8CF8u);
    ctx->pc = 0x5B4CE0u;
    {
        auto targetFn = runtime->lookupFunction(0x5B4CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8CF8u; }
        if (ctx->pc != 0x1B8CF8u) { return; }
    }
    ctx->pc = 0x1B8CF8u;
label_1b8cf8:
    // 0x1b8cf8: 0x2263c  dsll32      $a0, $v0, 24
    ctx->pc = 0x1b8cf8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1b8cfc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1b8cfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b8d00: 0x4263f  dsra32      $a0, $a0, 24
    ctx->pc = 0x1b8d00u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 24));
    // 0x1b8d04: 0x10830009  beq         $a0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B8D04u;
    {
        const bool branch_taken_0x1b8d04 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b8d04) {
            ctx->pc = 0x1B8D2Cu;
            goto label_1b8d2c;
        }
    }
    ctx->pc = 0x1B8D0Cu;
    // 0x1b8d0c: 0x92260003  lbu         $a2, 0x3($s1)
    ctx->pc = 0x1b8d0cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1b8d10: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b8d10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8d14: 0x26270038  addiu       $a3, $s1, 0x38
    ctx->pc = 0x1b8d14u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 56));
    // 0x1b8d18: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b8d18u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8d1c: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b8d1cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8d20: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b8d20u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8d24: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B8D24u;
    SET_GPR_U32(ctx, 31, 0x1B8D2Cu);
    ctx->pc = 0x1B8D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8D24u;
            // 0x1b8d28: 0x24c40008  addiu       $a0, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8D2Cu; }
        if (ctx->pc != 0x1B8D2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8D2Cu; }
        if (ctx->pc != 0x1B8D2Cu) { return; }
    }
    ctx->pc = 0x1B8D2Cu;
label_1b8d2c:
    // 0x1b8d2c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b8d2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1b8d30:
    // 0x1b8d30: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b8d30u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b8d34: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b8d34u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8d38: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8D38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8D38u;
            // 0x1b8d3c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8CA8u: goto label_1b8ca8;
            case 0x1B8CB4u: goto label_1b8cb4;
            case 0x1B8CC8u: goto label_1b8cc8;
            case 0x1B8CD4u: goto label_1b8cd4;
            case 0x1B8CE8u: goto label_1b8ce8;
            case 0x1B8CF0u: goto label_1b8cf0;
            case 0x1B8CF8u: goto label_1b8cf8;
            case 0x1B8D2Cu: goto label_1b8d2c;
            case 0x1B8D30u: goto label_1b8d30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8D40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
