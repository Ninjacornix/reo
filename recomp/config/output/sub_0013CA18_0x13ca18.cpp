#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CA18
// Address: 0x13ca18 - 0x13caa8
void sub_0013CA18_0x13ca18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CA18_0x13ca18");
#endif

    ctx->pc = 0x13ca18u;

    // 0x13ca18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ca18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ca1c: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x13ca1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ca20: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13CA20u;
    {
        const bool branch_taken_0x13ca20 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CA24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CA20u;
            // 0x13ca24: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ca20) {
            ctx->pc = 0x13CA40u;
            goto label_13ca40;
        }
    }
    ctx->pc = 0x13CA28u;
    // 0x13ca28: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ca28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ca2c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ca2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13ca30: 0xa040dea8  sb          $zero, -0x2158($v0)
    ctx->pc = 0x13ca30u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 4294958760), (uint8_t)GPR_U32(ctx, 0));
    // 0x13ca34: 0x3e00008  jr          $ra
    ctx->pc = 0x13CA34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CA38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CA34u;
            // 0x13ca38: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CA40u: goto label_13ca40;
            case 0x13CA80u: goto label_13ca80;
            case 0x13CA8Cu: goto label_13ca8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CA3Cu;
    // 0x13ca3c: 0x0  nop
    ctx->pc = 0x13ca3cu;
    // NOP
label_13ca40:
    // 0x13ca40: 0x80840000  lb          $a0, 0x0($a0)
    ctx->pc = 0x13ca40u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ca44: 0x2402002f  addiu       $v0, $zero, 0x2F
    ctx->pc = 0x13ca44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x13ca48: 0x1082000d  beq         $a0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13CA48u;
    {
        const bool branch_taken_0x13ca48 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x13CA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CA48u;
            // 0x13ca4c: 0x2402005c  addiu       $v0, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ca48) {
            ctx->pc = 0x13CA80u;
            goto label_13ca80;
        }
    }
    ctx->pc = 0x13CA50u;
    // 0x13ca50: 0x1082000b  beq         $a0, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x13CA50u;
    {
        const bool branch_taken_0x13ca50 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x13CA54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CA50u;
            // 0x13ca54: 0x3c040022  lui         $a0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ca50) {
            ctx->pc = 0x13CA80u;
            goto label_13ca80;
        }
    }
    ctx->pc = 0x13CA58u;
    // 0x13ca58: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x13ca58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x13ca5c: 0x2448d150  addiu       $t0, $v0, -0x2EB0
    ctx->pc = 0x13ca5cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955344));
    // 0x13ca60: 0x2487dea8  addiu       $a3, $a0, -0x2158
    ctx->pc = 0x13ca60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4294958760));
    // 0x13ca64: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x13ca64u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x13ca68: 0x81060001  lb          $a2, 0x1($t0)
    ctx->pc = 0x13ca68u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x13ca6c: 0xa0e30000  sb          $v1, 0x0($a3)
    ctx->pc = 0x13ca6cu;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x13ca70: 0xa0e60001  sb          $a2, 0x1($a3)
    ctx->pc = 0x13ca70u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 1), (uint8_t)GPR_U32(ctx, 6));
    // 0x13ca74: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x13CA74u;
    {
        const bool branch_taken_0x13ca74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CA78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CA74u;
            // 0x13ca78: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ca74) {
            ctx->pc = 0x13CA8Cu;
            goto label_13ca8c;
        }
    }
    ctx->pc = 0x13CA7Cu;
    // 0x13ca7c: 0x0  nop
    ctx->pc = 0x13ca7cu;
    // NOP
label_13ca80:
    // 0x13ca80: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13ca80u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13ca84: 0xa080dea8  sb          $zero, -0x2158($a0)
    ctx->pc = 0x13ca84u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 4294958760), (uint8_t)GPR_U32(ctx, 0));
    // 0x13ca88: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ca88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13ca8c:
    // 0x13ca8c: 0x2484dea8  addiu       $a0, $a0, -0x2158
    ctx->pc = 0x13ca8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294958760));
    // 0x13ca90: 0x8042bf0  j           func_10AFC0
    ctx->pc = 0x13CA90u;
    ctx->pc = 0x13CA94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CA90u;
            // 0x13ca94: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13CA98u;
    // 0x13ca98: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ca98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13ca9c: 0x3e00008  jr          $ra
    ctx->pc = 0x13CA9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CAA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CA9Cu;
            // 0x13caa0: 0x2442dea8  addiu       $v0, $v0, -0x2158 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958760));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CA40u: goto label_13ca40;
            case 0x13CA80u: goto label_13ca80;
            case 0x13CA8Cu: goto label_13ca8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CAA4u;
    // 0x13caa4: 0x0  nop
    ctx->pc = 0x13caa4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
