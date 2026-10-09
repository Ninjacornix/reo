#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F6F50
// Address: 0x1f6f50 - 0x1f6f9c
void sub_001F6F50_0x1f6f50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F6F50_0x1f6f50");
#endif

    switch (ctx->pc) {
        case 0x1f6f70u: goto label_1f6f70;
        case 0x1f6f78u: goto label_1f6f78;
        default: break;
    }

    ctx->pc = 0x1f6f50u;

    // 0x1f6f50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f6f50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f6f54: 0x24020061  addiu       $v0, $zero, 0x61
    ctx->pc = 0x1f6f54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 97));
    // 0x1f6f58: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f6f58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f6f5c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f6f5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6f60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f6f60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6f64: 0xac820090  sw          $v0, 0x90($a0)
    ctx->pc = 0x1f6f64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 144), GPR_U32(ctx, 2));
    // 0x1f6f68: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6F68u;
    SET_GPR_U32(ctx, 31, 0x1F6F70u);
    ctx->pc = 0x1F6F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6F68u;
            // 0x1f6f6c: 0x8c840010  lw          $a0, 0x10($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F70u; }
        if (ctx->pc != 0x1F6F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F70u; }
        if (ctx->pc != 0x1F6F70u) { return; }
    }
    ctx->pc = 0x1F6F70u;
label_1f6f70:
    // 0x1f6f70: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6F70u;
    SET_GPR_U32(ctx, 31, 0x1F6F78u);
    ctx->pc = 0x1F6F74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6F70u;
            // 0x1f6f74: 0x26040010  addiu       $a0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F78u; }
        if (ctx->pc != 0x1F6F78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F78u; }
        if (ctx->pc != 0x1F6F78u) { return; }
    }
    ctx->pc = 0x1F6F78u;
label_1f6f78:
    // 0x1f6f78: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1f6f78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f6f7c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6f7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6f80: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1f6f80u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6f84: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6f84u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6f88: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f6f88u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6f8c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f6f8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f6f90: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6f90u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6f94: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6F94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F6F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6F94u;
            // 0x1f6f98: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6F9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
