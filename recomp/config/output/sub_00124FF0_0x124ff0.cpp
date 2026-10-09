#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124FF0
// Address: 0x124ff0 - 0x125054
void sub_00124FF0_0x124ff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124FF0_0x124ff0");
#endif

    switch (ctx->pc) {
        case 0x125010u: goto label_125010;
        case 0x125028u: goto label_125028;
        default: break;
    }

    ctx->pc = 0x124ff0u;

    // 0x124ff0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x124ff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x124ff4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x124ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x124ff8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x124ff8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124ffc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x124ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x125000: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x125000u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125004: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x125004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x125008: 0xc042c56  jal         func_10B158
    ctx->pc = 0x125008u;
    SET_GPR_U32(ctx, 31, 0x125010u);
    ctx->pc = 0x12500Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125008u;
            // 0x12500c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125010u; }
        if (ctx->pc != 0x125010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125010u; }
        if (ctx->pc != 0x125010u) { return; }
    }
    ctx->pc = 0x125010u;
label_125010:
    // 0x125010: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x125010u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125014: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x125014u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125018: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x125018u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12501c: 0x27a70002  addiu       $a3, $sp, 0x2
    ctx->pc = 0x12501cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 2));
    // 0x125020: 0xc049156  jal         func_124558
    ctx->pc = 0x125020u;
    SET_GPR_U32(ctx, 31, 0x125028u);
    ctx->pc = 0x125024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125020u;
            // 0x125024: 0x27a80004  addiu       $t0, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124558u;
    if (runtime->hasFunction(0x124558u)) {
        auto targetFn = runtime->lookupFunction(0x124558u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125028u; }
        if (ctx->pc != 0x125028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124558_0x124558(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125028u; }
        if (ctx->pc != 0x125028u) { return; }
    }
    ctx->pc = 0x125028u;
label_125028:
    // 0x125028: 0x97a30000  lhu         $v1, 0x0($sp)
    ctx->pc = 0x125028u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12502c: 0x97a40002  lhu         $a0, 0x2($sp)
    ctx->pc = 0x12502cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 2)));
    // 0x125030: 0x97a20004  lhu         $v0, 0x4($sp)
    ctx->pc = 0x125030u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x125034: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x125034u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x125038: 0xa623009c  sh          $v1, 0x9C($s1)
    ctx->pc = 0x125038u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 156), (uint16_t)GPR_U32(ctx, 3));
    // 0x12503c: 0xa62200a0  sh          $v0, 0xA0($s1)
    ctx->pc = 0x12503cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 160), (uint16_t)GPR_U32(ctx, 2));
    // 0x125040: 0xa624009e  sh          $a0, 0x9E($s1)
    ctx->pc = 0x125040u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 158), (uint16_t)GPR_U32(ctx, 4));
    // 0x125044: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x125044u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125048: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x125048u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12504c: 0x3e00008  jr          $ra
    ctx->pc = 0x12504Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12504Cu;
            // 0x125050: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125010u: goto label_125010;
            case 0x125028u: goto label_125028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125054u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
