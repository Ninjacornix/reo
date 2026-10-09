#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CE980
// Address: 0x1ce980 - 0x1cea48
void sub_001CE980_0x1ce980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CE980_0x1ce980");
#endif

    switch (ctx->pc) {
        case 0x1ce9acu: goto label_1ce9ac;
        case 0x1ce9f8u: goto label_1ce9f8;
        default: break;
    }

    ctx->pc = 0x1ce980u;

    // 0x1ce980: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1ce980u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1ce984: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1ce984u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1ce988: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ce988u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ce98c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ce98cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ce990: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1ce990u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce994: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ce994u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ce998: 0x3c120034  lui         $s2, 0x34
    ctx->pc = 0x1ce998u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)52 << 16));
    // 0x1ce99c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ce99cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ce9a0: 0x26521500  addiu       $s2, $s2, 0x1500
    ctx->pc = 0x1ce9a0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 5376));
    // 0x1ce9a4: 0x808027  not         $s0, $a0
    ctx->pc = 0x1ce9a4u;
    SET_GPR_U64(ctx, 16, ~(GPR_U64(ctx, 4) | GPR_U64(ctx, 0)));
    // 0x1ce9a8: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1ce9a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ce9ac:
    // 0x1ce9ac: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1ce9acu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1ce9b0: 0x1060001a  beqz        $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1CE9B0u;
    {
        const bool branch_taken_0x1ce9b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE9B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE9B0u;
            // 0x1ce9b4: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce9b0) {
            ctx->pc = 0x1CEA1Cu;
            goto label_1cea1c;
        }
    }
    ctx->pc = 0x1CE9B8u;
    // 0x1ce9b8: 0x12630004  beq         $s3, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CE9B8u;
    {
        const bool branch_taken_0x1ce9b8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ce9b8) {
            ctx->pc = 0x1CE9CCu;
            goto label_1ce9cc;
        }
    }
    ctx->pc = 0x1CE9C0u;
    // 0x1ce9c0: 0x92430010  lbu         $v1, 0x10($s2)
    ctx->pc = 0x1ce9c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1ce9c4: 0x14730015  bne         $v1, $s3, . + 4 + (0x15 << 2)
    ctx->pc = 0x1CE9C4u;
    {
        const bool branch_taken_0x1ce9c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 19));
        if (branch_taken_0x1ce9c4) {
            ctx->pc = 0x1CEA1Cu;
            goto label_1cea1c;
        }
    }
    ctx->pc = 0x1CE9CCu;
label_1ce9cc:
    // 0x1ce9cc: 0x9243000f  lbu         $v1, 0xF($s2)
    ctx->pc = 0x1ce9ccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 15)));
    // 0x1ce9d0: 0x320400ff  andi        $a0, $s0, 0xFF
    ctx->pc = 0x1ce9d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x1ce9d4: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x1ce9d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1ce9d8: 0xa243000f  sb          $v1, 0xF($s2)
    ctx->pc = 0x1ce9d8u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 15), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ce9dc: 0x9243000f  lbu         $v1, 0xF($s2)
    ctx->pc = 0x1ce9dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 15)));
    // 0x1ce9e0: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CE9E0u;
    {
        const bool branch_taken_0x1ce9e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ce9e0) {
            ctx->pc = 0x1CEA00u;
            goto label_1cea00;
        }
    }
    ctx->pc = 0x1CE9E8u;
    // 0x1ce9e8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ce9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ce9ec: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1ce9ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce9f0: 0xc0739d4  jal         func_1CE750
    ctx->pc = 0x1CE9F0u;
    SET_GPR_U32(ctx, 31, 0x1CE9F8u);
    ctx->pc = 0x1CE9F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE9F0u;
            // 0x1ce9f4: 0xa2420000  sb          $v0, 0x0($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE750u;
    if (runtime->hasFunction(0x1CE750u)) {
        auto targetFn = runtime->lookupFunction(0x1CE750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE9F8u; }
        if (ctx->pc != 0x1CE9F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE750_0x1ce750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE9F8u; }
        if (ctx->pc != 0x1CE9F8u) { return; }
    }
    ctx->pc = 0x1CE9F8u;
label_1ce9f8:
    // 0x1ce9f8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1CE9F8u;
    {
        const bool branch_taken_0x1ce9f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE9FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE9F8u;
            // 0x1ce9fc: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce9f8) {
            ctx->pc = 0x1CEA20u;
            goto label_1cea20;
        }
    }
    ctx->pc = 0x1CEA00u;
label_1cea00:
    // 0x1cea00: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1cea00u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1cea04: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1cea04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1cea08: 0xa2430000  sb          $v1, 0x0($s2)
    ctx->pc = 0x1cea08u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cea0c: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1cea0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1cea10: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CEA10u;
    {
        const bool branch_taken_0x1cea10 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CEA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEA10u;
            // 0x1cea14: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cea10) {
            ctx->pc = 0x1CEA1Cu;
            goto label_1cea1c;
        }
    }
    ctx->pc = 0x1CEA18u;
    // 0x1cea18: 0xa2430000  sb          $v1, 0x0($s2)
    ctx->pc = 0x1cea18u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
label_1cea1c:
    // 0x1cea1c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1cea1cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1cea20:
    // 0x1cea20: 0x2a230010  slti        $v1, $s1, 0x10
    ctx->pc = 0x1cea20u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1cea24: 0x1460ffe1  bnez        $v1, . + 4 + (-0x1F << 2)
    ctx->pc = 0x1CEA24u;
    {
        const bool branch_taken_0x1cea24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CEA28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEA24u;
            // 0x1cea28: 0x26520014  addiu       $s2, $s2, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cea24) {
            ctx->pc = 0x1CE9ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ce9ac;
        }
    }
    ctx->pc = 0x1CEA2Cu;
    // 0x1cea2c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1cea2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cea30: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cea30u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cea34: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cea34u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cea38: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cea38u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cea3c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cea3cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cea40: 0x3e00008  jr          $ra
    ctx->pc = 0x1CEA40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CEA44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEA40u;
            // 0x1cea44: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CE9ACu: goto label_1ce9ac;
            case 0x1CE9CCu: goto label_1ce9cc;
            case 0x1CE9F8u: goto label_1ce9f8;
            case 0x1CEA00u: goto label_1cea00;
            case 0x1CEA1Cu: goto label_1cea1c;
            case 0x1CEA20u: goto label_1cea20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CEA48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
