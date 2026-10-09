#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011EDB0
// Address: 0x11edb0 - 0x11ee48
void sub_0011EDB0_0x11edb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011EDB0_0x11edb0");
#endif

    switch (ctx->pc) {
        case 0x11ee10u: goto label_11ee10;
        case 0x11ee1cu: goto label_11ee1c;
        case 0x11ee2cu: goto label_11ee2c;
        default: break;
    }

    ctx->pc = 0x11edb0u;

label_11edb0:
    // 0x11edb0: 0x41282  srl         $v0, $a0, 10
    ctx->pc = 0x11edb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 10));
    // 0x11edb4: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11EDB4u;
    {
        const bool branch_taken_0x11edb4 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x11EDB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EDB4u;
            // 0x11edb8: 0x22980  sll         $a1, $v0, 6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11edb4) {
            ctx->pc = 0x11EDCCu;
            goto label_11edcc;
        }
    }
    ctx->pc = 0x11EDBCu;
    // 0x11edbc: 0x8ca30008  lw          $v1, 0x8($a1)
    ctx->pc = 0x11edbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x11edc0: 0x308203ff  andi        $v0, $a0, 0x3FF
    ctx->pc = 0x11edc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1023);
    // 0x11edc4: 0x50430003  beql        $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11EDC4u;
    {
        const bool branch_taken_0x11edc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x11edc4) {
            ctx->pc = 0x11EDC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11EDC4u;
            // 0x11edc8: 0x8ca2000c  lw          $v0, 0xC($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11EDD4u;
            goto label_11edd4;
        }
    }
    ctx->pc = 0x11EDCCu;
label_11edcc:
    // 0x11edcc: 0x3e00008  jr          $ra
    ctx->pc = 0x11EDCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EDD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EDCCu;
            // 0x11edd0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EDB0u: goto label_11edb0;
            case 0x11EDCCu: goto label_11edcc;
            case 0x11EDD4u: goto label_11edd4;
            case 0x11EDF0u: goto label_11edf0;
            case 0x11EE10u: goto label_11ee10;
            case 0x11EE1Cu: goto label_11ee1c;
            case 0x11EE2Cu: goto label_11ee2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EDD4u;
label_11edd4:
    // 0x11edd4: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x11edd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x11edd8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11EDD8u;
    {
        const bool branch_taken_0x11edd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11edd8) {
            ctx->pc = 0x11EDF0u;
            goto label_11edf0;
        }
    }
    ctx->pc = 0x11EDE0u;
    // 0x11ede0: 0xdca30018  ld          $v1, 0x18($a1)
    ctx->pc = 0x11ede0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x11ede4: 0xdca20010  ld          $v0, 0x10($a1)
    ctx->pc = 0x11ede4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x11ede8: 0x3e00008  jr          $ra
    ctx->pc = 0x11EDE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EDECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EDE8u;
            // 0x11edec: 0x43102f  dsubu       $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EDB0u: goto label_11edb0;
            case 0x11EDCCu: goto label_11edcc;
            case 0x11EDD4u: goto label_11edd4;
            case 0x11EDF0u: goto label_11edf0;
            case 0x11EE10u: goto label_11ee10;
            case 0x11EE1Cu: goto label_11ee1c;
            case 0x11EE2Cu: goto label_11ee2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EDF0u;
label_11edf0:
    // 0x11edf0: 0x3e00008  jr          $ra
    ctx->pc = 0x11EDF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EDF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EDF0u;
            // 0x11edf4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EDB0u: goto label_11edb0;
            case 0x11EDCCu: goto label_11edcc;
            case 0x11EDD4u: goto label_11edd4;
            case 0x11EDF0u: goto label_11edf0;
            case 0x11EE10u: goto label_11ee10;
            case 0x11EE1Cu: goto label_11ee1c;
            case 0x11EE2Cu: goto label_11ee2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EDF8u;
    // 0x11edf8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11edf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11edfc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11edfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11ee00: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11ee00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11ee04: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11ee04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11ee08: 0xc047598  jal         func_11D660
    ctx->pc = 0x11EE08u;
    SET_GPR_U32(ctx, 31, 0x11EE10u);
    ctx->pc = 0x11EE0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE08u;
            // 0x11ee0c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE10u; }
        if (ctx->pc != 0x11EE10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE10u; }
        if (ctx->pc != 0x11EE10u) { return; }
    }
    ctx->pc = 0x11EE10u;
label_11ee10:
    // 0x11ee10: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11ee10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ee14: 0xc047b6c  jal         func_11EDB0
    ctx->pc = 0x11EE14u;
    SET_GPR_U32(ctx, 31, 0x11EE1Cu);
    ctx->pc = 0x11EE18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE14u;
            // 0x11ee18: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EDB0u;
    goto label_11edb0;
    ctx->pc = 0x11EE1Cu;
label_11ee1c:
    // 0x11ee1c: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11EE1Cu;
    {
        const bool branch_taken_0x11ee1c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EE20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE1Cu;
            // 0x11ee20: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ee1c) {
            ctx->pc = 0x11EE2Cu;
            goto label_11ee2c;
        }
    }
    ctx->pc = 0x11EE24u;
    // 0x11ee24: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11EE24u;
    SET_GPR_U32(ctx, 31, 0x11EE2Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE2Cu; }
        if (ctx->pc != 0x11EE2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EE2Cu; }
        if (ctx->pc != 0x11EE2Cu) { return; }
    }
    ctx->pc = 0x11EE2Cu;
label_11ee2c:
    // 0x11ee2c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11ee2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ee30: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11ee30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11ee34: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ee34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ee38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ee38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ee3c: 0x3e00008  jr          $ra
    ctx->pc = 0x11EE3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EE40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EE3Cu;
            // 0x11ee40: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EDB0u: goto label_11edb0;
            case 0x11EDCCu: goto label_11edcc;
            case 0x11EDD4u: goto label_11edd4;
            case 0x11EDF0u: goto label_11edf0;
            case 0x11EE10u: goto label_11ee10;
            case 0x11EE1Cu: goto label_11ee1c;
            case 0x11EE2Cu: goto label_11ee2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EE44u;
    // 0x11ee44: 0x0  nop
    ctx->pc = 0x11ee44u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
