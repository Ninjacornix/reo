#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A9F0
// Address: 0x12a9f0 - 0x12aa60
void sub_0012A9F0_0x12a9f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A9F0_0x12a9f0");
#endif

    switch (ctx->pc) {
        case 0x12aa28u: goto label_12aa28;
        case 0x12aa30u: goto label_12aa30;
        case 0x12aa40u: goto label_12aa40;
        default: break;
    }

    ctx->pc = 0x12a9f0u;

    // 0x12a9f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12a9f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12a9f4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12a9f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12a9f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12a9f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12a9fc: 0x24710480  addiu       $s1, $v1, 0x480
    ctx->pc = 0x12a9fcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 1152));
    // 0x12aa00: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x12aa00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12aa04: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12aa04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12aa08: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x12aa08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x12aa0c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12aa0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12aa10: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x12AA10u;
    {
        const bool branch_taken_0x12aa10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12AA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AA10u;
            // 0x12aa14: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12aa10) {
            ctx->pc = 0x12AA40u;
            goto label_12aa40;
        }
    }
    ctx->pc = 0x12AA18u;
    // 0x12aa18: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x12aa18u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x12aa1c: 0x261004d8  addiu       $s0, $s0, 0x4D8
    ctx->pc = 0x12aa1cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1240));
    // 0x12aa20: 0xc04ac56  jal         func_12B158
    ctx->pc = 0x12AA20u;
    SET_GPR_U32(ctx, 31, 0x12AA28u);
    ctx->pc = 0x12AA24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AA20u;
            // 0x12aa24: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B158u;
    if (runtime->hasFunction(0x12B158u)) {
        auto targetFn = runtime->lookupFunction(0x12B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AA28u; }
        if (ctx->pc != 0x12AA28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B158_0x12b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AA28u; }
        if (ctx->pc != 0x12AA28u) { return; }
    }
    ctx->pc = 0x12AA28u;
label_12aa28:
    // 0x12aa28: 0xc045144  jal         func_114510
    ctx->pc = 0x12AA28u;
    SET_GPR_U32(ctx, 31, 0x12AA30u);
    ctx->pc = 0x12AA2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AA28u;
            // 0x12aa2c: 0x8e030000  lw          $v1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AA30u; }
        if (ctx->pc != 0x12AA30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AA30u; }
        if (ctx->pc != 0x12AA30u) { return; }
    }
    ctx->pc = 0x12AA30u;
label_12aa30:
    // 0x12aa30: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12aa30u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12aa34: 0x8c657d70  lw          $a1, 0x7D70($v1)
    ctx->pc = 0x12aa34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32112)));
    // 0x12aa38: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12AA38u;
    SET_GPR_U32(ctx, 31, 0x12AA40u);
    ctx->pc = 0x12AA3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AA38u;
            // 0x12aa3c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AA40u; }
        if (ctx->pc != 0x12AA40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AA40u; }
        if (ctx->pc != 0x12AA40u) { return; }
    }
    ctx->pc = 0x12AA40u;
label_12aa40:
    // 0x12aa40: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x12aa40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12aa44: 0x4420001  bltzl       $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x12AA44u;
    {
        const bool branch_taken_0x12aa44 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x12aa44) {
            ctx->pc = 0x12AA48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12AA44u;
            // 0x12aa48: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12AA4Cu;
            goto label_12aa4c;
        }
    }
    ctx->pc = 0x12AA4Cu;
label_12aa4c:
    // 0x12aa4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12aa4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12aa50: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12aa50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12aa54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12aa54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12aa58: 0x3e00008  jr          $ra
    ctx->pc = 0x12AA58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12AA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AA58u;
            // 0x12aa5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12AA28u: goto label_12aa28;
            case 0x12AA30u: goto label_12aa30;
            case 0x12AA40u: goto label_12aa40;
            case 0x12AA4Cu: goto label_12aa4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12AA60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
