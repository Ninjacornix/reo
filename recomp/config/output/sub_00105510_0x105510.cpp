#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00105510
// Address: 0x105510 - 0x1055a0
void sub_00105510_0x105510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00105510_0x105510");
#endif

    switch (ctx->pc) {
        case 0x105550u: goto label_105550;
        case 0x105564u: goto label_105564;
        case 0x105578u: goto label_105578;
        default: break;
    }

    ctx->pc = 0x105510u;

    // 0x105510: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x105510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x105514: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x105514u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x105518: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x105518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10551c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10551cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105520: 0x244254d0  addiu       $v0, $v0, 0x54D0
    ctx->pc = 0x105520u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21712));
    // 0x105524: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x105524u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x105528: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x105528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10552c: 0x261101e4  addiu       $s1, $s0, 0x1E4
    ctx->pc = 0x10552cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 484));
    // 0x105530: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x105530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x105534: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x105534u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105538: 0xae02003c  sw          $v0, 0x3C($s0)
    ctx->pc = 0x105538u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 2));
    // 0x10553c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x10553cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105540: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x105540u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x105544: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x105544u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x105548: 0xc0414c0  jal         func_105300
    ctx->pc = 0x105548u;
    SET_GPR_U32(ctx, 31, 0x105550u);
    ctx->pc = 0x10554Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105548u;
            // 0x10554c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105300u;
    if (runtime->hasFunction(0x105300u)) {
        auto targetFn = runtime->lookupFunction(0x105300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105550u; }
        if (ctx->pc != 0x105550u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105300_0x105300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105550u; }
        if (ctx->pc != 0x105550u) { return; }
    }
    ctx->pc = 0x105550u;
label_105550:
    // 0x105550: 0x2604023c  addiu       $a0, $s0, 0x23C
    ctx->pc = 0x105550u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 572));
    // 0x105554: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x105554u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105558: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x105558u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x10555c: 0xc0414c0  jal         func_105300
    ctx->pc = 0x10555Cu;
    SET_GPR_U32(ctx, 31, 0x105564u);
    ctx->pc = 0x105560u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10555Cu;
            // 0x105560: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105300u;
    if (runtime->hasFunction(0x105300u)) {
        auto targetFn = runtime->lookupFunction(0x105300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105564u; }
        if (ctx->pc != 0x105564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105300_0x105300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105564u; }
        if (ctx->pc != 0x105564u) { return; }
    }
    ctx->pc = 0x105564u;
label_105564:
    // 0x105564: 0x26040294  addiu       $a0, $s0, 0x294
    ctx->pc = 0x105564u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 660));
    // 0x105568: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x105568u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10556c: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x10556cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x105570: 0xc0414c0  jal         func_105300
    ctx->pc = 0x105570u;
    SET_GPR_U32(ctx, 31, 0x105578u);
    ctx->pc = 0x105574u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105570u;
            // 0x105574: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105300u;
    if (runtime->hasFunction(0x105300u)) {
        auto targetFn = runtime->lookupFunction(0x105300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105578u; }
        if (ctx->pc != 0x105578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105300_0x105300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105578u; }
        if (ctx->pc != 0x105578u) { return; }
    }
    ctx->pc = 0x105578u;
label_105578:
    // 0x105578: 0xae0001d8  sw          $zero, 0x1D8($s0)
    ctx->pc = 0x105578u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 472), GPR_U32(ctx, 0));
    // 0x10557c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x10557cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x105580: 0xae1101e0  sw          $s1, 0x1E0($s0)
    ctx->pc = 0x105580u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 480), GPR_U32(ctx, 17));
    // 0x105584: 0xae0201dc  sw          $v0, 0x1DC($s0)
    ctx->pc = 0x105584u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 476), GPR_U32(ctx, 2));
    // 0x105588: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x105588u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10558c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10558cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x105590: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x105590u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x105594: 0x3e00008  jr          $ra
    ctx->pc = 0x105594u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x105598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105594u;
            // 0x105598: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105550u: goto label_105550;
            case 0x105564u: goto label_105564;
            case 0x105578u: goto label_105578;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10559Cu;
    // 0x10559c: 0x0  nop
    ctx->pc = 0x10559cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
