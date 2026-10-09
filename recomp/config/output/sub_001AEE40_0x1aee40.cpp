#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AEE40
// Address: 0x1aee40 - 0x1aef00
void sub_001AEE40_0x1aee40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AEE40_0x1aee40");
#endif

    ctx->pc = 0x1aee40u;

    // 0x1aee40: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aee40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aee44: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1aee44u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1aee48: 0x902343ec  lbu         $v1, 0x43EC($at)
    ctx->pc = 0x1aee48u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17388)));
    // 0x1aee4c: 0x28610006  slti        $at, $v1, 0x6
    ctx->pc = 0x1aee4cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x1aee50: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AEE50u;
    {
        const bool branch_taken_0x1aee50 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEE54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEE50u;
            // 0x1aee54: 0x24a543c0  addiu       $a1, $a1, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aee50) {
            ctx->pc = 0x1AEE5Cu;
            goto label_1aee5c;
        }
    }
    ctx->pc = 0x1AEE58u;
    // 0x1aee58: 0xa0a0002c  sb          $zero, 0x2C($a1)
    ctx->pc = 0x1aee58u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 44), (uint8_t)GPR_U32(ctx, 0));
label_1aee5c:
    // 0x1aee5c: 0x90a3002f  lbu         $v1, 0x2F($a1)
    ctx->pc = 0x1aee5cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 47)));
    // 0x1aee60: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x1aee60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1aee64: 0xa0a3002f  sb          $v1, 0x2F($a1)
    ctx->pc = 0x1aee64u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 47), (uint8_t)GPR_U32(ctx, 3));
    // 0x1aee68: 0x90a30005  lbu         $v1, 0x5($a1)
    ctx->pc = 0x1aee68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 5)));
    // 0x1aee6c: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x1aee6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1aee70: 0xa0a30005  sb          $v1, 0x5($a1)
    ctx->pc = 0x1aee70u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 5), (uint8_t)GPR_U32(ctx, 3));
    // 0x1aee74: 0x90a30009  lbu         $v1, 0x9($a1)
    ctx->pc = 0x1aee74u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 9)));
    // 0x1aee78: 0x28610008  slti        $at, $v1, 0x8
    ctx->pc = 0x1aee78u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1aee7c: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AEE7Cu;
    {
        const bool branch_taken_0x1aee7c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEE7Cu;
            // 0x1aee80: 0x24030007  addiu       $v1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aee7c) {
            ctx->pc = 0x1AEE88u;
            goto label_1aee88;
        }
    }
    ctx->pc = 0x1AEE84u;
    // 0x1aee84: 0xa0a30009  sb          $v1, 0x9($a1)
    ctx->pc = 0x1aee84u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 9), (uint8_t)GPR_U32(ctx, 3));
label_1aee88:
    // 0x1aee88: 0x90a3000a  lbu         $v1, 0xA($a1)
    ctx->pc = 0x1aee88u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 10)));
    // 0x1aee8c: 0x28610008  slti        $at, $v1, 0x8
    ctx->pc = 0x1aee8cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1aee90: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AEE90u;
    {
        const bool branch_taken_0x1aee90 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEE94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEE90u;
            // 0x1aee94: 0x24030007  addiu       $v1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aee90) {
            ctx->pc = 0x1AEE9Cu;
            goto label_1aee9c;
        }
    }
    ctx->pc = 0x1AEE98u;
    // 0x1aee98: 0xa0a3000a  sb          $v1, 0xA($a1)
    ctx->pc = 0x1aee98u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 10), (uint8_t)GPR_U32(ctx, 3));
label_1aee9c:
    // 0x1aee9c: 0x80a4002d  lb          $a0, 0x2D($a1)
    ctx->pc = 0x1aee9cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 45)));
    // 0x1aeea0: 0x2883fff6  slti        $v1, $a0, -0xA
    ctx->pc = 0x1aeea0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294967286) ? 1 : 0);
    // 0x1aeea4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AEEA4u;
    {
        const bool branch_taken_0x1aeea4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEEA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEEA4u;
            // 0x1aeea8: 0x2881000b  slti        $at, $a0, 0xB (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)11) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aeea4) {
            ctx->pc = 0x1AEEB4u;
            goto label_1aeeb4;
        }
    }
    ctx->pc = 0x1AEEACu;
    // 0x1aeeac: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AEEACu;
    {
        const bool branch_taken_0x1aeeac = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aeeac) {
            ctx->pc = 0x1AEEB8u;
            goto label_1aeeb8;
        }
    }
    ctx->pc = 0x1AEEB4u;
label_1aeeb4:
    // 0x1aeeb4: 0xa0a0002d  sb          $zero, 0x2D($a1)
    ctx->pc = 0x1aeeb4u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 45), (uint8_t)GPR_U32(ctx, 0));
label_1aeeb8:
    // 0x1aeeb8: 0x80a4002e  lb          $a0, 0x2E($a1)
    ctx->pc = 0x1aeeb8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 46)));
    // 0x1aeebc: 0x2883fff6  slti        $v1, $a0, -0xA
    ctx->pc = 0x1aeebcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294967286) ? 1 : 0);
    // 0x1aeec0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AEEC0u;
    {
        const bool branch_taken_0x1aeec0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEEC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEEC0u;
            // 0x1aeec4: 0x2881000b  slti        $at, $a0, 0xB (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)11) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aeec0) {
            ctx->pc = 0x1AEED0u;
            goto label_1aeed0;
        }
    }
    ctx->pc = 0x1AEEC8u;
    // 0x1aeec8: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AEEC8u;
    {
        const bool branch_taken_0x1aeec8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aeec8) {
            ctx->pc = 0x1AEED4u;
            goto label_1aeed4;
        }
    }
    ctx->pc = 0x1AEED0u;
label_1aeed0:
    // 0x1aeed0: 0xa0a0002e  sb          $zero, 0x2E($a1)
    ctx->pc = 0x1aeed0u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 46), (uint8_t)GPR_U32(ctx, 0));
label_1aeed4:
    // 0x1aeed4: 0x90a40030  lbu         $a0, 0x30($a1)
    ctx->pc = 0x1aeed4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 48)));
    // 0x1aeed8: 0x28830038  slti        $v1, $a0, 0x38
    ctx->pc = 0x1aeed8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)56) ? 1 : 0);
    // 0x1aeedc: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AEEDCu;
    {
        const bool branch_taken_0x1aeedc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEEE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEEDCu;
            // 0x1aeee0: 0x24030080  addiu       $v1, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aeedc) {
            ctx->pc = 0x1AEEF0u;
            goto label_1aeef0;
        }
    }
    ctx->pc = 0x1AEEE4u;
    // 0x1aeee4: 0x288100a5  slti        $at, $a0, 0xA5
    ctx->pc = 0x1aeee4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)165) ? 1 : 0);
    // 0x1aeee8: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AEEE8u;
    {
        const bool branch_taken_0x1aeee8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aeee8) {
            ctx->pc = 0x1AEEF4u;
            goto label_1aeef4;
        }
    }
    ctx->pc = 0x1AEEF0u;
label_1aeef0:
    // 0x1aeef0: 0xa0a30030  sb          $v1, 0x30($a1)
    ctx->pc = 0x1aeef0u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 48), (uint8_t)GPR_U32(ctx, 3));
label_1aeef4:
    // 0x1aeef4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEEF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AEE5Cu: goto label_1aee5c;
            case 0x1AEE88u: goto label_1aee88;
            case 0x1AEE9Cu: goto label_1aee9c;
            case 0x1AEEB4u: goto label_1aeeb4;
            case 0x1AEEB8u: goto label_1aeeb8;
            case 0x1AEED0u: goto label_1aeed0;
            case 0x1AEED4u: goto label_1aeed4;
            case 0x1AEEF0u: goto label_1aeef0;
            case 0x1AEEF4u: goto label_1aeef4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEEFCu;
    // 0x1aeefc: 0x0  nop
    ctx->pc = 0x1aeefcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
