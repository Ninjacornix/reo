#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161948
// Address: 0x161948 - 0x161978
void sub_00161948_0x161948(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161948_0x161948");
#endif

    switch (ctx->pc) {
        case 0x16196cu: goto label_16196c;
        default: break;
    }

    ctx->pc = 0x161948u;

    // 0x161948: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161948u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16194c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16194cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x161950: 0x8c8200e8  lw          $v0, 0xE8($a0)
    ctx->pc = 0x161950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 232)));
    // 0x161954: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x161954u;
    {
        const bool branch_taken_0x161954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x161958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161954u;
            // 0x161958: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161954) {
            ctx->pc = 0x16196Cu;
            goto label_16196c;
        }
    }
    ctx->pc = 0x16195Cu;
    // 0x16195c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x16195cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x161960: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x161960u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x161964: 0x60f809  jalr        $v1
    ctx->pc = 0x161964u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x16196Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x16196Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16196Cu: goto label_16196c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16196Cu; }
            if (ctx->pc != 0x16196Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16196Cu;
label_16196c:
    // 0x16196c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16196cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161970: 0x3e00008  jr          $ra
    ctx->pc = 0x161970u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161970u;
            // 0x161974: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16196Cu: goto label_16196c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161978u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
