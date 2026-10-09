#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F05B4
// Address: 0x1f05b4 - 0x1f0634
void sub_001F05B4_0x1f05b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F05B4_0x1f05b4");
#endif

    switch (ctx->pc) {
        case 0x1f05e0u: goto label_1f05e0;
        case 0x1f0614u: goto label_1f0614;
        default: break;
    }

    ctx->pc = 0x1f05b4u;

    // 0x1f05b4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f05b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f05b8: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f05b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f05bc: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f05bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f05c0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f05c0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f05c4: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f05c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f05c8: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f05c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f05cc: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f05ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f05d0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f05d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f05d4: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f05d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f05d8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f05d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f05dc: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f05dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_1f05e0:
    // 0x1f05e0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f05e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f05e4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F05E4u;
    {
        const bool branch_taken_0x1f05e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f05e4) {
            ctx->pc = 0x1F05F4u;
            goto label_1f05f4;
        }
    }
    ctx->pc = 0x1F05ECu;
    // 0x1f05ec: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1F05ECu;
    {
        const bool branch_taken_0x1f05ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f05ec) {
            ctx->pc = 0x1F061Cu;
            goto label_1f061c;
        }
    }
    ctx->pc = 0x1F05F4u;
label_1f05f4:
    // 0x1f05f4: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1f05f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1f05f8: 0x27c3000c  addiu       $v1, $fp, 0xC
    ctx->pc = 0x1f05f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1f05fc: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f05fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0600: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0600u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0604: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1f0604u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0608: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1f0608u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f060c: 0xc07ae0c  jal         func_1EB830
    ctx->pc = 0x1F060Cu;
    SET_GPR_U32(ctx, 31, 0x1F0614u);
    ctx->pc = 0x1EB830u;
    if (runtime->hasFunction(0x1EB830u)) {
        auto targetFn = runtime->lookupFunction(0x1EB830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0614u; }
        if (ctx->pc != 0x1F0614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB830_0x1eb830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0614u; }
        if (ctx->pc != 0x1F0614u) { return; }
    }
    ctx->pc = 0x1F0614u;
label_1f0614:
    // 0x1f0614: 0x1000fff2  b           . + 4 + (-0xE << 2)
    ctx->pc = 0x1F0614u;
    {
        const bool branch_taken_0x1f0614 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f0614) {
            ctx->pc = 0x1F05E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f05e0;
        }
    }
    ctx->pc = 0x1F061Cu;
label_1f061c:
    // 0x1f061c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f061cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0620: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f0620u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f0624: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f0624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f0628: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f0628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f062c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F062Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F05E0u: goto label_1f05e0;
            case 0x1F05F4u: goto label_1f05f4;
            case 0x1F0614u: goto label_1f0614;
            case 0x1F061Cu: goto label_1f061c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F0634u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
