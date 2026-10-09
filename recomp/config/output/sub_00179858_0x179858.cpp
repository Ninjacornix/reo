#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179858
// Address: 0x179858 - 0x1798a0
void sub_00179858_0x179858(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179858_0x179858");
#endif

    switch (ctx->pc) {
        case 0x179878u: goto label_179878;
        default: break;
    }

    ctx->pc = 0x179858u;

    // 0x179858: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17985c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17985cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179860: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179864: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x179864u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179868: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17986c: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x17986cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179870: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179870u;
    SET_GPR_U32(ctx, 31, 0x179878u);
    ctx->pc = 0x179874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179870u;
            // 0x179874: 0x24500080  addiu       $s0, $v0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179878u; }
        if (ctx->pc != 0x179878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179878u; }
        if (ctx->pc != 0x179878u) { return; }
    }
    ctx->pc = 0x179878u;
label_179878:
    // 0x179878: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179878u;
    {
        const bool branch_taken_0x179878 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179878) {
            ctx->pc = 0x17987Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179878u;
            // 0x17987c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179890u;
            goto label_179890;
        }
    }
    ctx->pc = 0x179880u;
    // 0x179880: 0x92030004  lbu         $v1, 0x4($s0)
    ctx->pc = 0x179880u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x179884: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179884u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179888: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179888u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x17988c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17988cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179890:
    // 0x179890: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179890u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179894: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179894u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179898: 0x3e00008  jr          $ra
    ctx->pc = 0x179898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17989Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179898u;
            // 0x17989c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179878u: goto label_179878;
            case 0x179890u: goto label_179890;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1798A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
