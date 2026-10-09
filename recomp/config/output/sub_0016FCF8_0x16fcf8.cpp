#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016FCF8
// Address: 0x16fcf8 - 0x16fd34
void sub_0016FCF8_0x16fcf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016FCF8_0x16fcf8");
#endif

    ctx->pc = 0x16fcf8u;

    // 0x16fcf8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16fcf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16fcfc: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x16fcfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16fd00: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16fd00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16fd04: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16FD04u;
    {
        const bool branch_taken_0x16fd04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16FD08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FD04u;
            // 0x16fd08: 0x2c43ffff  sltiu       $v1, $v0, -0x1 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)4294967295) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16fd04) {
            ctx->pc = 0x16FD28u;
            goto label_16fd28;
        }
    }
    ctx->pc = 0x16FD0Cu;
    // 0x16fd0c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16FD0Cu;
    {
        const bool branch_taken_0x16fd0c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16FD10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FD0Cu;
            // 0x16fd10: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16fd0c) {
            ctx->pc = 0x16FD20u;
            goto label_16fd20;
        }
    }
    ctx->pc = 0x16FD14u;
    // 0x16fd14: 0x2c42fffd  sltiu       $v0, $v0, -0x3
    ctx->pc = 0x16fd14u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)4294967293) ? 1 : 0);
    // 0x16fd18: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16FD18u;
    {
        const bool branch_taken_0x16fd18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16fd18) {
            ctx->pc = 0x16FD2Cu;
            goto label_16fd2c;
        }
    }
    ctx->pc = 0x16FD20u;
label_16fd20:
    // 0x16fd20: 0x805a704  j           func_169C10
    ctx->pc = 0x16FD20u;
    ctx->pc = 0x16FD24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16FD20u;
            // 0x16fd24: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16FD28u;
label_16fd28:
    // 0x16fd28: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16fd28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16fd2c:
    // 0x16fd2c: 0x3e00008  jr          $ra
    ctx->pc = 0x16FD2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16FD30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FD2Cu;
            // 0x16fd30: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16FD20u: goto label_16fd20;
            case 0x16FD28u: goto label_16fd28;
            case 0x16FD2Cu: goto label_16fd2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16FD34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
