#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BD910
// Address: 0x1bd910 - 0x1bd978
void sub_001BD910_0x1bd910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BD910_0x1bd910");
#endif

    switch (ctx->pc) {
        case 0x1bd958u: goto label_1bd958;
        default: break;
    }

    ctx->pc = 0x1bd910u;

    // 0x1bd910: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1bd910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1bd914: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd914u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd918: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1bd918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1bd91c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bd91cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bd920: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bd920u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bd924: 0x8c3044f0  lw          $s0, 0x44F0($at)
    ctx->pc = 0x1bd924u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17648)));
    // 0x1bd928: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD928u;
    {
        const bool branch_taken_0x1bd928 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BD92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD928u;
            // 0x1bd92c: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd928) {
            ctx->pc = 0x1BD938u;
            goto label_1bd938;
        }
    }
    ctx->pc = 0x1BD930u;
    // 0x1bd930: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1BD930u;
    {
        const bool branch_taken_0x1bd930 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD930u;
            // 0x1bd934: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd930) {
            ctx->pc = 0x1BD964u;
            goto label_1bd964;
        }
    }
    ctx->pc = 0x1BD938u;
label_1bd938:
    // 0x1bd938: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1bd938u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bd93c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1bd93cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1bd940: 0x24425020  addiu       $v0, $v0, 0x5020
    ctx->pc = 0x1bd940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20512));
    // 0x1bd944: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bd944u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bd948: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bd948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bd94c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1bd94cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bd950: 0x40f809  jalr        $v0
    ctx->pc = 0x1BD950u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1BD958u);
        ctx->pc = 0x1BD954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD950u;
            // 0x1bd954: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1BD958u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD938u: goto label_1bd938;
            case 0x1BD958u: goto label_1bd958;
            case 0x1BD964u: goto label_1bd964;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1BD958u; }
            if (ctx->pc != 0x1BD958u) { return; }
        }
        }
    }
    ctx->pc = 0x1BD958u;
label_1bd958:
    // 0x1bd958: 0xc6000038  lwc1        $f0, 0x38($s0)
    ctx->pc = 0x1bd958u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1bd95c: 0xe6200000  swc1        $f0, 0x0($s1)
    ctx->pc = 0x1bd95cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x1bd960: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1bd960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_1bd964:
    // 0x1bd964: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1bd964u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bd968: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bd968u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bd96c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bd96cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd970: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD970u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD970u;
            // 0x1bd974: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD938u: goto label_1bd938;
            case 0x1BD958u: goto label_1bd958;
            case 0x1BD964u: goto label_1bd964;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD978u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
