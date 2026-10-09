#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C2260
// Address: 0x1c2260 - 0x1c22c0
void sub_001C2260_0x1c2260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C2260_0x1c2260");
#endif

    switch (ctx->pc) {
        case 0x1c2280u: goto label_1c2280;
        default: break;
    }

    ctx->pc = 0x1c2260u;

    // 0x1c2260: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x1c2260u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c2264: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x1c2264u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1c2268: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2268u;
    {
        const bool branch_taken_0x1c2268 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C226Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2268u;
            // 0x1c226c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2268) {
            ctx->pc = 0x1C2278u;
            goto label_1c2278;
        }
    }
    ctx->pc = 0x1C2270u;
    // 0x1c2270: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C2270u;
    {
        const bool branch_taken_0x1c2270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2270) {
            ctx->pc = 0x1C22B0u;
            goto label_1c22b0;
        }
    }
    ctx->pc = 0x1C2278u;
label_1c2278:
    // 0x1c2278: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1c2278u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1c227c: 0x2402003e  addiu       $v0, $zero, 0x3E
    ctx->pc = 0x1c227cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 62));
label_1c2280:
    // 0x1c2280: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x1c2280u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c2284: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2284u;
    {
        const bool branch_taken_0x1c2284 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C2288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2284u;
            // 0x1c2288: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2284) {
            ctx->pc = 0x1C2294u;
            goto label_1c2294;
        }
    }
    ctx->pc = 0x1C228Cu;
    // 0x1c228c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C228Cu;
    {
        const bool branch_taken_0x1c228c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C228Cu;
            // 0x1c2290: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c228c) {
            ctx->pc = 0x1C22B0u;
            goto label_1c22b0;
        }
    }
    ctx->pc = 0x1C2294u;
label_1c2294:
    // 0x1c2294: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C2294u;
    {
        const bool branch_taken_0x1c2294 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c2294) {
            ctx->pc = 0x1C22A8u;
            goto label_1c22a8;
        }
    }
    ctx->pc = 0x1C229Cu;
    // 0x1c229c: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x1c229cu;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c22a0: 0x1000fff7  b           . + 4 + (-0x9 << 2)
    ctx->pc = 0x1C22A0u;
    {
        const bool branch_taken_0x1c22a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C22A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C22A0u;
            // 0x1c22a4: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c22a0) {
            ctx->pc = 0x1C2280u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c2280;
        }
    }
    ctx->pc = 0x1C22A8u;
label_1c22a8:
    // 0x1c22a8: 0xa0a00000  sb          $zero, 0x0($a1)
    ctx->pc = 0x1c22a8u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c22ac: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1c22acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1c22b0:
    // 0x1c22b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C22B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C2278u: goto label_1c2278;
            case 0x1C2280u: goto label_1c2280;
            case 0x1C2294u: goto label_1c2294;
            case 0x1C22A8u: goto label_1c22a8;
            case 0x1C22B0u: goto label_1c22b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C22B8u;
    // 0x1c22b8: 0x0  nop
    ctx->pc = 0x1c22b8u;
    // NOP
    // 0x1c22bc: 0x0  nop
    ctx->pc = 0x1c22bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
