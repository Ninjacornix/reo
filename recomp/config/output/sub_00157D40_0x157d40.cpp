#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00157D40
// Address: 0x157d40 - 0x157dc0
void sub_00157D40_0x157d40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00157D40_0x157d40");
#endif

    ctx->pc = 0x157d40u;

    // 0x157d40: 0x90860000  lbu         $a2, 0x0($a0)
    ctx->pc = 0x157d40u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x157d44: 0x90820001  lbu         $v0, 0x1($a0)
    ctx->pc = 0x157d44u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x157d48: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x157d48u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x157d4c: 0x90830002  lbu         $v1, 0x2($a0)
    ctx->pc = 0x157d4cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x157d50: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x157d50u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x157d54: 0x90850003  lbu         $a1, 0x3($a0)
    ctx->pc = 0x157d54u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x157d58: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x157d58u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x157d5c: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x157d5cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x157d60: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x157d60u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x157d64: 0xc53025  or          $a2, $a2, $a1
    ctx->pc = 0x157d64u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x157d68: 0x24c3fe47  addiu       $v1, $a2, -0x1B9
    ctx->pc = 0x157d68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294966855));
    // 0x157d6c: 0x2c620007  sltiu       $v0, $v1, 0x7
    ctx->pc = 0x157d6cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)7) ? 1 : 0);
    // 0x157d70: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x157D70u;
    {
        const bool branch_taken_0x157d70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x157D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157D70u;
            // 0x157d74: 0x24c2fe40  addiu       $v0, $a2, -0x1C0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294966848));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157d70) {
            ctx->pc = 0x157DB4u;
            goto label_157db4;
        }
    }
    ctx->pc = 0x157D78u;
    // 0x157d78: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x157d78u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x157d7c: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x157d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x157d80: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x157d80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x157d84: 0x8c63e550  lw          $v1, -0x1AB0($v1)
    ctx->pc = 0x157d84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294960464)));
    // 0x157d88: 0x600008  jr          $v1
    ctx->pc = 0x157D88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157D90u: goto label_157d90;
            case 0x157D98u: goto label_157d98;
            case 0x157DA0u: goto label_157da0;
            case 0x157DA8u: goto label_157da8;
            case 0x157DB0u: goto label_157db0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157D90u;
label_157d90:
    // 0x157d90: 0x3e00008  jr          $ra
    ctx->pc = 0x157D90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x157D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157D90u;
            // 0x157d94: 0x3c020001  lui         $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157D90u: goto label_157d90;
            case 0x157D98u: goto label_157d98;
            case 0x157DA0u: goto label_157da0;
            case 0x157DA8u: goto label_157da8;
            case 0x157DB0u: goto label_157db0;
            case 0x157DB4u: goto label_157db4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157D98u;
label_157d98:
    // 0x157d98: 0x3e00008  jr          $ra
    ctx->pc = 0x157D98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x157D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157D98u;
            // 0x157d9c: 0x3c020002  lui         $v0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157D90u: goto label_157d90;
            case 0x157D98u: goto label_157d98;
            case 0x157DA0u: goto label_157da0;
            case 0x157DA8u: goto label_157da8;
            case 0x157DB0u: goto label_157db0;
            case 0x157DB4u: goto label_157db4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157DA0u;
label_157da0:
    // 0x157da0: 0x3e00008  jr          $ra
    ctx->pc = 0x157DA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x157DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157DA0u;
            // 0x157da4: 0x3c020008  lui         $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157D90u: goto label_157d90;
            case 0x157D98u: goto label_157d98;
            case 0x157DA0u: goto label_157da0;
            case 0x157DA8u: goto label_157da8;
            case 0x157DB0u: goto label_157db0;
            case 0x157DB4u: goto label_157db4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157DA8u;
label_157da8:
    // 0x157da8: 0x3e00008  jr          $ra
    ctx->pc = 0x157DA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x157DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157DA8u;
            // 0x157dac: 0x3c020004  lui         $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157D90u: goto label_157d90;
            case 0x157D98u: goto label_157d98;
            case 0x157DA0u: goto label_157da0;
            case 0x157DA8u: goto label_157da8;
            case 0x157DB0u: goto label_157db0;
            case 0x157DB4u: goto label_157db4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157DB0u;
label_157db0:
    // 0x157db0: 0x24c2fe40  addiu       $v0, $a2, -0x1C0
    ctx->pc = 0x157db0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294966848));
label_157db4:
    // 0x157db4: 0x2c420030  sltiu       $v0, $v0, 0x30
    ctx->pc = 0x157db4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)48) ? 1 : 0);
    // 0x157db8: 0x3e00008  jr          $ra
    ctx->pc = 0x157DB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x157DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157DB8u;
            // 0x157dbc: 0x21480  sll         $v0, $v0, 18 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 18));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157D90u: goto label_157d90;
            case 0x157D98u: goto label_157d98;
            case 0x157DA0u: goto label_157da0;
            case 0x157DA8u: goto label_157da8;
            case 0x157DB0u: goto label_157db0;
            case 0x157DB4u: goto label_157db4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157DC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
