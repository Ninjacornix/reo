#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103088
// Address: 0x103088 - 0x103168
void sub_00103088_0x103088(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103088_0x103088");
#endif

    switch (ctx->pc) {
        case 0x1030c0u: goto label_1030c0;
        case 0x103124u: goto label_103124;
        case 0x10312cu: goto label_10312c;
        default: break;
    }

    ctx->pc = 0x103088u;

    // 0x103088: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x103088u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x10308c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x10308cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x103090: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x103090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x103094: 0x3442e000  ori         $v0, $v0, 0xE000
    ctx->pc = 0x103094u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57344);
    // 0x103098: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x103098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x10309c: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x10309cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1030a0: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1030a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1030a4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x1030a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x1030a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1030a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1030ac: 0x246394c8  addiu       $v1, $v1, -0x6B38
    ctx->pc = 0x1030acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939848));
    // 0x1030b0: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1030b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1030b4: 0x24c67710  addiu       $a2, $a2, 0x7710
    ctx->pc = 0x1030b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 30480));
    // 0x1030b8: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x1030b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1030bc: 0x30b10001  andi        $s1, $a1, 0x1
    ctx->pc = 0x1030bcu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
label_1030c0:
    // 0x1030c0: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x1030c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1030c4: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x1030C4u;
    {
        const bool branch_taken_0x1030c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1030c4) {
            ctx->pc = 0x1030C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1030C4u;
            // 0x1030c8: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1030ECu;
            goto label_1030ec;
        }
    }
    ctx->pc = 0x1030CCu;
    // 0x1030cc: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1030ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1030d0: 0xac400080  sw          $zero, 0x80($v0)
    ctx->pc = 0x1030d0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 128), GPR_U32(ctx, 0));
    // 0x1030d4: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1030d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1030d8: 0xac400030  sw          $zero, 0x30($v0)
    ctx->pc = 0x1030d8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 48), GPR_U32(ctx, 0));
    // 0x1030dc: 0xac400010  sw          $zero, 0x10($v0)
    ctx->pc = 0x1030dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0x1030e0: 0xac400050  sw          $zero, 0x50($v0)
    ctx->pc = 0x1030e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 80), GPR_U32(ctx, 0));
    // 0x1030e4: 0xac400040  sw          $zero, 0x40($v0)
    ctx->pc = 0x1030e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 64), GPR_U32(ctx, 0));
    // 0x1030e8: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1030e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
label_1030ec:
    // 0x1030ec: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1030ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1030f0: 0x481fff3  bgez        $a0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1030F0u;
    {
        const bool branch_taken_0x1030f0 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1030F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1030F0u;
            // 0x1030f4: 0x24c60004  addiu       $a2, $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1030f0) {
            ctx->pc = 0x1030C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1030c0;
        }
    }
    ctx->pc = 0x1030F8u;
    // 0x1030f8: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1030f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1030fc: 0x3402ff1f  ori         $v0, $zero, 0xFF1F
    ctx->pc = 0x1030fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65311);
    // 0x103100: 0x3463e010  ori         $v1, $v1, 0xE010
    ctx->pc = 0x103100u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)57360);
    // 0x103104: 0x3c06ff1f  lui         $a2, 0xFF1F
    ctx->pc = 0x103104u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)65311 << 16));
    // 0x103108: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x103108u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x10310c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x10310cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103110: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x103110u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x103114: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x103114u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x103118: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x103118u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x10311c: 0xc040c0a  jal         func_103028
    ctx->pc = 0x10311Cu;
    SET_GPR_U32(ctx, 31, 0x103124u);
    ctx->pc = 0x103120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10311Cu;
            // 0x103120: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103028u;
    if (runtime->hasFunction(0x103028u)) {
        auto targetFn = runtime->lookupFunction(0x103028u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103124u; }
        if (ctx->pc != 0x103124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103028_0x103028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103124u; }
        if (ctx->pc != 0x103124u) { return; }
    }
    ctx->pc = 0x103124u;
label_103124:
    // 0x103124: 0xc040c5a  jal         func_103168
    ctx->pc = 0x103124u;
    SET_GPR_U32(ctx, 31, 0x10312Cu);
    ctx->pc = 0x103128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103124u;
            // 0x103128: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103168u;
    if (runtime->hasFunction(0x103168u)) {
        auto targetFn = runtime->lookupFunction(0x103168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10312Cu; }
        if (ctx->pc != 0x10312Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103168_0x103168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10312Cu; }
        if (ctx->pc != 0x10312Cu) { return; }
    }
    ctx->pc = 0x10312Cu;
label_10312c:
    // 0x10312c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x10312cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x103130: 0x16030007  bne         $s0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x103130u;
    {
        const bool branch_taken_0x103130 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x103134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103130u;
            // 0x103134: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103130) {
            ctx->pc = 0x103150u;
            goto label_103150;
        }
    }
    ctx->pc = 0x103138u;
    // 0x103138: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x103138u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x10313c: 0x3463e000  ori         $v1, $v1, 0xE000
    ctx->pc = 0x10313cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)57344);
    // 0x103140: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x103140u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x103144: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x103144u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x103148: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x103148u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x10314c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x10314cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_103150:
    // 0x103150: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x103150u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x103154: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x103154u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x103158: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x103158u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10315c: 0x3e00008  jr          $ra
    ctx->pc = 0x10315Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10315Cu;
            // 0x103160: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1030C0u: goto label_1030c0;
            case 0x1030ECu: goto label_1030ec;
            case 0x103124u: goto label_103124;
            case 0x10312Cu: goto label_10312c;
            case 0x103150u: goto label_103150;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103164u;
    // 0x103164: 0x0  nop
    ctx->pc = 0x103164u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
