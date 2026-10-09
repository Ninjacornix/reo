#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD030
// Address: 0x1cd030 - 0x1cd080
void sub_001CD030_0x1cd030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD030_0x1cd030");
#endif

    ctx->pc = 0x1cd030u;

    // 0x1cd030: 0x28822100  slti        $v0, $a0, 0x2100
    ctx->pc = 0x1cd030u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8448) ? 1 : 0);
    // 0x1cd034: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1CD034u;
    {
        const bool branch_taken_0x1cd034 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD034u;
            // 0x1cd038: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd034) {
            ctx->pc = 0x1CD070u;
            goto label_1cd070;
        }
    }
    ctx->pc = 0x1CD03Cu;
    // 0x1cd03c: 0x28812400  slti        $at, $a0, 0x2400
    ctx->pc = 0x1cd03cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9216) ? 1 : 0);
    // 0x1cd040: 0x1020000a  beqz        $at, . + 4 + (0xA << 2)
    ctx->pc = 0x1CD040u;
    {
        const bool branch_taken_0x1cd040 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD040u;
            // 0x1cd044: 0x3c010057  lui         $at, 0x57 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd040) {
            ctx->pc = 0x1CD06Cu;
            goto label_1cd06c;
        }
    }
    ctx->pc = 0x1CD048u;
    // 0x1cd048: 0x902597b8  lbu         $a1, -0x6848($at)
    ctx->pc = 0x1cd048u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1cd04c: 0x51840  sll         $v1, $a1, 1
    ctx->pc = 0x1cd04cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1cd050: 0x511c0  sll         $v0, $a1, 7
    ctx->pc = 0x1cd050u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 7));
    // 0x1cd054: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1cd054u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1cd058: 0x24421800  addiu       $v0, $v0, 0x1800
    ctx->pc = 0x1cd058u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 6144));
    // 0x1cd05c: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1cd05cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1cd060: 0x24632100  addiu       $v1, $v1, 0x2100
    ctx->pc = 0x1cd060u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8448));
    // 0x1cd064: 0x832023  subu        $a0, $a0, $v1
    ctx->pc = 0x1cd064u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1cd068: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1cd068u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1cd06c:
    // 0x1cd06c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1cd06cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1cd070:
    // 0x1cd070: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD06Cu: goto label_1cd06c;
            case 0x1CD070u: goto label_1cd070;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD078u;
    // 0x1cd078: 0x0  nop
    ctx->pc = 0x1cd078u;
    // NOP
    // 0x1cd07c: 0x0  nop
    ctx->pc = 0x1cd07cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
