#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E8858
// Address: 0x1e8858 - 0x1e88c0
void sub_001E8858_0x1e8858(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E8858_0x1e8858");
#endif

    ctx->pc = 0x1e8858u;

    // 0x1e8858: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e8858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e885c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e885cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e8860: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8860u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8864: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e8864u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e8868: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e8868u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e886c: 0x440000e  bltz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1E886Cu;
    {
        const bool branch_taken_0x1e886c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1e886c) {
            ctx->pc = 0x1E88A8u;
            goto label_1e88a8;
        }
    }
    ctx->pc = 0x1E8874u;
    // 0x1e8874: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e8874u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8878: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x1e8878u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1e887c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1E887Cu;
    {
        const bool branch_taken_0x1e887c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e887c) {
            ctx->pc = 0x1E88A8u;
            goto label_1e88a8;
        }
    }
    ctx->pc = 0x1E8884u;
    // 0x1e8884: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e8884u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8888: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e8888u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e888c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e888cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e8890: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e8890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e8894: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e8894u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e8898: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e8898u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e889c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e889cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e88a0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E88A0u;
    {
        const bool branch_taken_0x1e88a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e88a0) {
            ctx->pc = 0x1E88ACu;
            goto label_1e88ac;
        }
    }
    ctx->pc = 0x1E88A8u;
label_1e88a8:
    // 0x1e88a8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e88a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e88ac:
    // 0x1e88ac: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e88acu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e88b0: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e88b0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e88b4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e88b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e88b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E88B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E88A8u: goto label_1e88a8;
            case 0x1E88ACu: goto label_1e88ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E88C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
