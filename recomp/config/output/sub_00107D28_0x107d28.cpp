#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00107D28
// Address: 0x107d28 - 0x107da8
void sub_00107D28_0x107d28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00107D28_0x107d28");
#endif

    switch (ctx->pc) {
        case 0x107d40u: goto label_107d40;
        case 0x107d78u: goto label_107d78;
        default: break;
    }

    ctx->pc = 0x107d28u;

    // 0x107d28: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x107d28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x107d2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x107d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x107d30: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x107d30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x107d34: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x107d34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x107d38: 0xc045144  jal         func_114510
    ctx->pc = 0x107D38u;
    SET_GPR_U32(ctx, 31, 0x107D40u);
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107D40u; }
        if (ctx->pc != 0x107D40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107D40u; }
        if (ctx->pc != 0x107D40u) { return; }
    }
    ctx->pc = 0x107D40u;
label_107d40:
    // 0x107d40: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x107d40u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x107d44: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x107d44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107d48: 0x24719c58  addiu       $s1, $v1, -0x63A8
    ctx->pc = 0x107d48u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941784));
    // 0x107d4c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x107d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x107d50: 0x24449c5c  addiu       $a0, $v0, -0x63A4
    ctx->pc = 0x107d50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941788));
    // 0x107d54: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x107d54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x107d58: 0x14500005  bne         $v0, $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x107D58u;
    {
        const bool branch_taken_0x107d58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        ctx->pc = 0x107D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107D58u;
            // 0x107d5c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107d58) {
            ctx->pc = 0x107D70u;
            goto label_107d70;
        }
    }
    ctx->pc = 0x107D60u;
    // 0x107d60: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x107d60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x107d64: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x107d64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x107d68: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x107D68u;
    {
        const bool branch_taken_0x107d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107D68u;
            // 0x107d6c: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107d68) {
            ctx->pc = 0x107D90u;
            goto label_107d90;
        }
    }
    ctx->pc = 0x107D70u;
label_107d70:
    // 0x107d70: 0xc045198  jal         func_114660
    ctx->pc = 0x107D70u;
    SET_GPR_U32(ctx, 31, 0x107D78u);
    ctx->pc = 0x107D74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x107D70u;
            // 0x107d74: 0x8c44a470  lw          $a0, -0x5B90($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294943856)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107D78u; }
        if (ctx->pc != 0x107D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107D78u; }
        if (ctx->pc != 0x107D78u) { return; }
    }
    ctx->pc = 0x107D78u;
label_107d78:
    // 0x107d78: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x107d78u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x107d7c: 0xae300000  sw          $s0, 0x0($s1)
    ctx->pc = 0x107d7cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x107d80: 0x24639c5c  addiu       $v1, $v1, -0x63A4
    ctx->pc = 0x107d80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941788));
    // 0x107d84: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x107d84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x107d88: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x107d88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x107d8c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x107d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_107d90:
    // 0x107d90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x107d90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x107d94: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x107d94u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x107d98: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x107d98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x107d9c: 0x3e00008  jr          $ra
    ctx->pc = 0x107D9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107DA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107D9Cu;
            // 0x107da0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107D40u: goto label_107d40;
            case 0x107D70u: goto label_107d70;
            case 0x107D78u: goto label_107d78;
            case 0x107D90u: goto label_107d90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107DA4u;
    // 0x107da4: 0x0  nop
    ctx->pc = 0x107da4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
