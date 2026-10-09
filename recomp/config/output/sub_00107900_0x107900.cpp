#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00107900
// Address: 0x107900 - 0x107938
void sub_00107900_0x107900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00107900_0x107900");
#endif

    ctx->pc = 0x107900u;

    // 0x107900: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x107900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x107904: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x107904u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107908: 0x3a0182d  daddu       $v1, $sp, $zero
    ctx->pc = 0x107908u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10790c: 0x10c00007  beqz        $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x10790Cu;
    {
        const bool branch_taken_0x10790c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x107910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10790Cu;
            // 0x107910: 0xa5180b  movn        $v1, $a1, $a1 (Delay Slot)
        if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10790c) {
            ctx->pc = 0x10792Cu;
            goto label_10792c;
        }
    }
    ctx->pc = 0x107914u;
    // 0x107914: 0x10e00005  beqz        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x107914u;
    {
        const bool branch_taken_0x107914 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x107918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107914u;
            // 0x107918: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107914) {
            ctx->pc = 0x10792Cu;
            goto label_10792c;
        }
    }
    ctx->pc = 0x10791Cu;
    // 0x10791c: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x10791cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x107920: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x107920u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x107924: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x107924u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x107928: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x107928u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_10792c:
    // 0x10792c: 0x3e00008  jr          $ra
    ctx->pc = 0x10792Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10792Cu;
            // 0x107930: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10792Cu: goto label_10792c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107934u;
    // 0x107934: 0x0  nop
    ctx->pc = 0x107934u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
