#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158568
// Address: 0x158568 - 0x1585b8
void sub_00158568_0x158568(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158568_0x158568");
#endif

    switch (ctx->pc) {
        case 0x15857cu: goto label_15857c;
        default: break;
    }

    ctx->pc = 0x158568u;

    // 0x158568: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x158568u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15856c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15856cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x158570: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x158570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x158574: 0xc0560f2  jal         func_1583C8
    ctx->pc = 0x158574u;
    SET_GPR_U32(ctx, 31, 0x15857Cu);
    ctx->pc = 0x158578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158574u;
            // 0x158578: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1583C8u;
    if (runtime->hasFunction(0x1583C8u)) {
        auto targetFn = runtime->lookupFunction(0x1583C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15857Cu; }
        if (ctx->pc != 0x15857Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583C8_0x1583c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15857Cu; }
        if (ctx->pc != 0x15857Cu) { return; }
    }
    ctx->pc = 0x15857Cu;
label_15857c:
    // 0x15857c: 0x3c05ff02  lui         $a1, 0xFF02
    ctx->pc = 0x15857cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65282 << 16));
    // 0x158580: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x158580u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158584: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x158584u;
    {
        const bool branch_taken_0x158584 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x158588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158584u;
            // 0x158588: 0x34a50103  ori         $a1, $a1, 0x103 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)259);
        ctx->in_delay_slot = false;
        if (branch_taken_0x158584) {
            ctx->pc = 0x1585A0u;
            goto label_1585a0;
        }
    }
    ctx->pc = 0x15858Cu;
    // 0x15858c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15858cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158590: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x158590u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x158594: 0x805607e  j           func_1581F8
    ctx->pc = 0x158594u;
    ctx->pc = 0x158598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158594u;
            // 0x158598: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1581F8u;
    if (runtime->hasFunction(0x1581F8u)) {
        auto targetFn = runtime->lookupFunction(0x1581F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001581F8_0x1581f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15859Cu;
    // 0x15859c: 0x0  nop
    ctx->pc = 0x15859cu;
    // NOP
label_1585a0:
    // 0x1585a0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1585a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1585a4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1585a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1585a8: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1585a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1585ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1585acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1585b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1585B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1585B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1585B0u;
            // 0x1585b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15857Cu: goto label_15857c;
            case 0x1585A0u: goto label_1585a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1585B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
