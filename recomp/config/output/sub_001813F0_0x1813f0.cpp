#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001813F0
// Address: 0x1813f0 - 0x1814a8
void sub_001813F0_0x1813f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001813F0_0x1813f0");
#endif

    switch (ctx->pc) {
        case 0x181428u: goto label_181428;
        case 0x181458u: goto label_181458;
        case 0x181480u: goto label_181480;
        case 0x18148cu: goto label_18148c;
        default: break;
    }

    ctx->pc = 0x1813f0u;

    // 0x1813f0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1813f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1813f4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1813f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1813f8: 0x8c66fa10  lw          $a2, -0x5F0($v1)
    ctx->pc = 0x1813f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x1813fc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1813fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181400: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x181400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x181404: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x181404u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181408: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x181408u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x18140c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x18140cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181410: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x181410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x181414: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x181414u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
    // 0x181418: 0x10c0001d  beqz        $a2, . + 4 + (0x1D << 2)
    ctx->pc = 0x181418u;
    {
        const bool branch_taken_0x181418 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x18141Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181418u;
            // 0x18141c: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181418) {
            ctx->pc = 0x181490u;
            goto label_181490;
        }
    }
    ctx->pc = 0x181420u;
    // 0x181420: 0xc061e90  jal         func_187A40
    ctx->pc = 0x181420u;
    SET_GPR_U32(ctx, 31, 0x181428u);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181428u; }
        if (ctx->pc != 0x181428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181428u; }
        if (ctx->pc != 0x181428u) { return; }
    }
    ctx->pc = 0x181428u;
label_181428:
    // 0x181428: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x181428u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x18142c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18142Cu;
    {
        const bool branch_taken_0x18142c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18142Cu;
            // 0x181430: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18142c) {
            ctx->pc = 0x181440u;
            goto label_181440;
        }
    }
    ctx->pc = 0x181434u;
    // 0x181434: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181434u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181438: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x181438u;
    {
        const bool branch_taken_0x181438 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18143Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181438u;
            // 0x18143c: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181438) {
            ctx->pc = 0x181490u;
            goto label_181490;
        }
    }
    ctx->pc = 0x181440u;
label_181440:
    // 0x181440: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x181440u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x181444: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181444u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181448: 0x14600011  bnez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x181448u;
    {
        const bool branch_taken_0x181448 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x18144Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181448u;
            // 0x18144c: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181448) {
            ctx->pc = 0x181490u;
            goto label_181490;
        }
    }
    ctx->pc = 0x181450u;
    // 0x181450: 0xc042c56  jal         func_10B158
    ctx->pc = 0x181450u;
    SET_GPR_U32(ctx, 31, 0x181458u);
    ctx->pc = 0x181454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181450u;
            // 0x181454: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181458u; }
        if (ctx->pc != 0x181458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181458u; }
        if (ctx->pc != 0x181458u) { return; }
    }
    ctx->pc = 0x181458u;
label_181458:
    // 0x181458: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x181458u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18145c: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x18145cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x181460: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181460u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181464: 0x2604041c  addiu       $a0, $s0, 0x41C
    ctx->pc = 0x181464u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
    // 0x181468: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x181468u;
    {
        const bool branch_taken_0x181468 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x18146Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181468u;
            // 0x18146c: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181468) {
            ctx->pc = 0x181490u;
            goto label_181490;
        }
    }
    ctx->pc = 0x181470u;
    // 0x181470: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x181470u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x181474: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x181474u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x181478: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x181478u;
    SET_GPR_U32(ctx, 31, 0x181480u);
    ctx->pc = 0x18147Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181478u;
            // 0x18147c: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181480u; }
        if (ctx->pc != 0x181480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181480u; }
        if (ctx->pc != 0x181480u) { return; }
    }
    ctx->pc = 0x181480u;
label_181480:
    // 0x181480: 0x34038417  ori         $v1, $zero, 0x8417
    ctx->pc = 0x181480u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33815);
    // 0x181484: 0xc062228  jal         func_1888A0
    ctx->pc = 0x181484u;
    SET_GPR_U32(ctx, 31, 0x18148Cu);
    ctx->pc = 0x181488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181484u;
            // 0x181488: 0xae03000c  sw          $v1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18148Cu; }
        if (ctx->pc != 0x18148Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18148Cu; }
        if (ctx->pc != 0x18148Cu) { return; }
    }
    ctx->pc = 0x18148Cu;
label_18148c:
    // 0x18148c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18148cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_181490:
    // 0x181490: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x181490u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181494: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x181494u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x181498: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x181498u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18149c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x18149cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1814a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1814A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1814A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1814A0u;
            // 0x1814a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181428u: goto label_181428;
            case 0x181440u: goto label_181440;
            case 0x181458u: goto label_181458;
            case 0x181480u: goto label_181480;
            case 0x18148Cu: goto label_18148c;
            case 0x181490u: goto label_181490;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1814A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
