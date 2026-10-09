#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A7C8
// Address: 0x20a7c8 - 0x20a83c
void sub_0020A7C8_0x20a7c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A7C8_0x20a7c8");
#endif

    switch (ctx->pc) {
        case 0x20a810u: goto label_20a810;
        default: break;
    }

    ctx->pc = 0x20a7c8u;

    // 0x20a7c8: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x20a7c8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20a7cc: 0x662821  addu        $a1, $v1, $a2
    ctx->pc = 0x20a7ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x20a7d0: 0x2ca20081  sltiu       $v0, $a1, 0x81
    ctx->pc = 0x20a7d0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)129) ? 1 : 0);
    // 0x20a7d4: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x20A7D4u;
    {
        const bool branch_taken_0x20a7d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20A7D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A7D4u;
            // 0x20a7d8: 0x80482d  daddu       $t1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a7d4) {
            ctx->pc = 0x20A7FCu;
            goto label_20a7fc;
        }
    }
    ctx->pc = 0x20A7DCu;
    // 0x20a7dc: 0x2cc20080  sltiu       $v0, $a2, 0x80
    ctx->pc = 0x20a7dcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x20a7e0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x20A7E0u;
    {
        const bool branch_taken_0x20a7e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A7E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A7E0u;
            // 0x20a7e4: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a7e0) {
            ctx->pc = 0x20A7F0u;
            goto label_20a7f0;
        }
    }
    ctx->pc = 0x20A7E8u;
    // 0x20a7e8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x20A7E8u;
    {
        const bool branch_taken_0x20a7e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A7ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A7E8u;
            // 0x20a7ec: 0x461823  subu        $v1, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a7e8) {
            ctx->pc = 0x20A7F8u;
            goto label_20a7f8;
        }
    }
    ctx->pc = 0x20A7F0u;
label_20a7f0:
    // 0x20a7f0: 0x24060080  addiu       $a2, $zero, 0x80
    ctx->pc = 0x20a7f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x20a7f4: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x20a7f4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_20a7f8:
    // 0x20a7f8: 0x662821  addu        $a1, $v1, $a2
    ctx->pc = 0x20a7f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
label_20a7fc:
    // 0x20a7fc: 0xc5102b  sltu        $v0, $a2, $a1
    ctx->pc = 0x20a7fcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x20a800: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x20A800u;
    {
        const bool branch_taken_0x20a800 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A800u;
            // 0x20a804: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a800) {
            ctx->pc = 0x20A834u;
            goto label_20a834;
        }
    }
    ctx->pc = 0x20A808u;
    // 0x20a808: 0x3c088007  lui         $t0, 0x8007
    ctx->pc = 0x20a808u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32775 << 16));
    // 0x20a80c: 0x0  nop
    ctx->pc = 0x20a80cu;
    // NOP
label_20a810:
    // 0x20a810: 0x1271021  addu        $v0, $t1, $a3
    ctx->pc = 0x20a810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 7)));
    // 0x20a814: 0x250347b0  addiu       $v1, $t0, 0x47B0
    ctx->pc = 0x20a814u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 18352));
    // 0x20a818: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x20a818u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x20a81c: 0x90440000  lbu         $a0, 0x0($v0)
    ctx->pc = 0x20a81cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x20a820: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x20a820u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x20a824: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x20a824u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x20a828: 0xc5102b  sltu        $v0, $a2, $a1
    ctx->pc = 0x20a828u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x20a82c: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x20A82Cu;
    {
        const bool branch_taken_0x20a82c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20A830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A82Cu;
            // 0x20a830: 0xa0640000  sb          $a0, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a82c) {
            ctx->pc = 0x20A810u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20a810;
        }
    }
    ctx->pc = 0x20A834u;
label_20a834:
    // 0x20a834: 0x3e00008  jr          $ra
    ctx->pc = 0x20A834u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A7F0u: goto label_20a7f0;
            case 0x20A7F8u: goto label_20a7f8;
            case 0x20A7FCu: goto label_20a7fc;
            case 0x20A810u: goto label_20a810;
            case 0x20A834u: goto label_20a834;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20A83Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
