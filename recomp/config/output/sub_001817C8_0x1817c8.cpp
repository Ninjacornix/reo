#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001817C8
// Address: 0x1817c8 - 0x181888
void sub_001817C8_0x1817c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001817C8_0x1817c8");
#endif

    switch (ctx->pc) {
        case 0x181808u: goto label_181808;
        case 0x181838u: goto label_181838;
        case 0x181860u: goto label_181860;
        case 0x181868u: goto label_181868;
        default: break;
    }

    ctx->pc = 0x1817c8u;

    // 0x1817c8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1817c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1817cc: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1817ccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1817d0: 0x8c67fa10  lw          $a3, -0x5F0($v1)
    ctx->pc = 0x1817d0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x1817d4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1817d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1817d8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1817d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1817dc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1817dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1817e0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1817e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1817e4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1817e4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1817e8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1817e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1817ec: 0x30d3ffff  andi        $s3, $a2, 0xFFFF
    ctx->pc = 0x1817ecu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x1817f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1817f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1817f4: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x1817f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
    // 0x1817f8: 0x10e0001c  beqz        $a3, . + 4 + (0x1C << 2)
    ctx->pc = 0x1817F8u;
    {
        const bool branch_taken_0x1817f8 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x1817FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1817F8u;
            // 0x1817fc: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1817f8) {
            ctx->pc = 0x18186Cu;
            goto label_18186c;
        }
    }
    ctx->pc = 0x181800u;
    // 0x181800: 0xc061e90  jal         func_187A40
    ctx->pc = 0x181800u;
    SET_GPR_U32(ctx, 31, 0x181808u);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181808u; }
        if (ctx->pc != 0x181808u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181808u; }
        if (ctx->pc != 0x181808u) { return; }
    }
    ctx->pc = 0x181808u;
label_181808:
    // 0x181808: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x181808u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x18180c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18180Cu;
    {
        const bool branch_taken_0x18180c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18180Cu;
            // 0x181810: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18180c) {
            ctx->pc = 0x181820u;
            goto label_181820;
        }
    }
    ctx->pc = 0x181814u;
    // 0x181814: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181814u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181818: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x181818u;
    {
        const bool branch_taken_0x181818 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18181Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181818u;
            // 0x18181c: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181818) {
            ctx->pc = 0x18186Cu;
            goto label_18186c;
        }
    }
    ctx->pc = 0x181820u;
label_181820:
    // 0x181820: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x181820u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x181824: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181824u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181828: 0x14600010  bnez        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x181828u;
    {
        const bool branch_taken_0x181828 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x18182Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181828u;
            // 0x18182c: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181828) {
            ctx->pc = 0x18186Cu;
            goto label_18186c;
        }
    }
    ctx->pc = 0x181830u;
    // 0x181830: 0xc042c56  jal         func_10B158
    ctx->pc = 0x181830u;
    SET_GPR_U32(ctx, 31, 0x181838u);
    ctx->pc = 0x181834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181830u;
            // 0x181834: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181838u; }
        if (ctx->pc != 0x181838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181838u; }
        if (ctx->pc != 0x181838u) { return; }
    }
    ctx->pc = 0x181838u;
label_181838:
    // 0x181838: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x181838u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18183c: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x18183cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x181840: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181840u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181844: 0x2604041c  addiu       $a0, $s0, 0x41C
    ctx->pc = 0x181844u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
    // 0x181848: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x181848u;
    {
        const bool branch_taken_0x181848 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x18184Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181848u;
            // 0x18184c: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181848) {
            ctx->pc = 0x18186Cu;
            goto label_18186c;
        }
    }
    ctx->pc = 0x181850u;
    // 0x181850: 0x2402000d  addiu       $v0, $zero, 0xD
    ctx->pc = 0x181850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x181854: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x181854u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x181858: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x181858u;
    SET_GPR_U32(ctx, 31, 0x181860u);
    ctx->pc = 0x18185Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181858u;
            // 0x18185c: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181860u; }
        if (ctx->pc != 0x181860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181860u; }
        if (ctx->pc != 0x181860u) { return; }
    }
    ctx->pc = 0x181860u;
label_181860:
    // 0x181860: 0xc062228  jal         func_1888A0
    ctx->pc = 0x181860u;
    SET_GPR_U32(ctx, 31, 0x181868u);
    ctx->pc = 0x181864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181860u;
            // 0x181864: 0xae13000c  sw          $s3, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181868u; }
        if (ctx->pc != 0x181868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181868u; }
        if (ctx->pc != 0x181868u) { return; }
    }
    ctx->pc = 0x181868u;
label_181868:
    // 0x181868: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x181868u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18186c:
    // 0x18186c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x18186cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181870: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x181870u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x181874: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x181874u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181878: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x181878u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x18187c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x18187cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x181880: 0x3e00008  jr          $ra
    ctx->pc = 0x181880u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181880u;
            // 0x181884: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181808u: goto label_181808;
            case 0x181820u: goto label_181820;
            case 0x181838u: goto label_181838;
            case 0x181860u: goto label_181860;
            case 0x181868u: goto label_181868;
            case 0x18186Cu: goto label_18186c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181888u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
