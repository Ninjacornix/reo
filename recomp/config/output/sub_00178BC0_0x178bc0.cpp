#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178BC0
// Address: 0x178bc0 - 0x178c38
void sub_00178BC0_0x178bc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178BC0_0x178bc0");
#endif

    switch (ctx->pc) {
        case 0x178bf0u: goto label_178bf0;
        case 0x178bf8u: goto label_178bf8;
        case 0x178c14u: goto label_178c14;
        default: break;
    }

    ctx->pc = 0x178bc0u;

    // 0x178bc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x178bc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x178bc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x178bc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178bc8: 0x24b00004  addiu       $s0, $a1, 0x4
    ctx->pc = 0x178bc8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x178bcc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x178bccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x178bd0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x178bd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178bd4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x178bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x178bd8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x178bd8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178bdc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x178bdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x178be0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x178be0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178be4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x178be4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x178be8: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x178be8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x178bec: 0x0  nop
    ctx->pc = 0x178becu;
    // NOP
label_178bf0:
    // 0x178bf0: 0xc05e30e  jal         func_178C38
    ctx->pc = 0x178BF0u;
    SET_GPR_U32(ctx, 31, 0x178BF8u);
    ctx->pc = 0x178BF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178BF0u;
            // 0x178bf4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178C38u;
    if (runtime->hasFunction(0x178C38u)) {
        auto targetFn = runtime->lookupFunction(0x178C38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178BF8u; }
        if (ctx->pc != 0x178BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178C38_0x178c38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178BF8u; }
        if (ctx->pc != 0x178BF8u) { return; }
    }
    ctx->pc = 0x178BF8u;
label_178bf8:
    // 0x178bf8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x178bf8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178bfc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x178bfcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178c00: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x178c00u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x178c04: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x178c04u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178c08: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x178c08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x178c0c: 0xc059bc6  jal         func_166F18
    ctx->pc = 0x178C0Cu;
    SET_GPR_U32(ctx, 31, 0x178C14u);
    ctx->pc = 0x178C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178C0Cu;
            // 0x178c10: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166F18u;
    if (runtime->hasFunction(0x166F18u)) {
        auto targetFn = runtime->lookupFunction(0x166F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178C14u; }
        if (ctx->pc != 0x178C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166F18_0x166f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178C14u; }
        if (ctx->pc != 0x178C14u) { return; }
    }
    ctx->pc = 0x178C14u;
label_178c14:
    // 0x178c14: 0x2a220003  slti        $v0, $s1, 0x3
    ctx->pc = 0x178c14u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x178c18: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x178C18u;
    {
        const bool branch_taken_0x178c18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x178C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178C18u;
            // 0x178c1c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178c18) {
            ctx->pc = 0x178BF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_178bf0;
        }
    }
    ctx->pc = 0x178C20u;
    // 0x178c20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178c20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178c24: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178c24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178c28: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x178c28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178c2c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x178c2cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x178c30: 0x3e00008  jr          $ra
    ctx->pc = 0x178C30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178C30u;
            // 0x178c34: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178BF0u: goto label_178bf0;
            case 0x178BF8u: goto label_178bf8;
            case 0x178C14u: goto label_178c14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178C38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
