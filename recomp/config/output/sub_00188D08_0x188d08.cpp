#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188D08
// Address: 0x188d08 - 0x188d90
void sub_00188D08_0x188d08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188D08_0x188d08");
#endif

    switch (ctx->pc) {
        case 0x188d68u: goto label_188d68;
        case 0x188d7cu: goto label_188d7c;
        default: break;
    }

    ctx->pc = 0x188d08u;

    // 0x188d08: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x188d08u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x188d0c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x188d0cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x188d10: 0x8c62fd38  lw          $v0, -0x2C8($v1)
    ctx->pc = 0x188d10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294966584)));
    // 0x188d14: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x188d14u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188d18: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x188d18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x188d1c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x188D1Cu;
    {
        const bool branch_taken_0x188d1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x188D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188D1Cu;
            // 0x188d20: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188d1c) {
            ctx->pc = 0x188D2Cu;
            goto label_188d2c;
        }
    }
    ctx->pc = 0x188D24u;
    // 0x188d24: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x188D24u;
    {
        const bool branch_taken_0x188d24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x188D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188D24u;
            // 0x188d28: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188d24) {
            ctx->pc = 0x188D80u;
            goto label_188d80;
        }
    }
    ctx->pc = 0x188D2Cu;
label_188d2c:
    // 0x188d2c: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x188d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188d30: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x188d30u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x188d34: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x188d34u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x188d38: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x188d38u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x188d3c: 0xac460c00  sw          $a2, 0xC00($v0)
    ctx->pc = 0x188d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3072), GPR_U32(ctx, 6));
    // 0x188d40: 0x24840b88  addiu       $a0, $a0, 0xB88
    ctx->pc = 0x188d40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2952));
    // 0x188d44: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x188d44u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x188d48: 0x34a51302  ori         $a1, $a1, 0x1302
    ctx->pc = 0x188d48u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4866);
    // 0x188d4c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x188d4cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188d50: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x188d50u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188d54: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x188d54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188d58: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x188d58u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188d5c: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x188d5cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188d60: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x188D60u;
    SET_GPR_U32(ctx, 31, 0x188D68u);
    ctx->pc = 0x188D64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188D60u;
            // 0x188d64: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188D68u; }
        if (ctx->pc != 0x188D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188D68u; }
        if (ctx->pc != 0x188D68u) { return; }
    }
    ctx->pc = 0x188D68u;
label_188d68:
    // 0x188d68: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x188D68u;
    {
        const bool branch_taken_0x188d68 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x188d68) {
            ctx->pc = 0x188D6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x188D68u;
            // 0x188d6c: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x188D80u;
            goto label_188d80;
        }
    }
    ctx->pc = 0x188D70u;
    // 0x188d70: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x188d70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x188d74: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x188D74u;
    SET_GPR_U32(ctx, 31, 0x188D7Cu);
    ctx->pc = 0x188D78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188D74u;
            // 0x188d78: 0x24841940  addiu       $a0, $a0, 0x1940 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6464));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188D7Cu; }
        if (ctx->pc != 0x188D7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188D7Cu; }
        if (ctx->pc != 0x188D7Cu) { return; }
    }
    ctx->pc = 0x188D7Cu;
label_188d7c:
    // 0x188d7c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x188d7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_188d80:
    // 0x188d80: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x188d80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188d84: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x188d84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x188d88: 0x3e00008  jr          $ra
    ctx->pc = 0x188D88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188D88u;
            // 0x188d8c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188D2Cu: goto label_188d2c;
            case 0x188D68u: goto label_188d68;
            case 0x188D7Cu: goto label_188d7c;
            case 0x188D80u: goto label_188d80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188D90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
