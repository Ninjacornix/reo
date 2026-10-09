#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114D20
// Address: 0x114d20 - 0x114dd0
void sub_00114D20_0x114d20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114D20_0x114d20");
#endif

    switch (ctx->pc) {
        case 0x114d48u: goto label_114d48;
        case 0x114d78u: goto label_114d78;
        case 0x114d8cu: goto label_114d8c;
        default: break;
    }

    ctx->pc = 0x114d20u;

    // 0x114d20: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x114d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x114d24: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x114d24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x114d28: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x114d28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x114d2c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x114d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x114d30: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x114d30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x114d34: 0x40116000  mfc0        $s1, Status
    ctx->pc = 0x114d34u;
    SET_GPR_S32(ctx, 17, (int32_t)ctx->cop0_status);
    // 0x114d38: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x114d38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x114d3c: 0x2228824  and         $s1, $s1, $v0
    ctx->pc = 0x114d3cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
    // 0x114d40: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x114D40u;
    {
        const bool branch_taken_0x114d40 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x114D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114D40u;
            // 0x114d44: 0x3c120021  lui         $s2, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114d40) {
            ctx->pc = 0x114D6Cu;
            goto label_114d6c;
        }
    }
    ctx->pc = 0x114D48u;
label_114d48:
    // 0x114d48: 0x42000039  di
    ctx->pc = 0x114d48u;
    ctx->cop0_status &= ~0x10000; // Disable interrupts
    // 0x114d4c: 0x40f  sync.p
    ctx->pc = 0x114d4cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114d50: 0x40026000  mfc0        $v0, Status
    ctx->pc = 0x114d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_status);
    // 0x114d54: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x114d54u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x114d58: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x114d58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x114d5c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x114D5Cu;
    {
        const bool branch_taken_0x114d5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x114d5c) {
            ctx->pc = 0x114D48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_114d48;
        }
    }
    ctx->pc = 0x114D64u;
    // 0x114d64: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x114D64u;
    {
        const bool branch_taken_0x114d64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x114D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114D64u;
            // 0x114d68: 0x8e429d34  lw          $v0, -0x62CC($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294942004)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114d64) {
            ctx->pc = 0x114D70u;
            goto label_114d70;
        }
    }
    ctx->pc = 0x114D6Cu;
label_114d6c:
    // 0x114d6c: 0x8e429d34  lw          $v0, -0x62CC($s2)
    ctx->pc = 0x114d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294942004)));
label_114d70:
    // 0x114d70: 0xc045180  jal         func_114600
    ctx->pc = 0x114D70u;
    SET_GPR_U32(ctx, 31, 0x114D78u);
    ctx->pc = 0x114D74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x114D70u;
            // 0x114d74: 0x448021  addu        $s0, $v0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114600u;
    if (runtime->hasFunction(0x114600u)) {
        auto targetFn = runtime->lookupFunction(0x114600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114D78u; }
        if (ctx->pc != 0x114D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114600_0x114600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114D78u; }
        if (ctx->pc != 0x114D78u) { return; }
    }
    ctx->pc = 0x114D78u;
label_114d78:
    // 0x114d78: 0x50102b  sltu        $v0, $v0, $s0
    ctx->pc = 0x114d78u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x114d7c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x114D7Cu;
    {
        const bool branch_taken_0x114d7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x114D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114D7Cu;
            // 0x114d80: 0x8e429d34  lw          $v0, -0x62CC($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294942004)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114d7c) {
            ctx->pc = 0x114DA8u;
            goto label_114da8;
        }
    }
    ctx->pc = 0x114D84u;
    // 0x114d84: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x114D84u;
    SET_GPR_U32(ctx, 31, 0x114D8Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114D8Cu; }
        if (ctx->pc != 0x114D8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114D8Cu; }
        if (ctx->pc != 0x114D8Cu) { return; }
    }
    ctx->pc = 0x114D8Cu;
label_114d8c:
    // 0x114d8c: 0x2403000c  addiu       $v1, $zero, 0xC
    ctx->pc = 0x114d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x114d90: 0x12200002  beqz        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x114D90u;
    {
        const bool branch_taken_0x114d90 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x114D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114D90u;
            // 0x114d94: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114d90) {
            ctx->pc = 0x114D9Cu;
            goto label_114d9c;
        }
    }
    ctx->pc = 0x114D98u;
    // 0x114d98: 0x42000038  ei
    ctx->pc = 0x114d98u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
label_114d9c:
    // 0x114d9c: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x114d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x114da0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x114DA0u;
    {
        const bool branch_taken_0x114da0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x114DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114DA0u;
            // 0x114da4: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x114da0) {
            ctx->pc = 0x114DB4u;
            goto label_114db4;
        }
    }
    ctx->pc = 0x114DA8u;
label_114da8:
    // 0x114da8: 0x12200002  beqz        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x114DA8u;
    {
        const bool branch_taken_0x114da8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x114DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114DA8u;
            // 0x114dac: 0xae509d34  sw          $s0, -0x62CC($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4294942004), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114da8) {
            ctx->pc = 0x114DB4u;
            goto label_114db4;
        }
    }
    ctx->pc = 0x114DB0u;
    // 0x114db0: 0x42000038  ei
    ctx->pc = 0x114db0u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
label_114db4:
    // 0x114db4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x114db4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x114db8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x114db8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x114dbc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x114dbcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x114dc0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x114dc0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x114dc4: 0x3e00008  jr          $ra
    ctx->pc = 0x114DC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114DC4u;
            // 0x114dc8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x114D48u: goto label_114d48;
            case 0x114D6Cu: goto label_114d6c;
            case 0x114D70u: goto label_114d70;
            case 0x114D78u: goto label_114d78;
            case 0x114D8Cu: goto label_114d8c;
            case 0x114D9Cu: goto label_114d9c;
            case 0x114DA8u: goto label_114da8;
            case 0x114DB4u: goto label_114db4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114DCCu;
    // 0x114dcc: 0x0  nop
    ctx->pc = 0x114dccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
