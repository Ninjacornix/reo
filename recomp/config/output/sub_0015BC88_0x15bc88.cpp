#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BC88
// Address: 0x15bc88 - 0x15bcd8
void sub_0015BC88_0x15bc88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BC88_0x15bc88");
#endif

    ctx->pc = 0x15bc88u;

    // 0x15bc88: 0x8c8a0008  lw          $t2, 0x8($a0)
    ctx->pc = 0x15bc88u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x15bc8c: 0x8c8b000c  lw          $t3, 0xC($a0)
    ctx->pc = 0x15bc8cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x15bc90: 0xa1fc2  srl         $v1, $t2, 31
    ctx->pc = 0x15bc90u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
    // 0x15bc94: 0x1431821  addu        $v1, $t2, $v1
    ctx->pc = 0x15bc94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x15bc98: 0xb27c2  srl         $a0, $t3, 31
    ctx->pc = 0x15bc98u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 11), 31));
    // 0x15bc9c: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x15bc9cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x15bca0: 0x1642021  addu        $a0, $t3, $a0
    ctx->pc = 0x15bca0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 4)));
    // 0x15bca4: 0x2462001f  addiu       $v0, $v1, 0x1F
    ctx->pc = 0x15bca4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 31));
    // 0x15bca8: 0x2463003e  addiu       $v1, $v1, 0x3E
    ctx->pc = 0x15bca8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 62));
    // 0x15bcac: 0x28490000  slti        $t1, $v0, 0x0
    ctx->pc = 0x15bcacu;
    SET_GPR_U64(ctx, 9, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15bcb0: 0x42043  sra         $a0, $a0, 1
    ctx->pc = 0x15bcb0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 1));
    // 0x15bcb4: 0x69100b  movn        $v0, $v1, $t1
    ctx->pc = 0x15bcb4u;
    if (GPR_U64(ctx, 9) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x15bcb8: 0x21143  sra         $v0, $v0, 5
    ctx->pc = 0x15bcb8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 5));
    // 0x15bcbc: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x15bcbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x15bcc0: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x15bcc0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x15bcc4: 0xad040000  sw          $a0, 0x0($t0)
    ctx->pc = 0x15bcc4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 4));
    // 0x15bcc8: 0xacaa0000  sw          $t2, 0x0($a1)
    ctx->pc = 0x15bcc8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 10));
    // 0x15bccc: 0x3e00008  jr          $ra
    ctx->pc = 0x15BCCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BCD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BCCCu;
            // 0x15bcd0: 0xaccb0000  sw          $t3, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 11));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15BCD4u;
    // 0x15bcd4: 0x0  nop
    ctx->pc = 0x15bcd4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
