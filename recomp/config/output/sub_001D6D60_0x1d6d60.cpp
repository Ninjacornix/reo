#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6D60
// Address: 0x1d6d60 - 0x1d6dd0
void sub_001D6D60_0x1d6d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6D60_0x1d6d60");
#endif

    switch (ctx->pc) {
        case 0x1d6d70u: goto label_1d6d70;
        default: break;
    }

    ctx->pc = 0x1d6d60u;

    // 0x1d6d60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d6d60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d6d64: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d6d64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d6d68: 0xc076480  jal         func_1D9200
    ctx->pc = 0x1D6D68u;
    SET_GPR_U32(ctx, 31, 0x1D6D70u);
    ctx->pc = 0x1D9200u;
    if (runtime->hasFunction(0x1D9200u)) {
        auto targetFn = runtime->lookupFunction(0x1D9200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6D70u; }
        if (ctx->pc != 0x1D6D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9200_0x1d9200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6D70u; }
        if (ctx->pc != 0x1D6D70u) { return; }
    }
    ctx->pc = 0x1D6D70u;
label_1d6d70:
    // 0x1d6d70: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d6d70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6d74: 0x2404fffe  addiu       $a0, $zero, -0x2
    ctx->pc = 0x1d6d74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1d6d78: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d6d78u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d6d7c: 0x1044000c  beq         $v0, $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D6D7Cu;
    {
        const bool branch_taken_0x1d6d7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x1D6D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6D7Cu;
            // 0x1d6d80: 0x2403fffa  addiu       $v1, $zero, -0x6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967290));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6d7c) {
            ctx->pc = 0x1D6DB0u;
            goto label_1d6db0;
        }
    }
    ctx->pc = 0x1D6D84u;
    // 0x1d6d84: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D6D84u;
    {
        const bool branch_taken_0x1d6d84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d6d84) {
            ctx->pc = 0x1D6DA8u;
            goto label_1d6da8;
        }
    }
    ctx->pc = 0x1D6D8Cu;
    // 0x1d6d8c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d6d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6d90: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6D90u;
    {
        const bool branch_taken_0x1d6d90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d6d90) {
            ctx->pc = 0x1D6DA0u;
            goto label_1d6da0;
        }
    }
    ctx->pc = 0x1D6D98u;
    // 0x1d6d98: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1D6D98u;
    {
        const bool branch_taken_0x1d6d98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6d98) {
            ctx->pc = 0x1D6DB8u;
            goto label_1d6db8;
        }
    }
    ctx->pc = 0x1D6DA0u;
label_1d6da0:
    // 0x1d6da0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D6DA0u;
    {
        const bool branch_taken_0x1d6da0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6DA0u;
            // 0x1d6da4: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6da0) {
            ctx->pc = 0x1D6DB8u;
            goto label_1d6db8;
        }
    }
    ctx->pc = 0x1D6DA8u;
label_1d6da8:
    // 0x1d6da8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6DA8u;
    {
        const bool branch_taken_0x1d6da8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6DA8u;
            // 0x1d6dac: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6da8) {
            ctx->pc = 0x1D6DB8u;
            goto label_1d6db8;
        }
    }
    ctx->pc = 0x1D6DB0u;
label_1d6db0:
    // 0x1d6db0: 0x2402fffd  addiu       $v0, $zero, -0x3
    ctx->pc = 0x1d6db0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1d6db4: 0x0  nop
    ctx->pc = 0x1d6db4u;
    // NOP
label_1d6db8:
    // 0x1d6db8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d6db8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6dbc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6DBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6DBCu;
            // 0x1d6dc0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6D70u: goto label_1d6d70;
            case 0x1D6DA0u: goto label_1d6da0;
            case 0x1D6DA8u: goto label_1d6da8;
            case 0x1D6DB0u: goto label_1d6db0;
            case 0x1D6DB8u: goto label_1d6db8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6DC4u;
    // 0x1d6dc4: 0x0  nop
    ctx->pc = 0x1d6dc4u;
    // NOP
    // 0x1d6dc8: 0x0  nop
    ctx->pc = 0x1d6dc8u;
    // NOP
    // 0x1d6dcc: 0x0  nop
    ctx->pc = 0x1d6dccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
