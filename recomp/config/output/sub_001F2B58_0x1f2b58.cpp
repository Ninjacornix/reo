#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F2B58
// Address: 0x1f2b58 - 0x1f2bf0
void sub_001F2B58_0x1f2b58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F2B58_0x1f2b58");
#endif

    ctx->pc = 0x1f2b58u;

    // 0x1f2b58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f2b58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f2b5c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f2b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f2b60: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f2b60u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2b64: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f2b64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f2b68: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2b68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2b6c: 0xac40003c  sw          $zero, 0x3C($v0)
    ctx->pc = 0x1f2b6cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
    // 0x1f2b70: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2b70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2b74: 0xac400040  sw          $zero, 0x40($v0)
    ctx->pc = 0x1f2b74u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 64), GPR_U32(ctx, 0));
    // 0x1f2b78: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2b78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2b7c: 0xac400044  sw          $zero, 0x44($v0)
    ctx->pc = 0x1f2b7cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 68), GPR_U32(ctx, 0));
    // 0x1f2b80: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2b80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2b84: 0xac400048  sw          $zero, 0x48($v0)
    ctx->pc = 0x1f2b84u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x1f2b88: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2b8c: 0xac40004c  sw          $zero, 0x4C($v0)
    ctx->pc = 0x1f2b8cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
    // 0x1f2b90: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2b90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2b94: 0xac400050  sw          $zero, 0x50($v0)
    ctx->pc = 0x1f2b94u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 80), GPR_U32(ctx, 0));
    // 0x1f2b98: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2b98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2b9c: 0xac400054  sw          $zero, 0x54($v0)
    ctx->pc = 0x1f2b9cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 84), GPR_U32(ctx, 0));
    // 0x1f2ba0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2ba4: 0xac400058  sw          $zero, 0x58($v0)
    ctx->pc = 0x1f2ba4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 88), GPR_U32(ctx, 0));
    // 0x1f2ba8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2bac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2bacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2bb0: 0x9442005c  lhu         $v0, 0x5C($v0)
    ctx->pc = 0x1f2bb0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1f2bb4: 0xa4620060  sh          $v0, 0x60($v1)
    ctx->pc = 0x1f2bb4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 96), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f2bb8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2bb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2bbc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2bc0: 0x94420062  lhu         $v0, 0x62($v0)
    ctx->pc = 0x1f2bc0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 98)));
    // 0x1f2bc4: 0xa4620066  sh          $v0, 0x66($v1)
    ctx->pc = 0x1f2bc4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 102), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f2bc8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2bc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2bcc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2bccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2bd0: 0x94420068  lhu         $v0, 0x68($v0)
    ctx->pc = 0x1f2bd0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 104)));
    // 0x1f2bd4: 0xa462006c  sh          $v0, 0x6C($v1)
    ctx->pc = 0x1f2bd4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 108), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f2bd8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f2bd8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2bdc: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f2bdcu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2be0: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f2be0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f2be4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f2be4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f2be8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F2BE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F2BF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
