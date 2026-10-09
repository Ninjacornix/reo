#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B4500
// Address: 0x1b4500 - 0x1b4590
void sub_001B4500_0x1b4500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B4500_0x1b4500");
#endif

    switch (ctx->pc) {
        case 0x1b4534u: goto label_1b4534;
        case 0x1b4544u: goto label_1b4544;
        case 0x1b4548u: goto label_1b4548;
        case 0x1b456cu: goto label_1b456c;
        default: break;
    }

    ctx->pc = 0x1b4500u;

    // 0x1b4500: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b4500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b4504: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4504u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4508: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b4508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b450c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b450cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b4510: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b4510u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b4514: 0x902343d6  lbu         $v1, 0x43D6($at)
    ctx->pc = 0x1b4514u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17366)));
    // 0x1b4518: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B4518u;
    {
        const bool branch_taken_0x1b4518 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B451Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4518u;
            // 0x1b451c: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4518) {
            ctx->pc = 0x1B457Cu;
            goto label_1b457c;
        }
    }
    ctx->pc = 0x1B4520u;
    // 0x1b4520: 0x9023ae94  lbu         $v1, -0x516C($at)
    ctx->pc = 0x1b4520u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946452)));
    // 0x1b4524: 0x14600015  bnez        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B4524u;
    {
        const bool branch_taken_0x1b4524 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b4524) {
            ctx->pc = 0x1B457Cu;
            goto label_1b457c;
        }
    }
    ctx->pc = 0x1B452Cu;
    // 0x1b452c: 0xc06d114  jal         func_1B4450
    ctx->pc = 0x1B452Cu;
    SET_GPR_U32(ctx, 31, 0x1B4534u);
    ctx->pc = 0x1B4450u;
    if (runtime->hasFunction(0x1B4450u)) {
        auto targetFn = runtime->lookupFunction(0x1B4450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4534u; }
        if (ctx->pc != 0x1B4534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4450_0x1b4450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4534u; }
        if (ctx->pc != 0x1B4534u) { return; }
    }
    ctx->pc = 0x1B4534u;
label_1b4534:
    // 0x1b4534: 0x3c110031  lui         $s1, 0x31
    ctx->pc = 0x1b4534u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49 << 16));
    // 0x1b4538: 0x2404fffe  addiu       $a0, $zero, -0x2
    ctx->pc = 0x1b4538u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1b453c: 0xc06d584  jal         func_1B5610
    ctx->pc = 0x1B453Cu;
    SET_GPR_U32(ctx, 31, 0x1B4544u);
    ctx->pc = 0x1B4540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B453Cu;
            // 0x1b4540: 0x263151d0  addiu       $s1, $s1, 0x51D0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 20944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5610u;
    if (runtime->hasFunction(0x1B5610u)) {
        auto targetFn = runtime->lookupFunction(0x1B5610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4544u; }
        if (ctx->pc != 0x1B4544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5610_0x1b5610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4544u; }
        if (ctx->pc != 0x1B4544u) { return; }
    }
    ctx->pc = 0x1B4544u;
label_1b4544:
    // 0x1b4544: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b4544u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b4548:
    // 0x1b4548: 0x86230000  lh          $v1, 0x0($s1)
    ctx->pc = 0x1b4548u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1b454c: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B454Cu;
    {
        const bool branch_taken_0x1b454c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b454c) {
            ctx->pc = 0x1B456Cu;
            goto label_1b456c;
        }
    }
    ctx->pc = 0x1B4554u;
    // 0x1b4554: 0x86240002  lh          $a0, 0x2($s1)
    ctx->pc = 0x1b4554u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b4558: 0x86250004  lh          $a1, 0x4($s1)
    ctx->pc = 0x1b4558u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1b455c: 0x92260008  lbu         $a2, 0x8($s1)
    ctx->pc = 0x1b455cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1b4560: 0x9228000a  lbu         $t0, 0xA($s1)
    ctx->pc = 0x1b4560u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 10)));
    // 0x1b4564: 0xc06d040  jal         func_1B4100
    ctx->pc = 0x1B4564u;
    SET_GPR_U32(ctx, 31, 0x1B456Cu);
    ctx->pc = 0x1B4568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4564u;
            // 0x1b4568: 0x2627000c  addiu       $a3, $s1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B4100u;
    if (runtime->hasFunction(0x1B4100u)) {
        auto targetFn = runtime->lookupFunction(0x1B4100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B456Cu; }
        if (ctx->pc != 0x1B456Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4100_0x1b4100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B456Cu; }
        if (ctx->pc != 0x1B456Cu) { return; }
    }
    ctx->pc = 0x1B456Cu;
label_1b456c:
    // 0x1b456c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b456cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b4570: 0x2a030020  slti        $v1, $s0, 0x20
    ctx->pc = 0x1b4570u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1b4574: 0x1460fff4  bnez        $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1B4574u;
    {
        const bool branch_taken_0x1b4574 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4574u;
            // 0x1b4578: 0x2631008c  addiu       $s1, $s1, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 140));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4574) {
            ctx->pc = 0x1B4548u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b4548;
        }
    }
    ctx->pc = 0x1B457Cu;
label_1b457c:
    // 0x1b457c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b457cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b4580: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b4580u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b4584: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4584u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4588: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4588u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B458Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4588u;
            // 0x1b458c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4534u: goto label_1b4534;
            case 0x1B4544u: goto label_1b4544;
            case 0x1B4548u: goto label_1b4548;
            case 0x1B456Cu: goto label_1b456c;
            case 0x1B457Cu: goto label_1b457c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4590u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
