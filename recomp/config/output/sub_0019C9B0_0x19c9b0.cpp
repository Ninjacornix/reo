#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019C9B0
// Address: 0x19c9b0 - 0x19ca50
void sub_0019C9B0_0x19c9b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019C9B0_0x19c9b0");
#endif

    switch (ctx->pc) {
        case 0x19c9d8u: goto label_19c9d8;
        case 0x19ca0cu: goto label_19ca0c;
        case 0x19ca1cu: goto label_19ca1c;
        default: break;
    }

    ctx->pc = 0x19c9b0u;

    // 0x19c9b0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x19c9b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x19c9b4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x19c9b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c9b8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x19c9b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19c9bc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19c9bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19c9c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19c9c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19c9c4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x19c9c4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c9c8: 0x3c10002a  lui         $s0, 0x2A
    ctx->pc = 0x19c9c8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)42 << 16));
    // 0x19c9cc: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x19c9ccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x19c9d0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x19C9D0u;
    {
        const bool branch_taken_0x19c9d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19C9D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C9D0u;
            // 0x19c9d4: 0x2610be90  addiu       $s0, $s0, -0x4170 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294950544));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19c9d0) {
            ctx->pc = 0x19C9ECu;
            goto label_19c9ec;
        }
    }
    ctx->pc = 0x19C9D8u;
label_19c9d8:
    // 0x19c9d8: 0x86030002  lh          $v1, 0x2($s0)
    ctx->pc = 0x19c9d8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x19c9dc: 0x10640007  beq         $v1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x19C9DCu;
    {
        const bool branch_taken_0x19c9dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x19C9E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C9DCu;
            // 0x19c9e0: 0x24030006  addiu       $v1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19c9dc) {
            ctx->pc = 0x19C9FCu;
            goto label_19c9fc;
        }
    }
    ctx->pc = 0x19C9E4u;
    // 0x19c9e4: 0x26100008  addiu       $s0, $s0, 0x8
    ctx->pc = 0x19c9e4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x19c9e8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x19c9e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_19c9ec:
    // 0x19c9ec: 0x28a30200  slti        $v1, $a1, 0x200
    ctx->pc = 0x19c9ecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)512) ? 1 : 0);
    // 0x19c9f0: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19C9F0u;
    {
        const bool branch_taken_0x19c9f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19c9f0) {
            ctx->pc = 0x19C9D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19c9d8;
        }
    }
    ctx->pc = 0x19C9F8u;
    // 0x19c9f8: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x19c9f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
label_19c9fc:
    // 0x19c9fc: 0x10a3000f  beq         $a1, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x19C9FCu;
    {
        const bool branch_taken_0x19c9fc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x19c9fc) {
            ctx->pc = 0x19CA3Cu;
            goto label_19ca3c;
        }
    }
    ctx->pc = 0x19CA04u;
    // 0x19ca04: 0xc067ba4  jal         func_19EE90
    ctx->pc = 0x19CA04u;
    SET_GPR_U32(ctx, 31, 0x19CA0Cu);
    ctx->pc = 0x19EE90u;
    if (runtime->hasFunction(0x19EE90u)) {
        auto targetFn = runtime->lookupFunction(0x19EE90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CA0Cu; }
        if (ctx->pc != 0x19CA0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EE90_0x19ee90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CA0Cu; }
        if (ctx->pc != 0x19CA0Cu) { return; }
    }
    ctx->pc = 0x19CA0Cu;
label_19ca0c:
    // 0x19ca0c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x19ca0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ca10: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x19ca10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ca14: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x19CA14u;
    SET_GPR_U32(ctx, 31, 0x19CA1Cu);
    ctx->pc = 0x19CA18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19CA14u;
            // 0x19ca18: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CA1Cu; }
        if (ctx->pc != 0x19CA1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CA1Cu; }
        if (ctx->pc != 0x19CA1Cu) { return; }
    }
    ctx->pc = 0x19CA1Cu;
label_19ca1c:
    // 0x19ca1c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ca1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ca20: 0x3223ffff  andi        $v1, $s1, 0xFFFF
    ctx->pc = 0x19ca20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
    // 0x19ca24: 0x8c24be80  lw          $a0, -0x4180($at)
    ctx->pc = 0x19ca24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950528)));
    // 0x19ca28: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ca28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ca2c: 0xac23f9f8  sw          $v1, -0x608($at)
    ctx->pc = 0x19ca2cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965752), GPR_U32(ctx, 3));
    // 0x19ca30: 0x2483ffff  addiu       $v1, $a0, -0x1
    ctx->pc = 0x19ca30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19ca34: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ca34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ca38: 0xac23be80  sw          $v1, -0x4180($at)
    ctx->pc = 0x19ca38u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950528), GPR_U32(ctx, 3));
label_19ca3c:
    // 0x19ca3c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x19ca3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19ca40: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19ca40u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19ca44: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19ca44u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19ca48: 0x3e00008  jr          $ra
    ctx->pc = 0x19CA48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19CA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19CA48u;
            // 0x19ca4c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19C9D8u: goto label_19c9d8;
            case 0x19C9ECu: goto label_19c9ec;
            case 0x19C9FCu: goto label_19c9fc;
            case 0x19CA0Cu: goto label_19ca0c;
            case 0x19CA1Cu: goto label_19ca1c;
            case 0x19CA3Cu: goto label_19ca3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19CA50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
