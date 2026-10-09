#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182198
// Address: 0x182198 - 0x182200
void sub_00182198_0x182198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182198_0x182198");
#endif

    switch (ctx->pc) {
        case 0x1821c0u: goto label_1821c0;
        default: break;
    }

    ctx->pc = 0x182198u;

    // 0x182198: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x182198u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18219c: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x18219cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1821a0: 0x52e03  sra         $a1, $a1, 24
    ctx->pc = 0x1821a0u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 24));
    // 0x1821a4: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1821a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1821a8: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1821A8u;
    {
        const bool branch_taken_0x1821a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1821ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1821A8u;
            // 0x1821ac: 0x90830000  lbu         $v1, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1821a8) {
            ctx->pc = 0x1821E4u;
            goto label_1821e4;
        }
    }
    ctx->pc = 0x1821B0u;
    // 0x1821b0: 0x10450011  beq         $v0, $a1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1821B0u;
    {
        const bool branch_taken_0x1821b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x1821B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1821B0u;
            // 0x1821b4: 0xc41023  subu        $v0, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1821b0) {
            ctx->pc = 0x1821F8u;
            goto label_1821f8;
        }
    }
    ctx->pc = 0x1821B8u;
    // 0x1821b8: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1821b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1821bc: 0x0  nop
    ctx->pc = 0x1821bcu;
    // NOP
label_1821c0:
    // 0x1821c0: 0x80c20000  lb          $v0, 0x0($a2)
    ctx->pc = 0x1821c0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1821c4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1821C4u;
    {
        const bool branch_taken_0x1821c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1821C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1821C4u;
            // 0x1821c8: 0x90c30000  lbu         $v1, 0x0($a2) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1821c4) {
            ctx->pc = 0x1821E4u;
            goto label_1821e4;
        }
    }
    ctx->pc = 0x1821CCu;
    // 0x1821cc: 0x0  nop
    ctx->pc = 0x1821ccu;
    // NOP
    // 0x1821d0: 0x0  nop
    ctx->pc = 0x1821d0u;
    // NOP
    // 0x1821d4: 0x0  nop
    ctx->pc = 0x1821d4u;
    // NOP
    // 0x1821d8: 0x0  nop
    ctx->pc = 0x1821d8u;
    // NOP
    // 0x1821dc: 0x5445fff8  bnel        $v0, $a1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1821DCu;
    {
        const bool branch_taken_0x1821dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x1821dc) {
            ctx->pc = 0x1821E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1821DCu;
            // 0x1821e0: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1821C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1821c0;
        }
    }
    ctx->pc = 0x1821E4u;
label_1821e4:
    // 0x1821e4: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1821e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1821e8: 0x31e03  sra         $v1, $v1, 24
    ctx->pc = 0x1821e8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 24));
    // 0x1821ec: 0x14650002  bne         $v1, $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1821ECu;
    {
        const bool branch_taken_0x1821ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1821F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1821ECu;
            // 0x1821f0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1821ec) {
            ctx->pc = 0x1821F8u;
            goto label_1821f8;
        }
    }
    ctx->pc = 0x1821F4u;
    // 0x1821f4: 0xc41023  subu        $v0, $a2, $a0
    ctx->pc = 0x1821f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
label_1821f8:
    // 0x1821f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1821F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1821C0u: goto label_1821c0;
            case 0x1821E4u: goto label_1821e4;
            case 0x1821F8u: goto label_1821f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182200u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
