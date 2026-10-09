#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016CC10
// Address: 0x16cc10 - 0x16cc98
void sub_0016CC10_0x16cc10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016CC10_0x16cc10");
#endif

    switch (ctx->pc) {
        case 0x16cc34u: goto label_16cc34;
        case 0x16cc44u: goto label_16cc44;
        default: break;
    }

    ctx->pc = 0x16cc10u;

    // 0x16cc10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16cc10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16cc14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16cc14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16cc18: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16cc18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cc1c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16cc1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16cc20: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16cc20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16cc24: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16cc24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16cc28: 0x8e121b38  lw          $s2, 0x1B38($s0)
    ctx->pc = 0x16cc28u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6968)));
    // 0x16cc2c: 0xc059d42  jal         func_167508
    ctx->pc = 0x16CC2Cu;
    SET_GPR_U32(ctx, 31, 0x16CC34u);
    ctx->pc = 0x16CC30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CC2Cu;
            // 0x16cc30: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167508u;
    if (runtime->hasFunction(0x167508u)) {
        auto targetFn = runtime->lookupFunction(0x167508u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CC34u; }
        if (ctx->pc != 0x16CC34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167508_0x167508(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CC34u; }
        if (ctx->pc != 0x16CC34u) { return; }
    }
    ctx->pc = 0x16CC34u;
label_16cc34:
    // 0x16cc34: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16cc34u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cc38: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16cc38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cc3c: 0xc059f48  jal         func_167D20
    ctx->pc = 0x16CC3Cu;
    SET_GPR_U32(ctx, 31, 0x16CC44u);
    ctx->pc = 0x16CC40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CC3Cu;
            // 0x16cc40: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D20u;
    if (runtime->hasFunction(0x167D20u)) {
        auto targetFn = runtime->lookupFunction(0x167D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CC44u; }
        if (ctx->pc != 0x16CC44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D20_0x167d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16CC44u; }
        if (ctx->pc != 0x16CC44u) { return; }
    }
    ctx->pc = 0x16CC44u;
label_16cc44:
    // 0x16cc44: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16cc44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cc48: 0x8e030028  lw          $v1, 0x28($s0)
    ctx->pc = 0x16cc48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x16cc4c: 0x2228823  subu        $s1, $s1, $v0
    ctx->pc = 0x16cc4cu;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x16cc50: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16cc50u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16cc54: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16cc54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16cc58: 0x223882a  slt         $s1, $s1, $v1
    ctx->pc = 0x16cc58u;
    SET_GPR_U64(ctx, 17, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x16cc5c: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x16CC5Cu;
    {
        const bool branch_taken_0x16cc5c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x16CC60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CC5Cu;
            // 0x16cc60: 0x34a50f1c  ori         $a1, $a1, 0xF1C (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3868);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16cc5c) {
            ctx->pc = 0x16CC80u;
            goto label_16cc80;
        }
    }
    ctx->pc = 0x16CC64u;
    // 0x16cc64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16cc64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16cc68: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16cc68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16cc6c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16cc6cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16cc70: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16cc70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16cc74: 0x805a704  j           func_169C10
    ctx->pc = 0x16CC74u;
    ctx->pc = 0x16CC78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16CC74u;
            // 0x16cc78: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16CC7Cu;
    // 0x16cc7c: 0x0  nop
    ctx->pc = 0x16cc7cu;
    // NOP
label_16cc80:
    // 0x16cc80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16cc80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16cc84: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16cc84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16cc88: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16cc88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16cc8c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16cc8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16cc90: 0x3e00008  jr          $ra
    ctx->pc = 0x16CC90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16CC94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16CC90u;
            // 0x16cc94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16CC34u: goto label_16cc34;
            case 0x16CC44u: goto label_16cc44;
            case 0x16CC80u: goto label_16cc80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16CC98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
