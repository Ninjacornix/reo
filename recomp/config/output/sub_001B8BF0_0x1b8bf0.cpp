#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8BF0
// Address: 0x1b8bf0 - 0x1b8c68
void sub_001B8BF0_0x1b8bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8BF0_0x1b8bf0");
#endif

    switch (ctx->pc) {
        case 0x1b8c08u: goto label_1b8c08;
        case 0x1b8c38u: goto label_1b8c38;
        case 0x1b8c58u: goto label_1b8c58;
        default: break;
    }

    ctx->pc = 0x1b8bf0u;

    // 0x1b8bf0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b8bf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b8bf4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b8bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b8bf8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b8bf8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b8bfc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1b8bfcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8c00: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B8C00u;
    SET_GPR_U32(ctx, 31, 0x1B8C08u);
    ctx->pc = 0x1B8C04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8C00u;
            // 0x1b8c04: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8C08u; }
        if (ctx->pc != 0x1B8C08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8C08u; }
        if (ctx->pc != 0x1B8C08u) { return; }
    }
    ctx->pc = 0x1B8C08u;
label_1b8c08:
    // 0x1b8c08: 0x92040002  lbu         $a0, 0x2($s0)
    ctx->pc = 0x1b8c08u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b8c0c: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b8c0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b8c10: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x1b8c10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1b8c14: 0x1480000a  bnez        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B8C14u;
    {
        const bool branch_taken_0x1b8c14 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B8C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8C14u;
            // 0x1b8c18: 0x24650001  addiu       $a1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8c14) {
            ctx->pc = 0x1B8C40u;
            goto label_1b8c40;
        }
    }
    ctx->pc = 0x1B8C1Cu;
    // 0x1b8c1c: 0x92060003  lbu         $a2, 0x3($s0)
    ctx->pc = 0x1b8c1cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b8c20: 0x26070038  addiu       $a3, $s0, 0x38
    ctx->pc = 0x1b8c20u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 56));
    // 0x1b8c24: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b8c24u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8c28: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b8c28u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8c2c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b8c2cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8c30: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B8C30u;
    SET_GPR_U32(ctx, 31, 0x1B8C38u);
    ctx->pc = 0x1B8C34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8C30u;
            // 0x1b8c34: 0x24c40004  addiu       $a0, $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8C38u; }
        if (ctx->pc != 0x1B8C38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8C38u; }
        if (ctx->pc != 0x1B8C38u) { return; }
    }
    ctx->pc = 0x1B8C38u;
label_1b8c38:
    // 0x1b8c38: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B8C38u;
    {
        const bool branch_taken_0x1b8c38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8C38u;
            // 0x1b8c3c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8c38) {
            ctx->pc = 0x1B8C5Cu;
            goto label_1b8c5c;
        }
    }
    ctx->pc = 0x1B8C40u;
label_1b8c40:
    // 0x1b8c40: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b8c40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8c44: 0x14830004  bne         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B8C44u;
    {
        const bool branch_taken_0x1b8c44 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b8c44) {
            ctx->pc = 0x1B8C58u;
            goto label_1b8c58;
        }
    }
    ctx->pc = 0x1B8C4Cu;
    // 0x1b8c4c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b8c4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8c50: 0xc06e2c8  jal         func_1B8B20
    ctx->pc = 0x1B8C50u;
    SET_GPR_U32(ctx, 31, 0x1B8C58u);
    ctx->pc = 0x1B8C54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8C50u;
            // 0x1b8c54: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8B20u;
    if (runtime->hasFunction(0x1B8B20u)) {
        auto targetFn = runtime->lookupFunction(0x1B8B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8C58u; }
        if (ctx->pc != 0x1B8C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8B20_0x1b8b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8C58u; }
        if (ctx->pc != 0x1B8C58u) { return; }
    }
    ctx->pc = 0x1B8C58u;
label_1b8c58:
    // 0x1b8c58: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b8c58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b8c5c:
    // 0x1b8c5c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b8c5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8c60: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8C60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8C60u;
            // 0x1b8c64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8C08u: goto label_1b8c08;
            case 0x1B8C38u: goto label_1b8c38;
            case 0x1B8C40u: goto label_1b8c40;
            case 0x1B8C58u: goto label_1b8c58;
            case 0x1B8C5Cu: goto label_1b8c5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8C68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
