#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6E90
// Address: 0x1b6e90 - 0x1b6f10
void sub_001B6E90_0x1b6e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6E90_0x1b6e90");
#endif

    ctx->pc = 0x1b6e90u;

    // 0x1b6e90: 0x24a2ffff  addiu       $v0, $a1, -0x1
    ctx->pc = 0x1b6e90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1b6e94: 0x2303c  dsll32      $a2, $v0, 0
    ctx->pc = 0x1b6e94u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6e98: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1b6e98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1b6e9c: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x1b6e9cu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x1b6ea0: 0x34450003  ori         $a1, $v0, 0x3
    ctx->pc = 0x1b6ea0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3);
    // 0x1b6ea4: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x1b6ea4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6ea8: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x1b6ea8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x1b6eac: 0x3c025100  lui         $v0, 0x5100
    ctx->pc = 0x1b6eacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20736 << 16));
    // 0x1b6eb0: 0x34450003  ori         $a1, $v0, 0x3
    ctx->pc = 0x1b6eb0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3);
    // 0x1b6eb4: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x1b6eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x1b6eb8: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x1b6eb8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1b6ebc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b6ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b6ec0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1b6ec0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1b6ec4: 0xac85000c  sw          $a1, 0xC($a0)
    ctx->pc = 0x1b6ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 5));
    // 0x1b6ec8: 0xfc820010  sd          $v0, 0x10($a0)
    ctx->pc = 0x1b6ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 2));
    // 0x1b6ecc: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1b6eccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1b6ed0: 0xfc820018  sd          $v0, 0x18($a0)
    ctx->pc = 0x1b6ed0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 2));
    // 0x1b6ed4: 0x24020044  addiu       $v0, $zero, 0x44
    ctx->pc = 0x1b6ed4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
    // 0x1b6ed8: 0xfc820020  sd          $v0, 0x20($a0)
    ctx->pc = 0x1b6ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 32), GPR_U64(ctx, 2));
    // 0x1b6edc: 0x24020042  addiu       $v0, $zero, 0x42
    ctx->pc = 0x1b6edcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 66));
    // 0x1b6ee0: 0xfc820028  sd          $v0, 0x28($a0)
    ctx->pc = 0x1b6ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 40), GPR_U64(ctx, 2));
    // 0x1b6ee4: 0x613b8  dsll        $v0, $a2, 14
    ctx->pc = 0x1b6ee4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << 14);
    // 0x1b6ee8: 0x3443000a  ori         $v1, $v0, 0xA
    ctx->pc = 0x1b6ee8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)10);
    // 0x1b6eec: 0x610bc  dsll32      $v0, $a2, 2
    ctx->pc = 0x1b6eecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 2));
    // 0x1b6ef0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1b6ef0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1b6ef4: 0xfc820030  sd          $v0, 0x30($a0)
    ctx->pc = 0x1b6ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 48), GPR_U64(ctx, 2));
    // 0x1b6ef8: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1b6ef8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b6efc: 0x24820040  addiu       $v0, $a0, 0x40
    ctx->pc = 0x1b6efcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 64));
    // 0x1b6f00: 0x3e00008  jr          $ra
    ctx->pc = 0x1B6F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6F00u;
            // 0x1b6f04: 0xfc830038  sd          $v1, 0x38($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 56), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B6F08u;
    // 0x1b6f08: 0x0  nop
    ctx->pc = 0x1b6f08u;
    // NOP
    // 0x1b6f0c: 0x0  nop
    ctx->pc = 0x1b6f0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
