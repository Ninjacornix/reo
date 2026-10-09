#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F0BA0
// Address: 0x1f0ba0 - 0x1f0c0c
void sub_001F0BA0_0x1f0ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F0BA0_0x1f0ba0");
#endif

    switch (ctx->pc) {
        case 0x1f0bccu: goto label_1f0bcc;
        default: break;
    }

    ctx->pc = 0x1f0ba0u;

    // 0x1f0ba0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f0ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f0ba4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f0ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f0ba8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f0ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f0bac: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f0bacu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0bb0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f0bb4: 0x27c20004  addiu       $v0, $fp, 0x4
    ctx->pc = 0x1f0bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 4));
    // 0x1f0bb8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f0bb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0bbc: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1f0bbcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0bc0: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0bc0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0bc4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0BC4u;
    SET_GPR_U32(ctx, 31, 0x1F0BCCu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0BCCu; }
        if (ctx->pc != 0x1F0BCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0BCCu; }
        if (ctx->pc != 0x1F0BCCu) { return; }
    }
    ctx->pc = 0x1F0BCCu;
label_1f0bcc:
    // 0x1f0bcc: 0x87c20004  lh          $v0, 0x4($fp)
    ctx->pc = 0x1f0bccu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0bd0: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f0bd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f0bd4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f0bd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0bd8: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1f0bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1f0bdc: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1f0bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0be0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1f0be0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f0be4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1f0be4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1f0be8: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f0be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f0bec: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f0becu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f0bf0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f0bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0bf4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f0bf4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0bf8: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f0bf8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f0bfc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f0bfcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f0c00: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f0c00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f0c04: 0x3e00008  jr          $ra
    ctx->pc = 0x1F0C04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F0BCCu: goto label_1f0bcc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F0C0Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
