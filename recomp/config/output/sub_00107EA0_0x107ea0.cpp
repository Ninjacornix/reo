#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00107EA0
// Address: 0x107ea0 - 0x107ed0
void sub_00107EA0_0x107ea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00107EA0_0x107ea0");
#endif

    ctx->pc = 0x107ea0u;

    // 0x107ea0: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x107EA0u;
    {
        const bool branch_taken_0x107ea0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x107ea0) {
            ctx->pc = 0x107EC4u;
            goto label_107ec4;
        }
    }
    ctx->pc = 0x107EA8u;
    // 0x107ea8: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x107ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x107eac: 0x8c84004c  lw          $a0, 0x4C($a0)
    ctx->pc = 0x107eacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x107eb0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x107eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x107eb4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x107eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x107eb8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x107eb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x107ebc: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x107ebcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x107ec0: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x107ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
label_107ec4:
    // 0x107ec4: 0x3e00008  jr          $ra
    ctx->pc = 0x107EC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107EC4u: goto label_107ec4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107ECCu;
    // 0x107ecc: 0x0  nop
    ctx->pc = 0x107eccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
