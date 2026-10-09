#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160E98
// Address: 0x160e98 - 0x160f08
void sub_00160E98_0x160e98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160E98_0x160e98");
#endif

    switch (ctx->pc) {
        case 0x160ef0u: goto label_160ef0;
        default: break;
    }

    ctx->pc = 0x160e98u;

    // 0x160e98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160e9c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x160e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x160ea0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x160ea0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160ea4: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x160ea4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160ea8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x160ea8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x160eac: 0x8c83008c  lw          $v1, 0x8C($a0)
    ctx->pc = 0x160eacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x160eb0: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x160EB0u;
    {
        const bool branch_taken_0x160eb0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x160EB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160EB0u;
            // 0x160eb4: 0x2c640003  sltiu       $a0, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x160eb0) {
            ctx->pc = 0x160EE0u;
            goto label_160ee0;
        }
    }
    ctx->pc = 0x160EB8u;
    // 0x160eb8: 0x50800005  beql        $a0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x160EB8u;
    {
        const bool branch_taken_0x160eb8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x160eb8) {
            ctx->pc = 0x160EBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x160EB8u;
            // 0x160ebc: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x160ED0u;
            goto label_160ed0;
        }
    }
    ctx->pc = 0x160EC0u;
    // 0x160ec0: 0x1070000c  beq         $v1, $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x160EC0u;
    {
        const bool branch_taken_0x160ec0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 16));
        ctx->pc = 0x160EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160EC0u;
            // 0x160ec4: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160ec0) {
            ctx->pc = 0x160EF4u;
            goto label_160ef4;
        }
    }
    ctx->pc = 0x160EC8u;
    // 0x160ec8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x160EC8u;
    {
        const bool branch_taken_0x160ec8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160EC8u;
            // 0x160ecc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160ec8) {
            ctx->pc = 0x160EE8u;
            goto label_160ee8;
        }
    }
    ctx->pc = 0x160ED0u;
label_160ed0:
    // 0x160ed0: 0x50620007  beql        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x160ED0u;
    {
        const bool branch_taken_0x160ed0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x160ed0) {
            ctx->pc = 0x160ED4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x160ED0u;
            // 0x160ed4: 0x24100003  addiu       $s0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x160EF0u;
            goto label_160ef0;
        }
    }
    ctx->pc = 0x160ED8u;
    // 0x160ed8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x160ED8u;
    {
        const bool branch_taken_0x160ed8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160ED8u;
            // 0x160edc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160ed8) {
            ctx->pc = 0x160EE8u;
            goto label_160ee8;
        }
    }
    ctx->pc = 0x160EE0u;
label_160ee0:
    // 0x160ee0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x160EE0u;
    {
        const bool branch_taken_0x160ee0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160EE0u;
            // 0x160ee4: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160ee0) {
            ctx->pc = 0x160EF0u;
            goto label_160ef0;
        }
    }
    ctx->pc = 0x160EE8u;
label_160ee8:
    // 0x160ee8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160EE8u;
    SET_GPR_U32(ctx, 31, 0x160EF0u);
    ctx->pc = 0x160EECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160EE8u;
            // 0x160eec: 0x2484f8f8  addiu       $a0, $a0, -0x708 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965496));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160EF0u; }
        if (ctx->pc != 0x160EF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160EF0u; }
        if (ctx->pc != 0x160EF0u) { return; }
    }
    ctx->pc = 0x160EF0u;
label_160ef0:
    // 0x160ef0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x160ef0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_160ef4:
    // 0x160ef4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160ef4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160ef8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x160ef8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160efc: 0x3e00008  jr          $ra
    ctx->pc = 0x160EFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160F00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160EFCu;
            // 0x160f00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160ED0u: goto label_160ed0;
            case 0x160EE0u: goto label_160ee0;
            case 0x160EE8u: goto label_160ee8;
            case 0x160EF0u: goto label_160ef0;
            case 0x160EF4u: goto label_160ef4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160F04u;
    // 0x160f04: 0x0  nop
    ctx->pc = 0x160f04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
