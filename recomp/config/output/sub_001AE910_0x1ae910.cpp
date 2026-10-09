#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE910
// Address: 0x1ae910 - 0x1ae99c
void sub_001AE910_0x1ae910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE910_0x1ae910");
#endif

    switch (ctx->pc) {
        case 0x1ae928u: goto label_1ae928;
        case 0x1ae98cu: goto label_1ae98c;
        default: break;
    }

    ctx->pc = 0x1ae910u;

    // 0x1ae910: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ae910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ae914: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ae914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ae918: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae918u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae91c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1ae91cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae920: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AE920u;
    SET_GPR_U32(ctx, 31, 0x1AE928u);
    ctx->pc = 0x1AE924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE920u;
            // 0x1ae924: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE928u; }
        if (ctx->pc != 0x1AE928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE928u; }
        if (ctx->pc != 0x1AE928u) { return; }
    }
    ctx->pc = 0x1AE928u;
label_1ae928:
    // 0x1ae928: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE928u;
    {
        const bool branch_taken_0x1ae928 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae928) {
            ctx->pc = 0x1AE938u;
            goto label_1ae938;
        }
    }
    ctx->pc = 0x1AE930u;
    // 0x1ae930: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1AE930u;
    {
        const bool branch_taken_0x1ae930 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE930u;
            // 0x1ae934: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae930) {
            ctx->pc = 0x1AE98Cu;
            goto label_1ae98c;
        }
    }
    ctx->pc = 0x1AE938u;
label_1ae938:
    // 0x1ae938: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae938u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae93c: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1ae93cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ae940: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae944: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae944u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae948: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1ae948u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae94c: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE94Cu;
    {
        const bool branch_taken_0x1ae94c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE94Cu;
            // 0x1ae950: 0x101840  sll         $v1, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae94c) {
            ctx->pc = 0x1AE95Cu;
            goto label_1ae95c;
        }
    }
    ctx->pc = 0x1AE954u;
    // 0x1ae954: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1AE954u;
    {
        const bool branch_taken_0x1ae954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE954u;
            // 0x1ae958: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae954) {
            ctx->pc = 0x1AE98Cu;
            goto label_1ae98c;
        }
    }
    ctx->pc = 0x1AE95Cu;
label_1ae95c:
    // 0x1ae95c: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae95cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae960: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1ae960u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1ae964: 0x24428d73  addiu       $v0, $v0, -0x728D
    ctx->pc = 0x1ae964u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937971));
    // 0x1ae968: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1ae968u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae96c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae96cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae970: 0x80420000  lb          $v0, 0x0($v0)
    ctx->pc = 0x1ae970u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae974: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE974u;
    {
        const bool branch_taken_0x1ae974 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE974u;
            // 0x1ae978: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae974) {
            ctx->pc = 0x1AE984u;
            goto label_1ae984;
        }
    }
    ctx->pc = 0x1AE97Cu;
    // 0x1ae97c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE97Cu;
    {
        const bool branch_taken_0x1ae97c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae97c) {
            ctx->pc = 0x1AE98Cu;
            goto label_1ae98c;
        }
    }
    ctx->pc = 0x1AE984u;
label_1ae984:
    // 0x1ae984: 0xc04cb88  jal         func_132E20
    ctx->pc = 0x1AE984u;
    SET_GPR_U32(ctx, 31, 0x1AE98Cu);
    ctx->pc = 0x132E20u;
    if (runtime->hasFunction(0x132E20u)) {
        auto targetFn = runtime->lookupFunction(0x132E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE98Cu; }
        if (ctx->pc != 0x1AE98Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E20_0x132e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE98Cu; }
        if (ctx->pc != 0x1AE98Cu) { return; }
    }
    ctx->pc = 0x1AE98Cu;
label_1ae98c:
    // 0x1ae98c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ae98cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae990: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae990u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae994: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE994u;
            // 0x1ae998: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE928u: goto label_1ae928;
            case 0x1AE938u: goto label_1ae938;
            case 0x1AE95Cu: goto label_1ae95c;
            case 0x1AE984u: goto label_1ae984;
            case 0x1AE98Cu: goto label_1ae98c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE99Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
