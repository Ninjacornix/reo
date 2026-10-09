#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A2F0
// Address: 0x13a2f0 - 0x13a328
void sub_0013A2F0_0x13a2f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A2F0_0x13a2f0");
#endif

    ctx->pc = 0x13a2f0u;

    // 0x13a2f0: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x13a2f0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x13a2f4: 0x42603  sra         $a0, $a0, 24
    ctx->pc = 0x13a2f4u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 24));
    // 0x13a2f8: 0x2482ff9f  addiu       $v0, $a0, -0x61
    ctx->pc = 0x13a2f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967199));
    // 0x13a2fc: 0x2483ffe0  addiu       $v1, $a0, -0x20
    ctx->pc = 0x13a2fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967264));
    // 0x13a300: 0x2c42001a  sltiu       $v0, $v0, 0x1A
    ctx->pc = 0x13a300u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)26) ? 1 : 0);
    // 0x13a304: 0x32e00  sll         $a1, $v1, 24
    ctx->pc = 0x13a304u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x13a308: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x13A308u;
    {
        const bool branch_taken_0x13a308 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A30Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A308u;
            // 0x13a30c: 0x80182d  daddu       $v1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a308) {
            ctx->pc = 0x13A314u;
            goto label_13a314;
        }
    }
    ctx->pc = 0x13A310u;
    // 0x13a310: 0x52603  sra         $a0, $a1, 24
    ctx->pc = 0x13a310u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 5), 24));
label_13a314:
    // 0x13a314: 0x3863005c  xori        $v1, $v1, 0x5C
    ctx->pc = 0x13a314u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)92);
    // 0x13a318: 0x2402002f  addiu       $v0, $zero, 0x2F
    ctx->pc = 0x13a318u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x13a31c: 0x3e00008  jr          $ra
    ctx->pc = 0x13A31Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A31Cu;
            // 0x13a320: 0x83100b  movn        $v0, $a0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13A314u: goto label_13a314;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13A324u;
    // 0x13a324: 0x0  nop
    ctx->pc = 0x13a324u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
