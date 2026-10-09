#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C078
// Address: 0x12c078 - 0x12c0c0
void sub_0012C078_0x12c078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C078_0x12c078");
#endif

    switch (ctx->pc) {
        case 0x12c0a0u: goto label_12c0a0;
        case 0x12c0a8u: goto label_12c0a8;
        default: break;
    }

    ctx->pc = 0x12c078u;

    // 0x12c078: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c078u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c07c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12c07cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12c080: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12c080u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12c084: 0x24500558  addiu       $s0, $v0, 0x558
    ctx->pc = 0x12c084u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 1368));
    // 0x12c088: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12c088u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12c08c: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x12C08Cu;
    {
        const bool branch_taken_0x12c08c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12C090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C08Cu;
            // 0x12c090: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12c08c) {
            ctx->pc = 0x12C0ACu;
            goto label_12c0ac;
        }
    }
    ctx->pc = 0x12C094u;
    // 0x12c094: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12c094u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c098: 0xc04cb02  jal         func_132C08
    ctx->pc = 0x12C098u;
    SET_GPR_U32(ctx, 31, 0x12C0A0u);
    ctx->pc = 0x132C08u;
    if (runtime->hasFunction(0x132C08u)) {
        auto targetFn = runtime->lookupFunction(0x132C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C0A0u; }
        if (ctx->pc != 0x12C0A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132C08_0x132c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C0A0u; }
        if (ctx->pc != 0x12C0A0u) { return; }
    }
    ctx->pc = 0x12C0A0u;
label_12c0a0:
    // 0x12c0a0: 0xc04a808  jal         func_12A020
    ctx->pc = 0x12C0A0u;
    SET_GPR_U32(ctx, 31, 0x12C0A8u);
    ctx->pc = 0x12A020u;
    if (runtime->hasFunction(0x12A020u)) {
        auto targetFn = runtime->lookupFunction(0x12A020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C0A8u; }
        if (ctx->pc != 0x12C0A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A020_0x12a020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C0A8u; }
        if (ctx->pc != 0x12C0A8u) { return; }
    }
    ctx->pc = 0x12C0A8u;
label_12c0a8:
    // 0x12c0a8: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x12c0a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_12c0ac:
    // 0x12c0ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12c0acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c0b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12c0b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c0b4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12c0b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12c0b8: 0x3e00008  jr          $ra
    ctx->pc = 0x12C0B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C0BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C0B8u;
            // 0x12c0bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C0A0u: goto label_12c0a0;
            case 0x12C0A8u: goto label_12c0a8;
            case 0x12C0ACu: goto label_12c0ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C0C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
