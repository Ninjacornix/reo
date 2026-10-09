#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001814A8
// Address: 0x1814a8 - 0x181560
void sub_001814A8_0x1814a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001814A8_0x1814a8");
#endif

    switch (ctx->pc) {
        case 0x1814e0u: goto label_1814e0;
        case 0x181510u: goto label_181510;
        case 0x181538u: goto label_181538;
        case 0x181540u: goto label_181540;
        default: break;
    }

    ctx->pc = 0x1814a8u;

    // 0x1814a8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1814a8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1814ac: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1814acu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1814b0: 0x8c66fa10  lw          $a2, -0x5F0($v1)
    ctx->pc = 0x1814b0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x1814b4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1814b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1814b8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1814b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1814bc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1814bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1814c0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1814c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1814c4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1814c4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1814c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1814c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1814cc: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x1814ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
    // 0x1814d0: 0x10c0001c  beqz        $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x1814D0u;
    {
        const bool branch_taken_0x1814d0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x1814D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1814D0u;
            // 0x1814d4: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1814d0) {
            ctx->pc = 0x181544u;
            goto label_181544;
        }
    }
    ctx->pc = 0x1814D8u;
    // 0x1814d8: 0xc061e90  jal         func_187A40
    ctx->pc = 0x1814D8u;
    SET_GPR_U32(ctx, 31, 0x1814E0u);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1814E0u; }
        if (ctx->pc != 0x1814E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1814E0u; }
        if (ctx->pc != 0x1814E0u) { return; }
    }
    ctx->pc = 0x1814E0u;
label_1814e0:
    // 0x1814e0: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x1814e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x1814e4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1814E4u;
    {
        const bool branch_taken_0x1814e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1814E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1814E4u;
            // 0x1814e8: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1814e4) {
            ctx->pc = 0x1814F8u;
            goto label_1814f8;
        }
    }
    ctx->pc = 0x1814ECu;
    // 0x1814ec: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1814ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1814f0: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1814F0u;
    {
        const bool branch_taken_0x1814f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1814F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1814F0u;
            // 0x1814f4: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1814f0) {
            ctx->pc = 0x181544u;
            goto label_181544;
        }
    }
    ctx->pc = 0x1814F8u;
label_1814f8:
    // 0x1814f8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1814f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1814fc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1814fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181500: 0x14600010  bnez        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x181500u;
    {
        const bool branch_taken_0x181500 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x181504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181500u;
            // 0x181504: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181500) {
            ctx->pc = 0x181544u;
            goto label_181544;
        }
    }
    ctx->pc = 0x181508u;
    // 0x181508: 0xc042c56  jal         func_10B158
    ctx->pc = 0x181508u;
    SET_GPR_U32(ctx, 31, 0x181510u);
    ctx->pc = 0x18150Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181508u;
            // 0x18150c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181510u; }
        if (ctx->pc != 0x181510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181510u; }
        if (ctx->pc != 0x181510u) { return; }
    }
    ctx->pc = 0x181510u;
label_181510:
    // 0x181510: 0x2604041c  addiu       $a0, $s0, 0x41C
    ctx->pc = 0x181510u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
    // 0x181514: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x181514u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x181518: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181518u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18151c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x18151cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181520: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x181520u;
    {
        const bool branch_taken_0x181520 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x181524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181520u;
            // 0x181524: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181520) {
            ctx->pc = 0x181544u;
            goto label_181544;
        }
    }
    ctx->pc = 0x181528u;
    // 0x181528: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x181528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x18152c: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x18152cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x181530: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x181530u;
    SET_GPR_U32(ctx, 31, 0x181538u);
    ctx->pc = 0x181534u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181530u;
            // 0x181534: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181538u; }
        if (ctx->pc != 0x181538u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181538u; }
        if (ctx->pc != 0x181538u) { return; }
    }
    ctx->pc = 0x181538u;
label_181538:
    // 0x181538: 0xc062228  jal         func_1888A0
    ctx->pc = 0x181538u;
    SET_GPR_U32(ctx, 31, 0x181540u);
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181540u; }
        if (ctx->pc != 0x181540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181540u; }
        if (ctx->pc != 0x181540u) { return; }
    }
    ctx->pc = 0x181540u;
label_181540:
    // 0x181540: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x181540u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_181544:
    // 0x181544: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x181544u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181548: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x181548u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x18154c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x18154cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181550: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x181550u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x181554: 0x3e00008  jr          $ra
    ctx->pc = 0x181554u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181554u;
            // 0x181558: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1814E0u: goto label_1814e0;
            case 0x1814F8u: goto label_1814f8;
            case 0x181510u: goto label_181510;
            case 0x181538u: goto label_181538;
            case 0x181540u: goto label_181540;
            case 0x181544u: goto label_181544;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18155Cu;
    // 0x18155c: 0x0  nop
    ctx->pc = 0x18155cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
