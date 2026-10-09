#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CDE10
// Address: 0x1cde10 - 0x1cdfe0
void sub_001CDE10_0x1cde10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CDE10_0x1cde10");
#endif

    switch (ctx->pc) {
        case 0x1cde58u: goto label_1cde58;
        case 0x1cde6cu: goto label_1cde6c;
        case 0x1cde7cu: goto label_1cde7c;
        case 0x1cde88u: goto label_1cde88;
        case 0x1cdea8u: goto label_1cdea8;
        case 0x1cdeb8u: goto label_1cdeb8;
        case 0x1cdec0u: goto label_1cdec0;
        case 0x1cdeccu: goto label_1cdecc;
        case 0x1cdf10u: goto label_1cdf10;
        case 0x1cdf20u: goto label_1cdf20;
        case 0x1cdf40u: goto label_1cdf40;
        case 0x1cdf50u: goto label_1cdf50;
        case 0x1cdf64u: goto label_1cdf64;
        case 0x1cdf74u: goto label_1cdf74;
        case 0x1cdf84u: goto label_1cdf84;
        case 0x1cdf8cu: goto label_1cdf8c;
        case 0x1cdfa4u: goto label_1cdfa4;
        case 0x1cdfb8u: goto label_1cdfb8;
        default: break;
    }

    ctx->pc = 0x1cde10u;

    // 0x1cde10: 0x27bdfcb0  addiu       $sp, $sp, -0x350
    ctx->pc = 0x1cde10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966448));
    // 0x1cde14: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cde14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cde18: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1cde18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1cde1c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cde1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cde20: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cde20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cde24: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1cde24u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cde28: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cde28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cde2c: 0x16630005  bne         $s3, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CDE2Cu;
    {
        const bool branch_taken_0x1cde2c = (GPR_U64(ctx, 19) != GPR_U64(ctx, 3));
        ctx->pc = 0x1CDE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDE2Cu;
            // 0x1cde30: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cde2c) {
            ctx->pc = 0x1CDE44u;
            goto label_1cde44;
        }
    }
    ctx->pc = 0x1CDE34u;
    // 0x1cde34: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cde34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cde38: 0x8c3366c8  lw          $s3, 0x66C8($at)
    ctx->pc = 0x1cde38u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26312)));
    // 0x1cde3c: 0x12630061  beq         $s3, $v1, . + 4 + (0x61 << 2)
    ctx->pc = 0x1CDE3Cu;
    {
        const bool branch_taken_0x1cde3c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 3));
        if (branch_taken_0x1cde3c) {
            ctx->pc = 0x1CDFC4u;
            goto label_1cdfc4;
        }
    }
    ctx->pc = 0x1CDE44u;
label_1cde44:
    // 0x1cde44: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1cde44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cde48: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1cde48u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cde4c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1cde4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cde50: 0xc0735c4  jal         func_1CD710
    ctx->pc = 0x1CDE50u;
    SET_GPR_U32(ctx, 31, 0x1CDE58u);
    ctx->pc = 0x1CDE54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDE50u;
            // 0x1cde54: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD710u;
    if (runtime->hasFunction(0x1CD710u)) {
        auto targetFn = runtime->lookupFunction(0x1CD710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDE58u; }
        if (ctx->pc != 0x1CDE58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD710_0x1cd710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDE58u; }
        if (ctx->pc != 0x1CDE58u) { return; }
    }
    ctx->pc = 0x1CDE58u;
label_1cde58:
    // 0x1cde58: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1cde58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cde5c: 0x12000059  beqz        $s0, . + 4 + (0x59 << 2)
    ctx->pc = 0x1CDE5Cu;
    {
        const bool branch_taken_0x1cde5c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDE60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDE5Cu;
            // 0x1cde60: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cde5c) {
            ctx->pc = 0x1CDFC4u;
            goto label_1cdfc4;
        }
    }
    ctx->pc = 0x1CDE64u;
    // 0x1cde64: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1CDE64u;
    SET_GPR_U32(ctx, 31, 0x1CDE6Cu);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDE6Cu; }
        if (ctx->pc != 0x1CDE6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDE6Cu; }
        if (ctx->pc != 0x1CDE6Cu) { return; }
    }
    ctx->pc = 0x1CDE6Cu;
label_1cde6c:
    // 0x1cde6c: 0x10400055  beqz        $v0, . + 4 + (0x55 << 2)
    ctx->pc = 0x1CDE6Cu;
    {
        const bool branch_taken_0x1cde6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDE70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDE6Cu;
            // 0x1cde70: 0x27a40250  addiu       $a0, $sp, 0x250 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 592));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cde6c) {
            ctx->pc = 0x1CDFC4u;
            goto label_1cdfc4;
        }
    }
    ctx->pc = 0x1CDE74u;
    // 0x1cde74: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1CDE74u;
    SET_GPR_U32(ctx, 31, 0x1CDE7Cu);
    ctx->pc = 0x1CDE78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDE74u;
            // 0x1cde78: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDE7Cu; }
        if (ctx->pc != 0x1CDE7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDE7Cu; }
        if (ctx->pc != 0x1CDE7Cu) { return; }
    }
    ctx->pc = 0x1CDE7Cu;
label_1cde7c:
    // 0x1cde7c: 0x27a40250  addiu       $a0, $sp, 0x250
    ctx->pc = 0x1cde7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 592));
    // 0x1cde80: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CDE80u;
    SET_GPR_U32(ctx, 31, 0x1CDE88u);
    ctx->pc = 0x1CDE84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDE80u;
            // 0x1cde84: 0x2405005c  addiu       $a1, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDE88u; }
        if (ctx->pc != 0x1CDE88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDE88u; }
        if (ctx->pc != 0x1CDE88u) { return; }
    }
    ctx->pc = 0x1CDE88u;
label_1cde88:
    // 0x1cde88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1cde88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cde8c: 0xa0400001  sb          $zero, 0x1($v0)
    ctx->pc = 0x1cde8cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cde90: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cde90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cde94: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1cde94u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cde98: 0x8c300ae0  lw          $s0, 0xAE0($at)
    ctx->pc = 0x1cde98u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2784)));
    // 0x1cde9c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1cde9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cdea0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1CDEA0u;
    SET_GPR_U32(ctx, 31, 0x1CDEA8u);
    ctx->pc = 0x1CDEA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDEA0u;
            // 0x1cdea4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDEA8u; }
        if (ctx->pc != 0x1CDEA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDEA8u; }
        if (ctx->pc != 0x1CDEA8u) { return; }
    }
    ctx->pc = 0x1CDEA8u;
label_1cdea8:
    // 0x1cdea8: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1cdea8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cdeac: 0x12400045  beqz        $s2, . + 4 + (0x45 << 2)
    ctx->pc = 0x1CDEACu;
    {
        const bool branch_taken_0x1cdeac = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDEB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDEACu;
            // 0x1cdeb0: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdeac) {
            ctx->pc = 0x1CDFC4u;
            goto label_1cdfc4;
        }
    }
    ctx->pc = 0x1CDEB4u;
    // 0x1cdeb4: 0x27a40150  addiu       $a0, $sp, 0x150
    ctx->pc = 0x1cdeb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
label_1cdeb8:
    // 0x1cdeb8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1CDEB8u;
    SET_GPR_U32(ctx, 31, 0x1CDEC0u);
    ctx->pc = 0x1CDEBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDEB8u;
            // 0x1cdebc: 0x27a50250  addiu       $a1, $sp, 0x250 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDEC0u; }
        if (ctx->pc != 0x1CDEC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDEC0u; }
        if (ctx->pc != 0x1CDEC0u) { return; }
    }
    ctx->pc = 0x1CDEC0u;
label_1cdec0:
    // 0x1cdec0: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1cdec0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1cdec4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CDEC4u;
    {
        const bool branch_taken_0x1cdec4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDEC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDEC4u;
            // 0x1cdec8: 0x2403000a  addiu       $v1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdec4) {
            ctx->pc = 0x1CDEE4u;
            goto label_1cdee4;
        }
    }
    ctx->pc = 0x1CDECCu;
label_1cdecc:
    // 0x1cdecc: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1cdeccu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1cded0: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1cded0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1cded4: 0x232082a  slt         $at, $s1, $s2
    ctx->pc = 0x1cded4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1cded8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cded8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1cdedc: 0x10200039  beqz        $at, . + 4 + (0x39 << 2)
    ctx->pc = 0x1CDEDCu;
    {
        const bool branch_taken_0x1cdedc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDEE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDEDCu;
            // 0x1cdee0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdedc) {
            ctx->pc = 0x1CDFC4u;
            goto label_1cdfc4;
        }
    }
    ctx->pc = 0x1CDEE4u;
label_1cdee4:
    // 0x1cdee4: 0x82050000  lb          $a1, 0x0($s0)
    ctx->pc = 0x1cdee4u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cdee8: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CDEE8u;
    {
        const bool branch_taken_0x1cdee8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1cdee8) {
            ctx->pc = 0x1CDEF8u;
            goto label_1cdef8;
        }
    }
    ctx->pc = 0x1CDEF0u;
    // 0x1cdef0: 0x14a0fff6  bnez        $a1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1CDEF0u;
    {
        const bool branch_taken_0x1cdef0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cdef0) {
            ctx->pc = 0x1CDECCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cdecc;
        }
    }
    ctx->pc = 0x1CDEF8u;
label_1cdef8:
    // 0x1cdef8: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1cdef8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cdefc: 0x2405002e  addiu       $a1, $zero, 0x2E
    ctx->pc = 0x1cdefcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1cdf00: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1cdf00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1cdf04: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cdf04u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1cdf08: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CDF08u;
    SET_GPR_U32(ctx, 31, 0x1CDF10u);
    ctx->pc = 0x1CDF0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF08u;
            // 0x1cdf0c: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF10u; }
        if (ctx->pc != 0x1CDF10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF10u; }
        if (ctx->pc != 0x1CDF10u) { return; }
    }
    ctx->pc = 0x1CDF10u;
label_1cdf10:
    // 0x1cdf10: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CDF10u;
    {
        const bool branch_taken_0x1cdf10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CDF14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF10u;
            // 0x1cdf14: 0x27a40050  addiu       $a0, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdf10) {
            ctx->pc = 0x1CDF30u;
            goto label_1cdf30;
        }
    }
    ctx->pc = 0x1CDF18u;
    // 0x1cdf18: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CDF18u;
    SET_GPR_U32(ctx, 31, 0x1CDF20u);
    ctx->pc = 0x1CDF1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF18u;
            // 0x1cdf1c: 0x2405002c  addiu       $a1, $zero, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF20u; }
        if (ctx->pc != 0x1CDF20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF20u; }
        if (ctx->pc != 0x1CDF20u) { return; }
    }
    ctx->pc = 0x1CDF20u;
label_1cdf20:
    // 0x1cdf20: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CDF20u;
    {
        const bool branch_taken_0x1cdf20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDF24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF20u;
            // 0x1cdf24: 0x27a40050  addiu       $a0, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdf20) {
            ctx->pc = 0x1CDF38u;
            goto label_1cdf38;
        }
    }
    ctx->pc = 0x1CDF28u;
    // 0x1cdf28: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CDF28u;
    {
        const bool branch_taken_0x1cdf28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDF2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF28u;
            // 0x1cdf2c: 0xa0400000  sb          $zero, 0x0($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdf28) {
            ctx->pc = 0x1CDF34u;
            goto label_1cdf34;
        }
    }
    ctx->pc = 0x1CDF30u;
label_1cdf30:
    // 0x1cdf30: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1cdf30u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
label_1cdf34:
    // 0x1cdf34: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1cdf34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
label_1cdf38:
    // 0x1cdf38: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1CDF38u;
    SET_GPR_U32(ctx, 31, 0x1CDF40u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF40u; }
        if (ctx->pc != 0x1CDF40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF40u; }
        if (ctx->pc != 0x1CDF40u) { return; }
    }
    ctx->pc = 0x1CDF40u;
label_1cdf40:
    // 0x1cdf40: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1CDF40u;
    {
        const bool branch_taken_0x1cdf40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDF44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF40u;
            // 0x1cdf44: 0x27a40050  addiu       $a0, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdf40) {
            ctx->pc = 0x1CDFC4u;
            goto label_1cdfc4;
        }
    }
    ctx->pc = 0x1CDF48u;
    // 0x1cdf48: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CDF48u;
    SET_GPR_U32(ctx, 31, 0x1CDF50u);
    ctx->pc = 0x1CDF4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF48u;
            // 0x1cdf4c: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF50u; }
        if (ctx->pc != 0x1CDF50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF50u; }
        if (ctx->pc != 0x1CDF50u) { return; }
    }
    ctx->pc = 0x1CDF50u;
label_1cdf50:
    // 0x1cdf50: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CDF50u;
    {
        const bool branch_taken_0x1cdf50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDF54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF50u;
            // 0x1cdf54: 0x27a40150  addiu       $a0, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdf50) {
            ctx->pc = 0x1CDF6Cu;
            goto label_1cdf6c;
        }
    }
    ctx->pc = 0x1CDF58u;
    // 0x1cdf58: 0x24450001  addiu       $a1, $v0, 0x1
    ctx->pc = 0x1cdf58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cdf5c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CDF5Cu;
    SET_GPR_U32(ctx, 31, 0x1CDF64u);
    ctx->pc = 0x1CDF60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF5Cu;
            // 0x1cdf60: 0x27a40150  addiu       $a0, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF64u; }
        if (ctx->pc != 0x1CDF64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF64u; }
        if (ctx->pc != 0x1CDF64u) { return; }
    }
    ctx->pc = 0x1CDF64u;
label_1cdf64:
    // 0x1cdf64: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1CDF64u;
    {
        const bool branch_taken_0x1cdf64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cdf64) {
            ctx->pc = 0x1CDF74u;
            goto label_1cdf74;
        }
    }
    ctx->pc = 0x1CDF6Cu;
label_1cdf6c:
    // 0x1cdf6c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CDF6Cu;
    SET_GPR_U32(ctx, 31, 0x1CDF74u);
    ctx->pc = 0x1CDF70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF6Cu;
            // 0x1cdf70: 0x27a50050  addiu       $a1, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF74u; }
        if (ctx->pc != 0x1CDF74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF74u; }
        if (ctx->pc != 0x1CDF74u) { return; }
    }
    ctx->pc = 0x1CDF74u;
label_1cdf74:
    // 0x1cdf74: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cdf74u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cdf78: 0x27a40150  addiu       $a0, $sp, 0x150
    ctx->pc = 0x1cdf78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
    // 0x1cdf7c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CDF7Cu;
    SET_GPR_U32(ctx, 31, 0x1CDF84u);
    ctx->pc = 0x1CDF80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF7Cu;
            // 0x1cdf80: 0x24a560c0  addiu       $a1, $a1, 0x60C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24768));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF84u; }
        if (ctx->pc != 0x1CDF84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF84u; }
        if (ctx->pc != 0x1CDF84u) { return; }
    }
    ctx->pc = 0x1CDF84u;
label_1cdf84:
    // 0x1cdf84: 0xc073768  jal         func_1CDDA0
    ctx->pc = 0x1CDF84u;
    SET_GPR_U32(ctx, 31, 0x1CDF8Cu);
    ctx->pc = 0x1CDF88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF84u;
            // 0x1cdf88: 0x27a40150  addiu       $a0, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDDA0u;
    if (runtime->hasFunction(0x1CDDA0u)) {
        auto targetFn = runtime->lookupFunction(0x1CDDA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF8Cu; }
        if (ctx->pc != 0x1CDF8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDDA0_0x1cdda0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDF8Cu; }
        if (ctx->pc != 0x1CDF8Cu) { return; }
    }
    ctx->pc = 0x1CDF8Cu;
label_1cdf8c:
    // 0x1cdf8c: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CDF8Cu;
    {
        const bool branch_taken_0x1cdf8c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CDF90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF8Cu;
            // 0x1cdf90: 0x24040ff0  addiu       $a0, $zero, 0xFF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4080));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdf8c) {
            ctx->pc = 0x1CDFACu;
            goto label_1cdfac;
        }
    }
    ctx->pc = 0x1CDF94u;
    // 0x1cdf94: 0x27a40150  addiu       $a0, $sp, 0x150
    ctx->pc = 0x1cdf94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
    // 0x1cdf98: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1cdf98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cdf9c: 0xc073364  jal         func_1CCD90
    ctx->pc = 0x1CDF9Cu;
    SET_GPR_U32(ctx, 31, 0x1CDFA4u);
    ctx->pc = 0x1CDFA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDF9Cu;
            // 0x1cdfa0: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCD90u;
    if (runtime->hasFunction(0x1CCD90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDFA4u; }
        if (ctx->pc != 0x1CDFA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCD90_0x1ccd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDFA4u; }
        if (ctx->pc != 0x1CDFA4u) { return; }
    }
    ctx->pc = 0x1CDFA4u;
label_1cdfa4:
    // 0x1cdfa4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CDFA4u;
    {
        const bool branch_taken_0x1cdfa4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDFA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDFA4u;
            // 0x1cdfa8: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdfa4) {
            ctx->pc = 0x1CDFBCu;
            goto label_1cdfbc;
        }
    }
    ctx->pc = 0x1CDFACu;
label_1cdfac:
    // 0x1cdfac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1cdfacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cdfb0: 0xc07333c  jal         func_1CCCF0
    ctx->pc = 0x1CDFB0u;
    SET_GPR_U32(ctx, 31, 0x1CDFB8u);
    ctx->pc = 0x1CDFB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDFB0u;
            // 0x1cdfb4: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCCF0u;
    if (runtime->hasFunction(0x1CCCF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CCCF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDFB8u; }
        if (ctx->pc != 0x1CDFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCCF0_0x1cccf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDFB8u; }
        if (ctx->pc != 0x1CDFB8u) { return; }
    }
    ctx->pc = 0x1CDFB8u;
label_1cdfb8:
    // 0x1cdfb8: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1cdfb8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1cdfbc:
    // 0x1cdfbc: 0x1000ffbe  b           . + 4 + (-0x42 << 2)
    ctx->pc = 0x1CDFBCu;
    {
        const bool branch_taken_0x1cdfbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDFC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDFBCu;
            // 0x1cdfc0: 0x27a40150  addiu       $a0, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdfbc) {
            ctx->pc = 0x1CDEB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cdeb8;
        }
    }
    ctx->pc = 0x1CDFC4u;
label_1cdfc4:
    // 0x1cdfc4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1cdfc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cdfc8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cdfc8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cdfcc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cdfccu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cdfd0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cdfd0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cdfd4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cdfd4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cdfd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CDFD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CDFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDFD8u;
            // 0x1cdfdc: 0x27bd0350  addiu       $sp, $sp, 0x350 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 848));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CDE44u: goto label_1cde44;
            case 0x1CDE58u: goto label_1cde58;
            case 0x1CDE6Cu: goto label_1cde6c;
            case 0x1CDE7Cu: goto label_1cde7c;
            case 0x1CDE88u: goto label_1cde88;
            case 0x1CDEA8u: goto label_1cdea8;
            case 0x1CDEB8u: goto label_1cdeb8;
            case 0x1CDEC0u: goto label_1cdec0;
            case 0x1CDECCu: goto label_1cdecc;
            case 0x1CDEE4u: goto label_1cdee4;
            case 0x1CDEF8u: goto label_1cdef8;
            case 0x1CDF10u: goto label_1cdf10;
            case 0x1CDF20u: goto label_1cdf20;
            case 0x1CDF30u: goto label_1cdf30;
            case 0x1CDF34u: goto label_1cdf34;
            case 0x1CDF38u: goto label_1cdf38;
            case 0x1CDF40u: goto label_1cdf40;
            case 0x1CDF50u: goto label_1cdf50;
            case 0x1CDF64u: goto label_1cdf64;
            case 0x1CDF6Cu: goto label_1cdf6c;
            case 0x1CDF74u: goto label_1cdf74;
            case 0x1CDF84u: goto label_1cdf84;
            case 0x1CDF8Cu: goto label_1cdf8c;
            case 0x1CDFA4u: goto label_1cdfa4;
            case 0x1CDFACu: goto label_1cdfac;
            case 0x1CDFB8u: goto label_1cdfb8;
            case 0x1CDFBCu: goto label_1cdfbc;
            case 0x1CDFC4u: goto label_1cdfc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CDFE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
