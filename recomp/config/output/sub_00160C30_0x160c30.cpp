#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160C30
// Address: 0x160c30 - 0x160c90
void sub_00160C30_0x160c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160C30_0x160c30");
#endif

    switch (ctx->pc) {
        case 0x160c78u: goto label_160c78;
        default: break;
    }

    ctx->pc = 0x160c30u;

    // 0x160c30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160c30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160c34: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x160c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x160c38: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160c38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160c3c: 0x2c850003  sltiu       $a1, $a0, 0x3
    ctx->pc = 0x160c3cu;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x160c40: 0x1082000e  beq         $a0, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x160C40u;
    {
        const bool branch_taken_0x160c40 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x160C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160C40u;
            // 0x160c44: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160c40) {
            ctx->pc = 0x160C7Cu;
            goto label_160c7c;
        }
    }
    ctx->pc = 0x160C48u;
    // 0x160c48: 0x50a00005  beql        $a1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x160C48u;
    {
        const bool branch_taken_0x160c48 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x160c48) {
            ctx->pc = 0x160C4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x160C48u;
            // 0x160c4c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x160C60u;
            goto label_160c60;
        }
    }
    ctx->pc = 0x160C50u;
    // 0x160c50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x160c50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160c54: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x160C54u;
    {
        const bool branch_taken_0x160c54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160C54u;
            // 0x160c58: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160c54) {
            ctx->pc = 0x160C64u;
            goto label_160c64;
        }
    }
    ctx->pc = 0x160C5Cu;
    // 0x160c5c: 0x0  nop
    ctx->pc = 0x160c5cu;
    // NOP
label_160c60:
    // 0x160c60: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x160c60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_160c64:
    // 0x160c64: 0x10820006  beq         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x160C64u;
    {
        const bool branch_taken_0x160c64 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x160C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160C64u;
            // 0x160c68: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160c64) {
            ctx->pc = 0x160C80u;
            goto label_160c80;
        }
    }
    ctx->pc = 0x160C6Cu;
    // 0x160c6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160c6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160c70: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160C70u;
    SET_GPR_U32(ctx, 31, 0x160C78u);
    ctx->pc = 0x160C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160C70u;
            // 0x160c74: 0x2484f8a8  addiu       $a0, $a0, -0x758 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965416));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160C78u; }
        if (ctx->pc != 0x160C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160C78u; }
        if (ctx->pc != 0x160C78u) { return; }
    }
    ctx->pc = 0x160C78u;
label_160c78:
    // 0x160c78: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x160c78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_160c7c:
    // 0x160c7c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160c7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_160c80:
    // 0x160c80: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x160c80u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160c84: 0x3e00008  jr          $ra
    ctx->pc = 0x160C84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160C88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160C84u;
            // 0x160c88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160C60u: goto label_160c60;
            case 0x160C64u: goto label_160c64;
            case 0x160C78u: goto label_160c78;
            case 0x160C7Cu: goto label_160c7c;
            case 0x160C80u: goto label_160c80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160C8Cu;
    // 0x160c8c: 0x0  nop
    ctx->pc = 0x160c8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
