#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163138
// Address: 0x163138 - 0x1631a0
void sub_00163138_0x163138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163138_0x163138");
#endif

    switch (ctx->pc) {
        case 0x163154u: goto label_163154;
        case 0x163168u: goto label_163168;
        case 0x163184u: goto label_163184;
        default: break;
    }

    ctx->pc = 0x163138u;

    // 0x163138: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x163138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16313c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16313cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163140: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163140u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163144: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163148: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x163148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16314c: 0xc058d10  jal         func_163440
    ctx->pc = 0x16314Cu;
    SET_GPR_U32(ctx, 31, 0x163154u);
    ctx->pc = 0x163150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16314Cu;
            // 0x163150: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163154u; }
        if (ctx->pc != 0x163154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163154u; }
        if (ctx->pc != 0x163154u) { return; }
    }
    ctx->pc = 0x163154u;
label_163154:
    // 0x163154: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x163154u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163158: 0x1443000c  bne         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x163158u;
    {
        const bool branch_taken_0x163158 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x16315Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163158u;
            // 0x16315c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163158) {
            ctx->pc = 0x16318Cu;
            goto label_16318c;
        }
    }
    ctx->pc = 0x163160u;
    // 0x163160: 0xc058d08  jal         func_163420
    ctx->pc = 0x163160u;
    SET_GPR_U32(ctx, 31, 0x163168u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163168u; }
        if (ctx->pc != 0x163168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163168u; }
        if (ctx->pc != 0x163168u) { return; }
    }
    ctx->pc = 0x163168u;
label_163168:
    // 0x163168: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x163168u;
    {
        const bool branch_taken_0x163168 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16316Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163168u;
            // 0x16316c: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163168) {
            ctx->pc = 0x163188u;
            goto label_163188;
        }
    }
    ctx->pc = 0x163170u;
    // 0x163170: 0x8c42002c  lw          $v0, 0x2C($v0)
    ctx->pc = 0x163170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x163174: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x163174u;
    {
        const bool branch_taken_0x163174 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x163174) {
            ctx->pc = 0x163178u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163174u;
            // 0x163178: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16318Cu;
            goto label_16318c;
        }
    }
    ctx->pc = 0x16317Cu;
    // 0x16317c: 0x40f809  jalr        $v0
    ctx->pc = 0x16317Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x163184u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x163184u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163154u: goto label_163154;
            case 0x163168u: goto label_163168;
            case 0x163184u: goto label_163184;
            case 0x163188u: goto label_163188;
            case 0x16318Cu: goto label_16318c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x163184u; }
            if (ctx->pc != 0x163184u) { return; }
        }
        }
    }
    ctx->pc = 0x163184u;
label_163184:
    // 0x163184: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x163184u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_163188:
    // 0x163188: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x163188u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_16318c:
    // 0x16318c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16318cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163190: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163190u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163194: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x163194u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163198: 0x3e00008  jr          $ra
    ctx->pc = 0x163198u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16319Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163198u;
            // 0x16319c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163154u: goto label_163154;
            case 0x163168u: goto label_163168;
            case 0x163184u: goto label_163184;
            case 0x163188u: goto label_163188;
            case 0x16318Cu: goto label_16318c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1631A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
