#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E7C00
// Address: 0x1e7c00 - 0x1e7c7c
void sub_001E7C00_0x1e7c00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E7C00_0x1e7c00");
#endif

    switch (ctx->pc) {
        case 0x1e7c18u: goto label_1e7c18;
        case 0x1e7c64u: goto label_1e7c64;
        default: break;
    }

    ctx->pc = 0x1e7c00u;

    // 0x1e7c00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e7c00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e7c04: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e7c04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e7c08: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e7c08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e7c0c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7c0cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7c10: 0x0  nop
    ctx->pc = 0x1e7c10u;
    // NOP
    // 0x1e7c14: 0xafc00000  sw          $zero, 0x0($fp)
    ctx->pc = 0x1e7c14u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
label_1e7c18:
    // 0x1e7c18: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7c18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7c1c: 0x3403cb1f  ori         $v1, $zero, 0xCB1F
    ctx->pc = 0x1e7c1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)51999);
    // 0x1e7c20: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1e7c20u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1e7c24: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7C24u;
    {
        const bool branch_taken_0x1e7c24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7c24) {
            ctx->pc = 0x1E7C34u;
            goto label_1e7c34;
        }
    }
    ctx->pc = 0x1E7C2Cu;
    // 0x1e7c2c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1E7C2Cu;
    {
        const bool branch_taken_0x1e7c2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7c2c) {
            ctx->pc = 0x1E7C5Cu;
            goto label_1e7c5c;
        }
    }
    ctx->pc = 0x1E7C34u;
label_1e7c34:
    // 0x1e7c34: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1e7c34u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1e7c38: 0x24638ca0  addiu       $v1, $v1, -0x7360
    ctx->pc = 0x1e7c38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937760));
    // 0x1e7c3c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7c40: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7c40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e7c44: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1e7c44u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1e7c48: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7c48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7c4c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e7c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e7c50: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1e7c50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x1e7c54: 0x1000fff0  b           . + 4 + (-0x10 << 2)
    ctx->pc = 0x1E7C54u;
    {
        const bool branch_taken_0x1e7c54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7c54) {
            ctx->pc = 0x1E7C18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e7c18;
        }
    }
    ctx->pc = 0x1E7C5Cu;
label_1e7c5c:
    // 0x1e7c5c: 0xc079eee  jal         func_1E7BB8
    ctx->pc = 0x1E7C5Cu;
    SET_GPR_U32(ctx, 31, 0x1E7C64u);
    ctx->pc = 0x1E7BB8u;
    if (runtime->hasFunction(0x1E7BB8u)) {
        auto targetFn = runtime->lookupFunction(0x1E7BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7C64u; }
        if (ctx->pc != 0x1E7C64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7BB8_0x1e7bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7C64u; }
        if (ctx->pc != 0x1E7C64u) { return; }
    }
    ctx->pc = 0x1E7C64u;
label_1e7c64:
    // 0x1e7c64: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e7c64u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7c68: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e7c68u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e7c6c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e7c6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e7c70: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e7c70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e7c74: 0x3e00008  jr          $ra
    ctx->pc = 0x1E7C74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7C18u: goto label_1e7c18;
            case 0x1E7C34u: goto label_1e7c34;
            case 0x1E7C5Cu: goto label_1e7c5c;
            case 0x1E7C64u: goto label_1e7c64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E7C7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
