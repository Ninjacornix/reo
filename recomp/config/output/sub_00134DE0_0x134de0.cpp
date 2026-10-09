#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134DE0
// Address: 0x134de0 - 0x134eb0
void sub_00134DE0_0x134de0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134DE0_0x134de0");
#endif

    switch (ctx->pc) {
        case 0x134e08u: goto label_134e08;
        case 0x134e5cu: goto label_134e5c;
        case 0x134e84u: goto label_134e84;
        case 0x134e94u: goto label_134e94;
        default: break;
    }

    ctx->pc = 0x134de0u;

    // 0x134de0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x134de0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x134de4: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x134de4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x134de8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x134de8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x134dec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x134decu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x134df0: 0x2483b7b8  addiu       $v1, $a0, -0x4848
    ctx->pc = 0x134df0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948792));
    // 0x134df4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x134df4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x134df8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x134df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x134dfc: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x134DFCu;
    {
        const bool branch_taken_0x134dfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x134E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134DFCu;
            // 0x134e00: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134dfc) {
            ctx->pc = 0x134E2Cu;
            goto label_134e2c;
        }
    }
    ctx->pc = 0x134E04u;
    // 0x134e04: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x134e04u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_134e08:
    // 0x134e08: 0x2a220010  slti        $v0, $s1, 0x10
    ctx->pc = 0x134e08u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x134e0c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x134E0Cu;
    {
        const bool branch_taken_0x134e0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x134E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134E0Cu;
            // 0x134e10: 0x2463003c  addiu       $v1, $v1, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134e0c) {
            ctx->pc = 0x134E2Cu;
            goto label_134e2c;
        }
    }
    ctx->pc = 0x134E14u;
    // 0x134e14: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x134e14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x134e18: 0x0  nop
    ctx->pc = 0x134e18u;
    // NOP
    // 0x134e1c: 0x0  nop
    ctx->pc = 0x134e1cu;
    // NOP
    // 0x134e20: 0x0  nop
    ctx->pc = 0x134e20u;
    // NOP
    // 0x134e24: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x134E24u;
    {
        const bool branch_taken_0x134e24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x134e24) {
            ctx->pc = 0x134E28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134E24u;
            // 0x134e28: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134E08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_134e08;
        }
    }
    ctx->pc = 0x134E2Cu;
label_134e2c:
    // 0x134e2c: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x134e2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x134e30: 0x12230019  beq         $s1, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x134E30u;
    {
        const bool branch_taken_0x134e30 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x134E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134E30u;
            // 0x134e34: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134e30) {
            ctx->pc = 0x134E98u;
            goto label_134e98;
        }
    }
    ctx->pc = 0x134E38u;
    // 0x134e38: 0x118100  sll         $s0, $s1, 4
    ctx->pc = 0x134e38u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x134e3c: 0x2482b7b8  addiu       $v0, $a0, -0x4848
    ctx->pc = 0x134e3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948792));
    // 0x134e40: 0x2118023  subu        $s0, $s0, $s1
    ctx->pc = 0x134e40u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x134e44: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x134e44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134e48: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x134e48u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x134e4c: 0x2406003c  addiu       $a2, $zero, 0x3C
    ctx->pc = 0x134e4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x134e50: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x134e50u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x134e54: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x134E54u;
    SET_GPR_U32(ctx, 31, 0x134E5Cu);
    ctx->pc = 0x134E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134E54u;
            // 0x134e58: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134E5Cu; }
        if (ctx->pc != 0x134E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134E5Cu; }
        if (ctx->pc != 0x134E5Cu) { return; }
    }
    ctx->pc = 0x134E5Cu;
label_134e5c:
    // 0x134e5c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x134e5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x134e60: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x134e60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x134e64: 0x240401f4  addiu       $a0, $zero, 0x1F4
    ctx->pc = 0x134e64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 500));
    // 0x134e68: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x134e68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x134e6c: 0x3405ac44  ori         $a1, $zero, 0xAC44
    ctx->pc = 0x134e6cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)44100);
    // 0x134e70: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x134e70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x134e74: 0x26060030  addiu       $a2, $s0, 0x30
    ctx->pc = 0x134e74u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x134e78: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x134e78u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x134e7c: 0xc049944  jal         func_126510
    ctx->pc = 0x134E7Cu;
    SET_GPR_U32(ctx, 31, 0x134E84u);
    ctx->pc = 0x134E80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134E7Cu;
            // 0x134e80: 0x26070032  addiu       $a3, $s0, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 50));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126510u;
    if (runtime->hasFunction(0x126510u)) {
        auto targetFn = runtime->lookupFunction(0x126510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134E84u; }
        if (ctx->pc != 0x134E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126510_0x126510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134E84u; }
        if (ctx->pc != 0x134E84u) { return; }
    }
    ctx->pc = 0x134E84u;
label_134e84:
    // 0x134e84: 0x26040028  addiu       $a0, $s0, 0x28
    ctx->pc = 0x134e84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
    // 0x134e88: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x134e88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134e8c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x134E8Cu;
    SET_GPR_U32(ctx, 31, 0x134E94u);
    ctx->pc = 0x134E90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134E8Cu;
            // 0x134e90: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134E94u; }
        if (ctx->pc != 0x134E94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134E94u; }
        if (ctx->pc != 0x134E94u) { return; }
    }
    ctx->pc = 0x134E94u;
label_134e94:
    // 0x134e94: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x134e94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_134e98:
    // 0x134e98: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x134e98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134e9c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x134e9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x134ea0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x134ea0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x134ea4: 0x3e00008  jr          $ra
    ctx->pc = 0x134EA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134EA4u;
            // 0x134ea8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134E08u: goto label_134e08;
            case 0x134E2Cu: goto label_134e2c;
            case 0x134E5Cu: goto label_134e5c;
            case 0x134E84u: goto label_134e84;
            case 0x134E94u: goto label_134e94;
            case 0x134E98u: goto label_134e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134EACu;
    // 0x134eac: 0x0  nop
    ctx->pc = 0x134eacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
