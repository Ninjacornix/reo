#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114E70
// Address: 0x114e70 - 0x114f18
void sub_00114E70_0x114e70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114E70_0x114e70");
#endif

    switch (ctx->pc) {
        case 0x114e80u: goto label_114e80;
        default: break;
    }

    ctx->pc = 0x114e70u;

    // 0x114e70: 0x3c07ffff  lui         $a3, 0xFFFF
    ctx->pc = 0x114e70u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)65535 << 16));
    // 0x114e74: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x114e74u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x114e78: 0x34e7f000  ori         $a3, $a3, 0xF000
    ctx->pc = 0x114e78u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)61440);
    // 0x114e7c: 0x0  nop
    ctx->pc = 0x114e7cu;
    // NOP
label_114e80:
    // 0x114e80: 0xf  sync
    ctx->pc = 0x114e80u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114e84: 0xbcd00000  cache       0x10, 0x0($a2)
    ctx->pc = 0x114e84u;
    // CACHE instruction (ignored)
    // 0x114e88: 0xf  sync
    ctx->pc = 0x114e88u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114e8c: 0x4002e000  mfc0        $v0, TagLo
    ctx->pc = 0x114e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_taglo);
    // 0x114e90: 0x471024  and         $v0, $v0, $a3
    ctx->pc = 0x114e90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 7));
    // 0x114e94: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x114e94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x114e98: 0xa2182b  sltu        $v1, $a1, $v0
    ctx->pc = 0x114e98u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x114e9c: 0x44102b  sltu        $v0, $v0, $a0
    ctx->pc = 0x114e9cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x114ea0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x114EA0u;
    {
        const bool branch_taken_0x114ea0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x114ea0) {
            ctx->pc = 0x114EBCu;
            goto label_114ebc;
        }
    }
    ctx->pc = 0x114EA8u;
    // 0x114ea8: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x114EA8u;
    {
        const bool branch_taken_0x114ea8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x114ea8) {
            ctx->pc = 0x114EBCu;
            goto label_114ebc;
        }
    }
    ctx->pc = 0x114EB0u;
    // 0x114eb0: 0xf  sync
    ctx->pc = 0x114eb0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114eb4: 0xbcd40000  cache       0x14, 0x0($a2)
    ctx->pc = 0x114eb4u;
    // CACHE instruction (ignored)
    // 0x114eb8: 0xf  sync
    ctx->pc = 0x114eb8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
label_114ebc:
    // 0x114ebc: 0xf  sync
    ctx->pc = 0x114ebcu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114ec0: 0xbcd00001  cache       0x10, 0x1($a2)
    ctx->pc = 0x114ec0u;
    // CACHE instruction (ignored)
    // 0x114ec4: 0xf  sync
    ctx->pc = 0x114ec4u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114ec8: 0x4002e000  mfc0        $v0, TagLo
    ctx->pc = 0x114ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_taglo);
    // 0x114ecc: 0x471024  and         $v0, $v0, $a3
    ctx->pc = 0x114eccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 7));
    // 0x114ed0: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x114ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x114ed4: 0xa2182b  sltu        $v1, $a1, $v0
    ctx->pc = 0x114ed4u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x114ed8: 0x44102b  sltu        $v0, $v0, $a0
    ctx->pc = 0x114ed8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x114edc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x114EDCu;
    {
        const bool branch_taken_0x114edc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x114edc) {
            ctx->pc = 0x114EF8u;
            goto label_114ef8;
        }
    }
    ctx->pc = 0x114EE4u;
    // 0x114ee4: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x114EE4u;
    {
        const bool branch_taken_0x114ee4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x114ee4) {
            ctx->pc = 0x114EF8u;
            goto label_114ef8;
        }
    }
    ctx->pc = 0x114EECu;
    // 0x114eec: 0xf  sync
    ctx->pc = 0x114eecu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114ef0: 0xbcd40001  cache       0x14, 0x1($a2)
    ctx->pc = 0x114ef0u;
    // CACHE instruction (ignored)
    // 0x114ef4: 0xf  sync
    ctx->pc = 0x114ef4u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
label_114ef8:
    // 0x114ef8: 0xf  sync
    ctx->pc = 0x114ef8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114efc: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x114efcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x114f00: 0x28c21000  slti        $v0, $a2, 0x1000
    ctx->pc = 0x114f00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4096) ? 1 : 0);
    // 0x114f04: 0x1440ffde  bnez        $v0, . + 4 + (-0x22 << 2)
    ctx->pc = 0x114F04u;
    {
        const bool branch_taken_0x114f04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x114f04) {
            ctx->pc = 0x114E80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_114e80;
        }
    }
    ctx->pc = 0x114F0Cu;
    // 0x114f0c: 0x3e00008  jr          $ra
    ctx->pc = 0x114F0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x114E80u: goto label_114e80;
            case 0x114EBCu: goto label_114ebc;
            case 0x114EF8u: goto label_114ef8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114F14u;
    // 0x114f14: 0x0  nop
    ctx->pc = 0x114f14u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
