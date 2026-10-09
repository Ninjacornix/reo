#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178E58
// Address: 0x178e58 - 0x178ed8
void sub_00178E58_0x178e58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178E58_0x178e58");
#endif

    switch (ctx->pc) {
        case 0x178e78u: goto label_178e78;
        case 0x178e88u: goto label_178e88;
        case 0x178e98u: goto label_178e98;
        default: break;
    }

    ctx->pc = 0x178e58u;

    // 0x178e58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x178e58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x178e5c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x178e5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x178e60: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x178e60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178e64: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x178e64u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178e68: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x178e68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x178e6c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x178e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x178e70: 0xc05df12  jal         func_177C48
    ctx->pc = 0x178E70u;
    SET_GPR_U32(ctx, 31, 0x178E78u);
    ctx->pc = 0x178E74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178E70u;
            // 0x178e74: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C48u;
    if (runtime->hasFunction(0x177C48u)) {
        auto targetFn = runtime->lookupFunction(0x177C48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E78u; }
        if (ctx->pc != 0x178E78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C48_0x177c48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E78u; }
        if (ctx->pc != 0x178E78u) { return; }
    }
    ctx->pc = 0x178E78u;
label_178e78:
    // 0x178e78: 0x10510011  beq         $v0, $s1, . + 4 + (0x11 << 2)
    ctx->pc = 0x178E78u;
    {
        const bool branch_taken_0x178e78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x178E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178E78u;
            // 0x178e7c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178e78) {
            ctx->pc = 0x178EC0u;
            goto label_178ec0;
        }
    }
    ctx->pc = 0x178E80u;
    // 0x178e80: 0xc059f30  jal         func_167CC0
    ctx->pc = 0x178E80u;
    SET_GPR_U32(ctx, 31, 0x178E88u);
    ctx->pc = 0x178E84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178E80u;
            // 0x178e84: 0x8e051c48  lw          $a1, 0x1C48($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CC0u;
    if (runtime->hasFunction(0x167CC0u)) {
        auto targetFn = runtime->lookupFunction(0x167CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E88u; }
        if (ctx->pc != 0x178E88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CC0_0x167cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E88u; }
        if (ctx->pc != 0x178E88u) { return; }
    }
    ctx->pc = 0x178E88u;
label_178e88:
    // 0x178e88: 0x1451000d  bne         $v0, $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x178E88u;
    {
        const bool branch_taken_0x178e88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x178E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178E88u;
            // 0x178e8c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178e88) {
            ctx->pc = 0x178EC0u;
            goto label_178ec0;
        }
    }
    ctx->pc = 0x178E90u;
    // 0x178e90: 0xc05e3b6  jal         func_178ED8
    ctx->pc = 0x178E90u;
    SET_GPR_U32(ctx, 31, 0x178E98u);
    ctx->pc = 0x178ED8u;
    if (runtime->hasFunction(0x178ED8u)) {
        auto targetFn = runtime->lookupFunction(0x178ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E98u; }
        if (ctx->pc != 0x178E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178ED8_0x178ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E98u; }
        if (ctx->pc != 0x178E98u) { return; }
    }
    ctx->pc = 0x178E98u;
label_178e98:
    // 0x178e98: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x178E98u;
    {
        const bool branch_taken_0x178e98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178E9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178E98u;
            // 0x178e9c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178e98) {
            ctx->pc = 0x178EC0u;
            goto label_178ec0;
        }
    }
    ctx->pc = 0x178EA0u;
    // 0x178ea0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178ea0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178ea4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178ea4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178ea8: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x178ea8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x178eac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x178eacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178eb0: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x178eb0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x178eb4: 0x805df0c  j           func_177C30
    ctx->pc = 0x178EB4u;
    ctx->pc = 0x178EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178EB4u;
            // 0x178eb8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C30u;
    if (runtime->hasFunction(0x177C30u)) {
        auto targetFn = runtime->lookupFunction(0x177C30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177C30_0x177c30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178EBCu;
    // 0x178ebc: 0x0  nop
    ctx->pc = 0x178ebcu;
    // NOP
label_178ec0:
    // 0x178ec0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178ec0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178ec4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178ec4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178ec8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x178ec8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178ecc: 0x3e00008  jr          $ra
    ctx->pc = 0x178ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178ECCu;
            // 0x178ed0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178E78u: goto label_178e78;
            case 0x178E88u: goto label_178e88;
            case 0x178E98u: goto label_178e98;
            case 0x178EC0u: goto label_178ec0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178ED4u;
    // 0x178ed4: 0x0  nop
    ctx->pc = 0x178ed4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
