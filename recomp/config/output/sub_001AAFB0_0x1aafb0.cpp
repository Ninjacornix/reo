#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AAFB0
// Address: 0x1aafb0 - 0x1ab050
void sub_001AAFB0_0x1aafb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AAFB0_0x1aafb0");
#endif

    switch (ctx->pc) {
        case 0x1aafe8u: goto label_1aafe8;
        case 0x1ab020u: goto label_1ab020;
        case 0x1ab028u: goto label_1ab028;
        default: break;
    }

    ctx->pc = 0x1aafb0u;

    // 0x1aafb0: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x1aafb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x1aafb4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1aafb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1aafb8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1aafb8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1aafbc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1aafbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1aafc0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1aafc0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aafc4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1aafc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1aafc8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1aafc8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aafcc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aafccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aafd0: 0x12600015  beqz        $s3, . + 4 + (0x15 << 2)
    ctx->pc = 0x1AAFD0u;
    {
        const bool branch_taken_0x1aafd0 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AAFD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAFD0u;
            // 0x1aafd4: 0xe0882d  daddu       $s1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aafd0) {
            ctx->pc = 0x1AB028u;
            goto label_1ab028;
        }
    }
    ctx->pc = 0x1AAFD8u;
    // 0x1aafd8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1aafd8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aafdc: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1aafdcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1aafe0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AAFE0u;
    SET_GPR_U32(ctx, 31, 0x1AAFE8u);
    ctx->pc = 0x1AAFE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAFE0u;
            // 0x1aafe4: 0x24060080  addiu       $a2, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAFE8u; }
        if (ctx->pc != 0x1AAFE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAFE8u; }
        if (ctx->pc != 0x1AAFE8u) { return; }
    }
    ctx->pc = 0x1AAFE8u;
label_1aafe8:
    // 0x1aafe8: 0x8fa40064  lw          $a0, 0x64($sp)
    ctx->pc = 0x1aafe8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x1aafec: 0x1080000e  beqz        $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x1AAFECu;
    {
        const bool branch_taken_0x1aafec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aafec) {
            ctx->pc = 0x1AB028u;
            goto label_1ab028;
        }
    }
    ctx->pc = 0x1AAFF4u;
    // 0x1aaff4: 0x8fa30074  lw          $v1, 0x74($sp)
    ctx->pc = 0x1aaff4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 116)));
    // 0x1aaff8: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AAFF8u;
    {
        const bool branch_taken_0x1aaff8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AAFFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAFF8u;
            // 0x1aaffc: 0x2043021  addu        $a2, $s0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aaff8) {
            ctx->pc = 0x1AB00Cu;
            goto label_1ab00c;
        }
    }
    ctx->pc = 0x1AB000u;
    // 0x1ab000: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1AB000u;
    {
        const bool branch_taken_0x1ab000 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB000u;
            // 0x1ab004: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab000) {
            ctx->pc = 0x1AB02Cu;
            goto label_1ab02c;
        }
    }
    ctx->pc = 0x1AB008u;
    // 0x1ab008: 0x2043021  addu        $a2, $s0, $a0
    ctx->pc = 0x1ab008u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_1ab00c:
    // 0x1ab00c: 0x324500ff  andi        $a1, $s2, 0xFF
    ctx->pc = 0x1ab00cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1ab010: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1ab010u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab014: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x1ab014u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab018: 0xc073d58  jal         func_1CF560
    ctx->pc = 0x1AB018u;
    SET_GPR_U32(ctx, 31, 0x1AB020u);
    ctx->pc = 0x1AB01Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB018u;
            // 0x1ab01c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF560u;
    if (runtime->hasFunction(0x1CF560u)) {
        auto targetFn = runtime->lookupFunction(0x1CF560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB020u; }
        if (ctx->pc != 0x1AB020u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF560_0x1cf560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB020u; }
        if (ctx->pc != 0x1AB020u) { return; }
    }
    ctx->pc = 0x1AB020u;
label_1ab020:
    // 0x1ab020: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1AB020u;
    SET_GPR_U32(ctx, 31, 0x1AB028u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB028u; }
        if (ctx->pc != 0x1AB028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB028u; }
        if (ctx->pc != 0x1AB028u) { return; }
    }
    ctx->pc = 0x1AB028u;
label_1ab028:
    // 0x1ab028: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1ab028u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1ab02c:
    // 0x1ab02c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ab02cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ab030: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ab030u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ab034: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ab034u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ab038: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ab038u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab03c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB03Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB03Cu;
            // 0x1ab040: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AAFE8u: goto label_1aafe8;
            case 0x1AB00Cu: goto label_1ab00c;
            case 0x1AB020u: goto label_1ab020;
            case 0x1AB028u: goto label_1ab028;
            case 0x1AB02Cu: goto label_1ab02c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB044u;
    // 0x1ab044: 0x0  nop
    ctx->pc = 0x1ab044u;
    // NOP
    // 0x1ab048: 0x0  nop
    ctx->pc = 0x1ab048u;
    // NOP
    // 0x1ab04c: 0x0  nop
    ctx->pc = 0x1ab04cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
