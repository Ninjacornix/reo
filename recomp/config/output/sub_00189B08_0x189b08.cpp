#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189B08
// Address: 0x189b08 - 0x189be0
void sub_00189B08_0x189b08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189B08_0x189b08");
#endif

    switch (ctx->pc) {
        case 0x189b28u: goto label_189b28;
        case 0x189b80u: goto label_189b80;
        case 0x189bb8u: goto label_189bb8;
        default: break;
    }

    ctx->pc = 0x189b08u;

label_189b08:
    // 0x189b08: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189b08u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189b0c: 0x78820000  lq          $v0, 0x0($a0)
    ctx->pc = 0x189b0cu;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189b10: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x189b10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x189b14: 0x7ca20000  sq          $v0, 0x0($a1)
    ctx->pc = 0x189b14u;
    WRITE128(ADD32(GPR_U32(ctx, 5), 0), GPR_VEC(ctx, 2));
    // 0x189b18: 0x14c0fffb  bnez        $a2, . + 4 + (-0x5 << 2)
    ctx->pc = 0x189B18u;
    {
        const bool branch_taken_0x189b18 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189B18u;
            // 0x189b1c: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189b18) {
            ctx->pc = 0x189B08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189b08;
        }
    }
    ctx->pc = 0x189B20u;
    // 0x189b20: 0x3e00008  jr          $ra
    ctx->pc = 0x189B20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189B08u: goto label_189b08;
            case 0x189B28u: goto label_189b28;
            case 0x189B80u: goto label_189b80;
            case 0x189BB8u: goto label_189bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189B28u;
label_189b28:
    // 0x189b28: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x189b28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189b2c: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x189b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x189b30: 0x8c880008  lw          $t0, 0x8($a0)
    ctx->pc = 0x189b30u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x189b34: 0x8c89000c  lw          $t1, 0xC($a0)
    ctx->pc = 0x189b34u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x189b38: 0x8c8a0010  lw          $t2, 0x10($a0)
    ctx->pc = 0x189b38u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x189b3c: 0x8c8b0014  lw          $t3, 0x14($a0)
    ctx->pc = 0x189b3cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x189b40: 0x8c8c0018  lw          $t4, 0x18($a0)
    ctx->pc = 0x189b40u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x189b44: 0x8c8d001c  lw          $t5, 0x1C($a0)
    ctx->pc = 0x189b44u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x189b48: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x189b48u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x189b4c: 0xaca30004  sw          $v1, 0x4($a1)
    ctx->pc = 0x189b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
    // 0x189b50: 0xaca80008  sw          $t0, 0x8($a1)
    ctx->pc = 0x189b50u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 8));
    // 0x189b54: 0xaca9000c  sw          $t1, 0xC($a1)
    ctx->pc = 0x189b54u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 9));
    // 0x189b58: 0xacaa0010  sw          $t2, 0x10($a1)
    ctx->pc = 0x189b58u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 10));
    // 0x189b5c: 0xacab0014  sw          $t3, 0x14($a1)
    ctx->pc = 0x189b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 11));
    // 0x189b60: 0xacac0018  sw          $t4, 0x18($a1)
    ctx->pc = 0x189b60u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 12));
    // 0x189b64: 0xacad001c  sw          $t5, 0x1C($a1)
    ctx->pc = 0x189b64u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 13));
    // 0x189b68: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189b68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189b6c: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x189b6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x189b70: 0x14c0ffed  bnez        $a2, . + 4 + (-0x13 << 2)
    ctx->pc = 0x189B70u;
    {
        const bool branch_taken_0x189b70 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189B70u;
            // 0x189b74: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189b70) {
            ctx->pc = 0x189B28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189b28;
        }
    }
    ctx->pc = 0x189B78u;
    // 0x189b78: 0x3e00008  jr          $ra
    ctx->pc = 0x189B78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189B08u: goto label_189b08;
            case 0x189B28u: goto label_189b28;
            case 0x189B80u: goto label_189b80;
            case 0x189BB8u: goto label_189bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189B80u;
label_189b80:
    // 0x189b80: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x189b80u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189b84: 0xdc830008  ld          $v1, 0x8($a0)
    ctx->pc = 0x189b84u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x189b88: 0xdc880010  ld          $t0, 0x10($a0)
    ctx->pc = 0x189b88u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x189b8c: 0xdc890018  ld          $t1, 0x18($a0)
    ctx->pc = 0x189b8cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x189b90: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x189b90u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x189b94: 0xfca30008  sd          $v1, 0x8($a1)
    ctx->pc = 0x189b94u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 3));
    // 0x189b98: 0xfca80010  sd          $t0, 0x10($a1)
    ctx->pc = 0x189b98u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 8));
    // 0x189b9c: 0xfca90018  sd          $t1, 0x18($a1)
    ctx->pc = 0x189b9cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 9));
    // 0x189ba0: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189ba0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189ba4: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x189ba4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x189ba8: 0x14c0fff5  bnez        $a2, . + 4 + (-0xB << 2)
    ctx->pc = 0x189BA8u;
    {
        const bool branch_taken_0x189ba8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189BA8u;
            // 0x189bac: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189ba8) {
            ctx->pc = 0x189B80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189b80;
        }
    }
    ctx->pc = 0x189BB0u;
    // 0x189bb0: 0x3e00008  jr          $ra
    ctx->pc = 0x189BB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189B08u: goto label_189b08;
            case 0x189B28u: goto label_189b28;
            case 0x189B80u: goto label_189b80;
            case 0x189BB8u: goto label_189bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189BB8u;
label_189bb8:
    // 0x189bb8: 0x78820000  lq          $v0, 0x0($a0)
    ctx->pc = 0x189bb8u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189bbc: 0x78830010  lq          $v1, 0x10($a0)
    ctx->pc = 0x189bbcu;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x189bc0: 0x7ca20000  sq          $v0, 0x0($a1)
    ctx->pc = 0x189bc0u;
    WRITE128(ADD32(GPR_U32(ctx, 5), 0), GPR_VEC(ctx, 2));
    // 0x189bc4: 0x7ca30010  sq          $v1, 0x10($a1)
    ctx->pc = 0x189bc4u;
    WRITE128(ADD32(GPR_U32(ctx, 5), 16), GPR_VEC(ctx, 3));
    // 0x189bc8: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189bc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189bcc: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x189bccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x189bd0: 0x14c0fff9  bnez        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x189BD0u;
    {
        const bool branch_taken_0x189bd0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189BD0u;
            // 0x189bd4: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189bd0) {
            ctx->pc = 0x189BB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189bb8;
        }
    }
    ctx->pc = 0x189BD8u;
    // 0x189bd8: 0x3e00008  jr          $ra
    ctx->pc = 0x189BD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189B08u: goto label_189b08;
            case 0x189B28u: goto label_189b28;
            case 0x189B80u: goto label_189b80;
            case 0x189BB8u: goto label_189bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189BE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
