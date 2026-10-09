#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2C10
// Address: 0x1a2c10 - 0x1a2c80
void sub_001A2C10_0x1a2c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2C10_0x1a2c10");
#endif

    switch (ctx->pc) {
        case 0x1a2c3cu: goto label_1a2c3c;
        case 0x1a2c54u: goto label_1a2c54;
        case 0x1a2c6cu: goto label_1a2c6c;
        default: break;
    }

    ctx->pc = 0x1a2c10u;

label_1a2c10:
    // 0x1a2c10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a2c10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a2c14: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a2c14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a2c18: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a2c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a2c1c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a2c1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a2c20: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a2c20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a2c24: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a2c24u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2c28: 0x8c22ffd8  lw          $v0, -0x28($at)
    ctx->pc = 0x1a2c28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967256)));
    // 0x1a2c2c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a2c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a2c30: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a2c30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a2c34: 0xc068b5c  jal         func_1A2D70
    ctx->pc = 0x1A2C34u;
    SET_GPR_U32(ctx, 31, 0x1A2C3Cu);
    ctx->pc = 0x1A2C38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2C34u;
            // 0x1a2c38: 0xac22ffd8  sw          $v0, -0x28($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294967256), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2D70u;
    if (runtime->hasFunction(0x1A2D70u)) {
        auto targetFn = runtime->lookupFunction(0x1A2D70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2C3Cu; }
        if (ctx->pc != 0x1A2C3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2D70_0x1a2d70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2C3Cu; }
        if (ctx->pc != 0x1A2C3Cu) { return; }
    }
    ctx->pc = 0x1A2C3Cu;
label_1a2c3c:
    // 0x1a2c3c: 0x8c450008  lw          $a1, 0x8($v0)
    ctx->pc = 0x1a2c3cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1a2c40: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1a2c40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a2c44: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A2C44u;
    {
        const bool branch_taken_0x1a2c44 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A2C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2C44u;
            // 0x1a2c48: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2c44) {
            ctx->pc = 0x1A2C54u;
            goto label_1a2c54;
        }
    }
    ctx->pc = 0x1A2C4Cu;
    // 0x1a2c4c: 0xc068b04  jal         func_1A2C10
    ctx->pc = 0x1A2C4Cu;
    SET_GPR_U32(ctx, 31, 0x1A2C54u);
    ctx->pc = 0x1A2C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2C4Cu;
            // 0x1a2c50: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2C10u;
    goto label_1a2c10;
    ctx->pc = 0x1A2C54u;
label_1a2c54:
    // 0x1a2c54: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x1a2c54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1a2c58: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1a2c58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a2c5c: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A2C5Cu;
    {
        const bool branch_taken_0x1a2c5c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A2C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2C5Cu;
            // 0x1a2c60: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2c5c) {
            ctx->pc = 0x1A2C6Cu;
            goto label_1a2c6c;
        }
    }
    ctx->pc = 0x1A2C64u;
    // 0x1a2c64: 0xc068b04  jal         func_1A2C10
    ctx->pc = 0x1A2C64u;
    SET_GPR_U32(ctx, 31, 0x1A2C6Cu);
    ctx->pc = 0x1A2C10u;
    goto label_1a2c10;
    ctx->pc = 0x1A2C6Cu;
label_1a2c6c:
    // 0x1a2c6c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a2c6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a2c70: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a2c70u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a2c74: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a2c74u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a2c78: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2C78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2C78u;
            // 0x1a2c7c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2C10u: goto label_1a2c10;
            case 0x1A2C3Cu: goto label_1a2c3c;
            case 0x1A2C54u: goto label_1a2c54;
            case 0x1A2C6Cu: goto label_1a2c6c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2C80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
